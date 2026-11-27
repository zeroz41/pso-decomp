#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma defer_codegen on
#include "pso/boss/olgaflow/TBoss6DPB.h"
#include "pso/effect/photon/TDPBShower.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/epsilon/TObjEneEpsilonGuard.h"
#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/network/TLobby.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/SoundEffect.h"
#include "pso/enemy/BattleParamTables.h"

#pragma push
#pragma readonly_strings on
const char *TBoss6DPB::class_name = "TBoss6DPB";
const char *TDPBShower::class_name = "TDPBShower";
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma push
#pragma fp_contract on
TBoss6DPB *TBoss6Type2::create_dpb(TObject *parent, const Vec *position, f32 radius) {
    return new TBoss6DPB(parent, position, radius);
}
#pragma pop

TBoss6DPB::TBoss6DPB(TObject *parent, const Vec *position, f32 radius) : TObject(parent) {
    m_name = TBoss6DPB::class_name;
    owner = (TBoss6Type2 *)parent;
    VecCopy(&this->position, position);
    this->position.y = 0.0f;
    this->radius = radius;
    f32 param = dispatch_shared_handler_a(0x2C)->values.floats[2];
    power = (s32)param;
    if (0.0f == param) {
        power = 0x14;
    }
    f32 scale = dispatch_shared_handler_a(0x2F)->values.floats[2];
    power_scale = scale;
    if (0.0f == scale) {
        power_scale = 1.0f;
    }
    play_sound_effect(0x40069410, &this->position, 0, 0);
    frame = 0;
}

TBoss6DPB::~TBoss6DPB() {}

void TBoss6DPB::run_task() {
    if (TObjEneDD::query_teammate_state() == 0) {
        frame = frame + 1;
        if ((f32)frame > 5.0f) {
            apply_shower_damage_to_players();
            play_sound_effect(0x40069411, &position, 0, 0);
            spawn_shower();
            queue_destruction();
        }
    }
}

void TBoss6DPB::render() {  }

#pragma push
#pragma opt_common_subs off
void TBoss6DPB::apply_shower_damage_to_players() {
    Vec v;
    DirectAttackPayload attack;
    s32 count;
    s32 i;
    TObjPlayer *player;
    s32 damage;
    count = TLobby::get_game_mode();
    for (i = 0; i < count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active(player) != 0) {
            VecCopy(&v, &player->position);
            subtract_vector(&v, &position);
            v.y = 0.0f;
            if (!(vector_length(&v) > radius)) {
                damage = power;
                if (owner->get_rotation_timer() != 0) {
                    damage = (f32)damage * power_scale;
                }
                s32 r = TBoss6PlotFalz::rand_vary_count(damage, 0.1f);
                attack.kind = 0;
                attack.power = r;
                player->receive_direct_attack(owner, attack, 0, -1, -1);
                create_TDPBShower(tl_02, &player->position);
            }
        }
    }
}
#pragma pop

void TBoss6DPB::spawn_shower() {
    Vec v = position;
    v.y = 5.0f;
    spawn_particle_effect_with_flags(&v, 0x21C, 0x40);
    spawn_particle_effect_with_flags(&v, 0x21D, 0x40);
    create_TDPBShower(tl_02, &position);
}
#pragma pop

void* create_TDPBShower(TObject *parent, const Vec *position) {
    return new TDPBShower(parent, position);
}

TDPBShower::TDPBShower(TObject *parent, const Vec *pos) : TObject(parent) {
    m_name = TDPBShower::class_name;
    m_countdown = 5;
    VecCopy(&position, pos);
    position.y += 300.0f;
    if ((particle_emitter = create_particle_emitter(&position, 0x134)) != NULL) {
        particle_emitter->set_flags(0x40);
    }
}

TDPBShower::~TDPBShower() {
    if (particle_emitter != nullptr) TParticleCtrl::release(particle_emitter);
}

void TDPBShower::run_task() {
    if (TObjEneDD::query_teammate_state() == 0) {
        position.y += -60.0f;
        if (particle_emitter != NULL) {
            particle_emitter->set_position(&position);
        }
        if (--m_countdown < 0) {
            queue_destruction();
        }
    }
}
