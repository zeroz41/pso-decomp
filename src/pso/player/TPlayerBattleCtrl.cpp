#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/TDuelEffectCtrl.h"
#include "pso/network/client_id.h"
#include "pso/system/memory.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include <stdio.h>
#include <stdlib.h>
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TQuestManager.h"
#include "pso/map/TSetEvtDestroy.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TDelayedAreaMusic.h"
#include "pso/player/TPlayerBattleCtrl.h"
#include "pso/player/PlayerCommands.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/player/BattleRuleConfig.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/network/TLobby.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/player/TPlayerBattleCtrl4P.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/render/ScreenSpriteDraw.h"
#include "pso/player/TObjPlayer.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TBattleProximitySound.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowDuelResult_801C2528.h"
#include "pso/audio/SoundRequests.h"
#include "pso/network/LegacyEnemyKill.h"
#include <string.h>
#include "pso/ui/Language.h"

#include "pso/object/base/TObjMotion.h"


#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/player/PlayerTrapCounts.h"
#include "pso/object/TDeadSpot.h"
#include "pso/ui/window/TWindowComCardFollower.h"
#include <dolphin/os/OSTime.h>
#include "pso/system/scene/OnlineLobbyScene.h"
#include "pso/boss/volopt/TObjVoloptCage.h"
#include "pso/effect/TIndirectEffectDrawTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/map/FloorPopulation.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/quest/QuestOpcodeHandlers.h"
#include "pso/audio/MusicControl.h"
#include "pso/network/BattleModeDataCmd.h"
#include "pso/item/FloorItemSync.h"
#include "pso/ui/window/TWindowComCardFollower.h"
// The placement ordinals show_score_results prints; their strings open the unit's .sdata2.
#pragma push
char *lobby_rank_ordinal_text_table[] = {"1st", "2nd", "3rd", "4th"};


TPlayerBattleCtrl *battle_mode_data_ptr;
s32 battle_frame_rate;
s32 battle_config_ptr;
s32 lbl_805D5DA4;
s32 lbl_805D5DA8;
s32 battle_scores_received;      // set when the 6x7F final scores arrive
s32 battle_team_report_count;   // 6x7D score reports since reset_score_counters
s32 battle_fadeout_done;         // set by the fade-out callback init_and_set_flag
void *lobby_char_slot_array;
u8 battle_player_ready_flags[4];
s32 battle_ctrl_default_value;
f32 battle_enemy_take_damage_score;
f32 battle_meseta_score;


void play_duel_result_stream(const char *file, saddr duration);

// "TPlayerBattleCtrl" opens the unit's .rodata, ahead of the pairs below.
f32 battle_player_give_damage_score = 0.05f;
f32 battle_player_take_damage_score = 0.02f;
f32 battle_player_kill_score = 10.0f;
f32 battle_player_death_score = 7.0f;
f32 battle_enemy_give_damage_score = 0.01f;
f32 battle_enemy_kill_score = 3.0f;
f32 battle_enemy_death_score = 7.0f;
const char *player_battle_ctrl_name = "TPlayerBattleCtrl";




extern "C" {


void __destroy_new_array(void *, void *);
void *__construct_new_array(void *, void *, void *, s32, s32);
void *__dt__19PlayerCharDataEntryFv(void *entry, s16 mode);
void __ct__19PlayerCharDataEntryFv(void);
}

extern s32 battle_intro_value_table[];

extern char battle_intro_message_buffer[];
void update_battle_exit_sequence(TPlayerBattleCtrl *ctrl);


#define CFG (*(BattleRuleConfig **)&battle_config_ptr)


BattleRanking duel_result_table[4];
s32 battle_team_table[4];
s16 battle_event_second_table[8];
u16 battle_mode_data_table[4];
s32 battle_intro_value_table[4];
char battle_intro_message_buffer[0x100];

TPlayerBattleCtrl::TPlayerBattleCtrl(TObject *parent) : TObject(parent) {
    TObjPlayer *player;
    m_name = player_battle_ctrl_name;
    unk_28 = 0;
    state_24 = 0;
    state_20 = 0;
    state_1c = 0;
    window_4c = NULL;
    window_50 = NULL;
    window_54 = NULL;
    text = (current_language == LANGUAGE_JAPANESE) ? player_battle_ctrl_text_japanese : player_battle_ctrl_text_english;
    player = get_local_player();
    if (player != NULL) {
        player->export_character_data(TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
    }
    stop_audio_streams();
    battle_ctrl_default = 0;
}

TPlayerBattleCtrl::~TPlayerBattleCtrl() {
    if (state_20 != -1) {
        state_20 = -1;
        update_state();
    }
    if (window_4c != NULL) window_4c->close();
    if (window_50 != NULL) window_50->close();
    if (window_54 != NULL) window_54->close();
    battle_mode_data_ptr = 0;
}

void TPlayerBattleCtrl::run_task() {
    if (TLobby::connection_lost == 0) {
        if (state_1c != state_24) {
            if (state_20 != -1) {
                state_20 = -1;
                update_state();
            }
            state_1c = state_24;
            state_20 = 0;
        }
        update_state();
    }
}

void TPlayerBattleCtrl::update_state() {
    switch (state_1c) {
    case 0:
        initialize_battle();
        return;
    case 1:
        update_battle_intro();
        return;
    case 2:
        update_timed_wait();
        return;
    case 3:
        update_duel_result();
        return;
    case 4:
        end_battle_mode_cleanup();
        return;
    case 5:
        show_lobby_transport_notice();
        return;
    case 6:
        update_battle_exit_sequence(this);
    default:
        return;
    }
}

void TPlayerBattleCtrl::initialize_battle() {
    switch (state_20) {
    case -1:
        break;
    case 0:
        init_battle_round();
        state_24 = 1;
        break;
    }
}

void TPlayerBattleCtrl::update_battle_intro() {
    switch (state_20) {
    case 0:
        if (window_4c == NULL) {
            BattleIntroWindowSize p = {328.0f, 166.0f};
            window_4c = TWindowMessage::create(get_window_layout_position(0x52), (const f32 *)(&p), 1);
        }
        lbl_805D5DA4 = 0;
        state_20 = 1;
        break;
    case 1:
        window_4c->append_line(intro_text, 0x80);
        timer = 0xF0;
        state_20 = 2;
        break;
    case 2:
        if (--timer <= 0) {
            if (lobby_rule_settings.get_is_teams() == 1) {
                state_20 = 3;
            } else {
                state_20 = 5;
            }
        }
        break;
    case 3: {
        BattleTeamTotals cnt = {0, 0};
        UpdateBattleIntroName names[4];
        s32 i;
        for (i = 0; i < 4; i++) {
            names[i].s[0] = 0;
        }
        for (i = 0; i < 4; i++) {
            TObjPlayer *pl = get_player_by_client_id(i);
            if (pl != NULL) {
                s32 team = battle_intro_value_table[i] != 1 ? 1 : 0;
                if (cnt.team[team] < 2) {
                    strncpy(names[team * 2 + cnt.team[team]].s, pl->get_name(), 0x10);
                    cnt.team[team]++;
                }
            }
        }
        sprintf(battle_intro_message_buffer, text[6], names[0].s, names[1].s, names[2].s, names[3].s);
        ((TWindowMessage *)(window_4c))->append_line(battle_intro_message_buffer, 0x80);
        timer = 0xF0;
        state_20 = 4;
        break;
    }
    case 4:
        if (--timer <= 0) {
            state_20 = 5;
        }
        break;
    case 5:
        timeout = 0x384;
        state_20 = 6;
    case 6:
        timeout--;
        if (check_all_battle_flags() != 0 || timeout <= 0) {
            window_4c->close();
            window_4c = NULL;
            send_player_ready();
            timeout = 0x1C2;
            state_20 = 7;
        }
        break;
    case 7:
        timeout--;
        if (check_all_players_ready() != 0 || timeout <= 0) {
            new TDuelEffectCtrl(this, 0);
            timer = 0x96;
            state_20 = 8;
        }
        break;
    case 8:
        if (--timer <= 0) {
            state_24 = 2;
        }
        break;
    case -1:
        if (window_4c != NULL) {
            window_4c->close();
            window_4c = NULL;
        }
        clear_battle_player_ready_flags();
        break;
    }
}

void TPlayerBattleCtrl::update_timed_wait() {
    s32 secs;
    s32 rem;
    switch (state_20) {
    case 0:
        start_duel_battle();
        state_20 = 1;
    case 1:
        if (check_team_balance(1) != 0) {
            send_battle_mode_params(5, 0, 0);
            return;
        }
        secs = (OSGetTime() - start_time) / (*(u32 *)0x800000F8 / 4);
        rem = time_limit - secs;
        time_left = rem > 0 ? rem : 0;
        TWindowCtrl::set_timer_window_time(time_left);
        if (time_left == 0) {
            state_24 = 3;
            send_battle_mode_params(3, 0, 0);
            return;
        }
        if (check_battle_end() != 0) {
            if (--end_wait <= 0) {
                state_24 = 3;
                send_battle_mode_params(3, 0, 0);
            }
        } else {
            end_wait = 300;
        }
        update_battle_sync(secs);
        if (--state_send_wait <= 0) {
            send_battle_mode_state();
            state_send_wait = 90;
        }
        calc_player_rankings();
        break;
    case -1:
        break;
    }
}

void TPlayerBattleCtrl::update_duel_result() {
    TObjPlayer *p;
    TObjPlayer *q;
    switch (state_20) {
    case 0:
        init();
        lbl_805D5DA8 = 0;
        battle_scores_received = 0;
        new TDuelEffectCtrl((TObject *)this, 1);
        timer = 0x78;
        TWindowCtrl::close_timer_window();
        TWindowCtrl::suppress_slot(local_client_id);
        state_20 = 1;
        p = get_local_player();
        if (p != NULL) {
            p->release_attached_resource();
        }
        break;
    case 1:
        p = get_local_player();
        if (p != NULL) {
            p->release_attached_resource();
        }
        if (--timer <= 0) {
            send_battle_mode_state();
            timer = 0x5A;
            state_20 = 2;
        }
        break;
    case 2:
        p = get_local_player();
        if (p != NULL) {
            p->release_attached_resource();
        }
        if (--timer <= 0) {
            timeout = 0x1C2;
            state_20 = 3;
        }
        break;
    case 3:
        p = get_local_player();
        if (p != NULL) {
            p->release_attached_resource();
        }
        if (check_timeout((timeout)--) != 0 || timeout <= 0) {
            reset_score_counters();
            calc_player_rankings();
            record_local_battle_placement(this);
            if (duel_result_table[0].client_id == local_client_id) {
                play_duel_result_stream("win.adx", 0x96);
            } else {
                play_duel_result_stream("lose.adx", 0x96);
            }
            state_20 = 4;
        }
        break;
    case 4:
        if (window_54 != NULL) {
            window_54->close();
        }
        window_54 = new TWindowDuelResult(local_client_id);
        q = get_local_player();
        if (q != NULL) {
            if (q->check_player_flag1() == 0) {
                TLobby::close_and_play_effect((u16)local_client_id, 1);
            }
            q->release_attached_resource();
        }
        state_20 = 5;
        break;
    case 5:
        if (controller_input_state.controllers[0].pressed_buttons & 2) {
            TLobby::handle_battle_result((u16)local_client_id, 1);
            window_54->close();
            window_54 = NULL;
            state_20 = 6;
            p = get_local_player();
            if (p != NULL && (p->actorFlags & 0x800)) {
                p->reset_pose();
            }
        }
        break;
    case 6:
        if (check_team_balance(0) != 0) {
            send_battle_mode_params(5, 1, 0);
        } else {
            q = get_local_player();
            if (local_client_id == designated_client_id && TWindowCtrl::has_player_active_menu(local_client_id) == 0) {
                if (window_4c == NULL) {
                    static const BattleIntroWindowSize size = {216.0f, 84.0f};
                    window_4c = TWindowMessage::create(get_window_layout_position(0x53), (const f32 *)(&size), 1);
                    if (window_4c != NULL) {
                        window_4c->append_line(text[0], 0x80);
                    }
                }
                if (window_50 == NULL) {
                    window_50 = create_window_menu_default(get_window_layout_position(0x54), 3);
                    window_50->add_text_entry(text[1], 6, 1);
                    window_50->add_text_entry(text[2], 6, 2);
                    window_50->add_text_entry(text[3], 6, 3);
                    window_50->calc_window_size();
                    align_menu_entry_positions(window_50);
                    window_50->set_ready_flag();
                }
                if (window_50 != NULL) {
                    if (window_50->is_decided() != 0) {
                        switch (window_50->get_selected_value()) {
                        case 1:
                            send_6x7D_set_battle_mode_data(this);
                            state_20 = 9;
                            break;
                        case 2:
                            state_20 = 7;
                            break;
                        case 3:
                            send_battle_mode_params(4, 0, 0);
                            state_20 = 9;
                            break;
                        }
                    } else if (window_50->is_cancelled() != 0) {
                        state_20 = 7;
                    }
                }
                if (q != NULL && q->check_player_flag1() == 0) {
                    TLobby::close_and_play_effect((u16)local_client_id, 1);
                }
            } else if (q != NULL && q->check_player_flag1() != 0) {
                TLobby::handle_battle_result((u16)local_client_id, 1);
            }
        }
        break;
    case 7:
        if (window_4c != NULL) {
            window_4c->close();
            window_4c = NULL;
        }
        if (window_50 != NULL) {
            window_50->close();
            window_50 = NULL;
        }
        p = get_local_player();
        if (p != NULL && p->check_player_flag1() != 0) {
            TLobby::handle_battle_result((u16)local_client_id, 1);
        }
        state_20 = 8;
    case 8:
        if (check_team_balance(0) != 0) {
            send_battle_mode_params(5, 1, 0);
        } else {
            p = get_player_by_client_id(local_client_id);
            if (p != NULL && p->is_controls_locked() == 0 && (controller_input_state.controllers[0].pressed_buttons & 6)) {
                state_20 = 6;
            }
        }
        break;
    case -1:
        if (window_4c != NULL) {
            window_4c->close();
            window_4c = NULL;
        }
        if (window_50 != NULL) {
            window_50->close();
            window_50 = NULL;
        }
        if (window_54 != NULL) {
            window_54->close();
            window_54 = NULL;
        }
        p = get_local_player();
        if (p != NULL) {
            obj_clear_flag30_20000(p);
        }
        TWindowCtrl::close_timer_window();
        TWindowCtrl::suppress_slot(local_client_id);
        break;
    case 9:
        break;
    }
    if (state_20 == 6 || state_20 == 8) {
        p = get_local_player();
        if (p != NULL && p->is_controls_locked() == 0 && TWindowCtrl::has_player_active_menu(local_client_id) == 0 && (controller_input_state.controllers[0].pressed_buttons & 0x400)) {
            if (window_4c != NULL) {
                window_4c->close();
                window_4c = NULL;
            }
            if (window_50 != NULL) {
                window_50->close();
                window_50 = NULL;
            }
            state_20 = 4;
        }
    }
}

void TPlayerBattleCtrl::end_battle_mode_cleanup() {
    switch (((TPlayerBattleCtrl *)this)->state_20) {
    case 0:
        if (lobby_idle_timeout_window != NULL) {
            delete lobby_idle_timeout_window;
            lobby_idle_timeout_window = NULL;
        }
        TLobby::clear_counter();
        evt2_random_enemies_mode = 0;
        set_keyboard_input_flag();
        lobby_floor_reload_pending = 1;
        ((TObject *)this)->queue_destruction();
        break;
    case -1:
        break;
    }
}

s32 get_battle_time_limit_frames(void) {
    return CFG->time_limit_seconds * 0x3C;
}

void TLobby::close_and_play_effect(int client, s32 local) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        send_impose_hold(player, -1);
    }
    if (local != 0) {
        TWindowCtrl::begin_client_keyboard_hold(local_client_id);
        request_active_window_close();
        TWindowCtrl::suppress_slot(local_client_id);
    }
}

void TLobby::handle_battle_result(int client, s32 local) {
    TObjPlayer *player;
    if ((player = get_player_by_client_id((u16)client)) != NULL) {
        send_release_hold(player);
    }
    if (local != 0) {
        TWindowCtrl::end_client_keyboard_hold(local_client_id);
        TWindowCtrl::clear_flag();
        TWindowCtrl::unsuppress_slot(local_client_id);
    }
}

void TPlayerBattleCtrl::apply_game_settings(s32 use_config) {
    lobby_rule_settings.reset_settings_to_default();
    if (use_config != 0) {
        s32 flag;
        lobby_rule_settings.set_tech_disk_mode(CFG->rules[0]);
        lobby_rule_settings.set_weapon_and_armor_mode(CFG->rules[1]);
        lobby_rule_settings.set_mag_mode(CFG->rules[2]);
        lobby_rule_settings.set_tool_mode(CFG->rules[3]);
        lobby_rule_settings.set_trap_mode(CFG->rules[4]);
        lobby_rule_settings.set_unused_F817(CFG->rules[5]);
        lobby_rule_settings.set_respawn_mode(CFG->rules[6]);
        lobby_rule_settings.set_replace_char(CFG->rules[7]);
        lobby_rule_settings.set_drop_weapon(CFG->rules[8]);
        lobby_rule_settings.set_hide_target_reticle(CFG->rules[0xA]);
        lobby_rule_settings.set_meseta_mode(CFG->rules[0xB]);
        lobby_rule_settings.set_death_level_up(CFG->value_c);
        for (s32 i = 0; i < 4; i++) {
            lobby_rule_settings.set_rule_slot_clamped(CFG->slot_rules[i], i);
        }
        lobby_rule_settings.set_enable_sonar(CFG->rule_d);
        lobby_rule_settings.set_sonar_count(CFG->level);
        lobby_rule_settings.set_forbid_scape_dolls(CFG->rule_e);
        lobby_rule_settings.set_lives((u8) CFG->volume);
        lobby_rule_settings.set_max_tech_level((u8) CFG->max_tech_level);
        lobby_rule_settings.set_char_level((s16) CFG->clamped_index);
        lobby_rule_settings.set_time_limit(CFG->time_limit_seconds);
        lobby_rule_settings.set_death_tech_level_up((u8) CFG->value_28);
        flag = 0;
        if ((s32) CFG->rules[9] == 1 && TLobby::get_game_mode() == 4) {
            s32 toggle = 1;
            for (s32 i = 0; i < 4; i++) {
                TObjPlayer *p = get_player_by_client_id(i);
                if (p != NULL) {
                    toggle = 1 - toggle;
                    s32 v = 2;
                    if (toggle != 0) {
                        v = 1;
                    }
                    battle_intro_value_table[i] = v;
                    p->pk_state.set_team(battle_intro_value_table[i]);
                } else {
                    battle_intro_value_table[i] = -1;
                }
            }
            flag = 1;
        }
        lobby_rule_settings.set_is_teams((u8) (flag != 0));
        for (s32 i = 0; i < 4; i++) {
            TObjPlayer *p = player_slot_table[i];
            if (p != NULL) {
                p->battle_score.damage_given.set_bonus_weight(battle_player_give_damage_score);
                p->battle_score.damage_given.set_normal_weight(battle_enemy_give_damage_score);
                p->battle_score.damage_taken.set_bonus_weight(battle_player_take_damage_score);
                p->battle_score.damage_taken.set_normal_weight(battle_enemy_take_damage_score);
                p->battle_score.kills.set_bonus_weight(battle_player_kill_score);
                p->battle_score.kills.set_normal_weight(battle_enemy_kill_score);
                p->battle_score.deaths.set_bonus_weight(battle_player_death_score);
                p->battle_score.deaths.set_normal_weight(battle_enemy_death_score);
                p->battle_score.meseta.set_bonus_weight(battle_meseta_score);
                p->battle_score.meseta.set_normal_weight(battle_meseta_score);
            }
        }
        lobby_rule_settings.set_section_id(1);
    }
    if (get_local_player() != NULL) {
        apply_battle_rules_to_players();
    }
}

void send_battle_mode_params(s8 command, s32 value, s32 extra) {
    G_SetBattleModeData_6x7D cmd;
    build_6x7D_set_battle_mode_data(&cmd);
    cmd.state = command;
    cmd.what = 0;
    cmd.params[0] = value;
    cmd.params[1] = extra;
    cmd.send();
}

s32 TPlayerBattleCtrl::check_team_balance(s32 check_rule) {
    s32 i;
    s32 t;
    TObjPlayer *pl;
    if (TLobby::get_game_mode() <= 1) {
        return 1;
    }
    if (check_rule != 0 && lobby_rule_settings.get_is_teams() == 1) {
        BattleTeamTotals cnt = {0, 0};
        i = 0;
        do {
            pl = get_player_by_client_id(i);
            if (pl != NULL) {
                t = pl->pk_state.get_team() - 1;
                if (t >= 0 && t < 2) {
                    cnt.team[t] = 1;
                }
            }
            i++;
        } while (i < 4);
        if (cnt.team[0] == 0 || cnt.team[1] == 0) {
            return 1;
        }
    }
    return 0;
}

void TPlayerBattleCtrl::show_lobby_transport_notice() {
    s32 idx;
    s32 s;
    switch (state_20) {
    case 0: {
        TLobby::close_and_play_effect((u16)local_client_id, 1);
        if (window_4c != NULL) {
            window_4c->close();
            window_4c = NULL;
        }
        if (aborted_after_result != 0) {
            idx = 5;
        } else {
            idx = 4;
            s = get_active_disconnect_count() - 1;
            set_active_disconnect_count((u16)(s > 0 ? s : 0));
        }
        BattleIntroWindowSize p = {238.0f, 188.0f};
        window_4c = TWindowMessage::create(get_window_layout_position(0xB3), (const f32 *)(&p), 1);
        if (window_4c != NULL) {
            window_4c->append_line(text[idx], 0x80);
        }
        state_20 = 1;
        break;
    }
    case 1:
        if (controller_input_state.sources[0]->pressed & 8) {
            state_24 = 4;
        }
        break;
    case -1:
        break;
    }
}

void init_char_slots(void) {
    battle_mode_data_ptr = 0;
    battle_frame_rate = get_video_standard() == 1 ? 0x19 : 0x1E;
    lobby_char_slot_array = __construct_new_array(mem_alloc(0x3220), (void *)__ct__19PlayerCharDataEntryFv, (void *)__dt__19PlayerCharDataEntryFv, 0x42C, 0xC);
    TBattleProximitySound::clear_battle_proximity_sound();
    clear_battle_player_ready_flags();
    battle_ctrl_default_value = 1;
    clear_duel_result_window();
}

void free_char_slots(void) {
    if (lobby_char_slot_array != 0) {
        __destroy_new_array(lobby_char_slot_array, __dt__19PlayerCharDataEntryFv);
        lobby_char_slot_array = 0;
    }
}

void init_battle_ctrl(s32 config, saddr src) {
    if (battle_mode_data_ptr == NULL) {
        battle_mode_data_ptr = new TPlayerBattleCtrl(tl_00);
    }
    if (battle_mode_data_ptr != NULL) {
        strncpy(battle_mode_data_ptr->intro_text, (const char *)src, 0x200);
        battle_config_ptr = config;
    }
}

void update_battle_exit_sequence(TPlayerBattleCtrl *ctrl) {
    TObjPlayer *player;
    switch (ctrl->state_20) {
    case 0:
        player = get_local_player();
        if (player != NULL) {
            send_impose_hold(player, -1);
        }
        ctrl->timer = 0xF;
        ctrl->state_20 = 1;
    case 1:
        if (--ctrl->timer <= 0) {
            destroy_current_floor_objects();
            reset_map();
            if (quest_mission_manager != NULL) {
                TQuestThread::clear_buffer(quest_mission_manager);
            }
            stop_audio_streams();
            battle_fadeout_done = 0;
            TLobby::init_fadeout_state(init_and_set_flag);
            ctrl->state_20 = 2;
        }
        break;
    case 2:
        if (battle_fadeout_done != 0) {
            finish_chr_select_scene_init();
            TLobby::set_fade_params(restart_battle_after_fade);
            ctrl->state_20 = 3;
        }
        break;
    case 3:
    default:
        break;
    }
}

void init_and_set_flag(void) { recreate_all_players(); advance_item_system_generation(); battle_fadeout_done = 1; }

void restart_battle_after_fade(void) {
    if ((void *) battle_mode_data_ptr != NULL) {
        battle_mode_data_ptr->state_24 = 0;
    }
}

void handle_6x7D_set_battle_mode_data(G_SetBattleModeData_6x7D *pkt) {
    TObjPlayer *p;
    s32 i;
    pkt->bswap();
    switch (pkt->what) {
    case 0:
        if (battle_mode_data_ptr != NULL) {
            battle_mode_data_ptr->state_24 = pkt->state;
            battle_mode_data_ptr->aborted_after_result = pkt->params[0];
            battle_mode_data_ptr->pad_5c = pkt->params[1];
        }
        break;
    case 2:
        lbl_805D5DA4 = 1;
        break;
    case 3:
        p = get_player_by_client_id(pkt->params[0]);
        if (p != NULL) {
            if (pkt->params[0] != local_client_id) {
                p->battle_score.slots.set_score(pkt->params[1]);
            }
            battle_team_table[pkt->params[0]] = pkt->is_alive;
        }
        battle_team_report_count++;
        break;
    case 4:
        battle_player_ready_flags[pkt->params[0]] = 1;
        break;
    case 5:
        if (battle_mode_data_ptr != NULL) {
            battle_mode_data_ptr->request_timed_event();
        }
        break;
    case 6:
        if (battle_mode_data_ptr != NULL) {
            battle_mode_data_ptr->state_24 = 6;
            for (i = 0; i < 4; i++) {
                battle_mode_data_table[i] = pkt->params[i];
            }
        }
        break;
    }
}

void handle_6x7E(void) {  }

void handle_6x7F_battle_scores(G_BattleScores_6x7F *cmd) {
    bswap_client_id_header(&cmd->header);
    memcpy(duel_result_table, cmd->rankings, sizeof(cmd->rankings));
    battle_scores_received = 1;
}

void copy_battle_ranking(BattleRanking *dst, BattleRanking *src) {
    dst->client_id = src->client_id;
    dst->place = src->place;
    dst->score = src->score;
}

s32 TPlayerBattleCtrl::calc_player_rankings() {
    s32 n;
    s32 i;
    s32 j;
    TObjPlayer *p;
    s32 rank;
    s32 m;
    s32 k;
    for (k = 0; k < 4; k++) {
        duel_result_table[k].client_id = 0xFFFF;
        duel_result_table[k].place = 0;
        duel_result_table[k].score = 0;
    }
    n = 0;
    if (lobby_rule_settings.get_is_teams() == 1) {
        BattleTeamTotals team = {0, 0};
        for (k = 0; k < 4; k++) {
            p = get_player_by_client_id(k);
            if (p != NULL) {
                s32 t = p->pk_state.get_team() != 1 ? 1 : 0;
                team.team[t] += p->battle_score.slots.get_score();
            }
        }
        for (k = 0; k < 4; k++) {
            p = get_player_by_client_id(k);
            if (p != NULL) {
                duel_result_table[n].client_id = p->get_entity_id();
                duel_result_table[n].score = team.team[p->pk_state.get_team() != 1 ? 1 : 0];
                n++;
            }
        }
    } else {
        for (k = 0; k < 4; k++) {
            p = get_player_by_client_id(k);
            if (p != NULL) {
                duel_result_table[n].client_id = p->get_entity_id();
                duel_result_table[n].score = p->battle_score.slots.get_score();
                n++;
            }
        }
        if (n <= 1) {
            return 0;
        }
    }
    for (i = 0; i < n - 1; i++) {
        if (duel_result_table[i].client_id != 0xFFFF) {
            for (j = i + 1; j < n; j++) {
                if (duel_result_table[j].client_id != 0xFFFF && duel_result_table[i].score < duel_result_table[j].score) {
                    BattleRanking tmp = duel_result_table[i];
                    copy_battle_ranking(&duel_result_table[i], &duel_result_table[j]);
                    copy_battle_ranking(&duel_result_table[j], &tmp);
                }
            }
        }
    }
    rank = 0;
    for (m = 0; m < n; m++) {
        duel_result_table[m].place = rank;
        if (m < n - 1 && duel_result_table[m].score != duel_result_table[m + 1].score) {
            rank = m + 1;
        }
    }
    return 1;
}

void record_local_battle_placement(void *arg0) {
    s32 slot;
    s32 i;
    s32 n;
    s32 s;
    s32 r;
    TObjPlayer *pl;

    slot = -1;
    for (i = 0; i < 4; i++) {
        pl = get_player_by_client_id(duel_result_table[i].client_id);
        if (pl != NULL && local_client_id == (u16)pl->get_entity_id()) {
            slot = duel_result_table[i].place;
            break;
        }
    }
    if (is_duel_ranking_empty() == 0) {
        switch (slot) {
        case 0:
            {
                u16 c = get_active_first_place_count();
                s32 m = 0xFFFF;
                if (c + 1 < m) m = c + 1;
                set_active_first_place_count(m);
            }
            break;
        case 1:
            {
                u16 c = get_active_second_place_count();
                s32 m = 0xFFFF;
                if (c + 1 < m) m = c + 1;
                set_active_second_place_count(m);
            }
            break;
        case 2:
            {
                u16 c = get_active_third_place_count();
                s32 m = 0xFFFF;
                if (c + 1 < m) m = c + 1;
                set_active_third_place_count(m);
            }
            break;
        case 3:
            {
                u16 c = get_active_fourth_place_count();
                s32 m = 0xFFFF;
                if (c + 1 < m) m = c + 1;
                set_active_fourth_place_count(m);
            }
            break;
        }
    }
    s = get_active_disconnect_count() - 1;
    set_active_disconnect_count((u16)(s > 0 ? s : 0));
    save_active_character_to_card();
}

void play_duel_result_stream(const char *file, saddr duration) {
    play_cue_stream_file(file);
    show_duel_result_window(-50, duration);
}

s32 TLobby::assign_player_id(void *) {
    s32 score;
    TObjPlayer *player;

    player = get_local_player();
    if (player == NULL) {
        return 0;
    }
    score = player->calc_battle_score();
    player->battle_score.slots.set_score(score);
    return score;
}

TDelayedAreaMusic::TDelayedAreaMusic(TObject *parent, const char *name, s32 delay) : TObject(parent) {
    delay_frames = delay;
    strncpy(music_name, name, 32);
}

TDelayedAreaMusic::~TDelayedAreaMusic() {}

void TDelayedAreaMusic::run_task() {
    if (--delay_frames <= 0) {
        play_area_music(music_name);
        queue_destruction();
    }
}

void TPlayerBattleCtrl::init_battle_round() {
  s32 char_select_slot;
  TObjPlayer *player;
  s32 clamped_slot;
  s32 i;
  time_limit = get_battle_time_limit_frames();
  TWindowCtrl::create_alt_timer();
  TWindowCtrl::set_timer_window_time(time_limit);
  TOMineTrap::destroy_matching_traps();
  char_select_slot = get_active_disconnect_count();
  char_select_slot = char_select_slot + 1;
  clamped_slot = 0xFFFF;
  if (char_select_slot < clamped_slot)
  {
    clamped_slot = char_select_slot;
  }
  set_active_disconnect_count((u16) clamped_slot);
  save_active_character_to_card();
  this->apply_game_settings(1);
  TLobby::close_and_play_effect((u16) local_client_id, 1);
  player = get_local_player();
  if (player != NULL)
  {
    obj_set_flag_20000(player);
    player->battle_score.damage_given.reset();
    player->battle_score.damage_taken.reset();
    player->battle_score.kills.reset();
    player->battle_score.deaths.reset();
    player->battle_score.meseta.reset();
    player->battle_score.slots.set_score(0);
  }
  state_send_wait = 0x5A;
  calc_player_rankings();
  for (i = 0; i < 4; i++)
  {
    battle_team_table[i] = 1;
  }
}

void TPlayerBattleCtrl::start_duel_battle() {
    const char *name;
    uaddr p;
    s32 area;
    s32 i;
    start_duel_stub_a(4);
    start_duel_stub_b();
    start_time = OSGetTime();
    TLobby::handle_battle_result((u16)local_client_id, 1);
    if ((p = (saddr)get_local_player()) != 0) {
        obj_clear_flag30_20000((TObjBase *)p);
    }
    reset_score_counters();
    area = get_current_floor_area();
    name = (area == AREA_BATTLE1) ? "duel1.adx" : "duel2.adx";
    new TDelayedAreaMusic(this, name, 0x2D);
    for (i = 0; i < 8; i++) {
        timed_event_flags[i] = 1;
        if (battle_event_second_table[i] == 0) {
            timed_event_flags[i] = 0;
        }
    }
    battle_ctrl_default = battle_ctrl_default_value;
}

void TPlayerBattleCtrl::init() {
    s32 i;
    TObjPlayer *player;

    request_timed_event();
    TLobby::close_and_play_effect((u16) local_client_id, 1);
    player = get_local_player();
    if (player != NULL) {
        obj_set_flag_20000(player);
        player->protection.set_frames(0xE10);
    }
    TOMineTrap::destroy_matching_traps();
    queue_destroy_event_descendants(tl_01);
    TQuestThread::destroy_all_in(tl_00);
    mark_floor_enemies_dead();
    TBattleProximitySound::destroy();
    destroy_floor_decoration_objects();
    i = 0;
    battle_ctrl_default = 0;
    do {
        player = get_player_by_client_id(i);
        if (player != NULL) {
            player->trap_counts.clear();
        }
        i += 1;
    } while (i < 4);
}

void send_6x7D_set_battle_mode_data(void *) {
    G_SetBattleModeData_6x7D msg;
    s32 i;
    s32 a;
    s32 b;
    s32 t;
    build_6x7D_set_battle_mode_data(&msg);
    msg.what = 6;
    for (i = 0; i < 4; i++) {
        msg.params[i] = i;
    }
    for (i = 0; i < 0x1E; i++) {
        a = (s32) (4.0f * (3.0517578125e-05f * (f32) rand()));
        b = (s32) (4.0f * (3.0517578125e-05f * (f32) rand()));
        if (a != b) {
            t = msg.params[a];
            msg.params[a] = msg.params[b];
            msg.params[b] = t;
        }
    }
    msg.send_to_leader();
    ((game_command *)&msg)->send();
}

void finish_chr_select_scene_init(void) {
    init_scene_objects();
    TObjPlayer *player = get_local_player();
    if (player != NULL) {
        player->send_selected_spawn_position(battle_mode_data_table[(u16)player->get_entity_id()]);
        reset_cameras_to_actor(player, 0);
    }
    ((TLobby *)tl_05)->destroy_matching_children();
    TBattleProximitySound::destroy();
}

void TLobby::destroy_matching_children() {
    TObject *down;
    down = this->m_down;
    while (down != NULL) {
        if (down->check_value_equals(dead_spot_class_name) != 0) {
            down->queue_destruction();
        }
        ((TLobby *)down)->destroy_matching_children();
        down = down->m_next;
    }
}

void clear_battle_player_ready_flags(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        battle_player_ready_flags[i] = 0;
    }
}

void TPlayerBattleCtrl::send_player_ready() {
    G_SetBattleModeData_6x7D cmd;
    build_6x7D_set_battle_mode_data(&cmd);
    cmd.what = 4;
    cmd.params[0] = local_client_id;
    cmd.send();
}

s32 TPlayerBattleCtrl::check_all_players_ready() {
    u8 *ready_flag;
    s32 all_ready;
    s32 client;

    ready_flag = battle_player_ready_flags;
    all_ready = 1;
    for (client = 0; client < 4; client++, ready_flag++) {
        if ((get_player_by_client_id(client) != NULL) && ((s8) *ready_flag == 0)) {
            all_ready = 0;
            break;
        }
    }
    return all_ready;
}

void TPlayerBattleCtrl::show_score_results() {
    char buf[0x48];
    BattleRanking *e;
    s32 i;
    TObjPlayer *p;
    reset_score_counters();
    calc_player_rankings();
    TWindowCtrl::append_message_all("SCORE");
    for (i = 0; i < 4; i++) {
        e = &duel_result_table[i];
        p = get_player_by_client_id(e->client_id);
        if (p != NULL) {
            sprintf(buf, "%s %s", lobby_rank_ordinal_text_table[e->place], p->get_name());
            TWindowCtrl::append_message_all(buf);
        }
    }
    play_duel_result_stream("start.adx", 0x3C);
}

void TPlayerBattleCtrl::request_timed_event() {
    send_battle_mode_state();
    timed_event_state = 1;
}

void TPlayerBattleCtrl::send_battle_mode_state() {
    G_SetBattleModeData_6x7D m;
    TObjPlayer *p;
    s32 id;
    s32 on;
    p = get_local_player();
    if (p != NULL) {
        id = TLobby::assign_player_id(this);
        build_6x7D_set_battle_mode_data(&m);
        m.what = 3;
        m.params[0] = p->get_entity_id();
        m.params[1] = id;
        on = 1;
        if (p->actorFlags & 0x800) {
            if (lobby_rule_settings.get_respawn_mode() == 1) {
                on = 0;
            } else if (lobby_rule_settings.get_respawn_mode() == 2 &&
                       p->battle_score.get_timer() == 0) {
                on = 0;
            }
        }
        m.is_alive = on;
        battle_team_table[local_client_id] = on;
        m.send();
    }
}

s32 TPlayerBattleCtrl::check_timeout(s32 timer) {
    if (battle_team_report_count >= TLobby::get_game_mode()) {
        timed_event_state = 2;
    }
    return timed_event_state == 2;
}

void TPlayerBattleCtrl::reset_score_counters() { timed_event_state = 0; battle_team_report_count = 0; }

void TLobby::send_battle_mode_data(void * _w0) {
    G_SetBattleModeData_6x7D cmd;

    build_6x7D_set_battle_mode_data(&cmd);
    cmd.what = 5;
    cmd.send();
}

void TPlayerBattleCtrl::update_battle_sync(s32 t) {
    s32 i;
    switch (timed_event_state) {
    case 0:
        if (local_client_id == designated_client_id) {
            for (i = 0; i < 8; i++) {
                if (timed_event_flags[i] != 0 && t / 60 == battle_event_second_table[i]) {
                    timed_event_flags[i] = 0;
                    TLobby::send_battle_mode_data(this);
                }
            }
        }
        break;
    case 1:
        check_timeout(t);
        break;
    case 2:
        show_score_results();
        break;
    }
}

s32 TPlayerBattleCtrl::check_battle_end() {
    TObjPlayer *p;
    s32 cnt;
    s32 i;
    s32 ok;
    s32 idx;
    s32 seen[2] = {0, 0};
    cnt = 0;
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            ok = 1;
            if (battle_team_table[i] == 0) {
                ok = 0;
            } else if (p->actorFlags & 0x800) {
                if (lobby_rule_settings.get_respawn_mode() == 1) {
                    ok = 0;
                } else if (lobby_rule_settings.get_respawn_mode() == 2 &&
                           p->battle_score.get_timer() == 0) {
                    ok = 0;
                }
            }
            if (ok != 0) {
                cnt++;
                if (lobby_rule_settings.get_is_teams() == 1) {
                    idx = p->pk_state.get_team() - 1;
                    if (idx >= 0 && idx < 2) {
                        seen[idx] = 1;
                    }
                }
            }
        }
    }
    if (lobby_rule_settings.get_is_teams() == 1 && (seen[0] == 0 || seen[1] == 0)) {
        return 1;
    }
    return cnt <= 1;
}

s32 is_duel_ranking_empty(void) {
    BattleRanking *e;
    s32 result = 1;
    s32 i;
    for (i = 0; i < 4; i++) {
        e = &duel_result_table[i];
        if (get_player_by_client_id(e->client_id) != NULL && e->place != 0) {
            result = 0;
            break;
        }
    }
    return result;
}

s32 get_ranked_battle_ctrl_value(void) {
    if (is_duel_ranking_empty() != 0) {
        return 0;
    }
    return battle_ctrl_default_value;
}

s32 is_battle_mode_running(void) {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return TPlayerBattleCtrl4P::is_battle_mode_active();
    }
    if (battle_mode_data_ptr != NULL) {
        return battle_mode_data_ptr->state_1c == 1 || battle_mode_data_ptr->state_1c == 2;
    }
    return 0;
}

s32 TPlayerBattleCtrl::check_all_battle_flags() {
    TObjPlayer *player;
    s32 client;

    for (client = 0; client < 4; client++) {
        player = get_player_by_client_id(client);
        if ((player != NULL) && (player->test_actor_flags(0x02000000) != 0)) {
            return 0;
        }
    }
    return 1;
}
