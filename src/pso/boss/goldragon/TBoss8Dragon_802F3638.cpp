#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_802F3638.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

extern "C" {
s32 is_split_screen();
u8 *get_enemy_entity(u16 entity_id);
extern TBoss8Dragon *boss8_dragon_leader_part;

s32 TBoss8Dragon__sub_802F3638() {
    s32 i;
    s32 alive;

    if (is_split_screen()) {
        return -1;
    }
    if (boss8_dragon_leader_part == NULL) {
        return 1;
    }
    alive = 0;
    for (i = 0; i < 6; i++) {
        if (get_enemy_entity(boss8_dragon_leader_part->get_part_count_plus(i)) != NULL) {
            alive++;
        }
    }
    if (alive >= 4) {
        return 0;
    }
    return (alive >= 1) ? 1 : 2;
}
}
