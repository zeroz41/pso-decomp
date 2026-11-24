#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/photon/TPhotonLine.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/TObjBase.h"

const char *TPhotonLine::class_name = "TPhotonLine";

CollisionBody photon_line_collision_body_part[1] = {
    { { 0.0f, 0.0f, 0.0f }, 30.0f, 30.0f, 1, 0x8007, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

void TPhotonLine::render() {
    TParticleCtrl::begin_effect_render();
    TParticleCtrl::end_effect_render();
}

void TPhotonLine::run_task() {
    Vec next = position;
    s32 i;
    TObjBase *player;
    s32 j;

    vec3_add_to(&next, &vel);
    VecCopy(&body_center, &position);
    body_center.y += 60.0f;
    next.y += 60.0f;
    if (check_path_obstructed(this, &next) == 1) {
        queue_destruction();
        return;
    }
    TObjPlayer::init_all_slots();
    mark_enemy_body_contacts();
    if (bodies->flags & 0x100000) {
        for (i = 0; i < 16; i++) {
            player = (TObjBase *)TObjPlayer::get_battle_param(i);
            if (player == NULL) {
                break;
            }
            for (j = 0; j < hit_count; j++) {
                if (hit_ids[j] == player->get_entity_id()) {
                    break;
                }
            }
            if (j == hit_count) {
                hit_ids[hit_count++] = player->get_entity_id(); // Retail records the ninth ID before stopping hit dispatch.
                if ((s32)hit_count >= 9) {
                    break;
                }
                queue_photon_blast_hit(player->get_entity_id(), 1, 0, power);
                spawn_particle_effect(&player->position, 0x162);
                spawn_particle_effect(&player->position, 0x163);
            }
        }
    }
    position.x += vel.x;
    position.z += vel.z;
}

TPhotonLine::~TPhotonLine() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TPhotonLine::TPhotonLine(PhotonLineParams *params, TObject *parent, u16 owner_id) : TObjChara(parent) {
    s32 i;

    m_name = class_name;
    VecCopy(&home_position, VecCopy(&position, &params->pos));
    VecCopy(&vel, &params->dir);
    vel.x *= params->speed;
    vel.y *= params->speed;
    vel.z *= params->speed;
    power = params->power;
    owner = find_entity_by_id(owner_id);
    init_collision_body_parts(this, photon_line_collision_body_part, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    for (i = 0; i < 10; i++) {
        hit_ids[i] = 0xFFFF;
    }
    hit_count = 0;
}
