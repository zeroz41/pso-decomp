#include "types.h"
#include "pso/TObject.h"
#include "pso/object/TObjIllGillKage.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneIllGill.h"
extern "C" void render__15TObjIllGillKageFv();
#include "pso/enemy/TUnk_80494938.h"

#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"

#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct IllGillBase_80367984_8036690C { char pad[0x14]; };
struct IllGillVObj_80367984_8036690C : IllGillBase_80367984_8036690C {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
};

struct Vec_80367270 { f32 x, y, z; };

struct Vec_803660A4 { f32 x, y, z; };

struct Ang_803660A4 { s32 x, y, z; };

struct Vec_80365688 { f32 x, y, z; };

struct VBase_18_80365688 { char pad[0x18]; };

struct VObj_18_80365688 : VBase_18_80365688 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17();
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual f32 m20(void *, f32);
    virtual void m21(); virtual void m22();
    virtual void m23(void *, f32);
};

struct Tgt_80365688 {
    u8 pad0[0x2FC]; Vec_80365688 p2fc;
};

struct Anim_80365688 { u8 pad[8]; f32 f8; u8 padc[4]; };

struct Param_80365688 { f32 range; f32 speed; s32 turn; };

struct Body_80365688 { u8 pad[0xC]; f32 radius; };

struct Gill_80365688 {
    u8 pad0[0x38];
    Vec_80365688 pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xA4 - 0x64];
    Body_80365688 *body;
    u8 padA8[0xB8 - 0xA8];
    s16 fb8;
    u8 padBA[0xC8 - 0xBA];
    f32 fc8;
    u8 padCC[0xD8 - 0xCC];
    Anim_80365688 *anims;
    u8 padDC[0x29C - 0xDC];
    Vec_80365688 f29c;
    Tgt_80365688 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_80365688 p2fc;
    u8 pad308[0x318 - 0x308];
    s32 f318;
    u8 pad31C[0x328 - 0x31C];
    s16 state;
    u8 pad32A[0x338 - 0x32A];
    u16 f338;
    u8 pad33A[0x350 - 0x33A];
    Param_80365688 *param;
    u8 pad354[0x39C - 0x354];
    s32 timer;
    u8 pad3A0[0x3AC - 0x3A0];
    f32 f3ac;
    u8 pad3B0[0x3C8 - 0x3B0];
    Vec_80365688 f3c8;
    Vec_80365688 f3d4;
    VObj_18_80365688 *hit[4];
    u8 pad3F0[0x410 - 0x3F0];
    s32 f410;
    u32 fx414;
    u32 fx418;
};

#define FIG_8036858C(T, o) (*(T *)((u8 *)self + (o)))
struct VBase_18_8036858C { char pad[0x18]; };

struct VObj_18_8036858C : VBase_18_8036858C {
#define V(n) virtual void m##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78)
#undef V
    virtual void m79(void *);
    virtual void m80();
};

struct VSubB_8036858C { char pad[0x14]; };

struct VSub_8036858C : VSubB_8036858C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

extern "C" {
f32 calc_xz_distance_sq(void *, void *, Vec_80367270 *);
extern const f64 lbl_8047A358[];
extern int enable_v2_features;
s32 apply_actor_gravity(void *, int, f32);
s32 update_angle__10TObjPlayerFlPv(void *, void *, void *);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(void *, int);
s32 get_current_floor(void);
f64 atan2_float(f32, f32);
f32 newton_sqrtf(f32);
void spawn_directional_particle(void *, void *, s32);
s32 spawn_continuous_particle_with_direction(void *, void *, s32);
s32 angle_difference_abs(s32, s32);
s32 advance_animation_playback(void *);
s32 get_player_by_client_id(u16);
s32 minimap_render_dot(void *, int, int, int);
s32 play_persistent_sound(int, void *, void *, int, int);
void *__nw__7TObjectFUl(int);
void TObjIllGillKage__ct(void *, s32, void *);
void subtract_vector(void *, void *);
extern const f64 TObjEneIllGill__data_8047A348;
extern s32 tl_05;
extern const f32 TObjEneIllGill__data_805E02BC;
extern const f32 TObjEneIllGill__data_805E02D8;
void TObjEneIllGill__sub_803660A4(void *arg0_);
s32 obj_setFlags30(void *, int);
s32 play_sound_effect(int, void *, int, int);
f32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, void *);
s32 push_matrix_from(void *);
s32 pop_matrices(s32 arg0);
u8 *get_player_data__10TObjPlayerFi(s32);
u16 obj_getField1c(void *);
void enemy_set_heading_velocity(void *, s32, f32);
void enemy_turn_toward_dest(void *, s32);
f32 horizontal_distance_squared(void *, void *);
void TObjEneIllGill__sub_80367DA4(s32 arg0);
void *create_particle_emitter(void *pos, s32 id);
f32 get_collision_body_radius(void *, int);
s32 select_enemy_destination(void *, Vec_80365688, int);
s32 copy_position_if_valid__10TObjPlayerFii(void *, Vec_80365688);
s32 is_split_screen();
extern s32 game_difficulty_selection;
extern s32 local_client_id;
extern u8 *TObjEneIllGill__data_805D6FDC;
extern const f32 lbl_805E02B8;
extern const f32 TObjEneIllGill__data_805E02C0;
extern const f32 lbl_805E02C4;
extern const f32 lbl_805E02C8;
extern const f32 TObjEneIllGill__data_805E02CC;
extern const f32 lbl_805E02D0;
extern const f32 lbl_805E02D4;
void __ct__9TObjEnemyFP7TObject(void *, s32, void *);
s32 init_collision_body_parts(void *, void *, int);
extern s32 __vt__14TObjEneIllGill[];
extern s32 TObjEneIllGill_class_name;
extern int TObjEneIllGill__shared_effect;
extern s32 TObjEneIllGill__boss_registration_id;
extern s32 lbl_805D6FD8;
extern const f32 lbl_805E0308;
u8 *TObjEneIllGill__ct(u8 *self, s32 arg1, u8 *arg2);
}
void move_with_wall_slide(u8 *arg0);
struct RecoveredGlobal_80367DC8_lbl_8050BF00 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_80367DC8_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredFields_80367EFC_arg0
{
  u8 unknown_0[0xB8];
  s16 field_B8;
  u8 unknown_BA[0x26C];
  s16 field_326;
  s16 field_328;
  u8 unknown_32A[0x66];
  s32 field_390;
};

struct RecoveredFields_80367F6C_arg0
{
  u8 unknown_0[0xB8];
  s16 field_B8;
  u8 unknown_BA[0x26C];
  s16 field_326;
  s16 field_328;
  u8 unknown_32A[0x66];
  s32 field_390;
};

struct O_80367DA4 { u8 pad[0x3e0]; s32 arr[4]; };

struct Gill_803671A4 {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[0x84];
    s16 xb8;
    u8 padba[0x26C];
    s16 x326;
    s16 x328;
    u8 pad32a[0x6A];
    s32 x394;
    u8 pad398[0x14];
    f32 x3ac;
};

struct Hit_803683BC { u8 pad[0x30]; u32 flags; };

struct Gill_803683BC {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[0x274];
    Hit_803683BC *x2a8;
    u8 pad2ac[8];
    f32 x2b4;
    u8 pad2b8[0x6E];
    s16 x326;
    u8 pad328[0x74];
    s32 x39c;
};

struct Vec_80367860 { f32 x, y, z; };

struct VBase_18_80367FDC { char pad[0x18]; };

struct VObj_18_80367FDC : VBase_18_80367FDC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16();
    virtual s32 m17(s32);
};

struct Vec_80367FDC { f32 x, y, z; };

struct Gill_80367FDC : VObj_18_80367FDC {
    u16 f1C;
    u8 pad1E[0x2A8 - 0x1E];
    s32 f2A8;
    u8 pad2AC[0x338 - 0x2AC];
    u16 f338;
    u8 pad33A[0x350 - 0x33A];
    f32 *f350;
    u8 pad354[0x390 - 0x354];
    s32 f390;
};

struct VBase_18_f68442 { char pad[0x18]; };

struct VObj_18_f68442 : VBase_18_f68442 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual f32 m20(void *, f32);
    virtual void m21();
    virtual f32 m22(void *, s32);
    virtual void m23(void *, f32);
};

struct Vec3_80366AE4 { f32 x, y, z; };

struct Rec_80366AE4 { f32 f0, f4, f8, fC; };

struct Vec_80367588 { f32 x, y, z; };

struct Vec_80367B00 { f32 x, y, z; };

struct Sub_80367B00 { u8 pad0[4]; f32 f4; s32 f8; };

struct Obj_80367B00 {
    u8 pad0[0x38]; Vec_80367B00 pos; Vec_80367B00 prev; Vec_80367B00 v50;
    u8 pad5c[0x60 - 0x5C]; s32 f60; u8 pad64[0xB8 - 0x64]; s16 fB8;
    u8 padba[0x290 - 0xBA]; Vec_80367B00 v290; Vec_80367B00 v29C;
    u8 pad2a8[0x2FC - 0x2A8]; Vec_80367B00 v2FC;
    u8 pad308[0x350 - 0x308]; Sub_80367B00 *f350;
};

extern "C" {
void *spawn_particle_effect(void *pos, s32 id);
void TObjEneIllGill__sub_803669B0(u8 *arg0);
void queue_destruction__7TObjectFv(void *arg0);
extern const f32 TObjEneIllGill__data_805E02DC;
extern const f32 lbl_805E02E0;
extern const f32 lbl_805E02E4;
s32 project_actor_to_ground(void *, void *, int);
extern RecoveredGlobal_80367DC8_lbl_8050BF00 lbl_8050BF00;
extern RecoveredGlobal_80367DC8_lbl_8058D490 identity_matrix;
void sub_80367DC8__14TObjEneIllGillFl(u8 *arg0, s32 arg1);
s32 update_movement_status__13TUnk_804806E8Fv(void *);
s32 update_action_hold_status__13TUnk_804806E8Fv(void *);
void submit_cursor_candidate(void *, int);
f32 step_toward_destination__10TObjPlayerFPvPvf(void *, Vec_80367860, f32);
void TObjEneIllGill__sub_80367860(u8 *arg0);
extern const f32 lbl_805E02E8;
void TObjEneIllGill__sub_803667B8(u8 *arg0);
u16 find_nearest_visible_player(void *, int, f32 *, f32);
s32 check_path_obstructed(void *, void *);
s32 obj_is_hit_receivable(void *);
s32 get_enemy_entity(u16);
extern Vec_80367FDC lbl_8047A328;
extern s32 lbl_805D586C;
extern s32 lbl_805D5870;
f32 calc_boss4_scale__10TObjPlayerFi(s32 arg0);
extern const f32 lbl_805E02EC;
void TObjEneIllGill__sub_80366AE4(u8 *arg0);
f32 enemy_move_toward(void *, s32, Vec_80367588 *, s32, f32, f32);
s32 enemy_pursue_point(void *, s32, Vec_80367588 *, f32, f32, f32);
extern const f32 lbl_805E02F0;
extern const f32 lbl_805E02F4;
extern const f32 lbl_805E02F8;
f32 fabs_float(f32);
s32 approach_angle_limited(s32, s32, s32);
extern Vec_80367B00 lbl_8050BEE0;
void *__dt__14TObjEneIllGillFv(void *arg0, s16 arg1);
int TLobby__sub_8001FE7C(void*, void*);
void *TObjControl__ct(void *, void *);
void free_collision_body_parts(void *);
s32 TObjEneMe3SinowZoa__sub_800D758C(void *);
void __dl__7TObjectFPv(void *);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);

#pragma push
#pragma opt_common_subs off
extern "C" {
void vfunc_6__13TUnk_804B9870FPsl();
}
extern "C" {
void get_name__13TUnk_804B9870Fv();
}
extern "C" {
void vfunc_9__13TUnk_804B9870Fv();
}
extern "C" {
void *__dt__15TObjIllGillKageFv(void *arg0, s16 arg1);
}
extern "C" {
void apply_object_set_data__13TUnk_804B9870FPv();
}
extern "C" {
void classify_actor_view_detail__13TUnk_804B9870Ffff();
}
extern "C" {
extern u8 lbl_8047A1E8[];
}
extern "C" {
extern u8 lbl_8047A1F8[];
}
extern "C" {
extern u8 lbl_8047A210[];
}
extern "C" {
extern u8 lbl_8047A228[];
}
extern "C" {
extern u8 lbl_8047A240[];
}
extern "C" {
extern u8 lbl_8047A258[];
}
extern "C" {
extern u8 lbl_8047A274[];
}
extern "C" {
extern u8 lbl_8047A290[];
}
extern "C" {
extern u8 lbl_8047A2A8[];
}
extern "C" {
extern u8 lbl_8047A2C4[];
}
extern "C" {
extern u8 lbl_8047A2DC[];
}
extern "C" {
extern u8 lbl_8047A2F4[];
}
extern "C" {
void render_shadows__7TObjectFv();
}
extern "C" {
void reset_motion_fields__13TUnk_804B9870Fv();
}
extern "C" {
void run_task__15TObjIllGillKageFv();
}
extern "C" {
void update_object_view_visibility__13TUnk_804B9870Fff();
}
extern void *TObjEneIllGill_model_file_list[2];
extern void *TObjEneIllGill_motion_name_table[11];
struct Vec_803664C0 { f32 x, y, z; };
typedef Vec_803664C0 V_80368208;
typedef Vec_803664C0 Vec_80368818;
Vec_803664C0 TObjEneIllGill__camera_vec_table;
Vec_803664C0 lbl_80543A6C;
Vec_803664C0 lbl_80543A78;
Vec_803664C0 lbl_80543A84;
u32 lbl_80543A90[4];
__declspec(section ".data") void *TObjEneIllGill_model_file_list[2] = {
    (void *)&lbl_8047A1E8, (void *)0x0,
};
void *TObjEneIllGill_motion_name_table[11] = {
    (void *)&lbl_8047A1F8, (void *)&lbl_8047A210, (void *)&lbl_8047A228, (void *)&lbl_8047A240,
    (void *)&lbl_8047A258, (void *)&lbl_8047A274, (void *)&lbl_8047A290, (void *)&lbl_8047A2A8,
    (void *)&lbl_8047A2C4, (void *)&lbl_8047A2DC, (void *)0x0,
};
void *lbl_804F2E74[4] = {
    (void *)&lbl_8047A2F4, (void *)&TObjEneIllGill_model_file_list, (void *)&TObjEneIllGill_motion_name_table, (void *)0x1000a,
};
void *lbl_804F2E84[40] = {
    (void *)0x10000, (void *)0x0, (void *)0x3f19999a, (void *)0x1,
    (void *)0x10001, (void *)0x1, (void *)0x3f4ccccd, (void *)0x1,
    (void *)0x20000, (void *)0x4, (void *)0x3f800000, (void *)0x4,
    (void *)0x20000, (void *)0x5, (void *)0x3f800000, (void *)0x4,
    (void *)0x20000, (void *)0x8, (void *)0x3f800000, (void *)0x4,
    (void *)0x20000, (void *)0x6, (void *)0x3f800000, (void *)0x8,
    (void *)0x30005, (void *)0x9, (void *)0x3f800000, (void *)0x10,
    (void *)0x20008, (void *)0x7, (void *)0x3f800000, (void *)0x20,
    (void *)0x30009, (void *)0x2, (void *)0x3f800000, (void *)0x20,
    (void *)0x20000, (void *)0x3, (void *)0x3f800000, (void *)0x20,
};
void *lbl_804F2F24[7] = {
    (void *)0x43c80000, (void *)0x3f666666, (void *)0x400, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0,
};
void *lbl_804F2F40[11] = {
    (void *)0x0, (void *)0x41533334, (void *)0x0, (void *)0x40e66667,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *ill_gill_combat_parameter_variants[4] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *__vt__15TObjIllGillKage[13] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__15TObjIllGillKageFv, (void *)&run_task__15TObjIllGillKageFv,
    (void *)&render__15TObjIllGillKageFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804B9870Fv, (void *)&vfunc_9__13TUnk_804B9870Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__13TUnk_804B9870Fv,
};
#define ill_gill_combat_parameter_variants ((s32 *)ill_gill_combat_parameter_variants)

void TObjEneIllGill::update_ai() {
    Gill_80365688 *o = (Gill_80365688 *)this;
    if (o->f338 < 0x1000) {
        s32 p = get_player_by_client_id(o->f338);
        if (p != 0 && ((TObjPlayer *)p)->get_field_3e4() == get_current_floor()) {
            o->target = (Tgt_80365688 *)p;
        } else {
            o->target = NULL;
        }
    } else {
        o->f338 = 0xFFFF;
        o->target = NULL;
    }
    ((TUnk_804B9870 *)o)->obj_clearFlags30(0x40000);
    if (o->target == NULL) {
        o->f338 = 0xFFFF;
        ((TUnk_804B9870 *)o)->obj_clearFlags30(0x4202000);
        o->timer = 0;
        return;
    }
    switch (o->state) {
    default:
        o->state = 0;
    case 0:
        ((TUnk_804B9870 *)o)->obj_clearFlags30(0x4000000);
        ((TUnk_804AF8A0 *)o)->clear_player_status_flag(0, 0x80);
        o->fc8 = lbl_805E02B8 * o->anims[o->fb8].f8;
        advance_animation_playback(o);
        apply_actor_gravity(o, 0, TObjEneIllGill__data_805E02BC);
        if (o->target != NULL) {
            Vec_80365688 v = o->target->p2fc;
            s32 d;
            subtract_vector(&v, &o->p2fc);
            d = update_angle__10TObjPlayerFlPv(o, (void *)(s32)(lbl_805E02B8 * (f32)o->param->turn), &v);
            if (d < ((TObjPlayer *)(o->f318))->get_field_0c()) {
                s32 ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(v.x, v.z));
                o->f3ac = TObjEneIllGill__data_805E02C0 + (newton_sqrtf(TObjPlayer::calc_distance_to_client((s32)o, o->f338, (u32)0)) + get_collision_body_radius(o, 0));
                if (o->f3ac < lbl_805E02C4) {
                    o->f3ac = lbl_805E02C4;
                }
                v.z = TObjEneIllGill__data_805E02BC;
                v.x = TObjEneIllGill__data_805E02BC;
                v.z = o->f3ac;
                push_matrix_from(&identity_matrix);
                rotate_matrix_y(0, (void *)ang);
                rotate_vector_by_matrix(0, &v, &v);
                pop_matrices(1);
                vec3_add_to(&v, &o->p2fc);
                if (select_enemy_destination(o, v, 1) != 0 || select_enemy_destination(o, o->target->p2fc, 1) != 0) {
                    o->state = 1;
                    o->fb8 = 8;
                    obj_setFlags30(o, 0x4000000);
                    ((TUnk_804AF8A0 *)o)->set_indexed_flags(0, 0x80);
                    copy_position_if_valid__10TObjPlayerFii(o, o->p2fc);
                    o->timer = 10;
                    play_sound_effect(0x4003A34E, &o->pos, 0, 0);
                } else {
                    if (o->f338 == 0xFFFF) {
                        o->target = NULL;
                    } else {
                        o->state = 4;
                        o->fb8 = 9;
                        o->timer = *(f32 *)TObjEneIllGill__data_805D6FDC;
                    }
                    TObjEneIllGill__sub_80367DA4((s32)o);
                }
            }
        }
        break;
    case 1: {
        obj_setFlags30(o, 0x4000000);
        ((TUnk_804AF8A0 *)o)->set_indexed_flags(0, 0x80);
        {
            Vec_80365688 v = o->target->p2fc;
            s32 d;
            subtract_vector(&v, &o->p2fc);
            d = update_angle__10TObjPlayerFlPv(o, (void *)(s32)(lbl_805E02B8 * (f32)o->param->turn), &v);
            if (d < ((TObjPlayer *)(o->f318))->get_field_0c()) {
                s32 ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(v.x, v.z));
                o->f3ac = TObjEneIllGill__data_805E02C0 + (newton_sqrtf(TObjPlayer::calc_distance_to_client((s32)o, o->f338, (u32)0)) + get_collision_body_radius(o, 0));
                if (o->f3ac < lbl_805E02C4) {
                    o->f3ac = lbl_805E02C4;
                }
                v.z = TObjEneIllGill__data_805E02BC;
                v.x = TObjEneIllGill__data_805E02BC;
                v.z = o->f3ac;
                push_matrix_from(&identity_matrix);
                rotate_matrix_y(0, (void *)ang);
                rotate_vector_by_matrix(0, &v, &v);
                pop_matrices(1);
                vec3_add_to(&v, &o->p2fc);
                if (select_enemy_destination(o, v, 1) == 0 && select_enemy_destination(o, o->target->p2fc, 1) == 0) {
                    if (o->f338 == 0xFFFF) {
                        o->target = NULL;
                    } else {
                        o->state = 4;
                        o->fb8 = 9;
                        o->timer = *(f32 *)TObjEneIllGill__data_805D6FDC;
                    }
                    TObjEneIllGill__sub_80367DA4((s32)o);
                }
            }
        }
        advance_animation_playback(o);
        apply_actor_gravity(o, 0, TObjEneIllGill__data_805E02BC);
        o->timer--;
        if (o->timer < 0) {
            o->state = 2;
            o->fb8 = 9;
            ((TUnk_804B9870 *)o)->obj_clearFlags30(0x4000000);
            ((TUnk_804AF8A0 *)o)->clear_player_status_flag(0, 0x80);
            if (o->fx414 == 0) {
                o->fx414 = (u32)create_particle_emitter(&o->f3c8, 0x222);
            }
            if (o->fx418 == 0) {
                o->fx418 = (u32)create_particle_emitter(&o->f3d4, 0x222);
            }
        }
        break;
    }
    case 2: {
        s32 k;
        VObj_18_80365688 *p;
        s32 i;
        ((TUnk_804B9870 *)o)->obj_clearFlags30(0x4000000);
        ((TUnk_804AF8A0 *)o)->clear_player_status_flag(0, 0x80);
        o->fc8 = o->anims[o->fb8].f8;
        advance_animation_playback(o);
        for (i = 0; i < 4; i++) {
            k = i * 4 + 0x3E0;
            if (*(VObj_18_80365688 **)((u8 *)o + k) == NULL) {
                p = (VObj_18_80365688 *)get_player_data__10TObjPlayerFi(i);
                if (p == NULL) {
                    break;
                }
                if (obj_getField1c(p) >= 0x1000) {
                    break;
                }
                if (((TUnk_804AF8A0 *)o)->find_actor_body_contact((u8 *)p, (f32)lbl_805E02C8) != 0 &&
                    p->m18(o, TObjEneIllGill__data_805E02CC) != 0) {
                    f32 dmg = p->m20(o, TObjEneIllGill__data_805E02CC);
                    obj_setFlags30(p, 0x400);
                    p->m23(o, lbl_805E02B8 * dmg);
                    *(VObj_18_80365688 **)((u8 *)o + k) = p;
                    if (is_split_screen() == 0 && local_client_id == obj_getField1c(p)) {
                        TCameraCtrl::set_shake_preset(1);
                    }
                }
            }
        }
        if (o->target != NULL) {
            Param_80365688 *prm = o->param;
            f32 spd = lbl_805E02D0 * prm->speed;
            f32 d2;
            f32 t;
            s32 c;
            if (enable_v2_features == 1 && game_difficulty_selection == 3) {
                spd *= lbl_805E02B8;
            }
            enemy_turn_toward_dest(o, (s32)(lbl_805E02D0 * (f32)prm->turn));
            enemy_set_heading_velocity(o, o->angle, spd);
            move_with_wall_slide((u8 *)o);
            d2 = horizontal_distance_squared(&o->f29c, &o->p2fc);
            t = spd + o->body->radius;
            if (d2 < t * t || o->param->range * o->param->range < d2 || lbl_805E02D4 < (f32)(c = o->f410)) {
                if (o->f338 == 0xFFFF) {
                    o->target = NULL;
                } else {
                    o->state = 4;
                    o->fb8 = 9;
                    o->timer = *(f32 *)TObjEneIllGill__data_805D6FDC;
                    ((TObjEneIllGill *)o)->free_resources();
                }
                TObjEneIllGill__sub_80367DA4((s32)o);
                o->f410 = 0;
            } else {
                o->f410 = c + 1;
            }
        }
        play_persistent_sound(0x4003A34F, o, &o->pos, 0, 0);
        if (o->fx414 != 0 && ((TObject *)(o->fx414))->all_parents_unqueued_for_destruction() != 0) {
            ((TNowLoading *)(o->fx414))->copy_pos(&o->f3c8);
        }
        if (o->fx418 != 0 && ((TObject *)(o->fx414))->all_parents_unqueued_for_destruction() != 0) {
            ((TNowLoading *)(o->fx418))->copy_pos(&o->f3d4);
        }
        break;
    }
    case 4:
        ((TUnk_804B9870 *)o)->obj_clearFlags30(0x4000000);
        ((TUnk_804AF8A0 *)o)->clear_player_status_flag(0, 0x80);
        o->fc8 = lbl_805E02B8 * o->anims[o->fb8].f8;
        advance_animation_playback(o);
        apply_actor_gravity(o, 0, TObjEneIllGill__data_805E02BC);
        o->timer--;
        if (o->timer < 0) {
            ((TUnk_804B9870 *)o)->obj_clearFlags30(0x200000);
            o->timer = 0;
            o->f338 = 0xFFFF;
            o->target = NULL;
        }
        break;
    }
    ((TUnk_804AF8A0 *)o)->refresh_collision_body_centers();
    minimap_render_dot(&o->pos, -0x5DB4, 1, 0);
}
#pragma pop

void TObjEneIllGill__sub_803660A4(void *arg0_) {
    u8 *pl;
    s32 a;
    u8 *enemy = (u8 *)arg0_;
    if (*(u16 *)((s8 *)enemy + 0x338) < 0x1000U) {
        pl = (u8 *)get_player_by_client_id(*(u16 *)((s8 *)enemy + 0x338));
        if (pl != NULL && ((TObjPlayer *)pl)->get_field_3e4() == get_current_floor()) {
            *(u8 **)((s8 *)enemy + 0x2A8) = pl;
        } else {
            *(u8 **)((s8 *)enemy + 0x2A8) = NULL;
        }
    } else {
        *(u16 *)((s8 *)enemy + 0x338) = 0xFFFFU;
        *(u8 **)((s8 *)enemy + 0x2A8) = NULL;
    }
    ((TUnk_804B9870 *)enemy)->obj_clearFlags30(0x04040000);
    advance_animation_playback(enemy);
    switch (*(s16 *)((s8 *)enemy + 0x328)) {
    case 0:
        if (*(u8 **)((s8 *)enemy + 0x2A8) == NULL) {
            *(s32 *)((s8 *)enemy + 0x30) &= ~0x00200000;
            *(s32 *)((s8 *)enemy + 0x39C) = 0;
        } else {
            Vec_803660A4 v;
            VecCopy((Vec *)&v, (const Vec *)(*(u8 **)((s8 *)enemy + 0x2A8) + 0x2FC));
            subtract_vector(&v, enemy + 0x2FC);
            a = update_angle__10TObjPlayerFlPv(enemy, (void *)*(s32 *)((s8 *)(*(u8 **)((s8 *)enemy + 0x350)) + 8), &v);
            apply_actor_gravity(enemy, 0, TObjEneIllGill__data_805E02BC);
            if (a < ((TObjPlayer *)(ill_gill_combat_parameter_variants[2]))->get_field_0c()) {
                *(s16 *)((s8 *)enemy + 0x328) = 1;
                *(s16 *)((s8 *)enemy + 0xB8) = 4;
                *(s32 *)((s8 *)enemy + 0x39C) = 0;
            }
        }
        break;
    case 1:
        if (objInBand((GameObj *)enemy, (f32)TObjEneIllGill__data_805E02D8) != 0) {
            *(s16 *)((s8 *)enemy + 0x328) = 2;
            *(s16 *)((s8 *)enemy + 0xB8) = 4;
            *(s32 *)((s8 *)enemy + 0x39C) = 0;
            {
                Vec_803660A4 d = *(Vec_803660A4 *)(*(u8 **)((s8 *)enemy + 0x2A8) + 0x2FC);
                Ang_803660A4 ang;
                subtract_vector(&d, enemy + 0x3BC);
                ang.x = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(d.z, newton_sqrtf(d.x * d.x + d.y * d.y)));
                ang.y = 0;
                ang.z = -(s32)(TObjEneIllGill__data_8047A348 * atan2_float(d.x, d.y));
                if (*(u32 *)((s8 *)enemy + 0x414) == 0U) {
                    *(u32 *)((s8 *)enemy + 0x414) = spawn_continuous_particle_with_direction(enemy + 0x3BC, &ang, 0x224);
                }
                spawn_directional_particle(enemy + 0x3BC, &ang, 0x223);
            }
        }
        break;
    case 2:
        play_persistent_sound(0x4003A356, enemy, enemy + 0x38, 0, 0);
        apply_actor_gravity(enemy, 0, TObjEneIllGill__data_805E02BC);
        if (*(u8 **)((s8 *)enemy + 0x2A8) != NULL) {
            Vec_803660A4 w;
            VecCopy((Vec *)&w, (const Vec *)(*(u8 **)((s8 *)enemy + 0x2A8) + 0x2FC));
            subtract_vector(&w, enemy + 0x2FC);
            a = angle_difference_abs(*(s32 *)((s8 *)enemy + 0x60), (s32)(TObjEneIllGill__data_8047A348 * atan2_float(w.x, w.z)));
            if (a < ((TObjPlayer *)(ill_gill_combat_parameter_variants[2]))->get_field_0c()) {
                VecCopy((Vec *)&w, (const Vec *)(*(u8 **)((s8 *)enemy + 0x2A8) + 0x38));
                subtract_vector(&w, enemy + 0x3BC);
                atan2_float(w.z, newton_sqrtf(w.x * w.x + w.y * w.y));
                atan2_float(w.x, w.y);
                if (*(u32 *)((s8 *)enemy + 0xB4) != 4 && obj_testFlags30__13TUnk_804AF8A0FUl(*(u8 **)((s8 *)enemy + 0x2A8), 0x04000000) == 0) {
                    void *m = __nw__7TObjectFUl(0x9C);
                    if (m != NULL) {
                        TObjIllGillKage__ct(m, tl_05, *(u8 **)((s8 *)enemy + 0x2A8));
                    }
                }
            } else {
                *(u32 *)((s8 *)enemy + 0xB4) &= ~4;
            }
        } else {
            *(u32 *)((s8 *)enemy + 0xB4) &= ~4;
        }
        if (*(u32 *)((s8 *)enemy + 0xB4) != 4) {
            *(s16 *)((s8 *)enemy + 0x328) = 4;
            *(s16 *)((s8 *)enemy + 0xB8) = 0;
            *(s32 *)((s8 *)enemy + 0x39C) = 10;
        }
        break;
    case 4:
        apply_actor_gravity(enemy, 0, TObjEneIllGill__data_805E02BC);
        *(s32 *)((s8 *)enemy + 0x39C) = *(s32 *)((s8 *)enemy + 0x39C) - 1;
        if (*(s32 *)((s8 *)enemy + 0x39C) < 0) {
            *(s32 *)((s8 *)enemy + 0x30) &= ~0x00200000;
            *(s32 *)((s8 *)enemy + 0x39C) = 0;
            ((TObjEneIllGill *)enemy)->free_resources();
        }
        break;
    }
    ((TObjPlayer *)enemy)->update_collisions();
    minimap_render_dot(enemy + 0x38, -0x5DB4, 1, 0);
}
extern u8 lbl_804FF5E8[];
extern s32 TObjEneIllGill__data_805D6FE0;
void TObjEneIllGill::advance_camera_vec_stage() {
    Vec_803664C0 *v;
    switch (TObjEneIllGill__data_805D6FE0) {
    case 50:
        v = &TObjEneIllGill__camera_vec_table;
        v->x = TObjEneIllGill__data_805E02BC;
        v->y = TObjEneIllGill__data_805E02BC;
        v->z = TObjEneIllGill__data_805E02BC;
        TObjBoss2Tunnel::transform_vec_by_camera((s32)lbl_804FF5E8, (s32)v, (s32)v);
        break;
    case 44:
        v = &lbl_80543A6C;
        v->x = TObjEneIllGill__data_805E02BC;
        v->y = TObjEneIllGill__data_805E02BC;
        v->z = TObjEneIllGill__data_805E02BC;
        TObjBoss2Tunnel::transform_vec_by_camera((s32)lbl_804FF5E8, (s32)v, (s32)v);
        break;
    case 40:
        v = &lbl_80543A78;
        v->x = TObjEneIllGill__data_805E02BC;
        v->y = TObjEneIllGill__data_805E02BC;
        v->z = TObjEneIllGill__data_805E02BC;
        TObjBoss2Tunnel::transform_vec_by_camera((s32)lbl_804FF5E8, (s32)v, (s32)v);
        break;
    case 27:
        v = &lbl_80543A84;
        v->x = TObjEneIllGill__data_805E02BC;
        v->y = TObjEneIllGill__data_805E02BC;
        v->z = TObjEneIllGill__data_805E02BC;
        TObjBoss2Tunnel::transform_vec_by_camera((s32)lbl_804FF5E8, (s32)v, (s32)v);
        break;
    }
    TObjEneIllGill__data_805D6FE0++;
}

void TObjEneIllGill::update_death_fall() {
    u8 *arg0 = (u8 *)this;
  s32 temp_r0_2;
  obj_setFlags30((void *) arg0, 0x04040000);
  advance_animation_playback((void *) arg0);
  switch (this->phase)
  {
    default:
      this->phase = 0;
    case 0:
      ((s32)apply_actor_gravity((void *) arg0, 0, (f32) TObjEneIllGill__data_805E02BC));
      if (objInBand((GameObj *)arg0, (f32)((f32) TObjEneIllGill__data_805E02D8)) != 0)
    {
      play_sound_effect(0x4003A351, (u8 *)&this->position, 0, 0);
      this->phase = 2;
    }
      return;
    return;
    case 2:
      this->m_300 = (f32) ((this->m_300) + TObjEneIllGill__data_805E02DC);
      move_with_wall_slide(arg0);
      *((f32 *) (((s8 *) arg0) + 0x308)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x308))) * lbl_805E02E0);
      this->m_310 = (f32) ((this->m_310) * lbl_805E02E0);
      if (objInBand((GameObj *)arg0, (f32)((f32) TObjEneIllGill__data_805E02C0)) != 0)
    {
      this->phase = 3;
      spawn_particle_effect(((u8 *)&this->position), 0xF0);
      return;
    }
      break;
    case 3:
      if (objInBand((GameObj *)arg0, (f32)((f32) lbl_805E02E4)) != 0)
    {
      play_sound_effect(0x4003A358, (u8 *)&this->position, 0, 0);
      TObjPlayer::apply_effect_variant_b((s32)(arg0 + 0x38), 0xA);
      ((TObjPlayer *)(arg0 + 0x38))->request_two_effects();
      this->phase = 4;
      this->m_3a0 = 0xA;
      return;
    }
      break;
    case 4:
      temp_r0_2 = (this->m_3a0) - 1;
      this->m_3a0 = temp_r0_2;
      if (temp_r0_2 < 0)
    {
      queue_destruction__7TObjectFv(arg0);
    }
      break;
  }
}

void TObjEneIllGill::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r5;
    if ((s16) this->mode != 8) {
        this->mode = 8;
        this->phase = 0;
        this->m_b8 = 6;
        temp_r5 = (u8 *)this->m_a4;
        *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) & 0xFFFF7FFE);
        ((TObjEneIllGill *)arg0)->free_resources();
        spawn_particle_effect(((u8 *)&this->m_2fc), 0xF2);
        ((TObjPlayer *)arg0)->refresh_lobby_state();
        ((TObjEnemy *)arg0)->send_entity_set_flags();
    }
}

void TObjEneIllGill__sub_803667B8(u8 *arg0) {
    ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x04040000);
    advance_animation_playback(arg0);
    ((TObjPlayer *)arg0)->m_310 = TObjEneIllGill__data_805E02BC;
    *(f32 *)((s8 *)arg0 + 0x308) = TObjEneIllGill__data_805E02BC;
    apply_actor_gravity(arg0, 0, TObjEneIllGill__data_805E02BC);
    ((TObjPlayer *)arg0)->update_collisions();
    if (objInBand((GameObj *)arg0, (f32)TObjEneIllGill__data_805E02C0) != 0) {
        play_sound_effect(0x4003A350, arg0 + 0x38, 0, 0);
    }
    if (((TObjPlayer *)arg0)->m_b4 != 8) {
        ((TObjPlayer *)arg0)->actorFlags &= ~0x600;
        *(u32 *)((s8 *)(((TObjPlayer *)arg0)->m_a4) + 0x18) &= ~0x04000000;
        if ((f32)((TObjPlayer *)arg0)->hp < lbl_805E02E8 * (f32)((TObjPlayer *)arg0)->hpmax) {
            ((TObjPlayer *)arg0)->actorFlags |= 0x2000;
            *(s32 *)((s8 *)arg0 + 0x2A8) = 0;
            *(u16 *)((s8 *)arg0 + 0x338) = 0xFFFF;
            VecCopy((Vec *)(arg0 + 0x290), (const Vec *)(arg0 + 0x2FC));
            VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(arg0 + 0x2FC));
            *(f32 *)((s8 *)arg0 + 0x3AC) = TObjEneIllGill__data_805E02BC;
        }
        ((TObjPlayer *)arg0)->m_33e = ((TObjPlayer *)arg0)->hp;
    }
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
}

void TObjEneIllGill::vfunc_62() {
    s16 temp_r0;
    void *temp_r3;

    temp_r0 = this->m_b8;
    if ((temp_r0 == 2) || (temp_r0 == 3)) {
        this->referenceHp = (s16) this->hp;
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFDFF);
        this->m_2dc = 0;
        temp_r3 = this->m_a4;
        *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFBFFFFFF);
        return;
    }
    if ((s16) this->mode != 7) {
        this->mode = 7;
        this->m_b8 = 5;
        this->free_resources();
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
}

void TObjEneIllGill__sub_803669B0(u8 *player) {
    s32 temp_r3;
    ((TUnk_804B9870 *)player)->obj_clearFlags30((int)(0x04040000U));
    advance_animation_playback(player);
    if (!(((TObjPlayer *)player)->actorFlags & 0x800000)) {
        apply_actor_gravity(player, 0, (f32) ((*(f32 *)&TObjEneIllGill__data_805E02BC)));
    }
    ((TObjPlayer *)player)->update_collisions();
    temp_r3 = *(s32 *)((s8 *)player + 0x39C);
    *(s32 *)((s8 *)player + 0x39C) = (temp_r3 - 1);
    if (temp_r3 < 0) {
        ((TObjPlayer *)player)->actorFlags = (s32) (((TObjPlayer *)player)->actorFlags & 0xFFFFFEFF);
        *(s32 *)((s8 *)player + 0x39C) = (s32) *(s16 *)((s8 *)player + 0x33A);
        ((TObjPlayer *)player)->m_33e = (s16) ((TObjPlayer *)player)->hp;
    }
    minimap_render_dot(player + 0x38, -0x5DB4, 1, 0);
}

void TObjEneIllGill::vfunc_61() { obj_clearFlags30(256); }
void TObjEneIllGill::free_resources() {
    if ((u32) this->m_414 != 0U) {
        TBoss4Type2::request_destroy(this->m_414);
        this->m_414 = 0U;
    }
    if ((u32) this->m_418 != 0U) {
        TBoss4Type2::request_destroy(this->m_418);
        this->m_418 = 0U;
    }
    if ((u32) this->m_41c != 0U) {
        TBoss4Type2::request_destroy(this->m_41c);
        this->m_41c = 0U;
    }
}

extern const f32 lbl_805E02FC;

void TObjEneIllGill__sub_80366AE4(u8 *actor) {
    s32 sp10;
    s32 spC;
    s32 sp8;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f31;
    s32 temp_r30;
    s32 temp_r30_2;
    u16 temp_r3;
    u32 temp_r3_10;
    u32 temp_r3_11;
    u32 temp_r3_12;
    u8 *player;
    u8 *temp_r3_3;
    u8 *temp_r4;
    u8 *temp_r6;
    temp_r3 = *(u16 *)((s8 *)actor + 0x338);
    if (temp_r3 < 0x1000U) {
        player = (u8 *)get_player_by_client_id(temp_r3);
        if ((player != NULL) && (((TObjPlayer *)player)->get_field_3e4() == get_current_floor())) {
            *(u8 **)((s8 *)actor + 0x2A8) = player;
        } else {
            *(u8 **)((s8 *)actor + 0x2A8) = NULL;
        }
    } else if (temp_r3 < 0x4000U) {
        *(u8 **)((s8 *)actor + 0x2A8) = (u8 *)get_enemy_entity(temp_r3);
    } else {
        *(u16 *)((s8 *)actor + 0x338) = 0xFFFFU;
        *(u8 **)((s8 *)actor + 0x2A8) = NULL;
    }
    ((TUnk_804B9870 *)actor)->obj_clearFlags30(0x04040000);
    *(f32 *)((s8 *)actor + 0xC8) = *(f32 *)((s8 *)TObjEneIllGill__data_805D6FDC + 4) * (*(Rec_80366AE4 **)((s8 *)actor + 0xD8))[*(s16 *)((s8 *)actor + 0xB8)].f8;
    advance_animation_playback(actor);
    switch (*(s16 *)((s8 *)actor + 0x328)) {
    default:
        *(s16 *)((s8 *)actor + 0x328) = 0;
    case 0:
        temp_r6 = (u8 *)(*(u8 **)((s8 *)actor + 0x2A8));
        if (temp_r6 == NULL) {
            *(s32 *)((s8 *)actor + 0x30) = (s32) (*(s32 *)((s8 *)actor + 0x30) & 0xFFDFFFFF);
            *(s32 *)((s8 *)actor + 0x39C) = 0;
        } else {
            Vec3_80366AE4 v = *(Vec3_80366AE4 *)((s8 *)temp_r6 + 0x2FC);
            subtract_vector(&v, actor + 0x2FC);
            temp_r30_2 = update_angle__10TObjPlayerFlPv(actor, (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)actor + 0x350)) + 8)), &v);
            apply_actor_gravity(actor, 0, TObjEneIllGill__data_805E02BC);
            if (temp_r30_2 < ((TObjPlayer *)(*(s32 *)((s8 *)actor + 0x318)))->get_field_0c()) {
                *(s16 *)((s8 *)actor + 0x328) = 2;
                temp_f1_2 = *(f32 *)((s8 *)actor + 0x358);
                if (TObjEneIllGill__data_805E02BC == temp_f1_2) {
                    if (calc_boss4_scale__10TObjPlayerFi((s32)actor) > lbl_805E02EC) {
                        if (calc_boss4_scale__10TObjPlayerFi((s32)actor) > lbl_805E02E0) {
                            *(s32 *)((s8 *)actor + 0x398) = 1;
                        } else {
                            *(s32 *)((s8 *)actor + 0x398) = 2;
                        }
                    } else {
                        *(s32 *)((s8 *)actor + 0x398) = 3;
                    }
                } else {
                    *(s32 *)((s8 *)actor + 0x398) = (s32) temp_f1_2;
                }
                switch (*(s32 *)((s8 *)actor + 0x398)) {
                case 1:
                    *(s16 *)((s8 *)actor + 0xB8) = 2;
                    if ((u32) *(u32 *)((s8 *)actor + 0x414) == 0U) {
                        *(u32 *)((s8 *)actor + 0x414) = (u32)create_particle_emitter((actor + 0x3B0), 0x1E);
                    }
                    if ((u32) *(u32 *)((s8 *)actor + 0x418) == 0U) {
                        *(u32 *)((s8 *)actor + 0x418) = (u32)create_particle_emitter((actor + 0x3B0), 0x1F);
                    }
                    *(s32 *)((s8 *)actor + 0x3A4) = 0x1E;
                    *(u32 *)((s8 *)actor + 0x41C) = 0U;
                    play_sound_effect(0x4003A352, actor + 0x38, 0, 0);
                    break;
                case 2:
                    *(s16 *)((s8 *)actor + 0xB8) = 2;
                    if ((u32) *(u32 *)((s8 *)actor + 0x414) == 0U) {
                        *(u32 *)((s8 *)actor + 0x414) = (u32)create_particle_emitter((actor + 0x3B0), 0xA1);
                    }
                    if ((u32) *(u32 *)((s8 *)actor + 0x418) == 0U) {
                        *(u32 *)((s8 *)actor + 0x418) = (u32)create_particle_emitter((actor + 0x3B0), 0x188);
                    }
                    *(s32 *)((s8 *)actor + 0x3A4) = 0x1E;
                    *(u32 *)((s8 *)actor + 0x41C) = 0U;
                    play_sound_effect(0x4003A352, actor + 0x38, 0, 0);
                    break;
                case 3:
                default:
                    *(s16 *)((s8 *)actor + 0xB8) = 3;
                    if ((u32) *(u32 *)((s8 *)actor + 0x414) == 0U) {
                        *(u32 *)((s8 *)actor + 0x414) = (u32)create_particle_emitter((actor + 0x3B0), 0x1C4);
                    }
                    if ((u32) *(u32 *)((s8 *)actor + 0x418) == 0U) {
                        *(u32 *)((s8 *)actor + 0x418) = (u32)create_particle_emitter((actor + 0x3B0), 0x1C5);
                    }
                    if ((u32) *(u32 *)((s8 *)actor + 0x41C) == 0U) {
                        *(u32 *)((s8 *)actor + 0x41C) = (u32)create_particle_emitter((actor + 0x3B0), 0x1C8);
                    }
                    *(s32 *)((s8 *)actor + 0x3A4) = 0x23;
                    play_sound_effect(0x4003A352, actor + 0x38, 0, 0);
                    break;
                }
            }
        }
        break;
    case 2:
        apply_actor_gravity(actor, 0, TObjEneIllGill__data_805E02BC);
        if (objInBand((GameObj *)(actor), TObjEneIllGill__data_805E02DC) != 0) {
            play_sound_effect(0x4003A353, actor + 0x38, 0, 0);
        }
        if (objInBand((GameObj *)(actor), (f32)((f32) *(s32 *)((s8 *)actor + 0x3A4))) != 0) {
            *(s32 *)((s8 *)actor + 0x3A4) = 0;
            temp_r3_3 = (u8 *)(*(u8 **)((s8 *)actor + 0x2A8));
            if ((temp_r3_3 != NULL) && (((VObj_18_f68442 *)(temp_r3_3))->m18(actor, TObjEneIllGill__data_805E02CC) != 0)) {
                switch (*(s32 *)((s8 *)actor + 0x398)) {
                case 1:
                    ((TObjPlayer *)actor)->set_model_id(7);
                    ((TObjPlayer *)actor)->set_model_param((int) ((s16) *(s32 *)((s8 *)TObjEneIllGill__data_805D6FDC + 0x18)));
                    ((VObj_18_f68442 *)((u8 *)(*(u8 **)((s8 *)actor + 0x2A8))))->m22(actor, 0);
                    play_sound_effect(0x40039E54, actor + 0x38, 0, 0);
                    break;
                case 2:
                    ((TObjPlayer *)actor)->set_model_id(0xA);
                    ((TObjPlayer *)actor)->set_model_param((int) ((s16) *(s32 *)((s8 *)TObjEneIllGill__data_805D6FDC + 0x18)));
                    ((VObj_18_f68442 *)((u8 *)(*(u8 **)((s8 *)actor + 0x2A8))))->m22(actor, 0);
                    play_sound_effect(0x40039E54, actor + 0x38, 0, 0);
                    break;
                case 3:
                    ((TObjPlayer *)actor)->set_model_id(0xB);
                    ((TObjPlayer *)actor)->set_model_param((int) ((s16) *(s32 *)((s8 *)TObjEneIllGill__data_805D6FDC + 0x1C)));
                    if (((VObj_18_f68442 *)((u8 *)(*(u8 **)((s8 *)actor + 0x2A8))))->m22(actor, 0) <= TObjEneIllGill__data_805E02BC) {
                        ((VObj_18_f68442 *)((u8 *)(*(u8 **)((s8 *)actor + 0x2A8))))->m20(actor, TObjEneIllGill__data_805E02CC);
                    }
                    play_sound_effect(0x40039E55, actor + 0x38, 0, 0);
                    break;
                default:
                    temp_f31 = ((VObj_18_f68442 *)((u8 *)(*(u8 **)((s8 *)actor + 0x2A8))))->m20(actor, TObjEneIllGill__data_805E02CC);
                    play_sound_effect(0x40039E54, actor + 0x38, 0, 0);
                    ((VObj_18_f68442 *)((u8 *)(*(u8 **)((s8 *)actor + 0x2A8))))->m23(actor, temp_f31);
                    break;
                }
            }
        }
        temp_r3_10 = *(u32 *)((s8 *)actor + 0x414);
        if ((temp_r3_10 != 0U) && (((TObject *)temp_r3_10)->all_parents_unqueued_for_destruction() != 0)) {
            ((TNowLoading *)(*(u32 *)((s8 *)actor + 0x414)))->copy_pos(actor + 0x3B0);
        }
        temp_r3_11 = *(u32 *)((s8 *)actor + 0x418);
        if ((temp_r3_11 != 0U) && (((TObject *)temp_r3_11)->all_parents_unqueued_for_destruction() != 0)) {
            ((TNowLoading *)(*(u32 *)((s8 *)actor + 0x418)))->copy_pos(actor + 0x3B0);
        }
        temp_r3_12 = *(u32 *)((s8 *)actor + 0x41C);
        if ((temp_r3_12 != 0U) && (((TObject *)temp_r3_12)->all_parents_unqueued_for_destruction() != 0)) {
            ((TNowLoading *)(*(u32 *)((s8 *)actor + 0x41C)))->copy_pos(actor + 0x3B0);
        }
        if ((u32) *(u32 *)((s8 *)actor + 0xB4) != 4U) {
            *(s16 *)((s8 *)actor + 0x328) = 3;
            *(s16 *)((s8 *)actor + 0xB8) = 0;
            *(s32 *)((s8 *)actor + 0x39C) = 0x1E;
            ((TObjEneIllGill *)actor)->free_resources();
        }
        break;
    case 3:
        apply_actor_gravity(actor, 0, TObjEneIllGill__data_805E02BC);
        *(s32 *)((s8 *)actor + 0x39C) = (s32) (*(s32 *)((s8 *)actor + 0x39C) - 1);
        if ((s32) *(s32 *)((s8 *)actor + 0x39C) < 0) {
            *(s32 *)((s8 *)actor + 0x30) = (s32) (*(s32 *)((s8 *)actor + 0x30) & 0xFFDFFFFF);
            *(s32 *)((s8 *)actor + 0x39C) = 0;
        }
        break;
    }
    ((TObjPlayer *)actor)->update_collisions();
    minimap_render_dot(actor + 0x38, -0x5DB4, 1, 0);
}

void TObjEneIllGill::vfunc_60() {
    Gill_803671A4 *o = (Gill_803671A4 *)this;
    switch (o->x394) {
    default:
        o->x394 = 0;
    case 0:
    case 1:
        o->x326 = 3;
        o->x328 = 0;
        o->xb8 = 1;
        break;
    case 2:
        o->x326 = 5;
        o->x328 = 0;
        o->xb8 = 1;
        break;
    case 3:
        o->x326 = 4;
        o->x328 = 0;
        o->xb8 = 7;
        o->x3ac = TObjEneIllGill__data_805E02BC;
        TObjEneIllGill__sub_80367DA4((s32)o);
        break;
    }
    o->flags |= 0x200000;
    o->flags &= ~0x40000;
}

#define F(t, o) (*(t *)((s8 *)(((u8 *)this)) + (o)))

s32 TObjEneIllGill::is_target_in_attack_range() {
    Vec_80367270 v;
    f32 dist;
    s32 ang;
    f32 rad;
    u16 id;
    u8 *pl;

    if (F(u8 *, 0x2A8) != NULL && F(u32, 0x318) != 0 && !(*(s32 *)((s8 *)(F(u8 *, 0x2A8)) + 0x30) & 0x02000800)) {
        if (obj_testFlags30__13TUnk_804AF8A0FUl(this, 0x2000) != 0) {
            F(s32, 0x394) = 3;
            bind_enemy_combat_stats((u8 *)0, (u8 *)(ill_gill_combat_parameter_variants[F(s32, 0x394)]), (u8 *)0);
            return 1;
        }
        dist = calc_xz_distance_sq(this, F(u8 *, 0x2A8), &v);
        ang = angle_difference_abs(F(s32, 0x60), (s32)(TObjEneIllGill__data_8047A348 * atan2_float(v.x, v.z)));
        pl = F(u8 *, 0x2A8);
        if (*(u8 **)((s8 *)pl + 0xA4) != NULL) {
            rad = *(f32 *)((s8 *)(*(u8 **)((s8 *)pl + 0xA4)) + 0xC) - lbl_8047A358[0];
        } else {
            rad = TObjEneIllGill__data_805E02D8;
        }
        id = obj_getField1c(pl);
        if (id < 0x1000) {
            s32 i;
            pl = F(u8 *, 0x2A8);
            if (((TLobby *)pl)->check_player_flag1() == 1 || (enable_v2_features == 1 && obj_testFlags30__13TUnk_804AF8A0FUl(pl, 0x20) != 0)) {
                F(s32, 0x318) = ill_gill_combat_parameter_variants[0];
                if (dist <= (rad + ((TObjPlayer *)(F(s32, 0x318)))->get_pos_x()) * (rad + ((TObjPlayer *)(F(s32, 0x318)))->get_pos_x()) &&
                    ang <= ((TObjPlayer *)(F(s32, 0x318)))->get_field_0c()) {
                    F(s32, 0x394) = 0;
                    bind_enemy_combat_stats((u8 *)0, (u8 *)(ill_gill_combat_parameter_variants[F(s32, 0x394)]), (u8 *)0);
                    return 1;
                }
                return 0;
            }
            for (i = 0; i < 4; i++) {
                f32 r2;
                s32 m;
                F(s32, 0x318) = ill_gill_combat_parameter_variants[i];
                r2 = (rad + ((TObjPlayer *)(F(s32, 0x318)))->get_pos_x()) * (rad + ((TObjPlayer *)(F(s32, 0x318)))->get_pos_x());
                m = ((TObjPlayer *)(F(s32, 0x318)))->get_field_0c();
                if (dist <= r2 && ang <= m) {
                    F(s32, 0x394) = i;
                    bind_enemy_combat_stats((u8 *)0, (u8 *)(ill_gill_combat_parameter_variants[F(s32, 0x394)]), (u8 *)0);
                    return 1;
                }
            }
        } else if (id < 0x4000) {
            F(s32, 0x318) = ill_gill_combat_parameter_variants[0];
            if (dist <= (rad + ((TObjPlayer *)(F(s32, 0x318)))->get_pos_x()) * (rad + ((TObjPlayer *)(F(s32, 0x318)))->get_pos_x()) &&
                ang <= ((TObjPlayer *)(F(s32, 0x318)))->get_field_0c()) {
                F(s32, 0x394) = 0;
                bind_enemy_combat_stats((u8 *)0, (u8 *)(ill_gill_combat_parameter_variants[F(s32, 0x394)]), (u8 *)0);
                return 1;
            }
        }
    }
    return 0;
}
#undef F

#define arg0 ((u8 *)arg0_)
void TObjEneIllGill::update_chase_target(void *arg0_) {
    f32 r;
    s32 id;
    f32 d;
    s32 a;
    f32 t;
    ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x04040000);
    r = *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4);
    id = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 8);
    advance_animation_playback(arg0);
    if (((TObjPlayer *)arg0)->target != NULL) {
        switch (((TObjPlayer *)arg0)->phase) {
        default:
        case 1:
            ((TObjPlayer *)arg0)->phase = 0;
        case 0: {
            Vec_80367588 dir;
            t = ((TObjPlayer *)arg0)->m_300 + TObjEneIllGill__data_805E02DC;
            ((TObjPlayer *)arg0)->m_300 = t;
            {
                Vec_80367588 tgt = *(Vec_80367588 *)(((TObjPlayer *)arg0)->target + 0x2FC);
                d = enemy_move_toward(arg0, id, &tgt, 0, lbl_805E02F0 * r, t);
            }
            VecCopy((Vec *)&dir, (const Vec *)(((TObjPlayer *)arg0)->target + 0x2FC));
            subtract_vector(&dir, arg0 + 0x2FC);
            a = angle_difference_abs(((TObjPlayer *)arg0)->rotation_y,
                                     (s32)(TObjEneIllGill__data_8047A348 * atan2_float(dir.x, dir.z)));
            if (a < ((TObjPlayer *)(((TObjPlayer *)arg0)->m_318))->get_field_0c()) {
                ((TObjPlayer *)arg0)->phase = 2;
            }
            break;
        }
        case 2: {
            t = ((TObjPlayer *)arg0)->m_300;
            ((TObjPlayer *)arg0)->m_300 = t + TObjEneIllGill__data_805E02DC;
            {
                Vec_80367588 tgt = *(Vec_80367588 *)(((TObjPlayer *)arg0)->target + 0x2FC);
                enemy_pursue_point(arg0, id, &tgt, r, lbl_805E02F4, t);
            }
            d = horizontal_distance_squared(arg0 + 0x29C, arg0 + 0x2FC);
            t = r + *(f32 *)((s8 *)(((TObjPlayer *)arg0)->m_a4) + 0xC);
            if (d < t * t) {
                if (*(u16 *)((s8 *)arg0 + 0x338) == 0xFFFF) {
                    ((TObjPlayer *)arg0)->target = NULL;
                } else {
                    ((TObjPlayer *)arg0)->phase = 0;
                }
            }
            break;
        }
        }
        t = *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 0);
        if (t * t < d) {
            ((TObjPlayer *)arg0)->target = NULL;
        }
        if (objInBand((GameObj *)arg0, (f32)TObjEneIllGill__data_805E02BC) != 0) {
            play_sound_effect(0x4003A34D, arg0 + 0x38, 0, 0);
        }
        if (objInBand((GameObj *)arg0, (f32)lbl_805E02F8) != 0) {
            play_sound_effect(0x4003A34D, arg0 + 0x38, 0, 0);
        }
    }
    ((TObjPlayer *)arg0)->update_collisions();
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
}
#undef arg0

void TObjEneIllGill::vfunc_59() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;
    temp_r0 = *(s16 *)((s8 *)arg0 + 0x326);
    if ((temp_r0 >= 3) || (temp_r0 < 1)) {
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        *(s16 *)((s8 *)arg0 + 0x326) = 2;
        *(s16 *)((s8 *)arg0 + 0x328) = 0;
        ((TUnk_804B9870 *)arg0)->obj_clearFlags30((int)(0x04040000U));
        ((TObjEneIllGill *)arg0)->free_resources();
    }
}

void TObjEneIllGill__sub_80367860(u8 *player) {
    Vec_80367860 v;
    f32 d;
    f32 a;
    f32 b;
    f32 *r;
    ((TObjPlayer *)player)->m_b8 = 0;
    advance_animation_playback(player);
    obj_setFlags30(player, 0x04040000);
    v.y = TObjEneIllGill__data_805E02BC;
    v.x = TObjEneIllGill__data_805E02BC;
    v.z = TObjEneIllGill__data_805E02CC;
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(0, *(void **)((s8 *)player + 0x60));
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrices(1);
    vec3_add_to(&v, player + 0x50);
    ((TObjPlayer *)player)->m_300 += TObjEneIllGill__data_805E02DC;
    d = step_toward_destination__10TObjPlayerFPvPvf(player, v, lbl_805E02B8 * (*(f32 **)((s8 *)player + 0x350))[1]);
    r = *(f32 **)((s8 *)player + 0x350);
    a = r[0] * r[0];
    b = r[1] * r[1];
    if (a < d || d < b) {
        *(s32 *)((s8 *)player + 0x2A8) = 0;
    }
    apply_actor_gravity(player, 0, TObjEneIllGill__data_805E02BC);
    minimap_render_dot(player + 0x38, -0x5DB4, 1, 0);
}

void TObjEneIllGill::run_attack_phase() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r4;

    advance_animation_playback(arg0);
    switch (this->phase) {
    case 0:
        obj_setFlags30(arg0, 0x04040000);
        TObjEneMe3SinowZoa__sub_800D758C((u8 *)&this->m_374);
        ((TBoss3Volopt *)(arg0 + 0x38))->play_area_se_with_particle();
        this->phase = 1;
        break;
    case 1:
        obj_setFlags30(arg0, 0x04040000);
        if (((IllGillVObj_80367984_8036690C *) (arg0 + 0x374))->m5() == 1) {
            this->phase = 2;
            this->m_b8 = 1;
            this->m_390 = 0;
        }
        break;
    case 2:
        ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x04040000);
        this->m_b8 = 1;
        if (horizontal_distance_squared((u8 *)&this->position, (u8 *)&this->m_50) > lbl_805E02C8) {
            move_toward_dest_with_detour();
        } else {
            this->m_300 = (f32) (this->m_300 + TObjEneIllGill__data_805E02DC);
            temp_r4 = (unsigned char *) (this->movementParameters);
            ((TObjEnemy *)arg0)->enemy_wander_home((*(s32 *)((s8 *)temp_r4 + 8)), (f32) (lbl_805E02E8 * *(f32 *)((s8 *)temp_r4 + 4)), lbl_805E02C4, lbl_805E02FC);
        }
        ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
        break;
    default:
        this->m_b8 = 0;
        if (!(this->actorFlags & 0x800000)) {
            apply_actor_gravity(arg0, 0, TObjEneIllGill__data_805E02BC);
        }
        break;
    }
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
    ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x200000);
}

extern void *tl_04;

typedef char RecoveredGlobal_80367DC8_lbl_8050BF00_size[sizeof(RecoveredGlobal_80367DC8_lbl_8050BF00) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_80367DC8_lbl_8058D490_size[sizeof(RecoveredGlobal_80367DC8_lbl_8058D490) == 0x30 ? 1 : -1];

#define TRY_80367B00(o, a) ((s32 (*)(u8 *, s32))sub_80367DC8__14TObjEneIllGillFl)(o, a)
void TObjEneIllGill::move_toward_dest_with_detour() {
    Obj_80367B00 *o = (Obj_80367B00 *)this;
    s32 ang;
    VecCopy((Vec *)&o->v29C, (const Vec *)&o->v50);
    VecCopy((Vec *)&o->v290, (const Vec *)&o->v2FC);
    VecCopy((Vec *)&o->prev, (const Vec *)&o->pos);
    VecCopy((Vec *)&lbl_8050BEE0, (const Vec *)&o->v50);
    subtract_vector(&lbl_8050BEE0, &o->pos);
    ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(lbl_8050BEE0.x, lbl_8050BEE0.z));
    if (TRY_80367B00((u8 *)o, ang) == 1) {
        o->fB8 = 1;
        VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
        o->f60 = approach_angle_limited(o->f60, ang, o->f350->f8);
    } else {
        if (fabs_float(lbl_8050BEE0.x) < fabs_float(lbl_8050BEE0.z)) {
            ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(lbl_8050BEE0.x, TObjEneIllGill__data_805E02BC));
        } else {
            ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(TObjEneIllGill__data_805E02BC, lbl_8050BEE0.z));
        }
        if (TRY_80367B00((u8 *)o, ang) == 1) {
            o->fB8 = 1;
            VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
            o->f60 = approach_angle_limited(o->f60, ang, o->f350->f8);
        } else {
            if (fabs_float(lbl_8050BEE0.x) < fabs_float(lbl_8050BEE0.z)) {
                ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(TObjEneIllGill__data_805E02BC, lbl_8050BEE0.z));
            } else {
                ang = (s32)(TObjEneIllGill__data_8047A348 * atan2_float(lbl_8050BEE0.x, TObjEneIllGill__data_805E02BC));
            }
            if (TRY_80367B00((u8 *)o, ang) == 1) {
                o->fB8 = 1;
                VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
                o->f60 = approach_angle_limited(o->f60, ang, o->f350->f8);
            } else {
                o->fB8 = 0;
            }
        }
    }
    enemy_turn_toward_dest(o, o->f350->f8);
    enemy_set_heading_velocity(o, o->f60, o->f350->f4);
    o->v2FC.y += TObjEneIllGill__data_805E02DC;
    move_with_wall_slide((u8 *)o);
}

void TObjEneIllGill__sub_80367DA4(s32 arg0) {
    O_80367DA4 *self = (O_80367DA4 *)arg0;
    s32 i;
    for (i = 0; i < 4; i++) {
        self->arr[i] = 0;
    }
}

void TObjEneIllGill::sub_80367DC8(s32 arg1) {
    *(f32 *)((s8 *)&lbl_8050BF00.value + 4) = (f32) TObjEneIllGill__data_805E02BC;
    *(f32 *)((s8 *)&lbl_8050BF00.value + 0) = (f32) TObjEneIllGill__data_805E02BC;
    *(f32 *)((s8 *)&lbl_8050BF00.value + 8) = (f32) *(f32 *)((s8 *)this->movementParameters + 4);
    push_matrix_from((void *)&identity_matrix.value);
    rotate_matrix_y(0, (void *)arg1);
    rotate_vector_by_matrix(0, (void *)&lbl_8050BF00.value, (void *)&lbl_8050BF00.value);
    pop_matrices(1);
    vec3_add_to((void *)&lbl_8050BF00.value, (void *) (((u8 *)this) + 0x38));
    project_actor_to_ground(this, (void *)&lbl_8050BF00.value, 0);
}

void TObjEneIllGill::vfunc_58() {
    switch (mode) {
    case 0:
        switch (phase) {
        case 0:
        case 1:
            break;
        default:
            phase = 2;
            if ((s32)m_390 != 0) {
                phase = 0;
            }
            break;
        }
        break;
    default:
        mode = 0;
        if ((s32)m_390 != 0) {
            phase = 0;
        } else {
            phase = 2;
        }
        m_b8 = 1;
        free_resources();
        break;
    }
}

typedef struct RecoveredFields_80367EFC_arg0 RecoveredFields_80367EFC_arg0;
s32 TObjEneIllGill::update_movement_status() {
    u8 *arg0 = (u8 *)this;
  if (update_movement_status__13TUnk_804806E8Fv((void *) arg0) != 0)
  {
    if (((RecoveredFields_80367EFC_arg0 *) arg0)->field_326 != 0)
    {
      if ((arg0 && arg0) && arg0)
      {
      }
    }
    else
    {
      ((RecoveredFields_80367EFC_arg0 *) arg0)->field_390 = 0;
      ((RecoveredFields_80367EFC_arg0 *) arg0)->field_328 = 0;
      ((RecoveredFields_80367EFC_arg0 *) arg0)->field_B8 = 1;
      ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x04040000);
    }
    return 1;
  }
  return 0;
}

typedef struct RecoveredFields_80367F6C_arg0 RecoveredFields_80367F6C_arg0;
s32 TObjEneIllGill::update_action_hold_status() {
    u8 *arg0 = (u8 *)this;
  if (0 != update_action_hold_status__13TUnk_804806E8Fv((void *) arg0))
  {
    if (((RecoveredFields_80367F6C_arg0 *) arg0)->field_326 != 0)
    {
      if (((!arg0) && (!arg0)) && (!arg0))
      {
      }
    }
    else
    {
      ((RecoveredFields_80367F6C_arg0 *) arg0)->field_390 = 0;
      ((RecoveredFields_80367F6C_arg0 *) arg0)->field_328 = 0;
      ((RecoveredFields_80367F6C_arg0 *) arg0)->field_B8 = 1;
      ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x04040000);
    }
    return 1;
  }
  return 0;
}

#pragma push
#pragma opt_loop_invariants off
void TObjEneIllGill::vfunc_28() {
    u16 best;
    s32 i;
    u8 *pl;
    u16 id;
    f32 bestDist;
    f32 d;
    u16 t;
    s32 ent;
    s32 x;
    if (((Gill_80367FDC *)this)->m17(0x1E) != 0) {
        if (((Gill_80367FDC *)this)->f390 != 0) {
            ((Gill_80367FDC *)this)->f338 = 0xFFFF;
            ((Gill_80367FDC *)this)->f2A8 = 0;
            return;
        }
        if (obj_testFlags30__13TUnk_804AF8A0FUl(((Gill_80367FDC *)this), 0x10) != 0) {
            i = 0;
            best = 0xFFFF;
            Vec_80367FDC v = lbl_8047A328;
            bestDist = *((Gill_80367FDC *)this)->f350 * *((Gill_80367FDC *)this)->f350;
            for (; i < lbl_805D586C + lbl_805D5870; i++) {
                pl = get_player_data__10TObjPlayerFi(i);
                if (pl == NULL) break;
                if (obj_is_hit_receivable(pl) == 0) continue;
                id = obj_getField1c(pl);
                if (id >= 0x4000) continue;
                if (id == ((Gill_80367FDC *)this)->f1C) continue;
                if (*(s32 *)((s8 *)pl + 0x30) & 0x02000800) continue;
                VecCopy((Vec *)&v, (const Vec *)(pl + 0x2FC));
                subtract_vector(&v, (u8 *)((Gill_80367FDC *)this) + 0x2FC);
                d = v.x * v.x + v.z * v.z;
                if (d < bestDist && check_path_obstructed(((Gill_80367FDC *)this), pl + 0x2FC) == 0) {
                    best = id;
                    bestDist = d;
                }
            }
            ((Gill_80367FDC *)this)->f338 = best;
        } else {
            ((Gill_80367FDC *)this)->f338 = find_nearest_visible_player(((Gill_80367FDC *)this), 0, ((Gill_80367FDC *)this)->f350, *((Gill_80367FDC *)this)->f350);
        }
        t = ((Gill_80367FDC *)this)->f338;
        if (t < 0x1000) {
            ent = get_player_by_client_id(t);
            if (ent != 0) {
                if (((TObjPlayer *)ent)->get_field_3e4() == get_current_floor()) {
                    ((Gill_80367FDC *)this)->f2A8 = ent;
                    obj_clearFlags30(0x04040000);
                    return;
                }
            }
            ((Gill_80367FDC *)this)->f2A8 = 0;
            obj_setFlags30(((Gill_80367FDC *)this), 0x04040000);
            return;
        }
        if (t < 0x4000) {
            ((Gill_80367FDC *)this)->f2A8 = get_enemy_entity(t);
            obj_clearFlags30(0x04040000);
        }
    }
}
#pragma pop

struct VBase_18_80368208 { char pad[0x18]; };
struct VObj_18_80368208 : VBase_18_80368208 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8();
    virtual s32 m9(f32, f32, f32);
};
struct VBase_14_80368208 { char pad[0x14]; };
struct VObj_14_80368208 : VBase_14_80368208 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
};
void select_actor_lighting(s32 obj);
void scale_matrix(int, f32, f32, f32);
void push_matrix(void);
s32 pop_matrix(void);
void post_translate_matrix(void *);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805E0300;
extern const f32 lbl_805E0304;
void TObjEneIllGill::render() {
    u8 *arg0 = (u8 *)this;

    if (((s32 (*)(void *))is_split_screen)(arg0) != 0) {
        TCameraCtrl::get_camera_mode();
    }
    *(s32 *)&this->m_3a8 = ((VObj_18_80368208 *)arg0)->m9(lbl_805E0300, lbl_805E0304, lbl_805E02F4);
    if (*(s32 *)&this->m_3a8 != 0) {
        select_actor_lighting((s32)arg0);
        TObjFish::set_global_param(this->texture_id);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        ((void (*)(int, s32))rotate_matrix_y)(0, this->rotation_y);
        scale_matrix(0, this->scale, this->target_scale, *(f32 *)((s8 *)arg0 + 0x70));
        TObjEneIllGill__data_805D6FE0 = 0;
        TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneIllGill::advance_camera_vec_stage));
        if (*(s32 *)&this->m_390 != 0 && TObjPlayer::check_demo_mode() == 0) {
            if (((VObj_14_80368208 *)(arg0 + 0x374))->m8() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                ((VObj_14_80368208 *)(arg0 + 0x374))->m6();
                ((TObjMotion *)arg0)->draw();
                ((VObj_14_80368208 *)(arg0 + 0x374))->m7();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
        } else if (*(s32 *)&this->m_3a8 == 1) {
            ((TObjMotion *)arg0)->draw();
        } else {
            ((TObjEnemy *)arg0)->render_world_model();
        }
        TObjEneRe7Berura::set_global_state((s32)NULL);
        VecCopy((Vec *)(arg0 + 0x3B0), (const Vec *)&TObjEneIllGill__camera_vec_table);
        VecCopy((Vec *)(arg0 + 0x3BC), (const Vec *)&lbl_80543A6C);
        VecCopy((Vec *)(arg0 + 0x3C8), (const Vec *)&lbl_80543A78);
        VecCopy((Vec *)(arg0 + 0x3D4), (const Vec *)&lbl_80543A84);
        pop_matrix();
    }
}
void TObjEneIllGill::run_task() {
    Gill_803683BC *o = (Gill_803683BC *)this;
    switch (o->x326) {
    case 0:
        run_attack_phase();
        break;
    case 1:
        TObjEneIllGill__sub_80367860((u8 *)o);
        break;
    case 2:
        TObjEneIllGill::update_chase_target(o);
        break;
    case 3:
        TObjEneIllGill__sub_80366AE4((u8 *)o);
        break;
    case 4:
        update_ai();
        break;
    case 5:
        TObjEneIllGill__sub_803660A4(o);
        break;
    case 6:
        TObjEneIllGill__sub_803669B0((u8 *)o);
        break;
    case 7:
        TObjEneIllGill__sub_803667B8((u8 *)o);
        break;
    case 8:
        update_death_fall();
        break;
    case 9:
        break;
    }
    if (o->x2a8 != NULL && (o->x2a8->flags & 0x02000800)) {
        o->x39c = 0;
        o->flags &= ~0x200000;
        o->x2a8 = NULL;
    }
    ((TObjEnemy *)o)->update_prev_position();
    ((TBoss3VoloptHiraisin *)o)->copy_position();
    submit_cursor_candidate(o, -1);
    o->x2b4 += TObjEneIllGill__data_805E02CC;
}

void *TObjEneIllGill::create() {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x420);
    if (o2 != NULL) {
        o2 = TObjEneIllGill__ct((u8 *)o2, (s32)o, (u8 *)this);
    }
    return o2;
}

void *__dt__14TObjEneIllGillFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TObjEneIllGill;
        ((TObjEneIllGill *)arg0)->free_resources();
        free_collision_body_parts(arg0);
        __dt__13TUnk_80494938Fv((s8 *)arg0 + 0x374, -1);
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define G6FD0 ((u8 *)TObjEneIllGill__shared_effect)
u8 *TObjEneIllGill__ct(u8 *self, s32 arg1, u8 *arg2) {
    __ct__9TObjEnemyFP7TObject(self, arg1, arg2);
    FIG_8036858C(void *, 0x18) = __vt__14TObjEneIllGill;
    ((TUnk_80494938 *)(self + 0x374))->init_common();
    FIG_8036858C(s32, 0) = TObjEneIllGill_class_name;
    ((TObjEnemy *)self)->set_param(0x52);
    ((VObj_18_8036858C *)self)->m79(arg2);
    ((VObj_18_8036858C *)self)->m80();
    ((TObjPlayer *)self)->init_position_vectors();
    apply_actor_gravity(self, 0, TObjEneIllGill__data_805E02BC);
    FIG_8036858C(s32, 0x34) = *(s32 *)(*(u8 **)(G6FD0 + 0x42C) + 8);
    FIG_8036858C(s32, 0x24) = *(s32 *)(*(u8 **)(G6FD0 + 0x42C) + 0xC);
    FIG_8036858C(s32, 0xDC) = *(s32 *)(G6FD0 + 0x430);
    FIG_8036858C(void *, 0xD8) = lbl_804F2E84;
    ((TObjMotion *)self)->set_field_d8(FIG_8036858C(s32, 0xD8));
    FIG_8036858C(s16, 0xB8) = 0;
    ((TObjMotion *)self)->set_animation(FIG_8036858C(s16, 0xB8));
    ((TObjMotion *)self)->set_field_b8(FIG_8036858C(s16, 0xB8));
    ((TObjEnemy *)self)->sub_8002AE64();
    FIG_8036858C(f32, 0x68) = lbl_805E0308;
    FIG_8036858C(f32, 0x6C) = lbl_805E0308;
    FIG_8036858C(f32, 0x70) = lbl_805E0308;
    ((TUnk_804806E8 *)self)->add_flags_2e4(8);
    init_collision_body_parts(self, lbl_804F2F40, 1);
    ((TObjEnemy *)self)->update_prev_position();
    ((TBoss3VoloptHiraisin *)self)->copy_position();
    ((TObjPlayer *)self)->reset_photon_effect();
    FIG_8036858C(void *, 0x350) = lbl_804F2F24;
    FIG_8036858C(s32, 0x394) = 0;
    ((TObjEnemy *)self)->bind_enemy_combat_stats((u8 *)TObjEneIllGill__boss_registration_id, (u8 *)(((s32 *)ill_gill_combat_parameter_variants)[FIG_8036858C(s32, 0x394)]), (u8 *)lbl_805D6FD8);
    FIG_8036858C(s32, 0x3A0) = 0;
    FIG_8036858C(s16, 0x326) = 0;
    FIG_8036858C(s16, 0x328) = 0;
    FIG_8036858C(s32, 0x398) = 0;
    FIG_8036858C(s32, 0x3A4) = 0;
    FIG_8036858C(f32, 0x3B8) = TObjEneIllGill__data_805E02BC;
    FIG_8036858C(f32, 0x3B4) = TObjEneIllGill__data_805E02BC;
    FIG_8036858C(f32, 0x3B0) = TObjEneIllGill__data_805E02BC;
    FIG_8036858C(f32, 0x3C4) = TObjEneIllGill__data_805E02BC;
    FIG_8036858C(f32, 0x3C0) = TObjEneIllGill__data_805E02BC;
    FIG_8036858C(f32, 0x3BC) = TObjEneIllGill__data_805E02BC;
    FIG_8036858C(f32, 0x3D0) = TObjEneIllGill__data_805E02BC;
    FIG_8036858C(f32, 0x3CC) = TObjEneIllGill__data_805E02BC;
    FIG_8036858C(f32, 0x3C8) = TObjEneIllGill__data_805E02BC;
    FIG_8036858C(f32, 0x3DC) = TObjEneIllGill__data_805E02BC;
    FIG_8036858C(f32, 0x3D8) = TObjEneIllGill__data_805E02BC;
    FIG_8036858C(f32, 0x3D4) = TObjEneIllGill__data_805E02BC;
    FIG_8036858C(s32, 0x41C) = 0;
    FIG_8036858C(s32, 0x418) = 0;
    FIG_8036858C(s32, 0x414) = 0;
    FIG_8036858C(f32, 0x3AC) = TObjEneIllGill__data_805E02BC;
    FIG_8036858C(s32, 0x410) = 0;
    FIG_8036858C(s32, 0x3A8) = 0;
    ((VSub_8036858C *)(self + 0x374))->m3();
    FIG_8036858C(s32, 0x390) = 1;
    TObjEneIllGill__sub_80367DA4((s32)self);
    if (TObjEneIllGill__data_805E02BC != FIG_8036858C(f32, 0x354)) {
        FIG_8036858C(u32, 0x30) |= 0x2000;
        FIG_8036858C(s32, 0x2A8) = 0;
        FIG_8036858C(u16, 0x338) = 0xFFFF;
        VecCopy((Vec *)(self + 0x290), (const Vec *)(self + 0x2FC));
        VecCopy((Vec *)(self + 0x29C), (const Vec *)(self + 0x2FC));
        FIG_8036858C(f32, 0x3AC) = TObjEneIllGill__data_805E02BC;
    }
    return self;
}
#undef FIG_8036858C

void TObjEneIllGill::free_effect() { TLobby__sub_8001FE7C((void*)TObjEneIllGill__shared_effect, (void*)1); TObjEneIllGill__shared_effect = 0;
 }

struct Pos_80368818 { s32 w[4]; };
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern Pos_80368818 lbl_8047A318;
void TObjEneIllGill::load_shared_resources() {
    void *p;
    u8 *area;
    s32 *arr;
    Vec_80368818 *q;

    p = (void *)((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
    if (p != NULL) {
        p = load_resource_from_descriptor(p, 1, lbl_804F2E74, 0, 0, 0);
    }
    TObjEneIllGill__shared_effect = (int)p;
    TObjEneIllGill__boss_registration_id = register_boss__6TLobbyFl(0x26);
    ill_gill_combat_parameter_variants[0] = dispatch_shared_handler_b__6TLobbyFl(0x26);
    ill_gill_combat_parameter_variants[1] = dispatch_shared_handler_b__6TLobbyFl(0x27);
    ill_gill_combat_parameter_variants[2] = dispatch_shared_handler_b__6TLobbyFl(0x28);
    ill_gill_combat_parameter_variants[3] = dispatch_shared_handler_b__6TLobbyFl(0x29);
    lbl_805D6FD8 = register_object__6TLobbyFl(0x26);
    TObjEneIllGill__data_805D6FDC = (u8 *)TLobby::dispatch_shared_handler_a(0x26);
    TObjEneIllGill__data_805D6FE0 = 0;
    q = &TObjEneIllGill__camera_vec_table;
    q->x = q->y = q->z = TObjEneIllGill__data_805E02BC;
    q = &lbl_80543A6C;
    q->x = q->y = q->z = TObjEneIllGill__data_805E02BC;
    q = &lbl_80543A78;
    q->x = q->y = q->z = TObjEneIllGill__data_805E02BC;
    q = &lbl_80543A84;
    q->x = q->y = q->z = TObjEneIllGill__data_805E02BC;
    {
        Pos_80368818 pos = lbl_8047A318;
        area = (u8 *)TObjEneIllGill__shared_effect;
        pos.w[0] = *(s32 *)(area + 0x430);
        TLobby::spawn_npc_enemy((s16)0x43, (s32)(*(s32 *)(*(u8 **)(area + 0x42C) + 8)), (s32)(*(s32 *)(*(u8 **)(area + 0x42C) + 0xC)), (s32)&pos, (f32)(*(f32 *)((u8 *)lbl_804F2F40 + 0xC)), (f32)TObjEneIllGill__data_805E02BC);
    }
}

}
