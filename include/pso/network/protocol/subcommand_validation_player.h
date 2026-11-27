#ifndef PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_PLAYER_H
#define PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_PLAYER_H

#include "types.h"

struct G_Attack_6x43_6x44_6x45;
struct G_ClientIDHeader;
struct G_DonateToPhotonBlast_6x38;
struct G_ImposeHold_6x2C;
struct G_MoveToPosition_6x41_6x42;
struct G_PhotonBlast_6x37;
struct G_RevivePlayer_6x33;
struct G_SetAnimationState_6xAE;
struct G_SetPosition_6x3F;
struct G_StopAtPosition_6x3E;
struct G_WalkToPosition_6x40;
struct PlayerShrinkPacket;
struct CapturedTarget;

// --- C functions defined in subcommand_validation_player.cpp ---
s32 validate_6x33_revive_player(G_RevivePlayer_6x33 *packet);
s32 validate_6x37_photon_blast(G_PhotonBlast_6x37 *packet);
s32 validate_6x38_donate_to_photon_blast(G_DonateToPhotonBlast_6x38 *packet);
s32 validate_6x39_set_photon_blast_ready_flag(G_ClientIDHeader *packet);
s32 validate_6x3A_clear_photon_blast_ready_flag(G_ClientIDHeader *packet);
s32 validate_6x3B_clear_temporary_photon_blast_state_flags(G_ClientIDHeader *packet);
s32 validate_6x3E_stop_at_position(G_StopAtPosition_6x3E *packet);
s32 validate_6x3F_set_position(G_SetPosition_6x3F *packet);
s32 validate_6x40_walk_to_position(G_WalkToPosition_6x40 *packet);
s32 validate_6x42_move_to_position(G_MoveToPosition_6x41_6x42 *packet);
s32 validate_6x43_attack(G_Attack_6x43_6x44_6x45 *packet);
s32 validate_6x44_attack(G_Attack_6x43_6x44_6x45 *packet);
s32 validate_6x45_attack(G_Attack_6x43_6x44_6x45 *packet);
s32 validate_6x87_shrink_player(PlayerShrinkPacket *packet);
s32 validate_6x88_restore_shrunken_player(G_ClientIDHeader *packet);
s32 validate_attack_target_entry(CapturedTarget *target);
s32 validate_6xAE_set_animation_state(G_SetAnimationState_6xAE *packet);
// --- end of C functions

#endif
