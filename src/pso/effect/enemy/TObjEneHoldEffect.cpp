#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

#pragma push
#pragma fp_contract on
void TObjEneHoldEffect::run_task() {
    TObjPlayer *player = get_player_by_client_id(target_id);
    if (player != NULL && player->all_parents_unqueued_for_destruction() != 0 &&
        player->test_actor_flags(0x800) == 0 && particle != NULL &&
        particle->all_parents_unqueued_for_destruction() != 0) {
        if (effect == 0x20F && is_split_screen() == 0) {
            Vec to_camera;
            Vec pos;
            VecCopy(&to_camera, &position);
            subtract_vector(&to_camera, &camera_ctrl_instance->pos);
            normalize_vector(&to_camera);
            pos.x = position.x - 5.0f * to_camera.x;
            pos.y = position.y;
            pos.z = position.z - 5.0f * to_camera.z;
            particle->set_position(&pos);
        } else {
            particle->set_position(&position);
        }
    }
    if (frames_left-- < 0) {
        queue_destruction();
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneHoldEffect::render() {
    TObjPlayer *player = get_player_by_client_id(target_id);
    if (player != NULL && player->all_parents_unqueued_for_destruction() != 0 &&
        player->test_actor_flags(0x800) == 0 && particle != NULL &&
        particle->all_parents_unqueued_for_destruction() != 0) {
        Vec to_camera;
        Vec pos;
        VecCopy(&to_camera, &position);
        subtract_vector(&to_camera, &camera_ctrl_instance->pos);
        normalize_vector(&to_camera);
        pos.x = position.x - 5.0f * to_camera.x;
        pos.y = position.y;
        pos.z = position.z - 5.0f * to_camera.z;
        particle->set_position(&pos);
    }
}
#pragma pop

TObjEneHoldEffect::~TObjEneHoldEffect() {
    if (particle != NULL) {
        TParticleCtrl::release(particle);
        particle = NULL;
    }
}

void TObjEneHoldEffect::create(void *target, s32 type, s32 frames) {
    new TObjEneHoldEffect((TObjBase *)target, type, frames);
}

const char *TObjEneHoldEffect::class_name = "TObjEneHoldEffect";

TObjEneHoldEffect::TObjEneHoldEffect(TObjBase *target, s32 type, s32 frames) : TObjBase(tl_07) {
    particle = NULL;
    if (target != NULL) {
        m_name = class_name;
        VecCopy(&position, &target->position);
        target_id = target->get_entity_id();
        frames_left = frames;
        switch (type) {
        case 1:
            effect = 0x12F;
            break;
        case 2:
            effect = 0x20F;
            break;
        case 3:
            effect = 0x223;
            break;
        default:
            queue_destruction();
            return;
        }
        particle = create_particle_emitter(&position, effect);
    } else {
        queue_destruction();
    }
}
