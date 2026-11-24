#ifndef PSO_PLAYER_TOBJPLAYER_801AF2F0_H
#define PSO_PLAYER_TOBJPLAYER_801AF2F0_H

#include "pso/player/PlayerHoldPacket.h"
#include "pso/player/PlayerSlots.h"

struct Vec;
struct TItem;

extern "C" {
// Thin wrapper: sends 6x29 to delete the item with this id (count of it) from the player.
void delete_item(void *player, s32 id, s32 count);
void submit_cursor_candidate(void *object, s32 id);
// 6x2F: sets a player's HP (sender 0xFFFF for an object).
void send_6x2F_change_player_hp(s32 sender, s32 client, s16 hp);
void unequip_item__10TObjPlayerFiPv(TObjPlayer *player, TItem *item);
void TObjPlayer__sub_801B1BA4(void);
void TObjPlayer__sub_801B1C8C(void);
// Restores the player to full health and clears its status effects.
void recover_player_full(void *player);
}

// 6x24: moves player `slot` to pos, facing heading.
void send_6x24_teleport_player(u16 slot, const Vec *pos, s32 heading);

#endif
