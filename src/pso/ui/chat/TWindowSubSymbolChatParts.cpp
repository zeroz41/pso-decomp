#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#include "types.h"
#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowBase.h"

#include <stddef.h>
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/chat/TWindowSubSymbolChatParts.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"

#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/SoundEffect.h"

#pragma push
#pragma readonly_strings on
const char *TWindowSubSymbolChatParts::class_name = "TWindowSubSymbolChatParts";
#pragma pop


// inferred: symbol_chat_parts_layout_entries, the layout table symbol_chat_parts_window_layout
// points at (three sprite parts).
struct SymbolChatPartsWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec[3];
};
SymbolChatPartsWindowLayout symbol_chat_parts_layout_entries = {
    3, 1,
    {
        {6, {89.0f, 14.0f}, {50.0f, 40.0f}, 178.0f, 168.0f, 0.4f, -1, &hud_texlist, 0xA, 4},
        {6, {14.0f, 14.0f}, {32.0f, 32.0f}, 0.0f, 192.0f, 0.5f, -1, &hud_texlist, 0xA, 4},
        {6, {94.0f, 14.0f}, {32.0f, 32.0f}, 128.0f, 208.0f, 0.6f, -1, &hud_texlist, 0xA, 4},
    },
};
WindowDescriptor symbol_chat_parts_window_layout = {
    {178.0f, 188.0f}, 50050.0f, &symbol_chat_parts_layout_entries, 0xC3,
};
struct Stack_80285274 {
    f32 sp8;
    f32 spC;
};



struct Part_80285314 {
    u8 pad0[0x8];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 f18;
    u8 pad1c[0x2C - 0x1C];
    s32 f2C;
    u8 pad30[0x34 - 0x30];
    s32 f34;
};

struct Slot_80285314 {
    s8 id;
    u8 pad1[2];
    u8 flags;
};

struct Chat_80285314 {
    u8 pad0[0x4];
    u16 slots[4];
    Slot_80285314 entries[1];
};

extern "C" {
void TWindowSubSymbolChatFaceType__sub_80283C84(void *, void *, f32, f32);
void setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(void *, void *, void *, u16, s32, s32, s32, s32);
}

#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatParts::update_row_count() {
    NJS_POINT2 extent;
    row_count = (s8) TWindowSubStatusDisp::round_away_from_zero((f32) item_count / 4.0f);
    extent.x = 170.0f;
    extent.y = (40.0f * (f32) row_count) + 18.0f;
    scrollbar->set_extent(&extent);
}
#pragma pop

void select_symbol_chat_slot(TWindowSubSymbolChatParts *parts) {
    s32 j;
    s32 i;
    s32 remaining;
    SymbolChatPreset *preset;
    i = parts->calc_symbol_index();
    preset = reinterpret_cast<SymbolChatPreset *>(TWindowSubSymbolChat::get_instance());
    remaining = TWindowSubSymbolChat::calc_remaining_slots();
    if (remaining > i) {
        ((TWindowSubSymbolChat *)preset)->remove_slot_shift_down(i);
        return;
    }
    i -= remaining;
    for (j = 0; j < 4; j += 1) {
        if (TWindowSubSymbolChat__sub_800771C4(preset, j) != 0) {
            if (i-- <= 0) {
                TWindowSubSymbolChat__sub_800771B0(preset, j);
                return;
            }
        }
    }
}

s32 TWindowSubSymbolChatParts::calc_symbol_index() {
    return (s8) this->cursor_col + ((s8) this->cursor_row * 4);
}

#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatParts::select_index_and_scroll(s32 symbol_index) {
    NJS_POINT2 v;

    if (symbol_index >= item_count) {
        symbol_index = item_count - 1;
    }
    cursor_row = symbol_index / 4;
    cursor_col = symbol_index % 4;
    scroll_offset[1] = 16.0f + (40.0f * (f32)(s8)cursor_row + 9.0f);
    scroll_offset[1] -= 81.0f;
    v.x = 0.0f;
    v.y = frame_size[1] - 10.0f - 16.0f;
    scrollbar->clamp_offset(scroll_offset, &v);
}
#pragma pop

void TWindowSubSymbolChatParts::handle_cancel() {
    if (this->sub_80283974() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_70 = (u8) (this->m_70 | 2);
    }
}

void TWindowSubSymbolChatParts::add_part() {
    s32 temp_r3;

    temp_r3 = this->calc_symbol_index();
    if (((s8) this->m_71 != 0) || (temp_r3 >= (s16) *(s16 *)&this->item_count) || (TWindowSubSymbolChat::count_instance_empty_slots() < 2)) {
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    }
    play_sound_effect(0x52D01, 0, 0, 0);
    *help = 1;
    this->m_70 = (u8) (this->m_70 | 1);
    this->heading->set_entry_state(2);
}

void TWindowSubSymbolChatParts::handle_add() {
    if (this->calc_symbol_index() >= (s16) *(s16 *)&this->item_count) {
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    }
    play_sound_effect(0x52D01, 0, 0, 0);
    this->m_70 = (u8) (this->m_70 | 1);
    this->heading->set_entry_state(2);
}

#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatParts::sub_80284FB8() {
    NJS_POINT2 v;
    f32 target = 16.0f + (40.0f * (f32)(s8)cursor_row + 9.0f);
    target -= 81.0f;
    scroll_offset[1] += target - scroll_offset[1];
    v.x = 0.0f;
    v.y = frame_size[1] - 10.0f - 16.0f;
    scrollbar->clamp_offset(scroll_offset, &v);
}
#pragma pop

void TWindowSubSymbolChatParts::sub_80285054() {
    u8 temp_r3;
    u8 temp_r3_2;
    u8 temp_r3_3;
    u8 temp_r4;
    u8 temp_r5;
    ControllerInputContext *input;
    input = &controller_input_state.controllers[0];
    if ((test_buttons_press_or_repeat(input, 0xF0, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0xF0, 6, 1) != 0)) {
        ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x54100, 0U, 0, 0);
        if ((test_buttons_press_or_repeat(input, 0x80, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x80, 6, 1) != 0)) {
            *(u8 *)((s8 *)(this) + 0x72) = (u8) (*(u8 *)((s8 *)(this) + 0x72) + 1);
        }
        if ((test_buttons_press_or_repeat(input, 0x40, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x40, 6, 1) != 0)) {
            *(u8 *)((s8 *)(this) + 0x72) = (u8) (*(u8 *)((s8 *)(this) + 0x72) - 1);
        }
        temp_r3 = *(u8 *)((s8 *)(this) + 0x72);
        if ((s8) temp_r3 < 0) {
            *(u8 *)((s8 *)(this) + 0x72) = (temp_r3 + 4);
        }
        temp_r3_2 = *(u8 *)((s8 *)(this) + 0x72);
        if ((s8) temp_r3_2 >= 4) {
            *(u8 *)((s8 *)(this) + 0x72) = (temp_r3_2 - 4);
        }
        if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
            *(u8 *)((s8 *)(this) + 0x73) = (u8) (*(u8 *)((s8 *)(this) + 0x73) - 1);
        }
        if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
            *(u8 *)((s8 *)(this) + 0x73) = (u8) (*(u8 *)((s8 *)(this) + 0x73) + 1);
        }
        temp_r3_3 = *(u8 *)((s8 *)(this) + 0x73);
        if ((s8) temp_r3_3 < 0) {
            *(u8 *)((s8 *)(this) + 0x73) = (u8) (temp_r3_3 + *(u8 *)((s8 *)(this) + 0x74));
        }
        temp_r4 = *(u8 *)((s8 *)(this) + 0x73);
        temp_r5 = *(u8 *)((s8 *)(this) + 0x74);
        if ((s8) temp_r4 >= (s8) temp_r5) {
            *(u8 *)((s8 *)(this) + 0x73) = (u8) (temp_r4 - temp_r5);
        }
    }
}

#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatParts::sub_80285274(u8 *ctx) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_80285274, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_80285274, spC) == 0x4);
    Stack_80285274 stack;
    stack.sp8 = ((40.0f * (f32) (s8) this->cursor_col) + 10.0f) - 3.0f;
    stack.spC = ((40.0f * (f32) (s8) this->cursor_row) + 9.0f) - 3.0f;
    TWindowSubSymbolChatFaceType__sub_80283C84(ctx, &stack.sp8, 38.0f, 0.1f);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatParts::draw_preset_parts(WindowDrawContext *ctx) {
    s32 n;
    s32 i;
    s32 col;
    s32 row;
    Part_80285314 *e1;
    Part_80285314 *e2;
    Part_80285314 *e0;
    Chat_80285314 *chat;
    Slot_80285314 *slot;
    u16 v;
    u8 flip;

    col = 0;
    row = 0;
    chat = (Chat_80285314 *)((u8 *)TWindowSubSymbolChat::get_instance() + 0x1C);
    e1 = (Part_80285314 *)get_array_entry(1);
    e2 = (Part_80285314 *)get_array_entry(2);
    e0 = (Part_80285314 *)get_array_entry(0);
    e1->f34 = 10;
    e1->f2C = -1;
    e0->f2C = -1;
    e0->w = 32.0f;
    e0->h = 32.0f;
    set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(e0), 185.0f, 22.0f);
    e0->f34 = 0;
    e0->f18 = 0.5f;
    ((TWindowSubStatusDisp *)e0)->clear_visible_flag();
    slot = chat->entries;
    n = TWindowSubSymbolChat::calc_remaining_slots();
    ((TWindowHelpItem *)e2)->set_flag0_bit2();
    for (i = 0; i < n; i++, slot++) {
        e0->x = 40.0f * (f32)col + 10.0f;
        e0->y = 40.0f * (f32)row + 9.0f;
        e1->x = 16.0f + e0->x;
        e1->y = 16.0f + e0->y;
        flip = slot->flags & 1;
        TWindowSubSymbolChatPartsSet::set_part_sprite(e1, slot->id, flip, (slot->flags >> 1) & 1);
        draw_visible_window_entries(this, &entry_list, ctx);
        if (++col >= 4) {
            col = 0;
            row++;
        }
    }
    i -= n;
    e0->f34 = 10;
    for (; i < 4; i++) {
        v = chat->slots[i];
        if ((u8)v != 0xFF) {
            e1->x = 40.0f * (f32)col + 10.0f;
            e1->y = 40.0f * (f32)row + 9.0f;
            setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(e1, e2, e0, (u8)v, (v >> 8) & 7, (v >> 11) & 1, (v >> 12) & 1, i);
            draw_visible_window_entries(this, &entry_list, ctx);
            if (++col >= 4) {
                col = 0;
                row++;
            }
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_propagation off
void TWindowSubSymbolChatParts::draw_part_choices(WindowDrawContext *ctx) {
    f32 sc;
    f32 y;
    f32 x;
    f32 hi;
    f32 off;
    s32 i;
    s32 row;
    f32 lo;
    f32 *a;
    f32 *b;
    f32 *c;
    int k;

    row = 0;
    a = (f32 *)get_array_entry(1);
    b = (f32 *)get_array_entry(2);
    c = (f32 *)get_array_entry(0);
    i = 0;
    lo = 8.0f;
    hi = 32.0f;
    sc = 40.0f;
    for (; i < item_count; row++) {
        off = sc * (f32)row;
        y = ctx->inner_y;
        y += off;
        if (lo + (hi + y) < ctx->clip_y0 || y - lo > ctx->clip_y1) {
            i += 4;
        } else {
            x = 9.0f + off;
            for (k = 0; k < 4; k++, i++) {
                if (i >= item_count) {
                    break;
                }
                a[2] = 40.0f * (f32)k + 10.0f;
                a[3] = x;
                setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(a, b, c, (u16)i, *selection, *m_7c, *m_80, 0);
                draw_visible_window_entries(this, &entry_list, ctx);
            }
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_propagation off

void TWindowSubSymbolChatParts::draw_part_icons(WindowDrawContext *ctx) {
    s32 i;
    s32 j;
    f32 *e0;
    s32 row;
    f32 *e1;
    f32 y;
    f32 off;
    f32 x;
    f32 h;
    row = 0;
    e1 = (f32 *)get_array_entry(1);
    e0 = (f32 *)get_array_entry(0);
    h = 32.0f;
    for (i = 0; i < item_count; row++) {
        off = 40.0f * (f32)row;
        y = ctx->inner_y;
        y = y + off;
        if (h + y < ctx->clip_y0 || y > ctx->clip_y1) {
            i += 4;
        } else {
            x = 9.0f + off;
            for (j = 0; j < 4; j++, i++) {
                if (i >= item_count) break;
                e0[2] = 40.0f * (f32)j + 10.0f;
                e0[3] = x;
                e1[2] = 16.0f + e0[2];
                e1[3] = 16.0f + e0[3];
                TWindowSubSymbolChatPartsSet::set_part_sprite(e1, (s16)i, *m_7c, *m_80);
                draw_visible_window_entries(this, &entry_list, ctx);
            }
        }
    }
}
#pragma pop

void TWindowSubSymbolChatParts::update_height() {
    item_count = TWindowSubSymbolChat::compute_total_height();
    update_row_count();
    m_71 = 2;
}

void TWindowSubSymbolChatParts::open(s8 *selected_value) {
    selection = selected_value;
    item_count = 0xC0;
    update_row_count();
    m_71 = 1;
}


void TWindowSubSymbolChatParts::init_help(s32 *help_value) {
    Part_80285314 *e2;
    Part_80285314 *e0;
    help = help_value;
    *help = 0;
    e2 = (Part_80285314 *)get_array_entry(2);
    e0 = (Part_80285314 *)get_array_entry(0);
    *(u16 *)e2 |= 2;
    set_sprite_dimensions(reinterpret_cast<WindowSpritePart *>(e0), 32.0f, 32.0f);
    set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(e0), 185.0f, 22.0f);
    e0->f34 = 0;
    item_count = 0x44;
    update_row_count();
    m_71 = 0;
}

void TWindowSubSymbolChatParts::render() {
    WindowDrawContext *ctx;

    ctx = get_draw_context();
    draw_window_frame(ctx);
    switch ((s8)m_71) {
    case 0:
        draw_part_icons(ctx);
        break;
    case 1:
        draw_part_choices(ctx);
        break;
    case 2:
        draw_preset_parts(ctx);
        break;
    }
    draw_window_scrollbar(scrollbar, ctx, scroll_offset);
    sub_80285274((u8 *)ctx);
    heading->forward_render(ctx);
}

void TWindowSubSymbolChatParts::run_task() {
    u8 *pad;

    if (!(window_flags & 2)) {
        open_tick = 0x01000000;
    }
    if (sub_80283974() == 0) {
        sub_80285054();
        pad = ((u8 *)&controller_input_state) + 0x20;
        if (test_pressed_buttons_packed(pad, 4) != 0 || (s32)test_controller_flag_4c_color(&(&controller_input_state)->keyboard, 4) != 0) {
            handle_add();
        }
        if (test_pressed_buttons_packed(pad, 0x400) != 0) {
            add_part();
        }
        if (test_pressed_buttons_packed(pad, 2) != 0 || (s32)test_controller_flag_4c_color(&(&controller_input_state)->keyboard, 2) != 0) {
            handle_cancel();
        }
    }
    sub_80284FB8();
    if ((f32)open_tick >= 7.5f) {
        heading->update_subwindow();
        scrollbar->increment_counter();
    }
    ((TWindowBase *)this)->update_window();
}

TWindowSubSymbolChatParts::~TWindowSubSymbolChatParts() {
    TWindowSubStatusDisp::destroy_allocation((saddr)scrollbar, (s16)1);
    TWindowSubStatusDisp::destroy_status_display((saddr)heading, (s16)1);
}

TWindowSubSymbolChatParts::TWindowSubSymbolChatParts(const NJS_POINT2 *position, s32 *arg2, s32 *arg3)
    : TWindowAddition((u8 *)&symbol_chat_parts_window_layout, 4, (u8 *)position) {
    NJS_POINT2 v;
    void *p;

    m_name = class_name;
    m_70 = 0;
    cursor_col = 0;
    cursor_row = 0;
    item_count = 0;
    m_7c = arg2;
    m_80 = arg3;
    p = ::operator new(0x24);
    if (p != NULL) {
        p = ((TWindowSubStatusDisp *)p)->construct_type1_heading((saddr)TWindowSubStatusDisp::get_message_10(0x33), client_index);
    }
    heading = (TWindowSubStatusDisp *)p;
    v.x = 0.0f;
    v.y = 0.0f;
    scrollbar = new WindowScrollBar(&v);
}
