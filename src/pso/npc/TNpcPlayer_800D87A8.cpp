#include "types.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"

extern "C" {
void *get_battle_param__10TObjPlayerFi();

void *TNpcPlayer::get_valid_target_player() {
    void *temp_r31;

    temp_r31 = get_battle_param__10TObjPlayerFi();
    if (TObjPlayer::is_valid_and_active((uaddr)temp_r31) != 0) {
        return temp_r31;
    }
    return 0;
}

void *find_active_entity_by_id(u16 id) {
    void *entity;
    entity = find_entity_by_id(id);
    if (TObjPlayer::is_valid_and_active((uaddr)entity) != 0) {
        return entity;
    }
    return 0;
}

}
