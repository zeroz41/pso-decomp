#ifndef PSO_PLAYER_TPLAYERFOOTSTAMPTYPES_H
#define PSO_PLAYER_TPLAYERFOOTSTAMPTYPES_H

#include "types.h"

// Per player class: the TObjPlayer::base_stats.proportions value the sizes above are for and
// how much the footprint grows per unit above it.
struct FootStampHeightScale {
    f32 base;
    f32 rate;
};

#endif
