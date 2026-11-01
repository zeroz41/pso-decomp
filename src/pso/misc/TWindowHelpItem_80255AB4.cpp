#include "types.h"
#include "pso/unk/text_80263A20.h"
#include "pso/misc/TWindowHelpItem_80255AB4.h"
#include "pso/misc/TWindowSubComCardList_8026CB08.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubMag.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/TWindowInputNumber.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
extern u8 *text_language_group_table;
extern void *__vt__15TWindowHelpItem[];
extern s32 TWindowHelpItem__object_vtable[];
extern u32 window_help_item_class_name;
extern TWindowHelpItem::CallbackWords __ptmf_null;
extern const f32 lbl_805DCE10;
void *init__21TWindowSubComCardListFiii(void *p, s32 a, s32 b, s32 c);
void call_if_split_screen(void *self, s32 idx);

s32 handle_list_page_flip_input(s32);
s32 draw_visible_window_entries(void *, void *, int);
s32 draw_list_page_indicator(int, int);
void __dl__7TObjectFPv(void *);
void destroy_window_base__9TWindowDDFs(void *, int);
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

void TWindowHelpItem__sub_80255B20(u8 *arg0) {
    s32 temp_r3;
    u8 temp_r3_2;

    temp_r3 = ((TWindowBase *)arg0)->setup_window_draw_context((s32)(arg0 + 0xA8));
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3);
    temp_r3_2 = ((TWindowHelpItem *)arg0)->m_60;
    if ((temp_r3_2 & 1) && (temp_r3_2 & 2)) {
        draw_list_page_indicator((int) (((TWindowHelpItem *)arg0)->m_64), temp_r3);
    }
}

void TWindowHelpItem::update_display() {
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
        toggle_help_window_on_button((u32)arg0, this->m_20);
    }
}

void *TWindowHelpItem::dt(s16 arg1) {
    if (this != NULL) {
        this->m_vtable18 = TWindowHelpItem__object_vtable;
        delete_if_allocated(this->m_64, 1);
        destroy_window_base__9TWindowDDFs(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}
TWindowHelpItem::TWindowHelpItem(void *pos, u16 idx) {
    TWindowHelpItem *self = this;
    void *p;
    ((TWindowDD *)self)->construct_base((u8 *)__vt__15TWindowHelpItem, (s16)idx, (u8 *)pos);
    self->m_vtable18 = ((s32 *)&TWindowHelpItem__object_vtable);
    self->m_00 = window_help_item_class_name;
    ((TWindowSubSymbolChatPartsSet *)((u8 *)self + 0x30))->copy_vec2(pos);
    ((TWindowBase *)self)->save_position();
    self->m_60 = 0;
    p = ::operator new(0xc);
    if (p != 0) {
        p = init__21TWindowSubComCardListFiii(p, 0, 3, self->m_20);
    }
    self->m_64 = (u32)p;
    self->m_68 = 0;
    self->m_6c = 0;
    self->m_70 = 0;
    self->m_9c = -1;
    self->m_a0 = -1;
    self->m_a4 = -1;
    self->m_callback = __ptmf_null;
    self->m_a8 = lbl_805DCE10;
    self->m_ac = lbl_805DCE10;
    ((TWindowHelpItem *)self)->dispatch_item_help();
    call_if_split_screen(self, self->m_20);
}

s32 get_help_text_string(s32 arg0) {
    return *(s32 *)((s8 *)(*(s32 *)((s8 *)text_language_group_table + 0x18)) + (arg0 * 4));
}

s32 TWindowHelpItem__sub_80255DDC(void* p) { return *(s32*)((char*)p + 0x1c); }
void TWindowHelpItem::set_flag0_bit20() { *(u16*)((char*)this + 0x0) |= 0x20; }
