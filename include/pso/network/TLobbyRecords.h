#ifndef PSO_NETWORK_TLOBBYRECORDS_H
#define PSO_NETWORK_TLOBBYRECORDS_H

#include "types.h"
#include "pso/map/FloorPopulation.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/player/PlayerSyncRecord.h"

struct LobbyPlayerEntry {
    u8 tag[8];
    u32 ip_addr;
    saddr client_id;
    char name[16];
    u8 char_data[0x41C];
};
/* An entry of a server menu (commands 07 and 1F: ship, block and information lists). */
struct ServerMenuEntry {
    u32 menu_id;
    u32 item_id;
    u16 flags;
    char name[0x12];
};
/* The 6x6B-6x6E game-state sync subcommands: an extended subcommand header (size 0, the whole packet's size in the
 * word after it) and the LZ-compressed state. */
struct CompressedSyncPacket {
    G_UnusedHeader header;
    s32 total_size;
    u8 data[1];
};
struct GameStateSyncScratch {
    u16 total_size;
    u16 floor_flags_size;
    u16 sync_records_size;
    u16 switch_table_size;
    u8 payload[sizeof(FloorSetFlagsPayload)];
};
LAYOUT_ASSERT(GameStateSyncScratchSize, sizeof(GameStateSyncScratch) == 0x4008);
LAYOUT_ASSERT(GameStateSyncPayloadOffset, offsetof(GameStateSyncScratch, payload) == 8);
struct GameJoinPlayerRecord { u8 pad[8]; u32 ip_addr; s32 client_id; char name[16]; };
/* 6x70: an extended subcommand header and the sending player's sync record. */
struct PlayerSyncPacket {
    G_ClientIDHeader header;
    s32 total_size;
    PlayerSyncRecord record;
};
typedef char LobbyPlayerName[16];
/* An entry of the game list (command 08). */
struct GameMenuEntry {
    u32 menu_id;
    u32 game_id;
    s8 difficulty_tag; /* the difficulty + 0x22 */
    u8 num_players;
    char name[0x10];
    u8 episode;
    s8 flags;
};
struct DownloadListEntry { u8 pad0[5]; u8 kind; u8 pad6[6]; u8 name[0x8C]; };
typedef struct LobbyServerAddress {
    const char *host;
    s32 port;
} LobbyServerAddress;

#endif
