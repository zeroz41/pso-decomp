#include "pso/TMainTask.h"
#pragma push

#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_8001C5E8.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_8033A8EC.h"
#include "pso/ui/TObjBagWarnWin_8006EF24.h"
#include "pso/system/main_loop.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/TUnk_804EF8C0.h"
#include "pso/TObject.h"

struct RecoveredGlobal_8033B264_lbl_804EF728 {
    s32 value;
    u8 remaining[0x194];
};

struct RecoveredGlobal_8033B264_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct O_8033AA64 { u8 pad[0x2C]; s32 f2c; u8 pad2[0x3C - 0x30]; s32 f3c; };

struct O_8033AC44 { u8 pad[0x24]; s32 f24; s32 f28; s32 f2c; };

struct O_8033AB04 { u8 pad[0x24]; s32 f24; u8 pad2[4]; s32 f2C; };

struct O_8033ACF4 { u8 pad[0x24]; s32 f24; s32 f28; s32 f2C; };

struct O_8033AFC8 { u8 pad[0x20]; u32 f20; s32 f24; s32 f28; s32 f2C; };

struct V3_8033B2AC { s32 x, y, z; };

struct V3_8033B39C { f32 x, y, z; };

s32 lbl_805D6D80;
s32 lbl_805D6D84;
s32 lbl_805D6D88;
s32 single_ply_quest_download_server;
s32 lbl_805D6D90;
extern "C" {
void free_buffer__13TUnk_804EF8C0Fv(void* p);
int memset(void*, void*, void*);
int queue_destruction__7TObjectFv(void*);
struct TAdSinglePlyChrSelectGC__sub_8033B5F0;
s32 setup__23TAdSinglePlyChrSelectGCFi(s32);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C();

u8 * create_check_memory_card__23TAdSinglePlyChrSelectGCFPvPvPv(void *, void *, void *);
int request_queued_main_phase(void*);
s32 call_funcs_reverse__6TLobbyFPvUi(void *, int);
extern void *character_select_scene_resource_callbacks[];
s32 TWindow__close(void *);
int check_room_seq_4__16TAdChrSelASlotGCFl(void*, void*);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void*, void*, void*, void*);
    extern unsigned char lbl_80477D58[];
    extern const float lbl_805DFA30;
u32 __nw__7TObjectFUl(int);
s32 get_selected_menu_value(int);

s32 get_card_file_info__15TAdPlayerLoadGCFiPvPv(int, void *, int);
s32 query_memcard_capacity__15TAdPlayerLoadGCFl(int, int);
extern u8 lbl_804C89BC[];
extern u8 lbl_804C88C0[];
s32 TAdPlayerLoadGC__sub_801E1944(s32, void *, u32, s32);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);

s8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv(void);
void check_ready__23TAdSinglePlyChrSelectGCFv(void);

s32 TKeyBoardControl__sub_8000F92C();
s32 TKeyBoardControl__sub_8000F9CC(int);
s32 set_active_camera_pose(void *, void *);
s32 activate_camera_mode(int);
s8 func_801A5E54__Fv();
s32 run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
}
void process_async_file_reads(void);
void update_sound_request_slots(void);
extern "C" {
s32 func_803DCDFC__Fv();
extern V3_8033B2AC lbl_80477D78[];
extern V3_8033B2AC lbl_80477D84[];
s32 TKeyBoardControl__sub_8000F90C(int);
s32 TCameraCtrl__ct(u32, TObject *);
s32 run_load_callback_table(void *, int);
s32 init_menu_scene_lights(void *, int);
s32 reset_controller_input_state();
s32 set_copy_clear_color_argb(int, int, int);
s32 play_area_music(void *);
s32 __ct__15TWindowCtrlMainFv(u32);
extern V3_8033B39C lbl_80477D60[];
extern V3_8033B39C lbl_80477D6C[];
extern u8 lbl_80477D90[];
extern u8 default_scene_light_config[];

extern u8 lobby_rule_settings[];
s32 register_callback__23TAdSinglePlyChrSelectGCFis(int, int);
u32 init_char_slots__23TAdSinglePlyChrSelectGCFi();
int TAdSinglePlyChrSelectGC__sub_801FCD3C(void *);
s32 compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(int, int, int, int);
s32 decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(int);
s32 encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv(int);
s32 save_character_file__23TAdSinglePlyChrSelectGCFi(int);
s32 init_and_register__23TAdSinglePlyChrSelectGCFi(int);
s32 get_field_118__22TAdEnterSerialAccessGCFv();
s32 get_character_save_record(int);
s32 memcpy(int, void *, int);
s32 update_window_mode_from_progress__6TLobbyFPv(s32 *, s32 *);

struct TAdSinglePlyChrSelectGC__sub_8033B9F8;
extern s32 lbl_80477D48[];
extern s32 lbl_80477D50[];
void TAdSinglePlyChrSelectGC::reset_quest_id() {
    single_ply_quest_download_server = 0xFFFF;
}
void TAdSinglePlyChrSelectGC::set_quest_download_server(int a0) { (*(int *)&single_ply_quest_download_server) = a0; }
void TAdSinglePlyChrSelectGC::init_logo_state(s32 arg0) {
    lbl_805D6D88 = 0;
    lbl_805D6D84 = 0;
    lbl_805D6D80 = arg0;
    single_ply_quest_download_server = 0xFFFF;
}
void TAdSinglePlyChrSelectGC::noop() {  }
void TUnk_804EF8C0::free_buffer() { if (*(unsigned int*)((char*)this + 0x20) != 0) { TAdSinglePlyChrSelectGC::safe_free((u32)(*(void**)((char*)this + 0x20))); *(int*)((char*)this + 0x20) = 0; *(int*)((char*)this + 0x1c) = 0; } }
void TUnk_804EF8C0::clear_buffer() { if (*(unsigned int*)((char*)this + 0x20) != 0) { memset(*(void**)((char*)this + 0x20), (void*)0, *(void**)((char*)this + 0x1c)); } }
void TUnk_804EF8C0::alloc_download_buffer() {
    if ((u32) *(u32 *)((s8 *)this + 0x20) == 0U) {
        *(s32 *)((s8 *)this + 0x1C) = 0x16000;
        *(u32 *)((s8 *)this + 0x20) = ((TQuestVmDownLoadServer *)(*(s32 *)((s8 *)this + 0x1C)))->alloc();
    }
}
void TAdSinglePlyChrSelectGC__sub_8033A9F0(TAdSinglePlyChrSelectGC *ad_single_ply_chr_select_gc) {
    *(s32 *)((s8 *)ad_single_ply_chr_select_gc + 0x2C) = 0xB;
    lbl_805D6D90 &= 0xFFFFFFFE;
    ad_single_ply_chr_select_gc->set_char_slots(0xA, (s32)(*(s32 *)((s8 *)ad_single_ply_chr_select_gc + 0x24) + 0xF));
    ad_single_ply_chr_select_gc->init_warps();
}
int TAdSinglePlyChrSelectGC::queue_destruction(void *) { return queue_destruction__7TObjectFv(this); }

void TAdSinglePlyChrSelectGC::sub_8033AA64() {
    O_8033AA64 *arg0 = (O_8033AA64 *)this;
    if (((TWindowMenu *)(arg0->f3c))->is_visible() != 0) {
        switch (get_selected_menu_value(arg0->f3c)) {
        case 0:
            arg0->f2c = 0;
            ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(arg0);
            close_window__23TAdSinglePlyChrSelectGCFPv(arg0);
            break;
        default:
            arg0->f2c = 0xE;
            ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(arg0);
            close_window__23TAdSinglePlyChrSelectGCFPv(arg0);
            u32 o = __nw__7TObjectFUl(0x28);
            if (o != 0U) {
                ((THunterGuildSeqOffline *)o)->init((void *)tl_fade, (void *)TAdSinglePlyChrSelectGC__sub_8033B244);
            }
            break;
        }
    }
}

void TAdSinglePlyChrSelectGC::handle_player_load() {
    O_8033AB04 *arg0 = (O_8033AB04 *)this;
    u32 p;
    if (((TAdPlayerLoadGC *)(arg0->f24))->probe_card_slot() == 0) {
        arg0->f2C = 0;
        ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(arg0);
        return;
    }
    switch (TAdPlayerLoadGC::get_instance()) {
    case 0:
        switch (TAdPlayerLoadGC__sub_801E1B50(arg0->f24)) {
        case 0:
            switch (TAdPlayerLoadGC::get_load_result((void *)arg0->f24)) {
            case 0:
                arg0->f2C = 0xE;
                close_window__23TAdSinglePlyChrSelectGCFPv(arg0);
                p = __nw__7TObjectFUl(0x28);
                if (p != 0) {
                    ((THunterGuildSeqOffline *)p)->init((void *)tl_fade, (void *)TAdSinglePlyChrSelectGC__sub_8033B244);
                }
                break;
            default:
                arg0->f2C = 0xD;
                lbl_805D6D90 &= ~1;
                set_char_slots(0xB, -1);
                init_warps();
                break;
            }
            break;
        }
        break;
    }
}

void TAdSinglePlyChrSelectGC::update_setup() {
    if (setup__23TAdSinglePlyChrSelectGCFi(*(s32 *)((s8 *)this + 0x24)) == 0) {
        *(s32 *)((s8 *)this + 0x2C) = 8;
        TAdSinglePlyChrSelectGC::set_player_index(0xC);
        return;
    }
    *(s32 *)((s8 *)this + 0x2C) = 0;
    ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(this);
}

#define arg0 ((O_8033AC44 *)this)
void TAdSinglePlyChrSelectGC::check_memcard_space() {
    switch (get_card_file_info__15TAdPlayerLoadGCFiPvPv(arg0->f24, lbl_804C89BC, 0)) {
    case 0:
        arg0->f2c = 7;
        break;
    case -1:
        break;
    default:
        if (arg0->f28 <= query_memcard_capacity__15TAdPlayerLoadGCFl(arg0->f24, 0)) {
            arg0->f2c = 7;
        } else {
            arg0->f2c = 0xA;
            lbl_805D6D90 &= ~1;
            ((TAdSinglePlyChrSelectGC *)arg0)->set_char_slots(8, -1);
            ((TAdSinglePlyChrSelectGC *)arg0)->init_warps();
        }
        break;
    }
}
#undef arg0

void TAdSinglePlyChrSelectGC::sub_8033ACF4() {
    O_8033ACF4 *arg0 = (O_8033ACF4 *)this;
    if (((TAdPlayerLoadGC *)(arg0->f24))->probe_card_slot() == 0) {
        arg0->f2C = 0;
        ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(arg0);
        return;
    }
    switch (TAdPlayerLoadGC::get_instance()) {
    case 0:
        switch (TAdPlayerLoadGC__sub_801E1B50(arg0->f24)) {
        case 0:
            switch (TAdPlayerLoadGC::get_load_result((void *)arg0->f24)) {
            case 0:
                arg0->f2C = 6;
                arg0->f24 = get_chr_select_state__23TAdSinglePlyChrSelectGCFv();
                arg0->f28 = TAdSinglePlyChrSelectGC__sub_8001C5F0();
                check_ready__23TAdSinglePlyChrSelectGCFv();
                break;
            default:
                arg0->f2C = 0xD;
                lbl_805D6D90 &= ~1;
                ((TAdSinglePlyChrSelectGC *)arg0)->set_char_slots(0xB, -1);
                ((TAdSinglePlyChrSelectGC *)arg0)->init_warps();
                break;
            }
            break;
        }
        break;
    }
}

void TAdSinglePlyChrSelectGC::update_select_state() {
    if (TAdSinglePlyChrSelectGC__sub_801FDA4C() == 0) {
        *(s32 *)((s8 *)this + 0x2C) = 5;
        TAdSinglePlyChrSelectGC::set_player_index(6);
        set_char_slots(0xC, -1);
        return;
    }
    *(s32 *)((s8 *)this + 0x2C) = 0;
    ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(this);
}

void TAdSinglePlyChrSelectGC::handle_load_result() {
    s32 r;
    s32 cw;
    s32 inst;
    u32 obj;
    s32 src;
    switch (TAdPlayerLoadGC__sub_801E1B50(*(s32 *)((s8 *)((u8 *)this) + 0x24))) {
    case 0:
        seed_character_select_serial_rng(get_field_118__22TAdEnterSerialAccessGCFv());
        src = *(s32 *)((s8 *)((u8 *)this) + 0x20);
        obj = (int)::operator new(0x1156C);
        if (obj != 0U) {
            obj = init_char_slots__23TAdSinglePlyChrSelectGCFi();
        }
        memcpy(obj, (void *)(src + 0x2048), 0x1156C);
        decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(obj);
        if (init_and_register__23TAdSinglePlyChrSelectGCFi(obj) == 0) {
            lbl_805D6D90 &= ~1;
            ((TLobby *)(*(s32 *)((s8 *)((u8 *)this) + 0x38)))->send_and_handle(TQuestVmDownLoadServer__sub_8006EF6C(0x6D), 1);
            *(s32 *)((s8 *)((u8 *)this) + 0x2C) = 0xB;
            init_warp();
            if (obj != 0U) {
                register_callback__23TAdSinglePlyChrSelectGCFis(obj, 1);
            }
        } else {
            r = compare_save_headers__23TAdSinglePlyChrSelectGCFPvPvPvPv(TAdSinglePlyChrSelectGC__sub_801FCD3C((void *)obj), get_character_save_record(0xFFFF), obj, TAdSinglePlyChrSelectGC::get_instance());
            if (r != 7) {
                *(s32 *)((s8 *)((u8 *)this) + 0x2C) = 0xC;
                lbl_805D6D90 &= ~1;
                ((TLobby *)(*(s32 *)((s8 *)((u8 *)this) + 0x38)))->send_and_handle(TQuestVmDownLoadServer__sub_8006EF6C(0xA), 1);
                if (r == 6) {
                    init_warp();
                } else {
                    init_warps();
                }
            } else {
                seed_character_select_serial_rng(get_field_118__22TAdEnterSerialAccessGCFv());
                encrypt_save_data__23TAdSinglePlyChrSelectGCFPvPv(TAdSinglePlyChrSelectGC::get_instance());
                save_character_file__23TAdSinglePlyChrSelectGCFi(1);
                *(s32 *)((s8 *)((u8 *)this) + 0x2C) = 4;
            }
            if (obj != 0U) {
                register_callback__23TAdSinglePlyChrSelectGCFis(obj, 1);
            }
        }
        break;
    }
}

#define ad_single_ply_chr_select_gc ((O_8033AFC8 *)this)
void TAdSinglePlyChrSelectGC::sub_8033AFC8() {
    switch (get_card_file_info__15TAdPlayerLoadGCFiPvPv(ad_single_ply_chr_select_gc->f24, lbl_804C88C0, 0)) {
    case 0:
        if (ad_single_ply_chr_select_gc->f20 != 0) {
            switch (TAdPlayerLoadGC__sub_801E1944(ad_single_ply_chr_select_gc->f24, lbl_804C88C0, ad_single_ply_chr_select_gc->f20, ad_single_ply_chr_select_gc->f28)) {
            case 0:
                ad_single_ply_chr_select_gc->f2C = 3;
                break;
            default:
                ad_single_ply_chr_select_gc->f2C = 0;
                ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(ad_single_ply_chr_select_gc);
                break;
            }
        }
        break;
    case -1:
        break;
    case -251:
    case -255:
        TAdSinglePlyChrSelectGC__sub_8033A9F0((TAdSinglePlyChrSelectGC *)ad_single_ply_chr_select_gc);
        break;
    case -254:
    case -252:
    default:
        ad_single_ply_chr_select_gc->f2C = 0;
        ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(ad_single_ply_chr_select_gc);
        break;
    }
}
#undef ad_single_ply_chr_select_gc

void TAdSinglePlyChrSelectGC::sub_8033B0AC() {
    void *ad_single_ply_chr_select_gc = this;
    u32 o;
    if (*(void **)((s8 *)ad_single_ply_chr_select_gc + 0x40) != 0) {
        if (((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B9F8)(*(void **)((s8 *)ad_single_ply_chr_select_gc + 0x40)) == 1) {
            queue_destruction__7TObjectFv((void*)(*(void **)((s8 *)ad_single_ply_chr_select_gc + 0x40)));
            *(void **)((s8 *)ad_single_ply_chr_select_gc + 0x40) = 0;
            *(s32 *)((s8 *)ad_single_ply_chr_select_gc + 0x2C) = 2;
            *(s32 *)((s8 *)ad_single_ply_chr_select_gc + 0x38) = update_window_mode_from_progress__6TLobbyFPv(lbl_80477D48, lbl_80477D50);
            lbl_805D6D90 |= 1;
            return;
        }
        if (((TAdSinglePlyChrSelectGC *)(*(void **)((s8 *)ad_single_ply_chr_select_gc + 0x40)))->get_field_44() == 1) {
            queue_destruction__7TObjectFv((void*)(*(void **)((s8 *)ad_single_ply_chr_select_gc + 0x40)));
            *(void **)((s8 *)ad_single_ply_chr_select_gc + 0x40) = 0;
            *(s32 *)((s8 *)ad_single_ply_chr_select_gc + 0x2C) = 0xE;
            ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(ad_single_ply_chr_select_gc);
            close_window__23TAdSinglePlyChrSelectGCFPv(ad_single_ply_chr_select_gc);
            o = __nw__7TObjectFUl(0x28);
            if (o != 0U) {
                ((THunterGuildSeqOffline *)o)->init((void *)tl_fade, (void *)TAdSinglePlyChrSelectGC__sub_8033B244);
            }
        }
    } else {
        *(s32 *)((s8 *)ad_single_ply_chr_select_gc + 0x2C) = 0;
    }
}

void TAdSinglePlyChrSelectGC::start_check_memory_card() {
    u8 *temp_r3;
    *(u8 **)((s8 *)((u8 *)this) + 0x40) = create_check_memory_card__23TAdSinglePlyChrSelectGCFPvPvPv(this, NULL, NULL);
    temp_r3 = (u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x40));
    if (temp_r3 != NULL) {
        TAdSinglePlyChrSelectGC__sub_8033B9E0(temp_r3);
    }
    *(s32 *)((s8 *)((u8 *)this) + 0x2C) = 1;
}
void TAdSinglePlyChrSelectGC::set_char_slots(s32 arg1, s32 arg2) {
    ((TLobby *)(*(s32 *)((s8 *)this + 0x38)))->send_and_handle(TQuestVmDownLoadServer__sub_8006EF6C(arg1), 1);
    if (arg2 != -1) {
        ((TLobby *)(*(s32 *)((s8 *)this + 0x38)))->send_and_handle(TQuestVmDownLoadServer__sub_8006EF6C(arg2), 8);
    }
}
int TAdSinglePlyChrSelectGC__sub_8033B244(void* p) { return request_queued_main_phase(p); }
void TAdSinglePlyChrSelectGC__sub_8033B264(void) {
    main_task.delete_layer_children();
    TLobby::stop_audio_streams();
    TLobby::set_and_notify(0);
    call_funcs_reverse__6TLobbyFPvUi((void *) (&(*(RecoveredGlobal_8033B264_lbl_804EF728 *)&character_select_scene_resource_callbacks).value), 0x30);
    render_tick();
}

void TAdSinglePlyChrSelectGC::run_frame() {
    func_803DCDFC__Fv();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    V3_8033B2AC a = lbl_80477D78[0];
    V3_8033B2AC b = lbl_80477D84[0];
    activate_camera_mode(9);
    set_active_camera_pose(&a, &b);
    main_task.begin_frame();
    main_task.run_task();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
    TAdSinglePlyChrSelectGC::noop();
    if (!(lbl_805D6D90 & 1)) {
        if (func_801A5E54__Fv() != 0) {
            TKeyBoardControl__sub_8000F92C();
        }
        if (TQuestVmDownLoadServer::is_ready() != 0) {
            TKeyBoardControl__sub_8000F9CC(0);
        }
    }
    render_tick();
}
}

struct RecoveredGlobal_8033B264_lbl_804EF728;
void init_single_player_char_select_scene(void) {
    u32 p;
    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    run_load_callback_table(&(*(RecoveredGlobal_8033B264_lbl_804EF728 *)&character_select_scene_resource_callbacks), 0x30);
    init_menu_scene_lights(default_scene_light_config, 4);
    p = __nw__7TObjectFUl(0x1D4);
    if (p != 0) {
        TCameraCtrl__ct(p, tl_camera);
    }
    V3_8033B39C a = lbl_80477D60[0];
    V3_8033B39C b = lbl_80477D6C[0];
    TCameraCtrl::select_active_controller(9);
    set_active_camera_pose(&a, &b);
    p = __nw__7TObjectFUl(0x1C);
    if (p != 0) {
        __ct__15TWindowCtrlMainFv(p);
    }
    p = __nw__7TObjectFUl(0x44);
    if (p != 0) {
        ((TUnk_804EF8C0 *)p)->construct();
    }
    TKeyBoardControl__sub_8000F90C(2);
    lbl_805D6D90 = 0;
    play_area_music(lbl_80477D90);
    TLobby::set_and_notify(-900);
    ((TLobby *)lobby_rule_settings)->reset_settings_to_default();
    render_tick();
}

void close_window__23TAdSinglePlyChrSelectGCFPv(void *arg0) {
    void *object = *(void **)((s8 *)arg0 + 0x3C);
    if ((u32) object != 0U) {
        if (((TObject *)object)->all_parents_unqueued_for_destruction() != 0) {
            TWindow__close(*(void **)((s8 *)arg0 + 0x3C));
            *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
        }
    }
}
void TAdSinglePlyChrSelectGC::init_warp() { close_window__23TAdSinglePlyChrSelectGCFPv(this); *(int*)((char*)this + 0x3c) = check_room_seq_4__16TAdChrSelASlotGCFl(lbl_80477D58, (void*)2); forward_trade_action_default__16TObjCityMainWarpFPviii((void*)(*(int*)((char*)this + 0x3c)), (void*)((int)TQuestVmDownLoadServer__sub_8006EF6C((s32)((void*)14))), (void*)6, (void*)1); ((TWindowSubComCardList *)(*(int*)((char*)this + 0x3c)))->update_layout_height(lbl_805DFA30); }
void TAdSinglePlyChrSelectGC::init_warps() { close_window__23TAdSinglePlyChrSelectGCFPv(this); *(int*)((char*)this + 0x3c) = check_room_seq_4__16TAdChrSelASlotGCFl(lbl_80477D58, (void*)2); forward_trade_action_default__16TObjCityMainWarpFPviii((void*)(*(int*)((char*)this + 0x3c)), (void*)((int)TQuestVmDownLoadServer__sub_8006EF6C((s32)((void*)13))), (void*)6, (void*)0); forward_trade_action_default__16TObjCityMainWarpFPviii((void*)(*(int*)((char*)this + 0x3c)), (void*)((int)TQuestVmDownLoadServer__sub_8006EF6C((s32)((void*)14))), (void*)6, (void*)1); ((TWindowSubComCardList *)(*(int*)((char*)this + 0x3c)))->update_layout_height(lbl_805DFA30); }

typedef char RecoveredGlobal_8033B264_lbl_804EF728_size[sizeof(RecoveredGlobal_8033B264_lbl_804EF728) == 0x198 ? 1 : -1];
typedef char RecoveredGlobal_8033B264_main_task_size[sizeof(RecoveredGlobal_8033B264_main_task) == 0x34 ? 1 : -1];

#pragma pop

#pragma push

#include "pso/misc/TWindowCtrlMain.h"

struct Sel_8033B640 {
    u8 pad[0x2C];
    s32 state;
};

typedef void (TAdSinglePlyChrSelectGC::*SelFn_8033B640)();

struct RecoveredGlobal_8033B9C4_lbl_80513910 {
    s32 value;
    u8 remaining[0xC];
};

extern void *lbl_804EF8C0[];
extern "C" {
s32 __ct__12TAdBackTxtGCFv(void *, void *);
s32 __ct__7TObjectFP7TObject(void *, TObject *);
s32 __ct__9TAdBackGCFv(void *, void *);

void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void free_buffer__13TUnk_804EF8C0Fv(void *);
extern void* lbl_804EF8C0[];
extern RecoveredGlobal_8033B9C4_lbl_80513910 chr_select_serial_seeds;
s32 find_card_file__15TAdPlayerLoadGCFiPv(void *, void *);
extern char pso_system_card_filename[];

extern "C" void TWindowCtrlMain__sub_8024D838();
extern "C" void register_texture_f256_ad_pic_2();
extern "C" void register_texture_f256_backtext();
extern "C" void reset__11TCameraCtrlFv();
void *character_select_scene_resource_callbacks[12] = {
    (void *)&TCameraCtrl::reset_view_state, (void *)&reset__11TCameraCtrlFv, (void *)&TCameraCtrl::init_default_view, (void *)&TCameraCtrl::reset_default_view,
    (void *)&register_texture_f256_ad_pic_2, (void *)&TAdSinglePlyChrSelectGC::free_global, (void *)&register_texture_f256_backtext, (void *)&TAdSinglePlyChrSelectGC::free_singleton_805D65C0,
    (void *)&TWindowCtrlMain__sub_8024D838, (void *)&TWindowCtrlMain::free_all_windows, (void *)&TLobby::update_keyboard_menu, (void *)&TLobby::free_keyboard_soft_resources,
};

void TAdSinglePlyChrSelectGC__sub_8033B5F0(void *arg0) {
    void *object = *(void **)((s8 *)arg0 + 0x38);
    if ((u32) object != 0U) {
        if (((TObject *)object)->all_parents_unqueued_for_destruction() != 0) {
            TWindow__close(*(void **)((s8 *)arg0 + 0x38));
            *(u32 *)((s8 *)arg0 + 0x38) = 0U;
        }
    }
}

void TUnk_804EF8C0::run_task() {
    Sel_8033B640 *arg0 = (Sel_8033B640 *)this;
    static SelFn_8033B640 table[15] = {
        &TAdSinglePlyChrSelectGC::start_check_memory_card,
        &TAdSinglePlyChrSelectGC::sub_8033B0AC,
        &TAdSinglePlyChrSelectGC::sub_8033AFC8,
        &TAdSinglePlyChrSelectGC::handle_load_result,
        &TAdSinglePlyChrSelectGC::update_select_state,
        &TAdSinglePlyChrSelectGC::sub_8033ACF4,
        &TAdSinglePlyChrSelectGC::check_memcard_space,
        &TAdSinglePlyChrSelectGC::update_setup,
        &TAdSinglePlyChrSelectGC::handle_player_load,
        &TAdSinglePlyChrSelectGC::sub_8033AA64,
        &TAdSinglePlyChrSelectGC::sub_8033AA64,
        &TAdSinglePlyChrSelectGC::sub_8033AA64,
        &TAdSinglePlyChrSelectGC::sub_8033AA64,
        &TAdSinglePlyChrSelectGC::sub_8033AA64,
        (SelFn_8033B640)&TAdSinglePlyChrSelectGC::queue_destruction,
    };
    (((TAdSinglePlyChrSelectGC *)this)->*table[arg0->state])();
}

void *TAdSinglePlyChrSelectGC::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = (s32*)lbl_804EF8C0;
        free_buffer__13TUnk_804EF8C0Fv(this);
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TUnk_804EF8C0::construct() {
    void *p;
    __ct__7TObjectFP7TObject(this, tl_01);
    *(void **)((s8 *)this + 0x18) = lbl_804EF8C0;
    *(s32 *)((s8 *)this + 0x30) = 0;
    *(s32 *)((s8 *)this + 0x34) = 0;
    *(s32 *)((s8 *)this + 0x38) = 0;
    *(s32 *)((s8 *)this + 0x3C) = 0;
    *(s32 *)((s8 *)this + 0x40) = 0;
    *(s32 *)((s8 *)this + 0x24) = (s32) ((s8 (*)(void *))get_chr_select_state__23TAdSinglePlyChrSelectGCFv)(lbl_804EF8C0);
    *(s32 *)((s8 *)this + 0x28) = TAdSinglePlyChrSelectGC::get_flag_count();
    *(s32 *)((s8 *)this + 0x2C) = 0;
    *(s32 *)((s8 *)this + 0x20) = 0;
    *(s32 *)((s8 *)this + 0x1C) = 0;
    p = ((void * (*)(s32))__nw__7TObjectFUl)(0x24);
    if (p != NULL) {
        __ct__9TAdBackGCFv(p, this);
    }
    p = ((void * (*)(s32))__nw__7TObjectFUl)(0x28);
    if (p != NULL) {
        __ct__12TAdBackTxtGCFv(p, this);
    }
    alloc_download_buffer();
    clear_buffer();
    stop_pad_rumble();
    return this;
}
}

typedef char RecoveredGlobal_8033B9C4_lbl_80513910_size[sizeof(RecoveredGlobal_8033B9C4_lbl_80513910) == 0x10 ? 1 : -1];
void seed_character_select_serial_rng(s32 arg0) {
    *(s32 *)((s8 *)&chr_select_serial_seeds.value + 4) = arg0;
    *(s32 *)((s8 *)&chr_select_serial_seeds.value + 0) = arg0;
}

s32 TAdSinglePlyChrSelectGC::get_field_44() { return *(s32*)((char*)this + 0x44); }

void TAdSinglePlyChrSelectGC__sub_8033B9E0(void* p) { *(s32*)((char*)p + 0x40) = 1; }

void TAdSinglePlyChrSelectGC__sub_8033B9EC(void* p) { *(s32*)((char*)p + 0x4c) = 1; }

u8 TAdSinglePlyChrSelectGC__sub_8033B9F8(u8 *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x3C) == 1);
}

s32 TAdSinglePlyChrSelectGC::has_no_save_files() {
    if (find_card_file__15TAdPlayerLoadGCFiPv(this, ((u8 *)&pso_system_card_filename)) != 0 || find_card_file__15TAdPlayerLoadGCFiPv(this, lbl_804C88C0) != 0 || find_card_file__15TAdPlayerLoadGCFiPv(this, lbl_804C89BC) != 0) {
        return 0;
    }
    return 1;
}

bool TAdSinglePlyChrSelectGC__sub_8033BA84(void *self) {
    return !find_card_file__15TAdPlayerLoadGCFiPv(self, pso_system_card_filename);
}

#pragma pop
