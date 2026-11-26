#include <string.h>
#include <dolphin/os/OSThread.h>
#include "pso/audio/AdxDecode4.h"
#include "pso/audio/AdxExpand.h"
#include "pso/audio/AdxHeader.h"
#include "pso/network/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/audio/CriSvm.h"

extern "C" {
s32 adx_expand_odd_result_flag;

void AdxDecoderChannel::update_receive_check() {
    if (state == 1) {
        state = 2;
    }
    if (state == 2) {
        if (decode_mode == 1) {
            decoded_count = decode_adx_mono_blocks(src, nblk, out_buf, delay_samples, coef_k0, coef_k1);
        } else {
            decoded_count = adx_decode_stereo_blocks(src, nblk, out_buf, delay_samples, out_right_buf,
                                                     &delay_samples[2], coef_k0, coef_k1);
            if (decoded_count % 2 == 1) {
                adx_expand_odd_result_flag = 1;
            }
        }
        state = 3;
    }
}

s32 AdxDecoderChannel::get_decoded_count() {
    return decoded_count;
}

void AdxDecoderChannel::clear_done_state() {
    if (state == 3) {
        state = 0;
    }
}

void AdxDecoderChannel::reset_client_state() {
    state = 0;
    memset(delay_samples, 0, sizeof(delay_samples));
}

void TLobby__sub_803CB4A4(AdxDecoderChannel *channel) {
    if (channel->state == 0) {
        channel->decoded_count = 0;
        channel->state = 1;
    }
}

s32 AdxDecoderChannel::post_request(s8 *src, s32 nblk, s16 *out_left, s16 *out_right) {
    if (state == 0) {
        decode_mode = 2;
        this->src = src;
        this->nblk = nblk;
        out_buf = out_left;
        out_right_buf = out_right;
        return 1;
    }
    return 0;
}

s32 AdxDecoderChannel::try_post_command(s8 *src, s32 nblk, s16 *out_buf) {
    if (state == 0) {
        decode_mode = 1;
        this->src = src;
        this->nblk = nblk;
        this->out_buf = out_buf;
        out_right_buf = NULL;
        return 1;
    }
    return 0;
}

s32 AdxDecoderChannel::get_state() {
    return state;
}

void AdxDecoderChannel::clear_record_data() {
    if (this != NULL) {
        used = 0;
        memset(this, 0, sizeof(AdxDecoderChannel));
    }
}

void TLobby__sub_803CB570(AdxDecoderChannel *channel, u8 *header, s16 *out_coefs) {
    s16 *header_samples = (s16 *)header;
    channel->delay_samples[0] = header_samples[0];
    channel->delay_samples[1] = *out_coefs;
    channel->delay_samples[2] = header_samples[1];
    channel->delay_samples[2] = header_samples[1];
}

#pragma push
#pragma fp_contract on
void AdxDecoderChannel::calc_adx_coeffs_at_offset(s32 rate, s32 cutoff) {
    calc_adx_predictor_coeffs(cutoff, rate, &coef_k0, &coef_k1);
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

void AdxDecoderChannel::clear_pool() {
    memset(adx_decoder_channel_pool, 0, sizeof(adx_decoder_channel_pool));
}

}

AdxDecoderChannel adx_decoder_channel_pool[16];
