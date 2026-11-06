#ifndef PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_H
#define PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_H

#include "pso/network/protocol/protocol_types.h"

typedef char SubcommandHeaderSizeCheck[sizeof(G_ClientIDHeader) == 4 ? 1 : -1];
#include <stddef.h>
typedef char SubcommandClientOffsetCheck[offsetof(G_ClientIDHeader, client_id) == 2 ? 1 : -1];

s32 validate_6x0E_clear_negative_status_effects(G_ClientIDHeader *packet);
extern "C" {
s32 validate_6xAB(G_ClientIDHeader *packet);
s32 validate_6x58_lobby_animation(G_ClientIDHeader *packet);
s32 validate_6x57(G_ClientIDHeader *packet);
s32 validate_6x56_set_player_position_and_angle(G_ClientIDHeader *packet);
s32 validate_6x55_intra_map_warp(G_ClientIDHeader *packet);
s32 validate_6x53(G_ClientIDHeader *packet);
s32 validate_6x52_set_animation_state(G_ClientIDHeader *packet);
s32 validate_6x50_switch_interaction(G_ClientIDHeader *packet);
s32 validate_6x4F_player_revived(G_ClientIDHeader *packet);
s32 validate_6x4E_player_revivable(G_ClientIDHeader *packet);
s32 validate_6x89_set_killer_entity_id(G_ClientIDHeader *packet);
s32 validate_6x4D_player_died(G_ClientIDHeader *packet);
s32 validate_6x4C_hit_by_enemy(G_ClientIDHeader *packet);
s32 validate_6x4B_hit_by_enemy(G_ClientIDHeader *packet);
s32 validate_6x4A_shield_attack(G_ClientIDHeader *packet);
}
s32 validate_photon_blast_parameters(void *parameters);
extern "C" {
s32 validate_6x48_cast_technique_complete(G_ClientIDHeader *packet);
s32 validate_6x8D_set_technique_level_override(G_ClientIDHeader *packet);
}
s32 validate_6x47_cast_technique(u8 *packet);
s32 validate_technique_parameters(void *parameters);
s32 validate_cast_target_entry(void *parameters);
extern "C" {
s32 validate_6x46_attack_finished(G_ClientIDHeader *packet);
}
s32 validate_attack_target_list(s32 *list);
extern "C" {
s32 validate_attack_target_entry(void *parameters);
s32 validate_6x45_attack(G_ClientIDHeader *packet);
s32 validate_6x44_attack(G_ClientIDHeader *packet);
s32 validate_6x43_attack(G_ClientIDHeader *packet);
s32 validate_6x42_move_to_position(G_ClientIDHeader *packet);
s32 validate_6x40_walk_to_position(G_ClientIDHeader *packet);
s32 validate_6x3F_set_position(G_ClientIDHeader *packet);
s32 validate_6x3E_stop_at_position(G_ClientIDHeader *packet);
s32 validate_6x88_restore_shrunken_player(G_ClientIDHeader *packet);
s32 validate_6x87_shrink_player(G_ClientIDHeader *packet);
}
s32 validate_6x83_place_trap(G_ClientIDHeader *packet);
extern "C" {
s32 validate_6x3B_clear_temporary_photon_blast_state_flags(G_ClientIDHeader *packet);
s32 validate_6x3A_clear_photon_blast_ready_flag(G_ClientIDHeader *packet);
s32 validate_6x39_set_photon_blast_ready_flag(G_ClientIDHeader *packet);
s32 validate_6x38_donate_to_photon_blast(G_ClientIDHeader *packet);
s32 validate_6x37_photon_blast(G_ClientIDHeader *packet);
s32 validate_6x33_revive_player(G_ClientIDHeader *packet);
}
s32 validate_6xA1_revive_player_v3(G_ClientIDHeader *packet);
s32 validate_6x31_use_medical_center(G_ClientIDHeader *packet);
s32 validate_6x30_change_player_level(G_ClientIDHeader *packet);
s32 validate_6x2F_change_player_hp(G_ClientIDHeader *packet);
s32 validate_6x2E_set_or_clear_player_flags(G_ClientIDHeader *packet);
s32 validate_6x2D_release_hold(G_ClientIDHeader *packet);
s32 validate_6x2C_impose_hold(G_ClientIDHeader *packet);
s32 validate_6x2B_create_inventory_item(G_ClientIDHeader *packet);
s32 validate_6x2A_drop_item(G_ClientIDHeader *packet);
s32 validate_6xAC(G_ClientIDHeader *packet);
s32 validate_6x29_delete_inventory_item(G_ClientIDHeader *packet);
s32 validate_6x28_feed_mag(G_ClientIDHeader *packet);
s32 validate_6x27_use_item(G_ClientIDHeader *packet);
s32 validate_6x26_unequip_item(G_ClientIDHeader *packet);
s32 validate_6x25_equip_item(G_ClientIDHeader *packet);
s32 validate_6x24_teleport_player(G_ClientIDHeader *packet);
s32 validate_6x23_set_player_visible(G_ClientIDHeader *packet);
s32 validate_6x22_set_player_invisible(G_ClientIDHeader *packet);
s32 validate_6x21_inter_level_warp(G_ClientIDHeader *packet);
s32 validate_6x20_set_position(G_ClientIDHeader *packet);
s32 validate_6x1F_set_player_floor(G_ClientIDHeader *packet);
s32 validate_6x82_enable_drop_weapon_on_death(G_ClientIDHeader *packet);
s32 validate_6x81_disable_drop_weapon_on_death(G_ClientIDHeader *packet);
s32 validate_6x7B_disable_stealth_suit_effect(G_ClientIDHeader *packet);
s32 validate_6x7A_enable_stealth_suit_effect(G_ClientIDHeader *packet);
s32 validate_6x90_set_player_battle_team(G_ClientIDHeader *packet);
s32 validate_6x8F_add_battle_damage_scores(G_ClientIDHeader *packet);
s32 validate_6x1C_disable_pk_mode_for_player(G_ClientIDHeader *packet);
s32 validate_6x1B_enable_pk_mode_for_player(G_ClientIDHeader *packet);
s32 validate_6x9B_level_up_all_techniques(G_ClientIDHeader *packet);
extern "C" {
s32 validate_subcommand_client(G_ClientIDHeader *packet);
}

#endif
