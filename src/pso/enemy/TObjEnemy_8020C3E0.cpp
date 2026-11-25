#include "types.h"
#include "pso/map/FloorPopulation.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/network/TLobby.h"
#include "pso/unk/text_8020CCF4.h"
#include "pso/unk/text_8020BC50.h"

s32 TObjEnemy::mask_sub_flags(s32 mask) {
    EnemySetRecord *set_entry;

    set_entry = (EnemySetRecord *)this->set_entry;
    if (set_entry != NULL) {
        set_entry->flags &= mask;
        return 1;
    }
    return 0;
}

s32 TObjBase::set_event_source_flag(s32 event_source_flag) {
    FloorObjectSetRow *set_entry;

    set_entry = (FloorObjectSetRow *)this->set_entry;
    if (set_entry != NULL) {
        set_entry->flags |= event_source_flag;
        return 1;
    }
    return 0;
}

s32 TObjBase::mask_object_set_row_flags(s32 arg1) {
    FloorObjectSetRow *set_entry;

    set_entry = (FloorObjectSetRow *)this->set_entry;
    if (set_entry != NULL) {
        set_entry->flags &= arg1;
        return 1;
    }
    return 0;
}
s32 TLobby::clear_record_flags_a() {
    s32 i;
    s32 j;
    s32 k;
    if (current_floor_enemy_set_rows != NULL) {
        for (i = 0; i < current_floor_enemy_set_count; i++) {
            current_floor_enemy_set_rows[i].flags = 0;
        }
    }
    for (k = 0; k < 0x12; k++) {
        if (floor_enemy_group_table[k].enemy_rows != NULL) {
            for (j = 0; j < floor_enemy_group_table[k].enemy_count; j++) {
                floor_enemy_group_table[k].enemy_rows[j].flags = 0;
            }
        }
    }
    return 1;
}
s32 TLobby::clear_record_flags_b() {
    s32 i;
    s32 j;
    s32 k;
    if (current_floor_object_set_rows != NULL) {
        for (i = 0; i < current_floor_object_set_count; i++) {
            current_floor_object_set_rows[i].flags = 0;
        }
    }
    for (k = 0; k < 0x12; k++) {
        if (floor_enemy_group_table[k].object_rows != NULL) {
            for (j = 0; j < floor_enemy_group_table[k].object_count; j++) {
                floor_enemy_group_table[k].object_rows[j].flags = 0;
            }
        }
    }
    return 1;
}

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
                    enemy->apply_enemy_state(&enemy_state_records[set_index].flags);
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
