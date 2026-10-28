#pragma readonly_strings on

#include "types.h"
#include "pso/item/TItemProArmor.h"
#include "pso/item/TItemProArmorParticle.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/item/TItemEffArmor_80107DA4.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/item/TUnk_804A0668.h"
#include "pso/item/TUnk_804A0688.h"
#include "pso/player/TUnk_804A0628.h"
#include "pso/player/TUnk_804A0648.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/FlagWord.h"
#include "pso/TMainTask.h"

extern "C" {
// Defined in TItemData.cpp, which has no header yet.
void *lookup_item_pmt_record(u8 *item);
// The timer events an armor starts. Their classes are still written as C
// functions on the raw object (TItemTimerEvent has no real constructor).
void init_item_timer_event__13TUnk_804A0648Fv(void *event, TItemHeapObject *parent, u16 client, s32 duration);
void construct_timer_event__13TUnk_804A0628Fv(void *event, TItemHeapObject *parent, u16 client, s32 duration);
void ct__13TUnk_804A0688Fv(void *event, TItemHeapObject *parent, u16 client, s32 duration);
void init_vtable__13TUnk_804A0668Fv(void *event, TItemHeapObject *parent, u16 client, s32 duration);
void TItemTimerEvent__ct(void *event);
extern s32 lbl_804A0628[];
extern s32 lbl_804A0648[];
extern s32 lbl_804A0668[];
extern s32 lbl_804A0688[];
}

const char *item_pro_armor_class_name = "TItemProArmor";

// The functions below run from the last one in the object back to the first
// (deferred code generation, see configure.py). The four timer event
// constructors at the end are this object's copies of the ones on_equip
// calls (TItemProShield and TItemProUnit call two of them too).

void *TUnk_804A0648::init_item_timer_event() {
    TItemTimerEvent__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A0648;
    return this;
}

void *TUnk_804A0628::construct_timer_event() {
    TItemTimerEvent__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A0628;
    return this;
}

void *TUnk_804A0688::ct() {
    TItemTimerEvent__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A0688;
    return this;
}

void *TUnk_804A0668::init_vtable() {
    TItemTimerEvent__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A0668;
    return this;
}

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
        TObjPlayer::spawn_appearance_effect(get_entity_id(owner));
    }
}

void TItemProArmor::update_equipped() {
    if (armor_flags & ARMOR_FLAG_REFRESH_STATS) {
        refresh_owner_stats();
    }
}

void TItemProArmor::on_equip() {
    void *event;
    if (effect_objects == NULL) {
        return;
    }
    switch (get_item_index()) {
    case 27:
        event = TItemHeapObject::operator new(0x2C);
        if (event != NULL) {
            init_item_timer_event__13TUnk_804A0648Fv(event, effect_objects, get_owner_client(), 150);
        }
        break;
    case 28:
        event = TItemHeapObject::operator new(0x2C);
        if (event != NULL) {
            construct_timer_event__13TUnk_804A0628Fv(event, effect_objects, get_owner_client(), 300);
        }
        break;
    case 32:
        event = TItemHeapObject::operator new(0x2C);
        if (event != NULL) {
            ct__13TUnk_804A0688Fv(event, effect_objects, get_owner_client(), 300);
        }
        break;
    case 33:
        event = TItemHeapObject::operator new(0x2C);
        if (event != NULL) {
            ct__13TUnk_804A0688Fv(event, effect_objects, get_owner_client(), 240);
        }
        break;
    case 34:
        event = TItemHeapObject::operator new(0x2C);
        if (event != NULL) {
            ct__13TUnk_804A0688Fv(event, effect_objects, get_owner_client(), 210);
        }
        break;
    case 43:
        event = TItemHeapObject::operator new(0x2C);
        if (event != NULL) {
            ct__13TUnk_804A0688Fv(event, effect_objects, get_owner_client(), 150);
        }
        break;
    case 49:
        event = TItemHeapObject::operator new(0x2C);
        if (event != NULL) {
            init_vtable__13TUnk_804A0668Fv(event, effect_objects, get_owner_client(), 150);
        }
        break;
    case 45:
        event = TObject::operator new(0x24);
        if (event != NULL) {
            fn_80107DA4((u8 *)event, (u8 *)effect_objects, get_owner_client());
        }
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
