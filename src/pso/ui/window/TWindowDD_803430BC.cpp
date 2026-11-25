#include "pso/ui/window/WindowVertexBufferAbi.h"
#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TWindowWordSelectMode.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowDD_8034435C.h"
#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDD_WS_ScrollBar.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/window/TWindowDD_80342428.h"
#include "pso/ui/window/TWindowDD_803424EC.h"
#include "pso/ui/window/TWindowDD_80347F34.h"
#include "pso/unk/text_8020C354.h"
#include "pso/ui/window/TWindowDD_80340EA8.h"
#include "pso/network/client_id.h"


struct Win_80343C64
{
  u8 pad0[0x30];
  f32 f30;
  f32 f34;
  f32 f38;
  u8 pad3C[4];
  f32 f40;
  f32 f44;
  f32 f48;
};

#include <stddef.h>
#include <string.h>
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/NinjaTypes.h"

struct WordSelectPage;

struct WordSelectWindowState {
    u8 unknown00[0x20];
    s32 activePage;
    WordSelectPage* pages[7];
    u8 unknown40[0x84 - 0x40];
    TWindowInputNumber* numberWindow;
};

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
s32 apply_input__9TWindowDDFPvPv(int, int);
s32 update__9TWindowDDFP17TWindowDD_WS_Word(int, int, int);
void advance_word_select_level(u8 *window_dd);
void TWindowDD__sub_80342800(u8 *window_dd);
void update__9TWindowDDFi(saddr window_dd);
void TWindowDD__sub_803429B0(u8 *window_dd);
void TWindowDD__sub_80342D14(u8 *window_dd);
void run_state__9TWindowDDFPv(u8 *window_dd);
s16 get_word_select_list_id(u8 *page);
void commit_word_select_level(void *);
void pop_menu_level__9TWindowDDFPv(TWindowDD *window);
void refresh_word_select_message(void *, void *);
extern const s32 TWindowDD__data_805DFB50;

extern const f32 TWindowDD__data_805DFB74;

extern const f32 lbl_805DFB7C;

extern const f32 lbl_805DFB80;

extern const f32 lbl_805DFB88;

extern const f32 TWindowDD__data_805DFBFC;

extern const f32 lbl_805DFC0C;

extern const f32 TWindowDD__data_805DFC10;
void take_word_select_word(u8 *window_dd, saddr word_window);
u8 *get_or_create_word_select_child(void *, s32, s32);
s32 create_word_select_cursor_label(void *, int);
extern const f32 TWindowDD__data_805DFB6C;

extern const f32 lbl_805DFB90;
s32 hide_word_select_selection(int);
s32 show_word_select_selection(int);
s32 get_word_select_first_visible_index(int);
s32 is_word_select_cancel_input(void *);
s32 finish_word_select(void *);
saddr create_word_select_child(s32 element_list, s32 rows);
s32 create_word_select_string(NJS_POINT2 *pos, NJS_POINT2 *size, s32 text, s32 style, f32 width);
void TWindowDD__sub_803412A0(TWindowDD_WS_String *self);
const char *word_select_type_name_pointer = "TWindowDD";



extern char *lbl_805D6E64;

extern s8 lbl_805D6E68;

extern char *lbl_805D6E6C;

extern s8 lbl_805D6E70;

extern const f32 lbl_805DFB54;

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


extern const f32 lbl_805DFB70, lbl_805DFC28;



s32 classify_id__9TWindowDDFs();
}


void clear_window_dd_nodes(void);
extern "C" {





extern uaddr ws_data_jp;

extern uaddr ws_data_us;

extern uaddr ws_data_es;

extern uaddr ws_data_de;


typedef struct Win_80343C64 Win_80343C64;

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
    if ((u32) TWindowDD::ws_data_buffer != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)TWindowDD::ws_data_buffer));
        TWindowDD::ws_data_buffer = 0U;
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
  u8 *p;
  s32 floor;
  s32 v;
  m_name = word_select_type_name_pointer;
  menu_index = (floor = lbl_805D6E24);
  build_item_list();
  *((u8 *) TWindowDD::work_buffer) = 0;
  enemies_active = 0;
  {
    p = (u8 *) get_player_by_client_id(local_client_id);
    if (p != 0)
    {
      floor = get_current_floor();
      s32 r;
      v = ((TObjBase *)p)->get_room();
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
  scroll_bar = (TWindowDD_WS_ScrollBar *)create_word_select_scroll_bar();
  {
    s32 i;
    for (i = 0; i < 8; i++)
    {
      word_windows[i] = 0;
      level_states[i] = 0;
    }
  }
  depth = 0;
  m_88 = get_initial_word_select_list((saddr)this);
  m_8c = -1;
  m_90 = -1;
  {
    saddr w = create_word_select_child(m_88, (s32) lbl_805DFB54);
    if (w != 0)
    {
      set_default_positions((TWindowDD_WS_Word *)w);
      word_windows[0] = w;
    }
  }
  level_states[0] = 0;
  p = (u8 *) create_word_select_child(m_8c, (s32) lbl_805DFB54);
  if (p != 0)
  {
    TWindowDD::init_layout(this, (TWindowDD_WS_Word *)p);
    word_windows[1] = (saddr) p;
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
    labels[0] = ((s32 (*)(f32, NJS_POINT2 *, NJS_POINT2 *, s32, s32)) create_word_select_string)(lbl_805DFBAC, &a, &b, (saddr) lbl_805D6E64, 4);
  }
  {
    a.x = lbl_805DFBB0;
    a.y = lbl_805DFBB4;
    b.x = lbl_805DFB64;
    b.y = lbl_805DFBB4;
    labels[1] = ((s32 (*)(f32, NJS_POINT2 *, NJS_POINT2 *, s32, s32)) create_word_select_string)(lbl_805DFBB8, &a, &b, (saddr) lbl_805D6E6C, 4);
  }
  {
    a.x = lbl_805DFBD0;
    a.y = lbl_805DFBD4;
    b.x = lbl_805DFBD0;
    b.y = lbl_805DFB68;
    void *q = (void *) ((saddr (*)(f32, NJS_POINT2 *, NJS_POINT2 *, s32, s32)) create_word_select_string)(lbl_805DFBD8, &a, &b, get_word_select_token_text(0x687), 5);
    labels[2] = (saddr) q;
    if (q != 0)
    {
      TWindowDD__sub_803412A0((TWindowDD_WS_String *)q);
    }
  }
  TWindowDD::format_message(&message, reinterpret_cast<char *>(TWindowDD::work_buffer), local_client_id);
  {
    a.x = lbl_805DFBF0;
    a.y = lbl_805DFBF4;
    b.x = lbl_805DFB60;
    b.y = lbl_805DFBF4;
    p = (u8 *) ((saddr (*)(f32, NJS_POINT2 *, NJS_POINT2 *, s32, s32)) create_word_select_string)(lbl_805DFBF8, &a, &b, TWindowDD::work_buffer, 0);
    labels[3] = (saddr) p;
    if (p != 0)
    {
      TWindowDD__sub_803412A0((TWindowDD_WS_String *)p);
      ((TWindowDD_WS_String *)p)->update_position(0);
      ((Win_80343C64 *) p)->f30 = lbl_805DFB60;
      ((Win_80343C64 *) p)->f40 = lbl_805DFB60;
      ((Win_80343C64 *) p)->f34 = lbl_805DFBF4;
      ((Win_80343C64 *) p)->f44 = lbl_805DFBF4;
      ((Win_80343C64 *) p)->f38 = 2.0f;
      ((Win_80343C64 *) p)->f48 = 2.0f;
    }
  }
  mode_window = (TWindowWordSelectMode *)TWindowDD::create();
  number_window = 0;
  dialog_state = 0;
  pending_transition = 0;
  state = 0;
  next_state = 0;
  dialog_locked = 0;
  extra_window_count = 0;
  selected_word = 0x37;
  m_100 = 0;
  result_flags = 0;
  token_pushed = 0;
  last_selected_id = -1;
  m_a4 = 0;
  m_104 = 0;
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
    TWindowBase *cur;
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
    cur = ((TWindowBase *)word_windows[depth]);
    if (scroll_bar != 0 && cur != NULL) {
        scroll_bar->set_first_index(get_word_select_first_visible_index((saddr)cur));
    }
    switch (dialog_state) {
    case 2:
        break;
    case 1:
        mode_window->handle_input();
        done = 0;
        if (test_input_flag_4() != 0) {
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
                    set_state();
                    break;
                }
            }
        } else if (is_word_select_cancel_input(this) != 0) {
            TWindowDD::play_se();
            done = 1;
            result_flags |= 2;
        } else if (TWindowDD::apply_both_choices((saddr)&menu_index, 0x40) != 0) {
            TWindowDD::spawn_window();
            done = 1;
        }
        if (done != 0) {
            dialog_state = 0;
            mode_window->hide_selection();
            show_word_select_selection((saddr)cur);
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
                mode_window->set_clamped_selection(((TWindowDD_WS_Word *)word_windows[depth])->get_selected_row());
                hide_word_select_selection((saddr)cur);
                copy_chat_entry__9TWindowDDFPvPv(&final_message, &message);
                if (final_message.count > 0) {
                    final_message.count--;
                    refresh_word_select_message(this, &final_message);
                }
            } else {
                run_state__9TWindowDDFPv((u8 *)this);
                result_flags = 0;
            }
            break;
        case 1:
            if (((TWindowBase *)word_windows[depth + 1]) != NULL && ((TWindowBase *)word_windows[depth + 1])->tween_ticks == 0) {
                advance_word_select_level((u8 *)this);
                pending_transition = 0;
            }
            break;
        case 2:
            if (((TWindowBase *)word_windows[depth])->tween_ticks == 0) {
                pop_menu_level__9TWindowDDFPv(this);
                pending_transition = 0;
            }
            break;
        }
        break;
    }
}

void run_state__9TWindowDDFPv(u8 *window_dd) {
    switch (*(u32 *)((s8 *)window_dd + 0xB0)) {
    case 0:
        ((TWindowDD *)window_dd)->handle_confirm_input();
        return;
    case 1:
    case 2:
        ((TWindowDD *)window_dd)->update();
        return;
    case 3:
        TWindowDD__sub_80342D14((window_dd));
        return;
    case 5:
        ((TWindowDD *)window_dd)->update_transition();
        return;
    case 6:
        ((TWindowDD *)window_dd)->update_layout();
        return;
    case 7:
        ((TWindowDD *)window_dd)->update_dispatch();
        return;
    case 8:
        ((TWindowDD *)window_dd)->enter_state_9();
        return;
    case 9:
        TWindowDD__sub_803429B0((window_dd));
        return;
    case 12:
        update__9TWindowDDFi((saddr)window_dd);
        return;
    case 13:
        TWindowDD__sub_80342800((window_dd));
        return;
    case 14:
        TWindowDD::update_state((window_dd));
        return;
    case 15:
        TWindowDD::enter_state_16((window_dd));
        return;
    case 17:
        ((TWindowDD *)window_dd)->enter_state_18();
        return;
    case 18:
        ((TWindowDD *)window_dd)->enter_state_19();
        return;
    case 20:
        handle_input__9TWindowDDFi((saddr)window_dd);
        return;
    case 10:
    case 11:
    case 16:
    case 19:
        TWindowDD__sub_80342428((window_dd));
    default:
        return;
    }
}

#define w ((TWindowDD *)window_dd)
void begin_word_select_state(u8 *window_dd) {
    s32 *entry;
    s32 *next_entry;
    s32 next;
    s32 entry_flags;
    s32 push_index;
    TWindowBase *word_window;
    TWindowDD *created;
    TWindowBase *mode_a;
    TWindowBase *mode_b;
    next = w->next_state;
    if ((next == 0x14) || (next == 0xC)) {
        TWindowDD::build_player_word_lists();
    }
    w->dialog_locked = 0;
    if (w->next_state == 1 || w->next_state == 2 || w->next_state == 8 || w->next_state == 0xF || w->next_state == 0x11) {
        w->message.reset_numeric_parameter();
    }
    entry = (s32 *)TWindowDD::get_entry(window_dd, w->state);
    next_entry = (s32 *)TWindowDD::get_entry(window_dd, w->next_state);
    word_window = (TWindowBase *)(window_dd + w->depth * 4);
    word_window = *(TWindowBase **)((u8 *)word_window + 0x24);
    if (word_window != NULL) {
        word_window->target_position[0] = (f32) lbl_805DFB90;
        word_window->target_size[0] = (f32) TWindowDD__data_805DFB74;
        word_window->tween_ticks = (s32) TWindowDD__data_805DFB50;
        if (*entry & 4) {
            push_index = w->extra_window_count;
            w->extra_window_count = (push_index + 1);
            create_word_select_cursor_label(window_dd, push_index);
        }
    }
    created = (TWindowDD *)get_or_create_word_select_child(window_dd, 1, w->m_8c);
    if (created != NULL) {
        created->set_pos_and_data(TWindowDD__data_805DFB6C);
        if (*next_entry & 1) {
            ((TWindowBase *)created)->target_size[0] = (f32) lbl_805DFB7C;
            mode_a = (TWindowBase *)w->mode_window;
            if (mode_a != NULL) {
                mode_a->target_position[0] = (f32) lbl_805DFC0C;
                ((TWindowBase *)w->mode_window)->tween_ticks = (s32) TWindowDD__data_805DFB50;
            }
        } else {
            ((TWindowBase *)created)->target_size[0] = (f32) TWindowDD__data_805DFB74;
            mode_b = (TWindowBase *)w->mode_window;
            if (mode_b != NULL) {
                mode_b->target_position[0] = (f32) TWindowDD__data_805DFBFC;
                ((TWindowBase *)w->mode_window)->tween_ticks = (s32) TWindowDD__data_805DFB50;
            }
        }
        if (*next_entry & 2) {
            take_word_select_word(window_dd, (saddr)created);
        }
    }
    entry_flags = *next_entry;
    if (!(entry_flags & 8)) {
        if (entry_flags & 1) {
            w->m_90 = dispatch_by_window_mode(w, w->next_state, w->m_8c, 0);
            if ((word_window = (TWindowBase *)get_or_create_word_select_child(window_dd, 2, w->m_90)) != NULL) {
                ((TWindowDD *)word_window)->set_pos_and_data(TWindowDD__data_805DFC10);
            }
            TWindowDD__sub_80347F48(window_dd);
        } else {
            w->m_90 = dispatch_by_window_mode(w, w->next_state, w->m_8c, 0);
            if ((word_window = (TWindowBase *)get_or_create_word_select_child(window_dd, 2, w->m_90)) != NULL) {
                ((TWindowDD *)word_window)->set_pos_and_data(lbl_805DFB80);
            }
            w->init_entry_field_64(1);
        }
    } else {
        update_word_select_child_position((saddr)window_dd, 1);
    }
    if ((s16) *(s16 *)((s8 *)next_entry + 4) == -1) {
        update_word_select_child_position((saddr)window_dd, 2);
    } else {
        w->setup_entry(*(s16 *)((s8 *)next_entry + 4));
        w->init_entry_field_64(2);
    }
    w->pending_transition = 1;
}
#undef w

void advance_word_select_level(u8 *window_dd) {
    TWindowDD *window = (TWindowDD *)window_dd;
    s32 saved_state;
    reinterpret_cast<TWindowDD_WS_Word *>(window->word_windows[window->depth])->free_child();
    apply_input__9TWindowDDFPvPv((saddr)window, (saddr)window->word_windows[window->depth]);
    saved_state = window->state;
    window->level_states[window->depth] = saved_state;
    window->depth++;
    update__9TWindowDDFP17TWindowDD_WS_Word((saddr)window, (saddr)window->word_windows[window->depth], saved_state);
    window->state = window->next_state;
    window->m_88 = window->m_8c;
    window->m_8c = window->m_90;
    window->m_90 = -1;
}

void TWindowDD::apply_entry_layout(void *window) {
    TWindowDD *window_dd = (TWindowDD *)window;
    s32 *prev;
    s32 *entry;
    u8 *w;
    TWindowBase *child;
    s32 id;
    prev = (s32 *)TWindowDD::get_entry(window_dd, window_dd->state);
    entry = (s32 *)TWindowDD::get_entry(window_dd, window_dd->level_states[window_dd->depth - 1]);
    w = window_dd->init_last_child();
    if (w != NULL) {
        if (*entry & 1) {
            *(f32 *)((s8 *)w + 0x38) = lbl_805DFB7C;
            if (window_dd->mode_window != NULL) {
                ((TWindowBase *)window_dd->mode_window)->target_position[0] = lbl_805DFC0C;
                ((TWindowBase *)window_dd->mode_window)->tween_ticks = TWindowDD__data_805DFB50;
            }
        } else {
            *(f32 *)((s8 *)w + 0x38) = TWindowDD__data_805DFB74;
            if (window_dd->mode_window != NULL) {
                ((TWindowBase *)window_dd->mode_window)->target_position[0] = TWindowDD__data_805DFBFC;
                ((TWindowBase *)window_dd->mode_window)->tween_ticks = TWindowDD__data_805DFB50;
            }
        }
    }
    child = (TWindowBase *)window_dd->word_windows[window_dd->depth];
    if (child != NULL) {
        if (*entry & 8) {
            window_dd->set_item_pos(0);
            update_word_select_child_position((saddr)window_dd, 1);
        } else if (*entry & 1) {
            ((TWindowDD *)child)->set_pos_and_data(TWindowDD__data_805DFC10);
            child->target_size[0] = lbl_805DFB88;
            TWindowDD__sub_80347F48((u8 *)window_dd);
        } else {
            ((TWindowDD *)child)->set_pos_and_data(lbl_805DFB80);
            child->target_size[0] = lbl_805DFB88;
            window_dd->init_entry_field_64(1);
        }
        if (*prev & 2) {
            window_dd->message.pop_token();
            refresh_word_select_message(window_dd, &window_dd->message);
        }
    }
    window_dd->set_item_pos(1);
    if (!(*entry & 2)) {
        update_word_select_child_position((saddr)window_dd, 3);
    }
    if (*entry & 4) {
        if (window_dd->extra_window_count > 0) {
            update_word_select_child_position((saddr)window_dd, window_dd->extra_window_count + 3);
        }
    }
    id = ((s16 *)entry)[2];
    if (id == -1) {
        update_word_select_child_position((saddr)window_dd, 2);
    } else {
        window_dd->setup_entry(id);
        window_dd->init_entry_field_64(2);
    }
    window_dd->pending_transition = 2;
}

void pop_menu_level__9TWindowDDFPv(TWindowDD *window) {
    s32 *entry;
    void *child;
    TWindowDD::get_entry(window, window->state);
    entry = (s32 *)TWindowDD::get_entry(window, window->level_states[window->depth - 1]);
    commit_word_select_level(window);
    if (*entry & 8) {
        window->destroy_menu_entry(0);
    } else if ((child = (void *)window->word_windows[window->depth]) != NULL) {
        TWindowDD::update(window, child);
    }
    window->destroy_menu_entry(1);
    window->depth--;
    if (*entry & 4) {
        window->extra_window_count--;
        if (window->extra_window_count >= 0 && window->labels[window->extra_window_count + 4] != 0) {
            ((TObject *)window->labels[window->extra_window_count + 4])->queue_destruction();
            window->labels[window->extra_window_count + 4] = 0;
        }
    }
    window->m_90 = window->m_8c;
    window->m_8c = window->m_88;
    window->m_88 = get_word_select_list_id((u8 *)window->word_windows[window->depth]);
    window->state = window->level_states[window->depth];
    if (window->state == 0xD) {
        window->message.type = 4;
    }
}

void open_numeric_parameter_input__9TWindowDDFPviii(WordSelectWindowState* self, s32 minimum, s32 maximum, s32 initial) {
    NJS_POINT2 position;
    position.x = 60.0f + TWindowDD__data_805DFB6C;
    position.y = 10.0f + lbl_805DFB70;
    self->numberWindow = new TWindowInputNumber(&position, minimum, maximum, initial, (s16)local_client_id);
    if (self->numberWindow) {
        ((TWindowBase *)(self->numberWindow))->set_depth(lbl_805DFC28);
        ((TWindowSubItem *)(self->numberWindow))->set_flag60_bit10();
        hide_word_select_selection((saddr)self->pages[self->activePage]);
    }
}

s32 TWindowDD::update_close_flag(void *window_dd) {
    ((TWindowDD *)window_dd)->get_current_child_index();
    if (classify_id__9TWindowDDFs() != 7) {
        *(s32 *)((s8 *)window_dd + 0xB8) = 1;
        return 1;
    }
    return 0;
}
}
