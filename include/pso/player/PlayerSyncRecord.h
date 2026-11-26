#ifndef PSO_PLAYER_PLAYERSYNCRECORD_H
#define PSO_PLAYER_PLAYERSYNCRECORD_H

#include <stddef.h>
#include "types.h"
#include "pso/macros.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/InventoryItemList.h"
#include "pso/player/MovementHold.h"
#include "pso/player/PlayerGuildCardTag.h"
#include "pso/player/PlayerPkState.h"
#include "pso/player/PlayerTelepipe.h"
#include "pso/player/PlayerStats.h"
#include "pso/player/TPlyDispData.h"
#include "pso/player/TPlyInventory.h"
#include "pso/system/data/FlagWord.h"

// A player as the 0x70 subcommand carries it (G_SyncPlayerDispAndInventory_GC_6x70
// after its header); create_remote_player_object builds the remote player from it.
struct PlayerSyncRecord {
    // An empty record: no client (0xFFFF), every item stack at its maximum count.
    PlayerSyncRecord();

    u16 client_id;
    s16 room_id;
    u32 game_flags;
    Vec position;
    s32 angle[3];
    s16 phase;
    s16 current_hp;
    s16 hp_material_bonus;
    s16 tp_material_bonus;
    StatusEffect status_effects[5];
    u32 language;
    PlayerGuildCardTag guild_card_tag;
    PlayerPkState pk_state;
    PlayerTelepipe telepipe;
    FlagWord death_flags;
    MovementHold hold_state;
    u32 area;
    u32 player_flags;
    u8 technique_levels[0x14];
    disp_data_part2 visual;
    player_stats stats;
    // Item `tech`'s m_present[2] holds the technique levels above the cast level, as in TPlyCharData.
    InventoryItemList inventory;
    u32 floor;

    // Material usage counts, kept in the last m_present byte of items 8-12 as in TPlyCharData.
    u8 get_luck_materials_used();
    u8 get_def_materials_used();
    u8 get_evade_materials_used();
    u8 get_mind_materials_used();
    u8 get_power_materials_used();
    void set_luck_materials_used(u8 v);
    void set_def_materials_used(u8 v);
    void set_evade_materials_used(u8 v);
    void set_mind_materials_used(u8 v);
    void set_power_materials_used(u8 v);

    // TObjPlayer's class flag bytes (init_class_flags), kept in the last m_present byte of items 13-15.
    u8 get_class_flag_0();
    u8 get_class_flag_1();
    u8 get_class_flag_2();
    void set_class_flag_0(u8 v);
    void set_class_flag_1(u8 v);
    void set_class_flag_2(u8 v);
};

LAYOUT_ASSERT(PlayerSyncRecordHpOffset, offsetof(PlayerSyncRecord, current_hp) == 0x22);
LAYOUT_ASSERT(PlayerSyncRecordStatusOffset, offsetof(PlayerSyncRecord, status_effects) == 0x28);
LAYOUT_ASSERT(PlayerSyncRecordTechOffset, offsetof(PlayerSyncRecord, technique_levels) == 0xB4);
LAYOUT_ASSERT(PlayerSyncRecordVisualOffset, offsetof(PlayerSyncRecord, visual) == 0xC8);
LAYOUT_ASSERT(PlayerSyncRecordStatsOffset, offsetof(PlayerSyncRecord, stats) == 0x118);
LAYOUT_ASSERT(PlayerSyncRecordItemsOffset, offsetof(PlayerSyncRecord, inventory) == 0x13C);
LAYOUT_ASSERT(PlayerSyncRecordSize, sizeof(PlayerSyncRecord) == 0x48C);

#endif
