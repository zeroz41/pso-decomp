#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDD_80346A84.h"

extern "C" {
s32 get_word_select_context__9TWindowDDFv();
void *load_encrypted_archive_data(const char *);

extern s32 TWindowDD__window_mode;
extern s32 TWindowDD__word_select_lists;
extern s32 TWindowDD__ws_data_base;
s32 window_dd_element_count;

s32 TWindowDD::get_element_ptr(s32 arg0) {
    if (arg0 == -1) {
        return 0;
    }
    if (arg0 == -0x32) {
        switch ((s32) TWindowDD__window_mode) {
        case 0:
            return TWindowDD__ws_data_base + 0x8C0;
        default:
            return TWindowDD__ws_data_base + 0x920;
        case 4:
            return TWindowDD__ws_data_base + 0x920;
        case 2:
            return TWindowDD__ws_data_base + 0x920;
        case 3:
            return TWindowDD__ws_data_base + 0x928;
        }
    } else {
        if ((arg0 >= 0) && (arg0 < (s32) window_dd_element_count)) {
            return TWindowDD__ws_data_base + (arg0 * 8);
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
extern s32 TWindowDD__ws_data_table;
extern s32 lbl_805D6E34;
extern s32 twindowdd_entry_count;
extern s32 TWindowDD__data_805D6E40;
extern s32 TWindowDD__data_805D6E44;
extern s32 TWindowDD__data_805D6E48;
extern s32 lbl_805D6E4C;
extern void *lbl_805D6E50;
extern void *lbl_805D6E54;
extern void *lbl_805D6E58;
extern void *lbl_805D6E5C;
extern void *TWindowDD__ws_data_buffer;

void ws_data_load(void) {
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_3;
    void *temp_r3_4;
    void *temp_r3_5;

    switch ((s32) TWindowDD__window_mode) {
    case 0:
        temp_r3 = load_encrypted_archive_data("ws_data_jp.bin");
        lbl_805D6E50 = temp_r3;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)temp_r3 + 0);
        TWindowDD__ws_data_base = *(s32 *)((s8 *)temp_r3 + 4);
        TWindowDD__ws_data_table = *(s32 *)((s8 *)temp_r3 + 8);
        lbl_805D6E34 = *(s32 *)((s8 *)temp_r3 + 0xC);
        window_dd_element_count = 0x11A;
        twindowdd_entry_count = 0x12;
        return;
    default:
        temp_r3_2 = load_encrypted_archive_data("ws_data_us.bin");
        lbl_805D6E54 = temp_r3_2;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)temp_r3_2 + 0);
        TWindowDD__ws_data_base = *(s32 *)((s8 *)temp_r3_2 + 4);
        TWindowDD__ws_data_table = *(s32 *)((s8 *)temp_r3_2 + 8);
        lbl_805D6E34 = *(s32 *)((s8 *)temp_r3_2 + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)temp_r3_2 + 0x10);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)temp_r3_2 + 0x14);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)temp_r3_2 + 0x18);
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 4:
        temp_r3_3 = load_encrypted_archive_data("ws_data_es.bin");
        lbl_805D6E58 = temp_r3_3;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)temp_r3_3 + 0);
        TWindowDD__ws_data_base = *(s32 *)((s8 *)temp_r3_3 + 4);
        TWindowDD__ws_data_table = *(s32 *)((s8 *)temp_r3_3 + 8);
        lbl_805D6E34 = *(s32 *)((s8 *)temp_r3_3 + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)temp_r3_3 + 0x10);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)temp_r3_3 + 0x18);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)temp_r3_3 + 0x14);
        lbl_805D6E4C = *(s32 *)((s8 *)temp_r3_3 + 0x20);
        window_dd_element_count = 0x126;
        twindowdd_entry_count = 0x13;
        return;
    case 2:
        temp_r3_4 = load_encrypted_archive_data("ws_data_de.bin");
        lbl_805D6E5C = temp_r3_4;
        TWindowDD__data_805D6E28 = *(s32 *)((s8 *)temp_r3_4 + 0);
        TWindowDD__ws_data_base = *(s32 *)((s8 *)temp_r3_4 + 4);
        TWindowDD__ws_data_table = *(s32 *)((s8 *)temp_r3_4 + 8);
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
        TWindowDD__ws_data_base = *(s32 *)((s8 *)temp_r3_5 + 4);
        TWindowDD__ws_data_table = *(s32 *)((s8 *)temp_r3_5 + 8);
        lbl_805D6E34 = *(s32 *)((s8 *)temp_r3_5 + 0xC);
        TWindowDD__data_805D6E40 = *(s32 *)((s8 *)temp_r3_5 + 0x10);
        TWindowDD__data_805D6E48 = *(s32 *)((s8 *)temp_r3_5 + 0x18);
        TWindowDD__data_805D6E44 = *(s32 *)((s8 *)temp_r3_5 + 0x14);
        window_dd_element_count = 0x127;
        twindowdd_entry_count = 0x13;
        return;
    }
}

s32 TWindowDD__sub_80346DB8(s32 arg0) {
  s32 var_r31;
  s32 var_r30;
  s32 var_r3;
  var_r30 = arg0;
  var_r31 = 0;
  switch (get_word_select_context__9TWindowDDFv())
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
  if (TWindowDD__sub_80346F30((u8 *)((int) var_r3)) != 0)
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
