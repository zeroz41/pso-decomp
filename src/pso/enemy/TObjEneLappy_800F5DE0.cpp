#include "types.h"
#include "pso/enemy/TObjEneLappy_800F5DE0.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/render/render_util.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/misc/TWindowLockOn.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 obj_testFlags30__14TObjCollidableFUl(void *, s32);
extern s32 model_render_flags;

void TObjEnemy::set_param(s32 v) { *(s32 *)&this->control = v; }
}

void initialize_enemy_photon_effect(void* p) { ((TBoss3Volopt *)p)->reset_photon_effect(); }

void TObjEnemy::render_shadows() {
    if (obj_testFlags30__14TObjCollidableFUl(this, 0x800) == 0) {
        this->set_shadow_flag();
        model_render_flags |= 0xC10;
        set_chunk_material_override_pair(-1, 0x800);
        set_shadow_material_state();
        this->render();
        this->clear_shadow_flag();
        model_render_flags &= ~0xC10;
    }
}
