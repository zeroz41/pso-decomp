#include "pso/map/FloorPopulation.h"
#include "pso/enemy/TObjEnemy.h"
#include "types.h"
#include "pso/unk/text_8020CCF4.h"
#include "pso/unk/TLobby.h"

void TLobby::assign_display_objects(EnemySetRecord *rows, s32 enemy_count) {
    s16 flags;
    s16 set_index;
    EnemySetRecord *row;
    s32 row_index;
    TObjEnemy *enemy;

    row = rows;
    for (row_index = 0; row_index < enemy_count; row_index++, row++) {
        flags = row->flags;
        if (!(flags & 8) && !(flags & 2) && (row->type != -1) && ((flags & 1) || (row->placement.wave == 0))) {
            enemy = construct_enemy_from_set_row(row);
            if (enemy != NULL) {
                row->enemy = enemy;
                row->flags |= 2;
                enemy->room = row->placement.room;
                enemy->set_group = row->placement.wave;
                enemy->set_index = row->placement.enemy_index;
                enemy->set_entry = row;
                set_index = enemy->set_index;
                if (set_index != -1) {
                    enemy->apply_enemy_state(&TLobby__data_805D6144[set_index].flags);
                }
            } else {
                row->enemy = NULL;
            }
            row->flags &= ~1;
        }
    }
}
