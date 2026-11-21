#ifndef PSO_CAMERA_FOLLOW_CAMERA_CONTROLLER_H
#define PSO_CAMERA_FOLLOW_CAMERA_CONTROLLER_H
#include "types.h"
#include <stddef.h>

struct FollowVector { f32 x, y, z; };
struct FollowActor {
    u8 prefix[0x38];
    FollowVector position;
};
struct FollowController {
    u8 prefix[0x1C];
    FollowActor *actor;
    u8 unknown20[0xBC];
    FollowVector position_offset;
};
struct FollowView {
    u8 prefix[0xD4];
    FollowVector split_positions[4];
    u8 unknown104[0x74];
    FollowVector position, target;
};
LAYOUT_ASSERT(FollowActorPositionOffset, offsetof(FollowActor, position) == 0x38);
LAYOUT_ASSERT(FollowControllerActorOffset, offsetof(FollowController, actor) == 0x1C);
LAYOUT_ASSERT(FollowControllerPositionOffset, offsetof(FollowController, position_offset) == 0xDC);
LAYOUT_ASSERT(FollowViewSplitOffset, offsetof(FollowView, split_positions) == 0xD4);
LAYOUT_ASSERT(FollowViewPositionOffset, offsetof(FollowView, position) == 0x178);
LAYOUT_ASSERT(FollowViewTargetOffset, offsetof(FollowView, target) == 0x184);

s32 conversation_camera_obstructed(FollowController *, s32 heading);
#endif
