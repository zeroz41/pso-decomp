#ifndef PSO_PLAYER_TPLYINVENTORY_H
#define PSO_PLAYER_TPLYINVENTORY_H

#include "types.h"
#include "pso/macros.h"
#include "pso/network/protocol/protocol.h"

#include "pso/item/TItemData.h"

class TPlyInventoryItem {
public:
    void init() {
        m_present[0] = 0;
        m_present[1] = -1;
        m_flags = 0;
        m_present[3] = 0;
        m_present[2] = 0;
        m_data.init();
    };
    void bswap() {
        bswap_32(&m_flags);
        m_data.bswap();
    };
public:
    char m_present[4];
    u32 m_flags;
    TItemData m_data;
};

class TPlyInventory {
public:
    void bswap();
public:
    u8 m_num_items;
    u8 m_hp_materials_used;
    u8 m_tp_materials_used;
    u8 m_language;
    TPlyInventoryItem m_items[30];
};

#endif
