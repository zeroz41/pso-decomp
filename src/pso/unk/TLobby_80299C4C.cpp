#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/unk/TLobby_80299C4C.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/object/TObjChallenge4PRetry.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/olgaflow/TBoss6EmptyWarp.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"

#include "types.h"
#include "pso/unk/TLobby_802268F4.h"

#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/system/ControllerInput.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TUnk_804DC7C4.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"

extern "C" {
s32 load_floor_sound_bank();
s32 TLobby__sub_801403B4(s32);
}
void init_music_sequencer(s32);
void init_area_lights(void);

void TLobby::update_floor_state_deferred() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

// inferred: the JUNGLE01-07 init of area_initializer_dispatch_table
s32 init_jungle_area(void) {
    get_current_floor_area();
    load_floor_sound_bank();
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
        TLobby::create_mist_ctrl(tl_05, NULL);
    }
    return 1;
}

void TLobby::update_scene_alt() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }


s32 initialize_boss_scene(void) {
    s32 area;

    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    if (is_split_screen() == 0) {
        new TUnk_804DC7C4(tl_particlemodel);
    }
    TLobby::create_tasks();
    TLobby__sub_801403B4(0);
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

const char *TObjChallenge4PRetry__class_name = "TObjChallenge4PRetry";

s32 TLobby__sub_80292F5C();

s32 TLobby::is_multi_ready() {
    if ((TLobby::get_challenge_mode_flag() != 0) || (TLobby__sub_80292F5C() <= 1)) {
        return 0;
    }
    return 1;
}

void TObjChallenge4PRetry::close_window_field30() {
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
    this->message = reinterpret_cast<TWindowMessage *>(TWindowMessage::create(
        get_window_layout_position(0x39),
        message_window_position, 1));
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
    this->menu = reinterpret_cast<TWindowSubComCardList *>(create_window_menu_default(reinterpret_cast<saddr>(get_window_layout_position(0x3A)), 3));
    if (this->menu != NULL) {
        this->menu->add_text_entry(get_message_text(0x5B), 5, 0);
        this->menu->add_text_entry(get_message_text(0x5C), 5, 1);
        this->menu->calc_window_size();
        this->menu->set_loss_flag();
        this->menu->set_selected_index(0);
    }
}

void send_giveup_to_all_players__6TLobbyFv(void) {
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

void close_giveup_window__6TLobbyFPv(void* a0) { TWindowCtrl::suppress_slot(local_client_id); TLobby::play_effect_all_players(a0); }

void play_all_players_effect__6TLobbyFPv(void* a0) { TWindowCtrl::disable_client_main_menu(local_client_id); TLobby::play_effect_all_players(a0); }

void play_effect_all_players__6TLobbyFPv(void*) {
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


u8 TLobby__sub_8029A16C(void) {
    return (u8) (local_client_id == designated_client_id);
}

void TObjChallenge4PRetry::countdown_and_destroy() {
    s32 countdown;

    ((s32 (*)())play_all_players_effect__6TLobbyFPv)();
    countdown = this->countdown - 1;
    this->countdown = countdown;
    if (countdown <= 0) {
        TLobby::start_challenge_countdown();
        ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(this);
        close_window();
        close_window_field30();
        queue_destruction();
    }
}

void TKeyBoardControl__sub_8000F950(void);
s32 TLobby__sub_80291F9C();
}

extern s32 evt2_random_enemies_mode;

void giveup_window_handle_select(void *arg0) {

    ((s32 (*)())play_effect_all_players__6TLobbyFPv)();
    switch (TLobby__sub_80291F9C()) {
    case 0:
        play_cue_stream_file("lose.adx");
        ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(arg0);
        ((TObjChallenge4PRetry *)arg0)->close_window();
        ((TObjChallenge4PRetry *)arg0)->close_window_field30();
        ((TObject *)arg0)->queue_destruction();
        if (is_quest_active() == 1) {
            TLobby::clear_counter();
            evt2_random_enemies_mode = 0;
            TKeyBoardControl__sub_8000F950();
        }
        return;
    case 1:
        play_sound_effect(0x52812, 0, 0, 0);
        ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(arg0);
        TLobby::play_all_players_effect(arg0);
        ((TObjChallenge4PRetry *)arg0)->close_window_field30();
        ((TObjChallenge4PRetry *)arg0)->close_window();
        ((TObjChallenge4PRetry *)arg0)->countdown = 0x1E;
        ((TObjChallenge4PRetry *)arg0)->state = 4;
        return;
    default:
        if (((s32) ((TObjChallenge4PRetry *)arg0)->m_20 != 0) && ((s32) ((TObjChallenge4PRetry *)arg0)->m_24 == 0)) {
            ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(arg0);
            TLobby::close_giveup_window(arg0);
            ((TObjChallenge4PRetry *)arg0)->close_window_field30();
            ((TObjChallenge4PRetry *)arg0)->open_giveup_window();
            ((TObjChallenge4PRetry *)arg0)->state = 2;
        }
        break;
    }
}
extern "C" {


extern s32 retry_selection_value_table[];

void TObjChallenge4PRetry::handle_retry_menu_select() {
    s32 selected_menu_value;

    ((s32 (*)())close_giveup_window__6TLobbyFPv)();
    if (this->menu == NULL) {
        open_giveup_window();
    }
    if (this->menu->is_decided() != 0) {
        selected_menu_value = this->menu->get_selected_value();
        if (selected_menu_value != 2) {
            TLobby::set_retry_selection(retry_selection_value_table[selected_menu_value]);
            ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(this);
            TLobby::play_effect_all_players(this);
            this->m_24 = 1;
            this->state = 3;
        }
    }
}




void TObjChallenge4PRetry::update_challenge_4p_retry() {
    TObjPlayer *player;
    ((s32 (*)())play_all_players_effect__6TLobbyFPv)();
    player = get_player_by_client_id(local_client_id);
    if ((player != NULL) && (player->is_controls_locked() == 0) && (test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0)) {
        ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(this);
        TLobby::close_giveup_window(this);
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
    TLobby::play_effect_all_players(this);
    flag = 1;
    for (i = 0; i < 4; i++) {
        TObjPlayer *player = get_player_by_client_id(i);
        if (player != NULL && player->test_actor_flags(0x02000000) != 0) {
            flag = 0;
            break;
        }
    }
    if (flag != 0) {
        if (this->m_20 != 0) {
            ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(this);
            TLobby::close_giveup_window(this);
            this->state = 2;
        } else {
            ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(this);
            TLobby::play_effect_all_players(this);
            open_message_window();
            this->state = 3;
        }
    }
}

void *__ct__20TObjChallenge4PRetryFP7TObject(void *, void *);

void TObjChallenge4PRetry::run_task() {
    u8 *arg0 = (u8 *)this;
    this->m_20 = ((s32 (*)(void *))TLobby__sub_8029A16C)(arg0);
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
        giveup_window_handle_select(arg0);
        break;
    case 4:
        this->countdown_and_destroy();
        break;
    }
    if (TLobby::is_multi_ready() == 0) {
        ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(arg0);
        this->close_window();
        this->close_window_field30();
        this->queue_destruction();
    }
}

TObjChallenge4PRetry::~TObjChallenge4PRetry() {
    if (m_20 != 0 && m_24 == 0) {
        TLobby::set_retry_selection(0);
    }
}
}

TObjChallenge4PRetry::TObjChallenge4PRetry(TObject *parent) : TObject(parent) {
    m_name = TObjChallenge4PRetry__class_name;
    this->m_20 = ((s32 (*)(void *))TLobby__sub_8029A16C)(this);
    this->m_24 = 0;
    this->menu = NULL;
    this->message = NULL;
    this->state = 0;
}

void *TObjChallenge4PRetry::create(void *arg0) {
    void *o = TObject::operator new(0x34);
    if (o != NULL) {
        o = __ct__20TObjChallenge4PRetryFP7TObject(o, arg0);
    }
    return o;
}
