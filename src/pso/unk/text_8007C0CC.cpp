#include "types.h"
#include "pso/unk/TLobby_8007C550.h"
#include "pso/unk/text_8007C0CC.h"
#include "pso/system/byteswap.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct Crypt_8007C438 { s32 pos; u32 k[0x38]; };

struct R_8007C48C { s32 f0; s32 tbl[55]; s32 fe0; s32 fe4; };

extern "C" {
void subtractive_rng_refill(Crypt_8007C438 *c);
void subtractive_rng_seed(R_8007C48C *arg0, s32 arg1);
extern void* memcpy(void*,const void*,u32);
u8 save_block_shuffle_permutation[256];
u8 save_block_unshuffle_permutation[256];

void TAdSinglePlyChrSelectGC::apply_rng_cipher(u32 *data, s32 len) {
    s32 i;
    s32 n = (len + 3) / 4;
    for (i = 0; i < n; i++) {
        data[i] = subtractive_rng_next(((s32 *)this)) - data[i];
    }
}

void subtractive_rng_unshuffle(void* stream,const u8* source,u8* destination,u32 size) {
 u32 block,i;
 memcpy(destination,source,size);
 for(block=0;block<(size>>8);block++) {
  for(i=0;i<256;i++) destination[(block<<8)+save_block_unshuffle_permutation[i]]=source[(block<<8)+i];
 }
}

void TAdSinglePlyChrSelectGC::permute_save_blocks(void* stream, const u8* source, u8* destination, u32 size) {
 u32 block,i;
 memcpy(destination,source,size);
 for(block=0;block<(size>>8);block++) {
  for(i=0;i<256;i++) destination[(block<<8)+save_block_shuffle_permutation[i]]=source[(block<<8)+i];
 }
}

void subtractive_rng_make_shuffle(s32* stream) {
 s32 i; u16 index; u8 value;
 for(i=0;i<256;i++) save_block_shuffle_permutation[i]=(u8)i;
 for(i=255;i>=0;i--) {
  index=TAdSinglePlyChrSelectGC__sub_8007C584(stream,i+1);
  value=save_block_shuffle_permutation[index];
  save_block_shuffle_permutation[index]=save_block_shuffle_permutation[i];
  save_block_unshuffle_permutation[value]=(u8)i;
  save_block_shuffle_permutation[i]=value;
 }
}

void TAdSinglePlyChrSelectGC::crypt_data_be(u32 *data, s32 len) {
    u32 *p;
    s32 i;
    s32 n = (len + 3) / 4;
    for (i = 0; i < n; i++) {
        p = &data[i];
        bswap_32(p);
        *p ^= subtractive_rng_next(((s32 *)this));
        bswap_32(p);
    }
}

void subtractive_rng_xor_buffer(s32 *self, u32 *data, s32 len) {
    s32 i;
    s32 n = (len + 3) / 4;
    for (i = 0; i < n; i++) {
        data[i] ^= subtractive_rng_next(self);
    }
}

s32 subtractive_rng_next(s32 *arg0) {
    s32 temp_r4;
    temp_r4 = *arg0;
    *arg0 = temp_r4 + 1;
    if (temp_r4 + 1 > 0x37) {
        subtractive_rng_refill((Crypt_8007C438 *)(arg0));
        *arg0 = 1;
    }
    return arg0[*arg0 + 1];
}
void subtractive_rng_refill(Crypt_8007C438 *c) {
    s32 i;
    for (i = 1; i < 0x19; i++) {
        c->k[i] -= c->k[i + 0x1F];
    }
    for (i = 0x19; i < 0x38; i++) {
        c->k[i] -= c->k[i - 0x18];
    }
}
void subtractive_rng_seed(R_8007C48C *arg0, s32 arg1) {
    s32 x;
    s32 idx;
    s32 a;
    s32 i;
    arg0->fe4 = arg1;
    arg0->fe0 = arg1;
    a = 1;
    for (i = 1; i < 0x37; i++) {
        idx = (0x15 * i) % 0x37;
        arg0->tbl[idx] = a;
        a = arg1 - a;
        arg1 = arg0->tbl[idx];
    }
    subtractive_rng_refill((Crypt_8007C438 *)arg0);
    subtractive_rng_refill((Crypt_8007C438 *)arg0);
    subtractive_rng_refill((Crypt_8007C438 *)arg0);
    subtractive_rng_refill((Crypt_8007C438 *)arg0);
    arg0->f0 = 0x37;
}

}
