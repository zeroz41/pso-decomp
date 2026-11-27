#include "pso/object/base/TObjChara.h"
#include "types.h"
#include <stddef.h>
#include "pso/weapon/TItemWeaponDarkBridge.h"
#include "pso/weapon/TItemWeaponFrozenShooter.h"
#include "pso/item/TItemTimerEventParalysisCurse.h"
#include "pso/item/TItemTimerEventConfusionCurse.h"
#include "pso/item/TItemTimerEventFreezeCurse.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"


void TItemWeaponDarkBridge::update_weapon() {
    s16 lost;
    s16 tp;
    s32 half;

    if (is_current_area_item_enabled() != 0) {
        tp = owner->get_actor_tp();
        lost = owner_tp - tp;
        if (lost != 0) {
            owner_tp = tp;
        }
        if (lost > 0) {
            half = lost / 2;
            subtract_actor_hp(owner, (s16)half);
            add_actor_tp(owner, half);
        }
    }
    update_count = update_count + 1;
}

void TItemWeaponDarkBridge::on_unequipped() {
    owner_tp = -1;
    update_count = 0;
}

// Starts the freeze, confusion and paralysis curse timers (was dark_bridge_start_timers).
void TItemWeaponDarkBridge::on_equipped() {
    owner_tp = owner->get_actor_tp();
    update_count = 0;
    if (effect_objects != NULL) {
        new TItemTimerEventFreezeCurse(effect_objects, get_owner_client(), 9000, 0.5f);
        new TItemTimerEventConfusionCurse(effect_objects, get_owner_client(), 9000, 0.5f);
        new TItemTimerEventParalysisCurse(effect_objects, get_owner_client(), 9000, 0.5f);
    }
}

TItemWeaponDarkBridge::~TItemWeaponDarkBridge() {}

TItemWeaponDarkBridge::TItemWeaponDarkBridge(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    owner_tp = -1;
    update_count = 0;
}

TItem *TItemWeaponDarkBridge::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponDarkBridge(tl_05, item);
    }
    return NULL;
}

// This object's copy of the paralysis curse timer's constructor (on_equipped
// calls it first).
TItemTimerEventParalysisCurse::TItemTimerEventParalysisCurse(TItemHeapObject *parent, u16 client, s32 period, f32 rate)
    : TItemTimerEvent(parent, client, period) {
    chance = rate;
}
