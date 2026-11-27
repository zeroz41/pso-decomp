#ifndef PSO_PLAYER_PLAYERCOMMANDS_H
#define PSO_PLAYER_PLAYERCOMMANDS_H

#include "pso/player/PlayerHoldPacket.h"
#include "pso/player/PlayerSlots.h"

struct Vec;
struct TItem;
class TObject;
class TObjCollidable;

// Thin wrapper: sends 6x29 to delete the item with this id (count of it) from the player.
void delete_item(TObjPlayer *player, s32 id, s32 count);
s32 try_send_6x27_use_item(TObjPlayer *player, s32 key);
void submit_cursor_candidate(TObjCollidable *object, s32 id);
// Offers target to the lock-on cursor of player `id` (a client id below 0x1000).
void submit_target_to_player_cursor(TObjCollidable *target, s32 id);
extern "C" {
// Lets every player move again after a boss cutscene.
void release_players_from_cutscene(void);
}
// 6x2F: sets a player's HP (sender 0xFFFF for an object).
void send_6x2F_change_player_hp(u16 sender, u16 client, s16 hp);

// True when obj exists and neither it nor a parent is queued for destruction.
s32 can_destroy_with_parents(TObject *obj);
// 6x24: moves player `slot` to pos, facing heading.
void send_6x24_teleport_player(u16 slot, const Vec *pos, s32 heading);
// The TPlayerReadyCallback that queue_player_kill queues: flags the player as killed.
void mark_player_killed(TObjPlayer *player);
void queue_player_kill(TObjPlayer *player);
// Deletes every player and creates them again from the lobby character slots.
void recreate_all_players(void);

void handle_6x32_medical_center_revive_all_players(void);
void handle_6x34(void);
void handle_6x8E(void);
void handle_6x98(void);
void handle_6x99(void);

// An equipped item and the slot it sits in, kept while apply_battle_level_reset rebuilds the stats.
struct EquippedItemSlot {
    EquippedItemSlot() {
        slot = 0;
        item = NULL;
    }

    s16 slot;
    TItem *item;
};

#endif
