#include "types.h"
#include "pso/weapon/TUnk_804A5A28.h"
#include "pso/item/TItem.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/weapon/TUnk_804A5B20.h"
#include "pso/player/TObjPlayer_8012D8E4.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_801D2E20.h"
#include "pso/object/base/TObjBase.h"
#define SLICER_LAUNCH_STATE_OUT_OF_LINE
#include "pso/weapon/SlicerLaunchState.h"

void enlarge_flight_cutter_slicer(void *arg0);

void TUnk_804A5A28::emit_marker_effects() {
    SlicerLaunchState tec;

    init_slicer_launch_state(&tec);
    tec.player_id = owner->get_entity_id();
    tec.item_id = get_item_id();
    tec.texlist = texlist;
    tec.model = second_model;
    tec.attack_kind = TObjPlayer__sub_801D2F4C((s16 *)&owner->attack_state);
    tec.combo_stage = owner->attack_state.get_validated_attack_stage();
    tec.damage_multiplier = owner->query_extended_state();
    tec.color.a = 1.0f;
    tec.color.r = 0.0f;
    tec.color.g = 1.0f;
    tec.color.b = 0.7f;
    tec.facing = owner->rotation_y;
    get_joint_position(3, &tec.first_joint);
    get_joint_position(2, &tec.second_joint);
    TItemAttacker::spawn_item_timer(TTecSlicer::create(&tec), (ItemTimerCallback)enlarge_flight_cutter_slicer, 3);
}

TUnk_804A5A28::~TUnk_804A5A28() {}

TUnk_804A5A28::TUnk_804A5A28(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
}

TItem *TObjPlayer::create_variant_2_5a28(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A5A28(tl_05, item);
    }
    return NULL;
}

void enlarge_flight_cutter_slicer(void *object) {
    if (object != NULL) {
        TObjBase *slicer = (TObjBase *)object;
        slicer->scale.x = 1.6f;
        slicer->scale.y = 1.6f;
        slicer->scale.z = 1.6f;
    }
}
