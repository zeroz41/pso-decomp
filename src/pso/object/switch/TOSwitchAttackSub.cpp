#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/switch/TOSwitchAttackSub.h"
#include "pso/system/task/TObject_80019A50.h"
#include "types.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/switch/TOSwitchAttack.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/network/client_id.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/CameraAngles.h"
#include "pso/render/render_util.h"
#include "pso/player/PlayerSlots.h"

const char *TOSwitchAttack__name = "TOSwitchAttack";
const char *TOSwitchAttackSub__name = "TOSwitchAttackSub";

void TOSwitchAttackSub::run_task() {
    f32 playerDistance;
    TObjPlayer *player;
    if (is_current_floor_switch_set(stopSwitchId) == 1) {
        queue_destruction();
        return;
    }
    if (is_current_floor_switch_set(requiredSwitchId) == 0) {
        queue_destruction();
        return;
    }
    if (particle != 0 && (player = get_player_by_client_id(local_client_id)) != 0 && camera_ctrl_instance != NULL) {
        playerDistance = horizontal_distance_squared(&player->position, &camera_ctrl_instance->pos);
        if (2.0f * horizontal_distance_squared(&position, &camera_ctrl_instance->pos) < playerDistance) {
            ((TParticleCtrl *)particle)->enable();
            return;
        }
        ((TParticleCtrl *)particle)->clear_active_flag();
    }
}

TOSwitchAttackSub::~TOSwitchAttackSub() {
    if (particle != nullptr) ((TObject *)particle)->queue_destruction();
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
TOSwitchAttackSub::TOSwitchAttackSub(TObject *parent, s32 stop_switch, s32 required_switch, u32 type, f32 scale) : TObject(parent) {
    CameraAngles rotation;
    m_name = TOSwitchAttackSub__name;
    disallow_rendering();
    stopSwitchId = stop_switch;
    requiredSwitchId = required_switch;
    particle = 0;
    VecCopy(&position, &((TOSwitchAttack *)parent)->position);
    // Particle effect id and roll per sub type; the roll is the third angle
    // of the rotation spawn_particle_effect_with_rotation reads.
    s32 effect_ids[18] = {132, 149, 175, 196, 207, 223, 225, 371, 430,
                          34, 69, 232, 332, 333, 412, 200, 244, 452};
    s32 rotation_z[18] = {0x8000, 0, 0x8000, 0x8000};
    if (type < 18) {
        rotation.yaw = 0;
        rotation.pitch = 0;
        rotation.roll = rotation_z[type];
        particle = spawn_particle_effect_with_rotation(&position, &rotation, effect_ids[type], 0x40);
        if (particle != 0) {
            if ((s32)type == 10) {
                ((TParticleCtrl *)particle)->set_scale(1.25f * scale, 1.25f * scale);
            } else {
                ((TParticleCtrl *)particle)->set_scale(scale, scale);
            }
        }
    }
}


void TOSwitchAttack::create_sub(saddr parent, s32 stop_switch, s32 required_switch, s32 type, f32 scale) {
    new TOSwitchAttackSub((TObject *)parent, stop_switch, required_switch, (u32)type, scale);
}

extern s32 game_difficulty_selection;

void TOSwitchAttack::init_params() {
    f32 x;

    this->m_a7 = (u8) this->rotation_x;
    x = this->scale.x;
    this->m_94 = (f32) (x * x);
    *(f32 *)&this->unk_98 = (f32) (this->scale.y * (2.0f * (game_difficulty_selection + 1)));
    *(f32 *)&this->unk_90 = (f32) this->scale.z;
    if ((u8) this->m_a7 >= 0x15U) {
        this->m_a7 = 0U;
    }
    this->m_9c = 0;
    this->m_a0 = (u16) this->set_params[0];
    if ((u16) this->m_a0 >= 0x100U) {
        this->m_a0 = 0xFFFFU;
    }
    this->m_a2 = (u16) this->set_params[1];
    if ((u16) this->m_a2 >= 0x100U) {
        this->m_a2 = 0xFFFFU;
    }
    this->m_a4 = (u16) this->set_params[2];
    if ((u16) this->m_a4 > 1U) {
        this->m_a4 = 1U;
    }
}
