#include "types.h"
#include "pso/weapon/TItemWeaponYamigarasu.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/item/TUnk_804A0588.h"
#include "pso/item/TUnk_804A0688.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponYamigarasu::on_equipped() {
    if (effect_objects != NULL) {
        new TUnk_804A0588(effect_objects, get_owner_client(), 0xE10, 0.25f);
        new TUnk_804A0688(effect_objects, get_owner_client(), 0x5A);
    }
}

TItemWeaponYamigarasu::~TItemWeaponYamigarasu() {}

TItemWeaponYamigarasu::TItemWeaponYamigarasu(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

TItem *TItemWeaponYamigarasu::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponYamigarasu(tl_05, item);
    }
    return NULL;
}

// This object's copy of the confusion curse timer's constructor (on_equipped
// calls it first).
TUnk_804A0588::TUnk_804A0588(TItemHeapObject *parent, u16 client, s32 period, f32 rate)
    : TItemTimerEvent(parent, client, period) {
    unk_2C = rate;
}
