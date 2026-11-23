// The game mode select scene: the scene-change state machine of the front end (title, story/mode
// select, character select, multi-play setup...), the scene's load/release hook tables and its frame
// loop. One TU: the hook tables open its .data, the frame loop's state (.sbss) and the mode state
// (.sdata) are read and written by every part.
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
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
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80227AA0.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/unk/TLobby_803360CC.h"
#include "pso/unk/TLobby_802A0F3C.h"
#include "pso/unk/text_800FA464.h"
#include "pso/unk/text_803DCDFC.h"
#include "pso/unk/text_8023F160.h"
#include "pso/unk/text_8023F3F8.h"
#include "pso/unk/text_802E10D8.h"
#include "pso/unk/text_8026ACDC.h"
#include "pso/unk/text_8026AC50.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007CF0C.h"
#include "pso/ui/TLogo.h"
#include "pso/ui/TLogo_8001C134.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/unk/TUnk_804C2298.h"
#include "pso/ui/frontend/DrawLineResource.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/ui/frontend/TAdEnterPPPPassGC.h"
#include "pso/ui/frontend/TAdEnterPasswordGC.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdEp3Exist.h"
#include "pso/ui/frontend/TAdGameStartGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC_8023F4E4.h"
#include "pso/ui/frontend/TAdMultiConfirmGC.h"
#include "pso/ui/frontend/TAdMultiOkGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802E0FC8.h"
#include "pso/ui/frontend/TAdMultiSaveGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdPlyPltAnimGC.h"
#include "pso/ui/frontend/TAdRayGC.h"
#include "pso/ui/frontend/TAdSelectCurGC_802AED98.h"
#include "pso/ui/frontend/TAdSelectGameModeGC_802C4748.h"
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
#include "pso/ui/TUnk_804F3A20.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/ui/frontend/TAdMultiSelGameModeGC.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/unk/TLobby_800F8AA8.h"
#include "pso/unk/TTitleScene.h"

extern "C" {
u8 *TAdSinglePlyChrSelectGC__ct(u8 *arg0, void *parent);
void run_load_callback_table(void *, s32);
}
void clear_resource_load_tasks(void);
void set_screen_size(f32, f32);

// The mode the scene machine shows (create_mode_scene picks the scene object by it) and the one
// before it (sync_mode_state).
s32 multi_chg_game_mode_state = 29;
int lbl_805D384C = 29;

// Scene change request: the set_* functions set the next mode and 1; the frame loop
// (run_game_mode_select_frame) then destroys the current scene object (2) and creates the next one (0).
s32 game_mode_scene_change_state;
TObject *game_mode_scene_instance;
int TAdPlayerLoadGC__load_state;

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
    {TLobby::update_keyboard_menu, TLobby::free_keyboard_soft_resources},
    {register_texture_f256_ad_pic_2, TAdSinglePlyChrSelectGC::free_global},
    {register_texture_f256_backtext, TAdSinglePlyChrSelectGC::free_singleton_805D65C0},
    {register_texture_f128_ray, TAdRayGC::destroy_instance},
    {fn_802E10D8, TAdChrSelPlayerGC__sub_802E10A0},
    {TAdTimeSetGC::sub_802E34A8, TAdTimeSetGC::sub_802E34A4},
    {register_texture_f512_multiplay, TAdGameStartSubGC::destroy_instance},
    {TAdSinglePlyChrSelectGC::alloc_char_buffers, TAdSinglePlyChrSelectGC::free_callbacks},
    {fn_802FFC7C, fn_802FFC78},
    {load_multi_confirm_textures, free_multi_confirm_textures},
    {register_texture_logo_e, TLogo::free_held_object},
    {TLogo__sub_8001C364, TLogo__sub_8001C360},
    {TLobby__sub_8026ACDC, fn_8026AC50},
    {register_player_prate, TAdPlyPltAnimGC__sub_8035615C},
    {load_data_buffers, TObjBoss2Tunnel::free_buffers},
    {KeyboardKeyState::reset_global_keys_b, KeyboardKeyState::reset_global_keys_a},
    {TWindowCtrlMain__sub_8024D838, TWindowCtrlMain::free_all_windows},
    {TLobby::set_ending_callback, TLobby::free_ending_callback},
    {TKeyBoardControl__sub_80131F60, TKeyBoardControl__sub_80131F5C},
    {alloc_quest_download_buffer, TLobby::free_chr_select_singleton},
    {load_draw_line_task_resource, free_draw_line_task_resource},
};

// The front-end screens' hooks, run after the table above and released before it.
FloorResourceCallbacks lobby_scene_release_callback_table[7] = {
    {initialize_lobby_title_scene, TLobby::destroy_global_object},
    {TLobby__sub_802A0F70, TLobby::free_dialog_global},
    {TLobby__sub_802A5154, TLobby::free_dialing_gc},
    {TLobby__sub_802A194C, TLobby__sub_802A1918},
    {TLobby::apply_menu_cursor_selection, TLobby__sub_802AF198},
    {TLobby__sub_802C7920, TLobby__sub_802C78EC},
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

void TAdMultiChgGameModeGC::set_mode_change_state() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 3;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::set_change_mode_flags() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 1;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::apply_bgm_col_ctrl(const char *name) {
    if (strcmp((const char *)TLobby::get_current_slot_entry(), name) != 0) {
        play_area_music((char *)name);
    }
}
void TAdMultiChgGameModeGC::set_state_0x1a() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x1A;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::reset_and_set_mode() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x19;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::set_mode_18() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x18;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::set_mode_17() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x17;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::set_mode_0x15() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x15;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::set_mode_0x14() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x14;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::request_transition() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x11;
    game_mode_scene_change_state = 1;
}

void TAdEnterSerialAccessGC::init_state() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x10;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::reset_mode_state() {
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

void TAdMultiChgGameModeGC::set_state_0xc() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xC;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::begin_change_game_mode() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xB;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::begin_transition() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xA;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::set_state_0x9() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 9;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::request_scene_change() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 8;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::set_change_game_mode() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 7;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::set_game_mode() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 6;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::set_game_mode_state() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 5;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::set_game_mode_changed() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 4;
    game_mode_scene_change_state = 1;
}

void TAdMultiChgGameModeGC::init_change_mode() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC::create_mode_scene() {
    void *p;
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
        game_mode_scene_instance = (TObject *)p;
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
        game_mode_scene_instance = new TUnk_804F3A20(tl_01);
        break;
    case 28:
        game_mode_scene_instance = new TAdEp3Exist(tl_01);
        break;
    case 1:
        game_mode_scene_instance = new TLevelSelect();
        break;
    case 3:
        game_mode_scene_instance = new TUnk_804C2298();
        break;
    case 29:
        break;
    }
}


extern "C" {
void unload_lobby_scene_resources(void) {
    TLobby::call_funcs_reverse(lobby_scene_release_callback_table, sizeof(lobby_scene_release_callback_table));
}
void load_lobby_scene_resources(void) {
    run_load_callback_table(lobby_scene_release_callback_table, sizeof(lobby_scene_release_callback_table));
}
}

void TLobby::release_scene_resources() {
    TLobby::refresh_render_state();
    TLobby::stop_audio_streams();
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
        TLobby::invoke_callback();
        TLobby::clear_callback_and_reset_keyboard();
        TLobby::reset_keyboard_state();
        return;
    }
    run_load_callback_table(lobby_scene_release_callback_table, sizeof(lobby_scene_release_callback_table));
    if (is_area_transfer_pending() != 0) {
        TLobby::invoke_callback();
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

extern "C" {
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
    func_803DCDFC__Fv();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::run_save_load_sequence();
    TAdSinglePlyChrSelectGC::noop();
    if (TAdPlayerLoadGC::get_instance() == 0) {
        if (func_801A5E54__Fv() != 0) {
            TKeyBoardControl__sub_8000F92C();
        }
        if (TQuestVmDownLoadServer::is_ready() != 0) {
            request_main_phase(0);
        }
    }
    render_tick();
}
}

void TAdMultiChgGameModeGC__sub_8023F4E4(void) { init_game_mode_select_scene(); TAdMultiChgGameModeGC::set_mode_change_state(); render_tick(); }
void TAdMultiChgGameModeGC__sub_8023F50C(void) { init_game_mode_select_scene(); TAdMultiChgGameModeGC::set_change_mode_flags(); render_tick(); }


void TAdMultiChgGameModeGC::set_mode_1c() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0x1C;
    game_mode_scene_change_state = 1;
}
void TAdMultiChgGameModeGC__sub_8023F564(void) { init_game_mode_select_scene(); TAdMultiChgGameModeGC::set_mode_17(); render_tick(); }
void TAdMultiChgGameModeGC__sub_8023F58C(void) { init_game_mode_select_scene(); TAdEnterSerialAccessGC::init_state(); render_tick(); }
void TAdMultiChgGameModeGC__sub_8023F5B4(void) { init_game_mode_select_scene(); TAdMultiChgGameModeGC::set_state_0x9(); render_tick(); }
void TAdMultiChgGameModeGC::render_scene() { init_game_mode_select_scene(); TAdMultiChgGameModeGC::request_scene_change(); render_tick(); }
void TAdMultiChgGameModeGC::render_game_mode_change() { init_game_mode_select_scene(); TAdMultiChgGameModeGC::set_game_mode_changed(); render_tick(); }
void TAdMultiChgGameModeGC__sub_8023F62C(void) { init_game_mode_select_scene(); TAdMultiChgGameModeGC::init_change_mode(); render_tick(); }
void TAdMultiChgGameModeGC::sync_mode_state() { lbl_805D384C = multi_chg_game_mode_state; }
