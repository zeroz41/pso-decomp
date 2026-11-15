#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TUnk_804D0948.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowShortCut.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"
#include "pso/ui/chat/TWindowChatSymbol_802486A8.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/unk/text_80266BD0.h"
#include "pso/unk/TLobby_8026B06C.h"
#include "pso/unk/TLobby_8001D6A0.h"

struct RecoveredGlobal_8026E110_lbl_804D0948 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_8026E168_lbl_804D0948 {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, int);
s32 draw_item_list_capacity(void *, int, int, int);
s32 draw_window_scrollbar(void *, int, void *);
s32 forward_render__20TWindowSubStatusDispFv(void *, int);
u8 * fn_80268384(void *, s32, s32, s16, s32);
s32 sub_8026DE94__13TUnk_804D0948Fv(void *, void *);
extern s32 item_list_window_vtable[];
extern s32 local_client_id;
u8 * get_window_layout_position(s32);
u8 *fn_802683F4(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void __dl__7TObjectFPv(void *);
char *fn_80076BC4(s32 *);
void update_state__9TWindowDDFv(s32 *, s32 *, u16);
TWindowSubSymbolChat *open_symbol_chat__11TWindowChatFPl(s32 *);

#pragma push
#pragma fp_contract on
void TUnk_804D0948::render() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    s32 n;
    void *p;
    temp_r3 = get_draw_context__11TWindowBaseFPv();
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3);
    if (!(this->state_flags & 0x80)) {
        ((TWindowMenuIconLine *)arg0)->draw_selected_list_entry(temp_r3);
    }
    n = *(s32 *)&this->unk_88;
    if (n > 0) {
        draw_item_list_capacity(arg0, temp_r3, this->entry_count, n);
    }
    p = this->status_display;
    if (p != NULL) {
        forward_render__20TWindowSubStatusDispFv(p, temp_r3);
    }
    p = *(void * *)&this->unk_84;
    if (p != NULL) {
        draw_window_scrollbar(p, temp_r3, (u8 *)&this->m_68);
    }
}
#pragma pop

void TUnk_804D0948::run_task() { run_task__19TWindowMenuIconLineFv((u8 *)this); }

void *TWindowSubStatusDisp::deleting_dtor(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = item_list_window_vtable;
        destroy_item_list_resources(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
typedef char RecoveredGlobal_8026E110_lbl_804D0948_size[sizeof(RecoveredGlobal_8026E110_lbl_804D0948) == 0x20 ? 1 : -1];
u8 *TWindowSubStatusDisp::ct_helper(s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    fn_80268384(this, arg1, arg3, (s16) local_client_id, arg4);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_8026E110_lbl_804D0948 *)&item_list_window_vtable).value;
    sub_8026DE94__13TUnk_804D0948Fv(this, (void *)arg2);
    return ((u8 *)this);
}
typedef char RecoveredGlobal_8026E168_lbl_804D0948_size[sizeof(RecoveredGlobal_8026E168_lbl_804D0948) == 0x20 ? 1 : -1];
u8 *TWindowSubStatusDisp::construct_item_list(s32 arg1, s32 arg2, s16 arg3) {
    fn_802683F4((((u8 *)this)), (s32)(get_window_layout_position(0x26)), (arg2), (arg3));
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_8026E168_lbl_804D0948 *)&item_list_window_vtable).value;
    sub_8026DE94__13TUnk_804D0948Fv(this, (void *)arg1);
    return ((u8 *)this);
}

struct TextEntry {
    u16 flags;
    u8 unk_2[0xE];
    f32 width;
    f32 height;
};

struct Vec2f {
    f32 x;
    f32 y;
};

void measure_message_text_width(TextEntry *entry, f32 max_width);
void refresh_status_display__9TWindowDDFv(TextEntry *entry);

static const u8 chat_shortcut_icons[4] = {0x12, 0x10, 0x11, 0};

#pragma push
#pragma fp_contract on
#pragma opt_propagation off
void TWindowShortCut::sub_8026E1D4(s32 index, s32 *chat_shortcut) {
    u8 first_icon;
    u8 second_icon;
    Vec2f pos;
    s32 type;
    Vec2f size;

    TextEntry *title = (TextEntry *)this->get_array_entry(0);
    TextEntry *button_icon = (TextEntry *)this->get_array_entry(2);
    TextEntry *pad_icon = (TextEntry *)this->get_array_entry(3);
    TextEntry *type_label = (TextEntry *)this->get_array_entry(4);
    TextEntry *type_icon = (TextEntry *)this->get_array_entry(6);
    TextEntry *type_name = (TextEntry *)this->get_array_entry(7);
    TextEntry *text_label = (TextEntry *)this->get_array_entry(8);
    TextEntry *text = (TextEntry *)this->get_array_entry(10);

    type = chat_shortcut[0];
    set_text_entry_string((u8 *)title, (u32)TWindowSubStatusDisp::get_message_10(0xC4), 0);
    fn_80266BD0(index, &first_icon, &second_icon, this->m_20);
    if (first_icon != 0x33) {
        const Vec2f *uv = (const Vec2f *)TWindowSubStatusDisp::get_entry_ptr(first_icon);
        button_icon->flags &= ~2;
        set_sprite_uv_from_pixels((u8 *)button_icon, uv->x, uv->y);
    } else {
        button_icon->flags |= 2;
    }

    const Vec2f *pad_uv = (const Vec2f *)TWindowSubStatusDisp::get_entry_ptr(second_icon);
    set_sprite_uv_from_pixels((u8 *)pad_icon, pad_uv->x, pad_uv->y);
    set_text_entry_string((u8 *)type_label, (u32)TWindowSubStatusDisp::get_message_10(0xC5), 0);
    set_text_entry_string((u8 *)type_name, (u32)TWindowSubStatusDisp::get_message_10(0xC0 + type), 0);
    const s32 type_sprite = chat_shortcut_icons[type - 1];
    const Vec2f *type_uv = (const Vec2f *)TWindowSubStatusDisp::get_entry_ptr(type_sprite);
    set_sprite_uv_from_pixels((u8 *)type_icon, type_uv->x, type_uv->y);

    pos.x = 211.0f;
    pos.y = 380.0f;
    set_text_entry_string((u8 *)text_label, (u32)TWindowSubStatusDisp::get_message_10(0x35), 0);

    switch (type) {
    case 0:
        break;
    case 1: {
        char *message = fn_80076BC4(chat_shortcut + 1);
        set_text_entry_string((u8 *)text, (u32)message, 0);
        measure_message_text_width(text, 200.0f);
        text->flags |= 2;
        size.x = 0.1f + (8.0f + text->width);
        size.y = 3.0f + (20.0f + text->height);
        pos.x = TWindowSubStatusDisp::round_away_from_zero(pos.x - 0.5f * size.x);
        pos.y = TWindowSubStatusDisp::round_away_from_zero(pos.y - 0.5f * size.y);
        this->message_window = (TWindowBase *)create_quest_message_window_at((s32)&pos, (s32)&size);
        dispatch_message_window_text(this->message_window, (int)message, 0x402);
        this->message_window->set_depth(50060.0f);
        break;
    }
    case 2: {
        s32 *buffer = get_shared_text_buffer();
        const u16 player = (u16)local_client_id;
        s32 *words = chat_shortcut + 1;
        update_state__9TWindowDDFv(words, buffer, player);
        set_text_entry_string((u8 *)text, (u32)get_shared_text_buffer(), 0);
        refresh_status_display__9TWindowDDFv(text);
        text->flags |= 2;
        size.x = 0.1f + (8.0f + text->width);
        size.y = 3.0f + (20.0f + text->height);
        pos.x = TWindowSubStatusDisp::round_away_from_zero(pos.x - 0.5f * size.x);
        pos.y = TWindowSubStatusDisp::round_away_from_zero(pos.y - 0.5f * size.y);
        this->message_window = (TWindowBase *)create_quest_message_window_at((s32)&pos, (s32)&size);
        dispatch_message_window_text(this->message_window, (int)get_shared_text_buffer(), 2);
        this->message_window->set_depth(50060.0f);
        break;
    }
    case 3: {
        TWindowSubSymbolChat *preset = open_symbol_chat__11TWindowChatFPl(chat_shortcut + 1);
        set_text_entry_string((u8 *)text, (u32)preset->get_symbol_chat_data(), 0);
        f32 half;
        f32 height;
        f32 width;
        width = 203.0f;
        height = 78.0f;
        half = 0.5f;
        size.x = width;
        pos.x -= half * width;
        size.y = height;
        pos.y -= half * height;
        TWindowChatSymbol *window = (TWindowChatSymbol *)TObject::operator new(0x68);
        if (window != NULL) {
            window = (TWindowChatSymbol *)TWindowChatSymbol__ct(window, (s32)&pos, (s32)&size);
        }
        this->symbol_chat_window = window;
        ((TWindowSubSymbolChatPartsSet *)this->symbol_chat_window)->set_selection((u32)preset);
        this->symbol_chat_window->set_depth(50060.0f);
        break;
    }
    }
}
#pragma pop

}
