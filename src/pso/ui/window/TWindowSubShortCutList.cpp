#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/PageIndicator.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/system/task/TObject.h"
#include "pso/network/client_id.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/text_80076BC4.h"

const char *TWindowSubShortCutList__class_name = "TWindowSubShortCutList";
// Size argument of the shortcut list window.
static const f32 lbl_8044FAA8[2] = {405.0f, 188.0f};

extern "C" {
void TShopJudgmentItemWindow__sub_80267F9C(void *, int);
char *fn_80076BC4(s32 *);
s32 get_symbol_chat_data__20TWindowSubSymbolChatFv();

}

void TWindowSubShortCutList::refresh_entries() {
    s32 *chat_shortcut;
    s32 temp_r0;
    s32 var_r30;
    s32 index;
    ((TShopArmorListWindow *)this)->save_cursor_selection();
    reset_list();
    index = m_88->get_type();
    var_r30 = 0;
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
            TWindowDD::format_message(chat_shortcut + 1, (void *)get_shared_text_buffer(), (u16) local_client_id);
            draw_entry(index, 0x10, (saddr)get_shared_text_buffer(), index);
            break;
        case 3:
            TWindowChat::open_symbol_chat(chat_shortcut + 1);
            {
                s32 d = get_symbol_chat_data__20TWindowSubSymbolChatFv();
                draw_entry(index, 0x11, d, index);
            }
            break;
        }
        var_r30 += 1;
        index += 1;
    } while (var_r30 < 4);
    ((TShopArmorListWindow *)this)->clamp_selection_to_valid_entry();
}

void *TWindowSubShortCutList::create(void *index) {
    TShopJudgmentItemWindow__sub_80267F9C((void *)lbl_8044FAA8, 4);
    return new TWindowSubShortCutList((u8 *)this, (saddr)index);
}

void TWindowSubShortCutList::render() {
    saddr context;

    context = reinterpret_cast<saddr>(get_draw_context());
    draw_window_frame((void *)context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>((u8 *)this + 0x24),
        reinterpret_cast<WindowDrawContext *>(context));
    draw_selected_list_entry(context);
    if (status_display != NULL) {
        ((TWindowSubStatusDisp *)((void *)(status_display)))->forward_render((void *)(context));
    }
    if (m_88 != NULL) {
        draw_list_page_indicator(m_88, reinterpret_cast<WindowDrawContext *>(context));
    }
}

void TWindowSubShortCutList::run_task() {
    TWindowMenuIconLine::run_task();
    if ((is_decided() == 0) && (handle_list_page_flip_input(this->m_88) != 0)) {
        refresh_entries();
    }
}

TWindowSubShortCutList::~TWindowSubShortCutList() {
    delete_if_allocated(m_88, 1);
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
    m_88 = new PageIndicator((s8)row, 5, local_client_id);
    set_flag70_bit10();
    refresh_entries();
    set_cursor_index(col);
}
