#include "types.h"
#include "pso/boss/TBoss6GravBall.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
extern "C" void *__ct__13TUnk_804AF8A0FP7TObject(void *, s32);

#include "pso/boss/TBoss6GravBall.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/misc/TLobby.h"

struct P_80323348 { u8 pad[0x30]; u32 flags; };

struct Vec_803237A0 { f32 x, y, z; };

struct Obj_803237A0 { u8 pad[0xC8]; Vec_803237A0 pos; };

struct Vec_803233AC { f32 x, y, z; };

struct PL_803233AC { u8 pad[0x30]; u32 flags; u8 pad34[4]; Vec_803233AC pos; };

struct Vec_80323544 { f32 x, y, z; };

struct PL_80323544 { u8 pad[0x30]; u32 flags; u8 pad34[4]; Vec_80323544 pos; };

extern "C" {
P_80323348 *get_player_data__10TObjPlayerFi(s32);
s32 is_state_1f__14TBoss6PlotFalzFUi();
f32 vector_length(void *);
void subtract_vector(void *, void *);
void normalize_vector(void *);
extern u8 lbl_80476684[];


void TBoss6GravBall__sub_803236F8(TBoss6GravBall *arg0);
s32 project_actor_to_ground(void *, void *, int);


u16 get_entity_id(void *);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
void vec3_add_to(void *, void *);
void TBoss6PlotFalz__sub_802AC724(void *, void *);



void TBoss6GravBall__sub_803233AC(u8 *self);



void TBoss6GravBall__sub_80323544(u8 *self);

void TBoss6GravBall::clear_player_grav_flags() {
    s32 n = TLobby::get_game_mode();
    s32 i;
    for (i = 0; i < n; i++) {
        P_80323348 *p = get_player_data__10TObjPlayerFi(i);
        if (is_state_1f__14TBoss6PlotFalzFUi() != 0) {
            p->flags &= 0xFFFDFFFF;
        }
    }
}

#pragma push
#pragma fp_contract on
void TBoss6GravBall__sub_803233AC(u8 *self) {
    Vec_803233AC v;
    s32 n;
    s32 i;
    PL_803233AC *pl;
    s32 id;
    s32 flag;
    f32 d;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        pl = (PL_803233AC *)get_player_data__10TObjPlayerFi(i);
        id = get_entity_id(pl) + 5;
        if (((TBoss6PlotFalz *)pl)->is_active() == 0) {
            ((TBoss6GravBall *)self)->destroy_part((s32)((void *)id));
            continue;
        }
        flag = 0;
        VecCopy((Vec *)&v, (const Vec *)(self + 0xC8));
        subtract_vector(&v, &pl->pos);
        v.y = 0.0f;
        d = vector_length(&v);
        if (d > 32.5f) {
            ((TBoss6GravBall *)self)->destroy_part((s32)((void *)id));
            continue;
        }
        if (d <= 1e+01f) {
            s32 a = get_entity_id(pl) << 14;
            v.x = 2.5f * sin_table_lookup(a) + v.x;
            v.z = 2.5f * cos_table_lookup(a) + v.z;
            flag = 1;
        } else {
            f32 s = (-33.5f) + d;
            normalize_vector(&v);
            v.x *= s;
            v.z *= s;
        }
        vec3_add_to(&v, &pl->pos);
        project_actor_to_ground(self, &v, 0);
        TBoss6PlotFalz__sub_802AC724(pl, &v);
        if (flag != 0) {
            pl->flags |= 0x20000;
            ((TBoss6GravBall *)self)->create_emitter(id);
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss6GravBall__sub_80323544(u8 *self) {
    Vec_80323544 v;
    s32 n;
    s32 i;
    PL_80323544 *pl;
    s32 id;
    s32 flag;
    f32 d;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        pl = (PL_80323544 *)get_player_data__10TObjPlayerFi(i);
        id = get_entity_id(pl) + 5;
        if (((TBoss6PlotFalz *)pl)->is_active() == 0) {
            ((TBoss6GravBall *)self)->destroy_part((s32)((void *)id));
            continue;
        }
        flag = 1;
        VecCopy((Vec *)&v, (const Vec *)(self + 0xC8));
        {
            s32 a = get_entity_id(pl) << 14;
            v.x = 2.5f * sin_table_lookup(a) + v.x;
            v.z = 2.5f * cos_table_lookup(a) + v.z;
        }
        subtract_vector(&v, &pl->pos);
        v.y = 0.0f;
        d = vector_length(&v);
        if (d > 1e+01f) {
            f32 s;
            if (*(u32 *)(self + 0xC0) & 1) {
                ((TBoss6GravBall *)self)->destroy_part((s32)((void *)id));
                continue;
            }
            s = 3.0f * (*(f32 *)(self + 0xBC) * (1.0f - d / 225.0f));
            if (s < 1.0f) {
                s = 1.0f;
            }
            normalize_vector(&v);
            flag = 0;
            v.x *= s;
            v.z *= s;
        }
        vec3_add_to(&v, &pl->pos);
        project_actor_to_ground(self, &v, 0);
        TBoss6PlotFalz__sub_802AC724(pl, &v);
        if (flag != 0) {
            pl->flags |= 0x20000;
            ((TBoss6GravBall *)self)->create_emitter(id);
        }
    }
}
#pragma pop

void TBoss6GravBall__sub_803236F8(TBoss6GravBall *arg0) {
    Vec v = arg0->ball_position;
    v.y = 0.0f;
    if (vector_length(&v) > 0.6666667f) {
        normalize_vector(&v);
        v.x *= 0.6666667f;
        v.z *= 0.6666667f;
        subtract_vector(&arg0->ball_position, &v);
    } else {
        VecCopy(&arg0->ball_position, (const Vec *)lbl_80476684);
    }
    arg0->clamp_to_ground();
}

s32 TBoss6GravBall::clamp_to_ground() {
    Obj_803237A0 *arg0 = (Obj_803237A0 *)this;
    Vec_803237A0 v = arg0->pos;
    if (project_actor_to_ground(arg0, &v, 0) == 0) {
        queue_destruction__7TObjectFv((arg0));
        return 1;
    }
    v.y += 1e+01f;
    arg0->pos.y += -2.0f;
    if (arg0->pos.y < v.y) {
        arg0->pos.y = v.y;
        return 1;
    }
    return 0;
}

void TBoss6GravBall::update_lifetime(void *) {
    s32 temp_r0;

    temp_r0 = this->m_b4 + 1;
    this->m_b4 = temp_r0;
    if (temp_r0 > 0x1E) {
        queue_destruction__7TObjectFv((this));
    }
}

}

#include "pso/boss/TBoss6GravBall_80323878.h"
#include "pso/unk/text_80087278.h"
#include "pso/player/TObjPlayer.h"

struct Obj_80323D20 {
    s32 f0; u8 pad[0xAC - 4]; s32 fAC; s32 fB0; s32 fB4; u8 padB8[4]; f32 fBC; s32 fC0; s32 fC4; f32 pos[3];
};

class TBoss6GravBall_80323BBC {
public:
    u8 pad[0xB0];
    s32 state;
    u8 pad2[0xC];
    s32 counter;
    void s0(); void s1(); void s2();
};
typedef void (TBoss6GravBall_80323BBC::*Act_80323BBC)();
typedef void (TBoss6GravBall::*ActP_80323BBC)(void *);
typedef void (TBoss6GravBall::*Act0_80323BBC)();

extern "C" {
s32 check_demo_mode__10TObjPlayerFv(void *);
s32 query_teammate_state__9TObjEneDDFv(void);
void VecCopy__FP3VecPC3Vec(void *, void *);
s32 create_emitter__14TBoss6GravBallFl(void *, int);
void TBoss6GravBall__sub_80323320(void *);
extern s32 lbl_8047667C[];
extern s32 __vt__14TBoss6GravBall[];
extern s32 TBoss6GravBall__name;

s32 play_persistent_sound(int, void *, void *, int, int);
s32 play_sound_effect(int, void *, int, int);
s32 get_state__14TBoss6GravBallFv(int);
s32 fn_80323134(void *);
s32 destroy_part__14TBoss6GravBallFl(void *, int);
s32 TBoss6GravBall__sub_80323214(void *, int);
void TBoss6GravBall__sub_80323544(u8 *self);
s32 clamp_to_ground__14TBoss6GravBallFv();


void clear_player_grav_flags__14TBoss6GravBallFv(void *);
void __dl__7TObjectFPv(void *);
void init_parts__14TBoss6GravBallFv(void *);

void update_charge_effects__14TBoss6GravBallFPv(u8 *self) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;

    TBoss6GravBall__sub_803233AC(self);
    play_persistent_sound(0x4003C418, self, self + 0xC8, 0, 0);
    temp_r0 = *(s32 *)((s8 *)self + 0xB8);
    if (temp_r0 >= 0x96) {
        if (temp_r0 == 0x96) {
            create_emitter__14TBoss6GravBallFl(self, 3);
        }
    } else if (temp_r0 > 0x4B) {
        temp_r0_2 = temp_r0 & 0xF;
        if (temp_r0_2 == 0) {
            create_emitter__14TBoss6GravBallFl(self, 3);
        } else if (temp_r0_2 == 0xE) {
            destroy_part__14TBoss6GravBallFl(self, 3);
        }
    } else {
        temp_r0_3 = temp_r0 & 0xF;
        if (temp_r0_3 == 0) {
            create_emitter__14TBoss6GravBallFl(self, 3);
        } else if (temp_r0_3 == 0xA) {
            destroy_part__14TBoss6GravBallFl(self, 3);
        }
    }
    *(s32 *)((s8 *)self + 0xB8) = (s32) (*(s32 *)((s8 *)self + 0xB8) + 1);
    *(s32 *)((s8 *)self + 0xB4) = (s32) (*(s32 *)((s8 *)self + 0xB4) + 1);
    switch (get_state__14TBoss6GravBallFv((int) (*(s32 *)((s8 *)self + 0xAC)))) {
    case 29:
    case 30:
    case 39:
        return;
    case 31:
        if ((s32) *(s32 *)((s8 *)self + 0xC4) == 0) {
            spawn_particle_effect((self + 0xC8), 0x21C);
            spawn_particle_effect((self + 0xC8), 0x21D);
            *(s32 *)((s8 *)self + 0xC4) = 1;
        }
        destroy_part__14TBoss6GravBallFl(self, 5);
        destroy_part__14TBoss6GravBallFl(self, 6);
        destroy_part__14TBoss6GravBallFl(self, 7);
        destroy_part__14TBoss6GravBallFl(self, 8);
        return;
    case 32:
        destroy_part__14TBoss6GravBallFl(self, 4);
        destroy_part__14TBoss6GravBallFl(self, 3);
        destroy_part__14TBoss6GravBallFl(self, 5);
        destroy_part__14TBoss6GravBallFl(self, 6);
        destroy_part__14TBoss6GravBallFl(self, 7);
        destroy_part__14TBoss6GravBallFl(self, 8);
        *(s32 *)((s8 *)self + 0xB4) = 0;
        clear_player_grav_flags__14TBoss6GravBallFv(self);
        *(s32 *)((s8 *)self + 0xB0) = 2;
        play_sound_effect(0x4003C417, self + 0xC8, 0, 0);
        return;
    default:
        queue_destruction__7TObjectFv((self));
        return;
    }
}

void update_state__14TBoss6GravBallFPv(u8 *arg0) {
    f32 temp_f2;
    s32 temp_r3;
    s32 temp_r3_2;
    temp_r3 = clamp_to_ground__14TBoss6GravBallFv();
    if (temp_r3 != 0) {
        TBoss6GravBall__sub_803236F8((TBoss6GravBall *)arg0);
    }
    fn_80323134(arg0);
    if (temp_r3 != 0) {
        create_emitter__14TBoss6GravBallFl(arg0, 2);
        temp_f2 = *(f32 *)((s8 *)arg0 + 0xBC);
        if (temp_f2 < 1.0f) {
            *(f32 *)((s8 *)arg0 + 0xBC) += 0.033333335f;
            if (*(f32 *)((s8 *)arg0 + 0xBC) > 1.0f) {
                *(f32 *)((s8 *)arg0 + 0xBC) = (f32) 1.0f;
            }
        }
        TBoss6GravBall__sub_80323544((arg0));
        play_persistent_sound(0x4003B51A, arg0, arg0 + 0xC8, 0, 0);
        switch (get_state__14TBoss6GravBallFv((int) (*(s32 *)((s8 *)arg0 + 0xAC)))) {
        case 0x27:
            return;
        case 0x1D:
            break;
        case 0x1E:
        case 0x1F:
            destroy_part__14TBoss6GravBallFl(arg0, 0);
            destroy_part__14TBoss6GravBallFl(arg0, 1);
            destroy_part__14TBoss6GravBallFl(arg0, 2);
            TBoss6GravBall__sub_80323214(arg0, 4);
            *(s32 *)((s8 *)arg0 + 0xB8) = 0;
            *(s32 *)((s8 *)arg0 + 0xB4) = 0;
            *(s32 *)((s8 *)arg0 + 0xB0) = 1;
            play_sound_effect(0x4003B516, arg0 + 0xC8, 0, 0);
            break;
        case 0x20:
        default:
            queue_destruction__7TObjectFv((arg0));
            break;
        }
    }
}

void run_task__14TBoss6GravBallFv(TBoss6GravBall_80323BBC *arg0) {
    if (check_demo_mode__10TObjPlayerFv(arg0) != 0) {
        return;
    }
    if (query_teammate_state__9TObjEneDDFv() != 0) {
        return;
    }
    static ActP_80323BBC tbl[3] = {
        &TBoss6GravBall::update_state, &TBoss6GravBall::update_charge_effects, &TBoss6GravBall::update_lifetime,
    };
    Act0_80323BBC a = (Act0_80323BBC)tbl[arg0->state];
    if (a) {
        (((TBoss6GravBall *)arg0)->*a)();
    }
    arg0->counter++;
}

void *__dt__14TBoss6GravBallFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TBoss6GravBall;
        init_parts__14TBoss6GravBallFv(arg0);
        clear_player_grav_flags__14TBoss6GravBallFv(arg0);
        __dt__13TUnk_804AF8A0Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
}
TBoss6GravBall::TBoss6GravBall(s32 arg1, void *arg2) : TUnk_804AF8A0((TObject *)arg1) {
    s32 i;
    ((Obj_80323D20 *)this)->f0 = TBoss6GravBall__name;
    ((Obj_80323D20 *)this)->fAC = arg1;
    VecCopy__FP3VecPC3Vec(((Obj_80323D20 *)this)->pos, arg2);
    ((Obj_80323D20 *)this)->fB4 = 0;
    ((Obj_80323D20 *)this)->fB0 = 0;
    ((Obj_80323D20 *)this)->fBC = 0.0f;
    ((Obj_80323D20 *)this)->fC0 = 0;
    ((Obj_80323D20 *)this)->fC4 = 0;
    TBoss6GravBall__sub_80323320(((Obj_80323D20 *)this));
    for (i = 0; i < 2; i++) {
        create_emitter__14TBoss6GravBallFl(((Obj_80323D20 *)this), lbl_8047667C[i]);
    }
}
extern "C" {

}
