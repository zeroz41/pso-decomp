#include "pso/system/BmlResource.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/NinjaTypes.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/MatrixOps.h"
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

class V_8036274C {
public:
    u8 pad[0xC];
    virtual ~V_8036274C();
};

extern "C" {
s32 matrix_mult_vec(int, void *, void *);
s32 rotate_matrix_y(int, int);
f32 post_translate_matrix(void *);

s32 TObjPlayer__sub_800F0928(void *);
f32 lbl_80543A18[3];
s32 epsilon_guard_part_color_table[9];
extern s32 TObjEneEpsilonGuard__movement_params;
extern s32 lbl_805D6F80;
extern s32 lbl_805D6F84;
extern s32 lbl_805D6F88;
extern s32 lbl_805D6F8C;
u8 *lbl_805D6FA0;
u8 *lbl_805D6FA4;
u8 *lbl_805D6FA8;


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

const char *TObjEneEpsilon__class_name = "TObjEneEpsilon";

// The original TU was compiled deferred: functions are written last-to-first.
#pragma defer_codegen on

TObjEneEpsilon::TObjEneEpsilon(TObject *parent) : TObjEneDD_ST(parent) {
    m_name = TObjEneEpsilon__class_name;
    set_state_flag_4();
}

TObjEneEpsilon::~TObjEneEpsilon() {}

void TObjEneEpsilonGuard::load_assets() {
    u8 *p;
    lbl_80543A18[0] = 0.0f;
    lbl_80543A18[1] = 0.0f;
    lbl_80543A18[2] = 0.0f;
    p = (u8 *)new BmlResource(1, &TObjEneEpsilonGuard__resource_descriptor, 0, 0, NULL);
    lbl_805D6FA0 = p;
    p = (u8 *)new TUnk_8048FA00((saddr)(get_bml_model((BmlResource *)lbl_805D6FA0, 5)));
    lbl_805D6FA4 = p;
    p = (u8 *)new TUnk_8048FA00((saddr)(get_bml_model((BmlResource *)lbl_805D6FA0, 6)));
    lbl_805D6FA8 = p;
    lbl_805D6F80 = (saddr)TLobby::register_boss(0x23);
    lbl_805D6F84 = (saddr)TLobby::dispatch_shared_handler_b(0x23);
    lbl_805D6F88 = (saddr)TLobby::register_object(0x23);
    lbl_805D6F8C = (saddr)TLobby::dispatch_shared_handler_a(0x23);
    epsilon_guard_boss_stat_handle = (u8 *)TLobby::register_boss(0x24);
    epsilon_guard_shared_handler_b = (u8 *)TLobby::dispatch_shared_handler_b(0x24);
    epsilon_guard_registered_object_handle = (u8 *)TLobby::register_object(0x24);
    TObjEneEpsilonGuard__movement_params = (saddr)TLobby::dispatch_shared_handler_a(0x24);
    epsilon_guard_part_color_table[0] = ((Leaf_803627DC *)get_bml_model((BmlResource *)lbl_805D6FA0, 0)->child->model)->v;
    epsilon_guard_part_color_table[1] = ((Leaf_803627DC *)get_bml_model((BmlResource *)lbl_805D6FA0, 0)->child->sibling->child->child->sibling->child->child->sibling->sibling->child->model)->v;
    epsilon_guard_part_color_table[2] = ((Leaf_803627DC *)get_bml_model((BmlResource *)lbl_805D6FA0, 0)->child->sibling->child->child->sibling->child->child->sibling->sibling->sibling->child->model)->v;
    epsilon_guard_part_color_table[3] = ((Leaf_803627DC *)get_bml_model((BmlResource *)lbl_805D6FA0, 0)->child->sibling->child->child->sibling->child->child->sibling->sibling->sibling->sibling->child->model)->v;
    epsilon_guard_part_color_table[4] = ((Leaf_803627DC *)get_bml_model((BmlResource *)lbl_805D6FA0, 0)->child->sibling->child->child->sibling->child->child->sibling->sibling->sibling->sibling->sibling->child->model)->v;
    epsilon_guard_part_color_table[5] = ((Leaf_803627DC *)get_bml_model((BmlResource *)lbl_805D6FA0, 1)->child->model)->v;
    epsilon_guard_part_color_table[6] = ((Leaf_803627DC *)get_bml_model((BmlResource *)lbl_805D6FA0, 2)->child->model)->v;
    epsilon_guard_part_color_table[8] = ((Leaf_803627DC *)get_bml_model((BmlResource *)lbl_805D6FA0, 3)->model)->v;
    epsilon_guard_part_color_table[7] = ((Leaf_803627DC *)get_bml_model((BmlResource *)lbl_805D6FA0, 4)->model)->v;
    TObjPlayer__sub_800F0928(epsilon_guard_part_color_table);
    {
        NpcAnimationBinding q = { NULL, reinterpret_cast<TObjMotionAction *>(&lbl_804F252C), 0, 0, 1 };
        q.motions = reinterpret_cast<BmlMotionEntry *>(((Res_803627DC *)lbl_805D6FA0)->f430);
        NpcModelRegistry::register_animated_chunk((s16)0x4E, reinterpret_cast<void *>((((Res_803627DC *)lbl_805D6FA0)->f42c->f8)), reinterpret_cast<void *>(((Res_803627DC *)lbl_805D6FA0)->f42c->texlist), &q, 5.0f, 15.0f);
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
        delete (BmlResource *)(*(uaddr *)&lbl_805D6FA0);
        (*(u32 *)&lbl_805D6FA0) = 0;
    }
}

void TObjEneEpsilonGuard::sub_803626A8(saddr arg1, s32 arg2) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_803626A8, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_803626A8, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_803626A8, sp10) == 0x8);
    Stack_803626A8 stack = { 0, 0, 0 };
    push_matrix_from((void *)&identity_matrix);
    post_translate_matrix((void *) (((u8 *)this) + 0x38));
    rotate_matrix_y(0, this->rotation_y);
    this->calc_joint_matrices(this->frame);
    pop_matrix();
    push_matrix_from(anim_model_matrix_array[arg2]);
    matrix_mult_vec(0, (void *)&stack.sp8, (void *)arg1);
    pop_matrix();
}
