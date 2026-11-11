// CRI adx_dcd.c: ADX header and info decoding, ADX_GetCoefficient.
#include "types.h"
#include "pso/unk/text_803D31A4.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/LscStream.h"
#include "pso/unk/TLobby_803C4698.h"
#include "pso/unk/TLobby_803CC0B4.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxEncoder.h"
#include "pso/system/RefCountedWorkBuffer.h"
#include "pso/audio/SjMemoryBuffer.h"
#include "pso/audio/SjRingBuffer.h"
#include "pso/unk/text_803CC294.h"
#include "pso/unk/text_803CE568.h"

struct Hdr_803C46A4 { u16 type; s16 len; };
struct Fmt_803C46DC { s16 a; s16 b; s16 c; s16 d; s32 e; s32 f; s32 g; s32 h; };

extern "C" {
f64 cos(f64);

s32 TLobby::parse_packet_header_len(s32 size, s16 *out) {
    Hdr_803C46A4 *p = (Hdr_803C46A4 *)this;
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
    s32 err;
    u8 ver;
    s32 hsz;
    s32 off;
    Fmt_803C46DC *f;
    *o2 = err = 0;
    if (size < 0x14) {
        err = -1;
    } else if (*(u16 *)hdr != 0x8000) {
        err = -2;
    } else if (*(s16 *)(hdr + 2) < 0x10) {
        err = -1;
    } else {
        ver = hdr[0x12];
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
    if (*(u16 *)hdr != 0x8000) {
        return -2;
    }
    if (*(s16 *)(hdr + 2) < hsz - 4) {
        return -1;
    }
    off = 0x14;
    if (ver == 4) {
        off = 0x20;
    }
    *o1 = *(s16 *)(hdr + off);
    f = (Fmt_803C46DC *)(off + (s32)hdr);
    *o2 = f->b;
    if (*o2 != 1) {
        return -2;
    }
    *o3 = f->d;
    *o4 = f->e;
    *o5 = f->f;
    *o6 = f->g;
    *o7 = f->h;
    return 0;
}

s32 TLobby::parse_header_loop_points(s32 arg1, u16 *arg2, u16 *arg3) {
    u8 *arg0 = (u8 *)this;
    s32 var_r0;
    u8 var_r7;
    if (arg1 < 0x14) {
        var_r0 = -1;
    } else if ((u16) *(u16 *)&this->m_name != 0x8000) {
        var_r0 = -2;
    } else if ((s16) *(s16 *)((s8 *)arg0 + 2) < 0x10) {
        var_r0 = -1;
    } else {
        var_r7 = *(u8 *)((s8 *)arg0 + 0x12);
        var_r0 = 0;
    }
    if (var_r0 != 0) {
        return -1;
    }
    if (var_r7 >= 4U) {
        if (arg1 < 0x20) {
            return -1;
        }
        if ((u16) *(u16 *)&this->m_name != 0x8000) {
            return -2;
        }
        if ((s16) *(s16 *)((s8 *)arg0 + 2) < 0x1C) {
            return -1;
        }
        arg2[0] = (u16) *(u16 *)((s8 *)arg0 + 0x18);
        arg3[0] = (u16) *(u16 *)((s8 *)arg0 + 0x1A);
        arg2[1] = (u16) *(u16 *)((s8 *)arg0 + 0x1C);
        arg3[1] = (u16) *(u16 *)((s8 *)arg0 + 0x1E);
    } else {
        arg2[0] = arg3[0] = arg2[1] = arg3[1] = 0;
    }
    return 0;
}

s32 TLobby__sub_803C48C8(u8 *arg0, s32 arg1, u16 *arg2) {
    if (arg1 < 0x12) {
        return -1;
    }
    if (*(u16 *)((s8 *)arg0 + 0) != 0x8000) {
        return -2;
    }
    if ((s16) *(s16 *)((s8 *)arg0 + 2) < 0xE) {
        return -1;
    }
    *arg2 = *(u16 *)((s8 *)arg0 + 0x10);
    return 0;
}

s32 ARStartDMA(u8 *arg0, s32 arg1, s16 *arg2, u8 *arg3, s8 *arg4, s8 *arg5, u8 *arg6, s32 *arg7, s32 *arg8, s32 *arg9) {
    if (arg1 < 0x10) {
        return -1;
    }
    if ((u16)((arg0[0] << 8) | arg0[1]) != 0x8000) {
        return -2;
    }
    *arg2 = ((arg0[2] << 8) | arg0[3]) + 4;
    *arg3 = arg0[4];
    *arg5 = arg0[5];
    *arg4 = arg0[6];
    *arg6 = arg0[7];
    *arg7 = (arg0[8] << 24) | (arg0[9] << 16) | (arg0[10] << 8) | arg0[11];
    *arg8 = (arg0[12] << 24) | (arg0[13] << 16) | (arg0[14] << 8) | arg0[15];
    if (*arg4 == 0) {
        *arg9 = 0;
    } else {
        *arg9 = ((*arg5 - 2) * 8) / *arg4;
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
