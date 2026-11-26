#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/switch/TOSwitchAttackSub.h"
#include "types.h"
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
#include "pso/ui/TLevelSelect.h"

const char *switch_attack_name = "TOSwitchAttack";
const char *switch_attack_sub_name = "TOSwitchAttackSub";

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
            particle->enable();
            return;
        }
        particle->clear_active_flag();
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
    m_name = switch_attack_sub_name;
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
                particle->set_scale(1.25f * scale, 1.25f * scale);
            } else {
                particle->set_scale(scale, scale);
            }
        }
    }
}


void TOSwitchAttack::create_sub(saddr parent, s32 stop_switch, s32 required_switch, s32 type, f32 scale) {
    new TOSwitchAttackSub((TObject *)parent, stop_switch, required_switch, (u32)type, scale);
}


void TOSwitchAttack::init_params() {
    f32 x;

    this->effect_type = (u8) this->rotation_x;
    x = this->scale.x;
    this->range_sq = (f32) (x * x);
    this->damage = (f32) (this->scale.y * (2.0f * (game_difficulty_selection + 1)));
    this->size = (f32) this->scale.z;
    if ((u8) this->effect_type >= 0x15U) {
        this->effect_type = 0U;
    }
    this->fired = 0;
    this->trigger_switch = (u16) this->set_params[0];
    if ((u16) this->trigger_switch >= 0x100U) {
        this->trigger_switch = 0xFFFFU;
    }
    this->stop_switch = (u16) this->set_params[1];
    if ((u16) this->stop_switch >= 0x100U) {
        this->stop_switch = 0xFFFFU;
    }
    this->repeatable = (u16) this->set_params[2];
    if ((u16) this->repeatable > 1U) {
        this->repeatable = 1U;
    }
}
