#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

extern "C" {

u32 get_enemy_entity();
s32 set_state_22__12TBoss8DragonFv();

extern u32 boss8_dragon_leader_part;

s32 TBoss8Dragon::find_target_enemy() {
    s32 var_r31;

    if ((u32) boss8_dragon_leader_part == 0U) {
        return 0;
    }
    var_r31 = 1;
loop_3:
    ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(var_r31);
    if (get_enemy_entity() != 0U) {
        return 1;
    }
    var_r31 += 1;
    if (var_r31 >= 6) {
        return 0;
    }
    goto loop_3;
}

s32 TBoss8Dragon::is_any_part_alive() {
    s32 var_r31;

    if ((u32) boss8_dragon_leader_part == 0U) {
        return 1;
    }
    var_r31 = 1;
loop_3:
    ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(var_r31);
    if (get_enemy_entity() != 0U) {
        return 0;
    }
    var_r31 += 1;
    if (var_r31 >= 6) {
        return 1;
    }
    goto loop_3;
}

void TBoss8Dragon::update_all_parts() {
    s32 var_r31;

    if ((u32) boss8_dragon_leader_part != 0U) {
        var_r31 = 1;
        do {
            ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(var_r31);
            if (get_enemy_entity() != 0U) {
                set_state_22__12TBoss8DragonFv();
            }
            var_r31 += 1;
        } while (var_r31 < 6);
    }
}

}
