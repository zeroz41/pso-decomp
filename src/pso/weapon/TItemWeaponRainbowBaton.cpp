#include "types.h"
#include <stddef.h>
#include "pso/weapon/TItemWeaponRainbowBaton.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/NinjaTypes.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerAttackController.h"
#define SLICER_LAUNCH_STATE_OUT_OF_LINE
#include "pso/weapon/SlicerLaunchState.h"

extern "C" void get_weapon_color__11TItemWeaponFPv(f32 *, void *);

void TItemWeaponRainbowBaton::emit_marker_effects() {
    f32 tmp[4];
    SlicerLaunchState launch;
    init_slicer_launch_state(&launch);
    launch.player_id = owner->get_entity_id();
    launch.item_id = get_item_id();
    launch.texlist = texlist;
    launch.model = second_model;
    launch.attack_kind = owner->attack_state.get_validated_attack_kind();
    launch.combo_stage = owner->attack_state.get_validated_attack_stage();
    launch.damage_multiplier = owner->query_extended_state();
    get_weapon_color__11TItemWeaponFPv(tmp, this);
    copy_argb(&launch.color, (NJS_ARGB *)tmp);
    launch.facing = owner->rotation_y;
    get_joint_position(2, &launch.first_joint);
    get_joint_position(1, &launch.second_joint);
    TTecSlicer::create(&launch);
}

TItemWeaponRainbowBaton::~TItemWeaponRainbowBaton() {}

TItemWeaponRainbowBaton::TItemWeaponRainbowBaton(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
}

TItem *TItemWeaponRainbowBaton::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponRainbowBaton(tl_05, item);
    }
    return NULL;
}
