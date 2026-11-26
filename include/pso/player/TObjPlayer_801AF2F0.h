#ifndef PSO_PLAYER_TOBJPLAYER_801AF2F0_H
#define PSO_PLAYER_TOBJPLAYER_801AF2F0_H

#include "pso/player/PlayerHoldPacket.h"
#include "pso/player/PlayerSlots.h"

struct Vec;
struct TItem;
class TObject;

// Thin wrapper: sends 6x29 to delete the item with this id (count of it) from the player.
void delete_item(TObjPlayer *player, s32 id, s32 count);
extern "C" {
void submit_cursor_candidate(void *object, s32 id);
// 6x2F: sets a player's HP (sender 0xFFFF for an object).
void send_6x2F_change_player_hp(s32 sender, s32 client, s16 hp);
void unequip_item__10TObjPlayerFiPv(TObjPlayer *player, TItem *item);
void TObjPlayer__sub_801B1BA4(void);
void TObjPlayer__sub_801B1C8C(void);
}

// True when obj exists and neither it nor a parent is queued for destruction.
s32 can_destroy_with_parents(TObject *obj);
// 6x24: moves player `slot` to pos, facing heading.
void send_6x24_teleport_player(u16 slot, const Vec *pos, s32 heading);
// The TPlayerReadyCallback that queue_player_kill queues: flags the player as killed.
void mark_player_killed(TObjPlayer *player);
void queue_player_kill(TObjPlayer *player);

void handle_6x32_medical_center_revive_all_players(void);
void handle_6x34(void);
void handle_6x8E(void);
void handle_6x98(void);
void handle_6x99(void);

#endif
