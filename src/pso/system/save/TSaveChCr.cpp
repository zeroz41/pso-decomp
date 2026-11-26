#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/save/CardSaveFile.h"
#include "pso/system/save/CardFileInfo.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/system/save/TSaveChCr.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/charcreate/CreationInput.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/ProgressMessageWindow.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"

#include <stddef.h>
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


extern TSaveChCrStateActions save_chcr_state_actions[];

#pragma readonly_strings on
const char *TSaveChCr::name = "TSaveChCr";

// Message window position and size passed to the window create in open_message_window.
static const NJS_POINT2 save_ch_cr_message_window_pos = {46.0f, 131.0f};
static const NJS_POINT2 save_ch_cr_message_window_size = {548.0f, 220.0f};

// Text group and entry of each message set_message_by_index shows.
struct SaveChCrMessageText {
    s32 group;
    s32 entry;
};

extern "C" {
extern void *tl_03;
}

void TSaveChCr::destroy_if_keyboard_idle() { if (this->timer == 0) { queue_destruction(); request_queued_main_phase(); } }
void TSaveChCr::enter_close_state() { close_window(); }
void TSaveChCr::save_if_dirty() { if (is_confirm_pressed() != 0) { set_state(4); } }
void TSaveChCr::close_and_advance_to_3() { close_and_advance(3); }
void TSaveChCr::update_save_status() {
    s32 result;

    if ((s32) this->timer <= 0) {
        this->status_checked = 0;
        this->card_status = poll_memcard_status();
        if ((s32) this->card_status != 0) {
            set_state(1);
            return;
        }
        if (this->mode == 0) {
            result = save_character();
        } else {
            result = load_card_character();
        }
        if (result == 7) {
            set_state(4);
            return;
        }
        queue_destruction();
        request_main_phase(9);
    }
}
void TSaveChCr::close_and_advance_step2() { close_and_advance(2); }
void TSaveChCr::update_saving() {}
void TSaveChCr::save_1() { close_and_advance(1); }
void TSaveChCr::update_save_state() {
    s32 card_status;

    card_status = this->card_status;
    if (!(card_status & 2)) {
        if (card_status & 1) {
            if (owned_window == NULL) {
                close_and_advance(0);
            }
        } else {
            if (card_status & 4) {
                set_state(1);
                return;
            }
            if (card_status == 0) {
                set_state(2);
            }
        }
    }
}
void TSaveChCr::enter_check_state() {
    close_window();
    if (card_status & 1) {
        close_and_advance(0);
    }
}
s32 TSaveChCr::has_no_save_files() {
    if ((TAdPlayerLoadGC::find_card_file(0, pso_system_card_filename) != 0) || (TAdPlayerLoadGC::find_card_file(0, pso_character_card_filename.filename) != 0) || (TAdPlayerLoadGC::find_card_file(0, pso_guildcard_card_filename.filename) != 0)) {
        return 0;
    }
    return 1;
}

s32 TSaveChCr::poll_memcard_status() {
    s32 status;

    if (TAdPlayerLoadGC::probe_card_slot(0) == 0) {
        this->status_checked = 0;
        return 1;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(0) == 0) {
        this->status_checked = 0;
        return 4;
    }
    if (poll_memcard_result(0) != 0) {
        this->read_fail_count = (this->read_fail_count + 1);
        this->status_checked = 0;
        return 2;
    }
    this->read_fail_count = 0;
    if (TAdPlayerLoadGC::check_memcard_status(0) != 0) {
        this->status_checked = 0;
        return 4;
    }
    if ((s32) this->status_checked != 0) {
        return this->card_status;
    }
    status = 0;
    this->status_checked = 1;
    if (TAdSinglePlyChrSelectGC::poll_memcard_status() == 0) {
        status |= 4;
    }
    if (has_no_save_files() == 0) {
        status |= 4;
    }
    return status;
}

s32 TSaveChCr::is_confirm_pressed() {
    return creation_buttons_pressed(4) ? 1 : 0;
}

void TSaveChCr::close_and_advance(s32 message) {
    close_window();
    set_message_by_index(message);
}
void TSaveChCr::set_message_by_index(s32 message) {
    SaveChCrMessageText texts[4] = {{0x20, 0}, {0xB, 0x62}, {0xB, 0xC}, {0xB, 0xB}};
    SaveChCrMessageText *text = &texts[message];
    open_message_window((u32)get_localized_text_entry(text->group, text->entry));
}
void TSaveChCr::open_message_window(u32 text) {
    if ((uaddr) this->owned_window == 0U) {
        *(u32 *)&this->owned_window = (uaddr)create_message_window_for_size((NJS_POINT2 *)&save_ch_cr_message_window_pos, (NJS_POINT2 *)&save_ch_cr_message_window_size);
        if ((uaddr) this->owned_window != 0U) {
            if (text != 0U) {
                owned_window->append_line(text, 3);
            }
            owned_window->complete_reveal();
        }
    }
}

void TSaveChCr::close_window() {
    if (owned_window != NULL) {
        owned_window->close();
        owned_window = NULL;
        this->timer = 7;
    }
}

void TSaveChCr::create_backgrounds() {
    backdrop = new TAdBackGC(this);
    backdrop_text = new TAdBackTxtGC(this);
}

s32 TSaveChCr::load_card_character() { return TAdSinglePlyChrSelectGC::load_character_from_card(0); }
s32 TSaveChCr::save_character() {
    TObjPlayer::begin_action_from_char_select();
    return TAdSinglePlyChrSelectGC::load_character_from_card(1);
}

void TSaveChCr::set_state(s32 next_state) {
    if (state_index != next_state) {
        state_index = next_state;
        TSaveChCrStateAction action = save_chcr_state_actions[state_index].first;
        if (action != NULL) {
            (this->*action)();
        }
    }
}

#pragma opt_common_subs off
void TSaveChCr::run_task() {
  TSaveChCrStateActions *entry;
  TChCrCharSelect::reset_proportions();
  card_status = poll_memcard_status();
  if (card_status & 1)
  {
    set_state(0);
  }
  entry = &save_chcr_state_actions[state_index];
  TSaveChCrStateAction action = (*entry).task;
  if (action != 0)
  {
    (this->*action)();
  }
  --timer;
  if (timer < 0)
  {
    timer = 0;
  }
}
#pragma opt_common_subs reset

TSaveChCr::~TSaveChCr() {
    if (owned_window != NULL) {
        delete owned_window;
        owned_window = NULL;
    }
}

TSaveChCr::TSaveChCr(TObject *parent, s32 mode) : TObject(parent) {
    m_name = TSaveChCr::name;
    this->mode = mode;
    read_fail_count = 0;
    status_checked = 0;
    card_status = poll_memcard_status();
    owned_window = NULL;
    timer = 0;
    create_backgrounds();
    set_state(0);
}

TSaveChCr *TSaveChCr::create(s32 mode) {
    return new TSaveChCr((TObject *)tl_03, mode);
}

// Per-state actions of TSaveChCr: the first runs when set_state enters the
// state, the task runs every frame from run_task.
TSaveChCrStateActions save_chcr_state_actions[5] = {
    {&TSaveChCr::enter_check_state, &TSaveChCr::update_save_state},
    {&TSaveChCr::save_1, &TSaveChCr::update_saving},
    {&TSaveChCr::close_and_advance_step2, &TSaveChCr::update_save_status},
    {&TSaveChCr::close_and_advance_to_3, &TSaveChCr::save_if_dirty},
    {&TSaveChCr::enter_close_state, &TSaveChCr::destroy_if_keyboard_idle},
};
