#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/object/TObjChallenge4PRetry.h"
#include "pso/quest/challenge/TChallenge4P.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TObjBagWarnWin.h"
#include "pso/audio/SoundRequests.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/olgaflow/TBoss6EmptyWarp.h"
#include "pso/network/TLobby.h"
#include "pso/object/ambient/TObjMistCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/window/WindowMenuFactory.h"

#include "types.h"

#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/audio/MusicControl.h"
#include "pso/system/ControllerInput.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/FloorReflection.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/map/area/AreaScene.h"
#include "pso/object/ambient/SceneLighting.h"
#include "pso/quest/QuestOpcodeHandlers.h"
#include "pso/quest/QuestStoryFlags.h"
#include "pso/map/FloorWaveEvents.h"
#include "pso/audio/SoundPlayback.h"

void update_floor_state_deferred() { refresh_render_state(); stop_audio_streams(); unload_current_floor_resources(); update_current_floor(); TLobby::clear_session_buffers(); }

// inferred: the JUNGLE01-07 init of area_initializer_dispatch_table
s32 init_jungle_area(void) {
    load_floor_sound_bank(get_current_floor_area());
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    if ((get_main_phase() != 0xE) || (is_quest_active() == 0)) {
        switch (((s32)get_current_floor_area())) {
        case 0x17:
            set_story_flag_or_send_quest_flag(0x51);
            break;
        }
    }
    if (is_split_screen() != 0) {
        play_area_music("j_b.adx");
    } else {
        init_music_sequencer(5);
    }
    if ((TRaderMapCore::is_not_split_screen() == 0) && (((s32)get_current_floor_area()) == AREA_CENTRAL_CONTROL_AREA)) {
        TObjMistCtrl::create(tl_05, NULL);
    }
    return 1;
}

void update_scene_alt() { refresh_render_state(); stop_audio_streams(); unload_current_floor_resources(); update_current_floor(); TLobby::clear_session_buffers(); }


s32 initialize_boss_scene(void) {
    s32 area;

    load_floor_sound_bank(get_current_floor_area());
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    if (is_split_screen() == 0) {
        new TFloorReflection(tl_particlemodel);
    }
    TLobby::create_tasks();
    debug_area_hook(0);
    if (is_split_screen() != 0) {
        play_area_music("w_b.adx");
    } else {
        init_music_sequencer(6);
    }
    if ((get_main_phase() != 0xE) || (is_quest_active() == 0)) {
        area = get_current_floor_area();
        switch (area) {
        case AREA_SEABED_UPPER:
            set_story_flag_or_send_quest_flag(0x54);
            break;
        case AREA_SEABED_LOWER:
            set_story_flag_or_send_quest_flag(0x55);
            break;
        }
    }
    return 1;
}
extern "C" {

const char *obj_challenge4p_retry_class_name = "TObjChallenge4PRetry";


}
s32 is_multi_ready() {
    if ((get_challenge_mode_flag() != 0) || (get_camera_view_count() <= 1)) {
        return 0;
    }
    return 1;
}

void TObjChallenge4PRetry::close_message_window() {
    if (this->message != NULL) {
        this->message->close();
        this->message = NULL;
    }
}

s32 retry_selection_value_table[3] = { 1, 0, 0 };
__declspec(section ".data") f32 message_window_position[2] = { 360.0f, 125.0f };

void TObjChallenge4PRetry::open_message_window() {
    if (this->message != NULL) {
        this->message->close();
        this->message = NULL;
    }
    this->message = TWindowMessage::create(
        get_window_layout_position(0x39),
        message_window_position, 1);
    if (this->message != NULL) {
        this->message->append_line(get_message_text(0x5E), 1);
    }
}

void TObjChallenge4PRetry::close_window() {
    if (this->menu != NULL) {
        this->menu->close();
        this->menu = NULL;
    }
}

void TObjChallenge4PRetry::open_giveup_window() {
    TWindowSubComCardList *temp = this->menu;
    if (temp != NULL) {
        temp->close();
        this->menu = NULL;
    }
    this->menu = reinterpret_cast<TWindowSubComCardList *>(create_window_menu_default(get_window_layout_position(0x3A), 3));
    if (this->menu != NULL) {
        this->menu->add_text_entry(get_message_text(0x5B), 5, 0);
        this->menu->add_text_entry(get_message_text(0x5C), 5, 1);
        this->menu->calc_window_size();
        this->menu->set_loss_flag();
        this->menu->set_selected_index(0);
    }
}

void TObjChallenge4PRetry::send_giveup_to_all_players() {
    s32 client;

    for (client = 0; client < 4; client++) {
        TObjPlayer *player = get_player_by_client_id(client);
        if ((player != NULL) && (player->check_player_flag1() != 0)) {
            send_release_hold(player);
        }
        TWindowCtrl::unsuppress_slot(client);
        TWindowCtrl::enable_client_main_menu(client);
    }
}

void TObjChallenge4PRetry::close_giveup_window() { TWindowCtrl::suppress_slot(local_client_id); play_effect_all_players(); }

void TObjChallenge4PRetry::play_all_players_effect() { TWindowCtrl::disable_client_main_menu(local_client_id); play_effect_all_players(); }

void TObjChallenge4PRetry::play_effect_all_players() {
    s32 i;
    TObjPlayer *player;

    i = 0;
    do {
        player = get_player_by_client_id(i);
        if (player != NULL) {
            if (player->check_player_flag1() == 0) {
                send_impose_hold(player, -1);
            }
        }
        i += 1;
    } while (i < 4);
}


s32 TObjChallenge4PRetry::is_designated_client() {
    return local_client_id == designated_client_id;
}

void TObjChallenge4PRetry::countdown_and_destroy() {
    s32 countdown;

    play_all_players_effect();
    countdown = this->countdown - 1;
    this->countdown = countdown;
    if (countdown <= 0) {
        start_challenge_countdown();
        send_giveup_to_all_players();
        close_window();
        close_message_window();
        queue_destruction();
    }
}


void TObjChallenge4PRetry::giveup_window_handle_select() {
    play_effect_all_players();
    switch (get_challenge4p_retry_choice()) {
    case 0:
        play_cue_stream_file("lose.adx");
        send_giveup_to_all_players();
        close_window();
        close_message_window();
        queue_destruction();
        if (is_quest_active() == 1) {
            TLobby::clear_counter();
            evt2_random_enemies_mode = 0;
            set_keyboard_input_flag();
        }
        return;
    case 1:
        play_sound_effect(0x52812, 0, 0, 0);
        send_giveup_to_all_players();
        play_all_players_effect();
        close_message_window();
        close_window();
        countdown = 0x1E;
        state = 4;
        return;
    default:
        if ((is_designated != 0) && (selection_sent == 0)) {
            send_giveup_to_all_players();
            close_giveup_window();
            close_message_window();
            open_giveup_window();
            state = 2;
        }
        break;
    }
}

void TObjChallenge4PRetry::handle_retry_menu_select() {
    s32 selected_menu_value;

    close_giveup_window();
    if (this->menu == NULL) {
        open_giveup_window();
    }
    if (this->menu->is_decided() != 0) {
        selected_menu_value = this->menu->get_selected_value();
        if (selected_menu_value != 2) {
            set_retry_selection(retry_selection_value_table[selected_menu_value]);
            send_giveup_to_all_players();
            play_effect_all_players();
            this->selection_sent = 1;
            this->state = 3;
        }
    }
}




void TObjChallenge4PRetry::update_challenge_4p_retry() {
    TObjPlayer *player;
    play_all_players_effect();
    player = get_player_by_client_id(local_client_id);
    if ((player != NULL) && (player->is_controls_locked() == 0) && (test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0)) {
        send_giveup_to_all_players();
        close_giveup_window();
        this->state = 2;
    }
}
void TObjChallenge4PRetry::update_giveup() {
    s32 flag;
    s32 i;
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
    case AREA_PIONEER2_EP2:
        if (has_window_task_root() != 0) {
            break;
        }
        return;
    default:
        return;
    }
    play_effect_all_players();
    flag = 1;
    for (i = 0; i < 4; i++) {
        TObjPlayer *player = get_player_by_client_id(i);
        if (player != NULL && player->test_actor_flags(0x02000000) != 0) {
            flag = 0;
            break;
        }
    }
    if (flag != 0) {
        if (this->is_designated != 0) {
            send_giveup_to_all_players();
            close_giveup_window();
            this->state = 2;
        } else {
            send_giveup_to_all_players();
            play_effect_all_players();
            open_message_window();
            this->state = 3;
        }
    }
}

void TObjChallenge4PRetry::run_task() {
    this->is_designated = is_designated_client();
    switch (this->state) {
    case 0:
        this->update_giveup();
        break;
    case 1:
        this->update_challenge_4p_retry();
        break;
    case 2:
        this->handle_retry_menu_select();
        break;
    case 3:
        giveup_window_handle_select();
        break;
    case 4:
        this->countdown_and_destroy();
        break;
    }
    if (is_multi_ready() == 0) {
        send_giveup_to_all_players();
        this->close_window();
        this->close_message_window();
        this->queue_destruction();
    }
}

TObjChallenge4PRetry::~TObjChallenge4PRetry() {
    if (is_designated != 0 && selection_sent == 0) {
        set_retry_selection(0);
    }
}

TObjChallenge4PRetry::TObjChallenge4PRetry(TObject *parent) : TObject(parent) {
    m_name = obj_challenge4p_retry_class_name;
    this->is_designated = is_designated_client();
    this->selection_sent = 0;
    this->menu = NULL;
    this->message = NULL;
    this->state = 0;
}

void *TObjChallenge4PRetry::create(TObject *parent) {
    void *o = new TObjChallenge4PRetry(parent);
    return o;
}
