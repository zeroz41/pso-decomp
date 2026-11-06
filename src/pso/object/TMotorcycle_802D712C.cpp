#include "types.h"
#include "pso/object/TMotorcycle_802D712C.h"
#include "pso/object/TMotorcycle.h"

void copy_position_data(void *arg0, void *arg1) {
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(s16 *)((s8 *)arg0 + 8) = (s16) *(s16 *)((s8 *)arg1 + 8);
    *(s16 *)((s8 *)arg0 + 0xA) = (s16) *(s16 *)((s8 *)arg1 + 0xA);
    *(s16 *)((s8 *)arg0 + 0xC) = (s16) *(s16 *)((s8 *)arg1 + 0xC);
}
extern "C" {

void *insert_slot_by_id__12TObjNpcEnemyFs();

void TMotorcycle::add_entry(s16 arg0, s32 arg1, s32 arg2, f32 farg0, f32 farg1) {
    void *temp_r3;

    temp_r3 = insert_slot_by_id__12TObjNpcEnemyFs();
    if (temp_r3 != NULL) {
        *(s16 *)((s8 *)temp_r3 + 0) = arg0;
        *(s16 *)((s8 *)temp_r3 + 2) = 2;
        *(f32 *)((s8 *)temp_r3 + 4) = farg1;
        *(s32 *)((s8 *)temp_r3 + 8) = arg1;
        *(s32 *)((s8 *)temp_r3 + 0xC) = arg2;
        *(f32 *)((s8 *)temp_r3 + 0x10) = farg0;
        *(s32 *)((s8 *)temp_r3 + 0x14) = 0;
        *(s32 *)((s8 *)temp_r3 + 0x18) = 0;
        *(s16 *)((s8 *)temp_r3 + 0x1C) = 0;
        *(s16 *)((s8 *)temp_r3 + 0x1E) = 0;
        *(s16 *)((s8 *)temp_r3 + 0x20) = 0;
    }
}
}
