#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdSoniclogo.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/TLogo.h"
#include "pso/ui/TLogo_8001C134.h"
#include "pso/unk/text_80145A94.h"
#include "pso/system/main_loop.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"

#include "types.h"
#include "pso/ui/frontend/TAdADXlogo.h"
#include "pso/ui/frontend/TAdSEGAlogo.h"

#include "pso/system/task/TMainTask.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/map/area/AreaScene.h"
#include "pso/unk/text_803DCDFC.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/unk/TLobby_800F8AA8.h"


extern "C" {
s32 TKeyBoardControl__sub_8000F90C(int);
s32 reset_controller_input_state();
s32 __ct__15TWindowCtrlMainFv(u32);
void request_main_phase(s32 arg0);
u32 __ct__10TAdADXlogoFP7TObject(void *, void *);
u32 __ct__12TAdSoniclogoFP7TObject(void *, void *);
u32 __ct__13TAdVIConfigGCFP7TObject(void *, void *);
u32 __ct__18TAdTrialModemChkGCFP7TObject(void *, void *);
s32 TKeyBoardControl__sub_8000F92C();
s8 func_801A5E54__Fv();

const char *TLogo__class_name = "TLogo";

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
}
int is_logo_exit_requested(int);
int is_sega_logo_done(TAdSEGAlogo *logo);
void process_async_file_reads(void);
void update_sound_request_slots(void);
extern int sega_logo_done_flag;
extern int logo_clear_flag;

// This unit was built with deferred inlining (-inline off,deferred): the compiler emits
// function bodies in reverse source order, so the functions below are listed from the
// highest address down to the lowest.

int TLogo__sub_8013F808(void) {  return logo_clear_flag; }

s32 TLogo__sub_8013F800(void* p) { return *(s32*)((char*)p + 0x48); }

int is_sega_logo_done(TAdSEGAlogo *logo) {  return sega_logo_done_flag; }

int is_logo_exit_requested(int _w0) {  return TLogo__exit_requested_flag; }

int TLogo__sub_8013F7E8(int _w0) {  return TAdADXlogo__done; }

void TLogo::init_logo_scene() {
    s32 i;
    u32 p;

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
    TKeyBoardControl__sub_8000F90C(1);
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
    p = (uaddr)TObject::operator new(0x1C);
    if (p != 0) {
        __ct__15TWindowCtrlMainFv(p);
    }
}

void TLogo::run_frame() {
    func_803DCDFC__Fv();
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
    if (func_801A5E54__Fv() != 0) {
        TKeyBoardControl__sub_8000F92C();
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
    m_name = TLogo__class_name;
    state = 0;
    vi_config = 0;
    modem_check = 0;
    sega_logo = NULL;
    sonic_logo = 0;
    adx_logo = 0;
}

TLogo::~TLogo() {}

void TLogo::run_task() {
    uaddr var_r0;
    uaddr var_r0_5;
    uaddr var_r0_7;
    uaddr var_r0_8;
    switch (state) {
    case 0:
        if (TLogo::check_progressive_ready() != 0) {
            if (((s32)TLogo__sub_8013F808()) != 0) {
                var_r0 = (uaddr)TObject::operator new(0x4C);
                if (var_r0 != 0U) {
                    var_r0 = __ct__13TAdVIConfigGCFP7TObject((void *)var_r0, this);
                }
                vi_config = var_r0;
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
        if (((u32) vi_config != 0U) && (TLogo__sub_8013F800((void *)vi_config) != 0)) {
            sega_logo = new TAdSEGAlogo(this);
            state = 4U;
            return;
        }
        break;
    case 2:
        if (TLobby__sub_80145DB4(1) == 0) {
            var_r0_5 = (uaddr)TObject::operator new(0x30);
            if (var_r0_5 != 0U) {
                var_r0_5 = __ct__18TAdTrialModemChkGCFP7TObject((void *)var_r0_5, this);
            }
            modem_check = var_r0_5;
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
            var_r0_7 = (uaddr)TObject::operator new(0x20);
            if (var_r0_7 != 0U) {
                var_r0_7 = __ct__12TAdSoniclogoFP7TObject((void *)var_r0_7, this);
            }
            sonic_logo = var_r0_7;
            state = 5U;
            return;
        }
        break;
    case 5:
        if (((s32)is_logo_exit_requested((int)(sonic_logo))) != 0) {
            ((TObject *)sonic_logo)->queue_destruction();
            sonic_logo = 0U;
            var_r0_8 = (uaddr)TObject::operator new(0x20);
            if (var_r0_8 != 0U) {
                var_r0_8 = __ct__10TAdADXlogoFP7TObject((void *)var_r0_8, this);
            }
            adx_logo = var_r0_8;
            state = 6U;
            return;
        }
        break;
    case 6:
        if (((s32)TLogo__sub_8013F7E8((int)(adx_logo))) != 0) {
            ((TObject *)adx_logo)->queue_destruction();
            adx_logo = 0U;
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
