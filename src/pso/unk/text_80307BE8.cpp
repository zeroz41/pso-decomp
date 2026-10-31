#include "types.h"
#include "pso/misc/THunterGuildSeqOffline.h"

extern "C" {
s32 get_current_floor();
s32 get_floor__10TObjPlayerFv();
f32 xz_distance_squared(void *, void *);
void *get_player_by_client_id(s32 i);
}
void update_players_in_range(u8 *arg0);
#pragma push
#pragma fp_contract on
void update_players_in_range(u8 *arg0) {
    s32 temp_r30;
    s32 player;
    s32 var_r28;
    *(s32 *)((s8 *)arg0 + 0x14) = 1;
    *(s32 *)((s8 *)arg0 + 0x18) = 0;
    *(s32 *)((s8 *)arg0 + 0x20) = 0;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x24) != 0U) {
        var_r28 = 0;
        do {
            player = (s32)get_player_by_client_id((var_r28));
            if (player != 0) {
                if ((get_current_floor() == get_floor__10TObjPlayerFv()) && (xz_distance_squared((void *)(player + 0x38), (void *)(arg0 + 8)) <= *(f32 *)((s8 *)arg0 + 0))) {
                    ((THunterGuildSeqOffline *)(*(u32 *)((s8 *)arg0 + 0x24)))->advance_matching_entries(1, var_r28);
                    *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) | (1 << var_r28));
                    *(s32 *)((s8 *)arg0 + 0x18) = 1;
                } else {
                    ((THunterGuildSeqOffline *)(*(u32 *)((s8 *)arg0 + 0x24)))->advance_matching_entries(0, var_r28);
                    *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) & ~(1 << var_r28));
                    *(s32 *)((s8 *)arg0 + 0x14) = 0;
                }
            } else {
                ((THunterGuildSeqOffline *)(*(u32 *)((s8 *)arg0 + 0x24)))->advance_matching_entries(0, var_r28);
            }
            var_r28 += 1;
        } while (var_r28 < 4);
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x14) == 0) {
        *(s32 *)((s8 *)arg0 + 0x1C) = (s32) *(s32 *)((s8 *)arg0 + 0x20);
    }
}
#pragma pop
