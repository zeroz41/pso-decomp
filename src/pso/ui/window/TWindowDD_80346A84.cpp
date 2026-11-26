#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDD_80346A84.h"

void *load_encrypted_archive_data(const char *);
extern "C" {

extern s32 TWindowDD__word_select_lists;
s32 window_dd_element_count;
}

saddr TWindowDD::get_element_ptr(s32 index) {
    if (index == -1) {
        return 0;
    }
    if (index == -0x32) {
        switch ((s32) TWindowDD::window_mode) {
        case 0:
            return reinterpret_cast<saddr>(TWindowDD::ws_data_base) + 0x8C0;
        default:
            return reinterpret_cast<saddr>(TWindowDD::ws_data_base) + 0x920;
        case 4:
            return reinterpret_cast<saddr>(TWindowDD::ws_data_base) + 0x920;
        case 2:
            return reinterpret_cast<saddr>(TWindowDD::ws_data_base) + 0x920;
        case 3:
            return reinterpret_cast<saddr>(TWindowDD::ws_data_base) + 0x928;
        }
    } else {
        if ((index >= 0) && (index < (s32) window_dd_element_count)) {
            return reinterpret_cast<saddr>(TWindowDD::ws_data_base) + (index * 8);
        }
        switch (index) {
        default:
            return 0;
        case -60:
            return TWindowDD__word_select_lists + 0x10;
        case -70:
            return TWindowDD__word_select_lists + 0x18;
        case -40:
            return TWindowDD__word_select_lists;
        case -45:
            return TWindowDD__word_select_lists + 8;
        case -80:
            return TWindowDD__word_select_lists + 0x20;
        case -90:
            return TWindowDD__word_select_lists + 0x28;
        }
    }
}

extern s32 ws_word_strings;
extern s32 ws_word_string_index;
s32 twindowdd_entry_count;
s32 TWindowDD__data_805D6E40;
s32 TWindowDD__data_805D6E44;
s32 TWindowDD__data_805D6E48;
u8 *lbl_805D6E4C;
// inferred: ws_word_strings and ws_word_string_index are words 0 and 3 of the ws_data archive (id -> string).
// inferred: the loaded ws_data_<lang>.bin archives ws_data_load keeps per language
void *ws_data_jp;
void *ws_data_us;
void *ws_data_es;
void *ws_data_de;
void *TWindowDD::ws_data_buffer;
char *word_page_select_label;
s8 word_page_select_label_set;
char *word_page_next_label;
s8 word_page_next_label_set;

void ws_data_load(void) {
    void *jp_data;
    void *us_data;
    void *es_data;
    void *de_data;
    void *fr_data;

    switch ((s32) TWindowDD::window_mode) {
    case 0:
        jp_data = load_encrypted_archive_data("ws_data_jp.bin");
        ws_data_jp = jp_data;
        ws_word_strings = *(s32 *)((s8 *)jp_data + 0);
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(jp_data)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(jp_data)[2];
        ws_word_string_index = *(s32 *)((s8 *)jp_data + 0xC);
        window_dd_element_count = 0x11A;
        twindowdd_entry_count = 0x12;
        return;
    default:
        us_data = load_encrypted_archive_data("ws_data_us.bin");
        ws_data_us = us_data;
        ws_word_strings = *(s32 *)((s8 *)us_data + 0);
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(us_data)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(us_data)[2];
        ws_word_string_index = *(s32 *)((s8 *)us_data + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)us_data + 0x10);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)us_data + 0x14);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)us_data + 0x18);
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 4:
        es_data = load_encrypted_archive_data("ws_data_es.bin");
        ws_data_es = es_data;
        ws_word_strings = *(s32 *)((s8 *)es_data + 0);
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(es_data)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(es_data)[2];
        ws_word_string_index = *(s32 *)((s8 *)es_data + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)es_data + 0x10);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)es_data + 0x18);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)es_data + 0x14);
        lbl_805D6E4C = *(u8 **)((s8 *)es_data + 0x20);
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 2:
        de_data = load_encrypted_archive_data("ws_data_de.bin");
        ws_data_de = de_data;
        ws_word_strings = *(s32 *)((s8 *)de_data + 0);
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(de_data)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(de_data)[2];
        ws_word_string_index = *(s32 *)((s8 *)de_data + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)de_data + 0x10);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)de_data + 0x14);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)de_data + 0x18);
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 3:
        fr_data = load_encrypted_archive_data("ws_data_fr.bin");
        TWindowDD::ws_data_buffer = fr_data;
        ws_word_strings = *(s32 *)((s8 *)fr_data + 0);
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(fr_data)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(fr_data)[2];
        ws_word_string_index = *(s32 *)((s8 *)fr_data + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)fr_data + 0x10);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)fr_data + 0x18);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)fr_data + 0x14);
        window_dd_element_count = 0x127;
        twindowdd_entry_count = 0x13;
        return;
    }
}

s32 get_initial_word_select_list(TWindowDD *window_dd) {
  s32 list_base;
  s32 offset;
  list_base = 0;
  switch (window_dd->get_word_select_context())
  {
    case 0:
      list_base = 1;
      break;
    case 1:
      list_base = 3;
      break;
    case 2:
      list_base = 5;
      break;
    case 3:
      list_base = 7;
      break;
    case 4:
      list_base = 9;
      break;
    case 5:
      list_base = 0xB;
      break;
  }
  offset = 0;
  if (has_menu_selection(window_dd) != 0)
  {
    offset = 1;
  }
  return list_base + offset;
}

void TWindowDD::render() {  }

s16 TWindowDD_read_indexed_value(s32 entry_index, s32 value_index) {
    s16 result;
    TWindowDDValueList *entry;
    result = -1;
    entry = (TWindowDDValueList *)TWindowDD::get_entry(entry_index);
    if (entry != NULL) {
        if ((value_index < 0) || (value_index >= entry->count)) {
            result = -1;
        } else {
            result = entry->values[value_index];
        }
    }
    return result;
}

s16 TWindowDD_read_resolved_value(s32 entry_id, s32 value_index) {
    s16 result;
    TWindowDDValueList *entry;
    result = -1;
    entry = (TWindowDDValueList *)TWindowDD::get_element_ptr(entry_id);
    if (entry != NULL) {
        if ((value_index < 0) || (value_index >= entry->count)) {
            result = -1;
        } else {
            result = entry->values[value_index];
        }
    }
    return result;
}

s32 has_menu_selection(TWindowDD *window_dd) {
    return window_dd->menu_index != -1;
}
