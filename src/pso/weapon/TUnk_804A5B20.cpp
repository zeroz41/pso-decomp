#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/weapon/TUnk_804A5B20.h"
#include "pso/player/TObjPlayer_8012D8E4.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/item/TItem.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/weapon/SlicerLaunchState.h"
#include "pso/object/base/TObjBase.h"


void TUnk_804A5B20::vfunc_60() {
    s32 player_list;

    switch (get_item_index()) {
    case 5:
        player_list = TObjPlayer::get_player_list();
        switch (player_list) {
        case 1:
            rotate_matrix_x(0, rotation);
            return;
        case 2:
            scale_current_matrix(&scale.x);
            return;
        }
        break;
    case 7:
        switch (TObjPlayer::get_player_list()) {
        case 4:
            post_translate_matrix(&scale.x);
            return;
        case 2:
            rotate_matrix_z(0, rotation);
            break;
        }
        break;
    }
}

extern "C" {
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
void get_weapon_color__11TItemWeaponFPv(f32 *, void *);
}

void TUnk_804A5B20::emit_marker_effects() {
    f32 tmp[4];
    SlicerLaunchState launch;
    init_slicer_launch_state(&launch);
    launch.player_id = owner->get_entity_id();
    launch.item_id = get_item_id();
    launch.texlist = texlist;
    launch.model = second_model;
    launch.attack_kind = TObjPlayer__sub_801D2F4C((s16 *)((u8 *)owner + 0x7CC));
    launch.combo_stage = owner->attack_state.get_validated_attack_stage();
    launch.damage_multiplier = owner->query_extended_state();
    get_weapon_color__11TItemWeaponFPv(tmp, this);
    copy_argb(&launch.color, (NJS_ARGB *)tmp);
    launch.facing = owner->rotation_y;
    get_joint_position(1, &launch.first_joint);
    get_joint_position(2, &launch.second_joint);
    TTecSlicer::create(&launch);
}

void TUnk_804A5B20::update_idle() {
    int new_var;
    switch (get_item_index()) {
    case 5:
        ::add_angle_clamped(&rotation, 0x1555, 0x8000);
        new_var = 0x8000;
        if (new_var <= rotation) {
            ::approach_value(&scale.z, -0.1f, 0.6f);
        }
        break;
    case 6:
        break;
    case 7:
        ::approach_value(&scale.z, -0.7f, -2.8f);
        ::add_angle_clamped(&rotation, -0x1555, -0x8000);
        break;
    }
}

void TUnk_804A5B20::update_attack() {
    switch (get_item_index()) {
    case 5:
        ::approach_value(&scale.z, 0.2f, 1.0f);
        if (1.0f <= scale.z) {
            ::add_angle_clamped(&rotation, -0x2AAA, 0);
        }
    case 6:
        return;
    case 7:
        ::approach_value(&scale.z, 1.6f, 0.0f);
        ::add_angle_clamped(&rotation, 0x2AAA, 0);
        break;
    }
}

TUnk_804A5B20::TUnk_804A5B20(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    rotation = 0;
    switch (item[2]) {
    case 6:
        break;
    case 5:
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;
        break;
    case 7:
        scale.x = 0.0f;
        scale.y = 0.0f;
        scale.z = 0.0f;
        break;
    }
}

TItem *create_slicer_weapon(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A5B20(tl_05, item);
    }
    return NULL;
}

TUnk_804A5B20::~TUnk_804A5B20() {}
