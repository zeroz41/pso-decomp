#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/FloorEventCommand.h"
#include "pso/boss/olgaflow/OlgaFlowActions.h"
#include "pso/boss/galgryphon/Boss5GryphonBehavior.h"
#include "pso/network/TGameProtocol.h"
#include "pso/unk/text_800C7FEC.h"
#include "pso/ui/window/TWindowKeyBoardHard_801A529C.h"
#include "pso/unk/TLobby_801C25B4.h"
#include "pso/unk/TLobby_80227AA0.h"
#include "pso/quest/TQuestThread.h"
#include "pso/network/TPacket.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/item/TItem.h"
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/network/protocol/GameplaySoundPacket.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/text_801E3F24.h"
#include "pso/system/debug_print.h"
#include "pso/map/FloorArea.h"
#include "pso/object/door/TObjDoorKey.h"
#include "pso/object/fence/WallHitPacket.h"
#include "pso/player/TObjPlayer_80011014.h"
#include <stdio.h>
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/object/lobby/LobbyGoGoBall.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/network/TradeSession.h"
#include "pso/object/TObjHashi.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/unk/TLobby_80103F5C.h"
#include "pso/unk/text_80072230.h"
#include "pso/unk/text_8011A780.h"
#include "pso/unk/text_801F3774.h"
#include "pso/npc/NpcPartnerControl.h"

struct TBoss3Volopt;
struct TLobby;
struct TObjPlayer;

TObject *game_protocol_instance;
void *TGameProtocol__instance;
// The class name opens the unit's .rodata, before the receive log formats of the
// dispatchers below.
extern "C" {
const char *TGameProtocol__class_name = "TGameProtocol";
}
s32 dispatching_own_subcommand;


void handle_6x05_write_switch_flag(void *arg0);
extern "C" void handle_6x07_symbol_chat();
extern "C" void handle_6x0A_update_enemy_state();
void handle_6x0B_update_object_state(G_UpdateObjectState_6x0B *packet);
extern "C" void handle_6x0C_add_or_remove_status_effect(void *arg0);
extern "C" void handle_6x0D_add_or_remove_status_effect(void *arg0);
extern "C" void handle_6x0E_clear_negative_status_effects(s32 arg0);
extern "C" void handle_6x18_vol_opt2_boss_actions();
extern "C" void handle_6x19_dark_falz_actions();
extern "C" void handle_6x1B_enable_pk_mode_for_player(void *arg0);
extern "C" void handle_6x1C_disable_pk_mode_for_player(void *arg0);
extern "C" void handle_6x1F_set_player_floor(void *arg0);
extern "C" void handle_6x20_set_position(void *arg0);
extern "C" void handle_6x21_inter_level_warp(void *arg0);
extern "C" void handle_6x22_set_player_invisible(void *arg0);
extern "C" void handle_6x23_set_player_visible(void *arg0);
extern "C" void handle_6x24_teleport_player(saddr arg0);
extern "C" void handle_6x25_equip_item(void *arg0);
extern "C" void handle_6x26_unequip_item(void *arg0);
extern "C" void handle_6x27_use_item(saddr arg0);
extern "C" void handle_6x28_feed_mag(saddr arg0);
extern "C" void handle_6x29_delete_inventory_item(void *arg0);
extern "C" void handle_6x2A_drop_item(void *arg0);
extern "C" void handle_6x2B_create_inventory_item(saddr arg0);
extern "C" void handle_6x2C_impose_hold(saddr arg0);
extern "C" void handle_6x2D_release_hold(void *arg0);
extern "C" void handle_6x2E_set_or_clear_player_flags(void *arg0);
extern "C" void handle_6x2F_change_player_hp(saddr arg0);
extern "C" void handle_6x30_change_player_level(void *arg0);
extern "C" void handle_6x31_use_medical_center(void *arg0);
extern "C" void handle_6x32_medical_center_revive_all_players();
extern "C" void handle_6x33_revive_player(void *arg0);
extern "C" void handle_6x34();
extern "C" void handle_6x36();
extern "C" void handle_6x37_photon_blast(saddr arg0);
void handle_6x38_donate_to_photon_blast(saddr arg0);
void handle_6x39_set_photon_blast_ready_flag(saddr arg0);
void handle_6x3A_clear_photon_blast_ready_flag(saddr arg0);
void handle_6x3B_clear_temporary_photon_blast_state_flags(saddr arg0);
extern "C" void handle_6x3E_stop_at_position(void *arg0);
extern "C" void handle_6x3F_set_position(void *arg0);
extern "C" void handle_6x40_walk_to_position(void *pkt);
extern "C" void handle_6x41_move_to_position();
extern "C" void handle_6x42_move_to_position(void *pkt);
extern "C" void handle_6x43_attack(void *src);
extern "C" void handle_6x44_attack(void *src);
extern "C" void handle_6x45_attack(void *src);
extern "C" void handle_6x46_attack_finished(s32 arg0);
extern "C" void handle_6x47_cast_technique(u8 *self);
extern "C" void handle_6x48_cast_technique_complete(void *arg);
extern "C" void handle_6x49_execute_photon_blast(void *arg0);
extern "C" void handle_6x4A_shield_attack(void *arg0);
extern "C" void handle_6x4B_hit_by_enemy(void *arg0);
extern "C" void handle_6x4C_hit_by_enemy(void *arg0);
extern "C" void handle_6x4D_player_died(void *arg0);
extern "C" void handle_6x4E_player_revivable(void *arg0);
extern "C" void handle_6x4F_player_revived(void *arg0);
extern "C" void handle_6x50_switch_interaction(const void *source);
extern "C" void handle_6x52_set_animation_state(saddr arg0);
extern "C" void handle_6x53(void *arg0);
extern "C" void handle_6x54();
extern "C" void handle_6x56_set_player_position_and_angle(void *arg0);
extern "C" void handle_6x57(void *arg0);
extern "C" void handle_6x58_lobby_animation(void *arg0);
extern "C" void handle_6x5A_pick_up_item_request();
extern "C" void handle_6x5F_drop_item();
void handle_6x62();
extern "C" void handle_6x64();
extern "C" void handle_6x65();
void handle_6x66_use_star_atomizer(u8 *arg0);
extern "C" void handle_6x68_set_telepipe_state();
extern "C" void handle_6x6B_sync_game_state();
extern "C" void handle_6x6C_sync_game_state();
extern "C" void handle_6x6D_sync_game_state();
extern "C" void handle_6x6E_sync_game_state();
void handle_6x6F_set_quest_flags_v2(saddr arg0);
extern "C" void handle_6x70_sync_player_disp_and_inventory();
void handle_6x71_unblock_game_join();
void handle_6x72_done_loading_into_game();
void handle_6x73_exit_quest();
void handle_6x74_word_select(u8 *arg0);
extern "C" void handle_6x76_set_entity_set_flags();
extern "C" void handle_6x7A_enable_stealth_suit_effect(void *arg0);
extern "C" void handle_6x7B_disable_stealth_suit_effect(void *arg0);
extern "C" void handle_6x7C_set_challenge_records();
extern "C" void handle_6x7D_set_battle_mode_data();
struct game_command_header;
extern "C" void handle_6x80_trigger_trap(game_command_header *command);
extern "C" void handle_6x81_disable_drop_weapon_on_death(void *arg0);
extern "C" void handle_6x82_enable_drop_weapon_on_death(void *arg0);
extern "C" void handle_6x83_place_trap(void *arg0);
extern "C" void handle_6x87_shrink_player();
extern "C" void handle_6x88_restore_shrunken_player();
extern "C" void handle_6x89_set_killer_entity_id(void *arg0);
extern "C" void handle_6x8A_show_challenge_time_records_window();
extern "C" void handle_6x8B();
extern "C" void handle_6x8C();
extern "C" void handle_6x8D_set_technique_level_override(void *arg0);
extern "C" void handle_6x8E();
extern "C" void handle_6x8F_add_battle_damage_scores(saddr arg0);
extern "C" void handle_6x90_set_player_battle_team(saddr arg0);
extern "C" void handle_6x91_update_attackable_col_state();
void handle_6x92(u8 *arg0);
extern "C" void handle_6x93_set_switch_flag_from_timer();
extern "C" void handle_6x95_set_challenge_time();
void handle_6x96();
extern "C" void handle_6x98();
extern "C" void handle_6x99();
extern "C" void handle_6x9A_update_entity_stat();
extern "C" void handle_6x9B_level_up_all_techniques(void *arg0);
extern "C" void handle_6x9C_set_enemy_low_game_flags_ultimate();
extern "C" void handle_6x9D_set_challenge_dead_flag();
extern "C" void handle_6xA1_revive_player_v3(void *arg0);
void handle_6xA7();
void handle_6xA8_gol_dragon_boss_actions(void *arg0);
void handle_6xA9_barba_ray_boss_actions(void *arg0);
void handle_6xAA_barba_ray_boss_actions(void *arg0);
extern "C" void handle_6xAB(void *arg0);
extern "C" void handle_6xAC(void *arg0);
extern "C" void handle_6xAD_olga_flow_subordinate_boss_actions();
extern "C" void handle_6xAE_set_animation_state(void *arg0);
extern "C" void handle_6xAF_turn_or_move_lobby_chair(void *arg0);
extern "C" void handle_6xB0_turn_or_move_lobby_chair(void *arg0);
extern "C" void handle_6xB1();
u32 lbl_804C5238[10] = { 0 };

u8 subcommand_area_masks[36] = {
    2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 1, 4, 4, 2, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
};
PsoCommandHandler pso_command_dispatch_table[] = {
    {0x3E, 0x0007, (PsoCommandFn)handle_6x3E_stop_at_position},
    {0x40, 0x0007, (PsoCommandFn)handle_6x40_walk_to_position},
    {0x42, 0x0007, (PsoCommandFn)handle_6x42_move_to_position},
    {0x43, 0x0004, (PsoCommandFn)handle_6x43_attack},
    {0x44, 0x0004, (PsoCommandFn)handle_6x44_attack},
    {0x45, 0x0004, (PsoCommandFn)handle_6x45_attack},
    {0x46, 0x0004, (PsoCommandFn)handle_6x46_attack_finished},
    {0x47, 0x0006, (PsoCommandFn)handle_6x47_cast_technique},
    {0x8D, 0x0006, (PsoCommandFn)handle_6x8D_set_technique_level_override},
    {0x48, 0x0006, (PsoCommandFn)handle_6x48_cast_technique_complete},
    {0x4A, 0x0006, (PsoCommandFn)handle_6x4A_shield_attack},
    {0x4B, 0x0006, (PsoCommandFn)handle_6x4B_hit_by_enemy},
    {0x4C, 0x0006, (PsoCommandFn)handle_6x4C_hit_by_enemy},
    {0x4D, 0x0006, (PsoCommandFn)handle_6x4D_player_died},
    {0x89, 0x0006, (PsoCommandFn)handle_6x89_set_killer_entity_id},
    {0x04, 0x0007, (PsoCommandFn)handle_6x04_legacy_activate_switch_by_token},
    {0x05, 0x0007, (PsoCommandFn)handle_6x05_write_switch_flag},
    {0x07, 0x0007, (PsoCommandFn)handle_6x07_symbol_chat},
    {0x09, 0x0007, (PsoCommandFn)handle_6x09_legacy_kill_enemy},
    {0x0A, 0x0006, (PsoCommandFn)handle_6x0A_update_enemy_state},
    {0x0B, 0x0007, (PsoCommandFn)handle_6x0B_update_object_state},
    {0x76, 0x0007, (PsoCommandFn)handle_6x76_set_entity_set_flags},
    {0x49, 0x0006, (PsoCommandFn)handle_6x49_execute_photon_blast},
    {0x4F, 0x0006, (PsoCommandFn)handle_6x4F_player_revived},
    {0x50, 0x0006, (PsoCommandFn)handle_6x50_switch_interaction},
    {0x52, 0x0007, (PsoCommandFn)handle_6x52_set_animation_state},
    {0x53, 0x0006, (PsoCommandFn)handle_6x53},
    {0x54, 0x0007, (PsoCommandFn)handle_6x54},
    {0x55, 0x0006, handle_6x55_intra_map_warp},
    {0x56, 0x0006, (PsoCommandFn)handle_6x56_set_player_position_and_angle},
    {0x57, 0x0007, (PsoCommandFn)handle_6x57},
    {0x58, 0x0007, (PsoCommandFn)handle_6x58_lobby_animation},
    {0xAB, 0x0007, (PsoCommandFn)handle_6xAB},
    {0xAF, 0x0007, (PsoCommandFn)handle_6xAF_turn_or_move_lobby_chair},
    {0xB0, 0x0007, (PsoCommandFn)handle_6xB0_turn_or_move_lobby_chair},
    {0xB1, 0x0007, (PsoCommandFn)handle_6xB1},
    {0xAE, 0x0007, (PsoCommandFn)handle_6xAE_set_animation_state},
    {0x4E, 0x0006, (PsoCommandFn)handle_6x4E_player_revivable},
    {0x3F, 0x0007, (PsoCommandFn)handle_6x3F_set_position},
    {0x59, 0x0006, (PsoCommandFn)handle_6x59_pick_up_item},
    {0x5A, 0x0006, (PsoCommandFn)handle_6x5A_pick_up_item_request},
    {0x5C, 0x0006, (PsoCommandFn)handle_6x5C_destroy_floor_item},
    {0x5D, 0x0006, (PsoCommandFn)handle_6x5D_drop_stacked_item},
    {0x5E, 0x0006, (PsoCommandFn)handle_6x5E_buy_shop_item},
    {0x5F, 0x0006, (PsoCommandFn)handle_6x5F_drop_item},
    {0x60, 0x0006, (PsoCommandFn)handle_6x60_standard_drop_item_request},
    {0xA2, 0x0006, (PsoCommandFn)handle_6xA2_specializable_item_drop_request},
    {0x61, 0x0006, (PsoCommandFn)handle_6x61_activate_item_effect},
    {0x62, 0x0006, (PsoCommandFn)handle_6x62},
    {0x63, 0x0006, (PsoCommandFn)handle_6x63_destroy_floor_item},
    {0x66, 0x0006, (PsoCommandFn)handle_6x66_use_star_atomizer},
    {0x98, 0x0007, (PsoCommandFn)handle_6x98},
    {0x99, 0x0007, (PsoCommandFn)handle_6x99},
    {0x1B, 0x0007, (PsoCommandFn)handle_6x1B_enable_pk_mode_for_player},
    {0x1C, 0x0007, (PsoCommandFn)handle_6x1C_disable_pk_mode_for_player},
    {0x8E, 0x0007, (PsoCommandFn)handle_6x8E},
    {0x8F, 0x0007, (PsoCommandFn)handle_6x8F_add_battle_damage_scores},
    {0x90, 0x0007, (PsoCommandFn)handle_6x90_set_player_battle_team},
    {0x1F, 0x0007, (PsoCommandFn)handle_6x1F_set_player_floor},
    {0x20, 0x0007, (PsoCommandFn)handle_6x20_set_position},
    {0x21, 0x0007, (PsoCommandFn)handle_6x21_inter_level_warp},
    {0x24, 0x0007, (PsoCommandFn)handle_6x24_teleport_player},
    {0x22, 0x0007, (PsoCommandFn)handle_6x22_set_player_invisible},
    {0x23, 0x0007, (PsoCommandFn)handle_6x23_set_player_visible},
    {0x25, 0x0006, (PsoCommandFn)handle_6x25_equip_item},
    {0x26, 0x0006, (PsoCommandFn)handle_6x26_unequip_item},
    {0x27, 0x0006, (PsoCommandFn)handle_6x27_use_item},
    {0x28, 0x0006, (PsoCommandFn)handle_6x28_feed_mag},
    {0x29, 0x0006, (PsoCommandFn)handle_6x29_delete_inventory_item},
    {0xAC, 0x0006, (PsoCommandFn)handle_6xAC},
    {0x2A, 0x0006, (PsoCommandFn)handle_6x2A_drop_item},
    {0x2B, 0x0007, (PsoCommandFn)handle_6x2B_create_inventory_item},
    {0x2C, 0x0007, (PsoCommandFn)handle_6x2C_impose_hold},
    {0x2D, 0x0007, (PsoCommandFn)handle_6x2D_release_hold},
    {0x2E, 0x0007, (PsoCommandFn)handle_6x2E_set_or_clear_player_flags},
    {0x2F, 0x0007, (PsoCommandFn)handle_6x2F_change_player_hp},
    {0x30, 0x0006, (PsoCommandFn)handle_6x30_change_player_level},
    {0x31, 0x0007, (PsoCommandFn)handle_6x31_use_medical_center},
    {0xA1, 0x0007, (PsoCommandFn)handle_6xA1_revive_player_v3},
    {0x32, 0x0007, (PsoCommandFn)handle_6x32_medical_center_revive_all_players},
    {0x33, 0x0007, (PsoCommandFn)handle_6x33_revive_player},
    {0x34, 0x0006, (PsoCommandFn)handle_6x34},
    {0x36, 0x0006, (PsoCommandFn)handle_6x36},
    {0x37, 0x0006, (PsoCommandFn)handle_6x37_photon_blast},
    {0x38, 0x0006, (PsoCommandFn)handle_6x38_donate_to_photon_blast},
    {0x39, 0x0006, (PsoCommandFn)handle_6x39_set_photon_blast_ready_flag},
    {0x3A, 0x0006, (PsoCommandFn)handle_6x3A_clear_photon_blast_ready_flag},
    {0x3B, 0x0007, (PsoCommandFn)handle_6x3B_clear_temporary_photon_blast_state_flags},
    {0x0C, 0x0006, (PsoCommandFn)handle_6x0C_add_or_remove_status_effect},
    {0x0D, 0x0007, (PsoCommandFn)handle_6x0D_add_or_remove_status_effect},
    {0x0E, 0x0006, (PsoCommandFn)handle_6x0E_clear_negative_status_effects},
    {0x7A, 0x0006, (PsoCommandFn)handle_6x7A_enable_stealth_suit_effect},
    {0x7B, 0x0007, (PsoCommandFn)handle_6x7B_disable_stealth_suit_effect},
    {0x81, 0x0007, (PsoCommandFn)handle_6x81_disable_drop_weapon_on_death},
    {0x82, 0x0007, (PsoCommandFn)handle_6x82_enable_drop_weapon_on_death},
    {0x83, 0x0006, (PsoCommandFn)handle_6x83_place_trap},
    {0x87, 0x0007, (PsoCommandFn)handle_6x87_shrink_player},
    {0x88, 0x0007, (PsoCommandFn)handle_6x88_restore_shrunken_player},
    {0x9B, 0x0006, (PsoCommandFn)handle_6x9B_level_up_all_techniques},
    {0x10, 0x0004, (PsoCommandFn)handle_6x10_dragon_boss_actions},
    {0x11, 0x0004, (PsoCommandFn)handle_6x11_dragon_boss_actions},
    {0x12, 0x0004, (PsoCommandFn)handle_6x12_dragon_boss_actions},
    {0x13, 0x0004, (PsoCommandFn)handle_6x13_de_rol_le_boss_actions},
    {0x14, 0x0004, (PsoCommandFn)handle_6x14_de_rol_le_boss_actions_with_target},
    {0x15, 0x0007, (PsoCommandFn)handle_6x15_vol_opt_boss_actions},
    {0x16, 0x0007, (PsoCommandFn)handle_6x16_vol_opt_boss_actions},
    {0x17, 0x0007, (PsoCommandFn)handle_6x17_set_entity_position_and_angle},
    {0x18, 0x0007, (PsoCommandFn)handle_6x18_vol_opt2_boss_actions},
    {0x84, 0x0007, (PsoCommandFn)handle_6x84_vol_opt_boss_actions},
    {0x85, 0x0007, (PsoCommandFn)handle_6x85_vol_opt_phase2_boss_actions},
    {0x19, 0x0004, (PsoCommandFn)handle_6x19_dark_falz_actions},
    {0x9F, 0x0004, (PsoCommandFn)handle_6x9F_gal_gryphon_boss_actions},
    {0xA0, 0x0004, (PsoCommandFn)handle_6xA0_gal_gryphon_boss_actions},
    {0xA3, 0x0004, handle_6xA3_olga_flow_boss_actions},
    {0xA4, 0x0004, handle_6xA4_olga_flow_boss_actions},
    {0xA5, 0x0004, handle_6xA5_olga_flow_boss_actions},
    {0xAD, 0x0004, (PsoCommandFn)handle_6xAD_olga_flow_subordinate_boss_actions},
    {0x67, 0x0007, handle_6x67_trigger_set_event},
    {0x68, 0x0006, (PsoCommandFn)handle_6x68_set_telepipe_state},
    {0x69, 0x0007, (PsoCommandFn)handle_6x69_npc_control},
    {0x6A, 0x0007, (PsoCommandFn)handle_6x6A_set_boss_warp_flags},
    {0x6B, 0x0007, (PsoCommandFn)handle_6x6B_sync_game_state},
    {0x6C, 0x0007, (PsoCommandFn)handle_6x6C_sync_game_state},
    {0x6D, 0x0007, (PsoCommandFn)handle_6x6D_sync_game_state},
    {0x6E, 0x0007, (PsoCommandFn)handle_6x6E_sync_game_state},
    {0x6F, 0x0007, (PsoCommandFn)handle_6x6F_set_quest_flags_v2},
    {0x70, 0x0007, (PsoCommandFn)handle_6x70_sync_player_disp_and_inventory},
    {0x71, 0x0007, (PsoCommandFn)handle_6x71_unblock_game_join},
    {0x72, 0x0007, (PsoCommandFn)handle_6x72_done_loading_into_game},
    {0x06, 0x0007, (PsoCommandFn)handle_6x06_send_guild_card},
    {0x74, 0x0007, (PsoCommandFn)handle_6x74_word_select},
    {0x41, 0x0007, (PsoCommandFn)handle_6x41_move_to_position},
    {0x02, 0x0007, (PsoCommandFn)handle_6x02},
    {0x03, 0x0007, (PsoCommandFn)handle_6x03},
    {0x75, 0x0007, (PsoCommandFn)handle_6x75_update_quest_flag_dc},
    {0x73, 0x0007, (PsoCommandFn)handle_6x73_exit_quest},
    {0x77, 0x0007, (PsoCommandFn)handle_6x77_sync_quest_register},
    {0x78, 0x0007, (PsoCommandFn)handle_6x78},
    {0x79, 0x0007, (PsoCommandFn)handle_6x79_gogo_ball},
    {0x7C, 0x0007, (PsoCommandFn)handle_6x7C_set_challenge_records},
    {0x7D, 0x0007, (PsoCommandFn)handle_6x7D_set_battle_mode_data},
    {0x7E, 0x0007, (PsoCommandFn)handle_6x7E},
    {0x7F, 0x0007, (PsoCommandFn)handle_6x7F_battle_scores},
    {0x80, 0x0004, handle_6x80_trigger_trap},
    {0x86, 0x0006, handle_6x86_hit_destructible_object},
    {0x8A, 0x0002, (PsoCommandFn)handle_6x8A_show_challenge_time_records_window},
    {0x91, 0x0006, (PsoCommandFn)handle_6x91_update_attackable_col_state},
    {0x92, 0x0004, (PsoCommandFn)handle_6x92},
    {0x93, 0x0006, (PsoCommandFn)handle_6x93_set_switch_flag_from_timer},
    {0x64, 0x0006, (PsoCommandFn)handle_6x64},
    {0x8B, 0x0006, (PsoCommandFn)handle_6x8B},
    {0x65, 0x0006, (PsoCommandFn)handle_6x65},
    {0x8C, 0x0006, (PsoCommandFn)handle_6x8C},
    {0x94, 0x0007, handle_6x94_inter_level_warp},
    {0x95, 0x0006, (PsoCommandFn)handle_6x95_set_challenge_time},
    {0x96, 0x0004, (PsoCommandFn)handle_6x96},
    {0x97, 0x0006, (PsoCommandFn)handle_6x97_select_challenge_mode_failure_option},
    {0x9A, 0x0006, (PsoCommandFn)handle_6x9A_update_entity_stat},
    {0x9C, 0x0006, (PsoCommandFn)handle_6x9C_set_enemy_low_game_flags_ultimate},
    {0x9D, 0x0006, (PsoCommandFn)handle_6x9D_set_challenge_dead_flag},
    {0x9E, 0x0007, (PsoCommandFn)handle_6x9E_player_camera_shutter_sound},
    {0xA6, 0x0006, (PsoCommandFn)handle_6xA6_modify_trade_proposal},
    {0xA7, 0x0006, (PsoCommandFn)handle_6xA7},
    {0xA8, 0x0004, (PsoCommandFn)handle_6xA8_gol_dragon_boss_actions},
    {0xA9, 0x0004, (PsoCommandFn)handle_6xA9_barba_ray_boss_actions},
    {0xAA, 0x0004, (PsoCommandFn)handle_6xAA_barba_ray_boss_actions},
    {0xB2, 0x0007, handle_6xB2_play_sound_from_player},
    {0x00, 0x0000, NULL},
};

void handle_6x9E_player_camera_shutter_sound(void) {

}

void handle_6x04_legacy_activate_switch_by_token(void *arg0) {
    ((TLobby *)arg0)->bswap_switch_activate_token();
    TObjDoorKey__sub_8018FAEC(*(u16 *)((s8 *)arg0 + 2), *(u16 *)((s8 *)arg0 + 4));
}

void handle_6x03(void) {  }
void handle_6x02(void) {  }

struct Msg_801E3FA4 {
    u8 a;
    u8 b;
};

extern "C" {
void dispatch_6x_subcommand(Msg_801E3FA4 *arg0) {
    s32 i;
    char buf[0x80];
    s32 key = arg0->a;
    for (i = 0; pso_command_dispatch_table[i].command != 0; i++) {
        if (key == pso_command_dispatch_table[i].command && (pso_command_dispatch_table[i].area_mask & subcommand_area_masks[get_current_floor_area()])) {
            sprintf(buf, "RcvPsoData2 %d %d", arg0->a, arg0->b);
            debug_print(buf);
            pso_command_dispatch_table[i].handle((game_command_header *)arg0);
            return;
        }
    }
}
}

void TPsoDataBuf::recv_pso_data_buf(size_t size) {
    char message[0x80];
    s32 remaining;
    game_command_header *command;
    u8 *cursor;
    cursor = (u8 *)this;
    remaining = size;

    while (remaining > 0) {
        command = (game_command_header *)cursor;
        bswap_client_id_header((G_ClientIDHeader *)command);
        if ((u8)command->size != 0) {
            u32 command_size = (u8)command->size * 4;
            cursor += command_size;
            remaining -= command_size;
            bswap_client_id_header((G_ClientIDHeader *)command);
        } else {
            bswap_client_id_header((G_ClientIDHeader *)command);
            extended_game_command_header *extended = (extended_game_command_header *)cursor;
            bswap_extended_subcommand_header(extended);
            cursor += extended->size;
            remaining -= extended->size;
            bswap_extended_subcommand_header(extended);
        }

        for (s32 i = 0; pso_command_dispatch_table[i].command != 0; i++) {
            if ((u8)command->command == pso_command_dispatch_table[i].command) {
                sprintf(message, "RcvPsoDataBuf %d %d", (u8)command->command, (u8)command->size);
                debug_print(message);
                if (pso_command_dispatch_table[i].area_mask & subcommand_area_masks[get_current_floor_area()]) {
                    pso_command_dispatch_table[i].handle(command);
                }
                break;
            }
        }
    }
}

struct Buf_801E416C {
    u8 pad0[0x2C];
    s16 end;
    s16 pos;
    u8 pad30[0x44];
    u8 data[1];
};

extern "C" {
void dispatch_pso_data_commands(Buf_801E416C *b) {
    char msg[0x80];
    u8 *pkt;
    s32 i;
    while (b->pos < b->end) {
        pkt = &b->data[b->pos];
        for (i = 0; pso_command_dispatch_table[i].command != 0; i++) {
            if (pkt[0] == pso_command_dispatch_table[i].command) {
                sprintf(msg, "RcvPsoData %d %d", pkt[0], pkt[1]);
                debug_print(msg);
                if (pso_command_dispatch_table[i].area_mask & subcommand_area_masks[get_current_floor_area()]) {
                    pso_command_dispatch_table[i].handle((game_command_header *)pkt);
                }
                break;
            }
        }
        if (pkt[1] != 0) {
            b->pos += pkt[1] * 4;
        } else {
            b->pos += *(s32 *)(pkt + 4);
        }
    }
}
}

void TGameProtocol::run_task() {
    TPacket *n;
    for (n = (TPacket *)game_protocol_instance->m_down; n != 0; n = (TPacket *)n->m_next) {
        TLobby__sub_8007EB20("Packet %s %x", n->m_name, n);
        if (n->m_buffer_cleared == 0) {
            dispatch_pso_data_commands((Buf_801E416C *)n);
            n->recv();
        }
        if (n->m_id == frame_slot) {
            TLobby__sub_801A54E8((u8 *)n);
            n->clear_send_buffer();
        }
    }
    frame_slot = (frame_slot + 1) & 3;
}

TGameProtocol::~TGameProtocol() {
    game_protocol_instance = 0;
}

TGameProtocol::TGameProtocol(TObject *parent) : TObject(parent) {
    m_name = TGameProtocol__class_name;
    TGameProtocol__instance = this;
    frame_slot = 0;
    game_protocol_instance = new TObject(this);
}
