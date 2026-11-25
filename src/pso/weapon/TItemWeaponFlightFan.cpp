#include "types.h"
#include "pso/weapon/TItemWeaponFlightFan.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/PlayerAttackController.h"
#include "pso/object/base/TObjBase.h"
#define SLICER_LAUNCH_STATE_OUT_OF_LINE
#include "pso/weapon/SlicerLaunchState.h"

void TItemWeaponFlightFan::transform_model_node() {
    switch (TObjPlayer::get_player_list()) {
    case 1:
        rotate_matrix_x(NULL, rotation_x);
        return;
    case 2:
        scale_current_matrix(&scale.x);
        return;
    case 3:
        rotate_matrix_x(NULL, -rotation_x);
        return;
    }
}

void TItemWeaponFlightFan::update_idle() {
    rotation_x = 0;
    scale.x = scale.y = scale.z = 1.0f;
}

void TItemWeaponFlightFan::update_attack() {
    rotation_x = 10922;
    scale.x = scale.y = scale.z = 10.0f;
}

void TItemWeaponFlightFan::emit_marker_effects() {
    SlicerLaunchState tec;

    init_slicer_launch_state(&tec);
    tec.player_id = owner->get_entity_id();
    tec.item_id = get_item_id();
    tec.texlist = texlist;
    tec.model = second_model;
    tec.attack_kind = owner->attack_state.get_validated_attack_kind();
    tec.combo_stage = owner->attack_state.get_validated_attack_stage();
    tec.damage_multiplier = owner->query_extended_state();
    tec.color.a = 1.0f;
    tec.color.r = 0.0f;
    tec.color.g = 1.0f;
    tec.color.b = 0.7f;
    tec.facing = owner->rotation_y;
    get_joint_position(5, &tec.first_joint);
    get_joint_position(4, &tec.second_joint);
    TTecSlicer::create(&tec);
}

TItemWeaponFlightFan::~TItemWeaponFlightFan() {}

TItemWeaponFlightFan::TItemWeaponFlightFan(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    rotation_x = 0;
    scale.x = scale.y = scale.z = 1.0f;
}

TItem *TObjPlayer::create_position_state(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponFlightFan(tl_05, item);
    }
    return NULL;
}
