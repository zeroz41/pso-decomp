/* The headers and records the game subcommands (subcmd_6x.h) share.
 *
 * The layouts started from newserv (MIT licence, Copyright (c) 2024 Martin Michelsen; see
 * third_party/LICENSES/newserv-MIT.txt). Where our code uses a type, its names and size follow our
 * code; each struct says whether it is used. Our integer types replace newserv's little-endian
 * wrappers; the senders and handlers swap the bytes.
 */

#ifndef PSO_PROTOCOL_TYPES_H
#define PSO_PROTOCOL_TYPES_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/item/TItemData.h"

// An x/z position on the floor. Used by our code (FloorItem).
struct VectorXZF {
 f32 x;
 f32 z;
 void bswap();
};

// An item lying on the floor: its floor, position, room, drop number and the item. Used by our code
// (TItem, FloorItemSync).
struct FloorItem {
 s8 floor;
 u8 source_type;
 s16 entity_index;
 struct VectorXZF pos;
 s16 room_id;
 u16 drop_number;
 TItemData item;
 FloorItem();
 void clear();
};

// The header of most game subcommands: the subcommand, its size in 4-byte words and the client it
// is about. Used by our code.
struct G_ClientIDHeader {
 u8 subcommand;
 u8 size;
 u16 client_id;
 // Whether the command came from another client.
 s32 is_remote();
 s32 is_local(u16 client);
 void bswap();
};

// Header helpers every 6x packet's send and operator= call with the packet itself.
void bswap_g_client_id_header(void *header);
void assign_subcommand_header(void *dst, void *src);
void *copy_subcommand_header(void *dst, const void *src);

// 6x05: a floor switch was set or cleared (TOKey's TU sends and handles it).
struct G_SwitchStateChanged_6x05 {
 G_ClientIDHeader header;  // client_id: the object that changed it
 u16 unused1;
 u16 unused2;
 u16 switch_id;
 s8 floor;
 u8 flags;  // 1: set, 2: play the switch sound on that floor
 G_SwitchStateChanged_6x05 *init();
 void send();
 void bswap();
};

// The header of subcommands about an enemy or object instead of a client. Used by our code (the
// Vol Opt packets).
struct G_EntityIDHeader {
 u8 subcommand;
 u8 size;
 u16 entity_id;
};

// A subcommand header whose third field is a parameter. Used by our code (dispatch_6x_subcommand).
struct G_ParameterHeader {
 u8 subcommand;
 u8 size;
 u16 param;
};

// A subcommand header whose third field is not used. Used by our code.
struct G_UnusedHeader {
 u8 subcommand;
 u8 size;
 u16 unused;
};

// A hold the player is caught in. Part of the 6x70 player state; layout from newserv, not used by
// our code yet.
struct PlayerHoldState {
 u16 expiration_frames;
 u16 unknown_a2;
 u32 unknown_a3;
 f32 trigger_radius2;
 f32 x;
 f32 z;
};

// A player's records: our code carries them as TPlyChallenge (packet_classes.h).

// A status effect: its type, strength and the frames left. Part of the 6x70 player state; layout
// from newserv, not used by our code yet.
struct StatusEffectState {
 u32 effect_type;
 f32 multiplier;
 u32 remaining_frames;
};

// A player's telepipe: its owner, floor, room, position and angle. Used by our code (TTecLuker).
struct TelepipeState {
 u16 owner_client_id;
 s16 floor;
 u32 room_id;
 Vec pos;
 u32 angle_y;
 void send_telepipe_packet();
 void reset();
 void init_fields(u16 owner);
 s32 get_floor();
};

// An x/y/z angle in integer units. Part of the 6x70 player state; layout from newserv, not used by
// our code yet.
struct VectorXYZI {
 u32 x;
 u32 y;
 u32 z;
};

#endif
