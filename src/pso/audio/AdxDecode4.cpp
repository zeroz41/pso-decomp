// CRI adx_dcd5.c: the 4-bit ADX block decoders (mono, stereo, stereo as mono).
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

struct AdxFrame {
    s16 scale;
    s8 nibbles[16];
};

extern "C" {
// Sign-extend the low four bits in the same way as the high nibble.
extern const s32 adx_signed_nibbles[16] = {
    0, 1, 2, 3, 4, 5, 6, 7, -8, -7, -6, -5, -4, -3, -2, -1,
};
}

extern "C" {
extern s32 lbl_805D7520;
}

void TLobby::set_global_805D7520(s32 arg0) {
    lbl_805D7520 = arg0;
}

void TLobby::dispatch_receive_update() {
    if ((s32) lbl_805D7520 == 0) {
        ((s32 (*)())decode_adx_stereo)();
        return;
    }
    ((s32 (*)())decode_adx_stereo_downmix)();
}

#define ADX_CLIP16(v)                    \
    if ((v) > 0x7FFF || (v) < -0x8000) { \
        if ((v) < -0x8000) {             \
            (v) = -0x8000;               \
        } else if ((v) > 0x7FFF) {       \
            (v) = 0x7FFF;                \
        }                                \
    }

s32 decode_adx_stereo_downmix(s8 *src, s32 nblk, s16 *outl, s16 *dlyl, s16 *outr, s16 *dlyr, s16 k0, s16 k1) {
    s32 l1;
    s32 i;
    s32 bl;
    s32 l2;
    s32 br;
    s32 v;
    s32 j;
    s32 r1;
    s32 r2;
    s32 scalel;
    s32 scaler;
    s32 n;

    l1 = dlyl[0];
    l2 = dlyl[1];
    r1 = dlyr[0];
    r2 = dlyr[1];
    n = nblk / 2;
    for (i = 0; i < n; i++) {
        if (((AdxFrame *)src)->scale & 0x8000) {
            return i * 2;
        }
        scalel = (((AdxFrame *)src)->scale & 0x1FFF) + 1;
        if (((AdxFrame *)src)[1].scale & 0x8000) {
            return i * 2;
        }
        scaler = (((AdxFrame *)src)[1].scale & 0x1FFF) + 1;
        src += 2;
        for (j = 0; j < 16; j++) {
            bl = src[0];
            br = src[18];
            src++;
            v = ((bl >> 4) * scalel) + ((k0 * l1 + k1 * l2) >> 12);
            ADX_CLIP16(v);
            l2 = l1;
            l1 = v;
            v = ((br >> 4) * scaler) + ((k0 * r1 + k1 * r2) >> 12);
            ADX_CLIP16(v);
            r2 = r1;
            r1 = v;
            v = (l1 + r1) * 7 / 10;
            ADX_CLIP16(v);
            outl[0] = outr[0] = v;
            bl = adx_signed_nibbles[bl & 0xF];
            br = adx_signed_nibbles[br & 0xF];
            v = (bl * scalel) + ((k0 * l1 + k1 * l2) >> 12);
            ADX_CLIP16(v);
            l2 = l1;
            l1 = v;
            v = (br * scaler) + ((k0 * r1 + k1 * r2) >> 12);
            ADX_CLIP16(v);
            r2 = r1;
            r1 = v;
            v = (l1 + r1) * 7 / 10;
            ADX_CLIP16(v);
            outl[1] = outr[1] = v;
            outl += 2;
            outr += 2;
        }
        src += 18;
    }
    dlyl[0] = l1;
    dlyl[1] = l2;
    dlyr[0] = r1;
    dlyr[1] = r2;
    return nblk;
}

s32 decode_adx_stereo(s8 *src, s32 nblk, s16 *outl, s16 *dlyl, s16 *outr, s16 *dlyr, s16 k0, s16 k1) {
    s32 l1;
    s32 r1;
    s32 i;
    s32 v;
    s32 bl;
    s32 br;
    s32 scalel;
    s32 n;
    s32 l2;
    s32 r2;
    s32 j;
    s32 scaler;

    l1 = dlyl[0];
    l2 = dlyl[1];
    r1 = dlyr[0];
    r2 = dlyr[1];
    n = nblk / 2;
    for (i = 0; i < n; i++) {
        if (((AdxFrame *)src)->scale & 0x8000) {
            return i * 2;
        }
        scalel = (((AdxFrame *)src)->scale & 0x1FFF) + 1;
        if (((AdxFrame *)src)[1].scale & 0x8000) {
            return i * 2;
        }
        scaler = (((AdxFrame *)src)[1].scale & 0x1FFF) + 1;
        src += 2;
        for (j = 0; j < 16; j++) {
            bl = src[0];
            br = src[18];
            src++;
            v = ((bl >> 4) * scalel) + ((k0 * l1 + k1 * l2) >> 12);
            ADX_CLIP16(v);
            l2 = l1;
            l1 = v;
            v = ((br >> 4) * scaler) + ((k0 * r1 + k1 * r2) >> 12);
            ADX_CLIP16(v);
            r2 = r1;
            r1 = v;
            outl[0] = l1;
            outr[0] = r1;
            bl = adx_signed_nibbles[bl & 0xF];
            br = adx_signed_nibbles[br & 0xF];
            v = (bl * scalel) + ((k0 * l1 + k1 * l2) >> 12);
            ADX_CLIP16(v);
            l2 = l1;
            l1 = v;
            v = (br * scaler) + ((k0 * r1 + k1 * r2) >> 12);
            ADX_CLIP16(v);
            r2 = r1;
            r1 = v;
            outl[1] = l1;
            outr[1] = r1;
            outl += 2;
            outr += 2;
        }
        src += 18;
    }
    dlyl[0] = l1;
    dlyl[1] = l2;
    dlyr[0] = r1;
    dlyr[1] = r2;
    return nblk;
}


s32 decode_adx_mono_blocks(s8 *src, s32 nblk, s16 *out, s16 *dly, s16 k0, s16 k1) {
    s32 i;
    s32 j;
    s32 d1;
    s32 d2;
    s32 scale;
    s32 b;
    s32 v;

    d1 = dly[0];
    d2 = dly[1];
    for (i = 0; i < nblk; i++) {
        if (((AdxFrame *)src)->scale & 0x8000) {
            return i;
        }
        scale = (((AdxFrame *)src)->scale & 0x1FFF) + 1;
        src += 2;
        for (j = 0; j < 16; j++) {
            b = *src;
            src++;
            v = (b >> 4) * scale + ((k0 * d1 + k1 * d2) >> 12);
            ADX_CLIP16(v);
            out[0] = v;
            d2 = d1;
            d1 = v;
            b = adx_signed_nibbles[b & 0xF];
            v = b * scale + ((k0 * d1 + k1 * d2) >> 12);
            ADX_CLIP16(v);
            out[1] = v;
            d2 = d1;
            d1 = v;
            out += 2;
        }
    }
    dly[0] = d1;
    dly[1] = d2;
    return nblk;
}
