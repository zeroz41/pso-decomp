#include "pso/system/BmlResource.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/NinjaTypes.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/epsilon/TObjEneEpsilonGuard.h"
#include "pso/enemy/epsilon/TObjEneEpsilonBody.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/system/BmlResourceDescriptor.h"


#include <stddef.h>
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/unk/TLobby.h"
#include "pso/item/TItem.h"

Vec epsilon_zero_vector;
u8 *epsilon_guard_part_color_table[9];
BmlResource *epsilon_bml_resource;
TBreakUpMdlData *epsilon_body_breakup_model;
TBreakUpMdlData *epsilon_guard_breakup_model;

const char *bm_ene_epsilon_model_names[8] = {
    "re6_b_bcbody.nj", "re6_b_bal_body.nj", "re6_b_claw_body.nj", "bc1_bc_body.nj", "bc2_body.nj", "re6_hahen1.nj",
    "re6_b1_hahen2.nj", NULL,
};
const char *bm_ene_epsilon_motion_names[5] = {
    "body_wait_re6_b_bcbody.njm", "bal_wait_re6_b_bal_body.njm", "claw_wait_re6_b_claw_body.njm", "bc_rot_bc1_bc_body.njm", NULL,
};
BmlResourceDescriptor TObjEneEpsilonGuard__resource_descriptor = { "bm_ene_epsilon.bml", bm_ene_epsilon_model_names, bm_ene_epsilon_motion_names, 7, 4 };
TObjMotionAction epsilon_action_table[1] = { { 1, 0, 0, 0.3f, 0 } };

const char *TObjEneEpsilon__class_name = "TObjEneEpsilon";

// The original TU was compiled deferred: functions are written last-to-first.
#pragma defer_codegen on

TObjEneEpsilon::TObjEneEpsilon(TObject *parent) : TObjEneDD_ST(parent) {
    m_name = TObjEneEpsilon__class_name;
    set_state_flag_4();
}

TObjEneEpsilon::~TObjEneEpsilon() {}

void TObjEneEpsilonGuard::load_assets() {
    epsilon_zero_vector.x = 0.0f;
    epsilon_zero_vector.y = 0.0f;
    epsilon_zero_vector.z = 0.0f;
    epsilon_bml_resource = new BmlResource(1, &TObjEneEpsilonGuard__resource_descriptor, 0, 0, NULL);
    epsilon_body_breakup_model = new TBreakUpMdlData(get_bml_model(epsilon_bml_resource, 5));
    epsilon_guard_breakup_model = new TBreakUpMdlData(get_bml_model(epsilon_bml_resource, 6));
    epsilon_body_boss_stat_handle = TLobby::register_boss(0x23);
    epsilon_body_shared_handler_b = TLobby::dispatch_shared_handler_b(0x23);
    epsilon_body_registered_object_handle = TLobby::register_object(0x23);
    epsilon_body_shared_params = (EpsilonBodySharedParams *)TLobby::dispatch_shared_handler_a(0x23);
    epsilon_guard_boss_stat_handle = TLobby::register_boss(0x24);
    epsilon_guard_shared_handler_b = TLobby::dispatch_shared_handler_b(0x24);
    epsilon_guard_registered_object_handle = TLobby::register_object(0x24);
    TObjEneEpsilonGuard__movement_params = (TObjEneEpsilonGuardParams *)TLobby::dispatch_shared_handler_a(0x24);
    epsilon_guard_part_color_table[0] = (u8 *)((NJS_CNK_MODEL *)get_bml_model(epsilon_bml_resource, 0)->child->model)->polygon_list;
    epsilon_guard_part_color_table[1] = (u8 *)((NJS_CNK_MODEL *)get_bml_model(epsilon_bml_resource, 0)->child->sibling->child->child->sibling->child->child->sibling->sibling->child->model)->polygon_list;
    epsilon_guard_part_color_table[2] = (u8 *)((NJS_CNK_MODEL *)get_bml_model(epsilon_bml_resource, 0)->child->sibling->child->child->sibling->child->child->sibling->sibling->sibling->child->model)->polygon_list;
    epsilon_guard_part_color_table[3] = (u8 *)((NJS_CNK_MODEL *)get_bml_model(epsilon_bml_resource, 0)->child->sibling->child->child->sibling->child->child->sibling->sibling->sibling->sibling->child->model)->polygon_list;
    epsilon_guard_part_color_table[4] = (u8 *)((NJS_CNK_MODEL *)get_bml_model(epsilon_bml_resource, 0)->child->sibling->child->child->sibling->child->child->sibling->sibling->sibling->sibling->sibling->child->model)->polygon_list;
    epsilon_guard_part_color_table[5] = (u8 *)((NJS_CNK_MODEL *)get_bml_model(epsilon_bml_resource, 1)->child->model)->polygon_list;
    epsilon_guard_part_color_table[6] = (u8 *)((NJS_CNK_MODEL *)get_bml_model(epsilon_bml_resource, 2)->child->model)->polygon_list;
    epsilon_guard_part_color_table[8] = (u8 *)((NJS_CNK_MODEL *)get_bml_model(epsilon_bml_resource, 3)->model)->polygon_list;
    epsilon_guard_part_color_table[7] = (u8 *)((NJS_CNK_MODEL *)get_bml_model(epsilon_bml_resource, 4)->model)->polygon_list;
    TObjPlayer::init_alt_model();
    {
        NpcAnimationBinding binding = { NULL, epsilon_action_table, 0, 0, 1 };
        binding.motions = epsilon_bml_resource->motions;
        TObjNpcEnemy::register_animated_chunk(0x4E, epsilon_bml_resource->models->model, epsilon_bml_resource->models->texlist, &binding, 5.0f, 15.0f);
    }
}

void TObjEneEpsilonGuard::free_shared_resources() {
    if (epsilon_body_breakup_model != NULL) {
        delete epsilon_body_breakup_model;
        epsilon_body_breakup_model = NULL;
    }
    if (epsilon_guard_breakup_model != NULL) {
        delete epsilon_guard_breakup_model;
        epsilon_guard_breakup_model = NULL;
    }
    if (epsilon_bml_resource != NULL) {
        delete epsilon_bml_resource;
        epsilon_bml_resource = NULL;
    }
}

void TObjEneEpsilonGuard::calc_joint_position(Vec *out, s32 joint) {
    Vec origin = { 0.0f, 0.0f, 0.0f };
    push_matrix_from((void *)&identity_matrix);
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    calc_joint_matrices(frame);
    pop_matrix();
    push_matrix_from(anim_model_matrix_array[joint]);
    matrix_mult_vec(NULL, &origin, out);
    pop_matrix();
}
