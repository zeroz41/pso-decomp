#include "types.h"
#include "pso/ui/window/TWindowMainMenu_80263AB0.h"
#include "pso/unk/text_80263A20.h"
#include "pso/ui/window/TWindowHelpItem_80255AB4.h"
#include "pso/ui/window/TWindowSubComCardList_8026CB08.h"
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
extern void *window_help_item_layout[];
extern "C" { extern char TWindowHelpItem__class_name_string[]; }
const char *window_help_item_class_name = TWindowHelpItem__class_name_string;
extern TWindowHelpItem::CallbackWords __ptmf_null;
void *init__21TWindowSubComCardListFiii(void *p, s32 a, s32 b, s32 c);

s32 handle_list_page_flip_input(s32);
s32 draw_visible_window_entries(void *, void *, int);
s32 draw_list_page_indicator(int, int);
s32 decay_page_arrow_offset(s32);

void TWindowHelpItem::update_cursor_selection() {
    this->m_60 = (u8) (this->m_60 | 1);
    if ((s32) this->m_a4 != -1) {
        this->m_68 = (s32) this->m_70;
        this->m_9c = (s32) this->m_a4;
        return;
    }
    if ((s32) this->m_a0 != -1) {
        this->m_68 = (s32) this->m_6c;
        this->m_9c = (s32) this->m_a0;
        return;
    }
    this->m_60 = (u8) (this->m_60 & 0xFE);
    this->m_68 = 0;
    this->m_9c = -1;
}

void TWindowHelpItem::render() {
    saddr temp_r3;
    u8 temp_r3_2;

    temp_r3 = this->setup_window_draw_context((f32 *)((u8 *)this + 0xA8));
    this->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(this, (u8 *)this + 0x24, temp_r3);
    temp_r3_2 = this->m_60;
    if ((temp_r3_2 & 1) && (temp_r3_2 & 2)) {
        draw_list_page_indicator((int) (this->m_64), temp_r3);
    }
}

void TWindowHelpItem::run_task() {
    u8 *arg0 = (u8 *)this;
    if (!(this->m_2c & 2)) {
        this->m_5c = 0x01000000;
    }
    if ((this->m_60 & 1) && (((TWindowBase *)arg0)->sub_80244994() != 0) && !(this->m_2c & 4)) {
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
    ((TWindowBase *)arg0)->update_window_entry_list((u8 *)&this->m_24);
    if (!(this->m_60 & 8)) {
        toggle_help_window_on_button((uaddr)arg0, this->m_20);
    }
}

TWindowHelpItem::~TWindowHelpItem() {
    delete_if_allocated(this->m_64, 1);
}

}
TWindowHelpItem::TWindowHelpItem(void *pos, u16 idx) : TWindowBase((u8 *)window_help_item_layout, (s16)idx, (u8 *)pos) {
    void *p;
    this->m_name = window_help_item_class_name;
    copy_vec2(((u8 *)this + 0x30), pos);
    this->save_position();
    this->m_60 = 0;
    p = ::operator new(0xc);
    if (p != 0) {
        p = init__21TWindowSubComCardListFiii(p, 0, 3, this->m_20);
    }
    this->m_64 = (uaddr)p;
    this->m_68 = 0;
    this->m_6c = 0;
    this->m_70 = 0;
    this->m_9c = -1;
    this->m_a0 = -1;
    this->m_a4 = -1;
    this->m_callback = __ptmf_null;
    this->m_a8 = 1.0f;
    this->m_ac = 1.0f;
    this->dispatch_item_help();
    call_if_split_screen((uaddr)this, this->m_20);
}

s32 get_help_text_string(s32 arg0) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x18)) + (arg0 * 4));
}

s32 TWindowHelpItem__sub_80255DDC(void* p) { return *(s32*)((char*)p + 0x1c); }
void TWindowHelpItem::set_flag0_bit20() { *(u16*)((char*)this + 0x0) |= 0x20; }
