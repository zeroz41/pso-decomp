#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/MatrixStack.h"
#include "pso/enemy/nanodrago/TObjEneNanoDrago.h"
#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/nanodrago/TObjNanoDragoTargetedBeam.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/DebugFont.h"
#include "pso/math/MatrixReflect.h"
#include "pso/map/CsnQuery.h"
#include "pso/network/client_id.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"

extern const Vec nano_drago_beam_forward = {0.0f, 0.0f, 0.0f};

void TObjNanoDragoTargetedBeam::run_task() {
    Vec dir;
    TObjCollidable *shooter;
    TObjChara *target;
    shooter = find_entity_by_id(shooter_id);
    if (shooter == NULL) {
        queue_destruction();
        return;
    }
    target = static_cast<TObjChara *>(find_active_entity_by_id(target_id));
    switch (state) {
    case 0:
        timer--;
        if (timer <= 0) {
            timer = 0;
            VecCopy(&beam_pos, origin);
            state = 1;
            play_sound_effect(0x4003A328, &beam_pos, 0, 0);
            return;
        }
        if (effect != NULL) {
            effect->enable();
        }
        return;
    case 1:
        timer++;
        if (timer >= 0x5A) {
            queue_destruction();
            return;
        }
        if (target != NULL) {
            VecCopy(&dir, &target->body_center);
            subtract_vector(&dir, &beam_pos);
            vec_set_length(&dir, homing);
            homing += nano_drago_beam_homing_gain;
            vec3_add_to(&velocity, &dir);
            vec_set_length(&velocity, nano_drago_beam_speed);
        }
        VecCopy(&prev_pos, &beam_pos);
        vec3_add_to(&beam_pos, &velocity);
        if (effect != NULL) {
            effect->set_position(&beam_pos);
        }
        if (csnVector(&prev_pos, &beam_pos, -1) != 0) {
            queue_destruction();
            return;
        }
        if (target == NULL) {
            return;
        }
        if (target->actorFlags & 0x4000A00) {
            return;
        }
        if (xyz_distance_squared(&beam_pos, &target->body_center) <= nano_drago_beam_speed * nano_drago_beam_speed) {
            DirectAttackPayload payload = {0, 0.0f};
            payload.power = nano_drago_beam_power;
            target->receive_direct_attack(shooter, payload, 0, -1, -1);
            TObjEneNanoDrago *nano_drago = static_cast<TObjEneNanoDrago *>(shooter);
            if (target->actorFlags & 0x800) {
                nano_drago->request_growth();
            }
            spawn_particle_effect(&target->body_center, 0xFB);
            spawn_particle_effect(&target->body_center, 0xFC);
            if (is_split_screen() == 0 && local_client_id == target_id) {
                nano_drago->trigger_hit_camera_shake(target);
            }
            queue_destruction();
        }
        break;
    }
}

TObjNanoDragoTargetedBeam::~TObjNanoDragoTargetedBeam() {
    if (effect != NULL) {
        effect->queue_destruction();
        effect = NULL;
    }
}

TObjNanoDragoTargetedBeam::TObjNanoDragoTargetedBeam(Vec *origin, u16 target_id, Angle3 *rotation, s32 delay, u16 shooter_id)
    : TObjCollidable(tl_04) {
    Vec *target_pos;
    this->target_id = target_id;
    this->shooter_id = shooter_id;
    this->origin = origin;
    distance = 0.0f;
    push_matrix_from(identity_matrix);
    {
        Vec forward = nano_drago_beam_forward;
        Angle3 angle;
        forward.z = nano_drago_beam_speed;
        rotate_matrix_y(0, rotation->y);
        rotate_matrix_x(0, rotation->x);
        matrix_mult_vec(0, &forward, &velocity);
        pop_matrix();
        timer = delay;
        target_pos = &static_cast<TObjChara *>(find_entity_by_id(target_id))->body_center;
        angle.x = 0;
        angle.y = (s32)(10430.38043493439 * atan2_float(target_pos->x - origin->x, target_pos->z - origin->z)) + 0x4000;
        angle.z = 0x4000 - (s32)(10430.38043493439 * atan2_float(target_pos->y - origin->y, vec_xz_distance(target_pos, origin)));
        effect = spawn_particle_effect_with_rotation(origin, &angle, 0xf4, 2);
    }
    homing = nano_drago_beam_homing;
    if (xz_distance_squared(target_pos, origin) < 22500.0f) {
        homing *= 2.0f;
    }
    state = 0;
}
