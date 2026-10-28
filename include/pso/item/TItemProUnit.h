#ifndef PSO_ITEM_TITEMPROUNIT_H
#define PSO_ITEM_TITEMPROUNIT_H

#include "types.h"

struct TItem;
struct TItemData;
#include "pso/item/TItemEquipBase.h"

struct TItemProUnit : public TItemEquipBase {
    // Copies what an item of this class keeps when it is replaced by a new
    // item code (replace_item_with_new_code) into the new item's data.
    static void carry_over_stats(TItemData *data, TItem *item);
    virtual ~TItemProUnit();
    virtual void update_owned();
    virtual void update_equipped();
    void remove_owner_bonuses();
    void apply_owner_bonuses();
    void on_unequip();
    void on_equip();
    u8 unk_18C[0x2];
    s16 m_18e;
    u8 unk_190[0x12];
    s16 m_1bc;
    s16 m_1be;
    static u8 *create(u8 *arg0);
    void set_evp(f32 v);
    void apply_unit_effect_flags();
};

#endif
