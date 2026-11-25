#include "pso/item/TItemData.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeaponSealedJSword.h"
#include "pso/item/TUnk_804A05A8.h"
#include "types.h"
#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/item/armor/TItemProArmor.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/weapon/TItemWeaponFlightCutter.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponSealedJSword::use() {
    TItemData item_data;
    if (get_kill_count() >= 0x59D8U) {
        item_data.data1.data_u8[0] = 0;
        item_data.data1.data_u8[1] = 0x32;
        item_data.data1.data_u8[2] = 0;
        replace_item_with_new_code(&item_data, this);
    }
}

void TItemWeaponSealedJSword::update_weapon() {
    if (kill_count_seen < owner->get_kill_count()) {
        set_kill_count(get_kill_count() + 1);
        kill_count_seen = owner->get_kill_count();
    }
    if (get_kill_count() >= 0x59D8U && test_item_flags(0x200) == 0) {
        add_item_flags(0x200);
    }
}

void TItemWeaponSealedJSword::on_equipped() {
    if (effect_objects != NULL) {
        new TUnk_804A05A8(effect_objects, get_owner_client(), 0xE10, 0.25f);
    }
    kill_count_seen = owner->get_kill_count();
}

TItemWeaponSealedJSword::~TItemWeaponSealedJSword() {}

TItemWeaponSealedJSword::TItemWeaponSealedJSword(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

TItem *TItemWeaponSealedJSword::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSealedJSword(tl_05, item);
    }
    return NULL;
}

s16 TObjPlayer::get_kill_count() { return this->m_11a; }


// This object's copy of the slow curse timer's constructor (on_equipped calls
// it first).
TUnk_804A05A8::TUnk_804A05A8(TItemHeapObject *parent, u16 client, s32 period, f32 rate)
    : TItemTimerEvent(parent, client, period) {
    unk_2C = rate;
}
