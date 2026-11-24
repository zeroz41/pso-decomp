#include "types.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"

TObjCollidable *get_valid_target_player(int id) {
    TObjCollidable *player = reinterpret_cast<TObjCollidable *>(TObjPlayer::get_battle_param(id));
    if (TObjPlayer::is_valid_and_active((uaddr)player) != 0) {
        return player;
    }
    return NULL;
}

TObjCollidable *find_active_entity_by_id(u16 id) {
    TObjCollidable *entity = find_entity_by_id(id);
    if (TObjPlayer::is_valid_and_active((uaddr)entity) != 0) {
        return entity;
    }
    return NULL;
}
