#ifndef PSO_MISC_TEFFINDIRECTCTRL_802A88AC_H
#define PSO_MISC_TEFFINDIRECTCTRL_802A88AC_H

#include "types.h"

extern "C" {
u32 calc_i8_tiled_texel_offset(u8 x, u8 y, u32 w);
void deform_indirect_texture_scroll(u8 *p, u32 px, u32 py, s32 amp, u32 phase);
}
void deform_indirect_texture_wave(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5);
s32 get_indirect_source_id(u8 arg0);
extern "C" {
s32 get_indirect_source_pixels(u8 arg0);
}
s32 update_indirect_texture_wave(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5);

// --- C functions defined in TEffIndirectCtrl_802A88AC.cpp ---
extern "C" {
u32 calc_i8_tiled_texel_offset(u8 x, u8 y, u32 w);
void deform_indirect_texture_scroll(u8 *p, u32 px, u32 py, s32 amp, u32 phase);
s32 get_indirect_source_pixels(u8 arg0);
}
// --- end of C functions

#endif
