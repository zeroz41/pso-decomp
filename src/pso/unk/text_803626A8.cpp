extern "C" void *__ct__12TObjEneDD_STFP7TObject(void *);
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/epsilon/TObjEneEpsilonGuard.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/weapon/TUnk_804F26E0.h"
#include "pso/system/BmlResourceDescriptor.h"


#include <stddef.h>
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/unk/TLobby.h"
#include "pso/item/TItem.h"
struct Stack_803626A8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};


struct RecoveredGlobal_803626A8_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};



struct Leaf_803627DC { u8 pad[4]; s32 v; };

struct Node_803627DC {
    u8 pad0[4];
    Leaf_803627DC *leaf;
    u8 pad8[0x2C - 8];
    Node_803627DC *child;
    Node_803627DC *next;
};

struct Model_803627DC { u8 pad[8]; s32 f8; NJS_TEXLIST *texlist; };

struct Res_803627DC { u8 pad[0x42C]; Model_803627DC *f42c; s32 f430; };

// The spawn record load_assets passes to TLobby::spawn_npc_enemy; b points at lbl_804F252C.
struct Unk_804F252C { s32 unk_0; s32 unk_4; f32 unk_8; s32 unk_C; };
struct Quad_803627DC { s32 a; Unk_804F252C *b; s32 c, d; };

class V_8036274C {
public:
    u8 pad[0xC];
    virtual ~V_8036274C();
};

extern "C" {
u8 *__nw__5TItemFUl(s32);
s32 matrix_mult_vec(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix_from(void *);
s32 pop_matrix();
f32 post_translate_matrix(void *);
extern RecoveredGlobal_803626A8_lbl_8058D490 identity_matrix;
void *spawn_particle_effect(void *pos, s32 id);
s16 get_validated_attack_stage(u8 *arg0);
extern s32 knuckle_marker_joint_table[];
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
Node_803627DC *get_bml_model(void *, int);
u8 *load_resource_from_descriptor(void *, int, void *, int, int, int);
s32 TObjPlayer__sub_800F0928(void *);
f32 lbl_80543A18[3];
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
void free_bin_model_request(void *, int);
void __construct_array(void *, void *, void *, int, int);


typedef char RecoveredGlobal_803626A8_lbl_8058D490_size[sizeof(RecoveredGlobal_803626A8_lbl_8058D490) == 0x30 ? 1 : -1];
}

const char *bm_ene_epsilon_model_names[8] = {
    "re6_b_bcbody.nj", "re6_b_bal_body.nj", "re6_b_claw_body.nj", "bc1_bc_body.nj", "bc2_body.nj", "re6_hahen1.nj",
    "re6_b1_hahen2.nj", NULL,
};
const char *bm_ene_epsilon_motion_names[5] = {
    "body_wait_re6_b_bcbody.njm", "bal_wait_re6_b_bal_body.njm", "claw_wait_re6_b_claw_body.njm", "bc_rot_bc1_bc_body.njm", NULL,
};
BmlResourceDescriptor TObjEneEpsilonGuard__resource_descriptor = { "bm_ene_epsilon.bml", bm_ene_epsilon_model_names, bm_ene_epsilon_motion_names, 7, 4 };
Unk_804F252C lbl_804F252C = { 0x10000, 0, 0.3f, 0 };

extern const f32 lbl_805E0258;
extern const f32 lbl_805E025C;

const char *TObjEneEpsilon__class_name = "TObjEneEpsilon";

u8 *create_s_rank_knuckle(u8 *arg0);

// The original TU was compiled deferred: functions are written last-to-first.
#pragma defer_codegen on

TUnk_804F26E0::~TUnk_804F26E0() {}

u8 *create_s_rank_knuckle(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804F26E0(tl_05, arg0);
    }
    return NULL;
}

TUnk_804F26E0::TUnk_804F26E0(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {}

// S-rank knuckle marker (was s_rank_knuckle_marker): effect at the owner's knuckle joint.
void TUnk_804F26E0::vfunc_62() {
  u8 sp8[0x10];
  s32 n;
  owner->get_anim_node_position(knuckle_marker_joint_table[(owner->has_valid_handle() * 3) + get_validated_attack_stage(((u8 *)owner) + 0x7CC)], (Vec *)sp8);
  spawn_particle_effect(sp8, 0x1D0);
}

// S-rank knuckle equip hook (was s_rank_knuckle_equip): sets the owner's EVP.
void TUnk_804F26E0::vfunc_57() {
    ((PlayerAttackState *)(*(s32 *)&this->owner + 0x7CC))->set_evp(lbl_805E025C);
}

void TUnk_804F26E0::vfunc_58() {
    ((PlayerAttackState *)(*(s32 *)&this->owner + 0x7CC))->set_evp(lbl_805E0258);
}

TObjEneEpsilon::TObjEneEpsilon(TObject *parent) : TObjEneDD_ST(parent) {
    m_name = TObjEneEpsilon__class_name;
    check_state_flag_4();
}

TObjEneEpsilon::~TObjEneEpsilon() {}

void TObjEneEpsilonGuard::load_assets() {
    u8 *p;
    lbl_80543A18[0] = 0.0f;
    lbl_80543A18[1] = 0.0f;
    lbl_80543A18[2] = 0.0f;
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
        Quad_803627DC q = { 0, &lbl_804F252C, 0, 0x10000 };
        q.a = ((Res_803627DC *)lbl_805D6FA0)->f430;
        TLobby::spawn_npc_enemy((s16)0x4E, (s32)(((Res_803627DC *)lbl_805D6FA0)->f42c->f8), ((Res_803627DC *)lbl_805D6FA0)->f42c->texlist, &q, 5.0f, 15.0f);
    }
}

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
        free_bin_model_request((void *)(*(u32 *)&lbl_805D6FA0), 1);
        (*(u32 *)&lbl_805D6FA0) = 0;
    }
}

void TObjEneEpsilonGuard::sub_803626A8(s32 arg1, s32 arg2) {
    typedef char sp8_offset[(offsetof(Stack_803626A8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_803626A8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_803626A8, sp10) == 0x8) ? 1 : -1];
    Stack_803626A8 stack = { 0, 0, 0 };
    push_matrix_from((void *)&identity_matrix.value);
    post_translate_matrix((void *) (((u8 *)this) + 0x38));
    rotate_matrix_y(0, this->rotation_y);
    this->calc_joint_matrices(this->frame);
    pop_matrix();
    push_matrix_from(anim_model_matrix_array[arg2]);
    matrix_mult_vec(0, (void *)&stack.sp8, (void *)arg1);
    pop_matrix();
}
