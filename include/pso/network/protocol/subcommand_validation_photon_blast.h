#ifndef PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_PHOTON_BLAST_H
#define PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_PHOTON_BLAST_H

#include "types.h"
#include "pso/network/protocol/cast_packets.h"

extern "C" {
s32 validate_6x49_execute_photon_blast(G_ExecutePhotonBlast_6x49 *packet);
}

#endif
