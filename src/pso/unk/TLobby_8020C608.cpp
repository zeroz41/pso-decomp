#include "pso/map/FloorPopulation.h"
#include "types.h"
#include "pso/unk/text_8020CCF4.h"
#include "pso/unk/text_8020BC50.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"

s32 TObjEnemy::send_entity_set_flags() {
    if ((uaddr) this->set_entry != 0U) {
        send_6x76_set_entity_set_flags(this, 8);
        return 1;
    }
    return 0;
}

s32 TObjCollidable::set_flag8() {
    void *set_entry;

    set_entry = this->set_entry;
    if (set_entry != NULL) {
        *(s16 *)((s8 *)set_entry + 2) = (s16) (*(s16 *)((s8 *)set_entry + 2) | 8);
        return 1;
    }
    return 0;
}

#include "pso/unk/TLobby.h"

extern "C" {

s32 append_wave_member(s32, void *);


s32 TLobby::spawn_matching_objects(s16 room, s16 wave, saddr wave_members) {
    s16 set_index;
    s16 flags;
    s32 row_count;
    s32 spawned;
    EnemySetRecord *row;
    s32 row_index;
    TObjEnemy *enemy;

    spawned = 0;
    if ((s32) active_set_floor < 0) {
        return 0;
    }
    row = get_active_floor_enemy_rows(active_set_floor);
    row_count = TLobby::get_object_type(active_set_floor);
    for (row_index = 0; row_index < row_count; row_index += 1, row++) {
        flags = row->flags;
        if (!(flags & 8) && !(flags & 2) && (row->placement.room == room) && (row->placement.wave == wave)) {
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
                append_wave_member(wave_members, enemy);
                spawned += 1;
            } else {
                row->enemy = NULL;
            }
        }
    }
    return spawned;
}

}
