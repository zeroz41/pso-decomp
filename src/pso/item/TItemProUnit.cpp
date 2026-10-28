#pragma readonly_strings on

#include "types.h"
#include "pso/item/TItemProUnit.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/item/TUnk_804A0608.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8011C000.h"
#include "pso/system/FlagWord.h"
#include "pso/unk/text_801D98F8.h"
#include "pso/TMainTask.h"

extern "C" {
// Defined in TItemData.cpp and text_801D9870.cpp, which have no headers yet.
void *lookup_item_pmt_record(u8 *item);
u8 get_cast_technique_level(void *levels, s16 technique);
void *memset(void *dst, int value, unsigned long size);
// The timer events a unit effect starts. Their classes are still written as
// C functions on the raw object (TItemTimerEvent has no real constructor).
void init_item_timer_event__13TUnk_804A0648Fv(void *event, TItemHeapObject *parent, u16 client, s32 duration);
void construct_timer_event__13TUnk_804A0628Fv(void *event, TItemHeapObject *parent, u16 client, s32 duration);
void init_timer_event__13TUnk_804A0608Fv(void *event, TItemHeapObject *parent, u16 client, s32 duration);
void TItemTimerEvent__ct(void *event);
extern s32 lbl_804A0608[];
}

const char *item_pro_unit_class_name = "TItemProUnit";

// The functions below run from the last one in the object back to the first
// (deferred code generation, see configure.py).

void *TUnk_804A0608::init_timer_event() {
    TItemTimerEvent__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A0608;
    return this;
}

// The out-of-line copies of PlayerAttackState's EVP scale accessors.
f32 PlayerAttackState::get_evp() { return evp_scale; }

void PlayerAttackState::set_evp(f32 scale) { evp_scale = scale; }

TItemProUnit::~TItemProUnit() {}

void TItemProUnit::load_data() {}

void TItemProUnit::free() {}

TItem *TItemProUnit::create(u8 *item) {
    if (item != NULL) {
        return new TItemProUnit(tl_05, item);
    }
    return NULL;
}

TItemProUnit::TItemProUnit(TObject *parent, u8 *item) : TItemEquipBase(parent, item) {
    UnitPmtEntry *pmt;
    m_name = item_pro_unit_class_name;
    set_attach_slot(item[4] + 9);
    technique_bonus = 0;
    evp_scale = 1.0f;
    pmt = (UnitPmtEntry *)lookup_item_pmt_record(item);
    if (pmt != NULL) {
        effect_type = pmt->stat;
        effect_amount = pmt->stat_amount;
        modifier_limit = pmt->modifier_amount * 2;
    } else {
        effect_type = 0;
        effect_amount = 0;
        modifier_limit = 0;
    }
    modifier = TItemData::get_field6_bswap(item);
    if ((modifier <= -10) || (modifier >= 10)) {
        modifier = 0;
    }
    memset(technique_added, 0, sizeof(technique_added));
    apply_unit_effect_flags();
}

void TItemProUnit::apply_unit_effect_flags() {
    switch (effect_type) {
    case UNIT_EFFECT_TECHNIQUE_LEVELS:
        technique_bonus = effect_amount;
        return;
    case 20:
        effect_flags.set(0x8);
        return;
    case 21:
        effect_flags.set(0x2);
        return;
    case UNIT_EFFECT_EVP_SCALE:
        evp_scale = 1.0f + (f32)effect_amount / 100.0f;
        return;
    case 22:
        effect_flags.set(0x80);
        return;
    case 23:
        effect_flags.set(0x200);
        return;
    case 24:
        effect_flags.set(0x800);
        return;
    case 25:
        effect_flags.set(0x2000);
        return;
    case 26:
        effect_flags.set(0x8000);
        return;
    case 27:
        effect_flags.set(0x20000);
    default:
        return;
    }
}

void TItemProUnit::on_equip() {
    void *event;
    switch (effect_type) {
    case 15:
        if (effect_objects != NULL) {
            event = TItemHeapObject::operator new(0x2C);
            if (event != NULL) {
                init_item_timer_event__13TUnk_804A0648Fv(event, effect_objects, get_owner_client(),
                                                         (s32)(30.0f * effect_amount));
            }
        }
        break;
    case 16:
        if (effect_objects != NULL) {
            event = TItemHeapObject::operator new(0x2C);
            if (event != NULL) {
                construct_timer_event__13TUnk_804A0628Fv(event, effect_objects, get_owner_client(),
                                                         (s32)(30.0f * effect_amount));
            }
        }
        break;
    case 17:
        if (effect_objects != NULL) {
            event = TItemHeapObject::operator new(0x2C);
            if (event != NULL) {
                init_timer_event__13TUnk_804A0608Fv(event, effect_objects, get_owner_client(),
                                                    (s32)(30.0f * effect_amount));
            }
        }
        break;
    }
}

// Built without common subexpression elimination: the owner is reloaded for
// every technique.
#pragma push
#pragma opt_common_subs off
void TItemProUnit::apply_owner_bonuses() {
    u8 level;
    s16 i;
    u8 limit;
    s16 bonus;
    u8 total;
    if (technique_bonus != 0) {
        for (i = 0; i != 19; i++) {
            if (i == 14 || i == 17) {
                continue;
            }
            level = get_cast_technique_level(owner->technique_levels, i);
            if (level != 0xFF) {
                // Called with the class byte unextended: this TU saw the
                // limit lookup as taking two u8s.
                limit = ((u8 (*)(u8, u8))get_technique_learn_limit)(owner->m_88d, (u8)i);
                bonus = technique_bonus;
                total = level + bonus;
                if (limit < total) {
                    technique_added[i] = bonus + limit - total;
                    total = limit;
                } else {
                    technique_added[i] = bonus;
                }
                set_technique_level_entry(owner->technique_levels, i, total);
            }
        }
    }
}
#pragma pop

void TItemProUnit::update_equipped() {
    if (effect_type == UNIT_EFFECT_EVP_SCALE) {
        if (((PlayerAttackState *)&owner->attack_state)->get_evp() < evp_scale) {
            ((PlayerAttackState *)&owner->attack_state)->set_evp(evp_scale);
        }
    }
}

void TItemProUnit::on_unequip() { set_attach_slot(9); }

void TItemProUnit::remove_owner_bonuses() {
    s32 i;
    if (effect_type == UNIT_EFFECT_EVP_SCALE) {
        ((PlayerAttackState *)&owner->attack_state)->set_evp(1.0f);
    }
    i = 0;
    do {
        set_technique_level_entry(owner->technique_levels, (s16)i,
                                  (u8)(get_cast_technique_level(owner->technique_levels, (s16)i) - technique_added[i]));
        i += 1;
    } while (i != 19);
    memset(technique_added, 0, sizeof(technique_added));
}

void TItemProUnit::write_item_data(TItemData *data) {
    data->data1.data_u8[4] = (s8)get_attach_slot() - 9;
    data->set_unit_modifier(modifier);
}

void TItemProUnit::update_owned() {
    if ((modifier_limit < modifier) || (modifier < -modifier_limit)) {
        modifier = 0;
    }
}

void TItemProUnit::carry_over_stats(TItemData *, TItem *) {}
