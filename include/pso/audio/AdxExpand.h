#ifndef PSO_AUDIO_ADXEXPAND_H
#define PSO_AUDIO_ADXEXPAND_H

#include "types.h"

struct AdxDecoderChannel {
    s32 used;
    s32 id;
    s32 pad_08;
    s32 state;
    s32 decoded_count;
    s32 decode_mode;
    s8 *src;
    s32 nblk;
    s16 *out_buf;
    s16 *out_right_buf;
    s16 delay_samples[4];
    s16 coef_k0;
    s16 coef_k1;

    static void clear_pool();
    void update_receive_check();
    s32 get_decoded_count();
    void clear_done_state();
    void reset_client_state();
    s32 post_request(s8 *src, s32 nblk, s16 *out_left, s16 *out_right);
    s32 try_post_command(s8 *src, s32 nblk, s16 *out_buf);
    s32 get_state();
    void clear_record_data();
    void calc_adx_coeffs_at_offset(s32 rate, s32 cutoff);
};
LAYOUT_ASSERT(AdxDecoderChannel_size, sizeof(AdxDecoderChannel) == 0x34);

// --- C functions defined in AdxExpand.cpp ---
extern "C" {
extern AdxDecoderChannel adx_decoder_channel_pool[16];
extern s32 adx_expand_odd_result_flag;
void TLobby__sub_803CB4A4(AdxDecoderChannel *channel);
void TLobby__sub_803CB570(AdxDecoderChannel *channel, u8 *header, s16 *out_coefs);
AdxDecoderChannel *adx_allocate_decoder_channel(void);
}
// --- end of C functions

#endif
