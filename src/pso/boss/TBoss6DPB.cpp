#include "pso/TBoss6DPB.h"
#include "pso/boss/TBoss6DPB.h"
#include "pso/effect/TDPBShower.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/vector.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEneEpsilonGuard.h"
#include "types.h"
#include "pso/boss/TBoss6Type2.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TLobby.h"

struct V_8035D8B0 { s32 a; f32 b; s32 c; };

struct W_8035D8B0 { u8 pad0[0x20]; V_8035D8B0 v; };

struct RecoveredGlobal_8035DB70___vt__9TBoss6DPB { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8035DB70___vt__9TBoss6DPB_size[sizeof(RecoveredGlobal_8035DB70___vt__9TBoss6DPB) == 0x18 ? 1 : -1];

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

struct Vec_8035D924 { f32 x, y, z; };

struct Dmg_8035D924 { s32 a; s32 b; s32 c; f32 d; };

struct Shower_8035D924 {
    u8 pad0[0x1C];
    s32 owner;
    Vec_8035D924 pos;
    f32 radius;
    u8 pad30[4];
    s32 power;
    f32 scale;
};

extern "C" {
extern s32 tl_02;

u8 *__nw__7TObjectFUl(s32);

s32 play_sound_effect(s32, u32, int, s32);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_8035DB70___vt__9TBoss6DPB __vt__9TBoss6DPB;
extern s32 TBoss6DPB__class_name;

int get_player_data__10TObjPlayerFi(int a0);
f32 vector_length(void *);
void subtract_vector(void *, void *);

void TBoss6DPB::sub_8035D8B0() {
    W_8035D8B0 *arg0 = (W_8035D8B0 *)this;
    V_8035D8B0 v = arg0->v;
    v.b = 5.0f;
    spawn_particle_effect_with_flags(&v, 0x21C, 0x40);
    spawn_particle_effect_with_flags(&v, 0x21D, 0x40);
    create_TDPBShower((void *)tl_02, &arg0->v);
}

#pragma push
#pragma opt_common_subs off
void TBoss6DPB::apply_shower_damage_to_players() {
    Shower_8035D924 *arg0 = (Shower_8035D924 *)this;
    Vec_8035D924 v;
    Dmg_8035D924 dmg;
    s32 n;
    s32 i;
    Pl_8035D924 *pl;
    s32 power;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        pl = (Pl_8035D924 *)get_player_data__10TObjPlayerFi(i);
        if (((TBoss6PlotFalz *)pl)->is_active() != 0) {
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

void TBoss6DPB::render() {  }
void TBoss6DPB::run_task() {
    u8 *arg0 = (u8 *)this;
    if (((TObjEneDD *)arg0)->query_teammate_state() == 0) {
        *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) + 1);
        if ((f32) *(s32 *)((s8 *)arg0 + 0x30) > 5.0f) {
            ((TBoss6DPB *)arg0)->apply_shower_damage_to_players();
            play_sound_effect(0x40069411, (u32)(arg0 + 0x20), 0, 0);
            ((TBoss6DPB *)arg0)->sub_8035D8B0();
            queue_destruction__7TObjectFv(arg0);
        }
    }
}
}

TBoss6DPB::~TBoss6DPB() {}

u8 *__ct__9TBoss6DPBFv(u8 *object, s32 arg1, s32 arg2, f32 farg0) {
    f32 temp_f1;
    f32 temp_f2;
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__9TBoss6DPB.value;
    *(s32 *)((s8 *)object + 0) = (s32) TBoss6DPB__class_name;
    *(s32 *)((s8 *)object + 0x1C) = arg1;
    VecCopy((Vec *)(object + 0x20), (const Vec *)(arg2));
    *(f32 *)((s8 *)object + 0x24) = (f32) 0.0f;
    *(f32 *)((s8 *)object + 0x2C) = farg0;
    temp_f2 = *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x2C)) + 8);
    *(s32 *)((s8 *)object + 0x34) = (s32) temp_f2;
    if (0.0f == temp_f2) {
        *(s32 *)((s8 *)object + 0x34) = 0x14;
    }
    temp_f1 = *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x2F)) + 8);
    *(f32 *)((s8 *)object + 0x38) = temp_f1;
    if (0.0f == temp_f1) {
        *(f32 *)((s8 *)object + 0x38) = (f32) 1.0f;
    }
    play_sound_effect(0x40069410, (u32)(object + 0x20), 0, 0);
    *(s32 *)((s8 *)object + 0x30) = 0;
    return object;
}

#pragma push
#pragma fp_contract on
u8 *TBoss6Type2::create_dpb(s32 arg0, s32 arg1, f32 farg0) {
    u8 *boss6_dpb;
    u8 *var_r0;
    boss6_dpb = (u8 *)(__nw__7TObjectFUl(0x3C));
    var_r0 = boss6_dpb;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(__ct__9TBoss6DPBFv(boss6_dpb, arg0, arg1, farg0));
    }
    return var_r0;
}
#pragma pop
