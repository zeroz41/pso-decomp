#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/PageIndicator.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/system/task/TObject.h"
#include "pso/network/client_id.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/text_80076BC4.h"

const char *TWindowSubShortCutList__class_name = "TWindowSubShortCutList";
// Size argument of the shortcut list window.
static const NJS_POINT2 lbl_8044FAA8 = {405.0f, 188.0f};

extern "C" {
char *fn_80076BC4(s32 *);
s32 get_symbol_chat_data__20TWindowSubSymbolChatFv();

}

void TWindowSubShortCutList::refresh_entries() {
    s32 *chat_shortcut;
    s32 temp_r0;
    s32 i;
    s32 index;
    save_cursor_selection();
    reset_list();
    index = storage->get_type();
    i = 0;
    index *= 4;
    do {
        chat_shortcut = (s32 *)get_chat_shortcut(index);
        switch (*chat_shortcut) {
        case 0:
            draw_entry(index, 0x33, 0, index);
            break;
        case 1:
            temp_r0 = (saddr)fn_80076BC4(chat_shortcut + 1);
            draw_entry(index, 0x12, temp_r0, index);
            break;
        case 2:
            TWindowDD::format_message(reinterpret_cast<WordSelectMessage *>(chat_shortcut + 1), reinterpret_cast<char *>(get_shared_text_buffer()), (u16)local_client_id);
            draw_entry(index, 0x10, (saddr)get_shared_text_buffer(), index);
            break;
        case 3: {
            SymbolChatPreset *preset = TWindowChat::open_symbol_chat(chat_shortcut + 1);
            s32 d = (saddr)preset->get_symbol_chat_data();
            draw_entry(index, 0x11, d, index);
            break;
        }
        }
        i += 1;
        index += 1;
    } while (i < 4);
    clamp_selection_to_valid_entry();
}

TWindowSubShortCutList *TWindowSubShortCutList::create(const NJS_POINT2 *position, s32 index) {
    TShopJudgmentItemWindow__sub_80267F9C(&lbl_8044FAA8, 4);
    return new TWindowSubShortCutList(reinterpret_cast<u8 *>(const_cast<NJS_POINT2 *>(position)), index);
}

void TWindowSubShortCutList::render() {
    WindowDrawContext *context = get_draw_context();
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
    draw_selected_list_entry(context);
    if (status_display != NULL) {
        ((TWindowSubStatusDisp *)((void *)(status_display)))->forward_render((void *)(context));
    }
    if (storage != NULL) {
        draw_list_page_indicator(storage, context);
    }
}

void TWindowSubShortCutList::run_task() {
    TWindowMenuIconLine::run_task();
    if ((is_decided() == 0) && (handle_list_page_flip_input(this->storage) != 0)) {
        refresh_entries();
    }
}

TWindowSubShortCutList::~TWindowSubShortCutList() {
    delete_if_allocated(storage, 1);
}
// index: the shortcut slot; its page (index / 4) picks the list page, its column the cursor.
TWindowSubShortCutList::TWindowSubShortCutList(u8 *parent, s32 index)
    : TWindowMenuIconLine(parent, 4, local_client_id) {
    s32 row;
    s32 col;
    m_name = TWindowSubShortCutList__class_name;
    row = index / 4;
    col = index % 4;
    ensure_status_display((saddr)(TWindowSubStatusDisp::get_message_10(0x2D)));
    storage = new PageIndicator((s8)row, 5, local_client_id);
    set_flag70_bit10();
    refresh_entries();
    set_cursor_index(col);
}
