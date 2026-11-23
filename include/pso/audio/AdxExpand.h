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
    s32 src;
    s32 nblk;
    s32 out_buf;
    s32 out_right_buf;
    s16 delay_samples[4];
    s16 coef_k0;
    s16 coef_k1;
};
LAYOUT_ASSERT(AdxDecoderChannel_size, sizeof(AdxDecoderChannel) == 0x34);

// --- C functions defined in AdxExpand.cpp ---
extern "C" {
extern AdxDecoderChannel adx_decoder_channel_pool[16];
extern s32 adx_expand_odd_result_flag;
void TLobby__sub_803CB4A4(u8 *channel_buf);
void TLobby__sub_803CB570(u8 *channel_buf, u8 *header, s16 *out_coefs);
AdxDecoderChannel *adx_allocate_decoder_channel(void);
u32 dispatch_receive_update__6TLobbyFv(int src, int nblk, int out_left, void *dly_left,
                                       int out_right, void *dly_right, int k0, int k1);
}
// --- end of C functions

#endif
