#ifndef PSO_ITEM_TITEMPROUNIT_H
#define PSO_ITEM_TITEMPROUNIT_H

#include "types.h"
#include "pso/item/TItemEquipBase.h"

struct TItem;
struct TItemData;

// A unit's ItemPMT record (lookup_item_pmt_record): the effect it gives and
// how far its +/- modifier may go.
struct UnitPmtEntry {
    u32 id;
    u16 type;
    u16 skin;
    s16 stat;
    s16 stat_amount;
    s16 modifier_amount;
};

// The stat values of TItemProUnit::effect_type with a known effect (15-17
// start timer events, 20-27 set effect_flags bits).
enum {
    UNIT_EFFECT_TECHNIQUE_LEVELS = 18,
    UNIT_EFFECT_EVP_SCALE = 19,
};

// An equipped unit: a stat effect from its ItemPMT record, a +/- modifier
// kept in the item data, and the technique levels it adds to its owner.
struct TItemProUnit : public TItemEquipBase {
    TItemProUnit(TObject *parent, u8 *item);
    virtual ~TItemProUnit();
    virtual void update_owned();
    virtual void update_equipped();
    virtual void write_item_data(TItemData *data);
    virtual void on_equip();
    virtual void on_unequip();
    virtual void apply_owner_bonuses();
    virtual void remove_owner_bonuses();

    // Copies what an item of this class keeps when it is replaced by a new
    // item code (replace_item_with_new_code) into the new item's data.
    static void carry_over_stats(TItemData *data, TItem *item);
    // The unit entry of construct_item's table: NULL without data.
    static TItem *create(u8 *item);
    // The unit entries of the item class load/unload table (nothing to do).
    static void free();
    static void load_data();
    // Sets what the unit's stat effect asks for: the technique bonus, the
    // EVP scale or an effect_flags bit.
    void apply_unit_effect_flags();

    s16 effect_type;             // UnitPmtEntry::stat
    s16 effect_amount;           // UnitPmtEntry::stat_amount
    s16 technique_bonus;         // added to each technique level while equipped
    s16 technique_added[19];     // what apply_owner_bonuses really added
    f32 evp_scale;               // the owner's PlayerAttackState::evp_scale floor
    s16 modifier;                // the item data's unit modifier
    s16 modifier_limit;          // twice UnitPmtEntry::modifier_amount
};

typedef char TItemProUnit_size[sizeof(TItemProUnit) == 0x1C0 ? 1 : -1];
typedef char TItemProUnitModifierOffset[(offsetof(TItemProUnit, modifier) == 0x1BC) ? 1 : -1];

#endif
