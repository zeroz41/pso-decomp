// The game mode select scene: the scene-change state machine of the front end (title, story/mode
// select, character select, multi-play setup...), the scene's load/release hook tables and its frame
// loop. One TU: the hook tables open its .data, the frame loop's state (.sbss) and the mode state
// (.sdata) are read and written by every part.
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include <dolphin/mtx/GeoTypes.h>
#include <string.h>
#include "pso/map/FloorResourceCallbacks.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/system/main_loop.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/math/AngleLookup.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/audio/MusicControl.h"
#include "pso/network/TLobby.h"
#include "pso/audio/SoundPlayback.h"
#include "pso/audio/SoundRequests.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/system/AsyncFileRead.h"
#include "pso/render/gjSystem.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/chat/ChatLogHeap.h"
#include "pso/ui/chat/ChatLogLines.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_Snapshot.h"
#include "pso/ui/TLogo.h"
#include "pso/ui/frontend/TAdSEGAlogo.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/unk/TAdDialingSelectGC.h"
#include "pso/ui/frontend/DrawLineResource.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/ui/frontend/TAdEnterPPPPassGC.h"
#include "pso/ui/frontend/TAdEnterPasswordGC.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdEp3Exist.h"
#include "pso/ui/frontend/TAdGameStartGC.h"
#include "pso/ui/frontend/TAdMultiConfirmGC.h"
#include "pso/ui/frontend/TAdMultiOkGC.h"
#include "pso/ui/TAdChrSelPlayerGC.h"
#include "pso/ui/frontend/TAdMultiSaveGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdPlyPltAnimGC.h"
#include "pso/ui/frontend/TAdRayGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "pso/ui/frontend/TAdSelectTxtGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028D5D4.h"
#include "pso/ui/frontend/TAdSoniclogo.h"
#include "pso/ui/frontend/TAdTimeSetGC.h"
#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/ui/frontend/TAdExNetConfirmGC.h"
#include "pso/ui/frontend/TAdLicAgreementGC.h"
#include "pso/ui/frontend/TAdTrialAgreementGC.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"
#include "pso/ui/frontend/TAdSnAkPassConfirmGC.h"
#include "pso/ui/frontend/TAdPsoPassSaveGC.h"
#include "pso/ui/TAdSystemFileCheckGC.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/ui/frontend/TAdMultiSelGameModeGC.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/object/ambient/SceneLighting.h"
#include "pso/system/MallocLoadFilePrc.h"
#include "pso/unk/TTitleScene.h"
#include "pso/map/area/AreaScene.h"
#include "pso/render/GinjaView.h"
#include "pso/ui/window/SmallFontText.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"


// The mode the scene machine shows (create_mode_scene picks the scene object by it) and the one
// before it (sync_mode_state).
s32 multi_chg_game_mode_state = 29;
int chg_game_mode_state_synced = 29;

// Scene change request: the set_* functions set the next mode and 1; the frame loop
// (run_game_mode_select_frame) then destroys the current scene object (2) and creates the next one (0).
s32 game_mode_scene_change_state;
TObject *game_mode_scene_instance;
int TAdPlayerLoadGC::load_state;

// The scene camera's start pose (init_game_mode_select_scene). File-scope objects: they open the
// unit's .rodata, before set_default_camera's own initialisers.
static const Vec game_mode_scene_camera_eye = {0.0f, 0.0f, 0.0f};
static const Vec game_mode_scene_camera_target = {0.0f, 0.0f, -100.0f};

// Load and release hooks of the scene, in pairs: init_game_mode_select_scene runs each load
// front to back (run_load_callback_table), TLobby::release_scene_resources each release back
// to front (TLobby::call_funcs_reverse).
FloorResourceCallbacks game_mode_select_scene_callbacks[23] = {
    {TCameraCtrl::reset_view_state, TCameraCtrl::reset},
    {TCameraCtrl::init_default_view, TCameraCtrl::reset_default_view},
    {update_keyboard_menu, free_keyboard_soft_resources},
    {register_texture_f256_ad_pic_2, TAdSinglePlyChrSelectGC::free_global},
    {register_texture_f256_backtext, TAdSinglePlyChrSelectGC::free_texture_f256_backtext},
    {register_texture_f128_ray, TAdRayGC::destroy_instance},
    {load_multi_ply_chr_select_resources, free_multi_ply_chr_select_resources},
    {TAdTimeSetGC::load_scene_resources, TAdTimeSetGC::free_scene_resources},
    {register_texture_f512_multiplay, TAdGameStartSubGC::destroy_instance},
    {TAdSinglePlyChrSelectGC::alloc_char_buffers, TAdSinglePlyChrSelectGC::free_callbacks},
    {TAdMultiChgGameModeGC::load_scene_resources, TAdMultiChgGameModeGC::free_scene_resources},
    {load_multi_confirm_textures, free_multi_confirm_textures},
    {register_texture_logo_e, TLogo::free_held_object},
    {load_sonic_logo_texture, free_sonic_logo_texture},
    {init_chat_log_heap, free_chat_log_lines},
    {register_player_prate, free_player_prate},
    {load_data_buffers, TObjBoss2Tunnel::free_buffers},
    {KeyboardKeyState::reset_global_keys_b, KeyboardKeyState::reset_global_keys_a},
    {TWindowCtrlMain::reset_windows, TWindowCtrlMain::free_all_windows},
    {set_ending_callback, free_ending_callback},
    {load_keyboard_resources, free_keyboard_resources},
    {alloc_quest_download_buffer, TLobby::free_chr_select_singleton},
    {load_draw_line_task_resource, free_draw_line_task_resource},
};

// The front-end screens' hooks, run after the table above and released before it.
FloorResourceCallbacks lobby_scene_release_callback_table[7] = {
    {initialize_lobby_title_scene, TLobby::destroy_global_object},
    {load_title_midashi_texture, free_title_midashi_texture},
    {load_player_tex_texture, free_player_tex_texture},
    {load_select_gamen_texture, free_select_gamen_texture},
    {load_select_cursor_texture, free_select_cursor_texture},
    {load_chr_sel_slot_texture, free_chr_sel_slot_texture},
    {TLobby::update_menu_cursor_selection, TLobby::free_global_object},
};

s32 TAdMultiChgGameModeGC::is_input_phase_active() {
    s32 r = 0;
    switch (get_main_phase()) {
    case 0:
    case 1:
    case 3:
    case 8:
    case 11:
    case 12:
        break;
    case 2:
    case 4:
    case 6:
    case 7:
    case 9:
    case 10:
    case 13:
        switch (multi_chg_game_mode_state) {
        case 7:
        case 14:
        case 24:
            r = 1;
            break;
        default:
            r = 0;
            break;
        }
        break;
    case 5:
        r = 1;
        break;
    }
    return r;
}

void TAdMultiChgGameModeGC::set_default_camera() {
    Vec a = {0.0f, 0.0f, 0.0f};
    Vec b = {0.0f, 0.0f, -100.0f};
    activate_camera_mode(9);
    set_active_camera_pose(&a, &b);
}

void TAdMultiChgGameModeGC::open_dialing_select_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 3;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::open_level_select_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 1;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::apply_bgm_col_ctrl(const char *name) {
    if (strcmp((const char *)get_current_slot_entry(), name) != 0) {
        play_area_music((char *)name);
    }
}
void TAdMultiChgGameModeGC::open_pso_pass_save_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x1A;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::open_enter_ppp_pass_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x19;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::set_mode_18() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x18;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::open_trial_agreement_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x17;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::open_ex_net_confirm_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x15;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::open_sn_ak_pass_confirm_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x14;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::open_lic_agreement_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x11;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::open_enter_password_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x10;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::open_enter_serial_access_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xF;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::set_mode_state_0e() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xE;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::set_mode_state_0d() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xD;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::open_multi_sel_game_mode_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xC;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::open_multi_chg_game_mode_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xB;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::open_multi_confirm_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xA;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::open_multi_save_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 9;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::open_time_set_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 8;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::open_multi_ply_chr_select_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 7;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::open_single_ply_chr_select_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 6;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::open_select_game_mode_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 5;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::open_story_select_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 4;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::open_title_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::create_mode_scene() {
    TObject *p;
    switch (multi_chg_game_mode_state) {
    case 0:
    case 8:
    case 9:
    case 18:
    case 19:
    case 21:
    case 22:
    case 23:
    case 27:
        break;
    default:
        TAdMultiChgGameModeGC::apply_bgm_col_ctrl("advr.adx");
        break;
    }
    switch (multi_chg_game_mode_state) {
    case 0:
        game_mode_scene_instance = new TTitleScene(tl_01);
        break;
    case 4:
        game_mode_scene_instance = new TAdStorySelectGC(tl_01);
        break;
    case 5:
        game_mode_scene_instance = new TAdSelectGameModeGC(tl_01);
        break;
    case 6:
        game_mode_scene_instance = new TAdSinglePlyChrSelectGC(tl_01);
        break;
    case 7:
        game_mode_scene_instance = TAdMultiPlyChrSelectGC::get_or_create(tl_01, 0);
        break;
    case 8:
        game_mode_scene_instance = (TObject *)new TAdTimeSetGC(tl_01);
        break;
    case 9:
        game_mode_scene_instance = (TObject *)new TAdMultiSaveGC(tl_01);
        break;
    case 10:
        game_mode_scene_instance = new TAdMultiConfirmGC(tl_01);
        break;
    case 11:
        game_mode_scene_instance = new TAdMultiChgGameModeGC(tl_01);
        break;
    case 12:
        game_mode_scene_instance = new TAdMultiSelGameModeGC(tl_01, 0);
        break;
    case 13:
        game_mode_scene_instance = new TAdMultiSelGameModeGC(tl_01, 1);
        break;
    case 14:
        game_mode_scene_instance = TAdMultiPlyChrSelectGC::get_or_create(tl_01, 1);
        break;
    case 15:
        game_mode_scene_instance = new TAdEnterSerialAccessGC(tl_02);
        break;
    case 16:
        game_mode_scene_instance = new TAdEnterPasswordGC(tl_02);
        break;
    case 17:
        game_mode_scene_instance = new TAdLicAgreementGC(tl_01);
        break;
    case 18:
        game_mode_scene_instance = new TAdVIConfigGC(tl_01);
        break;
    case 19:
        p = new TLogo(tl_01);
        game_mode_scene_instance = p;
        break;
    case 20:
        game_mode_scene_instance = new TAdSnAkPassConfirmGC(tl_01);
        break;
    case 21:
        game_mode_scene_instance = new TAdExNetConfirmGC(tl_01);
        break;
    case 22:
        game_mode_scene_instance = new TAdTrialModemChkGC(tl_01);
        break;
    case 23:
        game_mode_scene_instance = new TAdTrialAgreementGC(tl_01);
        break;
    case 24:
        game_mode_scene_instance = TAdMultiPlyChrSelectGC::get_or_create(tl_01, 2);
        break;
    case 25:
        game_mode_scene_instance = new TAdEnterPPPPassGC(tl_01);
        break;
    case 26:
        game_mode_scene_instance = new TAdPsoPassSaveGC(tl_01);
        break;
    case 27:
        game_mode_scene_instance = new TAdSystemFileCheckGC(tl_01);
        break;
    case 28:
        game_mode_scene_instance = new TAdEp3Exist(tl_01);
        break;
    case 1:
        game_mode_scene_instance = new TLevelSelect();
        break;
    case 3:
        game_mode_scene_instance = new TAdDialingSelectGC();
        break;
    case 29:
        break;
    }
}


void unload_lobby_scene_resources(void) {
    TLobby::call_funcs_reverse(lobby_scene_release_callback_table, sizeof(lobby_scene_release_callback_table));
}
void load_lobby_scene_resources(void) {
    run_load_callback_table(lobby_scene_release_callback_table, sizeof(lobby_scene_release_callback_table));
}

void TLobby::release_scene_resources() {
    refresh_render_state();
    stop_audio_streams();
    if (game_mode_scene_instance != NULL) {
        game_mode_scene_instance->queue_destruction();
        game_mode_scene_instance = NULL;
    }
    main_task.delete_layer_children();
    TLobby::call_funcs_reverse(lobby_scene_release_callback_table, sizeof(lobby_scene_release_callback_table));
    TLobby::call_funcs_reverse(game_mode_select_scene_callbacks, sizeof(game_mode_select_scene_callbacks));
    TParticleCtrl::free_heap();
    clear_resource_load_tasks();
    render_tick();
}
void init_game_mode_select_scene(void) {
    s32 i;
    f32 c;
    void *p;
    set_screen_size(1.0f, 1.0f);
    set_copy_clear_color_argb(0, 0, 0);
    for (i = 0; i < 0x80; i++) {
    }
    reset_controller_input_state();
    clear_resource_load_tasks();
    TLobby::reset_keyboard_state();
    apply_phase_keyboard_mode();
    run_load_callback_table(game_mode_select_scene_callbacks, sizeof(game_mode_select_scene_callbacks));
    if (is_area_transfer_pending() != 0) {
        invoke_callback();
        TLobby::clear_callback_and_reset_keyboard();
        TLobby::reset_keyboard_state();
        return;
    }
    run_load_callback_table(lobby_scene_release_callback_table, sizeof(lobby_scene_release_callback_table));
    if (is_area_transfer_pending() != 0) {
        invoke_callback();
        TLobby::clear_callback_and_reset_keyboard();
        TLobby::reset_keyboard_state();
        return;
    }
    TLobby::clear_callback_and_reset_keyboard();
    TParticleCtrl::init_heap(0x100000);
    init_menu_scene_lights(&default_scene_light_config, 4);
    scene_light_state.direction.y = -1.0f * sin_table_lookup(0x1555);
    c = cos_table_lookup(0x1555);
    scene_light_state.direction.x = c * sin_table_lookup(0x9000);
    scene_light_state.direction.z = c * cos_table_lookup(0x9000);
    new TCameraCtrl(tl_camera);
    {
        Vec eye = game_mode_scene_camera_eye;
        Vec at = game_mode_scene_camera_target;
        TCameraCtrl::select_active_controller(9);
        set_active_camera_pose(&eye, &at);
    }
    TParticleCtrl::create_quad_sprites();
    p = (void *)new TWindowCtrlMain();
    game_mode_scene_instance = 0;
    load_floor_sound_bank(0);
}

void run_game_mode_select_frame(void) {
    switch (game_mode_scene_change_state) {
    case 0:
        break;
    case 1:
        if (game_mode_scene_instance != NULL) {
            game_mode_scene_instance->queue_destruction();
            game_mode_scene_instance = NULL;
        }
        game_mode_scene_change_state = 2;
        break;
    case 2:
        game_mode_scene_change_state = 0;
        TAdMultiChgGameModeGC::create_mode_scene();
        break;
    }
    begin_gx_frame();
    controller_stuff();
    update_keyboard_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::run_save_load_sequence();
    TAdSinglePlyChrSelectGC::noop();
    if (TAdPlayerLoadGC::get_instance() == 0) {
        if (static_cast<s8>(poll_reset_request()) != 0) {
            switch_to_fallback_main_phase();
        }
        if (TQuestVmDownLoadServer::is_ready() != 0) {
            request_main_phase(0);
        }
    }
    render_tick();
}

void TAdMultiChgGameModeGC::init_dialing_select_phase() { init_game_mode_select_scene(); TAdMultiChgGameModeGC::open_dialing_select_scene(); render_tick(); }
void TAdMultiChgGameModeGC::init_level_select_phase() { init_game_mode_select_scene(); TAdMultiChgGameModeGC::open_level_select_scene(); render_tick(); }


void TAdMultiChgGameModeGC::open_ep3_exist_scene() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x1C;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::init_trial_agreement_phase() { init_game_mode_select_scene(); TAdMultiChgGameModeGC::open_trial_agreement_scene(); render_tick(); }
void TAdMultiChgGameModeGC::init_enter_password_phase() { init_game_mode_select_scene(); TAdMultiChgGameModeGC::open_enter_password_scene(); render_tick(); }
void TAdMultiChgGameModeGC::init_multi_save_phase() { init_game_mode_select_scene(); TAdMultiChgGameModeGC::open_multi_save_scene(); render_tick(); }
void TAdMultiChgGameModeGC::init_time_set_phase() { init_game_mode_select_scene(); TAdMultiChgGameModeGC::open_time_set_scene(); render_tick(); }
void TAdMultiChgGameModeGC::init_story_select_phase() { init_game_mode_select_scene(); TAdMultiChgGameModeGC::open_story_select_scene(); render_tick(); }
void TAdMultiChgGameModeGC::init_title_phase() { init_game_mode_select_scene(); TAdMultiChgGameModeGC::open_title_scene(); render_tick(); }
void TAdMultiChgGameModeGC::sync_mode_state() { chg_game_mode_state_synced = multi_chg_game_mode_state; }
