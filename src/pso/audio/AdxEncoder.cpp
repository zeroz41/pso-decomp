#define PSO_SDK_COMPACT_MATH
#include <dolphin/os/OSThread.h>
#include "pso/unk/TLobby.h"
#undef PSO_SDK_COMPACT_MATH
#include <string.h>
#include "pso/audio/AdxEncoder.h"

#include "types.h"

struct PointerRecords_803C5E78_var_r31 { u8 bytes[0x2D0]; };

struct RecoveredGlobal_803C6830_lbl_80573AC0 {
    s32 value;
    u8 remaining[0x167C];
};

struct RecoveredGlobal_803C6800_lbl_80573AC0 {
    s32 value;
    u8 remaining[0x167C];
};

struct Strm_803C7C10;
struct Buf_803C7C10 { void *data; s32 size; };

struct VT_803C7C10 {
    void *pad[6];
    void (*lock)(Strm_803C7C10 *, s32, s32, Buf_803C7C10 *);
    void (*unlock)(Strm_803C7C10 *, s32, Buf_803C7C10 *);
    void (*commit)(Strm_803C7C10 *, s32, Buf_803C7C10 *);
};

struct Strm_803C7C10 { VT_803C7C10 *vt; };

struct Obj_803C7C10 {
    u8 pad_0[0xC]; Strm_803C7C10 *fc; u8 pad_10[0x58 - 0x10]; s32 f58; u8 pad_5c[0x290 - 0x5C];
    s16 f290[12]; u8 f2a8[1][16];
};

struct Strm_803C6860;
struct Buf_803C6860 { void *data; s32 size; };

struct VT_803C6860 {
    void *pad[6];
    void (*lock)(Strm_803C6860 *, s32, s32, Buf_803C6860 *);
    void (*unlock)(Strm_803C6860 *, s32, Buf_803C6860 *);
    void (*commit)(Strm_803C6860 *, s32, Buf_803C6860 *);
};

struct Strm_803C6860 { VT_803C6860 *vt; };

struct Obj_803C6860 {
    u8 pad_0[0x48];
    s32 f48;
    s32 f4c;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5c;
    s32 f60;
    s32 f64;
    s32 f68;
    s32 f6c;
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7c;
    u8 pad_80[0x2C8 - 0x80];
    s16 f2c8;
    s16 f2ca;
    s16 f2cc;
    s16 f2ce;
};

struct Buf_803C7748 { void *data; s32 size; };
struct Strm_803C7748;
struct VT_803C7748 {
    void *pad[6];
    void (*lock)(Strm_803C7748 *, s32, s32, Buf_803C7748 *);
    void (*unlock)(Strm_803C7748 *, s32, Buf_803C7748 *);
    void (*commit)(Strm_803C7748 *, s32, Buf_803C7748 *);
    s32 (*avail)(Strm_803C7748 *, s32);
};
struct Strm_803C7748 { VT_803C7748 *vt; };
struct Obj_803C7748 {
    u8 pad_0[0xC]; Strm_803C7748 *fc; u8 pad_10[0x2C - 0x10]; s32 f2c; u8 pad_30[0x50 - 0x30];
    s32 f50; u8 pad_54[0x6C - 0x54]; s32 f6c;
};

/* ADX encoder work objects (CRI ADX encoder, statically pooled in this unit).
   Field names follow the ADX header fields write_adx_header emits from them. */
struct AdxEncCoef {                /* calc_adx_predictor_coeffs outputs */
    s16 coef1;
    s16 coef2;
};

struct AdxEncHistory {             /* 0x0C, pool of 16 */
    s8 used;
    u8 pad_1[3];
    AdxEncCoef coef;
    s16 hist1;
    s16 hist2;
};

struct AdxEncChannel {             /* 0x90, pool of 16 */
    s8 used;
    u8 pad_1[3];
    AdxEncCoef coef;
    u8 pad_8[0xC];
    s32 block_samples;
    s16 samples[32];
    u8 pad_58[0x24];
    s16 scale;
    u8 pad_7e[2];
    f64 inv_scale;
    AdxEncHistory *history;
    u8 pad_8c[4];
};

struct AdxEncoder {                /* 0x2D0, pool of 8 */
    s8 used;
    s8 state;
    s8 num_inputs;
    u8 end_of_input;
    Strm_803C5B50 *input[2];
    Strm_803C5B50 *output;
    u8 pad_10[0x18];
    s32 pad_28;
    s32 bytes_written;
    s32 samples_encoded;
    s32 pad_34;
    s32 pad_38;
    s32 total_samples;
    s32 pad_40;
    s32 block_samples;
    s32 data_offset;
    s32 encoding_type;
    s32 block_size;
    s32 sample_bits;
    s32 channels;
    s32 sample_rate;
    s32 header_samples;
    s32 highpass_freq;
    s32 loop_type;
    s32 loop_count;
    s32 loop_start_sample;
    s32 loop_start_byte;
    s32 loop_end_sample;
    s32 loop_end_byte;
    AdxEncChannel *channel[2];
    s16 hist1[2];
    s16 hist2[2];
    s16 pcm[2][32];
    s16 input_samples[2][32];
    s16 clamped_samples[2][32];
    s16 decoded_samples[2][32];
    s16 block_scale[2];
    u8 pad_294[4];
    f64 block_inv_scale[2];
    u8 block_data[2][16];
    s16 start_hist1[2];
    s16 start_hist2[2];
};

#define ADXENC_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ADXENC_MIN(a, b) (((a) < (b)) ? (a) : (b))

extern "C" {
s32 TLobby__sub_803C5ED4(int);
s32 adx_encode_available_blocks(void *);
extern RecoveredGlobal_803C6830_lbl_80573AC0 adx_encoder_context_pool;

typedef char PointerRecords_803C5E78_var_r31_size[sizeof(PointerRecords_803C5E78_var_r31)==0x2D0?1:-1];
void TLobby__sub_803C5E78(void) {
    s32 var_r30;
    u8 *var_r31;
    var_r31 = (u8 *)(((u8 *)&adx_encoder_context_pool));
    var_r30 = 0;
    do {
        if ((s32) *(u8 *)((s8 *)((u8 *)&((PointerRecords_803C5E78_var_r31 *)var_r31)[var_r30]) + 0) == 1) {
            TLobby__sub_803C5ED4((int) (((u8 *)&((PointerRecords_803C5E78_var_r31 *)var_r31)[var_r30])));
        }
        var_r30 += 1;
    } while (var_r30 < 8);
}

void adx_process_encoder_output(u8 *arg0p) {
    struct Fields_arg0 { u8 pad_0[1]; s8 field_1; u8 pad_2[1]; u8 field_3; u8 pad_4[40]; s32 field_2C; s32 field_30; u8 pad_34[8]; s32 field_3C; };
    s32 temp_r3;
loop_1:
    if ((s8) ((Fields_arg0*)arg0p)->field_3 == 0) {
loop_2:
        temp_r3 = adx_encode_available_blocks(arg0p);
        if (temp_r3 != 0) {
            ((Fields_arg0*)arg0p)->field_2C = (s32) (((Fields_arg0*)arg0p)->field_2C + temp_r3);
            if ((s32) ((Fields_arg0*)arg0p)->field_30 >= (s32) ((Fields_arg0*)arg0p)->field_3C) {
                ((Fields_arg0*)arg0p)->field_3 = 1U;
                goto loop_1;
            }
            goto loop_2;
        }
    } else if (TLobby::write_zero_padded_block(arg0p) > 0) {
        ((Fields_arg0*)arg0p)->field_1 = 3;
    }
}

void TLobby__sub_803C60F0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    *(s32 *)((s8 *)arg0 + 0x58) = arg1;
    *(s32 *)((s8 *)arg0 + 0x5C) = arg2;
    *(s32 *)((s8 *)arg0 + 0x3C) = arg3;
    *(s32 *)((s8 *)arg0 + 0x60) = arg3;
    *(s32 *)((s8 *)arg0 + 0x48) = 0x11C;
}

void TLobby__sub_803C610C(u8 *arg0) {
    *(s8 *)((s8 *)arg0 + 3) = 1;
}

void TLobby__sub_803C6118(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x28) = 0;
    *(s32 *)((s8 *)arg0 + 0x2C) = 0;
    *(s32 *)((s8 *)arg0 + 0x30) = 0;
    *(s8 *)((s8 *)arg0 + 3) = 0;
    *(s8 *)((s8 *)arg0 + 1) = 1;
}

typedef char RecoveredGlobal_803C6830_lbl_80573AC0_size[sizeof(RecoveredGlobal_803C6830_lbl_80573AC0) == 0x1680 ? 1 : -1];

typedef char RecoveredGlobal_803C6800_lbl_80573AC0_size[sizeof(RecoveredGlobal_803C6800_lbl_80573AC0) == 0x1680 ? 1 : -1];

void TLobby__sub_803C6138(S_803C6138 *arg0) {
    u8 *p;
    if (arg0 != NULL) {
        TLobby::init_once();
        p = arg0->f80;
        if (p != NULL && p != NULL) {
            *p = 0;
            memset(p, 0, 0x90);
        }
        p = arg0->f84;
        if (p != NULL && p != NULL) {
            *p = 0;
            memset(p, 0, 0x90);
        }
        memset(arg0, 0, 4);
        TLobby::release_ref();
    }
}

void TLobby::clear_net_buffer_1680() {
    memset((void *) (&(*(RecoveredGlobal_803C6800_lbl_80573AC0 *)&adx_encoder_context_pool).value), 0, 0x1680);
}

void TLobby::clear_buffer_1680() {
    memset(&adx_encoder_context_pool.value, 0, 0x1680);
}
u32 strlen(const char *);
extern char *lbl_805D4664;

#pragma push
#pragma opt_propagation off
#pragma dont_inline off
#pragma inline_depth(4)

inline s32 put8_803C6860(Strm_803C6860 *s, const void *v) {
    Buf_803C6860 b;
    s->vt->lock(s, 0, 1, &b);
    if (b.size < 1) {
        s->vt->unlock(s, 0, &b);
        return 0;
    }
    memcpy(b.data, v, 1);
    s->vt->commit(s, 1, &b);
    return 1;
}

inline s32 put16_803C6860(Strm_803C6860 *s, const void *v) {
    Buf_803C6860 b;
    s->vt->lock(s, 0, 2, &b);
    if (b.size < 2) {
        s->vt->unlock(s, 0, &b);
        return 0;
    }
    s16 *d = (s16 *)b.data;
    *d = *(const s16 *)v;
    s->vt->commit(s, 1, &b);
    return 1;
}

inline s32 put32_803C6860(Strm_803C6860 *s, const void *v) {
    Buf_803C6860 b;
    s->vt->lock(s, 0, 4, &b);
    if (b.size < 4) {
        s->vt->unlock(s, 0, &b);
        return 0;
    }
    s32 *d = (s32 *)b.data;
    *d = *(const s32 *)v;
    s->vt->commit(s, 1, &b);
    return 1;
}

inline s32 putn_803C6860(Strm_803C6860 *s, void *src, s32 n) {
    Buf_803C6860 b;
    s->vt->lock(s, 0, n, &b);
    if (b.size < n) {
        s->vt->unlock(s, 0, &b);
        return 0;
    }
    memcpy(b.data, src, (u16)n);
    s->vt->commit(s, 1, &b);
    return n;
}

s32 write_adx_header__6TLobbyFPvPv(Obj_803C6860 *o, Strm_803C6860 *s) {
    u8 c;
    u16 h;
    u16 h2;
    s32 w;
    s32 len;
    s32 total;
    s32 i;
    s32 lim;

    len = strlen(lbl_805D4664);
    h = 0x8000;
    if (put16_803C6860(s, &h) != 1) {
        goto fail;
    }
    h2 = o->f48;
    if (put16_803C6860(s, &h2) != 1) {
        goto fail;
    }
    c = o->f4c;
    if (put8_803C6860(s, &c) != 1) {
        goto fail;
    }
    c = o->f50;
    if (put8_803C6860(s, &c) != 1) {
        goto fail;
    }
    c = o->f54;
    if (put8_803C6860(s, &c) != 1) {
        goto fail;
    }
    c = o->f58;
    if (put8_803C6860(s, &c) != 1) {
        goto fail;
    }
    w = o->f5c;
    if (put32_803C6860(s, &w) != 1) {
        goto fail;
    }
    w = o->f60;
    if (put32_803C6860(s, &w) != 1) {
        goto fail;
    }
    h = o->f64;
    if (put16_803C6860(s, &h) != 1) {
        goto fail;
    }
    c = 4;
    if (put8_803C6860(s, &c) != 1) {
        goto fail;
    }
    c = 0;
    if (put8_803C6860(s, &c) != 1) {
        goto fail;
    }
    w = 0;
    if (put32_803C6860(s, &w) != 1) {
        goto fail;
    }
    h = o->f2c8;
    if (put16_803C6860(s, &h) != 1) {
        goto fail;
    }
    h = o->f2cc;
    if (put16_803C6860(s, &h) != 1) {
        goto fail;
    }
    h = o->f2ca;
    if (put16_803C6860(s, &h) != 1) {
        goto fail;
    }
    h = o->f2ce;
    if (put16_803C6860(s, &h) != 1) {
        goto fail;
    }
    total = 0x1C;
    if (o->f6c > 0) {
        h = o->f68;
        if (put16_803C6860(s, &h) != 1) {
            goto fail;
        }
        h = o->f6c;
        if (put16_803C6860(s, &h) != 1) {
            goto fail;
        }
        total += 4;
        for (i = 0; i < o->f6c; i++) {
            h = i;
            if (put16_803C6860(s, &h) != 1) {
                goto fail;
            }
            h = 1;
            if (put16_803C6860(s, &h) != 1) {
                goto fail;
            }
            w = o->f70;
            if (put32_803C6860(s, &w) != 1) {
                goto fail;
            }
            w = o->f74;
            if (put32_803C6860(s, &w) != 1) {
                goto fail;
            }
            w = o->f78;
            if (put32_803C6860(s, &w) != 1) {
                goto fail;
            }
            w = o->f7c;
            if (put32_803C6860(s, &w) != 1) {
                goto fail;
            }
            total += 0x14;
        }
    }
    c = 0;
    lim = o->f48 - len;
    for (; total < lim; total++) {
        if (put8_803C6860(s, &c) != 1) {
            goto fail;
        }
    }
    if (putn_803C6860(s, lbl_805D4664, len) != len) {
        goto fail;
    }
    total += len;
    return total + 4;
fail:
    return 0;
}

#pragma pop

#pragma push
#pragma opt_propagation off
#pragma inline_depth(4)
#pragma dont_inline off
inline void put16_803C7748(Strm_803C7748 *s, const void *src) {
    Buf_803C7748 b;
    s->vt->lock(s, 0, 2, &b);
    if (b.size < 2) {
        s->vt->unlock(s, 0, &b);
    } else {
        s16 *d = (s16 *)b.data;
        *d = *(const s16 *)src;
        s->vt->commit(s, 1, &b);
    }
}

inline void put_803C7748(Strm_803C7748 *s, void *src, s32 n) {
    Buf_803C7748 b;
    s->vt->lock(s, 0, n, &b);
    if (b.size < n) {
        s->vt->unlock(s, 0, &b);
    } else {
        memcpy(b.data, src, n);
        s->vt->commit(s, 1, &b);
    }
}

#define arg0 ((Obj_803C7748 *)arg0p)
s32 TLobby::write_zero_padded_block(void *arg0p) {
    s32 len;
    s32 n;
    s32 i;
    u16 w;
    u8 zero;
    Strm_803C7748 *s = arg0->fc;
    s32 off = arg0->f2c;

    if (arg0->f6c <= 0) {
        n = arg0->f50;
    } else {
        n = (((off + arg0->f50 + 0x7FF) / 2048) << 11) - off;
    }
    len = n - 4;
    if (s->vt->avail(s, 0) < n) {
        return 0;
    }
    w = 0x8001;
    put16_803C7748(s, &w);
    w = len;
    put16_803C7748(s, &w);
    zero = 0;
    for (i = 0; i < len; i++) {
        put_803C7748(s, &zero, 1);
    }
    return n;
}
#undef arg0
#pragma pop

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off
inline void put_803C7C10(Strm_803C7C10 *s, void *src, s32 n) {
    Buf_803C7C10 b;
    s->vt->lock(s, 0, n, &b);
    if (b.size < n) {
        s->vt->unlock(s, 0, &b);
    } else {
        memcpy(b.data, src, n);
        s->vt->commit(s, 1, &b);
    }
}
s32 adx_write_encoded_blocks(Obj_803C7C10 *arg0) {
    s32 i;
    s32 total;
    u8 c;
    Strm_803C7C10 *s = arg0->fc;
    i = 0;
    total = 0;
    for (; i < arg0->f58; i++) {
        s16 v = arg0->f290[i] - 1;
        c = v >> 8;
        put_803C7C10(s, &c, 1);
        c = v;
        put_803C7C10(s, &c, 1);
        put_803C7C10(s, arg0->f2a8[i], 16);
        total += 0x12;
    }
    return total;
}
#pragma pop

// Quantizes one block of channel ch to ADX nibbles (inferred: the ADX encoder's block step).
void TLobby__sub_803C7DF0(AdxEncoder *enc, s32 ch) {
    s32 i;
    s32 k;
    s32 per_byte;
    AdxEncChannel *c;
    s32 v;
    s32 q;
    s32 r;
    s16 *in;
    s16 *clamped;
    s16 *decoded;
    u8 *out;
    s32 b;

    in = enc->input_samples[ch];
    out = enc->block_data[ch];
    k = 0;
    per_byte = 8 / enc->sample_bits;
    c = enc->channel[ch];
    clamped = enc->clamped_samples[ch];
    b = -1;
    decoded = enc->decoded_samples[ch];
    for (i = 0; i < enc->block_samples; i++) {
        in[i] = (c == NULL) ? 0 : c->samples[i];
        v = (s32)(c->inv_scale * in[i]);
        r = ADXENC_MIN(0x7FFF, ADXENC_MAX(-0x8000, v));
        clamped[i] = r;
        if (clamped[i] < 0) {
            q = (r - 0x924) / 0x1249;
        } else {
            q = (r + 0x924) / 0x1249;
        }
        q = ADXENC_MIN(ADXENC_MAX(-8, q), 7);
        v = (s32)(c->inv_scale * (q * c->scale));
        r = ADXENC_MIN(0x7FFF, ADXENC_MAX(-0x8000, v));
        decoded[i] = r;
        if (i % per_byte == 0) {
            k = 1;
            b++;
            out[b] = 0;
        }
        out[b] |= (s8)(((u8)(q << (8 - enc->sample_bits)) >> (8 - enc->sample_bits)) << (enc->sample_bits * (per_byte - k)));
        k++;
    }
}
}

u32 adx_encoder_channel_work_pools[0x9C0 / 4];
RecoveredGlobal_803C6830_lbl_80573AC0 adx_encoder_context_pool;
