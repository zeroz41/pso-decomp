#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/player/TObjPlayer_80011014.h"

extern "C" {

u32 get_enemy_entity();

extern u32 boss8_dragon_leader_part;

bool TBoss8Dragon::has_enough_enemies() {
    s32 i;
    s32 count;

    if (is_split_screen() != 0) {
        return 1;
    }
    if (boss8_dragon_leader_part == 0U) {
        return 0;
    }
    count = 0;
    i = 0;
    do {
        ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(i);
        if (get_enemy_entity() != 0U) {
            count += 1;
        }
        i += 1;
    } while (i < 6);
    return count >= 3;
}

}
