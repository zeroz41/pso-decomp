#ifndef PSO_PLAYER_TPLYINVENTORY_H
#define PSO_PLAYER_TPLYINVENTORY_H

#include "types.h"
#include "pso/macros.h"
#include "pso/network/protocol/protocol.h"

#include "pso/item/TItemData.h"

class TPlyInventoryItem {
public:
    void init();
    void bswap();
    TItemData *get_data();
    void clear_equipped();
    void clear();
public:
    char m_present[4];
    u32 m_flags;
    TItemData m_data;
};

class TPlyInventory {
public:
    void bswap();
    TPlyInventoryItem *get_items();
    TPlyInventoryItem *get_item(s32 index);
    u8 get_item_count();
    TItemData *get_item_data(s32 index);
    void clear_item(s32 index);
    // Clears the equipped flag of every unit.
    void unequip_units();
    // Puts item in a freed slot at the end; 0 when all 30 slots are used.
    s32 append_item(TItemData *item);
public:
    u8 m_num_items;
    u8 m_hp_materials_used;
    u8 m_tp_materials_used;
    u8 m_language;
    TPlyInventoryItem m_items[30];
};

#endif
