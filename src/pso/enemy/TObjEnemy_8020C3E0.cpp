#include "types.h"
#include "pso/map/FloorPopulation.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/TLobby.h"


s32 TObjEnemy::mask_sub_flags(s32 mask) {
    void *temp_r5;

    temp_r5 = this->set_entry;
    if (temp_r5 != NULL) {
        *(s16 *)((s8 *)temp_r5 + 2) = (s16) (*(s16 *)((s8 *)temp_r5 + 2) & mask);
        return 1;
    }
    return 0;
}

s32 TObjBase::set_event_source_flag(s32 event_source_flag) {
    void *temp_r5;

    temp_r5 = this->set_entry;
    if (temp_r5 != NULL) {
        *(s16 *)((s8 *)temp_r5 + 2) = (s16) (*(s16 *)((s8 *)temp_r5 + 2) | event_source_flag);
        return 1;
    }
    return 0;
}

s32 TObjBase::mask_object_set_row_flags(s32 arg1) {
    void *temp_r5;

    temp_r5 = this->set_entry;
    if (temp_r5 != NULL) {
        *(s16 *)((s8 *)temp_r5 + 2) = (s16) (*(s16 *)((s8 *)temp_r5 + 2) & arg1);
        return 1;
    }
    return 0;
}
s32 TLobby::clear_record_flags_a() {
    s32 i;
    s32 j;
    s32 k;
    if (TLobby__data_805D6114 != NULL) {
        for (i = 0; i < current_floor_enemy_set_count; i++) {
            TLobby__data_805D6114[i].flags = 0;
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
    if (TLobby__data_805D610C != NULL) {
        for (i = 0; i < current_floor_object_set_count; i++) {
            TLobby__data_805D610C[i].flags = 0;
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
