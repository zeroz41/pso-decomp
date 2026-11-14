#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/olgaflow/TBoss6GravBall.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/olgaflow/TBoss6GravBall.h"
#include "pso/player/TObjPlayer.h"
extern "C" void *__ct__14TObjCollidableFP7TObject(void *, s32);

#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/ui/frontend/TAdLdQuestPrtGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_801AF2F0.h"


const char TBoss6GravBall__class_name_string[] = "TBoss6GravBall";
const s32 TBoss6GravBall__emitter_id_table[9] = {535, 536, 537, 538, 539, 534, 534, 534, 534};
const s32 lbl_8047667C[2] = {0, 1};
const Vec lbl_80476684 = {0.0f, 0.0f, 0.0f};
const char *TBoss6GravBall__name = TBoss6GravBall__class_name_string;

struct Vec_80323134 { f32 x, y, z; };
struct Ctl_80323134 { u8 pad[0x38]; Vec_80323134 pos; };
struct Obj_80323134 { u8 pad[0xC8]; Vec_80323134 pos; void *items[9]; };
struct T_80323320 { u8 pad[0xD4]; s32 arr[9]; };

extern "C" {

void fn_80323134(Obj_80323134 *arg0) {
    s32 i;
    Vec_80323134 v;
    Ctl_80323134 *c;
    for (i = 0; i < 9; i++) {
        if (arg0->items[i] != 0) {
            switch (i) {
            case 5: case 6: case 7: case 8:
                c = (Ctl_80323134 *)get_player_by_client_id((u16)(i - 5));
                if (c != 0) {
                    VecCopy((Vec *)&v, (const Vec *)&c->pos);
                    ((TParticleCtrl *)arg0->items[i])->set_position(&v);
                }
                break;
            default:
                ((TParticleCtrl *)arg0->items[i])->set_position(&arg0->pos);
                break;
            }
        }
    }
}

#pragma push
#pragma opt_common_subs off

void TBoss6GravBall::destroy_part(s32 arg1) {
    s32 arg0 = (s32)this;
    u32 temp_r3;
    u8 *temp_r31;
    temp_r31 = (u8 *)(arg0 + (arg1 * 4));
    temp_r3 = *(u32 *)((s8 *)temp_r31 + 0xD4);
    if (temp_r3 != 0U) {
        TParticleCtrl::release((void *)temp_r3);
        *(u32 *)((s8 *)temp_r31 + 0xD4) = 0U;
    }
}

void TBoss6GravBall__sub_80323214(s32 arg0, s32 arg1) {
    s32 temp_r5;
    u8 *temp_r31;
    u8 *boss4_type2;
    temp_r5 = arg1 * 4;
    temp_r31 = (u8 *)(arg0 + temp_r5);
    if ((void *) *(u8 **)((s8 *)temp_r31 + 0xD4) == NULL) {
        *(u8 **)((s8 *)temp_r31 + 0xD4) = (unsigned char *) (create_particle_emitter((void *)(arg0 + 0xC8), *(s32 *)((s8 *)TBoss6GravBall__emitter_id_table + temp_r5)));
        boss4_type2 = (u8 *)(*(u8 **)((s8 *)temp_r31 + 0xD4));
        if (boss4_type2 != NULL) {
            ((TParticleCtrl *)boss4_type2)->set_flags(0x2040);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TBoss6GravBall::create_emitter(s32 arg1) {
    s32 arg0 = (s32)this;
    s32 temp_r5;
    u8 *temp_r31;
    u8 *boss4_type2;
    temp_r5 = arg1 * 4;
    temp_r31 = (u8 *)(arg0 + temp_r5);
    if ((void *) *(u8 **)((s8 *)temp_r31 + 0xD4) == NULL) {
        *(u8 **)((s8 *)temp_r31 + 0xD4) = (unsigned char *) (create_particle_emitter((void *)(arg0 + 0xC8), *(s32 *)((s8 *)TBoss6GravBall__emitter_id_table + temp_r5)));
        boss4_type2 = (u8 *)(*(u8 **)((s8 *)temp_r31 + 0xD4));
        if (boss4_type2 != NULL) {
            ((TParticleCtrl *)boss4_type2)->set_flags(0x40);
        }
    }
}
#pragma pop

void TBoss6GravBall::init_parts() {
    s32 arg0 = (s32)this;
    s32 var_r31;
    var_r31 = 0;
    do {
        destroy_part(var_r31);
        var_r31 += 1;
    } while (var_r31 < 9);
}

void TBoss6GravBall__sub_80323320(T_80323320 *self) {
    s32 i;
    for (i = 0; i < 9; i++) {
        self->arr[i] = 0;
    }
}

void TBoss6GravBall::render() {  }

}

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


void TBoss6GravBall__sub_803236F8(TBoss6GravBall *arg0);
s32 project_actor_to_ground(void *, void *, int);


u16 get_entity_id(void *);
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
        pl = (PL_803233AC *)TObjPlayer::get_player_data(i);
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
        pl = (PL_80323544 *)TObjPlayer::get_player_data(i);
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

void TBoss6GravBall__sub_803236F8(TBoss6GravBall *arg0) {
    Vec v = arg0->ball_position;
    v.y = 0.0f;
    if (vector_length(&v) > 0.6666667f) {
        normalize_vector(&v);
        v.x *= 0.6666667f;
        v.z *= 0.6666667f;
        subtract_vector(&arg0->ball_position, &v);
    } else {
        VecCopy(&arg0->ball_position, &lbl_80476684);
    }
    arg0->clamp_to_ground();
}

s32 TBoss6GravBall::clamp_to_ground() {
    Obj_803237A0 *arg0 = (Obj_803237A0 *)this;
    Vec_803237A0 v = arg0->pos;
    if (project_actor_to_ground(arg0, &v, 0) == 0) {
        ((TObject *)arg0)->queue_destruction();
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
        queue_destruction();
    }
}

}

#include "pso/boss/olgaflow/TBoss6GravBall_80323878.h"
#include "pso/unk/text_80087278.h"
#include "pso/player/TObjPlayer.h"

struct Obj_80323D20 {
    const char *name; u8 pad[0xAC - 4]; s32 fAC; s32 fB0; s32 fB4; u8 padB8[4]; f32 fBC; s32 fC0; s32 fC4; f32 pos[3];
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
extern s32 __vt__14TBoss6GravBall[];

s32 play_persistent_sound(int, void *, void *, int, int);
void TBoss6GravBall__sub_80323544(u8 *self);
s32 clamp_to_ground__14TBoss6GravBallFv();


void clear_player_grav_flags__14TBoss6GravBallFv(void *);
void __dl__7TObjectFPv(void *);

void update_charge_effects__14TBoss6GravBallFPv(u8 *self) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;

    TBoss6GravBall__sub_803233AC(self);
    play_persistent_sound(0x4003C418, self, self + 0xC8, 0, 0);
    temp_r0 = *(s32 *)((s8 *)self + 0xB8);
    if (temp_r0 >= 0x96) {
        if (temp_r0 == 0x96) {
            ((TBoss6GravBall *)self)->create_emitter(3);
        }
    } else if (temp_r0 > 0x4B) {
        temp_r0_2 = temp_r0 & 0xF;
        if (temp_r0_2 == 0) {
            ((TBoss6GravBall *)self)->create_emitter(3);
        } else if (temp_r0_2 == 0xE) {
            ((TBoss6GravBall *)self)->destroy_part(3);
        }
    } else {
        temp_r0_3 = temp_r0 & 0xF;
        if (temp_r0_3 == 0) {
            ((TBoss6GravBall *)self)->create_emitter(3);
        } else if (temp_r0_3 == 0xA) {
            ((TBoss6GravBall *)self)->destroy_part(3);
        }
    }
    *(s32 *)((s8 *)self + 0xB8) = (s32) (*(s32 *)((s8 *)self + 0xB8) + 1);
    *(s32 *)((s8 *)self + 0xB4) = (s32) (*(s32 *)((s8 *)self + 0xB4) + 1);
    switch (((TBoss6GravBall *)((int) (*(s32 *)((s8 *)self + 0xAC))))->get_state()) {
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
        ((TBoss6GravBall *)self)->destroy_part(5);
        ((TBoss6GravBall *)self)->destroy_part(6);
        ((TBoss6GravBall *)self)->destroy_part(7);
        ((TBoss6GravBall *)self)->destroy_part(8);
        return;
    case 32:
        ((TBoss6GravBall *)self)->destroy_part(4);
        ((TBoss6GravBall *)self)->destroy_part(3);
        ((TBoss6GravBall *)self)->destroy_part(5);
        ((TBoss6GravBall *)self)->destroy_part(6);
        ((TBoss6GravBall *)self)->destroy_part(7);
        ((TBoss6GravBall *)self)->destroy_part(8);
        *(s32 *)((s8 *)self + 0xB4) = 0;
        clear_player_grav_flags__14TBoss6GravBallFv(self);
        *(s32 *)((s8 *)self + 0xB0) = 2;
        play_sound_effect(0x4003C417, self + 0xC8, 0, 0);
        return;
    default:
        ((TObject *)self)->queue_destruction();
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
    fn_80323134((Obj_80323134 *)arg0);
    if (temp_r3 != 0) {
        ((TBoss6GravBall *)arg0)->create_emitter(2);
        temp_f2 = *(f32 *)((s8 *)arg0 + 0xBC);
        if (temp_f2 < 1.0f) {
            *(f32 *)((s8 *)arg0 + 0xBC) += 0.033333335f;
            if (*(f32 *)((s8 *)arg0 + 0xBC) > 1.0f) {
                *(f32 *)((s8 *)arg0 + 0xBC) = 1.0f;
            }
        }
        TBoss6GravBall__sub_80323544((arg0));
        play_persistent_sound(0x4003B51A, arg0, arg0 + 0xC8, 0, 0);
        switch (((TBoss6GravBall *)((int) (*(s32 *)((s8 *)arg0 + 0xAC))))->get_state()) {
        case 0x27:
            return;
        case 0x1D:
            break;
        case 0x1E:
        case 0x1F:
            ((TBoss6GravBall *)arg0)->destroy_part(0);
            ((TBoss6GravBall *)arg0)->destroy_part(1);
            ((TBoss6GravBall *)arg0)->destroy_part(2);
            TBoss6GravBall__sub_80323214((s32)arg0, 4);
            *(s32 *)((s8 *)arg0 + 0xB8) = 0;
            *(s32 *)((s8 *)arg0 + 0xB4) = 0;
            *(s32 *)((s8 *)arg0 + 0xB0) = 1;
            play_sound_effect(0x4003B516, arg0 + 0xC8, 0, 0);
            break;
        case 0x20:
        default:
            ((TObject *)arg0)->queue_destruction();
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

}
TBoss6GravBall::~TBoss6GravBall() {
    init_parts();
    clear_player_grav_flags__14TBoss6GravBallFv(this);
}
TBoss6GravBall::TBoss6GravBall(s32 arg1, void *arg2) : TObjCollidable((TObject *)arg1) {
    s32 i;
    ((Obj_80323D20 *)this)->name = TBoss6GravBall__name;
    ((Obj_80323D20 *)this)->fAC = arg1;
    VecCopy__FP3VecPC3Vec(((Obj_80323D20 *)this)->pos, arg2);
    ((Obj_80323D20 *)this)->fB4 = 0;
    ((Obj_80323D20 *)this)->fB0 = 0;
    ((Obj_80323D20 *)this)->fBC = 0.0f;
    ((Obj_80323D20 *)this)->fC0 = 0;
    ((Obj_80323D20 *)this)->fC4 = 0;
    TBoss6GravBall__sub_80323320((T_80323320 *)this);
    for (i = 0; i < 2; i++) {
        ((TBoss6GravBall *)((Obj_80323D20 *)this))->create_emitter(lbl_8047667C[i]);
    }
}
