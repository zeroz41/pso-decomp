#pragma readonly_strings on

#include "types.h"
#include "pso/item/armor/TItemProArmor.h"
#include "pso/item/armor/TItemProArmorParticle.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/effect/item/TItemEffArmor.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/item/TUnk_804A0668.h"
#include "pso/item/TUnk_804A0688.h"
#include "pso/item/TUnk_804A0628.h"
#include "pso/item/TUnk_804A0648.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjBase.h"


// Defined in TItemData.cpp, which has no header yet.
void *lookup_item_pmt_record(u8 *item);

const char *item_pro_armor_class_name = "TItemProArmor";

// The functions below run from the last one in the object back to the first
// (deferred code generation, see configure.py). The four timer event
// constructors at the end are this object's copies of the ones on_equip
// calls (TItemProShield and TItemProUnit call two of them too).

TUnk_804A0648::TUnk_804A0648(TItemHeapObject *parent, u16 client, s32 period) : TItemTimerEvent(parent, client, period) {}

TUnk_804A0628::TUnk_804A0628(TItemHeapObject *parent, u16 client, s32 period) : TItemTimerEvent(parent, client, period) {}

TUnk_804A0688::TUnk_804A0688(TItemHeapObject *parent, u16 client, s32 period) : TItemTimerEvent(parent, client, period) {}

TUnk_804A0668::TUnk_804A0668(TItemHeapObject *parent, u16 client, s32 period) : TItemTimerEvent(parent, client, period) {}

TItemProArmor::~TItemProArmor() {}

void TItemProArmor::load_data() {}

void TItemProArmor::free() {}

TItem *TItemProArmor::create(u8 *item) {
    if (item != NULL) {
        switch (((ArmorPmtEntry *)lookup_item_pmt_record(item))->model_type) {
        case 0:
        case 1:
            return new TItemProArmor(tl_05, item);
        case 2:
            return new TItemProArmorParticle(tl_05, item);
        }
    }
    return NULL;
}

TItemProArmor::TItemProArmor(TObject *parent, u8 *item) : TItemEquipBase(parent, item) {
    m_name = item_pro_armor_class_name;
    set_attach_slot(2);
    armor_flags = 0;
    slot_count = item[5];
    dfp_bonus = TItemData::getS16_06(item);
    evp_bonus = TItemData::get_bswap16_field8(item);
    pmt = (ArmorPmtEntry *)lookup_item_pmt_record(item);
    dfp_range = pmt->dfp_range;
    evp_range = pmt->evp_range;
    if (slot_count > ARMOR_MAX_SLOTS) {
        slot_count = ARMOR_MAX_SLOTS;
    }
    apply_armor_effect_flags();
}

void TItemProArmor::request_equipped_model() {
    if (is_hidden() == 0) {
        TObjPlayer::spawn_appearance_effect(owner->get_entity_id());
    }
}

void TItemProArmor::update_equipped() {
    if (armor_flags & ARMOR_FLAG_REFRESH_STATS) {
        refresh_owner_stats();
    }
}

void TItemProArmor::on_equip() {
    if (effect_objects == NULL) {
        return;
    }
    switch (get_item_index()) {
    case 27:
        new TUnk_804A0648(effect_objects, get_owner_client(), 150);
        break;
    case 28:
        new TUnk_804A0628(effect_objects, get_owner_client(), 300);
        break;
    case 32:
        new TUnk_804A0688(effect_objects, get_owner_client(), 300);
        break;
    case 33:
        new TUnk_804A0688(effect_objects, get_owner_client(), 240);
        break;
    case 34:
        new TUnk_804A0688(effect_objects, get_owner_client(), 210);
        break;
    case 43:
        new TUnk_804A0688(effect_objects, get_owner_client(), 150);
        break;
    case 49:
        new TUnk_804A0668(effect_objects, get_owner_client(), 150);
        break;
    case 45:
        new TItemEffArmorPulse(effect_objects, get_owner_client());
        break;
    }
}

void TItemProArmor::write_item_data(TItemData *data) {
    data->data1.data_u8[5] = slot_count;
    data->set_dfp_bonus(dfp_bonus);
    data->set_bswapped_field_8(evp_bonus);
}

void TItemProArmor::update_owned() {
    if (dfp_range < dfp_bonus) {
        dfp_bonus = 0;
    }
    if (evp_range < evp_bonus) {
        evp_bonus = 0;
    }
}

u8 TItemProArmor::get_slot_count() { return slot_count; }

void TItemProArmor::add_slot() {
    if (slot_count < ARMOR_MAX_SLOTS) {
        slot_count++;
    }
}

void TItemProArmor::carry_over_stats(TItemData *data, TItem *item) {
    data->data1.data_u8[5] = ((TItemProArmor *)item)->slot_count;
}

void TItemProArmor::apply_armor_effect_flags() {
    switch (get_item_index()) {
    case 0x23:
        effect_flags.set(0x2);
        break;
    case 0x33:
        effect_flags.set(0x200);
        break;
    }
    switch (pmt->model_type) {
    case 0:
        break;
    case 1:
        armor_flags |= ARMOR_FLAG_REFRESH_STATS;
        break;
    case 2:
        break;
    }
}
