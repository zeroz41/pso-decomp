#ifndef PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_PHOTON_BLAST_H
#define PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_PHOTON_BLAST_H

#include "types.h"

extern "C" {
s32 validate_6x48_cast_technique_complete(G_ClientIDHeader *packet);
s32 validate_6x8D_set_technique_level_override(G_ClientIDHeader *packet);
}

// --- C functions defined in subcommand_validation_photon_blast.cpp ---
extern "C" {
s32 validate_6x48_cast_technique_complete(G_ClientIDHeader *packet);
s32 validate_6x8D_set_technique_level_override(G_ClientIDHeader *packet);
}
// --- end of C functions

#endif
