#include "pso/render/GinjaMaterialState.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowDD_803488A8.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD_WS_ScrollBar.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/window/TWindowWordSelectMode.h"
#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "pso/ui/window/TWindowDD_80341A08.h"
#include "pso/ui/window/TWindowDD_80341334.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80228E98.h"
#include <string.h>
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowDD_80347F34.h"
#include "pso/ui/window/TWindowDD_80348100.h"
#include "pso/ui/window/TWindowDD_80348304.h"
#include "pso/ui/window/TWindowDD_8034AF68.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"
#include "pso/player/PlayerSlots.h"
#include "pso/network/client_id.h"
#include "pso/system/SoundEffect.h"

struct E_80347CC8 { u8 pad[8]; f32 f8; u8 padc[4]; f32 f10; };


extern "C" {
void append_word_select_token(s16, saddr, void *);
void append_word_select_word_with_number(WordSelectMessage *entry, s16 id, char *word, char *buf, s32 *pos);
saddr TWindowDD__sub_80348D88(void *p);
void append_word_select_word(WordSelectMessage *entry, s16 id, char *buf, s32 *pos);
extern const f32 lbl_805DFB54;
s32 TWindowDD__sub_80348DD8(void *, int);
extern const f32 lbl_805DFB94;
extern const saddr TWindowDD__data_805DFB50;
extern const f32 lbl_805DFB60;
extern const f32 lbl_805DFBDC;
extern const f32 lbl_805DFBE0;
extern const f32 lbl_805DFBE4;
extern const f32 lbl_805DFBE8;
extern const f32 lbl_805DFBEC;
extern const f32 lbl_805DFC28;
extern const f32 TWindowDD__data_805DFB58;
void TWindowDD__sub_80347CC8(TWindowDD *window_dd, WordSelectMessage *message);
void TWindowDD__sub_80348D90(void *, int);
extern const f32 TWindowDD__data_805DFB6C;
extern const f32 TWindowDD__data_805DFB74;
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

void TWindowDD::format_type6_message(saddr window_dd, void *pos) {
    WordSelectMessage *arg0 = (WordSelectMessage *)this;
    s32 count;
    s32 n;
    s32 i;

    count = arg0->count;
    n = count;
    if (n > 3) {
        n = 3;
    }
    for (i = 0; i < n - 1; i++) {
        append_word_select_token(arg0->ids[i], window_dd, pos);
        TWindowDD::show_message_by_count((char *)window_dd, (s32 *)pos);
    }
    append_word_select_token(arg0->ids[n - 1], window_dd, pos);
    if (count > 3) {
        ((TWindowDD *)window_dd)->append_prompt_newline((s32 *)pos);
        append_word_select_token(arg0->ids[3], window_dd, pos);
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
        value = TWindowDD__sub_80348D88(entry);
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
    dst->numeric_value = src->numeric_value;
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
    if (pages[depth + offset] != NULL) {
        pages[depth + offset]->queue_destruction();
        pages[depth + offset] = NULL;
    }
}

void TWindowDD::set_item_pos(s32 i) {
    TWindowDD_WS_Word *page = pages[depth + i];
    if (page != NULL) {
        page->set_pos_and_data(lbl_805DFB94);
    }
}

extern "C" {

TWindowDD_WS_Word *TWindowDD__sub_80347980(TWindowDD *self) {
    TWindowDD_WS_Word *child;
    if (self->depth > 0) {
        child = self->pages[self->depth - 1];
        if (child != NULL) {
            self->update(child);
            self->list_ids[0] = TWindowDD__sub_8034214C(child);
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
        child = pages[level - 1];
        if (child != NULL) {
            child->init_and_mark_field8C();
            child->set_pos_and_data(TWindowDD__data_805DFB6C);
            child->target_size[0] = TWindowDD__data_805DFB74;
        }
    }
    return child;
}
extern "C" {

void TWindowDD__sub_80347A4C(TWindowDD *window_dd, TWindowDD_WS_Word *page) {
    s32 id;
    id = get_word_select_selected_id(page);
    if (TWindowDD::is_state_zero_unless_0x2C8(id) != 0) {
        TWindowDD__sub_80348DD8(&window_dd->message, id);
        TWindowDD__sub_80347CC8(window_dd, &window_dd->message);
        window_dd->word_appended = 1;
        window_dd->last_selected_id = (s16) id;
        return;
    }
    update_word_select_child_position(window_dd, 3);
    window_dd->word_appended = 0;
    window_dd->last_selected_id = (s16) id;
}

TWindowDD_WS_Word *TWindowDD__sub_80347AD4(TWindowDD *self, s32 offset, s32 id) {
    s32 i;
    TWindowDD_WS_Word *win;

    i = self->depth + offset;
    if (i >= 8) {
        return NULL;
    }
    win = self->pages[i];
    if (win == NULL) {
        win = TWindowDD__sub_80342384(id, (s32)lbl_805DFB54);
        TWindowDD::set_default_coords(self, win);
        self->pages[self->depth + offset] = win;
    }
    return win;
}

#pragma push
#pragma fp_contract on

void TWindowDD::update_selection_state() {
    s32 v;
    v = get_word_select_selected_id(pages[depth]);
    if ((s16)v != last_selected_id) {
        switch (word_appended) {
        case 0:
            if (TWindowDD::is_state_zero_unless_0x2C8(v) != 0) {
                TWindowDD__sub_80348DD8(&message, v);
                word_appended = 1;
            } else {
                TWindowDD__sub_80348D90(&message, v);
            }
            break;
        case 1:
            if (TWindowDD::is_state_zero_unless_0x2C8(v) != 0) {
                TWindowDD__sub_80348D90(&message, v);
            } else {
                message.pop_entry();
                word_appended = 0;
            }
            break;
        }
        TWindowDD__sub_80347CC8(this, &message);
        last_selected_id = (s16)v;
    }
}

void refresh_word_select_child_list(TWindowDD *self) {
    s32 next;

    next = dispatch_by_window_mode(self, self->state, self->list_ids[0], self->pages[self->depth]->get_field_68());
    if (next != self->list_ids[1]) {
        self->list_ids[1] = next;
        self->pages[self->depth + 1]->init_child(self->list_ids[1]);
    }
}

void TWindowDD__sub_80347CC8(TWindowDD *window_dd, WordSelectMessage *message) {
    TWindowDD_WS_String *s;
    E_80347CC8 *e;
    f32 x;
    f32 c;
    f32 max;
    f32 f10;
    TWindowDD::format_message(message, reinterpret_cast<char *>(TWindowDD::work_buffer), local_client_id);
    s = window_dd->strings[3];
    if (s != NULL) {
        e = (E_80347CC8 *)s->get_array_entry(0);
        if (e != NULL) {
            measure_message_text_width_default(e);
            x = 10.0f + e->f10;
            if (x >= 580.0f) {
                e->f8 = 580.0f - e->f10;
                x = 580.0f;
            } else {
                e->f8 = 0.0f;
            }
            s->target_size[0] = 2.0f * TWindowDD__data_805DFB58 + x;
            if (x <= 0.0f) {
                s->update_position(TWindowDD__data_805DFB50);
            } else {
                s->init_and_set_field50((void *)TWindowDD__data_805DFB50);
            }
        }
    }
}

s32 TWindowDD::setup_entry(s16 id) {
    s32 shown;
    TWindowDD_WS_String *text;

    s32 str;
    shown = 0;
    text = strings[2];
    if ((text != NULL) && ((str = get_word_select_token_text(id)) != 0)) {
        text->set_first_entry_text(str);
        TWindowDD__sub_803412A0(text);
        text->init_and_set_field50((void *)TWindowDD__data_805DFB50);
        shown = 1;
    }
    return shown;
}

void TWindowDD__sub_80347E04(TWindowDD *window_dd, s32 index) {
    NJS_POINT2 v;
    NJS_POINT2 a;
    NJS_POINT2 b;
    u32 r;
    TWindowDD_WS_String *o;
    window_dd->pages[window_dd->depth]->get_cursor_pos(&v);
    r = window_dd->pages[window_dd->depth]->update_if_field28_set();
    if (r != 0) {
        if (index == 0) {
            a.x = lbl_805DFBDC;
            a.y = lbl_805DFBE0;
        } else {
            a.x = lbl_805DFBE8;
            a.y = lbl_805DFBEC;
        }
        b.x = lbl_805DFB60;
        b.y = a.y;
        o = create_word_select_string(lbl_805DFBE4, (f32 *)&a, (f32 *)&b, (u32)r, 1);
        if (o != NULL) {
            o->set_depth(lbl_805DFC28);
            TWindowDD__sub_803412A0(o);
            copy_vec2(o->frame_position, &v);
            o->init_and_set_field50((void *)TWindowDD__data_805DFB50);
            window_dd->strings[index + 4] = o;
        }
    }
}
}

s32 TWindowDD::get_current_child_index() {
    TWindowDD_WS_Word *page;
    page = pages[depth];
    if (page != NULL) {
        return get_word_select_selected_id(page);
    }
    return -1;
}
#pragma pop


extern const f32 TWindowDD__data_805DFC10;

TWindowDDStateEntry *TWindowDD::get_state_entry(s32 state) { return &word_select_state_table[state]; }

void TWindowDD__sub_80347F48(TWindowDD *window_dd) {
    TWindowDD_WS_String *next;
    next = window_dd->strings[1];
    if (next != NULL) {
        next->target_position[0] = TWindowDD__data_805DFC10;
        next->tween_ticks = TWindowDD__data_805DFB50;
    }
}

void TWindowDD::init_entry_field_64(s32 index) {
    TWindowDD_WS_String *text;
    text = strings[index];
    if (text != NULL) {
        text->init_and_set_field50((void *)TWindowDD__data_805DFB50);
    }
}

void update_word_select_child_position(TWindowDD *window_dd, s32 index) {
    TWindowDD_WS_String *text;
    text = window_dd->strings[index];
    if (text != NULL) {
        text->update_position(TWindowDD__data_805DFB50);
    }
}

void TWindowDD::refresh_sub(void* p, void* a1) {
    TWindowDD_WS_Word *page = static_cast<TWindowDD_WS_Word *>(a1);
    TWindowDD__sub_80341AE0(page);
    page->set_mode_2();
}

void TWindowDD::apply_input(void* p, void* a1) {
    TWindowDD_WS_Word *page = static_cast<TWindowDD_WS_Word *>(a1);
    TWindowDD__sub_80341AE0(page);
    page->reset_cursor();
}

void TWindowDD::update(void* p, void* child) {
    TWindowDD_WS_Word *page = static_cast<TWindowDD_WS_Word *>(child);
    TWindowDD__sub_80341AE0(page);
    page->set_mode_2();
}


void TWindowDD::update(TWindowDD_WS_Word *window_dd) {
    TWindowDD__sub_80341AF8(window_dd);
    window_dd->reset_cursor();
    if (scroll_bar != NULL) {
        scroll_bar->set_scale(window_dd->get_field_0x74(), (s32) lbl_805DFB54);
        scroll_bar->set_value_f32(TWindowDD__sub_8034217C(window_dd));
    }
}

extern "C" {

        extern const float lbl_805DFB98;
    extern const float lbl_805DFB9C;
    extern const float lbl_805DFBA0;
void TWindowDD::set_default_coords(void *window, TWindowDD_WS_Word *win) {
    TWindowDD::refresh_sub(window, win);
    win->target_position[0] = lbl_805DFB94;
    win->frame_position[0] = lbl_805DFB94;
    win->target_position[1] = lbl_805DFB98;
    win->frame_position[1] = lbl_805DFB98;
    win->target_size[0] = lbl_805DFB9C;
    win->frame_size[0] = lbl_805DFB9C;
    win->target_size[1] = lbl_805DFBA0;
    win->frame_size[1] = lbl_805DFBA0;
}

    extern const float lbl_805DFB80;
    extern const float lbl_805DFB84;
    extern const float lbl_805DFB88;
    extern const float lbl_805DFB8C;
void TWindowDD::init_layout(void *window, TWindowDD_WS_Word *child) {
    TWindowDD::update(window, child);
    child->target_position[0] = lbl_805DFB80;
    child->frame_position[0] = lbl_805DFB80;
    child->target_position[1] = lbl_805DFB84;
    child->frame_position[1] = lbl_805DFB84;
    child->target_size[0] = lbl_805DFB88;
    child->frame_size[0] = lbl_805DFB88;
    child->target_size[1] = lbl_805DFB8C;
    child->frame_size[1] = lbl_805DFB8C;
}

        extern const float lbl_805DFB70;
        extern const float lbl_805DFB78;
void TWindowDD::set_default_positions(TWindowDD_WS_Word *child) {
    update(child);
    child->target_position[0] = TWindowDD__data_805DFB6C;
    child->frame_position[0] = TWindowDD__data_805DFB6C;
    child->target_position[1] = lbl_805DFB70;
    child->frame_position[1] = lbl_805DFB70;
    child->target_size[0] = TWindowDD__data_805DFB74;
    child->frame_size[0] = TWindowDD__data_805DFB74;
    child->target_size[1] = lbl_805DFB78;
    child->frame_size[1] = lbl_805DFB78;
}

void TWindowDD::spawn_window() { play_sound_effect(344320, 0, 0, 0); }
void TWindowDD::play_se() { play_sound_effect(339734, 0, 0, 0); }
void TWindowDD::play_sound() { play_sound_effect(339201, 0, 0, 0); }
u8 is_word_select_cancel_input(TWindowDD *window_dd) {
    s32 cancel;
    cancel = 0;
    if ((((s32)TWindowDD_check_input_mask(&window_dd->menu_index, 2)) != 0) || (window_dd->close_flags & 2)) {
        cancel = 1;
    }
    return (u8) cancel;
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
    return (enemies_present != 0 ? 1 : 0) + 2;
}

int TWindowDD__sub_80348424(s32 _w0, s32 _w1) { return TWindowDD__sub_8034B008((saddr)((void*)(1)), (_w1)); }

void TWindowDD__sub_80348448(s32 arg0, s16 id) {
    TWindowDD__sub_8034B008(0, ((s32) id));
}

s32 TWindowDD::get_mode_code() {
    s32 mode_status;
    mode_status = status;
    if (mode_status == 2) {
        return 1;
    }
    return ((mode_status - 3) == 0) ? 2 : 0;
}

void TWindowDD::set_state() { status = 3; close_all_windows(); }

void TWindowDD__sub_803484C4(TWindowDD *window_dd) {
    window_dd->status = 2;
    copy_chat_entry__9TWindowDDFPvPv(window_dd->result, &window_dd->message);
    if (window_dd->selection_confirmed != 0) {
        reset_selection__9TWindowDDFv(window_dd, &window_dd->message);
    }
    window_dd->close_all_windows();
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
        if (strings[i] != NULL) {
            strings[i]->close();
            strings[i] = NULL;
        }
    }
    for (i = 7; i >= 0; i--) {
        if (pages[i] != NULL) {
            pages[i]->close();
            pages[i] = NULL;
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
    u8 *arg0 = (u8 *)this;
    s32 p = *pos;
    if (((s32)TWindowDD::can_append_chars(3, pos)) != 0) {
        arg0[p++] = 0xA;
        arg0[p++] = 0x3E;
        arg0[p++] = 0x20;
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



struct Dst_80348A9C { u8 pad[0xc]; f32 x; f32 y; u8 pad2[4]; };

extern f32 lbl_805DFB1C;
WindowTexturePoint TWindowDD__data_805434E8[7][8];
extern s32 *TWindowDD__player_name_buffers;
extern s32 *TWindowDD__data_805D6E28;
extern s16 *lbl_805D6E34;
extern const f32 TWindowDD__data_805DFB58;
extern const f32 lbl_805DFB5C;
extern const f32 TWindowDD__data_805DFB20;
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
    ((TWindowDD *)(&sp8))->reset_entries(word_select_inverse_depth(draw_depth, offset), -1);
    ((TWindowDD *)(&sp8))->copy_point_table(idx);
    TWindowDD__sub_80348A2C(reinterpret_cast<WindowDrawContext *>(ctx), reinterpret_cast<WindowVertex *>(&sp8));
    TWindowDD__sub_803489B8(reinterpret_cast<WindowDrawContext *>(ctx), reinterpret_cast<WindowVertex *>(&sp8), 0);
    ((TWindowDD *)(&sp8))->draw_transformed_primitive(8, draw_count, 1);
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
    step = TWindowDD__data_805DFB20 * sc;
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
  f32 temp_f0;
  f32 temp_f0_2;
  f32 temp_f1;
  f32 temp_f1_2;
  s8 *new_var2;
  f32 temp_f2;
  f32 x;
  f32 temp_f4;
  s8 *new_var;
  f32 var_f0;
  temp_f2 = 0.5f * context->w;
  temp_f1 = temp_f2 * context->scale[0];
  temp_f0 = context->x + temp_f2;
  x = (0, temp_f0 - temp_f1);
  temp_f4 = temp_f0 + temp_f1;
  if (temp_f1 < lbl_805DFB1C)
  {
    var_f0 = (temp_f4 - x) / 3.0f;
  }
  else
  {
    var_f0 = lbl_805DFB1C;
  }
  new_var2 = ((s8 *) ((0, vertices))) + 0x90;
  *((f32 *) (((s8 *) vertices) + 0x18)) = x;
  temp_f1_2 = x + var_f0;
  temp_f0_2 = temp_f4 - var_f0;
  vertices->x = x;
  *((f32 *) (((s8 *) vertices) + 0x48)) = temp_f1_2;
  *((f32 *) (((s8 *) vertices) + 0x30)) = temp_f1_2;
  new_var = (s8 *) vertices;
  *((f32 *) (((s8 *) vertices) + 0x78)) = temp_f0_2;
  *((f32 *) (((s8 *) vertices) + 0x60)) = temp_f0_2;
  *((f32 *)(new_var + 0xA8)) = temp_f4;
  *((f32 *) new_var2) = temp_f4;
}

void TWindowDD::copy_point_table(s32 idx) {
    Dst_80348A9C *self = (Dst_80348A9C *)this;
    s32 i;
    const WindowTexturePoint *s = TWindowDD__data_805434E8[idx];
    for (i = 0; i < 8; i++) {
        self->x = s->x;
        self->y = s->y;
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
    ky = lbl_805DFB5C;
    x0 = x + TWindowDD__data_805DFB58;
    w = frame_size[0];
    h = frame_size[1];
    y0 = y + ky;
    context->inner_x = x0;
    context->inner_y = y0;
    context->inner_w = w - 2.0f * TWindowDD__data_805DFB58;
    context->inner_h = h - 2.0f * ky;
    context->clip_x0 = x0;
    context->clip_y0 = y0;
    context->clip_x1 = (x + w) - TWindowDD__data_805DFB58;
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
    return TWindowDD__data_805D6E28[lbl_805D6E34[id]];
}

saddr TWindowDD::get_entry(s32 index) {
    if ((index < 0) || (index >= (s32) twindowdd_entry_count)) {
        return 0;
    }
    return reinterpret_cast<saddr>(&TWindowDD::ws_data_table[index]);
}

