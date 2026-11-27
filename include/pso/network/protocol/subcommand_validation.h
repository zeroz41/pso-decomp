#ifndef PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_H
#define PSO_NETWORK_PROTOCOL_SUBCOMMAND_VALIDATION_H

#include "pso/network/protocol/protocol_types.h"

struct G_AddBattleDamageScores_6x8F;
struct G_Attack_6x43_6x44_6x45;
struct G_AttackFinished_6x46;
struct G_CastTechnique_6x47;
struct G_CastTechniqueComplete_6x48;
struct G_CastTechniqueParams_6x47;
struct G_ChangePlayerHP_6x2F;
struct G_CreateLobbyChair_6xAB;
struct G_ChangePlayerLevel_6x30;
struct G_DeleteMultipleInventoryItems_6xAC;
struct G_DonateToPhotonBlast_6x38;
struct G_DropItem_6x2A;
struct G_ExecutePhotonBlastParams_6x49;
struct G_EquipItem_6x25;
struct G_HitByEnemy_6x4B_6x4C;
struct G_ImposeHold_6x2C;
struct G_InterLevelWarp_6x21;
struct G_IntraMapWarp_6x55;
struct G_LevelUpAllTechniques_6x9B;
struct G_LobbyAnimation_6x58;
struct G_MoveToPosition_6x41_6x42;
struct G_PhotonBlast_6x37;
struct G_PlaceTrap_6x83;
struct G_RevivePlayer_6x33;
struct G_SetAnimationState_6x52;
struct G_SetPlayerBattleTeam_6x90;
struct G_SetPlayerFloor_6x1F;
struct G_SetPlayerPositionAndAngle_6x56;
struct G_SetPosition_6x20;
struct G_SetPosition_6x3F;
struct G_SetTechniqueLevelOverride_6x8D;
struct G_StopAtPosition_6x3E;
struct G_TeleportPlayer_6x24;
struct G_UnequipItem_6x26;
struct G_WalkToPosition_6x40;
struct PhotonBlastTarget;
struct PlayerShrinkPacket;

LAYOUT_ASSERT(SubcommandHeaderSizeCheck, sizeof(G_ClientIDHeader) == 4);
#include <stddef.h>
LAYOUT_ASSERT(SubcommandClientOffsetCheck, offsetof(G_ClientIDHeader, client_id) == 2);

s32 validate_6x0E_clear_negative_status_effects(G_ClientIDHeader *packet);
s32 validate_6x0D_remove_status_effect(G_ClientIDHeader *packet);
s32 validate_6x0C_add_status_effect(G_ClientIDHeader *packet);
s32 validate_6xB0_move_lobby_chair(G_ClientIDHeader *packet);
s32 validate_6xAF_turn_lobby_chair(G_ClientIDHeader *packet);
s32 validate_6xAB(G_CreateLobbyChair_6xAB *packet);
s32 validate_6x58_lobby_animation(G_LobbyAnimation_6x58 *packet);
s32 validate_6x57(G_ClientIDHeader *packet);
s32 validate_6x56_set_player_position_and_angle(G_SetPlayerPositionAndAngle_6x56 *packet);
s32 validate_6x55_intra_map_warp(G_IntraMapWarp_6x55 *packet);
s32 validate_6x53(G_ClientIDHeader *packet);
s32 validate_6x52_set_animation_state(G_SetAnimationState_6x52 *packet);
s32 validate_6x50_switch_interaction(G_ClientIDHeader *packet);
s32 validate_6x4F_player_revived(G_ClientIDHeader *packet);
s32 validate_6x4E_player_revivable(G_ClientIDHeader *packet);
s32 validate_6x89_set_killer_entity_id(G_ClientIDHeader *packet);
s32 validate_6x4D_player_died(G_ClientIDHeader *packet);
s32 validate_6x4C_hit_by_enemy(G_HitByEnemy_6x4B_6x4C *packet);
s32 validate_6x4B_hit_by_enemy(G_HitByEnemy_6x4B_6x4C *packet);
s32 validate_6x4A_shield_attack(G_ClientIDHeader *packet);
s32 validate_photon_blast_parameters(G_ExecutePhotonBlastParams_6x49 *params);
s32 validate_6x48_cast_technique_complete(G_CastTechniqueComplete_6x48 *packet);
s32 validate_6x8D_set_technique_level_override(G_SetTechniqueLevelOverride_6x8D *packet);
s32 validate_6x47_cast_technique(G_CastTechnique_6x47 *packet);
s32 validate_technique_parameters(G_CastTechniqueParams_6x47 *params);
s32 validate_cast_target_entry(PhotonBlastTarget *target);
s32 validate_6x46_attack_finished(G_AttackFinished_6x46 *packet);
s32 validate_attack_target_list(s32 *list);
s32 validate_attack_target_entry(void *parameters);
s32 validate_6x45_attack(G_Attack_6x43_6x44_6x45 *packet);
s32 validate_6x44_attack(G_Attack_6x43_6x44_6x45 *packet);
s32 validate_6x83_place_trap(G_PlaceTrap_6x83 *packet);
s32 validate_6xA1_revive_player_v3(G_ClientIDHeader *packet);
s32 validate_6x31_use_medical_center(G_ClientIDHeader *packet);
s32 validate_6x30_change_player_level(G_ChangePlayerLevel_6x30 *packet);
s32 validate_6x2F_change_player_hp(G_ChangePlayerHP_6x2F *packet);
s32 validate_6x2E_set_or_clear_player_flags(G_ClientIDHeader *packet);
s32 validate_6x2D_release_hold(G_ClientIDHeader *packet);
s32 validate_6x2C_impose_hold(G_ImposeHold_6x2C *packet);
s32 validate_6x2B_create_inventory_item(G_ClientIDHeader *packet);
s32 validate_6x2A_drop_item(G_DropItem_6x2A *packet);
s32 validate_6xAC(G_DeleteMultipleInventoryItems_6xAC *packet);
s32 validate_6x29_delete_inventory_item(G_ClientIDHeader *packet);
s32 validate_6x28_feed_mag(G_ClientIDHeader *packet);
s32 validate_6x27_use_item(G_ClientIDHeader *packet);
s32 validate_6x26_unequip_item(G_UnequipItem_6x26 *packet);
s32 validate_6x25_equip_item(G_EquipItem_6x25 *packet);
s32 validate_6x24_teleport_player(G_TeleportPlayer_6x24 *packet);
s32 validate_6x23_set_player_visible(G_ClientIDHeader *packet);
s32 validate_6x22_set_player_invisible(G_ClientIDHeader *packet);
s32 validate_6x21_inter_level_warp(G_InterLevelWarp_6x21 *packet);
s32 validate_6x20_set_position(G_SetPosition_6x20 *packet);
s32 validate_6x1F_set_player_floor(G_SetPlayerFloor_6x1F *packet);
s32 validate_6x82_enable_drop_weapon_on_death(G_ClientIDHeader *packet);
s32 validate_6x81_disable_drop_weapon_on_death(G_ClientIDHeader *packet);
s32 validate_6x7B_disable_stealth_suit_effect(G_ClientIDHeader *packet);
s32 validate_6x7A_enable_stealth_suit_effect(G_ClientIDHeader *packet);
s32 validate_6x90_set_player_battle_team(G_SetPlayerBattleTeam_6x90 *packet);
s32 validate_6x8F_add_battle_damage_scores(G_AddBattleDamageScores_6x8F *packet);
s32 validate_6x1C_disable_pk_mode_for_player(G_ClientIDHeader *packet);
s32 validate_6x1B_enable_pk_mode_for_player(G_ClientIDHeader *packet);
s32 validate_6x9B_level_up_all_techniques(G_LevelUpAllTechniques_6x9B *packet);
s32 validate_subcommand_client(G_ClientIDHeader *packet);
// TRUE when an attack's target count is 0 to 10 (validate_attack_target_list).
s32 validate_attack_target_count(s32 *count);

#endif
