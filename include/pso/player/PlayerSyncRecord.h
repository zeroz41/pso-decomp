#ifndef PSO_PLAYER_PLAYERSYNCRECORD_H
#define PSO_PLAYER_PLAYERSYNCRECORD_H

#include <stddef.h>
#include "types.h"
#include "pso/macros.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/PlayerStats.h"
#include "pso/player/TPlyDispData.h"
#include "pso/player/TPlyInventory.h"

// A player as the 0x70 subcommand carries it (G_SyncPlayerDispAndInventory_GC_6x70
// after its header); create_remote_player_object builds the remote player from it.
struct PlayerSyncRecord {
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
    u32 player_tag;
    u32 guild_card_number;
    u32 unknown_a6;
    u32 battle_team_number;
    TelepipeState telepipe;
    u32 telepipe_unknown_a4;
    u32 death_flags;
    PlayerHoldState hold_state;
    u32 area;
    u32 player_flags;
    u8 technique_levels[0x14];
    disp_data_part2 visual;
    player_stats stats;
    s32 item_count;
    // Item `tech`'s m_present[2] holds the technique levels above the cast level, as in TPlyCharData.
    TPlyInventoryItem items[30];
    u32 floor;
};

LAYOUT_ASSERT(PlayerSyncRecordHpOffset, offsetof(PlayerSyncRecord, current_hp) == 0x22);
LAYOUT_ASSERT(PlayerSyncRecordStatusOffset, offsetof(PlayerSyncRecord, status_effects) == 0x28);
LAYOUT_ASSERT(PlayerSyncRecordTechOffset, offsetof(PlayerSyncRecord, technique_levels) == 0xB4);
LAYOUT_ASSERT(PlayerSyncRecordVisualOffset, offsetof(PlayerSyncRecord, visual) == 0xC8);
LAYOUT_ASSERT(PlayerSyncRecordStatsOffset, offsetof(PlayerSyncRecord, stats) == 0x118);
LAYOUT_ASSERT(PlayerSyncRecordItemsOffset, offsetof(PlayerSyncRecord, item_count) == 0x13C);
LAYOUT_ASSERT(PlayerSyncRecordSize, sizeof(PlayerSyncRecord) == 0x48C);

#endif
