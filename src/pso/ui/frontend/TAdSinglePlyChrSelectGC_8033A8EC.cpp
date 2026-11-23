#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TitleBackgroundStorage.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/ProgressMessageWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/TUnk_804EF8C0.h"
#include <string.h>
#include "pso/object/ambient/TObjLight_80133568.h"
#pragma push

#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/system/PadRumble.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8001C5E8.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8033A8EC.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/system/main_loop.h"
#include "pso/system/save/TCheckMemoryCard.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/effect/particle/TParticleCtrl.h"

struct RecoveredGlobal_8033B264_lbl_804EF728 {
    s32 value;
    u8 remaining[0x194];
};






// Window position and size setup passes to create_message_window_for_size
static const f32 lbl_80477D48[2] = { 80.0f, 146.0f };
static const f32 lbl_80477D50[2] = { 479.0f, 267.0f };
// Window position init_warp and init_warps pass to create_window_menu_default
static const f32 lbl_80477D58[2] = { 324.0f, 374.0f };
// Camera position and target of init_single_player_char_select_scene
static const Vec lbl_80477D60 = { 0.0f, 0.0f, 0.0f };
static const Vec lbl_80477D6C = { 0.0f, 0.0f, -100.0f };
// Camera position and target of run_frame
static const Vec lbl_80477D78 = { 0.0f, 0.0f, 0.0f };
static const Vec lbl_80477D84 = { 0.0f, 0.0f, -100.0f };

s32 lbl_805D6D80;
s32 lbl_805D6D84;
s32 lbl_805D6D88;
s32 single_ply_quest_download_server;
s32 lbl_805D6D90;
extern "C" {
struct TAdSinglePlyChrSelectGC__sub_8033B5F0;
s32 setup__23TAdSinglePlyChrSelectGCFi(s32);
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C();

int request_queued_main_phase(void*);
extern void *character_select_scene_resource_callbacks[];
int create_window_menu_default(void*, void*);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void*, void*, void*, void*);
u32 __nw__7TObjectFUl(int);

s32 get_card_file_info__15TAdPlayerLoadGCFiPvPv(int, void *, int);
extern char pso_guildcard_card_filename[];
extern char pso_character_card_filename[];
s32 start_memcard_read(s32, void *, u32, s32);
s32 poll_memcard_result(saddr);

void check_ready__23TAdSinglePlyChrSelectGCFv(void);

s32 TKeyBoardControl__sub_8000F92C();
s32 request_main_phase(int);
s8 func_801A5E54__Fv();
s32 run_save_load_sequence__23TAdSinglePlyChrSelectGCFv();
}
void process_async_file_reads(void);
void update_sound_request_slots(void);
extern "C" {
s32 func_803DCDFC__Fv();
s32 TKeyBoardControl__sub_8000F90C(int);
s32 run_load_callback_table(void *, int);
s32 reset_controller_input_state();
s32 __ct__15TWindowCtrlMainFv(u32);

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
void TUnk_804EF8C0::free_buffer() {
    if (download_buffer != NULL) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)download_buffer);
        download_buffer = NULL;
        download_buffer_size = 0;
    }
}
void TUnk_804EF8C0::clear_buffer() {
    if (download_buffer != NULL) {
        memset(download_buffer, 0, download_buffer_size);
    }
}
void TUnk_804EF8C0::alloc_download_buffer() {
    if (download_buffer == NULL) {
        download_buffer_size = 0x16000;
        download_buffer = (void *)TQuestVmDownLoadServer::alloc(download_buffer_size);
    }
}
void TAdSinglePlyChrSelectGC__sub_8033A9F0(TAdSinglePlyChrSelectGC *ad_single_ply_chr_select_gc) {
    *(s32 *)((s8 *)ad_single_ply_chr_select_gc + 0x2C) = 0xB;
    lbl_805D6D90 &= 0xFFFFFFFE;
    ad_single_ply_chr_select_gc->set_char_slots(0xA, (s32)(*(s32 *)((s8 *)ad_single_ply_chr_select_gc + 0x24) + 0xF));
    ad_single_ply_chr_select_gc->init_warps();
}
void TAdSinglePlyChrSelectGC::queue_destruction(void *) { TObject::queue_destruction(); }

void TAdSinglePlyChrSelectGC::sub_8033AA64() {
    TUnk_804EF8C0 *arg0 = (TUnk_804EF8C0 *)this;
    if (((TWindowMenu *)(arg0->menu))->is_decided() != 0) {
        switch (((TWindowMenu *)arg0->menu)->get_selected_value()) {
        case 0:
            arg0->state = 0;
            ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(arg0);
            close_window__23TAdSinglePlyChrSelectGCFPv(arg0);
            break;
        default:
            arg0->state = 0xE;
            ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(arg0);
            close_window__23TAdSinglePlyChrSelectGCFPv(arg0);
            uaddr o = (uaddr)TObject::operator new(0x28);
            if (o != 0U) {
                ((THunterGuildSeqOffline *)o)->init((void *)tl_fade, (void *)TAdSinglePlyChrSelectGC__sub_8033B244);
            }
            break;
        }
    }
}

void TAdSinglePlyChrSelectGC::handle_player_load() {
    TUnk_804EF8C0 *arg0 = (TUnk_804EF8C0 *)this;
    uaddr p;
    if (TAdPlayerLoadGC::probe_card_slot(arg0->chr_select_state) == 0) {
        arg0->state = 0;
        ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(arg0);
        return;
    }
    switch (TAdPlayerLoadGC::get_instance()) {
    case 0:
        switch (poll_memcard_result(arg0->chr_select_state)) {
        case 0:
            switch (TAdPlayerLoadGC::get_load_result(arg0->chr_select_state)) {
            case 0:
                arg0->state = 0xE;
                close_window__23TAdSinglePlyChrSelectGCFPv(arg0);
                p = (uaddr)TObject::operator new(0x28);
                if (p != 0) {
                    ((THunterGuildSeqOffline *)p)->init((void *)tl_fade, (void *)TAdSinglePlyChrSelectGC__sub_8033B244);
                }
                break;
            default:
                arg0->state = 0xD;
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

#define arg0 ((TUnk_804EF8C0 *)this)
void TAdSinglePlyChrSelectGC::check_memcard_space() {
    switch (get_card_file_info__15TAdPlayerLoadGCFiPvPv(arg0->chr_select_state, pso_guildcard_card_filename, 0)) {
    case 0:
        arg0->state = 7;
        break;
    case -1:
        break;
    default:
        if (arg0->flag_count <= (s32)TAdPlayerLoadGC::query_memcard_capacity(arg0->chr_select_state, 0)) {
            arg0->state = 7;
        } else {
            arg0->state = 0xA;
            lbl_805D6D90 &= ~1;
            ((TAdSinglePlyChrSelectGC *)arg0)->set_char_slots(8, -1);
            ((TAdSinglePlyChrSelectGC *)arg0)->init_warps();
        }
        break;
    }
}
#undef arg0

void TAdSinglePlyChrSelectGC::sub_8033ACF4() {
    TUnk_804EF8C0 *arg0 = (TUnk_804EF8C0 *)this;
    if (TAdPlayerLoadGC::probe_card_slot(arg0->chr_select_state) == 0) {
        arg0->state = 0;
        ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(arg0);
        return;
    }
    switch (TAdPlayerLoadGC::get_instance()) {
    case 0:
        switch (poll_memcard_result(arg0->chr_select_state)) {
        case 0:
            switch (TAdPlayerLoadGC::get_load_result(arg0->chr_select_state)) {
            case 0:
                arg0->state = 6;
                arg0->chr_select_state = (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
                arg0->flag_count = TAdSinglePlyChrSelectGC__sub_8001C5F0();
                check_ready__23TAdSinglePlyChrSelectGCFv();
                break;
            default:
                arg0->state = 0xD;
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
    uaddr obj;
    saddr src;
    switch (poll_memcard_result(*(s32 *)((s8 *)((u8 *)this) + 0x24))) {
    case 0:
        seed_character_select_serial_rng(get_field_118__22TAdEnterSerialAccessGCFv());
        src = *(s32 *)((s8 *)((u8 *)this) + 0x20);
        obj = (saddr)::operator new(0x1156C);
        if (obj != 0U) {
            obj = init_char_slots__23TAdSinglePlyChrSelectGCFi();
        }
        memcpy((void *)obj, (void *)(src + 0x2048), 0x1156C);
        decrypt_char_data__23TAdSinglePlyChrSelectGCFPv(obj);
        if (init_and_register__23TAdSinglePlyChrSelectGCFi(obj) == 0) {
            lbl_805D6D90 &= ~1;
            ((TWindowMessage *)(*(saddr *)((s8 *)((u8 *)this) + 0x38)))->append_line(get_message_text(0x6D), 1);
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
                ((TWindowMessage *)(*(saddr *)((s8 *)((u8 *)this) + 0x38)))->append_line(get_message_text(0xA), 1);
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

#define ad_single_ply_chr_select_gc ((TUnk_804EF8C0 *)this)
void TAdSinglePlyChrSelectGC::sub_8033AFC8() {
    switch (get_card_file_info__15TAdPlayerLoadGCFiPvPv(ad_single_ply_chr_select_gc->chr_select_state, pso_character_card_filename, 0)) {
    case 0:
        if (ad_single_ply_chr_select_gc->download_buffer != 0) {
            switch (start_memcard_read(ad_single_ply_chr_select_gc->chr_select_state, pso_character_card_filename, (uaddr)ad_single_ply_chr_select_gc->download_buffer, ad_single_ply_chr_select_gc->flag_count)) {
            case 0:
                ad_single_ply_chr_select_gc->state = 3;
                break;
            default:
                ad_single_ply_chr_select_gc->state = 0;
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
        ad_single_ply_chr_select_gc->state = 0;
        ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(ad_single_ply_chr_select_gc);
        break;
    }
}
#undef ad_single_ply_chr_select_gc

void TAdSinglePlyChrSelectGC::sub_8033B0AC() {
    TAdSinglePlyChrSelectGC *ad_single_ply_chr_select_gc = this;
    uaddr o;
    if (ad_single_ply_chr_select_gc->memory_card_check != NULL) {
        if (ad_single_ply_chr_select_gc->memory_card_check->is_card_ready() == 1) {
            ad_single_ply_chr_select_gc->memory_card_check->queue_destruction();
            ad_single_ply_chr_select_gc->memory_card_check = NULL;
            *(s32 *)((s8 *)ad_single_ply_chr_select_gc + 0x2C) = 2;
            *(s32 *)((s8 *)ad_single_ply_chr_select_gc + 0x38) = (saddr)create_message_window_for_size((NJS_POINT2 *)lbl_80477D48, (NJS_POINT2 *)lbl_80477D50);
            lbl_805D6D90 |= 1;
            return;
        }
        if (ad_single_ply_chr_select_gc->memory_card_check->prompt_was_accepted() == 1) {
            ad_single_ply_chr_select_gc->memory_card_check->queue_destruction();
            ad_single_ply_chr_select_gc->memory_card_check = NULL;
            *(s32 *)((s8 *)ad_single_ply_chr_select_gc + 0x2C) = 0xE;
            ((s32 (*)(void *))TAdSinglePlyChrSelectGC__sub_8033B5F0)(ad_single_ply_chr_select_gc);
            close_window__23TAdSinglePlyChrSelectGCFPv(ad_single_ply_chr_select_gc);
            o = (uaddr)TObject::operator new(0x28);
            if (o != 0U) {
                ((THunterGuildSeqOffline *)o)->init((void *)tl_fade, (void *)TAdSinglePlyChrSelectGC__sub_8033B244);
            }
        }
    } else {
        *(s32 *)((s8 *)ad_single_ply_chr_select_gc + 0x2C) = 0;
    }
}

void TAdSinglePlyChrSelectGC::start_check_memory_card() {
    TCheckMemoryCard *check;
    memory_card_check = TCheckMemoryCard::create(this, NULL, 0);
    check = memory_card_check;
    if (check != NULL) {
        check->enable_prompt();
    }
    *(s32 *)((s8 *)((u8 *)this) + 0x2C) = 1;
}
void TAdSinglePlyChrSelectGC::set_char_slots(s32 arg1, s32 arg2) {
    ((TWindowMessage *)(*(saddr *)((s8 *)this + 0x38)))->append_line(get_message_text(arg1), 1);
    if (arg2 != -1) {
        ((TWindowMessage *)(*(saddr *)((s8 *)this + 0x38)))->append_line(get_message_text(arg2), 8);
    }
}
int TAdSinglePlyChrSelectGC__sub_8033B244(void* p) { return request_queued_main_phase(p); }
void TAdSinglePlyChrSelectGC__sub_8033B264(void) {
    main_task.delete_layer_children();
    TLobby::stop_audio_streams();
    TLobby::set_and_notify(0);
    TLobby::call_funcs_reverse((void *)&character_select_scene_resource_callbacks, 0x30);
    render_tick();
}

void TAdSinglePlyChrSelectGC::run_frame() {
    func_803DCDFC__Fv();
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    Vec a = lbl_80477D78;
    Vec b = lbl_80477D84;
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
            request_main_phase(0);
        }
    }
    render_tick();
}
}

struct RecoveredGlobal_8033B264_lbl_804EF728;
#pragma pool_data off
void init_single_player_char_select_scene(void) {
    u32 p;
    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    run_load_callback_table(&(*(RecoveredGlobal_8033B264_lbl_804EF728 *)&character_select_scene_resource_callbacks), 0x30);
    init_menu_scene_lights((u8 *)default_scene_light_config, 4);
    new TCameraCtrl(tl_camera);
    Vec a = lbl_80477D60;
    Vec b = lbl_80477D6C;
    TCameraCtrl::select_active_controller(9);
    set_active_camera_pose(&a, &b);
    p = (uaddr)TObject::operator new(0x1C);
    if (p != 0) {
        __ct__15TWindowCtrlMainFv(p);
    }
    new TUnk_804EF8C0();
    TKeyBoardControl__sub_8000F90C(2);
    lbl_805D6D90 = 0;
    play_area_music("title.adx");
    TLobby::set_and_notify(-900);
    ((TLobby *)lobby_rule_settings)->reset_settings_to_default();
    render_tick();
}
#pragma pool_data reset

void close_window__23TAdSinglePlyChrSelectGCFPv(void *arg0) {
    void *object = *(void **)((s8 *)arg0 + 0x3C);
    if ((uaddr) object != 0U) {
        if (((TObject *)object)->all_parents_unqueued_for_destruction() != 0) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x3C)))->close();
            *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
        }
    }
}
void TAdSinglePlyChrSelectGC::init_warp() { close_window__23TAdSinglePlyChrSelectGCFPv(this); *(int*)((char*)this + 0x3c) = create_window_menu_default((void *)lbl_80477D58, (void*)2); forward_trade_action_default__16TObjCityMainWarpFPviii((void*)(*(saddr*)((char*)this + 0x3c)), (void*)((saddr)get_message_text((saddr)((void*)14))), (void*)6, (void*)1); ((TWindowMenu *)(*(saddr*)((char*)this + 0x3c)))->update_layout_height(289.0f); }
void TAdSinglePlyChrSelectGC::init_warps() { close_window__23TAdSinglePlyChrSelectGCFPv(this); *(int*)((char*)this + 0x3c) = create_window_menu_default((void *)lbl_80477D58, (void*)2); forward_trade_action_default__16TObjCityMainWarpFPviii((void*)(*(saddr*)((char*)this + 0x3c)), (void*)((saddr)get_message_text((saddr)((void*)13))), (void*)6, (void*)0); forward_trade_action_default__16TObjCityMainWarpFPviii((void*)(*(saddr*)((char*)this + 0x3c)), (void*)((saddr)get_message_text((saddr)((void*)14))), (void*)6, (void*)1); ((TWindowMenu *)(*(saddr*)((char*)this + 0x3c)))->update_layout_height(289.0f); }

LAYOUT_ASSERT(RecoveredGlobal_8033B264_lbl_804EF728_size, sizeof(RecoveredGlobal_8033B264_lbl_804EF728) == 0x198);

#pragma pop

#pragma push

#include "pso/ui/window/TWindowCtrlMain.h"

typedef void (TAdSinglePlyChrSelectGC::*SelFn_8033B640)();

struct RecoveredGlobal_8033B9C4_lbl_80513910 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {

extern RecoveredGlobal_8033B9C4_lbl_80513910 chr_select_serial_seeds;
extern char pso_system_card_filename[];

extern "C" void TWindowCtrlMain__sub_8024D838();
extern "C" void register_texture_f256_ad_pic_2();
extern "C" void register_texture_f256_backtext();
void *character_select_scene_resource_callbacks[12] = {
    (void *)&TCameraCtrl::reset_view_state, (void *)&TCameraCtrl::reset, (void *)&TCameraCtrl::init_default_view, (void *)&TCameraCtrl::reset_default_view,
    (void *)&register_texture_f256_ad_pic_2, (void *)&TAdSinglePlyChrSelectGC::free_global, (void *)&register_texture_f256_backtext, (void *)&TAdSinglePlyChrSelectGC::free_singleton_805D65C0,
    (void *)&TWindowCtrlMain__sub_8024D838, (void *)&TWindowCtrlMain::free_all_windows, (void *)&TLobby::update_keyboard_menu, (void *)&TLobby::free_keyboard_soft_resources,
};

void TAdSinglePlyChrSelectGC__sub_8033B5F0(void *arg0) {
    void *object = *(void **)((s8 *)arg0 + 0x38);
    if ((uaddr) object != 0U) {
        if (((TObject *)object)->all_parents_unqueued_for_destruction() != 0) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x38)))->close();
            *(u32 *)((s8 *)arg0 + 0x38) = 0U;
        }
    }
}

void TUnk_804EF8C0::run_task() {
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
    (((TAdSinglePlyChrSelectGC *)this)->*table[state])();
}

TUnk_804EF8C0::~TUnk_804EF8C0() {
    free_buffer();
}

TUnk_804EF8C0::TUnk_804EF8C0() : TObject(tl_01) {
    void *p;
    unk_30 = 0;
    unk_34 = 0;
    message_window = NULL;
    menu = NULL;
    check_memory_card = NULL;
    chr_select_state = (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
    flag_count = TAdSinglePlyChrSelectGC::get_flag_count();
    state = 0;
    download_buffer = NULL;
    download_buffer_size = 0;
    p = new TAdBackGC(this);
    p = new TAdBackTxtGC(this);
    alloc_download_buffer();
    clear_buffer();
    stop_pad_rumble();
}
}

LAYOUT_ASSERT(RecoveredGlobal_8033B9C4_lbl_80513910_size, sizeof(RecoveredGlobal_8033B9C4_lbl_80513910) == 0x10);
void seed_character_select_serial_rng(s32 arg0) {
    *(s32 *)((s8 *)&chr_select_serial_seeds.value + 4) = arg0;
    *(s32 *)((s8 *)&chr_select_serial_seeds.value + 0) = arg0;
}

s32 TCheckMemoryCard::prompt_was_accepted() { return prompt_accepted; }

void TCheckMemoryCard::enable_prompt() { prompt = 1; }

void TCheckMemoryCard::select_main_window_controller() { use_main_ctrl = 1; }

s32 TCheckMemoryCard::is_card_ready() {
    return card_ready == 1;
}

s32 TAdSinglePlyChrSelectGC::has_no_save_files(s32 chan) {
    if (TAdPlayerLoadGC::find_card_file(chan, pso_system_card_filename) != 0 || TAdPlayerLoadGC::find_card_file(chan, pso_character_card_filename) != 0 || TAdPlayerLoadGC::find_card_file(chan, pso_guildcard_card_filename) != 0) {
        return 0;
    }
    return 1;
}

s32 TAdSinglePlyChrSelectGC__sub_8033BA84(s32 chan) {
    if (TAdPlayerLoadGC::find_card_file(chan, pso_system_card_filename) != 0) {
        return 0;
    }
    return 1;
}

#pragma pop
