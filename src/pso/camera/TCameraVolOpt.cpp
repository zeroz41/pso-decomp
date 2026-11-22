#include "types.h"
#include "pso/camera/TCameraVolOpt.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraCtrl_801A6E60.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D96A8.h"

extern TCameraCtrl *camera_ctrl_instance;

// Eye offsets from the followed player; the first is the Vol Opt camera's.
const Vec camera_ctrl_default_offset_vecs[2] = {
    {0.0f, 25.43f, 45.42f},
    {0.0f, 30.0f, 40.0f},
};

void TUnk_80488A28::set_target(uaddr object) {
    actor = object;
    if (object != 0U) {
        m_20 = get_entity_id((TObjBase *)object);
    }
}

#pragma push
#pragma fp_contract on
void TCameraVolOpt::update_target_follow() {
    Vec dir;
    Vec *focus = TBoss3Volopt::get_camera_focus();
    if (focus != NULL) {
        TObjBase *player = (TObjBase *)actor;
        dir.x = player->position.x - focus->x;
        f32 dz = player->position.z - focus->z;
        dir.y = 0.0f;
        dir.z = dz;
        f32 distance = vector_length(&dir);
        if (0.0f != distance) {
            normalize_vector(&dir);
        } else {
            return;
        }
        switch (follow_state) {
        case 0:
            target.x = focus->x;
            target.z = focus->z;
            target.y = focus->y;
            if (target.y >= 50.0f) {
                target.y = 60.0f;
            }
            position.x = 45.42f * dir.x + ((TObjBase *)actor)->position.x;
            position.z = 45.42f * dir.z + ((TObjBase *)actor)->position.z;
            position.y = 15.0f + ((TObjBase *)actor)->position.y;
            if (distance < 100.0f) {
                follow_state = 1;
                locked_target_offset.x = target.x - ((TObjBase *)actor)->position.x;
                locked_target_offset.y = target.y - ((TObjBase *)actor)->position.y;
                locked_target_offset.z = target.z - ((TObjBase *)actor)->position.z;
                locked_eye_offset.x = position.x - ((TObjBase *)actor)->position.x;
                locked_eye_offset.y = position.y - ((TObjBase *)actor)->position.y;
                locked_eye_offset.z = position.z - ((TObjBase *)actor)->position.z;
                return;
            }
            break;
        case 1:
            if (distance > 100.0f) {
                follow_state = 0;
            }
            target.x = locked_target_offset.x + ((TObjBase *)actor)->position.x;
            target.y = locked_target_offset.y + ((TObjBase *)actor)->position.y;
            target.z = locked_target_offset.z + ((TObjBase *)actor)->position.z;
            position.x = locked_eye_offset.x + ((TObjBase *)actor)->position.x;
            position.y = locked_eye_offset.y + ((TObjBase *)actor)->position.y;
            position.z = locked_eye_offset.z + ((TObjBase *)actor)->position.z;
            break;
        }
    }
}
#pragma pop

void TCameraVolOpt::update_follow_flags() {
    Vec to_target;
    m_38 = 0x15;
    m_58 = 1.65f;
    to_target.x = camera_ctrl_instance->tgt_x - target.x;
    to_target.y = camera_ctrl_instance->tgt_y - target.y;
    to_target.z = camera_ctrl_instance->tgt_z - target.z;
    *(f32 *)unk_5C = (0.7f * vector_length(&to_target)) / 100.0f;
    if (predict_obstruction() != 0) {
        m_fc = m_fc | 1;
    } else {
        m_fc = m_fc & ~1;
    }
    m_e8 = 0.0f;
    m_ec = 19.8f;
    m_f0 = -5.0f;
    VecCopy(&eye_offset, &camera_ctrl_default_offset_vecs[0]);
}

TUnk_80488A28 *TCameraVolOpt::create() {
    return new TCameraVolOpt();
}

void TCameraVolOpt::run_task() {
    m_38 = 0x15;
    if (test_previous_buttons_packed(&controller_input_state.controllers[0], 0x10000) != 0) {
        TUnk_80488E00::run_task();
    } else {
        update_target_follow();
    }
    m_38 = m_38 | 0x10;
}

TCameraVolOpt::~TCameraVolOpt() {}

TCameraVolOpt::TCameraVolOpt() {
    m_38 = 21;
    m_58 = 0.65f;
    follow_state = 0;
    pad_110 = 0;
}

void TUnk_80488E00::vfunc_14(s32 v) { m_10c = v; }
