#ifndef PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_TECHNIQUE_H
#define PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_TECHNIQUE_H

#include "types.h"

extern "C" {
s32 validate_6x46_attack_finished(G_ClientIDHeader *packet);
}

// --- C functions defined in subcommand_validation_technique.cpp ---
extern "C" {
s32 validate_6x46_attack_finished(G_ClientIDHeader *packet);
}
// --- end of C functions

#endif
