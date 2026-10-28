#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TBreakUpMdl.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneDubchik.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"
#define lbl_805D9ADC 2.0f
#define lbl_805D9AE0 0.0f
#define lbl_805D9AE4 100.0f
#define lbl_805D9AE8 6.0f
#define lbl_805D9AEC 7.0f

struct Vec_800A9C38 { f32 x, y, z; };
struct VBase_800AA704 { u8 pad[0xC]; };
struct VObj_800AA704 : VBase_800AA704 {
    virtual ~VObj_800AA704();
};

struct VBase_18_fe09eb { char pad[0x18]; };

struct VObj_18_fe09eb : VBase_18_fe09eb {
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
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual s32 m63(s32, void *);
};

struct Mdl_800AA82C { u8 pad[8]; s32 f8; s32 fC; };

struct Res_800AA82C { u8 pad[0x42C]; Mdl_800AA82C *mdl; s32 f430; };

struct Node_800AA82C { u32 flags; u8 pad[0x30 - 4]; s32 f30; };

struct Desc_800AA82C { s32 a; void *b; s32 c; s32 d; };

extern "C" {
void enemy_set_heading_velocity(TObjEnemy *arg0, s32 arg1, f32 farg0);
s32 check_path_obstructed(void *, void *);
s32 TObjPlayer__sub_800AAF98(void *, s32);
extern const f32 lbl_805D9AFC;
extern const f32 lbl_805D9B04;
extern const f32 lbl_805D9B08;
extern const f32 lbl_805D9B0C;
void apply_actor_gravity(TObjEnemy *arg0, s32 *arg1, f32 farg0);
s32 enemy_turn_toward_dest(void *, s32);
void queue_destruction__7TObjectFv(void *arg0);
void *create_particle_emitter(void *pos, s32 id);
s32 __ct__13TUnk_80491460FPvlll(void *, void *, s32, void *, s32);
s32 render_anim_model_at_pos__15TObjEnemyCustomFv();
s32 copy_target_state__14TObjEnePanarmsFPv(void *, s32);
s32 advance_animation_playback(void *);
void check_enemy_body_collisions(void *arg0);
s32 play_sound_effect(s32, void *, int, int);
void *__nw__7TObjectFUl(int);
void TObjPlayer__sub_800A8FB4(void *arg0_);

void TLobby__sub_8001FE7C(void *, s32);
s32 *__dt__11TBoss4Type3FPvs(s32 *arg0, s16 arg1);
extern s32 lbl_80500AF0[];
extern s32 lbl_80500AF8[];
struct Res_800AA82C;
extern Res_800AA82C *lbl_805D5090;
extern s32 lbl_805D5094;
extern s32 lbl_805D5098;
extern void *breakup_model_ptr;

s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
s32 get_bml_motion(void *, int);
s32 get_bml_model(void *, int);
void *load_resource_from_descriptor(void *, int, void *, int, int, int);
void TObjPlayer__sub_800A4294(void);
Res_800AA82C *load_enemy_bml_resource_named(void *, void *);
void draw_trail_with_colors(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void *init_trail_buffer__11TBoss4Type3FPvifff(void *, int, f32, f32, f32);
u8 *load_gvm_texture_file(s32 arg0);
void spawn_npc_enemy__6TLobbyFslllff(int, int, int, void *, f32, f32);
extern u8 lbl_8043ACA4[];
extern u8 lbl_8043ACBC[];
extern u8 lbl_8043ACD0[];
extern u8 bm_ene_dubchik_resource_descriptor[];
extern s16 player_model_node_index_pair[];
extern Node_800AA82C *lbl_805D509C;
extern Node_800AA82C *lbl_805D50A0;
extern const f32 lbl_805D9AF0;
extern const f32 lbl_805D9B10;
extern const f32 lbl_805D9B20;
extern const f32 lbl_805D9B34;
extern const f32 lbl_805D9B38;
extern const f32 lbl_805D9B3C;
extern const f32 lbl_805D9B40;
extern const f32 lbl_805D9B44;
extern const f32 lbl_805D9B48;
extern const f32 lbl_805D9B4C;
void TObjPlayer__sub_800AA82C(void);
}
#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define PADV virtual void CAT(pv, __LINE__)();
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();
struct Base_Sub { char pad[0x14]; };
struct V_Sub : Base_Sub {
    PADV4
    PADV
    virtual s32 m5();
};
struct RecoveredGlobal_800A8B8C_lbl_804910F4
{
  s32 value;
  u8 remaining[0x168];
};

struct Obj_800AA528 { u8 pad0[0x326]; s16 state; };

struct Obj_800A8A7C { u8 pad[0x388]; u32 flags; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Vec_800A8C4C { s32 x, y, z; };

struct Obj_800A8A7C;
struct VBase_14_fddec9 { char pad[0x14]; };

struct VObj_14_fddec9 : VBase_14_fddec9 {
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

struct VBase_18_ca64a0 { char pad[0x18]; };

struct VObj_18_ca64a0 : VBase_18_ca64a0 {
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

struct Self_800AA334 { u8 pad[0x3B0]; VObj_14_fddec9 sub; };

struct Vec_800AA334 { s32 x, y, z; };

typedef struct Vec_800A9E9C { f32 x, y, z; } Vec_800A9E9C;

extern "C" {
s32 TObjEneMe3SinowZoa__sub_800D758C(void *);
void TBoss3Volopt__sub_800D8D88(s32 arg0);
void TObjPlayer__sub_800A8E04(u8 *arg0);
void obj_setFlags30(void *, u32);
void TObjPlayer__sub_800A8C1C(u8 *arg0);
s32 find_active_entity_by_id(u16);
void TObjPlayer__sub_800AA330(void *);
s32 submit_cursor_candidate(void *, s32);
s32 minimap_render_dot(void *, s32, s32, s32);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(void *, s32);
void *TObjControl__ct(void *, void *);
void *TObjEneDubchik__ct(void *, void *, void *);
extern void *tl_04;
s32 TObjPlayer__sub_800AAFF0(int);
extern RecoveredGlobal_800A8B8C_lbl_804910F4 lbl_804910F4;
void TObjPlayer__sub_800A93E4(void *);
void TObjPlayer__sub_800A9C38(void *);
void TObjPlayer__sub_800A9718(void *);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 calc_velocity_toward_destination(void *, Vec_800A8C4C, Vec_800A8C4C, f32);
extern s32 lbl_804910E4[];
extern s32 lbl_804910EC[];
void TObjPlayer__sub_800A8C4C(u8 *arg0);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
s32 defer_render__7TObjectFv(void *);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_chunk_object(void *child);
extern s32 lbl_8043AC78[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D9B24;
extern const f32 lbl_805D9B28;
extern const f32 lbl_805D9B2C;
extern const f32 lbl_805D9B30;
void TObjPlayer__sub_800AA334(u8 *arg0);
f32 calc_boss4_scale__10TObjPlayerFi(s32 arg0);
s32 find_target_in_range__15TObjEnemyCustomFf(void *, f32);
extern const f32 lbl_805D9B14;
extern const f32 lbl_805D9B18;
extern const f32 lbl_805D9B1C;
s32 update_enemy_wander_move(void *, Vec_800A9E9C *, s32, f32);
s32 sub_8004292C__15TObjEnemyCustomFv();
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void TObjPlayer__sub_800A9E9C(void *arg0_);
s32 update_shock_clock__13TUnk_804806E8Fv();
s32 update_movement_status__13TUnk_804806E8Fv();

struct Ids_800AA82C { s16 v[2]; };
const Ids_800AA82C lbl_805D9AD8 = {{0x1E, 0x1F}};
__declspec(section ".data") s32 lbl_805009A0[2];
__declspec(section ".data") s32 lbl_805009A8[2];
__declspec(section ".data") s32 lbl_805009B0[2];
s32 lbl_805009B8[20];
u8 lbl_80500A08[0x10];
u8 lbl_80500A18[0x30];
u8 lbl_80500A48[0xA8];
__declspec(section ".data") s32 lbl_80500AF0[2];
__declspec(section ".data") s32 lbl_80500AF8[2];

#define lbl_805009A0 ((u8 *)lbl_805009A0)

void TObjPlayer::set_flag_start_effect() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;

    temp_r3 = *(s32 *)&this->unk_388;
    if (!(temp_r3 & 0x04000000)) {
        *(s32 *)&this->unk_388 = (s32) (temp_r3 | 0x04000000);
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 | 1);
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 & 0xFF7FFFFF);
        *(s16 *)&this->unk_33C = 0x1E;
        TObjPlayer::create_dead_spot((s32)(arg0 + 0x2FC), (s32)(*(s16 *)&this->unk_33C), (f32)lbl_805D9ADC);
    }
}

void TObjPlayer::clear_state7_flag() {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_374 == 7) {
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 & 0xFFFFFFFE);
        ((TObjEneMe1GiGue *)arg0)->update_if_active(0);
    }
}

s32 TObjPlayer::try_apply_800a89b0() {
    s32 arg0 = (s32)this;
    if (update_movement_status__13TUnk_804806E8Fv() != 0) {
        clear_state7_flag();
        return 1;
    }
    return 0;
}

s32 TObjEneDubchik::update_shock_clock() {
    s32 arg0 = (s32)this;
    if (update_shock_clock__13TUnk_804806E8Fv() != 0) {
        ((TObjPlayer *)arg0)->clear_state7_flag();
        return 1;
    }
    return 0;
}

void TObjEneDubchik::sub_800A8A7C() {
    u8 *g = lbl_805009A0;
    if (((Obj_800A8A7C *)this)->flags & 0x20000) {
        hide_model_nodes((NJS_OBJECT **)(g + 0x68));
    } else {
        show_model_nodes((NJS_OBJECT **)(g + 0x68));
    }
    if (((Obj_800A8A7C *)this)->flags & 0x40000) {
        hide_model_nodes((NJS_OBJECT **)(g + 0x78));
    } else {
        show_model_nodes((NJS_OBJECT **)(g + 0x78));
    }
    if (((Obj_800A8A7C *)this)->flags & 0x80000) {
        hide_model_nodes((NJS_OBJECT **)(g + 0xA8));
    } else {
        show_model_nodes((NJS_OBJECT **)(g + 0xA8));
    }
}

void TObjPlayer::render_model_and_set_attach_points() {
    render_anim_model_at_pos__15TObjEnemyCustomFv();
    this->get_anim_node_position(0x13, (Vec *)&this->unk_3D4);
    this->get_anim_node_position(0x28, (Vec *)&this->unk_3E0);
    this->get_anim_node_position(0x29, (Vec *)&this->m_3ec);
}

typedef struct RecoveredGlobal_800A8B8C_lbl_804910F4 RecoveredGlobal_800A8B8C_lbl_804910F4;
typedef char RecoveredGlobal_800A8B8C_lbl_804910F4_size[((sizeof(RecoveredGlobal_800A8B8C_lbl_804910F4)) == 0x16C) ? (1) : (-1)];
void TObjEneDubchik::sub_800A8B8C() {
  s32 *var_r4;
  s32 *var_r5;
  f32 temp_f1;
  f32 temp_f1_2;
  u8 *var_r31;
  u8 *var_r3;
  var_r4 = (s32 *) ((u8 *) 0);
  var_r31 = (u8 *) this;
  var_r4 = (s32 *)&lbl_804910F4.value;
  var_r3 = (u8 *) var_r31;
  var_r5 = (s32 *)&lbl_804910F4.value;
  var_r4 = (s32 *) ((u8 *) ((s32 *) 3));
  *((f32 *) (((s8 *)&lbl_804910F4.value) + 0x28)) = this->sub_800AAF78(0);
  temp_f1 = ((TObjEneDubchik *)var_r3)->sub_800AAF78(3);
  var_r5 = (var_r4 = (s32 *)&lbl_804910F4.value);
  var_r3 = (u8 *) var_r31;
  var_r4 = (s32 *) ((u8 *) ((s32 *) 4));
  *((f32 *) (((s8 *)&lbl_804910F4.value) + 0x78)) = temp_f1;
  temp_f1_2 = ((TObjEneDubchik *)var_r3)->sub_800AAF78(4);
  var_r4 = (s32 *)&lbl_804910F4.value;
  var_r3 = (u8 *) var_r31;
  var_r5 = (s32 *)&lbl_804910F4.value;
  var_r4 = (s32 *) ((u8 *) ((s32 *) 1));
  *((f32 *) (((s8 *)&lbl_804910F4.value) + 0xC8)) = temp_f1_2;
  if ((s16) (*((s16 *) (((s8 *) var_r31) + 0x392))))
  {
    var_r4 = (s32 *) ((u8 *) ((s32 *) 5));
  }
  ((TObjEneDubchik *)var_r3)->sub_800AAF78((s32) var_r4);
  var_r3 = (u8 *) (*((u8 **) (((s8 *) var_r31) + 0x318)));
  TObjPlayer__sub_800AAFF0((int) var_r3);
}

void TObjPlayer__sub_800A8C1C(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x388) = (s32) (*(s32 *)((s8 *)arg0 + 0x388) | 0x02000000);
    obj_setFlags30(arg0, 0x800U);
}

void TObjPlayer__sub_800A8C4C(u8 *arg0) {
    f32 var_f31;
    s32 var_r0;
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case -1:
        break;
    case 0:
        if (TObjEneDD::check_v2_mode() == 0) {
            if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
                var_r0 = 7;
            } else {
                var_r0 = *(s32 *)((s8 *)((u8 *)lbl_804910EC + (*(s32 *)((s8 *)arg0 + 0x368) * 4)) + 0);
            }
            *(s16 *)((s8 *)arg0 + 0xB8) = (s16) var_r0;
        } else {
            *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        }
        VecCopy((Vec *)((u8 *)arg0 + 0x29C), (const Vec *)((u8 *)arg0 + 0x50));
        *(s32 *)((s8 *)arg0 + 0x37C) = 1;
        return;
    case 1:
        advance_animation_playback((void *)arg0);
        apply_actor_gravity((TObjEnemy *)((u8 *)((void *)arg0)), (s32 *)(0), (f32)lbl_805D9AE0);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions((arg0));
        if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
            var_f31 = ((TObjEneDubchik *)arg0)->sub_800AAF78(2);
        } else {
            var_f31 = *(f32 *)((s8 *)((u8 *)lbl_804910E4 + (*(s32 *)((s8 *)arg0 + 0x368) * 4)) + 0);
        }
        VecCopy((Vec *)((u8 *)arg0 + 0x290), (const Vec *)((u8 *)arg0 + 0x2FC));
        calc_velocity_toward_destination((void *)arg0, *(Vec_800A8C4C *)(arg0 + 0x290), *(Vec_800A8C4C *)(arg0 + 0x29C), var_f31);
        ((TObjPlayer *)arg0)->update_angle((s32)((void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 8))), (void *)((u8 *)arg0 + 0x308));
        move_with_wall_slide((arg0));
        if (xz_distance_squared((Vec *)((u8 *)arg0 + 0x38), (Vec *)((u8 *)arg0 + 0x50)) < lbl_805D9AE4) {
            *(s16 *)((s8 *)arg0 + 0xB8) = 5;
            advance_animation_playback((void *)arg0);
            *(s32 *)((s8 *)arg0 + 0x388) = (s32) (*(s32 *)((s8 *)arg0 + 0x388) & 0xFE7FFFFF);
            ((TObjEneMe1GiGue *)arg0)->update_if_active(0);
        }
        return;
    }
}

void TObjPlayer__sub_800A8E04(u8 *ene_me1_gi_gue) {
    switch (((TObjEneMe1GiGue *)ene_me1_gi_gue)->state) {
    case 0:
        ((TObjEneMe1GiGue *)ene_me1_gi_gue)->m_388 = (s32) (((TObjEneMe1GiGue *)ene_me1_gi_gue)->m_388 | 4);
        ((TObjEneMe1GiGue *)ene_me1_gi_gue)->actorFlags = (((TObjEneMe1GiGue *)ene_me1_gi_gue)->actorFlags | 0x04000000);
        ((TObjEneMe1GiGue *)ene_me1_gi_gue)->m_b8 = 5;
        advance_animation_playback(ene_me1_gi_gue);
        TBoss3Volopt__sub_800D8D88((s32)(ene_me1_gi_gue + 0x2FC));
        TObjEneMe3SinowZoa__sub_800D758C(ene_me1_gi_gue + 0x3B0);
        ((TObjEneMe1GiGue *)ene_me1_gi_gue)->state = 1;
    case 1:
        if (((V_Sub *) (ene_me1_gi_gue + 0x3B0))->m5() == 1) {
            ((TObjEneMe1GiGue *)ene_me1_gi_gue)->state = -1;
        }
        return;
    case -1:
        ((TObjEneMe1GiGue *)ene_me1_gi_gue)->m_388 = (s32) ((((TObjEneMe1GiGue *)ene_me1_gi_gue)->m_388) & ~5);
        ((TObjEneMe1GiGue *)ene_me1_gi_gue)->actorFlags = (s32) (((TObjEneMe1GiGue *)ene_me1_gi_gue)->actorFlags & 0xFBFFFFFF);
        ((TObjEneMe1GiGue *)ene_me1_gi_gue)->update_if_active(0);
        break;
    }
}
void TObjPlayer::update_timed_state() {
    s16 temp_r4;
    switch (this->m_37c) {
    case 0:
        *(s16 *)&this->m_b8 = (s16) ((*(u32 *)&this->unk_388 & 0x1000000) ? 0 : 5);
        *(u32 *)&this->unk_388 = (u32) (*(u32 *)&this->unk_388 | 0x800000);
        this->m_37c = 1;
    case 1:
        if (!(this->actorFlags & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), lbl_805D9AE0);
        }
        if (this->actorFlags & 0x40000) {
            temp_r4 = *(s16 *)&this->unk_33C;
            *(s16 *)&this->unk_33C = (temp_r4 - 1);
            if (temp_r4 < 0) {
                this->m_37c = -1;
            }
        }
        break;
    case -1:
        this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
        *(s16 *)&this->unk_33C = (s16) *(s16 *)((s8 *)this + 0x33A);
        break;
    }
}
struct Vec_800A93E4 { f32 x, y, z; };
struct Pair_800A93E4 { s32 a, b; };
struct VB_800A93E4 { u8 pad[0x18]; };
struct VO_800A93E4 : VB_800A93E4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(Vec_800A93E4 *, Vec_800A93E4 *);
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
    virtual void m20(void *, f32);
    virtual void m21(void *, Pair_800A93E4 *, s32, s32, s32);
    virtual void m22();
    virtual void m23(void *, f32);
};
struct Params_800A93E4 { u8 pad[8]; s32 turn; };
struct Ene_800A93E4 {
    u8 pad0[0x30];
    s32 flags;
    u8 pad34[4];
    Vec_800A93E4 pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xB4 - 0x64];
    u32 fb4;
    s16 fb8;
    u8 padba[0xC0 - 0xBA];
    f32 fc0;
    u8 padc4[0x29C - 0xC4];
    Vec_800A93E4 dest;
    VO_800A93E4 *target;
    u8 pad2ac[0x350 - 0x2AC];
    Params_800A93E4 *params;
    u8 pad354[0x368 - 0x354];
    s32 f368;
    u8 pad36c[0x37C - 0x36C];
    s32 state;
    u8 pad380[0x392 - 0x380];
    s16 kind;
    u8 pad394[0x398 - 0x394];
    u32 f398;
    u32 f39c;
    u8 pad3a0[0x3AC - 0x3A0];
    VO_800A93E4 *model;
};

s32 mult_vec_array__10TObjPlayerFUll(int, u32, void *, int);
void set_matrix_identity(u8 *arg0);
extern f32 player_band_threshold_table[];
extern Pair_800A93E4 lbl_8043AC9C[];

void TObjPlayer__sub_800A8FB4(void *arg0_) {
    u8 *arg0 = (u8 *)arg0_;
    s32 r;
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case 0:
        if (*(u32 *)((s8 *)arg0 + 0x39C) != 0U) {
            ((TObjEneMe1GiGue *)arg0)->update_if_active(1);
            *(s32 *)((s8 *)arg0 + 0x37C) = -1;
            break;
        }
        *(s16 *)((s8 *)arg0 + 0x38E) = (s16) *(f32 *)((s8 *)arg0 + 0x354);
        if (*(s16 *)((s8 *)arg0 + 0x38E) == 0) {
            *(s16 *)((s8 *)arg0 + 0x38E) = 2;
        }
        {
            s16 v = 8;
            if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
                v = 9;
            }
            *(s16 *)((s8 *)arg0 + 0xB8) = v;
        }
    case 1:
        if (*(s16 *)((s8 *)arg0 + 0x38E) == 1) {
            s16 v = 0x11;
            if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
                v = 0x12;
            }
            *(s16 *)((s8 *)arg0 + 0xB8) = v;
        }
        *(s32 *)((s8 *)arg0 + 0x37C) = 2;
    case 2:
        if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
            VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
            enemy_turn_toward_dest(arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 8));
        }
        advance_animation_playback(arg0);
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), lbl_805D9AE0);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions(arg0);
        r = 0;
        if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
            if (*(s16 *)((s8 *)arg0 + 0xB8) != 9) {
                r = objInBand((GameObj *)arg0, (f32)lbl_805D9ADC);
            }
        } else if (*(s16 *)((s8 *)arg0 + 0xB8) != 8) {
            r = objInBand((GameObj *)arg0, (f32)lbl_805D9ADC);
        }
        if (r != 0) {
            ((s32 (*)(void *))render_anim_model_at_pos__15TObjEnemyCustomFv)(arg0);
            ((VObj_18_fe09eb *)arg0)->m63(0x22, arg0 + 0x410);
            *(u32 *)((s8 *)arg0 + 0x3A8) = (u32)create_particle_emitter(arg0 + 0x410, 0x119);
            *(s16 *)((s8 *)arg0 + 0x33C) = TObjPlayer__sub_800AAF98(arg0, 1);
            *(s32 *)((s8 *)arg0 + 0x37C) = 3;
        }
        break;
    case 3:
        if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
            VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
            enemy_turn_toward_dest(arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 8));
        }
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), lbl_805D9AE0);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions(arg0);
        ((s32 (*)(void *))render_anim_model_at_pos__15TObjEnemyCustomFv)(arg0);
        ((VObj_18_fe09eb *)arg0)->m63(0x22, arg0 + 0x410);
        if (*(u32 *)((s8 *)arg0 + 0x3A8) != 0U) {
            ((TNowLoading *)(*(void **)((s8 *)arg0 + 0x3A8)))->copy_pos(arg0 + 0x410);
        }
        if (--*(s16 *)((s8 *)arg0 + 0x33C) <= 0) {
            void *o;
            (*(s16 *)((s8 *)arg0 + 0x38E))--;
            o = __nw__7TObjectFUl(0x6C);
            if (o != NULL) {
                __ct__13TUnk_80491460FPvlll(o, arg0 + 0x410, *(s32 *)((s8 *)arg0 + 0x60), arg0, TObjPlayer__sub_800AAF98(arg0, 3));
            }
            *(s32 *)((s8 *)arg0 + 0x37C) = 4;
            if (*(u32 *)((s8 *)arg0 + 0x3A8) != 0U) {
                queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x3A8));
                *(u32 *)((s8 *)arg0 + 0x3A8) = 0U;
            }
            play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD04), arg0 + 0x38, 0, 0);
        }
        break;
    case 4:
        advance_animation_playback(arg0);
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), lbl_805D9AE0);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions(arg0);
        if (*(s16 *)((s8 *)arg0 + 0x38E) > 0) {
            if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
                r = objInBand((GameObj *)arg0, (f32)lbl_805D9AE8);
            } else {
                r = objInBand((GameObj *)arg0, (f32)lbl_805D9AEC);
            }
            if (r != 0) {
                *(s16 *)((s8 *)arg0 + 0x33C) = 0xF;
                *(s32 *)((s8 *)arg0 + 0x37C) = 5;
            }
        } else if (*(u32 *)((s8 *)arg0 + 0xB4) != 4U) {
            *(s16 *)((s8 *)arg0 + 0x33C) = 0x1E;
            *(s32 *)((s8 *)arg0 + 0x37C) = 6;
        }
        break;
    case 5:
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), lbl_805D9AE0);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions(arg0);
        *(s16 *)((s8 *)arg0 + 0x33C) = *(s16 *)((s8 *)arg0 + 0x33C) - 1;
        if (*(s16 *)((s8 *)arg0 + 0x33C) <= 0) {
            *(s32 *)((s8 *)arg0 + 0x37C) = 1;
        }
        break;
    case 6:
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), lbl_805D9AE0);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions(arg0);
        *(s16 *)((s8 *)arg0 + 0x33C) = *(s16 *)((s8 *)arg0 + 0x33C) - 1;
        if (*(s16 *)((s8 *)arg0 + 0x33C) <= 0) {
            if (*(s16 *)((s8 *)arg0 + 0x38E) > 0) {
                *(s32 *)((s8 *)arg0 + 0x37C) = 1;
            } else {
                ((TObjEneMe1GiGue *)arg0)->update_if_active(1);
                *(s32 *)((s8 *)arg0 + 0x37C) = -1;
            }
        }
        break;
    case -1:
        if (*(u32 *)((s8 *)arg0 + 0x3A8) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x3A8));
            *(u32 *)((s8 *)arg0 + 0x3A8) = 0U;
        }
        break;
    }
}

void TObjPlayer__sub_800A93E4(void *arg0_) {
    u8 *arg0 = (u8 *)arg0_;
    Ene_800A93E4 *e = (Ene_800A93E4 *)arg0;
    s32 act;
    u32 h0;
    u32 h1;
    Vec_800A93E4 b2;
    Vec_800A93E4 a2;
    Vec_800A93E4 b1;
    Vec_800A93E4 a1;

    switch (e->state) {
    case 0: {
        s16 a = 2;
        if (e->kind != 0) {
            a = 12;
        }
        e->fb8 = a;
        e->flags |= 0x200000;
        ((TBoss4Type3 *)(e->model))->reset_timer();
        e->state = 1;
    }
    case 1:
        if (e->target != NULL) {
            VecCopy((Vec *)&e->dest, (const Vec *)((u8 *)e->target + 0x2FC));
            enemy_turn_toward_dest(arg0, e->params->turn);
        }
        advance_animation_playback(arg0);
        act = -1;
        if (objInBand((GameObj *)arg0, (f32)player_band_threshold_table[e->kind]) != 0) {
            if (e->f39c == 0) {
                act = 4;
            }
        } else if (objInBand((GameObj *)arg0, (f32)player_band_threshold_table[e->kind + 2]) != 0 && e->f398 == 0) {
            act = 3;
        }
        if (act >= 0) {
            play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD03), &e->pos, 0, 0);
            if (e->target != NULL && e->target->m18(arg0, 1.0f) != 0) {
                e->target->m20(arg0, 1.0f);
                e->target->m23(arg0, 3.0f);
                if (e->f368 != 0 && calc_boss4_scale__10TObjPlayerFi((s32)arg0) <= 0.16666667f) {
                    Pair_800A93E4 p = lbl_8043AC9C[0];
                    e->target->m21(arg0, &p, 0, -1, -1);
                }
            }
        }
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions(arg0);
        h0 = TObjPlayer::lookup_entry_by_value((void *)lbl_80500AF0[e->kind], (f32)e->fc0);
        h1 = TObjPlayer::lookup_entry_by_value((void *)lbl_80500AF8[e->kind], (f32)e->fc0);
        push_matrix();
        set_matrix_identity(0);
        post_translate_matrix(&e->pos);
        rotate_matrix_y(0, e->angle);
        if (h0 != 0) {
            mult_vec_array__10TObjPlayerFUll(0, h0, &a1, 2);
            e->model->m4(&a1, &b1);
        }
        if (h1 != 0) {
            s32 pa = (s32)&a2;
            mult_vec_array__10TObjPlayerFUll(0, h1, (void *)pa, 2);
            e->model->m4((Vec_800A93E4 *)pa, &b2);
        }
        pop_matrix();
        if (e->fb4 != 4) {
            ((TObjEneMe1GiGue *)arg0)->update_if_active(1);
            e->state = -1;
        }
        break;
    case -1:
        e->flags &= ~0x200000;
        break;
    }
}

#define arg0 ((u8 *)arg0_)
void TObjPlayer__sub_800A9C38(void *arg0_) {
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case 0:
        if (TObjEneDD::check_v2_mode() != 0 && calc_boss4_scale__10TObjPlayerFi((s32)arg0) > lbl_805D9B0C) {
            *(s32 *)((s8 *)arg0 + 0x37C) = -1;
        } else {
            *(s16 *)((s8 *)arg0 + 0xB8) = 3;
            enemy_set_heading_velocity((TObjEnemy *)arg0, (s32)(*(s32 *)((s8 *)arg0 + 0x60)), (f32)lbl_805D9AFC);
            *(s32 *)((s8 *)arg0 + 0x37C) = 1;
            play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003A806), arg0 + 0x38, 0, 0);
            *(s32 *)((s8 *)arg0 + 0x3CC) = TObjPlayer__sub_800AAF98(arg0, 2);
        }
        *(u32 *)((s8 *)arg0 + 0x30) &= ~0x200000;
        break;
    case 1:
        advance_animation_playback(arg0);
        if (--*(s32 *)((s8 *)arg0 + 0x3CC) <= 0) {
            ((TObjPlayer *)arg0)->set_invuln_flags();
        }
        {
        Vec_800A9C38 pos = *(Vec_800A9C38 *)(arg0 + 0x2FC);
        pos.x += *(f32 *)((s8 *)arg0 + 0x308);
        pos.z += *(f32 *)((s8 *)arg0 + 0x310);
        if (check_path_obstructed(arg0, &pos) == 0) {
            move_with_wall_slide(arg0);
        } else {
            *(f32 *)((s8 *)arg0 + 0x308) = *(f32 *)((s8 *)arg0 + 0x310) = lbl_805D9AE0;
        }
        }
        *(f32 *)((s8 *)arg0 + 0x308) *= lbl_805D9B04;
        *(f32 *)((s8 *)arg0 + 0x310) *= lbl_805D9B04;
        if (*(s16 *)((s8 *)arg0 + 0xB8) == 0xE) {
            *(f32 *)((s8 *)arg0 + 0x308) = *(f32 *)((s8 *)arg0 + 0x310) = lbl_805D9AE0;
            *(s32 *)((s8 *)arg0 + 0x37C) = 3;
            ((TObjPlayer *)arg0)->set_invuln_flags();
        }
        break;
    case 2:
        break;
    case 3:
        advance_animation_playback(arg0);
        if (*(f32 *)((s8 *)arg0 + 0xC0) >= lbl_805D9B08) {
            ((TObjPlayer *)arg0)->clear_flag_04000000();
        }
        if (*(u32 *)((s8 *)arg0 + 0xB4) != 8) {
            *(s32 *)((s8 *)arg0 + 0x37C) = -1;
        }
        break;
    case 4:
        (*(s32 *)((s8 *)arg0 + 0x384))--;
        if (*(s32 *)((s8 *)arg0 + 0x384) <= 0) {
            *(s32 *)((s8 *)arg0 + 0x37C) = -1;
        }
        break;
    case -1:
        ((TObjPlayer *)arg0)->clear_flag_04000000();
        ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x200);
        *(u32 *)((s8 *)arg0 + 0x388) &= ~1;
        *(s16 *)((s8 *)arg0 + 0x33E) = *(s16 *)((s8 *)arg0 + 0x32C);
        ((TObjEneMe1GiGue *)arg0)->update_if_active(1);
        return;
    }
    apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), lbl_805D9AE0);
    ((TObjPlayer *)arg0)->check_object_collisions();
    check_enemy_body_collisions(arg0);
}

#undef arg0

#define arg0 ((u8 *)arg0_)
void TObjPlayer__sub_800A9E9C(void *arg0_) {
    f32 var_f31;
    s32 var_r0;
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case -1:
        break;
    case 0:
        *(s32 *)((s8 *)arg0 + 0x388) |= 0x01800000;
        sub_8004292C__15TObjEnemyCustomFv();
        if (*(s32 *)((s8 *)arg0 + 0x380) != 0) {
            if (TObjEneDD::check_v2_mode() == 0) {
                if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
                    var_r0 = 7;
                } else {
                    var_r0 = ((s32 *)lbl_804910EC)[*(s32 *)((s8 *)arg0 + 0x368)];
                }
                *(s16 *)((s8 *)arg0 + 0xB8) = (s16) var_r0;
            } else {
                *(s16 *)((s8 *)arg0 + 0xB8) = 0;
            }
            *(s32 *)((s8 *)arg0 + 0x37C) = 2;
        } else {
            play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003B205), arg0 + 0x38, 0, 0);
            *(s32 *)((s8 *)arg0 + 0x37C) = 1;
        }
        if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
            VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
        }
        break;
    case 1:
        advance_animation_playback(arg0);
        if (*(s16 *)((s8 *)arg0 + 0xB8) == 0) {
            if (TObjEneDD::check_v2_mode() == 0) {
                if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
                    var_r0 = 7;
                } else {
                    var_r0 = ((s32 *)lbl_804910EC)[*(s32 *)((s8 *)arg0 + 0x368)];
                }
                *(s16 *)((s8 *)arg0 + 0xB8) = (s16) var_r0;
            }
            *(s32 *)((s8 *)arg0 + 0x37C) = 2;
        }
        break;
    case 2:
        advance_animation_playback(arg0);
        if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
            var_r0 = copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003A801);
        } else {
            var_r0 = copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003B200);
        }
        play_persistent_sound((s32)var_r0, (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
        if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
            if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
                var_f31 = ((TObjEneDubchik *)arg0)->sub_800AAF78(2);
            } else {
                var_f31 = ((f32 *)lbl_804910E4)[*(s32 *)((s8 *)arg0 + 0x368)];
            }
            {
                Vec_800A9E9C v = *(Vec_800A9E9C *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC);
                update_enemy_wander_move(arg0, &v, 1, var_f31);
            }
            *(f32 *)((s8 *)arg0 + 0x3A4) += var_f31;
            ((TObjPlayer *)arg0)->update_angle((s32)((void *) *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 8)), arg0 + 0x308);
        } else {
            ((TObjEneMe1GiGue *)arg0)->update_if_active(0);
        }
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), lbl_805D9AE0);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions(arg0);
        break;
    }
}
#undef arg0

void TObjEneDubchik::sub_800AA10C() {
    f32 temp_f31;
    u32 temp_r0_2;
    switch (this->mode) {
    case 8:
    case 0:
        if ((this->is_actor_cadence_frame(0x1E) != 0) && (find_target_in_range__15TObjEnemyCustomFf(this, this->m_3d0) != 0)) {
            ((TObjEneMe1GiGue *)((u8 *)this))->update_if_active(1);
        }
        break;
    case 1:
        if (this->is_actor_cadence_frame(0x1E) != 0) {
            find_target_in_range__15TObjEnemyCustomFf(this, (f32) (lbl_805D9B10 + this->m_3d0));
        }
        temp_r0_2 = *(u32 *)((s8 *)((u8 *)this) + 0x2A8);
        if (temp_r0_2 == 0U) {
            ((TObjEneMe1GiGue *)((u8 *)this))->update_if_active(8);
            return;
        }
        if (this->m_3a4 >= lbl_805D9B14) {
            this->m_3a4 = (f32) lbl_805D9AE0;
            if ((*(f32 *)((s8 *)((u8 *)this) + 0x354) >= lbl_805D9AE0) && (calc_boss4_scale__10TObjPlayerFi((s32)this) < lbl_805D9B18)) {
                this->targetId = pick_random_nearby_player(lbl_805D9B1C);
                if (this->targetId != 0xFFFF) {
                    *(u32 *)((s8 *)((u8 *)this) + 0x2A8) = find_active_entity_by_id(this->targetId);
                    ((TObjEneMe1GiGue *)((u8 *)this))->update_if_active(9);
                    return;
                }
                find_target_in_range__15TObjEnemyCustomFf(this, (f32) (lbl_805D9B10 + this->m_3d0));
                return;
            }
        } else if (temp_r0_2 != 0U) {
            if (xz_distance_squared((Vec *)(((u8 *)this) + 0x38), (Vec *)(*(u32 *)((s8 *)((u8 *)this) + 0x2A8) + 0x38)) < (((TObjPlayer *)(this->m_318))->get_pos_x() * ((TObjPlayer *)(this->m_318))->get_pos_x())) {
                this->m_390 = (this->m_390 + 1);
                if ((s16) this->m_390 > 3) {
                    this->m_390 = 0;
                    this->target_nearest_player(lbl_805D9B20);
                }
                ((TObjEneMe1GiGue *)((u8 *)this))->update_if_active(2);
                return;
            }
        } else if (this->is_actor_cadence_frame(0x1E) != 0) {
            find_target_in_range__15TObjEnemyCustomFf(this, (f32) (lbl_805D9B10 + this->m_3d0));
        }
        break;
    }
}

void TObjPlayer__sub_800AA330(void * _w0) {  }

#pragma push
#pragma opt_common_subs off
void TObjPlayer__sub_800AA334(u8 *arg0) {
    s32 temp_r3;
    s32 var_r30;
    s32 var_r29;
    if (!(((TObjEneDubchik *)arg0)->actorFlags & 0x02000000)) {
        temp_r3 = ((VObj_18_ca64a0 *)(arg0))->m9(lbl_805D9B24, lbl_805D9B28, lbl_805D9B2C);
        if (temp_r3 != 0) {
            select_actor_lighting((s32)arg0);
            TObjPlayer::toggle_particle_effect();
            if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
                TObjFish::set_global_param(lbl_805D5094);
            } else {
                TObjFish::set_global_param((s32)((void *) (((TObjEneDubchik *)arg0)->texlist)));
            }
            var_r30 = 1;
            push_matrix();
            saved_model_render_flags = model_render_flags;
            ((TObjEneDubchik *)arg0)->sub_800A8A7C();
            post_translate_matrix(arg0 + 0x38);
            rotate_matrix_y(0, (int) (((TObjEneDubchik *)arg0)->rotation_y));
            scale_matrix(0, lbl_805D9B30, lbl_805D9B30, lbl_805D9B30);
            model_render_flags &= 0xFFFFFBFF;
            if (TObjPlayer::check_demo_mode() == 1) {
                draw_chunk_object((void *)(*(s32 *)((s8 *)arg0 + 0x34)));
            } else if (((TObjEneDubchik *)arg0)->m_388 & 4) {
                if (((Self_800AA334 *)arg0)->sub.m8() != 0) {
                    ((Self_800AA334 *)arg0)->sub.m6();
                    var_r29 = 1;
                    if (defer_render__7TObjectFv(arg0) != 0) {
                        var_r29 = 0;
                    }
                    if (var_r29 != 0) {
                        if (temp_r3 == 1) {
                            ((TObjMotion *)arg0)->draw();
                        } else {
                            ((TObjEnemy *)arg0)->render_world_model();
                        }
                    }
                    ((Self_800AA334 *)arg0)->sub.m7();
                } else {
                    var_r30 = 0;
                }
            } else if (temp_r3 == 1) {
                ((TObjMotion *)arg0)->draw();
            } else {
                ((TObjEnemy *)arg0)->render_world_model();
            }
            model_render_flags = saved_model_render_flags;
            pop_matrix();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            if (!(((TObjEneDubchik *)arg0)->actorFlags & 0x800) && (var_r30 != 0)) {
                Vec_800AA334 v = *(Vec_800AA334 *)lbl_8043AC78;
                ((TObjEnemy *)arg0)->render_with_position_override((u8 *)&v, 0);
            }
        }
    }
}
#pragma pop

void TObjPlayer::run_synced_state_handler() {
    Obj_800AA528 *arg0 = (Obj_800AA528 *)this;
    switch (this->mode) {
    case 0: update_timed_state(); return;
    case 1: TObjPlayer__sub_800A9E9C(arg0); return;
    case 2: TObjPlayer__sub_800A93E4(arg0); return;
    case 9: TObjPlayer__sub_800A8FB4(arg0); return;
    case 4: TObjPlayer__sub_800A9C38(arg0); return;
    case 5: TObjPlayer__sub_800A9718(arg0); return;
    case 7: TObjPlayer__sub_800A8E04((u8 *)arg0); return;
    case 8: TObjPlayer__sub_800A8C4C((u8 *)arg0); break;
    }
}

void TObjPlayer::update_synced_state() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        TObjPlayer__sub_800AA330(arg0);
        return;
    }
    ((TObjEneDubchik *)arg0)->sub_800A8B8C();
    (*(s32 *)&this->target) = find_active_entity_by_id(*(u16 *)((s8 *)arg0 + 0x338));
    ((TObjEnemyCustom *)arg0)->release_destroyed_target();
    ((TObjEneDubchik *)arg0)->sub_800AA10C();
    if ((s16) this->mode != (s32) this->m_374) {
        if ((s32) this->m_37c != -1) {
            this->m_37c = -1;
            run_synced_state_handler();
        }
        this->mode = (s16) this->m_374;
        this->m_37c = 0;
    }
    run_synced_state_handler();
    ((TObjEneDubchik *)arg0)->sub_800AB068();
    ((TObjEnemy *)arg0)->update_prev_position();
    VecCopy(&this->center, (const Vec *)&this->m_2fc);
    if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x04000000) == 0) {
        submit_cursor_candidate(arg0, -1);
    }
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
}
void *TObjPlayer::create_dubchik(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x41C);
    if (o2 != NULL) {
        o2 = TObjEneDubchik__ct(o2, o, arg0);
    }
    return o2;
}
void TObjPlayer::free_effect_resources() {
    if (breakup_model_ptr != NULL) {
        delete (VObj_800AA704 *)breakup_model_ptr;
        breakup_model_ptr = NULL;
    }
    if (lbl_805D5090 != NULL) {
        TLobby__sub_8001FE7C(lbl_805D5090, 1);
        lbl_805D5090 = NULL;
    }
    lbl_805D5094 = 0;
    if ((void *)lbl_805D5098 != NULL) {
        TObjPlayer::free_if_valid(lbl_805D5098);
        lbl_805D5098 = 0;
    }
    TObjPlayer::reset_effect_count();
    if ((void *)lbl_80500AF0[0] != NULL) {
        __dt__11TBoss4Type3FPvs((s32 *)lbl_80500AF0[0], 1);
        lbl_80500AF0[0] = 0;
    }
    if ((void *)lbl_80500AF8[0] != NULL) {
        __dt__11TBoss4Type3FPvs((s32 *)lbl_80500AF8[0], 1);
        lbl_80500AF8[0] = 0;
    }
    if ((void *)lbl_80500AF0[1] != NULL) {
        __dt__11TBoss4Type3FPvs((s32 *)lbl_80500AF0[1], 1);
        lbl_80500AF0[1] = 0;
    }
    if ((void *)lbl_80500AF8[1] != NULL) {
        __dt__11TBoss4Type3FPvs((s32 *)lbl_80500AF8[1], 1);
        lbl_80500AF8[1] = 0;
    }
}
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjPlayer__sub_800AA82C(void) {
    s32 *t;
    Node_800AA82C *nodes[3];
    void *p;
    s32 m;
    s32 i;
    u32 mdl;
    Node_800AA82C *n;
    if (TObjEneDD::check_v2_mode() != 0) {
        lbl_805D5090 = load_enemy_bml_resource_named(bm_ene_dubchik_resource_descriptor, lbl_8043ACA4);
    } else {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, bm_ene_dubchik_resource_descriptor, 0, 0, 0);
        }
        lbl_805D5090 = (Res_800AA82C *)p;
    }
    lbl_805D5094 = *(s32 *)((u8 *)lbl_805D5090->mdl + 0x1C);
    if (TObjEneDD::check_v2_mode() != 0) {
        lbl_805D5098 = (s32)load_gvm_texture_file((s32)lbl_8043ACBC);
    } else {
        lbl_805D5098 = (s32)load_gvm_texture_file((s32)lbl_8043ACD0);
    }
    n = (Node_800AA82C *)find_model_node(*(s32 *)((u8 *)lbl_805D5090->mdl + 0x18), 0x17);
    n->f30 = 0;
    TObjPlayer__sub_800A4294();
    lbl_805D509C = (Node_800AA82C *)find_model_node(lbl_805D5090->mdl->f8, 0x15);
    lbl_805D50A0 = (Node_800AA82C *)find_model_node(lbl_805D5090->mdl->f8, 0x2A);
    ((NJS_OBJECT *)find_model_node(*(s32 *)((u8 *)lbl_805D5090->mdl + 0x18), 0x15))->evalflags |= 8;
    p = ::operator new(0x10);
    if (p != NULL) {
        p = ((TBreakUpMdl *)p)->init_from_model(lbl_805D5090->mdl->f8);
    }
    breakup_model_ptr = p;
    p = ::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, lbl_805D9B34, lbl_805D9B38, lbl_805D9AF0);
    }
    lbl_80500AF0[0] = (s32)p;
    draw_trail_with_colors((u8 *)lbl_80500AF0[0], get_bml_model(lbl_805D5090, 0), get_bml_motion(lbl_805D5090, 6), 0x1C, 0x24);
    p = ::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, lbl_805D9B3C, lbl_805D9B20, lbl_805D9AF0);
    }
    lbl_80500AF8[0] = (s32)p;
    draw_trail_with_colors((u8 *)lbl_80500AF8[0], get_bml_model(lbl_805D5090, 0), get_bml_motion(lbl_805D5090, 6), 0x2E, 0x32);
    p = ::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, lbl_805D9B40, lbl_805D9B44, lbl_805D9AF0);
    }
    t = lbl_80500AF0;
    t[1] = (s32)p;
    draw_trail_with_colors((u8 *)t[1], get_bml_model(lbl_805D5090, 0), get_bml_motion(lbl_805D5090, 7), 0x1C, 0x24);
    p = ::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, lbl_805D9B10, lbl_805D9B48, lbl_805D9AF0);
    }
    t = lbl_80500AF8;
    t[1] = (s32)p;
    draw_trail_with_colors((u8 *)t[1], get_bml_model(lbl_805D5090, 0), get_bml_motion(lbl_805D5090, 7), 0x2E, 0x32);
    for (i = 0; i < 2; i++) {
        ((s32 *)lbl_805009A0)[i] = register_boss__6TLobbyFl(i + 0x1B);
        lbl_805009A8[i] = dispatch_shared_handler_b__6TLobbyFl(i + 0x1B);
        lbl_805009B0[i] = register_object__6TLobbyFl(i + 0x1B);
        lbl_805009B8[i] = dispatch_shared_handler_a__6TLobbyFl(i + 0x1B);
    }
    mdl = lbl_805D5090->mdl->f8;
    for (i = 0; i < 3; i++) {
        nodes[i] = (Node_800AA82C *)find_model_node(mdl, player_model_node_index_pair[i]);
    }
    collect_visible_nodes((NJS_OBJECT *)nodes[0], (NJS_OBJECT **)lbl_80500A08);
    collect_visible_nodes((NJS_OBJECT *)nodes[1], (NJS_OBJECT **)lbl_80500A18);
    collect_visible_nodes((NJS_OBJECT *)nodes[2], (NJS_OBJECT **)lbl_80500A48);
    {
        Ids_800AA82C ids = lbl_805D9AD8;
        Desc_800AA82C d = {0, &lbl_804910F4, 1, 0x140000};
        s32 j;
        d.a = lbl_805D5090->f430;
        for (j = 0; j < 2; j++) {
            Mdl_800AA82C *e = &lbl_805D5090->mdl[j];
            spawn_npc_enemy__6TLobbyFslllff(ids.v[j], e->f8, e->fC, &d, lbl_805D9B4C, lbl_805D9AE0);
        }
    }
}
}
#pragma pop
