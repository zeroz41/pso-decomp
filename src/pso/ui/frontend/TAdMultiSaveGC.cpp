#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/TScreenFadeOut.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/frontend/TAdMultiSaveGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TObjBagWarnWin.h"


static const f32 save_message_window_pos[2] = { 80.0f, 176.0f };
static const f32 save_message_window_size[2] = { 479.0f, 207.0f };
const char *TAdMultiSaveGC::class_name = "TAdMultiSaveGC";
static const NJS_POINT2 save_menu_pos = { 324.0f, 374.0f };

TAdMultiSaveGC::TAdMultiSaveGC(TObject *parent) : TObject(parent) {
    m_name = TAdMultiSaveGC::class_name;
    m_state = 0;
    no_card_window = NULL;
    card_status_window = NULL;
    saving_window = NULL;
    load_error_window = NULL;
    retry_menu = NULL;
    void *o = new TAdBackGC(this);
    void *o2 = new TAdBackTxtGC(this);
    TAdSinglePlyChrSelectGC::copy_chr_slots_from_request();
}

TAdMultiSaveGC::~TAdMultiSaveGC() {
    if (no_card_window != NULL) { no_card_window->queue_destruction(); no_card_window = NULL; }
    if (card_status_window != NULL) { card_status_window->queue_destruction(); card_status_window = NULL; }
    if (load_error_window != NULL) { load_error_window->queue_destruction(); load_error_window = NULL; }
    if (saving_window != NULL) { saving_window->queue_destruction(); saving_window = NULL; }
    if (retry_menu != NULL) { retry_menu->queue_destruction(); retry_menu = NULL; }
}

void TAdMultiSaveGC::run_task() {
    s32 selected_menu_value;
    s32 save_ok;
    if (TAdPlayerLoadGC::probe_card_slot(0) == 0) {
        m_state = 0U;
    }
    switch (m_state) {
    case 0:
        if (card_status_window != NULL) {
            card_status_window->close();
            card_status_window = NULL;
        }
        if (saving_window != NULL) {
            saving_window->close();
            saving_window = NULL;
        }
        if (load_error_window != NULL) {
            load_error_window->close();
            load_error_window = NULL;
        }
        if (retry_menu != NULL) {
            retry_menu->close();
            retry_menu = NULL;
        }
        if (TAdPlayerLoadGC::probe_card_slot(0) != 0) {
            m_state = 1U;
            return;
        }
        if (no_card_window == NULL) {
            no_card_window = create_no_card_message();
        }
        break;
    case 1:
        if (no_card_window != NULL) {
            no_card_window->close();
            no_card_window = NULL;
        }
        if (TAdPlayerLoadGC::check_memcard_status(0) == 0) {
            m_state = 2U;
            return;
        }
        if (card_status_window == NULL) {
            card_status_window = create_card_status_message();
            return;
        }
        break;
    case 2:
        save_ok = 1;
        if (TAdSinglePlyChrSelectGC::verify_system_file() == 0) {
            save_ok = 0;
        }
        if (TAdSinglePlyChrSelectGC::load_save_from_card() == 0) {
            save_ok = 0;
        }
        if (save_ok != 0) {
            m_state = 4U;
            return;
        }
        load_error_window = create_load_error_message();
        retry_menu = create_save_or_exit_menu();
        m_state = 3U;
        return;
    case 3:
        if (retry_menu->is_decided() != 0) {
            selected_menu_value = retry_menu->get_selected_value();
            switch (selected_menu_value) {
            case 1:
                m_state = 8U;
                return;
            case 0:
                m_state = 0U;
                return;
            }
        }
        break;
    case 4:
        TAdSinglePlyChrSelectGC::write_encrypted_save();
        saving_window = create_saving_message();
        m_state = 5U;
        return;
    case 5:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            m_state = 6U;
            return;
        }
        break;
    case 6:
        begin_character_card_save();
        m_state = 7U;
        return;
    case 7:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            if (saving_window != NULL) {
                saving_window->close();
                saving_window = NULL;
            }
            m_state = 8U;
            return;
        }
        break;
    case 8:
        {
            new TScreenFadeOut(tl_fade, TAdMultiSaveGC::queue_destruction);
        }
        break;
    case 9:
        break;
    }
}

TWindowMessage *TAdMultiSaveGC::create_no_card_message() {
    TWindowMessage *msg = create_message_window_for_size((NJS_POINT2 *)save_message_window_pos, (NJS_POINT2 *)save_message_window_size);
    msg->append_line(get_localized_text_entry(0x20, 0), 1);
    return msg;
}

TWindowMessage *TAdMultiSaveGC::create_load_error_message() {
    TWindowMessage *msg = create_message_window_for_size((NJS_POINT2 *)save_message_window_pos, (NJS_POINT2 *)save_message_window_size);
    msg->append_line(get_localized_text_entry(0x20, 3), 1);
    return msg;
}

TWindowMessage *TAdMultiSaveGC::create_card_status_message() {
    TWindowMessage *msg = create_message_window_for_size((NJS_POINT2 *)save_message_window_pos, (NJS_POINT2 *)save_message_window_size);
    msg->append_line(get_localized_text_entry(0x20, 3), 1);
    return msg;
}

TWindowMessage *TAdMultiSaveGC::create_saving_message() {
    TWindowMessage *msg = create_message_window_for_size((NJS_POINT2 *)save_message_window_pos, (NJS_POINT2 *)save_message_window_size);
    msg->append_line(get_localized_text_entry(0x20, 2), 1);
    return msg;
}

TWindowSubComCardList *TAdMultiSaveGC::create_save_or_exit_menu() {
    TWindowSubComCardList *menu = (TWindowSubComCardList *)create_window_menu_default(&save_menu_pos, 2);
    menu->add_text_entry(get_message_text(0xD), 6, 0);
    menu->add_text_entry(get_message_text(0xE), 6, 1);
    menu->update_layout_height(289.0f);
    return menu;
}

// Fade callback (TScreenFadeOut): the fade passes itself, so this retires
// the fade before switching game mode.
void TAdMultiSaveGC::queue_destruction(TObject *fade) {
    fade->queue_destruction();
    TAdMultiChgGameModeGC::open_multi_chg_game_mode_scene();
}

void TAdMultiSaveGC::render() {
    if (TMainTask::get_render_pass() == 1) return;
}
