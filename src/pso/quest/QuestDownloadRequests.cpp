#include "types.h"
#include "pso/quest/AskDicConvert.h"
#include <string.h>
#include "pso/quest/QuestDownloadRecords.h"
#include "pso/quest/QuestDownloadText.h"
#include "pso/quest/QuestDownloadWorkspace.h"
#include "pso/quest/QuestDownloadRequests.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/QuestDownloadServer.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include <stddef.h>
#include "pso/quest/AskDicFile.h"

#pragma readonly_strings on

s32 ask_header_dirty;
u8 *allowed_char_bitmap;
s32 lbl_805D7828;
s32 quest_download_initialized;
s32 lbl_805D7830;
s32 quest_download_state;
s32 lbl_805D7838;
s32 lbl_805D783C;
s32 lbl_805D7840;
s32 lbl_805D7844;
s32 text_input_mode;
extern u8 candidate_number_label[];

// Handlers by request id (1..63); unassigned ids return -1.
typedef s32 (*KeyBoardSoftHandler)(saddr *args);
static const KeyBoardSoftHandler keyboard_soft_dispatch_fn_table[63] = {
    quest_download_request_unassigned, // 0x01
    quest_download_request_unassigned, // 0x02
    quest_download_request_unassigned, // 0x03
    quest_download_request_unassigned, // 0x04
    quest_download_request_unassigned, // 0x05
    quest_download_request_unassigned, // 0x06
    quest_download_request_unassigned, // 0x07
    quest_download_request_unassigned, // 0x08
    quest_download_request_unassigned, // 0x09
    quest_download_request_unassigned, // 0x0A
    quest_download_request_unassigned, // 0x0B
    quest_download_request_unassigned, // 0x0C
    quest_download_request_unassigned, // 0x0D
    quest_download_request_unassigned, // 0x0E
    convert_jis_to_sjis_string, // 0x0F
    convert_jis_to_sjis_string, // 0x10
    quest_download_request_unassigned, // 0x11
    quest_download_request_unassigned, // 0x12
    quest_download_request_convert, // 0x13
    handle_list_scroll, // 0x14
    handle_list_scroll, // 0x15
    quest_download_request_turn_page, // 0x16
    quest_download_request_turn_page, // 0x17
    quest_download_request_convert_all, // 0x18
    quest_download_request_select_candidate, // 0x19
    quest_download_request_unassigned, // 0x1A
    quest_download_request_unassigned, // 0x1B
    poll_download_status, // 0x1C
    reset_download_buffers, // 0x1D
    quest_download_request_edit_word, // 0x1E
    quest_download_request_edit_word, // 0x1F
    quest_download_request_open, // 0x20
    quest_download_request_extend_segment, // 0x21
    quest_download_request_shrink_segment, // 0x22
    quest_download_request_prev_segment, // 0x23
    quest_download_request_next_segment, // 0x24
    quest_download_request_convert_as, // 0x25
    quest_download_request_convert_as, // 0x26
    quest_download_request_convert_as, // 0x27
    quest_download_request_convert_as, // 0x28
    quest_download_request_convert_as, // 0x29
    quest_download_request_convert_as, // 0x2A
    quest_download_request_convert_as, // 0x2B
    quest_download_request_convert_as, // 0x2C
    quest_download_request_unassigned, // 0x2D
    quest_download_request_unassigned, // 0x2E
    quest_download_request_unassigned, // 0x2F
    quest_download_request_unassigned, // 0x30
    quest_download_request_unassigned, // 0x31
    quest_download_request_unassigned, // 0x32
    quest_download_request_unassigned, // 0x33
    quest_download_request_unassigned, // 0x34
    quest_download_request_unassigned, // 0x35
    quest_download_request_unassigned, // 0x36
    quest_download_request_unassigned, // 0x37
    quest_download_request_unassigned, // 0x38
    quest_download_request_unassigned, // 0x39
    quest_download_request_unassigned, // 0x3A
    quest_download_request_unassigned, // 0x3B
    quest_download_request_unassigned, // 0x3C
    quest_download_request_unassigned, // 0x3D
    quest_download_request_unassigned, // 0x3E
    quest_download_request_unassigned, // 0x3F
};

// Request kind (1..30) to download text code.
static const u8 quest_download_code_remap_table[30] = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
    0x0C, 0x0D, 0x0E, 0x13, 0x14, 0x16, 0x18, 0x28, 0x1B, 0x1C,
    0x1A, 0x1D, 0x1E, 0x1F, 0x1F, 0x32, 0x20, 0x21, 0x22, 0x26,
};

s32 quest_download_request_unassigned(saddr *) {
    return -1;
}

s32 quest_download_request_convert_as(saddr *args) {
    saddr segment;
    saddr rest;
    s32 k;
    if (quest_download_state != 3) {
        return -1;
    }
    segment = args[0];
    rest = args[1];
    switch (args[-1]) {
    case 37:
        k = 2;
        break;
    case 38:
        k = 1;
        break;
    case 39:
        k = 3;
        break;
    case 40:
        k = 4;
        break;
    }
    rebuild_current_slot_text_chain(k);
    if (quest_download_slot_chain_table[quest_text_cursor_pos].chain == NULL) {
        return -1;
    }
    seek_quest_text_page(0, 1);
    strcpy((char *)segment, (const char *)get_entry_text(quest_text_cursor_pos, quest_text_entry_len));
    strcpy((char *)rest, (const char *)get_entry_text((quest_text_cursor_pos + quest_text_entry_len), ((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len)));
    return 0;
}

s32 quest_download_request_next_segment(saddr *args) {
    saddr segment;
    saddr rest;

    if (quest_download_state != 3) {
        return -1;
    }
    segment = args[0];
    rest = args[1];
    if ((s32) (quest_text_cursor_pos + quest_text_entry_len) >= (s32) quest_text_end) {
        return 0;
    }
    free_slot_node_chain(quest_text_cursor_pos, 0);
    quest_text_cursor_pos += quest_text_entry_len;
    quest_text_entry_len = get_slot_entry_length(quest_text_cursor_pos);
    seek_quest_text_page(0, 1);
    strcpy((char *)segment, (const char *)(get_entry_text(quest_text_cursor_pos, quest_text_entry_len)));
    strcpy((char *)rest, (const char *)(get_entry_text((quest_text_cursor_pos + quest_text_entry_len), ((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len))));
    return count_quest_text_entries(quest_download_slot_chain_table[quest_text_cursor_pos].chain);
}
s32 quest_download_request_prev_segment(saddr *args) {
    saddr segment;
    saddr rest;
    s32 i;
    s32 n;

    if (quest_download_state != 3) {
        return -1;
    }
    segment = args[0];
    rest = args[1];
    if (quest_text_cursor_pos == 0) {
        return 0;
    }
    free_slot_node_chain(quest_text_cursor_pos, 0);
    for (i = 0; i < quest_text_cursor_pos; i += n) {
        n = get_slot_entry_length(i);
        if (i + n >= quest_text_cursor_pos) {
            break;
        }
    }
    quest_text_cursor_pos = i;
    quest_text_entry_len = n;
    seek_quest_text_page(0, 1);
    strcpy((char *)segment, (const char *)get_entry_text(quest_text_cursor_pos, quest_text_entry_len));
    strcpy((char *)rest, (const char *)get_entry_text((quest_text_cursor_pos + quest_text_entry_len), ((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len)));
    return count_quest_text_entries(quest_download_slot_chain_table[quest_text_cursor_pos].chain);
}
s32 quest_download_request_shrink_segment(saddr *args) {
    saddr segment;
    saddr rest;

    if (quest_download_state != 3) {
        return -1;
    }
    segment = args[0];
    rest = args[1];
    if ((s32) quest_text_entry_len <= 1) {
        return 0;
    }
    latch_slot_value(quest_text_cursor_pos);
    reset_slot_range(quest_text_cursor_pos, quest_text_end, 1);
    quest_text_entry_len -= 1;
    convert_input_range(quest_text_cursor_pos, quest_text_end, 1, quest_text_entry_len);
    seek_quest_text_page(0, 1);
    strcpy((char *)segment, (const char *)(get_entry_text(quest_text_cursor_pos, quest_text_entry_len)));
    strcpy((char *)rest, (const char *)(get_entry_text((quest_text_cursor_pos + quest_text_entry_len), ((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len))));
    return count_quest_text_entries(quest_download_slot_chain_table[quest_text_cursor_pos].chain);
}
s32 quest_download_request_extend_segment(saddr *args) {
    saddr segment;
    saddr rest;

    if (quest_download_state != 3) {
        return -1;
    }
    segment = args[0];
    rest = args[1];
    if ((s32) (quest_text_cursor_pos + quest_text_entry_len) >= (s32) quest_text_end) {
        return 0;
    }
    latch_slot_value(quest_text_cursor_pos);
    reset_slot_range(quest_text_cursor_pos, quest_text_end, 1);
    quest_text_entry_len += 1;
    convert_input_range(quest_text_cursor_pos, quest_text_end, 1, quest_text_entry_len);
    seek_quest_text_page(0, 1);
    strcpy((char *)segment, (const char *)(get_entry_text(quest_text_cursor_pos, quest_text_entry_len)));
    strcpy((char *)rest, (const char *)(get_entry_text((quest_text_cursor_pos + quest_text_entry_len), ((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len))));
    return count_quest_text_entries(quest_download_slot_chain_table[quest_text_cursor_pos].chain);
}

s32 quest_download_request_open(saddr *args) {
    u32 i;
    for (i = 0; i < 80; i++) {
        name_entry_name_buffer[i] = 0;
        name_entry_text_buffer[i] = 0;
    }
    {
        saddr src = *args;
        strcpy(quest_convert_string.value, reinterpret_cast<const char *>(src));
    }
    quest_download_state = 0;
    lbl_805D7830 = 0;
    quest_download_initialized = 1;
    lbl_805D7828 = 0;
    allowed_char_bitmap = ask_header_buffer + 0x4E;
    quest_download_file_handle = -1;
    ask_header_dirty = 0;
    ask_learning_enabled = 0;
    number_format_mode = 0;
    ask_dictionary_open_mode = 0x8002;
    ask_convert_mode = 0;
    lbl_805D7884 = 1;
    lbl_805D7880 = 0;
    japanese_punctuation_enabled = 1;
    lbl_805D78E0 = 0x4000;
    text_input_mode = 0;
    quest_download_match_length_limit = 0x24;
    strcpy((char *)candidate_number_label, (const char *)"  1.");
    strcpy((char *)quest_download_display_prefix.text, (const char *)"  \x8E\x63      "); // "  残      " (remaining)
    quest_download_server_state = 0;
    lbl_805D7844 = 0;
    lbl_805D7840 = 0;
    lbl_805D783C = 0;
    lbl_805D7838 = 0;
    quest_download_free_list_ready_flag = 1;
    return 0;
}

s32 quest_download_request_edit_word(saddr *args) {
  s32 kind;
  u8 *text;
  s32 code;
  u8 *src;
  int index_base;
  u16 ch;
  u8 *dst;
  s32 n;
  s32 idx;
  s32 mode;
  u8 r;
  s32 ret;
  QuestDownloadRequest req;
  if ((text_input_mode >= 2) || (quest_download_state >= 2))
  {
    return 4;
  }
  mode = args[0];
  kind = args[-1];
  if ((mode != 1) && (mode != 0))
  {
    return 1;
  }
  index_base = 1;
  idx = args[3];
  src = (u8 *) args[1];
  text = (u8 *) args[2];
  if (((idx - 1) < 0) || ((idx - 1) >= 30))
  {
    code = -1;
  }
  else
  {
    code = (idx - index_base)[quest_download_code_remap_table];
  }
  if (code < 0)
  {
    return 2;
  }
  dst = quest_request_text_buffer;
  n = 0;
  while ((*src) != 0)
  {
    ch = (src[0] << 8) | src[1];
    if (is_sjis_double_byte(ch) == 0)
    {
      return 3;
    }
    ch = sjis_to_jis(ch);
    r = jis_to_single_byte(ch);
    if (r == 0)
    {
      return 3;
    }
    *(dst++) = r;
    n++;
    src += 2;
  }
  *dst = 0;
  req.name = (char *)quest_request_text_buffer;
  req.len = (s16) n;
  req.pad6 = 0;
  req.x7 = code;
  req.x8 = 0;
  req.text = text;
  if (kind == 30)
  {
    if (register_name_entry(&req) == 3)
    {
      return 0;
    }
  }
  else
    if (kind == 31)
  {
    ret = delete_name_entry(&req);
    if (ret == 3)
    {
      return 0;
    }
    if (ret == 0)
    {
      return -1;
    }
  }
  return 4;
}

s32 reset_download_buffers(saddr *) {
    if (quest_download_initialized == 0) {
        return -1;
    }
    init_buffer_pointers();
    save_and_close_download_file();
    quest_download_state = 0;
    return 0;
}
s32 poll_download_status(saddr *) {
    if (quest_download_initialized == 0) {
        return -1;
    }
    if (open_ask_dictionary(reinterpret_cast<s8 *>(quest_convert_string.value)) == -7) {
        return 1;
    }
    reset_text_input_state(0);
    quest_download_state = 1;
    return 0;
}
s32 quest_download_request_select_candidate(saddr *args) {
    s32 n;
    saddr b;
    s8 *c;
    s16 *d;
    s8 *a;
    s32 ret;

    if (quest_download_state != 3) {
        return -1;
    }
    n = args[0];
    if (n <= 0 || n > quest_page_node_count) {
        return 0;
    }
    b = args[1];
    a = (s8 *)args[2];
    c = (s8 *)args[3];
    d = (s16 *)args[4];
    quest_page_node_index = n - 1;
    strcpy((char *)b, (const char *)get_entry_text(quest_text_cursor_pos, quest_text_entry_len));
    free_slot_node_chain(quest_text_cursor_pos, 1);
    ret = sum_entry_sizes(quest_text_cursor_pos, quest_text_entry_len);
    quest_text_cursor_pos += quest_text_entry_len;
    if (quest_text_cursor_pos >= quest_text_end) {
        *a = 0;
        *c = 0;
        *d = 0;
        return ret;
    }
    quest_text_entry_len = get_slot_entry_length(quest_text_cursor_pos);
    seek_quest_text_page(0, 1);
    strcpy((char *)a, (const char *)get_entry_text(quest_text_cursor_pos, quest_text_entry_len));
    strcpy((char *)c, (const char *)get_entry_text((quest_text_cursor_pos + quest_text_entry_len), ((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len)));
    *d = (s16)count_quest_text_entries(quest_download_slot_chain_table[quest_text_cursor_pos].chain);
    return ret;
}
s32 quest_download_request_convert_all(saddr *args) {
    saddr out;
    if (quest_download_state != 3) {
        return -1;
    }
    out = args[0];
    process_entry_text_range(0, quest_text_end);
    strcpy((char *)out, (const char *)convert_all_entry_text());
    init_buffer_pointers();
    quest_download_state = 1;
    return 0;
}
s32 quest_download_request_turn_page(saddr *args) {
    s32 err;
    saddr a;
    saddr b;
    err = 0;
    if (quest_download_state != 3) {
        return 0;
    }
    a = args[0];
    b = args[1];
    switch (args[-1]) {
    case 22:
        if (quest_text_prev_page(0, 0) == 0) {
            err = 1;
        }
        break;
    case 23:
        if (quest_text_next_page(0, 0) == 0) {
            err = 1;
        }
        break;
    }
    strcpy((char *)a, (const char *)get_entry_text(quest_text_cursor_pos, quest_text_entry_len));
    strcpy((char *)b, (const char *)get_entry_text((quest_text_cursor_pos + quest_text_entry_len), ((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len)));
    if (err != 0) {
        return 0;
    }
    return quest_page_node_count;
}
s32 handle_list_scroll(saddr *args) {
    saddr b;
    saddr a;
    s32 n;
    u8 unused[8];
    if (quest_download_state != 3) {
        return 0;
    }
    a = args[0];
    b = args[1];
    switch (args[-1]) {
    case 20:
        if (quest_page_node_index > 0) {
            quest_page_node_index--;
        } else if (quest_text_prev_page(0, 0) == 0) {
            seek_quest_text_page(0, 1);
            n = quest_page_node_count;
            while (quest_text_next_page(0, 0) != 0) {
                n += quest_page_node_count;
            }
            seek_quest_text_page(n - 1, 1);
        } else {
            quest_page_node_index = quest_page_node_count - 1;
        }
        break;
    case 21:
        if (quest_page_node_index < quest_page_node_count - 1) {
            quest_page_node_index++;
        } else if (quest_text_next_page(0, 0) == 0) {
            seek_quest_text_page(0, 1);
        }
        break;
    }
    strcpy((char *)a, (const char *)get_entry_text(quest_text_cursor_pos, quest_text_entry_len));
    strcpy((char *)b, (const char *)get_entry_text((quest_text_cursor_pos + quest_text_entry_len), ((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len)));
    return quest_page_node_index + 1;
}
s32 quest_download_request_convert(saddr *args) {
    u32 id;
    s8 *a;
    s8 *b;
    if (quest_download_state == 0) {
        return -1;
    }
    id = args[0];
    a = (s8 *)args[1];
    b = (s8 *)args[2];
    if (id != 0) {
        if (quest_download_state >= 2) {
            init_buffer_pointers();
        }
        if (set_input_text(id) < 0) {
            return -1;
        }
    }
    if (quest_text_end <= 0) {
        *a = 0;
        *b = 0;
        return 0;
    }
    convert_input_range(0, quest_text_end, 0, -1);
    quest_text_cursor_pos = 0;
    quest_text_entry_len = get_slot_entry_length(0);
    seek_quest_text_page(0, 1);
    strcpy((char *)a, (const char *)get_entry_text(quest_text_cursor_pos, quest_text_entry_len));
    strcpy((char *)b, (const char *)get_entry_text((quest_text_cursor_pos + quest_text_entry_len), ((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len)));
    quest_download_state = 3;
    return count_quest_text_entries(quest_download_slot_chain_table[0].chain);
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
s32 convert_jis_to_sjis_string(saddr *args) {
    u16 buf[4];
    s32 cnt;
    u8 *src;
    u8 *dst;
    u16 flag;
    u16 *p;
    s32 n;
    s32 r;
    u16 *q;
    u16 c;
    src = (u8 *)args[0];
    dst = (u8 *)args[1];
    if (args[-1] == 0xF) {
        flag = 0x4100;
    } else {
        flag = 0x4000;
    }
    p = quest_download_text_buffer.words;
    n = 0;
    while (*src != 0 && p < quest_download_text_buffer.words + 0x200) {
        *p++ = *src++ | flag;
        n++;
    }
    p = quest_download_text_buffer.words;
    while (n > 0) {
        r = convert_romaji_to_kana(p, n, buf, &cnt);
        if (r <= 0) {
            if (r != -1) {
                return (p - quest_download_text_buffer.words) + 1;
            }
            r = 1;
        }
        p += r;
        n -= r;
        q = buf;
        while (cnt-- != 0) {
            c = jis_to_sjis(*q++);
            if (c == 0x82F2) {
                c = 0x8394;
            }
            dst[0] = c >> 8;
            dst[1] = c;
            dst += 2;
        }
    }
    *dst = 0;
    return 0;
}
#pragma pop

u8 name_entry_text_buffer[80];
u8 name_entry_name_buffer[80];
u8 learned_name_text_buffer[80];
u8 quest_request_text_buffer[80];
QuestConvertString quest_convert_string;


s32 ime_dispatch_request(ImeRequest *request) {
    s32 i = request->id;
    saddr *args = (saddr *)(request + 1);
    if (i <= 0 || (u32)i > 0x3F) {
        return -1;
    }
    return keyboard_soft_dispatch_fn_table[i - 1](args);
}

s32 ime_request_convert_to_fullwidth(char *text, char *rest) {
    ImeTextRequest req;
    req.id = 0x28;
    req.text = text;
    req.rest = rest;
    return ime_dispatch_request(&req);
}

s32 ime_request_convert_to_halfwidth_kana(char *text, char *rest) {
    ImeTextRequest req;
    req.id = 0x27;
    req.text = text;
    req.rest = rest;
    return ime_dispatch_request(&req);
}

s32 ime_request_convert_to_hiragana(char *text, char *rest) {
    ImeTextRequest req;
    req.id = 0x26;
    req.text = text;
    req.rest = rest;
    return ime_dispatch_request(&req);
}

s32 ime_request_convert_to_katakana(char *text, char *rest) {
    ImeTextRequest req;
    req.id = 0x25;
    req.text = text;
    req.rest = rest;
    return ime_dispatch_request(&req);
}

s32 ime_request_next_segment(char *text, char *rest) {
    ImeTextRequest req;
    req.id = 0x24;
    req.text = text;
    req.rest = rest;
    return ime_dispatch_request(&req);
}

s32 ime_request_prev_segment(char *text, char *rest) {
    ImeTextRequest req;
    req.id = 0x23;
    req.text = text;
    req.rest = rest;
    return ime_dispatch_request(&req);
}

s32 ime_request_shrink_segment(char *text, char *rest) {
    ImeTextRequest req;
    req.id = 0x22;
    req.text = text;
    req.rest = rest;
    return ime_dispatch_request(&req);
}

s32 ime_request_extend_segment(char *text, char *rest) {
    ImeTextRequest req;
    req.id = 0x21;
    req.text = text;
    req.rest = rest;
    return ime_dispatch_request(&req);
}

s32 ime_request_open(const char *a, const char *b) {
    ImeOpenRequest req;
    req.id = 0x20;
    req.a = a;
    req.b = b;
    return ime_dispatch_request(&req);
}

s32 ime_request_poll_status() {
    ImeRequest req;
    req.id = 0x1C;
    return ime_dispatch_request(&req);
}

s32 ime_request_next_candidate(char *text, char *rest) {
    ImeTextRequest req;
    req.id = 0x15;
    req.text = text;
    req.rest = rest;
    return ime_dispatch_request(&req);
}

s32 ime_request_prev_candidate(char *text, char *rest) {
    ImeTextRequest req;
    req.id = 0x14;
    req.text = text;
    req.rest = rest;
    return ime_dispatch_request(&req);
}

s32 ime_request_convert(const u8 *reading, char *text, char *rest) {
    ImeConvertRequest req;
    req.id = 0x13;
    req.reading = reading;
    req.text = text;
    req.rest = rest;
    return ime_dispatch_request(&req);
}
s32 ime_request_romaji_to_hiragana(const char *romaji, char *kana) {
    ImeRomajiRequest req;
    req.id = 0x10;
    req.romaji = romaji;
    req.kana = kana;
    return ime_dispatch_request(&req);
}
s32 ime_request_romaji_to_katakana(const char *romaji, char *kana) {
    ImeRomajiRequest req;
    req.id = 0xf;
    req.romaji = romaji;
    req.kana = kana;
    return ime_dispatch_request(&req);
}
