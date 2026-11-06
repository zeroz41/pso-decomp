#ifndef PSO_PLAYER_TPLYCHARDATA_H
#define PSO_PLAYER_TPLYCHARDATA_H

#include "types.h"
#include "pso/macros.h"
#include "pso/protocol.h"
#include "pso/TPlyInventory.h"
#include "pso/TPlyDispData.h"

class TPlyCharData {
public:
    TPlyCharData() {
        for (int i = 0; i < 30; ++i) {
            m_inventory.m_items[i].init();
        }
    };

    ~TPlyCharData() {};
    void bswap() {
        for (int i = 0; i < 30; ++i) {
            m_inventory.m_items[i].bswap();
        }
        m_disp_data.m_disp_part2.bswap();
        m_disp_data.m_stats.bswap();
        m_disp_data.m_config.bswap();
    };
    void some_stub() {};
public:
    TPlyInventory m_inventory;
    TPlyDispData m_disp_data;
public:
    void init_inventory_items();
};

extern "C" {
s32 __dt__12TPlyCharDataFv(s32 arg0, s16 arg1);
}

#endif
