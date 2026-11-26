#include "pso/ui/window/WindowVertexBufferAbi.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowDD_803488A8.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDD_WS_ScrollBar.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD_WS_ScrollBar.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/window/TWindowWordSelectMode.h"
#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include <string.h>
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowDD_80348304.h"
#include "pso/ui/window/TWindowDD_8034AF68.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/system/SoundEffect.h"



extern "C" {
void append_word_select_token(s16, saddr, void *);
void append_word_select_word_with_number(WordSelectMessage *entry, s16 id, char *word, char *buf, s32 *pos);
void append_word_select_word(WordSelectMessage *entry, s16 id, char *buf, s32 *pos);
s32 is_id_in_special_range__9TWindowDDFs(s16);
s32 TWindowDD__sub_80347238();

s32 TWindowDD::classify_id(s16 id) {
    s32 kind;

    if (id == 0x2E4) {
        return 0;
    }
    if (TWindowDD__sub_80347238() != 0) {
        return 1;
    }
    if (is_id_in_special_range__9TWindowDDFs(id) != 0) {
        return 2;
    }
    if (id == 0x4F3) {
        return 3;
    }
    if (id == 0x635) {
        return 4;
    }
    kind = 7;
    if (id == 0x650) {
        kind = 5;
    }
    return kind;
}

s32 TWindowDD::get_player_battle_flag_state(u16 client) {
    s32 class_flags;
    void *player;

    player = get_player_by_client_id((u16) client);
    if (player != NULL) {
        class_flags = ((TObjPlayer *)player)->class_flags;
        if (class_flags & CLASS_FLAG_MALE) {
            return 0;
        }
        if (class_flags & CLASS_FLAG_FEMALE) {
            return 2;
        }
        goto block_5;
    }
block_5:
    return 0;
}

void WordSelectMessage::format_type6_message(saddr window_dd, void *pos) {
    s32 n_tokens;
    s32 n;
    s32 i;

    n_tokens = count;
    n = n_tokens;
    if (n > 3) {
        n = 3;
    }
    for (i = 0; i < n - 1; i++) {
        append_word_select_token(ids[i], window_dd, pos);
        TWindowDD::show_message_by_count((char *)window_dd, (s32 *)pos);
    }
    append_word_select_token(ids[n - 1], window_dd, pos);
    if (n_tokens > 3) {
        ((TWindowDD *)window_dd)->append_prompt_newline((s32 *)pos);
        append_word_select_token(ids[3], window_dd, pos);
    }
}

void append_word_select_entry_words(WordSelectMessage *entry, saddr window_dd, saddr pos) {
    append_word_select_word(entry, entry->ids[0], (char *)window_dd, (s32 *)pos);
    if (entry->count > 1) {
        ((TWindowDD *)window_dd)->append_prompt_newline((s32 *)pos);
        append_word_select_token(entry->ids[1], window_dd, (void *) pos);
    }
}

void append_word_select_word(WordSelectMessage *entry, s16 id, char *buf, s32 *pos) {
    char *word = (char *)get_word_select_token_text(id);
    append_word_select_word_with_number(entry, id, word, buf, pos);
}

void append_word_select_word_with_number(WordSelectMessage *entry, s16 id, char *word, char *buf, s32 *pos) {
    char num[20];
    s32 kind;
    s32 value;
    s32 limit;
    s32 len;
    s32 split;
    s32 next;
    s32 c;
    char *p;
    s32 i;

    kind = TWindowDD::classify_id(id);
    if (kind != 7) {
        value = entry->get_numeric_parameter();
        limit = word_select_numeric_limits[kind];
        if (value > 0) {
            if (value > limit) {
                value = limit;
            }
            format_int_decimal(value, num);
            switch (kind) {
            case 0:
            case 5:
                if (kind == 5 && TWindowDD::window_mode == 2) {
                    len = strlen(word);
                    s32 need = len + strlen(num) + 1;
                    if (TWindowDD::can_append_chars(need, pos) == 0) {
                        break;
                    }
                    split = len;
                    for (i = 0; i < len - 1; i++) {
                        p = word + i;
                        c = p[0];
                        next = p[1];
                        if ((c == 'J' || c == 'j') && next == 'a') {
                            split = i;
                            break;
                        }
                    }
                    if (split != 0) {
                        strncpy(buf + *pos, word, split);
                        *pos += split;
                    }
                    TWindowDD::append_string(num, buf, pos);
                    TWindowDD::show_message_by_count(buf, pos);
                    len -= split;
                    if (len > 0) {
                        strncpy(buf + *pos, word + split, len);
                        *pos += len;
                    }
                } else {
                    TWindowDD::append_string(num, buf, pos);
                    if (TWindowDD::window_mode != 0) {
                        TWindowDD::append_char(' ', buf, pos);
                    }
                    TWindowDD::append_string(word, buf, pos);
                }
                break;
            case 1:
                TWindowDD::append_string(word, buf, pos);
                TWindowDD::append_char('+', buf, pos);
                TWindowDD::append_string(num, buf, pos);
                break;
            case 2:
                TWindowDD::append_string(word, buf, pos);
                TWindowDD::append_string(" Lv.", buf, pos);
                TWindowDD::append_string(num, buf, pos);
                break;
            case 3:
            case 4:
                TWindowDD::append_string(word, buf, pos);
                TWindowDD::append_string(num, buf, pos);
                break;
            }
            return;
        }
    }
    TWindowDD::append_string(word, buf, pos);
}

void TWindowDD__sub_80347758(WordSelectMessage *src, WordSelectMessage *dst) {
    s16 id;
    s16 n;
    n = src->count;
    if (n > 1) {
        id = src->ids[1];
        if (TWindowDD_is_id_in_range_5AC_5F9(id) != 0) {
            dst->type = 4;
            if (n > 3) {
                dst->ids[0] = src->ids[3];
            } else if (n > 2 && src->ids[2] == 0x685) {
                dst->ids[0] = 0x698;
            } else {
                dst->ids[0] = 0x2C4;
            }
            dst->ids[1] = id;
            dst->ids[2] = src->ids[0];
            if (n > 2) {
                dst->ids[3] = src->ids[2];
                dst->count = 4;
            } else {
                dst->count = 3;
            }
        } else {
            s32 i;
            dst->type = 5;
            for (i = 0; i < n; i++) {
                dst->ids[i] = src->ids[i];
            }
            dst->count = src->count;
        }
    }
    dst->numeric_parameter = src->numeric_parameter;
}

u8 TWindowDD__sub_80347858(s16 id) {
    s32 r = 0;
    if (id >= 0x37 && id <= 0x45) {
        r = 1;
    }
    return (u8)r;
}
}

s32 TWindowDD::is_state_zero_unless_0x2C8(s32 id) {
    if ((s16)id == 0x2C8) {
        return 0;
    }
    return (u32) __cntlzw((u32) ((s32 (*)(void))TWindowDD__sub_80347858)()) >> 5;
}

s32 TWindowDD_is_id_in_range_5AC_5F9(s32 value) {
    u8 in_range = 0;
    if (static_cast<s16>(value) >= 0x5ac && static_cast<s16>(value) <= 0x5f9) {
        in_range = 1;
    }
    return in_range;
}

void TWindowDD::destroy_menu_entry(s32 offset) {
    if (word_windows[depth + offset] != NULL) {
        word_windows[depth + offset]->queue_destruction();
        word_windows[depth + offset] = NULL;
    }
}

void TWindowDD::set_item_pos(s32 i) {
    TWindowDD_WS_Word *page = word_windows[depth + i];
    if (page != NULL) {
        page->set_pos_and_data(last_word_page_x);
    }
}

extern "C" {

TWindowDD_WS_Word *TWindowDD::commit_word_select_level() {
    TWindowDD_WS_Word *child;
    if (depth > 0) {
        child = word_windows[depth - 1];
        if (child != NULL) {
            update(child);
            list_ids[0] = child->get_element_list_id();
        }
    }
    return child;
}
}

TWindowDD_WS_Word *TWindowDD::init_last_child() {
    s32 level;
    TWindowDD_WS_Word *child;
    child = NULL;
    level = depth;
    if (level > 0) {
        child = word_windows[level - 1];
        if (child != NULL) {
            child->init_and_mark_field8C();
            child->set_pos_and_data(word_page_x);
            child->target_size[0] = word_page_width;
        }
    }
    return child;
}

extern "C" {

void TWindowDD::take_word_select_word(TWindowDD_WS_Word *word_window) {
    s32 id;
    id = word_window->get_selected_id();
    if (TWindowDD::is_state_zero_unless_0x2C8(id) != 0) {
        message.push_token(id);
        refresh_word_select_message(&message);
        token_pushed = 1;
        last_selected_id = (s16) id;
        return;
    }
    update_word_select_child_position(3);
    token_pushed = 0;
    last_selected_id = (s16) id;
}

TWindowDD_WS_Word *TWindowDD::get_or_create_word_select_child(s32 offset, s32 id) {
    s32 i;
    TWindowDD_WS_Word *win;

    i = depth + offset;
    if (i >= 8) {
        return NULL;
    }
    win = word_windows[i];
    if (win == NULL) {
        win = TWindowDD_WS_Word::create(id, (s32)window_dd_visible_rows);
        set_default_coords(win);
        word_windows[depth + offset] = win;
    }
    return win;
}

#pragma push
#pragma fp_contract on

void TWindowDD::update_selection_state() {
    s32 v;
    v = word_windows[depth]->get_selected_id();
    if ((s16)v != last_selected_id) {
        switch (token_pushed) {
        case 0:
            if (TWindowDD::is_state_zero_unless_0x2C8(v) != 0) {
                message.push_token(v);
                token_pushed = 1;
            } else {
                message.set_last_token(v);
            }
            break;
        case 1:
            if (TWindowDD::is_state_zero_unless_0x2C8(v) != 0) {
                message.set_last_token(v);
            } else {
                message.pop_token();
                token_pushed = 0;
            }
            break;
        }
        refresh_word_select_message(&message);
        last_selected_id = (s16)v;
    }
}

void TWindowDD::refresh_word_select_child_list() {
    s32 next;

    next = dispatch_by_window_mode(this, state, list_ids[0], word_windows[depth]->get_selected_token_index());
    if (next != list_ids[1]) {
        list_ids[1] = next;
        word_windows[depth + 1]->init_child(list_ids[1]);
    }
}

void TWindowDD::refresh_word_select_message(WordSelectMessage *message) {
    TWindowDD_WS_String *s;
    WindowTextEntry *e;
    f32 x;
    f32 c;
    f32 max;
    f32 f10;
    TWindowDD::format_message(message, reinterpret_cast<char *>(TWindowDD::work_buffer), local_client_id);
    s = labels[3];
    if (s != NULL) {
        e = (WindowTextEntry *)s->get_array_entry(0);
        if (e != NULL) {
            measure_message_text_width_default(e);
            x = 10.0f + e->width;
            if (x >= 580.0f) {
                e->x = 580.0f - e->width;
                x = 580.0f;
            } else {
                e->x = 0.0f;
            }
            s->target_size[0] = 2.0f * window_dd_frame_margin + x;
            if (x <= 0.0f) {
                s->update_position(window_dd_tween_ticks);
            } else {
                s->move_to_start(window_dd_tween_ticks);
            }
        }
    }
}
s32 TWindowDD::setup_entry(s16 id) {
    s32 result;
    TWindowDD_WS_String *label;

    s32 str;
    result = 0;
    label = labels[2];
    if ((label != NULL) && ((str = get_word_select_token_text(id)) != 0)) {
        label->set_first_entry_text(str);
        label->fit_width_to_text();
        label->move_to_start(window_dd_tween_ticks);
        result = 1;
    }
    return result;
}

void TWindowDD::create_word_select_cursor_label(s32 slot) {
    NJS_POINT2 v;
    NJS_POINT2 a;
    NJS_POINT2 b;
    u32 r;
    TWindowDD_WS_String *o;
    word_windows[depth]->get_cursor_pos(&v);
    r = word_windows[depth]->get_selected_row_text();
    if (r != 0) {
        if (slot == 0) {
            a.x = cursor_label_x;
            a.y = cursor_label_y;
        } else {
            a.x = cursor_label2_x;
            a.y = cursor_label2_y;
        }
        b.x = word_label_hidden_x;
        b.y = a.y;
        o = TWindowDD_WS_String::create(cursor_label_width, (f32 *)&a, (f32 *)&b, (u32)r, 1);
        if (o != NULL) {
            o->set_depth(word_cursor_depth);
            o->fit_width_to_text();
            copy_vec2(o->frame_position, &v);
            o->move_to_start(window_dd_tween_ticks);
            labels[slot + 4] = o;
        }
    }
}}

s32 TWindowDD::get_current_child_index() {
    TWindowDD_WS_Word *word_window;
    word_window = word_windows[depth];
    if (word_window != NULL) {
        return word_window->get_selected_id();
    }
    return -1;
}
#pragma pop



TWindowDDStateEntry *TWindowDD::get_state_entry(s32 state) { return &word_select_state_table[state]; }

void TWindowDD::move_next_label_after_wide_page() {
    TWindowDD_WS_String *label;
    label = labels[1];
    if (label != NULL) {
        label->target_position[0] = wide_next_word_page_x;
        label->tween_ticks = window_dd_tween_ticks;
    }
}

void TWindowDD::init_entry_field_64(s32 index) {
    TWindowDD_WS_String *label;
    label = labels[index];
    if (label != NULL) {
        label->move_to_start(window_dd_tween_ticks);
    }
}

void TWindowDD::update_word_select_child_position(s32 index) {
    TWindowDD_WS_String *label;
    label = labels[index];
    if (label != NULL) {
        label->update_position(window_dd_tween_ticks);
    }
}

void TWindowDD::refresh_sub(TWindowDD_WS_Word *page) {
    page->disable_input();
    page->use_dim_strips();
}

void TWindowDD::apply_input(TWindowDD_WS_Word *page) {
    page->disable_input();
    page->use_active_strips();
}

void TWindowDD::dim_next_page(TWindowDD_WS_Word *page) {
    page->disable_input();
    page->use_dim_strips();
}


void TWindowDD::update(TWindowDD_WS_Word *window_dd) {
    window_dd->enable_input();
    window_dd->use_active_strips();
    if (scroll_bar != NULL) {
        scroll_bar->set_range(window_dd->get_token_count(), (s32) window_dd_visible_rows);
        scroll_bar->set_first_index(window_dd->get_scroll_top());
    }
}

extern "C" {

void TWindowDD::set_default_coords(TWindowDD_WS_Word *win) {
    refresh_sub(win);
    win->target_position[0] = last_word_page_x;
    win->frame_position[0] = last_word_page_x;
    win->target_position[1] = last_word_page_y;
    win->frame_position[1] = last_word_page_y;
    win->target_size[0] = last_word_page_width;
    win->frame_size[0] = last_word_page_width;
    win->target_size[1] = last_word_page_height;
    win->frame_size[1] = last_word_page_height;
}

void TWindowDD::init_layout(TWindowDD_WS_Word *child) {
    dim_next_page(child);
    child->target_position[0] = next_word_page_x;
    child->frame_position[0] = next_word_page_x;
    child->target_position[1] = next_word_page_y;
    child->frame_position[1] = next_word_page_y;
    child->target_size[0] = next_word_page_width;
    child->frame_size[0] = next_word_page_width;
    child->target_size[1] = next_word_page_height;
    child->frame_size[1] = next_word_page_height;
}

void TWindowDD::set_default_positions(TWindowDD_WS_Word *child) {
    update(child);
    child->target_position[0] = word_page_x;
    child->frame_position[0] = word_page_x;
    child->target_position[1] = word_page_y;
    child->frame_position[1] = word_page_y;
    child->target_size[0] = word_page_width;
    child->frame_size[0] = word_page_width;
    child->target_size[1] = word_page_height;
    child->frame_size[1] = word_page_height;
}

void TWindowDD::spawn_window() { play_sound_effect(344320, 0, 0, 0); }
void TWindowDD::play_se() { play_sound_effect(339734, 0, 0, 0); }
void TWindowDD::play_sound() { play_sound_effect(339201, 0, 0, 0); }
s32 TWindowDD::is_word_select_cancel_input() {
    u8 cancel;
    cancel = 0;
    if (TWindowDD_check_input_mask(&menu_index, 2) != 0 || (result_flags & 2)) {
        cancel = 1;
    }
    return cancel;
}

}


extern "C" {
s32 copy_chat_entry__9TWindowDDFPvPv(void *, void *);
s32 reset_selection__9TWindowDDFv(void *, void *);
}

int TWindowDD::test_input_flag_4() { return TWindowDD_check_input_mask((char*)this + 0x1c, 4); }

s32 dispatch_by_window_mode(TWindowDD *window, u32 window_mode, s32 entry_id, s32 value_index) {
    switch ((s32) TWindowDD::window_mode) {
    case 0:
        return window->get_entry_value_japanese(window_mode, entry_id, value_index);
    default:
        return window->get_entry_value_english(window_mode, entry_id, value_index);
    case 4:
        return window->get_entry_value_spanish(window_mode, entry_id, value_index);
    case 2:
        return window->get_entry_value_german(window_mode, entry_id, value_index);
    case 3:
        return window->get_entry_value_french(window_mode, entry_id, value_index);
    }
}

s32 TWindowDD::get_word_select_context() {
    s32 area;
    area = get_current_floor_area();
    if (area == AREA_PIONEER2_EP1 || area == AREA_PIONEER2_EP2) {
        return 1;
    }
    if (area == AREA_LOBBY) {
        return 0;
    }
    if (TObjPlayer::get_player_count() != 0) {
        return 4;
    }
    if (is_challenge_mode() != 0) {
        return 5;
    }
    return (enemies_active != 0 ? 1 : 0) + 2;
}

int TWindowDD__sub_80348424(s32 _w0, s32 _w1) { return get_word_select_type_state((saddr)((void*)(1)), (_w1)); }

void TWindowDD__sub_80348448(s32 unused, s16 id) {
    get_word_select_type_state(0, ((s32) id));
}

s32 TWindowDD::get_mode_code() {
    s32 mode;
    mode = dialog_state;
    if (mode == 2) {
        return 1;
    }
    return ((mode - 3) == 0) ? 2 : 0;
}

void TWindowDD::set_state() { dialog_state = 3; close_all_windows(); }

void TWindowDD::finish_word_select() {
    dialog_state = 2;
    copy_chat_entry__9TWindowDDFPvPv(output, &message);
    if (selection_confirmed != 0) {
        reset_selection__9TWindowDDFv(this, &message);
    }
    close_all_windows();
}

void TWindowDD::close_all_windows() {
    s32 i;
    if (number_window != NULL) {
        number_window->close();
        number_window = NULL;
    }
    if (mode_window != NULL) {
        mode_window->close();
        mode_window = NULL;
    }
    if (scroll_bar != NULL) {
        scroll_bar->close();
        scroll_bar = NULL;
    }
    for (i = 0; i < 6; i++) {
        if (labels[i] != NULL) {
            labels[i]->close();
            labels[i] = NULL;
        }
    }
    for (i = 7; i >= 0; i--) {
        if (word_windows[i] != NULL) {
            word_windows[i]->close();
            word_windows[i] = NULL;
        }
    }
}

s32 TWindowDD::can_append_chars(s32 len, s32 *pos) {
    s32 t = *pos;
    return (len + t + 1) < 0x80;
}

void TWindowDD::format_message(WordSelectMessage *message, char *text, u16 player) {
    switch ((s32) TWindowDD::window_mode) {
    case LANGUAGE_JAPANESE:
        format_entry_text__9TWindowDDFPvPv(message, text);
        return;
    default:
        format_english_message__9TWindowDDFPvPvUs(message, text, player);
        return;
    case LANGUAGE_SPANISH:
        TWindowDD__sub_80345608(message, text, player);
        return;
    case LANGUAGE_GERMAN:
        format_german_message__9TWindowDDFPvPvUs(message, text, player);
        return;
    case LANGUAGE_FRENCH:
        format_message_text__9TWindowDDFPvPvUs(message, text, player);
        return;
    }
}

void TWindowDD::append_prompt_newline(s32 *pos) {
    u8 *buffer = (u8 *)this;
    s32 p = *pos;
    if (((s32)TWindowDD::can_append_chars(3, pos)) != 0) {
        buffer[p++] = 0xA;
        buffer[p++] = 0x3E;
        buffer[p++] = 0x20;
    }
    *pos = p;
}

s32 TWindowDD::clamp_range_5FA_682(s16 id) {
    if ((id >= 0x5FA) && (id <= 0x682)) {
        return id - 0x5FA;
    }
    return 0;
}

s32 TWindowDD::clamp_range_2C9_552(s16 id) {
    if ((id >= 0x2C9) && (id <= 0x552)) {
        return id - 0x2C9;
    }
    return 0;
}


extern "C" {

void TWindowDD::show_message_by_count(char *buf, s32 *pos) {
    if (TWindowDD::count_chars_since_newline(buf, pos) > 0xF) {
        TWindowDD::append_char(0xA, buf, pos);
        return;
    }
    TWindowDD::append_char(0x20, buf, pos);
}

}


void TWindowDD::maybe_scroll(char *buf, s32 *pos) {
    if (TWindowDD::count_chars_since_newline(buf, pos) > 15) {
        TWindowDD::append_char(10, buf, pos);
    }
}

s32 TWindowDD::count_chars_since_newline(const char *buf, s32 *pos) {
    s32 n = 0;
    s32 i;
    for (i = *pos - 1; i >= 0; i--) {
        if (buf[i] == '\n') {
            break;
        }
        n++;
    }
    return n;
}

void TWindowDD::append_char(s8 c, char *buf, s32 *pos) {
    s32 i;
    if (TWindowDD::can_append_chars(1, pos) != 0) {
        i = *pos;
        *pos = i + 1;
        buf[i] = c;
    }
}

void append_word_select_token(s16 id, saddr window_dd, void *pos) {
    TWindowDD::append_string((const char *)get_word_select_token_text(id), (char *)window_dd, (s32 *)pos);
}




WindowTexturePoint word_select_quad_points[7][8];
extern s32 *TWindowDD__player_name_buffers;
extern s32 *ws_word_strings;
extern s16 *ws_word_string_index;
typedef struct { char pad[0xBC]; } Buf;

void TWindowDD::append_string(const char *str, char *buf, s32 *pos) {
    s32 len;

    if (str != NULL) {
        len = strlen(str);
        if (TWindowDD::can_append_chars(len, pos) != 0) {
            strncpy(buf + *pos, str, len);
            *pos += len;
        }
    }
}


void TWindowDD_WS_String::draw(saddr ctx, s32 idx, f32 offset) {
    Buf sp8;
    s32 draw_count;

    draw_count = TWindowDD::get_draw_count(hud_texlist);
    reset_window_vertices((WindowVertex *)&sp8, word_select_inverse_depth(draw_depth, offset), -1);
    copy_window_point_table((WindowVertex *)&sp8, idx);
    TWindowDD__sub_80348A2C(reinterpret_cast<WindowDrawContext *>(ctx), reinterpret_cast<WindowVertex *>(&sp8));
    TWindowDD__sub_803489B8(reinterpret_cast<WindowDrawContext *>(ctx), reinterpret_cast<WindowVertex *>(&sp8), 0);
    draw_window_vertices((WindowVertex *)&sp8, 8, draw_count, 1);
}

#pragma push
#pragma fp_contract on
void TWindowDD__sub_803489B8(WindowDrawContext *context, WindowVertex *vertices, s32 row) {
    s32 i;
    f32 hs;
    f32 half;
    f32 v;
    f32 t0;
    f32 step;
    f32 sc;
    half = 0.5f * context->h;
    sc = context->scale[1];
    t0 = context->y + half;
    step = window_dd_row_height * sc;
    hs = half * sc;
    v = t0 - hs;
    v += step * (f32)row;
    for (i = 0; i < 4; i++) {
        vertices[0].y = v;
        vertices[1].y = v + step;
        vertices += 2;
    }
}
#pragma pop

void TWindowDD__sub_80348A2C(WindowDrawContext *context, WindowVertex *vertices) {
  f32 center_x;
  f32 inner_right;
  f32 half_scaled;
  f32 inner_left;
  s8 *right_vertex;
  f32 half_width;
  f32 x;
  f32 right;
  s8 *base_vertex;
  f32 edge;
  half_width = 0.5f * context->w;
  half_scaled = half_width * context->scale[0];
  center_x = context->x + half_width;
  x = (0, center_x - half_scaled);
  right = center_x + half_scaled;
  if (half_scaled < window_dd_cap_width)
  {
    edge = (right - x) / 3.0f;
  }
  else
  {
    edge = window_dd_cap_width;
  }
  right_vertex = ((s8 *) ((0, vertices))) + 0x90;
  *((f32 *) (((s8 *) vertices) + 0x18)) = x;
  inner_left = x + edge;
  inner_right = right - edge;
  vertices->x = x;
  *((f32 *) (((s8 *) vertices) + 0x48)) = inner_left;
  *((f32 *) (((s8 *) vertices) + 0x30)) = inner_left;
  base_vertex = (s8 *) vertices;
  *((f32 *) (((s8 *) vertices) + 0x78)) = inner_right;
  *((f32 *) (((s8 *) vertices) + 0x60)) = inner_right;
  *((f32 *)(base_vertex + 0xA8)) = right;
  *((f32 *) right_vertex) = right;
}

void copy_window_point_table(WindowVertex *vertices, s32 idx) {
    WindowVertex *self = vertices;
    s32 i;
    const WindowTexturePoint *s = word_select_quad_points[idx];
    for (i = 0; i < 8; i++) {
        self->u = s->x;
        self->v = s->y;
        s++;
        self++;
    }
}

#pragma push
#pragma fp_contract on
f32 word_select_inverse_depth(f32 draw_depth, f32 offset) {
    return (-1.0f) / ((0.299f * offset) + draw_depth);
}
#pragma pop

s32 TWindowDD::get_draw_count(const NJS_TEXLIST *textures) {
    return textures->textures[2].texture->surface->id;
}

extern s32 twindowdd_entry_count;

#pragma push
#pragma fp_contract on
void TWindowBase::calc_inner_rect(WindowDrawContext *context) {
    f32 y0;
    f32 ky;
    f32 x0;
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    x = frame_position[0];
    y = frame_position[1];
    ky = window_dd_frame_margin_y;
    x0 = x + window_dd_frame_margin;
    w = frame_size[0];
    h = frame_size[1];
    y0 = y + ky;
    context->inner_x = x0;
    context->inner_y = y0;
    context->inner_w = w - 2.0f * window_dd_frame_margin;
    context->inner_h = h - 2.0f * ky;
    context->clip_x0 = x0;
    context->clip_y0 = y0;
    context->clip_x1 = (x + w) - window_dd_frame_margin;
    context->clip_y1 = (y + h) - ky;
    context->pivot[0] = 0.5f * w + x;
    context->pivot[1] = 0.5f * h + y;
}
#pragma pop

saddr get_word_select_token_text(s16 id) {
    s32 *t = TWindowDD__player_name_buffers;
    if (id >= 0x68C && id <= 0x697) {
        return t[id - 0x68C];
    }
    if (id == 0x698) {
        return 0;
    }
    return ws_word_strings[ws_word_string_index[id]];
}

saddr TWindowDD::get_entry(s32 index) {
    if ((index < 0) || (index >= (s32) twindowdd_entry_count)) {
        return 0;
    }
    return reinterpret_cast<saddr>(&TWindowDD::ws_data_table[index]);
}

