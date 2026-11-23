#ifndef PSO_OBJECT_TOBJHMS_EZROPE_PLAYER_800FEFCC_H
#define PSO_OBJECT_TOBJHMS_EZROPE_PLAYER_800FEFCC_H

#include "types.h"

struct TObjEZRopeSegment;
struct TObjEZRopeEnd;
struct TObjEZRopeCollider;

// --- C functions defined in TObjHMS_EZRope_Player.cpp ---
extern "C" {
void copy_ezrope_collider(TObjEZRopeCollider *dst, TObjEZRopeCollider *src);
void copy_ezrope_end(TObjEZRopeEnd *dst, TObjEZRopeEnd *src);
void copy_ezrope_segment(TObjEZRopeSegment *dst, TObjEZRopeSegment *src);
}
// --- end of C functions

#endif
