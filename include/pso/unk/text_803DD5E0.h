#ifndef PSO_UNK_TEXT_803DD5E0_H
#define PSO_UNK_TEXT_803DD5E0_H

#include "types.h"

extern "C" {
void TLobby__sub_803DDD20(s32 arg0);
s32 TLobby__sub_803DDD2C(s32 arg0);
void TLobby__sub_803DDD40(s32 arg0, s32 arg1);
}
s32 calc_gvm_entry_stride(u16 arg0);
extern "C" {
void *load_nj_chunk_model_resource(u8 *base, u32 *off, u32 *out);
}
void set_ginja_draw_flags(s32 arg0);

// Saved polygon-list positions, indexed by the chunk cache command's slot.
extern s16 *chunk_polygon_list_cache[0x7E];

// --- C functions defined in text_803DD5E0.cpp ---
extern "C" {
void TLobby__sub_803DDD20(s32 arg0);
s32 TLobby__sub_803DDD2C(s32 arg0);
void TLobby__sub_803DDD40(s32 arg0, s32 arg1);
void *load_nj_chunk_model_resource(u8 *base, u32 *off, u32 *out);
}
// --- end of C functions

#endif
