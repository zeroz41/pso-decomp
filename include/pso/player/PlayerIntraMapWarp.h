#ifndef PSO_PLAYER_PLAYERINTRAMAPWARP_H
#define PSO_PLAYER_PLAYERINTRAMAPWARP_H

#include "types.h"
#include "dolphin/mtx/GeoTypes.h"

// TObjPlayer + 0x658: where a 6x55 intra-map warp puts the player.
// handle_6x55_intra_map_warp fills yaw and destination; the warp action
// counts timer down before it moves the player there.
struct PlayerIntraMapWarp {
    s32 timer;
    s32 yaw;
    Vec destination;

    PlayerIntraMapWarp();
};

LAYOUT_ASSERT(PlayerIntraMapWarp_size, sizeof(PlayerIntraMapWarp) == 0x14);

#endif
