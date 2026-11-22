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

struct V_8035D8B0 { s32 a; f32 b; s32 c; };

struct W_8035D8B0 { u8 pad0[0x20]; V_8035D8B0 v; };

struct RecoveredGlobal_8035DB70___vt__9TBoss6DPB { s32 value; u8 remaining[0x14]; };
LAYOUT_ASSERT(RecoveredGlobal_8035DB70___vt__9TBoss6DPB_size, sizeof(RecoveredGlobal_8035DB70___vt__9TBoss6DPB) == 0x18);

struct RecoveredGlobal_8035D7D0___vt__10TDPBShower {
    s32 value;
    u8 remaining[0x14];
};
LAYOUT_ASSERT(RecoveredGlobal_8035D7D0___vt__10TDPBShower_size, sizeof(RecoveredGlobal_8035D7D0___vt__10TDPBShower) == 0x18);


#pragma push
#pragma readonly_strings on
const char *TBoss6DPB__class_name = "TBoss6DPB";
const char *TDPBShower__class_name = "TDPBShower";
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct PBase_8035D924 { u8 pad[0x18]; };

struct Pl_8035D924 : PBase_8035D924 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(s32, void *, int, int, int);
};

struct Dmg_8035D924 { s32 a; s32 b; s32 c; f32 d; };

struct Shower_8035D924 {
    u8 pad0[0x1C];
    saddr owner;
    Vec pos;
    f32 radius;
    u8 pad30[4];
    s32 power;
    f32 scale;
};

extern "C" {

s32 play_sound_effect(s32, u32, int, s32);

f32 vector_length(void *);
void subtract_vector(void *, void *);
}

#pragma push
#pragma fp_contract on
u8 *TBoss6Type2::create_dpb(saddr parent, saddr position, f32 farg0) {
    return (u8 *)new TBoss6DPB((TObject *)parent, position, farg0);
}
#pragma pop

TBoss6DPB::TBoss6DPB(TObject *parent, saddr position, f32 farg0) : TObject(parent) {
    u8 *object = (u8 *)this;
    saddr arg1 = (saddr)parent;
    f32 temp_f1;
    f32 temp_f2;
    *(const char **)((s8 *)object + 0) = TBoss6DPB__class_name;
    *(s32 *)((s8 *)object + 0x1C) = arg1;
    VecCopy((Vec *)(object + 0x20), (const Vec *)(position));
    *(f32 *)((s8 *)object + 0x24) = 0.0f;
    *(f32 *)((s8 *)object + 0x2C) = farg0;
    temp_f2 = *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x2C)) + 8);
    *(s32 *)((s8 *)object + 0x34) = (s32) temp_f2;
    if (0.0f == temp_f2) {
        *(s32 *)((s8 *)object + 0x34) = 0x14;
    }
    temp_f1 = *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x2F)) + 8);
    *(f32 *)((s8 *)object + 0x38) = temp_f1;
    if (0.0f == temp_f1) {
        *(f32 *)((s8 *)object + 0x38) = 1.0f;
    }
    play_sound_effect(0x40069410, (uaddr)(object + 0x20), 0, 0);
    *(s32 *)((s8 *)object + 0x30) = 0;
}

TBoss6DPB::~TBoss6DPB() {}

extern "C" {
void TBoss6DPB::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjEneDD::query_teammate_state() == 0) {
        *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) + 1);
        if ((f32) *(s32 *)((s8 *)arg0 + 0x30) > 5.0f) {
            ((TBoss6DPB *)arg0)->apply_shower_damage_to_players();
            play_sound_effect(0x40069411, (uaddr)(arg0 + 0x20), 0, 0);
            ((TBoss6DPB *)arg0)->sub_8035D8B0();
            ((TObject *)arg0)->queue_destruction();
        }
    }
}

void TBoss6DPB::render() {  }

#pragma push
#pragma opt_common_subs off
void TBoss6DPB::apply_shower_damage_to_players() {
    Shower_8035D924 *arg0 = (Shower_8035D924 *)this;
    Vec v;
    Dmg_8035D924 dmg;
    s32 n;
    s32 i;
    Pl_8035D924 *pl;
    s32 power;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        pl = (Pl_8035D924 *)TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active((TObjPlayer *)pl) != 0) {
            VecCopy((Vec *)&v, (const Vec *)((u8 *)pl + 0x38));
            subtract_vector(&v, &arg0->pos);
            v.y = 0.0f;
            if (!(vector_length(&v) > arg0->radius)) {
                power = arg0->power;
                if (((TBoss6Type2 *)(arg0->owner))->get_rotation_timer() != 0) {
                    power = (f32)power * arg0->scale;
                }
                s32 r = TBoss6PlotFalz::rand_vary_count(power, 0.1f);
                dmg.a = 0;
                dmg.c = 0;
                dmg.d = r;
                dmg.b = *(s32 *)&dmg.d;
                pl->v21(arg0->owner, &dmg, 0, -1, -1);
                create_TDPBShower((void *)tl_02, (u8 *)pl + 0x38);
            }
        }
    }
}
#pragma pop

void TBoss6DPB::sub_8035D8B0() {
    W_8035D8B0 *arg0 = (W_8035D8B0 *)this;
    V_8035D8B0 v = arg0->v;
    v.b = 5.0f;
    spawn_particle_effect_with_flags((const Vec *)&v, 0x21C, 0x40);
    spawn_particle_effect_with_flags((const Vec *)&v, 0x21D, 0x40);
    create_TDPBShower((void *)tl_02, &arg0->v);
}
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
