#ifndef PSO_PLAYER_TPLYCHARDATA_H
#define PSO_PLAYER_TPLYCHARDATA_H

#include <stddef.h>
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
    // Material usage counts, kept in the last m_present byte of inventory slots 8-12.
    void set_luck_materials_used(u8 count);
    void set_def_materials_used(u8 count);
    void set_evade_materials_used(u8 count);
    void set_mind_materials_used(u8 count);
    void set_power_materials_used(u8 count);
    // Set on a record saved from a disc whose game files failed the size/CRC check.
    void mark_game_files_modified();
    // Cast level of technique `tech` up to 14; the levels above it are kept in m_present[2] of inventory slot `tech`.
    u8 *technique_level(s32 tech);
    u8 *technique_level_overflow(s32 tech);
};

LAYOUT_ASSERT(PlyCharDataSize, sizeof(TPlyCharData) == 0x41C);
LAYOUT_ASSERT(PlyCharDataInventoryOffset, offsetof(TPlyCharData, m_inventory) == 0);
LAYOUT_ASSERT(PlyCharDataStatsOffset, offsetof(TPlyCharData, m_stats) == 0x34C);
LAYOUT_ASSERT(PlyCharDataAppearanceOffset, offsetof(TPlyCharData, m_disp_part2) == 0x370);

#endif
