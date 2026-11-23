#include "types.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A4338.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_801D2E20.h"
#include "pso/player/TObjPlayer_80128A70.h"
#include "pso/object/base/TObjBase.h"
#define SLICER_LAUNCH_STATE_OUT_OF_LINE
#include "pso/weapon/SlicerLaunchState.h"

void TUnk_804A4338::emit_marker_effects() {
    SlicerLaunchState tec;
    TObjPlayer__sub_80128A70();
    init_slicer_launch_state(&tec);
    tec.player_id = owner->get_entity_id();
    tec.item_id = get_item_id();
    tec.texlist = texlist;
    tec.model = second_model;
    tec.attack_kind = TObjPlayer__sub_801D2F4C((s16 *)&owner->attack_state);
    tec.combo_stage = owner->attack_state.get_validated_attack_stage();
    tec.damage_multiplier = owner->query_extended_state();
    tec.color.a = 1.0f;
    tec.color.r = 0.6f;
    tec.color.g = 0.5f;
    tec.color.b = 0.3f;
    tec.facing = owner->rotation_y;
    get_joint_position(1, &tec.first_joint);
    get_joint_position(2, &tec.second_joint);
    TTecSlicer::create(&tec);
}

TUnk_804A4338::TUnk_804A4338(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(2);
}

TItem *create_s_rank_slicer_weapon(u8 *owner) {
    if (owner != NULL) {
        return new TUnk_804A4338(tl_05, owner);
    }
    return NULL;
}

TUnk_804A4338::~TUnk_804A4338() {}
