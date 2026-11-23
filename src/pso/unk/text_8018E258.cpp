#include "types.h"
#include "pso/object/door/TObjDoor.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
f32 xyz_distance(void *, void *);
}
s32 check_player_door_proximity(saddr arg0, s32 arg1, f32 farg0);
s32 check_player_door_proximity(saddr arg0, s32 arg1, f32 farg0) {
    saddr p;
    s32 i;
    s32 j;
    saddr q;
    if (arg1 == 1) {
        for (i = 0; i < 0xC; i++) {
            p = (saddr)get_player_by_client_id(i);
            if (p != 0) {
                if (((TObjPlayer *)p)->get_floor() == get_current_floor() && xyz_distance((void *)(arg0 + 0x38), (void *)(p + 0x38)) < farg0) {
                    return 0;
                }
            }
        }
        return 1;
    } else if (arg1 == 0) {
        for (j = 0; j < 0xC; j++) {
            q = (saddr)get_player_by_client_id(j);
            if (q != 0) {
                if (((TObjPlayer *)q)->get_floor() == get_current_floor() && xyz_distance((void *)(arg0 + 0x38), (void *)(q + 0x38)) < farg0) {
                    return 1;
                }
            }
        }
        return 0;
    }
    return 0;
}
