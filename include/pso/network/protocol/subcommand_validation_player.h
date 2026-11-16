#ifndef PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_PLAYER_H
#define PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_PLAYER_H

#include "types.h"

// --- C functions defined in subcommand_validation_player.cpp ---
s32 validate_6x33_revive_player(G_ClientIDHeader *packet);
s32 validate_6x37_photon_blast(G_ClientIDHeader *packet);
extern "C" {
s32 validate_6x38_donate_to_photon_blast(G_ClientIDHeader *packet);
s32 validate_6x39_set_photon_blast_ready_flag(G_ClientIDHeader *packet);
s32 validate_6x3A_clear_photon_blast_ready_flag(G_ClientIDHeader *packet);
s32 validate_6x3B_clear_temporary_photon_blast_state_flags(G_ClientIDHeader *packet);
}
s32 validate_6x3E_stop_at_position(G_ClientIDHeader *packet);
s32 validate_6x3F_set_position(G_ClientIDHeader *packet);
s32 validate_6x40_walk_to_position(G_ClientIDHeader *packet);
s32 validate_6x42_move_to_position(G_ClientIDHeader *packet);
s32 validate_6x43_attack(G_ClientIDHeader *packet);
s32 validate_6x44_attack(G_ClientIDHeader *packet);
s32 validate_6x45_attack(G_ClientIDHeader *packet);
extern "C" {
s32 validate_6x87_shrink_player(G_ClientIDHeader *packet);
s32 validate_6x88_restore_shrunken_player(G_ClientIDHeader *packet);
s32 validate_attack_target_entry(void *parameters);
}
// --- end of C functions

#endif
