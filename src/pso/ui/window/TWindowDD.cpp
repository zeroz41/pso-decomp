#include "pso/ui/window/WindowVertexBufferAbi.h"
#pragma defer_codegen on

#include "pso/ui/window/TWindowWordSelectMode.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD_WS_ScrollBar.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/map/FloorPopulation.h"
#include "pso/network/client_id.h"


#include <stddef.h>
#include <string.h>
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"

TWindowDDStateEntry word_select_state_table[21] = {
    { 0x04, 0x687 },
    { 0x03, -1 },
    { 0x0b, -1 },
    { 0x03, -1 },
    { 0x03, -1 },
    { 0x02, 0x689 },
    { 0x03, -1 },
    { 0x04, 0x68a },
    { 0x02, -1 },
    { 0x02, -1 },
    { 0x03, -1 },
    { 0x0b, -1 },
    { 0x04, 0x68a },
    { 0x02, 0x68b },
    { 0x02, -1 },
    { 0x02, -1 },
    { 0x0b, -1 },
    { 0x02, 0x688 },
    { 0x02, -1 },
    { 0x0b, -1 },
    { 0x0b, 0x688 },
};

const s32 word_select_numeric_limits[6] = { 999999, 99, 30, 15, 200, 999 };

extern "C" {
s32 get_word_next_state(TWindowDD *window, s32 id);
s32 get_word_message_type(TWindowDD *window, s16 id);
void push_recent_id(s16 id);
}



s32 TWindowDD::window_mode;

char *TWindowDD::work_buffer;

char *window_dd_buffer_a;

char *window_dd_buffer_b;

char **TWindowDD::player_name_buffers;

TWindowDDValueList *TWindowDD::word_select_lists;

s16 *word_select_word_storage;

s16 remembered_word_select_id;

char **ws_word_strings;

TWindowDDValueList *TWindowDD::ws_data_base;

TWindowDDValueList *TWindowDD::ws_data_table;

s16 *ws_word_string_index;
const char *TWindowDD::class_name = "TWindowDD";


#pragma push
#pragma opt_common_subs off
void load_word_select_data(void) {
    s32 i;
    s16 *list;
    s32 j;
    TWindowDDValueList *entry;
    const NJS_POINT2 *src;
    NJS_POINT2 *pt;
    f32 x;
    f32 y;
    f32 x2;
    f32 dy;

    ws_word_strings = 0;
    TWindowDD::ws_data_base = 0;
    TWindowDD::ws_data_table = 0;
    ws_word_string_index = 0;
    ws_word_variant_lists = 0;
    ws_word_form_lists = 0;
    ws_word_form_index = 0;
    ws_spanish_prefix_categories = 0;
    ws_data_jp = 0;
    ws_data_us = 0;
    ws_data_es = 0;
    ws_data_de = 0;
    TWindowDD::ws_data_fr = 0;
    TWindowDD::window_mode = current_language;
    if (TWindowDD::window_mode < 0 || TWindowDD::window_mode >= 5) {
        TWindowDD::window_mode = 0;
    }
    ws_data_load();
    TWindowDD::work_buffer = new char[0x80];
    window_dd_buffer_a = new char[0x80];
    memset(TWindowDD::work_buffer, 0, 0x80);
    memset(window_dd_buffer_a, 0, 0x80);
    window_dd_buffer_b = new char[0x120];
    memset(window_dd_buffer_b, 0, 0x120);
    TWindowDD::player_name_buffers = new char *[12];
    for (i = 0; i < 12; i++) {
        TWindowDD::player_name_buffers[i] = window_dd_buffer_b + i * 0x18;
        TWindowDD::player_name_buffers[i][0] = 0;
    }
    word_select_word_storage = new s16[128];
    TWindowDD::word_select_lists = new TWindowDDValueList[6];
    list = word_select_word_storage;
    for (j = 0; j < 6; j++) {
        entry = &TWindowDD::word_select_lists[j];
        entry->values = list;
        entry->count = 0;
        switch (j) {
        case 0:
        case 1:
            list += 0x20;
            break;
        default:
            list += 0x10;
            break;
        }
    }
    remembered_word_select_id = -1;
    for (i = 0; i < 6; i++) {
        src = &window_dd_quad_positions[i];
        fill_window_point_table(word_select_quad_points[i], src->x, src->y, window_dd_quad_scales[i]);
    }
    pt = word_select_quad_points[6];
    x2 = window_dd_quad_positions[6].x;
    y = window_dd_quad_positions[6].y;
    x = x2 * window_dd_texel_scale;
    y *= window_dd_texel_scale;
    x2 = window_dd_texel_scale * (x2 + scroll_bar_tile_width);
    dy = scroll_bar_tile_height * window_dd_texel_scale;
    for (i = 0; i < 4; i++) {
        pt[0].x = x;
        pt[0].y = y;
        pt[1].x = x2;
        pt[1].y = y;
        y += dy;
        pt += 2;
    }
    init_ws_data_tables();
}
extern "C" {

void TWindowDD::free_buffers() {
    clear_window_dd_nodes();
    if (TWindowDD::word_select_lists != NULL) {
        delete[] TWindowDD::word_select_lists;
        TWindowDD::word_select_lists = NULL;
    }
    if (word_select_word_storage != NULL) {
        delete[] word_select_word_storage;
        word_select_word_storage = NULL;
    }
    if (TWindowDD::player_name_buffers != NULL) {
        delete[] TWindowDD::player_name_buffers;
        TWindowDD::player_name_buffers = NULL;
    }
    if (window_dd_buffer_b != NULL) {
        delete[] window_dd_buffer_b;
        window_dd_buffer_b = NULL;
    }
    if (window_dd_buffer_a != NULL) {
        delete[] window_dd_buffer_a;
        window_dd_buffer_a = NULL;
    }
    if (TWindowDD::work_buffer != NULL) {
        delete[] TWindowDD::work_buffer;
        TWindowDD::work_buffer = NULL;
    }
    if (TWindowDD::ws_data_fr != NULL) {
        TLobby::free_nodes_with_id(TWindowDD::ws_data_fr);
        TWindowDD::ws_data_fr = NULL;
    }
    if (ws_data_de != NULL) {
        TLobby::free_nodes_with_id(ws_data_de);
        ws_data_de = NULL;
    }
    if (ws_data_es != NULL) {
        TLobby::free_nodes_with_id(ws_data_es);
        ws_data_es = NULL;
    }
    if (ws_data_us != NULL) {
        TLobby::free_nodes_with_id(ws_data_us);
        ws_data_us = NULL;
    }
    if (ws_data_jp != NULL) {
        TLobby::free_nodes_with_id(ws_data_jp);
        ws_data_jp = NULL;
    }
}

TWindowDD::TWindowDD(TObject *parent, WordSelectMessage *result) : TObject(parent) {
  NJS_POINT2 a;
  NJS_POINT2 b;
  TObjPlayer *player;
  TWindowDD_WS_Word *page;
  TWindowDD_WS_String *text;
  s32 floor;
  s32 v;
  m_name = class_name;
  menu_index = (floor = remembered_word_select_id);
  build_item_list();
  *TWindowDD::work_buffer = 0;
  enemies_active = 0;
  {
    player = get_player_by_client_id(local_client_id);
    if (player != 0)
    {
      floor = get_current_floor();
      s32 r;
      v = player->get_room();
      if (is_boss_area() != 0)
      {
        r = TWindowDD::check_all_ready(floor);
      }
      else
      {
        r = is_room_free_of_active_enemies(floor, v);
      }
      if (r == 0)
      {
        enemies_active = 1;
      }
    }
  }
  TWindowDD::build_player_word_lists();
  output = result;
  message.init();
  final_message.init();
  scroll_bar = TWindowDD_WS_ScrollBar::create();
  {
    s32 i;
    for (i = 0; i < 8; i++)
    {
      word_windows[i] = 0;
      level_states[i] = 0;
    }
  }
  depth = 0;
  list_ids[0] = get_initial_word_select_list();
  list_ids[1] = -1;
  list_ids[2] = -1;
  {
    TWindowDD_WS_Word *first = TWindowDD_WS_Word::create(list_ids[0], (s32) window_dd_visible_rows);
    if (first != 0)
    {
      set_default_positions(first);
      word_windows[0] = first;
    }
  }
  level_states[0] = 0;
  page = TWindowDD_WS_Word::create(list_ids[1], (s32) window_dd_visible_rows);
  if (page != 0)
  {
    init_layout(page);
    word_windows[1] = page;
  }
  if (!word_page_select_label_set)
  {
    word_page_select_label = "SELECT";
    word_page_select_label_set = 1;
  }
  if (!word_page_next_label_set)
  {
    word_page_next_label = "NEXT";
    word_page_next_label_set = 1;
  }
  {
    s32 i;
    for (i = 0; i < 6; i++)
    {
      labels[i] = 0;
    }
  }
  {
    a.x = word_page_label_x;
    a.y = word_page_label_y;
    b.x = word_label_hidden_x;
    b.y = word_page_label_y;
    labels[0] = TWindowDD_WS_String::create(word_page_label_width, &a.x, &b.x, word_page_select_label, 4);
  }
  {
    a.x = next_word_page_label_x;
    a.y = next_word_page_label_y;
    b.x = word_label_hidden_right_x;
    b.y = next_word_page_label_y;
    labels[1] = TWindowDD_WS_String::create(next_word_page_label_width, &a.x, &b.x, word_page_next_label, 4);
  }
  {
    a.x = word_prompt_x;
    a.y = word_prompt_y;
    b.x = word_prompt_x;
    b.y = word_prompt_hidden_y;
    TWindowDD_WS_String *prompt = TWindowDD_WS_String::create(word_prompt_width, &a.x, &b.x, get_word_select_token_text(0x687), 5);
    labels[2] = prompt;
    if (prompt != 0)
    {
      prompt->fit_width_to_text();
    }
  }
  TWindowDD::format_message(&message, TWindowDD::work_buffer, local_client_id);
  {
    a.x = message_label_x;
    a.y = message_label_y;
    b.x = word_label_hidden_x;
    b.y = message_label_y;
    text = TWindowDD_WS_String::create(message_label_width, &a.x, &b.x, TWindowDD::work_buffer, 0);
    labels[3] = text;
    if (text != 0)
    {
      text->fit_width_to_text();
      text->update_position(0);
      text->target_position[0] = word_label_hidden_x;
      text->frame_position[0] = word_label_hidden_x;
      text->target_position[1] = message_label_y;
      text->frame_position[1] = message_label_y;
      text->target_size[0] = 2.0f;
      text->frame_size[0] = 2.0f;
    }
  }
  mode_window = TWindowWordSelectMode::create();
  number_window = 0;
  dialog_state = 0;
  pending_transition = 0;
  state = 0;
  next_state = 0;
  dialog_locked = 0;
  extra_window_count = 0;
  selected_word = 0x37;
  pad_100 = 0;
  result_flags = 0;
  token_pushed = 0;
  last_selected_id = -1;
  selection_confirmed = 0;
  pad_104 = 0;
}

#pragma pop

TWindowDD::~TWindowDD() {
    close_all_windows();
}
}

#pragma push
#pragma optimization_level 1
void TWindowDD::copy_chat_entry(WordSelectMessage *body, WordSelectMessage *src) {
    u32 a, b;
    body->count = src->count;
    body->type = src->type;
    b = ((u32 *)src->ids)[0]; a = ((u32 *)src->ids)[1]; ((u32 *)body->ids)[0] = b; ((u32 *)body->ids)[1] = a;
    b = ((u32 *)src->ids)[2]; a = ((u32 *)src->ids)[3]; ((u32 *)body->ids)[2] = b; ((u32 *)body->ids)[3] = a;
    body->numeric_parameter = src->numeric_parameter;
    body->unknown_a4 = src->unknown_a4;
}

#pragma pop
extern "C" {
void TWindowDD::run_task() {
    TWindowDD_WS_Word *cur;
    s32 done;
    if (mode_window != 0) {
        if (state == 0) {
            mode_window->set_clamped_page(2);
        } else if (message.count > 1) {
            mode_window->set_clamped_page(0);
        } else {
            mode_window->set_clamped_page(1);
        }
    }
    cur = word_windows[depth];
    if (scroll_bar != 0 && cur != NULL) {
        scroll_bar->set_first_index(cur->get_scroll_top());
    }
    switch (dialog_state) {
    case 2:
        break;
    case 1:
        mode_window->handle_input();
        done = 0;
        if (this->test_input_flag_4() != 0) {
            if (mode_window != 0) {
                switch (mode_window->get_selected_row()) {
                case 0:
                    TWindowDD::play_sound();
                    finish_word_select();
                    copy_chat_entry(output, &final_message);
                    break;
                case 1:
                    TWindowDD::play_se();
                    done = 1;
                    result_flags |= 2;
                    break;
                case 2:
                    TWindowDD::play_se();
                    this->set_state();
                    break;
                }
            }
        } else if (is_word_select_cancel_input() != 0) {
            TWindowDD::play_se();
            done = 1;
            result_flags |= 2;
        } else if (TWindowDD::apply_both_choices(&menu_index, 0x40) != 0) {
            TWindowDD::spawn_window();
            done = 1;
        }
        if (done != 0) {
            dialog_state = 0;
            mode_window->hide_selection();
            cur->enable_input();
            if (message.count > 0) {
                refresh_word_select_message(&message);
            }
        }
        break;
    case 0:
        switch (pending_transition) {
        case 0:
            if (dialog_locked != 1 && TWindowDD_check_input_mask(&menu_index, 0x80) != 0) {
                TWindowDD::spawn_window();
                dialog_state = 1;
                mode_window->set_clamped_selection(word_windows[depth]->get_selected_row());
                cur->disable_input();
                copy_chat_entry(&final_message, &message);
                if (final_message.count > 0) {
                    final_message.count--;
                    refresh_word_select_message(&final_message);
                }
            } else {
                run_state();
                result_flags = 0;
            }
            break;
        case 1:
            if (word_windows[depth + 1] != NULL && word_windows[depth + 1]->tween_ticks == 0) {
                advance_word_select_level();
                pending_transition = 0;
            }
            break;
        case 2:
            if (word_windows[depth]->tween_ticks == 0) {
                pop_menu_level();
                pending_transition = 0;
            }
            break;
        }
        break;
    }
}

void TWindowDD::run_state() {
    switch (state) {
    case 0:
        handle_confirm_input();
        return;
    case 1:
    case 2:
        update();
        return;
    case 3:
        handle_state_3();
        return;
    case 5:
        update_transition();
        return;
    case 6:
        update_layout();
        return;
    case 7:
        update_dispatch();
        return;
    case 8:
        enter_state_9();
        return;
    case 9:
        handle_state_9();
        return;
    case 12:
        handle_state_12();
        return;
    case 13:
        handle_state_13();
        return;
    case 14:
        update_state();
        return;
    case 15:
        enter_state_16();
        return;
    case 17:
        enter_state_18();
        return;
    case 18:
        enter_state_19();
        return;
    case 20:
        handle_input();
        return;
    case 10:
    case 11:
    case 16:
    case 19:
        handle_final_word_state();
    default:
        return;
    }
}

void TWindowDD::begin_word_select_state() {
    TWindowDDStateEntry *entry;
    TWindowDDStateEntry *next_entry;
    s32 next;
    s32 entry_flags;
    TWindowDD_WS_Word *word_window;
    TWindowDD_WS_Word *created;
    next = next_state;
    if ((next == 0x14) || (next == 0xC)) {
        TWindowDD::build_player_word_lists();
    }
    dialog_locked = 0;
    if (next_state == 1 || next_state == 2 || next_state == 8 || next_state == 0xF || next_state == 0x11) {
        message.reset_numeric_parameter();
    }
    entry = get_state_entry(state);
    next_entry = get_state_entry(next_state);
    word_window = word_windows[depth];
    if (word_window != NULL) {
        word_window->target_position[0] = word_page_exit_x;
        word_window->target_size[0] = word_page_width;
        word_window->tween_ticks = window_dd_tween_ticks;
        if (entry->flags & 4) {
            create_word_select_cursor_label(extra_window_count++);
        }
    }
    created = get_or_create_word_select_child(1, list_ids[1]);
    if (created != NULL) {
        created->set_pos_and_data(word_page_x);
        if (next_entry->flags & 1) {
            created->target_size[0] = wide_word_page_width;
            if (mode_window != NULL) {
                mode_window->target_position[0] = wide_mode_window_x;
                mode_window->tween_ticks = window_dd_tween_ticks;
            }
        } else {
            created->target_size[0] = word_page_width;
            if (mode_window != NULL) {
                mode_window->target_position[0] = mode_window_x;
                mode_window->tween_ticks = window_dd_tween_ticks;
            }
        }
        if (next_entry->flags & 2) {
            take_word_select_word(created);
        }
    }
    entry_flags = next_entry->flags;
    if (!(entry_flags & 8)) {
        if (entry_flags & 1) {
            list_ids[2] = dispatch_by_window_mode(this, next_state, list_ids[1], 0);
            if ((word_window = get_or_create_word_select_child(2, list_ids[2])) != NULL) {
                word_window->set_pos_and_data(wide_next_word_page_x);
            }
            move_next_label_after_wide_page();
        } else {
            list_ids[2] = dispatch_by_window_mode(this, next_state, list_ids[1], 0);
            if ((word_window = get_or_create_word_select_child(2, list_ids[2])) != NULL) {
                word_window->set_pos_and_data(next_word_page_x);
            }
            move_label_to_start(1);
        }
    } else {
        update_word_select_child_position(1);
    }
    if (next_entry->prompt_id == -1) {
        update_word_select_child_position(2);
    } else {
        setup_entry(next_entry->prompt_id);
        move_label_to_start(2);
    }
    pending_transition = 1;
}

void TWindowDD::advance_word_select_level() {
    word_windows[depth]->free_child();
    apply_input(word_windows[depth]);
    level_states[depth] = state;
    depth++;
    update(word_windows[depth]);
    state = next_state;
    list_ids[0] = list_ids[1];
    list_ids[1] = list_ids[2];
    list_ids[2] = -1;
}

void TWindowDD::apply_entry_layout() {
    TWindowDDStateEntry *prev;
    TWindowDDStateEntry *entry;
    TWindowDD_WS_Word *w;
    TWindowDD_WS_Word *child;
    s32 id;
    prev = get_state_entry(state);
    entry = get_state_entry(level_states[depth - 1]);
    w = init_last_child();
    if (w != NULL) {
        if (entry->flags & 1) {
            w->target_size[0] = wide_word_page_width;
            if (mode_window != NULL) {
                mode_window->target_position[0] = wide_mode_window_x;
                mode_window->tween_ticks = window_dd_tween_ticks;
            }
        } else {
            w->target_size[0] = word_page_width;
            if (mode_window != NULL) {
                mode_window->target_position[0] = mode_window_x;
                mode_window->tween_ticks = window_dd_tween_ticks;
            }
        }
    }
    child = word_windows[depth];
    if (child != NULL) {
        if (entry->flags & 8) {
            set_item_pos(0);
            update_word_select_child_position(1);
        } else if (entry->flags & 1) {
            child->set_pos_and_data(wide_next_word_page_x);
            child->target_size[0] = next_word_page_width;
            move_next_label_after_wide_page();
        } else {
            child->set_pos_and_data(next_word_page_x);
            child->target_size[0] = next_word_page_width;
            move_label_to_start(1);
        }
        if (prev->flags & 2) {
            message.pop_token();
            refresh_word_select_message(&message);
        }
    }
    set_item_pos(1);
    if (!(entry->flags & 2)) {
        update_word_select_child_position(3);
    }
    if (entry->flags & 4) {
        if (extra_window_count > 0) {
            update_word_select_child_position(extra_window_count + 3);
        }
    }
    id = entry->prompt_id;
    if (id == -1) {
        update_word_select_child_position(2);
    } else {
        setup_entry(id);
        move_label_to_start(2);
    }
    pending_transition = 2;
}

void TWindowDD::pop_menu_level() {
    TWindowDDStateEntry *entry;
    TWindowDD_WS_Word *child;
    get_state_entry(state);
    entry = get_state_entry(level_states[depth - 1]);
    commit_word_select_level();
    if (entry->flags & 8) {
        destroy_menu_entry(0);
    } else if ((child = word_windows[depth]) != NULL) {
        dim_next_page(child);
    }
    destroy_menu_entry(1);
    depth--;
    if (entry->flags & 4) {
        extra_window_count--;
        if (extra_window_count >= 0 && labels[extra_window_count + 4] != NULL) {
            labels[extra_window_count + 4]->queue_destruction();
            labels[extra_window_count + 4] = NULL;
        }
    }
    list_ids[2] = list_ids[1];
    list_ids[1] = list_ids[0];
    list_ids[0] = word_windows[depth]->get_element_list_id();
    state = level_states[depth];
    if (state == 0xD) {
        message.type = 4;
    }
}

void TWindowDD::open_numeric_parameter_input(s32 minimum, s32 maximum, s32 initial) {
    NJS_POINT2 position;
    position.x = 60.0f + word_page_x;
    position.y = 10.0f + word_page_y;
    number_window = new TWindowInputNumber(&position, minimum, maximum, initial, (s16)local_client_id);
    if (number_window) {
        number_window->set_depth(word_cursor_depth);
        number_window->set_flag_10();
        word_windows[depth]->disable_input();
    }
}

s32 TWindowDD::update_close_flag() {
    if (classify_id(get_current_child_index()) != 7) {
        dialog_locked = 1;
        return 1;
    }
    return 0;
}
}


s32 TWindowDD::update_numeric_parameter_input() {
    s32 kind;
    s32 result;
    result = 0;
    if (number_window == NULL) {
        kind = classify_id(get_current_child_index());
        if (kind != 7) {
            open_numeric_parameter_input(0, word_select_numeric_limits[kind], message.get_numeric_parameter());
            return 0;
        }
        return 1;
    }
    refresh_word_select_message(&message);
    if (number_window != NULL || number_window->all_parents_unqueued_for_destruction() != 0) {
        message.set_numeric_parameter(number_window->get_value());
        if (number_window->is_cancelled() != 0) {
            result = 2;
            message.reset_numeric_parameter();
            number_window->close();
        } else if (number_window->is_confirmed() != 0) {
            result = 1;
            number_window->close();
        }
    } else {
        result = 2;
    }
    if (result != 0) {
        word_windows[depth]->enable_input();
        number_window = NULL;
        dialog_locked = 0;
    }
    return result == 1;
}

void TWindowDD::handle_confirm_input() {
    s16 id;
    refresh_word_select_child_list();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        id = word_windows[depth]->get_selected_id();
        message.type = get_word_message_type(this, id);
        next_state = get_word_next_state(this, id);
        push_recent_id(id);
        pad_104 = 0;
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        set_state();
    }
}

void TWindowDD::update() {
    this->update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        if (state == 1) {
            next_state = 0x14;
            list_ids[1] = -0x3C;
            begin_word_select_state();
            return;
        }
        finish_word_select();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}

void TWindowDD::handle_state_3() {
    s32 done;
    done = 0;
    message.type = 1;
    switch (dialog_locked) {
    case 0:
        refresh_word_select_child_list();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            done = !update_close_flag();
        } else if (is_word_select_cancel_input() != 0) {
            TWindowDD::play_se();
            selection_confirmed = 0;
            apply_entry_layout();
        }
        break;
    case 1:
        done = update_numeric_parameter_input();
        break;
    }
    if (done) {
        selection_confirmed = 1;
        if (list_ids[1] == -0x3C) {
            next_state = 0x14;
        } else {
            switch (TWindowDD::window_mode) {
            case 0:
                store_selected_word_plain();
                message.init();
                message.type = 3;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            default:
                message.init();
                message.type = 4;
                store_selected_word();
                break;
            }
        }
        begin_word_select_state();
    }
}

void TWindowDD::update_transition() {
    refresh_word_select_child_list();
    update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        next_state = 6;
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}

void TWindowDD::update_layout() {
    this->update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        next_state = 0x14;
        list_ids[1] = -0x3C;
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}

void TWindowDD::update_dispatch() {
    refresh_word_select_child_list();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        store_selected_word_plain();
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_sound();
        apply_entry_layout();
    }
}

void TWindowDD::store_selected_word_plain() {
    TWindowDD_WS_Word *word_window;
    next_state = 8;
    selected_word = 0x37;
    word_window = word_windows[depth];
    if (word_window != NULL) {
        selected_word = word_window->get_selected_id();
    }
}

void TWindowDD::enter_state_9() {
    s32 confirmed;

    confirmed = 0;
    switch (dialog_locked) {
    case 0:
        refresh_word_select_child_list();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            confirmed = update_close_flag() == 0;
        } else if (is_word_select_cancel_input() != 0) {
            TWindowDD::play_se();
            apply_entry_layout();
        }
        break;
    case 1:
        confirmed = update_numeric_parameter_input();
        break;
    }
    if (confirmed != 0) {
        next_state = 9;
        begin_word_select_state();
    }
}

void TWindowDD::handle_state_9() {
    s32 done;
    done = 0;
    switch (dialog_locked) {
    case 0:
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            done = update_close_flag() == 0;
        } else if (is_word_select_cancel_input() != 0) {
            TWindowDD::play_se();
            apply_entry_layout();
        }
        break;
    case 1:
        done = update_numeric_parameter_input();
        break;
    }
    if (done != 0) {
        if (is_verb_word(word_windows[depth]->get_selected_id()) != 0) {
            next_state = 0xA;
        } else {
            next_state = 0xB;
            list_ids[2] = -1;
        }
        list_ids[1] = -0x32;
        begin_word_select_state();
    }
}

void TWindowDD::handle_state_12() {
    refresh_word_select_child_list();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        store_selected_word();
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}

void TWindowDD::store_selected_word() {
    TWindowDD_WS_Word *page;
    next_state = 0xD;
    selected_word = 0x37;
    page = word_windows[depth];
    if (page != NULL) {
        selected_word = page->get_selected_id();
        if (selected_word == 0x43) {
            next_state = 0x11;
            message.type = 5;
        }
        message.count = 0;
    }
}

void TWindowDD::handle_state_13() {
    refresh_word_select_child_list();
    update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        if (static_cast<s16>(word_windows[depth]->get_selected_id()) == 0x2C8) {
            next_state = 0x11;
            message.type = 5;
            message.count = 0;
        } else {
            next_state = 0xE;
            message.type = 4;
            message.count = 1;
        }
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}

void TWindowDD::update_state() {
    refresh_word_select_child_list();
    update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        next_state = 0xF;
        begin_word_select_state();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}

void TWindowDD::enter_state_16() {
    s32 done;

    done = 0;
    switch (dialog_locked) {
    case 0:
        refresh_word_select_child_list();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            done = update_close_flag() == 0;
        } else if (is_word_select_cancel_input() != 0) {
            TWindowDD::play_se();
            apply_entry_layout();
        }
        break;
    case 1:
        done = update_numeric_parameter_input();
        break;
    }
    if (done != 0) {
        next_state = 0x10;
        begin_word_select_state();
    }
}

void TWindowDD::enter_state_18() {
    s32 confirmed;

    confirmed = 0;
    switch (dialog_locked) {
    case 0:
        refresh_word_select_child_list();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            confirmed = update_close_flag() == 0;
        } else if (is_word_select_cancel_input() != 0) {
            TWindowDD::play_se();
            apply_entry_layout();
        }
        break;
    case 1:
        confirmed = update_numeric_parameter_input();
        break;
    }
    if (confirmed != 0) {
        next_state = 0x12;
        begin_word_select_state();
    }
}

void TWindowDD::enter_state_19() {
    s32 confirmed;

    confirmed = 0;
    switch (dialog_locked) {
    case 0:
        refresh_word_select_child_list();
        update_selection_state();
        if (test_input_flag_4() != 0) {
            TWindowDD::play_sound();
            confirmed = update_close_flag() == 0;
        } else if (is_word_select_cancel_input() != 0) {
            TWindowDD::play_se();
            apply_entry_layout();
        }
        break;
    case 1:
        confirmed = update_numeric_parameter_input();
        break;
    }
    if (confirmed != 0) {
        next_state = 0x13;
        begin_word_select_state();
    }
}

void TWindowDD::handle_input() {
    update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        finish_word_select();
        return;
    }
    if (is_word_select_cancel_input() != 0) {
        TWindowDD::play_se();
        apply_entry_layout();
    }
}

void TWindowDD::handle_final_word_state() {
  refresh_word_select_child_list();
  update_selection_state();
  if (test_input_flag_4())
  {
    TWindowDD::play_sound();
    if (state == 0xA)
    {
      if (static_cast<s16>(word_windows[depth]->get_selected_id()) == 0x685)
      {
        next_state = 0x14;
        list_ids[1] = -0x3C;
        begin_word_select_state();
        return;
      }
      finish_word_select();
      return;
    }
    finish_word_select();
    return;
  }
  if (is_word_select_cancel_input() != 0)
  {
    TWindowDD::play_se();
    apply_entry_layout();
  }
}
