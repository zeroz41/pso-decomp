#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/enemy/nanodrago/TObjNanoDragoSingleBeam.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/nanodrago/TObjEneNanoDrago.h"

#include "pso/player/TObjPlayer.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/BmlResource.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/render_util.h"
#include "pso/network/client_id.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/math/MatrixVector.h"


s32 TObjEneNanoDrago::get_int_parameter(s32 index) {
    return nano_drago_behavior_params->int_params[index];
}

f32 TObjEneNanoDrago::get_float_parameter(s32 index) {
    return nano_drago_behavior_params->float_params[index];
}

void TObjEneNanoDrago::update_attack() {  }

void TObjEneNanoDrago::load_entry_params_nanodrago(s32 i) {
    model = nano_drago_entry_params_resource->models[i].model;
    texlist = nano_drago_entry_params_resource->models[i].texlist;
}

int TObjMotion::is_action_passing_frame(s32 action, f32 at_frame) {
    if (requested_action == action) {
        f32 current = frame;
        if (current >= at_frame && current < at_frame + play_speed) {
            return 1;
        }
    }
    return 0;
}

void TObjNanoDragoSingleBeam::hit_object_in_radius(TObjChara *target, TObjCollidable *shooter) {
    if (target == NULL) {
        return;
    }
    if (target == shooter) {
        return;
    }
    if (target->actorFlags & 0x4000A00) {
        return;
    }
    if (xyz_distance_squared(&pos, &target->body_center) > nano_drago_single_beam_speed * nano_drago_single_beam_speed) {
        return;
    }
    DirectAttackPayload payload = {0, 0.0f};
    payload.power = nano_drago_single_beam_power;
    target->receive_direct_attack(shooter, payload, 0, -1, -1);
    if (shooter != NULL) {
        TObjEneNanoDrago *nano_drago = static_cast<TObjEneNanoDrago *>(shooter);
        if (target->actorFlags & 0x800) {
            nano_drago->request_growth();
        }
        if (is_split_screen() == 0 && local_client_id == target->get_entity_id()) {
            nano_drago->trigger_hit_camera_shake(target);
        }
    }
    spawn_particle_effect(&target->body_center, 0xFB);
    spawn_particle_effect(&target->body_center, 0xFC);
}

s32 TObjNanoDragoSingleBeam::snap_to_ground(Vec *origin) {
    CsnHit *hit = csnVecterUnder(origin, 0x16EF);
    if (hit == NULL) {
        return 0;
    }
    VecCopy(origin, &hit->contact->point);
    return 1;
}

void TObjNanoDragoSingleBeam::run_task() {
    TObjCollidable *shooter;
    s32 i;
    TObjPlayer *player;
    Vec old = pos;
    vec3_add_to(&pos, &velocity);
    if (effect != NULL) {
        effect->set_position(&pos);
    }
    distance += nano_drago_single_beam_speed;
    if (trail != 0) {
        VecCopy(&trail_pos, &pos);
        trail_snap_timer++;
        if (trail_snap_timer > 4) {
            trail_snap_timer = 0;
            snap_to_ground(&trail_pos);
        }
        if (trail_effect != NULL) {
            trail_effect->set_position(&trail_pos);
        }
    }
    if (distance >= 500.0f) {
        queue_destruction();
        return;
    }
    if (csnVector(&old, &pos, -1) != 0) {
        queue_destruction();
        return;
    }
    shooter = find_entity_by_id(owner_id);
    if (shooter != NULL) {
        for (i = 0; i < registered_player_count + registered_enemy_count; i++) {
            player = TObjPlayer::get_player_data(i);
            if (player != NULL && TObjPlayer::is_valid_and_active((uaddr)player) != 0) {
                hit_object_in_radius(player, shooter);
            }
        }
    }
}

TObjNanoDragoSingleBeam::~TObjNanoDragoSingleBeam() {
    if (effect != NULL) {
        effect->queue_destruction();
        effect = NULL;
    }
    if (trail_effect != NULL) {
        trail_effect->queue_destruction();
        trail_effect = NULL;
    }
}

TObjNanoDragoSingleBeam::TObjNanoDragoSingleBeam(Vec *origin, Vec *target_pos, s32 trail, TObjEneNanoDrago *owner)
    : TObjCollidable(tl_06) {
    Angle3 angle;
    f32 s;
    this->trail = trail;
    VecCopy(&pos, origin);
    distance = 0.0f;
    VecCopy(&velocity, target_pos);
    subtract_vector(&velocity, origin);
    s = nano_drago_single_beam_speed / vector_length(&velocity);
    velocity.x *= s;
    velocity.y *= s;
    velocity.z *= s;
    owner_id = owner->get_entity_id();
    angle.x = 0;
    angle.y = (s32)(10430.38043493439 * atan2_float(target_pos->x - origin->x, target_pos->z - origin->z)) + 0x4000;
    angle.z = 0x4000 - (s32)(10430.38043493439 * atan2_float(target_pos->y - origin->y, vec_xz_distance(target_pos, origin)));
    effect = spawn_particle_effect_with_rotation(origin, &angle, 0xF5, 2);
    if (this->trail != 0) {
        VecCopy(&trail_pos, &pos);
        snap_to_ground(&trail_pos);
        trail_effect = spawn_continuous_particle_effect_with_flags(&trail_pos, 0xF9, 2);
        trail_snap_timer = 0;
    } else {
        trail_effect = NULL;
    }
}
