#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/misc/TLobby.h"

struct Rec_8020C458 { u8 p0[2]; s16 flags; u8 p1[0x44]; };

struct Sub_8020C458 { u8 p0[2]; s16 flags; u8 p1[4]; };

struct Grp_8020C458 { s32 a; s32 count; u8 pad[0xC]; Sub_8020C458 *recs; };

struct Rec_8020C500 { u8 p0[2]; s16 flags; u8 p1[0x40]; };

struct Sub_8020C500 { u8 p0[2]; s16 flags; u8 p1[4]; };

struct Grp_8020C500 { s32 count; u8 pad[0xC]; Sub_8020C500 *recs; u8 pad2[4]; };

extern Grp_8020C458 TLobby__floor_enemy_group_table[];
extern Rec_8020C458 *TLobby__data_805D6114;
extern s32 TLobby__current_floor_enemy_set_count;
extern Rec_8020C500 *TLobby__data_805D610C;
extern s32 TLobby__current_floor_object_set_count;

s32 TObjEnemy::mask_sub_flags(s32 arg1) {
    void *temp_r5;

    temp_r5 = this->set_entry;
    if (temp_r5 != NULL) {
        *(s16 *)((s8 *)temp_r5 + 2) = (s16) (*(s16 *)((s8 *)temp_r5 + 2) & arg1);
        return 1;
    }
    return 0;
}

s32 TObjBase::set_event_source_flag(s32 arg1) {
    void *temp_r5;

    temp_r5 = this->set_entry;
    if (temp_r5 != NULL) {
        *(s16 *)((s8 *)temp_r5 + 2) = (s16) (*(s16 *)((s8 *)temp_r5 + 2) | arg1);
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
        for (i = 0; i < TLobby__current_floor_enemy_set_count; i++) {
            TLobby__data_805D6114[i].flags = 0;
        }
    }
    for (k = 0; k < 0x12; k++) {
        if (TLobby__floor_enemy_group_table[k].recs != NULL) {
            for (j = 0; j < TLobby__floor_enemy_group_table[k].count; j++) {
                TLobby__floor_enemy_group_table[k].recs[j].flags = 0;
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
        for (i = 0; i < TLobby__current_floor_object_set_count; i++) {
            TLobby__data_805D610C[i].flags = 0;
        }
    }
    for (k = 0; k < 0x12; k++) {
        if (((Grp_8020C500 *)&TLobby__floor_enemy_group_table)[k].recs != NULL) {
            for (j = 0; j < ((Grp_8020C500 *)&TLobby__floor_enemy_group_table)[k].count; j++) {
                ((Grp_8020C500 *)&TLobby__floor_enemy_group_table)[k].recs[j].flags = 0;
            }
        }
    }
    return 1;
}
