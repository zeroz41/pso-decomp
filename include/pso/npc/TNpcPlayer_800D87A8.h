#ifndef PSO_NPC_TNPCPLAYER_800D87A8_H
#define PSO_NPC_TNPCPLAYER_800D87A8_H

#include "types.h"

class TObjCollidable;

// The player in battle slot `id` (TObjPlayer::get_battle_param), or 0 when that
// slot is not a valid, active player.
TObjCollidable *get_valid_target_player(int id);

// The entity with id `id` (find_entity_by_id), or NULL when there is none or it
// is not valid and active.
TObjCollidable *find_active_entity_by_id(u16 id);

#endif
