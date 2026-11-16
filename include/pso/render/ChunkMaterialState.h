#ifndef PSO_RENDER_CHUNKMATERIALSTATE_H
#define PSO_RENDER_CHUNKMATERIALSTATE_H
#include "types.h"
#include "pso/system/NinjaTypes.h"
extern "C" {
void set_chunk_material_override_pair(s32 first, s32 second);
}
void submit_chunk_material_color(u8 chunkType, s16 *packedMaterial);
// Sets the material colour the constant-material draw uses, each channel
// clamped to [-1, 1] (njSetConstantMaterial).
void set_constant_material(const NJS_ARGB *color);
extern "C" {
f32 clampMaterialChannel(f32 value, f32 lower, f32 upper);
void set_chunk_material_override_pair(s32 arg0, s32 arg1);
}

// keyboard_control_pad_slots: layout known from its uses only.
struct KeyboardControlPadSlots { s32 value; u8 remaining[0xCC]; };
extern KeyboardControlPadSlots keyboard_control_pad_slots;

#endif
