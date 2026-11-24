#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/TWindowMainMenu_80263AB0.h"
#include "pso/unk/text_80263A20.h"
#include "pso/ui/window/TWindowHelpItem_80255AB4.h"
#include "pso/ui/window/PageIndicator.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/system/vector.h"


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
extern u8 *text_language_group_table;
extern WindowDescriptor window_help_item_layout;
extern "C" { extern char TWindowHelpItem__class_name_string[]; }
const char *window_help_item_class_name = TWindowHelpItem__class_name_string;
extern TWindowHelpItem::CallbackWords __ptmf_null;


void TWindowHelpItem::update_cursor_selection() {
    this->m_60 = (u8) (this->m_60 | 1);
    if ((s32) this->m_a4 != -1) {
        active_item = reinterpret_cast<TItemData *>(m_70);
        this->m_9c = (s32) this->m_a4;
        return;
    }
    if ((s32) this->m_a0 != -1) {
        active_item = reinterpret_cast<TItemData *>(m_6c);
        this->m_9c = (s32) this->m_a0;
        return;
    }
    this->m_60 = (u8) (this->m_60 & 0xFE);
    active_item = NULL;
    this->m_9c = -1;
}

void TWindowHelpItem::render() {
    saddr context;
    u8 temp_r3_2;

    context = reinterpret_cast<saddr>(this->setup_window_draw_context((f32 *)((u8 *)this + 0xA8)));
    this->draw_window_frame((void *)context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>((u8 *)this + 0x24),
        reinterpret_cast<WindowDrawContext *>(context));
    temp_r3_2 = this->m_60;
    if ((temp_r3_2 & 1) && (temp_r3_2 & 2)) {
        draw_list_page_indicator(m_64, reinterpret_cast<WindowDrawContext *>(context));
    }
}

void TWindowHelpItem::run_task() {
    u8 *arg0 = (u8 *)this;
    if (!(this->window_flags & 2)) {
        this->open_tick = 0x01000000;
    }
    if ((this->m_60 & 1) && (((TWindowBase *)arg0)->sub_80244994() != 0) && !(this->window_flags & 4)) {
        if (!(this->m_60 & 4)) {
            if (handle_list_page_flip_input(this->m_64) != 0) {
                ((TWindowHelpItem *)arg0)->dispatch_item_help();
            }
        } else {
            decay_page_arrow_offset(this->m_64);
        }
        ((TWindowHelpItem *)arg0)->invoke_callback_pmf();
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
    if (!(this->m_60 & 8)) {
        toggle_help_window_on_button((uaddr)arg0, this->client_index);
    }
}

TWindowHelpItem::~TWindowHelpItem() {
    delete_if_allocated(this->m_64, 1);
}

}
TWindowHelpItem::TWindowHelpItem(void *pos, s32 idx) : TWindowBase((u8 *)&window_help_item_layout, (s16)idx, (u8 *)pos) {
    this->m_name = window_help_item_class_name;
    copy_vec2(((u8 *)this + 0x30), pos);
    this->save_position();
    this->m_60 = 0;
    m_64 = new PageIndicator(0, 3, client_index);
    active_item = NULL;
    this->m_6c = 0;
    this->m_70 = 0;
    this->m_9c = -1;
    this->m_a0 = -1;
    this->m_a4 = -1;
    this->m_callback = __ptmf_null;
    this->scale_x = 1.0f;
    this->scale_y = 1.0f;
    this->dispatch_item_help();
    call_if_split_screen((uaddr)this, this->client_index);
}

s32 get_help_text_string(s32 id) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x18)) + (id * 4));
}

s32 TWindowHelpItem__sub_80255DDC(void* p) { return *(s32*)((char*)p + 0x1c); }
void TWindowHelpItem::set_flag0_bit20() { *(u16*)((char*)this + 0x0) |= 0x20; }
