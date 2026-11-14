#include "types.h"
#include "pso/player/TUnk_80491460.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_800870BC.h"
#include "pso/map/CsnQuery.h"
#include "pso/render/NinjaUtil.h"
#include "pso/effect/particle/TParticleCtrl.h"

// Written last-to-first: the TU was compiled with deferred codegen, which emits the
// functions in reverse definition order.
#pragma defer_codegen on

TUnk_80491460::TUnk_80491460(void *start, s32 angle, s32 source, s32 power) : TObject(tl_06) {
    VecCopy(&pos, (Vec *)start);
    VecCopy(&prev_pos, (Vec *)start);
    distance = 0.0f;
    push_matrix_from(&identity_matrix);
    Vec step = {0.0f, 0.0f, 7.0f};
    rotate_matrix_y(0, angle);
    rotate_vector_by_matrix(0, &step, &velocity);
    pop_matrix();
    this->source = source;
    s32 rotation[3];
    rotation[0] = 0;
    rotation[1] = angle + 0x4000;
    rotation[2] = 0x4000;
    particle = (TParticleCtrl *)spawn_particle_effect_with_rotation(start, rotation, 0x6D, 2);
    frame = 0;
    this->power = power;
}

TUnk_80491460::~TUnk_80491460() {
    if (particle != NULL) {
        particle->queue_destruction();
    }
}

void TUnk_80491460::run_task() {
    s32 i;
    vec3_add_to(&pos, &velocity);
    frame = frame + 1;
    if (!(frame & 3)) {
        if (csnVector(&prev_pos, &pos, -1) != NULL) {
            queue_destruction();
            return;
        }
        VecCopy(&prev_pos, &pos);
    }
    if (particle != NULL) {
        particle->set_position(&pos);
    }
    distance += 7.0f;
    if (distance >= 150.0f) {
        queue_destruction();
        return;
    }
    for (i = 0; i < 12; i++) {
        TObjPlayer *player = get_player_by_client_id(i);
        try_hit_target(player);
    }
}

void TUnk_80491460::try_hit_target(TObjPlayer *player) {
    if (player != NULL && !(player->actorFlags & 0xA00) && !(xz_distance_squared(&pos, (Vec *)&player->m_2fc) > 49.0f)) {
        DirectAttackPayload hit = {0, 0.0f};
        hit.power = power;
        player->receive_direct_attack((void *)source, hit, 0, -1, -1);
        spawn_particle_effect((Vec *)&player->m_2fc, 0xFB);
        queue_destruction();
    }
}
