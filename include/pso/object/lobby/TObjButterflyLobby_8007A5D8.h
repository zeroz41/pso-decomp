#ifndef PSO_OBJECT_LOBBY_TOBJBUTTERFLYLOBBY_8007A5D8_H
#define PSO_OBJECT_LOBBY_TOBJBUTTERFLYLOBBY_8007A5D8_H

#include "types.h"
#include <dolphin/mtx.h>

extern "C" {
// The first map collision on the segment from `from` to `to` (NULL if none).
void *csnVector(const Vec *from, const Vec *to, u32 mask);
}

#endif
