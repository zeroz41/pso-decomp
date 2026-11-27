#ifndef PSO_NETWORK_PROTOCOL_GAMEPLAY_SOUND_PACKET_H
#define PSO_NETWORK_PROTOCOL_GAMEPLAY_SOUND_PACKET_H

#include <stddef.h>
#include "pso/network/protocol/protocol_types.h"

struct game_command_header;

// 6xB2: Plays a sound effect on a floor, at the local player's position or, when client_id is 0xFFFF,
// without a position. Sent by take_snapshot (send_6xB2_play_sound); received by
// handle_6xB2_play_sound_from_player, which ignores it on another floor. Size checked:
// init_6xB2_play_sound sets the header size to 3 words.
struct G_PlaySound_6xB2 {
    G_ClientIDHeader header;
    s8 floor;
    u8 unused;
    u16 client_id;
    u32 sound_id;
};
LAYOUT_ASSERT(PlaySoundPacketSize, sizeof(G_PlaySound_6xB2) == 0xC);
LAYOUT_ASSERT(PlaySoundPacketClientOffset, offsetof(G_PlaySound_6xB2, client_id) == 0x6);
LAYOUT_ASSERT(PlaySoundPacketSoundOffset, offsetof(G_PlaySound_6xB2, sound_id) == 0x8);

// Fills in the subcommand and size, in words.
void init_6xB2_play_sound(G_PlaySound_6xB2 *cmd);
void send_6xB2_play_sound(G_PlaySound_6xB2 *cmd);
void bswap_6xB2_play_sound(G_PlaySound_6xB2 *cmd);
void handle_6xB2_play_sound_from_player(game_command_header *header);

#endif
