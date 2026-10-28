#include "pso/object/TObjMotion.h"
#include "pso/TObject.h"
#include "pso/misc/TLogo.h"
#include "pso/misc/TLogo_8001C134.h"
#include "pso/unk/text_80145A94.h"
#include "pso/system/main_loop.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
class TLogo : public TObject {
public:
    virtual void render();
    virtual ~TLogo();
};

#include "types.h"
#include "pso/TAdADXlogo.h"

#include "pso/TMainTask.h"

#include "pso/TParticleCtrl.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TWindowCtrlMain.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct V3_8013F5E8 { s32 x, y, z; };
struct V3_8013F6C4 { s32 x, y, z; };
extern "C" {
s32 TKeyBoardControl__sub_8000F90C(int);
s32 TCameraCtrl__ct(u32, void *);
s32 is_area_transfer_pending();
s32 apply_phase_keyboard_mode();
s32 run_load_callback_table(void *, int);
s32 init_menu_scene_lights(void *, int);
s32 reset_controller_input_state();
s32 set_copy_clear_color_argb(int, int, int);
s32 __ct__15TWindowCtrlMainFv(u32);
extern V3_8013F6C4 lbl_8043F138;
extern V3_8013F6C4 lbl_8043F144;
extern u8 default_scene_light_config[];
s32 call_funcs_reverse__6TLobbyFPvUi(void *, int);
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
u32 __ct__10TAdADXlogoFP7TObject(void *, void *);
void queue_destruction__7TObjectFv(void *arg0);
u32 __ct__11TAdSEGAlogoFv(void *, void *);
u32 __ct__12TAdSoniclogoFv(void *, void *);
u32 __nw__7TObjectFUl(int);
u32 TAdVIConfigGC__ct(void *, void *);
s32 check_progressive_ready__5TLogoFv();
u32 TAdTrialModemChkGC__ct(void *, void *);
s32 TKeyBoardControl__sub_8000F92C();
s32 set_active_camera_pose(void *, void *);
s32 activate_camera_mode(s32 arg0);
s8 func_801A5E54__Fv();
}
int is_logo_exit_requested(int);
int is_sega_logo_done(int);
void process_async_file_reads(void);
void update_sound_request_slots(void);
extern "C" {
void func_803DCDFC__Fv(void);
extern V3_8013F5E8 lbl_8043F150;
extern V3_8013F5E8 lbl_8043F15C;
void __ct__7TObjectFP7TObject(void *);

s32 TUnk_804AF8A0::get_cursor_action() { return cursor_action.get(); }
s32 CursorAction::get() { return kind; }
void render__5TLogoFv(void) {  }

extern void *__vt__5TLogo[];
extern void *TLogo__class_name;

extern "C" {
void reset_view_state__11TCameraCtrlFv(); void reset__11TCameraCtrlFv(); void TCameraCtrl::init_default_view(); void TCameraCtrl::reset_default_view();
void register_texture_f256_ad_pic_2(); void TAdSinglePlyChrSelectGC::free_global();
void register_texture_f256_backtext(); void TAdSinglePlyChrSelectGC::free_singleton_805D65C0();
void free_held_object__5TLogoFv(); void TLogo__sub_8001C364(); void TLogo__sub_8001C360();
void TWindowCtrlMain__sub_8024D838(); void TWindowCtrlMain::free_all_windows();
void __dt__5TLogoFv(); void render_shadows__7TObjectFv();
void *logo_load_callback_table[18] = {
    (void *)reset_view_state__11TCameraCtrlFv, (void *)reset__11TCameraCtrlFv,
    (void *)TCameraCtrl::init_default_view, (void *)TCameraCtrl::reset_default_view,
    (void *)TLobby::update_keyboard_menu, (void *)TLobby::free_keyboard_soft_resources,
    (void *)register_texture_f256_ad_pic_2, (void *)TAdSinglePlyChrSelectGC::free_global,
    (void *)register_texture_f256_backtext, (void *)TAdSinglePlyChrSelectGC::free_singleton_805D65C0,
    (void *)register_texture_logo_e, (void *)free_held_object__5TLogoFv,
    (void *)TLogo__sub_8001C364, (void *)TLogo__sub_8001C360,
    (void *)TWindowCtrlMain__sub_8024D838, (void *)TWindowCtrlMain::free_all_windows,
    (void *)load_adx_logo_texture, (void *)free_adx_logo_texture,
};
void *__vt__5TLogo[6] = {
    0, 0,
    (void *)__dt__5TLogoFv,
    (void *)run_task__5TLogoFv,
    (void *)render__5TLogoFv,
    (void *)render_shadows__7TObjectFv,
};
}
void run_task__5TLogoFv(u8 *ad_seg_alogo) {
    u32 var_r0;
    u32 var_r0_2;
    u32 var_r0_3;
    u32 var_r0_4;
    u32 var_r0_5;
    u32 var_r0_6;
    u32 var_r0_7;
    u32 var_r0_8;
    switch (*(u32 *)((s8 *)ad_seg_alogo + 0x20)) {
    case 0:
        if (check_progressive_ready__5TLogoFv() != 0) {
            if (((s32)TLogo__sub_8013F808()) != 0) {
                var_r0 = __nw__7TObjectFUl(0x4C);
                if (var_r0 != 0U) {
                    var_r0 = TAdVIConfigGC__ct((void *)var_r0, ad_seg_alogo);
                }
                *(u32 *)((s8 *)ad_seg_alogo + 0x24) = var_r0;
                *(u32 *)((s8 *)ad_seg_alogo + 0x20) = 1U;
                return;
            }
            var_r0_2 = __nw__7TObjectFUl(0x20);
            if (var_r0_2 != 0U) {
                var_r0_2 = __ct__11TAdSEGAlogoFv((void *)var_r0_2, ad_seg_alogo);
            }
            *(u32 *)((s8 *)ad_seg_alogo + 0x2C) = var_r0_2;
            *(u32 *)((s8 *)ad_seg_alogo + 0x20) = 4U;
            return;
        }
        var_r0_3 = __nw__7TObjectFUl(0x20);
        if (var_r0_3 != 0U) {
            var_r0_3 = __ct__11TAdSEGAlogoFv((void *)var_r0_3, ad_seg_alogo);
        }
        *(u32 *)((s8 *)ad_seg_alogo + 0x2C) = var_r0_3;
        *(u32 *)((s8 *)ad_seg_alogo + 0x20) = 4U;
        return;
    case 1:
        if (((u32) *(u32 *)((s8 *)ad_seg_alogo + 0x24) != 0U) && (TLogo__sub_8013F800((void*)(*(void **)((s8 *)ad_seg_alogo + 0x24))) != 0)) {
            var_r0_4 = __nw__7TObjectFUl(0x20);
            if (var_r0_4 != 0U) {
                var_r0_4 = __ct__11TAdSEGAlogoFv((void *)var_r0_4, ad_seg_alogo);
            }
            *(u32 *)((s8 *)ad_seg_alogo + 0x2C) = var_r0_4;
            *(u32 *)((s8 *)ad_seg_alogo + 0x20) = 4U;
            return;
        }
        break;
    case 2:
        if (TLobby__sub_80145DB4(1) == 0) {
            var_r0_5 = __nw__7TObjectFUl(0x30);
            if (var_r0_5 != 0U) {
                var_r0_5 = TAdTrialModemChkGC__ct((void *)var_r0_5, ad_seg_alogo);
            }
            *(u32 *)((s8 *)ad_seg_alogo + 0x28) = var_r0_5;
            *(u32 *)((s8 *)ad_seg_alogo + 0x20) = 3U;
            return;
        }
        var_r0_6 = __nw__7TObjectFUl(0x20);
        if (var_r0_6 != 0U) {
            var_r0_6 = __ct__11TAdSEGAlogoFv((void *)var_r0_6, ad_seg_alogo);
        }
        *(u32 *)((s8 *)ad_seg_alogo + 0x2C) = var_r0_6;
        *(u32 *)((s8 *)ad_seg_alogo + 0x20) = 4U;
        return;
    case 4:
        if (((s32)is_sega_logo_done((int)((int) (*(u32 *)((s8 *)ad_seg_alogo + 0x2C))))) != 0) {
            queue_destruction__7TObjectFv((void *)(*(u32 *)((s8 *)ad_seg_alogo + 0x2C)));
            *(u32 *)((s8 *)ad_seg_alogo + 0x2C) = 0U;
            var_r0_7 = __nw__7TObjectFUl(0x20);
            if (var_r0_7 != 0U) {
                var_r0_7 = __ct__12TAdSoniclogoFv((void *)var_r0_7, ad_seg_alogo);
            }
            *(u32 *)((s8 *)ad_seg_alogo + 0x30) = var_r0_7;
            *(u32 *)((s8 *)ad_seg_alogo + 0x20) = 5U;
            return;
        }
        break;
    case 5:
        if (((s32)is_logo_exit_requested((int)((int) (*(u32 *)((s8 *)ad_seg_alogo + 0x30))))) != 0) {
            queue_destruction__7TObjectFv((void *)(*(u32 *)((s8 *)ad_seg_alogo + 0x30)));
            *(u32 *)((s8 *)ad_seg_alogo + 0x30) = 0U;
            var_r0_8 = __nw__7TObjectFUl(0x20);
            if (var_r0_8 != 0U) {
                var_r0_8 = __ct__10TAdADXlogoFP7TObject((void *)var_r0_8, ad_seg_alogo);
            }
            *(u32 *)((s8 *)ad_seg_alogo + 0x34) = var_r0_8;
            *(u32 *)((s8 *)ad_seg_alogo + 0x20) = 6U;
            return;
        }
        break;
    case 6:
        if (((s32)TLogo__sub_8013F7E8((int)((int) (*(u32 *)((s8 *)ad_seg_alogo + 0x34))))) != 0) {
            queue_destruction__7TObjectFv((void *)(*(u32 *)((s8 *)ad_seg_alogo + 0x34)));
            *(u32 *)((s8 *)ad_seg_alogo + 0x34) = 0U;
            *(u32 *)((s8 *)ad_seg_alogo + 0x20) = 7U;
            return;
        }
        break;
    case 7:
        TKeyBoardControl__sub_8000F9CC(0xA);
        break;
    }
}

TLogo::~TLogo() {}
void *__ct__5TLogoFv(void *object) {
    __ct__7TObjectFP7TObject(object);
    *(s32 **)((s8 *)object + 0x18) = (s32 *)__vt__5TLogo;
    *(void **)((s8 *)object + 0x0) = TLogo__class_name;
    *(u32 *)((s8 *)object + 0x20) = 0;
    *(u32 *)((s8 *)object + 0x24) = 0;
    *(u32 *)((s8 *)object + 0x28) = 0;
    *(u32 *)((s8 *)object + 0x2C) = 0;
    *(u32 *)((s8 *)object + 0x30) = 0;
    *(u32 *)((s8 *)object + 0x34) = 0;
    return object;
}


void TLogo__sub_8013F5AC() {
    main_task.delete_layer_children();
    call_funcs_reverse__6TLobbyFPvUi(logo_load_callback_table, sizeof(logo_load_callback_table));
    render_tick();
}

void run_frame__5TLogoFv(void) {
    func_803DCDFC__Fv();
    V3_8013F5E8 a = lbl_8043F150;
    V3_8013F5E8 b = lbl_8043F15C;
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
        TKeyBoardControl__sub_8000F9CC(0);
    }
    render_tick();
}

void init_logo_scene__5TLogoFv(void) {
    s32 i;
    u32 p;

    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    for (i = 0; i < 0x80; i++) {
    }
    init_menu_scene_lights(default_scene_light_config, 4);
    p = __nw__7TObjectFUl(0x1D4);
    if (p != 0) {
        TCameraCtrl__ct(p, tl_camera);
    }
    V3_8013F6C4 a = lbl_8043F138;
    V3_8013F6C4 b = lbl_8043F144;
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
    p = __nw__7TObjectFUl(0x38);
    if (p != 0) {
        ((void *(*)(u32, void *))__ct__5TLogoFv)(p, tl_01);
    }
    p = __nw__7TObjectFUl(0x1C);
    if (p != 0) {
        __ct__15TWindowCtrlMainFv(p);
    }
}

int TLogo__sub_8013F7E8(int _w0) {  return TAdADXlogo__done; }
}

    extern int TLogo__exit_requested_flag;
int is_logo_exit_requested(int _w0) {  return TLogo__exit_requested_flag; }

    extern int sega_logo_done_flag;
int is_sega_logo_done(int _w0) {  return sega_logo_done_flag; }

s32 TLogo__sub_8013F800(void* p) { return *(s32*)((char*)p + 0x48); }

    extern int logo_clear_flag;
int TLogo__sub_8013F808(void) {  return logo_clear_flag; }
