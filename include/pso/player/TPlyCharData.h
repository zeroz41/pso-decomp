#ifndef PSO_PLAYER_TPLYCHARDATA_H
#define PSO_PLAYER_TPLYCHARDATA_H

#include "types.h"
#include "pso/macros.h"
#include "pso/network/protocol/protocol.h"
#include "pso/player/TPlyInventory.h"
#include "pso/player/TPlyDispData.h"

class TPlyCharData {
public:
    TPlyCharData();
    ~TPlyCharData();
    void bswap() {
        for (int i = 0; i < 30; ++i) {
            m_inventory.m_items[i].bswap();
        }
        m_disp_part2.bswap();
        m_stats.bswap();
        m_config.bswap();
    };
    void some_stub() {};
public:
    TPlyInventory m_inventory;
    player_stats m_stats;
    disp_data_part2 m_disp_part2;
    TPlyDispConfig m_config;
    u8 m_tech_levels[20];
public:
    void init_inventory_items();
};

#endif
