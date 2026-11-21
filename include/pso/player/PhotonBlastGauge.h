#ifndef PSO_PLAYER_PHOTONBLASTGAUGE_H
#define PSO_PLAYER_PHOTONBLASTGAUGE_H

#include "types.h"

// A player's photon blast state (TObjPlayer + 0x4AC): the charge the mag's
// support events and the photon blast window read.
struct PhotonBlastGauge {
    // Empties the charge.
    void clear_charge();
    f32 get_charge();
    // The equipped mag's level for blast (0-5), -1 when no mag holds it.
    void set_blast_level(s16 blast, s8 level);

    u8 pad_0[0x3C];
    f32 charge;
    u8 pad_40[0x4];
    s8 blast_levels[6];
    u8 pad_4a[0xA];
};

LAYOUT_ASSERT(PhotonBlastGaugeSize, sizeof(PhotonBlastGauge) == 0x54);

#endif
