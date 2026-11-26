#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/math/FloatRound.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#include "types.h"
#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"

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



extern "C" {
void draw_selection_corners(void *, void *, f32, f32);
}

#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatParts::update_row_count() {
    NJS_POINT2 extent;
    row_count = (s8) round_away_from_zero((f32) item_count / 4.0f);
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
        preset->remove_slot_shift_down(i);
        return;
    }
    i -= remaining;
    for (j = 0; j < 4; j += 1) {
        if (is_facial_part_set(preset, j) != 0) {
            if (i-- <= 0) {
                clear_facial_part(preset, j);
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
    if (this->is_confirmed() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->result_flags = (u8) (this->result_flags | 2);
    }
}

void TWindowSubSymbolChatParts::add_part() {
    s32 symbol_index;

    symbol_index = this->calc_symbol_index();
    if (((s8) this->view_mode != 0) || (symbol_index >= (s16) *(s16 *)&this->item_count) || (TWindowSubSymbolChat::count_instance_empty_slots() < 2)) {
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    }
    play_sound_effect(0x52D01, 0, 0, 0);
    *help = 1;
    this->result_flags = (u8) (this->result_flags | 1);
    this->heading->set_state(2);
}

void TWindowSubSymbolChatParts::handle_add() {
    if (this->calc_symbol_index() >= (s16) *(s16 *)&this->item_count) {
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    }
    play_sound_effect(0x52D01, 0, 0, 0);
    this->result_flags = (u8) (this->result_flags | 1);
    this->heading->set_state(2);
}

#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatParts::scroll_to_cursor_row() {
    NJS_POINT2 v;
    f32 target = 16.0f + (40.0f * (f32)(s8)cursor_row + 9.0f);
    target -= 81.0f;
    scroll_offset[1] += target - scroll_offset[1];
    v.x = 0.0f;
    v.y = frame_size[1] - 10.0f - 16.0f;
    scrollbar->clamp_offset(scroll_offset, &v);
}
#pragma pop

void TWindowSubSymbolChatParts::update_cursor_input() {
    u8 col;
    u8 col_now;
    u8 row;
    u8 row_now;
    u8 rows;
    ControllerInputContext *input;
    input = &controller_input_state.controllers[0];
    if ((test_buttons_press_or_repeat(input, 0xF0, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0xF0, 6, 1) != 0)) {
        play_sound_effect(0x54100, 0, 0, 0);
        if ((test_buttons_press_or_repeat(input, 0x80, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x80, 6, 1) != 0)) {
            cursor_col = (u8) (cursor_col + 1);
        }
        if ((test_buttons_press_or_repeat(input, 0x40, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x40, 6, 1) != 0)) {
            cursor_col = (u8) (cursor_col - 1);
        }
        col = cursor_col;
        if ((s8) col < 0) {
            cursor_col = (col + 4);
        }
        col_now = cursor_col;
        if ((s8) col_now >= 4) {
            cursor_col = (col_now - 4);
        }
        if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
            cursor_row = (u8) (cursor_row - 1);
        }
        if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
            cursor_row = (u8) (cursor_row + 1);
        }
        row = cursor_row;
        if ((s8) row < 0) {
            cursor_row = (u8) (row + *(u8 *)&row_count);
        }
        row_now = cursor_row;
        rows = *(u8 *)&row_count;
        if ((s8) row_now >= (s8) rows) {
            cursor_row = (u8) (row_now - rows);
        }
    }
}

#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatParts::draw_selected_cursor(u8 *ctx) {
    NJS_POINT2 corner;
    corner.x = ((40.0f * (f32) (s8) this->cursor_col) + 10.0f) - 3.0f;
    corner.y = ((40.0f * (f32) (s8) this->cursor_row) + 9.0f) - 3.0f;
    draw_selection_corners(ctx, &corner, 38.0f, 0.1f);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowSubSymbolChatParts::draw_preset_parts(WindowDrawContext *ctx) {
    s32 n;
    s32 i;
    s32 col;
    s32 row;
    WindowSpritePart *e1;
    WindowSpritePart *e2;
    WindowSpritePart *e0;
    SymbolChatPayload *chat;
    SymbolChatPart *slot;
    u16 v;
    u8 flip;

    col = 0;
    row = 0;
    chat = &reinterpret_cast<SymbolChatPreset *>(TWindowSubSymbolChat::get_instance())->payload;
    e1 = (WindowSpritePart *)get_array_entry(1);
    e2 = (WindowSpritePart *)get_array_entry(2);
    e0 = (WindowSpritePart *)get_array_entry(0);
    e1->kind = 10;
    e1->color = -1;
    e0->color = -1;
    e0->w = 32.0f;
    e0->h = 32.0f;
    set_sprite_uv_from_pixels(e0, 185.0f, 22.0f);
    e0->kind = 0;
    e0->depth = 0.5f;
    ((TWindowLayoutEntry *)e0)->show();
    slot = chat->parts;
    n = TWindowSubSymbolChat::calc_remaining_slots();
    ((TWindowLayoutEntry *)e2)->hide();
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
    e0->kind = 10;
    for (; i < 4; i++) {
        v = chat->facial_parts[i];
        if ((u8)v != 0xFF) {
            e1->x = 40.0f * (f32)col + 10.0f;
            e1->y = 40.0f * (f32)row + 9.0f;
            TWindowSubSymbolChatPartsSet::setup_part_sprites(e1, e2, e0, (u8)v, (v >> 8) & 7, (v >> 11) & 1, (v >> 12) & 1, i);
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
    WindowSpritePart *a;
    WindowSpritePart *b;
    WindowSpritePart *c;
    int k;

    row = 0;
    a = (WindowSpritePart *)get_array_entry(1);
    b = (WindowSpritePart *)get_array_entry(2);
    c = (WindowSpritePart *)get_array_entry(0);
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
                a->x = 40.0f * (f32)k + 10.0f;
                a->y = x;
                TWindowSubSymbolChatPartsSet::setup_part_sprites(a, b, c, (u16)i, *selection, *flip_u, *flip_v, 0);
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
    WindowSpritePart *e0;
    s32 row;
    WindowSpritePart *e1;
    f32 y;
    f32 off;
    f32 x;
    f32 h;
    row = 0;
    e1 = (WindowSpritePart *)get_array_entry(1);
    e0 = (WindowSpritePart *)get_array_entry(0);
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
                e0->x = 40.0f * (f32)j + 10.0f;
                e0->y = x;
                e1->x = 16.0f + e0->x;
                e1->y = 16.0f + e0->y;
                TWindowSubSymbolChatPartsSet::set_part_sprite(e1, (s16)i, *flip_u, *flip_v);
                draw_visible_window_entries(this, &entry_list, ctx);
            }
        }
    }
}
#pragma pop

void TWindowSubSymbolChatParts::update_height() {
    item_count = TWindowSubSymbolChat::compute_total_height();
    update_row_count();
    view_mode = 2;
}

void TWindowSubSymbolChatParts::open(s8 *selected_value) {
    selection = selected_value;
    item_count = 0xC0;
    update_row_count();
    view_mode = 1;
}


void TWindowSubSymbolChatParts::init_help(s32 *help_value) {
    WindowSpritePart *e2;
    WindowSpritePart *e0;
    help = help_value;
    *help = 0;
    e2 = (WindowSpritePart *)get_array_entry(2);
    e0 = (WindowSpritePart *)get_array_entry(0);
    *(u16 *)e2 |= 2;
    set_sprite_dimensions(e0, 32.0f, 32.0f);
    set_sprite_uv_from_pixels(e0, 185.0f, 22.0f);
    e0->kind = 0;
    item_count = 0x44;
    update_row_count();
    view_mode = 0;
}

void TWindowSubSymbolChatParts::render() {
    WindowDrawContext *ctx;

    ctx = get_draw_context();
    draw_window_frame(ctx);
    switch ((s8)view_mode) {
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
    draw_selected_cursor((u8 *)ctx);
    heading->render(ctx);
}

void TWindowSubSymbolChatParts::run_task() {
    ControllerInputContext *pad;

    if (!(window_flags & 2)) {
        open_tick = 0x01000000;
    }
    if (is_confirmed() == 0) {
        update_cursor_input();
        pad = &controller_input_state.controllers[0];
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
    scroll_to_cursor_row();
    if ((f32)open_tick >= 7.5f) {
        heading->update();
        scrollbar->increment_counter();
    }
    this->update_window();
}

TWindowSubSymbolChatParts::~TWindowSubSymbolChatParts() {
    TWindowSubStatusDisp::destroy_allocation((saddr)scrollbar, (s16)1);
    delete heading;
}

TWindowSubSymbolChatParts::TWindowSubSymbolChatParts(const NJS_POINT2 *position, s32 *flip_u_flag, s32 *flip_v_flag)
    : TWindowAddition((u8 *)&symbol_chat_parts_window_layout, 4, (u8 *)position) {
    NJS_POINT2 v;
    WindowHeading *p;

    m_name = class_name;
    result_flags = 0;
    cursor_col = 0;
    cursor_row = 0;
    item_count = 0;
    flip_u = flip_u_flag;
    flip_v = flip_v_flag;
    p = new WindowHeading((saddr)TWindowSubStatusDisp::get_message_10(0x33), client_index);
    heading = p;
    v.x = 0.0f;
    v.y = 0.0f;
    scrollbar = new WindowScrollBar(&v);
}
