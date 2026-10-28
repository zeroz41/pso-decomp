/* PSO shared wire payload/header structs.
 *
 * Shared PSO wire-protocol structures for Episode I & II Plus (GameCube / V3).
 * These command/subcommand formats are identical between server and client by
 * definition, so they are safe to use to type the GameCube client decomp's
 * network handlers.
 *
 * Field names and byte offsets are derived from newserv
 * (fuzziqersoftware/newserv), an MIT-licensed PSO server reimplementation, via
 * tools/newserv_match.py. newserv is MIT (Copyright (c) 2024 Martin Michelsen);
 * its LICENSE is bundled at reference/newserv-LICENSE and permits this reuse.
 *
 * The decomp's own integer types (u8/u16/u32/s8/s16/s32/f32 ...) replace
 * newserv's phosg le_/be_ wire-endian wrappers; on the big-endian PowerPC
 * client these are plain scalars. The `size 0xNN` trailer reflects newserv's
 * static_assert/check_struct_size (0 computed-vs-declared mismatches at
 * generation time). V3/GC-relevant structs are kept; BB/DC/Ep3/XB-only
 * variants are skipped.
 *
 * GENERATED — verify offsets against the DOL before relying on a field.
 */

#ifndef PSO_PROTOCOL_TYPES_H
#define PSO_PROTOCOL_TYPES_H

#include "types.h"

struct VectorXZF {
 f32 x;
 f32 z;
 void bswap();
};

struct ItemData {
 u8 _anon_u_0[0xC];
 u32 id;
 u8 _anon_u_10[0x4];
 void copy_from(ItemData *src);
};

struct FloorItem {
 s8 floor;
 u8 source_type;
 s16 entity_index;
 struct VectorXZF pos;
 s16 room_id;
 u16 drop_number;
 struct ItemData item;
 FloorItem();
 void clear();
};

struct G_ClientIDHeader {
 u8 subcommand;
 u8 size;
 u16 client_id;
 // Whether the command came from another client.
 s32 is_remote();
 s32 is_local(u16 client);
 void bswap();
};

struct G_EntityIDHeader {
 u8 subcommand;
 u8 size;
 u16 entity_id;
};

struct G_ParameterHeader {
 u8 subcommand;
 u8 size;
 u16 param;
};

struct G_UnusedHeader {
 u8 subcommand;
 u8 size;
 u16 unused;
};

struct GuildCardPC {
 u32 player_tag;
 u32 guild_card_number;
 char name[0x30];
 char description[0xB4];
 u8 present;
 u8 language[0x1];
 u8 section_id;
 u8 char_class;
};

struct PlayerHoldState {
 u16 expiration_frames;
 u16 unknown_a2;
 u32 unknown_a3;
 f32 trigger_radius2;
 f32 x;
 f32 z;
};

struct PlayerHoldState_DCProtos {
 u16 expiration_frames;
 u16 unknown_a2;
 f32 trigger_radius2;
 f32 x;
 f32 z;
};

struct PlayerLobbyDataDCGC {
 u32 player_tag;
 u32 guild_card_number;
 u32 ip_address;
 u32 client_id;
 char name[0x10];
};

struct PlayerRecordsEntry_PC {
 u32 client_id;
 u8 challenge[0xD8];
 u8 battle[0x18];
};

struct PlayerRecordsEntry_V3 {
 u32 client_id;
 u8 challenge[0x100];
 u8 battle[0x18];
};

struct StatusEffectState {
 u32 effect_type;
 f32 multiplier;
 u32 remaining_frames;
};

struct VectorXYZF {
 f32 x;
 f32 y;
 f32 z;
};

struct TelepipeState {
 u16 owner_client_id;
 u16 floor;
 u32 room_id;
 struct VectorXYZF pos;
 u32 angle_y;
};

struct VectorXYZI {
 u32 x;
 u32 y;
 u32 z;
};

#endif
