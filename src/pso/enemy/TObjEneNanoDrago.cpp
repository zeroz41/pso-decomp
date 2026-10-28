#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneNanoDrago.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/misc/TCameraCtrl.h"

#include "pso/enemy/TUnk_80494938.h"

struct RecoveredGlobal_800D9E8C_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct Obj_800D9F4C { u8 pad[0x3b4]; s32 f3b4; };

struct Vec_800D9C7C { f32 x, y, z; };

struct Hit_800D9C7C { u8 pad[4]; s32 x4; };

typedef struct Vec_800D9FC4
{
  f32 x;
  f32 y;
  f32 z;
} Vec_800D9FC4;

typedef struct Obj_800D9FC4
{
  u8 pad0[0x30];
  u32 flags;
  u8 pad34[0x38 - 0x34];
  Vec_800D9FC4 pos;
  u8 pad44[0x60 - 0x44];
  s32 angle;
  u8 pad64[0x3B4 - 0x64];
  s32 count;
  s16 ids[12];
} Obj_800D9FC4;

extern "C" {
s32 TObjPlayer__sub_800DC420(void *self, s32 i);
f32 TObjPlayer__sub_800DC434(s32 arg0, s32 arg1);
extern f32 lbl_805D525C;
extern f32 lbl_805D5260;
extern f32 lbl_805D5264;
extern f32 lbl_805D5268;
extern s32 lbl_805D526C;
extern s32 lbl_805D5270;
void TObjPlayer__sub_800D9E08(s32 arg0);
void push_matrix_from(void *, f32);
s32 pop_matrix(void);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 translate_matrix(int, f32, f32, f32);
extern RecoveredGlobal_800D9E8C_lbl_8058D490 identity_matrix;
extern s32 lbl_805D586C;
extern s32 lbl_805D5870;
int get_player_data__10TObjPlayerFi(int a0);
s32 TObjPlayer__sub_800D9F4C(Obj_800D9F4C *self);
f32 atan2_float(f32, f32);
Hit_800D9C7C *csnVector(void *, void *, s32);
void vec3_add_to(void *, void *);
s32 matrix_mult_vec(int, Vec_800D9C7C *, void *);
extern Vec_800D9C7C lbl_8043C8E4;
extern Vec_800D9C7C find_open_direction_zero_vec;
extern const f64 lbl_8043C900[];
void find_open_direction__10TObjPlayerFPvPv(u8 *arg0, f32 *arg1);
s16 get_entity_id(void *);
s32 angle_difference_abs(s32, s32);
void subtract_vector(void *, void *);
s32 update_action_hold_status__16TObjEneNanoDragoFv(s32 arg0);
s32 update_action_hold_status__13TUnk_804806E8Fv();

s32 TObjEneNanoDrago::update_action_hold_status() {
    s32 arg0 = (s32)this;
    if (update_action_hold_status__13TUnk_804806E8Fv() != 0) {
        ((TObjEneNanoDrago *)arg0)->sub_800D9BBC();
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
void find_open_direction__10TObjPlayerFPvPv(u8 *arg0, f32 *arg1) {
    s32 ang;
    s32 best;
    s32 i;
    f32 bias;
    f32 bestv;
    f32 d;
    Hit_800D9C7C *h;
    ang = (s32)(lbl_8043C900[0] * atan2_float(arg1[0], arg1[2]));
    bestv = 0.0f;
    best = ang;
    ((s32 (*)(u32))push_matrix_from)((u32) &identity_matrix.value);
    {
        Vec_800D9C7C v = lbl_8043C8E4;
        rotate_matrix_y(0, ang);
        i = 0;
        bias = 20.0f;
        for (; i < 3; i++) {
            matrix_mult_vec(0, &v, arg0 + 0x390);
            vec3_add_to(arg0 + 0x390, arg0 + 0x2FC);
            h = csnVector(arg0 + 0x2FC, arg0 + 0x390, -1);
            if (h == NULL) {
                pop_matrix();
                return;
            }
            d = vec_xz_distance((Vec *)(arg0 + 0x38), (Vec *)h->x4) - bias;
            if (bestv < d) {
                bestv = d;
                best = ang;
            }
            rotate_matrix_y(0, 0x5555);
            ang += 0x5555;
        }
    }
    pop_matrix();
    ((s32 (*)(u32))push_matrix_from)((u32) &identity_matrix.value);
    {
        Vec_800D9C7C v2 = find_open_direction_zero_vec;
        v2.x = bestv;
        rotate_matrix_y(0, best);
        matrix_mult_vec(0, &v2, arg0 + 0x390);
        vec3_add_to(arg0 + 0x390, arg0 + 0x2FC);
        pop_matrix();
    }
}
#pragma pop

void TObjPlayer__sub_800D9E08(s32 arg0) {
    lbl_805D525C = TObjPlayer__sub_800DC434((arg0), 1);
    lbl_805D5260 = TObjPlayer__sub_800DC434((arg0), 2);
    lbl_805D5264 = TObjPlayer__sub_800DC434((arg0), 3);
    lbl_805D5268 = TObjPlayer__sub_800DC434((arg0), 4);
    lbl_805D526C = TObjPlayer__sub_800DC420((void *)arg0, 0);
    lbl_805D5270 = TObjPlayer__sub_800DC420((void *)arg0, 1);
}
typedef char RecoveredGlobal_800D9E8C_lbl_8058D490_size[sizeof(RecoveredGlobal_800D9E8C_lbl_8058D490) == 0x30 ? 1 : -1];
void TObjPlayer::render_model_transformed() {
    f32 temp_f1;
    ((s32 (*)(u32))push_matrix_from)((u32) &identity_matrix.value);
    translate_matrix(0, (f32) (this->position.x), (f32) (this->m_404 + (this->position.y + *(f32 *)&this->m_3e4)), this->position.z);
    rotate_matrix_y(0, this->rotation_y);
    temp_f1 = this->scale.x;
    scale_matrix(0, temp_f1, temp_f1, temp_f1);
    ((TObjEnemy *)((u8 *)this))->render_anim_model(*(f32 *)&this->m_c0);
    pop_matrix();
    this->get_anim_node_position(0x55, (Vec *)((u8 *)this + 0x39C));
    this->get_anim_node_position(0x54, (Vec *)((u8 *)this + 0x3A8));
}
s32 TObjPlayer__sub_800D9F4C(Obj_800D9F4C *self) {
    s32 i;
    void *p;
    self->f3b4 = 0;
    for (i = 0; i < lbl_805D586C + lbl_805D5870; i++) {
        p = (void *)get_player_data__10TObjPlayerFi(i);
        if (TObjPlayer::is_valid_and_active((u32)p) != 0) {
            ((TObjPlayer *)self)->add_target_in_front_arc(p);
        }
    }
    return self->f3b4;
}
typedef struct Obj_800D9FC4 Obj_800D9FC4;
typedef struct Vec_800D9FC4 Vec_800D9FC4;
void TObjPlayer::add_target_in_front_arc(void *p) {
  f32 new_var;
  int new_var2;
  if ((((((Obj_800D9FC4 *) this)->count < 12) && (p != 0)) && (p != this)) && (!(((Obj_800D9FC4 *) p)->flags & 0x6000800)))
  {
    Vec_800D9FC4 v = ((Obj_800D9FC4 *) p)->pos;
    subtract_vector(&v, &((Obj_800D9FC4 *) this)->pos);
    if (!(((v.x * v.x) + (v.z * v.z)) > 160000.0f))
    {
      new_var = v.x;
      new_var2 = (-((s32) (lbl_8043C900[0] * atan2_float(v.z, new_var)))) + 0x4000;
      if (angle_difference_abs(new_var2, ((Obj_800D9FC4 *) this)->angle) <= 0xAAA)
      {
        s16 id = get_entity_id(p);
        s16 *ids = ((Obj_800D9FC4 *) this)->ids;
        ids[((Obj_800D9FC4 *) this)->count++] = id;
      }
    }
  }
}

}
#include <stddef.h>
typedef char NanoGrow_scale[offsetof(TObjEneNanoDrago, scale.x) == 0x68 ? 1 : -1];
typedef char NanoGrow_target_scale[offsetof(TObjEneNanoDrago, scale.y) == 0x6c ? 1 : -1];
typedef char NanoGrow_m_2c0[offsetof(TObjEneNanoDrago, m_2c0) == 0x2c0 ? 1 : -1];
typedef char NanoGrow_m_2c8[offsetof(TObjEneNanoDrago, m_2c8) == 0x2c8 ? 1 : -1];
typedef char NanoGrow_m_2fc[offsetof(TObjEneNanoDrago, m_2fc) == 0x2fc ? 1 : -1];
typedef char NanoGrow_params[offsetof(TObjEneNanoDrago, movementParameters) == 0x350 ? 1 : -1];
typedef char NanoGrow_next_action[offsetof(TObjEneNanoDrago, next_action) == 0x374 ? 1 : -1];
typedef char NanoGrow_state[offsetof(TObjEneNanoDrago, state) == 0x37c ? 1 : -1];
typedef char NanoGrow_growth_count[offsetof(TObjEneNanoDrago, growth_count) == 0x38c ? 1 : -1];
typedef char NanoGrow_speed[offsetof(TObjEneNanoDrago, speed) == 0x3d8 ? 1 : -1];
typedef char NanoDrago_flags30_offset[offsetof(TObjEneNanoDrago, actorFlags) == 0x30 ? 1 : -1];
typedef char NanoDrago_pos_offset[offsetof(TObjEneNanoDrago, position) == 0x38 ? 1 : -1];
typedef char NanoDrago_angle_offset[offsetof(TObjEneNanoDrago, rotation_y) == 0x60 ? 1 : -1];
typedef char NanoDrago_fb8_offset[offsetof(TObjEneNanoDrago, m_b8) == 0xb8 ? 1 : -1];
typedef char NanoDrago_home_offset[offsetof(TObjEneNanoDrago, m_29c) == 0x29c ? 1 : -1];
typedef char NanoDrago_target_offset[offsetof(TObjEneNanoDrago, target) == 0x2a8 ? 1 : -1];
typedef char NanoDrago_hpmax_offset[offsetof(TObjEneNanoDrago, hpmax) == 0x2b8 ? 1 : -1];
typedef char NanoDrago_hp_offset[offsetof(TObjEneNanoDrago, hp) == 0x32c ? 1 : -1];
typedef char NanoDrago_params_offset[offsetof(TObjEneNanoDrago, movementParameters) == 0x350 ? 1 : -1];
typedef char NanoDrago_state_offset[offsetof(TObjEneNanoDrago, state) == 0x37c ? 1 : -1];
typedef char NanoDrago_flags388_offset[offsetof(TObjEneNanoDrago, m_388) == 0x388 ? 1 : -1];
typedef char NanoDrago_accum_offset[offsetof(TObjEneNanoDrago, accum) == 0x3d0 ? 1 : -1];
typedef char NanoDrago_t_offset[offsetof(TObjEneNanoDrago, t) == 0x3d4 ? 1 : -1];
typedef char NanoDrago_speed_offset[offsetof(TObjEneNanoDrago, speed) == 0x3d8 ? 1 : -1];
typedef char NanoDrago_toggle_offset[offsetof(TObjEneNanoDrago, toggle) == 0x3e0 ? 1 : -1];

#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define PADV virtual void CAT(pv, __LINE__)();
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();
struct Base_Sub_800da0b8 { char pad[0x14]; };
struct V_Sub_800da0b8 : Base_Sub_800da0b8 {
    PADV4
    PADV
    virtual s32 m5();
};

struct V3_800DA1F4 { f32 x; f32 y; f32 z; };
struct Obj_800DA1F4 { u8 pad0[0x30]; u32 flags; u8 pad34[4]; V3_800DA1F4 pos; V3_800DA1F4 pos2; u8 pad50[0x60 - 0x50]; s32 h; u8 pad64[0x378 - 0x64]; s32 f378; };

struct Obj_800DA1F4;
struct Base_800DA2A0 {
    char pad[0x18];
};

struct Ene_800DA2A0 : Base_800DA2A0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual s32 v17(s32);
    u8 pad1C[0x326 - 0x1C];
    s16 state;
    u8 pad328[0x350 - 0x328];
    f32 *param;
    u8 pad354[0x378 - 0x354];
    s32 f378;
    u8 pad37C[0x388 - 0x37C];
    u32 f388;
};

typedef NanoDragoVector Vec_800DB5A8;
extern "C" {
u16 find_nearest_visible_player(void *, s32, f32);
s32 apply_actor_gravity(void *, int, f32);
s32 enemy_wander_home__9TObjEnemyFlfff(void *, int, f32, f32, f32);
void enemy_set_heading_velocity(void *, f32, s32);
f32 atan2_float(f32 y, f32 x);
s32 update_if_active__15TObjEneMe1GiGueFl(void *, s32, s32);
s32 sub_8004292C__15TObjEnemyCustomFv();
s32 advance_animation_playback(void *);
s32 check_enemy_body_collisions(void *);
void check_object_collisions__10TObjPlayerFv(void *);
s32 play_sound_effect(int, void *, int, int);
void rotate_vector_by_matrix(int, void *, void *);

s32 TObjEneMe3SinowZoa__sub_800D758C(void *);
u32 get_player_by_client_id(s32);
s32 play_area_sound_effect__12TBoss3VoloptFv(void *, s32);

void TObjPlayer::update_death_state() {
    s32 temp_r4;
    s32 temp_r5;

    switch (this->m_37c) {
    case 0:
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 | 4);
        temp_r4 = this->actorFlags | 0x04000000;
        this->actorFlags = temp_r4;
        this->m_b8 = 0;
        play_area_sound_effect__12TBoss3VoloptFv(((u8 *)this) + 0x2FC, temp_r4);
        TObjEneMe3SinowZoa__sub_800D758C(((u8 *)this) + 0x3E8);
        this->m_37c = 1;
    case 1:
        advance_animation_playback(this);
        if (((V_Sub_800da0b8 *) (((u8 *)this) + 0x3E8))->m5() == 1) {
            this->m_37c = -1;
        }
        this->update_collisions();
        return;
    case -1:
        temp_r5 = *(s32 *)&this->unk_388;
        *(s32 *)&this->unk_388 = (s32) (temp_r5 & ~5);
        this->actorFlags = (s32) (this->actorFlags & 0xFBFFFFFF);
        update_if_active__15TObjEneMe1GiGueFl(this, 0, temp_r5);
        break;
    }
}

void TObjPlayer::trigger_hit_camera_shake(u32 arg1) {
    if ((arg1 == get_player_by_client_id(0)) && ((s32) this->m_3dc <= 0)) {
        this->m_3dc = 0x1E;
        TCameraCtrl::set_shake_preset(1);
    }
}

void TObjEneNanoDrago::sub_800DA1F4() {
    Obj_800DA1F4 *arg0 = (Obj_800DA1F4 *)this;
    V3_800DA1F4 v;
    v.y = 0.0f;
    v.x = 0.0f;
    v.z = (-150.0f);
    push_matrix_from(&identity_matrix, 0.0f);
    rotate_matrix_y(0, arg0->h);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrix();
    vec3_add_to(&arg0->pos, &v);
    VecCopy((Vec *)&arg0->pos2, (const Vec *)&arg0->pos);
    arg0->flags |= 0x01000000;
    ((void (*)(void *, int))update_if_active__15TObjEneMe1GiGueFl)(arg0, 0xB);
    arg0->f378 = 1;
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
}
void TObjEneNanoDrago::sub_800DA2A0() {
    switch (((Ene_800DA2A0 *)this)->state) {
    case 0:
        if (this->is_actor_cadence_frame(0x1E) != 0) {
            if (find_nearest_visible_player(((Ene_800DA2A0 *)this), 0, *((Ene_800DA2A0 *)this)->param) != 0xFFFF) {
                select_nearest_target(*((Ene_800DA2A0 *)this)->param);
                if (((Ene_800DA2A0 *)this)->f388 & 0x40000) {
                    sub_800DA1F4();
                } else {
                    ((void (*)(void *, int))update_if_active__15TObjEneMe1GiGueFl)(((Ene_800DA2A0 *)this), 1);
                }
            }
        }
        break;
    case 11:
        break;
    case 1:
        if (find_nearest_visible_player(((Ene_800DA2A0 *)this), 0, 50.0f) != 0xFFFF) {
            ((void (*)(void *, int))update_if_active__15TObjEneMe1GiGueFl)(((Ene_800DA2A0 *)this), 0xB);
            ((Ene_800DA2A0 *)this)->f378 = 1;
        } else if (find_nearest_visible_player(((Ene_800DA2A0 *)this), 0, 50.0f + *((Ene_800DA2A0 *)this)->param) == 0xFFFF) {
            ((void (*)(void *, int))update_if_active__15TObjEneMe1GiGueFl)(((Ene_800DA2A0 *)this), 0);
        }
        break;
    }
}
}
void move_with_wall_slide(u8 *arg0);

struct Rec_800DA4B4 { s32 a; s32 b; s32 c; };

struct Obj_800DA4B4 { u8 pad[0x60]; s32 f60; u8 pad2[0x39c - 0x64]; Rec_800DA4B4 recs[1]; };

struct Vec_800DA4B4 { s32 x; s32 y; s32 z; };

struct S_800DA414 { s32 a; s32 b; s32 c; };

struct Obj_800DA414 { u8 pad0[0x1C]; u16 f1c; u8 pad1e[0x60 - 0x1E]; s32 h; u8 pad64[0x39C - 0x64]; u8 sub[2][0xC]; u8 pad3b4[4]; u16 ids[2]; };

typedef struct Vec_800DA508 {
    f32 x, y, z;
} Vec_800DA508;

typedef struct Param_800DA508 {
    u8 pad0[8];
    s32 turn;
} Param_800DA508;

typedef struct Ene_800DA508 {
    u8 pad0[0x38];
    Vec_800DA508 pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0x29C - 0x64];
    Vec_800DA508 v29C;
    u8 pad2A8[0x350 - 0x2A8];
    Param_800DA508 *param;
    u8 pad354[0x390 - 0x354];
    Vec_800DA508 dest;
    u8 pad39C[0x3D8 - 0x39C];
    f32 speed;
} Ene_800DA508;

struct Vec_800DA7E4 { f32 x, y, z; };

typedef struct Home_800DB0F8 {
    u8 pad0[8];
    s32 f8;
} Home_800DB0F8;

typedef struct Obj_800DB0F8 {
    u8 pad0[0x30];
    s32 flags30;
    u8 pad34[0x38 - 0x34];
    u8 pos[0xC];
    u8 pad44[0xB8 - 0x44];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 frame;
    u8 padC4[0x350 - 0xC4];
    Home_800DB0F8 *home;
    u8 pad354[0x37C - 0x354];
    s32 state;
    u8 pad380[0x384 - 0x380];
    s32 timer;
    s32 f388;
    u8 pad38C[0x39C - 0x38C];
    u8 fx39C[0xC];
    u8 fx3A8[0xC];
    s32 count;
    u8 pad3B8[0x3D8 - 0x3B8];
    f32 f3D8;
} Obj_800DB0F8;

struct Vec_800DAB98 { f32 x, y, z; };

extern "C" {
void vfunc_63__16TObjEneNanoDragoFv(u8 *arg0);
void *spawn_directional_particle(void *pos, void *dir, s32 id);
void TObjPlayer__sub_800DCD04(void *, void *, int, void *, s32, int);
void *find_entity_by_id(u16 id);
u32 __nw__7TObjectFUl(u32);
void TObjPlayer__sub_800DA414(Obj_800DA414 *arg0, s32 arg1);
f32 calc_boss4_scale__10TObjPlayerFi(void *);
void enemy_turn_toward_dest(void *, s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
void update_circle_move__10TObjPlayerFPvPvf(Ene_800DA508 *arg0, Vec_800DA508 *center, f32 radius);
s32 enemy_turn_half_toward_dest(void *);
void *spawn_particle_effect(void *pos, s32 id);
s32 construct_beam_effect__10TObjPlayerFPvPvPviPv(u32, void *, void *, u8, void *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void TObjPlayer__sub_800DB390(u8 *arg0);
s32 check_path_obstructed(void *, Vec_800DA7E4 *);
void TObjPlayer__sub_800DA7E4(u8 *arg0);
void TObjPlayer__sub_800DB0F8(Obj_800DB0F8 *o);
void calc_velocity_toward_destination(void *, Vec_800DAB98, Vec_800DAB98, f32);
s32 TObjPlayer__sub_800DC478(u8 *arg0, s32 arg1, f32 farg0);
void project_actor_to_ground(void *, void *, s32);
void TObjPlayer__sub_800DAB98(u8 *arg0);
s32 queue_destruction__7TObjectFv();
void TObjPlayer__sub_800D92BC(s32 point, s32 delay);
s32 refresh_lobby_state__10TObjPlayerFv();
void update_death_sequence__10TObjPlayerFPv(u8 *arg0);

void TObjPlayer::set_flag_20000() {
    if (!(*(s32 *)&this->unk_388 & 0x20000)) {
        ((s32 (*)(void *, s32))update_if_active__15TObjEneMe1GiGueFl)(this, 0xC);
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 | 0x20000 | 1);
    }
}

void TObjPlayer__sub_800DA414(Obj_800DA414 *arg0, s32 arg1) {
    S_800DA414 s;
    s32 t;
    s32 off;
    void *o;
    if (find_entity_by_id(arg0->ids[arg1]) != 0) {
        t = arg1 & 1;
        s.a = 0;
        off = 0x2000;
        if (t != 0) {
            off = -0x2000;
        }
        s.b = arg0->h + off;
        s.c = 0;
        o = (void *)__nw__7TObjectFUl(0x104);
        if (o != 0) {
            TObjPlayer__sub_800DCD04(o, arg0->sub[t], arg0->ids[arg1], &s, arg1 * 3, arg0->f1c);
        }
    }
}

void TObjPlayer::spawn_directional_particle_at_slot(s32 i) {
    Vec_800DA4B4 v;
    v.x = ((Obj_800DA4B4 *)this)->f60 + 0x4000;
    v.y = 0;
    v.z = 0x4000;
    spawn_directional_particle(&((Obj_800DA4B4 *)this)->recs[i], &v, 0xfd);
}

#pragma push
#pragma fp_contract on
void update_circle_move__10TObjPlayerFPvPvf(Ene_800DA508 *actor, Vec_800DA508 *center, f32 radius) {
    s32 ang;
    f32 r;
    if (xz_distance_squared((Vec *)&actor->pos, (Vec *)&actor->dest) < 400.0f) {
        ang = (s32)(182.04445f * (360.0f * calc_boss4_scale__10TObjPlayerFi(actor)));
        r = 0.4f * (radius * (1.0f + calc_boss4_scale__10TObjPlayerFi(actor)));
        actor->dest.x = r * cos_table_lookup(ang) + center->x;
        actor->dest.z = r * sin_table_lookup(ang) + center->z;
    }
    VecCopy((Vec *)&actor->v29C, (const Vec *)&actor->dest);
    enemy_turn_toward_dest(actor, actor->param->turn);
    enemy_set_heading_velocity(actor, actor->speed, actor->angle);
    move_with_wall_slide((u8 *)actor);
}
#pragma pop

struct Obj_800DA4B4;

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline f32 fmax_800DA5FC(f32 a, f32 b) {
    if (a > b) {
        return a;
    }
    return b;
}
void update_death_sequence__10TObjPlayerFPv(u8 *enemy) {
    f32 var_f1;
    switch (*(s32 *)((s8 *)enemy + 0x37C)) {
    case 0:
        refresh_lobby_state__10TObjPlayerFv();
        ((TObjEnemy *)enemy)->send_entity_set_flags();
        *(s16 *)&((TObjEnemy *)enemy)->timer = 0x1E;
        play_sound_effect(0x4003A825, enemy + 0x38, 0, 0);
        if (*(s32 *)&((TObjEnemy *)enemy)->actorFlags & 0x01000000) {
            *(f32 *)((s8 *)enemy + 0x408) = (f32) (0.015384615f * -*(f32 *)((s8 *)enemy + 0x404));
            ((TObjEnemy *)enemy)->m_b8 = 0xB;
            *(s32 *)((s8 *)enemy + 0x37C) = 2;
            return;
        }
        ((TObjEnemy *)enemy)->m_b8 = 4;
        *(s32 *)((s8 *)enemy + 0x37C) = 1;
        return;
    case 1:
        ((s32 (*)())advance_animation_playback)();
        apply_actor_gravity(enemy, 0, (f32) (0.0f));
        if (((TObjEnemy *)enemy)->m_c0 >= 30.0f) {
            spawn_particle_effect((enemy + 0x38), 0xF0);
            *(s32 *)((s8 *)enemy + 0x37C) = 3;
            return;
        }
        break;
    case 2:
        ((s32 (*)())advance_animation_playback)();
        apply_actor_gravity(enemy, 0, (f32) (0.0f));
        {
        f32 lim = 0.0f;
        *(f32 *)((s8 *)enemy + 0x404) = fmax_800DA5FC(*(f32 *)((s8 *)enemy + 0x404) + *(f32 *)((s8 *)enemy + 0x408), lim);
        }
        if (((TObjEnemy *)enemy)->m_c0 >= 30.0f) {
            spawn_particle_effect((enemy + 0x38), 0xF0);
            play_sound_effect(0x40039E22, enemy + 0x38, 0, 0);
            *(s32 *)((s8 *)enemy + 0x37C) = 3;
            return;
        }
        break;
    case 3:
        *(s16 *)&((TObjEnemy *)enemy)->timer = (s16) (*(s16 *)&((TObjEnemy *)enemy)->timer - 1);
        if (*(s16 *)&((TObjEnemy *)enemy)->timer <= 0) {
            ((TObjPlayer *)(enemy + 0x38))->spawn_ground_effect(0x1E);
            TObjPlayer__sub_800D92BC((s32)(enemy + 0x38), 0xF);
            *(s32 *)((s8 *)enemy + 0x37C) = 4;
            return;
        }
        break;
    case 4:
        *(f32 *)((s8 *)enemy + 0x3E4) = (f32) (*(f32 *)((s8 *)enemy + 0x3E4) - 0.3f);
        if (*(f32 *)((s8 *)enemy + 0x3E4) < (-15.0f)) {
            queue_destruction__7TObjectFv();
        }
        break;
    }
}
#pragma pop

void TObjPlayer__sub_800DA7E4(u8 *player) {
    f32 sp10;
    s32 spC;
    f32 sp8;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_r5;
    s16 temp_r4;
    s16 var_r3;
    u32 entity;
    s32 var_r30;
    switch (((TObjPlayer *)player)->m_37c) {
    case 0:
        var_r3 = 3;
        ((TObjPlayer *)player)->actorFlags = (s32) (((TObjPlayer *)player)->actorFlags & 0xFFDFFFFF);
        if (((TObjPlayer *)player)->actorFlags & 0x01000000) {
            var_r3 = 0xA;
        }
        ((TObjPlayer *)player)->m_b8 = var_r3;
        spawn_particle_effect((player + 0x2FC), 0xF2);
        play_sound_effect(0x40039E22, player + 0x38, 0, 0);
        ((TObjPlayer *)player)->m_37c = 1;
    case 1:
        advance_animation_playback(player);
        if (!(((TObjPlayer *)player)->actorFlags & 0x01000000)) {
            Vec_800DA7E4 v = *(Vec_800DA7E4 *)((s8 *)player + 0x2FC);
            v.x += *(f32 *)((s8 *)player + 0x308);
            v.z += ((TObjPlayer *)player)->m_310;
            if (check_path_obstructed(player, &v) == 0) {
                move_with_wall_slide(player);
            } else {
                *(f32 *)((s8 *)player + 0x308) = ((TObjPlayer *)player)->m_310 = 0.0f;
            }
            *(f32 *)((s8 *)player + 0x308) *= 0.5f;
            ((TObjPlayer *)player)->m_310 *= 0.5f;
        }
        apply_actor_gravity(player, 0, 0.0f);
        ((TObjPlayer *)player)->update_collisions();
        if ((u32) ((TObjPlayer *)player)->m_b4 != 8U) {
            ((TObjPlayer *)player)->m_37c = -1;
        }
        break;
    case -1:
        var_r30 = 0;
        ((TObjPlayer *)player)->actorFlags = (s32) (((TObjPlayer *)player)->actorFlags & 0xFFFFFDFF);
        *(s32 *)((s8 *)player + 0x388) = (s32) (*(s32 *)((s8 *)player + 0x388) & 0xFFFFFFFE);
        *(s32 *)((s8 *)player + 0x378) = 1;
        temp_r4 = ((TObjPlayer *)player)->m_33e;
        if (((s32) (temp_r4 - ((TObjPlayer *)player)->hp) > (s32) (temp_r4 / 4)) && !(((TObjPlayer *)player)->actorFlags & 2)) {
            entity = (u32)find_entity_by_id(((TObjPlayer *)player)->m_2d4);
            if (entity != 0) {
                var_r30 = 1;
                if ((((TObjPlayer *)player)->actorFlags & 0x01000000) && (xz_distance_squared((Vec *)(player + 0x38), (Vec *)((u8 *)entity + 0x38)) > 400.0f)) {
                    var_r30 = 0;
                }
            }
        }
        if (var_r30 == 1) {
            *(u16 *)((s8 *)player + 0x338) = (u16) ((TObjPlayer *)player)->m_2d4;
            *(s32 *)((s8 *)player + 0x374) = 0xA;
        } else if (((TObjPlayer *)player)->actorFlags & 0x01000000) {
            ((s32 (*)(void *, s32))update_if_active__15TObjEneMe1GiGueFl)(player, 0xB);
            *(s32 *)((s8 *)player + 0x378) = (s32) *(s32 *)((s8 *)player + 0x380);
        } else {
            ((s32 (*)(void *, s32))update_if_active__15TObjEneMe1GiGueFl)(player, 0);
        }
        ((TObjPlayer *)player)->m_33e = (s16) ((TObjPlayer *)player)->hp;
        break;
    }
}

struct Obj_800DA414;

#define F(t, o) (*(t *)(arg0 + (o)))
#define POS (*(Vec_800DAB98 *)(arg0 + 0x38))
#define DEST (*(Vec_800DAB98 *)(arg0 + 0x390))
}

void TObjEneNanoDrago::update_growth_state() {
    TObjEneNanoDrago *p = this;
    f32 t;
    f32 v;

    switch (p->state) {
    case 0:
        if (!((p->actorFlags) & 0x01000000) && p->growth_count < 4) {
            p->growth_count++;
            p->m_b8 = 5;
            p->state = 1;
            p->scale.y = 0.1f + p->scale.x;
            spawn_particle_effect(&p->m_2fc, 0xFA);
            p->speed = (*(NanoDragoMovementParams * *)&p->movementParameters)->base_speed * p->scale.x;
            play_sound_effect(0x4003A824, (NanoDragoVector *)&p->position, 0, 0);
            p->m_2c8 += 8;
            p->m_2c0 += 8;
        } else {
            p->scale.y = p->scale.x;
            p->state = -1;
        }
    case 1:
        advance_animation_playback(p);
        apply_actor_gravity(p, 0, 0.0f);
        ((TObjPlayer *)p)->update_collisions();
        t = p->scale.y;
        v = 0.0016000001f + p->scale.x;
        p->scale.x = (v < t) ? v : t;
        if (p->m_b8 != 5) {
            (p->state) = -1;
        }
        break;
    case -1:
        p->scale.x = p->scale.y;
        (p->m_388) &= 0xFFFDFFFE;
        (p->next_action) = 1;
        break;
    }
}

extern "C" {

void TObjPlayer__sub_800DAB98(u8 *arg0) {
    Vec_800DAB98 v;
    F(s32, 0x30) &= ~0x800000;
    switch (F(s32, 0x37C)) {
    case 0:
        F(s32, 0x37C) = 1;
        if (F(s32, 0x30) & 0x01000000) {
            if (F(s32, 0x388) & 0x40000) {
                VecCopy((Vec *)(arg0 + 0x390), (const Vec *)(arg0 + 0x50));
                calc_velocity_toward_destination(arg0, POS, DEST, F(f32, 0x3D8));
                F(s32, 0x388) &= ~0x40000;
                ((s32 (*)(void *))sub_8004292C__15TObjEnemyCustomFv)(arg0);
                F(f32, 0x404) = 50.0f;
            } else {
                ((TObjEnemyCustom *)arg0)->find_target_in_range(*F(f32 *, 0x350));
                calc_velocity_toward_destination(arg0, POS, DEST, F(f32, 0x3D8));
            }
            F(s16, 0xB8) = 7;
        } else {
            F(s32, 0x30) |= 0x01000000;
            F(s16, 0xB8) = 6;
            F(f32, 0x404) = 0.0f;
            ((TObjEnemyCustom *)arg0)->find_target_in_range(*F(f32 *, 0x350));
            if (F(u32, 0x2A8) != 0) {
                VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x38));
                subtract_vector(&v, F(u8 *, 0x2A8) + 0x38);
                ((void (*)(void *, void *))find_open_direction__10TObjPlayerFPvPv)(arg0, &v);
                calc_velocity_toward_destination(arg0, POS, DEST, F(f32, 0x3D8));
            } else {
                VecCopy((Vec *)(arg0 + 0x390), (const Vec *)(arg0 + 0x50));
                calc_velocity_toward_destination(arg0, POS, DEST, F(f32, 0x3D8));
            }
        }
        break;
    case 1:
        advance_animation_playback(arg0);
        calc_velocity_toward_destination(arg0, POS, DEST, TObjPlayer__sub_800DC434((s32)arg0, 0));
        if (F(f32, 0x404) < 50.0f) {
            s32 ok = 1;
            if (F(s16, 0xB8) == 6 && F(f32, 0xC0) < 22.0f) {
                ok = 0;
            }
            if (ok != 0) {
                F(f32, 0x404) += 2.2f;
            }
            ((TObjPlayer *)arg0)->update_collisions();
            if (TObjPlayer__sub_800DC478(arg0, 6, 22.0f) != 0) {
                spawn_particle_effect(arg0 + 0x38, 0xF0);
                play_sound_effect(0x4003AD20, arg0 + 0x38, 0, 0);
            }
        } else {
            F(f32, 0x30C) = 0.0f;
            VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
            vec3_add_to(arg0 + 0x38, arg0 + 0x308);
            if (xz_distance_squared((Vec *)(arg0 + 0x38), (Vec *)(arg0 + 0x390)) <= (10.0f + F(f32, 0x3D8)) * (10.0f + F(f32, 0x3D8))) {
                F(s32, 0x37C) = 2;
                F(f32, 0x310) = 0.0f;
                F(f32, 0x308) = 0.0f;
            }
            if (objInBand((GameObj *)arg0, (f32)(10.0f)) != 0) {
                spawn_particle_effect(arg0 + 0x38, 0xF0);
                play_sound_effect(0x4003AD20, arg0 + 0x38, 0, 0);
            }
            ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
        }
        if (F(f32, 0x404) > 15.0f) {
            ((TObjPlayer *)arg0)->update_angle(*(s32 *)(F(u8 *, 0x350) + 8) * 2, arg0 + 0x308);
        }
        project_actor_to_ground(arg0, arg0 + 0x38, 0);
        break;
    case 2:
        *(s32 *)(F(u8 *, 0xA4) + 0x44) |= 1;
        advance_animation_playback(arg0);
        F(f32, 0x404) += -2.3f;
        if (F(f32, 0x404) <= 0.0f) {
            F(f32, 0x404) = 0.0f;
            F(s32, 0x30) |= 0x800000;
            F(s32, 0x30) &= ~0x01000000;
            F(f32, 0x30C) = 0.0f;
            if (F(s16, 0xB8) != 8) {
                ((s32 (*)(void *, s32))update_if_active__15TObjEneMe1GiGueFl)(arg0, 0);
            }
        } else if (F(s16, 0xB8) == 7) {
            if (F(f32, 0x404) <= 2.3f * (40.0f + 1.0f / F(f32, 0xCC))) {
                F(s16, 0xB8) = 8;
            }
        } else {
            s32 t = (s32)F(f32, 0xC0);
            if (t == 20 || t == 40) {
                spawn_particle_effect(arg0 + 0x38, 0xF0);
            }
        }
        if (TObjPlayer__sub_800DC478(arg0, 8, 42.0f) != 0) {
            play_sound_effect(0x4003AD23, arg0 + 0x38, 0, 0);
        }
        check_object_collisions__10TObjPlayerFv(arg0);
        apply_actor_gravity(arg0, 0, 0.0f);
        break;
    case -1:
        if (F(s32, 0x374) != 4 && F(s32, 0x374) != 5) {
            F(f32, 0x404) = 0.0f;
        }
        *(s32 *)(F(u8 *, 0xA4) + 0x44) &= ~1;
        F(s32, 0x388) &= ~0x40000;
        break;
    }
}

void TObjPlayer__sub_800DB0F8(Obj_800DB0F8 *o) {
    s32 r;
    s32 i;
    switch (o->state) {
    case 0:
        sub_8004292C__15TObjEnemyCustomFv();
        r = 0;
        if (!(o->flags30 & 0x01000000)) {
            r = ((s32 (*)(void *))TObjPlayer__sub_800D9F4C)(o);
        }
        if (r > 0) {
            o->fB8 = 2;
            o->timer = 0x5A;
            o->state = 1;
        } else if (o->flags30 & 0x01000000) {
            ((s32 (*)(void *, s32))update_if_active__15TObjEneMe1GiGueFl)(o, 0xB);
        } else {
            ((s32 (*)(void *, s32))update_if_active__15TObjEneMe1GiGueFl)(o, 0);
        }
        o->f388 &= ~0x40000;
        break;
    case 1:
    case 2:
    case 3:
        switch (o->state) {
        case 1:
            if (o->frame >= 5.0f) {
                ((TObjPlayer *)o)->render_model_transformed();
                spawn_particle_effect(o->fx39C, 0xF7);
                spawn_particle_effect(o->fx3A8, 0xF7);
                o->state = 2;
            }
            break;
        case 2:
            play_persistent_sound(0x4003AD1E, (s32)o, (u32)o->pos, 0, 0);
            if (o->frame >= 20.0f) {
                ((TObjPlayer *)o)->render_model_transformed();
                for (i = 0; i < o->count; i++) {
                    TObjPlayer__sub_800DA414((Obj_800DA414 *)o, i);
                }
                o->state = 3;
            }
            break;
        }
        advance_animation_playback(o);
        apply_actor_gravity(o, 0, 0.0f);
        ((TObjPlayer *)o)->update_collisions();
        o->timer--;
        if (o->timer <= 0) {
            o->timer = 0x2D;
            o->fB8 = 1;
            o->state = 4;
        }
        break;
    case 4:
        enemy_wander_home__9TObjEnemyFlfff(o, o->home->f8, o->f3D8, 100.0f, 100.0f);
        advance_animation_playback(o);
        apply_actor_gravity(o, 0, 0.0f);
        ((TObjPlayer *)o)->update_collisions();
        if (objInBand((GameObj *)o, (f32)(4.0f)) != 0 || objInBand((GameObj *)((GameObj *)o), (f32)(20.0f)) != 0) {
            play_sound_effect(0x4003AD23, o->pos, 0, 0);
        }
        if (((u16 (*)(void *, int, f32))find_nearest_visible_player)(o, 0, 50.0f) != 0xFFFF) {
            ((s32 (*)(void *, s32))update_if_active__15TObjEneMe1GiGueFl)(o, 0xB);
        } else {
            o->timer--;
            if (o->timer <= 0) {
                ((s32 (*)(void *, s32))update_if_active__15TObjEneMe1GiGueFl)(o, 0);
            }
        }
        break;
    case -1:
        break;
    }
}

void TObjPlayer__sub_800DB390(u8 *arg0) {
    s32 temp_r0;
    s32 temp_r4;
    temp_r4 = ((TObjPlayer *)arg0)->m_37c;
    switch (temp_r4) {
    case -1:
        break;
    case 0:
        sub_8004292C__15TObjEnemyCustomFv();
        *(s32 *)((s8 *)arg0 + 0x384) = 0x5A;
        if (!(((TObjPlayer *)arg0)->actorFlags & 0x01000000)) {
            ((TObjPlayer *)arg0)->m_b8 = 2;
        } else {
            ((TObjPlayer *)arg0)->m_b8 = 9;
        }
        ((TObjPlayer *)arg0)->m_37c = 1;
        advance_animation_playback(arg0);
        *(s32 *)((s8 *)arg0 + 0x388) = (s32) (*(s32 *)((s8 *)arg0 + 0x388) & 0xFFFBFFFF);
        break;
    case 3:
    case 2:
    case 1:
        if ((u32) *(u32 *)((s8 *)arg0 + 0x2A8) == 0U) {
            ((TObjPlayer *)arg0)->m_37c = 4;
            return;
        }
        switch (temp_r4) {
        case 1:
            if (((TObjPlayer *)arg0)->m_c0 >= 5.0f) {
                ((TObjPlayer *)arg0)->render_model_transformed();
                spawn_particle_effect((arg0 + 0x39C), 0xF7);
                ((TObjPlayer *)arg0)->m_37c = 2;
            }
            break;
        case 2:
            play_persistent_sound(0x4003AD1E, (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
            if (((TObjPlayer *)arg0)->m_c0 >= 20.0f) {
                ((TObjPlayer *)arg0)->render_model_transformed();
                u32 obj = __nw__7TObjectFUl(0x100);
                if (obj != 0U) {
                    construct_beam_effect__10TObjPlayerFPvPvPviPv(obj, arg0 + 0x39C, (void *) (*(u32 *)((s8 *)arg0 + 0x2A8) + 0x2FC), (u8) !(((TObjPlayer *)arg0)->actorFlags & 0x01000000), arg0);
                }
                ((TObjPlayer *)arg0)->spawn_directional_particle_at_slot(0);
                play_sound_effect(0x4003A527, arg0 + 0x38, 0, 0);
                ((TObjPlayer *)arg0)->m_37c = 3;
            }
            break;
        }
        VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(*(u32 *)((s8 *)arg0 + 0x2A8) + 0x2FC));
        enemy_turn_half_toward_dest(arg0);
        advance_animation_playback(arg0);
        if (!(((TObjPlayer *)arg0)->actorFlags & 0x01000000)) {
            apply_actor_gravity(arg0, 0, (f32) (0.0f));
        }
        ((TObjPlayer *)arg0)->update_collisions();
        temp_r0 = *(s32 *)((s8 *)arg0 + 0x384) - 1;
        *(s32 *)((s8 *)arg0 + 0x384) = temp_r0;
        if (temp_r0 <= 0) {
            ((TObjPlayer *)arg0)->m_37c = 4;
        }
        break;
    case 4:
        if (((TObjPlayer *)arg0)->actorFlags & 0x01000000) {
            *(s32 *)((s8 *)arg0 + 0x378) = 0;
            ((s32 (*)(void *, s32))update_if_active__15TObjEneMe1GiGueFl)(arg0, 0xB);
            return;
        }
        ((s32 (*)(void *, s32))update_if_active__15TObjEneMe1GiGueFl)(arg0, 0);
        break;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline f32 xz_sq_800DB5A8(Vec_800DB5A8 *v) { return v->x * v->x + v->z * v->z; }
}

void TObjEneNanoDrago::update_circling_state() {
    u8 *arg0 = (u8 *)this;
    TObjEneNanoDrago *e = this;
    (e->actorFlags) &= ~0x01000000;
    switch (e->state) {
    case -1:
        break;
    case 0:
        (e->m_388) &= ~0x00040000;
        ((void (*)(void *))sub_8004292C__15TObjEnemyCustomFv)(arg0);
        e->m_b8 = 1;
        e->accum = 0;
        if (e->target != NULL) {
            VecCopy((Vec *)((NanoDragoVector *)&e->m_29c), (const Vec *)(e->target + 0x2FC));
        }
        e->state = 1;
    case 1:
        advance_animation_playback(arg0);
        apply_actor_gravity(arg0, 0, 0.0f);
        if (objInBand((GameObj *)arg0, (f32)(4.0f)) != 0 || objInBand((GameObj *)((GameObj *)arg0), (f32)(20.0f)) != 0) {
            play_sound_effect(0x4003AD23, (NanoDragoVector *)&e->position, 0, 0);
        }
        if (e->target != NULL) {
            Vec_800DB5A8 d = *(Vec_800DB5A8 *)(e->target + 0x38);
            subtract_vector(&d, (NanoDragoVector *)&e->position);
            if (xz_sq_800DB5A8(&d) <= 160000.0f &&
                angle_difference_abs(-(s32)(lbl_8043C900[0] * atan2_float(d.z, d.x)) + 0x4000, e->rotation_y) < 0xAAA) {
                s32 next;
                if (e->hp <= e->hpmax / 4) {
                    next = 10;
                } else {
                    s32 n = 9;
                    if (e->toggle != 0) {
                        n = 10;
                    }
                    next = n;
                    e->toggle ^= 1;
                }
                ((void (*)(void *, s32))update_if_active__15TObjEneMe1GiGueFl)(arg0, next);
                break;
            }
        }
        e->rotation_y += (*(NanoDragoMovementParams * *)&e->movementParameters)->turn / 2;
        enemy_set_heading_velocity(arg0, e->speed, e->rotation_y);
        move_with_wall_slide(arg0);
        e->accum += (*(NanoDragoMovementParams * *)&e->movementParameters)->turn / 2;
        if (e->accum > 0x10000) {
            e->t = 0.0f;
            e->state = 2;
        }
        check_object_collisions__10TObjPlayerFv(arg0);
        check_enemy_body_collisions(arg0);
        break;
    case 2:
        ((s32 (*)(void *, f32, f32, f32, int))enemy_wander_home__9TObjEnemyFlfff)(arg0, e->speed, 100.0f, 50.0f, (*(NanoDragoMovementParams * *)&e->movementParameters)->turn);
        advance_animation_playback(arg0);
        apply_actor_gravity(arg0, 0, 0.0f);
        if (objInBand((GameObj *)arg0, (f32)(4.0f)) != 0 || objInBand((GameObj *)((GameObj *)arg0), (f32)(20.0f)) != 0) {
            play_sound_effect(0x4003AD23, (NanoDragoVector *)&e->position, 0, 0);
        }
        e->t += e->speed;
        if (e->t > 100.0f) {
            if (((TObjEnemyCustom *)arg0)->select_nearest_target((*(NanoDragoMovementParams * *)&e->movementParameters)->f0) != 0) {
                e->accum = 0;
                e->state = 1;
            } else {
                ((void (*)(void *, s32))update_if_active__15TObjEneMe1GiGueFl)(arg0, 0);
            }
        }
        check_object_collisions__10TObjPlayerFv(arg0);
        check_enemy_body_collisions(arg0);
        break;
    }
}
extern "C" {

#pragma pop

void TObjEneNanoDrago::vfunc_63() {
    ((TObjEneMe1GiGue *)((u8 *)this))->set_state(5);
    this->m_380 = (s32) this->m_378;
    this->m_378 = 5;
    this->m_388 = (s32) (this->m_388 | 1);
}

void sub_800DB970__16TObjEneNanoDragoFv(u8 *arg0);
void vfunc_62__16TObjEneNanoDragoFv(void *arg0);

void TObjEneNanoDrago::vfunc_62() {
    ((TObjEneMe1GiGue *)this)->set_state(4);
    this->m_380 = (s32) this->m_378;
    this->m_378 = 4;
    this->m_388 = (s32) (this->m_388 | 0x10000 | 1);
}
void TObjEneNanoDrago::sub_800DB970() {
    if ((this->m_388) & 0x40000) {
        return;
    }
    switch ((this->state)) {
    case -1:
        break;
    case 0:
        this->m_b8 = 1;
        (this->state) = 1;
        this->m_384 = 0x96;
        ((s32 (*)(void *))sub_8004292C__15TObjEnemyCustomFv)(this);
    case 1:
        advance_animation_playback(this);
        ((s32 (*)(void *, void *, f32))update_circle_move__10TObjPlayerFPvPvf)(this, ((u8 *)this) + 0x50, this->parameters[1]);
        if (objInBand((GameObj *)this, (f32)(4.0f)) != 0 || objInBand((GameObj *)this, (f32)(20.0f)) != 0) {
            play_sound_effect(0x4003AD23, ((u8 *)this) + 0x38, 0, 0);
        }
        this->m_384 = this->m_384 - 1;
        if (this->m_384 <= 0) {
            this->m_b8 = 0;
            (this->state) = 2;
            this->m_384 = 0x5A;
        }
        ((s32 (*)(void *))check_object_collisions__10TObjPlayerFv)(this);
        apply_actor_gravity(this, 0, 0.0f);
        break;
    case 2:
        advance_animation_playback(this);
        ((s32 (*)(void *))check_object_collisions__10TObjPlayerFv)(this);
        this->m_384 = this->m_384 - 1;
        if (this->m_384 <= 0) {
            (this->state) = 0;
        }
        break;
    }
}

}

#include "pso/misc/TLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3VoloptMonitor.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct VBase_14 { char pad[0x14]; };

struct VObj_14 : VBase_14 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8();
};

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual s32 m9(f32, f32, f32);
};

struct Vec_800DBABC { f32 x, y, z; };

struct Fade_800DBABC { u8 b[0x1C]; };

struct Nano_800DBABC { u8 pad[0x40C]; Fade_800DBABC fades[2]; };

extern "C" {
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 update_obstruction_fade(int);
s32 restore_scene_lighting();
s32 select_actor_lighting(void *);
s32 defer_render__7TObjectFv(void *);
s32 push_matrix();
s32 pop_matrix();
s32 draw_chunk_object(int);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void render_enemy_with_fade__10TObjPlayerFPv(u8 *arg0);
struct Stack_800DC028 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
};

struct RecoveredGlobal_800DC028_lbl_8043C8D4 {
    s32 value;
    u8 remaining[0xC];
};

typedef char RecoveredGlobal_800DC028_lbl_8043C8D4_size[sizeof(RecoveredGlobal_800DC028_lbl_8043C8D4) == 0x10 ? 1 : -1];

struct RecoveredGlobal_800DC028_lbl_80494B4C {
    s32 value;
    u8 remaining[0xC];
};

typedef char RecoveredGlobal_800DC028_lbl_80494B4C_size[sizeof(RecoveredGlobal_800DC028_lbl_80494B4C) == 0x10 ? 1 : -1];

struct Obj_800DC0FC { u8 pad0[0x18]; void *vt; };

struct Sub_800DC180 { u8 b[0x1C]; };

struct Self_800DC180 { u8 pad[0x40C]; Sub_800DC180 subs[4]; };

void obj_setFlags30(void *, u32);
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
void TLobby__sub_8001FE7C(void*, int);
u8 * load_resource_from_descriptor(void *, s32, s32 *, s32, s32, s32);
void *__dt__15TObjEnemyCustomFv(void *arg0, s16 arg1);
void __ct__15TObjEnemyCustomFP7TObject(void *, s32, void *);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804949A8Fv(void *arg0, s16 arg1);
void init_and_activate__10TObjPlayerFv();
s32 find_active_entity_by_id(int);

void TObjPlayer__sub_800DBAB8(void);
void run_task__16TObjEneNanoDragoFv(u8 *arg0);
void TLobby__sub_800DC028(void);
Obj_800DC0FC * __dt__16TObjEneNanoDragoFv(Obj_800DC0FC *arg0, s16 arg1);
u8 * TObjEneNanoDrago__ct(u8 *arg0, s32 arg1, u8 *arg2);
void TObjPlayer__sub_800DC444(void);
}
int initialize_enemy_photon_effect(void *p);
extern "C" {
void * TObjControl__ct(void *, void *);
s32 free_collision_body_parts(void *);
void init_collision_body_parts(void *, void *, s32);
s32 submit_cursor_candidate(void *, int);
s32 minimap_render_dot(void *, int, int, int);
s32 __dl__7TObjectFPv(void *);
void __destroy_arr(void *, void *, int, int);
void __construct_array(void *, void *, void *, int, int);

extern RecoveredGlobal_800DC028_lbl_8043C8D4 nano_drago_anim_binding;
extern s32 lbl_805D2AA8;
extern s32 lbl_805D5248;
extern s32 lbl_805D524C;
extern s32 lbl_805D5250;
extern s32 lbl_805D5254;
extern u32 nano_drago_entry_params_resource;
extern void *tl_04;

extern "C" {
void get_anim_node_position__15TObjEnemyCustomFlP3Vec();
}
extern "C" {
void vfunc_6__13TUnk_804B9870FPsl();
}
extern "C" {
void vfunc_58__16TObjEneNanoDragoFv();
}
extern "C" {
void vfunc_60__16TObjEneNanoDragoFv();
}
extern "C" {
void vfunc_59__16TObjEneNanoDragoFv();
}
extern "C" {
void vfunc_61__16TObjEneNanoDragoFv();
}
extern "C" {
void vfunc_28__15TObjEnemyCustomFv();
}
extern "C" {
void vfunc_29__13TUnk_804806E8Fv();
}
extern "C" {
void recalc_stats__13TUnk_804806E8Fv();
}
extern "C" {
void consume_timer_field__13TUnk_804806E8Fl();
}
extern "C" {
void vfunc_67__13TUnk_804806E8Ff();
}
extern "C" {
void vfunc_66__13TUnk_804806E8Fv();
}
extern "C" {
void apply_slow_status__13TUnk_804806E8Fv();
}
extern "C" {
void update_shock_clock__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_43__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_18__13TUnk_804806E8FPUc();
}
extern "C" {
void interact__13TUnk_804AF8A0Fl();
}
extern "C" {
void vfunc_74__9TObjEnemyFl();
}
extern "C" {
void apply_hit_message_flags__9TObjEnemyFPv();
}
extern "C" {
void add_actor_exp__13TUnk_804806E8Fl();
}
extern "C" {
void apply_action_hold_status__13TUnk_804806E8Ff();
}
extern "C" {
void apply_anti_technique__13TUnk_804806E8Fl();
}
extern "C" {
void apply_attack_stat_status__13TUnk_804806E8FPv();
}
extern "C" {
void apply_confusion_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
}
extern "C" {
void apply_movement_ailment__13TUnk_804806E8Fl();
}
extern "C" {
void apply_object_set_data__13TUnk_804B9870FPv();
}
extern "C" {
void apply_paralysis__13TUnk_804806E8Fv();
}
extern "C" {
void apply_poison_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_set_data__9TObjEnemyFPv();
}
extern "C" {
void apply_shock_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_switch_attack__13TUnk_804806E8Fv();
}
extern "C" {
void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
}
extern "C" {
void vfunc_79__15TObjEnemyCustomFv();
}
extern "C" {
void classify_actor_view_detail__13TUnk_804B9870Ffff();
}
extern "C" {
void clear_all_status_effects__13TUnk_804806E8Fv();
}
extern "C" {
void clear_harmful_statuses__13TUnk_804806E8Fv();
}
extern "C" {
void cure_paralysis__13TUnk_804806E8Fv();
}
extern "C" {
void cure_poison_ailment__13TUnk_804806E8Fv();
}
extern "C" {
void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
}
extern "C" {
void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_78__13TUnk_804806E8Fl();
}
extern "C" {
void vfunc_77__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_76__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_75__13TUnk_804806E8Ff();
}
extern "C" {
void clear_lobby_object_state__9TObjEnemyFv();
}
extern "C" {
void get_center__13TUnk_804806E8Fv();
}
extern "C" {
void get_actor_level_index__13TUnk_804806E8Fv();
}
extern "C" {
void get_name__9TObjEnemyFv();
}
extern "C" {
void get_pos__13TUnk_804806E8Fl();
}
extern "C" {
void is_actor_cadence_frame__13TUnk_804806E8Fl();
}
extern "C" {
void is_target_in_attack_range__13TUnk_804806E8Fv();
}
extern "C" {
extern u8 lbl_8043C760[];
}
extern "C" {
extern u8 lbl_8043C774[];
}
extern "C" {
extern u8 lbl_8043C78C[];
}
extern "C" {
extern u8 lbl_8043C7A8[];
}
extern "C" {
extern u8 lbl_8043C7C4[];
}
extern "C" {
extern u8 lbl_8043C7E0[];
}
extern "C" {
extern u8 lbl_8043C7FC[];
}
extern "C" {
extern u8 lbl_8043C814[];
}
extern "C" {
extern u8 lbl_8043C82C[];
}
extern "C" {
extern u8 lbl_8043C844[];
}
extern "C" {
extern u8 lbl_8043C860[];
}
extern "C" {
extern u8 lbl_8043C878[];
}
extern "C" {
extern u8 lbl_8043C890[];
}
extern "C" {
extern u8 lbl_8043C8A8[];
}
extern "C" {
void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
}
extern "C" {
void receive_physical_attack__13TUnk_804806E8FPvf();
}
extern "C" {
void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
void apply_defense_stat_status__13TUnk_804806E8FPv();
}
extern "C" {
void render_shadows__9TObjEnemyFv(u8 *arg0);
}
extern "C" {
void reset_motion_fields__13TUnk_804806E8Fv();
}
extern "C" {
void reset_pose__13TUnk_804806E8Fv();
}
extern "C" {
void roll_physical_accuracy__13TUnk_804806E8FPvlf();
}
extern "C" {
void select_melee_contact_body__13TUnk_804806E8FPvf();
}
extern "C" {
void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
}
extern "C" {
void try_start_action__13TUnk_804806E8Fll();
}
extern "C" {
s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
void update_actor_ground_y__13TUnk_804806E8Fv();
}
extern "C" {
s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
void update_flag30_timer__13TUnk_804806E8Fv();
}
extern "C" {
void update_movement_status__13TUnk_804806E8Fv();
}
extern "C" {
void update_object_view_visibility__13TUnk_804B9870Fff();
}
extern "C" {
void update_poison_status__13TUnk_804806E8Fv();
}
extern void *bm_ene_nanodrago_model_names[2];
extern void *bm_ene_nanodrago_motion_names[13];
__declspec(section ".data") void *bm_ene_nanodrago_model_names[2] = {
    (void *)&lbl_8043C760, (void *)0x0,
};
void *bm_ene_nanodrago_motion_names[13] = {
    (void *)&lbl_8043C774, (void *)&lbl_8043C78C, (void *)&lbl_8043C7A8, (void *)&lbl_8043C7C4,
    (void *)&lbl_8043C7E0, (void *)&lbl_8043C7FC, (void *)&lbl_8043C814, (void *)&lbl_8043C82C,
    (void *)&lbl_8043C844, (void *)&lbl_8043C860, (void *)&lbl_8043C878, (void *)&lbl_8043C890,
    (void *)0x0,
};
void *bm_ene_nanodrago_resource_descriptor[4] = {
    (void *)&lbl_8043C8A8, (void *)&bm_ene_nanodrago_model_names, (void *)&bm_ene_nanodrago_motion_names, (void *)0x1000c,
};
void *lbl_80494B5C[48] = {
    (void *)0x20000, (void *)0xa, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x10001, (void *)0xb, (void *)0x3f4ccccd, (void *)0x1,
    (void *)0x20000, (void *)0x0, (void *)0x3f333333, (void *)0x4,
    (void *)0x20000, (void *)0x2, (void *)0x3f4ccccd, (void *)0x8,
    (void *)0x30004, (void *)0x3, (void *)0x3f000000, (void *)0x10,
    (void *)0x20000, (void *)0x6, (void *)0x3f4ccccd, (void *)0x1,
    (void *)0x20007, (void *)0x9, (void *)0x3f666666, (void *)0x1,
    (void *)0x10007, (void *)0x5, (void *)0x3fb33333, (void *)0x1,
    (void *)0x20000, (void *)0x7, (void *)0x3fb33333, (void *)0x1,
    (void *)0x20007, (void *)0x8, (void *)0x3f333333, (void *)0x4,
    (void *)0x20007, (void *)0x1, (void *)0x3f4ccccd, (void *)0x8,
    (void *)0x3000b, (void *)0x4, (void *)0x3f000000, (void *)0x10,
};
void *lbl_80494C1C[7] = {
    (void *)0x43160000, (void *)0x3eed097b, (void *)0x300, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0,
};
void *lbl_80494C38[22] = {
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x41700000,
    (void *)0x0, (void *)0x0, (void *)0x8001, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41700000, (void *)0x0, (void *)0x41400000, (void *)0x0,
    (void *)0x0, (void *)0xa000002, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
void *lbl_80494C90[83] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__16TObjEneNanoDragoFv, (void *)&run_task__16TObjEneNanoDragoFv,
    (void *)&render_enemy_with_fade__10TObjPlayerFPv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&get_center__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__15TObjEnemyCustomFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__16TObjEneNanoDragoFv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__16TObjEneNanoDragoFv, (void *)&vfunc_59__16TObjEneNanoDragoFv,
    (void *)&vfunc_60__16TObjEneNanoDragoFv, (void *)&vfunc_61__16TObjEneNanoDragoFv, (void *)&vfunc_62__16TObjEneNanoDragoFv, (void *)&vfunc_63__16TObjEneNanoDragoFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__15TObjEnemyCustomFlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&recalc_stats__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__15TObjEnemyCustomFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv,
};
#define bm_ene_nanodrago_resource_descriptor (*(RecoveredGlobal_800DC028_lbl_80494B4C *)bm_ene_nanodrago_resource_descriptor)
#define lbl_80494B5C ((u8 *)lbl_80494B5C)
#define lbl_80494C1C ((u8 *)lbl_80494C1C)
#define lbl_80494C38 ((u8 *)lbl_80494C38)
#define lbl_80494C90 ((u8 *)lbl_80494C90)

void TObjPlayer__sub_800DBAB8(void) {  }

#pragma push
#pragma fp_contract on
void render_enemy_with_fade__10TObjPlayerFPv(u8 *arg0) {
    Vec_800DBABC v;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    s32 var_r29;
    s32 temp_r3;
    s32 var_r28;
    var_r29 = 0;
    if (is_split_screen() != 0) {
        var_r29 = get_camera_mode__11TCameraCtrlFv();
    }
    if (!(((TObjEneNanoDrago *)arg0)->actorFlags & 0x02000000) && (temp_r3 = ((VObj_18 *)(arg0))->m9(150.0f, 400.0f, 20.0f), ((temp_r3 == 0) == 0)) && ((TObjPlayer::check_demo_mode() == 1) || !(((TObjEneNanoDrago *)arg0)->m_388 & 0x40000))) {
        saved_model_render_flags = model_render_flags;
        var_r29 = (s32)&((Nano_800DBABC *)arg0)->fades[var_r29];
        update_obstruction_fade((int) (((u8 *)var_r29)));
        if (((RenderFadeState *)var_r29)->updateFromCamera((const f32*)(arg0 + 0x2FC)) != 0) {
            ((VObj_14 *)(((u8 *)var_r29)))->m6();
            if (defer_render__7TObjectFv(arg0) != 0) {
                model_render_flags = saved_model_render_flags;
                return;
            }
        }
        TObjFish::set_global_param((int) (((TObjEneNanoDrago *)arg0)->texlist));
        select_actor_lighting(arg0);
        TObjPlayer::toggle_particle_effect();
        var_r28 = 1;
        push_matrix();
        translate_matrix(0, (f32) (*(f32 *)((s8 *)arg0 + 0x38)), (f32) (((TObjEneNanoDrago *)arg0)->m_404 + (*(f32 *)((s8 *)arg0 + 0x3C) + *(f32 *)((s8 *)arg0 + 0x3E4))), (f32) (*(f32 *)((s8 *)arg0 + 0x40)));
        rotate_matrix_y(0, (int) (((TObjEneNanoDrago *)arg0)->rotation_y));
        temp_f1 = ((TObjEneNanoDrago *)arg0)->scale.x;
        scale_matrix(0, temp_f1, temp_f1, temp_f1);
        model_render_flags &= 0xFFFFFBFF;
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_chunk_object((int) (*(s32 *)((s8 *)arg0 + 0x34)));
        } else if (((TObjEneNanoDrago *)arg0)->m_388 & 4) {
            if (((VObj_14 *)(arg0 + 0x3E8))->m8() != 0) {
                ((VObj_14 *)(arg0 + 0x3E8))->m6();
                if (temp_r3 == 1) {
                    ((TObjMotion *)arg0)->draw();
                } else {
                    ((TObjEnemy *)arg0)->render_world_model();
                }
                ((VObj_14 *)(arg0 + 0x3E8))->m7();
            } else {
                var_r28 = 0;
            }
        } else if (temp_r3 == 1) {
            ((TObjMotion *)arg0)->draw();
        } else {
            ((TObjEnemy *)arg0)->render_world_model();
        }
        pop_matrix();
        restore_scene_lighting();
        TParticleCtrl::end_effect_render();
        if (!(((TObjEneNanoDrago *)arg0)->actorFlags & 0x800) && (var_r28 != 0)) {
            temp_f0 = -(0.01f * ((TObjEneNanoDrago *)arg0)->m_404 - 1.0f) * (5.0f * ((TObjEneNanoDrago *)arg0)->scale.x);
            v.z = temp_f0;
            v.y = temp_f0;
            v.x = temp_f0;
            ((TObjEnemy *)arg0)->render_with_position_override((u8 *)&v, 0);
        }
        ((VObj_14 *)(((u8 *)var_r29)))->m7();
        model_render_flags = saved_model_render_flags;
    }
}
#pragma pop

void TObjEneNanoDrago::dispatch_action_state() {
    u8 *arg0 = (u8 *)this;
  s16 temp_r0;
  temp_r0 = this->mode;
  {
    switch (temp_r0)
    {
      case 0:
        ((void (*)())sub_800DB970__16TObjEneNanoDragoFv)();
        return;
      case 1:
        ((TObjEneNanoDrago *)arg0)->update_circling_state();
        return;
      case 2:
        TObjPlayer__sub_800DC444();
        return;
      case 3:
        ((TObjEnemyCustom *)arg0)->update_state_machine();
        return;
      case 4:
        ((void (*)())TObjPlayer__sub_800DA7E4)();
        return;
      case 5:
        ((void (*)())update_death_sequence__10TObjPlayerFPv)();
        return;
      case 9:
        ((void (*)())TObjPlayer__sub_800DB0F8)();
        return;
      case 10:
        ((void (*)())TObjPlayer__sub_800DB390)();
        return;
      case 11:
        ((void (*)())TObjPlayer__sub_800DAB98)();
        return;
      case 12:
        ((TObjEneNanoDrago *)arg0)->update_growth_state();
        return;
      case 7:
        ((TObjPlayer *)arg0)->update_death_state();
        break;
    }
  }
}

void TObjEneNanoDrago::run_task() {
    s32 temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    u8 *arg0 = (u8 *)this;

    if (TObjPlayer::check_demo_mode() == 1) {
        ((void (*)(void *))TObjPlayer__sub_800D9E08)(arg0);
        ((s32 (*)(void *))TObjPlayer__sub_800DBAB8)(arg0);
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x2A8) = find_active_entity_by_id((int) (((TObjEneNanoDrago *)arg0)->targetId));
    ((TObjEnemyCustom *)arg0)->release_destroyed_target();
    ((TObjEneNanoDrago *)arg0)->sub_800DA2A0();
    if ((s16) ((TObjEneNanoDrago *)arg0)->mode != (s32) ((TObjEneNanoDrago *)arg0)->next_action) {
        if ((s32) ((TObjEneNanoDrago *)arg0)->state != -1) {
            ((TObjEneNanoDrago *)arg0)->state = -1;
            ((TObjEneNanoDrago *)arg0)->dispatch_action_state();
        }
        ((TObjEneNanoDrago *)arg0)->mode = (s16) ((TObjEneNanoDrago *)arg0)->next_action;
        ((TObjEneNanoDrago *)arg0)->state = 0;
    }
    ((TObjEneNanoDrago *)arg0)->dispatch_action_state();
    if ((s32) ((TObjEneNanoDrago *)arg0)->state == -1) {
        ((TObjEneNanoDrago *)arg0)->state = -1;
        ((TObjEneNanoDrago *)arg0)->dispatch_action_state();
        ((TObjEneNanoDrago *)arg0)->mode = (s16) ((TObjEneNanoDrago *)arg0)->next_action;
        ((TObjEneNanoDrago *)arg0)->state = 0;
    }
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    ((TObjEneNanoDrago *)arg0)->m_300 = (f32) (((TObjEneNanoDrago *)arg0)->m_300 + (15.0f + ((TObjEneNanoDrago *)arg0)->m_404));
    *(f32 *)((s8 *)(((TObjEneNanoDrago *)arg0)->bodies) + 4) = (f32) (15.0f + ((TObjEneNanoDrago *)arg0)->m_404);
    if (!(((TObjEneNanoDrago *)arg0)->m_388 & 0x40000)) {
        submit_cursor_candidate(arg0, -1);
        minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
    }
    temp_r3 = ((TObjEneNanoDrago *)arg0)->m_3dc;
    if (temp_r3 > 0) {
        ((TObjEneNanoDrago *)arg0)->m_3dc = (temp_r3 - 1);
    }
    temp_r3_2 = (unsigned char *) (((TObjEneNanoDrago *)arg0)->bodies);
    *(s32 *)((s8 *)temp_r3_2 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_2 + 0x18) & 0xFFFFFFF9);
    if (((TObjEneNanoDrago *)arg0)->m_404 > 5.0f) {
        temp_r3_3 = (unsigned char *) (((TObjEneNanoDrago *)arg0)->bodies);
        *(s32 *)((s8 *)temp_r3_3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_3 + 0x18) | 4);
    } else {
        temp_r3_4 = (unsigned char *) (((TObjEneNanoDrago *)arg0)->bodies);
        *(s32 *)((s8 *)temp_r3_4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_4 + 0x18) | 2);
    }
    if (xz_distance_squared(&this->position, &this->prev_position) > 2500.0f) {
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0x44));
    }
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
}

void *TObjEneNanoDrago::create(void *arg0) {
    void *o;
    void *o2;
    o = (void *)__nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = (void *)__nw__7TObjectFUl(0x47C);
    if (o2 != NULL) {
        o2 = ((void * (*)(void *, void *, void *))TObjEneNanoDrago__ct)(o2, o, arg0);
    }
    return o2;
}

void TLobby::free_global_window() {
    if ((u32) nano_drago_entry_params_resource != 0U) {
        TLobby__sub_8001FE7C((void*)nano_drago_entry_params_resource, 1);
        nano_drago_entry_params_resource = 0U;
    }
}

void TLobby__sub_800DC028(void) {
    Stack_800DC028 stack;

    u8 *temp_r3;
    u8 *temp_r5;
    u8 *var_r0;

    temp_r3 = (u8 *)((int)::operator new(0x440));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(load_resource_from_descriptor(temp_r3, 1, &bm_ene_nanodrago_resource_descriptor.value, 0, 0, 0));
    }
    nano_drago_entry_params_resource = (u32) var_r0;
    lbl_805D5248 = register_boss__6TLobbyFl(0x1A);
    lbl_805D524C = dispatch_shared_handler_b__6TLobbyFl(0x1A);
    lbl_805D5250 = register_object__6TLobbyFl(0x1A);
    lbl_805D5254 = dispatch_shared_handler_a__6TLobbyFl(0x1A);
    stack.sp8 = *(s32 *)((s8 *)&nano_drago_anim_binding.value + 0);
    stack.spC = *(s32 *)((s8 *)&nano_drago_anim_binding.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&nano_drago_anim_binding.value + 8);
    stack.sp14 = *(s32 *)((s8 *)&nano_drago_anim_binding.value + 0xC);
    stack.sp8 = *(s32 *)((s8 *)nano_drago_entry_params_resource + 0x430);
    temp_r5 = (u8 *)(*(u8 **)((s8 *)nano_drago_entry_params_resource + 0x42C));
    TLobby::spawn_npc_enemy((s16)(0x22), (s32)((int) (*(s32 *)((s8 *)temp_r5 + 8))), (s32)((int) (*(s32 *)((s8 *)temp_r5 + 0xC))), (s32)((void *)&stack.sp8), (f32)((f32) (15.0f)), (f32)((f32) (0.0f)));
}

Obj_800DC0FC *__dt__16TObjEneNanoDragoFv(Obj_800DC0FC *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->vt = lbl_80494C90;
        free_collision_body_parts(arg0);
        __destroy_arr((u8 *)arg0 + 0x40C, (void *)__dt__13TUnk_804949A8Fv, 0x1C, 4);
        __dt__13TUnk_80494938Fv((u8 *)arg0 + 0x3E8, -1);
        __dt__15TObjEnemyCustomFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TObjEneNanoDrago__ct(u8 *arg0, s32 arg1, u8 *arg2) {
    s32 i;
    __ct__15TObjEnemyCustomFP7TObject(arg0, arg1, arg2);
    *(u8 **)((s8 *)arg0 + 0x18) = lbl_80494C90;
    ((TUnk_80494938 *)(arg0 + 0x3E8))->init_common();
    __construct_array(arg0 + 0x40C, (void *)&init_and_activate__10TObjPlayerFv, (void *)&__dt__13TUnk_804949A8Fv, 0x1C, 4);
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D2AA8;
    ((TObjEneNanoDrago *)arg0)->apply_set_data(arg2);
    VecCopy((Vec *)(arg0 + 0x290), (const Vec *)(VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(arg0 + 0x38))));
    *(s32 *)((s8 *)arg0 + 0xDC) = *(s32 *)((s8 *)(*(u8 * *)&nano_drago_entry_params_resource) + 0x430);
    ((TObjEneNanoDrago *)arg0)->variant = 0;
    ((TUnk_804806E8 *)arg0)->add_flags_2e4(2);
    ((TObjEneNanoDrago *)arg0)->state36C = *(s16 *)((s8 *)arg2 + 0x3E);
    ((TObjEneNanoDrago *)arg0)->load_entry_params_nanodrago(((TObjEneNanoDrago *)arg0)->variant);
    ((TObjEneNanoDrago *)arg0)->action_table = lbl_80494B5C;
    ((TObjMotion *)arg0)->set_field_d8((s32)(((TObjEneNanoDrago *)arg0)->action_table));
    init_collision_body_parts(arg0, lbl_80494C38, 2);
    *(u32 *)((s8 *)(((TObjEneNanoDrago *)arg0)->bodies) + 0x44) &= ~1;
    ((TObjEneNanoDrago *)arg0)->movementParameters = lbl_80494C1C;
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)lbl_805D5248, (u8 *)lbl_805D524C, (u8 *)lbl_805D5250);
    ((void (*)(void *))TObjPlayer__sub_800D9E08)(arg0);
    ((TObjEneNanoDrago *)arg0)->m_b8 = 0;
    ((TObjMotion *)arg0)->set_animation(((TObjEneNanoDrago *)arg0)->m_b8);
    ((TObjMotion *)arg0)->set_field_b8(((TObjEneNanoDrago *)arg0)->m_b8);
    ((TObjEneNanoDrago *)arg0)->hp = ((TObjEneNanoDrago *)arg0)->hpmax;
    ((TObjEneNanoDrago *)arg0)->tp = ((TObjEneNanoDrago *)arg0)->tpmax;
    ((TObjEneNanoDrago *)arg0)->referenceHp = ((TObjEneNanoDrago *)arg0)->hp;
    ((TObjEnemy *)arg0)->update_prev_position();
    initialize_enemy_photon_effect(arg0);
    ((TObjEneNanoDrago *)arg0)->growth_count = 0;
    ((TObjEneNanoDrago *)arg0)->scale.x = 0.6f;
    ((TObjEneNanoDrago *)arg0)->speed = *(f32 *)((s8 *)(((TObjEneNanoDrago *)arg0)->movementParameters) + 4) * ((TObjEneNanoDrago *)arg0)->scale.x;
    VecCopy((Vec *)(arg0 + 0x50), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x390), (const Vec *)(arg0 + 0x38));
    if ((s32)*(f32 *)((s8 *)arg0 + 0x354) == 1) {
        ((TObjEneNanoDrago *)arg0)->m_388 |= 0x40000;
        if (*(f32 *)((s8 *)arg0 + 0x358) < 1.0f) {
            *(f32 *)((s8 *)arg0 + 0x358) = 50.0f;
        }
        ((TObjEnemyCustom *)arg0)->set_flags_30();
    }
    ((TObjEneNanoDrago *)arg0)->m_3dc = 0;
    ((TObjEneNanoDrago *)arg0)->toggle = 0;
    ((TObjEnemy *)arg0)->set_param(0xF);
    *(f32 *)((s8 *)arg0 + 0x3E4) = 0.0f;
    if (*(s16 *)((s8 *)arg2 + 0xA) != 0 && !(((TObjEneNanoDrago *)arg0)->m_388 & 0x40000)) {
        ((TObjEnemyCustom *)arg0)->sub_800C7860();
    }
    ((TObjEneNanoDrago *)arg0)->m_404 = 0.0f;
    for (i = 0; i < 4; i++) {
        ((TObjPlayer *)(&((Self_800DC180 *)arg0)->subs[i]))->activate_and_dispatch();
    }
    obj_setFlags30(arg0, 0x1000000);
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x38));
    ((TObjEneNanoDrago *)arg0)->clear_lobby_object_state();
    return arg0;
}

void vfunc_58__16TObjEneNanoDragoFv(void);
void vfunc_60__16TObjEneNanoDragoFv(void);
void vfunc_59__16TObjEneNanoDragoFv(void);
void vfunc_61__16TObjEneNanoDragoFv(void);

void TObjEneNanoDrago::vfunc_58() {  }
void TObjEneNanoDrago::vfunc_60() {  }
void TObjEneNanoDrago::vfunc_59() {  }
void TObjEneNanoDrago::vfunc_61() {  }
}
