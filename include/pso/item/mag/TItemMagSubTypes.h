#ifndef PSO_ITEM_MAG_TITEMMAGSUBTYPES_H
#define PSO_ITEM_MAG_TITEMMAGSUBTYPES_H

#include "types.h"

// The owner's current current_motion (TObjMotion::motion): the heading its root
// node adds to the owner's.
struct MagOwnerPoseNode {
    u8 pad_0[0x4];
    s16 heading;
};

struct MagOwnerPose {
    u8 pad_0[0x4];
    MagOwnerPoseNode *node;
};

#endif
