// CRI adx_dcd.c: ADX header and info decoding, ADX_GetCoefficient.
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_803C4698.h"
#include "pso/audio/AdxEncoder.h"
#include "pso/audio/AdxHeader.h"

#include <math.h>

static inline s32 adx_parse_header_loop_points_impl(void *ptr, s32 size, u16 *out0, u16 *out1) {
    AdxHeader *h = (AdxHeader *)ptr;
    s32 err;
    u8 ver;
    if (size < 0x14) {
        err = -1;
    } else if (h->magic != 0x8000) {
        err = -2;
    } else if (h->header_offset < 0x10) {
        err = -1;
    } else {
        ver = h->version;
        err = 0;
    }
    if (err != 0) {
        return -1;
    }
    if (ver >= 4U) {
        if (size < 0x20) {
            return -1;
        }
        if (h->magic != 0x8000) {
            return -2;
        }
        if (h->header_offset < 0x1C) {
            return -1;
        }
        out0[0] = h->loop_points[0];
        out1[0] = h->loop_points[1];
        out0[1] = h->loop_points[2];
        out1[1] = h->loop_points[3];
    } else {
        out0[0] = out1[0] = out0[1] = out1[1] = 0;
    }
    return 0;
}

static inline s32 adx_parse_packet_header_len_impl(void *ptr, s32 size, s16 *out) {
    AdxPacketHeader *p = (AdxPacketHeader *)ptr;
    if (size < 0x10) {
        return -1;
    }
    if (p->type != 0x8001) {
        return -2;
    }
    *out = p->len + 4;
    return 0;
}

extern "C" {

s32 TLobby::parse_packet_header_len(s32 size, s16 *out) {
    return adx_parse_packet_header_len_impl(this, size, out);
}

s32 sub_803C46DC(u8 *hdr, s32 size, s32 *o1, s16 *o2, s16 *o3, s32 *o4, s32 *o5, s32 *o6, s32 *o7) {
    AdxHeader *h = (AdxHeader *)hdr;
    s32 err;
    u8 ver;
    s32 hsz;
    s32 off;
    AdxHeaderBlock *f;
    *o2 = err = 0;
    if (size < 0x14) {
        err = -1;
    } else if (h->magic != 0x8000) {
        err = -2;
    } else if (h->header_offset < 0x10) {
        err = -1;
    } else {
        ver = h->version;
    }
    if (err != 0) {
        return err;
    }
    hsz = 0x30;
    if (ver == 4) {
        hsz = 0x3C;
    }
    if (size < hsz) {
        return -1;
    }
    if (h->magic != 0x8000) {
        return -2;
    }
    if (h->header_offset < hsz - 4) {
        return -1;
    }
    off = 0x14;
    if (ver == 4) {
        off = 0x20;
    }
    *o1 = ((AdxHeaderBlock *)(hdr + off))->loop_enabled_flag;
    f = (AdxHeaderBlock *)(off + (saddr)hdr);
    *o2 = f->loop_type;
    if (*o2 != 1) {
        return -2;
    }
    *o3 = f->loop_count;
    *o4 = f->loop_start_sample;
    *o5 = f->loop_start_offset;
    *o6 = f->loop_end_sample;
    *o7 = f->loop_end_offset;
    return 0;
}

s32 TLobby::parse_header_loop_points(s32 size, u16 *out0, u16 *out1) {
    return adx_parse_header_loop_points_impl(this, size, out0, out1);
}

s32 TLobby__sub_803C48C8(u8 *hdr, s32 size, u16 *out) {
    AdxHeader *h = (AdxHeader *)hdr;
    if (size < 0x12) {
        return -1;
    }
    if (h->magic != 0x8000) {
        return -2;
    }
    if (h->header_offset < 0xE) {
        return -1;
    }
    *out = h->flags;
    return 0;
}

s32 sub_803C4910(u8 *hdr, s32 size, s16 *len, u8 *out_0C, s8 *bits, s8 *block_bytes, u8 *channels, s32 *rate, s32 *samples, s32 *block_samples) {
    if (size < 0x10) {
        return -1;
    }
    if ((u16)((hdr[0] << 8) | hdr[1]) != 0x8000) {
        return -2;
    }
    *len = ((hdr[2] << 8) | hdr[3]) + 4;
    *out_0C = hdr[4];
    *block_bytes = hdr[5];
    *bits = hdr[6];
    *channels = hdr[7];
    *rate = (hdr[8] << 24) | (hdr[9] << 16) | (hdr[10] << 8) | hdr[11];
    *samples = (hdr[12] << 24) | (hdr[13] << 16) | (hdr[14] << 8) | hdr[15];
    if (*bits == 0) {
        *block_samples = 0;
    } else {
        *block_samples = ((*block_bytes - 2) * 8) / *bits;
    }
    return 0;
}

s32 TLobby::find_terminator_index(s16 *samples, s32 count, s16 *out_index) {
    s16 *p = samples;
    s32 i;
    s32 best = 0x7FFFFFFF;
    for (i = 0; i < count - 1; i += 2, p++) {
        if (*p == -0x8000) {
            best = (i < 0x7FFFFFFF) ? i : 0x7FFFFFFF;
            break;
        }
    }
    if (best != 0x7FFFFFFF) {
        *out_index = best;
        return 0;
    }
    *out_index = 0;
    return -1;
}
}

#pragma push
#pragma fp_contract on
static inline f32 adx_cosf(f32 x) {
    f32 r = cos(x);
    return r;
}

static inline f32 adx_sqrtf(f32 x) {
    if (x > 0.0f) {
        volatile f32 r;
        f64 g = __frsqrte(x);
        g = 0.5 * g * (3.0 - x * (g * g));
        g = 0.5 * g * (3.0 - x * (g * g));
        g = 0.5 * g * (3.0 - x * (g * g));
        r = (f32)(x * g);
        return r;
    }
    return x;
}

void calc_adx_predictor_coeffs(s32 cutoff, s32 rate, s16 *k0, s16 *k1) {
    f32 c;
    f64 a;
    f64 b;
    f64 x;

    c = adx_cosf(6.28318530717958 * cutoff / rate);
    a = adx_sqrtf(2.0f) - c;
    b = adx_sqrtf(2.0f) - 1.0;
    x = (a - adx_sqrtf((a + b) * (a - b))) / b;
    *k0 = 4096.0 * (2.0 * x);
    *k1 = 4096.0 * (-x * x);
}
#pragma pop
