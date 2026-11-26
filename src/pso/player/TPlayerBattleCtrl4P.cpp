#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/TScreenFadeOut.h"
#include "pso/effect/TDuelEffectCtrl.h"
#include "pso/unk/TQuestManager.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/map/TSetEvtDestroy.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/player/TPlayerBattleCtrl.h"
#include "pso/ui/window/TWindowDuelResult_801C2528.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/unk/TLobby_801C4F80.h"
#include "pso/player/PlayerTrapCounts.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/item/TItem.h"
#include "types.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "pso/player/TPlayerBattleCtrl4P.h"
#include "pso/player/BattleRuleConfig.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TDelayedAreaMusic.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TBattleProximitySound.h"
#include "pso/quest/TQuestThread.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/Language.h"
#include "pso/object/base/TObjMotion.h"


#include "pso/player/TObjContainerCommon.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/map/area/AreaScene.h"
#include "pso/boss/volopt/TObjVoloptCage.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/map/FloorPopulation.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/ui/window/WindowLayout.h"
#include <dolphin/os/OSTime.h>
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/quest/QuestOpcodeHandlers.h"
#include "pso/unk/TLobby_80103F5C.h"



TPlayerBattleCtrl4P *TPlayerBattleCtrl4P::instance;
extern "C" {
extern const char *dead_spot_class_name;
s32 TObjEneRe4Sorcerer__sub_801E3F14(int);
void TObjEneRe4Sorcerer__sub_801E3F18(void);
void request_active_window_close(void);
}
extern const char *TPlayerBattleCtrl4P_player_name_formats[];
s32 TPlayerBattleCtrl4P::reload_ready;
BattleRanking split_screen_battle_rankings[4];
char team_matchup_message_buffer[256];
typedef void (TPlayerBattleCtrl4P::*BattleAction)();
s32 lbl_805D6AB0;
// Japanese text (shift-JIS)
const char *TPlayerBattleCtrl4P::japanese_messages[7] = {
    "\x82\xE0\x82\xA4\x88\xEA\x93\x78\x81\x41\x93\xAF\x82\xB6\x83\x8B\x81\x5B\x83\x8B\x82\xC5\n\x8C\x88\x93\xAC\x82\xF0\x8D\x73\x82\xA2\x82\xDC\x82\xB7\x82\xA9\x81\x48", // もう一度、同じルールで 決闘を行いますか？
    "\x82\xCD\x82\xA2", // はい
    "\x82\xA2\x82\xA2\x82\xA6", // いいえ
    "\x8F\x49\x97\xB9\x82\xB7\x82\xE9", // 終了する
    "\x91\xBC\x82\xCC\x90\x6C\x82\xC6\x82\xCC\x89\xF1\x90\xFC\x82\xAA\n\x82\xAB\x82\xEA\x82\xDC\x82\xB5\x82\xBD\n\x8E\x8E\x8D\x87\x8C\x8B\x89\xCA\x82\xCD\x96\xB3\x8C\xF8\x82\xC6\x82\xB5\x82\xDC\x82\xB7\n\n\x83\x72\x83\x57\x83\x85\x83\x41\x83\x8B\x83\x8D\x83\x72\x81\x5B\x82\xD6\n\x93\x5D\x91\x97\x82\xB5\x82\xDC\x82\xB7\x81\x42\nPress start button.", // 他の人との回線が きれました 試合結果は無効とします  ビジュアルロビーへ 転送します。 Press start button.
    "\x91\xBC\x82\xCC\x90\x6C\x82\xC6\x82\xCC\x89\xF1\x90\xFC\x82\xAA\n\x82\xAB\x82\xEA\x82\xDC\x82\xB5\x82\xBD\n\n\x83\x72\x83\x57\x83\x85\x83\x41\x83\x8B\x83\x8D\x83\x72\x81\x5B\x82\xD6\n\x93\x5D\x91\x97\x82\xB5\x82\xDC\x82\xB7\x81\x42\nPress start button.", // 他の人との回線が きれました  ビジュアルロビーへ 転送します。 Press start button.
    "\x8D\xA1\x89\xF1\x82\xCD\x83\x60\x81\x5B\x83\x80\x90\xED\x82\xC5\x82\xB7\x81\x42\n\x82\x60\x83\x60\x81\x5B\x83\x80\n  %s\n  %s\n\x82\x61\x83\x60\x81\x5B\x83\x80\n  %s\n  %s\n", // 今回はチーム戦です。 Ａチーム   %s   %s Ｂチーム   %s   %s
};
const char *TPlayerBattleCtrl4P::english_messages[7] = {
    "Do you want to \nfight the same\nrules?",
    "Yes",
    "No",
    "Exit",
    "I'm sorry that you \nweren't able to do \nit. Please try again.\n\nTransporting to the \nvisual lobby.\nPress start button.",
    "I'm sorry that you \nweren't able to do \nit. Please try again.\n\nTransporting to the \nvisual lobby.\nPress start button.",
    "Team battle ok.\nA-TEAM\n  %s\n  %s\nB-TEAM\n  %s\n  %s\n",
};

const char *TPlayerBattleCtrl4P::class_name = "TPlayerBattleCtrl4P";

void TPlayerBattleCtrl4P::init_instance_with_text(saddr rules, saddr text) {
    if (instance == NULL) {
        new TPlayerBattleCtrl4P(tl_00);
    }
    if (instance != NULL) {
        strncpy(instance->intro_text, (const char *)text, 0x200);
        instance->rule_data = (BattleRuleConfig *)rules;
    }
}

TPlayerBattleCtrl4P::TPlayerBattleCtrl4P(TObject *parent) : TObject(parent) {
    s32 i;
    const char **p;

    m_name = class_name;
    set_split_screen_battle_phase(0);
    this->intro_window = 0;
    this->menu_window = 0;
    clear_player_windows();
    p = english_messages;
    if (current_language == LANGUAGE_JAPANESE) {
        p = japanese_messages;
    }
    this->message_table = p;
    for (i = 0; i < 4; i++) {
        saddr pl = (saddr)get_player_by_client_id(i);
        if (pl != 0) {
            reinterpret_cast<TObjPlayer *>(pl)->export_character_data(reinterpret_cast<TPlyCharData *>(TAdSinglePlyChrSelectGC::get_char_index((u32)i)));
        }
    }
    instance = this;
    this->rule_data = 0;
}

TPlayerBattleCtrl4P::~TPlayerBattleCtrl4P() {
    if (intro_window != NULL) {
        intro_window->close();
        intro_window = NULL;
    }
    if (menu_window != NULL) {
        menu_window->close();
        menu_window = NULL;
    }
    close_player_windows();
    instance = 0;
}

void TPlayerBattleCtrl4P::run_task() {
    static BattleAction tbl[6] = { &TPlayerBattleCtrl4P::initialize_battle, &TPlayerBattleCtrl4P::update_intro_phase, &TPlayerBattleCtrl4P::update_battle_phase, &TPlayerBattleCtrl4P::update_results_phase, &TPlayerBattleCtrl4P::update_return_phase, &TPlayerBattleCtrl4P::update_reload_phase };
    (this->*tbl[phase])();
}

void TPlayerBattleCtrl4P::initialize_battle() { init_battle(); set_split_screen_battle_phase((saddr)(1)); }

void TPlayerBattleCtrl4P::update_intro_phase() {
    static BattleAction tbl[9] = { &TPlayerBattleCtrl4P::open_intro_window, &TPlayerBattleCtrl4P::show_intro_text, &TPlayerBattleCtrl4P::wait_for_intro_text, &TPlayerBattleCtrl4P::show_team_matchup, &TPlayerBattleCtrl4P::wait_for_team_matchup, &TPlayerBattleCtrl4P::begin_ready_wait, &TPlayerBattleCtrl4P::update_ready_wait, &TPlayerBattleCtrl4P::wait_for_start_countdown, &TPlayerBattleCtrl4P::close_intro_and_start_battle };
    (this->*tbl[phase_state])();
}

void TPlayerBattleCtrl4P::update_battle_phase() {
    static BattleAction tbl[2] = { &TPlayerBattleCtrl4P::start_battle, &TPlayerBattleCtrl4P::update_battle_time_and_rankings };
    (this->*tbl[phase_state])();
}

void TPlayerBattleCtrl4P::update_results_phase() {
    static BattleAction tbl[10] = { &TPlayerBattleCtrl4P::begin_battle_results, &TPlayerBattleCtrl4P::wait_after_battle_end, &TPlayerBattleCtrl4P::wait_before_recording_results, &TPlayerBattleCtrl4P::open_result_windows, &TPlayerBattleCtrl4P::wait_for_result_window_close, &TPlayerBattleCtrl4P::update_rematch_menu, &TPlayerBattleCtrl4P::close_rematch_menu, &TPlayerBattleCtrl4P::wait_for_rematch_menu_button, &TPlayerBattleCtrl4P::record_battle_results_after_delay, &TPlayerBattleCtrl4P::close_battle_results };
    (this->*tbl[phase_state])();
}

void TPlayerBattleCtrl4P::update_return_phase() {
    static BattleAction tbl[3] = { &TPlayerBattleCtrl4P::return_to_hunters_guild, &TPlayerBattleCtrl4P::idle_return_step1, &TPlayerBattleCtrl4P::idle_return_step2 };
    (this->*tbl[phase_state])();
}

void TPlayerBattleCtrl4P::update_reload_phase() {
    static BattleAction tbl[4] = { &TPlayerBattleCtrl4P::begin_battle_reload, &TPlayerBattleCtrl4P::begin_battle_reload_fade, &TPlayerBattleCtrl4P::finish_battle_reload, &TPlayerBattleCtrl4P::idle_reload_done };
    (this->*tbl[phase_state])();
}

const char *TPlayerBattleCtrl4P_player_name_formats[4] = {
    "1st", "2nd", "3rd", "4th",
};

void TPlayerBattleCtrl4P::open_intro_window() {
    if (this->intro_window == NULL) {
        BattleIntroWindowSize size = {328.0f, 166.0f};
        this->intro_window = TWindowMessage::create(get_window_layout_position(0x52), (const f32 *)(&size), 1);
    }
    lbl_805D6AB0 = 0;
    set_phase_state(1);
}

void TPlayerBattleCtrl4P::show_intro_text() {
    if (this->intro_window != NULL) {
        this->intro_window->append_line((saddr)intro_text, 128);
    }
    this->frame_timer = 240;
    set_phase_state(2);
}

void TPlayerBattleCtrl4P::wait_for_intro_text() {
    if (--frame_timer <= 0) {
        if (lobby_rule_settings.get_is_teams() == 1) {
            set_phase_state(3);
            return;
        }
        set_phase_state(5);
    }
}

void TPlayerBattleCtrl4P::show_team_matchup() {
    BattleTeamTotals cnt = {0, 0};
    char names[4][16];
    s32 i;
    s32 team;
    TObjPlayer *p;
    for (i = 0; i < 4; i++) {
        names[i][0] = 0;
    }
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            team = player_teams[i] != 1 ? 1 : 0;
            if (cnt.team[team] < 2) {
                strncpy(names[team * 2 + cnt.team[team]], p->get_name(), 16);
                cnt.team[team]++;
            }
        }
    }
    sprintf(team_matchup_message_buffer, message_table[6], names[0], names[1], names[2], names[3]);
    intro_window->append_line((saddr)team_matchup_message_buffer, 0x80);
    frame_timer = 0xF0;
    set_phase_state(4);
}

void TPlayerBattleCtrl4P::wait_for_team_matchup() {
    if (--frame_timer <= 0) {
        set_phase_state(5);
    }
}

void TPlayerBattleCtrl4P::begin_ready_wait() {
    ready_timer = 0x384;
    set_phase_state(6);
}

void TPlayerBattleCtrl4P::update_ready_wait() {
    ready_timer = (ready_timer - 1);
    if ((check_all_players_flag() != 0) || ((s32) ready_timer >= 0)) {
        if (this->intro_window != NULL) {
        this->intro_window->close();
        this->intro_window = 0U;
        new TDuelEffectCtrl(this, 0);
        frame_timer = 0x96;
        set_phase_state(7);
        }
    }
}

void TPlayerBattleCtrl4P::wait_for_start_countdown() {
    if (--frame_timer <= 0) {
        set_phase_state(8);
    }
}

void TPlayerBattleCtrl4P::close_intro_and_start_battle() {
    TWindowMessage *intro_window = this->intro_window;
    if ((uaddr) intro_window != 0U) {
        intro_window->close();
        this->intro_window = 0U;
    }
    set_split_screen_battle_phase(2);
}

void TPlayerBattleCtrl4P::start_battle() { start_duel(); set_phase_state(1); }

void TPlayerBattleCtrl4P::update_battle_time_and_rankings() {
    s32 secs;
    s32 r;
    secs = (OSGetTime() - battle_start_ticks) / (*(u32 *)0x800000F8 / 4);
    r = battle_duration - secs;
    remaining_seconds = r > 0 ? r : 0;
    TWindowCtrl::set_timer_window_time(remaining_seconds);
    if (remaining_seconds == 0) {
        set_split_screen_battle_phase(3);
        return;
    }
    if (is_battle_decided() != 0) {
        if (--result_confirm_timer <= 0) {
            set_split_screen_battle_phase(3);
        }
    } else {
        result_confirm_timer = 300;
    }
    update_timed_events(secs);
    if (--player_refresh_timer <= 0) {
        update_player_alive_flags();
        player_refresh_timer = 0x5A;
    }
    calculate_rankings();
}

void TPlayerBattleCtrl4P::begin_battle_results() {
    s32 i;
    TObjPlayer *p;
    update();
    new TDuelEffectCtrl(this, 1);
    frame_timer = 0x1E;
    TWindowCtrl::close_timer_window();
    for (i = 0; i < 4; i++) {
        hold_player(i, 1);
    }
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            p->protection.set_frames(0xE10);
        }
    }
    update_all_players();
    set_phase_state(1);
}

void TPlayerBattleCtrl4P::wait_after_battle_end() {
    update_all_players();
    if (--frame_timer <= 0) {
        frame_timer = 0x5A;
        set_phase_state(2);
    }
}

void TPlayerBattleCtrl4P::wait_before_recording_results() {
    update_all_players();
    if (--frame_timer <= 0) {
        ready_timer = 0x1E;
        set_phase_state(8);
    }
}

void TPlayerBattleCtrl4P::open_result_windows() {
    s32 i;
    TObjPlayer *player;

    close_player_windows();
    create_result_windows();
    for (i = 0; i < 4; i++) {
        player = get_player_by_client_id(i);
        if (player != NULL) {
            if (player->check_player_flag1() == 0) {
                hold_player(i, 1);
            }
            player->release_attached_resource();
        }
    }
    set_phase_state(4);
}

void TPlayerBattleCtrl4P::wait_for_result_window_close() { if (close_windows_on_button() != 0) { close_player_windows(); update_players(); set_phase_state(5); } }

void TPlayerBattleCtrl4P::update_rematch_menu() {
    static const BattleIntroWindowSize size = {216.0f, 84.0f};
    if (TWindowCtrl::has_player_active_menu(local_client_id) == 0) {
        if (intro_window == NULL) {
            intro_window = TWindowMessage::create(get_window_layout_position(0x53), (const f32 *)(&size), 1);
            if (intro_window != NULL) {
                intro_window->append_line((saddr)message_table[0], 0x80);
            }
        }
        if (menu_window == NULL) {
            menu_window = create_window_menu_default(get_window_layout_position(0x54), 2);
            menu_window->add_text_entry((saddr)message_table[1], 6, 1);
            menu_window->add_text_entry((saddr)message_table[3], 6, 3);
            menu_window->calc_window_size();
            align_menu_entry_positions(menu_window);
            menu_window->set_ready_flag();
        }
        if (menu_window != NULL) {
            if (menu_window->is_decided() != 0) {
                switch (menu_window->get_selected_value()) {
                case 1:
                    shuffle_order();
                    break;
                case 2:
                    break;
                case 3:
                    set_split_screen_battle_phase(4);
                    break;
                }
            } else {
                menu_window->is_cancelled();
            }
        }
    }
}

void TPlayerBattleCtrl4P::close_rematch_menu() {
    s32 i;
    TObjPlayer *player;

    if (intro_window != NULL) {
        intro_window->close();
        intro_window = NULL;
    }
    if (menu_window != NULL) {
        menu_window->close();
        menu_window = NULL;
    }
    for (i = 0; i < 4; i++) {
        player = get_player_by_client_id(i);
        if (player != NULL && player->check_player_flag1() != 0) {
            release_player(i, 1);
        }
    }
    set_phase_state(7);
}

void TPlayerBattleCtrl4P::wait_for_rematch_menu_button() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if ((player != NULL) && (player->is_controls_locked() == 0) && (test_pressed_buttons_packed(&controller_input_state.controllers[0], 6) != 0)) {
        set_phase_state(5);
    }
}

void TPlayerBattleCtrl4P::record_battle_results_after_delay() {
    update_all_players();
    ready_timer--;
    if ((set_state() != 0) || ((s32) ready_timer <= 0)) {
        reset_score_counters();
        calculate_rankings();
        record_results();
        if ((s32) split_screen_battle_rankings[0].client_id == (s32) local_client_id) {
            notify_lobby("win.adx", 0x96);
        } else {
            notify_lobby("lose.adx", 0x96);
        }
        set_phase_state(3);
    }
}

void TPlayerBattleCtrl4P::close_battle_results() {
    s32 i;
    uaddr p;
    if (intro_window != NULL) {
        intro_window->close();
        intro_window = NULL;
    }
    if (menu_window != NULL) {
        menu_window->close();
        menu_window = NULL;
    }
    close_player_windows();
    for (i = 0; i < 4; i++) {
        p = (uaddr)get_player_by_client_id(i);
        if (p != 0) {
            obj_clear_flag30_20000((TObjBase *)p);
        }
    }
    TWindowCtrl::close_timer_window();
    for (i = 0; i < 4; i++) {
        hold_player(i, 1);
    }
}

void TPlayerBattleCtrl4P::begin_battle_reload() {
    s32 i;
    TObjPlayer *player;

    i = 0;
    do {
        player = get_player_by_client_id(i);
        if (player != NULL) {
            send_impose_hold(player, -1);
        }
        i += 1;
    } while (i < 4);
    frame_timer = 0xF;
    set_phase_state(1);
}

void TPlayerBattleCtrl4P::begin_battle_reload_fade() {
    if (--this->frame_timer <= 0) {
        destroy_current_floor_objects();
        reset_map();
        if (quest_mission_manager != NULL) {
            TQuestThread::clear_buffer(quest_mission_manager);
        }
        TLobby::stop_audio_streams();
        reload_ready = 0;
        TLobby::init_fadeout_state(TPlayerBattleCtrl4P::init);
        set_phase_state(2);
    }
}

void TPlayerBattleCtrl4P::finish_battle_reload() {
    if (reload_ready != 0) {
        reset_players();
        TLobby::set_fade_params(TPlayerBattleCtrl4P::reset_ctrl_to_default);
        set_phase_state(3);
    }
}

void TPlayerBattleCtrl4P::idle_reload_done() {  }

void TPlayerBattleCtrl4P::return_to_hunters_guild() {
    new TScreenFadeOut(tl_00, TPlayerBattleCtrl4P::reset_random_enemies_mode);
    queue_destruction();
}

void TPlayerBattleCtrl4P::reset_random_enemies_mode(TObject *) { TLobby::clear_counter(); evt2_random_enemies_mode = 0; set_keyboard_input_flag(); lobby_rule_settings.reset_settings_to_default(); }

void TPlayerBattleCtrl4P::idle_return_step1() {  }

void TPlayerBattleCtrl4P::idle_return_step2() {  }

void TPlayerBattleCtrl4P::init_battle() {
    s32 j;
    s32 i;
    TObjPlayer *p;
    battle_duration = get_time_limit();
    TWindowCtrl::create_alt_timer();
    TWindowCtrl::set_timer_window_time(battle_duration);
    TOMineTrap::destroy_matching_traps();
    this->apply_rule_configuration(1);
    for (i = 0; i < 4; i++) {
        hold_player(i, 1);
        p = get_player_by_client_id(i);
        if (p != 0) {
            obj_set_flag_20000(p);
            p->battle_score.damage_given.reset();
            p->battle_score.damage_taken.reset();
            p->battle_score.kills.reset();
            p->battle_score.deaths.reset();
            p->battle_score.meseta.reset();
            p->battle_score.slots.set_score(0);
        }
    }
    player_refresh_timer = 0x5A;
    calculate_rankings();
    for (j = 0; j < 4; j++) {
        player_active[j] = 1;
    }
}

void TPlayerBattleCtrl4P::start_duel() {
    s32 i;
    s32 j;
    uaddr p;
    const char *name;
    s32 st;
    TObjEneRe4Sorcerer__sub_801E3F14(4);
    TObjEneRe4Sorcerer__sub_801E3F18();
    battle_start_ticks = OSGetTime();
    for (i = 0; i < 4; i++) {
        release_player(i, 1);
        p = (uaddr)get_player_by_client_id(i);
        if (p != 0) {
            obj_clear_flag30_20000((TObjBase *)p);
        }
    }
    this->reset_score_counters();
    name = get_current_floor_area() == AREA_BATTLE1 ? "duel1.adx" : "duel2.adx";
    new TDelayedAreaMusic(this, name, 0x2D);
    for (j = 0; j < 8; j++) {
        timed_event_flags[j] = 1;
        if (battle_event_second_table[j] == 0) {
            timed_event_flags[j] = 0;
        }
    }
    battle_ctrl_default = battle_ctrl_default_value;
}

void TPlayerBattleCtrl4P::update() {
    s32 i;
    s32 j;
    TObjPlayer *player;

    refresh_alive_flags();
    i = 0;
    do {
        TObjPlayer *p = get_player_by_client_id(i);
        if (p != NULL) {
            obj_set_flag_20000(p);
        }
        i += 1;
    } while (i < 4);
    queue_destroy_event_descendants(tl_01);
    TQuestThread::destroy_all_in(tl_00);
    TLobby__sub_8020BCE4();
    destroy_floor_decoration_objects();
    j = 0;
    do {
        player = get_player_by_client_id(j);
        if (player != NULL) {
            player->trap_counts.clear();
        }
        j += 1;
    } while (j < 4);
}

void TPlayerBattleCtrl4P::shuffle_order() {
    s32 order[4];
    s32 i;
    s32 a;
    s32 b;
    s32 t;
    for (i = 0; i < 4; i++) {
        order[i] = i;
    }
    for (i = 0; i < 30; i++) {
        a = (s32)(4.0f * (3.0517578e-05f * (f32)rand()));
        b = (s32)(4.0f * (3.0517578e-05f * (f32)rand()));
        if (a != b) {
            t = order[a];
            order[a] = order[b];
            order[b] = t;
        }
    }
    for (i = 0; i < 4; i++) {
        player_order[i] = order[i];
    }
    if (this->intro_window != NULL) {
        this->intro_window->close();
        this->intro_window = NULL;
    }
    if (this->menu_window != NULL) {
        ((TWindowBase *)this->menu_window)->close();
        this->menu_window = NULL;
    }
    close_player_windows();
    set_split_screen_battle_phase(5);
}

void TPlayerBattleCtrl4P::reset_players() {
    s32 i;
    TObjPlayer *p;
    init_scene_objects();
    for (i = 0; i < 4; i++) {
        p = reinterpret_cast<TObjPlayer *>(get_player_by_client_id(i));
        if (p != 0) {
            p->send_selected_spawn_position(player_order[p->get_entity_id()]);
            reset_cameras_to_actor(p, 0);
        }
    }
    destroy_dead_spots(tl_05);
    TBattleProximitySound::destroy();
}

void TPlayerBattleCtrl4P::destroy_dead_spots(TObject *parent) {
    TObject *child = parent->m_down;
    TObject *cur;
    while (parent->m_down != NULL && child != NULL) {
        cur = child;
        child = cur->m_next;
        if (reinterpret_cast<TObject *>(cur)->check_value_equals(dead_spot_class_name) != 0) {
            cur->queue_destruction();
        } else {
            destroy_dead_spots(cur);
        }
    }
}

void TPlayerBattleCtrl4P::update_all_players() {
    s32 i;
    uaddr p;

    i = 0;
    do {
        if ((p = (uaddr)get_player_by_client_id(i)) != 0U) {
            ((TObjPlayer *)p)->release_attached_resource();
        }
        i += 1;
    } while (i < 4);
}

void TPlayerBattleCtrl4P::set_split_screen_battle_phase(s32 phase) {
    this->phase = phase;
    this->phase_state = 0;
}

void TPlayerBattleCtrl4P::set_phase_state(s32 state) { this->phase_state = state; }

s32 TPlayerBattleCtrl4P::get_time_limit() {
    return rule_data->time_limit_seconds * 60;
}

#pragma push

#pragma opt_lifetimes off

void TPlayerBattleCtrl4P::apply_rule_configuration(s32 use_rules) {
  s32 w;
  s32 i;
  s32 flag;
  s32 t;
  s32 j;
  TObjPlayer *p;
  lobby_rule_settings.reset_settings_to_default();
  if (use_rules != 0)
  {
    lobby_rule_settings.set_tech_disk_mode(rule_data->rules[0]);
    lobby_rule_settings.set_weapon_and_armor_mode(rule_data->rules[1]);
    lobby_rule_settings.set_mag_mode(rule_data->rules[2]);
    lobby_rule_settings.set_tool_mode(rule_data->rules[3]);
    lobby_rule_settings.set_trap_mode(rule_data->rules[4]);
    lobby_rule_settings.set_unused_F817(rule_data->rules[5]);
    lobby_rule_settings.set_respawn_mode(rule_data->rules[6]);
    lobby_rule_settings.set_replace_char(rule_data->rules[7]);
    lobby_rule_settings.set_drop_weapon(rule_data->rules[8]);
    lobby_rule_settings.set_hide_target_reticle(rule_data->rules[0xA]);
    lobby_rule_settings.set_meseta_mode(rule_data->rules[0xB]);
    lobby_rule_settings.set_death_level_up(rule_data->value_c);
    for (i = 0; i < 4; i++)
    {
      lobby_rule_settings.set_trap_count(rule_data->slot_rules[i], i);
    }
    lobby_rule_settings.set_enable_sonar(rule_data->rule_d);
    lobby_rule_settings.set_sonar_count(rule_data->level);
    lobby_rule_settings.set_forbid_scape_dolls(rule_data->rule_e);
    lobby_rule_settings.set_lives((u8)rule_data->volume);
    lobby_rule_settings.set_max_tech_level((u8)rule_data->max_tech_level);
    lobby_rule_settings.set_char_level((s16)rule_data->clamped_index);
    lobby_rule_settings.set_time_limit((saddr)rule_data->time_limit_seconds);
    lobby_rule_settings.set_death_tech_level_up((u8)rule_data->value_28);
    flag = 0;
    if ((((s32) rule_data->rules[9]) == 1) && (TLobby::get_game_mode() == 4))
    {
      t = 1;
      for (j = 0; j < 4; j++)
      {
        p = get_player_by_client_id(j);
        if (p != 0)
        {
          t = 1 - t;
          w = 2;
          if (t != 0)
          {
            w = 1;
          }
          s32 &team = player_teams[j];
          team = w;
          p->pk_state.set_team(team);
        }
        else
        {
          player_teams[j] = -1;
        }
      }
      flag = 1;
    }
    lobby_rule_settings.set_is_teams((u8) (flag != 0));
    for (j = 0; j < 4; j++)
    {
      p = get_player_by_client_id(j);
      if (p != 0)
      {
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
  for (j = 0; j < 4; j++)
  {
    if (get_player_by_client_id(j) != NULL)
    {
      apply_battle_rules_to_players();
    }
  }
}

#pragma pop

void TPlayerBattleCtrl4P::hold_player(u16 client_id, s32 hold_input) {
    uaddr id;
    TObjPlayer *player;

    id = client_id;
    player = get_player_by_client_id(id);
    if (player != NULL) {
        send_impose_hold(player, -1);
    }
    if (hold_input != 0) {
        TWindowCtrl::begin_client_keyboard_hold(id);
        request_active_window_close();
        TWindowCtrl::suppress_slot(id);
    }
}

s32 TPlayerBattleCtrl4P::calculate_rankings() {
    s32 n;
    s32 i;
    s32 j;
    TObjPlayer *p;
    s32 rank;
    s32 m;
    s32 k;
    for (k = 0; k < 4; k++) {
        split_screen_battle_rankings[k].client_id = 0xFFFF;
        split_screen_battle_rankings[k].place = 0;
        split_screen_battle_rankings[k].score = 0;
    }
    n = 0;
    if (lobby_rule_settings.get_is_teams() == 1) {
        BattleTeamTotals team = {0, 0};
        for (k = 0; k < 4; k++) {
            p = get_player_by_client_id(k);
            if (p != 0) {
                s32 t = p->pk_state.get_team() != 1 ? 1 : 0;
                team.team[t] += p->battle_score.slots.get_score();
            }
        }
        for (k = 0; k < 4; k++) {
            p = get_player_by_client_id(k);
            if (p != 0) {
                split_screen_battle_rankings[n].client_id = p->get_entity_id();
                split_screen_battle_rankings[n].score = team.team[p->pk_state.get_team() != 1 ? 1 : 0];
                n++;
            }
        }
    } else {
        for (k = 0; k < 4; k++) {
            p = get_player_by_client_id(k);
            if (p != 0) {
                split_screen_battle_rankings[n].client_id = p->get_entity_id();
                split_screen_battle_rankings[n].score = p->battle_score.slots.get_score();
                n++;
            }
        }
        if (n <= 1) {
            return 0;
        }
    }
    for (i = 0; i < n - 1; i++) {
        if (split_screen_battle_rankings[i].client_id != 0xFFFF) {
            for (j = i + 1; j < n; j++) {
                if (split_screen_battle_rankings[j].client_id != 0xFFFF && split_screen_battle_rankings[i].score < split_screen_battle_rankings[j].score) {
                    BattleRanking tmp = split_screen_battle_rankings[i];
                    copy_battle_ranking(&split_screen_battle_rankings[i], &split_screen_battle_rankings[j]);
                    copy_battle_ranking(&split_screen_battle_rankings[j], &tmp);
                }
            }
        }
    }
    rank = 0;
    for (m = 0; m < n; m++) {
        split_screen_battle_rankings[m].place = rank;
        if (m < n - 1 && split_screen_battle_rankings[m].score != split_screen_battle_rankings[m + 1].score) {
            rank = m + 1;
        }
    }
    return 1;
}

s32 TPlayerBattleCtrl4P::check_all_players_flag() {
    s32 client_id;
    TObjPlayer *player;

    for (client_id = 0; client_id < 4; client_id++) {
        player = get_player_by_client_id(client_id);
        if (player != NULL && player->test_actor_flags(0x02000000) != 0) {
            return 0;
        }
    }
    return 1;
}

void TPlayerBattleCtrl4P::release_player(u16 client_id, s32 release_input) {
    TObjPlayer *player;
    if ((player = get_player_by_client_id(client_id)) != NULL) {
        send_release_hold(player);
    }
    if (release_input != 0) {
        TWindowCtrl::end_client_keyboard_hold(client_id);
        TWindowCtrl::clear_flag();
        TWindowCtrl::unsuppress_slot(client_id);
    }
}


s32 TPlayerBattleCtrl4P::is_battle_decided() {
    s32 count = 0;
    s32 i = 0;
    s32 ok;
    s32 team;
    TObjPlayer *p;
    BattleTeamTotals seen = {0, 0};
    do {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            ok = 1;
            if (player_active[i] == 0) {
                ok = 0;
            } else if (p->actorFlags & 0x800) {
                if (lobby_rule_settings.get_respawn_mode() == 1) {
                    ok = 0;
                } else if (lobby_rule_settings.get_respawn_mode() == 2 && p->battle_score.get_timer() == 0) {
                    ok = 0;
                }
            }
            if (ok != 0) {
                count++;
                if (lobby_rule_settings.get_is_teams() == 1) {
                    team = p->pk_state.get_team() - 1;
                    if (team >= 0 && team < 2) {
                        seen.team[team] = 1;
                    }
                }
            }
        }
        i++;
    } while (i < 4);
    if (lobby_rule_settings.get_is_teams() == 1 && (seen.team[0] == 0 || seen.team[1] == 0)) {
        return (u8)(1);
    }
    return (u8)(count <= 1);
}

void TPlayerBattleCtrl4P::update_timed_events(s32 frames) {
    s32 i;
    switch (timed_event_state) {
    case 0:
        if (local_client_id == designated_client_id) {
            for (i = 0; i < 8; i++) {
                if (timed_event_flags[i] != 0 && frames / 60 == battle_event_second_table[i]) {
                    timed_event_flags[i] = 0;
                    request_timed_event();
                }
            }
        }
        break;
    case 1:
        set_state();
        break;
    case 2:
        start_match();
        break;
    }
}

void TPlayerBattleCtrl4P::request_timed_event() { timed_event_state = 1; }

// start_match loads each of its strings with its own lis/addi (no pooled .rodata base).
#pragma pool_data off
void TPlayerBattleCtrl4P::start_match() {
    char buf[0x40];
    BattleRanking *e;
    s32 i;
    TObjPlayer *p;
    reset_score_counters();
    calculate_rankings();
    TWindowCtrl::append_message_all("SCORE", 0x200);
    for (i = 0; i < 4; i++) {
        e = &split_screen_battle_rankings[i];
        p = get_player_by_client_id(e->client_id);
        if (p != 0) {
            sprintf(buf, "%s %s", TPlayerBattleCtrl4P_player_name_formats[e->place], p->get_name());
            TWindowCtrl::append_message_all(buf, 0x200);
        }
    }
    notify_lobby("start.adx", 0x3C);
}
#pragma pool_data reset

void TPlayerBattleCtrl4P::update_players() {
    s32 i;
    TObjPlayer *player;

    i = 0;
    do {
        player = get_player_by_client_id(i);
        if ((player != NULL) && (player->actorFlags & 0x800)) {
            player->reset_pose();
        }
        i += 1;
    } while (i < 4);
}

s32 TPlayerBattleCtrl4P::set_state() {
    this->timed_event_state = 2;
    return 1;
}

void TPlayerBattleCtrl4P::record_results() {
    CharacterSaveRecord *record;
    BattleRanking *rankings;
    s32 i;
    s32 off;
    BattleRanking *entry;
    i = 0;
    rankings = split_screen_battle_rankings;
    off = 0;
    do {
        entry = (BattleRanking *)((u8 *)rankings + off);
        if (get_player_by_client_id(entry->client_id) != NULL) {
            record = (CharacterSaveRecord *)get_character_save_record(entry->client_id);
            if (record != NULL) {
                s16 place = entry->place;
                if (are_split_screen_battle_players_tied() == 0) {
                    switch (place) {
                    case 0:
                        {
                            s32 count = record->split_screen_battle.place_counts[0] + 1;
                            s32 lim = 0xFFFF;
                            if (count < lim) lim = count;
                            record->split_screen_battle.place_counts[0] = lim;
                        }
                        break;
                    case 1:
                        {
                            s32 count = record->split_screen_battle.place_counts[1] + 1;
                            s32 lim = 0xFFFF;
                            if (count < lim) lim = count;
                            record->split_screen_battle.place_counts[1] = lim;
                        }
                        break;
                    case 2:
                        {
                            s32 count = record->split_screen_battle.place_counts[2] + 1;
                            s32 lim = 0xFFFF;
                            if (count < lim) lim = count;
                            record->split_screen_battle.place_counts[2] = lim;
                        }
                        break;
                    case 3:
                        {
                            s32 count = record->split_screen_battle.place_counts[3] + 1;
                            s32 lim = 0xFFFF;
                            if (count < lim) lim = count;
                            record->split_screen_battle.place_counts[3] = lim;
                        }
                        break;
                    }
                }
                {
                    s32 count = record->split_screen_battle.disconnect_count - 1;
                    record->split_screen_battle.disconnect_count = count > 0 ? count : 0;
                }
            }
        }
        i++;
        off += sizeof(BattleRanking);
    } while (i < 4);
    TAdSinglePlyChrSelectGC__sub_801FCE6C();
}

void TPlayerBattleCtrl4P::reset_score_counters() { this->timed_event_state = 0; unknown_290 = 0; }

void TPlayerBattleCtrl4P::notify_lobby(const char *file, saddr duration) {
    play_cue_stream_file(file);
    show_duel_result_window(-50, duration);
}

void TPlayerBattleCtrl4P::reset_phase() { set_split_screen_battle_phase(0); }

void TPlayerBattleCtrl4P::init() {
    recreate_all_players();
    advance_item_system_generation();
    reload_ready = 1;
}

void TPlayerBattleCtrl4P::reset_ctrl_to_default() {
    TPlayerBattleCtrl4P *ctrl = instance;
    if (ctrl != NULL) {
        ctrl->reset_phase();
    }
}

void TPlayerBattleCtrl4P::refresh_alive_flags() { update_player_alive_flags(); }

void TPlayerBattleCtrl4P::update_player_alive_flags() {
    s32 i;
    TObjPlayer *e;
    s32 v;
    for (i = 0; i < 4; i++) {
        e = get_player_by_client_id(i);
        if (e != NULL) {
            calc_battle_score(e);
            v = 1;
            if (e->actorFlags & 0x800) {
                if (lobby_rule_settings.get_respawn_mode() == 1) {
                    v = 0;
                } else if (lobby_rule_settings.get_respawn_mode() == 2 && e->battle_score.get_timer() == 0) {
                    v = 0;
                }
            }
            player_active[i] = v;
        }
    }
}

s32 TPlayerBattleCtrl4P::calc_battle_score(TObjPlayer *player) {
    f32 score;
    s32 total;

    score = (f32)player->battle_score.damage_given.get_total();
    score -= (f32)player->battle_score.damage_taken.get_total();
    score += (f32)player->battle_score.kills.get_total();
    score -= (f32)player->battle_score.deaths.get_total();
    score += (f32)player->get_actor_meseta() * player->battle_score.meseta.get_bonus_weight();
    total = (s32)score;
    player->battle_score.slots.set_score(total);
    return total;
}
s32 are_split_screen_battle_players_tied(void) {
    BattleRanking *e;
    s32 result;
    s32 i;
    result = 1;
    for (i = 0; i < 4; i++) {
        e = &split_screen_battle_rankings[i];
        if (get_player_by_client_id(e->client_id) != NULL && e->place != 0) {
            result = 0;
            break;
        }
    }
    return result;
}
BattleRanking *get_split_screen_battle_rankings(void) {
    return split_screen_battle_rankings;
}

u8 TPlayerBattleCtrl4P::is_battle_mode_active() {
    TPlayerBattleCtrl4P *ctrl = instance;
    if (ctrl != 0) {
        return ctrl->phase == 1 || ctrl->phase == 2;
    }
    return 0;
}

void TPlayerBattleCtrl4P::clear_player_windows() {
    s32 i;
    for (i = 0; i < 4; i++) {
        player_windows[i] = 0;
    }
}

void TPlayerBattleCtrl4P::create_result_windows() {
    for (s32 i = 0; i < 4; i++) {
        if (get_player_by_client_id(i) != 0) {
            player_windows[i] = new TWindowDuelResult(i);
        }
    }
}

void TPlayerBattleCtrl4P::close_player_windows() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (player_windows[i] != 0) {
            player_windows[i]->close();
            player_windows[i] = 0;
        }
    }
}

s32 TPlayerBattleCtrl4P::close_windows_on_button() {
    s32 r = 1;
    s32 i;
    TObjPlayer *p;
    for (i = 0; i < 4; i++) {
        if ((p = get_player_by_client_id(i)) != NULL) {
            if (player_windows[i] != NULL) {
                if (test_pressed_buttons_packed(&controller_input_state.controllers[p->get_controller_port()], 2) != 0) {
                    player_windows[i]->close();
                    player_windows[i] = 0;
                } else {
                    r = 0;
                }
            }
        }
    }
    return r;
}
