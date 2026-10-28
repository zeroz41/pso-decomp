#include "pso/map/FloorResourceCallbacks.h"
#include "pso/TObjChallenge4PRetry.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss6EmptyWarp.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/map/FloorArea.h"

extern "C" {
s32 get_main_phase();
s32 is_split_screen();
s32 is_quest_active();
s32 play_area_music(s32 *);
s32 load_floor_sound_bank();
extern s32 lbl_804651C0[];
extern void *tl_05;
s32 TLobby__sub_80299C7C(void);
s32 TLobby__sub_801403B4(s32);
u32 __nw__7TObjectFUl(s32);
s32 create_instance__10TSceneSoraFPv(void*, s32);
void fn_802F105C(void);
s32 fn_802F1084();
void fn_802FE9E0(void);
void fn_802FEA0C(void);
}
void init_music_sequencer(s32);
void init_area_lights(void);
s32 init_scene_delo2(void);
s32 load_dragon2_scene(void);
void stop_cue_stream(void);
void create_boss8_demo_objects(void);
void init_scene_boss2_tunnel(void);

void TLobby::refresh_lobby_state() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); stop_cue_stream(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

extern s32 tl_particlemodel;

s32 TLobby::init_particle_model() {
    void* obj;
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    if ((is_split_screen() == 0) && ((obj = (void*)__nw__7TObjectFUl(0x3C)) != 0)) {
        create_instance__10TSceneSoraFPv(obj, tl_particlemodel);
    }
    TBoss6EmptyWarp::create();
    return 1;
}

void TLobby::update_field_state() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); stop_cue_stream(); fn_802FE9E0(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

extern s32 lbl_804651A0[];

s32 load_dragon2_scene(void) {
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    fn_802FEA0C();
    init_area_lights();
    TLobby::create_tasks();
    create_boss8_demo_objects();
    play_area_music(lbl_804651A0);
    return 1;
}

void TLobby::update_subsystems() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); stop_cue_stream(); fn_802F105C(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

extern s32 lbl_804651B0[];

s32 init_scene_delo2(void) {
    void *obj;
    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_scene_boss2_tunnel();
    init_area_lights();
    TLobby::create_tasks();
    fn_802F1084();
    TLobby__sub_801403B4(0);
    play_area_music(lbl_804651B0);
    if ((is_split_screen() == 0) && ((obj = (void *)__nw__7TObjectFUl(0x3C)) != 0)) {
        create_instance__10TSceneSoraFPv(obj, tl_particlemodel);
    }
    return 1;
}

void TLobby::update_floor_state_deferred() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

s32 TLobby__sub_80299C7C(void) {
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
            TBoss4DarkFalz::dispatch_by_main_phase(0x51);
            break;
        }
    }
    if (is_split_screen() != 0) {
        play_area_music(lbl_804651C0);
    } else {
        init_music_sequencer(5);
    }
    if ((TRaderMapCore::is_not_split_screen() == 0) && (((s32)get_current_floor_area()) == AREA_CENTRAL_CONTROL_AREA)) {
        TLobby::create_mist_ctrl(tl_05, NULL);
    }
    return 1;
}

void TLobby::update_scene_alt() { TLobby::refresh_render_state(); TLobby::stop_audio_streams(); unload_current_floor_resources(); TLobby::update_current_floor(); TLobby::clear_session_buffers(); }

#define CIS ((s32 (*)(s32, s32))create_instance__10TSceneSoraFPv)
extern s32 lbl_804651C8[];

s32 initialize_boss_scene(void) {
    s32 area;
    u32 temp_new;

    get_current_floor_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    if (is_split_screen() == 0) {
        temp_new = __nw__7TObjectFUl(0x3C);
        if (temp_new != 0U) {
            CIS(temp_new, tl_particlemodel);
        }
    }
    TLobby::create_tasks();
    TLobby__sub_801403B4(0);
    if (is_split_screen() != 0) {
        play_area_music(lbl_804651C8);
    } else {
        init_music_sequencer(6);
    }
    if ((get_main_phase() != 0xE) || (is_quest_active() == 0)) {
        area = get_current_floor_area();
        switch (area) {
        case AREA_SEABED_UPPER:
            TBoss4DarkFalz::dispatch_by_main_phase(0x54);
            break;
        case AREA_SEABED_LOWER:
            TBoss4DarkFalz::dispatch_by_main_phase(0x55);
            break;
        }
    }
    return 1;
}
extern "C" {

void send_giveup_to_all_players__6TLobbyFv(void);
void close_giveup_window__6TLobbyFPv(void* a0);
void play_all_players_effect__6TLobbyFPv(void* a0);
void play_effect_all_players__6TLobbyFPv(void*);
u32 check_room_seq_4__16TAdChrSelASlotGCFl(s32, s32);
s32 check_player_flag1__6TLobbyFv();
s32 TLobby__sub_8024AC20(int);
u32 set_window_mode_4__6TLobbyFPvll(s32, s32 *, s32);
s32 TLobby__sub_80292F5C();
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 get_player_by_client_id(int);
s32 TQuestVmDownLoadServer__sub_8006EF6C(s32);
s32 get_window_layout_position(s32);
void TWindow__close(u8 *arg0);
void TObjPlayer__sub_8024ABDC(s32 arg0);
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);

s32 TLobby::is_multi_ready() {
    if ((TLobby::get_challenge_mode_flag() != 0) || (TLobby__sub_80292F5C() <= 1)) {
        return 0;
    }
    return 1;
}

void TObjChallenge4PRetry::close_window_field30() { if (*(unsigned int*)((char*)this + 0x30) != 0) { TWindow__close((u8 *)(*(void**)((char*)this + 0x30))); *(int*)((char*)this + 0x30) = 0; } }

s32 retry_selection_value_table[3] = { 1, 0, 0 };
__declspec(section ".data") s32 message_window_position[2] = { 0x43B40000, 0x42FA0000 };

void TObjChallenge4PRetry::open_message_window() {
    if ((u32) *(u32 *)((s8 *)this + 0x30) != 0U) {
        TWindow__close((u8 *)(*(void **)((s8 *)this + 0x30)));
        *(u32 *)((s8 *)this + 0x30) = 0U;
    }
    *(u32 *)((s8 *)this + 0x30) = set_window_mode_4__6TLobbyFPvll(get_window_layout_position(0x39), message_window_position, 1);
    if ((u32) *(u32 *)((s8 *)this + 0x30) != 0U) {
        ((TLobby *)(*(u32 *)((s8 *)this + 0x30)))->send_and_handle(TQuestVmDownLoadServer__sub_8006EF6C(0x5E), 1);
    }
}

void TObjChallenge4PRetry::close_window() { if (*(unsigned int*)((char*)this + 0x2c) != 0) { TWindow__close((u8 *)(*(void**)((char*)this + 0x2c))); *(int*)((char*)this + 0x2c) = 0; } }

void TObjChallenge4PRetry::open_giveup_window() {
    u32 temp;

    temp = *(u32 *)((s8 *)this + 0x2C);
    if (temp != 0U) {
        TWindow__close((u8 *)temp);
        *(u32 *)((s8 *)this + 0x2C) = 0U;
    }
    *(u32 *)((s8 *)this + 0x2C) = check_room_seq_4__16TAdChrSelASlotGCFl(get_window_layout_position(0x3A), 3);
    if ((u32) *(u32 *)((s8 *)this + 0x2C) != 0U) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)(*(u32 *)((s8 *)this + 0x2C)), (int)(TQuestVmDownLoadServer__sub_8006EF6C(0x5B)), 5, 0);
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)(*(u32 *)((s8 *)this + 0x2C)), (int)(TQuestVmDownLoadServer__sub_8006EF6C(0x5C)), 5, 1);
        ((TWindowSubComCard *)(*(u32 *)((s8 *)this + 0x2C)))->calc_window_size();
        ((TLobby *)(*(u32 *)((s8 *)this + 0x2C)))->set_loss_flag();
        ((TWindowSubComCardList *)(*(u32 *)((s8 *)this + 0x2C)))->set_selected_index(0);
    }
}

void send_giveup_to_all_players__6TLobbyFv(void) {
    s32 player;
    s32 var_r31;

    var_r31 = 0;
    do {
        player = get_player_by_client_id(var_r31);
        if ((player != 0) && (check_player_flag1__6TLobbyFv() != 0)) {
            TObjPlayer::send_code_45_1(player);
        }
        ((TWindowCtrl *)var_r31)->unsuppress_slot();
        TLobby__sub_8024AC20(var_r31);
        var_r31 += 1;
    } while (var_r31 < 4);
}

    extern int local_client_id;
void close_giveup_window__6TLobbyFPv(void* a0) { ((TWindowCtrl *)local_client_id)->suppress_slot(); play_effect_all_players__6TLobbyFPv(a0); }

void play_all_players_effect__6TLobbyFPv(void* a0) { TObjPlayer__sub_8024ABDC((local_client_id)); play_effect_all_players__6TLobbyFPv(a0); }

void play_effect_all_players__6TLobbyFPv(void*) {
    s32 var_r31;
    s32 player;

    var_r31 = 0;
    do {
        player = get_player_by_client_id(var_r31);
        if (player != 0) {
            if (check_player_flag1__6TLobbyFv() == 0) {
                play_effect_default__10TObjPlayerFii(player, -1);
            }
        }
        var_r31 += 1;
    } while (var_r31 < 4);
}

u8 TLobby__sub_8029A16C(void);

extern s32 TLobby__designated_client_id;

u8 TLobby__sub_8029A16C(void) {
    return (u8) (local_client_id == TLobby__designated_client_id);
}

void queue_destruction__7TObjectFv(void *arg0);

void TObjChallenge4PRetry::countdown_and_destroy() {
    s32 temp_r0;

    ((s32 (*)())play_all_players_effect__6TLobbyFPv)();
    temp_r0 = *(s32 *)((s8 *)this + 0x28) - 1;
    *(s32 *)((s8 *)this + 0x28) = temp_r0;
    if (temp_r0 <= 0) {
        TLobby::start_challenge_countdown();
        ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(this);
        close_window();
        close_window_field30();
        queue_destruction__7TObjectFv(this);
    }
}

void TKeyBoardControl__sub_8000F950(void);
s32 play_sound_effect(s32, s32, s32, s32);
void play_cue_stream_file(s32 name);
s32 TLobby__sub_80291F9C();
}

extern s32 lbl_804651E8[];
extern s32 evt2_random_enemies_mode;

void giveup_window_handle_select(void *arg0) {

    ((s32 (*)())play_effect_all_players__6TLobbyFPv)();
    switch (TLobby__sub_80291F9C()) {
    case 0:
        play_cue_stream_file((s32)lbl_804651E8);
        ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(arg0);
        ((TObjChallenge4PRetry *)arg0)->close_window();
        ((TObjChallenge4PRetry *)arg0)->close_window_field30();
        queue_destruction__7TObjectFv(arg0);
        if (is_quest_active() == 1) {
            TLobby::clear_counter();
            evt2_random_enemies_mode = 0;
            TKeyBoardControl__sub_8000F950();
        }
        return;
    case 1:
        play_sound_effect(0x52812, 0, 0, 0);
        ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(arg0);
        play_all_players_effect__6TLobbyFPv(arg0);
        ((TObjChallenge4PRetry *)arg0)->close_window_field30();
        ((TObjChallenge4PRetry *)arg0)->close_window();
        *(s32 *)((s8 *)arg0 + 0x28) = 0x1E;
        *(s32 *)((s8 *)arg0 + 0x1C) = 4;
        return;
    default:
        if (((s32) ((TObjChallenge4PRetry *)arg0)->m_20 != 0) && ((s32) ((TObjChallenge4PRetry *)arg0)->m_24 == 0)) {
            ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(arg0);
            close_giveup_window__6TLobbyFPv(arg0);
            ((TObjChallenge4PRetry *)arg0)->close_window_field30();
            ((TObjChallenge4PRetry *)arg0)->open_giveup_window();
            *(s32 *)((s8 *)arg0 + 0x1C) = 2;
        }
        break;
    }
}
extern "C" {

s32 get_selected_menu_value(u32);

extern s32 retry_selection_value_table[];

void TObjChallenge4PRetry::handle_retry_menu_select() {
    s32 selected_menu_value;

    ((s32 (*)())close_giveup_window__6TLobbyFPv)();
    if ((u32) *(u32 *)((s8 *)this + 0x2C) == 0U) {
        open_giveup_window();
    }
    if (((TWindowMenu *)(*(u32 *)((s8 *)this + 0x2C)))->is_visible() != 0) {
        selected_menu_value = get_selected_menu_value(*(u32 *)((s8 *)this + 0x2C));
        if (selected_menu_value != 2) {
            TLobby::set_retry_selection(retry_selection_value_table[selected_menu_value]);
            ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(this);
            play_effect_all_players__6TLobbyFPv(this);
            this->m_24 = 1;
            *(s32 *)((s8 *)this + 0x1C) = 3;
        }
    }
}

s32 obj_testFlags30__14TObjCollidableFUl(s32, s32);

s32 TWindowCtrlMain__sub_8024CE58();

s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 check_flag_100__10TObjPlayerFPv();

extern s8 controller_input_state[];

void TObjChallenge4PRetry::update_challenge_4p_retry() {
    ((s32 (*)())play_all_players_effect__6TLobbyFPv)();
    if ((get_player_by_client_id(local_client_id) != 0U) && (check_flag_100__10TObjPlayerFPv() == 0) && (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 4) != 0)) {
        ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(this);
        close_giveup_window__6TLobbyFPv(this);
        *(s32 *)((s8 *)this + 0x1C) = 2;
    }
}
void TObjChallenge4PRetry::update_giveup() {
    s32 flag;
    s32 i;
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
    case AREA_PIONEER2_EP2:
        if (TWindowCtrlMain__sub_8024CE58() != 0) {
            break;
        }
        return;
    default:
        return;
    }
    play_effect_all_players__6TLobbyFPv(this);
    flag = 1;
    for (i = 0; i < 4; i++) {
        u32 ctrl = get_player_by_client_id(i);
        if (ctrl != 0U && obj_testFlags30__14TObjCollidableFUl(ctrl, 0x02000000) != 0) {
            flag = 0;
            break;
        }
    }
    if (flag != 0) {
        if (this->m_20 != 0) {
            ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(this);
            close_giveup_window__6TLobbyFPv(this);
            *(s32 *)((s8 *)this + 0x1C) = 2;
        } else {
            ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(this);
            play_effect_all_players__6TLobbyFPv(this);
            open_message_window();
            *(s32 *)((s8 *)this + 0x1C) = 3;
        }
    }
}

extern s32 TObjChallenge4PRetry__class_name;
void *__ct__20TObjChallenge4PRetryFP7TObject(void *, void *);

void TObjChallenge4PRetry::run_task() {
    u8 *arg0 = (u8 *)this;
    this->m_20 = ((s32 (*)(void *))TLobby__sub_8029A16C)(arg0);
    switch (*(s32 *)&this->_pad1c) {
    case 0:
        ((TObjChallenge4PRetry *)arg0)->update_giveup();
        break;
    case 1:
        ((TObjChallenge4PRetry *)arg0)->update_challenge_4p_retry();
        break;
    case 2:
        ((TObjChallenge4PRetry *)arg0)->handle_retry_menu_select();
        break;
    case 3:
        giveup_window_handle_select(arg0);
        break;
    case 4:
        ((TObjChallenge4PRetry *)arg0)->countdown_and_destroy();
        break;
    }
    if (TLobby::is_multi_ready() == 0) {
        ((s32 (*)(void *))send_giveup_to_all_players__6TLobbyFv)(arg0);
        ((TObjChallenge4PRetry *)arg0)->close_window();
        ((TObjChallenge4PRetry *)arg0)->close_window_field30();
        queue_destruction__7TObjectFv((arg0));
    }
}

TObjChallenge4PRetry::~TObjChallenge4PRetry() {
    if (m_20 != 0 && m_24 == 0) {
        TLobby::set_retry_selection(0);
    }
}
}

TObjChallenge4PRetry::TObjChallenge4PRetry(TObject *parent) : TObject(parent) {
    *(s32 *)((s8 *)this + 0) = (s32) TObjChallenge4PRetry__class_name;
    this->m_20 = ((s32 (*)(void *))TLobby__sub_8029A16C)(this);
    this->m_24 = 0;
    *(s32 *)((s8 *)this + 0x2C) = 0;
    *(s32 *)((s8 *)this + 0x30) = 0;
    *(s32 *)((s8 *)this + 0x1C) = 0;
}

void *TObjChallenge4PRetry::create(void *arg0) {
    void *o = ((void *(*)(int))__nw__7TObjectFUl)(0x34);
    if (o != NULL) {
        o = __ct__20TObjChallenge4PRetryFP7TObject(o, arg0);
    }
    return o;
}
