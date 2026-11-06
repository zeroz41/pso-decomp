#include "pso/audio/LscStream.h"
#include "pso/unk/TLobby_803C4698.h"
#include "pso/unk/TLobby_803CC0B4.h"
#include "pso/unk/text_803D31A4.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/system/RefCountedWorkBuffer.h"
#include "pso/audio/SjMemoryBuffer.h"
#include "pso/audio/SjRingBuffer.h"
#include "pso/unk/text_803CC294.h"
#include "pso/unk/text_803CE568.h"

#include "types.h"
#include "pso/unk/TLobby.h"

struct RecoveredGlobal_803C5850_lbl_80572020 {
    s32 value;
    u8 remaining[0xFC];
};

struct RecoveredGlobal_803C588C_lbl_80572020 {
    s32 value;
    u8 remaining[0xFC];
};

struct Hdr_803C46A4 { u16 type; s16 len; };

struct AdxFrame {
    s16 scale;
    s8 nibbles[16];
};

typedef void (*RecoveredCallback_e2efd47cbcab)(s32, char *);

struct Fmt_803C46DC { s16 a; s16 b; s16 c; s16 d; s32 e; s32 f; s32 g; s32 h; };

extern "C" {
s32 memset(void *, int, int);
extern RecoveredGlobal_803C5850_lbl_80572020 adx_error_message_buffer;
extern s32 lobby_error_callback;
extern s32 tlobby_error_callback_arg;
char *strncpy(char *dst, const char *src, u32 n);
void strncat(char *buf, s32 arg, s32 n);
void TLobby__sub_803D38B4(const char *fmt, ...);
void flush_update__6TLobbyFv(void *, int);
extern u8 adx_stream_player_pool[];
extern s32 lbl_805D4658;
extern s32 TLobby_init_ref_count;
extern s32 TLobby__svm_cb_svr_handle;
extern s32 lbl_805D7540;
extern const s32 lbl_805E0D30;
s32 strlen(const char *);
char number_format_digit_buffer[0x20];
RecoveredGlobal_803C5850_lbl_80572020 adx_error_message_buffer;
extern const char lbl_805E0D28[2];
// Sign-extend the low four bits in the same way as the high nibble.
extern const s32 adx_signed_nibbles[16] = {
    0, 1, 2, 3, 4, 5, 6, 7, -8, -7, -6, -5, -4, -3, -2, -1,
};
f64 cos(f64);
void calc_adx_predictor_coeffs(s32 cutoff, s32 rate, s16 *k0, s16 *k1);
s32 set_callback_params__6TLobbyFll();

extern s32 TLobby__init_ref_count;

void TLobby__sub_803C4698(void) {
    TLobby__init_ref_count = 0;
}

extern s32 lbl_805D7520;

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
#pragma dont_inline off
#pragma inline_depth(4)
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

typedef void (*Callback_803C5744)(s32 ctx, char *msg);

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void num_to_str_803C526C(s32 v, char *out, s32 n) {
    s32 i;
    s32 len;
    for (i = 0; i < 32; i++) {
        out[i] = v % 10;
        v /= 10;
        if (v == 0) {
            out[i] = 0;
            break;
        }
    }
    s32 sl = strlen(number_format_digit_buffer);
    len = n - 1;
    if (sl < len) {
        len = sl;
    }
    for (i = 0; i < len; i++) {
        out[i] = number_format_digit_buffer[len - 1 - i];
    }
    out[i] = 0;
}
void TLobby::format_number_pair(s32 arg0, s32 arg1, char *arg2, s32 arg3) {
    num_to_str_803C526C(arg0, arg2, arg3);
    strncat(arg2, (s32)lbl_805E0D28, arg3 - strlen(arg2) - 1);
    num_to_str_803C526C(arg1, arg2 + strlen(arg2), 4 - strlen(arg2));
}
#pragma pop

void TLobby::report_adx_error(const char *msg, s32 arg) {
    strncpy(((char *)&adx_error_message_buffer), msg, 0xFF);
    strncat(((char *)&adx_error_message_buffer), arg, 0xFF);
    if ((*(Callback_803C5744 *)&lobby_error_callback) != 0) {
        (*(Callback_803C5744 *)&lobby_error_callback)(tlobby_error_callback_arg, ((char *)&adx_error_message_buffer));
    }
    TLobby__sub_803D38B4(((char *)&adx_error_message_buffer));
}

void TLobby::notify_error(const char *arg0) {
    strncpy(((char *)&adx_error_message_buffer), arg0, 0xFF);
    if ((*(RecoveredCallback_e2efd47cbcab *)&lobby_error_callback) != NULL) {
        (*(RecoveredCallback_e2efd47cbcab *)&lobby_error_callback)(tlobby_error_callback_arg, ((char *)&adx_error_message_buffer));
    }
    TLobby__sub_803D38B4(((char *)&adx_error_message_buffer));
}

void TLobby::set_params(s32 arg0, s32 arg1) {
    lobby_error_callback = arg0;
    tlobby_error_callback_arg = arg1;
    set_callback_params__6TLobbyFll();
}

extern s32 lbl_805D7530;

typedef char RecoveredGlobal_803C5850_lbl_80572020_size[sizeof(RecoveredGlobal_803C5850_lbl_80572020) == 0x100 ? 1 : -1];
void TLobby::clear_error_callback() {
    memset(&adx_error_message_buffer.value, 0, 0x100);
    lobby_error_callback = 0;
    tlobby_error_callback_arg = 0;
}

typedef char RecoveredGlobal_803C588C_lbl_80572020_size[sizeof(RecoveredGlobal_803C588C_lbl_80572020) == 0x100 ? 1 : -1];
void TLobby::clear_error_callback_state() {
    memset((void *) (&(*(RecoveredGlobal_803C588C_lbl_80572020 *)&adx_error_message_buffer).value), 0, 0x100);
    lobby_error_callback = 0;
    tlobby_error_callback_arg = 0;
}

void ARAlloc(void) {
    if ((s32) lbl_805D7530 == 0) {
        TLobby::init_once();
        lbl_805D7530 = 1;
        update_active_stream_reads();
        lbl_805D7530 = 2;
        TLobby__sub_803CEF60();
        lbl_805D7530 = 5;
        update_active_stream_reads();
        lbl_805D7530 = 6;
        TLobby__sub_803CC884();
        lbl_805D7530 = 0;
        TLobby::release_ref();
    }
}

void TLobby::dec_ref_and_shutdown() {
    s32 temp_r0;

    temp_r0 = TLobby_init_ref_count - 1;
    TLobby_init_ref_count = temp_r0;
    if (temp_r0 == 0) {
        TLobby::shutdown_cleanup();
        TLobby::dec_ref_and_reset_tables();
        TLobby::si_get_type_async();
        lsc_shutdown();
        TLobby::init_once();
        TLobby::SVM_DelCbSvr(2, (s32)((void *) (1)));
        TLobby::SVM_DelCbSvr(2, (s32)((void *) (3)));
        TLobby::SVM_DelCbSvr(4, TLobby__svm_cb_svr_handle);
        TLobby__sub_803D3194();
        TLobby::release_ref();
        TLobby::init_once();
        TLobby::clear_session_buffer();
        TLobby::clear_error_callback();
        sj_memory_buffer_shutdown();
        sj_ring_buffer_shutdown();
        TLobby::dec_ref_and_clear_buffer();
        TLobby::release_ref();
    }
}
void TLobby::init_and_add_ref() {
    s32 v = lbl_805E0D30;
    if (TLobby_init_ref_count == 0) {
        ((void (*)(s32))TLobby__sub_803C4698)(v);
        TLobby::init_once();
        TLobby__sub_803D2ED4();
        sj_ring_buffer_init();
        sj_memory_buffer_init();
        TLobby::clear_error_callback_state();
        TLobby::clear_buffer_a00();
        TLobby::reset_sound_buffers();
        TLobby::init_afs_adxf_state();
        TLobby__sub_803CC114();
        flush_update__6TLobbyFv((void *)TLobby::forward_notify_error, 0);
        memset(adx_stream_player_pool, 0, 0xA80);
        lsc_init();
        if (lbl_805D4658 == 1) {
            TLobby::SVM_SetCbSvrId(2, 1, (s32)((void *)TLobby::get_state_zero), 0);
            TLobby::SVM_SetCbSvrId(2, 3, (s32)((void *)TLobby::ar_alloc), 0);
            TLobby__svm_cb_svr_handle = TLobby::svm_set_cb_svr(4, (s32)((void *)TLobby::process_connection_state), 0);
        }
        lbl_805D7540 = 0;
        TLobby::release_ref();
    }
    TLobby_init_ref_count += 1;
}
