#include "pso/ui/window/WindowVertexBufferAbi.h"
#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TWindowWordSelectMode.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD_WS_ScrollBar.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowDD_8034435C.h"
#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/window/TWindowDD_80342428.h"
#include "pso/ui/window/TWindowDD_80347F34.h"
#include "pso/unk/text_8020C354.h"
#include "pso/network/client_id.h"


#include <stddef.h>
#include <string.h>
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/NinjaTypes.h"

s32 TWindowDD::window_mode;

uaddr TWindowDD::work_buffer;

char *window_dd_buffer_a;

char *window_dd_buffer_b;

uaddr TWindowDD__player_name_buffers;

uaddr TWindowDD__word_select_lists;

uaddr lbl_805D6E20;

s16 lbl_805D6E24;

char **TWindowDD__data_805D6E28;

TWindowDDValueList *TWindowDD::ws_data_base;

TWindowDDValueList *TWindowDD::ws_data_table;

u32 lbl_805D6E34;
extern "C" {
void advance_word_select_level(TWindowDD *window_dd);
void TWindowDD__sub_80342800(TWindowDD *window_dd);
void update__9TWindowDDFi(TWindowDD *window_dd);
void TWindowDD__sub_803429B0(TWindowDD *window_dd);
void TWindowDD__sub_80342D14(TWindowDD *window_dd);
void run_state__9TWindowDDFPv(TWindowDD *window_dd);
TWindowDD_WS_Word *commit_word_select_level(TWindowDD *window_dd);
void pop_menu_level__9TWindowDDFPv(TWindowDD *window);
void refresh_word_select_message(void *, void *);


extern const f32 lbl_805DFB7C;

extern const f32 lbl_805DFB80;

extern const f32 lbl_805DFB88;

extern const f32 TWindowDD__data_805DFBFC;

extern const f32 lbl_805DFC0C;

extern const f32 TWindowDD__data_805DFC10;
void take_word_select_word(TWindowDD *window_dd, TWindowDD_WS_Word *page);
TWindowDD_WS_Word *get_or_create_word_select_child(TWindowDD *window_dd, s32 offset, s32 id);
void create_word_select_cursor_label(TWindowDD *window_dd, s32 index);

extern const f32 lbl_805DFB90;
s32 is_word_select_cancel_input(void *);
s32 finish_word_select(void *);
const char *word_select_type_name_pointer = "TWindowDD";



extern char *lbl_805D6E64;

extern s8 lbl_805D6E68;

extern char *lbl_805D6E6C;

extern s8 lbl_805D6E70;


extern const f32 lbl_805DFB60;

extern const f32 lbl_805DFB64;

extern const f32 lbl_805DFB68;

extern const f32 lbl_805DFBA4;

extern const f32 lbl_805DFBA8;

extern const f32 lbl_805DFBAC;

extern const f32 lbl_805DFBB0;

extern const f32 lbl_805DFBB4;

extern const f32 lbl_805DFBB8;

extern const f32 lbl_805DFBD0;

extern const f32 lbl_805DFBD4;

extern const f32 lbl_805DFBD8;

extern const f32 lbl_805DFBF0;

extern const f32 lbl_805DFBF4;

extern const f32 lbl_805DFBF8;


extern const f32 lbl_805DFC28;



s32 classify_id__9TWindowDDFs();
}


void clear_window_dd_nodes(void);
extern "C" {





extern uaddr ws_data_jp;

extern uaddr ws_data_us;

extern uaddr ws_data_es;

extern uaddr ws_data_de;


struct WordList_80344114 { u8 *words; s32 count; };
extern "C++" void ws_data_load(void);


extern NJS_POINT2 TWindowDD__data_805434E8[][8];

extern const NJS_POINT2 window_dd_quad_positions[];

extern const f32 window_dd_quad_scales[];

extern const f32 TWindowDD__data_805DFB18;

extern const f32 lbl_805DFB24;

extern const f32 lbl_805DFB28;

#pragma push
#pragma opt_common_subs off
void TWindowDD__sub_80344114(void) {
    s32 i;
    u8 *list;
    s32 j;
    WordList_80344114 *entry;
    const NJS_POINT2 *src;
    NJS_POINT2 *pt;
    f32 x;
    f32 y;
    f32 x2;
    f32 dy;

    TWindowDD__data_805D6E28 = 0;
    TWindowDD::ws_data_base = 0;
    TWindowDD::ws_data_table = 0;
    lbl_805D6E34 = 0;
    TWindowDD__data_805D6E40 = 0;
    TWindowDD__data_805D6E44 = 0;
    TWindowDD__data_805D6E48 = 0;
    lbl_805D6E4C = 0;
    ws_data_jp = 0;
    ws_data_us = 0;
    ws_data_es = 0;
    ws_data_de = 0;
    TWindowDD::ws_data_buffer = 0;
    TWindowDD::window_mode = current_language;
    if (TWindowDD::window_mode < 0 || TWindowDD::window_mode >= 5) {
        TWindowDD::window_mode = 0;
    }
    ws_data_load();
    TWindowDD::work_buffer = (uaddr)mem_alloc(0x80);
    window_dd_buffer_a = (char *)mem_alloc(0x80);
    memset((void *)TWindowDD::work_buffer, 0, 0x80);
    memset(window_dd_buffer_a, 0, 0x80);
    window_dd_buffer_b = (char *)mem_alloc(0x120);
    memset(window_dd_buffer_b, 0, 0x120);
    TWindowDD__player_name_buffers = (uaddr)mem_alloc(0x30);
    for (i = 0; i < 12; i++) {
        ((char **)TWindowDD__player_name_buffers)[i] = window_dd_buffer_b + i * 0x18;
        ((char **)TWindowDD__player_name_buffers)[i][0] = 0;
    }
    lbl_805D6E20 = (uaddr)mem_alloc(0x100);
    TWindowDD__word_select_lists = (uaddr)mem_alloc(0x30);
    list = (u8 *)lbl_805D6E20;
    for (j = 0; j < 6; j++) {
        entry = &((WordList_80344114 *)TWindowDD__word_select_lists)[j];
        entry->words = list;
        entry->count = 0;
        switch (j) {
        case 0:
        case 1:
            list += 0x40;
            break;
        default:
            list += 0x20;
            break;
        }
    }
    lbl_805D6E24 = -1;
    for (i = 0; i < 6; i++) {
        src = &window_dd_quad_positions[i];
        fill_window_point_table(TWindowDD__data_805434E8[i], src->x, src->y, window_dd_quad_scales[i]);
    }
    pt = TWindowDD__data_805434E8[6];
    x2 = window_dd_quad_positions[6].x;
    y = window_dd_quad_positions[6].y;
    x = x2 * TWindowDD__data_805DFB18;
    y *= TWindowDD__data_805DFB18;
    x2 = TWindowDD__data_805DFB18 * (x2 + lbl_805DFB24);
    dy = lbl_805DFB28 * TWindowDD__data_805DFB18;
    for (i = 0; i < 4; i++) {
        pt[0].x = x;
        pt[0].y = y;
        pt[1].x = x2;
        pt[1].y = y;
        y += dy;
        pt += 2;
    }
    TWindowDD::init_ws_data_tables();
}

void TWindowDD::free_buffers() {
    clear_window_dd_nodes();
    if ((u32) TWindowDD__word_select_lists != 0U) {
        mem_free((void*)TWindowDD__word_select_lists);
        TWindowDD__word_select_lists = 0U;
    }
    if ((u32) lbl_805D6E20 != 0U) {
        mem_free((void*)lbl_805D6E20);
        lbl_805D6E20 = 0U;
    }
    if ((u32) TWindowDD__player_name_buffers != 0U) {
        mem_free((void*)TWindowDD__player_name_buffers);
        TWindowDD__player_name_buffers = 0U;
    }
    if (window_dd_buffer_b != NULL) {
        mem_free(window_dd_buffer_b);
        window_dd_buffer_b = NULL;
    }
    if (window_dd_buffer_a != NULL) {
        mem_free(window_dd_buffer_a);
        window_dd_buffer_a = NULL;
    }
    if ((u32) TWindowDD::work_buffer != 0U) {
        mem_free((void*)TWindowDD::work_buffer);
        TWindowDD::work_buffer = 0U;
    }
    if (TWindowDD::ws_data_buffer != NULL) {
        TLobby::free_nodes_with_id((uaddr)((void*)TWindowDD::ws_data_buffer));
        TWindowDD::ws_data_buffer = NULL;
    }
    if ((u32) ws_data_de != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)ws_data_de));
        ws_data_de = 0U;
    }
    if ((u32) ws_data_es != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)ws_data_es));
        ws_data_es = 0U;
    }
    if ((u32) ws_data_us != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)ws_data_us));
        ws_data_us = 0U;
    }
    if ((u32) ws_data_jp != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)ws_data_jp));
        ws_data_jp = 0U;
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
  m_name = word_select_type_name_pointer;
  menu_index = (floor = lbl_805D6E24);
  build_item_list();
  *((u8 *) TWindowDD::work_buffer) = 0;
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
  list_ids[0] = get_initial_word_select_list(this);
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
    init_layout(this, page);
    word_windows[1] = page;
  }
  if (!lbl_805D6E68)
  {
    lbl_805D6E64 = "SELECT";
    lbl_805D6E68 = 1;
  }
  if (!lbl_805D6E70)
  {
    lbl_805D6E6C = "NEXT";
    lbl_805D6E70 = 1;
  }
  {
    s32 i;
    for (i = 0; i < 6; i++)
    {
      labels[i] = 0;
    }
  }
  {
    a.x = lbl_805DFBA4;
    a.y = lbl_805DFBA8;
    b.x = lbl_805DFB60;
    b.y = lbl_805DFBA8;
    labels[0] = TWindowDD_WS_String::create(lbl_805DFBAC, &a.x, &b.x, (uaddr) lbl_805D6E64, 4);
  }
  {
    a.x = lbl_805DFBB0;
    a.y = lbl_805DFBB4;
    b.x = lbl_805DFB64;
    b.y = lbl_805DFBB4;
    labels[1] = TWindowDD_WS_String::create(lbl_805DFBB8, &a.x, &b.x, (uaddr) lbl_805D6E6C, 4);
  }
  {
    a.x = lbl_805DFBD0;
    a.y = lbl_805DFBD4;
    b.x = lbl_805DFBD0;
    b.y = lbl_805DFB68;
    TWindowDD_WS_String *prompt = TWindowDD_WS_String::create(lbl_805DFBD8, &a.x, &b.x, get_word_select_token_text(0x687), 5);
    labels[2] = prompt;
    if (prompt != 0)
    {
      prompt->fit_width_to_text();
    }
  }
  TWindowDD::format_message(&message, reinterpret_cast<char *>(TWindowDD::work_buffer), local_client_id);
  {
    a.x = lbl_805DFBF0;
    a.y = lbl_805DFBF4;
    b.x = lbl_805DFB60;
    b.y = lbl_805DFBF4;
    text = TWindowDD_WS_String::create(lbl_805DFBF8, &a.x, &b.x, TWindowDD::work_buffer, 0);
    labels[3] = text;
    if (text != 0)
    {
      text->fit_width_to_text();
      text->update_position(0);
      text->target_position[0] = lbl_805DFB60;
      text->frame_position[0] = lbl_805DFB60;
      text->target_position[1] = lbl_805DFBF4;
      text->frame_position[1] = lbl_805DFBF4;
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
extern "C" {
void copy_chat_entry__9TWindowDDFPvPv(WordSelectMessage *body, WordSelectMessage *src) {
    u32 a, b;
    body->count = src->count;
    body->type = src->type;
    b = ((u32 *)src->ids)[0]; a = ((u32 *)src->ids)[1]; ((u32 *)body->ids)[0] = b; ((u32 *)body->ids)[1] = a;
    b = ((u32 *)src->ids)[2]; a = ((u32 *)src->ids)[3]; ((u32 *)body->ids)[2] = b; ((u32 *)body->ids)[3] = a;
    body->numeric_parameter = src->numeric_parameter;
    body->unknown_a4 = src->unknown_a4;
}
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
                    finish_word_select(this);
                    copy_chat_entry__9TWindowDDFPvPv(output, &final_message);
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
        } else if (is_word_select_cancel_input(this) != 0) {
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
                refresh_word_select_message(this, &message);
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
                copy_chat_entry__9TWindowDDFPvPv(&final_message, &message);
                if (final_message.count > 0) {
                    final_message.count--;
                    refresh_word_select_message(this, &final_message);
                }
            } else {
                run_state__9TWindowDDFPv(this);
                result_flags = 0;
            }
            break;
        case 1:
            if (word_windows[depth + 1] != NULL && word_windows[depth + 1]->tween_ticks == 0) {
                advance_word_select_level(this);
                pending_transition = 0;
            }
            break;
        case 2:
            if (word_windows[depth]->tween_ticks == 0) {
                pop_menu_level__9TWindowDDFPv(this);
                pending_transition = 0;
            }
            break;
        }
        break;
    }
}

void run_state__9TWindowDDFPv(TWindowDD *window_dd) {
    switch (window_dd->state) {
    case 0:
        window_dd->handle_confirm_input();
        return;
    case 1:
    case 2:
        window_dd->update();
        return;
    case 3:
        TWindowDD__sub_80342D14(window_dd);
        return;
    case 5:
        window_dd->update_transition();
        return;
    case 6:
        window_dd->update_layout();
        return;
    case 7:
        window_dd->update_dispatch();
        return;
    case 8:
        window_dd->enter_state_9();
        return;
    case 9:
        TWindowDD__sub_803429B0(window_dd);
        return;
    case 12:
        update__9TWindowDDFi(window_dd);
        return;
    case 13:
        TWindowDD__sub_80342800(window_dd);
        return;
    case 14:
        window_dd->update_state();
        return;
    case 15:
        window_dd->enter_state_16();
        return;
    case 17:
        window_dd->enter_state_18();
        return;
    case 18:
        window_dd->enter_state_19();
        return;
    case 20:
        window_dd->handle_input();
        return;
    case 10:
    case 11:
    case 16:
    case 19:
        TWindowDD__sub_80342428(window_dd);
    default:
        return;
    }
}

void begin_word_select_state(TWindowDD *window_dd) {
    TWindowDDStateEntry *entry;
    TWindowDDStateEntry *next_entry;
    s32 next;
    s32 entry_flags;
    TWindowDD_WS_Word *word_window;
    TWindowDD_WS_Word *created;
    next = window_dd->next_state;
    if ((next == 0x14) || (next == 0xC)) {
        TWindowDD::build_player_word_lists();
    }
    window_dd->dialog_locked = 0;
    if (window_dd->next_state == 1 || window_dd->next_state == 2 || window_dd->next_state == 8 || window_dd->next_state == 0xF || window_dd->next_state == 0x11) {
        window_dd->message.reset_numeric_parameter();
    }
    entry = window_dd->get_state_entry(window_dd->state);
    next_entry = window_dd->get_state_entry(window_dd->next_state);
    word_window = window_dd->word_windows[window_dd->depth];
    if (word_window != NULL) {
        word_window->target_position[0] = lbl_805DFB90;
        word_window->target_size[0] = word_page_width;
        word_window->tween_ticks = window_dd_tween_ticks;
        if (entry->flags & 4) {
            create_word_select_cursor_label(window_dd, window_dd->extra_window_count++);
        }
    }
    created = get_or_create_word_select_child(window_dd, 1, window_dd->list_ids[1]);
    if (created != NULL) {
        created->set_pos_and_data(word_page_x);
        if (next_entry->flags & 1) {
            created->target_size[0] = lbl_805DFB7C;
            if (window_dd->mode_window != NULL) {
                window_dd->mode_window->target_position[0] = lbl_805DFC0C;
                window_dd->mode_window->tween_ticks = window_dd_tween_ticks;
            }
        } else {
            created->target_size[0] = word_page_width;
            if (window_dd->mode_window != NULL) {
                window_dd->mode_window->target_position[0] = TWindowDD__data_805DFBFC;
                window_dd->mode_window->tween_ticks = window_dd_tween_ticks;
            }
        }
        if (next_entry->flags & 2) {
            take_word_select_word(window_dd, created);
        }
    }
    entry_flags = next_entry->flags;
    if (!(entry_flags & 8)) {
        if (entry_flags & 1) {
            window_dd->list_ids[2] = dispatch_by_window_mode(window_dd, window_dd->next_state, window_dd->list_ids[1], 0);
            if ((word_window = get_or_create_word_select_child(window_dd, 2, window_dd->list_ids[2])) != NULL) {
                word_window->set_pos_and_data(TWindowDD__data_805DFC10);
            }
            TWindowDD__sub_80347F48(window_dd);
        } else {
            window_dd->list_ids[2] = dispatch_by_window_mode(window_dd, window_dd->next_state, window_dd->list_ids[1], 0);
            if ((word_window = get_or_create_word_select_child(window_dd, 2, window_dd->list_ids[2])) != NULL) {
                word_window->set_pos_and_data(lbl_805DFB80);
            }
            window_dd->init_entry_field_64(1);
        }
    } else {
        update_word_select_child_position(window_dd, 1);
    }
    if (next_entry->prompt_id == -1) {
        update_word_select_child_position(window_dd, 2);
    } else {
        window_dd->setup_entry(next_entry->prompt_id);
        window_dd->init_entry_field_64(2);
    }
    window_dd->pending_transition = 1;
}

void advance_word_select_level(TWindowDD *window_dd) {
    window_dd->word_windows[window_dd->depth]->free_child();
    TWindowDD::apply_input(window_dd, window_dd->word_windows[window_dd->depth]);
    window_dd->level_states[window_dd->depth] = window_dd->state;
    window_dd->depth++;
    window_dd->update(window_dd->word_windows[window_dd->depth]);
    window_dd->state = window_dd->next_state;
    window_dd->list_ids[0] = window_dd->list_ids[1];
    window_dd->list_ids[1] = window_dd->list_ids[2];
    window_dd->list_ids[2] = -1;
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
            w->target_size[0] = lbl_805DFB7C;
            if (mode_window != NULL) {
                mode_window->target_position[0] = lbl_805DFC0C;
                mode_window->tween_ticks = window_dd_tween_ticks;
            }
        } else {
            w->target_size[0] = word_page_width;
            if (mode_window != NULL) {
                mode_window->target_position[0] = TWindowDD__data_805DFBFC;
                mode_window->tween_ticks = window_dd_tween_ticks;
            }
        }
    }
    child = word_windows[depth];
    if (child != NULL) {
        if (entry->flags & 8) {
            set_item_pos(0);
            update_word_select_child_position(this, 1);
        } else if (entry->flags & 1) {
            child->set_pos_and_data(TWindowDD__data_805DFC10);
            child->target_size[0] = lbl_805DFB88;
            TWindowDD__sub_80347F48(this);
        } else {
            child->set_pos_and_data(lbl_805DFB80);
            child->target_size[0] = lbl_805DFB88;
            init_entry_field_64(1);
        }
        if (prev->flags & 2) {
            message.pop_token();
            refresh_word_select_message(this, &message);
        }
    }
    set_item_pos(1);
    if (!(entry->flags & 2)) {
        update_word_select_child_position(this, 3);
    }
    if (entry->flags & 4) {
        if (extra_window_count > 0) {
            update_word_select_child_position(this, extra_window_count + 3);
        }
    }
    id = entry->prompt_id;
    if (id == -1) {
        update_word_select_child_position(this, 2);
    } else {
        setup_entry(id);
        init_entry_field_64(2);
    }
    pending_transition = 2;
}

void pop_menu_level__9TWindowDDFPv(TWindowDD *window) {
    TWindowDDStateEntry *entry;
    TWindowDD_WS_Word *child;
    window->get_state_entry(window->state);
    entry = window->get_state_entry(window->level_states[window->depth - 1]);
    commit_word_select_level(window);
    if (entry->flags & 8) {
        window->destroy_menu_entry(0);
    } else if ((child = window->word_windows[window->depth]) != NULL) {
        TWindowDD::update(window, child);
    }
    window->destroy_menu_entry(1);
    window->depth--;
    if (entry->flags & 4) {
        window->extra_window_count--;
        if (window->extra_window_count >= 0 && window->labels[window->extra_window_count + 4] != NULL) {
            window->labels[window->extra_window_count + 4]->queue_destruction();
            window->labels[window->extra_window_count + 4] = NULL;
        }
    }
    window->list_ids[2] = window->list_ids[1];
    window->list_ids[1] = window->list_ids[0];
    window->list_ids[0] = window->word_windows[window->depth]->get_element_list_id();
    window->state = window->level_states[window->depth];
    if (window->state == 0xD) {
        window->message.type = 4;
    }
}

void open_numeric_parameter_input__9TWindowDDFPviii(TWindowDD *self, s32 minimum, s32 maximum, s32 initial) {
    NJS_POINT2 position;
    position.x = 60.0f + word_page_x;
    position.y = 10.0f + word_page_y;
    self->number_window = new TWindowInputNumber(&position, minimum, maximum, initial, (s16)local_client_id);
    if (self->number_window) {
        self->number_window->set_depth(lbl_805DFC28);
        ((TWindowSubItem *)(self->number_window))->set_flag60_bit10();
        self->word_windows[self->depth]->disable_input();
    }
}

s32 TWindowDD::update_close_flag() {
    get_current_child_index();
    if (classify_id__9TWindowDDFs() != 7) {
        dialog_locked = 1;
        return 1;
    }
    return 0;
}
}
