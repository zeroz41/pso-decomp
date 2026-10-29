#ifndef PSO_OBJECT_TOBJMAPWARP_80141C68_H
#define PSO_OBJECT_TOBJMAPWARP_80141C68_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

extern "C" {
s32 TObjMapWarp__sub_80141C68(s32 arg0, s16 arg1);
void TObjMapWarp__sub_80141CA4(void *p);
void TObjMapWarp__sub_80141CB0(void);
void TObjMapWarp__sub_80141CB4(void);
void TObjMapWarp__sub_80141CB8(void);
void TObjRoomId__sub_80141CF4(void);
void fn_80141CBC(void *a, void *b, f32 s);
// The squared distance from a to b on the ground (x/z) plane.
f32 horizontal_distance_squared(const Vec *a, const Vec *b);
}

#endif
