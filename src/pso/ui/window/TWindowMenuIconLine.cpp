#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/TWindowLayoutEntry.h"
#include "pso/ui/window/HeadingEntry.h"
#include "types.h"
#include "pso/ui/font/MenuFontGlyphs.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/ItemListRow.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/player/PlayerTrapCounts.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/window/WindowLayoutRecord.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowCheckBox.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include <stddef.h>
#include "pso/network/TLobby.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowSubTradeMain.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/WindowTextDraw.h"
#include "pso/enemy/BattleParamTables.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/TWindowMenuInfomation.h"
#include "pso/ui/window/LabelValueRow.h"
#include "pso/ui/window/TWindowLayoutRect.h"

const char *TWindowMenuIconLine::class_name = "TWindowMenuIconLine";


void get_shortcut_entry_codes(s32 index, u8 *first, u8 *second, s32 player) {
    // pairs of entry codes handed to init_entry by TWindowSubShortCutList::draw_entry
    static const u8 entry_code_pairs[20][2] = {
        {0x33, 0x1C}, {0x33, 0x1E}, {0x33, 0x1F}, {0x33, 0x1D}, {0x1A, 0x1C}, {0x1A, 0x1E}, {0x1A, 0x1F},
        {0x1A, 0x1D}, {0x33, 0x20}, {0x33, 0x21}, {0x33, 0x22}, {0x33, 0x23}, {0x33, 0x24}, {0x33, 0x25},
        {0x33, 0x26}, {0x33, 0x27}, {0x33, 0x28}, {0x33, 0x29}, {0x33, 0x2A}, {0x33, 0x2B},
    };
    const u8 *entry = entry_code_pairs[index];
    *first = *entry++;
    if (*first == 0x1A && TWindowKeyBoardHard::test_card_flag_2(player) != 0) {
        *first = 0x1B;
    }
    *second = *entry;
}



// The trade lists' enable step, the reverse of deactivate.
void TWindowMenuIconLine::activate() {
    if (status_display != NULL) {
        if (is_decided() != 0) {
            status_display->set_state(2);
        } else {
            status_display->set_state(1);
        }
    }
    clear_close_flag();
    enable_input();
}

// What the trade window creators call on a new list.
void TWindowMenuIconLine::deactivate() {
    disable_input();
    set_close_flag();
    if (status_display != NULL) {
        status_display->set_state(0);
    }
}

// Puts the cursor back on the saved row, or the nearest selectable row above it.
void TWindowMenuIconLine::clamp_selection_to_valid_entry() {
    TWindowLayoutEntry *e;
    if (entry_count >= 0) {
        if (saved_cursor >= entry_count) {
            cursor = entry_count - 1;
            return;
        }
        e = (TWindowLayoutEntry *)get_array_entry(saved_cursor);
        while (e->is_flag_4_set() == 0) {
            saved_cursor = saved_cursor - 1;
            e = (TWindowLayoutEntry *)get_array_entry(saved_cursor);
        }
        cursor = saved_cursor;
    }
}

void TWindowMenuIconLine::save_cursor_selection() {
    saved_cursor = cursor;
    saved_cursor_value = get_cursor_value();
}
void TWindowMenuIconLine::reset_list() {
    u32 i;
    this->entry_count = 0;
    this->cursor = 0;
    for (i = 0; i < (u32)this->entry_capacity; i++) {
        ((ItemListRow *)get_array_entry(i))->reset();
    }
}


extern "C" {
s32 list_window_layout[3] = {1, 0, 8};
WindowDescriptor list_window_descriptor = {
    {0.0f, 0.0f}, 50050.0f, list_window_layout, 3,
};

}


saddr TWindowMenuIconLine::get_cursor_value() {
    return ((ItemListRow *)get_array_entry(cursor))->get_item();
}

void TWindowMenuIconLine::calc_content_extent() {
    NJS_POINT2 extent;

    if (scroll_bar != NULL) {
        extent.x = frame_size[0] - 8.0f;
        if (scroll_bar != NULL) {
            extent.x -= 5.0f;
        }
        extent.y = (f32) (entry_count * 20 - 2);
        scroll_bar->set_extent(&extent);
    }
}

void TWindowMenuIconLine::clamp_scroll_offset() {
    NJS_POINT2 range;
    if (scroll_bar != NULL) {
        range.x = 0.0f;
        range.y = frame_size[1] - 20.0f;
        if (status_display != NULL) {
            range.y -= 6.0f;
        }
        scroll_bar->clamp_offset(scroll_offset, &range);
    }
}

void TWindowMenuIconLine::advance_line(s32 message) {
    int index;
    index = entry_count;
    if (index < entry_capacity) {
        ((ItemListRow *)get_array_entry(index))->setup_entry_msg_d1(message);
        entry_count++;
    }
}

void TWindowMenuIconLine::advance_status_disp_entry(s32 message) {
    int index;
    index = entry_count;
    if (index < entry_capacity) {
        ((ItemListRow *)get_array_entry(index))->setup_entry_msg_d0(message);
        entry_count++;
    }
}

void TWindowMenuIconLine::add_list_entry(s32 message) {
    int index;
    index = entry_count;
    if (index < entry_capacity) {
        ((ItemListRow *)(get_array_entry(index)))->init_no_item_entry(message);
        entry_count++;
    }
}

void TWindowSubShortCutList::draw_entry(s32 index, s32 status_style, const char *src, s32 item) {
    u8 status_icon;
    u8 category_icon;

    if ((s16) this->entry_count < (s16) this->entry_capacity) {
        get_shortcut_entry_codes(index, &status_icon, &category_icon, this->client_index);
        ((ItemListRow *)get_array_entry(this->entry_count))->init_entry(status_icon, category_icon, status_style, src, item);
        this->entry_count = (this->entry_count + 1);
    }
}

void TWindowMenuIconLine::add_meseta_entry(s32 meseta, s32 id) {
    if (entry_count < entry_capacity) {
        static_cast<ItemListRow *>(get_array_entry(entry_count))->init_meseta(meseta, id);
        entry_count++;
    }
}

void TWindowMenuIconLine::add_battle_stat_entry(s32 stat, s32 item, s32 gray_out) {
    s32 value;
    ItemListRow *row;
    TObjPlayer *player;

    if (entry_count < entry_capacity) {
        player = get_player_by_client_id(client_index);
        if (player != NULL) {
            if (stat == 4) {
                value = player->sonar_stock.get_count();
            } else {
                value = player->trap_counts.get_count(stat);
            }
            if (value > 0) {
                row = (ItemListRow *)get_array_entry(entry_count);
                row->setup_stat_line(get_localized_text_entry(0x10, stat + 0x13), value, item);
                if ((gray_out != 0) && ((is_current_area_item_enabled() == 0) || (is_boss_area() != 0))) {
                    row->flags |= 0x80;
                }
                entry_count++;
            }
        }
    }
}

void TWindowMenuIconLine::advance_all_entries(s32 play_sound) {
    s32 i;
    if (static_cast<ItemListRow *>(get_array_entry(cursor))->is_flag80_set() == 0) {
        if (play_sound != 0) {
            play_sound_effect(0x52D01, 0, 0, 0);
        }
        for (i = 0; i < entry_capacity; i++) {
            static_cast<ItemListRow *>(get_array_entry(i))->advance_state();
        }
        static_cast<ItemListRow *>(get_array_entry(cursor))->finalize_state();
    }
}

void TWindowMenuIconLine::refresh_selected_entry(s32 play_sound) {
    ItemListRow *entry;

    entry = static_cast<ItemListRow *>(get_array_entry(cursor));
    if (entry->is_flag80_set() == 0) {
        if (play_sound != 0) {
            play_sound_effect(0x52D01, 0, 0, 0);
        }
        entry->finalize_state();
    }
}

void TWindowMenuIconLine::add_status_entry(s8 flags, const char *src, s32 item) {
    u8 category_icon;
    s16 index = entry_count;

    if (index < entry_capacity) {
        if (flags & 8) {
            category_icon = 0xD;
        } else if (flags & 4) {
            category_icon = 0xF;
        } else {
            category_icon = 0x33;
        }
        ItemListRow *row = static_cast<ItemListRow *>(get_array_entry(index));
        row->init_status_entry(category_icon, src, item);
        row->x = -18.0f;
        if (flags & 2) {
            row->status_icon = 0xE;
            row->flags |= 0x100;
        }
        ++entry_count;
    }
}

void TWindowMenuIconLine::append_entry(s32 flag, const char *src, s32 item, s32 extra_flag, s32 space_rows) {
    ItemListRow *row;
    s32 i;
    f32 k;
    ItemListRow *other;

    if (entry_count < entry_capacity) {
        row = static_cast<ItemListRow *>(get_array_entry(entry_count));
        row->init_status_entry_by_flag(flag, src, item);
        if (extra_flag != 0) {
            row->flags |= 0x400;
        }
        if (space_rows != 0) {
            k = 40.0f;
            i = 0;
            row->flags |= 0x1000;
            while (i < entry_capacity) {
                other = static_cast<ItemListRow *>(get_array_entry(i));
                other->y = k * (f32)i++;
            }
        }
        entry_count++;
    }
}

void TWindowMenuIconLine::add_inventory_item(TItem *item, s32 count, s32 id) {
    int index;
    if (item != NULL) {
        index = entry_count;
        if (index < entry_capacity) {
            ((ItemListRow *)(get_array_entry(index)))->set_inventory_item(item, count, id);
            entry_count++;
        }
    }
}

void TWindowMenuIconLine::add_item(TItem *item, s32 price, s32 index) {
    int row;
    if (item != NULL) {
        row = entry_count;
        if (row < entry_capacity) {
            ((ItemListRow *)get_array_entry(row))->update_from_player(item, price, index);
            entry_count++;
        }
    }
}

void TWindowMenuIconLine::add_list_entry(TItem *item, s32 index) {
    int row;
    if (item != NULL) {
        row = entry_count;
        if (row < entry_capacity) {
            ((ItemListRow *)get_array_entry(row))->init_item_row(item, index);
            entry_count = entry_count + 1;
        }
    }
}

void TWindowMenuIconLine::add_item_info_entry(TItemData *item, s32 index, s32 count) {
    if (item != NULL) {
        if (entry_count < entry_capacity) {
            ((ItemListRow *)get_array_entry(entry_count))->set_item_info(item, index, count);
            entry_count++;
        }
    }
}

void TWindowMenuIconLine::add_ground_item(TItemData *item, s32 index) {
    if (item != NULL) {
        if (entry_count < entry_capacity) {
            ((ItemListRow *)get_array_entry(entry_count))->set_ground_item(item, index);
            entry_count++;
        }
    }
}

void TWindowMenuIconLine::add_text_entry(const char *text, s32 id) {
    if (entry_count < entry_capacity) {
        ItemListRow *entry = (ItemListRow *)get_array_entry(entry_count);
        entry->init_display(text, id);
        entry_count++;
    }
}

void set_menu_icon_line_flags(s32 flags) {
    list_window_descriptor.flags = flags;
}

#pragma fp_contract on
void TWindowMenuIconLine::draw_item_list_capacity(WindowDrawContext *context, s32 current_items, s32 capacity) {
  u8 advance;
  NJS_POINT2 pt;
  if (context->open_tick >= 0)
  {
    pt.x = (166.0f + context->x) - 8.0f;
    pt.y = context->y - 13.0f;
    draw_window_tab(context, &pt.x, -60.0f, 0);
    pt.x += 50.0f;
    pt.y += 4.0f;
    set_text_draw_params(context, 0, 0, (f32)(-1.0f / (0.1794f + context->depth)), (f32)100000.0f);
    text_builder_reset();
    text_builder_append_int(current_items);
    pt.x -= (f32) calc_text_width(get_shared_text_buffer());
    advance = get_font_char_advance(map_char_to_font_code(0x2F));
    pt.x -= 0.5f * advance;
    text_builder_append("/");
    text_builder_append_int(capacity);
    draw_window_text((f32 *)&pt, get_shared_text_buffer(), -1, 0, (f32)100000.0f);
  }
}

void TWindowMenuIconLine::set_flag4() {
    if (!(this->state_flags & 8) && (is_decided() == 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state_flags = (u16) (this->state_flags | 4);
    }
}

void TWindowMenuIconLine::handle_open() {
    TWindowLayoutEntry *entry;
    entry = static_cast<TWindowLayoutEntry *>(get_array_entry(this->cursor));
    if ((entry->is_flag_4_set() == 0) || (entry->is_flag80_set() != 0)) {
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    }
    if (!(this->state_flags & 0x100)) {
        play_sound_effect(0x52D01, 0, 0, 0);
    }
    this->state_flags = (u16) (this->state_flags | 2);
    if (this->status_display != NULL) {
        this->status_display->set_state(2);
    }
}

void TWindowMenuIconLine::move_cursor_next() {
    s16 candidate;

    play_sound_effect(0x54100, 0, 0, 0);
    candidate = this->cursor;
    while (1) {
        candidate += 1;
        if (candidate >= (s16) this->entry_capacity) {
            if (this->state_flags & 1) {
                return;
            }
            candidate = 0;
        }
        if (candidate == (s16) this->cursor) {
            return;
        }
        if (is_entry_selectable(candidate) != 0) {
            this->cursor = candidate;
            return;
        }
    }
}

void TWindowMenuIconLine::move_cursor() {
    s16 candidate;

    play_sound_effect(0x54100, 0, 0, 0);
    candidate = this->cursor;
    while (1) {
        candidate -= 1;
        if (candidate < 0) {
            if (this->state_flags & 1) {
                return;
            }
            candidate = this->entry_capacity - 1;
        }
        if (candidate == (s16) this->cursor) {
            return;
        }
        if (is_entry_selectable(candidate) != 0) {
            this->cursor = candidate;
            return;
        }
    }
}

void TWindowMenuIconLine::set_cursor_index(s16 index) {
    if (index >= 0) {
        if (index >= entry_capacity) {
            return;
        }
        while (is_entry_selectable(index) == 0) {
            if (index > 0) {
                index -= 1;
                continue;
            }
            break;
        }
        cursor = index;
    }
}

void TWindowMenuIconLine::create_menu_scroll_bar() {
    NJS_POINT2 size;
    if (this->scroll_bar == NULL) {
        size.x = this->target_size[0] - 8.0f;
        size.y = 0.0f;
        this->scroll_bar = new WindowScrollBar(&size);
        this->window_flags |= 0x80;
    }
}

void TWindowMenuIconLine::ensure_status_display(const char *title) {
    WindowHeading *heading;

    if (this->status_display == NULL) {
        heading = new WindowHeading(title, this->client_index);
        this->status_display = heading;
        (this->window_flags) = (s32) ((this->window_flags) | 0x40);
    }
}

void TWindowMenuIconLine::start_scroll(f32 height) {
    u16 flags = state_flags;
    if (flags & 0x20) {
        state_flags = flags & ~0x20;
        target_size[1] = height;
        tween_ticks = 3;
    }
}

void TWindowMenuIconLine::shrink_to_selected_entry() {
    u16 flags;
    TWindowLayoutRect *entry;

    flags = state_flags;
    if (!(flags & 0x20)) {
        state_flags = flags | 0x20;
        entry = (TWindowLayoutRect *)this->get_array_entry(cursor);
        this->target_size[1] = 20.0f + entry->height;
        if (this->window_flags & 0x40) {
            this->target_size[1] += 6.0f;
        }
        this->tween_ticks = 3;
    }
}

#pragma push
#pragma fp_contract on
void TWindowMenuIconLine::center_list_selection() {
    f32 target;

    if ((this->scroll_bar != 0U) && (this->tween_ticks == 0U)) {
        f32 t = (this->frame_size[1] - 16.0f) - 10.0f;
        target = 9.0f + (f32) (this->cursor * 0x14);
        target -= 0.5f * t;
        scroll_offset[1] += target - scroll_offset[1];
    }
}
#pragma pop

void TWindowMenuIconLine::clamp_item_list_scroll() {
    NJS_POINT2 range;
    if (this->scroll_bar != NULL) {
        range.x = 0.0f;
        range.y = this->frame_size[1] - 20.0f;
        if (this->status_display != NULL) {
            range.y -= 6.0f;
        }
        scroll_bar->clamp_offset(scroll_offset, &range);
    }
}

#pragma fp_contract on
void TWindowMenuIconLine::update_scroll_offset() {
  WindowTextEntry *entry;
  f32 target_y;
  u32 n;
  if ((this->state_flags) & 0x20)
  {
    entry = (WindowTextEntry *)get_array_entry(this->cursor);
    target_y = entry->y;
  }
  else
  {
    target_y = 0.0f;
  }
  n = this->tween_ticks;
  if (n == 0)
  {
    this->scroll_offset[1] = target_y;
  }
  else
  {
    target_y += 0.5f * ((this->target_size[1]) - (this->frame_size[1]));
    this->scroll_offset[1] += (target_y - (this->scroll_offset[1])) / ((f32) n);
  }
}

void TWindowMenuIconLine::draw_selected_list_entry(WindowDrawContext *context) {
    TWindowLayoutRect *entry;

    if (!(this->state_flags & 0x80)) {
        entry = (TWindowLayoutRect *)this->get_array_entry(this->cursor);
        if (entry->flags & 1) {
            draw_selection_bar(context, entry, this->is_decided());
        }
    }
}

void TWindowMenuIconLine::init(u32 count, s32 client) {
    u32 i;
    WindowTextEntry *e;
    m_name = TWindowMenuIconLine::class_name;
    client_index = client;
    entry_count = 0;
    cursor = 0;
    entry_capacity = count;
    saved_cursor = 0;
    saved_cursor_value = 0;
    state_flags = 0;
    status_display = 0;
    scroll_bar = 0;
    for (i = 0; i < count; i++) {
        e = static_cast<WindowTextEntry *>(get_array_entry(i));
        e->y = (f32)(i * 0x14);
    }
}

TWindowMenuIconLine *create_menu_icon_line(const NJS_POINT2 *position, const NJS_POINT2 *size, u32 count, s16 client) {
    set_menu_icon_line_params(size, count);
    return new TWindowMenuIconLine((u8 *)position, count, client);
}

void set_menu_icon_line_params(const NJS_POINT2 *size, s32 count) {
    list_window_descriptor.size[0] = size->x;
    list_window_descriptor.size[1] = size->y;
    list_window_layout[1] = count;
}

void TWindowMenuIconLine::render() {
    WindowDrawContext *draw_context;

    draw_context = get_draw_context();
    draw_window_frame(draw_context);
    draw_visible_window_entries(
        this,
        &entry_list,
        draw_context);
    this->draw_selected_list_entry(draw_context);
    if (this->status_display != NULL) {
        this->status_display->render(draw_context);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, draw_context, scroll_offset);
    }
}

void TWindowMenuIconLine::run_task() {
    s32 controller_index;
    WindowScrollBar *bar;
    ControllerInputContext *input;
    ControllerInputContext *pad;
    ControllerInputContext *context;
    controller_index = is_player_input_active(((s32) this->client_index));
    if ((this->is_input_disabled() == 0) && (this->is_decided() == 0) && (this->is_open_and_unblocked() != 0)) {
        if (this->state_flags & 0x10) {
            input = &controller_input_state.controllers[controller_index];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                this->move_cursor();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                this->move_cursor_next();
            }
        } else {
            pad = &controller_input_state.controllers[controller_index];
            if ((test_buttons_press_or_repeat_color(pad, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                this->move_cursor();
            }
            if ((test_buttons_press_or_repeat_color(pad, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                this->move_cursor_next();
            }
        }
        context = &controller_input_state.controllers[controller_index];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            this->handle_open();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            this->set_flag4();
        }
    }
    if ((f32) this->open_tick >= 7.5f) {
        if (status_display != NULL) {
            status_display->update();
        }
        bar = scroll_bar;
        if (bar != NULL) {
            bar->increment_counter();
        }
    }
    update_window();
    this->update_scroll_offset();
    this->step_window_tween();
    this->center_list_selection();
    this->clamp_item_list_scroll();
    this->update_window_entry_list(&entry_list);
}

TWindowMenuIconLine::~TWindowMenuIconLine() {
    delete this->scroll_bar;
    delete this->status_display;
}

// The descriptor-taking form; the window layout comes from the caller.
TWindowMenuIconLine::TWindowMenuIconLine(u8 *parent, u32 count, s16 client, u8 *descriptor)
    : TWindowAddition(descriptor, client, parent) {
    init(count, client);
}

// The default form: the list window descriptor of this unit.
TWindowMenuIconLine::TWindowMenuIconLine(u8 *parent, u32 count, s16 client)
    : TWindowAddition((u8 *)&list_window_descriptor, client, parent) {
    init(count, client);
}

void TWindowMenuIconLine::enable_input() { state_flags &= ~0x40; }

void TWindowMenuIconLine::clear_close_flag() { state_flags &= ~0x80; }

int TWindowLayoutEntry::is_flag80_set() const { return flags & 0x80; }

s32 TWindowMenuInfomation::update_selected_entry() {
    return ((LabelValueRow *)get_array_entry(index))->get_entry_id();
}

char *TWindowMenuInfomation::find_entry_value_by_id(s32 key) {
    s32 i;
    LabelValueRow *e;
    for (i = 0; i < entry_capacity; i++) {
        e = (LabelValueRow *)get_array_entry(i);
        if (e != NULL && e->is_flag_4_set() != 0 && key == e->get_entry_id()) {
            return e->label;
        }
    }
    return 0;
}
void TWindowMenuInfomation::mark_entry_by_id(s32 entry_id) {
    s32 i;
    LabelValueRow *e;
    for (i = 0; i < entry_capacity; i++) {
        e = (LabelValueRow *)get_array_entry(i);
        if (e != 0 && e->is_flag_4_set() != 0 && entry_id == e->get_entry_id()) {
            e->flags |= 1;
            e->color = -1;
        }
    }
}
void TWindowMenuInfomation::disable_entry_by_id(s32 id) {
    s32 i;
    LabelValueRow *e;
    for (i = 0; i < entry_capacity; i++) {
        e = (LabelValueRow *)get_array_entry(i);
        if (e != 0 && e->is_flag_4_set() != 0 && id == e->get_entry_id()) {
            e->flags &= 0xFFFE;
            e->color = 0xFF909090;
        }
    }
}
void TWindowMenuInfomation::set_entry_string_by_id(const char *string, s32 entry_id) {
    s32 i;
    LabelValueRow *e;
    for (i = 0; i < entry_capacity; i++) {
        e = (LabelValueRow *)get_array_entry(i);
        if (e != 0 && e->is_flag_4_set() != 0 && entry_id == e->get_entry_id()) {
            e->set_string(string);
        }
    }
}

void TWindowMenuInfomation::update_next_entry(const char *label, const char *string, s32 id) {
    s16 next_row;

    next_row = next_entry;
    if (next_row < entry_capacity) {
        ((LabelValueRow *)(get_array_entry(next_row)))->set_text(label, string, id);
        ++next_entry;
    }
}

void TWindowMenuInfomation::add_text_entry(const char *label_text, s32 id) {
    s16 next_row;

    next_row = next_entry;
    if (next_row < entry_capacity) {
        ((LabelValueRow *)(get_array_entry(next_row)))->set_text(label_text, id);
        ++next_entry;
    }
}
