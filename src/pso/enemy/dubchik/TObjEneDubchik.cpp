#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/TUnk_80494938.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/effect/TUnk_80494968.h"
#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/dubchik/TObjEneDubchik.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/gigue/TObjEneMe1GiGue.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TUnk_80491478.h"
#include "pso/unk/text_800A887C.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"

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
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
s32 check_path_obstructed(void *, void *);
s32 TObjPlayer__sub_800AAF98(void *, s32);
void apply_actor_gravity(TObjEnemy *arg0, s32 *arg1, f32 farg0);
s32 enemy_turn_toward_dest(void *, s32);
void queue_destruction__7TObjectFv(void *arg0);
s32 __ct__13TUnk_80491460FPvlll(void *, void *, s32, void *, s32);
s32 render_anim_model_at_pos__15TObjEnemyCustomFv();
void *__nw__7TObjectFUl(int);
void TObjPlayer__sub_800A8FB4(void *arg0_);

void TLobby__sub_8001FE7C(void *, s32);
extern s32 lbl_80500AF0[];
extern s32 lbl_80500AF8[];
struct Res_800AA82C;
Res_800AA82C *dubchik_resource;
NJS_TEXLIST *dubchik_texlist;
NJS_TEXLIST *dubchik_variant_texlist;

s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
s32 get_bml_motion(void *, int);
void *load_resource_from_descriptor(void *, int, void *, int, int, int);
void TObjPlayer__sub_800A4294(void);
Res_800AA82C *load_enemy_bml_resource_named(BmlResourceDescriptor *, const char *);
u8 *load_gvm_texture_file(s32 arg0);
Node_800AA82C *lbl_805D509C;
Node_800AA82C *lbl_805D50A0;
void *breakup_model_ptr;
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


typedef struct Vec_800A9E9C { f32 x, y, z; } Vec_800A9E9C;

extern "C" {
void TBoss3Volopt__sub_800D8D88(s32 arg0);
void TObjPlayer__sub_800A8E04(u8 *arg0);
void obj_setFlags30(void *, u32);
void dubchik_start_dying(u8 *arg0);
s32 find_active_entity_by_id(u16);
void TObjPlayer__sub_800AA330(void *);
s32 minimap_render_dot(void *, s32, s32, s32);
s32 obj_testFlags30__14TObjCollidableFUl(void *, s32);
extern void *tl_04;
void TObjPlayer__sub_800AAFF0(void *p, f32 v);
f32 fabs_float(f32);
void TObjPlayer__sub_800A93E4(void *);
void TObjPlayer__sub_800A9C38(void *);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 calc_velocity_toward_destination(void *, Vec_800A8C4C, Vec_800A8C4C, f32);
void TObjPlayer__sub_800A8C4C(u8 *arg0);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
s32 defer_render__7TObjectFv(void *);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
f32 random_ratio__9TObjCharaFv(s32 arg0);
s32 find_target_in_range__15TObjEnemyCustomFf(void *, f32);
s32 update_enemy_wander_move(void *, Vec_800A9E9C *, s32, f32);
s32 sub_8004292C__15TObjEnemyCustomFv();
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void TObjPlayer__sub_800A9E9C(void *arg0_);
s32 update_shock_clock__9TObjCharaFv();
s32 update_movement_status__9TObjCharaFv();

struct Ids_800AA82C { s16 v[2]; };
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


const char *bm_ene_dubchik_model_names[] = {
    "me2_y_me2.nj",
    "me2_y_me2_2.nj",
    NULL,
};

const char *bm_ene_dubchik_motion_names[] = {
    "damage_b_me2_y_me2.njm",
    "damage_f_me2_y_me2.njm",
    "kamae01_me2_y_me2.njm",
    "kamae02_me2_y_me2.njm",
    "revival_b_me2_y_me2.njm",
    "revival_f_me2_y_me2.njm",
    "scratch01_me2_me2.njm",
    "scratch02_me2_y_me2.njm",
    "shoot01_me2_y_me2.njm",
    "shoot02_me2_me2.njm",
    "starting_me2_y_me2.njm",
    "wait01_me2_y_me2.njm",
    "wait02_me2_y_me2.njm",
    "walk01_me2_y_me2.njm",
    "walk02_me2_y_me2.njm",
    NULL,
};

BmlResourceDescriptor bm_ene_dubchik_resource_descriptor = {
    "bm_ene_dubchik.bml", bm_ene_dubchik_model_names, bm_ene_dubchik_motion_names, 2, 15,
};

const char *TObjEneDubchik__class_name = "TObjEneDubchik";

__declspec(section ".data") f32 lbl_804910E4[2] = { 0.37037036f, 0.5703704f };
__declspec(section ".data") s32 lbl_804910EC[2] = { 1, 19 };

// Installed as TObjMotion::action_table by the constructor.
TObjMotionAction lbl_804910F4[20] = {
    { 1, 0, 11, 0.5f, 0 },
    { 1, 1, 13, 0.7f, 1 },
    { 2, 0, 6, 0.7f, 4 },
    { 2, 14, 1, 0.7f, 8 },
    { 2, 14, 1, 0.7f, 16 },
    { 2, 0, 10, 0.5f, 0 },
    { 1, 6, 12, 0.5f, 0 },
    { 1, 7, 14, 1.2f, 1 },
    { 2, 10, 2, 0.6f, 4 },
    { 2, 11, 3, 0.4f, 4 },
    { 1, 10, 8, 0.5f, 4 },
    { 1, 11, 9, 0.4f, 4 },
    { 2, 0, 7, 0.8f, 4 },
    { 5, 15, 0, 0.6f, 8 },
    { 2, 0, 5, 0.7f, 8 },
    { 2, 0, 4, 0.7f, 8 },
    { 1, 16, 11, 0.5f, 8 },
    { 2, 0, 8, 0.5f, 4 },
    { 2, 6, 9, 0.4f, 4 },
    { 1, 19, 13, 1.0f, 1 },
};

CollisionBody dubchik_collision_body[1] = {
    { { 0.0f, 9.0f, 0.0f }, 5.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

TBoss3VoloptBreakupParams lbl_80491260 = { 0x14, { 0.06f, 1.5f, 0.9f, 0.12f, 0.55f, 0.5f } };

TBoss3VoloptP01Movement dubchik_movement = { 150.0f, 0.37037036f, 0x400, 0x1E0000, 0, 1, 0 };

__declspec(section ".data") s16 lbl_80491298[3] = { 0x14, 0x15, -1 };
s16 lbl_804912A0[6] = { 0x2B, 0x31, 0x32, 0x33, 0x34, -1 };
s16 lbl_804912AC[9] = { 0x17, 0x1A, 0x1D, 0x1F, 0x20, 0x21, 0x23, 0x24, -1 };
__declspec(section ".data") s16 player_model_node_index_pair[3] = { 0x14, 0x2B, 0x17 };












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











}





struct T_800AAF98 { u8 pad[0x18]; s32 arr[1]; };

struct O_800AAF98 { u8 pad[0x368]; s32 x368; };








s32 TObjEneDubchik::sub_800AB068() {
    u8 *arg0 = (u8 *)this;
  u8 *new_var;
  if ((fabs_float((*((f32 *) (((s8 *) arg0) + 0x38))) - (*((f32 *) (((s8 *) arg0) + 0x44)))) + fabs_float((*((f32 *) (((s8 *) arg0) + 0x40))) - (*((f32 *) (((s8 *) arg0) + 0x4C))))) > 50.0f)
  {
    VecCopy((Vec *) ((new_var = arg0) + 0x38), &this->prev_position);
    return 1;
  }
  return 0;
}

void TObjPlayer::set_invuln_flags() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r5;
    temp_r5 = (u8 *)this->bodies;
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 0x0A000000);
    obj_setFlags30(arg0, 0x04000000U);
}

void TObjPlayer::clear_flag_04000000() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r6;
    temp_r6 = (u8 *)this->bodies;
    *(s32 *)((s8 *)temp_r6 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r6 + 0x18) & 0xF5FFFFFF);
    ((TObjBase *)arg0)->obj_clearFlags30(0x04000000U);
}

extern "C" void TObjPlayer__sub_800AAFF0(void* p, f32 v) { *(f32*)((char*)p + 0x8) = v; }

void TObjEneDubchik::init_level_stats(s32 arg1) {
    s32 var_r0;

    *(s32 *)&this->model = dubchik_resource->mdl->f8;
    if (arg1 == 0) {
        var_r0 = dubchik_resource->mdl->fC;
    } else {
        var_r0 = (s32)dubchik_variant_texlist;
    }
    this->texlist = var_r0;
}

extern "C" s32 TObjPlayer__sub_800AAF98(void *self, s32 i) {
    return ((T_800AAF98 **)lbl_805009B8)[((O_800AAF98 *)self)->x368]->arr[i];
}

f32 TObjEneDubchik::sub_800AAF78(s32 arg1) {
    return ((f32 *)lbl_805009B8[variant])[arg1];
}

void TObjEneDubchik::vfunc_59() {  }

void TObjEneDubchik::vfunc_58() {  }

TObjEneDubchik::TObjEneDubchik(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    s32 i;
    m_name = TObjEneDubchik__class_name;
    apply_set_data(set_data);
    VecCopy((Vec *)&m_290, VecCopy((Vec *)&m_29c, VecCopy(&prev_position, &position)));
    motion_list = (BmlMotionEntry *)dubchik_resource->f430;
    variant = *(s16 *)((u8 *)set_data + 0x3C) ? 1 : 0;
    state36C = *(s16 *)((u8 *)set_data + 0x3E);
    init_level_stats(variant);
    action_table = (TObjMotionAction *)&lbl_804910F4;
    set_field_d8((s32)action_table);
    init_collision_body_parts(this, dubchik_collision_body, 1);
    movementParameters = &dubchik_movement;
    bind_enemy_combat_stats((u8 *)((s32 *)lbl_805009A0)[variant], (u8 *)lbl_805009A8[variant], (u8 *)lbl_805009B0[variant]);
    sub_800A8B8C();
    requested_action = 5;
    set_animation(requested_action);
    set_field_b8(requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    collapsed = 0;
    for (i = 0; i < 3; i++) {
        parts[i] = NULL;
    }
    update_prev_position();
    initialize_enemy_photon_effect(this);
    add_flags_2e4(4);
    attack_count = 0;
    chase_distance = 0.0f;
    if (variant != 0) {
        set_param(50);
    } else {
        set_param(24);
    }
    saver = TUnk_80494968::create(0x00FFFFFF, 0xA0707070);
    if (*(s16 *)((u8 *)set_data + 0xA) != 0) {
        sub_800C7860();
    }
    effect = NULL;
    reassemble_count = 0;
    search_range = ((s32)parameters[0] & 1) ? 220.0f : 170.0f;
    clear_lobby_object_state();
}

TObjEneDubchik::~TObjEneDubchik() {
    s32 i;
    if (effect != NULL) {
        effect->queue_destruction();
    }
    free_collision_body_parts(this);
    for (i = 0; i < 3; i++) {
        if (parts[i] != NULL) {
            parts[i]->queue_destruction();
        }
    }
    delete saver;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void TObjPlayer__sub_800AA82C(void) {
    s32 *t;
    Node_800AA82C *nodes[3];
    void *p;
    s32 m;
    s32 i;
    u32 mdl;
    Node_800AA82C *n;
    if (TObjEneDD::check_v2_mode() != 0) {
        dubchik_resource = load_enemy_bml_resource_named(&bm_ene_dubchik_resource_descriptor, bm_ene_dubchik_a_bml_filename);
    } else {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, &bm_ene_dubchik_resource_descriptor, 0, 0, 0);
        }
        dubchik_resource = (Res_800AA82C *)p;
    }
    dubchik_texlist = *(NJS_TEXLIST **)((u8 *)dubchik_resource->mdl + 0x1C);
    if (TObjEneDD::check_v2_mode() != 0) {
        dubchik_variant_texlist = (NJS_TEXLIST *)load_gvm_texture_file((s32)me2_y_me2_z_a_gvm_filename);
    } else {
        dubchik_variant_texlist = (NJS_TEXLIST *)load_gvm_texture_file((s32)me2_y_me2_z_gvm_filename);
    }
    n = (Node_800AA82C *)find_model_node(*(s32 *)((u8 *)dubchik_resource->mdl + 0x18), 0x17);
    n->f30 = 0;
    TObjPlayer__sub_800A4294();
    lbl_805D509C = (Node_800AA82C *)find_model_node(dubchik_resource->mdl->f8, 0x15);
    lbl_805D50A0 = (Node_800AA82C *)find_model_node(dubchik_resource->mdl->f8, 0x2A);
    ((NJS_OBJECT *)find_model_node(*(s32 *)((u8 *)dubchik_resource->mdl + 0x18), 0x15))->evalflags |= 8;
    p = ::operator new(0x10);
    if (p != NULL) {
        p = ((TBreakUpMdl *)p)->init_from_model(dubchik_resource->mdl->f8);
    }
    breakup_model_ptr = p;
    p = new SampledMotionPoints(2, 28.0f, 35.0f, 1.0f);
    lbl_80500AF0[0] = (s32)p;
    ((SampledMotionPoints *)lbl_80500AF0[0])->sample_two_nodes((NJS_OBJECT *)get_bml_model((BmlResource *)dubchik_resource, 0), (NJS_MOTION *)get_bml_motion(dubchik_resource, 6), 0x1C, 0x24);
    p = new SampledMotionPoints(2, 36.0f, 40.0f, 1.0f);
    lbl_80500AF8[0] = (s32)p;
    ((SampledMotionPoints *)lbl_80500AF8[0])->sample_two_nodes((NJS_OBJECT *)get_bml_model((BmlResource *)dubchik_resource, 0), (NJS_MOTION *)get_bml_motion(dubchik_resource, 6), 0x2E, 0x32);
    p = new SampledMotionPoints(2, 30.0f, 38.0f, 1.0f);
    t = lbl_80500AF0;
    t[1] = (s32)p;
    ((SampledMotionPoints *)t[1])->sample_two_nodes((NJS_OBJECT *)get_bml_model((BmlResource *)dubchik_resource, 0), (NJS_MOTION *)get_bml_motion(dubchik_resource, 7), 0x1C, 0x24);
    p = new SampledMotionPoints(2, 50.0f, 58.0f, 1.0f);
    t = lbl_80500AF8;
    t[1] = (s32)p;
    ((SampledMotionPoints *)t[1])->sample_two_nodes((NJS_OBJECT *)get_bml_model((BmlResource *)dubchik_resource, 0), (NJS_MOTION *)get_bml_motion(dubchik_resource, 7), 0x2E, 0x32);
    for (i = 0; i < 2; i++) {
        ((s32 *)lbl_805009A0)[i] = register_boss__6TLobbyFl(i + 0x1B);
        lbl_805009A8[i] = dispatch_shared_handler_b__6TLobbyFl(i + 0x1B);
        lbl_805009B0[i] = register_object__6TLobbyFl(i + 0x1B);
        lbl_805009B8[i] = dispatch_shared_handler_a__6TLobbyFl(i + 0x1B);
    }
    mdl = dubchik_resource->mdl->f8;
    for (i = 0; i < 3; i++) {
        nodes[i] = (Node_800AA82C *)find_model_node(mdl, player_model_node_index_pair[i]);
    }
    collect_visible_nodes((NJS_OBJECT *)nodes[0], (NJS_OBJECT **)lbl_80500A08);
    collect_visible_nodes((NJS_OBJECT *)nodes[1], (NJS_OBJECT **)lbl_80500A18);
    collect_visible_nodes((NJS_OBJECT *)nodes[2], (NJS_OBJECT **)lbl_80500A48);
    {
        Ids_800AA82C ids = {{0x1E, 0x1F}};
        Desc_800AA82C d = {0, &lbl_804910F4, 1, 0x140000};
        s32 j;
        d.a = dubchik_resource->f430;
        for (j = 0; j < 2; j++) {
            Mdl_800AA82C *e = &dubchik_resource->mdl[j];
            TLobby::spawn_npc_enemy(ids.v[j], e->f8, (NJS_TEXLIST *)e->fC, &d, 5.0f, 0.0f);
        }
    }
}
#pragma pop

void TObjPlayer::free_effect_resources() {
    if (breakup_model_ptr != NULL) {
        delete (VObj_800AA704 *)breakup_model_ptr;
        breakup_model_ptr = NULL;
    }
    if (dubchik_resource != NULL) {
        TLobby__sub_8001FE7C(dubchik_resource, 1);
        dubchik_resource = NULL;
    }
    dubchik_texlist = NULL;
    if (dubchik_variant_texlist != NULL) {
        TObjPlayer::free_if_valid((s32)dubchik_variant_texlist);
        dubchik_variant_texlist = NULL;
    }
    TObjPlayer::reset_effect_count();
    if ((void *)lbl_80500AF0[0] != NULL) {
        delete (SampledMotionPoints *)lbl_80500AF0[0];
        lbl_80500AF0[0] = 0;
    }
    if ((void *)lbl_80500AF8[0] != NULL) {
        delete (SampledMotionPoints *)lbl_80500AF8[0];
        lbl_80500AF8[0] = 0;
    }
    if ((void *)lbl_80500AF0[1] != NULL) {
        delete (SampledMotionPoints *)lbl_80500AF0[1];
        lbl_80500AF0[1] = 0;
    }
    if ((void *)lbl_80500AF8[1] != NULL) {
        delete (SampledMotionPoints *)lbl_80500AF8[1];
        lbl_80500AF8[1] = 0;
    }
}

void *TObjPlayer::create_dubchik(void *arg0) {
    void *o;
    void *o2;
    o = new TObjControl((TObject *)tl_04);
    o2 = new TObjEneDubchik((TObject *)o, arg0);
    return o2;
}

void TObjEneDubchik::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        TObjPlayer__sub_800AA330(arg0);
        return;
    }
    ((TObjEneDubchik *)arg0)->sub_800A8B8C();
    (*(s32 *)&this->target) = find_active_entity_by_id(*(u16 *)((s8 *)arg0 + 0x338));
    ((TObjEnemyCustom *)arg0)->release_destroyed_target();
    ((TObjEneDubchik *)arg0)->sub_800AA10C();
    if ((s16) this->mode != (s32) this->next_action) {
        if ((s32) this->state != -1) {
            this->state = -1;
            ((TObjPlayer *)arg0)->run_synced_state_handler();
        }
        this->mode = (s16) this->next_action;
        this->state = 0;
    }
    ((TObjPlayer *)arg0)->run_synced_state_handler();
    ((TObjEneDubchik *)arg0)->sub_800AB068();
    ((TObjEnemy *)arg0)->update_prev_position();
    VecCopy(&this->center, (const Vec *)&this->m_2fc);
    if (obj_testFlags30__14TObjCollidableFUl(arg0, 0x04000000) == 0) {
        submit_cursor_candidate(arg0, -1);
    }
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
}

void TObjPlayer::run_synced_state_handler() {
    Obj_800AA528 *arg0 = (Obj_800AA528 *)this;
    switch (this->mode) {
    case 0: update_timed_state(); return;
    case 1: TObjPlayer__sub_800A9E9C(arg0); return;
    case 2: TObjPlayer__sub_800A93E4(arg0); return;
    case 9: TObjPlayer__sub_800A8FB4(arg0); return;
    case 4: TObjPlayer__sub_800A9C38(arg0); return;
    case 5: ((TObjEneDubchik *)this)->update_fall_apart(); return;
    case 7: TObjPlayer__sub_800A8E04((u8 *)arg0); return;
    case 8: TObjPlayer__sub_800A8C4C((u8 *)arg0); break;
    }
}

#pragma push
#pragma opt_common_subs off
void TObjEneDubchik::render() {
    s32 temp_r3;
    s32 var_r30;
    s32 var_r29;
    u8 *arg0 = (u8 *)this;
    if (!(((TObjEneDubchik *)arg0)->actorFlags & 0x02000000)) {
        temp_r3 = ((VObj_18_ca64a0 *)(arg0))->m9(120.0f, 400.0f, 20.0f);
        if (temp_r3 != 0) {
            select_actor_lighting((s32)arg0);
            TObjPlayer::toggle_particle_effect();
            if (collapsed != 0) {
                TObjFish::set_global_param((s32)dubchik_texlist);
            } else {
                TObjFish::set_global_param((s32)((void *) (((TObjEneDubchik *)arg0)->texlist)));
            }
            var_r30 = 1;
            push_matrix();
            saved_model_render_flags = model_render_flags;
            ((TObjEneDubchik *)arg0)->sub_800A8A7C();
            post_translate_matrix(arg0 + 0x38);
            rotate_matrix_y(0, (int) (((TObjEneDubchik *)arg0)->rotation_y));
            scale_matrix(0, 1.3f, 1.3f, 1.3f);
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
                            ((TObjEnemy *)arg0)->draw_motion_model();
                        }
                    }
                    ((Self_800AA334 *)arg0)->sub.m7();
                } else {
                    var_r30 = 0;
                }
            } else if (temp_r3 == 1) {
                ((TObjMotion *)arg0)->draw();
            } else {
                ((TObjEnemy *)arg0)->draw_motion_model();
            }
            model_render_flags = saved_model_render_flags;
            pop_matrix();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            if (!(((TObjEneDubchik *)arg0)->actorFlags & 0x800) && (var_r30 != 0)) {
                Vec v = {1.5f, 1.5f, 1.5f};
                ((TObjEnemy *)arg0)->draw_ground_shadow(&v, 0);
            }
        }
    }
}
#pragma pop

extern "C" void TObjPlayer__sub_800AA330(void * _w0) {  }

void TObjEneDubchik::sub_800AA10C() {
    f32 temp_f31;
    u32 temp_r0_2;
    switch (this->mode) {
    case 8:
    case 0:
        if ((this->is_actor_cadence_frame(0x1E) != 0) && (find_target_in_range__15TObjEnemyCustomFf(this, this->search_range) != 0)) {
            ((TObjEnemyCustom *)((u8 *)this))->update_if_active(1);
        }
        break;
    case 1:
        if (this->is_actor_cadence_frame(0x1E) != 0) {
            find_target_in_range__15TObjEnemyCustomFf(this, (f32) (50.0f + this->search_range));
        }
        temp_r0_2 = *(u32 *)((s8 *)((u8 *)this) + 0x2A8);
        if (temp_r0_2 == 0U) {
            ((TObjEnemyCustom *)((u8 *)this))->update_if_active(8);
            return;
        }
        if (this->chase_distance >= 80.0f) {
            this->chase_distance = 0.0f;
            if ((*(f32 *)((s8 *)((u8 *)this) + 0x354) >= 0.0f) && (random_ratio__9TObjCharaFv((s32)this) < 0.35f)) {
                this->targetId = pick_random_nearby_player(150.0f);
                if (this->targetId != 0xFFFF) {
                    *(u32 *)((s8 *)((u8 *)this) + 0x2A8) = find_active_entity_by_id(this->targetId);
                    ((TObjEnemyCustom *)((u8 *)this))->update_if_active(9);
                    return;
                }
                find_target_in_range__15TObjEnemyCustomFf(this, (f32) (50.0f + this->search_range));
                return;
            }
        } else if (temp_r0_2 != 0U) {
            if (xz_distance_squared((Vec *)(((u8 *)this) + 0x38), (Vec *)(*(u32 *)((s8 *)((u8 *)this) + 0x2A8) + 0x38)) < (((AttackParams *)(this->m_318))->get_attack_range() * ((AttackParams *)(this->m_318))->get_attack_range())) {
                this->attack_count = (this->attack_count + 1);
                if ((s16) this->attack_count > 3) {
                    this->attack_count = 0;
                    this->target_nearest_player(40.0f);
                }
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(2);
                return;
            }
        } else if (this->is_actor_cadence_frame(0x1E) != 0) {
            find_target_in_range__15TObjEnemyCustomFf(this, (f32) (50.0f + this->search_range));
        }
        break;
    }
}

#define arg0 ((u8 *)arg0_)
extern "C" void TObjPlayer__sub_800A9E9C(void *arg0_) {
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
            play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003B205)), arg0 + 0x38, 0, 0);
            *(s32 *)((s8 *)arg0 + 0x37C) = 1;
        }
        if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
            VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
        }
        break;
    case 1:
        ((TObjMotion *)arg0)->advance_animation();
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
        ((TObjMotion *)arg0)->advance_animation();
        if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
            var_r0 = ((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003A801));
        } else {
            var_r0 = ((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003B200));
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
            ((TObjEnemy *)arg0)->turn_toward_direction(*(s32 *)((u8 *)((TObjEnemy *)arg0)->movementParameters + 8), (Vec *)((u8 *)arg0 + 0x308));
        } else {
            ((TObjEnemyCustom *)arg0)->update_if_active(0);
        }
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions((TObjCollidable *)arg0);
        break;
    }
}
#undef arg0

#define arg0 ((u8 *)arg0_)
extern "C" void TObjPlayer__sub_800A9C38(void *arg0_) {
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case 0:
        if (TObjEneDD::check_v2_mode() != 0 && random_ratio__9TObjCharaFv((s32)arg0) > 0.2f) {
            *(s32 *)((s8 *)arg0 + 0x37C) = -1;
        } else {
            *(s16 *)((s8 *)arg0 + 0xB8) = 3;
            enemy_set_heading_velocity(-7.0f, (TObjEnemy *)arg0, (s32)(*(s32 *)((s8 *)arg0 + 0x60)));
            *(s32 *)((s8 *)arg0 + 0x37C) = 1;
            play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003A806)), arg0 + 0x38, 0, 0);
            *(s32 *)((s8 *)arg0 + 0x3CC) = TObjPlayer__sub_800AAF98(arg0, 2);
        }
        *(u32 *)((s8 *)arg0 + 0x30) &= ~0x200000;
        break;
    case 1:
        ((TObjMotion *)arg0)->advance_animation();
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
            *(f32 *)((s8 *)arg0 + 0x308) = *(f32 *)((s8 *)arg0 + 0x310) = 0.0f;
        }
        }
        *(f32 *)((s8 *)arg0 + 0x308) *= 0.75f;
        *(f32 *)((s8 *)arg0 + 0x310) *= 0.75f;
        if (*(s16 *)((s8 *)arg0 + 0xB8) == 0xE) {
            *(f32 *)((s8 *)arg0 + 0x308) = *(f32 *)((s8 *)arg0 + 0x310) = 0.0f;
            *(s32 *)((s8 *)arg0 + 0x37C) = 3;
            ((TObjPlayer *)arg0)->set_invuln_flags();
        }
        break;
    case 2:
        break;
    case 3:
        ((TObjMotion *)arg0)->advance_animation();
        if (*(f32 *)((s8 *)arg0 + 0xC0) >= 25.0f) {
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
        ((TObjBase *)arg0)->obj_clearFlags30(0x200);
        *(u32 *)((s8 *)arg0 + 0x388) &= ~1;
        *(s16 *)((s8 *)arg0 + 0x33E) = *(s16 *)((s8 *)arg0 + 0x32C);
        ((TObjEnemyCustom *)arg0)->update_if_active(1);
        return;
    }
    apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
    ((TObjPlayer *)arg0)->check_object_collisions();
    check_enemy_body_collisions((TObjCollidable *)arg0);
}
#undef arg0

void TObjEneDubchik::update_fall_apart() {
    s32 i;

    if (m_388 & 0x02000000) {
        dubchik_update_dying((u8 *)this);
        return;
    }
    switch ((s32)state) {
    case 0:
        actorFlags &= ~0x200000;
        m_388 &= ~0x800000;
        ((TObjPlayer *)this)->set_invuln_flags();
        requested_action = 4;
        enemy_set_heading_velocity(-7.0f, this, rotation_y);
        ((TObjPlayer *)this)->render_model_and_set_attach_points();
        for (i = 0; i < 3; i++) {
            if (parts[i] == NULL && random_ratio() >= 0.5f) {
                u8 *part = (u8 *)TObject::operator new(0xFC);
                if (part != NULL) {
                    part = TObjPlayer__sub_800AB7A0(part, i, this, (s32)variant != 0 ? dubchik_variant_texlist : dubchik_texlist, &part_offsets[i]);
                }
                parts[i] = (TUnk_80491478 *)part;
                m_388 |= 0x20000 << i;
            }
        }
        play_sound_effect(remap_sound_for_area(0x4003A806), &position, 0, 0);
        ((TObjPlayer *)this)->set_invuln_flags();
        reassemble_count++;
        state = 1;
    case 1: {
        advance_animation();
        Vec pos = *body_center();
        pos.x += velocity()->x;
        pos.z += velocity()->z;
        if (check_path_obstructed(this, &pos) == 0) {
            move_with_wall_slide((u8 *)this);
        } else {
            velocity()->x = velocity()->z = 0.0f;
        }
        velocity()->x *= 0.75f;
        velocity()->z *= 0.75f;
        if (requested_action == 0xE) {
            if ((s32)variant != 0 || reassemble_count >= 5) {
                dubchik_start_dying((u8 *)this);
            } else {
                velocity()->x = velocity()->z = 0.0f;
                collapsed = 1;
                m_384 = TObjPlayer__sub_800AAF98(this, 0);
                state = 2;
            }
        }
        break;
    }
    case 2:
        m_384--;
        if (m_384 <= 0) {
            s32 j;
            for (j = 0; j < 3; j++) {
                if (parts[j] != NULL) {
                    if (random_ratio() >= 0.5f) {
                        part_hit[j] = 1;
                        ((TObjPlayer *)parts[j])->cancel_action();
                    } else {
                        part_hit[j] = 0;
                    }
                }
            }
            if (parts[1] != NULL && parts[2] != NULL && part_hit[1] + part_hit[2] == 0) {
                s32 k;
                f32 dist = xz_distance_squared(body_center(), (Vec *)&parts[1]->m_f0);
                if (dist < xz_distance_squared(body_center(), (Vec *)&parts[2]->m_f0)) {
                    k = 1;
                } else {
                    k = 2;
                }
                part_hit[k] = 1;
                ((TObjPlayer *)parts[k])->cancel_action();
            }
            m_388 |= 0x800000;
            state = 3;
        }
        break;
    case 3: {
        s32 all_done;
        ((TObjPlayer *)this)->render_model_and_set_attach_points();
        play_persistent_sound(remap_sound_for_area(0x4003AD07), (s32)this, (u32)&position, 0, 0);
        all_done = 1;
        for (i = 0; i < 3; i++) {
            if (part_hit[i] != 0 && parts[i] != NULL) {
                if (((TObjPlayer *)parts[i])->get_action_priority() != 0) {
                    parts[i]->queue_destruction();
                    parts[i] = NULL;
                    m_388 &= ~(0x20000 << i);
                } else {
                    all_done = 0;
                }
            }
        }
        if (all_done != 0) {
            play_sound_effect(remap_sound_for_area(0x4003A808), &position, 0, 0);
            state = 4;
        }
        break;
    }
    case 4:
        advance_animation();
        if (obj_testFlags30(0x800) == 0 && frame >= 25.0f) {
            ((TObjPlayer *)this)->clear_flag_04000000();
        }
        if (action_flags != 8) {
            obj_clearFlags30(0xA00);
            hp = referenceHp = hpmax;
            clear_harmful_statuses();
            m_388 &= ~1;
            update_if_active(1);
            ((TObjPlayer *)this)->clear_flag_04000000();
        }
        break;
    case -1:
        obj_clearFlags30(0x200);
        break;
    }
    apply_actor_gravity(this, NULL, 0.0f);
    check_object_collisions();
    check_enemy_body_collisions(this);
}

extern "C" const f32 player_band_threshold_table[6] = { 20.0f, 34.0f, 28.0f, 54.0f, 0.7f, 0.8f };

extern "C" void TObjPlayer__sub_800A93E4(void *arg0_) {
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
        ((TUnk_80494968 *)(e->model))->clear_segments();
        e->state = 1;
    }
    case 1:
        if (e->target != NULL) {
            VecCopy((Vec *)&e->dest, (const Vec *)((u8 *)e->target + 0x2FC));
            enemy_turn_toward_dest(arg0, e->params->turn);
        }
        ((TObjMotion *)arg0)->advance_animation();
        act = -1;
        if (((TObjMotion *)arg0)->is_passing_frame((f32)player_band_threshold_table[e->kind]) != 0) {
            if (e->f39c == 0) {
                act = 4;
            }
        } else if (((TObjMotion *)arg0)->is_passing_frame((f32)player_band_threshold_table[e->kind + 2]) != 0 && e->f398 == 0) {
            act = 3;
        }
        if (act >= 0) {
            play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AD03)), &e->pos, 0, 0);
            if (e->target != NULL && e->target->m18(arg0, 1.0f) != 0) {
                e->target->m20(arg0, 1.0f);
                e->target->m23(arg0, 3.0f);
                if (e->f368 != 0 && random_ratio__9TObjCharaFv((s32)arg0) <= 0.16666667f) {
                    Pair_800A93E4 p = {0x11, 0};
                    e->target->m21(arg0, &p, 0, -1, -1);
                }
            }
        }
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions((TObjCollidable *)arg0);
        h0 = (s32)((SampledMotionPoints *)((void *)lbl_80500AF0[e->kind]))->lookup((f32)e->fc0);
        h1 = (s32)((SampledMotionPoints *)((void *)lbl_80500AF8[e->kind]))->lookup((f32)e->fc0);
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
            ((TObjEnemyCustom *)arg0)->update_if_active(1);
            e->state = -1;
        }
        break;
    case -1:
        e->flags &= ~0x200000;
        break;
    }
}

extern "C" void TObjPlayer__sub_800A8FB4(void *arg0_) {
    u8 *arg0 = (u8 *)arg0_;
    s32 r;
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case 0:
        if (*(u32 *)((s8 *)arg0 + 0x39C) != 0U) {
            ((TObjEnemyCustom *)arg0)->update_if_active(1);
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
        ((TObjMotion *)arg0)->advance_animation();
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions((TObjCollidable *)arg0);
        r = 0;
        if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
            if (*(s16 *)((s8 *)arg0 + 0xB8) != 9) {
                r = ((TObjMotion *)arg0)->is_passing_frame(2.0f);
            }
        } else if (*(s16 *)((s8 *)arg0 + 0xB8) != 8) {
            r = ((TObjMotion *)arg0)->is_passing_frame(2.0f);
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
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions((TObjCollidable *)arg0);
        ((s32 (*)(void *))render_anim_model_at_pos__15TObjEnemyCustomFv)(arg0);
        ((VObj_18_fe09eb *)arg0)->m63(0x22, arg0 + 0x410);
        if (*(u32 *)((s8 *)arg0 + 0x3A8) != 0U) {
            ((TParticleCtrl *)*(void **)((s8 *)arg0 + 0x3A8))->set_position(arg0 + 0x410);
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
            play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AD04)), arg0 + 0x38, 0, 0);
        }
        break;
    case 4:
        ((TObjMotion *)arg0)->advance_animation();
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions((TObjCollidable *)arg0);
        if (*(s16 *)((s8 *)arg0 + 0x38E) > 0) {
            if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
                r = ((TObjMotion *)arg0)->is_passing_frame(6.0f);
            } else {
                r = ((TObjMotion *)arg0)->is_passing_frame(7.0f);
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
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions((TObjCollidable *)arg0);
        *(s16 *)((s8 *)arg0 + 0x33C) = *(s16 *)((s8 *)arg0 + 0x33C) - 1;
        if (*(s16 *)((s8 *)arg0 + 0x33C) <= 0) {
            *(s32 *)((s8 *)arg0 + 0x37C) = 1;
        }
        break;
    case 6:
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions((TObjCollidable *)arg0);
        *(s16 *)((s8 *)arg0 + 0x33C) = *(s16 *)((s8 *)arg0 + 0x33C) - 1;
        if (*(s16 *)((s8 *)arg0 + 0x33C) <= 0) {
            if (*(s16 *)((s8 *)arg0 + 0x38E) > 0) {
                *(s32 *)((s8 *)arg0 + 0x37C) = 1;
            } else {
                ((TObjEnemyCustom *)arg0)->update_if_active(1);
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

void TObjPlayer::update_timed_state() {
    s16 temp_r4;
    switch (this->m_37c) {
    case 0:
        *(s16 *)&this->requested_action = (s16) ((*(u32 *)&this->unk_388 & 0x1000000) ? 0 : 5);
        *(u32 *)&this->unk_388 = (u32) (*(u32 *)&this->unk_388 | 0x800000);
        this->m_37c = 1;
    case 1:
        if (!(this->actorFlags & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), 0.0f);
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

extern "C" void TObjPlayer__sub_800A8E04(u8 *ene_me1_gi_gue) {
    switch (((TObjEneMe1GiGue *)ene_me1_gi_gue)->state) {
    case 0:
        ((TObjEneMe1GiGue *)ene_me1_gi_gue)->m_388 = (s32) (((TObjEneMe1GiGue *)ene_me1_gi_gue)->m_388 | 4);
        ((TObjEneMe1GiGue *)ene_me1_gi_gue)->actorFlags = (((TObjEneMe1GiGue *)ene_me1_gi_gue)->actorFlags | 0x04000000);
        ((TObjEneMe1GiGue *)ene_me1_gi_gue)->requested_action = 5;
        ((TObjMotion *)ene_me1_gi_gue)->advance_animation();
        TBoss3Volopt__sub_800D8D88((s32)(ene_me1_gi_gue + 0x2FC));
        ((TUnk_80494938 *)(ene_me1_gi_gue + 0x3B0))->start_fade_in();
        ((TObjEneMe1GiGue *)ene_me1_gi_gue)->state = 1;
    case 1:
        if (((V_Sub *) (ene_me1_gi_gue + 0x3B0))->m5() == 1) {
            ((TObjEneMe1GiGue *)ene_me1_gi_gue)->state = -1;
        }
        return;
    case -1:
        ((TObjEneMe1GiGue *)ene_me1_gi_gue)->m_388 = (s32) ((((TObjEneMe1GiGue *)ene_me1_gi_gue)->m_388) & ~5);
        ((TObjEneMe1GiGue *)ene_me1_gi_gue)->actorFlags = (s32) (((TObjEneMe1GiGue *)ene_me1_gi_gue)->actorFlags & 0xFBFFFFFF);
        ((TObjEnemyCustom *)ene_me1_gi_gue)->update_if_active(0);
        break;
    }
}

extern "C" void TObjPlayer__sub_800A8C4C(u8 *arg0) {
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
        ((TObjMotion *)arg0)->advance_animation();
        apply_actor_gravity((TObjEnemy *)((u8 *)((void *)arg0)), (s32 *)(0), 0.0f);
        ((TObjPlayer *)arg0)->check_object_collisions();
        check_enemy_body_collisions((TObjCollidable *)arg0);
        if (*(s16 *)((s8 *)arg0 + 0x392) != 0) {
            var_f31 = ((TObjEneDubchik *)arg0)->sub_800AAF78(2);
        } else {
            var_f31 = *(f32 *)((s8 *)((u8 *)lbl_804910E4 + (*(s32 *)((s8 *)arg0 + 0x368) * 4)) + 0);
        }
        VecCopy((Vec *)((u8 *)arg0 + 0x290), (const Vec *)((u8 *)arg0 + 0x2FC));
        calc_velocity_toward_destination((void *)arg0, *(Vec_800A8C4C *)(arg0 + 0x290), *(Vec_800A8C4C *)(arg0 + 0x29C), var_f31);
        ((TObjEnemy *)arg0)->turn_toward_direction(*(s32 *)((u8 *)((TObjEnemy *)arg0)->movementParameters + 8), (Vec *)((u8 *)arg0 + 0x308));
        move_with_wall_slide((arg0));
        if (xz_distance_squared((Vec *)((u8 *)arg0 + 0x38), (Vec *)((u8 *)arg0 + 0x50)) < 100.0f) {
            *(s16 *)((s8 *)arg0 + 0xB8) = 5;
            ((TObjMotion *)arg0)->advance_animation();
            *(s32 *)((s8 *)arg0 + 0x388) = (s32) (*(s32 *)((s8 *)arg0 + 0x388) & 0xFE7FFFFF);
            ((TObjEnemyCustom *)arg0)->update_if_active(0);
        }
        return;
    }
}

extern "C" void dubchik_start_dying(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x388) = (s32) (*(s32 *)((s8 *)arg0 + 0x388) | 0x02000000);
    obj_setFlags30(arg0, 0x800U);
}

void TObjEneDubchik::sub_800A8B8C() {
    lbl_804910F4[2].speed = sub_800AAF78(0);
    lbl_804910F4[7].speed = sub_800AAF78(3);
    lbl_804910F4[12].speed = sub_800AAF78(4);
    TObjPlayer__sub_800AAFF0(*(u8 **)((s8 *)this + 0x318), sub_800AAF78(*(s16 *)((s8 *)this + 0x392) ? 5 : 1));
}

void TObjPlayer::render_model_and_set_attach_points() {
    render_anim_model_at_pos__15TObjEnemyCustomFv();
    this->get_anim_node_position(0x13, (Vec *)&this->unk_3D4);
    this->get_anim_node_position(0x28, (Vec *)&this->unk_3E0);
    this->get_anim_node_position(0x29, (Vec *)&this->m_3ec);
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

s32 TObjEneDubchik::update_shock_clock() {
    s32 arg0 = (s32)this;
    if (update_shock_clock__9TObjCharaFv() != 0) {
        ((TObjPlayer *)arg0)->clear_state7_flag();
        return 1;
    }
    return 0;
}

s32 TObjEneDubchik::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        ((TObjPlayer *)this)->clear_state7_flag();
        return 1;
    }
    return 0;
}

void TObjPlayer::clear_state7_flag() {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_374 == 7) {
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 & 0xFFFFFFFE);
        ((TObjEnemyCustom *)arg0)->update_if_active(0);
    }
}

void TObjPlayer::set_flag_start_effect() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;

    temp_r3 = *(s32 *)&this->unk_388;
    if (!(temp_r3 & 0x04000000)) {
        *(s32 *)&this->unk_388 = (s32) (temp_r3 | 0x04000000);
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 | 1);
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 & 0xFF7FFFFF);
        *(s16 *)&this->unk_33C = 0x1E;
        TObjPlayer::create_dead_spot((s32)(arg0 + 0x2FC), (s32)(*(s16 *)&this->unk_33C), 2.0f);
    }
}

extern "C" void dubchik_update_dying(u8 *arg0) {
  s16 temp_r3;
  ((TObjPlayer *)arg0)->set_flag_start_effect();
  temp_r3 = (*((s16 *) (((s8 *) arg0) + 0x33C)) = (*((s16 *) (((s8 *) arg0) + 0x33C))) - 1);
  if (temp_r3 <= 0)
  {
    if (TLobby::get_instance() != 0)
    {
      play_sound_effect(0x4003AD10, arg0 + 0x38, 0, 0);
    }
    else
    {
      play_sound_effect(((TObjEnemy *)((void *) arg0))->remap_sound_for_area((s32)(0x4003AD16)), arg0 + 0x38, 0, 0);
    }
    TBoss3Volopt::create_breakup_mdl((s32)breakup_model_ptr, (s32)&lbl_80491260, (s32)((int) (*((s32 *) (((s8 *) arg0) + 0x24)))), (s32)(arg0 + 0x2FC), (s32)((int) (*((s32 *) (((s8 *) arg0) + 0x60)))));
    ((TObjPlayer *)arg0)->refresh_lobby_state();
    ((TObjEnemy *)arg0)->send_entity_set_flags();
    ((TObjPlayer *)(arg0 + 0x2FC))->trigger_dell_biter_events();
    obj_setFlags30((void *) arg0, 0x800);
    queue_destruction__7TObjectFv(arg0);
  }
}
