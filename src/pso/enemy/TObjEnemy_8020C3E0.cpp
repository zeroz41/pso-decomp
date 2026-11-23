#include "types.h"
#include "pso/map/FloorPopulation.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/TLobby.h"


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
