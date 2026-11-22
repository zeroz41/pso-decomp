#define PSO_SDK_COMPACT_MATH
#include "types.h"
#include <dolphin/gx/GXFrameBuffer.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/unk/text_803E2008.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"

void TParticleCtrl::begin_effect_render() { TObjPlayer::reset_particle_counter(); apply_scene_fog(); }

void TParticleCtrl::end_effect_render() { TObjPlayer::set_effect_active(); apply_scene_fog(); }

void set_copy_clear_color_argb(u32 argb, s32, s32) {
    GXColor c;
    c.a = argb >> 24;
    c.r = argb >> 16;
    c.g = argb >> 8;
    c.b = argb;
    GXSetCopyClear(c, GX_MAX_Z24);
}
