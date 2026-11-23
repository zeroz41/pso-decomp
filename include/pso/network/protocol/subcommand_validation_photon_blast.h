#ifndef PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_PHOTON_BLAST_H
#define PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_PHOTON_BLAST_H

#include "types.h"
#include "pso/network/protocol/subcmd_6x.h"

// 6x49 as validated: the header (its parameters checked by
// validate_photon_blast_parameters), then target_count target entries.
struct G_ExecutePhotonBlast_6x49 {
    G_ExecutePhotonBlast_Header_6x49 header;
    u32 targets[1];
};

extern "C" {
s32 validate_6x49_execute_photon_blast(G_ExecutePhotonBlast_6x49 *packet);
}

#endif
