#ifndef PSO_PLAYER_PHOTONBLASTAIM_H
#define PSO_PLAYER_PHOTONBLASTAIM_H

#include "types.h"
#include "dolphin/mtx/GeoTypes.h"

// TObjPlayer + 0x744: the entity a photon blast is aimed at and the point
// enter_photon_blast_action turns the player towards.
struct PhotonBlastAim {
    u16 target_id;
    u16 pad_2;
    Vec position;

    void reset();
};

LAYOUT_ASSERT(PhotonBlastAim_size, sizeof(PhotonBlastAim) == 0x10);

#endif
