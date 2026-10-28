#ifndef PSO_PLAYER_PHOTONBLASTGAUGE_H
#define PSO_PLAYER_PHOTONBLASTGAUGE_H

#include "types.h"

// A player's photon blast state (TObjPlayer + 0x4AC): the charge the mag's
// support events and the photon blast window read.
struct PhotonBlastGauge {
    // Empties the charge.
    void clear_charge();

    u8 pad_0[0x3C];
    f32 charge;
};

#endif
