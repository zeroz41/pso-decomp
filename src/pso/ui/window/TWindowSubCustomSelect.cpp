#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/TWindowSubCustomEquip.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubCustomSelect.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/SoundEffect.h"

#pragma readonly_strings on

struct Ent_80277AEC { u16 id; u8 pad[0xA]; };

struct Sub_80277AEC { u8 pad[0x34]; s32 flags; };

struct Big_80277AEC { u8 pad[0x85C]; Sub_80277AEC sub; };

struct Ent_802776D0 { u16 id; u16 sub; };


// inferred: window_sub_custom_select_layout_entries, the layout table
// TWindowSubCustomSelect__window_settings points at (two sprite parts and a value entry).
struct SubCustomSelectWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    SpritePartLayoutRecord rec_1;
    ValueLayoutRecord rec_2;
};
SubCustomSelectWindowLayout window_sub_custom_select_layout_entries = {
    3, 1,
    {6, {3.0f, 9.0f}, {56.0f, 47.0f}, 196.0f, 0.0f, 0.2f, -1, &hud_texlist, 1, 4},
    {6, {6.0f, 11.0f}, {50.0f, 43.0f}, 0.0f, 0.0f, 0.3f, -1, &hud_texlist, 3, 4},
    {4, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
};
WindowDescriptor TWindowSubCustomSelect__window_settings = {
    {204.0f, 188.0f}, 50050.0f, &window_sub_custom_select_layout_entries, 0x43,
};

const char *TWindowSubCustomSelect::class_name = "TWindowSubCustomSelect";

void TWindowSubCustomSelect::handle_cancel() {
    if (is_active() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state_flags = (u8) (this->state_flags | 2);
    }
}

void TWindowSubCustomSelect::handle_decide() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->state_flags = (u8) (this->state_flags | 1);
    ((TWindowSubStatusDisp *)(this->status_display))->set_entry_state(2);
}

#pragma fp_contract on
void TWindowSubCustomSelect::update_list_scroll() {
  NJS_POINT2 range;
  f32 *scroll_y;
  f32 target_y;
  float row_y;
  row_y = (51.0f * ((f32) ((s8)this->row))) + 6.0f;
  target_y = 27.0f + row_y;
  target_y -= 81.0f;
  scroll_y = &this->scroll_offset[1];
  *scroll_y = (*scroll_y) + (target_y - (this->scroll_offset[1]));
  range.x = 0.0f;
  range.y = ((this->frame_size[1]) - 10.0f) - 16.0f;
  scroll_bar->clamp_offset(scroll_offset, &range);
}

void TWindowSubCustomSelect::handle_grid_navigation() {
    u8 column_now;
    u8 column_wrapped;
    u8 row_now;
    u8 row_wrapped;
    u8 rows;
    ControllerInputContext *window_choice_setting;
    window_choice_setting = &controller_input_state.controllers[is_player_input_active(((s32) this->client_index))];
    if ((test_buttons_press_or_repeat(window_choice_setting, 0xF0, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0xF0, 6, 1) != 0)) {
        play_sound_effect(0x54100, 0, 0, 0);
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
            this->row = (this->row - 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
            this->row = (this->row + 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x80, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x80, 6, 1) != 0)) {
            this->column = (this->column + 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x40, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x40, 6, 1) != 0)) {
            this->column = (this->column - 1);
        }
        column_now = this->column;
        if ((s8) column_now < 0) {
            this->column = (column_now + 3);
        }
        column_wrapped = this->column;
        if ((s8) column_wrapped >= 3) {
            this->column = (column_wrapped - 3);
        }
        row_now = this->row;
        if ((s8) row_now < 0) {
            this->row = (u8) (row_now + this->row_count);
        }
        row_wrapped = this->row;
        rows = this->row_count;
        if ((s8) row_wrapped >= (s8) rows) {
            this->row = (u8) (row_wrapped - rows);
        }
    }
}

#pragma push
#pragma fp_contract on
void TWindowSubCustomSelect::draw_cursor(WindowDrawContext *context) {
    NJS_POINT2 position;
    position.x = (58.0f * (f32) (s8) this->column) + 1.0f;
    position.y = (51.0f * (f32) (s8) this->row) + (-5.0f);
    TWindowSubCustomEquip::draw_cursor_sprite(0.4f, context, &position, cursor_frame);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
void TWindowSubCustomSelect::draw_palette_cells(WindowDrawContext *ctx) {
    u32 i;
    TObjPlayer *p;
    Ent_802776D0 *e;
    s16 id;
    s16 sub;
    WindowSpritePart *icon;
    WindowSpritePart *background;
    TWindowLayoutNumber *label;
    f32 y;
    f32 fx;
    f32 fy;
    p = get_player_by_client_id(this->client_index);
    if (p == NULL) {
        return;
    }
    e = reinterpret_cast<Ent_802776D0 *>(action_table);
    for (i = 0; e->id != 8; i++, e++) {
        if (e->id == 0) {
            continue;
        }
        fx = 58.0f * (f32)(i % 3);
        fy = 51.0f * (f32)(i / 3);
        y = ctx->inner_y + fy;
        if (47.0f + (8.0f + y) < ctx->clip_y0 || 8.0f + y > ctx->clip_y1) {
            continue;
        }
        icon = static_cast<WindowSpritePart *>(get_array_entry(1));
        background = static_cast<WindowSpritePart *>(get_array_entry(0));
        label = static_cast<TWindowLayoutNumber *>(get_array_entry(2));
        icon->x = 12.0f + fx;
        icon->y = 10.0f + fy;
        background->x = 9.0f + fx;
        background->y = 8.0f + fy;
        id = e->id;
        sub = e->sub;
        if (p->can_use_palette_action(id, sub) != 0) {
            icon->color = -1;
        } else {
            icon->color = 0xFF404040;
        }
        draw_action_palette_icon(icon, id, sub);
        update_palette_item_count_label(label, icon, id, sub, client_index);
        draw_visible_window_entries(this, &entry_list, ctx);
    }
}
#pragma pop

void TWindowSubCustomSelect::render() {
    TWindowSubCustomSelect *window_sub_custom_select = this;
    WindowDrawContext *draw_context;
    draw_context = window_sub_custom_select->get_draw_context();
    window_sub_custom_select->draw_window_frame(draw_context);
    window_sub_custom_select->draw_palette_cells(draw_context);
    window_sub_custom_select->draw_cursor(draw_context);
    ((TWindowSubStatusDisp *)(window_sub_custom_select->status_display))->forward_render(draw_context);
    draw_window_scrollbar(window_sub_custom_select->scroll_bar, draw_context, window_sub_custom_select->scroll_offset);
}

void TWindowSubCustomSelect::run_task() {
    s32 controller_index;
    ControllerInputContext *context;
    controller_index = is_player_input_active(((s32) this->client_index));
    if (!(*(s32 *)&this->window_flags & 2)) {
        *(s32 *)&this->open_tick = 0x01000000;
    }
    if (this->is_active() == 0) {
        handle_grid_navigation();
        context = &controller_input_state.controllers[controller_index];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            handle_decide();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            handle_cancel();
        }
    }
    update_list_scroll();
    if ((f32) *(s32 *)&this->open_tick >= 7.5f) {
        ((TWindowSubStatusDisp *)(*(saddr *)&this->status_display))->update_subwindow();
        scroll_bar->increment_counter();
    }
    update_window();
    this->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
    *(s32 *)&this->cursor_frame = (s32) (*(s32 *)&this->cursor_frame + 1);
}

TWindowSubCustomSelect::~TWindowSubCustomSelect() {
    TWindowSubStatusDisp::destroy_allocation(reinterpret_cast<saddr>(scroll_bar), (s16)1);
    TWindowSubStatusDisp::destroy_status_display((saddr)status_display, (s16)1);
}
const u32 custom_select_organic_action_table[40] = {
    0x20000, 0x20001, 0x20002, 0x30000, 0x30006, 0x30003, 0x30001, 0x30007,
    0x30004, 0x30002, 0x30008, 0x30005, 0x30009, 0x30012, 0, 0x3000F,
    0x30010, 0x30011, 0x3000D, 0x3000A, 0x3000B, 0x3000C, 0x3000E, 0,
    0x40000, 0x40001, 0x40002, 0x40003, 0x40004, 0x40005, 0x40006, 0x40007,
    0x40008, 0x40009, 0x4000A, 0, 0x4000B, 0x4000C, 0, 0x80000,
};
const u32 custom_select_android_action_table[20] = {
    0x20000, 0x20001, 0x20002, 0x40000, 0x40001, 0x40002, 0x40009, 0x4000A,
    0, 0x4000B, 0x40008, 0, 0x4000D, 0x4000E, 0, 0x4000F,
    0x40010, 0, 0x80000, 0,
};

#pragma push
#pragma fp_contract on
#pragma fp_contract on
TWindowSubCustomSelect::TWindowSubCustomSelect(s32 client)
    : TWindowAddition((u8 *)&TWindowSubCustomSelect__window_settings,
                      static_cast<s16>(client), (u8 *)get_window_layout_position(0x10)) {
    NJS_POINT2 pos;
    Big_80277AEC *p;
    Sub_80277AEC *q;
    Ent_80277AEC *e;
    void *o;
    m_name = TWindowSubCustomSelect::class_name;
    client_index = client;
    p = (Big_80277AEC *)get_player_by_client_id(client_index);
    if (p == NULL) {
        return;
    }
    q = &p->sub;
    if (q == NULL) {
        return;
    }
    if (q->flags & 0x10) {
        action_table = reinterpret_cast<uaddr>(custom_select_android_action_table);
    } else {
        action_table = reinterpret_cast<uaddr>(custom_select_organic_action_table);
    }
    this->state_flags = 0;
    this->column = 0;
    this->row = 0;
    this->cursor_frame = 0;
    e = reinterpret_cast<Ent_80277AEC *>(action_table);
    this->row_count = 0;
    while (e->id != 8) {
        e++;
        (this->row_count)++;
    }
    o = ::operator new(0x24);
    if (o != NULL) {
        o = ((TWindowSubStatusDisp *)o)->construct_type1_heading((saddr)TWindowSubStatusDisp::get_message_10(0x22), client_index);
    }
    status_display = (uaddr)o;
    pos.x = 196.0f;
    pos.y = 51.0f * (f32)(s8)row_count + 18.0f;
    scroll_bar = new WindowScrollBar(&pos);
}
#pragma pop

