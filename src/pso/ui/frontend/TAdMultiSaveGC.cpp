#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TScreenFadeOut.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/ProgressMessageWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/frontend/TAdMultiSaveGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
saddr get_message_text(s32 arg0);
saddr create_window_menu_default(const void *, int);
s32 verify_system_file__23TAdSinglePlyChrSelectGCFPv();
}

static const f32 TAdMultiSaveGC__data_80474D70[2] = { 80.0f, 176.0f };
static const f32 TAdMultiSaveGC__data_80474D78[2] = { 479.0f, 207.0f };
const char *TAdMultiSaveGC__name = "TAdMultiSaveGC";
static const f32 lbl_80474D90[2] = { 324.0f, 374.0f };

TAdMultiSaveGC::TAdMultiSaveGC(TObject *parent) : TObject(parent) {
    m_name = TAdMultiSaveGC__name;
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
            no_card_window = sub_802FF314();
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
            card_status_window = sub_802FF254();
            return;
        }
        break;
    case 2:
        save_ok = 1;
        if (verify_system_file__23TAdSinglePlyChrSelectGCFPv() == 0) {
            save_ok = 0;
        }
        if (TAdSinglePlyChrSelectGC::load_save_from_card() == 0) {
            save_ok = 0;
        }
        if (save_ok != 0) {
            m_state = 4U;
            return;
        }
        load_error_window = sub_802FF2B4();
        retry_menu = sub_802FF170();
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
        saving_window = sub_802FF1F4();
        m_state = 5U;
        return;
    case 5:
        if (TAdPlayerLoadGC::get_instance() == 0) {
            m_state = 6U;
            return;
        }
        break;
    case 6:
        TAdSinglePlyChrSelectGC__sub_801FDAAC();
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

TWindowMessage *TAdMultiSaveGC::sub_802FF314() {
    TWindowMessage *msg = (TWindowMessage *)(saddr)create_message_window_for_size((NJS_POINT2 *)TAdMultiSaveGC__data_80474D70, (NJS_POINT2 *)TAdMultiSaveGC__data_80474D78);
    msg->append_line(get_localized_text_entry(0x20, 0), 1);
    return msg;
}

TWindowMessage *TAdMultiSaveGC::sub_802FF2B4() {
    TWindowMessage *msg = (TWindowMessage *)(saddr)create_message_window_for_size((NJS_POINT2 *)TAdMultiSaveGC__data_80474D70, (NJS_POINT2 *)TAdMultiSaveGC__data_80474D78);
    msg->append_line(get_localized_text_entry(0x20, 3), 1);
    return msg;
}

TWindowMessage *TAdMultiSaveGC::sub_802FF254() {
    TWindowMessage *msg = (TWindowMessage *)(saddr)create_message_window_for_size((NJS_POINT2 *)TAdMultiSaveGC__data_80474D70, (NJS_POINT2 *)TAdMultiSaveGC__data_80474D78);
    msg->append_line(get_localized_text_entry(0x20, 3), 1);
    return msg;
}

TWindowMessage *TAdMultiSaveGC::sub_802FF1F4() {
    TWindowMessage *msg = (TWindowMessage *)(saddr)create_message_window_for_size((NJS_POINT2 *)TAdMultiSaveGC__data_80474D70, (NJS_POINT2 *)TAdMultiSaveGC__data_80474D78);
    msg->append_line(get_localized_text_entry(0x20, 2), 1);
    return msg;
}

TWindowSubComCardList *TAdMultiSaveGC::sub_802FF170() {
    TWindowSubComCardList *menu = (TWindowSubComCardList *)create_window_menu_default(lbl_80474D90, 2);
    menu->add_text_entry(get_message_text(0xD), 6, 0);
    menu->add_text_entry(get_message_text(0xE), 6, 1);
    menu->update_layout_height(289.0f);
    return menu;
}

// Fade callback (TScreenFadeOut): the fade passes itself, so this retires
// the fade before switching game mode.
void TAdMultiSaveGC::queue_destruction(TObject *fade) {
    fade->queue_destruction();
    TAdMultiChgGameModeGC::begin_change_game_mode();
}

void TAdMultiSaveGC::render() {
    if (TMainTask::get_render_pass() == 1) return;
}
