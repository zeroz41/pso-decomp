#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDD_80346A84.h"

extern "C" {
void *load_encrypted_archive_data(const char *);

extern s32 TWindowDD__window_mode;
extern s32 TWindowDD__word_select_lists;
s32 window_dd_element_count;

saddr TWindowDD::get_element_ptr(s32 arg0) {
    if (arg0 == -1) {
        return 0;
    }
    if (arg0 == -0x32) {
        switch ((s32) TWindowDD__window_mode) {
        case 0:
            return reinterpret_cast<saddr>(TWindowDD__ws_data_base) + 0x8C0;
        default:
            return reinterpret_cast<saddr>(TWindowDD__ws_data_base) + 0x920;
        case 4:
            return reinterpret_cast<saddr>(TWindowDD__ws_data_base) + 0x920;
        case 2:
            return reinterpret_cast<saddr>(TWindowDD__ws_data_base) + 0x920;
        case 3:
            return reinterpret_cast<saddr>(TWindowDD__ws_data_base) + 0x928;
        }
    } else {
        if ((arg0 >= 0) && (arg0 < (s32) window_dd_element_count)) {
            return reinterpret_cast<saddr>(TWindowDD__ws_data_base) + (arg0 * 8);
        }
        switch (arg0) {
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
void *TWindowDD__ws_data_buffer;
char *lbl_805D6E64;
s8 lbl_805D6E68;
char *lbl_805D6E6C;
s8 lbl_805D6E70;

void ws_data_load(void) {
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_3;
    void *temp_r3_4;
    void *temp_r3_5;

    switch ((s32) TWindowDD__window_mode) {
    case 0:
        temp_r3 = load_encrypted_archive_data("ws_data_jp.bin");
        ws_data_jp = temp_r3;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)temp_r3 + 0);
        TWindowDD__ws_data_base = reinterpret_cast<TWindowDDValueList **>(temp_r3)[1];
        TWindowDD__ws_data_table = reinterpret_cast<TWindowDDValueList **>(temp_r3)[2];
        lbl_805D6E34 = *(s32 *)((s8 *)temp_r3 + 0xC);
        window_dd_element_count = 0x11A;
        twindowdd_entry_count = 0x12;
        return;
    default:
        temp_r3_2 = load_encrypted_archive_data("ws_data_us.bin");
        ws_data_us = temp_r3_2;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)temp_r3_2 + 0);
        TWindowDD__ws_data_base = reinterpret_cast<TWindowDDValueList **>(temp_r3_2)[1];
        TWindowDD__ws_data_table = reinterpret_cast<TWindowDDValueList **>(temp_r3_2)[2];
        lbl_805D6E34 = *(s32 *)((s8 *)temp_r3_2 + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)temp_r3_2 + 0x10);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)temp_r3_2 + 0x14);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)temp_r3_2 + 0x18);
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 4:
        temp_r3_3 = load_encrypted_archive_data("ws_data_es.bin");
        ws_data_es = temp_r3_3;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)temp_r3_3 + 0);
        TWindowDD__ws_data_base = reinterpret_cast<TWindowDDValueList **>(temp_r3_3)[1];
        TWindowDD__ws_data_table = reinterpret_cast<TWindowDDValueList **>(temp_r3_3)[2];
        lbl_805D6E34 = *(s32 *)((s8 *)temp_r3_3 + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)temp_r3_3 + 0x10);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)temp_r3_3 + 0x18);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)temp_r3_3 + 0x14);
        lbl_805D6E4C = *(u8 **)((s8 *)temp_r3_3 + 0x20);
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 2:
        temp_r3_4 = load_encrypted_archive_data("ws_data_de.bin");
        ws_data_de = temp_r3_4;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)temp_r3_4 + 0);
        TWindowDD__ws_data_base = reinterpret_cast<TWindowDDValueList **>(temp_r3_4)[1];
        TWindowDD__ws_data_table = reinterpret_cast<TWindowDDValueList **>(temp_r3_4)[2];
        lbl_805D6E34 = *(s32 *)((s8 *)temp_r3_4 + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)temp_r3_4 + 0x10);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)temp_r3_4 + 0x14);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)temp_r3_4 + 0x18);
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 3:
        temp_r3_5 = load_encrypted_archive_data("ws_data_fr.bin");
        TWindowDD__ws_data_buffer = temp_r3_5;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)temp_r3_5 + 0);
        TWindowDD__ws_data_base = reinterpret_cast<TWindowDDValueList **>(temp_r3_5)[1];
        TWindowDD__ws_data_table = reinterpret_cast<TWindowDDValueList **>(temp_r3_5)[2];
        lbl_805D6E34 = *(s32 *)((s8 *)temp_r3_5 + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)temp_r3_5 + 0x10);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)temp_r3_5 + 0x18);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)temp_r3_5 + 0x14);
        window_dd_element_count = 0x127;
        twindowdd_entry_count = 0x13;
        return;
    }
}

s32 TWindowDD__sub_80346DB8(saddr window_dd) {
  s32 var_r31;
  s32 var_r30;
  saddr var_r3;
  var_r30 = window_dd;
  var_r31 = 0;
  switch (((TWindowDD *)window_dd)->get_word_select_context())
  {
    case 0:
      var_r31 = 1;
      break;
    case 1:
      var_r31 = 3;
      if (var_r30)
    {
    }
      break;
    case 2:
      var_r31 = 5;
      break;
    case 3:
      var_r31 = 7;
      break;
    case 4:
      var_r31 = 9;
      break;
    case 5:
      var_r31 = 0xB;
      break;
  }
  var_r3 = var_r30;
  var_r30 = 0;
  if (TWindowDD__sub_80346F30((u8 *)((saddr) var_r3)) != 0)
  {
    var_r30 = 1;
  }
  var_r3 = var_r31 + var_r30;
  return var_r3;
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

s32 TWindowDD__sub_80346F30(u8 *arg0) {
    return *(s16 *)((s8 *)arg0 + 0x1C) != -1;
}
