#ifndef PSO_UNK_TEXT_803DA798_H
#define PSO_UNK_TEXT_803DA798_H

#include "types.h"

struct GinjaTextureHeader;
struct GinjaTextureList;
struct GinjaTextureState;

// The image description at the start of a GVRT chunk: GX format and attribute bits, then the size.
struct GvrTextureDesc {
    u32 format;
    u16 width;
    u16 height;
};

extern "C" {
void TObjPlayer__sub_803DA7E0(void);
void TObjPlayer__sub_803DA808(void *buf, saddr src, u32 size);
s32 TObjPlayer__sub_803DA84C(GinjaTextureHeader *header, s32 src, s32 offset, s32 length);
s32 TObjPlayer__sub_803DA8B4(GinjaTextureHeader *header, s32 src);
s32 TObjPlayer__sub_803DA8E4(u32 id, u32 tlut_name, s32 format, s32 *slot);
s32 TObjPlayer__sub_803DAA70(u32 id, u32 tlut_name, GvrTextureDesc *desc);
void TObjPlayer__sub_803DAB7C(GinjaTextureList *list, s32 index, s32 slot);
s32 TObjPlayer__sub_803DAB9C(s32 slot, s32 src);
void TObjPlayer__sub_803DAC1C(s32 slot);
s32 TObjPlayer__sub_803DAC48(GinjaTextureList *list, s32 index, u32 id, u32 tlut_name, GvrTextureDesc *desc, s32 *slot);
void TObjPlayer__sub_803DAD24(GinjaTextureState *texture);
s32 TObjPlayer__sub_803DAD28(u32 id);
s32 TObjPlayer__sub_803DAD84(GinjaTextureState *texture, s32 src, u32 arg2);
s32 TObjPlayer__sub_803DAE1C(s32 index, s32 src, u32 arg2);
}
s32 set_texture_num(s32 i);

#endif
