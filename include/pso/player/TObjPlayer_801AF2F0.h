#ifndef PSO_PLAYER_TOBJPLAYER_801AF2F0_H
#define PSO_PLAYER_TOBJPLAYER_801AF2F0_H

#include "pso/player/PlayerSlots.h"

struct Vec;
struct TItem;

extern "C" {
// Thin wrapper: sends 6x29 to delete the item with this id (count of it) from the player.
void delete_item(void *player, s32 id, s32 count);
void submit_cursor_candidate(void *object, s32 id);
// 6x2F: sets a player's HP (sender 0xFFFF for an object).
void send_6x2F_change_player_hp(s32 sender, s32 client, s16 hp);
// 6x2C: holds a player in place at pos for the given frames. The packet keeps 16 bits of
// frames and arg3, but TOTrapAncient02's virtual at vtable +0x144 passes its s32 timer unextended: ints.
void send_6x2C_impose_hold(TObjPlayer *player, const Vec *pos, s32 frames, s32 arg3, f32 radius);
void unequip_item__10TObjPlayerFiPv(TObjPlayer *player, TItem *item);
// Restores the player to full health and clears its status effects.
void recover_player_full(void *player);
}

// 6x24: moves player `slot` to pos, facing heading.
void send_6x24_teleport_player(u16 slot, const Vec *pos, s32 heading);

#endif
