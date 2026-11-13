// CRI adx_dcd.c: ADX header and info decoding, ADX_GetCoefficient.
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_803C4698.h"
#include "pso/audio/AdxEncoder.h"
#include "pso/audio/AdxHeader.h"

extern "C" {
f64 cos(f64);

s32 TLobby::parse_packet_header_len(s32 size, s16 *out) {
    AdxPacketHeader *p = (AdxPacketHeader *)this;
    if (size < 0x10) {
        return -1;
    }
    if (p->type != 0x8001) {
        return -2;
    }
    *out = p->len + 4;
    return 0;
}

s32 __DVDPrepareResetAsync(u8 *hdr, s32 size, s32 *o1, s16 *o2, s16 *o3, s32 *o4, s32 *o5, s32 *o6, s32 *o7) {
    AdxHeader *h = (AdxHeader *)hdr;
    s32 err;
    u8 ver;
    s32 hsz;
    s32 off;
    AdxHeaderBlock *f;
    *o2 = err = 0;
    if (size < 0x14) {
        err = -1;
    } else if (h->m_00 != 0x8000) {
        err = -2;
    } else if (h->m_02 < 0x10) {
        err = -1;
    } else {
        ver = h->m_12;
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
    if (h->m_00 != 0x8000) {
        return -2;
    }
    if (h->m_02 < hsz - 4) {
        return -1;
    }
    off = 0x14;
    if (ver == 4) {
        off = 0x20;
    }
    *o1 = ((AdxHeaderBlock *)(hdr + off))->m_00;
    f = (AdxHeaderBlock *)(off + (s32)hdr);
    *o2 = f->m_02;
    if (*o2 != 1) {
        return -2;
    }
    *o3 = f->m_06;
    *o4 = f->m_08;
    *o5 = f->m_0C;
    *o6 = f->m_10;
    *o7 = f->m_14;
    return 0;
}

s32 TLobby::parse_header_loop_points(s32 size, u16 *out0, u16 *out1) {
    AdxHeader *h = (AdxHeader *)this;
    s32 err;
    u8 ver;
    if (size < 0x14) {
        err = -1;
    } else if (h->m_00 != 0x8000) {
        err = -2;
    } else if (h->m_02 < 0x10) {
        err = -1;
    } else {
        ver = h->m_12;
        err = 0;
    }
    if (err != 0) {
        return -1;
    }
    if (ver >= 4U) {
        if (size < 0x20) {
            return -1;
        }
        if (h->m_00 != 0x8000) {
            return -2;
        }
        if (h->m_02 < 0x1C) {
            return -1;
        }
        out0[0] = h->m_18[0];
        out1[0] = h->m_18[1];
        out0[1] = h->m_18[2];
        out1[1] = h->m_18[3];
    } else {
        out0[0] = out1[0] = out0[1] = out1[1] = 0;
    }
    return 0;
}

s32 TLobby__sub_803C48C8(u8 *hdr, s32 size, u16 *out) {
    AdxHeader *h = (AdxHeader *)hdr;
    if (size < 0x12) {
        return -1;
    }
    if (h->m_00 != 0x8000) {
        return -2;
    }
    if (h->m_02 < 0xE) {
        return -1;
    }
    *out = h->m_10;
    return 0;
}

s32 ARStartDMA(u8 *hdr, s32 size, s16 *len, u8 *out_0C, s8 *bits, s8 *block_bytes, u8 *channels, s32 *rate, s32 *samples, s32 *block_samples) {
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
}

s32 TLobby::find_terminator_index(s16 *arg0, s32 arg1, s16 *arg2) {
    s16 *p = arg0;
    s32 i;
    s32 best = 0x7FFFFFFF;
    for (i = 0; i < arg1 - 1; i += 2, p++) {
        if (*p == -0x8000) {
            best = (i < 0x7FFFFFFF) ? i : 0x7FFFFFFF;
            break;
        }
    }
    if (best != 0x7FFFFFFF) {
        *arg2 = best;
        return 0;
    }
    *arg2 = 0;
    return -1;
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
