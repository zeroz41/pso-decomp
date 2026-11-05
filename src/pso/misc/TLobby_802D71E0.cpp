#include "types.h"
#include "pso/misc/TMotorcycle_802D712C.h"
#include "pso/misc/TLobby.h"

extern "C" {

u8 *insert_slot_by_id__12TObjNpcEnemyFs();

void TLobby::spawn_npc_enemy(s16 arg0, s32 arg1, NJS_TEXLIST *arg2, void *arg3, f32 farg0, f32 farg1) {
    u8 *temp_r3;

    temp_r3 = insert_slot_by_id__12TObjNpcEnemyFs();
    if (temp_r3 != NULL) {
        *(s16 *)((s8 *)temp_r3 + 0) = arg0;
        *(s16 *)((s8 *)temp_r3 + 2) = 1;
        *(f32 *)((s8 *)temp_r3 + 4) = farg1;
        *(s32 *)((s8 *)temp_r3 + 8) = arg1;
        *(NJS_TEXLIST **)((s8 *)temp_r3 + 0xC) = arg2;
        *(f32 *)((s8 *)temp_r3 + 0x10) = farg0;
        copy_position_data(temp_r3 + 0x14, arg3);
    }
}

}
