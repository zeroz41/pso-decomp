#ifndef PSO_UNK_TLOBBY_803C4698_H
#define PSO_UNK_TLOBBY_803C4698_H

#include "types.h"

extern "C" {
s32 sub_803C4910(u8 *hdr, s32 size, s16 *len, u8 *out_0C, s8 *bits, s8 *block_bytes, u8 *channels, s32 *rate, s32 *samples, s32 *block_samples);
s32 TLobby__sub_803C48C8(u8 *hdr, s32 size, u16 *arg2);
s32 sub_803C46DC(u8 *hdr, s32 size, s32 *o1, s16 *o2, s16 *o3, s32 *o4, s32 *o5, s32 *o6, s32 *o7);
void num_to_str_803C526C(s32 v, char *out, s32 n);
}
s32 decode_adx_stereo(s8 *src, s32 nblk, s16 *outl, s16 *dlyl, s16 *outr, s16 *dlyr, s16 k0, s16 k1);
s32 decode_adx_stereo_downmix(s8 *src, s32 nblk, s16 *outl, s16 *dlyl, s16 *outr, s16 *dlyr, s16 k0, s16 k1);

#endif
