#include "types.h"
#include "pso/object/door/TObjDoor.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/PlayerSlots.h"
#include "pso/render/GinjaDrawUtil.h"

s32 check_player_door_proximity(TObjDoor *door, s32 expect_clear, f32 radius) {
    TObjPlayer *p;
    s32 i;
    s32 j;
    TObjPlayer *q;
    if (expect_clear == 1) {
        for (i = 0; i < 0xC; i++) {
            p = get_player_by_client_id(i);
            if (p != NULL) {
                if (p->get_floor() == get_current_floor() && xyz_distance(&door->position, &p->position) < radius) {
                    return 0;
                }
            }
        }
        return 1;
    } else if (expect_clear == 0) {
        for (j = 0; j < 0xC; j++) {
            q = get_player_by_client_id(j);
            if (q != NULL) {
                if (q->get_floor() == get_current_floor() && xyz_distance(&door->position, &q->position) < radius) {
                    return 1;
                }
            }
        }
        return 0;
    }
    return 0;
}
