#ifndef PSO_OBJECT_TOBJHMS_EZROPE_PLAYER_800FEFCC_H
#define PSO_OBJECT_TOBJHMS_EZROPE_PLAYER_800FEFCC_H

#include "types.h"

struct TObjEZRopeSegment;
struct TObjEZRopeEnd;
struct TObjEZRopeCollider;

// --- C functions defined in TObjHMS_EZRope_Player.cpp ---
extern "C" {
void TObjPlayer__sub_800FF1FC(TObjEZRopeCollider *dst, TObjEZRopeCollider *src);
void TObjPlayer__sub_800FF220(TObjEZRopeEnd *dst, TObjEZRopeEnd *src);
void TObjPlayer__sub_800FF244(TObjEZRopeSegment *dst, TObjEZRopeSegment *src);
}
// --- end of C functions

#endif
