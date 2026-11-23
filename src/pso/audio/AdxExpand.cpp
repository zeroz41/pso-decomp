#include <string.h>
#include <dolphin/os/OSThread.h>
#include "pso/audio/AdxDecode4.h"
#include "pso/audio/AdxExpand.h"
#include "pso/audio/AdxHeader.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/unk/text_803D31A4.h"

static inline void adx_expand_update_impl(void *ptr) {
    AdxDecoderChannel *ch = (AdxDecoderChannel *)ptr;
    u32 decoded_blocks;
    u32 sign_bit;

    if (ch->state == 1) {
        ch->state = 2;
    }
    if (ch->state == 2) {
        if (ch->decode_mode == 1) {
            ch->decoded_count = decode_adx_mono_blocks((s8 *)ch->src, ch->nblk, (s16 *)ch->out_buf, ch->delay_samples,
                                                       ch->coef_k0, ch->coef_k1);
        } else {
            ch->decoded_count = dispatch_receive_update__6TLobbyFv(ch->src, ch->nblk, ch->out_buf, ch->delay_samples,
                                                                    ch->out_right_buf, &ch->delay_samples[2],
                                                                    ch->coef_k0, ch->coef_k1);
            decoded_blocks = (u32)ch->decoded_count;
            sign_bit = decoded_blocks >> 0x1FU;
            if ((s32)(((decoded_blocks & 1) ^ sign_bit) - sign_bit) == 1) {
                adx_expand_odd_result_flag = 1;
            }
        }
        ch->state = 3;
    }
}

static inline s32 adx_expand_get_size_impl(const void *ptr) {
    return ((const AdxDecoderChannel *)ptr)->decoded_count;
}

static inline void adx_expand_reset_state_impl(void *ptr) {
    AdxDecoderChannel *ch = (AdxDecoderChannel *)ptr;
    if (ch->state == 3) {
        ch->state = 0;
    }
}

static inline void adx_expand_reset_client_impl(void *ptr) {
    AdxDecoderChannel *ch = (AdxDecoderChannel *)ptr;
    ch->state = 0;
    memset(ch->delay_samples, 0, sizeof(ch->delay_samples));
}

static inline s32 adx_expand_is_idle_impl(const void *ptr) {
    return ((const AdxDecoderChannel *)ptr)->state == 0;
}

static inline void adx_expand_set_stereo_impl(void *ptr, s32 src, s32 nblk, s32 out_left, s32 out_right) {
    AdxDecoderChannel *ch = (AdxDecoderChannel *)ptr;
    ch->decode_mode = 2;
    ch->src = src;
    ch->nblk = nblk;
    ch->out_buf = out_left;
    ch->out_right_buf = out_right;
}

static inline void adx_expand_set_mono_impl(void *ptr, s32 src, s32 nblk, s32 out_buf) {
    AdxDecoderChannel *ch = (AdxDecoderChannel *)ptr;
    ch->decode_mode = 1;
    ch->src = src;
    ch->nblk = nblk;
    ch->out_buf = out_buf;
    ch->out_right_buf = 0;
}

static inline s32 adx_expand_get_state_impl(const void *ptr) {
    return ((const AdxDecoderChannel *)ptr)->state;
}

static inline void adx_expand_clear_impl(void *ptr) {
    AdxDecoderChannel *ch = (AdxDecoderChannel *)ptr;
    if (ch != NULL) {
        ch->used = 0;
        memset(ch, 0, sizeof(AdxDecoderChannel));
    }
}

static inline void adx_expand_calc_coeffs_impl(void *ptr, s32 rate, s32 cutoff) {
    AdxDecoderChannel *ch = (AdxDecoderChannel *)ptr;
    calc_adx_predictor_coeffs(cutoff, rate, &ch->coef_k0, &ch->coef_k1);
}

extern "C" {
s32 adx_expand_odd_result_flag;

void TLobby::update_receive_check() {
    adx_expand_update_impl(this);
}

s32 TLobby::get_size() {
    return adx_expand_get_size_impl(this);
}

void TLobby::reset_field_0C() {
    adx_expand_reset_state_impl(this);
}

void TLobby::reset_client_state() {
    adx_expand_reset_client_impl(this);
}

void TLobby__sub_803CB4A4(u8 *channel_buf) {
    AdxDecoderChannel *ch = (AdxDecoderChannel *)channel_buf;
    if (ch->state == 0) {
        ch->decoded_count = 0;
        ch->state = 1;
    }
}

s32 TLobby::post_request(s32 src, s32 nblk, s32 out_left, s32 out_right) {
    if (adx_expand_is_idle_impl(this)) {
        adx_expand_set_stereo_impl(this, src, nblk, out_left, out_right);
        return 1;
    }
    return 0;
}

s32 TLobby::try_post_command(s32 src, s32 nblk, s32 out_buf) {
    if (adx_expand_is_idle_impl(this)) {
        adx_expand_set_mono_impl(this, src, nblk, out_buf);
        return 1;
    }
    return 0;
}

s32 TLobby::get_client_count() {
    return adx_expand_get_state_impl(this);
}

void TLobby::clear_record_data() {
    adx_expand_clear_impl(this);
}

void TLobby__sub_803CB570(u8 *channel_buf, u8 *header, s16 *out_coefs) {
    AdxDecoderChannel *ch = (AdxDecoderChannel *)channel_buf;
    s16 *header_samples = (s16 *)header;
    ch->delay_samples[0] = header_samples[0];
    ch->delay_samples[1] = *out_coefs;
    ch->delay_samples[2] = header_samples[1];
    ch->delay_samples[2] = header_samples[1];
}

#pragma push
#pragma fp_contract on
void TLobby::calc_adx_coeffs_at_offset(s32 rate, s32 cutoff) {
    adx_expand_calc_coeffs_impl(this, rate, cutoff);
}
#pragma pop

AdxDecoderChannel *adx_allocate_decoder_channel(void) {
    s32 i;
    AdxDecoderChannel *c;

    for (i = 0; i < 16; i++) {
        if (adx_decoder_channel_pool[i].used == 0) {
            break;
        }
    }
    if (i == 16) {
        return NULL;
    }
    c = &adx_decoder_channel_pool[i];
    memset(c, 0, sizeof(AdxDecoderChannel));
    c->used = 1;
    c->id = i;
    c->pad_08 = 0;
    c->state = 0;
    calc_adx_predictor_coeffs(500, 44100, &c->coef_k0, &c->coef_k1);
    memset(c->delay_samples, 0, sizeof(c->delay_samples));
    return c;
}

void TLobby::clear_buffer_340() {
    memset(adx_decoder_channel_pool, 0, sizeof(adx_decoder_channel_pool));
}

}

AdxDecoderChannel adx_decoder_channel_pool[16];
