#ifndef PSO_ITEM_TITEMPROSHIELD_H
#define PSO_ITEM_TITEMPROSHIELD_H

#include "types.h"

struct TItem;
struct TItemData;
#include "pso/item/TItemEquipBase.h"

struct TItemProShield : public TItemEquipBase {
    // Copies what an item of this class keeps when it is replaced by a new
    // item code (replace_item_with_new_code) into the new item's data.
    static void carry_over_stats(TItemData *data, TItem *item);
    virtual ~TItemProShield();
    virtual void vfunc_51();
    virtual void on_equip();
    virtual void vfunc_26();
    virtual void perform_action();
    virtual void on_unequip();
    virtual void request_equipped_model();
    virtual void vfunc_16();
    virtual void vfunc_14();
    void sub_80117FEC();
    u32 m_18c;
    u32 m_190;
    u32 m_194;
    u8 m_198;
    u8 m_199;
    u8 m_19a;
    u8 m_19b;
    u32 m_19c;
    s16 get_field_2b8();
    static void create_shield_effect(s32 arg0, u16 arg1, u32 arg2);
    u8 *create();
    void deactivate_shield_effect(s32 arg1);
    u8 *create_instance();
    static void free();
    static void load_data();
};

typedef char TItemProShield_size[sizeof(TItemProShield) == 0x1A0 ? 1 : -1];
#endif
