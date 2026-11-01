#include "types.h"
#include "pso/object/TObjDoor.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 get_current_floor();
void *get_player_by_client_id(s32 i);
f32 xyz_distance(void *, void *);
}
s32 check_player_door_proximity(s32 arg0, s32 arg1, f32 farg0);
s32 check_player_door_proximity(s32 arg0, s32 arg1, f32 farg0) {
    s32 p;
    s32 i;
    s32 j;
    s32 q;
    if (arg1 == 1) {
        for (i = 0; i < 0xC; i++) {
            p = (s32)get_player_by_client_id(i);
            if (p != 0) {
                if (((TObjPlayer *)p)->get_floor() == get_current_floor() && xyz_distance((void *)(arg0 + 0x38), (void *)(p + 0x38)) < farg0) {
                    return 0;
                }
            }
        }
        return 1;
    } else if (arg1 == 0) {
        for (j = 0; j < 0xC; j++) {
            q = (s32)get_player_by_client_id(j);
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
