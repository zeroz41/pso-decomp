#ifndef PSO_NETWORK_PROTOCOL_CAST_PACKETS_H
#define PSO_NETWORK_PROTOCOL_CAST_PACKETS_H

#include "types.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/player/PhotonBlastGauge.h"

// 6x47's parameters after the header: the technique, the level it is cast
// at and how many of the targets follow.
struct G_CastTechniqueParams_6x47 {
    G_CastTechniqueParams_6x47();

    s8 technique_number;
    u8 unused;
    u8 level;
    s8 target_count;
};

// 6x47: a player casts a technique on up to ten targets.
struct G_CastTechnique_6x47 {
    G_CastTechnique_6x47();

    // Bytes actually sent: the header, the parameters and target_count targets.
    u8 get_size();
    void bswap();
    // Sets the header size, byte-swaps and sends the packet.
    void send();

    G_ClientIDHeader header;
    G_CastTechniqueParams_6x47 params;
    PhotonBlastTarget targets[10];
};

LAYOUT_ASSERT(G_CastTechnique_6x47Size, sizeof(G_CastTechnique_6x47) == 0x30);

// 6x49's parameters after the header (validate_photon_blast_parameters
// checks them).
struct G_ExecutePhotonBlastParams_6x49 {
    G_ExecutePhotonBlastParams_6x49();

    s8 photon_blast; // -1, or which of the six
    u8 unused1;
    s16 target_count;
    s16 pb_meter_value;
    s16 unused2;
};

// 6x49: a player fires a photon blast at up to ten targets.
struct G_ExecutePhotonBlast_6x49 {
    G_ExecutePhotonBlast_6x49();

    G_ClientIDHeader header;
    G_ExecutePhotonBlastParams_6x49 params;
    PhotonBlastTarget targets[10];
};

LAYOUT_ASSERT(G_ExecutePhotonBlast_6x49Size, sizeof(G_ExecutePhotonBlast_6x49) == 0x34);

#endif
