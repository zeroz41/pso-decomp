#ifndef PSO_PLAYER_TOBJPLAYER_800A7764_H
#define PSO_PLAYER_TOBJPLAYER_800A7764_H

#include "types.h"
#include <dolphin/mtx.h>

class TObjBase;

extern "C" {
// Copies position into object's TObjBase position.
void TObjPlayer__sub_800A7774(TObjBase *object, const Vec *position);
}

#endif
