#include "types.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/render_util.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/player/TObjPlayer.h"


extern s32 model_render_flags;

void TObjEnemy::set_param(s32 v) { *(s32 *)&this->control = v; }

void initialize_enemy_photon_effect(TObjEnemy *enemy) { enemy->register_by_id(); }

void TObjEnemy::render_shadows() {
    if (test_actor_flags(0x800) == 0) {
        this->set_shadow_flag();
        model_render_flags |= 0xC10;
        set_chunk_material_override_pair(-1, 0x800);
        set_shadow_material_state();
        this->render();
        this->clear_shadow_flag();
        model_render_flags &= ~0xC10;
    }
}
