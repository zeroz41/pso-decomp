#include "types.h"
#include <stddef.h>
#include "pso/weapon/TUnk_804ECDC0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/NinjaTypes.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/TObjPlayer_801D2E20.h"
#define SLICER_LAUNCH_STATE_OUT_OF_LINE
#include "pso/weapon/SlicerLaunchState.h"

extern "C" void get_weapon_color__11TItemWeaponFPv(f32 *, void *);

void TUnk_804ECDC0::emit_marker_effects() {
    f32 tmp[4];
    SlicerLaunchState launch;
    init_slicer_launch_state(&launch);
    launch.player_id = owner->get_entity_id();
    launch.item_id = get_item_id();
    launch.texlist = texlist;
    launch.model = second_model;
    launch.attack_kind = TObjPlayer__sub_801D2F4C((s16 *)&owner->attack_state);
    launch.combo_stage = owner->attack_state.get_validated_attack_stage();
    launch.damage_multiplier = owner->query_extended_state();
    get_weapon_color__11TItemWeaponFPv(tmp, this);
    copy_argb(&launch.color, (NJS_ARGB *)tmp);
    launch.facing = owner->rotation_y;
    get_joint_position(2, &launch.first_joint);
    get_joint_position(1, &launch.second_joint);
    TTecSlicer::create(&launch);
}

TUnk_804ECDC0::~TUnk_804ECDC0() {}

TUnk_804ECDC0::TUnk_804ECDC0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
}

TItem *TObjPlayer__sub_803265C0(u8 *item) {
    if (item != NULL) {
        return new TUnk_804ECDC0(tl_05, item);
    }
    return NULL;
}
