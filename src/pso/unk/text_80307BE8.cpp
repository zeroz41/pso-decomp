#include "types.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
f32 xz_distance_squared(void *, void *);
}
void update_players_in_range(u8 *arg0);
#pragma push
#pragma fp_contract on
void update_players_in_range(u8 *arg0) {
    s32 temp_r30;
    saddr player;
    s32 i;
    *(s32 *)((s8 *)arg0 + 0x14) = 1;
    *(s32 *)((s8 *)arg0 + 0x18) = 0;
    *(s32 *)((s8 *)arg0 + 0x20) = 0;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x24) != 0U) {
        i = 0;
        do {
            player = (saddr)get_player_by_client_id((i));
            if (player != 0) {
                if ((get_current_floor() == ((TObjPlayer *)player)->get_floor()) && (xz_distance_squared((void *)(player + 0x38), (void *)(arg0 + 8)) <= *(f32 *)((s8 *)arg0 + 0))) {
                    ((THunterGuildSeqOffline *)(*(uaddr *)((s8 *)arg0 + 0x24)))->advance_matching_entries(1, i);
                    *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) | (1 << i));
                    *(s32 *)((s8 *)arg0 + 0x18) = 1;
                } else {
                    ((THunterGuildSeqOffline *)(*(uaddr *)((s8 *)arg0 + 0x24)))->advance_matching_entries(0, i);
                    *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) & ~(1 << i));
                    *(s32 *)((s8 *)arg0 + 0x14) = 0;
                }
            } else {
                ((THunterGuildSeqOffline *)(*(uaddr *)((s8 *)arg0 + 0x24)))->advance_matching_entries(0, i);
            }
            i += 1;
        } while (i < 4);
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x14) == 0) {
        *(s32 *)((s8 *)arg0 + 0x1C) = (s32) *(s32 *)((s8 *)arg0 + 0x20);
    }
}
#pragma pop
