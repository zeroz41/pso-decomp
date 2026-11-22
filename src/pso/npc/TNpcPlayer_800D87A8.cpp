#include "types.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"

void *get_valid_target_player(int id) {
    void *player = (void *)TObjPlayer::get_battle_param(id);
    if (TObjPlayer::is_valid_and_active((uaddr)player) != 0) {
        return player;
    }
    return NULL;
}

extern "C" {
void *find_active_entity_by_id(u16 id) {
    void *entity;
    entity = find_entity_by_id(id);
    if (TObjPlayer::is_valid_and_active((uaddr)entity) != 0) {
        return entity;
    }
    return 0;
}

}
