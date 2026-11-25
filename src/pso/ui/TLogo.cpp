#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdSoniclogo.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/TLogo.h"
#include "pso/ui/TLogo_8001C134.h"
#include "pso/unk/text_80145A94.h"
#include "pso/system/main_loop.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/network/TLobby.h"

#include "types.h"
#include "pso/ui/frontend/TAdADXlogo.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"
#include "pso/ui/frontend/TAdSEGAlogo.h"

#include "pso/system/task/TMainTask.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/map/area/AreaScene.h"
#include "pso/render/gjSystem.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/unk/TLobby_800F8AA8.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/unk/text_800FA464.h"
#include "pso/unk/TLobby_802268F4.h"


const char *logo_class_name = "TLogo";

// Load and release hooks run by run_load_callback_table / call_funcs_reverse.
void (*logo_load_callback_table[18])(void) = {
    TCameraCtrl::reset_view_state, TCameraCtrl::reset,
    TCameraCtrl::init_default_view, TCameraCtrl::reset_default_view,
    TLobby::update_keyboard_menu, TLobby::free_keyboard_soft_resources,
    register_texture_f256_ad_pic_2, TAdSinglePlyChrSelectGC::free_global,
    register_texture_f256_backtext, TAdSinglePlyChrSelectGC::free_singleton_805D65C0,
    register_texture_logo_e, TLogo::free_held_object,
    TLogo__sub_8001C364, TLogo__sub_8001C360,
    TWindowCtrlMain__sub_8024D838, TWindowCtrlMain::free_all_windows,
    load_adx_logo_texture, free_adx_logo_texture,
};
extern int sega_logo_done_flag;

// This unit was built with deferred inlining (-inline off,deferred): the compiler emits
// function bodies in reverse source order, so the functions below are listed from the
// highest address down to the lowest.

int is_logo_clear_flag_set(void) {  return logo_clear_flag; }

s32 TLogo__sub_8013F800(void* p) { return *(s32*)((char*)p + 0x48); }

int is_sega_logo_done(TAdSEGAlogo *logo) {  return sega_logo_done_flag; }

int is_logo_exit_requested(TAdSoniclogo *logo) {  return TLogo::exit_requested_flag; }

int is_adx_logo_done(TAdADXlogo *logo) {  return TAdADXlogo::done; }

void TLogo::init_logo_scene() {
    s32 i;

    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    for (i = 0; i < 0x80; i++) {
    }
    init_menu_scene_lights(&default_scene_light_config, 4);
    new TCameraCtrl(tl_camera);
    Vec a = {0.0f, 0.0f, 0.0f};
    Vec b = {0.0f, 0.0f, -100.0f};
    TCameraCtrl::select_active_controller(9);
    set_active_camera_pose(&a, &b);
    set_fallback_main_phase(1);
    apply_phase_keyboard_mode();
    run_load_callback_table(logo_load_callback_table, sizeof(logo_load_callback_table));
    if (is_area_transfer_pending() != 0) {
        TLobby::invoke_callback();
        TLobby::clear_callback_and_reset_keyboard();
        TLobby::reset_keyboard_state();
        return;
    }
    TLobby::clear_callback_and_reset_keyboard();
    TParticleCtrl::create_quad_sprites();
    new TLogo(tl_01);
    new TWindowCtrlMain();
}

void TLogo::run_frame() {
    begin_gx_frame();
    Vec a = {0.0f, 0.0f, 0.0f};
    Vec b = {0.0f, 0.0f, -100.0f};
    activate_camera_mode(9);
    set_active_camera_pose(&a, &b);
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    if (static_cast<s8>(poll_reset_request()) != 0) {
        switch_to_fallback_main_phase();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        request_main_phase(0);
    }
    render_tick();
}

void TLogo__sub_8013F5AC() {
    main_task.delete_layer_children();
    TLobby::call_funcs_reverse(logo_load_callback_table, sizeof(logo_load_callback_table));
    render_tick();
}

TLogo::TLogo(TObject *parent) : TObject(parent) {
    m_name = logo_class_name;
    state = 0;
    vi_config = NULL;
    modem_check = NULL;
    sega_logo = NULL;
    sonic_logo = NULL;
    adx_logo = NULL;
}

TLogo::~TLogo() {}

void TLogo::run_task() {
    switch (state) {
    case 0:
        if (TLogo::check_progressive_ready() != 0) {
            if (((s32)is_logo_clear_flag_set()) != 0) {
                vi_config = new TAdVIConfigGC(this);
                state = 1U;
                return;
            }
            sega_logo = new TAdSEGAlogo(this);
            state = 4U;
            return;
        }
        sega_logo = new TAdSEGAlogo(this);
        state = 4U;
        return;
    case 1:
        if ((vi_config != NULL) && (TLogo__sub_8013F800(vi_config) != 0)) {
            sega_logo = new TAdSEGAlogo(this);
            state = 4U;
            return;
        }
        break;
    case 2:
        if (TLobby__sub_80145DB4(1) == 0) {
            modem_check = new TAdTrialModemChkGC(this);
            state = 3U;
            return;
        }
        sega_logo = new TAdSEGAlogo(this);
        state = 4U;
        return;
    case 4:
        if (is_sega_logo_done(sega_logo) != 0) {
            sega_logo->queue_destruction();
            sega_logo = NULL;
            sonic_logo = new TAdSoniclogo(this);
            state = 5U;
            return;
        }
        break;
    case 5:
        if (is_logo_exit_requested(sonic_logo) != 0) {
            sonic_logo->queue_destruction();
            sonic_logo = NULL;
            adx_logo = new TAdADXlogo(this);
            state = 6U;
            return;
        }
        break;
    case 6:
        if (is_adx_logo_done(adx_logo) != 0) {
            adx_logo->queue_destruction();
            adx_logo = NULL;
            state = 7U;
            return;
        }
        break;
    case 7:
        request_main_phase(0xA);
        break;
    }
}

void TLogo::render() {}

s32 CursorAction::get() { return kind; }

s32 TObjCollidable::get_cursor_action() { return cursor_action.get(); }
