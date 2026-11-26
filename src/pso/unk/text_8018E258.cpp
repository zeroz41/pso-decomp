#include "types.h"
#include "pso/object/door/TObjDoor.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
f32 xyz_distance(void *, void *);
}
s32 check_player_door_proximity(saddr door, s32 expect_clear, f32 radius);
s32 check_player_door_proximity(saddr door, s32 expect_clear, f32 radius) {
    saddr p;
    s32 i;
    s32 j;
    saddr q;
    if (expect_clear == 1) {
        for (i = 0; i < 0xC; i++) {
            p = (saddr)get_player_by_client_id(i);
            if (p != 0) {
                if (((TObjPlayer *)p)->get_floor() == get_current_floor() && xyz_distance((void *)(door + 0x38), (void *)(p + 0x38)) < radius) {
                    return 0;
                }
            }
        }
        return 1;
    } else if (expect_clear == 0) {
        for (j = 0; j < 0xC; j++) {
            q = (saddr)get_player_by_client_id(j);
            if (q != 0) {
                if (((TObjPlayer *)q)->get_floor() == get_current_floor() && xyz_distance((void *)(door + 0x38), (void *)(q + 0x38)) < radius) {
                    return 1;
                }
            }
        }
        return 0;
    }
    return 0;
}
