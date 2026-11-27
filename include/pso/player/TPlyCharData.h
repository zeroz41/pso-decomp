#ifndef PSO_PLAYER_TPLYCHARDATA_H
#define PSO_PLAYER_TPLYCHARDATA_H

#include <stddef.h>
#include "types.h"
#include "pso/macros.h"
#include "pso/network/protocol/protocol.h"
#include "pso/player/TPlyInventory.h"
#include "pso/player/TPlyDispData.h"
#include "pso/player/TPlyGuildCardTag.h"

class TObjPlayer;

class TPlyCharData {
public:
    TPlyCharData();
    ~TPlyCharData();
    TPlyCharData &operator=(TPlyCharData &src);
    void bswap();
    void some_stub() {};
public:
    TPlyInventory m_inventory;
    player_stats m_stats;
    disp_data_part2 m_disp_part2;
    TPlyDispConfig m_config;
    u8 m_tech_levels[20];
public:
    void init_inventory_items();
    void initialize_player_data();
    // Every technique level to 255, not learned.
    void clear_technique_levels();
    // Material usage counts, kept in the last m_present byte of inventory slots 8-12.
    void set_luck_materials_used(u8 count);
    void set_def_materials_used(u8 count);
    void set_evade_materials_used(u8 count);
    void set_mind_materials_used(u8 count);
    void set_power_materials_used(u8 count);
    u8 get_luck_materials_used();
    s32 get_record_byte_at(s32 tech);
    // TObjPlayer's class flag bytes (init_class_flags), kept in the last m_present byte of items 13-15.
    u8 get_class_flag_0();
    u8 get_class_flag_1();
    u8 get_class_flag_2();
    // The words fill_player_record packs into the last m_present byte of items 0-3 (lo) and 4-7 (hi).
    u32 unpack_u32_hi();
    u32 unpack_u32_lo();
    u8 get_def_materials_used();
    u8 get_evade_materials_used();
    u8 get_mind_materials_used();
    u8 get_power_materials_used();
    // Set on a record saved from a disc whose game files failed the size/CRC check.
    void mark_game_files_modified();
    // Cast level of technique `tech` up to 14; the levels above it are kept in m_present[2] of inventory slot `tech`.
    u8 *technique_level(s32 tech);
    u8 *technique_level_overflow(s32 tech);
    // Name inferred from set_technique_level, which it mirrors.
    s32 get_technique_level(s32 tech);
    void set_technique_level(s32 tech, u8 level);
    void set_technique_level_overflow(s32 tech, u8 level);
    u8 *get_technique_levels();
    // Copies `player`'s stats, inventory, look and palettes into this record.
    void copy_from_player(TObjPlayer *player);
    // copy_from_player of the player of `client`; 0 when that client has no player.
    s32 capture_client_player(u16 client);
    void clear_inventory();
    void set_mag_level(u8 level);
    void set_battle_mode(u8 mode);
    void set_class_flag_1(u8 value);
    void set_pending_action(u32 action);
    void set_save_time(u32 seconds);
    // set_save_time with the current date in seconds.
    void stamp_save_time();
    void clear_technique_level_overflows();
    // Every technique back to its starting level, with no overflow.
    void reset_technique_levels();
};

LAYOUT_ASSERT(PlyCharDataSize, sizeof(TPlyCharData) == 0x41C);
LAYOUT_ASSERT(PlyCharDataInventoryOffset, offsetof(TPlyCharData, m_inventory) == 0);
LAYOUT_ASSERT(PlyCharDataStatsOffset, offsetof(TPlyCharData, m_stats) == 0x34C);
LAYOUT_ASSERT(PlyCharDataAppearanceOffset, offsetof(TPlyCharData, m_disp_part2) == 0x370);

// Copies one 0x50-byte player visual record over another; returns dst.
disp_data_part2 *copy_player_visual_record(disp_data_part2 *dst, disp_data_part2 *src);

// TPlyCharData's constructor and destructor by symbol, for the static initializers that build and register a
// global TPlyCharData (C++ cannot take a constructor's or destructor's address).
extern "C" {
void *__ct__12TPlyCharDataFv(void *object);
void __dt__12TPlyCharDataFv(void *object, s16 flags);
}

#endif
