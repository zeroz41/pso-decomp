#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/system/save/CardSaveFile.h"
#include "pso/system/save/CardFileInfo.h"
#include "pso/unk/TScreenFadeOut.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TitleBackgroundStorage.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/ProgressMessageWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/TCharSaveSequence.h"
#include <string.h>
#include "pso/object/ambient/TObjLight_80133568.h"
#pragma push

#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/system/PadRumble.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8001C5E8.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/system/main_loop.h"
#include "pso/system/save/TCheckMemoryCard.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/save/CharacterFile.h"
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
s32 TAdSinglePlyChrSelectGC__sub_801FDA4C();

extern void *character_select_scene_resource_callbacks[];
int create_window_menu_default(void*, void*);
u32 __nw__7TObjectFUl(int);

s32 start_memcard_read(s32, void *, u32, s32);


s8 func_801A5E54__Fv();
}
void process_async_file_reads(void);
void update_sound_request_slots(void);
extern "C" {
s32 func_803DCDFC__Fv();
s32 run_load_callback_table(void *, int);
s32 reset_controller_input_state();
s32 __ct__15TWindowCtrlMainFv(u32);

extern u8 lobby_rule_settings[];
CharacterSaveRecord *TAdSinglePlyChrSelectGC__sub_801FCD3C(CharacterFile *);
s32 get_field_118__22TAdEnterSerialAccessGCFv();

void TAdSinglePlyChrSelectGC::reset_quest_id() {
    single_ply_quest_download_server = 0xFFFF;
}
void TAdSinglePlyChrSelectGC::set_quest_download_server(int quest_download_server) { (*(int *)&single_ply_quest_download_server) = quest_download_server; }
void TAdSinglePlyChrSelectGC::init_logo_state(s32 arg0) {
    lbl_805D6D88 = 0;
    lbl_805D6D84 = 0;
    lbl_805D6D80 = arg0;
    single_ply_quest_download_server = 0xFFFF;
}
void TAdSinglePlyChrSelectGC::noop() {  }
void TCharSaveSequence::free_buffer() {
    if (download_buffer != NULL) {
        safe_free(download_buffer);
        download_buffer = NULL;
        download_buffer_size = 0;
    }
}
void TCharSaveSequence::clear_buffer() {
    if (download_buffer != NULL) {
        memset(download_buffer, 0, download_buffer_size);
    }
}
void TCharSaveSequence::alloc_download_buffer() {
    if (download_buffer == NULL) {
        download_buffer_size = 0x16000;
        download_buffer = (void *)TQuestVmDownLoadServer::alloc(download_buffer_size);
    }
}
void TCharSaveSequence::report_missing_file() {
    state = 0xB;
    lbl_805D6D90 &= 0xFFFFFFFE;
    set_char_slots(0xA, chr_select_state + 0xF);
    init_warps();
}
void TCharSaveSequence::queue_destruction() { TObject::queue_destruction(); }

void TCharSaveSequence::handle_retry_menu() {
    if (menu->is_decided() != 0) {
        switch (menu->get_selected_value()) {
        case 0:
            state = 0;
            close_message_window();
            close_window();
            break;
        default:
            state = 0xE;
            close_message_window();
            close_window();
            new TScreenFadeOut(tl_fade, TAdSinglePlyChrSelectGC__sub_8033B244);
            break;
        }
    }
}

void TCharSaveSequence::handle_player_load() {
    uaddr p;
    if (TAdPlayerLoadGC::probe_card_slot(chr_select_state) == 0) {
        state = 0;
        close_message_window();
        return;
    }
    switch (TAdPlayerLoadGC::get_instance()) {
    case 0:
        switch (poll_memcard_result(chr_select_state)) {
        case 0:
            switch (TAdPlayerLoadGC::get_load_result(chr_select_state)) {
            case 0:
                state = 0xE;
                close_window();
                new TScreenFadeOut(tl_fade, TAdSinglePlyChrSelectGC__sub_8033B244);
                break;
            default:
                state = 0xD;
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

void TCharSaveSequence::update_setup() {
    if (TAdSinglePlyChrSelectGC::setup(chr_select_state) == 0) {
        state = 8;
        TAdSinglePlyChrSelectGC::set_player_index(0xC);
        return;
    }
    state = 0;
    close_message_window();
}

void TCharSaveSequence::check_memcard_space() {
    switch (TAdPlayerLoadGC::get_card_file_info(chr_select_state, pso_guildcard_card_filename.filename, 0)) {
    case 0:
        state = 7;
        break;
    case -1:
        break;
    default:
        if (flag_count <= (s32)TAdPlayerLoadGC::query_memcard_capacity(chr_select_state, 0)) {
            state = 7;
        } else {
            state = 0xA;
            lbl_805D6D90 &= ~1;
            set_char_slots(8, -1);
            init_warps();
        }
        break;
    }
}

void TCharSaveSequence::wait_character_file_write() {
    if (TAdPlayerLoadGC::probe_card_slot(chr_select_state) == 0) {
        state = 0;
        close_message_window();
        return;
    }
    switch (TAdPlayerLoadGC::get_instance()) {
    case 0:
        switch (poll_memcard_result(chr_select_state)) {
        case 0:
            switch (TAdPlayerLoadGC::get_load_result(chr_select_state)) {
            case 0:
                state = 6;
                chr_select_state = (s8)TAdSinglePlyChrSelectGC::get_chr_select_state();
                flag_count = TAdSinglePlyChrSelectGC__sub_8001C5F0();
                TAdSinglePlyChrSelectGC::check_ready();
                break;
            default:
                state = 0xD;
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

void TCharSaveSequence::update_select_state() {
    if (TAdSinglePlyChrSelectGC__sub_801FDA4C() == 0) {
        state = 5;
        TAdSinglePlyChrSelectGC::set_player_index(6);
        set_char_slots(0xC, -1);
        return;
    }
    state = 0;
    close_message_window();
}

void TCharSaveSequence::handle_load_result() {
    s32 r;
    CharacterFile *obj;
    saddr src;
    switch (poll_memcard_result(chr_select_state)) {
    case 0:
        seed_character_select_serial_rng(get_field_118__22TAdEnterSerialAccessGCFv());
        src = (saddr)download_buffer;
        obj = new CharacterFile;
        memcpy(obj, (void *)(src + 0x2048), 0x1156C);
        TAdSinglePlyChrSelectGC::decrypt_char_data(obj);
        if (TAdSinglePlyChrSelectGC::init_and_register(obj) == 0) {
            lbl_805D6D90 &= ~1;
            message_window->append_line(get_message_text(0x6D), 1);
            state = 0xB;
            init_warp();
            if (obj != NULL) {
                delete obj;
            }
        } else {
            r = TAdSinglePlyChrSelectGC::compare_save_headers(TAdSinglePlyChrSelectGC__sub_801FCD3C(obj), (void *)get_character_save_record(0xFFFF), obj, (void *)TAdSinglePlyChrSelectGC::get_instance());
            if (r != 7) {
                state = 0xC;
                lbl_805D6D90 &= ~1;
                message_window->append_line(get_message_text(0xA), 1);
                if (r == 6) {
                    init_warp();
                } else {
                    init_warps();
                }
            } else {
                seed_character_select_serial_rng(get_field_118__22TAdEnterSerialAccessGCFv());
                TAdSinglePlyChrSelectGC::encrypt_save_data((void *)TAdSinglePlyChrSelectGC::get_instance());
                TAdSinglePlyChrSelectGC::save_character_file(1);
                state = 4;
            }
            if (obj != NULL) {
                delete obj;
            }
        }
        break;
    }
}

void TCharSaveSequence::start_character_read() {
    switch (TAdPlayerLoadGC::get_card_file_info(chr_select_state, pso_character_card_filename.filename, 0)) {
    case 0:
        if (download_buffer != 0) {
            switch (start_memcard_read(chr_select_state, pso_character_card_filename.filename, (uaddr)download_buffer, flag_count)) {
            case 0:
                state = 3;
                break;
            default:
                state = 0;
                close_message_window();
                break;
            }
        }
        break;
    case -1:
        break;
    case -251:
    case -255:
        report_missing_file();
        break;
    case -254:
    case -252:
    default:
        state = 0;
        close_message_window();
        break;
    }
}

void TCharSaveSequence::wait_card_check() {
    uaddr o;
    if (check_memory_card != NULL) {
        if (check_memory_card->is_card_ready() == 1) {
            check_memory_card->queue_destruction();
            check_memory_card = NULL;
            state = 2;
            message_window = (TWindowMessage *)create_message_window_for_size((NJS_POINT2 *)lbl_80477D48, (NJS_POINT2 *)lbl_80477D50);
            lbl_805D6D90 |= 1;
            return;
        }
        if (check_memory_card->prompt_was_accepted() == 1) {
            check_memory_card->queue_destruction();
            check_memory_card = NULL;
            state = 0xE;
            close_message_window();
            close_window();
            new TScreenFadeOut(tl_fade, TAdSinglePlyChrSelectGC__sub_8033B244);
        }
    } else {
        state = 0;
    }
}

void TCharSaveSequence::start_check_memory_card() {
    TCheckMemoryCard *check;
    check_memory_card = TCheckMemoryCard::create(this, NULL, 0);
    check = check_memory_card;
    if (check != NULL) {
        check->enable_prompt();
    }
    state = 1;
}
void TCharSaveSequence::set_char_slots(s32 message, s32 sub_message) {
    message_window->append_line(get_message_text(message), 1);
    if (sub_message != -1) {
        message_window->append_line(get_message_text(sub_message), 8);
    }
}
void TAdSinglePlyChrSelectGC__sub_8033B244(TObject *) { request_queued_main_phase(); }
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
    TAdSinglePlyChrSelectGC::run_save_load_sequence();
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
    init_menu_scene_lights(&default_scene_light_config, 4);
    new TCameraCtrl(tl_camera);
    Vec a = lbl_80477D60;
    Vec b = lbl_80477D6C;
    TCameraCtrl::select_active_controller(9);
    set_active_camera_pose(&a, &b);
    p = (uaddr)TObject::operator new(0x1C);
    if (p != 0) {
        __ct__15TWindowCtrlMainFv(p);
    }
    new TCharSaveSequence();
    TKeyBoardControl__sub_8000F90C(2);
    lbl_805D6D90 = 0;
    play_area_music("title.adx");
    TLobby::set_and_notify(-900);
    ((TLobby *)lobby_rule_settings)->reset_settings_to_default();
    render_tick();
}
#pragma pool_data reset

void TCharSaveSequence::close_window() {
    TWindowMenu *object = menu;
    if (object != NULL) {
        if (object->all_parents_unqueued_for_destruction() != 0) {
            menu->close();
            menu = NULL;
        }
    }
}
void TCharSaveSequence::init_warp() {
    close_window();
    menu = (TWindowMenu *)create_window_menu_default((void *)lbl_80477D58, (void *)2);
    menu->add_text_entry(get_message_text(14), 6, 1);
    menu->update_layout_height(289.0f);
}
void TCharSaveSequence::init_warps() {
    close_window();
    menu = (TWindowMenu *)create_window_menu_default((void *)lbl_80477D58, (void *)2);
    menu->add_text_entry(get_message_text(13), 6, 0);
    menu->add_text_entry(get_message_text(14), 6, 1);
    menu->update_layout_height(289.0f);
}

LAYOUT_ASSERT(RecoveredGlobal_8033B264_lbl_804EF728_size, sizeof(RecoveredGlobal_8033B264_lbl_804EF728) == 0x198);

#pragma pop

#pragma push

#include "pso/ui/window/TWindowCtrlMain.h"

typedef void (TCharSaveSequence::*Handler)();

struct RecoveredGlobal_8033B9C4_lbl_80513910 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {

extern RecoveredGlobal_8033B9C4_lbl_80513910 chr_select_serial_seeds;

extern "C" void TWindowCtrlMain__sub_8024D838();
extern "C" void register_texture_f256_backtext();
void *character_select_scene_resource_callbacks[12] = {
    (void *)&TCameraCtrl::reset_view_state, (void *)&TCameraCtrl::reset, (void *)&TCameraCtrl::init_default_view, (void *)&TCameraCtrl::reset_default_view,
    (void *)&register_texture_f256_ad_pic_2, (void *)&TAdSinglePlyChrSelectGC::free_global, (void *)&register_texture_f256_backtext, (void *)&TAdSinglePlyChrSelectGC::free_singleton_805D65C0,
    (void *)&TWindowCtrlMain__sub_8024D838, (void *)&TWindowCtrlMain::free_all_windows, (void *)&TLobby::update_keyboard_menu, (void *)&TLobby::free_keyboard_soft_resources,
};

void TCharSaveSequence::close_message_window() {
    TWindowMessage *object = message_window;
    if (object != NULL) {
        if (object->all_parents_unqueued_for_destruction() != 0) {
            message_window->close();
            message_window = NULL;
        }
    }
}

void TCharSaveSequence::run_task() {
    static Handler table[15] = {
        &TCharSaveSequence::start_check_memory_card,
        &TCharSaveSequence::wait_card_check,
        &TCharSaveSequence::start_character_read,
        &TCharSaveSequence::handle_load_result,
        &TCharSaveSequence::update_select_state,
        &TCharSaveSequence::wait_character_file_write,
        &TCharSaveSequence::check_memcard_space,
        &TCharSaveSequence::update_setup,
        &TCharSaveSequence::handle_player_load,
        &TCharSaveSequence::handle_retry_menu,
        &TCharSaveSequence::handle_retry_menu,
        &TCharSaveSequence::handle_retry_menu,
        &TCharSaveSequence::handle_retry_menu,
        &TCharSaveSequence::handle_retry_menu,
        &TCharSaveSequence::queue_destruction,
    };
    (this->*table[state])();
}

TCharSaveSequence::~TCharSaveSequence() {
    free_buffer();
}

TCharSaveSequence::TCharSaveSequence() : TObject(tl_01) {
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

#pragma pop
