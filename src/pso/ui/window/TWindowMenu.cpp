#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowAddition.h"
#include <stddef.h>
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/ControllerInput.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/HeadingEntry.h"
#include "pso/unk/TWindowLayoutRect.h"

#pragma readonly_strings on






void set_window_menu_rows(s32 rows);

const f64 com_card_minimum_entry_height = 0.0;
MenuWindowLayout menu_window_layout = {1, 0, {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, 0}};
WindowDescriptor menu_window_descriptor = {{0.0f, 0.0f}, 50050.0f, &menu_window_layout, 3};
const char *TWindowMenu::class_name = "TWindowMenu";
extern s32 actor_frame_tick;

void TKeyBoardControl::set_composer_flag62_bit4() {
    TWindowKeyBoardBase *keyboard = m_base;
    if (keyboard != NULL) {
        keyboard->set_flag62_bit4();
    }
}

int TWindowMenuInfomation::get_flag() { return (state_flags >> 2) & 1; }

void TWindowMenuInfomation::clear_flag_and_release2() {
    state_flags &= ~2;
    if (heading != NULL) {
        heading->set_state(1);
    }
}

void TWindowMenu::update_scroll_target_position() {
    NJS_POINT2 extent;
    WindowScrollBar *scroll = scroll_bar;
    if (scroll != NULL) {
        extent.x = (frame_size[0] - 4.0f) - 9.0f;
        extent.y = (f32) ((entry_count * 0x14) - 2);
        scroll->set_extent(&extent);
    }
}

void TWindowMenu::clamp_scroll_offset() {
    NJS_POINT2 scroll_range;
    f32 max_scroll_y;
    if (scroll_bar != NULL) {
        scroll_range.x = 0.0f;
        max_scroll_y = frame_size[1] - 20.0f;
        scroll_range.y = max_scroll_y;
        if (heading != NULL) {
            scroll_range.y = max_scroll_y - 6.0f;
        }
        scroll_bar->clamp_offset(scroll_offset, &scroll_range);
    }
}

void TWindowMenu::ensure_scroll_bar() {
    NJS_POINT2 extent;
    f32 extent_x;
    if (scroll_bar == NULL) {
        extent_x = this->target_size[0] - 8.0f;
        extent.y = 0.0f;
        extent.x = extent_x;
        scroll_bar = new WindowScrollBar(&extent);
        this->window_flags = (s32) (this->window_flags | 0x80);
    }
}

void TWindowMenu::reset_entries() {
    s32 i;
    TWindowMenuRow *r;
    void *e;
    entry_count = 0;
    row_cursor = 0;
    r = rows;
    for (i = 0; i < row_count; i++, r++) {
        e = ((void *)get_array_entry(i));
        TWindowDuelResult::set_default_status(e, 0);
        measure_message_text_width_default(e);
        r->flags = 0;
        r->value = 0;
    }
}

s32 TWindowMenu::is_row_enabled(s16 row) {
    if (rows[row].flags & 0x10) return 0;
    return 1;
}

// Greys the row out and marks it disabled.
void TWindowMenu::disable_row(s16 row) {
    WindowTextEntry *entry = static_cast<WindowTextEntry *>(get_array_entry(row));
    TWindowMenuRow *state = &rows[row];
    entry->color = 0xFF909090;
    state->flags |= 0x10;
}

// Gives the row its text colour back and enables it.
void TWindowMenu::enable_row(s16 row, s32 color) {
    WindowTextEntry *entry = static_cast<WindowTextEntry *>(get_array_entry(row));
    TWindowMenuRow *state = rows;
    entry->color = color;
    state[row].flags &= ~0x10;
}

void *TWindowMenu::get_selected_entry() {
    s16 row;
    row = selected_row;
    if (row < 0) {
        return 0;
    }
    if (row >= row_count) {
        return 0;
    }
    return get_array_entry(row);
}

void TWindowMenu::set_active_flag() {
    if (!(this->menu_flags & 8) && (is_decided() == 0)) {
        if (!(this->menu_flags & 0x400)) {
            play_sound_effect(0x52F16, 0, 0, 0);
        }
        this->menu_flags = (u16) (this->menu_flags | 4);
    }
}

void TWindowMenu::confirm_selection() {
    s32 row_flags;
    u8 *window_sub_status_disp;
    if (((int)this->is_decided()) == 0) {
        row_flags = rows[selected_row].flags;
        if (row_flags & 0x10) {
            if (!(row_flags & 0x20)) {
                play_sound_effect(0x53F06, 0, 0, 0);
            }
        } else {
            if (!(row_flags & 0x20)) {
                play_sound_effect(0x52D01, 0, 0, 0);
            }
            this->menu_flags = (u16) (this->menu_flags | 2);
            window_sub_status_disp = (u8 *)this->heading;
            if (window_sub_status_disp != NULL) {
                ((WindowHeading *)window_sub_status_disp)->set_state(2);
            }
        }
    }
}

void TWindowMenu::select_next_item() {
    s16 candidate;

    play_sound_effect(0x54100, 0, 0, 0);
    candidate = selected_row;
    while (1) {
        candidate += 1;
        if (candidate >= row_count) {
            if (this->menu_flags & 1) {
                return;
            }
            candidate = 0;
        }
        if (candidate == selected_row) {
            return;
        }
        if (is_entry_selectable(candidate) != 0) {
            selected_row = candidate;
            return;
        }
    }
}

void TWindowMenu::move_cursor_prev() {
    s16 candidate;

    play_sound_effect(0x54100, 0, 0, 0);
    candidate = selected_row;
    while (1) {
        candidate -= 1;
        if (candidate < 0) {
            if (this->menu_flags & 1) {
                return;
            }
            candidate = row_count - 1;
        }
        if (candidate == selected_row) {
            return;
        }
        if (is_entry_selectable(candidate) != 0) {
            selected_row = candidate;
            return;
        }
    }
}

#pragma push
#pragma fp_contract on
void TWindowMenu::update_target_y() {
    f32 v;
    f32 t;
    f32 base;
    if (scroll_bar != 0 && this->tween_ticks == 0) {
        v = 9.0f + (f32)(this->selected_row * 0x14);
        v -= 0.5f * (this->frame_size[1] - 20.0f);
        if (heading != NULL) {
            v -= 3.0f;
        }
        t = this->scroll_offset[1];
        this->scroll_offset[1] = t + (v - t);
    }
}
#pragma pop

void TWindowMenu::clamp_menu_choice_scroll() {
    NJS_POINT2 scroll_range;
    f32 max_scroll_y;
    if (scroll_bar != NULL) {
        scroll_range.x = 0.0f;
        max_scroll_y = this->frame_size[1] - 20.0f;
        scroll_range.y = max_scroll_y;
        if (this->heading != 0) {
            scroll_range.y = max_scroll_y - 6.0f;
        }
        this->scroll_bar->clamp_offset(scroll_offset, &scroll_range);
    }
}

void TWindowMenu::advance_past_disabled_menu_rows() {
    WindowTextEntry *e;
    s16 t;
    if (row_cursor < row_count) {
        e = static_cast<WindowTextEntry *>(get_array_entry((s32)row_cursor));
        while (e->get_text() != 0 && (e->flags & 0x10)) {
            t = row_cursor + 1;
            row_cursor = t;
            if (t >= row_count) {
                break;
            }
            e = static_cast<WindowTextEntry *>(get_array_entry((s32)row_cursor));
            if (rows[row_cursor].flags & 2) {
                rows[row_cursor].flags &= ~2;
                e->flags &= ~8;
            }
        }
    }
}

#pragma fp_contract on
void TWindowMenu::update_scroll_value() {
    f32 v;
    u32 *ticks;
    u32 n;
    ticks = &tween_ticks;
    if (menu_flags & 0x20) {
        v = ((TWindowLayoutRect *)get_selected_entry())->y;
    } else {
        v = 0.0f;
        ticks = &tween_ticks;
    }
    n = *ticks;
    if (n == 0) {
        scroll_offset[1] = v;
        return;
    }
    v += 0.5f * (target_size[1] - frame_size[1]);
    scroll_offset[1] += (v - scroll_offset[1]) / (f32)n;
}

s32 TWindowMenu::get_selected_value() {
    return rows[selected_row].value;
}

void TWindowMenu::set_selected_index(s16 index) {
    if ((index >= 0) && (index < row_count)) {
        selected_row = index;
    }
}

#pragma push
#pragma fp_contract on
void align_menu_entry_positions(TWindowMenu *self) {
    f32 left = self->target_size[0] - 8.0f;
    f32 right = 0.5f * self->target_size[0] - 4.0f;
    u32 i;
    for (i = 0; i < self->row_count; i++) {
        WindowTextEntry *e = static_cast<WindowTextEntry *>(self->get_array_entry(i));
        if (e->get_text() != 0) {
            e->measure_text(left);
            if (e->height > 18.0f) {
                e->x = 0.0f;
            } else {
                e->x = right - 0.5f * e->width;
            }
        }
    }
}
#pragma pop

void TWindowMenu::calc_layout_height(f32 width) {
    f32 h;
    u32 i;
    WindowTextEntry *e;
    h = 0.0f;
    for (i = 0; i < row_count; i++) {
        e = static_cast<WindowTextEntry *>(get_array_entry(i));
        if (e->get_text() != 0 && !(e->height <= com_card_minimum_entry_height)) {
            e->measure_text(width);
            h += 2.0f + e->height;
        }
    }
    h -= 2.0f;
    if (window_flags & 0x40) {
        h += 6.0f;
    }
    target_size[0] = width;
    target_size[1] = 20.0f + h;
    layout_height = h;
    save_position();
}

void TWindowMenu::set_scroll_target(f32 width, f32 max_height) {
    update_layout_height(width);
    if (this->target_size[1] > max_height) {
        ensure_scroll_bar();
    }
    this->target_size[1] = max_height;
    layout_height = (f32) (max_height - 20.0f);
    save_position();
    update_scroll_target_position();
}

void TWindowMenu::update_layout_height(f32 x) {
    f32 sum = 0.0f;
    u32 i;
    for (i = 0; i < row_count; i++) {
        WindowTextEntry *e = static_cast<WindowTextEntry *>(this->TWindowBase::get_array_entry(i));
        if (e->get_text() != 0) {
            if (!(e->height <= com_card_minimum_entry_height)) {
                sum += 2.0f + e->height;
            }
        }
    }
    sum -= 2.0f;
    if (window_flags & 0x40) {
        sum += 6.0f;
    }
    target_size[0] = x;
    target_size[1] = 20.0f + sum;
    layout_height = sum;
    save_position();
}

void TWindowMenu::calc_window_size() {
    f32 width = 0.0f;
    f32 row_gap = 2.0f;
    f32 sum = width;
    f64 minimum_entry_height = com_card_minimum_entry_height;
    u32 i;
    for (i = 0; i < row_count; i++) {
        WindowTextEntry *e = static_cast<WindowTextEntry *>(get_array_entry(i));
        if (e->get_text() != 0) {
            if (e->width > width) {
                width = e->width;
            }
            if (!(e->height <= minimum_entry_height)) {
                sum += row_gap + e->height;
            }
        }
    }
    sum -= 2.0f;
    layout_height = sum;
    if (window_flags & 0x40) {
        sum += 6.0f;
    }
    target_size[0] = 8.0f + width;
    target_size[1] = 20.0f + sum;
    save_position();
}

void TWindowMenu::layout_entries() {
    f32 gap;
    f64 zero;
    f32 y;
    u32 i;
    WindowTextEntry *e;
    f32 h;
    y = 0.0f;
    gap = 2.0f;
    zero = com_card_minimum_entry_height;
    for (i = 0; i < row_count; i++) {
        e = static_cast<WindowTextEntry *>(get_array_entry(i));
        if (e->get_text() != 0) {
            e->y = y;
            h = e->height;
            if (!(h <= zero)) {
                y += gap + h;
            }
        }
    }
}

void TWindowMenu::clear_transition_flag() {
    u16 flags = menu_flags;
    if (flags & 0x20) {
        menu_flags = flags & ~0x20;
        target_size[1] = 20.0f + layout_height;
        tween_ticks = 3;
    }
}

void TWindowMenu::open() {
    u16 open_flags;
    WindowTextEntry *selected_entry;

    open_flags = menu_flags;
    if (!(open_flags & 0x20)) {
        menu_flags = (u16) (open_flags | 0x20);
        selected_entry = static_cast<WindowTextEntry *>(get_selected_entry());
        target_size[1] = 20.0f + selected_entry->height;
        if (window_flags & 0x40) {
            target_size[1] += 6.0f;
        }
        tween_ticks = 3;
    }
}

void add_gray_text_entry(TWindowMenu *list, const char *text, s32 kind, s32 id) {
    list->add_text_entry(text, kind | 0x10, id, 0xFF909090);
}

s32 TWindowMenu::add_text_entry(const char *text, s32 flags, s32 id, s32 color) {
    s16 row_index;
    WindowTextEntry *entry;
    TWindowMenuRow *row;

    if (entry_count >= row_count) {
        return 0;
    }
    entry = static_cast<WindowTextEntry *>(get_array_entry(entry_count));
    row_index = entry_count;
    row = &rows[row_index];
    entry->y = (f32)(row_index * 0x14);
    entry->color = color;
    if (flags & 1) {
        set_text_entry_string(entry, text, 0x20);
    } else {
        set_text_entry_string(entry, text, 0);
    }
    if (flags & 4) {
        entry->flags |= 1;
    }
    if (flags & 8) {
        entry->flags |= 0x40;
    }
    if (flags & 0x40) {
        entry->flags |= 0x200;
    }
    if (flags & 2) {
        if (entry_count == row_cursor) {
            flags &= ~2;
        } else {
            entry->flags |= 8;
        }
    }
    if (menu_flags & 0x100) {
        entry->reveal_all();
    }
    measure_message_text_width_default(entry);
    row->flags = flags;
    row->value = id;
    entry_count++;
    return 1;
}

s32 TWindowMenu::add_text_entry(const char *text, s32 flags, s32 id) {
    return add_text_entry(text, flags, id, -1);
}

void set_window_menu_rows(s32 rows) {
    menu_window_layout.rows = rows;
}

TWindowMenu *create_yes_no_window(const NJS_POINT2 *position, s32 id, const char *yes_text, const char *no_text) {
  TWindowMenu *window_menu = create_window_menu(position, 2, id);
  if (yes_text == NULL)
  {
    window_menu->add_text_entry((TWindowSubStatusDisp::get_message_10(0x5B)), 6, 0);
  }
  else
  {
    window_menu->add_text_entry(yes_text, 6, 0);
  }
  if (no_text == NULL)
  {
    window_menu->add_text_entry((TWindowSubStatusDisp::get_message_10(0x5C)), 6, 1);
  }
  else
  {
    window_menu->add_text_entry(no_text, 6, 1);
  }
  window_menu->calc_window_size();
  if (window_menu->frame_size[0] < 104.0f)
  {
    window_menu->update_layout_height(104.0f);
  }
  align_menu_entry_positions(window_menu);
  window_menu->set_ready_flag();
  window_menu->set_depth(50030.0f);
  return window_menu;
}

TWindowMenu *init_shop_judgment_window(void *p) { return create_yes_no_window((const NJS_POINT2 *)p, 4, NULL, NULL); }

TWindowMenu *create_window_menu(const NJS_POINT2 *position, s32 count, s32 client_id) {
    set_window_menu_rows(count);
    return new TWindowMenu(count, client_id, position);
}

TWindowMenu *create_window_menu_default(const NJS_POINT2 *pos, s32 entries) {
    return create_window_menu(pos, entries, 4);
}

TWindowMenu *create_titled_window_menu(const NJS_POINT2 *position, s32 count, const char *title, s32 client_id) {
    TWindowMenu *menu = create_window_menu(position, count, client_id);
    WindowHeading *heading = new WindowHeading(title, client_id);
    menu->heading = heading;
    menu->window_flags |= 0x40;
    return menu;
}

TWindowMenu *create_titled_window_menu_default(const NJS_POINT2 *pos, s32 entries, const char *title) {
    return create_titled_window_menu(pos, entries, title, 4);
}

void TWindowMenu::draw_selected_bar(WindowDrawContext *context) {
    s16 selected_row;
    TWindowLayoutRect *entry;
    if (!(actor_frame_tick & 0x10)) {
        selected_row = marked_row;
        if (selected_row >= 0) {
            entry = (TWindowLayoutRect *)get_array_entry((s32) selected_row);
            if (entry->flags & 1) {
                draw_selection_bar(context, entry, 1);
            }
        }
    }
}

void TWindowMenu::render_selected_entry(WindowDrawContext *context) {
    TWindowLayoutRect *entry;

    entry = (TWindowLayoutRect *)this->get_array_entry(selected_row);
    if (entry->flags & 1) {
        draw_selection_bar(context, entry, is_decided());
    }
}

void TWindowMenu::render() {
    WindowDrawContext *ctx;

    ctx = this->get_draw_context();
    draw_window_frame(ctx);
    draw_visible_window_entries(
        this,
        &this->entry_list,
        ctx);
    if (!(this->menu_flags & 0x80)) {
        this->render_selected_entry(ctx);
        this->draw_selected_bar(ctx);
    }
    if (this->heading != 0) {
        this->heading->render(ctx);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, ctx, scroll_offset);
    }
}

void TWindowMenu::run_task() {
    s32 player_idx;
    ControllerInputContext *input;
    ControllerInputContext *pad;
    ControllerInputContext *context;

    this->layout_entries();
    if (!(this->window_flags & 2)) {
        this->open_tick = 0x01000000;
    }
    if ((this->is_input_disabled() == 0) && (this->is_decided() == 0) && (this->open_tick > 2) && (is_window_display_enabled() != 0) && (this->is_open_and_unblocked() != 0)) {
        player_idx = is_player_input_active((this->client_index));
        if (this->menu_flags & 0x10) {
            input = &controller_input_state.controllers[player_idx];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (is_locked(0x10) != 0)) {
                move_cursor_prev();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (is_locked(0x20) != 0)) {
                select_next_item();
            }
        } else {
            pad = &controller_input_state.controllers[player_idx];
            if ((test_buttons_press_or_repeat_color(pad, 0x10, 6, 1) != 0) || (is_locked(0x10) != 0)) {
                move_cursor_prev();
            }
            if ((test_buttons_press_or_repeat_color(pad, 0x20, 6, 1) != 0) || (is_locked(0x20) != 0)) {
                select_next_item();
            }
        }
        context = &controller_input_state.controllers[player_idx];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (this->test_menu_flag(4) != 0)) {
            confirm_selection();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (this->test_menu_flag(2) != 0)) {
            set_active_flag();
        }
    }
    if ((f32) this->open_tick >= 7.5f) {
        if (this->heading != 0) {
            this->heading->update();
        }
        if (scroll_bar != NULL) {
            scroll_bar->increment_counter();
        }
    }
    update_window();
    this->update_scroll_value();
    this->step_window_tween();
    this->update_target_y();
    this->clamp_menu_choice_scroll();
    this->advance_past_disabled_menu_rows();
    this->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
}

TWindowMenu::~TWindowMenu() {
    delete scroll_bar;
    delete heading;
    mem_free(rows);
}

TWindowMenu::TWindowMenu(u32 count, s32 client, const NJS_POINT2 *position) : TWindowAddition((u8 *)&menu_window_descriptor, (s16)client, (u8 *)position) {
    u32 i;
    TWindowMenuRow *p;
    m_name = class_name;
    entry_count = 0;
    row_cursor = 0;
    row_count = count;
    selected_row = 0;
    menu_flags = 0;
    client_index = client;
    reset_selection();
    rows = (TWindowMenuRow *)mem_alloc(count * 8);
    p = rows;
    for (i = 0; i < count; i++) {
        p->flags = 0;
        p->value = 0;
        p++;
    }
    heading = 0;
    scroll_bar = 0;
}

#pragma push
#pragma scheduling off
void WindowScrollBar::set_extent(const NJS_POINT2 *size) {
    extent.x = size->x;
    extent.y = size->y;
}
#pragma pop

s32 TWindowAddition::is_entry_selectable(s32 index) {
    return ((TWindowLayoutEntry *)entry_list.items[index])->flags & 1;
}

s32 TWindowMenu::test_menu_flag(s32 buttons) {
    if (this->menu_flags & 0x200) {
        return 0U;
    }
    return test_controller_flag_4c_color(&controller_input_state.keyboard, buttons);
}

s32 TWindowMenu::is_locked(s32 buttons) {
    if (this->menu_flags & 0x200) {
        return 0;
    }
    return test_buttons_press_or_repeat(&controller_input_state.keyboard, buttons, 6, 1);
}

int TWindowMenu::is_input_disabled() { return (this->menu_flags >> 6) & 0x1; }

void TWindowMenu::reset_selection() { marked_row = -1; }
