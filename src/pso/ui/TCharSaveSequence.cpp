#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/memory.h"
#include "pso/system/AsyncFileRead.h"
#include "pso/system/save/CardSaveFile.h"
#include "pso/system/save/CardFileInfo.h"
#include "pso/system/TScreenFadeOut.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/TCharSaveSequence.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include <string.h>
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/map/area/AreaScene.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#pragma push

#include "types.h"
#include "pso/render/gjSystem.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/system/PadRumble.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/system/main_loop.h"
#include "pso/system/save/TCheckMemoryCard.h"
#include "pso/audio/MusicControl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/save/CharacterFile.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/audio/SoundRequests.h"

// Window position and size setup passes to create_message_window_for_size
static const f32 char_save_message_window_pos[2] = { 80.0f, 146.0f };
static const f32 char_save_message_window_size[2] = { 479.0f, 267.0f };
// Window position init_warp and init_warps pass to create_window_menu_default
static const NJS_POINT2 char_save_menu_position = { 324.0f, 374.0f };
// Camera position and target of init_single_player_char_select_scene
static const Vec char_select_camera_position = { 0.0f, 0.0f, 0.0f };
static const Vec char_select_camera_target = { 0.0f, 0.0f, -100.0f };
// Camera position and target of run_frame
static const Vec char_save_frame_camera_position = { 0.0f, 0.0f, 0.0f };
static const Vec char_save_frame_camera_target = { 0.0f, 0.0f, -100.0f };

s32 chr_select_logo_state;
s32 lbl_805D6D84;
s32 lbl_805D6D88;
s32 single_ply_quest_download_server;
s32 char_save_message_flags;
extern "C" {
extern void *character_select_scene_resource_callbacks[];

s32 start_memcard_read(s32, void *, u32, s32);
}
void TAdSinglePlyChrSelectGC::reset_quest_id() {
    single_ply_quest_download_server = 0xFFFF;
}
void TAdSinglePlyChrSelectGC::set_quest_download_server(int quest_download_server) { single_ply_quest_download_server = quest_download_server; }
void TAdSinglePlyChrSelectGC::init_logo_state(s32 state) {
    lbl_805D6D88 = 0;
    lbl_805D6D84 = 0;
    chr_select_logo_state = state;
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
    char_save_message_flags &= 0xFFFFFFFE;
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
            new TScreenFadeOut(tl_fade, on_chr_select_fade_out_done);
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
                new TScreenFadeOut(tl_fade, on_chr_select_fade_out_done);
                break;
            default:
                state = 0xD;
                char_save_message_flags &= ~1;
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
            char_save_message_flags &= ~1;
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
                flag_count = get_guild_card_file_block_count();
                TAdSinglePlyChrSelectGC::check_ready();
                break;
            default:
                state = 0xD;
                char_save_message_flags &= ~1;
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
    if (start_character_file_write() == 0) {
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
        seed_character_select_serial_rng(TAdEnterSerialAccessGC::get_serial_seed());
        src = (saddr)download_buffer;
        obj = new CharacterFile;
        memcpy(obj, (void *)(src + 0x2048), 0x1156C);
        TAdSinglePlyChrSelectGC::decrypt_char_data(obj);
        if (TAdSinglePlyChrSelectGC::init_and_register(obj) == 0) {
            char_save_message_flags &= ~1;
            message_window->append_line(get_message_text(0x6D), 1);
            state = 0xB;
            init_warp();
            if (obj != NULL) {
                delete obj;
            }
        } else {
            r = TAdSinglePlyChrSelectGC::compare_save_headers(get_selected_save_record(obj), (CharacterSaveRecord *)get_character_save_record(0xFFFF), obj, TAdSinglePlyChrSelectGC::get_instance());
            if (r != 7) {
                state = 0xC;
                char_save_message_flags &= ~1;
                message_window->append_line(get_message_text(0xA), 1);
                if (r == 6) {
                    init_warp();
                } else {
                    init_warps();
                }
            } else {
                seed_character_select_serial_rng(TAdEnterSerialAccessGC::get_serial_seed());
                TAdSinglePlyChrSelectGC::encrypt_save_data(TAdSinglePlyChrSelectGC::get_instance());
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
            message_window = create_message_window_for_size((NJS_POINT2 *)char_save_message_window_pos, (NJS_POINT2 *)char_save_message_window_size);
            char_save_message_flags |= 1;
            return;
        }
        if (check_memory_card->prompt_was_accepted() == 1) {
            check_memory_card->queue_destruction();
            check_memory_card = NULL;
            state = 0xE;
            close_message_window();
            close_window();
            new TScreenFadeOut(tl_fade, on_chr_select_fade_out_done);
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

void on_chr_select_fade_out_done(TObject *) { request_queued_main_phase(); }
void release_single_ply_chr_select_scene(void) {
    main_task.delete_layer_children();
    stop_audio_streams();
    set_and_notify(0);
    TLobby::call_funcs_reverse(&character_select_scene_resource_callbacks, 0x30);
    render_tick();
}

void TAdSinglePlyChrSelectGC::run_frame() {
    begin_gx_frame();
    controller_stuff();
    update_keyboard_input_frame();
    Vec a = char_save_frame_camera_position;
    Vec b = char_save_frame_camera_target;
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
    if (!(char_save_message_flags & 1)) {
        if (static_cast<s8>(poll_reset_request()) != 0) {
            switch_to_fallback_main_phase();
        }
        if (TQuestVmDownLoadServer::is_ready() != 0) {
            request_main_phase(0);
        }
    }
    render_tick();
}

#pragma pool_data off
void init_single_player_char_select_scene(void) {
    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    run_load_callback_table(&character_select_scene_resource_callbacks, 0x30);
    init_menu_scene_lights(&default_scene_light_config, 4);
    new TCameraCtrl(tl_camera);
    Vec a = char_select_camera_position;
    Vec b = char_select_camera_target;
    TCameraCtrl::select_active_controller(9);
    set_active_camera_pose(&a, &b);
    new TWindowCtrlMain();
    new TCharSaveSequence();
    set_fallback_main_phase(2);
    char_save_message_flags = 0;
    play_area_music("title.adx");
    set_and_notify(-900);
    lobby_rule_settings.reset_settings_to_default();
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
    menu = create_window_menu_default(&char_save_menu_position, 2);
    menu->add_text_entry(get_message_text(14), 6, 1);
    menu->update_layout_height(289.0f);
}
void TCharSaveSequence::init_warps() {
    close_window();
    menu = create_window_menu_default(&char_save_menu_position, 2);
    menu->add_text_entry(get_message_text(13), 6, 0);
    menu->add_text_entry(get_message_text(14), 6, 1);
    menu->update_layout_height(289.0f);
}


#pragma pop

#pragma push


typedef void (TCharSaveSequence::*Handler)();

LAYOUT_ASSERT(ChrSelectSerialSeeds_size, sizeof(ChrSelectSerialSeeds) == 0x10);


extern ChrSelectSerialSeeds chr_select_serial_seeds;

void *character_select_scene_resource_callbacks[12] = {
    (void *)&TCameraCtrl::reset_view_state, (void *)&TCameraCtrl::reset, (void *)&TCameraCtrl::init_default_view, (void *)&TCameraCtrl::reset_default_view,
    (void *)&register_texture_f256_ad_pic_2, (void *)&TAdSinglePlyChrSelectGC::free_global, (void *)&register_texture_f256_backtext, (void *)&TAdSinglePlyChrSelectGC::free_texture_f256_backtext,
    (void *)&TWindowCtrlMain::reset_windows, (void *)&TWindowCtrlMain::free_all_windows, (void *)&update_keyboard_menu, (void *)&free_keyboard_soft_resources,
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

void seed_character_select_serial_rng(s32 seed) {
    chr_select_serial_seeds.seed_b = seed;
    chr_select_serial_seeds.seed_a = seed;
}

#pragma pop
