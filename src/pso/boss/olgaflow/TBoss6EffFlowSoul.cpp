#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma readonly_strings on
#include "pso/boss/olgaflow/TBoss6EffFlowSoul.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"

#include "pso/player/TObjPlayer.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
const char *TBoss6EffFlowSoul__name = "TBoss6EffFlowSoul";
}

void TBoss6EffFlowSoul::run_task() {
    Vec target;
    Vec d;
    TObjPlayer *p;
    f32 remain;
    f32 k;

    if (TObjEneDD::query_teammate_state() != 0) {
        return;
    }
    if (player == 0xFFFF) {
        owner->copy_pos_620(&target);
    } else {
        p = get_player_by_client_id(player);
        if (p != NULL && TBoss6PlotFalz::is_state_1f(p) != 0) {
            VecCopy(&target, &p->position);
            target.y += 10.0f;
        } else {
            queue_destruction();
            return;
        }
    }
    remain = (f32)(duration - age);
    if (remain <= 1e-05f) {
        VecCopy(&position, &target);
    } else {
        VecCopy(&d, &target);
        subtract_vector(&d, &position);
        k = 1.0f / remain;
        d.x *= k;
        d.y *= k;
        d.z *= k;
        vec3_add_to(&position, &d);
    }
    if (emitter != NULL) {
        emitter->set_position(&position);
    }
    age++;
    if (age > duration) {
        queue_destruction();
    }
}

TBoss6EffFlowSoul::~TBoss6EffFlowSoul() {
    if (emitter != nullptr) TParticleCtrl::release(emitter);
}

TBoss6EffFlowSoul::TBoss6EffFlowSoul(TObject *parent, Vec *pos, s32 player, s32 duration) : TObject(parent) {
    m_name = TBoss6EffFlowSoul__name;
    owner = static_cast<TBoss6Type2 *>(parent);
    VecCopy(&position, pos);
    this->player = player;
    this->duration = duration;
    if ((emitter = create_particle_emitter(&position, 0x225)) != NULL) {
        emitter->set_flags(0x40);
    }
    age = 0;
}
