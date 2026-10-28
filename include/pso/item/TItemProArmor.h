#ifndef PSO_ITEM_TITEMPROARMOR_H
#define PSO_ITEM_TITEMPROARMOR_H

#include "types.h"

struct TItem;
struct TItemData;
#include "pso/item/TItemEquipBase.h"

struct TItemProArmor : public TItemEquipBase {
    // Copies what an item of this class keeps when it is replaced by a new
    // item code (replace_item_with_new_code) into the new item's data.
    static void carry_over_stats(TItemData *data, TItem *item);
    virtual ~TItemProArmor();
    virtual void update_equipped();
    virtual void update_owned();
    virtual u8 get_slot_count();
    virtual void add_slot();
    virtual void request_equipped_model();
    virtual void on_equip();
    u32 m_18c;
    u16 m_190;
    u8 m_192;
    u8 m_193;
    u8 m_194;
    u8 m_195;
    u8 m_196;
    u8 *create_instance();
    void init_effect_flags();
    s32 create_armor_object();
    int get_stat_value();
    static s16 calc_scaled_offset();
    static s16 calc_armor_value();
    void apply_armor_stat();
    u8 *create();
    u8 unk_197[0x1];
};

typedef char TItemProArmor_size[sizeof(TItemProArmor) == 0x198 ? 1 : -1];
#endif
