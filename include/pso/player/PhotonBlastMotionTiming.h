#ifndef PSO_PLAYER_PHOTONBLASTMOTIONTIMING_H
#define PSO_PLAYER_PHOTONBLASTMOTIONTIMING_H

#include "types.h"

// Photon blast motion frames of one weapon handle.
struct PhotonBlastMotionTiming {
    f32 hold_frame;
    f32 upper_bound;
    f32 complete_threshold;
};

#endif
