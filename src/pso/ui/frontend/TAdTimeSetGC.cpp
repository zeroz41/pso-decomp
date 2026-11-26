#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/save/CardSaveFile.h"
#include "pso/system/save/CardFileInfo.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include <stdio.h>
#include <string.h>
#include "pso/system/ControllerInputState.h"
#include "pso/system/TLanguage.h"
#include "pso/system/date.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/Language.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8001C5E8.h"
#include "pso/ui/frontend/TAdTimeSetGC.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowKeyBoardHard_801FBA48.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/ProgressMessageWindow.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/unk/text_8023F160.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/ui/frontend/TAdPlyStatusGC.h"
#include "pso/ui/charcreate/CharacterPreview.h"

#pragma push
#pragma defer_codegen off

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

s32 CharacterPreview::get_hair_model() { return part_models[0]; }
NJS_TEXLIST *CharacterPreview::get_chara_making_data() { return &head_textures.list; }
s32 CharacterPreview::get_head_model() { return part_models[1]; }
s32 CharacterPreview::get_attachment_model() { return part_models[2]; }
NJS_TEXLIST *CharacterPreview::get_status_data() { return &other_textures.list; }
saddr CharacterPreview::get_body_model() { return body_model; }
NJS_TEXLIST *CharacterPreview::get_status_sub() { return &body_textures.list; }

void TAdPlyStatusGC::set_status_param(CharacterPreview *preview) { ply_status_preview = preview; }

TAdPlyStatusGC *TAdPlyStatusGC::get_index() { return ply_status_gc_instance; }

void TAdPlyStatusGC::set_status_index(int a0, int a1) { ply_status_index = a1; }


void TAdPlyStatusGC::close_window(s32 index) {
    TAdPlyStatusGC::window_offset_index = index;
    if (window != NULL) {
        window->close();
        window = NULL;
    }
}

#pragma pop

// Functions and data of other units that have no shared declaration with the signature these calls use.
extern "C" {
s32 start_memcard_format(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
}

// One entry per state: enter is called by change_state, run by run_task every frame.
struct TAdTimeSetGCState {
    void (TAdTimeSetGC::*enter)();
    void (TAdTimeSetGC::*run)();
};
LAYOUT_ASSERT(TAdTimeSetGCState_size, sizeof(TAdTimeSetGCState) == 24);
LAYOUT_ASSERT(TAdTimeSetGCState_run_offset, offsetof(TAdTimeSetGCState, run) == 12);

const char *TAdTimeSetGC_class_name = "TAdTimeSetGC";

static const f32 time_set_message_size[2] = {540.0f, 260.0f};

const char *T_ATS_DrawCalendar__name = "T_ATS_DrawCalendar";

static const f32 time_set_message_pos[2] = {
    0.5f * (640.0f - time_set_message_size[0]),
    90.0f,
};
static const NJS_POINT2 time_set_menu_pos = {
    20.0f + time_set_message_pos[0],
    10.0f + (time_set_message_pos[1] + time_set_message_size[1]),
};
static const f32 time_set_menu_width = time_set_message_size[0] - 40.0f;
static const f32 time_set_calendar_pos[2] = {
    time_set_message_pos[0] + 0.5f * time_set_message_size[0],
    (time_set_message_pos[1] + time_set_message_size[1]) - 85.0f,
};
static TAdTimeSetGCState time_set_state_table[25] = {
    {&TAdTimeSetGC::rebuild_and_maybe_close, &TAdTimeSetGC::report_card_status},
    {&TAdTimeSetGC::enter_state_1, &TAdTimeSetGC::ensure_system_file_loaded},
    {&TAdTimeSetGC::enter_state_2, &TAdTimeSetGC::run_state_2},
    {&TAdTimeSetGC::enter_state_3, &TAdTimeSetGC::ensure_player_loaded},
    {&TAdTimeSetGC::enter_state_4, &TAdTimeSetGC::reset_on_load_complete},
    {&TAdTimeSetGC::open_char_select, &TAdTimeSetGC::handle_confirm_menu},
    {&TAdTimeSetGC::close_and_next_cancel, &TAdTimeSetGC::update_load_state},
    {&TAdTimeSetGC::arm_load_countdown, &TAdTimeSetGC::update_load_countdown},
    {&TAdTimeSetGC::close_scene, &TAdTimeSetGC::run_state_8},
    {&TAdTimeSetGC::arm_char_delete_timer, &TAdTimeSetGC::update_timer},
    {&TAdTimeSetGC::enter_state_10, &TAdTimeSetGC::advance_when_load_done},
    {&TAdTimeSetGC::arm_guildcard_delete_timer, &TAdTimeSetGC::update_char_timer},
    {&TAdTimeSetGC::init_screen, &TAdTimeSetGC::run_state_12},
    {&TAdTimeSetGC::enter_state_13, &TAdTimeSetGC::update_close_timer},
    {&TAdTimeSetGC::enter_state_14, &TAdTimeSetGC::try_setup},
    {NULL, &TAdTimeSetGC::update_close_on_load},
    {&TAdTimeSetGC::enter_state_16, &TAdTimeSetGC::run_state_16},
    {&TAdTimeSetGC::enter_state_17, &TAdTimeSetGC::run_states_17_18},
    {&TAdTimeSetGC::enter_state_18, &TAdTimeSetGC::run_states_17_18},
    {&TAdTimeSetGC::enter_state_19, &TAdTimeSetGC::run_states_19_21},
    {&TAdTimeSetGC::init_menu_window, &TAdTimeSetGC::run_states_19_21},
    {&TAdTimeSetGC::build_selection_summary, &TAdTimeSetGC::run_states_19_21},
    {&TAdTimeSetGC::create_result_bg, &TAdTimeSetGC::sub_802E2158},
    {&TAdTimeSetGC::show_confirm_dialog, &TAdTimeSetGC::run_state_23},
    {&TAdTimeSetGC::enter_state_24, &TAdTimeSetGC::update_state},
};

void TAdTimeSetGC::sub_802E34A8() {
}

void TAdTimeSetGC::sub_802E34A4() {
}

TAdTimeSetGC::TAdTimeSetGC(TObject *parent) : TObject(parent) {
    m_name = TAdTimeSetGC_class_name;
    init();
    TLobby::stop_audio_streams();
}

TAdTimeSetGC::~TAdTimeSetGC() {
    if (message_window != NULL) {
        delete message_window;
        message_window = NULL;
    }
    if (menu_window != NULL) {
        menu_window->close();
        menu_window = NULL;
    }
    if (calendar != NULL) {
        calendar->queue_destruction();
        calendar = NULL;
    }
}

void TAdTimeSetGC::run_task() {
    load_status = poll_load_status();
    if (load_status & 1) {
        change_state(0);
    }
    TAdTimeSetGCState *entry = &time_set_state_table[state_index];
    void (TAdTimeSetGC::*run)() = entry->run;
    if (run != NULL) {
        (this->*run)();
    }
    timer--;
    if (timer < 0) {
        timer = 0;
    }
}

void TAdTimeSetGC::rebuild_and_maybe_close() {
    create_backgrounds();
    close_windows();
    if (load_status & 1) {
        close_and_next(0, -1, -1, -1);
    }
}

void TAdTimeSetGC::report_card_status() {
    s32 flags;

    flags = load_status;
    if (flags & 2) {
        return;
    }
    if (flags & 1) {
        if (message_window == NULL) {
            close_and_next(0, -1, -1, -1);
        }
        return;
    }
    if (flags & 4) {
        change_state(0x11);
        return;
    }
    if (flags & 8) {
        change_state(0x12);
        return;
    }
    if (flags & 0x10) {
        change_state(0x13);
        return;
    }
    if (flags & 0x20) {
        change_state(0x14);
        return;
    }
    if (flags & 0x40) {
        if (state7_message_closed != 0) {
            change_state(0x14);
            return;
        }
        change_state(5);
        return;
    }
    if (flags & 0x380) {
        change_state(0x15);
        return;
    }
    if (system_file_loaded == 0 && !(flags & 0x400)) {
        change_state(1);
        return;
    }
    if (load_status == 0) {
        change_state(3);
        return;
    }
    if (flags & 0x400) {
        switch (flags & 0x1800) {
        case 0x800:
            change_state(0xA);
            return;
        case 0x1800:
            break;
        case 0x1000:
        default:
            change_state(8);
            return;
        }
    }
    if (check_capacity() == 0) {
        change_state(0x17);
        return;
    }
    flags = load_status;
    if (flags & 0x400) {
        if (state12_message_closed != 0) {
            change_state(0x14);
            return;
        }
        change_state(0x10);
        return;
    }
    if (flags & 0x800) {
        if (state13_message_closed != 0) {
            change_state(0x14);
            return;
        }
        change_state(0xD);
        return;
    }
    if (flags & 0x1000) {
        if (state15_load_ended != 0) {
            change_state(0x14);
            return;
        }
        change_state(0xE);
    }
}

void TAdTimeSetGC::enter_state_1() {
    close_windows();
}

void TAdTimeSetGC::ensure_system_file_loaded() {
    if (!(load_status & 2)) {
        load_system_file(0);
        change_state(2);
    }
}

void TAdTimeSetGC::enter_state_2() {
}

void TAdTimeSetGC::run_state_2() {
    if (TAdPlayerLoadGC::get_instance() == 0) {
        system_file_loaded = 1;
        if (load_status == 0) {
            change_state(3);
            return;
        }
        change_state(0);
    }
}

void TAdTimeSetGC::enter_state_3() {
    close_windows();
}

void TAdTimeSetGC::ensure_player_loaded() {
    if (!(load_status & 2)) {
        load_guild_card_save();
        change_state(4);
    }
}

void TAdTimeSetGC::enter_state_4() {
}

void TAdTimeSetGC::reset_on_load_complete() {
    if (TAdPlayerLoadGC::get_instance() == 0) {
        skip_apply_options = 0;
        change_state(0x18);
    }
}

void TAdTimeSetGC::open_char_select() {
    create_backgrounds();
    strcpy(text, (const char *)get_localized_text_entry(0x1C, 8));
    close_and_dispatch((uaddr)text, 1, get_localized_text_entry(0x1C, 0x29), get_localized_text_entry(0x1C, 0x16));
}

void TAdTimeSetGC::handle_confirm_menu() {
    if (menu_window == NULL || menu_window->is_decided() == 0) {
        return;
    }
    switch (menu_window->get_selected_value()) {
    case 0:
        change_state(6);
        break;
    case 1:
        state_index = -1;
        change_state(5);
        break;
    }
}

void TAdTimeSetGC::close_and_next_cancel() {
    close_and_next(2, -1, -1, -1);
}

void TAdTimeSetGC::update_load_state() {
    if (is_load_complete() != 0) {
        if (TAdPlayerLoadGC::check_card_result_code(0) == 0) {
            change_state(0x16);
            return;
        }
        change_state(7);
    }
}

void TAdTimeSetGC::arm_load_countdown() {
    message_frames = 30;
}

void TAdTimeSetGC::update_load_countdown() {
    if (TAdPlayerLoadGC::check_card_result_code(0) == 0) {
        change_state(0x16);
        return;
    }
    message_frames--;
    if (message_frames < 0) {
        message_frames = 0;
    }
    if (!(load_status & 2)) {
        if (message_frames < 0xF && sub_802E1868() != 0) {
            message_frames = 0;
        }
        if (message_frames == 0) {
            state7_message_closed = 1;
            close_windows();
            if (timer == 0) {
                change_state(0);
            }
        }
    }
}

void TAdTimeSetGC::close_scene() {
    create_backgrounds();
    close_and_dispatch(get_localized_text_entry(0x1C, 9), -1, 0, 0);
}

void TAdTimeSetGC::run_state_8() {
    if ((s32)TAdPlayerLoadGC::delete_memcard_file(0, pso_character_card_filename.filename) == 0) {
        change_state(9);
    }
}

void TAdTimeSetGC::arm_char_delete_timer() {
    message_frames = 30;
}

void TAdTimeSetGC::update_timer() {
    message_frames--;
    if (message_frames < 0) {
        message_frames = 0;
    }
    if (!(load_status & 2)) {
        if (message_frames < 0xF && sub_802E1868() != 0) {
            message_frames = 0;
        }
        if (message_frames == 0) {
            close_windows();
            if (timer == 0) {
                change_state(0);
            }
        }
    }
}

void TAdTimeSetGC::enter_state_10() {
    create_backgrounds();
    close_and_dispatch(get_localized_text_entry(0x1C, 0xA), -1, 0, 0);
}

void TAdTimeSetGC::advance_when_load_done() {
    if ((s32)TAdPlayerLoadGC::delete_memcard_file(0, pso_guildcard_card_filename.filename) == 0) {
        change_state(0xB);
    }
}

void TAdTimeSetGC::arm_guildcard_delete_timer() {
    message_frames = 30;
}

void TAdTimeSetGC::update_char_timer() {
    message_frames--;
    if (message_frames < 0) {
        message_frames = 0;
    }
    if (!(load_status & 2)) {
        if (message_frames < 0xF && sub_802E1868() != 0) {
            message_frames = 0;
        }
        if (message_frames == 0) {
            close_windows();
            if (timer == 0) {
                change_state(0);
            }
        }
    }
}

void TAdTimeSetGC::init_screen() {
    TAdSinglePlyChrSelectGC::reset_save_header();
    if (TAdSinglePlyChrSelectGC::try_confirm_selection() == 0) {
        change_state(0);
        return;
    }
    start_system_file_write((s8)TAdSinglePlyChrSelectGC::get_chr_select_state());
    TAdSinglePlyChrSelectGC::set_player_index(0xF);
    create_backgrounds();
    close_and_next(3, -1, -1, -1);
    message_frames = 30;
}

void TAdTimeSetGC::run_state_12() {
    message_frames--;
    if (message_frames < 0) {
        message_frames = 0;
    }
    if (!(load_status & 2) && TAdPlayerLoadGC::get_instance() == 0) {
        if (message_frames < 0xF && sub_802E1868() != 0) {
            message_frames = 0;
        }
        if (message_frames == 0) {
            close_windows();
            if (timer == 0) {
                state12_message_closed = 1;
                change_state(0);
            }
        }
    }
}

void TAdTimeSetGC::enter_state_13() {
    TAdSinglePlyChrSelectGC::start_load();
    create_backgrounds();
    close_and_next(4, -1, -1, -1);
    message_frames = 30;
}

void TAdTimeSetGC::update_close_timer() {
    message_frames--;
    if (message_frames < 0) {
        message_frames = 0;
    }
    if (!(load_status & 2) && TAdPlayerLoadGC::get_instance() == 0) {
        if (message_frames < 0xF && sub_802E1868() != 0) {
            message_frames = 0;
        }
        if (message_frames == 0) {
            close_windows();
            if (timer == 0) {
                state13_message_closed = 1;
                change_state(0);
            }
        }
    }
}

void TAdTimeSetGC::enter_state_14() {
    init_timestamped_data();
    if (TAdSinglePlyChrSelectGC::check_ready() == 0) {
        change_state(0);
        return;
    }
    create_backgrounds();
    close_and_next(5, -1, -1, -1);
}

void TAdTimeSetGC::try_setup() {
    if (TAdSinglePlyChrSelectGC::setup((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) == 0) {
        TAdSinglePlyChrSelectGC::set_player_index(0xC);
        change_state(0xF);
    }
}

void TAdTimeSetGC::update_close_on_load() {
    if (!(load_status & 2) && TAdPlayerLoadGC::get_instance() == 0) {
        close_windows();
        if (timer == 0) {
            state15_load_ended = 1;
            change_state(0);
        }
    }
}

void TAdTimeSetGC::enter_state_16() {
    create_backgrounds();
    close_and_dispatch(get_localized_text_entry(0x1C, 0xB), 1, 0, 0);
    if (calendar != NULL) {
        calendar->enable_calendar_draw();
    }
}

void TAdTimeSetGC::run_state_16() {
    if (menu_window == NULL || menu_window->is_decided() == 0) {
        return;
    }
    switch (menu_window->get_selected_value()) {
    case 0:
        skip_apply_options = 1;
        change_state(0x18);
        return;
    case 1:
        change_state(0xC);
        break;
    }
}

void TAdTimeSetGC::enter_state_17() {
    create_backgrounds();
    strcpy(text, (const char *)get_localized_text_entry(0x1C, 0x25));
    close_and_dispatch((uaddr)text, -2, get_localized_text_entry(0x1C, 0x16), 0);
}

void TAdTimeSetGC::run_states_17_18() {
    if (menu_window == NULL || menu_window->is_decided() == 0) {
        return;
    }
    menu_window->get_selected_value();
    TAdPlayerLoadGC::poll_card_load(0);
    sub_802E1F14();
    change_state(0);
}

void TAdTimeSetGC::enter_state_18() {
    create_backgrounds();
    strcpy(text, (const char *)get_localized_text_entry(0x1C, 0x27));
    close_and_dispatch((uaddr)text, -2, get_localized_text_entry(0x1C, 0x16), 0);
}

void TAdTimeSetGC::enter_state_19() {
    create_backgrounds();
    strcpy(text, (const char *)get_localized_text_entry(0x1C, 0x26));
    close_and_dispatch((uaddr)text, -2, get_localized_text_entry(0x1C, 0x16), 0);
}

void TAdTimeSetGC::init_menu_window() {
    create_backgrounds();
    strcpy(text, (const char *)get_localized_text_entry(0x1C, 1));
    strcat(text, "\n");
    close_and_dispatch((uaddr)text, -2, get_localized_text_entry(0x1C, 0x16), 0);
}

void TAdTimeSetGC::run_states_19_21() {
    if (menu_window == NULL || menu_window->is_decided() == 0) {
        return;
    }
    switch (menu_window->get_selected_value()) {
    case 0:
        if (load_status & 0x80) {
            TAdSinglePlyChrSelectGC::try_load_system_file();
        }
        if (load_status & 0x100) {
            TAdSinglePlyChrSelectGC__sub_801FBB1C();
        }
        if (load_status & 0x200) {
            TAdSinglePlyChrSelectGC__sub_801FBB7C();
        }
        TAdPlayerLoadGC::poll_card_load(0);
        sub_802E1F14();
        change_state(0);
        break;
    case 1:
        TAdPlayerLoadGC::poll_card_load(0);
        sub_802E1F14();
        change_state(0);
        break;
    }
}

void TAdTimeSetGC::build_selection_summary() {
    create_backgrounds();
    text[0] = 0;
    if (load_status & 0x80) {
        strcat(text, (const char *)get_localized_text_entry(0x1C, 0x1D));
        strcat(text, "\n");
    }
    if (load_status & 0x100) {
        strcat(text, (const char *)get_localized_text_entry(0x1C, 0x1E));
        strcat(text, "\n");
    }
    if (load_status & 0x200) {
        strcat(text, (const char *)get_localized_text_entry(0x1C, 0x1F));
        strcat(text, "\n");
    }
    close_and_dispatch((uaddr)text, 1, get_localized_text_entry(0x1C, 0x2A), get_localized_text_entry(0x1C, 0x2B));
}

void TAdTimeSetGC::create_result_bg() {
    create_backgrounds();
    close_and_dispatch(get_localized_text_entry(0x1C, 0x1C), -1, 0, 0);
}

void TAdTimeSetGC::sub_802E2158() {
}

void TAdTimeSetGC::show_confirm_dialog() {
    s32 files;
    s32 flags;

    files = get_localized_text_entry(0x1C, 0x18);
    flags = load_status;
    if (!(flags & 0x400)) {
        switch (flags & 0x1800) {
        case 0x1800:
            files = get_localized_text_entry(0x1C, 0x19);
            break;
        case 0x800:
            files = get_localized_text_entry(0x1C, 0x1A);
            break;
        case 0x1000:
            files = get_localized_text_entry(0x1C, 0x1B);
            break;
        }
    }
    sprintf(text, "%s\n%s\n%s", get_localized_text_entry(0x1C, 0x17), files, get_localized_text_entry(0x1C, 0x14));
    create_backgrounds();
    close_and_dispatch((uaddr)text, 1, get_localized_text_entry(0x1C, 0x15), get_localized_text_entry(0x1C, 0x16));
}

void TAdTimeSetGC::run_state_23() {
    if (menu_window == NULL || menu_window->is_decided() == 0) {
        return;
    }
    switch (menu_window->get_selected_value()) {
    case 0:
        skip_apply_options = 1;
        change_state(0x18);
        break;
    case 1:
        sub_802E1F14();
        change_state(0);
        break;
    }
}

void TAdTimeSetGC::enter_state_24() {
    close_windows();
}

void TAdTimeSetGC::update_state() {
    if (timer <= 0) {
        switch (skip_apply_options) {
        case 0:
            apply_settings();
            return;
        default:
        case 1:
            sub_802E18C8();
            break;
        }
    }
}

void TAdTimeSetGC::sub_802E1F14() {
    system_file_check = -1;
    character_file_check = -1;
    guild_card_file_check = -1;
    state7_message_closed = 0;
    state12_message_closed = 0;
    state13_message_closed = 0;
    state15_load_ended = 0;
}

void TAdTimeSetGC::init() {
    sub_802E1F14();
    back = NULL;
    back_text = NULL;
    message_window = NULL;
    menu_window = NULL;
    calendar = T_ATS_DrawCalendar::create();
    system_file_loaded = 0;
    skip_apply_options = 0;
    timer = 0;
    busy_count = 0;
    load_status = poll_load_status();
    state_index = -1;
    if (load_status == 0) {
        change_state(1);
        return;
    }
    change_state(0);
}

void TAdTimeSetGC::change_state(s32 new_state) {
    if (state_index != new_state) {
        state_index = new_state;
        TAdTimeSetGCState *entry = &time_set_state_table[state_index];
        void (TAdTimeSetGC::*enter)() = entry->enter;
        if (enter != NULL) {
            (this->*enter)();
        }
    }
}

s32 TAdTimeSetGC::count_flags() {
    s32 count = 0;

    if (load_status & 0x400) {
        count = 1;
    }
    if (load_status & 0x800) {
        count++;
    }
    if (load_status & 0x1000) {
        count++;
    }
    return count;
}

s32 TAdTimeSetGC::count_selected_flags() {
    s32 count = 0;

    if (load_status & 0x400) {
        count = TAdSinglePlyChrSelectGC::get_selected_count();
    }
    if (load_status & 0x800) {
        count += TAdSinglePlyChrSelectGC::get_flag_count();
    }
    if (load_status & 0x1000) {
        count += TAdSinglePlyChrSelectGC__sub_8001C5F0();
    }
    return count;
}

s32 TAdTimeSetGC::check_capacity() {
    s32 files = count_flags();
    s32 blocks = count_selected_flags();
    s32 free_files = get_memcard_free_files(0);
    s32 free_blocks = (s32)TAdPlayerLoadGC::query_memcard_capacity(0, 0);

    if (files > free_files || blocks > free_blocks) {
        return 0;
    }
    return 1;
}

void TAdTimeSetGC::create_backgrounds() {
    void *object;

    if (back == NULL) {
        object = new TAdBackGC(this);
        back = (TAdBackGC *)object;
    }
    if (back_text == NULL) {
        object = new TAdBackTxtGC(this);
        back_text = (TAdBackTxtGC *)object;
    }
}

void TAdTimeSetGC::close_windows() {
    if (message_window != NULL) {
        message_window->close();
        message_window = NULL;
        timer = 7;
    }
    if (menu_window != NULL) {
        menu_window->close();
        menu_window = NULL;
        timer = 7;
    }
    if (calendar != NULL) {
        calendar->disable_calendar_draw();
    }
}

// sel -1: message only; -2: one menu entry; otherwise two entries with entry sel selected.
void TAdTimeSetGC::open_message_choice(u32 text, s32 sel, u32 first_text, u32 second_text) {
    u32 entry_text;

    if (message_window != NULL || menu_window != NULL) {
        return;
    }
    message_window = create_message_window_for_size((NJS_POINT2 *)time_set_message_pos, (NJS_POINT2 *)time_set_message_size);
    if (message_window == NULL) {
        return;
    }
    if (text != 0) {
        message_window->append_line(text, 3);
    }
    message_window->complete_reveal();
    if (sel == -1) {
        return;
    }
    menu_window = (TWindowMenu *)(saddr)create_window_menu_default(&time_set_menu_pos, 2);
    if (message_window == NULL) {
        return;
    }
    entry_text = first_text;
    if (first_text == 0) {
        entry_text = (uaddr)TWindowSubStatusDisp::get_message_10(0x5B);
    }
    if (sel != -2) {
        menu_window->add_text_entry(entry_text, 5, 0);
        entry_text = second_text;
        if (second_text == 0) {
            entry_text = (uaddr)TWindowSubStatusDisp::get_message_10(0x5C);
        }
        menu_window->add_text_entry(entry_text, 5, 1);
    } else {
        menu_window->add_text_entry(entry_text, 5, 1);
    }
    ((TWindowMenu *)menu_window)->update_layout_height(time_set_menu_width);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(menu_window));
    if (sel == -2) {
        ((TWindowSubComCardList *)menu_window)->set_selected_index(0);
    } else {
        ((TWindowSubComCardList *)menu_window)->set_selected_index(sel);
    }
    ((TWindowOptionCtrl *)menu_window)->clear_flag70_bit4();
}

void TAdTimeSetGC::sub_802E1A04(s32 entry, s32 sel, s32 first_entry, s32 second_entry) {
    s32 text;
    s32 first_text;

    text = get_localized_text_entry(0x1C, entry);
    first_text = 0;
    if (first_entry >= 0) {
        first_text = get_localized_text_entry(0x1C, first_entry);
    }
    if (second_entry >= 0) {
        first_text = get_localized_text_entry(0x1C, second_entry);
    }
    open_message_choice(text, sel, first_text, 0);
}

void TAdTimeSetGC::close_and_dispatch(u32 text, s32 sel, u32 first_text, u32 second_text) {
    close_windows();
    open_message_choice(text, sel, first_text, second_text);
}

void TAdTimeSetGC::close_and_next(s32 entry, s32 sel, s32 first_entry, s32 second_entry) {
    close_windows();
    sub_802E1A04(entry, sel, first_entry, second_entry);
}

void TAdTimeSetGC::apply_settings() {
    s8 *state = (s8 *)TAdSinglePlyChrSelectGC::get_global_state();

    if (state == NULL) {
        change_state(1);
        return;
    }
    TLanguage::set_language(state[7]);
    update_music_stream_gain(*(s16 *)(state + 4));
    TLobby__sub_8022614C(state[6]);
    TLobby::init_sound_mode();
    unload_lobby_scene_resources();
    load_lobby_scene_resources();
    TAdMultiChgGameModeGC::init_change_mode();
}

void TAdTimeSetGC::sub_802E18C8() {
    request_main_phase(0);
}

s32 TAdTimeSetGC::sub_802E1868() {
    if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 4) != 0 ||
        test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0) {
        return 1;
    }
    return 0;
}

// Result bits: 1 no card, 2 card busy, 4/8/0x10/0x20 card errors, 0x40 card check failed, 0x80/0x100/0x200 system /
// character / Guild Card file damaged, 0x400/0x800/0x1000 system / character / Guild Card file not on the card yet.
s32 TAdTimeSetGC::poll_load_status() {
    s32 damaged;
    s32 failed;
    s32 absent;

    if (poll_memcard_result(0) != 0) {
        busy_count++;
        return 2;
    }
    busy_count = 0;
    if (TAdPlayerLoadGC::probe_card_slot(0) == 0) {
        sub_802E1F14();
        return 1;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(0) == 0) {
        switch (TAdPlayerLoadGC::get_load_result(0)) {
        case -125:
            return 4;
        case -127:
            return 8;
        case -223:
            return 0x10;
        default:
            return 0x20;
        }
    } else {
        if (TAdPlayerLoadGC::check_memcard_status(0) != 0) {
            return 0x40;
        }
        if (sub_802E1528() != 0) {
            return 0x80;
        }
        damaged = 0;
        if (is_card_file_missing_b() != 0) {
            damaged |= 0x100;
        }
        if (is_card_file_missing_a() != 0) {
            damaged |= 0x200;
        }
        if (damaged != 0) {
            return damaged;
        }
        if (system_file_check == -1) {
            system_file_check = 0;
            if (TAdSinglePlyChrSelectGC::load_system_file_blocking() != 0) {
                system_file_check = 1;
            }
        }
        if (system_file_check == 1) {
            return 0x80;
        }
        if (sub_802E15C8() != 0) {
            if (character_file_check == -1) {
                character_file_check = 0;
                if (TAdSinglePlyChrSelectGC::load_character_and_wait() != 0) {
                    character_file_check = 1;
                }
            }
            if (guild_card_file_check == -1) {
                guild_card_file_check = 0;
                if (TAdSinglePlyChrSelectGC::load_player_and_wait() != 0) {
                    guild_card_file_check = 1;
                }
            }
            failed = 0;
            if (character_file_check == 1) {
                failed |= 0x100;
            }
            if (guild_card_file_check == 1) {
                failed |= 0x200;
            }
            if (failed != 0) {
                return failed;
            }
        }
        absent = 0;
        if (sub_802E15C8() == 0) {
            absent |= 0x400;
        }
        if (is_card_file_absent_b() == 0) {
            absent |= 0x800;
        }
        if (is_card_file_absent_a() == 0) {
            absent |= 0x1000;
        }
        return absent;
    }
}

s32 TAdTimeSetGC::is_load_complete() {
    if (start_memcard_format(0, 0, 0, 0, 0) == 0) {
        return 1;
    }
    return 0;
}

s32 TAdTimeSetGC::sub_802E15C8() {
    return TAdPlayerLoadGC::find_card_file(0, pso_system_card_filename) == 0;
}

s32 TAdTimeSetGC::is_card_file_absent_b() {
    return TAdPlayerLoadGC::find_card_file(0, pso_character_card_filename.filename) == 0;
}

s32 TAdTimeSetGC::is_card_file_absent_a() {
    return TAdPlayerLoadGC::find_card_file(0, pso_guildcard_card_filename.filename) == 0;
}

s32 TAdTimeSetGC::sub_802E1528() {
    return TAdPlayerLoadGC::find_card_file(0, pso_system_card_filename) == -0xBF;
}

s32 TAdTimeSetGC::is_card_file_missing_b() {
    return TAdPlayerLoadGC::find_card_file(0, pso_character_card_filename.filename) == -0xBF;
}

s32 TAdTimeSetGC::is_card_file_missing_a() {
    return TAdPlayerLoadGC::find_card_file(0, pso_guildcard_card_filename.filename) == -0xBF;
}

T_ATS_DrawCalendar *T_ATS_DrawCalendar::create() {
    return new T_ATS_DrawCalendar(tl_clipout);
}

T_ATS_DrawCalendar::T_ATS_DrawCalendar(TObject *parent) : TObject(parent) {
    m_name = T_ATS_DrawCalendar__name;
    visible = 0;
    // The two-float copy at 0x80052EA0 is declared as a member of TWindowSubSymbolChatPartsSet.
    copy_vec2(&pos, (void *)time_set_calendar_pos);
}

T_ATS_DrawCalendar::~T_ATS_DrawCalendar() {
}

// render reaches each of its three format strings and the conversion constant 0x80472980 with a lis/addi of
// its own, while the static initialiser addresses the unit's .data from one base register.
#pragma pool_data off
void T_ATS_DrawCalendar::render() {
    char buf[0x24];
    DateStamp date;
    char *s;
    f32 w;
    s32 wd;

    if (visible != 0) {
        T_ATS_DrawCalendarPos p = pos;
        s = (char *)get_localized_text_entry(0x1C, 0xC);
        // The text drawing function at 0x80145778 is declared as a member of TAdSinglePlyChrSelectGC.
        draw_menu_font_string_white(s, -(0.5f * (f32)calc_text_width(s) - p.x), p.y);
        p.y += 30.0f;
        getDateStamp(&date);
        wd = date.weekday + 13;
        switch (current_language) {
        case LANGUAGE_JAPANESE:
            sprintf(buf, "%d/%02d/%02d %s", date.year, date.month, date.day, get_localized_text_entry(0x1C, wd));
            s = buf;
            w = -0.5f * (f32)calc_text_width(s);
            break;
        default:
            sprintf(buf, "%02d/%02d/%d %s", date.month, date.day, date.year, get_localized_text_entry(0x1C, wd));
            s = buf;
            w = -0.5f * (f32)calc_fullwidth_text_width(s);
            break;
        }
        draw_menu_font_string_white(s, p.x + w, p.y);
        p.y += 22.0f;
        sprintf(buf, "%02d:%02d:%02d", date.hour, date.minute, date.second);
        draw_menu_font_string_white(buf, -(0.5f * (f32)calc_text_width(buf) - p.x), p.y);
    }
}

#pragma pool_data reset

void T_ATS_DrawCalendar::enable_calendar_draw() {
    visible = 1;
}

void T_ATS_DrawCalendar::disable_calendar_draw() {
    visible = 0;
}
