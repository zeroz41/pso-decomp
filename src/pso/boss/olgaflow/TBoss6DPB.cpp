#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma defer_codegen on
#include "pso/unk/text_80087278.h"
#include "pso/boss/olgaflow/TBoss6DPB.h"
#include "pso/effect/photon/TDPBShower.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/epsilon/TObjEneEpsilonGuard.h"
#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/SoundEffect.h"

#pragma push
#pragma readonly_strings on
const char *TBoss6DPB__class_name = "TBoss6DPB";
const char *TDPBShower__class_name = "TDPBShower";
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma push
#pragma fp_contract on
u8 *TBoss6Type2::create_dpb(saddr parent, saddr position, f32 farg0) {
    return (u8 *)new TBoss6DPB((TObject *)parent, position, farg0);
}
#pragma pop

TBoss6DPB::TBoss6DPB(TObject *parent, saddr position, f32 radius) : TObject(parent) {
    m_name = TBoss6DPB__class_name;
    owner = (TBoss6Type2 *)parent;
    VecCopy(&this->position, (const Vec *)position);
    this->position.y = 0.0f;
    this->radius = radius;
    f32 param = ((f32 *)TLobby::dispatch_shared_handler_a(0x2C))[2];
    power = (s32)param;
    if (0.0f == param) {
        power = 0x14;
    }
    f32 scale = ((f32 *)TLobby::dispatch_shared_handler_a(0x2F))[2];
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
            sub_8035D8B0();
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
                create_TDPBShower((void *)tl_02, &player->position);
            }
        }
    }
}
#pragma pop

void TBoss6DPB::sub_8035D8B0() {
    Vec v = position;
    v.y = 5.0f;
    spawn_particle_effect_with_flags(&v, 0x21C, 0x40);
    spawn_particle_effect_with_flags(&v, 0x21D, 0x40);
    create_TDPBShower((void *)tl_02, &position);
}
#pragma pop

void* create_TDPBShower(void* parent, void* position) {
    return new TDPBShower((TObject *)parent, position);
}

TDPBShower::TDPBShower(TObject *parent, void *position) : TObject(parent) {
    u8 *dpb_shower = (u8 *)this;
    u8 *particle_emitter;
    *(const char **)((s8 *)dpb_shower + 0) = TDPBShower__class_name;
    ((TDPBShower *)dpb_shower)->m_countdown = 5;
    VecCopy((Vec *)(dpb_shower + 0x1C), (const Vec *)position);
    *(f32 *)((s8 *)dpb_shower + 0x20) += 300.0f;
    particle_emitter = (u8 *)(create_particle_emitter((dpb_shower + 0x1C), 0x134));
    ((TDPBShower *)dpb_shower)->m_2c = particle_emitter;
    if (particle_emitter != NULL) {
        ((TParticleCtrl *)(((TDPBShower *)dpb_shower)->m_2c))->set_flags(0x40);
    }
}

TDPBShower::~TDPBShower() {
    if (m_2c != nullptr) TParticleCtrl::release(m_2c);
}

void TDPBShower::run_task() {
    if (TObjEneDD::query_teammate_state() == 0) {
        m_position[1] += -60.0f;
        if (m_2c != NULL) {
            ((TParticleCtrl *)m_2c)->set_position(m_position);
        }
        if (--m_countdown < 0) {
            queue_destruction();
        }
    }
}
