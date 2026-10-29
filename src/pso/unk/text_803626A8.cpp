extern "C" void *__ct__12TObjEneDD_STFP7TObject(void *);
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/misc/TBreakUpMdl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneEpsilonGuard.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/unk/TUnk_804F26E0.h"
#include "pso/system/BmlResourceDescriptor.h"

extern char lbl_80479EA0[];
extern char lbl_80479EB0[];
extern char lbl_80479EC4[];
extern char lbl_80479ED8[];
extern char lbl_80479EE8[];
extern char lbl_80479EF4[];
extern char lbl_80479F04[];
extern char lbl_80479F18[];
extern char lbl_80479F34[];
extern char lbl_80479F50[];
extern char lbl_80479F70[];
extern char lbl_80479F88[];
extern const char *bm_ene_epsilon_model_names[8];
extern const char *bm_ene_epsilon_motion_names[5];
extern BmlResourceDescriptor TObjEneEpsilonGuard__resource_descriptor;

#include <stddef.h>
#include "pso/enemy/TObjEneDD.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/misc/TLobby.h"
#include "pso/item/TItem.h"
struct Stack_803626A8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_803626A8_lbl_80479FBC {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_803626A8_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_80362B48___vt__14TObjEneEpsilon {
    s32 value;
    u8 remaining[0x1A0];
};

struct Obj_80362DE8 {
    u8 pad0[0x40]; u32 flags; u8 pad44[8]; f32 f4C; u8 pad50[8]; s32 i58; u8 pad5C[4]; u8 v60[0x10]; void *fn70; void *fn74;
};

struct VBase_18_c22f9c
{
  char pad[0x18];
};

struct VObj_18_c22f9c : VBase_18_c22f9c {
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
    virtual void m63(s32, void *);
};

struct T_80362C80
{
  u8 pad0[0xF0];
  VObj_18_c22f9c *obj;
};

struct S_80362C80
{
  s32 v;
};

struct Leaf_803627DC { u8 pad[4]; s32 v; };

struct Node_803627DC {
    u8 pad0[4];
    Leaf_803627DC *leaf;
    u8 pad8[0x2C - 8];
    Node_803627DC *child;
    Node_803627DC *next;
};

struct Model_803627DC { u8 pad[8]; s32 f8; s32 fC; };

struct Res_803627DC { u8 pad[0x42C]; Model_803627DC *f42c; s32 f430; };

struct Quad_803627DC { s32 a, b, c, d; };

class V_8036274C {
public:
    u8 pad[0xC];
    virtual ~V_8036274C();
};

extern const f32 lbl_805E0258;
extern const f32 lbl_805E025C;
void s_rank_knuckle_equip(u8 *arg0);
void * init_s_rank_knuckle(void *, s32, void *);
extern "C" {
u8 *__nw__5TItemFUl(s32);
s32 matrix_mult_vec(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix_from(void *);
s32 pop_matrix();
f32 post_translate_matrix(void *);
extern RecoveredGlobal_803626A8_lbl_80479FBC lbl_80479FBC;
extern RecoveredGlobal_803626A8_lbl_8058D490 identity_matrix;
extern s32 anim_model_matrix_array;
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 __dl__7TObjectFPv(void *);
s32 __destroy_arr(void *, void *, int, int);
extern s32 __dt__15RenderFadeStateFv[];
extern s32 __vt__14TObjEneEpsilon[];
u8 *__dt__14TObjEneEpsilonFv(u8 *arg0, s16 arg1);
void get_weapon_color__11TItemWeaponFPv(void *, void *);
void TObjPlayer__sub_8032E648(s32 arg0, s32 arg1, s32 arg2);
extern const f32 lbl_805E0260;
void init_weapon_effect_descriptor__10TObjPlayerFPvPv(void *arg0, Obj_80362DE8 *arg1);
void *spawn_particle_effect(void *pos, s32 id);
s16 get_validated_attack_stage(u8 *arg0);
extern s32 knuckle_marker_joint_table[];
void s_rank_knuckle_marker(T_80362C80 *arg0);
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
Node_803627DC *get_bml_model(void *, int);
u8 *load_resource_from_descriptor(void *, int, void *, int, int, int);
s32 TObjPlayer__sub_800F0928(void *);
extern Quad_803627DC lbl_80479FAC;
extern f32 lbl_80543A18[3];
extern s32 epsilon_guard_part_color_table[9];
extern s32 epsilon_guard_boss_stat_handle;
extern s32 epsilon_guard_shared_handler_b;
extern s32 epsilon_guard_registered_object_handle;
extern s32 TObjEneEpsilonGuard__movement_params;
extern s32 lbl_805D6F80;
extern s32 lbl_805D6F84;
extern s32 lbl_805D6F88;
extern s32 lbl_805D6F8C;
extern u8 *lbl_805D6FA0;
extern u8 *lbl_805D6FA4;
extern u8 *lbl_805D6FA8;
extern const f32 lbl_805E0248;
extern const f32 lbl_805E024C;
extern const f32 lbl_805E0250;
void TLobby__sub_8001FE7C(void *, int);
void *__dt__13TUnk_804F26E0Fv(void *arg0, s16 arg1);
void *TObjEneEpsilon__ct(void *arg0);
void construct_srank_weapon(void *);
void __construct_array(void *, void *, void *, int, int);
void *__dt__13TUnk_804A4948Fv(void *arg0, s16 arg1);

extern s32 __ct__15RenderFadeStateFv[];
extern void *TObjEneEpsilon__class_name;

typedef char RecoveredGlobal_803626A8_lbl_80479FBC_size[sizeof(RecoveredGlobal_803626A8_lbl_80479FBC) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_803626A8_lbl_8058D490_size[sizeof(RecoveredGlobal_803626A8_lbl_8058D490) == 0x30 ? 1 : -1];
void TObjEneEpsilonGuard::sub_803626A8(s32 arg1, s32 arg2) {
    typedef char sp8_offset[(offsetof(Stack_803626A8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_803626A8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_803626A8, sp10) == 0x8) ? 1 : -1];
    Stack_803626A8 stack;
    stack.sp8 = *(s32 *)((s8 *)&lbl_80479FBC.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_80479FBC.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_80479FBC.value + 8);
    push_matrix_from((void *)&identity_matrix.value);
    post_translate_matrix((void *) (((u8 *)this) + 0x38));
    rotate_matrix_y(0, this->rotation_y);
    this->calc_joint_matrices(this->frame);
    pop_matrix();
    push_matrix_from((void *) (anim_model_matrix_array + (arg2 * 0x30)));
    matrix_mult_vec(0, (void *)&stack.sp8, (void *)arg1);
    pop_matrix();
}

typedef char RecoveredGlobal_80362B48___vt__14TObjEneEpsilon_size[sizeof(RecoveredGlobal_80362B48___vt__14TObjEneEpsilon) == 0x1A4 ? 1 : -1];

void TObjEneEpsilonGuard::free_shared_resources() {
    if ((*(V_8036274C * *)&lbl_805D6FA4) != NULL) {
        delete (*(V_8036274C * *)&lbl_805D6FA4);
        (*(V_8036274C * *)&lbl_805D6FA4) = NULL;
    }
    if ((*(V_8036274C * *)&lbl_805D6FA8) != NULL) {
        delete (*(V_8036274C * *)&lbl_805D6FA8);
        (*(V_8036274C * *)&lbl_805D6FA8) = NULL;
    }
    if ((*(u32 *)&lbl_805D6FA0) != 0) {
        TLobby__sub_8001FE7C((void *)(*(u32 *)&lbl_805D6FA0), 1);
        (*(u32 *)&lbl_805D6FA0) = 0;
    }
}

void TObjEneEpsilonGuard::load_assets() {
    u8 *p;
    lbl_80543A18[0] = lbl_805E0248;
    lbl_80543A18[1] = lbl_805E0248;
    lbl_80543A18[2] = lbl_805E0248;
    p = (u8 *)::operator new(0x440);
    if (p != NULL) {
        p = load_resource_from_descriptor(p, 1, &TObjEneEpsilonGuard__resource_descriptor, 0, 0, 0);
    }
    lbl_805D6FA0 = p;
    p = (u8 *)::operator new(0x10);
    if (p != NULL) {
        p = ((TBreakUpMdl *)p)->init_from_model((s32)(get_bml_model(lbl_805D6FA0, 5)));
    }
    lbl_805D6FA4 = p;
    p = (u8 *)::operator new(0x10);
    if (p != NULL) {
        p = ((TBreakUpMdl *)p)->init_from_model((s32)(get_bml_model(lbl_805D6FA0, 6)));
    }
    lbl_805D6FA8 = p;
    lbl_805D6F80 = register_boss__6TLobbyFl(0x23);
    lbl_805D6F84 = dispatch_shared_handler_b__6TLobbyFl(0x23);
    lbl_805D6F88 = register_object__6TLobbyFl(0x23);
    lbl_805D6F8C = dispatch_shared_handler_a__6TLobbyFl(0x23);
    epsilon_guard_boss_stat_handle = register_boss__6TLobbyFl(0x24);
    epsilon_guard_shared_handler_b = dispatch_shared_handler_b__6TLobbyFl(0x24);
    epsilon_guard_registered_object_handle = register_object__6TLobbyFl(0x24);
    TObjEneEpsilonGuard__movement_params = dispatch_shared_handler_a__6TLobbyFl(0x24);
    epsilon_guard_part_color_table[0] = get_bml_model(lbl_805D6FA0, 0)->child->leaf->v;
    epsilon_guard_part_color_table[1] = get_bml_model(lbl_805D6FA0, 0)->child->next->child->child->next->child->child->next->next->child->leaf->v;
    epsilon_guard_part_color_table[2] = get_bml_model(lbl_805D6FA0, 0)->child->next->child->child->next->child->child->next->next->next->child->leaf->v;
    epsilon_guard_part_color_table[3] = get_bml_model(lbl_805D6FA0, 0)->child->next->child->child->next->child->child->next->next->next->next->child->leaf->v;
    epsilon_guard_part_color_table[4] = get_bml_model(lbl_805D6FA0, 0)->child->next->child->child->next->child->child->next->next->next->next->next->child->leaf->v;
    epsilon_guard_part_color_table[5] = get_bml_model(lbl_805D6FA0, 1)->child->leaf->v;
    epsilon_guard_part_color_table[6] = get_bml_model(lbl_805D6FA0, 2)->child->leaf->v;
    epsilon_guard_part_color_table[8] = get_bml_model(lbl_805D6FA0, 3)->leaf->v;
    epsilon_guard_part_color_table[7] = get_bml_model(lbl_805D6FA0, 4)->leaf->v;
    TObjPlayer__sub_800F0928(epsilon_guard_part_color_table);
    {
        Quad_803627DC q = lbl_80479FAC;
        q.a = ((Res_803627DC *)lbl_805D6FA0)->f430;
        TLobby::spawn_npc_enemy((s16)0x4E, (s32)(((Res_803627DC *)lbl_805D6FA0)->f42c->f8), (s32)(((Res_803627DC *)lbl_805D6FA0)->f42c->fC), (s32)&q, (f32)lbl_805E024C, (f32)lbl_805E0250);
    }
}

u8 *__dt__14TObjEneEpsilonFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80362B48___vt__14TObjEneEpsilon *)&__vt__14TObjEneEpsilon).value;
        __destroy_arr(arg0 + 0x3C0, &__dt__15RenderFadeStateFv, 0x1C, 4);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TObjEneEpsilon__ct(void *ene_epsilon) {
    __ct__12TObjEneDD_STFP7TObject(ene_epsilon);
    *(s32 **)((s8 *)ene_epsilon + 0x18) = __vt__14TObjEneEpsilon;
    __construct_array((void *)((char *)ene_epsilon + 960), __ct__15RenderFadeStateFv, __dt__15RenderFadeStateFv, 28, 4);
    *(void * *)&((TObjEneEpsilon *)ene_epsilon)->m_name = TObjEneEpsilon__class_name;
    ((TObjEneDD *)ene_epsilon)->check_state_flag_4();
    return ene_epsilon;
}

extern s32 lbl_804F26E0[];

void TUnk_804F26E0::vfunc_62() {
    ((PlayerAttackState *)(*(s32 *)&this->owner + 0x7CC))->set_evp(lbl_805E0258);
}
}
extern s32 tl_05;
u8 *create_s_rank_knuckle(u8 *arg0);
void s_rank_knuckle_equip(u8 *arg0) {
    ((PlayerAttackState *)(*(s32 *)((s8 *)arg0 + 0xF0) + 0x7CC))->set_evp(lbl_805E025C);
}

typedef struct S_80362C80 S_80362C80;
typedef struct T_80362C80 T_80362C80;
typedef struct VBase_18_c22f9c VBase_18_c22f9c;
typedef struct VObj_18_c22f9c VObj_18_c22f9c;

void s_rank_knuckle_marker(T_80362C80 *arg0) {
  u8 sp8[0x10];
  s32 n;
  arg0->obj->m63(knuckle_marker_joint_table[(((TObjPlayer *)(arg0->obj))->has_valid_handle() * 3) + get_validated_attack_stage(((u8 *) arg0->obj) + 0x7CC)], sp8);
  spawn_particle_effect(sp8, 0x1D0);
}

void *init_s_rank_knuckle(void *arg0, s32 _w1, void * _w2) {
    construct_srank_weapon(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804F26E0;
    return arg0;
}
u8 *create_s_rank_knuckle(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)init_s_rank_knuckle(temp_r3, tl_05, arg0)));
        }
        return var_r0;
    }
    return NULL;
}
extern "C" {

void *__dt__13TUnk_804F26E0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804F26E0;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
void init_weapon_effect_descriptor__10TObjPlayerFPvPv(void *weapon, Obj_80362DE8 *arg1) {
    u8 sp8[16];
    arg1->f4C = lbl_805E0260;
    arg1->i58 = 0xC000;
    arg1->flags |= 0x282;
    get_weapon_color__11TItemWeaponFPv(sp8, weapon);
    copy_argb((NJS_ARGB *)arg1->v60, (NJS_ARGB *)sp8);
    arg1->fn74 = (void *)TObjPlayer::create_network_object;
    arg1->fn70 = (void *)TObjPlayer__sub_8032E648;
}

__declspec(section ".data") const char *bm_ene_epsilon_model_names[8] = { lbl_80479EA0, lbl_80479EB0, lbl_80479EC4, lbl_80479ED8, lbl_80479EE8, lbl_80479EF4, lbl_80479F04, NULL };
__declspec(section ".data") const char *bm_ene_epsilon_motion_names[5] = { lbl_80479F18, lbl_80479F34, lbl_80479F50, lbl_80479F70, NULL };
}
BmlResourceDescriptor TObjEneEpsilonGuard__resource_descriptor = { lbl_80479F88, bm_ene_epsilon_model_names, bm_ene_epsilon_motion_names, 7, 4 };
