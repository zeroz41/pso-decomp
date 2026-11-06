#include "pso/quest/QuestOpcodeTables.h"
#include "pso/unk/TLobby.h"

extern "C" {
void qst_op_va_start();
void qst_op_va_end();
void qst_op_npc_text();
void qst_op_masterkey_on();
void qst_op_masterkey_off();
void qst_op_enable_mainmenu();
void qst_op_start_battlebgm();
void qst_op_end_battlebgm();
void qst_op_set_returnhunter();
void qst_op_set_returncity();
void qst_op_load_pvr();
void qst_op_load_midi();
void qst_op_npc_param();
void qst_op_clear_mainwarp();
void qst_op_start_setevt();
void qst_op_set_bgm();
void qst_op_create_bgmctrl();
void qst_op_pl_add_meseta2();
void qst_op_default_camera_pos1();
void qst_op_set_chat_callback();
void qst_op_clear_ba_rules();
void qst_op_ba_set_tech_disk_mode();
void qst_op_ba_set_weapon_and_armor_mode();
void qst_op_ba_set_forbid_mags();
void qst_op_ba_set_replace_char();
void qst_op_ba_dropwep();
void qst_op_ba_teams();
void qst_op_cmode_stage();
void qst_op_set_cmode_char_template();
void qst_op_set_cmode_difficulty();
void qst_op_set_switch_flag_sync();
void qst_op_clear_switch_flag_sync();
void qst_op_set_area_total();
void qst_op_set_area_title();
void qst_op_unequip_item();
void qst_op_ba_enable_sonar();
void qst_op_clear_score_announce();
void qst_op_set_score_announce();
void qst_op_give_s_rank_weapon();
void qst_op_award_item_name();
void qst_op_award_item_select();
void qst_op_ba_set_max_tech_level();
void qst_op_set_eventflag16();
void qst_op_set_eventflag32();
void qst_op_set_override_enemy_bp_index();
void qst_op_chl_create_retry_menu();
void qst_op_ba_forbid_scape_dolls();
void qst_op_disable_bosswarp_option();
void qst_op_enable_bosswarp_option();
void qst_op_load_serial_number_to_flag_buf();
void qst_op_read1();
void qst_op_disable_retry_menu();
void qst_op_chl_show_dead_player_list();
void qst_op_load_guild_card_file_creation_time_to_flag_buf();
void qst_op_prepare_gba_rom_from_download();
void qst_op_qexit();
void qst_op_fleti_fixed_camera();
void qst_op_get_vector_from_path();
void qst_op_toggle_freeze_enemies();
void qst_op_unfreeze_enemies();
void qst_op_call_image_data();
void qst_op_compute_bezier_curve_point();
void qst_op_particle2();
void qst_op_get_total_deaths();
void qst_op_toggle_freeze_and_hide_equip();
void qst_op_thaw_and_show_equip();
void qst_op_activate_palettex();
void qst_op_enable_palettex();
void qst_op_disable_movement2();
void qst_op_enable_movement2();
void qst_op_get_section_id();
void qst_op_write_counter();
void qst_op_open_pack_select();
void qst_op_add_color_overlay();
void qst_op_send_statistic();
void qst_op_chat_box();
void qst_op_scroll_text();
void qst_op_item_delete_noreturn();
void qst_op_get_item_info();
void qst_op_wrap_item();
void qst_op_wrap_item_with_color();
void qst_op_enable_keyword_detect();
void qst_op_get_recent_symbol_chat();
void qst_op_create_symbol_chat_capture_buffer();
void qst_op_get_item_stackability();
void qst_op_sin();
void qst_op_cos();
void qst_op_tan();
void qst_op_has_ep3_save_file();
void qst_op_olga_flow_is_dead();
void qst_op_initial_floor();
void qst_op_get_guildcard_num();
void qst_op_prepare_statistic();
void qst_op_arg_pusho();
void qst_op_arg_pusha();
void qst_op_arg_pushr();
void qst_op_va_call();
void qst_op_item_create_multi_cm();
void qst_op_delayed_switch_episode();
void qst_op_chat_bubble();
void qst_op_get_chosen_item_id();
void qst_op_prevent_item_select();
void qst_op_prepare_gba_rom_from_disk();
void qst_op_get_players_present();
void qst_op_find_bank_item();
void qst_op_read_counter();
void qst_op_get_coord_player_detect();
void qst_op_get_player_room();
void qst_op_get_player_hp_tp();
void qst_op_gba_write_identifiers();
void qst_op_get_player_level();
void qst_op_get_slot_meseta();
void qst_op_get_guildcard_total();
void qst_op_get_time_played();
void qst_op_add_damage_to();
void qst_op_gba_update_dl_graph();
void qst_op_gba_destroy_dl_graph();
void qst_op_gba_create_dl_graph();
void qst_op_get_palettex_enabled();
void qst_op_get_palettex_activated();
void qst_op_disable_palettex();
void qst_op_restore_palettex();
void qst_op_set_palettex_callback();
void qst_op_get_stackable_item_count();
void qst_op_atan2_int();
void qst_op_fdivi();
void qst_op_fdiv();
void qst_op_fmuli();
void qst_op_fmul();
void qst_op_fsubi();
void qst_op_fsub();
void qst_op_faddi();
void qst_op_fadd();
void qst_op_float2dec();
void qst_op_dec2float();
void qst_op_check_npc_straggle_ex();
void qst_op_set_obj_param_ex();
void qst_op_party_coords_call_ex();
void qst_op_npc_coords_call_ex();
void qst_op_at_coords_talk_ex();
void qst_op_at_coords_call_ex();
void qst_op_unfreeze_everything();
void qst_op_toggle_freeze_everything();
void qst_op_npc_text_id();
void qst_op_get_pressed_buttons();
void qst_op_get_held_buttons();
void qst_op_default_camera_pos2();
void qst_op_fleti_locked_camera();
void qst_op_move_coords_object();
void qst_op_close_chat_bubble();
void qst_op_set_screen_bw();
void qst_op_set_motion_blur();
void qst_op_restore_tp();
void qst_op_restore_hp();
void qst_op_set_slot_zalure();
void qst_op_set_slot_jellen();
void qst_op_set_slot_deband();
void qst_op_set_slot_shifta();
void qst_op_set_slot_confuse();
void qst_op_set_slot_slow();
void qst_op_set_slot_freeze();
void qst_op_set_slot_shock();
void qst_op_set_slot_paralyze();
void qst_op_set_slot_poison();
void qst_op_clear_slot_invincible();
void qst_op_set_slot_invincible();
void qst_op_run_to_coord();
void qst_op_stop_animation();
void qst_op_use_animation();
void qst_op_results_window_visible_multi_cm();
void qst_op_congrats_msg_multi_cm();
void qst_op_start_or_update_gba_joyboot();
void qst_op_get_dl_status();
void qst_op_file_dl_req();
void qst_op_set_episode();
void qst_op_write_flag_buf_to_event_flags2();
void qst_op_chl_set_min_time_online();
void qst_op_check_for_hacking();
void qst_op_someone_has_spoken();
void qst_op_party_has_name();
void qst_op_get_number_of_players2();
void qst_op_get_cmode_prize_rank();
void qst_op_get_ba_record();
void qst_op_is_there_grave_message();
void qst_op_vol_opt_is_dead();
void qst_op_ba_death_tech_level_up();
void qst_op_set_symbol_chat_collision();
void qst_op_set_chat_callback_no_filter();
void qst_op_write_flag_buf_to_event_flags();
void qst_op_is_bosswarp_opt_disabled();
void qst_op_player_recovery();
void qst_op_get_chl_retry_choice();
void qst_op_reset_map();
void qst_op_get_random();
void qst_op_get_eventflag32();
void qst_op_get_eventflag16();
void qst_op_set_enemy_movement_data();
void qst_op_set_enemy_resist_data();
void qst_op_set_enemy_attack_data();
void qst_op_set_enemy_physical_data();
void qst_op_set_cmode_grave_rates();
void qst_op_chl_get_timerecord();
void qst_op_chl_set_timerecord();
void qst_op_get_game_version();
void qst_op_send_mail();
void qst_op_get_player_state();
void qst_op_disable_win_pfx();
void qst_op_enable_win_pfx();
void qst_op_ba_get_score();
void qst_op_ba_get_place();
void qst_op_turn_on_bgm_p2();
void qst_op_turn_off_bgm_p2();
void qst_op_nop_F8EF();
void qst_op_animation_check();
void qst_op_get_pl_name();
void qst_op_set_trap_damage();
void qst_op_get_eventflag();
void qst_op_get_serial_number();
void qst_op_kill_player();
void qst_op_get_guild_card_file_creation_time();
void qst_op_take_slot_meseta();
void qst_op_get_chara_class();
void qst_op_get_gender();
void qst_op_get_pl_job();
void qst_op_disable_techs();
void qst_op_enable_techs();
void qst_op_disable_stealth_suit_effect();
void qst_op_enable_stealth_suit_effect();
void qst_op_set_cmode_rank_override();
void qst_op_dark_falz_is_dead();
void qst_op_ba_clear_trapself();
void qst_op_ba_set_trapself();
void qst_op_award_item_ok();
void qst_op_ba_set_box_drop_area();
void qst_op_item_create_cmode();
void qst_op_check_rank_time();
void qst_op_get_player_proximity();
void qst_op_set_cmode_rank_threshold();
void qst_op_award_item_give();
void qst_op_set_cmode_rank_result();
void qst_op_get_mag_levels();
void qst_op_ba_sonar_count();
void qst_op_set_allow_item_flags();
void qst_op_p_talk_guild_local();
void qst_op_equip_item();
void qst_op_ba_hide_self_traps();
void qst_op_ba_show_self_traps();
void qst_op_unset_ult_map();
void qst_op_set_ult_map();
void qst_op_restore_warp_dest_floor();
void qst_op_override_warp_dest_floor();
void qst_op_set_current_area_number();
void qst_op_ba_set_meseta_drop_mode();
void qst_op_ba_death_lvl_up();
void qst_op_ba_set_time_limit();
void qst_op_ba_set_char_level();
void qst_op_ba_set_lives();
void qst_op_ba_hide_target_reticle();
void qst_op_ba_set_trap_count();
void qst_op_ba_meseta_score();
void qst_op_ba_enemy_death_score();
void qst_op_ba_enemy_kill_score();
void qst_op_ba_player_death_score();
void qst_op_ba_player_kill_score();
void qst_op_ba_enemy_take_damage_score();
void qst_op_ba_enemy_give_damage_score();
void qst_op_ba_player_take_damage_score();
void qst_op_ba_player_give_damage_score();
void qst_op_set_cmode_base_time();
void qst_op_prepare_npc_visual();
void qst_op_enable_npc_visual();
void qst_op_set_shrink_cam2();
void qst_op_set_shrink_cam1();
void qst_op_unshrink();
void qst_op_shrink();
void qst_op_read_switch_flag_on_floor();
void qst_op_read_switch_flag();
void qst_op_reset_kills();
void qst_op_get_num_kills();
void qst_op_go_floor();
void qst_op_release_dragon();
void qst_op_control_dragon();
void qst_op_cmode_check_any_player_dead();
void qst_op_cmode_check_all_players_dead();
void qst_op_exp_multiplication();
void qst_op_nop_F822();
void qst_op_nop_F821();
void qst_op_ba_start();
void qst_op_ba_set_respawn();
void qst_op_ba_set_unused_F817();
void qst_op_ba_set_trap_mode();
void qst_op_ba_set_tool_mode();
void qst_op_ba_initial_floor();
void qst_op_enable_weapon_drop();
void qst_op_disable_weapon_drop();
void qst_op_disable_map();
void qst_op_enable_map();
void qst_op_get_coord_of_player();
void qst_op_get_number_of_players();
void qst_op_get_difficulty_level_v2();
void qst_op_update_switch_flag();
void qst_op_warp_off();
void qst_op_pad_dragon();
void qst_op_delete_bank_item();
void qst_op_leti_fixed_camera();
void qst_op_set_eventflag2();
void qst_op_set_eventflag();
void qst_op_disable_mainmenu();
void qst_op_nop_BC();
void qst_op_clr_qt_exit();
void qst_op_set_qt_exit();
void qst_op_get_difficulty_level_v1();
void qst_op_setevt();
void qst_op_getmtime();
void qst_op_winset_time();
void qst_op_show_timer();
void qst_op_find_inventory_item_ex();
void qst_op_del_obj_param();
void qst_op_clr_qt_cancel();
void qst_op_clr_qt_success();
void qst_op_pcam_param();
void qst_op_clear_mainwarp_all();
void qst_op_npc_text_clear_all();
void qst_op_pl_pkon();
void qst_op_pl_pkoff();
void qst_op_npc_chkwarp();
void qst_op_check_npc_straggle();
void qst_op_unhide_ene();
void qst_op_unhide_obj();
void qst_op_player_effect_nc();
void qst_op_particle_effect_nc();
void qst_op_particle();
void qst_op_cam_pan();
void qst_op_close_msg_qb();
void qst_op_stack_popm();
void qst_op_stack_pushm();
void qst_op_stack_pop();
void qst_op_stack_push();
void qst_op_jmp_off();
void qst_op_jmp_on();
void qst_op_mod();
void qst_op_grev();
void qst_op_rev();
void qst_op_clear();
void qst_op_set();
void qst_op_leto();
void qst_getargs_801F2700(s32 opcode);
void qst_getargs_801F2828(s32 opcode);
void qst_getargs_801F2B0C(s32 opcode);
}
void qst_op_npc_crptalk_id(u8 first);
void qst_op_npc_crptalk(u8 first);
void qst_op_check_for_keyword();
void qst_op_arg_pushs(int a0);
void qst_op_arg_pushw(u16 a0);
void qst_op_arg_pushb(u8 a0);
void qst_op_arg_pushl(int a0);
void qst_op_get_lang_setting();
void qst_op_write4();
void qst_op_write2();
void qst_op_write1();
void qst_op_read4();
void qst_op_read2();
void qst_op_set_shrink_size(s32 player_variable, s32 size_variable);
void qst_op_shift_right(s32 arg0, s32 arg1);
void qst_op_shift_left(s32 arg0, s32 arg1);
void qst_op_map_designate_ex(u32 first);
void qst_op_get_leader_id(u8 reg);
void qst_op_get_client_id(u8 reg);
int qst_op_warp_on(void *p);
void qst_op_sync_register();
void qst_op_clear_quest_board_handler();
void qst_op_set_quest_board_handler();
int qst_op_winend_time(void *p);
void qst_op_map_designate(u32 first);
void qst_op_item_check(u32 first, u32 destination);
void qst_op_item_delete2(u32 src, u32 dst);
void qst_op_item_delete(u32 src, u32 dst);
void qst_op_item_create2(u8 arg0, u8 arg1);
void qst_op_item_create(u8 arg0, u8 arg1);
void qst_op_pl_add_meseta();
int qst_op_clr_qt_failure(void);
void qst_op_set_qt_cancel(u16 arg0);
void qst_op_set_qt_success(u16 arg0);
void qst_op_set_qt_failure(u16 arg0);
void qst_op_clr_floor_handler();
void qst_op_set_floor_handler();
void qst_op_set_mainwarp();
void qst_op_playbgm_epi();
void qst_op_switch_off();
void qst_op_switch_on();
void qst_op_npc_talk_kill();
void qst_op_npc_talk_pl(u8 arg0);
void qst_op_p_talk_guild();
void qst_op_p_return_guild();
void qst_op_nop_A0_debug();
int qst_op_cine_disable(void);
int qst_op_cine_enable(void);
void qst_op_hud_show();
void qst_op_hud_hide();
void qst_op_set_obj_param(u8 arg0, u8 arg1);
void qst_op_col_npcinr(u8 arg0);
void qst_op_npc_coords_call(u8 arg0);
void qst_op_at_coords_talk(u8 arg0);
void qst_op_at_coords_call(u8 arg0);
void qst_op_gettime(u8 arg0);
void qst_op_chk_ene_num(int a0);
void qst_op_if_zone_clear(s32 arg0, s32 arg1);
void qst_op_p_action_enable();
void qst_op_p_action_disable();
void qst_op_pos_pipe(u8 arg0);
void qst_op_create_pipe();
void qst_op_p_setpos();
void qst_op_p_enablewarp();
void qst_op_p_disablewarp();
void qst_op_p_dead();
void qst_op_p_hpstat();
void qst_op_p_move(u8 arg0);
void qst_op_p_look_at();
void qst_op_particle_id(u8 first);
void qst_op_pl_walk(u8 arg0);
void qst_op_p_look();
int qst_op_p_col(void *p);
int qst_op_p_noncol(void *p);
void qst_op_enable_movement1();
void qst_op_disable_movement1();
int qst_op_npc_talk(void *p);
int qst_op_npc_nont(void *p);
void qst_op_npc_kill();
int qst_op_cam_adj(void *p);
void qst_op_nop_86();
void qst_op_nop_85();
int qst_op_cam_zmout(void *p);
int qst_op_cam_zmin(void *p);
int qst_op_cam_quake(void);
void qst_op_npc_play();
void qst_op_npc_stop();
void qst_op_npc_crp_id(u8 first);
void qst_op_npc_crp(u8 first);
void qst_op_npc_crppk(u8 arg0);
void qst_op_npc_crtpk();
void qst_op_npc_crt();
void qst_op_winend();
void qst_op_mesend();
void qst_op_add_msg();
void qst_op_disp_msg_qb();
void qst_op_window_msg();
void qst_op_bgm();
void qst_op_se();
void qst_op_fadeout();
void qst_op_fadein();
void qst_op_list();
void qst_op_message();
void qst_op_switch_call(s32 arg0, u8 arg1, s32 arg2);
void qst_op_switch_jmp(s32 arg0, u8 arg1, s32 arg2);
void qst_op_jmpi_le(s32 arg0, s32 arg1, s32 arg2);
void qst_op_jmp_le(s32 arg0, s32 arg1, s32 arg2);
void qst_op_ujmpi_le(s32 arg0, u32 arg1, s32 arg2);
void qst_op_ujmp_le(s32 arg0, s32 arg1, s32 arg2);
void qst_op_jmpi_ge(s32 arg0, s32 arg1, s32 arg2);
void qst_op_jmp_ge(s32 arg0, s32 arg1, s32 arg2);
void qst_op_ujmpi_ge(s32 arg0, u32 arg1, s32 arg2);
void qst_op_ujmp_ge(s32 arg0, s32 arg1, s32 arg2);
void qst_op_jmpi_lt(s32 arg0, s32 arg1, s32 arg2);
void qst_op_jmp_lt(s32 arg0, s32 arg1, s32 arg2);
void qst_op_ujmpi_lt(s32 arg0, u32 arg1, s32 arg2);
void qst_op_ujmp_lt(s32 arg0, s32 arg1, s32 arg2);
void qst_op_jmpi_gt(s32 arg0, s32 arg1, s32 arg2);
void qst_op_jmp_gt(s32 arg0, s32 arg1, s32 arg2);
void qst_op_ujmpi_gt(s32 arg0, u32 arg1, s32 arg2);
void qst_op_ujmp_gt(s32 arg0, s32 arg1, s32 arg2);
void qst_op_jmpi_ne(s32 arg0, s32 arg1, s32 arg2);
void qst_op_jmp_ne(s32 arg0, s32 arg1, s32 arg2);
void qst_op_jmpi_eq(s32 arg0, s32 arg1, s32 arg2);
void qst_op_jmp_eq(s32 arg0, s32 arg1, s32 arg2);
void qst_op_call(u16 arg0);
void qst_op_modi(s32 arg0, u32 arg1);
void qst_op_jmp(int a0);
void qst_op_xori(s32 arg0, s32 arg1);
void qst_op_xor(s32 arg0, s32 arg1);
void qst_op_ori(s32 arg0, s32 arg1);
void qst_op_or(s32 arg0, s32 arg1);
void qst_op_andi(s32 arg0, s32 arg1);
void qst_op_and(s32 arg0, s32 arg1);
void qst_op_divi(s32 arg0, s32 arg1);
void qst_op_div(s32 arg0, s32 arg1);
void qst_op_muli(s32 arg0, s32 arg1);
void qst_op_mul(s32 arg0, s32 arg1);
void qst_op_subi(s32 arg0, s32 arg1);
void qst_op_sub(s32 arg0, s32 arg1);
void qst_op_addi(int a0, int a1);
void qst_op_add(s32 arg0, s32 arg1);
void qst_op_gget(u16 flag, s32 arg1);
void qst_op_glet(u16 flag, s32 arg1);
void qst_op_gclear(u16 flag);
void qst_op_gset(u16 arg0);
void qst_op_leta(s32 arg0, s32 arg1);
void qst_op_letw(int a0, int a1);
void qst_op_letb(int a0, int a1);
void qst_op_leti(int a0, int a1);
void qst_op_let(s32 arg0, s32 arg1);
void qst_op_thread_stg(u16 arg0);
void qst_op_thread(u16 arg0);
void qst_op_sync();
void qst_op_exit();
void qst_op_ret();
void qst_op_nop();
void qst_getargs_801F26A8(s32 opcode);
void qst_getargs_cstring(s32 opcode);
void qst_getargs_801F27A0(s32 opcode);
void qst_getargs_801F28AC(s32 opcode);
void qst_getargs_801F2910(s32 opcode);
void qst_getargs_801F29CC(s32 opcode);
void qst_getargs_801F2A14(s32 opcode);
void qst_getargs_801F2A5C(s32 opcode);
void qst_getargs_801F2AB4(s32 opcode);
void qst_getargs_801F2B54(s32 opcode);
void qst_getargs_801F2B94(s32 opcode);

extern const char quest_bgm_clear_filename[];
extern const char quest_bgm_miniclear_filename[];
extern "C" {

__declspec(section ".data") const char* qst_bgm_filename_table[2] = {
    quest_bgm_clear_filename, quest_bgm_miniclear_filename
};
}

QuestOpcodeEntry qst_opcode_table[0x300] = {
    { qst_getargs_801F2B94, qst_op_nop },
    { qst_getargs_801F2B94, qst_op_ret },
    { qst_getargs_801F2B94, qst_op_sync },
    { qst_getargs_801F2A14, qst_op_exit },
    { qst_getargs_801F29CC, (void (*)())qst_op_thread },
    { qst_getargs_801F2B94, qst_op_va_start },
    { qst_getargs_801F2B94, qst_op_va_end },
    { qst_getargs_801F29CC, qst_op_va_call },
    { qst_getargs_801F2AB4, (void (*)())qst_op_let },
    { qst_getargs_801F2A5C, (void (*)())qst_op_leti },
    { qst_getargs_801F2AB4, (void (*)())qst_op_letb },
    { TLobby::dispatch_command, (void (*)())qst_op_letw },
    { qst_getargs_801F2AB4, (void (*)())qst_op_leta },
    { TLobby::dispatch_command, qst_op_leto },
    { 0, 0 },
    { 0, 0 },
    { qst_getargs_801F2B0C, qst_op_set },
    { qst_getargs_801F2B0C, qst_op_clear },
    { qst_getargs_801F2B0C, qst_op_rev },
    { qst_getargs_801F2700, (void (*)())qst_op_gset },
    { qst_getargs_801F2700, (void (*)())qst_op_gclear },
    { qst_getargs_801F2700, qst_op_grev },
    { qst_getargs_801F26A8, (void (*)())qst_op_glet },
    { qst_getargs_801F26A8, (void (*)())qst_op_gget },
    { qst_getargs_801F2AB4, (void (*)())qst_op_add },
    { qst_getargs_801F2A5C, (void (*)())qst_op_addi },
    { qst_getargs_801F2AB4, (void (*)())qst_op_sub },
    { qst_getargs_801F2A5C, (void (*)())qst_op_subi },
    { qst_getargs_801F2AB4, (void (*)())qst_op_mul },
    { qst_getargs_801F2A5C, (void (*)())qst_op_muli },
    { qst_getargs_801F2AB4, (void (*)())qst_op_div },
    { qst_getargs_801F2A5C, (void (*)())qst_op_divi },
    { qst_getargs_801F2AB4, (void (*)())qst_op_and },
    { qst_getargs_801F2A5C, (void (*)())qst_op_andi },
    { qst_getargs_801F2AB4, (void (*)())qst_op_or },
    { qst_getargs_801F2A5C, (void (*)())qst_op_ori },
    { qst_getargs_801F2AB4, (void (*)())qst_op_xor },
    { qst_getargs_801F2A5C, (void (*)())qst_op_xori },
    { qst_getargs_801F2AB4, qst_op_mod },
    { qst_getargs_801F2A5C, (void (*)())qst_op_modi },
    { qst_getargs_801F29CC, (void (*)())qst_op_jmp },
    { qst_getargs_801F29CC, (void (*)())qst_op_call },
    { qst_getargs_801F2828, qst_op_jmp_on },
    { qst_getargs_801F2828, qst_op_jmp_off },
    { qst_getargs_801F2910, (void (*)())qst_op_jmp_eq },
    { qst_getargs_801F28AC, (void (*)())qst_op_jmpi_eq },
    { qst_getargs_801F2910, (void (*)())qst_op_jmp_ne },
    { qst_getargs_801F28AC, (void (*)())qst_op_jmpi_ne },
    { qst_getargs_801F2910, (void (*)())qst_op_ujmp_gt },
    { qst_getargs_801F28AC, (void (*)())qst_op_ujmpi_gt },
    { qst_getargs_801F2910, (void (*)())qst_op_jmp_gt },
    { qst_getargs_801F28AC, (void (*)())qst_op_jmpi_gt },
    { qst_getargs_801F2910, (void (*)())qst_op_ujmp_lt },
    { qst_getargs_801F28AC, (void (*)())qst_op_ujmpi_lt },
    { qst_getargs_801F2910, (void (*)())qst_op_jmp_lt },
    { qst_getargs_801F28AC, (void (*)())qst_op_jmpi_lt },
    { qst_getargs_801F2910, (void (*)())qst_op_ujmp_ge },
    { qst_getargs_801F28AC, (void (*)())qst_op_ujmpi_ge },
    { qst_getargs_801F2910, (void (*)())qst_op_jmp_ge },
    { qst_getargs_801F28AC, (void (*)())qst_op_jmpi_ge },
    { qst_getargs_801F2910, (void (*)())qst_op_ujmp_le },
    { qst_getargs_801F28AC, (void (*)())qst_op_ujmpi_le },
    { qst_getargs_801F2910, (void (*)())qst_op_jmp_le },
    { qst_getargs_801F28AC, (void (*)())qst_op_jmpi_le },
    { qst_getargs_801F27A0, (void (*)())qst_op_switch_jmp },
    { qst_getargs_801F27A0, (void (*)())qst_op_switch_call },
    { qst_getargs_801F2B0C, qst_op_stack_push },
    { qst_getargs_801F2B0C, qst_op_stack_pop },
    { qst_getargs_801F2A5C, qst_op_stack_pushm },
    { qst_getargs_801F2A5C, qst_op_stack_popm },
    { 0, 0 },
    { 0, 0 },
    { qst_getargs_801F2B0C, qst_op_arg_pushr },
    { qst_getargs_801F2A14, (void (*)())qst_op_arg_pushl },
    { qst_getargs_801F2B0C, (void (*)())qst_op_arg_pushb },
    { qst_getargs_801F29CC, (void (*)())qst_op_arg_pushw },
    { qst_getargs_801F2B0C, qst_op_arg_pusha },
    { qst_getargs_801F29CC, qst_op_arg_pusho },
    { qst_getargs_cstring, (void (*)())qst_op_arg_pushs },
    { 0, 0 },
    { qst_getargs_801F2B54, qst_op_message },
    { qst_getargs_801F2B54, qst_op_list },
    { qst_getargs_801F2B94, qst_op_fadein },
    { qst_getargs_801F2B94, qst_op_fadeout },
    { qst_getargs_801F2B54, qst_op_se },
    { qst_getargs_801F2B54, qst_op_bgm },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { qst_getargs_801F2B54, qst_op_window_msg },
    { qst_getargs_801F2B54, qst_op_add_msg },
    { qst_getargs_801F2B94, qst_op_mesend },
    { qst_getargs_801F2B0C, (void (*)())qst_op_gettime },
    { qst_getargs_801F2B94, qst_op_winend },
    { 0, 0 },
    { qst_getargs_801F2B54, qst_op_npc_crt },
    { qst_getargs_801F2B54, qst_op_npc_stop },
    { qst_getargs_801F2B54, qst_op_npc_play },
    { qst_getargs_801F2B54, qst_op_npc_kill },
    { qst_getargs_801F2B94, (void (*)())qst_op_npc_nont },
    { qst_getargs_801F2B94, (void (*)())qst_op_npc_talk },
    { qst_getargs_801F2B0C, (void (*)())qst_op_npc_crp },
    { 0, 0 },
    { qst_getargs_801F2B54, qst_op_create_pipe },
    { qst_getargs_801F2B54, qst_op_p_hpstat },
    { qst_getargs_801F2B54, qst_op_p_dead },
    { qst_getargs_801F2B94, qst_op_p_disablewarp },
    { qst_getargs_801F2B94, qst_op_p_enablewarp },
    { qst_getargs_801F2B0C, (void (*)())qst_op_p_move },
    { qst_getargs_801F2B54, qst_op_p_look },
    { 0, 0 },
    { qst_getargs_801F2B94, qst_op_p_action_disable },
    { qst_getargs_801F2B94, qst_op_p_action_enable },
    { qst_getargs_801F2B54, qst_op_disable_movement1 },
    { qst_getargs_801F2B54, qst_op_enable_movement1 },
    { qst_getargs_801F2B94, (void (*)())qst_op_p_noncol },
    { qst_getargs_801F2B94, (void (*)())qst_op_p_col },
    { qst_getargs_801F2B54, qst_op_p_setpos },
    { qst_getargs_801F2B94, qst_op_p_return_guild },
    { qst_getargs_801F2B54, qst_op_p_talk_guild },
    { qst_getargs_801F2B0C, (void (*)())qst_op_npc_talk_pl },
    { qst_getargs_801F2B54, qst_op_npc_talk_kill },
    { qst_getargs_801F2B54, qst_op_npc_crtpk },
    { qst_getargs_801F2B0C, (void (*)())qst_op_npc_crppk },
    { qst_getargs_801F2B0C, (void (*)())qst_op_npc_crptalk },
    { qst_getargs_801F2B54, qst_op_p_look_at },
    { qst_getargs_801F2B0C, (void (*)())qst_op_npc_crp_id },
    { qst_getargs_801F2B94, (void (*)())qst_op_cam_quake },
    { qst_getargs_801F2B94, (void (*)())qst_op_cam_adj },
    { qst_getargs_801F2B94, (void (*)())qst_op_cam_zmin },
    { qst_getargs_801F2B94, (void (*)())qst_op_cam_zmout },
    { qst_getargs_801F2B0C, qst_op_cam_pan },
    { qst_getargs_801F2B94, qst_op_nop_85 },
    { qst_getargs_801F2B94, qst_op_nop_86 },
    { qst_getargs_801F2B0C, (void (*)())qst_op_pos_pipe },
    { qst_getargs_801F2AB4, (void (*)())qst_op_if_zone_clear },
    { qst_getargs_801F2B0C, (void (*)())qst_op_chk_ene_num },
    { qst_getargs_801F2B0C, qst_op_unhide_obj },
    { qst_getargs_801F2B0C, qst_op_unhide_ene },
    { qst_getargs_801F2B0C, (void (*)())qst_op_at_coords_call },
    { qst_getargs_801F2B0C, (void (*)())qst_op_at_coords_talk },
    { qst_getargs_801F2B0C, (void (*)())qst_op_npc_coords_call },
    { qst_getargs_801F2B0C, (void (*)())qst_op_col_npcinr },
    { qst_getargs_801F2B54, qst_op_switch_on },
    { qst_getargs_801F2B54, qst_op_switch_off },
    { qst_getargs_801F2B54, qst_op_playbgm_epi },
    { qst_getargs_801F2B54, qst_op_set_mainwarp },
    { qst_getargs_801F2AB4, (void (*)())qst_op_set_obj_param },
    { qst_getargs_801F2B54, qst_op_set_floor_handler },
    { qst_getargs_801F2B54, qst_op_clr_floor_handler },
    { qst_getargs_801F2B0C, qst_op_check_npc_straggle },
    { qst_getargs_801F2B94, qst_op_hud_hide },
    { qst_getargs_801F2B94, qst_op_hud_show },
    { qst_getargs_801F2B94, (void (*)())qst_op_cine_enable },
    { qst_getargs_801F2B94, (void (*)())qst_op_cine_disable },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { qst_getargs_801F2B54, qst_op_nop_A0_debug },
    { qst_getargs_801F29CC, (void (*)())qst_op_set_qt_failure },
    { qst_getargs_801F29CC, (void (*)())qst_op_set_qt_success },
    { qst_getargs_801F2B94, (void (*)())qst_op_clr_qt_failure },
    { qst_getargs_801F2B94, qst_op_clr_qt_success },
    { qst_getargs_801F29CC, (void (*)())qst_op_set_qt_cancel },
    { qst_getargs_801F2B94, qst_op_clr_qt_cancel },
    { 0, 0 },
    { qst_getargs_801F2B0C, (void (*)())qst_op_pl_walk },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { qst_getargs_801F2B54, qst_op_pl_add_meseta },
    { qst_getargs_801F29CC, (void (*)())qst_op_thread_stg },
    { qst_getargs_801F2B0C, qst_op_del_obj_param },
    { qst_getargs_801F2AB4, (void (*)())qst_op_item_create },
    { qst_getargs_801F2AB4, (void (*)())qst_op_item_create2 },
    { qst_getargs_801F2AB4, (void (*)())qst_op_item_delete },
    { qst_getargs_801F2AB4, (void (*)())qst_op_item_delete2 },
    { qst_getargs_801F2AB4, (void (*)())qst_op_item_check },
    { qst_getargs_801F2B54, qst_op_setevt },
    { qst_getargs_801F2B0C, qst_op_get_difficulty_level_v1 },
    { qst_getargs_801F29CC, qst_op_set_qt_exit },
    { qst_getargs_801F2B94, qst_op_clr_qt_exit },
    { qst_getargs_cstring, qst_op_nop_BC },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { qst_getargs_801F2B0C, qst_op_particle },
    { qst_getargs_801F2B54, qst_op_npc_text },
    { qst_getargs_801F2B94, qst_op_npc_chkwarp },
    { qst_getargs_801F2B94, qst_op_pl_pkoff },
    { qst_getargs_801F2B0C, (void (*)())qst_op_map_designate },
    { qst_getargs_801F2B94, qst_op_masterkey_on },
    { qst_getargs_801F2B94, qst_op_masterkey_off },
    { qst_getargs_801F2B94, qst_op_show_timer },
    { qst_getargs_801F2B94, (void (*)())qst_op_winend_time },
    { qst_getargs_801F2B0C, qst_op_winset_time },
    { qst_getargs_801F2B0C, qst_op_getmtime },
    { qst_getargs_801F2B54, qst_op_set_quest_board_handler },
    { qst_getargs_801F2B54, qst_op_clear_quest_board_handler },
    { qst_getargs_801F2B0C, (void (*)())qst_op_particle_id },
    { qst_getargs_801F2B0C, (void (*)())qst_op_npc_crptalk_id },
    { qst_getargs_801F2B94, qst_op_npc_text_clear_all },
    { qst_getargs_801F2B94, qst_op_pl_pkon },
    { qst_getargs_801F2AB4, qst_op_find_inventory_item_ex },
    { qst_getargs_801F2B94, qst_op_enable_mainmenu },
    { qst_getargs_801F2B94, qst_op_disable_mainmenu },
    { qst_getargs_801F2B94, qst_op_start_battlebgm },
    { qst_getargs_801F2B94, qst_op_end_battlebgm },
    { qst_getargs_801F2B54, qst_op_disp_msg_qb },
    { qst_getargs_801F2B94, qst_op_close_msg_qb },
    { qst_getargs_801F2B54, qst_op_set_eventflag },
    { qst_getargs_801F2B54, qst_op_sync_register },
    { qst_getargs_801F2B94, qst_op_set_returnhunter },
    { qst_getargs_801F2B94, qst_op_set_returncity },
    { qst_getargs_801F2B94, qst_op_load_pvr },
    { qst_getargs_801F2B94, qst_op_load_midi },
    { qst_getargs_801F2B0C, qst_op_delete_bank_item },
    { qst_getargs_801F2B54, qst_op_npc_param },
    { qst_getargs_801F2B94, qst_op_pad_dragon },
    { qst_getargs_801F2B54, qst_op_clear_mainwarp },
    { qst_getargs_801F2B0C, qst_op_pcam_param },
    { qst_getargs_801F2B54, qst_op_start_setevt },
    { qst_getargs_801F2B94, (void (*)())qst_op_warp_on },
    { qst_getargs_801F2B94, qst_op_warp_off },
    { qst_getargs_801F2B0C, (void (*)())qst_op_get_client_id },
    { qst_getargs_801F2B0C, (void (*)())qst_op_get_leader_id },
    { qst_getargs_801F2B54, qst_op_set_eventflag2 },
    { qst_getargs_801F2AB4, qst_op_mod },
    { qst_getargs_801F2A5C, (void (*)())qst_op_modi },
    { qst_getargs_801F2B54, qst_op_set_bgm },
    { qst_getargs_801F2B0C, qst_op_update_switch_flag },
    { qst_getargs_801F2B94, qst_op_create_bgmctrl },
    { qst_getargs_801F2B54, qst_op_pl_add_meseta2 },
    { qst_getargs_801F2B54, qst_op_sync_register },
    { 0, 0 },
    { qst_getargs_801F2B0C, qst_op_leti_fixed_camera },
    { qst_getargs_801F2B94, qst_op_default_camera_pos1 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { qst_getargs_801F2B54, qst_op_set_chat_callback },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { qst_getargs_801F2B0C, qst_op_get_difficulty_level_v2 },
    { qst_getargs_801F2B0C, qst_op_get_number_of_players },
    { qst_getargs_801F2AB4, qst_op_get_coord_of_player },
    { qst_getargs_801F2B94, qst_op_enable_map },
    { qst_getargs_801F2B94, qst_op_disable_map },
    { qst_getargs_801F2B0C, (void (*)())qst_op_map_designate_ex },
    { qst_getargs_801F2B54, qst_op_disable_weapon_drop },
    { qst_getargs_801F2B54, qst_op_enable_weapon_drop },
    { qst_getargs_801F2B54, qst_op_ba_initial_floor },
    { qst_getargs_801F2B94, qst_op_clear_ba_rules },
    { qst_getargs_801F2B54, qst_op_ba_set_tech_disk_mode },
    { qst_getargs_801F2B54, qst_op_ba_set_weapon_and_armor_mode },
    { qst_getargs_801F2B54, qst_op_ba_set_forbid_mags },
    { qst_getargs_801F2B54, qst_op_ba_set_tool_mode },
    { qst_getargs_801F2B54, qst_op_ba_set_trap_mode },
    { qst_getargs_801F2B54, qst_op_ba_set_unused_F817 },
    { qst_getargs_801F2B54, qst_op_ba_set_respawn },
    { qst_getargs_801F2B54, qst_op_ba_set_replace_char },
    { qst_getargs_801F2B54, qst_op_ba_dropwep },
    { qst_getargs_801F2B54, qst_op_ba_teams },
    { qst_getargs_801F2B54, qst_op_ba_start },
    { qst_getargs_801F2B54, qst_op_ba_death_lvl_up },
    { qst_getargs_801F2B54, qst_op_ba_set_meseta_drop_mode },
    { 0, 0 },
    { qst_getargs_801F2B54, qst_op_cmode_stage },
    { qst_getargs_801F2B0C, qst_op_nop_F821 },
    { qst_getargs_801F2B0C, qst_op_nop_F822 },
    { qst_getargs_801F2B54, qst_op_set_cmode_char_template },
    { qst_getargs_801F2B54, qst_op_set_cmode_difficulty },
    { qst_getargs_801F2B0C, qst_op_exp_multiplication },
    { qst_getargs_801F2B0C, qst_op_cmode_check_all_players_dead },
    { qst_getargs_801F2B0C, qst_op_cmode_check_any_player_dead },
    { qst_getargs_801F2AB4, qst_op_go_floor },
    { qst_getargs_801F2AB4, qst_op_get_num_kills },
    { qst_getargs_801F2B0C, qst_op_reset_kills },
    { qst_getargs_801F2B54, qst_op_set_switch_flag_sync },
    { qst_getargs_801F2B54, qst_op_clear_switch_flag_sync },
    { qst_getargs_801F2B0C, qst_op_read_switch_flag },
    { qst_getargs_801F2B0C, qst_op_read_switch_flag_on_floor },
    { 0, 0 },
    { qst_getargs_801F2B0C, qst_op_control_dragon },
    { qst_getargs_801F2B94, qst_op_release_dragon },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { qst_getargs_801F2B0C, qst_op_shrink },
    { qst_getargs_801F2B0C, qst_op_unshrink },
    { qst_getargs_801F2B0C, qst_op_set_shrink_cam1 },
    { qst_getargs_801F2B0C, qst_op_set_shrink_cam2 },
    { qst_getargs_801F2B0C, qst_op_set_cmode_base_time },
    { qst_getargs_801F2B54, qst_op_set_area_total },
    { qst_getargs_801F2B54, qst_op_set_current_area_number },
    { 0, 0 },
    { qst_getargs_801F2B94, qst_op_enable_npc_visual },
    { qst_getargs_801F29CC, qst_op_prepare_npc_visual },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { qst_getargs_801F2B0C, qst_op_ba_player_give_damage_score },
    { qst_getargs_801F2B0C, qst_op_ba_player_take_damage_score },
    { qst_getargs_801F2B0C, qst_op_ba_enemy_give_damage_score },
    { qst_getargs_801F2B0C, qst_op_ba_enemy_take_damage_score },
    { qst_getargs_801F2B0C, qst_op_ba_player_kill_score },
    { qst_getargs_801F2B0C, qst_op_ba_player_death_score },
    { qst_getargs_801F2B0C, qst_op_ba_enemy_kill_score },
    { qst_getargs_801F2B0C, qst_op_ba_enemy_death_score },
    { qst_getargs_801F2B0C, qst_op_ba_meseta_score },
    { qst_getargs_801F2B0C, qst_op_ba_set_trap_count },
    { qst_getargs_801F2B54, qst_op_ba_hide_target_reticle },
    { qst_getargs_801F2B94, qst_op_override_warp_dest_floor },
    { qst_getargs_801F2B94, qst_op_restore_warp_dest_floor },
    { qst_getargs_801F2B94, qst_op_set_ult_map },
    { qst_getargs_801F2B94, qst_op_unset_ult_map },
    { qst_getargs_801F2B54, qst_op_set_area_title },
    { qst_getargs_801F2B94, qst_op_ba_show_self_traps },
    { qst_getargs_801F2B94, qst_op_ba_hide_self_traps },
    { qst_getargs_801F2B0C, qst_op_equip_item },
    { qst_getargs_801F2B54, qst_op_unequip_item },
    { qst_getargs_801F2B94, qst_op_p_talk_guild_local },
    { qst_getargs_801F2B54, qst_op_set_allow_item_flags },
    { qst_getargs_801F2B54, qst_op_ba_enable_sonar },
    { qst_getargs_801F2B54, qst_op_ba_sonar_count },
    { qst_getargs_801F2B94, qst_op_clear_score_announce },
    { qst_getargs_801F2B54, qst_op_set_score_announce },
    { qst_getargs_801F2B54, qst_op_give_s_rank_weapon },
    { qst_getargs_801F2B0C, qst_op_get_mag_levels },
    { qst_getargs_801F2B54, qst_op_set_cmode_rank_result },
    { qst_getargs_801F2B94, qst_op_award_item_name },
    { qst_getargs_801F2B94, qst_op_award_item_select },
    { qst_getargs_801F2B0C, qst_op_award_item_give },
    { qst_getargs_801F2AB4, qst_op_set_cmode_rank_threshold },
    { qst_getargs_801F2AB4, qst_op_check_rank_time },
    { qst_getargs_801F2AB4, qst_op_item_create_cmode },
    { qst_getargs_801F2B0C, qst_op_ba_set_box_drop_area },
    { qst_getargs_801F2B0C, qst_op_award_item_ok },
    { qst_getargs_801F2B94, qst_op_ba_set_trapself },
    { qst_getargs_801F2B94, qst_op_ba_clear_trapself },
    { qst_getargs_801F2B54, qst_op_ba_set_lives },
    { qst_getargs_801F2B54, qst_op_ba_set_max_tech_level },
    { qst_getargs_801F2B54, qst_op_ba_set_char_level },
    { qst_getargs_801F2B54, qst_op_ba_set_time_limit },
    { qst_getargs_801F2B0C, qst_op_dark_falz_is_dead },
    { qst_getargs_801F2B54, qst_op_set_cmode_rank_override },
    { qst_getargs_801F2B0C, qst_op_enable_stealth_suit_effect },
    { qst_getargs_801F2B0C, qst_op_disable_stealth_suit_effect },
    { qst_getargs_801F2B0C, qst_op_enable_techs },
    { qst_getargs_801F2B0C, qst_op_disable_techs },
    { qst_getargs_801F2AB4, qst_op_get_gender },
    { qst_getargs_801F2AB4, qst_op_get_chara_class },
    { qst_getargs_801F2AB4, qst_op_take_slot_meseta },
    { qst_getargs_801F2B0C, qst_op_get_guild_card_file_creation_time },
    { qst_getargs_801F2B0C, qst_op_kill_player },
    { qst_getargs_801F2B0C, qst_op_get_serial_number },
    { qst_getargs_801F2AB4, qst_op_get_eventflag },
    { qst_getargs_801F2B0C, qst_op_set_trap_damage },
    { qst_getargs_801F2B0C, qst_op_get_pl_name },
    { qst_getargs_801F2B0C, qst_op_get_pl_job },
    { qst_getargs_801F2AB4, qst_op_get_player_proximity },
    { qst_getargs_801F2B54, qst_op_set_eventflag16 },
    { qst_getargs_801F2B54, qst_op_set_eventflag32 },
    { qst_getargs_801F2AB4, qst_op_ba_get_place },
    { qst_getargs_801F2AB4, qst_op_ba_get_score },
    { qst_getargs_801F2B94, qst_op_enable_win_pfx },
    { qst_getargs_801F2B94, qst_op_disable_win_pfx },
    { qst_getargs_801F2AB4, qst_op_get_player_state },
    { qst_getargs_801F2B54, qst_op_send_mail },
    { qst_getargs_801F2B0C, qst_op_get_game_version },
    { qst_getargs_801F2B0C, qst_op_chl_set_timerecord },
    { qst_getargs_801F2B0C, qst_op_chl_get_timerecord },
    { qst_getargs_801F2B0C, qst_op_set_cmode_grave_rates },
    { qst_getargs_801F2B94, qst_op_clear_mainwarp_all },
    { qst_getargs_801F2B54, qst_op_set_override_enemy_bp_index },
    { qst_getargs_801F29CC, qst_op_set_enemy_physical_data },
    { qst_getargs_801F29CC, qst_op_set_enemy_attack_data },
    { qst_getargs_801F29CC, qst_op_set_enemy_resist_data },
    { qst_getargs_801F29CC, qst_op_set_enemy_movement_data },
    { qst_getargs_801F2AB4, qst_op_get_eventflag16 },
    { qst_getargs_801F2AB4, qst_op_get_eventflag32 },
    { qst_getargs_801F2AB4, (void (*)())qst_op_shift_left },
    { qst_getargs_801F2AB4, (void (*)())qst_op_shift_right },
    { qst_getargs_801F2AB4, qst_op_get_random },
    { qst_getargs_801F2B94, qst_op_reset_map },
    { qst_getargs_801F2B0C, qst_op_get_chl_retry_choice },
    { qst_getargs_801F2B94, qst_op_chl_create_retry_menu },
    { qst_getargs_801F2B54, qst_op_ba_forbid_scape_dolls },
    { qst_getargs_801F2B0C, qst_op_player_recovery },
    { qst_getargs_801F2B94, qst_op_disable_bosswarp_option },
    { qst_getargs_801F2B94, qst_op_enable_bosswarp_option },
    { qst_getargs_801F2B0C, qst_op_is_bosswarp_opt_disabled },
    { qst_getargs_801F2B94, qst_op_load_serial_number_to_flag_buf },
    { qst_getargs_801F2B0C, qst_op_write_flag_buf_to_event_flags },
    { qst_getargs_801F2B0C, qst_op_set_chat_callback_no_filter },
    { qst_getargs_801F2B0C, qst_op_set_symbol_chat_collision },
    { qst_getargs_801F2AB4, (void (*)())qst_op_set_shrink_size },
    { qst_getargs_801F2B54, qst_op_ba_death_tech_level_up },
    { qst_getargs_801F2B0C, qst_op_vol_opt_is_dead },
    { qst_getargs_801F2B0C, qst_op_is_there_grave_message },
    { qst_getargs_801F2B0C, qst_op_get_ba_record },
    { qst_getargs_801F2B0C, qst_op_get_cmode_prize_rank },
    { qst_getargs_801F2B0C, qst_op_get_number_of_players2 },
    { qst_getargs_801F2B0C, qst_op_party_has_name },
    { qst_getargs_801F2B0C, qst_op_someone_has_spoken },
    { qst_getargs_801F2B54, qst_op_read1 },
    { qst_getargs_801F2B54, qst_op_read2 },
    { qst_getargs_801F2B54, qst_op_read4 },
    { qst_getargs_801F2B54, qst_op_write1 },
    { qst_getargs_801F2B54, qst_op_write2 },
    { qst_getargs_801F2B54, qst_op_write4 },
    { qst_getargs_801F2B0C, qst_op_check_for_hacking },
    { qst_getargs_801F2B0C, qst_op_chl_set_min_time_online },
    { qst_getargs_801F2B94, qst_op_disable_retry_menu },
    { qst_getargs_801F2B94, qst_op_chl_show_dead_player_list },
    { qst_getargs_801F2B94, qst_op_load_guild_card_file_creation_time_to_flag_buf },
    { qst_getargs_801F2B0C, qst_op_write_flag_buf_to_event_flags2 },
    { qst_getargs_801F2A14, qst_op_set_episode },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { qst_getargs_801F2B54, qst_op_file_dl_req },
    { qst_getargs_801F2B0C, qst_op_get_dl_status },
    { qst_getargs_801F2B94, qst_op_prepare_gba_rom_from_download },
    { qst_getargs_801F2B0C, qst_op_start_or_update_gba_joyboot },
    { qst_getargs_801F2B0C, qst_op_congrats_msg_multi_cm },
    { qst_getargs_801F2B0C, qst_op_results_window_visible_multi_cm },
    { qst_getargs_801F2B94, qst_op_qexit },
    { qst_getargs_801F2AB4, qst_op_use_animation },
    { qst_getargs_801F2B0C, qst_op_stop_animation },
    { qst_getargs_801F2AB4, qst_op_run_to_coord },
    { qst_getargs_801F2AB4, qst_op_set_slot_invincible },
    { qst_getargs_801F2B0C, qst_op_clear_slot_invincible },
    { qst_getargs_801F2B0C, qst_op_set_slot_poison },
    { qst_getargs_801F2B0C, qst_op_set_slot_paralyze },
    { qst_getargs_801F2B0C, qst_op_set_slot_shock },
    { qst_getargs_801F2B0C, qst_op_set_slot_freeze },
    { qst_getargs_801F2B0C, qst_op_set_slot_slow },
    { qst_getargs_801F2B0C, qst_op_set_slot_confuse },
    { qst_getargs_801F2B0C, qst_op_set_slot_shifta },
    { qst_getargs_801F2B0C, qst_op_set_slot_deband },
    { qst_getargs_801F2B0C, qst_op_set_slot_jellen },
    { qst_getargs_801F2B0C, qst_op_set_slot_zalure },
    { qst_getargs_801F2B54, qst_op_fleti_fixed_camera },
    { qst_getargs_801F2B54, qst_op_fleti_locked_camera },
    { qst_getargs_801F2B94, qst_op_default_camera_pos2 },
    { qst_getargs_801F2B94, qst_op_set_motion_blur },
    { qst_getargs_801F2B94, qst_op_set_screen_bw },
    { qst_getargs_801F2B54, qst_op_get_vector_from_path },
    { qst_getargs_801F2910, qst_op_npc_text_id },
    { qst_getargs_801F2AB4, qst_op_get_held_buttons },
    { qst_getargs_801F2AB4, qst_op_get_pressed_buttons },
    { qst_getargs_801F2B94, qst_op_toggle_freeze_enemies },
    { qst_getargs_801F2B94, qst_op_unfreeze_enemies },
    { qst_getargs_801F2B94, qst_op_toggle_freeze_everything },
    { qst_getargs_801F2B94, qst_op_unfreeze_everything },
    { qst_getargs_801F2B0C, qst_op_restore_hp },
    { qst_getargs_801F2B0C, qst_op_restore_tp },
    { qst_getargs_801F2B0C, qst_op_close_chat_bubble },
    { qst_getargs_801F2AB4, qst_op_move_coords_object },
    { qst_getargs_801F2AB4, qst_op_at_coords_call_ex },
    { qst_getargs_801F2AB4, qst_op_at_coords_talk_ex },
    { qst_getargs_801F2AB4, qst_op_npc_coords_call_ex },
    { qst_getargs_801F2AB4, qst_op_party_coords_call_ex },
    { qst_getargs_801F2AB4, qst_op_set_obj_param_ex },
    { qst_getargs_801F2AB4, qst_op_check_npc_straggle_ex },
    { qst_getargs_801F2AB4, qst_op_animation_check },
    { qst_getargs_801F2B54, qst_op_call_image_data },
    { qst_getargs_801F2B94, qst_op_nop_F8EF },
    { qst_getargs_801F2B94, qst_op_turn_off_bgm_p2 },
    { qst_getargs_801F2B94, qst_op_turn_on_bgm_p2 },
    { qst_getargs_801F2B54, qst_op_compute_bezier_curve_point },
    { qst_getargs_801F2B54, qst_op_particle2 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { qst_getargs_801F2AB4, qst_op_dec2float },
    { qst_getargs_801F2AB4, qst_op_float2dec },
    { qst_getargs_801F2AB4, (void (*)())qst_op_let },
    { qst_getargs_801F2A5C, (void (*)())qst_op_leti },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { qst_getargs_801F2AB4, qst_op_fadd },
    { qst_getargs_801F2A5C, qst_op_faddi },
    { qst_getargs_801F2AB4, qst_op_fsub },
    { qst_getargs_801F2A5C, qst_op_fsubi },
    { qst_getargs_801F2AB4, qst_op_fmul },
    { qst_getargs_801F2A5C, qst_op_fmuli },
    { qst_getargs_801F2AB4, qst_op_fdiv },
    { qst_getargs_801F2A5C, qst_op_fdivi },
    { qst_getargs_801F2B54, qst_op_get_total_deaths },
    { qst_getargs_801F2AB4, qst_op_get_stackable_item_count },
    { qst_getargs_801F2B94, qst_op_toggle_freeze_and_hide_equip },
    { qst_getargs_801F2B94, qst_op_thaw_and_show_equip },
    { qst_getargs_801F2B54, qst_op_set_palettex_callback },
    { qst_getargs_801F2B54, qst_op_activate_palettex },
    { qst_getargs_801F2B54, qst_op_enable_palettex },
    { qst_getargs_801F2B54, qst_op_restore_palettex },
    { qst_getargs_801F2B54, qst_op_disable_palettex },
    { qst_getargs_801F2B54, qst_op_get_palettex_activated },
    { qst_getargs_801F2B54, qst_op_get_palettex_enabled },
    { qst_getargs_801F2B54, qst_op_disable_movement2 },
    { qst_getargs_801F2B54, qst_op_enable_movement2 },
    { qst_getargs_801F2B0C, qst_op_get_time_played },
    { qst_getargs_801F2B0C, qst_op_get_guildcard_total },
    { qst_getargs_801F2B0C, qst_op_get_slot_meseta },
    { qst_getargs_801F2B54, qst_op_get_player_level },
    { qst_getargs_801F2B54, qst_op_get_section_id },
    { qst_getargs_801F2B54, qst_op_get_player_hp_tp },
    { qst_getargs_801F2B54, qst_op_get_player_room },
    { qst_getargs_801F2AB4, qst_op_get_coord_player_detect },
    { qst_getargs_801F2B54, qst_op_read_counter },
    { qst_getargs_801F2B54, qst_op_write_counter },
    { qst_getargs_801F2AB4, qst_op_find_bank_item },
    { qst_getargs_801F2B0C, qst_op_get_players_present },
    { qst_getargs_801F2B54, qst_op_prepare_gba_rom_from_disk },
    { qst_getargs_801F2B54, qst_op_open_pack_select },
    { qst_getargs_801F2B0C, qst_op_prevent_item_select },
    { qst_getargs_801F2B0C, qst_op_get_chosen_item_id },
    { qst_getargs_801F2B54, qst_op_add_color_overlay },
    { qst_getargs_801F2B54, qst_op_send_statistic },
    { qst_getargs_801F2B54, qst_op_gba_write_identifiers },
    { qst_getargs_801F2B54, qst_op_chat_box },
    { qst_getargs_801F2B54, qst_op_chat_bubble },
    { qst_getargs_801F2B0C, qst_op_delayed_switch_episode },
    { qst_getargs_801F2B0C, qst_op_item_create_multi_cm },
    { qst_getargs_801F2B54, qst_op_scroll_text },
    { qst_getargs_801F2B54, qst_op_gba_create_dl_graph },
    { qst_getargs_801F2B54, qst_op_gba_destroy_dl_graph },
    { qst_getargs_801F2B54, qst_op_gba_update_dl_graph },
    { qst_getargs_801F2B54, qst_op_add_damage_to },
    { qst_getargs_801F2B54, qst_op_item_delete_noreturn },
    { qst_getargs_801F2B54, qst_op_get_item_info },
    { qst_getargs_801F2B54, qst_op_wrap_item },
    { qst_getargs_801F2B54, qst_op_wrap_item_with_color },
    { qst_getargs_801F2B54, qst_op_get_lang_setting },
    { qst_getargs_801F2B54, qst_op_prepare_statistic },
    { qst_getargs_801F2B54, qst_op_enable_keyword_detect },
    { qst_getargs_801F2B54, qst_op_check_for_keyword },
    { qst_getargs_801F2B54, qst_op_get_guildcard_num },
    { qst_getargs_801F2B54, qst_op_get_recent_symbol_chat },
    { qst_getargs_801F2B54, qst_op_create_symbol_chat_capture_buffer },
    { qst_getargs_801F2B54, qst_op_get_item_stackability },
    { qst_getargs_801F2B54, qst_op_initial_floor },
    { qst_getargs_801F2B54, qst_op_sin },
    { qst_getargs_801F2B54, qst_op_cos },
    { qst_getargs_801F2B54, qst_op_tan },
    { qst_getargs_801F2B54, qst_op_atan2_int },
    { qst_getargs_801F2B0C, qst_op_olga_flow_is_dead },
    { qst_getargs_801F2B0C, qst_op_particle_effect_nc },
    { qst_getargs_801F2B0C, qst_op_player_effect_nc },
    { qst_getargs_801F2B54, qst_op_has_ep3_save_file },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
};
