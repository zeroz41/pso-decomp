#ifndef PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_ACTIONS_H
#define PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_ACTIONS_H

#include "types.h"

extern "C" {
s32 validate_6x4A_shield_attack(G_ClientIDHeader *packet);
s32 validate_6x4B_hit_by_enemy(G_ClientIDHeader *packet);
s32 validate_6x4C_hit_by_enemy(G_ClientIDHeader *packet);
s32 validate_6x4D_player_died(G_ClientIDHeader *packet);
s32 validate_6x4E_player_revivable(G_ClientIDHeader *packet);
s32 validate_6x4F_player_revived(G_ClientIDHeader *packet);
s32 validate_6x50_switch_interaction(G_ClientIDHeader *packet);
s32 validate_6x52_set_animation_state(G_ClientIDHeader *packet);
s32 validate_6x53(G_ClientIDHeader *packet);
s32 validate_6x55_intra_map_warp(G_ClientIDHeader *packet);
s32 validate_6x56_set_player_position_and_angle(G_ClientIDHeader *packet);
s32 validate_6x57(G_ClientIDHeader *packet);
s32 validate_6x58_lobby_animation(G_ClientIDHeader *packet);
s32 validate_6x89_set_killer_entity_id(G_ClientIDHeader *packet);
s32 validate_6xAB(G_ClientIDHeader *packet);
}

// --- C functions defined in subcommand_validation_actions.cpp ---
extern "C" {
s32 validate_6x4A_shield_attack(G_ClientIDHeader *packet);
s32 validate_6x4B_hit_by_enemy(G_ClientIDHeader *packet);
s32 validate_6x4C_hit_by_enemy(G_ClientIDHeader *packet);
s32 validate_6x4D_player_died(G_ClientIDHeader *packet);
s32 validate_6x4E_player_revivable(G_ClientIDHeader *packet);
s32 validate_6x4F_player_revived(G_ClientIDHeader *packet);
s32 validate_6x50_switch_interaction(G_ClientIDHeader *packet);
s32 validate_6x52_set_animation_state(G_ClientIDHeader *packet);
s32 validate_6x53(G_ClientIDHeader *packet);
s32 validate_6x55_intra_map_warp(G_ClientIDHeader *packet);
s32 validate_6x56_set_player_position_and_angle(G_ClientIDHeader *packet);
s32 validate_6x57(G_ClientIDHeader *packet);
s32 validate_6x58_lobby_animation(G_ClientIDHeader *packet);
s32 validate_6x89_set_killer_entity_id(G_ClientIDHeader *packet);
s32 validate_6xAB(G_ClientIDHeader *packet);
}
// --- end of C functions

#endif
