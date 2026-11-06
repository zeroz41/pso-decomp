#ifndef PSO_TEFFECT_H
#define PSO_TEFFECT_H
#include "pso/system/task/TObject.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/mtx.h>

// Base of the one-shot effects that live on the particle task list.
class TEffect : public TObject {
public:
    TEffect();
    virtual ~TEffect();

    u32 source;
    Vec position;
    NJS_ARGB color;
    Vec scale;
    Vec direction;
    s32 angles[3];
    f32 field_60;
    f32 speed;
    s32 age;
    u32 state;
};
#include <stddef.h>
typedef char EffectSize[(sizeof(TEffect) == 0x70) ? 1 : -1];
typedef char EffectPositionOffset[(offsetof(TEffect, position) == 0x20) ? 1 : -1];
typedef char EffectScaleOffset[(offsetof(TEffect, scale) == 0x3C) ? 1 : -1];
typedef char EffectAgeOffset[(offsetof(TEffect, age) == 0x68) ? 1 : -1];

// One frame of an animated texture list, put into a slot of the texture list
// a model draws with.
struct TextureFrameSlot {
    GinjaTextureList *frames;
    GinjaTextureList *texlist;
    s32 frame;
    s32 slot;
};

// The particle textures from effect_nt.gvm, bound by load_effect_resources.
__declspec(section ".data") extern GinjaTextureList shared_effect_texture_list;
// EFFECT_NT.REL, the effect models.
extern s32 effect_rel;

void approach_vector_in_place(Vec *current, const Vec *target, f32 step);
s32 approach_alpha_clamped(f32 *current, const f32 *target, f32 step);
void approach_rgb_clamped(NJS_ARGB *current, const NJS_ARGB *target, f32 step);
s32 find_particle_texture_index(s32 id);
void copy_slot_to_anim_frame(TextureFrameSlot *slot);
void copy_anim_frame_to_slot(TextureFrameSlot *slot);
void free_effect_resources();
void load_effect_resources();

#endif
