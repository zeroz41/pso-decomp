#include "pso/object/base/TObjChara.h"
#include "types.h"
#include <stddef.h>
#include "pso/weapon/TUnk_804ECFB0.h"
#include "pso/weapon/TUnk_804A2960.h"
#include "pso/item/TUnk_804A0568.h"
#include "pso/item/TUnk_804A0588.h"
#include "pso/item/TUnk_804A05E8.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"


void TUnk_804ECFB0::update_weapon() {
    s16 lost;
    s16 tp;
    s32 half;

    if (is_current_area_item_enabled() != 0) {
        tp = get_actor_tp(owner);
        lost = owner_tp - tp;
        if (lost != 0) {
            owner_tp = tp;
        }
        if (lost > 0) {
            half = lost / 2;
            TObjectV8047c128_subtract_hp((u8 *)owner, (s16)half);
            add_actor_tp((TObjChara *)owner, (s16)half);
        }
    }
    pad_1f8 = pad_1f8 + 1;
}

void TUnk_804ECFB0::on_unequipped() {
    owner_tp = -1;
    pad_1f8 = 0;
}

// Starts the freeze, confusion and paralysis curse timers (was dark_bridge_start_timers).
void TUnk_804ECFB0::on_equipped() {
    owner_tp = get_actor_tp(owner);
    pad_1f8 = 0;
    if (effect_objects != NULL) {
        new TUnk_804A05E8(effect_objects, get_owner_client(), 9000, 0.5f);
        new TUnk_804A0588(effect_objects, get_owner_client(), 9000, 0.5f);
        new TUnk_804A0568(effect_objects, get_owner_client(), 9000, 0.5f);
    }
}

TUnk_804ECFB0::~TUnk_804ECFB0() {}

TUnk_804ECFB0::TUnk_804ECFB0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    owner_tp = -1;
    pad_1f8 = 0;
}

TItem *dark_bridge_create(u8 *item) {
    if (item != NULL) {
        return new TUnk_804ECFB0(tl_05, item);
    }
    return NULL;
}

// This object's copy of the paralysis curse timer's constructor (on_equipped
// calls it first).
TUnk_804A0568::TUnk_804A0568(TItemHeapObject *parent, u16 client, s32 period, f32 rate)
    : TItemTimerEvent(parent, client, period) {
    unk_2C = rate;
}
