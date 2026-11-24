#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_80065C90_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_80065C90_H

#include "types.h"

struct Vec;
struct NJS_OBJECT;
struct NJS_TEXLIST;
struct AnimationMotion;
class TParticleCtrl;

// --- C functions defined in TBoss8Dragon_80065C90.cpp ---
extern "C" {
const Vec *get_arena_center(void);
void attach_particle_model(TParticleCtrl *particle, NJS_OBJECT *model, NJS_TEXLIST *texlist,
                           AnimationMotion *motion, s32 loop, f32 frame);
}
// --- end of C functions

#endif
