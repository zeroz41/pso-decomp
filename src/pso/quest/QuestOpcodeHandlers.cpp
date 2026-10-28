#include "pso/TMainTask.h"
#include "pso/quest/QuestVm.h"
#include "pso/quest/BattleRules.h"

extern "C" {
void qst_call_stack_push(s32 value);
s32 qst_call_stack_pop(void);
int qst_label_address(int label);
}
#include "pso/quest/QuestOpcodeTables.h"
#include "types.h"
#include "pso/camera/CreationCamera.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/system/date.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/TAdStorySelectGC.h"
#include "pso/TItemMenuCtrl.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemProShield.h"
#include "pso/menu/TQuestBgmCtrl.h"
#include "pso/misc/TCheckRoomSequence.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/misc/TOChatSensor.h"
#include "pso/misc/TOSymbolchatColli.h"
#include "pso/misc/TPlayerBattleCtrl4P.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TTecLuker.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjAreaWarpQuest.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/object/TObjDoor.h"
#include "pso/system/TOChatSensorCapture.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/TChallenge4PResult.h"
#include "pso/object/TObjMotion.h"
#include "pso/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss1Dragon.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/ui/Language.h"

extern "C" {
void qst_op_va_start(void);
void qst_op_va_end(void);
void qst_op_va_call(s32 arg0);
void qst_op_mod(s32 arg0, s32 arg1);
void qst_op_stack_pop(int a0);
void qst_op_stack_pushm(s32 arg0, s32 arg1);
void qst_op_stack_popm(s32 arg0, s32 arg1);
void qst_op_arg_pushr(u8 a0);
void qst_op_arg_pusha(u8 a0);
void qst_op_arg_pusho(u16 a0);
void qst_op_get_difficulty_level_v1(s32 arg0);
void qst_op_set_qt_exit(u16 arg0);
void qst_op_particle(u8 arg0);
void qst_op_npc_text(void);
void qst_op_masterkey_on(void);
void qst_op_masterkey_off(void);
int qst_op_show_timer(void *p);
void qst_op_getmtime(int a0);
int qst_op_npc_text_clear_all(void *p);
void qst_op_enable_mainmenu(void);
void qst_op_start_battlebgm(void);
void qst_op_end_battlebgm(void);
void qst_op_set_returnhunter(void);
void qst_op_set_returncity(void);
void qst_op_load_pvr(void);
void qst_op_load_midi(void);
void qst_op_delete_bank_item(u8 arg0, u8 arg1);
void qst_op_npc_param(void);
void qst_op_clear_mainwarp(void);
void qst_op_pcam_param(u8 arg0);
void qst_op_start_setevt(void);
int qst_op_warp_off(void *p);
void qst_op_set_bgm(void);
void qst_op_update_switch_flag(s32 arg0);
void qst_op_create_bgmctrl(void);
void qst_op_pl_add_meseta2(void);
void qst_op_leti_fixed_camera(u8 arg0);
void qst_op_default_camera_pos1(void);
void qst_op_set_chat_callback(void);
void qst_op_get_difficulty_level_v2(s32 arg0);
void qst_op_get_number_of_players(int a0);
void qst_op_get_coord_of_player(s32 a, s32 b);
void qst_op_disable_weapon_drop(int _w0, int _w1);
void qst_op_enable_weapon_drop(int _w0, int _w1);
void qst_op_clear_ba_rules(void);
void qst_op_ba_set_tech_disk_mode(void);
void qst_op_ba_set_weapon_and_armor_mode(void);
void qst_op_ba_set_forbid_mags(void);
void qst_op_ba_set_replace_char(void);
void qst_op_ba_dropwep(void);
void qst_op_ba_teams(void);
void qst_op_cmode_stage(void);
void qst_op_nop_F821(u8 arg0);
void qst_op_set_cmode_char_template(void);
void qst_op_set_cmode_difficulty(void);
void qst_op_go_floor(s32 a, s32 b);
void qst_op_get_num_kills(s32 arg0, s32 arg1);
void qst_op_reset_kills(s32 arg0);
void qst_op_set_switch_flag_sync(void);
void qst_op_clear_switch_flag_sync(void);
void qst_op_read_switch_flag(s32 arg0);
void qst_op_read_switch_flag_on_floor(s32 arg0);
void qst_op_control_dragon(s32 arg0);
void qst_op_set_area_total(void);
void qst_op_prepare_npc_visual(s32 arg0);
void qst_op_ba_player_take_damage_score(s32 a);
void qst_op_ba_enemy_give_damage_score(s32 a);
void qst_op_ba_enemy_take_damage_score(s32 a);
void qst_op_ba_player_kill_score(s32 a);
void qst_op_ba_player_death_score(s32 a);
int qst_op_override_warp_dest_floor(void *p);
void qst_op_set_area_title(void);
void qst_op_equip_item(u8 i);
void qst_op_unequip_item(void);
void qst_op_p_talk_guild_local(int _w0, int _w1);
void qst_op_ba_enable_sonar(void);
void qst_op_clear_score_announce(void);
void qst_op_set_score_announce(void);
void qst_op_give_s_rank_weapon(void);
void qst_op_get_mag_levels(s32 i);
void qst_op_award_item_name(void);
void qst_op_award_item_select(void);
void qst_op_item_create_cmode(u8 arg0, u8 arg1);
void qst_op_award_item_ok(int a0);
int qst_op_ba_set_trapself(void);
void qst_op_ba_set_max_tech_level(void);
void qst_op_dark_falz_is_dead(s32 arg0);
void qst_op_enable_techs(s32 arg0);
void qst_op_disable_techs(s32 arg0);
void qst_op_get_gender(s32 arg0, s32 arg1);
void qst_op_get_chara_class(s32 arg0, s32 arg1);
void qst_op_take_slot_meseta(s32 arg0, s32 arg1);
void qst_op_get_guild_card_file_creation_time(s32 arg0);
void qst_op_get_serial_number(u8 arg0);
void qst_op_set_trap_damage(s32 i);
void qst_op_get_pl_name(s32 arg0);
void qst_op_get_pl_job(s32 arg0);
void qst_op_get_player_proximity(u8 arg0, u8 arg1);
void qst_op_set_eventflag16(void);
void qst_op_set_eventflag32(void);
void qst_op_ba_get_place(u8 a0, u8 a1);
void qst_op_get_player_state(s32 arg0, s32 arg1);
void qst_op_set_override_enemy_bp_index(void);
void qst_op_set_enemy_movement_data(s32 arg0);
void qst_op_get_eventflag16(u8 a0, u8 a1);
void qst_op_get_eventflag32(u8 a0, u8 a1);
void qst_op_get_random(s32 arg0, s32 arg1);
void qst_op_chl_create_retry_menu(void);
void qst_op_ba_forbid_scape_dolls(void);
void qst_op_disable_bosswarp_option(void);
void qst_op_enable_bosswarp_option(void);
void qst_op_load_serial_number_to_flag_buf(void);
void qst_op_set_chat_callback_no_filter(u8 i);
void qst_op_set_symbol_chat_collision(u8 i);
void qst_op_vol_opt_is_dead(s32 arg0);
void qst_op_get_ba_record(u8 i);
void qst_op_get_number_of_players2(int a0);
void qst_op_party_has_name(s32 arg0);
void qst_op_someone_has_spoken(s32 arg0);
void qst_op_read1(void);
void qst_op_disable_retry_menu(void);
void qst_op_chl_show_dead_player_list(void);
void qst_op_load_guild_card_file_creation_time_to_flag_buf(void);
void qst_op_set_episode(s32 arg0);
void qst_op_get_dl_status(s32 arg0);
void qst_op_prepare_gba_rom_from_download(void);
void qst_op_congrats_msg_multi_cm(u8 arg0);
void qst_op_qexit(void);
void qst_op_stop_animation(s32 arg0);
void qst_op_set_slot_shock(s32 arg0);
void qst_op_set_slot_freeze(s32 arg0);
void qst_op_set_slot_slow(s32 arg0);
void qst_op_set_slot_confuse(s32 arg0);
void qst_op_set_slot_shifta(s32 arg0);
void qst_op_fleti_fixed_camera(void);
int qst_op_set_motion_blur(void);
void qst_op_get_vector_from_path(void);
void qst_op_npc_text_id(u8 a0, u8 a1, void *a2);
void qst_op_get_held_buttons(u8 src, u8 dst);
void qst_op_get_pressed_buttons(u8 a0, u8 a1);
void qst_op_toggle_freeze_enemies(void);
void qst_op_unfreeze_enemies(void);
void qst_op_restore_hp(s32 arg0);
void qst_op_restore_tp(s32 arg0);
void qst_op_close_chat_bubble(s32 arg0);
void qst_op_move_coords_object(s32 i, s32 k);
void qst_op_at_coords_call_ex(u8 i, u8 out);
void qst_op_at_coords_talk_ex(u8 i, u8 out);
void qst_op_party_coords_call_ex(u8 i, u8 out);
void qst_op_set_obj_param_ex(u8 i, u8 out);
void qst_op_check_npc_straggle_ex(u8 i, u8 slot);
void qst_op_animation_check(s32 arg0, s32 arg1);
void qst_op_call_image_data(void);
int qst_op_turn_on_bgm_p2(void *p);
void qst_op_compute_bezier_curve_point(void);
void qst_op_particle2(void);
void qst_op_dec2float(u8 reg, u8 src);
void qst_op_float2dec(s32 arg0, s32 arg1);
void qst_op_fadd(u8 reg, u8 src);
void qst_op_faddi(u8 reg, s32 val);
void qst_op_fsub(u8 reg, u8 src);
void qst_op_fsubi(u8 reg, s32 val);
void qst_op_fmul(u8 reg, u8 src);
void qst_op_fmuli(u8 reg, s32 val);
void qst_op_fdiv(u8 reg, u8 src);
void qst_op_fdivi(u8 reg, s32 val);
void qst_op_get_total_deaths(void);
void qst_op_get_stackable_item_count(s32 i, s32 dst);
void qst_op_toggle_freeze_and_hide_equip(void);
void qst_op_thaw_and_show_equip(void);
void qst_op_activate_palettex(void);
void qst_op_enable_palettex(void);
void qst_op_disable_movement2(void);
void qst_op_enable_movement2(void);
void qst_op_get_guildcard_total(int a0);
void qst_op_get_section_id(void);
void qst_op_write_counter(void);
void qst_op_get_players_present(u8 out);
void qst_op_open_pack_select(void);
void qst_op_prevent_item_select(s32 arg0);
void qst_op_get_chosen_item_id(int a0);
void qst_op_add_color_overlay(void);
void qst_op_send_statistic(void);
void qst_op_chat_box(void);
void qst_op_delayed_switch_episode(s32 arg0);
void qst_op_scroll_text(void);
void qst_op_item_delete_noreturn(void);
void qst_op_get_item_info(void);
void qst_op_wrap_item(void);
void qst_op_wrap_item_with_color(void);
void qst_op_enable_keyword_detect(void);
void qst_op_get_recent_symbol_chat(void);
void qst_op_create_symbol_chat_capture_buffer(void);
void qst_op_get_item_stackability(void);
void qst_op_sin(void);
void qst_op_cos(void);
void qst_op_tan(void);
void qst_op_player_effect_nc(u8 arg0);
void qst_op_has_ep3_save_file(void);
}

struct RecoveredGlobal_8000F7FC_lbl_80515F48 {
    s32 value;
    u8 remaining[0x24];
};

struct Cmd_801E6604 {
    const char *name;
    void (*fn)(void);
};

struct CmdTable_801E6604 {
    Cmd_801E6604 e[12];
};

extern "C" {
namespace pf2_p0 { extern "C" { s32 append_string(void *); } }
#define append_string pf2_p0::append_string
namespace pf2_p0 { extern "C" { extern RecoveredGlobal_8000F7FC_lbl_80515F48 quest_player_class_name_buffer; } }
#define quest_player_class_name_buffer pf2_p0::quest_player_class_name_buffer
namespace pf2_p0 { extern "C" { extern RecoveredGlobal_8000F7FC_lbl_80515F48 quest_player_name_buffer; } }
#define quest_player_name_buffer pf2_p0::quest_player_name_buffer
void TLobby__sub_801E6840(void);
int sprintf(char *, const char *, ...);
extern char lbl_80449C74[];
namespace pf2_p0 { extern "C" { s32 TLobby__sub_801E6BB8(); } }
#define TLobby__sub_801E6BB8 pf2_p0::TLobby__sub_801E6BB8
namespace pf2_p0 { extern "C" { s8 read_byte_advance__6TLobbyFv(); } }
#define read_byte_advance__6TLobbyFv pf2_p0::read_byte_advance__6TLobbyFv
void TLobby__sub_801E6C2C(s8);
namespace pf2_p0 { extern "C" { void TLobby__sub_801E6C40(); } }
#define TLobby__sub_801E6C40 pf2_p0::TLobby__sub_801E6C40
s32 expand_message_substitutions(s32 arg0, s32 arg1);
}
s32 parse_f_index(s32 a0);
extern "C" {
namespace pf2_p0 { extern "C" { s32 parse_r_index(char *); } }
#define parse_r_index pf2_p0::parse_r_index
void append_float_value__6TLobbyFi(s32);
void append_int_param__6TLobbyFi(s32);
namespace pf2_p0 { extern "C" { int strcmp(const char *, const char *); } }
#define strcmp pf2_p0::strcmp
extern CmdTable_801E6604 message_substitution_handlers;
namespace pf2_p0 { extern "C" { char *get_unit_list__6TLobbyFv(); } }
#define get_unit_list__6TLobbyFv pf2_p0::get_unit_list__6TLobbyFv
extern char lbl_80449C64[];
extern s32 TLobby__data_805DC4A0;
namespace pf2_p0 { extern "C" { char *TLobby__sub_80070ACC(); } }
#define TLobby__sub_80070ACC pf2_p0::TLobby__sub_80070ACC
void TLobby__sub_801E677C(void);
int sscanf(s32, s32 *, ...);
extern s32 lbl_80449C7C[];
s32 dispatch_chat_message_to_children__12TOChatSensorFl();
namespace pf2_p0 { extern "C" { u32 get_character_save_record(int); } }
#define get_character_save_record pf2_p0::get_character_save_record

extern s32 local_client_id;

void TLobby::capture_chat_sensor() {
    s32 message = (s32)this;
    dispatch_chat_message_to_children__12TOChatSensorFl();
    TOChatSensorCapture::capture_message((u16)((u16) local_client_id), (const char *)message);
}

extern s32 lbl_80449C6C[];

s32 expand_message_substitutions(s32 arg0, s32 arg1) {
    TLobby__sub_801E6C40();
    while (TLobby__sub_801E6BB8() == 0) {
        s8 c = read_byte_advance__6TLobbyFv();
        switch (c) {
        case 0x3C:
            TLobby::parse_message_tag();
            break;
        case 0x3E:
            while (1) {
            }
        case 0x3D:
        default:
            TLobby__sub_801E6C2C(c);
            break;
        }
    }
    TLobby__sub_801E6C2C(0);
    return arg1;
}

void TLobby::parse_message_tag() {
    char buf[64];
    CmdTable_801E6604 tbl = message_substitution_handlers;
    u32 i;
    s32 idx;
    s8 c;
    for (i = 0; i < 0x40 && TLobby__sub_801E6BB8() == 0; i++) {
        c = read_byte_advance__6TLobbyFv();
        switch (c) {
        case 0x3E:
            buf[i] = 0;
            if ((idx = parse_r_index(buf)) != -1) {
                append_int_param__6TLobbyFi(idx);
                return;
            }
            if ((idx = parse_f_index((s32)buf)) != -1) {
                append_float_value__6TLobbyFi(idx);
                return;
            }
            if ((idx = TLobby::parse_color_code((char *)(buf))) != -1) {
                TLobby::append_color_code(idx);
                return;
            }
            for (i = 0; i < 12; i++) {
                if (strcmp(tbl.e[i].name, buf) == 0) {
                    tbl.e[i].fn();
                }
            }
            return;
        default:
            buf[i] = c;
            break;
        }
    }
}

void TLobby::append_unit_list_name() {
    char *s;
    s = get_unit_list__6TLobbyFv();
    if (strcmp(s, (const char *)&TLobby__data_805DC4A0) == 0) {
        append_string(lbl_80449C64);
        return;
    }
    append_string(s);
}

void TLobby__sub_801E677C(void) {
    char *s;
    s = TLobby__sub_80070ACC();
    if (strcmp(s, (const char *)&TLobby__data_805DC4A0) == 0) {
        append_string(lbl_80449C64);
        return;
    }
    append_string(s);
}

void TLobby::append_card_window_text() {
    u32 character_save_record;

    character_save_record = get_character_save_record(0xFFFF);
    if (character_save_record != 0U) {
        append_string((void *) (character_save_record + 0x2254));
        return;
    }
    append_string(lbl_80449C6C);
}

extern s32 lbl_805DC4A4;

typedef char RecoveredGlobal_8000F7FC_lbl_80515F48_size[sizeof(RecoveredGlobal_8000F7FC_lbl_80515F48) == 0x28 ? 1 : -1];
void TLobby::append_default_string() {
    append_string((void *)((s32 *)(&quest_player_class_name_buffer.value)));
}

void TLobby__sub_801E6840(void) {
    append_string((void *)((s32 *)(&quest_player_name_buffer.value)));
}

void TLobby::append_color_code(s32 arg0) {
    char buf[64];
    sprintf(buf, lbl_80449C74, arg0);
    append_string(buf);
}

s32 TLobby::parse_color_code(char *s) {
    s32 v;
    v = -1;
    sscanf((s32)s, lbl_80449C7C, &v);
    if ((v <= 7) && (v >= 0)) {
        return v;
    }
    return -1;
}
}

s32 parse_f_index(s32 a0) {
    s32 sp8;

    sp8 = -1;
    sscanf(a0, &lbl_805DC4A4, &sp8);
    if ((sp8 < 0x100) && (sp8 >= 0)) {
        return sp8;
    }
    return -1;
}

#undef TLobby__sub_80070ACC
#undef TLobby__sub_801E6BB8
#undef TLobby__sub_801E6C40
#undef append_string
#undef get_character_save_record
#undef get_unit_list__6TLobbyFv
#undef parse_r_index
#undef read_byte_advance__6TLobbyFv
#undef strcmp
#undef quest_player_name_buffer
#undef quest_player_class_name_buffer

extern "C" {
void append_string(s32 arg0);
extern char lbl_805DC4B4[4];
void append_int_param__6TLobbyFi(s32 arg0);
extern char lbl_80449C90[];
void TLobby__sub_801E6AE0(void);
extern char lbl_805DC4B0[4];
void append_float_value__6TLobbyFi(s32 arg0);
s32 TObjItemOKWindow__sub_801F3268();
s32 *fn_801F4C98(void);
extern char lbl_80449C88[];
void TLobby__sub_801E6A04(void);
namespace pf2_p1 { extern "C" { s32 get_class_type_name__6TLobbyFl(s32); } }
#define get_class_type_name__6TLobbyFl pf2_p1::get_class_type_name__6TLobbyFl
u32 get_player_by_client_id(s32);
}
extern char lbl_80449C9C[];
void append_hero_class_name(void);
extern char lbl_80449CA8[];
void append_hero_name(void);
extern "C" {
s32 is_split_screen();
char *TLobby__sub_800713C8();
extern char lbl_805DC4AC[3];
void TLobby__sub_801E6998(void);
u8 TLobby__sub_801E6BB8(void);
s32 parse_r_index(s32 arg0);
u8 read_byte_advance__6TLobbyFv(void);
s32 strcpy(s32, s32);
s32 strlen();

extern s32 lbl_805DC4A8;

s32 parse_r_index(s32 arg0) {
    s32 sp8;

    sp8 = -1;
    sscanf(arg0, &lbl_805DC4A8, &sp8);
    if ((sp8 < 0x100) && (sp8 >= 0)) {
        return sp8;
    }
    return -1;
}

extern u8 *TLobby__quest_script_read_ptr;

void TLobby__sub_801E6998(void) {
    char buf[0x40];
    if (is_split_screen() == 1) {
        sprintf(buf, lbl_805DC4AC, get_split_screen_character_name());
    } else {
        sprintf(buf, lbl_805DC4AC, TLobby__sub_800713C8());
    }
    buf[0x3F] = 0;
    append_string((s32)buf);
}

void TLobby__sub_801E6A04(void) {
    char buf[64];
    s32 t = (s32)fn_801F4C98();
    sprintf(buf, lbl_80449C88, TObjItemOKWindow__sub_801F3268(), t);
    buf[63] = 0;
    append_string((s32)buf);
}

void append_float_value__6TLobbyFi(s32 arg0) {
    char buf[64];
    sprintf(buf, lbl_805DC4B0, ((f32 *)qst_registers)[arg0]);
    append_string((s32)buf);
}

void append_int_param__6TLobbyFi(s32 arg0) {
    char buf[64];
    sprintf(buf, lbl_805DC4B4, qst_registers[arg0]);
    append_string((s32)buf);
}

void TLobby__sub_801E6AE0(void) {
    char buf[64];
    sprintf(buf, lbl_80449C90, 1, 12);
    append_string((s32)buf);
}
}

void append_hero_class_name(void) {
    TObjPlayer *c = (TObjPlayer *)get_player_by_client_id(local_client_id);
    if (c != NULL) {
        append_string(get_class_type_name__6TLobbyFl(c->class_flags));
    } else {
        append_string((s32)lbl_80449C9C);
    }
}

void append_hero_name(void) {
    u8 *player;
    player = (u8 *)(get_player_by_client_id(local_client_id));
    if (player != NULL) {
        append_string((s32)((TObjPlayer *)player)->get_name());
    } else {
        append_string((s32)lbl_80449CA8);
    }
}
extern "C" {

u8 TLobby__sub_801E6BB8(void) {
    return (u8) ((s8) *TLobby__quest_script_read_ptr == 0);
}

u8 read_byte_advance__6TLobbyFv(void) {
    u8 *temp_r3;

    temp_r3 = TLobby__quest_script_read_ptr;
    TLobby__quest_script_read_ptr = temp_r3 + 1;
    return *temp_r3;
}

extern s32 quest_string_append_cursor;

void append_string(s32 arg0) {
    s32 temp_r31;

    temp_r31 = strlen();
    strcpy(quest_string_append_cursor, arg0);
    quest_string_append_cursor += temp_r31;
}

#undef get_class_type_name__6TLobbyFl

void TLobby__sub_801E6C2C(s8 arg0);

namespace pf2_p2 { extern "C" { extern s8 *quest_string_append_cursor; } }
#define quest_string_append_cursor pf2_p2::quest_string_append_cursor

void TLobby__sub_801E6C2C(s8 arg0) {
    s8 *temp_r4;

    temp_r4 = quest_string_append_cursor;
    quest_string_append_cursor = temp_r4 + 1;
    *temp_r4 = arg0;
}
}

#undef quest_string_append_cursor

struct Tbl_801E6CA4 { u32 w[18]; };

extern "C" {
void qst_op_olga_flow_is_dead(s32 arg0);
s32 TObjPlayer__sub_801C1AC8();
void qst_op_get_guildcard_num(void);
void TLobby__sub_80141038(u8 *arg0, s32 arg1, s32 arg2);
extern Tbl_801E6CA4 lobby_index_identity_table_b;
extern u8 lbl_80515BA0[];
void qst_op_initial_floor(void);
void *memcpy(void *, const void *, u32);
}
void qst_op_check_for_keyword(void);
extern "C" {
void TLobby__sub_801E6C40(int a0, int a1);
void create_singleton__6TLobbyFPv(void *arg0);

namespace pf2_p3 { extern "C" { extern int TLobby__quest_script_read_ptr; } }
#define TLobby__quest_script_read_ptr pf2_p3::TLobby__quest_script_read_ptr
void TLobby__sub_801E6C40(int a0, int a1) { TLobby__quest_script_read_ptr = a0; quest_string_append_cursor = a1; }

void qst_op_olga_flow_is_dead(s32 arg0) {
    if (TBoss6PlotFalz::is_phase_reached() != 0) {
        qst_registers[(u8)arg0] = 1;
        return;
    }
    qst_registers[(u8)arg0] = 0;
}

void qst_op_initial_floor(void) {
    Tbl_801E6CA4 t = lobby_index_identity_table_b;
    if (qst_args[0] <= 0x11U) {
        TLobby__sub_80141038(lbl_80515BA0, t.w[qst_args[0]], 0);
    }
}

void qst_op_get_item_stackability() {
    u8 temp_r31;
    temp_r31 = (u8) qst_args[1];
    if (find_item_by_id((int) (qst_args[0])) != 0U) {
        if (TObjPlayer__sub_801C1AC8() != 0) {
            qst_registers[(u8)temp_r31] = 1;
            return;
        }
        qst_registers[(u8)temp_r31] = 0;
        return;
    }
    qst_registers[(u8)temp_r31] = -1;
}

void qst_op_create_symbol_chat_capture_buffer() { create_singleton__6TLobbyFPv((void *)tl_01); }

void qst_op_get_recent_symbol_chat() {
    u8 buf[0x3C];
    u8 idx;
    idx = (u8) qst_args[1];
    TLobby::send_slot_entity_or_local((u16) qst_args[0], (s32) buf);
    memcpy(&qst_registers[(u8)idx], buf, 0x3C);
}

void qst_op_get_guildcard_num(void) {
    u8 temp_r31;
    u8 *player;
    temp_r31 = (u8) qst_args[1];
    player = (u8 *)(get_player_by_client_id((s32) (u16) qst_args[0]));
    if (player != NULL) {
        qst_registers[(u8)temp_r31] = *(s32 *)((s8 *)player + 0xDB0);
        return;
    }
    qst_registers[(u8)temp_r31] = -1;
}
}
void qst_op_check_for_keyword(void) {
    u8 idx;
    idx = (u8) qst_args[0];
    if (TOChatSensorCapture::check_keyword((u16) qst_args[1], (const char *) qst_args[2]) != 0) {
        qst_registers[(u8)idx] = 1;
        return;
    }
    qst_registers[(u8)idx] = 0;
}

#undef TLobby__quest_script_read_ptr

extern s16 TLobby__quest_state_word_170;
extern s16 TLobby__quest_state_word_172;
extern s16 TLobby__data_805D5ECC;
extern "C" {
void qst_op_prepare_statistic(void);
s32 fn_801D9FA0(int, int, int, int, void *);
}
extern s32 TLobby__protocol_instance;
void qst_op_arg_pushw(u16 a0);
void qst_op_arg_pushb(u8 a0);
void qst_op_arg_pushs(int a0);
extern "C" {

void qst_op_enable_keyword_detect() { TOChatSensorCapture::create_instance((void*)tl_01); }

void qst_op_prepare_statistic(void) {
    TLobby__data_805D5ECC = (s16) qst_args[0];
    TLobby__quest_state_word_170 = (s16) qst_args[1];
    TLobby__quest_state_word_172 = (s16) qst_args[2];
}

void qst_op_send_statistic() {
    fn_801D9FA0(TLobby__protocol_instance, (int) ((*(u16 *)&TLobby__data_805D5ECC)), (int) ((*(u16 *)&TLobby__quest_state_word_170)), (int) ((*(u16 *)&TLobby__quest_state_word_172)), (void *) qst_args);
}
}

void qst_op_arg_pushs(int a0) { int old = qst_arg_count; qst_arg_count = old + 1; qst_args[old] = a0; }
extern "C" {

void qst_op_arg_pusho(u16 a0) {
    qst_args[qst_arg_count++] = (s32)&qst_function_table[a0];
}

void qst_op_arg_pusha(u8 a0) {
    qst_args[qst_arg_count++] = (int)(&qst_registers[a0]);
}
}

void qst_op_arg_pushw(u16 a0) {
    qst_args[qst_arg_count++] = a0;
}

void qst_op_arg_pushb(u8 a0) {
    qst_args[qst_arg_count++] = a0;
}

void qst_op_arg_pushl(int a0)
{
  unsigned long new_var3;
  int new_var;
  int *new_var2;
  new_var = qst_arg_count;
  new_var2 = &a0;
  new_var3 = *new_var2;
  qst_arg_count = qst_arg_count + 0x1;
  qst_args[new_var] = new_var3;
}
extern "C" {
void qst_op_arg_pushr(u8 a0) {
    qst_args[qst_arg_count++] = qst_registers[a0];
}

void qst_op_va_call(s32 arg0) {
  int new_var;
  (*(s32 *)&qst_arg_count) = 0;
  qst_registers[1] = qst_args[0];
  qst_registers[2] = qst_args[1];
  qst_registers[3] = qst_args[2];
  qst_registers[4] = qst_args[3];
  qst_registers[5] = qst_args[4];
  qst_registers[6] = qst_args[5];
  qst_registers[7] = qst_args[6];
  qst_call_stack_push(qst_pc);
  qst_pc = qst_function_table[(u16)arg0];
}
}


extern "C" {
s16 get_actor_hp(u8 *);
}
extern const f32 lbl_805DC4C4;
extern const f32 lbl_805DC4D0;
void qst_op_p_hpstat(void);
extern "C" {
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);

struct ItemData_801E72B4 {
    u8 data1[12];
    u32 id;
    u8 data2[4];
};

struct Win_801E78D4 { u8 pad[0x2314]; s32 t[16]; };

struct Card_801E7D7C {
    u8 pad[0x24C];
    s32 v;
};

struct ItemData_801E7810 {
    u8 data1[12];
    u32 id;
    u8 data2[4];
};

struct RecoveredGlobal_801F196C_lbl_804499A8 {
    s32 value;
    u8 remaining[0x70];
};

struct ItemData_801E8000 {
    u8 b0, b1, b2, b3, b4, b5, b6;
    s8 b7;
    u8 b8;
    s8 b9;
    u8 b10;
    s8 b11;
    u32 id;
    u32 extra;
};

typedef char RecoveredGlobal_8000F7FC_lbl_80515F48_size[sizeof(RecoveredGlobal_8000F7FC_lbl_80515F48) == 0x28 ? 1 : -1];

typedef char RecoveredGlobal_801F196C_lbl_804499A8_size[sizeof(RecoveredGlobal_801F196C_lbl_804499A8) == 0x74 ? 1 : -1];

union U_801E8784 { s32 i; f32 f; };

union U_801E871C { s32 i; f32 f; };

union U_801E8750 { s32 i; f32 f; };

union U_801E87EC { s32 i; f32 f; };

union U_801E8854 { s32 i; f32 f; };

union U_801E87B8 { s32 i; f32 f; };

struct E_801E93B4 { u8 pad[0x20]; s32 f20; u8 pad24[4]; s32 f28; u8 pad2c[0x24]; };

union U_801E8888 { s32 i; f32 f; };

union U_801E8820 { s32 i; f32 f; };

struct Vec_801E9400 { f32 x, y, z; };

struct Vec_801E945C { f32 x, y, z; };

struct Tbl_801E9AF8 { u8 bytes[0x14]; };

struct Glob_801E915C {
    s32 count;
    f32 f4;
    f32 f8;
    s32 fC;
    s32 out;
    u32 id;
};

struct Vec3_801E915C { f32 x, y, z; };

struct Glob_801E9274 {
    s32 count;
    f32 f4;
    f32 f8;
    s32 fC;
    s32 out;
    u32 id;
};

struct Vec3_801E9274 { f32 x, y, z; };

struct ByteBlock_30 { u8 bytes[0x30]; };

struct ByteBlock_20 { u8 bytes[0x20]; };

struct ByteBlock_24 { u8 bytes[0x24]; };

struct Ctx_801EA5FC { u8 pad[0x10]; u8 buf[0xFD]; };

struct Ctx_801EAA34 { u8 pad[0x10]; u8 buf[0xFD]; };

struct Ctx_801EAAB4 { u8 pad[0x10]; u8 buf[0xFF]; };

struct Card_801EA0F0 {
    u8 pad[0x21A8];
    u16 stats[7];
};

struct Spawn_801EA508 {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    s32 f18;
    s32 f1c;
    u8 pad20[4];
    f32 a;
    f32 b;
    u8 pad2c[4];
    s32 c;
    u8 pad34[0xC];
};

struct Spawn_801EACD8 {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    s32 f18;
    s32 f1c;
    u8 pad20[4];
    f32 a;
    f32 b;
    u8 pad2c[4];
    s32 c;
    u8 pad34[0xC];
};

struct VBase_18_801EB10C { char pad[0x18]; };

struct Card_801EB10C : VBase_18_801EB10C {
    virtual void m0(s32);
};

struct Tag_801EB10C {
    u8 pad0[8];
    s32 id;
    char name[0x10];
    u8 pad1c[4];
    char text[0x200];
};

struct VBase_18_801EBD40 { char pad[0x18]; };

struct Card_801EBD40 : VBase_18_801EBD40 {
    virtual void m0(s32);
};

struct Item_801EBF30 {
    u8 data[12];
    s32 id;
    u32 f10;
};

struct Vec_801ECFDC {
    f32 x, y, z;
};

struct Vec_801ED0CC {
    f32 x, y, z;
};

struct Spawn_801EA388 {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0xC];
    f32 a;
    u8 pad28[8];
    s32 c;
    s32 d;
    s32 e;
    u8 pad3c[4];
};

struct Spawn_801EA508;

struct RecoveredGlobal_801EB6B8_lbl_80512350 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801EB73C_lbl_80512340 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801EC90C_lbl_80449AFC {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_801ECF84_lbl_8050D3E0 {
    s32 value;
    u8 remaining[0x4C];
};

struct E_801EB484 { s32 a; s32 b; };

struct Pkt_801ED300 {
    u8 cmd;
    u8 size;
    u16 a;
    u16 b;
    u16 pad;
    u16 c;
    u8 d;
    u8 e;
};

struct Pkt_801ED360 {
    u8 cmd;
    u8 size;
    u16 a;
    u16 b;
    u16 pad;
    u16 c;
    u8 d;
    u8 e;
};

struct E_801EB4C4 { s16 a; s16 b; s32 c; };

struct Ctx_801EB508 { u8 pad[0x10]; u8 buf[0xFD]; };

struct Ctx_801EB658 { u8 pad[0x10]; u8 buf[0xFF]; };

struct Item_801EC720 { s8 a; s8 b; s8 c; u8 pad[0x1D]; };

typedef char RecoveredGlobal_801EB6B8_lbl_80512350_size[sizeof(RecoveredGlobal_801EB6B8_lbl_80512350) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_801EB73C_lbl_80512340_size[sizeof(RecoveredGlobal_801EB73C_lbl_80512340) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_801EC90C_lbl_80449AFC_size[sizeof(RecoveredGlobal_801EC90C_lbl_80449AFC) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_801ECF84_lbl_8050D3E0_size[sizeof(RecoveredGlobal_801ECF84_lbl_8050D3E0) == 0x50 ? 1 : -1];

struct Item_801ED7BC {
    u8 data[12];
    s32 id;
    u32 f10;
};

struct RecoveredGlobal_801EDA70_lbl_80449AC8 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_801EDB4C_lbl_80449AAC {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_801EDBDC_lbl_80449A94 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801EDC24_lbl_80449A88 {
    s32 value;
    u8 remaining[0x8];
};

struct Tbl_801EDC98 { u32 w[18]; };

typedef char RecoveredGlobal_801EDA70_lbl_80449AC8_size[sizeof(RecoveredGlobal_801EDA70_lbl_80449AC8) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_801EDB4C_lbl_80449AAC_size[sizeof(RecoveredGlobal_801EDB4C_lbl_80449AAC) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_801EDBDC_lbl_80449A94_size[sizeof(RecoveredGlobal_801EDBDC_lbl_80449A94) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_801EDC24_lbl_80449A88_size[sizeof(RecoveredGlobal_801EDC24_lbl_80449A88) == 0xC ? 1 : -1];

struct Pkt_801EE048 {
    u8 cmd;
    u8 size;
    u16 a;
    s32 b;
    s32 c;
    s32 d;
};

struct Item_801EE0BC {
    u8 data[12];
    s32 id;
    u32 f10;
};

struct Pkt_801EDF64 {
    u8 cmd;
    u8 size;
    u16 a;
    u16 b;
    u16 pad;
    u16 c;
    u8 d;
    u8 e;
};

struct Pkt_801EE330 {
    u8 cmd;
    u8 size;
    u16 pad0;
    u16 a;
    u16 pad1;
    s32 b;
};

struct RecoveredGlobal_801EE5A4_lbl_805129F8 {
    s32 value;
    u8 remaining[0xD4];
};

struct Pkt_801EE54C {
    u8 cmd;
    u8 size;
    u16 a;
    s32 b;
    s32 c;
    s32 d;
};

struct Ent_801EE5EC {
    u8 name[0x20];
    s32 v;
};

typedef char RecoveredGlobal_801EE5A4_lbl_805129F8_size[sizeof(RecoveredGlobal_801EE5A4_lbl_805129F8) == 0xD8 ? 1 : -1];

struct Item_801EE77C {
    u8 data[12];
    s32 id;
    u32 f10;
};

struct Player_801EE77C {
    u8 pad[0xD00];
    void *fD00;
};

struct Item_801EEE68 {
    u8 data[12];
    s32 id;
    u32 f10;
};

struct Item_801EE77C;

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
    virtual void m0(int);
    char pad2[0x1080];
    s32 f109c;
};

struct Base_801F1A0C { u8 pad[0x18]; };

struct List_801F1A0C : Base_801F1A0C {
    virtual ~List_801F1A0C();
    char names[0x84][0x20];
    s32 count;
};

struct Vec3_801F0970 { f32 x, y, z; };

struct Pair_801F1838 { s32 a; s32 b; };

struct Vec2_801E717C { f32 x, y; };

struct Vec2_801E74D0 { f32 x, y; };

struct Vec3_801E79BC { f32 x, y, z; };

struct Spawn_801E8930 {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    s32 f18;
    s32 f1c;
    u8 pad20[4];
    f32 a;
    f32 b;
    u8 pad2c[4];
    s32 c;
    u8 pad34[0x8];
};

struct Vec_801E8930 { f32 x; f32 y; f32 z; };

struct Spawn_801E8AE8 {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0xC];
    f32 a;
    f32 b;
    u8 pad2c[4];
    s32 c;
    u8 pad34[0xC];
};

struct Spawn_801E8C14 {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0xC];
    f32 a;
    f32 b;
    u8 pad2c[4];
    s32 c;
    u8 pad34[0xC];
};

struct Spawn_801E8D44 {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0xC];
    f32 a;
    f32 b;
    u8 pad2c[4];
    s32 c;
    u8 pad34[0xC];
};

struct Spawn_801E8E4C {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0xC];
    f32 a;
    f32 b;
    u8 pad2c[4];
    s32 c;
    u8 pad34[0xC];
};

struct Spawn_801E8F54 {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0xC];
    f32 a;
    f32 b;
    u8 pad2c[4];
    s32 c;
    u8 pad34[0xC];
};

struct Vec_801EE220 {
    f32 x, y, z;
};

struct Vec_801EF134 {
    f32 x, y, z;
};

struct NpcSet_801EF3B4 {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0x1C - 0x18];
    s32 f1C;
    u8 pad20[4];
    f32 f24;
    u8 pad28[0x30 - 0x28];
    s32 f30;
    s32 f34;
    s32 f38;
    u8 pad3C[0x40 - 0x3C];
};

struct Spawn_801EF7A8 {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    s32 f18;
    s32 f1c;
    u8 pad20[4];
    f32 a;
    f32 b;
    u8 pad2c[4];
    s32 c;
    u8 pad34[0x8];
};

struct Vec_801EF7A8 { f32 x; f32 y; f32 z; };

struct NpcSet_801EF944 {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0x24 - 0x18];
    f32 f24;
    f32 f28;
    u8 pad2C[0x30 - 0x2C];
    s32 f30;
    u8 pad34[0x40 - 0x34];
};

struct NpcSet_801EFA5C {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0x24 - 0x18];
    f32 f24;
    f32 f28;
    u8 pad2C[0x30 - 0x2C];
    s32 f30;
    u8 pad34[0x40 - 0x34];
};

struct NpcSet_801EFB6C {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0x24 - 0x18];
    f32 f24;
    f32 f28;
    u8 pad2C[0x30 - 0x2C];
    s32 f30;
    u8 pad34[0x40 - 0x34];
};

struct NpcSet_801EFC54 {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0x24 - 0x18];
    f32 f24;
    f32 f28;
    u8 pad2C[0x30 - 0x2C];
    s32 f30;
    u8 pad34[0x40 - 0x34];
};

struct NpcSet_801EFD3C {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0x24 - 0x18];
    f32 f24;
    f32 f28;
    u8 pad2C[0x30 - 0x2C];
    s32 f30;
    u8 pad34[0x40 - 0x34];
};

typedef struct Vec_801F0034 { f32 x, y, z; } Vec_801F0034;

struct Vec_801F0110 {
    f32 x, y, z;
};

struct Vec_801F0458 { f32 x, y, z; };

struct Vec_801F0574 {
    f32 x, y, z;
};

typedef struct Vec_801F0710 { f32 x, y, z; } Vec_801F0710;

struct Vec_801F07D8 {
    f32 x, y, z;
};

struct Vec_801F08AC {
    f32 x, y, z;
};

struct WalkCmd_801F09EC {
    u16 f0;
    u16 player;
    f32 x;
    f32 z;
    u32 flags;
};

struct Obj_801F09EC {
    u8 pad[0x30];
    u32 f30;
};

struct Vec_801F12F0 {
    f32 x, y, z;
};

struct Npc_801F1450 {
    s16 h0;
    s16 h2;
    s32 flags;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    u8 b20;
    u8 b21;
    u8 b22;
    u8 b23;
    f32 f24;
};

void * memcpy(void *, const void *, u32);
s32 memset(void *, int, int);
void TKeyBoardControl__sub_8000F950(void);
void mark_area_change_pending();
void VecCopy__FP3VecPC3Vec(Vec_801F0574 *, const void *);
int obj_isState2_324__13TUnk_804806E8Fv(TObjPlayer*);
s16 get_actor_tp(u8 *);
s32 obj_getPtr2B0_20();
s16 obj_getS16_2BA(u8 *);
s32 obj_isState3_324__13TUnk_804806E8Fv(int);
int get_player_data__10TObjPlayerFi(int a0);
u16 get_entity_id(void *);
s32 get_current_floor();
f64 atan2_float(void *, f32, f32);
void TLobby__sub_8001DE30(void *);
void TLobby__sub_8001DEA8(s32 arg0);
void bswap__12player_statsFv(void *arg0);
Ctx_801EA5FC * get_global_state__23TAdSinglePlyChrSelectGCFv();
s32 setControlOverride__12TBoss1DragonFs(int, void *);
f32 * get_position_ptr__10TObjPlayerFv();
int set_camera_capture_overlay_alpha(void*);
int set_shake_preset__11TCameraCtrlFl(void*);
}
void reset_cameras_to_actor(void *actor, s32 arg1);
extern "C" {
int is_quest_active(void);
s32 reset_battle_camera__11TCameraCtrlFv();
void TCameraCtrl__sub_8006B3B8(Vec_801EE220 *, Vec_801EE220 *);
int reset_to_local_player__11TCameraCtrlFv(void*);
void set_override_position_and_angle__11TCameraCtrlFPUcs(Vec_801E9400 *, int, Vec_801E9400 *, s32 *);
void set_fixed_position_and_target__11TCameraCtrlFPUcPUc(Vec_801E945C *, Vec_801E945C *, Vec_801E945C *);
void request_follow_camera_offsets(void *arg0, void *arg1, u16 arg2);
int set_active_camera_flag__11TCameraCtrlFv(void*);
int end_conversation_camera(void*);
int begin_conversation_camera(void*);
u32 get_layout_id__20TWindowSubStatusDispFv(s32);
s32 get_unit_list__6TLobbyFv();
s32 TLobby__sub_80070ACC();
s32 set_split_screen_flag__6TLobbyFv();
s32 TLobby__sub_80070B34(int);
s32 TLobby__sub_80070BE8(s32);
s32 TLobby__sub_80070C50();
s32 TLobby__sub_80070EE4(int);
s32 TLobby__sub_80070F4C();
s32 TLobby__sub_80070FD8();
s32 TLobby__sub_80071064(int);
s32 TLobby__sub_800710D8(Item_801EBF30 *);
s32 TLobby__sub_8007119C(s32);
void add_entry__6TLobbyFiii(void *, void *, s32);
s32 copy_player_visual_record(void *, int);
s32 fn_80077788(void);
s32 fn_80077790(void);
s32 __ct__16TPlyGuildCardTagFv(s32);
int reset_state__9TCineCtrlFl(void*);
int reset__9TCineCtrlFl(void*);
void * get_state__23TAdSinglePlyChrSelectGCFv();
volatile unsigned long get_actor_section_id__15TPlyPhotonChairFv(int);
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
void resume_update__7TObjectFv(void *arg0);
u32 prs_decompress_buffer(s32, s32);
void *TLobby__sub_800F8498(void *arg0, void *arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
u32 get_serial_access__22TQuestVmDownLoadServerFv();
u32 poll_serial_access__22TQuestVmDownLoadServerFv();
s32 TLobby__sub_801036CC();
s32 is_script_controlled__10TObjPlayerFv();
s32 activate_d04_slot__10TObjPlayerFv();
s32 create_instance__12TItemDropSubFl(int, void *);
void init__9TItemDataFv(Item_801EE77C *);
s16 get_mag_item_data(s32);
s16 get_mag_level(s32);
s16 get_mag_item_percent(s32);
s16 get_mag_item_stat_percent();
s32 advance_item_id_counter(u16);
f32 xz_distance_squared(Vec3_801E79BC *, Vec3_801E79BC *);
f32 xyz_distance_squared(u8 *arg0, u8 *arg1);
s32 get_class_type_name__6TLobbyFl(int);
int TLobby__sub_80142944(void *);
int TNpcPlayer__sub_8014DC30(void*);
}
void init_6x40_walk_packet(void *a0);
extern "C" {
void *find_entity_by_id(u16 id);
u32 TOChatSensor__create(s32 arg0);
void TOMineTrap__sub_80171368(f32);
int set_instance__10TOMineTrapFi(void*);
int set_trap_count__10TOMineTrapFi(void*);
int clear_enabled_main_warps(void*);
s32 clear_active_bit__16TObjCityMainWarpFv(int);
void TLobby__sub_80190FD0(int a0);
int TObjHashiVersus2__sub_801912A4(void*);
int TObjHashiVersus2__sub_801912B0(void*);
s32 delete_by_param__13TQuestColCtrlFl(int, void *);
void * create_quest_col_apc_inw__6TLobbyFPvPv(Spawn_801E8930 *, s32 *);
int fn_8019608C(void*);
void * fn_80196214(Spawn_801E8C14 *, s32 *);
void * fn_801963A8(Spawn_801E8D44 *, s32 *);
void * create_quest_col_alock(Spawn_801E8AE8 *, s32 *);
void * fn_80196814(Spawn_801E8E4C *, s32 *);
void * create_quest_col(Spawn_801E8F54 *, s32 *);
}
void load_memcard_file(void);
extern "C" {
void TLobby__sub_80197F74(void);
void fn_80197FD0(void *arg0, void *arg1);
s32 sub_801A1DDC__10TObjPlayerFv();
int clear_quest_state__6TLobbyFv(void*);
int reset_quest_counter__6TLobbyFv(void*);
int set_cleanup_flag__6TLobbyFv(void*);
s32 get_card_window_field_244__10TObjPlayerFv();
s32 init_local_pad_binding__10TObjPlayerFv();
s32 stop_force_if_alive__10TObjPlayerFv();
s32 TObjPlayer__sub_801AF904();
s32 send_field1c_packet__6TLobbyFl();
s32 send_font_state__6TLobbyFl();
void draw_small_label__15TFontSmallLobbyFi(s32 arg0);
void TLobby__sub_801B1254(s32 arg0);
s32 foreach_player__10TObjPlayerFv(s32 *);
void send_6x24_teleport_player(u16 slot, void *pos, s32 heading);
s32 prepare_guild_return__10TObjPlayerFPv(u32, s32);
s32 player_flag_1__6TLobbyFv();
s32 stop_battle__10TObjPlayerFv();
s32 enable_action_input__10TObjPlayerFPv();
s32 disable_action_input__10TObjPlayerFv();
s32 TObjPlayer__sub_801B3FD8();
s32 TObjPlayer__sub_801B4044();
void send_code50_packet__10TObjPlayerFi(s32 arg0);
s32 send_code_49_1__10TObjPlayerFi();
void get_item_record__23TShopJudgmentItemWindowFPv(void *, s32, s32);
void send_6x29_delete_item__10TObjPlayerFPvii(void *obj, s32 a, s32 b);
void send_6x21_inter_level_warp(void *obj, s32 value);
u32 TObjPlayer__sub_801BFFA0(void *);
int TFontSmallLobby__sub_801C013C(void *p);
void init_battle_ctrl__6TLobbyFii(s32, s32);
void request_player_size_restore(PlayerScaleState *state);
void request_player_shrink(PlayerScaleState *state);
Vec_801ECFDC * TObjPlayer__sub_801C6FDC(void *);
void * set_mode_and_refresh_object__10TObjPlayerFPvi(void *, Item_801EE77C *);
void * start_inventory_update__10TObjPlayerFi(void *, s32);
void * get_owner_if_alive__10TObjPlayerFv(void *);
s32 fn_801DA140(int, int, int);
void* __ct__13TQuestBgmCtrlFP7TObject(void*, TObject *);
void qst_op_item_create_multi_cm(u8 i);
void qst_op_chat_bubble(void);
void qst_op_prepare_gba_rom_from_disk(void);
void qst_op_find_bank_item(u8 i, u8 out);
void qst_op_read_counter(void);
void qst_op_get_player_room(void);
void qst_op_get_player_hp_tp(void);
void qst_op_gba_write_identifiers(void);
void qst_op_get_player_level(void);
void qst_op_get_slot_meseta(u8 i);
void qst_op_get_time_played(s32 arg0);
}
void qst_op_get_lang_setting(void);
extern "C" {
int qst_op_gba_update_dl_graph(void* p);
int qst_op_gba_destroy_dl_graph(void* p);
int qst_op_gba_create_dl_graph(void* p);
void qst_op_disable_palettex(void);
void qst_op_restore_palettex(void);
void qst_op_atan2_int(void);
void qst_op_unfreeze_everything(void);
void qst_op_toggle_freeze_everything(void);
int qst_op_default_camera_pos2(void* p);
void qst_op_fleti_locked_camera(void);
int qst_op_set_screen_bw(void* p);
void qst_op_set_slot_zalure(s32 arg0);
void qst_op_set_slot_jellen(s32 arg0);
void qst_op_set_slot_deband(s32 arg0);
void qst_op_set_slot_paralyze(s32 arg0);
void qst_op_set_slot_poison(s32 arg0);
void qst_op_clear_slot_invincible(s32 arg0);
void qst_op_set_slot_invincible(s32 arg0, s32 arg1);
void qst_op_use_animation(s32 arg0, s32 arg1);
void reset_random_enemies_mode__6TLobbyFv(void);
void qst_op_results_window_visible_multi_cm(s32 arg0);
void qst_op_start_or_update_gba_joyboot(s32 idx);
void qst_op_file_dl_req(void);
int qst_op_write_flag_buf_to_event_flags2(void* p);
void qst_op_chl_set_min_time_online(s32 arg0);
void qst_op_check_for_hacking(u8 out);
}
void qst_op_write4(void);
void qst_op_write2(void);
void qst_op_write1(void);
void qst_op_read4(void);
void qst_op_read2(void);
extern "C" {
void qst_op_is_there_grave_message(s32 arg0);
void qst_op_ba_death_tech_level_up(void);
}
void qst_op_set_shrink_size(s32 player_variable, s32 size_variable);
extern "C" {
void qst_op_write_flag_buf_to_event_flags(u8 arg0);
void qst_op_is_bosswarp_opt_disabled(s32 arg0);
void qst_op_player_recovery(s32 arg0);
void qst_op_get_chl_retry_choice(s32 arg0);
void qst_op_reset_map(void);
}
void qst_op_shift_right(s32 arg0, s32 arg1);
void qst_op_shift_left(s32 arg0, s32 arg1);
extern "C" {
void qst_op_set_enemy_resist_data(s32 arg0);
void qst_op_set_enemy_attack_data(s32 arg0);
void qst_op_set_enemy_physical_data(int _w0);
void qst_op_set_cmode_grave_rates(s32 reg);
void TObjTombstone__sub_80074E74(f32 *w);
void qst_op_chl_get_timerecord(s32 arg0);
void qst_op_chl_set_timerecord(s32 arg0);
void qst_op_get_game_version(s32 arg0);
void qst_op_send_mail(void);
void qst_op_disable_win_pfx(void);
void qst_op_enable_win_pfx(void);
void qst_op_ba_get_score(u8 src, u8 dst);
int qst_op_turn_off_bgm_p2(void* p);
void qst_op_nop_F8EF(void);
void qst_op_get_eventflag(s32 arg0, s32 arg1);
void qst_op_kill_player(s32 arg0);
void qst_op_disable_stealth_suit_effect(s32 arg0);
void qst_op_enable_stealth_suit_effect(s32 arg0);
void qst_op_set_cmode_rank_override(void);
int qst_op_ba_clear_trapself(void);
void qst_op_ba_set_box_drop_area(s32 arg0);
void qst_op_check_rank_time(u8 arg0, u8 arg1);
void qst_op_set_cmode_rank_result(void);
void qst_op_ba_sonar_count(void);
void qst_op_set_allow_item_flags(void);
int qst_op_ba_hide_self_traps(void);
int qst_op_ba_show_self_traps(void);
int qst_op_unset_ult_map(void* p);
int qst_op_set_ult_map(void* p);
int qst_op_restore_warp_dest_floor(void* p);
void qst_op_set_current_area_number(void);
void qst_op_ba_set_meseta_drop_mode(void);
void qst_op_ba_death_lvl_up(void);
void qst_op_ba_set_time_limit(void);
void qst_op_ba_set_char_level(void);
void qst_op_ba_set_lives(void);
void qst_op_ba_hide_target_reticle(void);
void qst_op_ba_set_trap_count(s32 reg);
extern const s32 lbl_80449AEC[];
void qst_op_set_cmode_base_time(s32 arg0);
int qst_op_enable_npc_visual(void* p);
void qst_op_set_shrink_cam2(u8 arg0);
void qst_op_set_shrink_cam1(u8 arg0);
void qst_op_unshrink(s32 arg0);
void qst_op_shrink(s32 arg0);
void qst_op_release_dragon(void* p);
void qst_op_cmode_check_any_player_dead(s32 arg0);
void qst_op_cmode_check_all_players_dead(s32 arg0);
void qst_op_nop_F822(s32 arg0);
void qst_op_ba_start(void);
void qst_op_ba_set_respawn(void);
void qst_op_ba_set_unused_F817(void);
void qst_op_ba_set_trap_mode(void);
void qst_op_ba_set_tool_mode(void);
void qst_op_ba_initial_floor(void);
}
void qst_op_map_designate_ex(u32 first);
extern "C" {
int qst_op_disable_map(void);
int qst_op_enable_map(void);
}
void qst_op_get_leader_id(u8 reg);
void qst_op_get_client_id(u8 reg);
int qst_op_warp_on(void* p);
extern "C" {
void qst_op_pad_dragon(void* p);
}
void qst_op_sync_register(void);
extern "C" {
void qst_op_set_eventflag2(void);
void qst_op_set_eventflag(void);
void qst_op_disable_mainmenu(void);
void qst_op_nop_BC(void);
int qst_op_clr_qt_exit(void);
void qst_op_setevt(void);
}
void qst_op_clear_quest_board_handler(void);
void qst_op_set_quest_board_handler(void);
extern "C" {
void qst_op_winset_time(s32 arg0);
}
int qst_op_winend_time(void* p);
void qst_op_map_designate(u32 first);
extern "C" {
void qst_op_find_inventory_item_ex(u8 arg0, u8 arg1);
}
void qst_op_item_check(u32 first, u32 destination);
void qst_op_item_delete2(u32 src, u32 dst);
void qst_op_item_delete(u32 src, u32 dst);
void qst_op_item_create2(u8 arg0, u8 arg1);
void qst_op_item_create(u8 arg0, u8 arg1);
extern "C" {
void qst_op_del_obj_param(s32 arg0);
}
void qst_op_pl_add_meseta(void);
extern "C" {
int qst_op_clr_qt_cancel(void);
int qst_op_clr_qt_success(void);
}
int qst_op_clr_qt_failure(void);
void qst_op_set_qt_cancel(u16 arg0);
void qst_op_set_qt_success(u16 arg0);
void qst_op_set_qt_failure(u16 arg0);
void qst_op_clr_floor_handler(void);
void qst_op_set_floor_handler(void);
extern "C" {
int qst_op_clear_mainwarp_all(void* p);
}
void qst_op_set_mainwarp(void);
void qst_op_playbgm_epi(void);
void qst_op_switch_off(void);
void qst_op_switch_on(void);
void qst_op_npc_talk_kill(void);
void qst_op_p_talk_guild(void);
void qst_op_p_return_guild(void);
void qst_op_nop_A0_debug(void);
int qst_op_cine_disable(void);
int qst_op_cine_enable(void);
void qst_op_hud_show(void);
void qst_op_hud_hide(void);
extern "C" {
int qst_op_pl_pkon(void* p);
int qst_op_pl_pkoff(void* p);
int qst_op_npc_chkwarp(void* p);
}
void qst_op_gettime(u8 arg0);
extern "C" {
void qst_op_unhide_ene(s32 arg0);
void qst_op_unhide_obj(s32 arg0);
}
void qst_op_chk_ene_num(int a0);
void qst_op_if_zone_clear(s32 arg0, s32 arg1);
void qst_op_p_action_enable(void);
void qst_op_p_action_disable(void);
void qst_op_create_pipe(void);
void qst_op_p_enablewarp(void);
void qst_op_p_disablewarp(void);
void qst_op_p_dead(void);
void qst_op_p_look_at(void);
void qst_op_p_look(void);
int qst_op_p_col(void* p);
int qst_op_p_noncol(void* p);
void qst_op_enable_movement1(void);
void qst_op_disable_movement1(void);
int qst_op_npc_talk(void* p);
int qst_op_npc_nont(void* p);
void qst_op_npc_kill(void);
int qst_op_cam_adj(void* p);
extern "C" void qst_op_cam_pan(u8 reg);
void qst_op_nop_86(void);
void qst_op_nop_85(void);
int qst_op_cam_zmout(void* p);
int qst_op_cam_zmin(void* p);
int qst_op_cam_quake(void);
void qst_op_npc_play(void);
void qst_op_npc_stop(void);
void qst_op_npc_crtpk(void);
void qst_op_npc_crt(void);
void qst_op_winend(void);
void qst_op_mesend(void);
void qst_op_add_msg(void);
extern "C" {
void qst_op_close_msg_qb(void);
}
void qst_op_disp_msg_qb(void);
void qst_op_window_msg(void);
void qst_op_bgm(void);
void qst_op_se(void);
void qst_op_fadeout(void);
void qst_op_fadein(void);
void qst_op_list(void);
void qst_op_message(void);
extern "C" {
void qst_op_stack_push(s32 arg0);
}
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
extern "C" {
void qst_op_jmp_off(s32 arg0, u8 arg1, u8 *arg2);
void qst_op_jmp_on(s32 arg0, u8 arg1, u8 *arg2);
}
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
void qst_op_gget(u16 arg0, s32 arg1);
void qst_op_glet(u16 arg0, s32 arg1);
extern "C" {
s32 set_flag_80000__6TLobbyFv(int);
s32 set_flag_40000__6TLobbyFv(int);
s32 TLobby__sub_801F3314(int);
s32 set_flag_8000__6TLobbyFv(int);
int TLobby__sub_801F3384(void *p);
int TLobby__sub_801F33A8(void *p);
int TLobby__sub_801F33CC(void *p);
int TLobby__sub_801F33F0(void *p);
int set_flag_4__6TLobbyFPv(void *p);
s32 TLobby__sub_801F345C();
int fn_801F34A0(void *p);
}
s32 get_field_d4(void *);
extern "C" {
s32 fn_get_field_3ac(void *);
void TLobby__sub_801F34E8(int a0, int a1);
int TLobby__sub_801F34F8(void);
void TLobby__sub_801F3500(void *, Vec_801E8930 *);
int TLobby__sub_801F3568(void*);
}
void build_6x77_sync_quest_register(void* p);
extern "C" {
s32 TLobby__sub_801F3614();
void copy_position__6TLobbyFv(void *, Vec_801ECFDC *);
int TLobby__sub_801F3694(void *p);
int TLobby__sub_801F36BC(void*);
int TLobby__sub_801F36D8(void*);
int TLobby__sub_801F36E4(void*);
s32 TLobby__sub_801F36F0(int);
void TLobby__sub_801F36F8(s32, s32, s32, Item_801ED7BC *);
s32 TLobby__sub_801F3700(int);
void TLobby__sub_801F3708(s32, s32, s32, Item_801ED7BC *);
int set_mode__13TRaderMapCoreFi(void*);
int set_quest_exit_callback(void*);
int set_quest_cancel_callback(void*);
int set_quest_success_callback(void*);
int THunterGuildSeqOffline__sub_801F3748(void*);
void TObjDoor__sub_801F3754(void);
void TObjDoor__sub_801F3760(void);
}
void set_quest_floor_designation_ex(s16, s32, s32, s32, s32);
void set_quest_floor_designation(s16, s32, s32, s32);
s32 get_story_flag(s32 flag);
void clear_story_flag(s32 flag);
extern "C" {
s32 dispatch_by_main_phase__14TBoss4DarkFalzFUs(void *);
int create__16TObjItemOKWindowFPv(void*);
int create__18TObjItemNameSelectFPv(void*);
void *create__17TObjItemNameEntryFPv(void *arg0);
s32 destroy_children_with_tag(TObject *);
}
void clear_floor_handler(s32 i);
void set_floor_handler(s32 i, s32 v);
extern "C" {
s32 clear_buffer__12TQuestThreadFPv(u32);
s32 get_character_save_record(u32);
s32 get_floor_map_terrain(s32 arg0);
}
s32 request_story_select_state(s32 arg0);
extern "C" {
void TLobby__sub_80207F30(Spawn_801EA508 *);
s32 clear_floor_event_flags();
s32 is_room_enemy_set_cleared(int, int, void *);
s32 unhide_enemies_at__6TLobbyFlll(s32, s32, s32, s32);
void unhide_room_set_objects(s32 a, s16 b, s16 c, s32 d);
s32 TCheckRoomSequence__sub_80210D44(u8 *item, s32 slot);
s32 handle_main_phase__6TLobbyFl();
void try_close__6TLobbyFPv(void *p);
s32 play_sound_effect(int, int, int, int);
void play_cue_stream_file(s32 name);
int TLobby__sub_802272B4(void*);
int TLobby__sub_8022733C(void*);
void set_area__6TLobbyFl(void *, int, int);
Card_801EB10C * construct__13TUnk_804CC048FPvPvPv(void *, void *, void *, void *);
}
u8 is_floor_switch_set(u32 id, s16 floor);
extern "C" {
u8 is_current_floor_switch_set(int);
}
void clear_current_floor_switch(s32 id);
void set_current_floor_switch(s32 id);
void init_switch_table(void);
extern "C" {
void * __nw__7TObjectFUl(u32);
}
void create_quest_telepipe_for_client(u16 arg0);
extern "C" {
void TWindow__close(u8 *arg0);
void request_active_window_close(void);
s32 set_timer_window_time__11TWindowCtrlFv(int, void *);
int close_timer_window__11TWindowCtrlFv(void*);
int create_alt_timer__11TWindowCtrlFv(void*);
}
void close_window_if_active(void *p);
extern "C" {
void TObjPlayer__sub_8024ABDC(s32 arg0);
void TLobby__sub_8024AC20(s32 arg0);
void set_field28__11TWindowCtrlFs(u16);
s32 close_windows_by_flags__11TWindowCtrlFUs(int, void *);
void open_default__11TWindowCtrlFi(u16, s32);
s32 __ct__15TWindowHelpItemFPvUs(s32, s32, s32);
void align_menu_entry_positions(s32 win);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 check_room_seq_4__16TAdChrSelASlotGCFl(s32 a, s32 b);
u32 update_window_mode_from_progress__6TLobbyFPv(s32, Pair_801F1838 *);
}
int dispatch_message_window_text(void *w, int text, int flags);
s32 create_quest_message_window_at(s32 arg0, s32 arg1);
extern "C" {
u32 create_quest_message_window();
s32 get_window_layout_position(s32);
void fn_80278518(void *arg0, s32 arg1);
s32 save_and_close__20TShopArmorListWindowFv();
s32 create_equip_kind_window(s32, s32 *, s32);
s32 update_screen__6TLobbyFv();
s32 set_challenge_split_flag__6TLobbyFv();
s32 TLobby__sub_80291DF8(int);
s32 TLobby__sub_80291EAC(s32);
s32 TLobby__sub_8029204C();
s32 TLobby__sub_80292200(int);
void TLobby__sub_80292268(void *, void *, s32);
s32 TLobby__sub_80292270(s32, s32);
s32 TLobby__sub_802924B4(Item_801EBF30 *, u16);
s32 TLobby__sub_8029299C();
s32 TLobby__sub_80292A34();
int destroy_singleton__6TLobbyFv(void*);
int init_graph__6TLobbyFv(void*);
int update_alloc_size__6TLobbyFv(void*);
int get_selected_slot__6TLobbyFv(void*);
}
void update_gba_joyboot_transfer();
extern "C" {
s32 TLobby__sub_8032CDEC();
void update_entries__18TChallenge4PResultFii(ItemData_801E72B4 *, s32);
}
s32 update_challenge_result_player_locks();
extern "C" {
s32 fn_8034D3D0(u8 *, f32, s32, s32, s32, Vec3_801E915C *, s32);
s32 fn_8034D790(u8 *, f32, s32, s32, s32, Vec3_801E9274 *);
}
void set_partner_dialogue_override(const char *text, s32 kind, u16 player);
extern "C" {
s32 TLobby__sub_8034DAA0(int, int, void *);
int notify_all_battle_players__10TObjPlayerFv(void*);
int update_4p_battle_ctrls__10TObjPlayerFv(void*);
}
void set_partner_common_remark(s32 kind, const char *text);
extern "C" {
int clear_partner_dialogue_flags(void*);
}
void quest_player_face_actor(u16, u16);
void quest_player_look_at_partner(u16);
extern "C" {
void send_stop_at_position__10TNpcPlayerFUsPvs(u16, Vec_801F0458 *, s32);
int enable_partner_chatter__10TNpcPlayerFv(void*);
int disable_partner_chatter__10TNpcPlayerFv(void*);
}
void quest_remove_npc_player(u16 arg0);
extern "C" {
void send_inter_level_warp_all__10TNpcPlayerFl();
s32 send_npc_control_6x69__10TNpcPlayerFs(int);
s32 send_npc_stop_6x69__10TNpcPlayerFs(int);
void send_npc_control_create__10TNpcPlayerFsUssPUcl(u16, u16, s32, Vec_801F12F0 *, s32);
void create_default_companion__10TNpcPlayerFssPUcl(u16 leader, int appearance, f32* pos, int heading);
s32 send_npc_control_notify_players__10TNpcPlayerFsUss(s32, s32, s32);
s32 send_npc_create__10TNpcPlayerFss(int, int);
s32 reset_player_lobby_model__10TNpcPlayerFUs(int, void *);
s32 update_player_field__10TNpcPlayerFUsl(int, int, void *);
s32 end_camera_pan_for_client__10TNpcPlayerFUs(int, void *);
s32 apply_to_battle_player_slot__10TNpcPlayerFUss(int, int, void *);
void TObjPlayer__sub_80354CCC(s32 arg0);
void TObjPlayer__sub_80354D14(s32 arg0);
void TObjPlayer__sub_80354DAC(s32 arg0);
void TObjPlayer__sub_80354DF4(s32 arg0);
void * open_message_scroll_window__6TLobbyFlll(Vec2_801E717C *, Vec2_801E717C *, void *);
void fn_80364C40(void *, s32, s32, f32);
s32 rand(void);
s32 strncmp(void *, void *, int);
s32 strcmp(void *, void *);
s32 strncpy(void *, int, int);
u32 TLobby__sub_803DF1CC(void);

extern E_801EB484 TLobby__duel_result_table[];
extern s32 TLobby__designated_client_id;
extern int TLobby__battle_ctrl_default_value;
extern u8 *TLobby__quest_message_window;
extern u32 TLobby__quest_secondary_window;
extern s32 TLobby__quest_choice_window;
extern unsigned char TLobby__active_window_index;
extern int TLobby__quest_window_state;
extern int TLobby__data_805D5EB0;
extern int TLobby__quest_window_object;
extern int TLobby__menu_state_object;
extern s32 TLobby__quest_state_object_168;
extern u32 TLobby__quest_state_object_16c;
extern u32 TLobby__data_805D5EC4;
extern s32 gba_download_data_buffer;
extern s32 gba_download_data_size;
extern int evt2_random_enemies_mode;
extern RecoveredGlobal_8000F7FC_lbl_80515F48 fn_801F3480;
extern RecoveredGlobal_801F196C_lbl_804499A8 quest_sound_effect_ids;
extern Pair_801F1838 lbl_80449A38[];
extern Tbl_801EDC98 lobby_sub_801edc98_id_table;
extern RecoveredGlobal_801EDC24_lbl_80449A88 lbl_80449A88;
extern RecoveredGlobal_801EDBDC_lbl_80449A94 lobby_menu_byte_1_map;
extern RecoveredGlobal_801EDB4C_lbl_80449AAC lbl_80449AA4;
extern RecoveredGlobal_801EDB4C_lbl_80449AAC lbl_80449AAC;
extern RecoveredGlobal_801EDB4C_lbl_80449AAC lbl_80449AB8;
extern RecoveredGlobal_801EDB4C_lbl_80449AAC lbl_80449AC0;
extern RecoveredGlobal_801EDA70_lbl_80449AC8 lbl_80449AC8;
extern RecoveredGlobal_801EDA70_lbl_80449AC8 lbl_80449AD4;
extern RecoveredGlobal_801EDB4C_lbl_80449AAC lbl_80449ADC;
extern RecoveredGlobal_801EDB4C_lbl_80449AAC lbl_80449AE4;
extern RecoveredGlobal_801EC90C_lbl_80449AFC lbl_80449AFC;
extern RecoveredGlobal_801EC90C_lbl_80449AFC lbl_80449B08;
extern s32 lbl_80449B10[];
extern Tbl_801E9AF8 lobby_index_identity_table_a[];
extern s32 lbl_80449B2C[];
extern const f64 lbl_80449CC0;
extern RecoveredGlobal_801ECF84_lbl_8050D3E0 lbl_8050D3E0;
extern s32 symbolchat_colli_param_table[];
extern E_801E93B4 controller_input_state[];
extern s16 battle_event_second_table[];
extern RecoveredGlobal_801EB73C_lbl_80512340 quest_player_name_buffer;
extern RecoveredGlobal_801EB6B8_lbl_80512350 quest_player_class_name_buffer;
extern RecoveredGlobal_801EE5A4_lbl_805129F8 quest_board_handlers;
extern f32 lbl_805D3538;
extern f32 lbl_805D353C;
extern f32 lbl_805D3540;
extern f32 lbl_805D3544;
extern f32 lbl_805D3548;
extern s32 resource_decompress_buffer;
extern s32 game_difficulty_selection;
extern f32 lbl_805D5DC4;
extern s32 quest_message_speaker_id;
extern u32 quest_mission_manager;
extern const f32 lbl_805DC4B8;
extern const f32 lbl_805DC4BC;
extern const f32 lbl_805DC4C0;
extern const f32 lbl_805DC4C8;
extern const f32 lbl_805DC4CC;
extern const f32 lbl_805DC4D4;
extern const f32 lbl_805DC4D8;

void qst_op_va_end() {
    qst_op_stack_popm(1, 7);
}

void qst_op_va_start() { qst_arg_count = 0; qst_op_stack_pushm(1, 7); }

void qst_op_scroll_text() {
    Vec2_801E717C pos;
    Vec2_801E717C size;
    s32 x = qst_args[0];
    s32 y = qst_args[1];
    s32 cols = qst_args[2];
    s32 rows = qst_args[3];
    s32 field90 = qst_args[4];
    f32 timer = *(f32 *)&qst_args[5];
    s32 msg = qst_args[6];
    s32 arg = qst_args[7];
    void *win;

    if ((*(void * *)&TLobby__quest_message_window) != NULL) {
        TWindow__close((u8 *)(*(void * *)&TLobby__quest_message_window));
    }
    pos.x = x;
    pos.y = y;
    size.x = lbl_805DC4B8 + (f32)(cols * 0x12);
    size.y = (lbl_805DC4BC + (f32)(rows * 0x14)) - lbl_805DC4C0;
    win = open_message_scroll_window__6TLobbyFlll(&pos, &size, &qst_registers[msg]);
    ((TLobby *)win)->set_field_90(field90);
    dispatch_message_window_text(win, arg, 0x13);
    ((TLobby *)win)->set_timer(timer);
    (*(void * *)&TLobby__quest_message_window) = win;
}

void qst_op_item_create_multi_cm(u8 i) {
    ItemData_801E72B4 item;
    s32 mode = qst_registers[i++];
    ((void (*)(ItemData_801E72B4 *))init__9TItemDataFv)(&item);
    item.data1[0] = qst_registers[i++];
    item.data1[1] = qst_registers[i++];
    item.data1[2] = qst_registers[i++];
    item.data1[3] = qst_registers[i++];
    item.data1[4] = qst_registers[i++];
    item.data1[5] = qst_registers[i];
    item.id = ((u32 (*)(u16))advance_item_id_counter)(local_client_id);
    switch (mode) {
    case 0:
        update_entries__18TChallenge4PResultFii(&item, 2);
        break;
    case 1:
        update_entries__18TChallenge4PResultFii(&item, 0);
        break;
    case 2:
        update_entries__18TChallenge4PResultFii(&item, 1);
        break;
    }
}

void qst_op_delayed_switch_episode(s32 arg0) {
    switch (qst_registers[(u8)arg0]) {
    case 0:
        request_story_select_state(0);
        return;
    case 1:
        request_story_select_state(1);
        return;
    }
}

void qst_op_chat_bubble(void) {
    s32 id = qst_args[0];
    s32 arg = qst_args[1];
    void *player;
    s32 start;
    s32 end;
    s32 i;
    s32 win;
    s32 v;
    if (id < 100) {
        open_default__11TWindowCtrlFi(id, arg);
        set_field28__11TWindowCtrlFs(id);
        return;
    }
    start = TLobby::get_game_mode();
    end = start + TLobby::get_lobby_flag();
    for (i = start; i < end; i++) {
        player = (void *)get_player_data__10TObjPlayerFi(i);
        if (player != NULL) {
            win = get_entity_id(player);
            if (win < 0x4000) {
                v = fn_get_field_3ac(player);
            } else {
                v = get_field_d4(player);
            }
            if (v == id) {
                open_default__11TWindowCtrlFi(win, arg);
                set_field28__11TWindowCtrlFs(win);
                return;
            }
        }
    }
}

void qst_op_chat_box() {
    Vec2_801E74D0 pos;
    Vec2_801E74D0 size;
    s32 x = qst_args[0];
    s32 y = qst_args[1];
    s32 cols = qst_args[2];
    s32 rows = qst_args[3];
    s32 field90 = qst_args[4];
    s32 arg = qst_args[5];

    if ((*(void * *)&TLobby__quest_message_window) != NULL) {
        TWindow__close((u8 *)(*(void * *)&TLobby__quest_message_window));
    }
    pos.x = x;
    pos.y = y;
    size.x = lbl_805DC4B8 + (f32)(cols * 0x12);
    size.y = (lbl_805DC4BC + (f32)(rows * 0x14)) - lbl_805DC4C0;
    (*(void * *)&TLobby__quest_message_window) = (void *)create_quest_message_window_at((s32)&pos, (s32)&size);
    ((TLobby *)(*(void * *)&TLobby__quest_message_window))->set_field_90(field90);
    dispatch_message_window_text((*(void * *)&TLobby__quest_message_window), arg, 3);
    (*(s32 *)&TLobby__quest_window_state) = 4;
    TWindowCtrl::set_flag_bit2();
    close_window_if_active((void *)local_client_id);
    request_active_window_close();
    TWindowCtrl::set_close_flag();
}

void qst_op_add_color_overlay() {
    s32 a = qst_args[0];
    s32 b = qst_args[1];
    s32 c = qst_args[2];
    s32 d = qst_args[3];
    s32 e = qst_args[4];
    u32 obj = ((u32 (*)(u32))__nw__7TObjectFUl)(0x30);
    if (obj != 0) {
        TLobby__sub_800F8498((void *)obj, (void *)(*(s32 *)&tl_01), 0, (s32)e, (u8)((u8)d), (u8)((u8)a), (u8)((u8)b), (u8)((u8)c));
    }
}

void qst_op_get_chosen_item_id(int a0) { qst_registers[(unsigned char)(a0)] = -1; TLobby__active_window_index = a0; TLobby__quest_window_state = 12; TWindowCtrl::set_flag_bit2(); close_window_if_active((void *)((*(int *)&local_client_id))); request_active_window_close(); TWindowCtrl::set_close_flag(); }

void qst_op_prevent_item_select(s32 arg0) {
    if ((u32) TLobby__quest_state_object_16c != 0U) {
        fn_80278518((void *)TLobby__quest_state_object_168, (qst_registers[(u8)arg0]));
    }
}

void qst_op_open_pack_select() {
    s32 var_r31;

    TLobby__quest_state_object_168 = create_equip_kind_window(get_window_layout_position(3), lbl_80449B2C, local_client_id);
    save_and_close__20TShopArmorListWindowFv();
    var_r31 = ((s32 (*)(s32))__nw__7TObjectFUl)(0xBC);
    if (var_r31 != 0) {
        var_r31 = __ct__15TWindowHelpItemFPvUs(var_r31, get_window_layout_position(2), local_client_id);
    }
    (*(s32 *)&TLobby__quest_state_object_16c) = var_r31;
}

void qst_op_prepare_gba_rom_from_disk(void) {
    s32 temp_r31;

    temp_r31 = qst_args[0];
    TLobby::free_luker_object();
    TLobby::send_data(temp_r31);
    TLobby::set_send_buffer((u8 *)gba_download_data_buffer, (s32)gba_download_data_size);
    TLobby::clear_quest_vm_flag();
}

void qst_op_get_players_present(u8 out) {
    s32 p;
    for (p = 0; p < 4; p++, out++) {
        if (((u8 * (*)(s32))get_player_by_client_id)(p) != NULL) {
            qst_registers[out] = 1;
        } else {
            qst_registers[out] = 0;
        }
    }
}

void qst_op_find_bank_item(u8 i, u8 out) {
    ItemData_801E7810 item;
    s32 card;
    qst_registers[out] = -1;
    card = get_character_save_record(0xFFFF);
    if (card != 0) {
        ((void (*)(ItemData_801E7810 *))init__9TItemDataFv)(&item);
        item.data1[0] = qst_registers[i++];
        item.data1[1] = qst_registers[i++];
        item.data1[2] = qst_registers[i++];
        item.data1[4] = qst_registers[i];
        if (((TAdSinglePlyChrSelectGC *)card)->find_entry((s32)(&item)) != 0) {
            qst_registers[out] = 1;
        } else {
            qst_registers[out] = 0;
        }
    }
}

void qst_op_write_counter() {
    s32 idx = qst_args[0];
    s32 val = qst_args[1];
    Win_801E78D4 *w = ((Win_801E78D4 *)get_character_save_record(0xFFFFU));
    if (w != NULL && idx >= 0 && idx < 0x10) {
        w->t[idx] = val;
    }
}

void qst_op_read_counter(void) {
  long long new_var;
  s32 temp_r31;
  u32 character_save_record;
  u8 temp_r30;
  temp_r31 = qst_args[0];
  temp_r30 = (u8) qst_args[1];
  character_save_record = get_character_save_record(0xFFFFU);
  if (character_save_record != 0U)
  {
    if ((temp_r31 >= 0) && (temp_r31 < 0x10))
    {
      new_var = character_save_record + (temp_r31 * 4);
      qst_registers[(u8)temp_r30] = *((s32 *) (((s8 *) new_var) + 0x2314));
    }
  }
  else
  {
    qst_registers[(u8)temp_r30] = -1;
  }
}

void qst_op_get_coord_player_detect(u8 i, u8 out) {
    Vec3_801E79BC pos;
    f32 r;
    f32 r2;
    s32 p;
    u8 *player;

    pos.x = qst_registers[i++];
    pos.y = lbl_805DC4C4;
    pos.z = qst_registers[i++];
    r = qst_registers[i];
    r2 = r * r;
    for (p = 0; p < 4; p++, out++) {
        qst_registers[out] = 0;
        player = ((u8 * (*)(s32))get_player_by_client_id)(p);
        if (player != NULL) {
            if (xz_distance_squared((Vec3_801E79BC *)(player + 0x38), &pos) < r2) {
                qst_registers[out] = 1;
            }
        }
    }
}

void qst_op_get_player_room(void) {
    u8 *player = ((u8 * (*)(s32))get_player_by_client_id)(qst_args[0]);
    u8 i = qst_args[1];
    if (player != NULL) {
        qst_registers[i++] = ((TObjPlayer *)player)->get_field_3e4();
        qst_registers[i] = ((TUnk_804B9870 *)player)->get_stat_by_key_state();
    } else {
        qst_registers[i++] = -1;
        qst_registers[i] = -1;
    }
}

void qst_op_get_player_hp_tp(void) {
    u8 *player = ((u8 * (*)(s32))get_player_by_client_id)(qst_args[0]);
    u8 i = qst_args[1];
    if (player != NULL) {
        qst_registers[i++] = ((TItemProShield *)player)->get_field_2b8();
        qst_registers[i++] = get_actor_hp(player);
        qst_registers[i++] = obj_getS16_2BA(player);
        qst_registers[i] = get_actor_tp(player);
    } else {
        qst_registers[i++] = -1;
        qst_registers[i++] = -1;
        qst_registers[i++] = -1;
        qst_registers[i] = -1;
    }
}

void qst_op_get_section_id() {
  u32 temp_r3;
  u8 temp_r31;
  temp_r3 = ((u32)((u8 * (*)(s32))get_player_by_client_id)((s32)((int) qst_args[0])));
  temp_r31 = (u8) qst_args[1];
  if (temp_r3 != 0U)
  {
    qst_registers[(u8)temp_r31] = get_actor_section_id__15TPlyPhotonChairFv((int) temp_r3);
    return;
  }
  qst_registers[(u8)temp_r31] = -1;
}

void qst_op_gba_write_identifiers(void) {
    TLobby__sub_801F34E8((qst_args[0]), (qst_args[1]));
}

void qst_op_get_player_level(void) {
    u8 temp_r31;
    u8 *temp_r3;
    temp_r3 = (u8 *)(((u8 * (*)(s32))get_player_by_client_id)(qst_args[0]));
    temp_r31 = (u8) qst_args[1];
    if (temp_r3 != NULL) {
        qst_registers[(u8)temp_r31] = ((TObjPlayer *)temp_r3)->get_actor_level_index() + 1;
        return;
    }
    qst_registers[(u8)temp_r31] = -1;
}

void qst_op_get_slot_meseta(u8 i) {
    Card_801E7D7C *w;
    if (((u32)((u8 * (*)(s32))get_player_by_client_id)((s32)((*(void * *)&local_client_id)))) != 0) {
        qst_registers[i] = obj_getPtr2B0_20();
    } else {
        qst_registers[i] = -1;
    }
    w = ((Card_801E7D7C *)get_character_save_record(0xFFFF));
    if (w != 0) {
        (&qst_registers[i])[1] = w->v;
    } else {
        (&qst_registers[i])[1] = -1;
    }
}

void qst_op_get_guildcard_total(int a0) { qst_registers[(unsigned char)(a0)] = TWindowSubComCard::count_active_cards(); }

void qst_op_get_time_played(s32 arg0) {
    u8 *character_save_record;
    character_save_record = (u8 *)(get_character_save_record(0xFFFFU));
    if (character_save_record != NULL) {
        qst_registers[(u8)arg0] = *(s32 *)((s8 *)character_save_record + 0xC);
        return;
    }
    qst_registers[(u8)arg0] = -1;
}
}

void qst_op_get_lang_setting(void) {
    qst_registers[qst_args[0]] = current_language;
}
extern "C" {

void qst_op_wrap_item_with_color() {
    s32 id;
    s8 n;
    u32 player;
    Item_801EE77C item;
    void *obj;
    id = ((s32 *)&qst_args)[0];
    n = ((s32 *)&qst_args)[1];
    obj = find_item_by_id(id);
    if (obj != NULL) {
        ((TItem *)obj)->copy_to_item_data((TItemData *)&item);
    } else {
        return;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != 0) {
        send_6x29_delete_item__10TObjPlayerFPvii((void *)player, (s32)id, 1);
        ((TItemData *)(&item))->set_wrapped();
        ((TItemData *)(&item))->set_present_color(n);
        if (((TObjPlayer *)player)->can_inventory_accept_item((u8 *)((Item_801EEE68 *)&item)) > 0) {
            ((TObjPlayer *)player)->request_inventory_item((TItemData*)((Item_801EEE68 *)&item));
        }
    }
}

void qst_op_wrap_item() {
    s32 id;
    u32 player;
    Item_801EE77C item;
    void *obj;
    id = ((s32 *)&qst_args)[0];
    obj = find_item_by_id(id);
    if (obj != NULL) {
        ((TItem *)obj)->copy_to_item_data((TItemData *)&item);
    } else {
        return;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != 0) {
        send_6x29_delete_item__10TObjPlayerFPvii((void *)player, (s32)id, 1);
        ((TItemData *)(&item))->set_wrapped();
        if (((TObjPlayer *)player)->can_inventory_accept_item((u8 *)((Item_801EEE68 *)&item)) > 0) {
            ((TObjPlayer *)player)->request_inventory_item((TItemData*)((Item_801EEE68 *)&item));
        }
    }
}

void qst_op_get_item_info() {
    s32 r;
    void *item;
    ItemData_801E8000 d;
    r = qst_args[1];
    item = find_item_by_id(qst_args[0]);
    if (item != NULL) {
        ((TItem *)item)->copy_to_item_data((TItemData *)&d);
        qst_registers[r++] = d.b0;
        qst_registers[r++] = d.b1;
        qst_registers[r++] = d.b2;
        qst_registers[r++] = d.b3;
        qst_registers[r++] = d.b4;
        qst_registers[r++] = d.b5;
        qst_registers[r++] = d.b6;
        qst_registers[r++] = d.b7;
        qst_registers[r++] = d.b8;
        qst_registers[r++] = d.b9;
        qst_registers[r++] = d.b10;
        qst_registers[r++] = d.b11;
    } else {
        qst_registers[r] = -1;
    }
}

void qst_op_item_delete_noreturn() {
    s32 temp_r31;
    u32 ret;

    temp_r31 = qst_args[0];
    ret = get_player_by_client_id(local_client_id);
    if (ret != 0U) {
        send_6x29_delete_item__10TObjPlayerFPvii((void *)ret, (s32)temp_r31, 1);
    }
}

void qst_op_add_damage_to(void) {
    u16 a = qst_args[0];
    f32 b = (f32)qst_args[1];
    void *p = __nw__7TObjectFUl(0x24);
    if (p != 0) {
        fn_80364C40(p, a, (*(s32 *)&tl_03), b);
    }
}

int qst_op_gba_update_dl_graph(void* p) { return get_selected_slot__6TLobbyFv(p); }

int qst_op_gba_destroy_dl_graph(void* p) { return destroy_singleton__6TLobbyFv(p); }

int qst_op_gba_create_dl_graph(void* p) { return init_graph__6TLobbyFv(p); }

void qst_op_enable_movement2() {
    if (get_player_by_client_id((s32)((int) ((u16) qst_args[0]))) != 0U) {
        init_local_pad_binding__10TObjPlayerFv();
    }
}

void qst_op_disable_movement2() {
    if (get_player_by_client_id((s32)((int) ((u16) qst_args[0]))) != 0U) {
        stop_force_if_alive__10TObjPlayerFv();
    }
}

s32 TObjPlayer__sub_80354C7C(u16, void *);
void qst_op_get_palettex_enabled(void) {
    u8 idx = qst_args[2];
    qst_registers[idx] = TObjPlayer__sub_80354C7C(qst_args[0], qst_args);
}

s32 TObjPlayer__sub_80354D5C(u16, void *);
void qst_op_get_palettex_activated(void) {
    u8 idx = qst_args[1];
    qst_registers[idx] = TObjPlayer__sub_80354D5C(qst_args[0], qst_args);
}

void qst_op_disable_palettex(void) {
    TObjPlayer__sub_80354CCC(((u16) qst_args[0]));
}

void qst_op_restore_palettex(void) {
    TObjPlayer__sub_80354DAC(((u16) qst_args[0]));
}

void qst_op_enable_palettex() {
    TObjPlayer__sub_80354D14(((u16) qst_args[0]));
}

void qst_op_activate_palettex() {
    TObjPlayer__sub_80354DF4(((u16) qst_args[0]));
}

s32 TObjPlayer__sub_80354C2C(u16, int);
void qst_op_set_palettex_callback(void) {
    TObjPlayer__sub_80354C2C(qst_args[0], (u16)qst_args[1]);
}

void qst_op_thaw_and_show_equip() {
    void *self = tl_03;
    if (self != NULL) {
        resume_update__7TObjectFv(self);
    }
}

void qst_op_toggle_freeze_and_hide_equip() {
    void *temp = tl_03;
    if (temp != 0) {
        ((TObject *)temp)->toggle_pause();
    }
}

s32 count_items_of_type__10TObjPlayerFScScSc(u32, u8, u8, u8);
void qst_op_get_stackable_item_count(s32 i, s32 dst) {
    u16 a = qst_registers[(u8)i++];
    u8 b = qst_registers[(u8)i++];
    u8 c = qst_registers[(u8)i++];
    u8 d = qst_registers[(u8)i];
    u32 p = get_player_by_client_id(a);
    if (p != 0) {
        qst_registers[(u8)dst] = count_items_of_type__10TObjPlayerFScScSc(p, b, c, d);
    }
}

void qst_op_get_total_deaths() {
    u8 temp_r31;
    temp_r31 = (u8) qst_args[1];
    if (((u32 (*)(int))get_player_by_client_id)((int) (qst_args[0])) != 0U) {
        qst_registers[(u8)temp_r31] = get_card_window_field_244__10TObjPlayerFv();
    }
}

void qst_op_atan2_int(void) {
    u8 temp_r31;
    temp_r31 = (u8) qst_args[0];
    qst_registers[(u8)temp_r31] = (s32) (lbl_80449CC0 * atan2_float((void *) qst_args, (f32) (*(f32 *)&qst_args[1]), (f32) (*(f32 *)&qst_args[2])));
}

void qst_op_tan() {
  s32 arg;
  u8 idx;
  idx = qst_args[0] & 0xFFu;
  arg = qst_args[1];
  f32 v = sin_table_lookup(arg) / cos_table_lookup(arg);
  qst_registers[idx] = *((s32 *) (&v));
}

void qst_op_cos() {
    u8 idx = qst_args[0];
    f32 v = cos_table_lookup(qst_args[1]);
    qst_registers[idx] = *(s32 *)&v;
}

void qst_op_sin() {
    u8 idx = qst_args[0];
    f32 v = sin_table_lookup(qst_args[1]);
    qst_registers[idx] = *(s32 *)&v;
}

void qst_op_fdivi(u8 reg, s32 val) {
    U_801E871C b;
    U_801E871C a;
    a.i = val;
    b.f = *(f32 *)&qst_registers[reg];
    b.f /= a.f;
    qst_registers[reg] = b.i;
}

void qst_op_fdiv(u8 reg, u8 src) {
    U_801E8750 b;
    b.f = *(f32 *)&qst_registers[reg];
    b.f /= *(f32 *)&qst_registers[src];
    qst_registers[reg] = b.i;
}

void qst_op_fmuli(u8 reg, s32 val) {
    U_801E8784 b;
    U_801E8784 a;
    a.i = val;
    b.f = *(f32 *)&qst_registers[reg];
    b.f *= a.f;
    qst_registers[reg] = b.i;
}

void qst_op_fmul(u8 reg, u8 src) {
    U_801E87B8 b;
    b.f = *(f32 *)&qst_registers[reg];
    b.f *= *(f32 *)&qst_registers[src];
    qst_registers[reg] = b.i;
}

void qst_op_fsubi(u8 reg, s32 val) {
    U_801E87EC b;
    U_801E87EC a;
    a.i = val;
    b.f = *(f32 *)&qst_registers[reg];
    b.f -= a.f;
    qst_registers[reg] = b.i;
}

void qst_op_fsub(u8 reg, u8 src) {
    U_801E8820 b;
    b.f = *(f32 *)&qst_registers[reg];
    b.f -= *(f32 *)&qst_registers[src];
    qst_registers[reg] = b.i;
}

void qst_op_faddi(u8 reg, s32 val) {
    U_801E8854 b;
    U_801E8854 a;
    a.i = val;
    b.f = *(f32 *)&qst_registers[reg];
    b.f += a.f;
    qst_registers[reg] = b.i;
}

void qst_op_fadd(u8 reg, u8 src) {
    U_801E8888 b;
    b.f = *(f32 *)&qst_registers[reg];
    b.f += *(f32 *)&qst_registers[src];
    qst_registers[reg] = b.i;
}

void qst_op_float2dec(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] = (s32) *(f32 *)&qst_registers[(u8)arg1];
}

void qst_op_dec2float(u8 reg, u8 src) {
    U_801E8888 b;
    b.f = (f32)qst_registers[src];
    qst_registers[reg] = b.i;
}

void qst_op_check_npc_straggle_ex(u8 i, u8 slot) {
    u8 start = i;
    Vec_801E8930 v;
    Spawn_801E8930 s;
    void *obj;

    ((void (*)(Spawn_801E8930 *))TLobby__sub_80207F30)(&s);
    s.x = qst_registers[i++];
    s.y = qst_registers[i++];
    s.z = qst_registers[i++];
    s.a = qst_registers[i++];
    s.c = qst_registers[i++];
    s.b = qst_registers[i++];
    obj = create_quest_col_apc_inw__6TLobbyFPvPv(&s, &qst_registers[start]);
    if (obj != NULL) {
        v.x = qst_registers[i++];
        v.y = qst_registers[i++];
        v.z = qst_registers[i];
        TLobby__sub_801F3500(obj, &v);
        qst_registers[slot] = (u16)((int (*)(int))get_entity_id)((int)obj);
    }
}

void qst_op_set_obj_param_ex(u8 i, u8 out) {
    Spawn_801E8AE8 s;
    void *obj;
    ((void (*)(Spawn_801E8AE8 *))TLobby__sub_80207F30)(&s);
    s.x = qst_registers[i++];
    s.y = qst_registers[i++];
    s.z = qst_registers[i++];
    s.a = qst_registers[i++];
    s.c = qst_registers[i++];
    s.b = qst_registers[i];
    obj = create_quest_col_alock(&s, &qst_registers[out]);
    if (obj != NULL) {
        qst_registers[out] = get_entity_id(obj);
    }
}

void qst_op_party_coords_call_ex(u8 i, u8 out) {
    Spawn_801E8C14 s;
    void *obj;
    u8 first = i;
    ((void (*)(Spawn_801E8C14 *))TLobby__sub_80207F30)(&s);
    s.x = qst_registers[i++];
    s.y = qst_registers[i++];
    s.z = qst_registers[i++];
    s.a = qst_registers[i++];
    s.b = qst_registers[i++];
    s.c = qst_registers[i];
    obj = fn_80196214(&s, &qst_registers[first]);
    if (obj != NULL) {
        qst_registers[out] = get_entity_id(obj);
    }
}

void qst_op_npc_coords_call_ex(u8 i, u8 out) {
    Spawn_801E8D44 s;
    void *obj;
    u8 first = i;
    ((void (*)(Spawn_801E8D44 *))TLobby__sub_80207F30)(&s);
    s.x = qst_registers[i++];
    s.y = qst_registers[i++];
    s.z = qst_registers[i++];
    s.a = qst_registers[i++];
    s.c = qst_registers[i];
    obj = fn_801963A8(&s, &qst_registers[first]);
    if (obj != NULL) {
        qst_registers[out] = get_entity_id(obj);
    }
}

void qst_op_at_coords_talk_ex(u8 i, u8 out) {
    Spawn_801E8E4C s;
    void *obj;
    u8 first = i;
    ((void (*)(Spawn_801E8E4C *))TLobby__sub_80207F30)(&s);
    s.x = qst_registers[i++];
    s.y = qst_registers[i++];
    s.z = qst_registers[i++];
    s.a = qst_registers[i++];
    s.c = qst_registers[i];
    obj = fn_80196814(&s, &qst_registers[first]);
    if (obj != NULL) {
        qst_registers[out] = get_entity_id(obj);
    }
}

void qst_op_at_coords_call_ex(u8 i, u8 out) {
    Spawn_801E8F54 s;
    void *obj;
    u8 first = i;
    ((void (*)(Spawn_801E8F54 *))TLobby__sub_80207F30)(&s);
    s.x = qst_registers[i++];
    s.y = qst_registers[i++];
    s.z = qst_registers[i++];
    s.a = qst_registers[i++];
    s.c = qst_registers[i];
    obj = create_quest_col(&s, &qst_registers[first]);
    if (obj != NULL) {
        qst_registers[out] = get_entity_id(obj);
    }
}

void qst_op_unfreeze_everything(void) {
    main_task.resume_game_layers();
}

void qst_op_toggle_freeze_everything(void) {
    main_task.toggle_pause_game_layers();
}

void qst_op_unfreeze_enemies() {
    void *temp = tl_04;
    if (temp != 0) {
        resume_update__7TObjectFv(temp);
    }
}

void qst_op_toggle_freeze_enemies() {
    void *temp = tl_04;
    if (temp != 0) {
        ((TObject *)temp)->toggle_pause();
    }
}

void qst_op_npc_text_id(u8 a0, u8 a1, void *a2) {
    s32 x = qst_registers[a0];
    s32 v = qst_registers[a1];
    u16 y = x;
    u32 r = ((u32 (*)(void *, int))qst_label_address)(a2, x);
    if (r != 0U) {
        set_partner_dialogue_override((const char *)r, v, (u16)y);
    }
}

void qst_op_compute_bezier_curve_point() {
    Vec3_801E915C v;
    Glob_801E915C *g = (Glob_801E915C *)qst_args;
    s32 count = g->count;
    f32 f4 = g->f4;
    f32 f8 = g->f8;
    s32 fC = g->fC;
    s32 out = g->out;
    u8 *pts;
    s32 i;
    s32 ret;
    s32 j;
    Vec3_801E915C *dst;
    pts = (u8 *)((u32 (*)(void *, int))qst_label_address)((void *)(u16)g->id, (int)g);
    if (pts == NULL) {
        return;
    }
    for (i = 0; i < count; i++) {
        ((TLobby *)(pts + i * 0x10))->bswap_4x32();
    }
    ret = fn_8034D3D0(pts, f4, count, f8, fC, &v, 100);
    dst = (Vec3_801E915C *)&qst_registers[out];
    dst->x = v.x;
    dst->y = v.y;
    dst->z = v.z;
    *(s32 *)&((f32 *)qst_registers)[out + 3] = ret;
    for (j = 0; j < count; j++) {
        ((TLobby *)(pts + j * 0x10))->bswap_4x32();
    }
    return;
}

void qst_op_get_vector_from_path() {
    Vec3_801E9274 v;
    Glob_801E9274 *g = (Glob_801E9274 *)qst_args;
    s32 count = g->count;
    f32 f4 = g->f4;
    f32 f8 = g->f8;
    s32 fC = g->fC;
    s32 out = g->out;
    u8 *pts;
    s32 i;
    s32 ret;
    s32 j;
    Vec3_801E9274 *dst;
    pts = (u8 *)((u32 (*)(void *, int))qst_label_address)((void *)(u16)g->id, (int)g);
    if (pts == NULL) {
        return;
    }
    for (i = 0; i < count; i++) {
        ((TLobby *)(pts + i * 0x10))->bswap_4x32();
    }
    ret = fn_8034D790(pts, f4, count, f8, fC, &v);
    dst = (Vec3_801E9274 *)&qst_registers[out];
    dst->x = v.x;
    dst->y = v.y;
    dst->z = v.z;
    *(s32 *)&((f32 *)qst_registers)[out + 3] = ret;
    for (j = 0; j < count; j++) {
        ((TLobby *)(pts + j * 0x10))->bswap_4x32();
    }
    return;
}

void qst_op_get_pressed_buttons(u8 a0, u8 a1) {
    qst_registers[a1] = controller_input_state[qst_registers[a0]].f28;
}

void qst_op_get_held_buttons(u8 src, u8 dst) {
    qst_registers[dst] = controller_input_state[qst_registers[src]].f20;
}

int qst_op_default_camera_pos2(void* p) { return reset_to_local_player__11TCameraCtrlFv(p); }

void qst_op_fleti_locked_camera(void) {
    Vec_801E9400 *p = (Vec_801E9400 *)(qst_registers + qst_args[1]);
    Vec_801E9400 v;
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    set_override_position_and_angle__11TCameraCtrlFPUcs(&v, (u16)qst_args[0], p, qst_registers);
}

void qst_op_fleti_fixed_camera() {
    Vec_801E945C a;
    Vec_801E945C b;
    Vec_801E945C *p = (Vec_801E945C *)(qst_registers + qst_args[0]);
    a.x = p[0].x;
    a.y = p[0].y;
    a.z = p[0].z;
    b.x = p[1].x;
    b.y = p[1].y;
    b.z = p[1].z;
    set_fixed_position_and_target__11TCameraCtrlFPUcPUc(&a, &b, p);
}

struct Vec3_801E94CC { f32 x, y, z; };
u32 find_by_id__13TQuestColCtrlFUs(u16);
void qst_op_move_coords_object(s32 i, s32 k) {
    Vec3_801E94CC v;
    v.x = qst_registers[(u8)k++];
    v.y = qst_registers[(u8)k++];
    v.z = qst_registers[(u8)k];
    u32 r = find_by_id__13TQuestColCtrlFUs((u16)qst_registers[(u8)i]);
    if (r != 0) {
        ((TUnk_804B9870 *)r)->set_position_from(&v);
    }
}

void qst_op_close_chat_bubble(s32 arg0) {
    close_windows_by_flags__11TWindowCtrlFUs((int) ((u16) qst_registers[(u8)arg0]), qst_registers);
}

int qst_op_set_screen_bw(void* p) { return TLobby__sub_801F3568(p); }

int qst_op_set_motion_blur() { return set_camera_capture_overlay_alpha((void*)(143)); }

void qst_op_restore_tp(s32 arg0) {
    TLobby__sub_8034DAA0((int) (qst_registers[(u8)arg0]), 0xB, qst_registers);
}

void qst_op_restore_hp(s32 arg0) {
    TLobby__sub_8034DAA0((int) (qst_registers[(u8)arg0]), 0xA, qst_registers);
}

void qst_op_set_slot_zalure(s32 arg0) {
    TLobby__sub_8034DAA0((int) (qst_registers[(u8)arg0]), 9, qst_registers);
}

void qst_op_set_slot_jellen(s32 arg0) {
    TLobby__sub_8034DAA0((int) (qst_registers[(u8)arg0]), 8, qst_registers);
}

void qst_op_set_slot_deband(s32 arg0) {
    TLobby__sub_8034DAA0((int) (qst_registers[(u8)arg0]), 7, qst_registers);
}

void qst_op_set_slot_shifta(s32 arg0) {
    TLobby__sub_8034DAA0((int) (qst_registers[(u8)arg0]), 6, qst_registers);
}

void qst_op_set_slot_confuse(s32 arg0) {
    TLobby__sub_8034DAA0((int) (qst_registers[(u8)arg0]), 5, qst_registers);
}

void qst_op_set_slot_slow(s32 arg0) {
    TLobby__sub_8034DAA0((int) (qst_registers[(u8)arg0]), 4, qst_registers);
}

void qst_op_set_slot_freeze(s32 arg0) {
    TLobby__sub_8034DAA0((int) (qst_registers[(u8)arg0]), 3, qst_registers);
}

void qst_op_set_slot_shock(s32 arg0) {
    TLobby__sub_8034DAA0((int) (qst_registers[(u8)arg0]), 2, qst_registers);
}

void qst_op_set_slot_paralyze(s32 arg0) {
    TLobby__sub_8034DAA0((int) (qst_registers[(u8)arg0]), 1, qst_registers);
}

void qst_op_set_slot_poison(s32 arg0) {
    TLobby__sub_8034DAA0((int) (qst_registers[(u8)arg0]), 0, qst_registers);
}

void qst_op_clear_slot_invincible(s32 arg0) {
    reset_player_lobby_model__10TNpcPlayerFUs((int) ((u16) qst_registers[(u8)arg0]), qst_registers);
}

void qst_op_set_slot_invincible(s32 arg0, s32 arg1) {
    update_player_field__10TNpcPlayerFUsl((int) ((u16) qst_registers[(u8)arg0]), (int) (qst_registers[(u8)arg1]), qst_registers);
}

struct Move_801E989C {
    u16 f0;
    u16 id;
    f32 x;
    f32 z;
    u8 pad[4];
};
void qst_op_run_to_coord(u8 arg0) {
    Move_801E989C m;
    f32 x;
    f32 z;
    u16 id;
    s32 i;

    i = arg0;
    x = qst_registers[i++];
    i++;
    z = qst_registers[i++];
    id = qst_registers[i];
    if (get_player_by_client_id(id) != 0) {
        ((TNpcPlayer *)(&m))->reset_move_state();
        m.id = id;
        m.x = x;
        m.z = z;
        ((TNpcPlayer *)(&m))->reset_model();
    }
}

void qst_op_stop_animation(s32 arg0) {
    end_camera_pan_for_client__10TNpcPlayerFUs((int) ((u16) qst_registers[(u8)arg0]), qst_registers);
}

void qst_op_use_animation(s32 arg0, s32 arg1) {
    apply_to_battle_player_slot__10TNpcPlayerFUss((int) ((u16) qst_registers[(u8)arg0]), (int) ((s16) qst_registers[(u8)arg1]), qst_registers);
}

void reset_random_enemies_mode__6TLobbyFv(void) { TLobby::clear_counter(); evt2_random_enemies_mode = 0; TKeyBoardControl__sub_8000F950(); }

void qst_op_qexit() {
    void *hunter_guild_seq_offline;
    if ((is_quest_active() == 1) && ((hunter_guild_seq_offline = (void*)((u32 (*)(s32))__nw__7TObjectFUl)(0x28)) != 0U)) {
        ((THunterGuildSeqOffline *)hunter_guild_seq_offline)->init((void *)tl_00, (void *)reset_random_enemies_mode__6TLobbyFv);
    }
}

void qst_op_results_window_visible_multi_cm(s32 arg0) {
    if (update_challenge_result_player_locks() != 0) {
        qst_registers[(u8)arg0] = 1;
        return;
    }
    qst_registers[(u8)arg0] = 0;
}

void qst_op_congrats_msg_multi_cm(u8 arg0) {
    s32 i;
    TChallenge4PResult::clear_slot_entries();
    i = 0;
    do {
        TChallenge4PResult::create((u16)i, qst_registers[arg0]);
        i += 1;
    } while (i < 4);
}

void qst_op_start_or_update_gba_joyboot(s32 idx) {
    s32 tbl[5];
    s32 n;
    *(Tbl_801E9AF8 *)tbl = *lobby_index_identity_table_a;
    update_gba_joyboot_transfer();
    n = TLobby__sub_801F34F8();
    if (n >= 0 && n < 5) {
        qst_registers[(u8)idx] = tbl[n];
    } else {
        qst_registers[(u8)idx] = 2;
    }
}

void qst_op_prepare_gba_rom_from_download() { update_alloc_size__6TLobbyFv((void*)0); TLobby::set_send_buffer((u8 *)(*(int *)&gba_download_data_buffer), (s32)((void*)((*(int *)&gba_download_data_size)))); }

void qst_op_get_dl_status(s32 arg0) {
    if (TLobby::get_lobby_count() != 0) {
        qst_registers[(u8)arg0] = 0;
        return;
    }
    if (TLobby::get_field_6CE8() != 0) {
        qst_registers[(u8)arg0] = 2;
        return;
    }
    qst_registers[(u8)arg0] = 1;
}

void qst_op_file_dl_req(void) {
    fn_801DA140(TLobby__protocol_instance, (int) ((u8) qst_args[0]), (int) (qst_args[1]));
    TLobby__sub_801F3614();
    TLobby__sub_8032CDEC();
}

void qst_op_set_episode(s32 arg0) {
    switch (arg0) {
    case 0:
        TAdStorySelectGC::set_state(0);
        return;
    case 1:
        TAdStorySelectGC::set_state(1);
        return;
    default:
        TAdStorySelectGC::set_state(0);
        return;
    }
}

int qst_op_write_flag_buf_to_event_flags2(void* p) { return ((int (*)(void*))qst_op_write_flag_buf_to_event_flags)(p); }

void qst_op_load_guild_card_file_creation_time_to_flag_buf() {
    s32 var_r0;
    void *temp_r3;

    temp_r3 = get_state__23TAdSinglePlyChrSelectGCFv();
    if (temp_r3 != NULL) {
        var_r0 = *(s32 *)((s8 *)temp_r3 + 0xE284);
    } else {
        var_r0 = 0;
    }
    (*(s32 *)&TLobby__data_805D5EC4) = var_r0;
}

void qst_op_chl_show_dead_player_list() {
    if (is_split_screen() == 1) {
        update_screen__6TLobbyFv();
        return;
    }
    TLobby::update_dead_list_win();
}

void qst_op_disable_retry_menu() {
    if (is_split_screen() == 1) {
        set_challenge_split_flag__6TLobbyFv();
        return;
    }
    set_split_screen_flag__6TLobbyFv();
}

void qst_op_chl_set_min_time_online(s32 arg0) {
    if (is_split_screen() == 1) {
        TLobby__sub_80291DF8((int) (qst_registers[(u8)arg0]));
        return;
    }
    TLobby__sub_80070B34((int) (qst_registers[(u8)arg0]));
}

void qst_op_check_for_hacking(u8 out) {
    u32 *p;
    s16 i;
    u8 *player;
    qst_registers[out] = 0;
    p = (u32 *)0x8C007220;
    for (i = 0; i < 0xC0U; i++) {
        if (*p++ != 0) {
            qst_registers[out] |= 1;
        }
    }
    if (fn_80077790() == 1) {
        qst_registers[out] |= 2;
    }
    if (fn_80077788() == 1) {
        qst_registers[out] |= 4;
    }
    if (TLobby::get_drop_flag() == 1) {
        qst_registers[out] |= 8;
    }
    player = ((u8 *)((u32 (*)(int))get_player_by_client_id)(local_client_id));
    if (player != NULL && TObjPlayer__sub_801BFFA0(player + 0x41C) != 0) {
        qst_registers[out] |= 0x10;
    }
}
}

void qst_op_write4(void) {
    **(s32 **)&qst_args[0] = qst_args[1];
}

void qst_op_write2(void) {
    **(s16 **)&qst_args[0] = (s16) qst_args[1];
}

void qst_op_write1(void) {
    **(s8 **)&qst_args[0] = (s8) qst_args[1];
}

void qst_op_read4(void) {
    qst_registers[(u8)qst_args[0]] = *(s32 *)((s8 *)(*(s32 **)&qst_args[1]) + 0);
}

void qst_op_read2(void) {
    qst_registers[(u8)qst_args[0]] = (s32) *(s16 *)((s8 *)(*(s16 **)&qst_args[1]) + 0);
}

extern "C" {
void qst_op_read1() {
    qst_registers[(u8)qst_args[0]] = (s32) (s8) *(u8 *)((s8 *)(*(u8 **)&qst_args[1]) + 0);
}

void qst_op_someone_has_spoken(s32 arg0) {
    if (strcmp((void *)(get_unit_list__6TLobbyFv()), (void *) (&TLobby__data_805DC4A0)) == 0) {
        qst_registers[(u8)arg0] = 0;
        return;
    }
    qst_registers[(u8)arg0] = 1;
}

void qst_op_party_has_name(s32 arg0) {
    if (strcmp((void *)(TLobby__sub_80070ACC()), (void *) (&TLobby__data_805DC4A0)) == 0) {
        qst_registers[(u8)arg0] = 0;
        return;
    }
    qst_registers[(u8)arg0] = 1;
}

void qst_op_get_number_of_players2(int a0) { qst_registers[(unsigned char)(a0)] = TLobby::get_game_mode(); }

u8 *TWindowSubStatusDisp__sub_8006F134(s32, s32);
s32 get_slot_clamped__6TLobbyFv(int);
void qst_op_get_cmode_prize_rank(s32 arg0) {
    u32 character_save_record;

    character_save_record = get_character_save_record(0xFFFF);
    if (character_save_record != 0U) {
        qst_registers[(u8)arg0] = get_slot_clamped__6TLobbyFv((int) (*(s32 *)((s8 *)(TWindowSubStatusDisp__sub_8006F134(character_save_record + 0x21C4, -1)) + 4)));
    }
}

void qst_op_get_ba_record(u8 i) {
    Card_801EA0F0 *card = (Card_801EA0F0 *)get_character_save_record(0xFFFF);
    if (card != NULL) {
        qst_registers[i++] = card->stats[0];
        qst_registers[i++] = card->stats[1];
        qst_registers[i++] = card->stats[2];
        qst_registers[i++] = card->stats[3];
        qst_registers[i++] = card->stats[4];
        qst_registers[i++] = card->stats[5];
        qst_registers[i] = card->stats[6];
    }
}

void qst_op_is_there_grave_message(s32 arg0) {
    u32 character_save_record;
    character_save_record = get_character_save_record(0xFFFFU);
    if (character_save_record != 0U) {
        if (strncmp((void *) (character_save_record + 0x2254), (void *) (&TLobby__data_805DC4A0), 0x20) == 0) {
            qst_registers[(u8)arg0] = 0;
            return;
        }
        qst_registers[(u8)arg0] = 1;
        return;
    }
    qst_registers[(u8)arg0] = 0;
}

void qst_op_vol_opt_is_dead(s32 arg0) {
    if ((s32) volopt_death_active != 0) {
        qst_registers[(u8)arg0] = 1;
        return;
    }
    qst_registers[(u8)arg0] = 0;
}

void qst_op_ba_death_tech_level_up(void) {
    if ((u32) (u32)qst_args[0] <= 0x1DU) {
        battle_rules.death_tech_level_up = (s16) (u32)qst_args[0];
    }
}
}

void qst_op_set_shrink_size(s32 player_variable, s32 size_variable) {
    TObjPlayer* player = ((TObjPlayer*)((s32 (*)(int, void *))get_player_by_client_id)((int)(qst_registers[(u8)player_variable]), (void *)size_variable));
    if (player && !obj_isState2_324__13TUnk_804806E8Fv(player)) {
        s32 whole = qst_registers[(u8)size_variable++];
        s32 numerator = qst_registers[(u8)size_variable++];
        s32 denominator = qst_registers[(u8)size_variable];
        ((TObjPlayer *)(&player->scale_state))->set_speed(denominator > 0 ? (f32)whole + (f32)numerator / (f32)denominator : (f32)whole);
    }
}

extern "C" {
void qst_op_set_symbol_chat_collision(u8 i) {
    Spawn_801EA388 s;
    TLobby__sub_80207F30((Spawn_801EA508 *)&s);
    s.x = qst_registers[i++];
    s.y = qst_registers[i++];
    s.z = qst_registers[i++];
    s.a = qst_registers[i++];
    s.c = qst_registers[i++];
    s.d = qst_registers[i++];
    s.e = qst_registers[i++];
    symbolchat_colli_param_table[0] = ((int (*)(int))qst_label_address)((u16)qst_registers[i++]);
    symbolchat_colli_param_table[1] = ((int (*)(int))qst_label_address)((u16)qst_registers[i++]);
    symbolchat_colli_param_table[2] = ((int (*)(int))qst_label_address)((u16)qst_registers[i]);
    TOSymbolchatColli::create(&s);
    symbolchat_colli_param_table[1] = 0;
    symbolchat_colli_param_table[0] = 0;
    symbolchat_colli_param_table[2] = 0;
}

void qst_op_set_chat_callback_no_filter(u8 i) {
    Spawn_801EA508 s;
    TLobby__sub_80207F30(&s);
    s.f18 = 0;
    s.f1c = 1;
    s.x = qst_registers[i++];
    s.y = qst_registers[i++];
    s.z = qst_registers[i++];
    s.a = qst_registers[i++];
    s.c = qst_registers[i];
    TOChatSensor__create((s32)&s);
}

void qst_op_write_flag_buf_to_event_flags(u8 arg0) {
    s32 idx = qst_registers[arg0];
    Ctx_801EA5FC *w = get_global_state__23TAdSinglePlyChrSelectGCFv();
    if (w != NULL && idx >= 0 && idx < 0xFD) {
        ((TLobby *)(&w->buf[idx]))->move_data(&TLobby__data_805D5EC4, 4);
    }
}

void qst_op_load_serial_number_to_flag_buf() {
    u32 temp_r3;

    temp_r3 = get_serial_access__22TQuestVmDownLoadServerFv();
    TLobby__data_805D5EC4 = temp_r3;
    if (temp_r3 == 0U) {
        TLobby__data_805D5EC4 = poll_serial_access__22TQuestVmDownLoadServerFv();
    }
}

void qst_op_is_bosswarp_opt_disabled(s32 arg0) {
    if (is_split_screen() == 1) {
        if (TLobby::get_normalized_mode() != 0) {
            qst_registers[(u8)arg0] = 1;
            return;
        }
        qst_registers[(u8)arg0] = 0;
        return;
    }
    if (TLobby::get_state() != 0) {
        qst_registers[(u8)arg0] = 1;
        return;
    }
    qst_registers[(u8)arg0] = 0;
}

void qst_op_enable_bosswarp_option() {
    if (is_split_screen() == 1) {
        TLobby__sub_80291EAC(0);
        return;
    }
    TLobby__sub_80070BE8(0);
}

void qst_op_disable_bosswarp_option() {
    if (is_split_screen() == 1) {
        TLobby__sub_80291EAC(1);
        return;
    }
    TLobby__sub_80070BE8(1);
}

void qst_op_player_recovery(s32 arg0) {
    s32 temp_r3;
    temp_r3 = ((s32 (*)(int, void *))get_player_by_client_id)((int) (qst_registers[(u8)arg0]), qst_registers);
    if (temp_r3 != 0) {
        send_code_49_1__10TObjPlayerFi();
        send_code50_packet__10TObjPlayerFi((temp_r3));
    }
}

void qst_op_ba_forbid_scape_dolls() {
    u32 v = (u32)qst_args[0];
    if (v < 2) {
        battle_rules.forbid_scape_dolls = lbl_80449B10[v];
    }
}

void qst_op_chl_create_retry_menu() {
    if (is_split_screen() == 1) {
        TLobby::draw_if_ready2();
        return;
    }
    TLobby::draw_if_ready();
}

void qst_op_get_chl_retry_choice(s32 arg0) {
    s32 var_r3;
    if (is_split_screen() == 1) {
        var_r3 = TLobby::check_ready_status();
    } else {
        var_r3 = TLobby::check_ready_state();
    }
    switch (var_r3) {
    case -1:
        qst_registers[(u8)arg0] = 0;
        return;
    case 0:
        qst_registers[(u8)arg0] = 1;
        return;
    case 1:
        qst_registers[(u8)arg0] = 2;
        return;
    }
}

void qst_op_reset_map(void) {
    TLobby__sub_801036CC();
    if ((u32) quest_mission_manager != 0U) {
        clear_buffer__12TQuestThreadFPv(quest_mission_manager);
    }
    destroy_children_with_tag(tl_00);
    TLobby::init_sub_objects();
    TLobby::reset_id_tables();
    clear_floor_event_flags();
    init_switch_table();
    TRaderMapCore::free_map_data();
    if (is_split_screen() == 1) {
        TLobby::reset_menu_state_globals();
        return;
    }
    TLobby__sub_80070C50();
}

void qst_op_get_random(s32 arg0, s32 arg1) {
  s32 temp_r31;
  s32 var_r4;
  s32 temp_r30;
  temp_r31 = qst_registers[(u8)arg0];
  temp_r30 = qst_registers[(u8)(arg0 + 1)];
  var_r4 = (s32) (((f32) temp_r30) * (lbl_805DC4C8 * ((f32) rand())));
  if (var_r4 < temp_r31)
  {
    var_r4 = temp_r31;
  }
  qst_registers[(u8)arg1] = var_r4;
}
}

void qst_op_shift_right(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] >>= qst_registers[(u8)arg1];
}

void qst_op_shift_left(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] <<= qst_registers[(u8)arg1];
}

extern "C" {
void qst_op_get_eventflag32(u8 a0, u8 a1) {
    s32 v;
    qst_registers[a1] = 0;
    Ctx_801EAA34 *w = ((Ctx_801EAA34 *)get_global_state__23TAdSinglePlyChrSelectGCFv());
    if (w != NULL) {
        s32 i = qst_registers[a0];
        if (i >= 0 && i < 0xFD) {
            memcpy(&v, &w->buf[i], 4);
            qst_registers[a1] = v;
        }
    }
}

void qst_op_get_eventflag16(u8 a0, u8 a1) {
    s16 v;
    qst_registers[a1] = 0;
    Ctx_801EAAB4 *w = ((Ctx_801EAAB4 *)get_global_state__23TAdSinglePlyChrSelectGCFv());
    if (w != NULL) {
        s32 i = qst_registers[a0];
        if (i >= 0 && i < 0xFF) {
            memcpy(&v, &w->buf[i], 2);
            qst_registers[a1] = v;
        }
    }
}

void qst_op_set_enemy_movement_data(s32 arg0) {
    ByteBlock_30 sp8;
    u32 temp_r3;
    temp_r3 = ((int (*)(int))qst_label_address)(arg0);
    if (temp_r3 != 0U) {
        sp8 = *(const ByteBlock_30 *)(temp_r3 - 4 + 4);
        TLobby::bswap_entry_words((s32) &sp8);
        TLobby::broadcast(&sp8);
    }
}

void qst_op_set_enemy_resist_data(s32 arg0) {
    ByteBlock_20 sp8;
    u32 temp_r3;
    temp_r3 = ((int (*)(int))qst_label_address)(arg0);
    if (temp_r3 != 0U) {
        sp8 = *(const ByteBlock_20 *)(temp_r3 - 4 + 4);
        ((TLobby *)(&sp8))->swap_endian();
        TLobby__sub_8001DE30(&sp8);
    }
}

void qst_op_set_enemy_attack_data(s32 arg0) {
    ByteBlock_30 sp8;
    u32 temp_r3;
    temp_r3 = ((int (*)(int))qst_label_address)(arg0);
    if (temp_r3 != 0U) {
        sp8 = *(const ByteBlock_30 *)(temp_r3 - 4 + 4);
        ((TLobby *)(&sp8))->byteswap_packet();
        TLobby::copy_all_entries(&sp8);
    }
}

void qst_op_set_enemy_physical_data(int _w0) {
    struct CopyStack_801EAC48 { u8 bytes[0x24]; };
    CopyStack_801EAC48 copy_storage_801EAC48;
    u32 temp_r3;
    temp_r3 = ((u32)((int (*)(int))qst_label_address)(_w0));
    if (temp_r3 != 0U) {
        *(ByteBlock_24 *)(copy_storage_801EAC48.bytes) = *(const ByteBlock_24 *)((temp_r3 - 4) + 4);
        bswap__12player_statsFv(((copy_storage_801EAC48.bytes)));
        TLobby::copy_data((void *) ((copy_storage_801EAC48.bytes)));
    }
}

void qst_op_set_override_enemy_bp_index() {
    TLobby__sub_8001DEA8((qst_args[0]));
}

void qst_op_set_chat_callback() {
    Spawn_801EACD8 s;
    u8 i = (u32)qst_args[0];
    s32 arg = qst_args[1];
    void *sensor;
    TLobby__sub_80207F30((Spawn_801EA508 *)(&s));
    s.x = qst_registers[i++];
    s.y = qst_registers[i++];
    s.z = qst_registers[i++];
    s.a = qst_registers[i++];
    s.c = qst_registers[i];
    sensor = (void *)TOChatSensor__create((s32)((Spawn_801EA508 *)(&s)));
    if (sensor != NULL) {
        ((TOChatSensor *)sensor)->set_trigger_text((void *)arg);
    }
}

void qst_op_set_cmode_grave_rates(s32 reg) {
    f32 params[10];
    s32 *p = &qst_registers[(u8)reg];
    f32 num, den, ratio;
    num = p[0];
    den = p[1];
    ratio = num / den;
    params[0] = ratio;
    num = p[2];
    den = p[3];
    ratio = num / den;
    params[1] = ratio;
    num = p[4];
    den = p[5];
    ratio = num / den;
    params[2] = ratio;
    num = p[6];
    den = p[7];
    ratio = num / den;
    params[3] = ratio;
    num = p[8];
    den = p[9];
    ratio = num / den;
    params[4] = ratio;
    num = p[10];
    den = p[11];
    ratio = num / den;
    params[5] = ratio;
    num = p[12];
    den = p[13];
    ratio = num / den;
    params[6] = ratio;
    num = p[14];
    den = p[15];
    ratio = num / den;
    params[7] = ratio;
    num = p[16];
    den = p[17];
    ratio = num / den;
    params[8] = ratio;
    num = p[18];
    den = p[19];
    ratio = num / den;
    params[9] = ratio;
    TObjTombstone__sub_80074E74(params);
}

void qst_op_chl_get_timerecord(s32 arg0) {
    if (is_split_screen() == 1) {
        qst_registers[(u8)arg0] = TLobby__sub_8029204C();
        return;
    }
    qst_registers[(u8)arg0] = TLobby::get_max_challenge_time();
}

void qst_op_chl_set_timerecord(s32 arg0) {
    if (is_split_screen() == 1) {
        TLobby__sub_80292200((int) (qst_registers[(u8)arg0]));
        return;
    }
    TLobby__sub_80070EE4((int) (qst_registers[(u8)arg0]));
}

void qst_op_get_game_version(s32 arg0) {
    qst_registers[(u8)arg0] = 3;
}

void qst_op_send_mail(void) {
    Tag_801EB10C tag;
    char buf[0x400];
    Card_801EB10C *card;
    u8 i = (u32)qst_args[0];
    char *src = *(char **)&qst_args[1];
    ((TLobby *)((s32)&tag))->init_guild_card_tag();
    card = (Card_801EB10C *)__nw__7TObjectFUl(0x10A8);
    if (card != NULL) {
        card = construct__13TUnk_804CC048FPvPvPv(card, 0, 0, 0);
    }
    strncpy(buf, (int)src, 0x3FF);
    ((TLobby *)buf)->trim_whitespace();
    ((TLobby *)card)->tokenize_args(buf);
    if (*(s32 *)((u8 *)card + 0x109C) > 2) {
        if (card != NULL) {
            card->m0(1);
        }
    } else {
        tag.id = qst_registers[i];
        strncpy(tag.name, (int)((u8 *)card + 0x1C), 0xF);
        tag.name[0xF] = 0;
        strncpy(tag.text, (int)((u8 *)card + 0x3C), 0x1FF);
        tag.text[0x1FF] = 0;
        try_close__6TLobbyFPv(&tag);
        if (card != NULL) {
            card->m0(1);
        }
    }
}

s32 TLobby::init_guild_card_tag() {
    s32 arg0 = (s32)this;
    __ct__16TPlyGuildCardTagFv(arg0 + 4);
    return arg0;
}

void qst_op_get_player_state(s32 arg0, s32 arg1) {
    s32 temp_r3;
    temp_r3 = ((s32 (*)(int, void *))get_player_by_client_id)((int)(qst_registers[(u8)arg0]), (void *)arg1);
    if (temp_r3 != 0) {
        if (TLobby__sub_801F345C() != 0) {
            qst_registers[(u8)arg1] = 1;
            return;
        }
        if (set_flag_4__6TLobbyFPv((void *)temp_r3) != 0) {
            qst_registers[(u8)arg1] = 2;
            return;
        }
        if (((TLobby *)temp_r3)->test_flag_16() != 0) {
            qst_registers[(u8)arg1] = 3;
            return;
        }
        if (TLobby__sub_801F33F0((void *)temp_r3) != 0) {
            qst_registers[(u8)arg1] = 4;
            return;
        }
        if (TLobby__sub_801F33CC((void *)temp_r3) != 0) {
            qst_registers[(u8)arg1] = 5;
            return;
        }
        if (TLobby__sub_801F33A8((void *)temp_r3) != 0) {
            qst_registers[(u8)arg1] = 6;
            return;
        }
        if (TLobby__sub_801F3384((void *)temp_r3) != 0) {
            qst_registers[(u8)arg1] = 7;
            return;
        }
        if (((TLobby *)temp_r3)->check_flag_24576() != 0) {
            qst_registers[(u8)arg1] = 8;
            return;
        }
        if (set_flag_8000__6TLobbyFv(temp_r3) != 0) {
            qst_registers[(u8)arg1] = 9;
            return;
        }
        if (TLobby__sub_801F3314(temp_r3) != 0) {
            qst_registers[(u8)arg1] = 0xA;
            return;
        }
        if (set_flag_40000__6TLobbyFv(temp_r3) != 0) {
            qst_registers[(u8)arg1] = 0xB;
            return;
        }
        if (set_flag_80000__6TLobbyFv(temp_r3) != 0) {
            qst_registers[(u8)arg1] = 0xC;
            return;
        }
        qst_registers[(u8)arg1] = 0;
        return;
    }
    qst_registers[(u8)arg1] = 0;
}

void qst_op_disable_win_pfx(void) { TLobby__battle_ctrl_default_value = 0; }

void qst_op_enable_win_pfx(void) { TLobby__battle_ctrl_default_value = 1; }

void qst_op_ba_get_score(u8 src, u8 dst) {
    E_801EB484 e = TLobby__duel_result_table[qst_registers[src]];
    qst_registers[dst] = e.b;
}

void qst_op_ba_get_place(u8 a0, u8 a1) {
    E_801EB4C4 e = ((E_801EB4C4 *)&TLobby__duel_result_table)[qst_registers[a0]];
    qst_registers[a1] = e.b;
}

void qst_op_set_eventflag32() {
    u32 i = (u32)qst_args[0];
    s32 v = qst_args[1];
    Ctx_801EB508 *w = ((Ctx_801EB508 *)((s32 (*)(void))get_global_state__23TAdSinglePlyChrSelectGCFv)());
    if (w != NULL && i < 0xFD) {
        ((TLobby *)(&w->buf[i]))->move_data(&v, 4);
    }
}

int qst_op_turn_on_bgm_p2(void *p) { return TLobby__sub_802272B4(p); }

int qst_op_turn_off_bgm_p2(void* p) { return TLobby__sub_8022733C(p); }

void qst_op_nop_F8EF(void) {  }

void qst_op_call_image_data() {
    s32 quest_vm_down_load_server;
    u32 temp_r3;
    quest_vm_down_load_server = qst_args[0];
    temp_r3 = ((int)((u32 (*)(void *))qst_label_address)((void *)((s32) (u16) qst_args[1])));
    if (temp_r3 != 0U) {
        prs_decompress_buffer((s32) temp_r3, resource_decompress_buffer);
        fn_80197FD0((void *)resource_decompress_buffer, (void *)quest_vm_down_load_server);
    }
}

void qst_op_animation_check(s32 arg0, s32 arg1) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(((s32)((u32 (*)(int, int))get_player_by_client_id)((int)((u32) (u16) qst_registers[(u8)arg0]), (int)(arg1))));
    if (temp_r3 != NULL) {
        qst_registers[(u8)arg1] = TLobby__sub_80142944(temp_r3);
    }
}

void qst_op_set_eventflag16() {
    u32 i = (u32)qst_args[0];
    s16 v = qst_args[1];
    Ctx_801EB658 *w = ((Ctx_801EB658 *)((s32 (*)(void))get_global_state__23TAdSinglePlyChrSelectGCFv)());
    if (w != NULL && i < 0xFF) {
        ((TLobby *)(&w->buf[i]))->move_data(&v, 2);
    }
}

void qst_op_get_pl_job(s32 arg0) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(((u8 *)((u32 (*)(int, int))get_player_by_client_id)((int)qst_registers[(u8)arg0], (int)qst_registers)));
    if (temp_r3 != NULL) {
        strncpy((void *) (&quest_player_class_name_buffer.value), (int) (get_class_type_name__6TLobbyFl((int) (((TObjPlayer *)temp_r3)->class_flags))), 0xF);
        *(s8 *)((s8 *)(&quest_player_class_name_buffer.value) + 0xF) = 0;
        qst_registers[(u8)arg0] = 1;
        return;
    }
    qst_registers[(u8)arg0] = 0;
}

void qst_op_get_pl_name(s32 arg0) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(((u8 *)((u32 (*)(int, int))get_player_by_client_id)((int)qst_registers[(u8)arg0], (int)qst_registers)));
    if (temp_r3 != NULL) {
        strncpy(((void *)(&quest_player_name_buffer.value)), (int)((TObjPlayer *)temp_r3)->get_name(), 0xF);
        *(s8 *)((s8 *)(&quest_player_name_buffer.value) + 0xF) = 0;
        qst_registers[(u8)arg0] = 1;
        return;
    }
    qst_registers[(u8)arg0] = 0;
}

void qst_op_set_trap_damage(s32 i) {
    s32 j = i + 1;
    TOMineTrap__sub_80171368((f32)qst_registers[(u8)i] + (f32)qst_registers[(u8)j] / (f32)qst_registers[(u8)++j]);
}

void qst_op_get_eventflag(s32 arg0, s32 arg1) {
    u8 *flags;
    s32 *regs;
    s32 index;
    flags = (u8 *)((s32 (*)(void))get_global_state__23TAdSinglePlyChrSelectGCFv)();
    if (flags != NULL) {
        regs = qst_registers;
        index = regs[(u8)arg0];
        if (index >= 0 && index < 0x100) {
            regs[(u8)arg1] = flags[index + 0x10];
        }
    }
}

void qst_op_get_serial_number(u8 arg0) {
    qst_registers[arg0] = ((s32 (*)(void))get_serial_access__22TQuestVmDownLoadServerFv)();
    if (qst_registers[arg0] == 0) {
        qst_registers[arg0] = ((s32 (*)(void))poll_serial_access__22TQuestVmDownLoadServerFv)();
    }
}

void qst_op_kill_player(s32 arg0) {
    if (((u32 (*)(int, int))get_player_by_client_id)((int)(qst_registers[(u8)arg0]), (int)qst_registers) != 0U) {
        TObjPlayer__sub_801AF904();
    }
}

void qst_op_get_guild_card_file_creation_time(s32 arg0) {
    u8 *temp_r3;
    temp_r3 = ((u8 * (*)(void))get_state__23TAdSinglePlyChrSelectGCFv)();
    if (temp_r3 != NULL) {
        qst_registers[(u8)arg0] = *(s32 *)((s8 *)temp_r3 + 0xE284);
        return;
    }
    qst_registers[(u8)arg0] = 0;
}

s32 try_spend_actor_meseta(u8 *arg0, s32 arg1);
void qst_op_take_slot_meseta(s32 arg0, s32 arg1) {
    u32 p = get_player_by_client_id(qst_registers[(u8)arg0++]);
    if (p != 0) {
        if (try_spend_actor_meseta((u8 *)p, qst_registers[(u8)arg0]) != 0) {
            qst_registers[(u8)arg1] = 1;
        } else {
            qst_registers[(u8)arg1] = 0;
        }
    } else {
        qst_registers[(u8)((u8)arg1 + 1)] = 0;
    }
}

void qst_op_get_chara_class(s32 arg0, s32 arg1) {
    u8 *p = ((u8 * (*)(s32))get_player_by_client_id)(qst_registers[(u8)arg0]);
    if (p != NULL) {
        s32 f = ((TObjPlayer *)p)->class_flags;
        if (f & CLASS_FLAG_HUMAN) {
            qst_registers[(u8)arg1] = RACE_HUMAN;
        } else if (f & CLASS_FLAG_NEWMAN) {
            qst_registers[(u8)arg1] = RACE_NEWMAN;
        } else if (f & CLASS_FLAG_ANDROID) {
            qst_registers[(u8)arg1] = RACE_ANDROID;
        } else {
            qst_registers[(u8)arg1] = RACE_NONE;
        }
        if (f & CLASS_FLAG_HUNTER) {
            qst_registers[(u8)(arg1 + 1)] = CLASS_TYPE_HUNTER;
        } else if (f & CLASS_FLAG_RANGER) {
            qst_registers[(u8)(arg1 + 1)] = CLASS_TYPE_RANGER;
        } else if (f & CLASS_FLAG_FORCE) {
            qst_registers[(u8)(arg1 + 1)] = CLASS_TYPE_FORCE;
        } else {
            qst_registers[(u8)(arg1 + 1)] = CLASS_TYPE_NONE;
        }
    } else {
        qst_registers[(u8)arg1++] = RACE_NONE;
        qst_registers[(u8)arg1] = CLASS_TYPE_NONE;
    }
}

void qst_op_get_gender(s32 arg0, s32 arg1) {
    s32 temp_r3_2;
    u8 *temp_r3;
    temp_r3 = ((u8 *)((u32 (*)(int, int))get_player_by_client_id)((int)(qst_registers[(u8)arg0]), (int)(arg1)));
    if (temp_r3 != NULL) {
        temp_r3_2 = ((TObjPlayer *)temp_r3)->class_flags;
        if (temp_r3_2 & CLASS_FLAG_MALE) {
            qst_registers[(u8)arg1] = GENDER_MALE;
            return;
        }
        if (temp_r3_2 & CLASS_FLAG_FEMALE) {
            qst_registers[(u8)arg1] = GENDER_FEMALE;
            return;
        }
        qst_registers[(u8)arg1] = GENDER_NONE;
        return;
    }
    qst_registers[(u8)arg1] = GENDER_NONE;
}

void qst_op_disable_techs(s32 arg0) {
    u32 temp_r3;
    temp_r3 = ((u32 (*)(int, int))get_player_by_client_id)((int)(qst_registers[(u8)arg0]), (int)qst_registers);
    if (temp_r3 != 0U) {
        TLobby__sub_801F3694((void *)(temp_r3 + 0x428));
    }
}

void qst_op_enable_techs(s32 arg0) {
    u32 temp_r3;
    temp_r3 = ((u32 (*)(int, int))get_player_by_client_id)((int)(qst_registers[(u8)arg0]), (int)qst_registers);
    if (temp_r3 != 0U) {
        TFontSmallLobby__sub_801C013C((void *)(temp_r3 + 0x428));
    }
}

void qst_op_disable_stealth_suit_effect(s32 arg0) {
    s32 temp_r3;
    temp_r3 = ((s32)((u32 (*)(int, int))get_player_by_client_id)((int)(qst_registers[(u8)arg0]), (int)qst_registers));
    if ((temp_r3 != 0) && (sub_801A1DDC__10TObjPlayerFv() != 0)) {
        draw_small_label__15TFontSmallLobbyFi((temp_r3));
    }
}

void qst_op_enable_stealth_suit_effect(s32 arg0) {
    s32 temp_r3;
    temp_r3 = ((s32)((u32 (*)(int, int))get_player_by_client_id)((int)(qst_registers[(u8)arg0]), (int)qst_registers));
    if ((temp_r3 != 0) && (sub_801A1DDC__10TObjPlayerFv() != 0)) {
        TLobby__sub_801B1254((temp_r3));
    }
}

void qst_op_set_cmode_rank_override(void) {
    char buf[0x200];
    Card_801EBD40 *card;
    s32 arg = (u32)qst_args[0];
    char *src = *(char **)&qst_args[1];
    card = (Card_801EBD40 *)__nw__7TObjectFUl(0x10A8);
    if (card != NULL) {
        card = ((Card_801EBD40 *)construct__13TUnk_804CC048FPvPvPv(card, 0, 0, 0));
    }
    strncpy(buf, (int)src, 0x1FF);
    ((TLobby *)buf)->trim_whitespace();
    ((TLobby *)card)->tokenize_args((char *)(buf));
    if (*(s32 *)((u8 *)card + 0x109C) == 2) {
        if (is_split_screen() == 1) {
            TLobby__sub_80292268((u8 *)card + 0x1C, (u8 *)card + 0x3C, arg);
        } else {
            add_entry__6TLobbyFiii((u8 *)card + 0x1C, (u8 *)card + 0x3C, arg);
        }
    }
    if (card != NULL) {
        card->m0(1);
    }
}

void qst_op_dark_falz_is_dead(s32 arg0) {
    if (TLobby::is_boss_phase_reached() != 0) {
        qst_registers[(u8)arg0] = 1;
        return;
    }
    qst_registers[(u8)arg0] = 0;
}

int qst_op_ba_clear_trapself(void) { return set_trap_count__10TOMineTrapFi((void*)(0)); }

int qst_op_ba_set_trapself() { return set_trap_count__10TOMineTrapFi((void*)(1)); }

void qst_op_award_item_ok(int a0) { TLobby__menu_state_object = create__16TObjItemOKWindowFPv((void*)tl_01); qst_registers[(unsigned char)(a0)] = 0; TLobby__active_window_index = a0; TLobby__quest_window_state = 11; }

void qst_op_ba_set_box_drop_area(s32 arg0) {
    create_instance__12TItemDropSubFl((int) (qst_registers[(u8)arg0]), qst_registers);
}

void qst_op_item_create_cmode(u8 arg0, u8 arg1) {
    Item_801EBF30 item;
    ((s32 (*)(void *))init__9TItemDataFv)((void *)(&item));
    item.data[0] = qst_registers[(u8)arg0++];
    item.data[1] = qst_registers[(u8)arg0++];
    item.data[2] = qst_registers[(u8)arg0++];
    item.data[3] = qst_registers[(u8)arg0++];
    item.data[4] = qst_registers[(u8)arg0++];
    item.data[5] = qst_registers[(u8)arg0];
    item.id = advance_item_id_counter(local_client_id);
    if (is_split_screen() == 1) {
        if (TLobby__sub_802924B4(&item, 0) != 0) {
            qst_registers[arg1] = 1;
        } else {
            qst_registers[arg1] = 0;
        }
    } else {
        if (TLobby__sub_800710D8(&item) != 0) {
            qst_registers[arg1] = 1;
        } else {
            qst_registers[arg1] = 0;
        }
    }
}

void qst_op_check_rank_time(u8 arg0, u8 arg1) {
    s32 r;
    if (is_split_screen() == 1) {
        r = TLobby__sub_80292270(qst_registers[arg0], 0);
    } else {
        r = TLobby__sub_8007119C(qst_registers[arg0]);
    }
    switch (r) {
    case 2:
        qst_registers[arg1] = 2;
        break;
    case 1:
        qst_registers[arg1] = 1;
        break;
    case 0:
        qst_registers[arg1] = 0;
        break;
    case -1:
        qst_registers[arg1] = 3;
        break;
    case -2:
        qst_registers[arg1] = 4;
        break;
    case -3:
        qst_registers[arg1] = 5;
        break;
    case -4:
    default:
        qst_registers[arg1] = 6;
        break;
    }
}

void qst_op_get_player_proximity(u8 arg0, u8 arg1) {
    s32 idx;
    f32 range;
    u8 *self;
    u8 *other;
    s32 field;
    s32 i;
    idx = qst_registers[arg0++];
    range = qst_registers[arg0];
    qst_registers[arg1] = 0;
    self = (u8 *)((s32 (*)(int))get_player_by_client_id)(idx);
    if (self != NULL) {
        field = ((TObjPlayer *)self)->get_field_3e4();
        for (i = 0; i < 12; i++) {
            if (i != idx) {
                other = (u8 *)((s32 (*)(int))get_player_by_client_id)(i);
                if (other != NULL && field == ((TObjPlayer *)other)->get_field_3e4() &&
                    xyz_distance_squared(self + 0x38, other + 0x38) < range * range) {
                    qst_registers[arg1]++;
                }
            }
        }
    }
}

s32 TLobby__sub_800712D8(s32, s32, s32);
s32 TLobby__sub_802923C4(s32, s32, s32);
void qst_op_set_cmode_rank_threshold(u8 arg0, u8 arg1) {
    s32 a = qst_registers[(u8)arg0++];
    s32 b = qst_registers[(u8)arg0++];
    s32 c = qst_registers[(u8)arg0];
    if (is_split_screen() == 1) {
        if (TLobby__sub_802923C4(a, b, c) != 0) {
            qst_registers[arg1] = 1;
        } else {
            qst_registers[arg1] = 0;
        }
    } else {
        if (TLobby__sub_800712D8(a, b, c) != 0) {
            qst_registers[arg1] = 1;
        } else {
            qst_registers[arg1] = 0;
        }
    }
}
}

s32 get_selected_entry_value(void);
extern "C" {
s32 TObjItemOKWindow__sub_801F3268(void);
void TItemData__sub_8010CA08(Item_801EBF30 *, s32, s32);
void qst_op_award_item_give(u8 arg0) {
    Item_801EBF30 item;
    u8 t = get_selected_entry_value();
    TItemData__sub_8010CA08(&item, TObjItemOKWindow__sub_801F3268(), t);
    if (is_split_screen() == 1) {
        if (TLobby__sub_802924B4(&item, 0) != 0) {
            qst_registers[arg0] = 1;
        } else {
            qst_registers[arg0] = 0;
        }
    } else {
        if (TLobby__sub_800710D8(&item) != 0) {
            qst_registers[arg0] = 1;
        } else {
            qst_registers[arg0] = 0;
        }
    }
}

void qst_op_award_item_select() { TLobby__quest_window_object = create__18TObjItemNameSelectFPv((void*)tl_01); TLobby__quest_window_state = 10; }

void qst_op_award_item_name() { TLobby__data_805D5EB0 = (int)create__17TObjItemNameEntryFPv((void *)tl_01); TLobby__quest_window_state = 9; }

void qst_op_set_cmode_rank_result(void) {
    s32 temp_r31;
    u8 *lobby;
    temp_r31 = qst_args[0];
    lobby = (u8 *)(*(u8 **)&qst_args[1]);
    if (is_split_screen() == 1) {
        TLobby::set_encoded_name_and_color(lobby, temp_r31);
        return;
    }
    ((TLobby *)lobby)->set_player_name_and_color(temp_r31);
}

void qst_op_get_mag_levels(s32 i) {
    s32 r;
    if (((u32 (*)(void *))get_player_by_client_id)((void *)local_client_id) != 0) {
        r = activate_d04_slot__10TObjPlayerFv();
        if (r != 0) {
            qst_registers[(u8)i++] = get_mag_item_stat_percent();
            qst_registers[(u8)i++] = get_mag_item_percent(r);
            qst_registers[(u8)i++] = get_mag_level(r);
            qst_registers[(u8)i] = get_mag_item_data(r);
        }
    }
}

void qst_op_give_s_rank_weapon() {
    Item_801EBF30 item;
    u8 r = qst_args[1];
    s32 a = qst_args[2];
    u16 id = qst_args[0];
    if (id == local_client_id) {
        void *player = (void *)get_player_by_client_id(id);
        if (player != NULL) {
            TItemData__sub_8010CA08(&item, a, (u8)qst_registers[r]);
            if (((TItemData *)(&item))->isValidGroundDrop() == 1 && ((TObjPlayer *)player)->can_inventory_accept_item((u8 *)((Item_801EEE68 *)&item)) > 0) {
                ((TObjPlayer *)player)->request_inventory_item((TItemData*)((Item_801EEE68 *)&item));
            }
        }
    }
}

void qst_op_set_score_announce() {
    s32 i;
    s32 v = qst_args[0];
    for (i = 0; i < 8; i++) {
        if (battle_event_second_table[i] == 0) {
            battle_event_second_table[i] = v;
            return;
        }
    }
}

void qst_op_clear_score_announce() {
    s32 i;
    for (i = 0; i < 8; i++) {
        battle_event_second_table[i] = 0;
    }
}

void qst_op_ba_sonar_count(void) {
    battle_rules.sonar_count = (s8) qst_args[0];
}

void qst_op_ba_enable_sonar() {
    if ((u32) (u32)qst_args[0] <= 0x1U) {
        battle_rules.enable_sonar = (s8) *(s32 *)((s8 *)((u8 *)(&lbl_80449B08.value) + ((u32)qst_args[0] * 4)) + 0);
    }
}

void qst_op_set_allow_item_flags(void) {
    TItemMenuCtrl::open_menu((int) (qst_args[0]));
}

void qst_op_p_talk_guild_local(int _w0, int _w1) {
    if (((u32 (*)(int, int))get_player_by_client_id)((int)(local_client_id), (int)(_w1)) != 0U) {
        handle_main_phase__6TLobbyFl();
    }
}

void qst_op_unequip_item() {
    TLobby::handle_player_event((int) ((u16) qst_args[0]), (int) (qst_args[1]));
}

void qst_op_equip_item(u8 i) {
    Item_801EC720 item;
    u16 id = qst_registers[i++];
    ((s32 (*)(void *))init__9TItemDataFv)(&item);
    item.a = qst_registers[i++];
    item.b = qst_registers[i++];
    item.c = qst_registers[i++];
    TLobby::forward_to_player(id, &item);
}

int qst_op_ba_hide_self_traps(void) { return set_instance__10TOMineTrapFi((void*)(0)); }

int qst_op_ba_show_self_traps(void) { return set_instance__10TOMineTrapFi((void*)(1)); }

void qst_op_set_area_title() {
    s32 temp_r31;

    temp_r31 = qst_args[0];
    if (is_split_screen() == 1) {
        ((TLobby *)temp_r31)->set_name_string();
        return;
    }
    ((TLobby *)temp_r31)->set_name_string();
}

int qst_op_unset_ult_map(void* p) { return clear_quest_state__6TLobbyFv(p); }

int qst_op_set_ult_map(void* p) { return TLobby__sub_801F36BC(p); }

int qst_op_restore_warp_dest_floor(void* p) { return reset_quest_counter__6TLobbyFv(p); }

int qst_op_override_warp_dest_floor(void *p) { return TLobby__sub_801F36D8(p); }

void qst_op_set_current_area_number(void) {
    TLobby::set_lobby_id((int) (qst_args[0]));
}

void qst_op_set_area_total() {
    TLobby::set_global_805D3614((int) (qst_args[0]));
}

void qst_op_ba_set_meseta_drop_mode(void) {
    if ((u32) (u32)qst_args[0] <= 2U) {
        battle_rules.meseta_mode = (s8) *(s32 *)((s8 *)((u8 *)(&lbl_80449AFC.value) + ((u32)qst_args[0] * 4)) + 0);
    }
}

void qst_op_ba_death_lvl_up(void) {
    battle_rules.death_level_up = (s8) qst_args[0];
}

void qst_op_ba_set_time_limit(void) {
    u32 var_r4;
    var_r4 = (u32)qst_args[0];
    if (var_r4 > 0x278D0U) {
        var_r4 = 0U;
    }
    battle_rules.time_limit = var_r4;
}

void qst_op_ba_set_char_level(void) {
    u32 var_r31;
    var_r31 = (u32)qst_args[0];
    if (var_r31 > TObjPlayer::get_max_level()) {
        var_r31 = 0U;
    }
    battle_rules.char_level = var_r31;
}

void qst_op_ba_set_max_tech_level() {
    u32 var_r0;
    var_r0 = (u32)qst_args[0];
    if ((var_r0 != 0xFFU) && (var_r0 > 0x1DU)) {
        var_r0 = 0U;
    }
    battle_rules.max_tech_level = var_r0;
}

void qst_op_ba_set_lives(void) {
    u32 var_r0;
    var_r0 = (u32)qst_args[0];
    if (var_r0 > 0x63U) {
        var_r0 = 0U;
    }
    battle_rules.lives = var_r0;
}

void qst_op_ba_hide_target_reticle(void) {
    if ((u32) (u32)qst_args[0] <= 1U) {
        battle_rules.hide_target_reticle = (s8) (u32)qst_args[0];
    }
}

void qst_op_ba_set_trap_count(s32 reg) {
    s32 slot = qst_registers[(u8)reg++];
    s32 value = qst_registers[(u8)reg];
    if (slot >= 0 && slot <= 3) {
        battle_rules.trap_counts[lbl_80449AEC[slot]] = value;
    }
}

extern f32 lbl_805D5DC8;
void qst_op_ba_meseta_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D5DC8 = v;
}

extern f32 lbl_805D3550;
void qst_op_ba_enemy_death_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D3550 = v;
}

extern f32 lbl_805D354C;
void qst_op_ba_enemy_kill_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D354C = v;
}

void qst_op_ba_player_death_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D3544 = v;
}

void qst_op_ba_player_kill_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D3540 = v;
}

void qst_op_ba_enemy_take_damage_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D5DC4 = v;
}

void qst_op_ba_enemy_give_damage_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D3548 = v;
}

void qst_op_ba_player_take_damage_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D353C = v;
}

void qst_op_ba_player_give_damage_score(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    lbl_805D3538 = v;
}

void qst_op_set_cmode_base_time(s32 arg0) {
    if (is_split_screen() == 1) {
        TLobby::update_challenge_timer((int) (qst_registers[(u8)arg0]));
        return;
    }
    TLobby__sub_80071064((int) (qst_registers[(u8)arg0]));
}

void qst_op_prepare_npc_visual(s32 arg0) {
    u32 temp_r3;
    temp_r3 = ((u32 (*)(void *))qst_label_address)((void *)arg0);
    if (temp_r3 != 0U) {
        copy_player_visual_record((void *) (&lbl_8050D3E0.value), temp_r3);
    }
}

int qst_op_enable_npc_visual(void* p) { return TNpcPlayer__sub_8014DC30(p); }

void qst_op_set_shrink_cam2(u8 arg0) {
    Vec_801ECFDC pos;
    u8 *player;
    Vec_801ECFDC *cur;
    player = (u8 *)((s32 (*)(int))get_player_by_client_id)(qst_registers[arg0++]);
    if (player != NULL) {
        cur = TObjPlayer__sub_801C6FDC(player + 0x5D4);
        if (cur != NULL) {
            pos.x = cur->x + (f32)qst_registers[arg0++];
            pos.y = cur->y + (f32)qst_registers[arg0++];
            pos.z = cur->z + (f32)qst_registers[arg0];
            copy_position__6TLobbyFv(player + 0x5D4, &pos);
        }
    }
}

void qst_op_set_shrink_cam1(u8 arg0) {
    Vec_801ED0CC pos;
    u8 *player;
    Vec_801ED0CC *cur;
    player = (u8 *)((s32 (*)(int))get_player_by_client_id)(qst_registers[arg0++]);
    if (player != NULL) {
        cur = ((Vec_801ED0CC *)TObjPlayer__sub_801C6FDC(player + 0x5C8));
        if (cur != NULL) {
            pos.x = cur->x + (f32)qst_registers[arg0++];
            pos.y = cur->y + (f32)qst_registers[arg0++];
            pos.z = cur->z + (f32)qst_registers[arg0];
            copy_position__6TLobbyFv((void *)(player + 0x5C8), (Vec_801ECFDC *)(&pos));
        }
    }
}

void qst_op_unshrink(s32 arg0) {
    s32 temp_r3;
    temp_r3 = ((s32)((u32 (*)(int, int))get_player_by_client_id)((int)(qst_registers[(u8)arg0]), (int)qst_registers));
    if ((temp_r3 != 0) && (((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0)) {
        request_player_size_restore((PlayerScaleState *)(temp_r3 + 0x5B0));
    }
}

void qst_op_shrink(s32 arg0) {
    s32 temp_r3;
    temp_r3 = ((s32)((u32 (*)(int, int))get_player_by_client_id)((int)(qst_registers[(u8)arg0]), (int)qst_registers));
    if ((temp_r3 != 0) && (((s32 (*)(void))obj_isState2_324__13TUnk_804806E8Fv)() == 0)) {
        request_player_shrink((PlayerScaleState *)(temp_r3 + 0x5B0));
    }
}

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma opt_dead_assignments off
void qst_op_read_switch_flag_on_floor(s32 arg0) {
    s32 var_r31;
    s32 var_r4;
    u8 *var_r3;
    var_r31 = (arg0 * 4) & 0x3FC;
    var_r4 = ((s32)qst_registers);
    var_r3 = (u8 *)(var_r4 + var_r31);
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 4));
    var_r4 = (s32) (s16) *(s32 *)((s8 *)var_r4 + var_r31);
    var_r3 = (u8 *)((void *) (u16) var_r3);
    var_r4 = (s32) is_floor_switch_set((u32)var_r3, (var_r4));
    var_r3 = (u8 *)(((s32)qst_registers) + var_r31);
    *(s32 *)((s8 *)var_r3 + 8) = var_r4;
}
#pragma pop

void qst_op_read_switch_flag(s32 arg0) {
    qst_registers[(u8)arg0 + 1] = is_current_floor_switch_set((u16)qst_registers[(u8)arg0]);
}

void qst_op_clear_switch_flag_sync() {
    Pkt_801ED300 pkt;
    s32 x = qst_args[0];
    s32 y = qst_args[1];
    ((TLobby *)(&pkt))->init_6x05_switch_changed();
    pkt.a = 0xFFFF;
    pkt.b = 0;
    pkt.c = y;
    pkt.d = x;
    pkt.e = 0;
    ((TLobby *)(&pkt))->finalize_and_send_60();
}

void qst_op_set_switch_flag_sync() {
    Pkt_801ED360 pkt;
    s32 x = qst_args[0];
    s32 y = qst_args[1];
    ((TLobby *)(&pkt))->init_6x05_switch_changed();
    pkt.a = 0xFFFF;
    pkt.b = 0;
    pkt.c = y;
    pkt.d = x;
    pkt.e = 1;
    ((TLobby *)(&pkt))->finalize_and_send_60();
}

void qst_op_reset_kills(s32 arg0) {
    u8 *lobby;
    lobby = (u8 *)(((u8 *)((u32 (*)(int, int))get_player_by_client_id)((int)(qst_registers[(u8)arg0]), (int)(((s32)qst_registers)))));
    if (lobby != NULL) {
        ((TLobby *)lobby)->set_floor(0);
    }
}

void qst_op_get_num_kills(s32 arg0, s32 arg1) {
    u8 *player;
    player = (u8 *)(((s32)((u32 (*)(int, int))get_player_by_client_id)((int)(qst_registers[(u8)arg0]), arg1)));
    if (player != NULL) {
        qst_registers[(u8)arg1] = (s32) ((TObjPlayer *)player)->get_kill_count();
        return;
    }
    qst_registers[(u8)arg1] = 0;
}

void qst_op_go_floor(s32 a, s32 b) {
    u32 r = ((u32 (*)(int, int))get_player_by_client_id)(qst_registers[(u8)a], b);
    if (r != 0 && local_client_id == qst_registers[(u8)a]) {
        set_area__6TLobbyFl(lbl_80515BA0, qst_registers[(u8)b], get_floor_map_terrain(qst_registers[(u8)b]));
        mark_area_change_pending();
        ((TObjAreaWarpQuest *)lbl_80515BA0)->get_dest_area();
        send_inter_level_warp_all__10TNpcPlayerFl();
        send_6x21_inter_level_warp((void *)r, (s32)((void *)((TObjAreaWarpQuest *)lbl_80515BA0)->get_dest_area()));
    }
}

void qst_op_release_dragon(void* p) { TBoss1Dragon::clearControlOverride(); }

void qst_op_control_dragon(s32 arg0) {
    setControlOverride__12TBoss1DragonFs((int) ((u16) qst_registers[(u8)arg0]), qst_registers);
}

void qst_op_cmode_check_any_player_dead(s32 arg0) {
    if (is_split_screen() == 1) {
        qst_registers[(u8)arg0] = TLobby__sub_8029299C();
        return;
    }
    qst_registers[(u8)arg0] = TLobby__sub_80070F4C();
}

void qst_op_cmode_check_all_players_dead(s32 arg0) {
    if (is_split_screen() == 1) {
        qst_registers[(u8)arg0] = TLobby__sub_80292A34();
        return;
    }
    qst_registers[(u8)arg0] = TLobby__sub_80070FD8();
}

void qst_op_exp_multiplication(s32 a) {
    s32 b = a + 1;
    f32 v = (f32)qst_registers[(u8)a];
    v += (f32)qst_registers[(u8)b] / (f32)qst_registers[(u8)++b];
    if (is_split_screen() == 1) {
        TLobby::set_camera_height_if_valid(v);
        return;
    }
    TLobby::try_set_value(v);
}

void qst_op_set_cmode_difficulty() {
    s32 temp_r31;

    temp_r31 = qst_args[0];
    if (is_split_screen() == 1) {
        TLobby::try_set_split_screen(temp_r31);
        return;
    }
    TLobby::set_split_screen_flag(temp_r31);
}

void qst_op_set_cmode_char_template() {
    s32 temp_r31;

    temp_r31 = qst_args[0];
    if (is_split_screen() == 1) {
        TLobby::rebuild_players_for_stage(temp_r31);
        return;
    }
    TObjPlayer::rebuild_players_for_stage(temp_r31);
}

void qst_op_nop_F822(s32 arg0) {
    if (is_split_screen() == 1) {
        TLobby__sub_801F3700((int) (qst_registers[(u8)arg0]));
        return;
    }
    TLobby__sub_801F36F0((int) (qst_registers[(u8)arg0]));
}

void qst_op_nop_F821(u8 arg0) {
    Item_801ED7BC item;
    s32 a;
    s32 b;
    s32 c;
    a = qst_registers[(u8)arg0++];
    b = qst_registers[(u8)arg0++];
    c = qst_registers[(u8)arg0++];
    ((void (*)(Item_801ED7BC *))init__9TItemDataFv)(&item);
    item.data[0] = qst_registers[(u8)arg0++];
    item.data[1] = qst_registers[(u8)arg0++];
    item.data[2] = qst_registers[(u8)arg0++];
    item.data[3] = qst_registers[(u8)arg0++];
    item.data[4] = qst_registers[(u8)arg0++];
    item.data[5] = qst_registers[(u8)arg0];
    item.id = advance_item_id_counter(local_client_id);
    if (is_split_screen() == 1) {
        TLobby__sub_801F3708(a, b, c, &item);
    } else {
        TLobby__sub_801F36F8(a, b, c, &item);
    }
}

void qst_op_cmode_stage() {
    u32 temp_r30;
    u32 temp_r31;

    temp_r30 = (u32)qst_args[0];
    temp_r31 = get_layout_id__20TWindowSubStatusDispFv(-1);
    if (is_split_screen() == 1) {
        if (temp_r30 < temp_r31) {
            TLobby::clamp_and_store_layout_index(temp_r30);
            return;
        }
        TLobby::clamp_and_store_layout_index(0U);
        return;
    }
    if (temp_r30 < temp_r31) {
        TLobby::set_selected_layout(temp_r30);
        return;
    }
    TLobby::set_selected_layout(0U);
}

void qst_op_ba_start(void) {
    s32 temp_r31;
    temp_r31 = qst_args[0];
    if (TRaderMapCore::is_not_split_screen() == 1) {
        TPlayerBattleCtrl4P::init_instance_with_text((s32)&battle_rules, temp_r31);
        return;
    }
    init_battle_ctrl__6TLobbyFii((s32)&battle_rules, temp_r31);
}

void qst_op_ba_teams() {
    if ((u32) (u32)qst_args[0] <= 0x1U) {
        battle_rules.is_teams = (s8) (&lbl_80449AE4.value)[(u32)qst_args[0]];
        return;
    }
    battle_rules.is_teams = (s8) lbl_80449AE4.value;
}

void qst_op_ba_dropwep() {
    if ((u32) (u32)qst_args[0] <= 0x1U) {
        battle_rules.drop_weapon = (s8) (&lbl_80449ADC.value)[(u32)qst_args[0]];
        return;
    }
    battle_rules.drop_weapon = (s8) lbl_80449ADC.value;
}

void qst_op_ba_set_replace_char() {
    if ((u32) (u32)qst_args[0] <= 0x1U) {
        battle_rules.replace_char = (s8) *(s32 *)((s8 *)((u8 *)(&lbl_80449AD4.value) + ((u32)qst_args[0] * 4)) + 0);
        return;
    }
    battle_rules.replace_char = (s8) *(s32 *)((s8 *)(&lbl_80449AD4.value) + 0x4);
}

void qst_op_ba_set_respawn(void) {
    if ((u32) (u32)qst_args[0] <= 2U) {
        battle_rules.respawn_mode = (s8) *(s32 *)((s8 *)((u8 *)(&lbl_80449AC8.value) + ((u32)qst_args[0] * 4)) + 0);
        return;
    }
    battle_rules.respawn_mode = (s8) *(s32 *)((s8 *)(&lbl_80449AC8.value) + 8);
}

void qst_op_ba_set_unused_F817(void) {
    if ((u32) (u32)qst_args[0] <= 0x1U) {
        battle_rules.unused_F817 = (s8) (&lbl_80449AC0.value)[(u32)qst_args[0]];
        return;
    }
    battle_rules.unused_F817 = (s8) lbl_80449AC0.value;
}

void qst_op_ba_set_trap_mode(void) {
    if ((u32) (u32)qst_args[0] <= 0x1U) {
        battle_rules.trap_mode = (s8) (&lbl_80449AB8.value)[(u32)qst_args[0]];
        return;
    }
    battle_rules.trap_mode = (s8) lbl_80449AB8.value;
}

void qst_op_ba_set_tool_mode(void) {
    if ((u32) (u32)qst_args[0] <= 2U) {
        battle_rules.tool_mode = (s8) (&lbl_80449AAC.value)[(u32)qst_args[0]];
        return;
    }
    battle_rules.tool_mode = (s8) lbl_80449AAC.value;
}

void qst_op_ba_set_forbid_mags() {
    if ((u32) (u32)qst_args[0] <= 0x1U) {
        battle_rules.mag_mode = (s8) (&lbl_80449AA4.value)[(u32)qst_args[0]];
        return;
    }
    battle_rules.mag_mode = (s8) lbl_80449AA4.value;
}

void qst_op_ba_set_weapon_and_armor_mode() {
    if ((u32) (u32)qst_args[0] <= 3U) {
        battle_rules.weapon_and_armor_mode = (s8) (&lobby_menu_byte_1_map.value)[(u32)qst_args[0]];
        return;
    }
    battle_rules.weapon_and_armor_mode = (s8) lobby_menu_byte_1_map.value;
}

void qst_op_ba_set_tech_disk_mode() {
    s8 var_r0;
    if ((u32) (u32)qst_args[0] <= 2U) {
        var_r0 = (s8) *(s32 *)((s8 *)((u8 *)(&lbl_80449A88.value) + ((u32)qst_args[0] * 4)) + 0);
    } else {
        var_r0 = (s8) *(s32 *)((s8 *)(&lbl_80449A88.value) + 8);
    }
    battle_rules.tech_disk_mode = var_r0;
}

void qst_op_clear_ba_rules() {
    memset(&battle_rules, 0, sizeof(BattleRules));
}

void qst_op_ba_initial_floor(void) {
    Tbl_801EDC98 t = lobby_sub_801edc98_id_table;
    if ((u32)qst_args[0] <= 0x11U) {
        TLobby__sub_80141038(lbl_80515BA0, t.w[(u32)qst_args[0]], 0);
    }
}

void qst_op_enable_weapon_drop(int _w0, int _w1) {
    if (((u32 (*)(int, int))get_player_by_client_id)((int)(qst_args[0]), _w1) != 0U) {
        send_field1c_packet__6TLobbyFl();
    }
}

void qst_op_disable_weapon_drop(int _w0, int _w1) {
    if (((u32 (*)(int, int))get_player_by_client_id)((int)(qst_args[0]), _w1) != 0U) {
        send_font_state__6TLobbyFl();
    }
}
}

void qst_op_map_designate_ex(u32 first) {
    u32 i = first;
    s32 a = qst_registers[(u8)i++];
    s32 b = qst_registers[(u8)i++];
    s16 c = qst_registers[(u8)i++];
    s32 d = qst_registers[(u8)i++];
    s32 e = qst_registers[(u8)i];
    set_quest_floor_designation_ex(c, a, b, d, e);
}

extern "C" {
int qst_op_disable_map(void) { return set_mode__13TRaderMapCoreFi((void*)(0)); }

int qst_op_enable_map(void) { return set_mode__13TRaderMapCoreFi((void*)(1)); }

void qst_op_get_coord_of_player(s32 a, s32 b) {
    if (((u32 (*)(int, int))get_player_by_client_id)((int)(qst_registers[(u8)b]), b) != 0) {
        f32 *p = get_position_ptr__10TObjPlayerFv();
        if (p != NULL) {
            qst_registers[(u8)a++] = (s32)p[0];
            qst_registers[(u8)a++] = (s32)p[1];
            qst_registers[(u8)a] = (s32)p[2];
        }
    }
}

void qst_op_get_number_of_players(int a0) { qst_registers[(unsigned char)(a0)] = TLobby::count_members(); }

void qst_op_get_difficulty_level_v2(s32 arg0) {
    s32 var_r5;
    var_r5 = game_difficulty_selection;
    if (var_r5 < 0) {
        var_r5 = 0;
    }
    if (var_r5 > 3) {
        var_r5 = 3;
    }
    qst_registers[(u8)arg0] = var_r5;
}

void qst_op_create_bgmctrl() {
    void* obj = __nw__7TObjectFUl(0x1C);
    if (obj != 0) {
        __ct__13TQuestBgmCtrlFP7TObject(obj, tl_05);
    }
}

void qst_op_update_switch_flag(s32 arg0) {
    Pkt_801EDF64 pkt;
    ((TLobby *)(&pkt))->init_6x05_switch_changed();
    pkt.b = 0;
    pkt.a = 0xFFFF;
    pkt.c = qst_registers[(u8)arg0++];
    pkt.d = qst_registers[(u8)arg0++];
    pkt.e = qst_registers[(u8)arg0];
    ((TLobby *)(&pkt))->finalize_and_send_60();
}
}

void qst_op_get_leader_id(u8 reg) {
    qst_registers[reg] = TLobby__designated_client_id;
}

void qst_op_get_client_id(u8 reg) {
    qst_registers[reg] = local_client_id;
}
extern "C" {

int qst_op_warp_off(void *p) { return TLobby__sub_801F36E4(p); }
}

int qst_op_warp_on(void* p) { return set_cleanup_flag__6TLobbyFv(p); }
extern "C" {

void qst_op_start_setevt() {
    Pkt_801EE048 pkt;
    s32 x = qst_args[0];
    s32 y = qst_args[1];
    ((TLobby *)(&pkt))->init_packet_67_04();
    pkt.b = x;
    pkt.a = 0;
    pkt.c = y;
    pkt.d = 0;
    ((TLobby *)((s32)&pkt))->byteswap_and_send();
}

void qst_op_pad_dragon(void* p) { TBoss1Dragon::requestActionRefresh(); }

void qst_op_delete_bank_item(u8 arg0, u8 arg1) {
    Item_801EE0BC item;
    ((void (*)(Item_801EE0BC *))init__9TItemDataFv)(&item);
    item.data[0] = qst_registers[(u8)arg0++];
    item.data[1] = qst_registers[(u8)arg0++];
    item.data[2] = qst_registers[(u8)arg0++];
    item.data[3] = qst_registers[(u8)arg0++];
    item.data[4] = qst_registers[(u8)arg0++];
    item.data[5] = qst_registers[(u8)arg0];
    if (TCheckRoomSequence__sub_80210D44((u8 *)&item, 0) != 0) {
        qst_registers[arg1] = 1;
    } else {
        qst_registers[arg1] = 0;
    }
}

void qst_op_set_returncity() {
    if (((s32 (*)(s32))get_player_by_client_id)(local_client_id) != 0U) {
        stop_battle__10TObjPlayerFv();
    }
}

void qst_op_set_returnhunter() {
    if (((s32 (*)(s32))get_player_by_client_id)(local_client_id) != 0U) {
        player_flag_1__6TLobbyFv();
    }
}

void qst_op_default_camera_pos1() {
    u32 temp_r3;
    reset_battle_camera__11TCameraCtrlFv();
    temp_r3 = ((s32 (*)(s32))get_player_by_client_id)(local_client_id);
    if (temp_r3 != 0U) {
        reset_cameras_to_actor((void *)temp_r3, 0);
    }
}

void qst_op_leti_fixed_camera(u8 arg0) {
    Vec_801EE220 eye;
    Vec_801EE220 at;

    eye.x = qst_registers[(u8)arg0++];
    eye.y = qst_registers[(u8)arg0++];
    eye.z = qst_registers[(u8)arg0++];
    at.x = qst_registers[(u8)arg0++];
    at.y = qst_registers[(u8)arg0++];
    at.z = qst_registers[(u8)arg0];
    TCameraCtrl__sub_8006B3B8(&eye, &at);
}
}

void qst_op_sync_register(void) {
    Pkt_801EE330 pkt;
    build_6x77_sync_quest_register(&pkt);
    pkt.a = qst_args[0];
    pkt.b = qst_args[1];
    ((TLobby *)(&pkt))->sync_quest_register_and_send();
}
extern "C" {

void qst_op_set_eventflag2(void) {
    u32 x = (u32)qst_args[0];
    u32 y = (u32)qst_args[1];
    u8* s = ((u8* (*)(void))get_global_state__23TAdSinglePlyChrSelectGCFv)();
    if (s != 0 && x < 0x100) {
        s[x + 0x10] = y;
    }
}

void qst_op_set_eventflag(void) {
    u32 x = (u32)qst_args[0];
    u32 y = (u32)qst_args[1];
    u8* s = ((u8* (*)(void))get_global_state__23TAdSinglePlyChrSelectGCFv)();
    if (s != 0 && x < 0x100) {
        s[x + 0x10] = y;
    }
}

void qst_op_end_battlebgm() {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(s32))get_player_by_client_id)(local_client_id);
    if (temp_r3 != 0) {
        TObjPlayer__sub_801B3FD8();
        ((TObjPlayer *)temp_r3)->forward_1BF500_at_63c();
    }
}

void qst_op_start_battlebgm() {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(s32))get_player_by_client_id)(local_client_id);
    if (temp_r3 != 0) {
        TObjPlayer__sub_801B4044();
        ((TObjPlayer *)temp_r3)->attach_battle_ctrl_sub();
    }
}

void qst_op_disable_mainmenu(void) { TObjPlayer__sub_8024ABDC(((*(int *)&local_client_id))); }

void qst_op_enable_mainmenu() { TLobby__sub_8024AC20(((*(int *)&local_client_id))); }

void qst_op_nop_BC(void) {  }

int qst_op_clr_qt_exit(void) { return set_quest_exit_callback((void*)(-1)); }

void qst_op_set_qt_exit(u16 arg0) {
    set_quest_exit_callback((void *)arg0);
}

void qst_op_get_difficulty_level_v1(s32 arg0) {
    s32 var_r5;
    var_r5 = game_difficulty_selection;
    if (var_r5 < 0) {
        var_r5 = 0;
    }
    if (var_r5 > 2) {
        var_r5 = 2;
    }
    qst_registers[(u8)arg0] = var_r5;
}

void qst_op_setevt(void) {
    Pkt_801EE54C pkt;
    s32 x = qst_args[0];
    ((TLobby *)(&pkt))->init_packet_67_04();
    pkt.a = 0;
    pkt.b = get_current_floor();
    pkt.c = x;
    pkt.d = 0;
    ((TLobby *)((s32)&pkt))->byteswap_and_send();
}
}

void qst_op_clear_quest_board_handler(void) {
    if ((u32) (u32)qst_args[0] <= 5U) {
        memset((void *) ((u8 *)&quest_board_handlers.value + ((u32)qst_args[0] * 0x24)), 0, 0x24);
    }
}

void qst_op_set_quest_board_handler(void) {
    s32 i = qst_args[0];
    s32 v = qst_args[1];
    s32 n = qst_args[2];
    if (i <= 5) {
        Ent_801EE5EC* e = &((Ent_801EE5EC *)&quest_board_handlers)[i];
        e->v = v;
        ((void* (*)(void*, s32, s32))strncpy)(e, n, 0x20);
    }
}
extern "C" {

void qst_op_getmtime(int a0) { qst_registers[(unsigned char)(a0)] = TLobby__sub_803DF1CC(); }

void qst_op_winset_time(s32 arg0) {
    set_timer_window_time__11TWindowCtrlFv((int) (qst_registers[(u8)arg0]), qst_registers);
}
}

int qst_op_winend_time(void* p) { return close_timer_window__11TWindowCtrlFv(p); }
extern "C" {

int qst_op_show_timer(void *p) { return create_alt_timer__11TWindowCtrlFv(p); }

void qst_op_masterkey_off() { TLobby::reset_door_state(); TObjDoor::reset_instance(); }

void qst_op_masterkey_on() { TObjDoor__sub_801F3760(); TObjDoor__sub_801F3754(); }
}

void qst_op_map_designate(u32 first) {
    u32 i = first;
    s32 floor = qst_registers[(u8)i++];
    s16 mode = qst_registers[(u8)i++];
    s32 terrain = qst_registers[(u8)i++];
    s32 extra = qst_registers[(u8)i];
    set_quest_floor_designation(mode, floor, terrain, extra);
}
extern "C" {

void qst_op_find_inventory_item_ex(u8 arg0, u8 arg1) {
    Item_801EE77C item;
    Player_801EE77C *player;
    void *obj;
    player = (Player_801EE77C *)get_player_by_client_id(local_client_id);
    if (player != NULL) {
        init__9TItemDataFv(&item);
        item.data[0] = qst_registers[(u8)arg0++];
        item.data[1] = qst_registers[(u8)arg0++];
        item.data[2] = qst_registers[(u8)arg0++];
        item.data[4] = qst_registers[(u8)arg0];
        obj = set_mode_and_refresh_object__10TObjPlayerFPvi(player->fD00, &item);
        if (obj != NULL) {
            obj = get_owner_if_alive__10TObjPlayerFv(obj);
            if (obj != NULL) {
                qst_registers[arg1] = ((TItem *)obj)->get_item_id();
            } else {
                qst_registers[arg1] = -1;
            }
        } else {
            qst_registers[arg1] = -1;
        }
    } else {
        qst_registers[arg1] = -1;
    }
}
}

void qst_op_item_check(u32 first, u32 destination) {
    Item_801EE77C item;
    u32 player;
    void *slot;
    void *owner;
    player = get_player_by_client_id(local_client_id);
    if (player != 0) {
        init__9TItemDataFv(&item);
        item.data[0] = qst_registers[(u8)first++];
        item.data[1] = qst_registers[(u8)first++];
        item.data[2] = qst_registers[(u8)first];
        slot = set_mode_and_refresh_object__10TObjPlayerFPvi(*(void **)((s8 *)player + 0xD00), &item);
        if (slot != 0) {
            owner = get_owner_if_alive__10TObjPlayerFv(slot);
            if (owner != 0) {
                qst_registers[(u8) destination] = ((TItem *)owner)->get_item_id();
                return;
            }
            qst_registers[(u8) destination] = -1;
            return;
        }
        qst_registers[(u8) destination] = -1;
        return;
    }
    qst_registers[(u8) destination] = -1;
}

void qst_op_item_delete2(u32 src, u32 dst) {
    Item_801EE77C item;
    u32 player;
    void *slot;
    void *owner;
    if ((u8)dst > 0xF4) {
        return;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != 0) {
        init__9TItemDataFv(&item);
        item.data[0] = qst_registers[(u8)src++];
        item.data[1] = qst_registers[(u8)src++];
        item.data[2] = qst_registers[(u8)src];
        slot = set_mode_and_refresh_object__10TObjPlayerFPvi(*(void **)((s8 *)player + 0xD00), &item);
        if (slot != 0) {
            owner = get_owner_if_alive__10TObjPlayerFv(slot);
            if (owner != 0) {
                ((TItem *)owner)->copy_to_item_data((TItemData *)&item);
                qst_registers[(u8)dst++] = item.data[0];
                qst_registers[(u8)dst++] = item.data[1];
                qst_registers[(u8)dst++] = item.data[2];
                qst_registers[(u8)dst++] = item.data[3];
                qst_registers[(u8)dst++] = item.data[4];
                qst_registers[(u8)dst++] = item.data[5];
                qst_registers[(u8)dst++] = item.data[6];
                qst_registers[(u8)dst++] = (s8)item.data[7];
                qst_registers[(u8)dst++] = item.data[8];
                qst_registers[(u8)dst++] = (s8)item.data[9];
                qst_registers[(u8)dst++] = item.data[10];
                qst_registers[(u8)dst] = (s8)item.data[11];
                get_item_record__23TShopJudgmentItemWindowFPv((void *)player, item.id, 1);
                return;
            }
            qst_registers[(u8)dst] = -1;
            return;
        }
        qst_registers[(u8)dst] = -1;
        return;
    }
    qst_registers[(u8)dst] = -1;
}

void qst_op_item_delete(u32 src, u32 dst) {
    Item_801EE77C item;
    u32 player;
    void *slot;
    void *owner;
    if ((u8)dst > 0xF4) {
        return;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != 0) {
        slot = start_inventory_update__10TObjPlayerFi(*(void **)((s8 *)player + 0xD00), qst_registers[(u8)src]);
        if (slot != 0) {
            owner = get_owner_if_alive__10TObjPlayerFv(slot);
            if (owner != 0) {
                ((TItem *)owner)->copy_to_item_data((TItemData *)&item);
                qst_registers[(u8)dst++] = item.data[0];
                qst_registers[(u8)dst++] = item.data[1];
                qst_registers[(u8)dst++] = item.data[2];
                qst_registers[(u8)dst++] = item.data[3];
                qst_registers[(u8)dst++] = item.data[4];
                qst_registers[(u8)dst++] = item.data[5];
                qst_registers[(u8)dst++] = item.data[6];
                qst_registers[(u8)dst++] = (s8)item.data[7];
                qst_registers[(u8)dst++] = item.data[8];
                qst_registers[(u8)dst++] = (s8)item.data[9];
                qst_registers[(u8)dst++] = item.data[10];
                qst_registers[(u8)dst] = (s8)item.data[11];
                get_item_record__23TShopJudgmentItemWindowFPv((void *)player, qst_registers[(u8)src], 1);
                return;
            }
            qst_registers[(u8)dst] = -1;
            return;
        }
        qst_registers[(u8)dst] = -1;
        return;
    }
    qst_registers[(u8)dst] = -1;
}

void qst_op_item_create2(u8 arg0, u8 arg1) {
    Item_801EEE68 item;
    void *player;
    player = (void *)get_player_by_client_id(local_client_id);
    if (player != NULL) {
        init__9TItemDataFv((Item_801EE77C *)(&item));
        item.data[0] = qst_registers[arg0++];
        item.data[1] = qst_registers[arg0++];
        item.data[2] = qst_registers[arg0++];
        item.data[3] = qst_registers[arg0++];
        item.data[4] = qst_registers[arg0++];
        item.data[5] = qst_registers[arg0++];
        item.id = advance_item_id_counter(local_client_id);
        item.data[6] = qst_registers[arg0++];
        item.data[7] = qst_registers[arg0++];
        item.data[8] = qst_registers[arg0++];
        item.data[9] = qst_registers[arg0++];
        item.data[10] = qst_registers[arg0++];
        item.data[11] = qst_registers[arg0];
        if (((TObjPlayer *)player)->can_inventory_accept_item((u8 *)(&item)) > 0) {
            ((TObjPlayer *)player)->request_inventory_item((TItemData*)(&item));
            qst_registers[arg1] = item.id;
        } else {
            qst_registers[arg1] = -1;
        }
    } else {
        qst_registers[arg1] = -1;
    }
}

void qst_op_item_create(u8 arg0, u8 arg1) {
    Item_801EEE68 item;
    void *player;
    player = (void *)get_player_by_client_id(local_client_id);
    if (player != NULL) {
        init__9TItemDataFv((Item_801EE77C *)(&item));
        item.data[0] = qst_registers[(u8)arg0++];
        item.data[1] = qst_registers[(u8)arg0++];
        item.data[2] = qst_registers[(u8)arg0];
        item.id = advance_item_id_counter(local_client_id);
        if (((TObjPlayer *)player)->can_inventory_accept_item((u8 *)(&item)) > 0) {
            ((TObjPlayer *)player)->request_inventory_item((TItemData*)(&item));
            qst_registers[arg1] = item.id;
        } else {
            qst_registers[arg1] = -1;
        }
    } else {
        qst_registers[arg1] = -1;
    }
}
extern "C" {

void qst_op_del_obj_param(s32 arg0) {
    delete_by_param__13TQuestColCtrlFl((int) (qst_registers[(u8)arg0]), qst_registers);
}

void qst_op_pl_add_meseta2() {
    s32 amount;
    u32 ret;

    amount = qst_args[0];
    ret = get_player_by_client_id(local_client_id);
    if (ret != 0U) {
        ((TObjPlayer *)ret)->add_meseta(amount);
    }
}
}

void qst_op_pl_add_meseta(void) {
    s32 amount;
    u32 player;
    amount = qst_args[1];
    player = get_player_by_client_id((s32)((int) (qst_args[0])));
    if (player != 0U) {
        ((TObjPlayer *)player)->add_meseta((s32)(amount));
    }
}
extern "C" {

int qst_op_clr_qt_cancel(void) { return set_quest_cancel_callback((void*)(-1)); }

int qst_op_clr_qt_success(void) { return set_quest_success_callback((void*)(-1)); }
}

int qst_op_clr_qt_failure(void) { return THunterGuildSeqOffline__sub_801F3748((void*)(-1)); }

void qst_op_set_qt_cancel(u16 arg0) {
    set_quest_cancel_callback((void *)arg0);
}

void qst_op_set_qt_success(u16 arg0) {
    set_quest_success_callback((void *)arg0);
}

void qst_op_set_qt_failure(u16 arg0) {
    THunterGuildSeqOffline__sub_801F3748((void *)arg0);
}

void qst_op_clr_floor_handler(void) {
    clear_floor_handler((qst_args[0]));
}

void qst_op_set_floor_handler(void) {
    set_floor_handler((qst_args[0]), ((u16) qst_args[1]));
}
extern "C" {

void qst_op_pcam_param(u8 arg0) {
    s32 i = arg0;
    Vec_801EF134 a;
    Vec_801EF134 b;

    a.x = qst_registers[i++];
    a.y = qst_registers[i++];
    a.z = qst_registers[i++];
    b.x = qst_registers[i++];
    b.y = qst_registers[i++];
    b.z = qst_registers[i];
    request_follow_camera_offsets(&a, &b, 0xFFFF);
}

int qst_op_clear_mainwarp_all(void* p) { return clear_enabled_main_warps(p); }

void qst_op_clear_mainwarp() {
    clear_active_bit__16TObjCityMainWarpFv((int) (qst_args[0]));
}
}

void qst_op_set_mainwarp(void) {
    s32 temp_r31;
    temp_r31 = qst_args[0];
    TObjCityMainWarp::set_active_bit((int) (qst_args[0]));
    TObjDoor::set_main_warp_id(temp_r31);
}
extern "C" {

void qst_op_set_bgm() {
    TQuestBgmCtrl::force_bgm((int) (qst_args[0]));
}
}

void qst_op_playbgm_epi(void) {
    TQuestBgmCtrl::defer_bgm((int) (qst_args[0]));
}

void qst_op_switch_off(void) {
    clear_current_floor_switch(((u16) qst_args[0]));
}

void qst_op_switch_on(void) {
    set_current_floor_switch(((u16) qst_args[0]));
}

void qst_op_npc_talk_kill(void) {
    TLobby__sub_80190FD0((qst_args[0]));
}
void qst_op_npc_talk_pl(u8 arg0) {
    s32 i;
    NpcSet_801EF3B4 set;

    ((void (*)(NpcSet_801EF3B4 *))TLobby__sub_80207F30)(&set);
    i = arg0;
    set.x = qst_registers[i++];
    set.y = qst_registers[i++];
    set.z = qst_registers[i++];
    set.f24 = qst_registers[i++];
    set.f1C = (*(f32 *)&lbl_805DC4CC) * qst_registers[i++];
    set.f30 = qst_registers[i++];
    set.f34 = qst_registers[i++];
    set.f38 = qst_registers[i];
    TLobby::create_npc(&set);
}

void qst_op_p_talk_guild(void) {
    if (get_player_by_client_id((s32)((int) (qst_args[0]))) != 0U) {
        handle_main_phase__6TLobbyFl();
    }
}

void qst_op_p_return_guild(void) {
    u32 player = get_player_by_client_id(local_client_id);
    if (player != 0U) {
        prepare_guild_return__10TObjPlayerFPv(player, 0);
    }
}
extern "C" {

int qst_op_npc_text_clear_all(void *p) { return clear_partner_dialogue_flags(p); }

void qst_op_load_midi() { TLobby::free_luker_object(); TLobby__sub_80197F74(); TLobby::clear_quest_vm_flag(); }

void qst_op_load_pvr() { TLobby::free_luker_object(); load_memcard_file(); TLobby::clear_quest_vm_flag(); }

void qst_op_npc_text() {
    set_partner_common_remark((qst_args[0]), (const char *)(qst_args[1]));
}
}

void qst_op_nop_A0_debug(void) {
    char buf[0x200];
    VObj_18 *o;
    void *s = *(void **)&qst_args[1];
    o = (VObj_18 *)((void * (*)(u32, void *))__nw__7TObjectFUl)(0x10A8, qst_args);
    if (o != NULL) {
        o = ((VObj_18 * (*)(void *, void *, void *, void *))construct__13TUnk_804CC048FPvPvPv)(o, 0, 0, 0);
    }
    buf[0x1FF] = 0;
    ((void (*)(void *, void *, int))strncpy)(buf, s, 0x1FF);
    ((TLobby *)buf)->trim_whitespace();
    ((TLobby *)o)->parse_csv_line(buf);
    if (o->f109c != 2) {
        while (1) {}
    }
    if (o != NULL) {
        o->m0(1);
    }
}
int qst_op_cine_disable(void) { return reset_state__9TCineCtrlFl((void*)(0)); }

int qst_op_cine_enable(void) { return reset__9TCineCtrlFl((void*)(0)); }

void qst_op_hud_show(void) { ((TWindowCtrl *)(*(int *)&local_client_id))->unsuppress_slot(); TRaderMapCore::show_radar(); }

void qst_op_hud_hide(void) { ((TWindowCtrl *)(*(int *)&local_client_id))->suppress_slot(); TRaderMapCore::hide_radar(); }
extern "C" {

int qst_op_pl_pkon(void* p) { return notify_all_battle_players__10TObjPlayerFv(p); }

int qst_op_pl_pkoff(void* p) { return update_4p_battle_ctrls__10TObjPlayerFv(p); }

int qst_op_npc_chkwarp(void* p) { return fn_8019608C(p); }

void qst_op_check_npc_straggle(u8 i) {
    u8 start = i;
    Vec_801EF7A8 v;
    Spawn_801EF7A8 s;
    void *obj;

    ((void (*)(Spawn_801EF7A8 *))TLobby__sub_80207F30)(&s);
    s.x = qst_registers[i++];
    s.y = qst_registers[i++];
    s.z = qst_registers[i++];
    s.a = qst_registers[i++];
    s.c = qst_registers[i++];
    s.b = qst_registers[i++];
    obj = ((void * (*)(Spawn_801EF7A8 *, s32 *))create_quest_col_apc_inw__6TLobbyFPvPv)(&s, &qst_registers[start]);
    if (obj != NULL) {
        v.x = qst_registers[i++];
        v.y = qst_registers[i++];
        v.z = qst_registers[i];
        ((void (*)(void *, Vec_801EF7A8 *))TLobby__sub_801F3500)(obj, &v);
    }
}
}

void qst_op_set_obj_param(u8 arg0, u8 arg1) {
    NpcSet_801EF944 set;

    ((void (*)(NpcSet_801EF944 *))TLobby__sub_80207F30)(&set);
    set.x = qst_registers[(u8)arg0++];
    set.y = qst_registers[(u8)arg0++];
    set.z = qst_registers[(u8)arg0++];
    set.f24 = qst_registers[(u8)arg0++];
    set.f30 = qst_registers[(u8)arg0++];
    set.f28 = qst_registers[(u8)arg0];
    ((void (*)(NpcSet_801EF944 *, s32 *))create_quest_col_alock)(&set, &qst_registers[arg1]);
}

void qst_op_col_npcinr(u8 arg0) {
    NpcSet_801EFA5C set;
    u8 first;

    ((void (*)(NpcSet_801EFA5C *))TLobby__sub_80207F30)(&set);
    first = arg0;
    set.x = qst_registers[(u8)arg0++];
    set.y = qst_registers[(u8)arg0++];
    set.z = qst_registers[(u8)arg0++];
    set.f24 = qst_registers[(u8)arg0++];
    set.f28 = qst_registers[(u8)arg0++];
    set.f30 = qst_registers[(u8)arg0];
    ((void (*)(NpcSet_801EFA5C *, s32 *))fn_80196214)(&set, &qst_registers[first]);
}

void qst_op_npc_coords_call(u8 arg0) {
    NpcSet_801EFB6C set;
    u8 first;

    ((void (*)(NpcSet_801EFB6C *))TLobby__sub_80207F30)(&set);
    first = arg0;
    set.x = qst_registers[(u8)arg0++];
    set.y = qst_registers[(u8)arg0++];
    set.z = qst_registers[(u8)arg0++];
    set.f24 = qst_registers[(u8)arg0++];
    set.f30 = qst_registers[(u8)arg0];
    ((void (*)(NpcSet_801EFB6C *, s32 *))fn_801963A8)(&set, &qst_registers[first]);
}

void qst_op_at_coords_talk(u8 arg0) {
    NpcSet_801EFC54 set;
    u8 first;

    ((void (*)(NpcSet_801EFC54 *))TLobby__sub_80207F30)(&set);
    first = arg0;
    set.x = qst_registers[(u8)arg0++];
    set.y = qst_registers[(u8)arg0++];
    set.z = qst_registers[(u8)arg0++];
    set.f24 = qst_registers[(u8)arg0++];
    set.f30 = qst_registers[(u8)arg0];
    ((void (*)(NpcSet_801EFC54 *, s32 *))fn_80196814)(&set, &qst_registers[first]);
}

void qst_op_at_coords_call(u8 arg0) {
    NpcSet_801EFD3C set;
    u8 first;

    ((void (*)(NpcSet_801EFD3C *))TLobby__sub_80207F30)(&set);
    first = arg0;
    set.x = qst_registers[(u8)arg0++];
    set.y = qst_registers[(u8)arg0++];
    set.z = qst_registers[(u8)arg0++];
    set.f24 = qst_registers[(u8)arg0++];
    set.f30 = qst_registers[(u8)arg0];
    ((void (*)(NpcSet_801EFD3C *, s32 *))create_quest_col)(&set, &qst_registers[first]);
}

#pragma push
#pragma fp_contract on
void qst_op_gettime(u8 arg0) {
    s32 spC;
    s32 sp8;
    getDateStamp((DateStamp *)(&spC));
    DateToSeconds((DateStamp *)(&spC), (int *)(&sp8));
    qst_registers[arg0] = sp8;
}
#pragma pop
extern "C" {

void qst_op_unhide_ene(s32 arg0) {
    s32 v0 = qst_registers[(u8)arg0];
    s32 v1 = qst_registers[(u8)++arg0];
    s32 v2 = qst_registers[(u8)++arg0];
    unhide_enemies_at__6TLobbyFlll(v0, (s16)v1, (s16)v2, arg0);
}

void qst_op_unhide_obj(s32 arg0) {
    s32 v0 = qst_registers[(u8)arg0];
    s32 v1 = qst_registers[(u8)++arg0];
    s32 v2 = qst_registers[(u8)++arg0];
    unhide_room_set_objects(v0, (s16)v1, (s16)v2, arg0);
}
}

void qst_op_chk_ene_num(int a0) { qst_registers[(unsigned char)(a0)] = TLobby::count_quest_enemies_flag8(); }

void qst_op_if_zone_clear(s32 arg0, s32 arg1) {
    if (is_room_enemy_set_cleared((int) (qst_registers[(u8)arg1]), (int) ((s16) qst_registers[(u8)(arg1 + 1)]), qst_registers) != 0) {
        qst_registers[(u8)arg0] = 1;
        return;
    }
    qst_registers[(u8)arg0] = 0;
}

void qst_op_p_action_enable(void) {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(s32))get_player_by_client_id)(local_client_id);
    if (temp_r3 != 0) {
        enable_action_input__10TObjPlayerFPv();
        ((TObjPlayer *)temp_r3)->action_enable_if_present();
    }
}

void qst_op_p_action_disable(void) {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(s32))get_player_by_client_id)(local_client_id);
    if (temp_r3 != 0) {
        disable_action_input__10TObjPlayerFv();
        ((TObjPlayer *)temp_r3)->release_attached_resource();
    }
}
void qst_op_pos_pipe(u8 arg0) {
    s32 i = arg0;
    Vec_801F0034 point;

    point.x = (f32)qst_registers[i++];
    point.y = (f32)qst_registers[i++];
    point.z = (f32)qst_registers[i++];
    TTecLuker::create_for_player((int)((u16)qst_registers[i]), (s32)(&point));
}

void qst_op_create_pipe(void) {
    create_quest_telepipe_for_client(((u16) qst_args[0]));
}

void qst_op_p_setpos(void) {
    Vec_801F0110 pos;
    u16 player;
    u8 reg;
    u8 i;
    void *obj;

    reg = qst_args[1];
    player = qst_args[0];
    i = reg;
    pos.x = qst_registers[i++];
    pos.y = qst_registers[i++];
    pos.z = qst_registers[i++];
    send_6x24_teleport_player(player, &pos, lbl_805DC4CC * qst_registers[i]);
    obj = (void *)((s32 (*)(s32))get_player_by_client_id)(player);
    if (obj != NULL && player == local_client_id) {
        reset_cameras_to_actor(obj, 0);
    }
}

void qst_op_p_enablewarp(void) {
    foreach_player__10TObjPlayerFv((s32 *)(&fn_801F3480.value));
}

void qst_op_p_disablewarp(void) {
    TTecLuker::apply_all_players();
    foreach_player__10TObjPlayerFv((s32 *)((void *) fn_801F34A0));
}

void qst_op_p_dead(void) {
    s32 temp_r31;
    u8 *lobby;
    temp_r31 = qst_args[0];
    lobby = (u8 *)(((u8 *)((s32 (*)(s32))get_player_by_client_id)(qst_args[1])));
    if ((lobby != NULL) && (is_script_controlled__10TObjPlayerFv() == 0)) {
        if (obj_isState3_324__13TUnk_804806E8Fv((int)lobby) != 0) {
            if (*(s32 *)((s8 *)lobby + 0x30) & 0x800) {
                qst_registers[temp_r31] = 1;
                return;
            }
            goto block_7;
        }
        if (((TLobby *)lobby)->check_player_state_flag_2() != 0) {
            qst_registers[temp_r31] = 1;
            return;
        }
        goto block_7;
    }
block_7:
    qst_registers[temp_r31] = 0;
}

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
void qst_op_p_hpstat(void) {
    s32 reg;
    f32 pct;
    f32 limit;
    void *obj;
    f32 hp;
    s32 player;
    s32 *args = qst_args;
    s32 *regs = qst_registers;
    reg = args[0];
    pct = regs[reg];
    player = args[1];
    if (lbl_805DC4C4 == pct) {
        qst_registers[reg] = 0;
        return;
    }
    limit = lbl_805DC4D0 / pct;
    obj = (void *)((s32)get_player_by_client_id(player));
    if (obj != NULL) {
        hp = get_actor_hp((u8 *)obj);
        if (hp / ((TItemProShield *)obj)->get_field_2b8() < limit) {
            qst_registers[reg] = 1;
            return;
        }
    }
    qst_registers[reg] = 0;
}
#pragma pop
void qst_op_p_move(u8 arg0) {
    Vec_801F0458 pos;
    s32 i = arg0;
    s32 yaw;
    u16 id;

    pos.x = (f32) qst_registers[i++];
    pos.y = (f32) qst_registers[i++];
    pos.z = (f32) qst_registers[i++];
    yaw = (s32) (lbl_805DC4CC * (f32) qst_registers[i++]);
    id = qst_registers[i++];
    send_stop_at_position__10TNpcPlayerFUsPvs(id, &pos, yaw);
}

void qst_op_p_look_at(void) {
    quest_player_face_actor((u16) qst_args[0], (u16) qst_args[1]);
}
extern "C" {

void qst_op_player_effect_nc(u8 arg0) {
    Vec_801F0574 v;
    u16 id;
    s16 kind;
    s32 extra;
    f32 dy;
    u8 *p;
    u32 r;
    s32 i;

    i = arg0;
    kind = qst_registers[i++];
    extra = qst_registers[i++];
    id = qst_registers[i++];
    dy = qst_registers[i];
    p = (u8 *)find_entity_by_id(id);
    if (p != NULL) {
        VecCopy__FP3VecPC3Vec(&v, p + 0x38);
        v.y += dy;
        r = (u32)create_timed_particle_emitter(&v, kind, 0, extra);
        if (r != 0) {
            ((TBoss4Type2 *)r)->set_flags(0x40);
        }
    }
}

s32 find_card_file__15TAdPlayerLoadGCFiPv(s32, const char *);
extern const char lbl_80449CC8[];
void qst_op_has_ep3_save_file() {
    u8 reg = qst_args[0];
    s32 ok = 0;
    if (((TAdPlayerLoadGC *)0)->probe_card_slot() != 0 && find_card_file__15TAdPlayerLoadGCFiPv(0, lbl_80449CC8) == 0 && TAdPlayerLoadGC::get_load_result((void *)0) == 0) {
        ok = 1;
    }
    if (ok == 0 && ((TAdPlayerLoadGC *)1)->probe_card_slot() != 0 && find_card_file__15TAdPlayerLoadGCFiPv(1, lbl_80449CC8) == 0 && TAdPlayerLoadGC::get_load_result((void *)1) == 0) {
        ok = 1;
    }
    qst_registers[reg] = ok;
}
}

void qst_op_particle_id(u8 first) {
    Vec_801F0710 point;
    s32 i = first;
    s16 effect = (s16) qst_registers[i++];
    s32 lifetime = qst_registers[i++];
    u16 id = (u16) qst_registers[i++];
    f32 height = (f32) qst_registers[i];
    s32 actor = (s32)find_entity_by_id(id);
    if (actor != 0) {
        ((void (*)(Vec_801F0710 *, const Vec_801F0710 *))VecCopy__FP3VecPC3Vec)(&point, (const Vec_801F0710 *) (actor + 0x38));
        point.y += height;
        create_timed_particle_emitter(&point, effect, 0, lifetime);
    }
}
extern "C" {

void qst_op_particle_effect_nc(u8 arg0) {
    Vec_801F07D8 v;
    s32 i;
    f32 x;
    f32 y;
    f32 z;
    s16 kind;
    s32 extra;
    u32 r;

    i = arg0;
    x = qst_registers[i++];
    y = qst_registers[i++];
    z = qst_registers[i++];
    kind = qst_registers[i++];
    extra = qst_registers[i];
    v.x = x;
    v.y = y;
    v.z = z;
    r = (u32)create_timed_particle_emitter(&v, kind, 0, extra);
    if (r != 0) {
        ((TBoss4Type2 *)r)->set_flags(0x40);
    }
}

void qst_op_particle(u8 arg0) {
    Vec_801F08AC v;
    s32 i;
    f32 x;
    f32 y;
    f32 z;
    s16 kind;
    s32 extra;

    i = arg0;
    x = qst_registers[i++];
    y = qst_registers[i++];
    z = qst_registers[i++];
    kind = qst_registers[i++];
    extra = qst_registers[i];
    v.x = x;
    v.y = y;
    v.z = z;
    create_timed_particle_emitter(&v, kind, 0, extra);
}

void qst_op_particle2() {
    Vec3_801F0970 v;
    f32* p = &((f32*)qst_registers)[qst_args[0]];
    v.x = p[0];
    v.y = p[1];
    v.z = p[2];
    u32 r = (u32)create_timed_particle_emitter(&v, qst_args[1], 0, (s32)*(f32 *)&qst_args[2]);
    if (r != 0) {
        ((TBoss4Type2 *)r)->set_flags(0x40);
    }
}
}

void qst_op_pl_walk(u8 arg0) {
    WalkCmd_801F09EC cmd;
    f32 x;
    f32 z;
    u16 player;
    Obj_801F09EC *obj;
    s32 i;

    i = arg0;
    x = qst_registers[i++];
    i++;
    z = qst_registers[i++];
    player = qst_registers[i];
    obj = (Obj_801F09EC *)((s32 (*)(s32))get_player_by_client_id)(player);
    if (obj != NULL) {
        init_6x40_walk_packet(&cmd);
        cmd.player = player;
        cmd.x = x;
        cmd.z = z;
        cmd.flags = 0;
        if (obj->f30 & 0x100000) {
            cmd.flags |= 8;
        }
        ((TNpcPlayer *)(&cmd))->sync_from_lobby();
    }
}

void qst_op_p_look(void) {
    quest_player_look_at_partner((u16) qst_args[0]);
}
int qst_op_p_col(void* p) { return TObjHashiVersus2__sub_801912A4(p); }

int qst_op_p_noncol(void* p) { return TObjHashiVersus2__sub_801912B0(p); }

void qst_op_enable_movement1(void) {
    TNpcPlayer::send_code_45_to_player((u16) qst_args[0]);
}

void qst_op_disable_movement1(void) {
    TNpcPlayer::play_effect((u16) qst_args[0]);
}
int qst_op_npc_talk(void* p) { return enable_partner_chatter__10TNpcPlayerFv(p); }

int qst_op_npc_nont(void* p) { return disable_partner_chatter__10TNpcPlayerFv(p); }

void qst_op_npc_kill(void) {
    quest_remove_npc_player(((u16) qst_args[0]));
}
int qst_op_cam_adj(void* p) { return set_active_camera_flag__11TCameraCtrlFv(p); }

void qst_op_cam_pan(u8 reg) {
    s32 r = reg;
    Vec pos;
    pos.x = qst_registers[r++];
    pos.y = qst_registers[r++];
    pos.z = qst_registers[r++];
    {
        s32 arg1 = qst_registers[r++];
        s32 arg2 = qst_registers[r];
        TCameraCtrl::create((s32)&pos, arg1, arg2);
    }
}

void qst_op_nop_86(void) {  }

void qst_op_nop_85(void) {  }
int qst_op_cam_zmout(void* p) { return end_conversation_camera(p); }

int qst_op_cam_zmin(void* p) { return begin_conversation_camera(p); }

int qst_op_cam_quake(void) { return set_shake_preset__11TCameraCtrlFl((void*)(2)); }

void qst_op_npc_play(void) {
    send_npc_control_6x69__10TNpcPlayerFs((int) ((s32) (u16) qst_args[0]));
}

void qst_op_npc_stop(void) {
    send_npc_stop_6x69__10TNpcPlayerFs((int) ((s32) (u16) qst_args[0]));
}
void qst_op_npc_crp_id(u8 first) {
    f32 pos[3];
    int heading;
    int leader;
    int appearance;
    int slot;
    int i = first;

    pos[0] = (f32)qst_registers[i++];
    pos[1] = (f32)qst_registers[i++];
    pos[2] = (f32)qst_registers[i++];
    heading = (int)(lbl_805DC4CC * (f32)qst_registers[i++]);
    leader = qst_registers[i++];
    slot = qst_registers[i++];
    appearance = qst_registers[i++];
    TLobby::free_luker_object();
    TNpcPlayer::create_companion(leader, slot, appearance, pos, heading);
    TLobby::clear_quest_vm_flag();
}

void qst_op_npc_crp(u8 first) {
    f32 pos[3];
    int heading;
    int leader;
    int appearance;
    int i = first;

    pos[0] = (f32)qst_registers[i++];
    pos[1] = (f32)qst_registers[i++];
    pos[2] = (f32)qst_registers[i++];
    heading = (int)(lbl_805DC4CC * (f32)qst_registers[i++]);
    leader = qst_registers[i++];
    appearance = qst_registers[i++];
    TLobby::free_luker_object();
    create_default_companion__10TNpcPlayerFssPUcl(leader, appearance, pos, heading);
    TLobby::clear_quest_vm_flag();
}

extern "C" {
u8 *load_npc_player_template(s32 appearance);
u8 *construct_player_instance__10TObjPlayerFlslPUc(void *self, s32 parent, s32 slot, s32 role, u8 *data);
void set_arrival_override_coords(u16 slot, s32 heading, f32 x, f32 y, f32 z);
void queue_player_injured_pose(s32 arg0);
void set_player_quest_control_flag(TObjPlayer *player);
}
void qst_op_npc_crptalk_id(u8 first);
void qst_op_npc_crptalk(u8 first);

void qst_op_npc_crptalk_id(u8 first) {
    f32 pos[3];
    TObjPlayer *player;
    int heading;
    int slot;
    int appearance;
    int i = first;
    u32 injured;

    pos[0] = (f32)qst_registers[i++];
    pos[1] = (f32)qst_registers[i++];
    pos[2] = (f32)qst_registers[i++];
    heading = (int)(lbl_805DC4CC * (f32)qst_registers[i++]);
    injured = qst_registers[i++];
    appearance = qst_registers[i++];
    slot = qst_registers[i++];
    TLobby::free_luker_object();
    player = (TObjPlayer *)TObject::operator new(0xDB8);
    if (player != NULL) {
        player = (TObjPlayer *)construct_player_instance__10TObjPlayerFlslPUc(player, (s32)tl_03, slot, 6, load_npc_player_template(appearance));
    }
    if (player != NULL) {
        *(s16 *)((u8 *)player + 0x324) = 6;
        send_6x24_teleport_player(slot, pos, heading);
        set_arrival_override_coords(slot, heading, pos[0], pos[1], pos[2]);
        player->reset_motion_fields();
        if (injured == 1) {
            queue_player_injured_pose((s32)player);
            set_player_quest_control_flag(player);
        }
    }
    TLobby::clear_quest_vm_flag();
}

void qst_op_npc_crptalk(u8 first) {
    f32 pos[3];
    TObjPlayer *player;
    int heading;
    int appearance;
    int i = first;
    u32 injured;

    pos[0] = (f32)qst_registers[i++];
    pos[1] = (f32)qst_registers[i++];
    pos[2] = (f32)qst_registers[i++];
    heading = (int)(lbl_805DC4CC * (f32)qst_registers[i++]);
    injured = qst_registers[i++];
    appearance = qst_registers[i++];
    TLobby::free_luker_object();
    player = (TObjPlayer *)TObject::operator new(0xDB8);
    if (player != NULL) {
        player = (TObjPlayer *)player->construct_player_instance((s32)tl_03, 3, 6, load_npc_player_template(appearance));
    }
    if (player != NULL) {
        *(s16 *)((u8 *)player + 0x324) = 6;
        send_6x24_teleport_player(3, pos, heading);
        set_arrival_override_coords(3, heading, pos[0], pos[1], pos[2]);
        player->reset_motion_fields();
        if (injured == 1) {
            queue_player_injured_pose((s32)player);
            set_player_quest_control_flag(player);
        }
    }
    TLobby::clear_quest_vm_flag();
}

void qst_op_npc_crppk(u8 arg0) {
    Vec_801F12F0 v;
    s32 angle;
    s32 a;
    s32 b;
    s32 c;
    s32 i;

    i = arg0;
    v.x = qst_registers[i++];
    v.y = qst_registers[i++];
    v.z = qst_registers[i++];
    angle = lbl_805DC4CC * qst_registers[i++];
    a = qst_registers[i++];
    b = qst_registers[i++];
    c = qst_registers[i];
    TLobby::free_luker_object();
    send_npc_control_create__10TNpcPlayerFsUssPUcl(a, c, b, &v, angle);
    TLobby::clear_quest_vm_flag();
}

void qst_op_npc_crtpk(void) {
    s32 a = qst_args[0];
    s32 b = qst_args[1];
    TLobby::free_luker_object();
    send_npc_control_notify_players__10TNpcPlayerFsUss(a & 0xFFFF, 1, b);
    TLobby::clear_quest_vm_flag();
}
extern "C" {

void qst_op_npc_param() {
    Npc_801F1450 s;
    u8 i;
    s32 flags;
    s32 arg;

    i = qst_args[0];
    arg = qst_args[1];
    s.h0 = qst_registers[i++];
    s.h2 = qst_registers[i++];
    switch (qst_registers[i++]) {
    case 0:
        flags = 0x40;
        break;
    case 1:
        flags = 4;
        break;
    case 2:
        flags = 8;
        break;
    case 3:
    case 10:
        flags = 0xC0;
        break;
    case 11:
        flags = 0x84;
        break;
    case 12:
        flags = 0x88;
        break;
    case 13:
        flags = 0x90;
        break;
    }
    s.flags = flags;
    s.f8 = qst_registers[i++];
    s.fC = qst_registers[i++];
    s.f10 = qst_registers[i++];
    s.f14 = qst_registers[i++];
    s.f18 = qst_registers[i++];
    s.f1C = qst_registers[i++];
    s.b20 = qst_registers[i++];
    s.b21 = qst_registers[i++];
    s.b22 = qst_registers[i++];
    s.b23 = qst_registers[i++];
    s.f24 = qst_registers[i];
    ((TNpcPlayer *)(&s))->copy_entry_by_index(arg);
}
}

void qst_op_npc_crt(void) {
    s32 *var_r3;
    s32 var_r4;
    TLobby::free_luker_object();
    var_r3 = (s32 *)qst_args;
    var_r3 = (s32 *)qst_args;
    var_r4 = qst_args[1];
    var_r3 = (s32 *)((u8 *)((s32 *) (u16) qst_args[0]));
    send_npc_create__10TNpcPlayerFss((int)var_r3, (int)var_r4);
    TLobby::clear_quest_vm_flag();
}

void qst_op_winend(void) {
    if ((void *) TLobby__quest_message_window != NULL) {
        TWindow__close((TLobby__quest_message_window));
        TLobby__quest_message_window = NULL;
    }
    TWindowCtrl::clear_flag_bit2();
    TLobby__sub_8024AC20((local_client_id));
    TWindowCtrl::clear_flag();
    TWindowCtrl::clear_flag_2();
}

void qst_op_mesend(void) {
    s32 id;
    void *p;
    s32 start;
    s32 end;
    s32 i;
    s32 f;
    s32 v;
    TLobby__sub_8024AC20(local_client_id);
    TWindowCtrl::clear_flag();
    TWindowCtrl::clear_flag_2();
    id = quest_message_speaker_id;
    if (id < 100) {
        ((void (*)(u16))close_windows_by_flags__11TWindowCtrlFUs)(id);
        return;
    }
    start = TLobby::get_game_mode();
    end = start + TLobby::get_lobby_flag();
    for (i = start; i < end; i++) {
        p = (void *)get_player_data__10TObjPlayerFi(i);
        if (p != NULL) {
            f = get_entity_id(p);
            if (f < 0x4000) {
                v = fn_get_field_3ac(p);
            } else {
                v = get_field_d4(p);
            }
            if (v == id) {
                ((void (*)(s32))close_windows_by_flags__11TWindowCtrlFUs)(f);
                return;
            }
        }
    }
}

void qst_op_add_msg(void) {
    s32 x = qst_args[0];
    if ((*(u8* *)&TLobby__quest_message_window) != 0) {
        dispatch_message_window_text((*(u8* *)&TLobby__quest_message_window), x, 3);
        TLobby__quest_window_state = 4;
        return;
    }
    if (TLobby__quest_secondary_window != 0) {
        ((TLobby *)TLobby__quest_secondary_window)->send_and_handle(x, 3);
        TLobby__quest_window_state = 5;
        return;
    }
    qst_args[1] = x;
    qst_args[0] = quest_message_speaker_id;
    qst_op_message();
}
extern "C" {

void qst_op_close_msg_qb(void) {
    if ((u32) TLobby__quest_secondary_window != 0U) {
        TWindow__close((u8 *)TLobby__quest_secondary_window);
        TLobby__quest_secondary_window = 0U;
    }
}
}

void qst_op_disp_msg_qb(void) {
    s32 t = qst_args[0];
    Pair_801F1838 pr = lbl_80449A38[0];
    if (TLobby__quest_secondary_window != 0) {
        TWindow__close((u8 *)((void *)TLobby__quest_secondary_window));
        TLobby__quest_secondary_window = 0;
    }
    TLobby__quest_secondary_window = update_window_mode_from_progress__6TLobbyFPv(get_window_layout_position(0x71), &pr);
    ((TLobby *)TLobby__quest_secondary_window)->send_and_handle(t, 3);
    ((TLobby *)TLobby__quest_secondary_window)->set_field_1c(lbl_805DC4D4);
    TLobby__quest_window_state = 5;
}

void qst_op_window_msg(void) {
    s32 text;
    u32 temp_r3;
    text = qst_args[0];
    if ((u32) (*(u32 *)&TLobby__quest_message_window) != 0U) {
        TWindow__close((u8 *)((int) ((*(u32 *)&TLobby__quest_message_window))));
    }
    temp_r3 = create_quest_message_window();
    (*(u32 *)&TLobby__quest_message_window) = temp_r3;
    dispatch_message_window_text((void *)temp_r3, (text), 3);
    (*(s32 *)&TLobby__quest_window_state) = 4;
    TWindowCtrl::set_flag_bit2();
    close_window_if_active((void *)local_client_id);
    request_active_window_close();
    TWindowCtrl::set_close_flag();
}

void qst_op_bgm(void) {
    play_cue_stream_file((s32)qst_bgm_filename_table[qst_args[0]]);
}

void qst_op_se(void) {
    play_sound_effect((int) (*(s32 *)((s8 *)((u8 *)(&quest_sound_effect_ids.value) + (qst_args[0] * 4)) + 0)), 0, 0, 0);
}

void qst_op_fadeout(void) { TLobby::init_fadeout_state((s32)((void*)0)); TLobby__quest_window_state = 8; }

void qst_op_fadein(void) { TLobby::set_fade_params((s32)((void*)0)); TLobby__quest_window_state = 8; }

void qst_op_list(void) {
    char *text;
    List_801F1A0C *list;
    u8 idx;
    s32 i;
    char buf[0x200];
    idx = (u32)qst_args[0];
    text = *(char **)&qst_args[1];
    list = (List_801F1A0C *)__nw__7TObjectFUl(0x10A8);
    if (list != 0) {
        list = (List_801F1A0C *)((void * (*)(void *, void *, void *, void *))construct__13TUnk_804CC048FPvPvPv)(list, 0, 0, 0);
    }
    ((char * (*)(char *, const char *, u32))strncpy)(buf, text, 0x1FF);
    ((TLobby *)buf)->trim_whitespace();
    ((TLobby *)list)->tokenize_args(buf);
    TLobby__quest_choice_window = check_room_seq_4__16TAdChrSelASlotGCFl(get_window_layout_position(0x37), list->count);
    for (i = 0; i < list->count; i++) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)TLobby__quest_choice_window, (int)list->names[i], 7, (int)i);
    }
    ((TWindowSubComCard *)TLobby__quest_choice_window)->calc_window_size();
    align_menu_entry_positions(TLobby__quest_choice_window);
    ((TCheckRoomSequence *)TLobby__quest_choice_window)->set_ready_flag();
    ((TLobby *)TLobby__quest_choice_window)->set_field_1c(lbl_805DC4D8);
    qst_registers[idx] = 0;
    TLobby__active_window_index = idx;
    TLobby__quest_window_state = 7;
    close_window_if_active((void *)local_client_id);
    request_active_window_close();
    TWindowCtrl::set_close_flag();
    delete list;
}

void qst_op_message(void) {
    s32 speaker = qst_args[0];
    s32 text = qst_args[1];
    s32 first;
    void *actor;
    s32 end;
    s32 i;
    close_window_if_active((void *)local_client_id);
    request_active_window_close();
    TWindowCtrl::set_close_flag();
    quest_message_speaker_id = speaker;
    if (speaker < 100) {
        TWindowCtrl::open(speaker & 0xFFFF, text, 0x2D);
        ((void (*)(s32))set_field28__11TWindowCtrlFs)((u16)speaker);
        TLobby__quest_window_state = 4;
    } else {
        first = TLobby::get_game_mode();
        end = first + TLobby::get_lobby_flag();
        for (i = first; i < end; i++) {
            actor = (void *)get_player_data__10TObjPlayerFi(i);
            if (actor != NULL) {
                s32 identity = get_entity_id(actor);
                s32 entity;
                if (identity < 0x4000) {
                    entity = fn_get_field_3ac(actor);
                } else {
                    entity = get_field_d4(actor);
                }
                if (entity == speaker) {
                    TWindowCtrl::open(identity, text, 0x2D);
                    ((void (*)(s32))set_field28__11TWindowCtrlFs)(identity);
                    TLobby__quest_window_state = 4;
                    break;
                }
            }
        }
    }
}
extern "C" {

void qst_op_stack_popm(s32 arg0, s32 arg1) {
    s32 n = arg1;
    u8 j = arg0 + arg1;
    while (n > 0) {
        int v = qst_call_stack_pop();
        j--;
        qst_registers[j] = v;
        n--;
    }
}

void qst_op_stack_pushm(s32 arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        qst_call_stack_push(qst_registers[(u8)arg0++]);
    }
}

void qst_op_stack_pop(int a0) { qst_registers[(unsigned char)(a0)] = qst_call_stack_pop(); }

void qst_op_stack_push(s32 arg0) {
    qst_call_stack_push((int) (qst_registers[(u8)arg0]));
}
}

void qst_op_switch_call(s32 arg0, u8 arg1, s32 arg2) {
    s32 temp_r3;
    temp_r3 = qst_registers[(u8)arg0];
    if ((temp_r3 < (s32) arg1) && (temp_r3 >= 0)) {
        qst_op_call((u16)((int) (*(u16 *)((s8 *)(arg2 + (temp_r3 * 2)) + 0))));
    }
}

void qst_op_switch_jmp(s32 arg0, u8 arg1, s32 arg2) {
    s32 temp_r3;
    temp_r3 = qst_registers[(u8)arg0];
    if ((temp_r3 < (s32) arg1) && (temp_r3 >= 0)) {
        qst_op_jmp((int) (*(u16 *)((s8 *)(arg2 + (temp_r3 * 2)) + 0)));
    }
}

void qst_op_jmpi_le(s32 arg0, s32 arg1, s32 arg2) {
    if ((s32) qst_registers[(u8)arg0] <= arg1) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_jmp_le(s32 arg0, s32 arg1, s32 arg2) {
    if ((s32) qst_registers[(u8)arg0] <= (s32) qst_registers[(u8)arg1]) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_ujmpi_le(s32 arg0, u32 arg1, s32 arg2) {
    if ((u32) qst_registers[(u8)arg0] <= arg1) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_ujmp_le(s32 arg0, s32 arg1, s32 arg2) {
    if ((u32) qst_registers[(u8)arg0] <= (u32) qst_registers[(u8)arg1]) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_jmpi_ge(s32 arg0, s32 arg1, s32 arg2) {
    if ((s32) qst_registers[(u8)arg0] >= arg1) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_jmp_ge(s32 arg0, s32 arg1, s32 arg2) {
    if ((s32) qst_registers[(u8)arg0] >= (s32) qst_registers[(u8)arg1]) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_ujmpi_ge(s32 arg0, u32 arg1, s32 arg2) {
    if ((u32) qst_registers[(u8)arg0] >= arg1) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_ujmp_ge(s32 arg0, s32 arg1, s32 arg2) {
    if ((u32) qst_registers[(u8)arg0] >= (u32) qst_registers[(u8)arg1]) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_jmpi_lt(s32 arg0, s32 arg1, s32 arg2) {
    if ((s32) qst_registers[(u8)arg0] < arg1) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_jmp_lt(s32 arg0, s32 arg1, s32 arg2) {
    if ((s32) qst_registers[(u8)arg0] < (s32) qst_registers[(u8)arg1]) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_ujmpi_lt(s32 arg0, u32 arg1, s32 arg2) {
    if ((u32) qst_registers[(u8)arg0] < arg1) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_ujmp_lt(s32 arg0, s32 arg1, s32 arg2) {
    if ((u32) qst_registers[(u8)arg0] < (u32) qst_registers[(u8)arg1]) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_jmpi_gt(s32 arg0, s32 arg1, s32 arg2) {
    if ((s32) qst_registers[(u8)arg0] > arg1) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_jmp_gt(s32 arg0, s32 arg1, s32 arg2) {
    if ((s32) qst_registers[(u8)arg0] > (s32) qst_registers[(u8)arg1]) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_ujmpi_gt(s32 arg0, u32 arg1, s32 arg2) {
    if ((u32) qst_registers[(u8)arg0] > arg1) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_ujmp_gt(s32 arg0, s32 arg1, s32 arg2) {
    if ((u32) qst_registers[(u8)arg0] > (u32) qst_registers[(u8)arg1]) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_jmpi_ne(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 != (s32) qst_registers[(u8)arg0]) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_jmp_ne(s32 arg0, s32 arg1, s32 arg2) {
    if ((s32) qst_registers[(u8)arg0] != (s32) qst_registers[(u8)arg1]) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_jmpi_eq(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == (s32) qst_registers[(u8)arg0]) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}

void qst_op_jmp_eq(s32 arg0, s32 arg1, s32 arg2) {
    if ((s32) qst_registers[(u8)arg0] == (s32) qst_registers[(u8)arg1]) {
        qst_pc = qst_function_table[(u16)arg2];
    }
}
extern "C" {

void qst_op_jmp_off(s32 arg0, u8 arg1, u8 *arg2) {
    s32 all_off = 1;
    while (arg1 != 0) {
        u8 reg = *arg2;
        arg1--;
        arg2++;
        all_off &= (u8) ((s32) qst_registers[(u8)reg] == 0);
    }
    if (all_off != 0) {
        qst_pc = qst_function_table[(u16)arg0];
    }
}

void qst_op_jmp_on(s32 arg0, u8 arg1, u8 *arg2) {
    s32 i;
    for (i = 0; i < arg1; i++) {
        if ((s32) qst_registers[(u8)*arg2++] == 0) {
            return;
        }
    }
    qst_pc = qst_function_table[(u16)arg0];
}
}

#pragma push
#pragma fp_contract on
void qst_op_call(u16 arg0) {
    qst_call_stack_push((int)((void *) (qst_pc)));
    qst_pc = qst_function_table[arg0];
}
#pragma pop

void qst_op_modi(s32 arg0, u32 arg1) {
    qst_registers[(u8)arg0] %= arg1;
}
extern "C" {

void qst_op_mod(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] %= qst_registers[(u8)arg1];
}
}

void qst_op_jmp(int a0) { qst_pc = qst_function_table[(u16)a0]; }

void qst_op_xori(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] ^= arg1;
}

void qst_op_xor(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] ^= qst_registers[(u8)arg1];
}

void qst_op_ori(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] |= arg1;
}

void qst_op_or(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] |= qst_registers[(u8)arg1];
}

void qst_op_andi(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] &= arg1;
}

void qst_op_and(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] &= qst_registers[(u8)arg1];
}

void qst_op_divi(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] /= arg1;
}

void qst_op_div(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] /= (s32) qst_registers[(u8)arg1];
}

void qst_op_muli(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] *= arg1;
}

void qst_op_mul(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] *= qst_registers[(u8)arg1];
}

void qst_op_subi(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] -= arg1;
}

void qst_op_sub(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] -= qst_registers[(u8)arg1];
}

#pragma push
#pragma scheduling off
void qst_op_addi(int a0, int a1) { qst_registers[(unsigned char)(a0)] += a1; }
#pragma pop

void qst_op_add(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] += qst_registers[(u8)arg1];
}

void qst_op_gget(u16 flag, s32 arg1) {
    if (get_story_flag((flag)) != 0) {
        qst_registers[(u8)arg1] = 1;
        return;
    }
    qst_registers[(u8)arg1] = 0;
}

void qst_op_glet(u16 flag, s32 arg1) {
    if ((s32) qst_registers[(u8)arg1] != 0) {
        dispatch_by_main_phase__14TBoss4DarkFalzFUs((void *)flag);
        return;
    }
    clear_story_flag((flag));
}


void qst_op_gclear(u16 arg0);
void qst_op_gset(u16 arg0);
namespace pf2_p6 { extern "C" { s32 dispatch_by_main_phase__14TBoss4DarkFalzFUs(s32); } }
#define dispatch_by_main_phase__14TBoss4DarkFalzFUs pf2_p6::dispatch_by_main_phase__14TBoss4DarkFalzFUs
void qst_op_thread_stg(u16 arg0);
extern "C" {
u32 create__12TQuestThreadFi(s32 arg0);
}
void qst_op_thread(u16 arg0);
extern "C" {
u8 *create_quest_thread(s32 arg0);
void qst_op_rev(s32 arg0);
void qst_op_clear(s32 arg0);
void qst_op_set(s32 arg0);
void qst_op_leto(s32 arg0, s32 arg1);
}
void qst_op_leta(s32 arg0, s32 arg1);
void qst_op_let(s32 arg0, s32 arg1);
void qst_op_letw(int a0, int a1);
void qst_op_exit(void);
extern "C" {
void qst_op_grev(s32 arg0);
}
void qst_op_letb(int a0, int a1);
void qst_op_leti(int a0, int a1);
void qst_op_nop(void);
void qst_op_ret(void);
void qst_op_sync(void);
extern "C" {

void qst_op_grev(s32 arg0) {
    u16 v = arg0;
    if (get_story_flag(v) != 0) {
        clear_story_flag(v);
        return;
    }
    dispatch_by_main_phase__14TBoss4DarkFalzFUs(v);
}
}

void qst_op_gclear(u16 flag) {
    clear_story_flag((flag));
}

void qst_op_gset(u16 arg0) {
    dispatch_by_main_phase__14TBoss4DarkFalzFUs((s32)(arg0));
}
extern "C" {

void qst_op_rev(s32 arg0) {
    qst_registers[(u8)arg0] = qst_registers[(u8)arg0] == 0;
}

void qst_op_clear(s32 arg0) {
    qst_registers[(u8)arg0] = 0;
}

void qst_op_set(s32 arg0) {
    qst_registers[(u8)arg0] = 1;
}

void qst_op_leto(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] = (s32)&qst_function_table[(u16)arg1];
}
}

void qst_op_leta(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] = (s32)&qst_registers[(u8)arg1];
}

void qst_op_letw(int a0, int a1) { qst_registers[(unsigned char)(a0)] = (a1 & 0xffff); }

void qst_op_letb(int a0, int a1) { qst_registers[(unsigned char)(a0)] = (a1 & 0xff); }

void qst_op_leti(int a0, int a1) { qst_registers[(unsigned char)(a0)] = a1; }

void qst_op_let(s32 arg0, s32 arg1) {
    qst_registers[(u8)arg0] = qst_registers[(u8)arg1];
}

void qst_op_thread_stg(u16 arg0) {
    create__12TQuestThreadFi((arg0));
}

void qst_op_thread(u16 arg0) {
    create_quest_thread((arg0));
}

void qst_op_sync(void) { TLobby__quest_window_state = 1; }

void qst_op_exit(void) { TLobby__quest_window_state = 3; }

void qst_op_ret(void) {
    u32 nested = qst_call_stack_depth > 0;
    if (nested) {
        qst_pc = qst_call_stack_pop();
    }
    if (!nested) {
        TLobby__quest_window_state = 2;
    }
}

void qst_op_nop(void) {  }
extern "C" {
u16 read_be_u16(void);
s32 stream_read_be32(void);
void append_string_to_buffer(s32 arg0);
}
extern char qst_cstring_buffer[];

void qst_getargs_801F26A8(s32 op) {
    void (*fn)(u16, u8) = (void (*)(u16, u8))qst_opcode_table[op].handler;
    u16 a = read_be_u16();
    fn(a, TLobby::read_packet_byte());
}

extern "C" {
void qst_getargs_801F2700(s32 op) {
    void (*fn)(u16) = (void (*)(u16))qst_opcode_table[op].handler;
    fn(read_be_u16());
}
}

void qst_getargs_cstring(s32 op) {
    void (*fn)(char *) = (void (*)(char *))qst_opcode_table[op].handler;
    append_string_to_buffer((s32)qst_cstring_buffer);
    fn(qst_cstring_buffer);
}

typedef void (*Handler_801F27A0)(s32, u8, s16 *);
typedef void (*Handler_801F2828)(u16, u8, u8 *);

void qst_getargs_801F27A0(s32 op) {
    s16 buf[16];
    Handler_801F27A0 fn = (Handler_801F27A0) qst_opcode_table[op].handler;
    s32 first = ((s32 (*)(void))TLobby::read_packet_byte)();
    u8 count = ((s32 (*)(void))TLobby::read_packet_byte)();
    s32 i;

    for (i = 0; i < count; i++) {
        buf[i] = ((s16 (*)(void))read_be_u16)();
    }
    fn(first, count, buf);
}

extern "C" {
void qst_getargs_801F2828(s32 op) {
    u8 buf[16];
    Handler_801F2828 fn = (Handler_801F2828) qst_opcode_table[op].handler;
    u16 label = ((s32 (*)(void))read_be_u16)();
    u8 count = ((s32 (*)(void))TLobby::read_packet_byte)();
    s32 i;

    for (i = 0; i < count; i++) {
        buf[i] = ((s32 (*)(void))TLobby::read_packet_byte)();
    }
    fn(label, count, buf);
}
}

void qst_getargs_801F28AC(s32 op) {
    void (*fn)(u8, s32, u16) = (void (*)(u8, s32, u16))qst_opcode_table[op].handler;
    u8 a = TLobby::read_packet_byte();
    s32 b = stream_read_be32();
    fn(a, b, read_be_u16());
}

void qst_getargs_801F2910(s32 op) {
    void (*fn)(u8, u8, u16) = (void (*)(u8, u8, u16))qst_opcode_table[op].handler;
    u8 a = TLobby::read_packet_byte();
    u8 b = TLobby::read_packet_byte();
    fn(a, b, read_be_u16());
}

void TLobby::dispatch_command(s32 op) {
    void (*fn)(u8, u16) = (void (*)(u8, u16))qst_opcode_table[op].handler;
    u8 a = TLobby::read_packet_byte();
    fn(a, read_be_u16());
}

void qst_getargs_801F29CC(s32 op) {
    void (*fn)(u16) = (void (*)(u16))qst_opcode_table[op].handler;
    fn(read_be_u16());
}

void qst_getargs_801F2A14(s32 op) {
    void (*fn)(s32) = (void (*)(s32))qst_opcode_table[op].handler;
    fn(stream_read_be32());
}

void qst_getargs_801F2A5C(s32 op) {
    void (*fn)(u8, s32) = (void (*)(u8, s32))qst_opcode_table[op].handler;
    u8 a = TLobby::read_packet_byte();
    fn(a, stream_read_be32());
}

void qst_getargs_801F2AB4(s32 op) {
    void (*fn)(u8, u8) = (void (*)(u8, u8))qst_opcode_table[op].handler;
    u8 a = TLobby::read_packet_byte();
    fn(a, TLobby::read_packet_byte());
}

extern "C" {
void qst_getargs_801F2B0C(s32 op) {
    void (*fn)(u8) = (void (*)(u8))qst_opcode_table[op].handler;
    fn(TLobby::read_packet_byte());
}
}

void qst_getargs_801F2B54(s32 op) {
    qst_opcode_table[op].handler();
    qst_arg_count = 0;
}

void qst_getargs_801F2B94(s32 op) {
    qst_opcode_table[op].handler();
}

extern "C" {
s32 qst_call_stack_pop(void) {
    if (qst_call_stack_depth > 0) {
        return qst_call_stack[--qst_call_stack_depth];
    }
    return 0;
}

void qst_call_stack_push(s32 a0)
{
  qst_call_stack[qst_call_stack_depth++] = a0;
}
int qst_label_address(int a0) {  return (int)(qst_code + qst_function_table[(u16)a0]); }

namespace pf2_p12 { extern "C" { s32 expand_message_substitutions(s32, s32, s32); } }
#define expand_message_substitutions pf2_p12::expand_message_substitutions
s32 bswap_32__FPUl(s32 *, s32);
namespace pf2_p12 { extern "C" { s32 memcpy(s32 *, s32, s32); } }
#define memcpy pf2_p12::memcpy
namespace pf2_p12 { extern "C" { s32 strlen(s32, s32); } }
#define strlen pf2_p12::strlen

void append_string_to_buffer(s32 arg0) {
    s32 temp_r31;

    temp_r31 = strlen((s32)(qst_code + qst_pc), (s32)qst_code);
    expand_message_substitutions((s32)(qst_code + qst_pc), arg0, (s32)qst_code);
    qst_pc += temp_r31 + 1;
}

s32 stream_read_be32(void) {
    s32 sp8;
    s32 temp_r4;

    memcpy(&sp8, (s32)(qst_code + qst_pc), 4);
    temp_r4 = qst_pc;
    qst_pc = temp_r4 + 4;
    bswap_32__FPUl(&sp8, temp_r4);
    return sp8;
}

#undef expand_message_substitutions
#undef memcpy
#undef strlen

s32 bswap_16__FPUs(u16 *, s32);
namespace pf2_p13 { extern "C" { s32 memcpy(u16 *, s32, s32); } }
#define memcpy pf2_p13::memcpy

u16 read_be_u16(void) {
    u16 sp8;
    s32 temp_r4;

    memcpy(&sp8, (s32)(qst_code + qst_pc), 2);
    temp_r4 = qst_pc;
    qst_pc = temp_r4 + 2;
    bswap_16__FPUs(&sp8, temp_r4);
    return sp8;
}
}

#undef memcpy
