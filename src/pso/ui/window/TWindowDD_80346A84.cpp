#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDD_80346A84.h"

extern "C" {
void *load_encrypted_archive_data(const char *);

extern s32 TWindowDD__word_select_lists;
s32 window_dd_element_count;

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
}

extern s32 TWindowDD__data_805D6E28;
extern s32 lbl_805D6E34;
s32 twindowdd_entry_count;
s32 TWindowDD__data_805D6E40;
s32 TWindowDD__data_805D6E44;
s32 TWindowDD__data_805D6E48;
u8 *lbl_805D6E4C;
// inferred: the loaded ws_data_<lang>.bin archives ws_data_load keeps per language
void *ws_data_jp;
void *ws_data_us;
void *ws_data_es;
void *ws_data_de;
void *TWindowDD::ws_data_buffer;
char *lbl_805D6E64;
s8 lbl_805D6E68;
char *lbl_805D6E6C;
s8 lbl_805D6E70;

void ws_data_load(void) {
    void *data_jp;
    void *data_us;
    void *data_es;
    void *data_de;
    void *data_fr;

    switch ((s32) TWindowDD::window_mode) {
    case 0:
        data_jp = load_encrypted_archive_data("ws_data_jp.bin");
        ws_data_jp = data_jp;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)data_jp + 0);
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(data_jp)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(data_jp)[2];
        lbl_805D6E34 = *(s32 *)((s8 *)data_jp + 0xC);
        window_dd_element_count = 0x11A;
        twindowdd_entry_count = 0x12;
        return;
    default:
        data_us = load_encrypted_archive_data("ws_data_us.bin");
        ws_data_us = data_us;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)data_us + 0);
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(data_us)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(data_us)[2];
        lbl_805D6E34 = *(s32 *)((s8 *)data_us + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)data_us + 0x10);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)data_us + 0x14);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)data_us + 0x18);
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 4:
        data_es = load_encrypted_archive_data("ws_data_es.bin");
        ws_data_es = data_es;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)data_es + 0);
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(data_es)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(data_es)[2];
        lbl_805D6E34 = *(s32 *)((s8 *)data_es + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)data_es + 0x10);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)data_es + 0x18);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)data_es + 0x14);
        lbl_805D6E4C = *(u8 **)((s8 *)data_es + 0x20);
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 2:
        data_de = load_encrypted_archive_data("ws_data_de.bin");
        ws_data_de = data_de;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)data_de + 0);
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(data_de)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(data_de)[2];
        lbl_805D6E34 = *(s32 *)((s8 *)data_de + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)data_de + 0x10);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)data_de + 0x14);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)data_de + 0x18);
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 3:
        data_fr = load_encrypted_archive_data("ws_data_fr.bin");
        TWindowDD::ws_data_buffer = data_fr;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)data_fr + 0);
        TWindowDD::ws_data_base = reinterpret_cast<TWindowDDValueList **>(data_fr)[1];
        TWindowDD::ws_data_table = reinterpret_cast<TWindowDDValueList **>(data_fr)[2];
        lbl_805D6E34 = *(s32 *)((s8 *)data_fr + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)data_fr + 0x10);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)data_fr + 0x18);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)data_fr + 0x14);
        window_dd_element_count = 0x127;
        twindowdd_entry_count = 0x13;
        return;
    }
}

s32 TWindowDD__sub_80346DB8(TWindowDD *window_dd) {
  s32 list_id;
  s32 extra;
  list_id = 0;
  switch (window_dd->get_word_select_context())
  {
    case 0:
      list_id = 1;
      break;
    case 1:
      list_id = 3;
      break;
    case 2:
      list_id = 5;
      break;
    case 3:
      list_id = 7;
      break;
    case 4:
      list_id = 9;
      break;
    case 5:
      list_id = 0xB;
      break;
  }
  extra = 0;
  if (TWindowDD__sub_80346F30(window_dd) != 0)
  {
    extra = 1;
  }
  return list_id + extra;
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

s32 TWindowDD__sub_80346F30(TWindowDD *window_dd) {
    return window_dd->menu_index != -1;
}
