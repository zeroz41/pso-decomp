#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer_803E5668.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include <stddef.h>

#pragma readonly_strings on

struct Ent_803E5670 {
    u8 pad[0xC];
    u32 c;
    u8 pad2[0x1C - 0x10];
};

struct Ent_803E639C { u8 pad[0xC]; s32 c; u8 pad2[0x1C - 0x10]; };

struct Req_803E5D20
{
  u8 *buf;
  s16 len;
  u8 a;
  u8 code;
  u8 b;
  s32 x;
};

extern "C" {
s32 TQuestVmDownLoadServer__sub_803F0890(void);
void TQuestVmDownLoadServer__sub_803E6ACC(s32 arg0);
s32 TQuestVmDownLoadServer__sub_803F08E4(s8 *arg0);
u8 * convert_all_entry_text(void);
void process_entry_text_range(s32 pos, s32 end);
extern s32 quest_text_end;
s32 strcpy(int, int);
void TQuestVmDownLoadServer__sub_803EBC88(s32 mode);
void TQuestVmDownLoadServer__sub_803EC284(s32 pos, s32 mode);
s32 get_entry_text(void *, void *);
extern Ent_803E5670 quest_download_slot_chain_table[];
extern s32 quest_text_entry_len;
extern s32 quest_text_cursor_pos;
s32 TQuestVmDownLoadServer__sub_803EB0D8(s32 arg0, s32 arg1);
s32 TQuestVmDownLoadServer__sub_803EB208(s32 mode, s32 force);
extern s32 quest_page_node_count;
extern s32 quest_page_node_index;
s32 TQuestVmDownLoadServer__sub_803E9F54(s32 arg0);
void TQuestVmDownLoadServer__sub_803EA9E8(s32 start, s32 inputEnd, s32 mode, s32 selectedLength);
s32 TQuestVmDownLoadServer__sub_803EDC20(u32);
s32 convert_romaji_to_kana(u16 *src, s32 n, u16 *out, s32 *count);
extern s16 quest_download_text_buffer[0x200];
void free_slot_node_chain(s32 slot, s32 mode);
void TQuestVmDownLoadServer__sub_803EAE84(s32 arg0, s32 arg1, void *arg2);
extern u8 lbl_8058DC48[80];
extern u8 lbl_8058DC98[80];
extern u8 lbl_80591AC4[];
extern u8 lbl_80596258[];
s32 lbl_805D7820;
u8 *lbl_805D7824;
s32 lbl_805D7828;
s32 quest_download_initialized;
s32 lbl_805D7830;
s32 quest_download_state;
s32 lbl_805D7838;
s32 lbl_805D783C;
s32 lbl_805D7840;
s32 lbl_805D7844;
s32 lbl_805D7848;
extern s32 lbl_805D7880;
extern s32 lbl_805D7884;
extern s32 lbl_805D7888;
extern u8 lbl_805D7894[];
extern s32 quest_download_free_list_ready_flag;
extern s32 quest_download_match_length_limit;
extern s16 lbl_805D78E0;
extern s32 lbl_805D78E4;
extern s32 quest_download_server_state;
extern s32 lbl_805D78F8;
extern s32 lbl_805D78FC;
extern s32 lbl_805D7900;
extern s32 quest_download_file_handle;
s32 TQuestVmDownLoadServer__sub_803EC69C(u32 arg0);
u8 TQuestVmDownLoadServer__sub_803EC8D8();
s32 TQuestVmDownLoadServer__sub_803ECC7C(u32 arg0);
s32 TQuestVmDownLoadServer__sub_803EF208(Req_803EEF2C *msg);
s32 TQuestVmDownLoadServer__sub_803EF538(Req_803E5D20 *);
extern u8 quest_request_text_buffer[];

// Handlers by request id (1..63); unassigned ids return -1.
typedef s32 (*KeyBoardSoftHandler)(s32 *args);
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
    TQuestVmDownLoadServer::convert_jis_to_sjis_string, // 0x0F
    TQuestVmDownLoadServer::convert_jis_to_sjis_string, // 0x10
    quest_download_request_unassigned, // 0x11
    quest_download_request_unassigned, // 0x12
    OSFillFPUContext, // 0x13
    TQuestVmDownLoadServer::handle_list_scroll, // 0x14
    TQuestVmDownLoadServer::handle_list_scroll, // 0x15
    quest_download_request_0x16, // 0x16
    quest_download_request_0x16, // 0x17
    quest_download_request_0x18, // 0x18
    quest_download_request_0x19, // 0x19
    quest_download_request_unassigned, // 0x1A
    quest_download_request_unassigned, // 0x1B
    TQuestVmDownLoadServer::poll_download_status, // 0x1C
    TQuestVmDownLoadServer::reset_download_buffers, // 0x1D
    quest_download_request_0x1E, // 0x1E
    quest_download_request_0x1E, // 0x1F
    quest_download_request_0x20, // 0x20
    quest_download_request_0x21, // 0x21
    quest_download_request_0x22, // 0x22
    quest_download_request_0x23, // 0x23
    quest_download_request_0x24, // 0x24
    quest_download_request_0x25, // 0x25
    quest_download_request_0x25, // 0x26
    quest_download_request_0x25, // 0x27
    quest_download_request_0x25, // 0x28
    quest_download_request_0x25, // 0x29
    quest_download_request_0x25, // 0x2A
    quest_download_request_0x25, // 0x2B
    quest_download_request_0x25, // 0x2C
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

s32 quest_download_request_unassigned(s32 *) {
    return -1;
}

s32 quest_download_request_0x25(s32 *arg0) {
    s32 a;
    s32 b;
    s32 k;
    if (quest_download_state != 3) {
        return -1;
    }
    a = arg0[0];
    b = arg0[1];
    switch (arg0[-1]) {
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
    TQuestVmDownLoadServer__sub_803EBC88(k);
    if (quest_download_slot_chain_table[quest_text_cursor_pos].c == 0) {
        return -1;
    }
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy(a, (int)get_entry_text((void *)quest_text_cursor_pos, (void *)quest_text_entry_len));
    strcpy(b, (int)get_entry_text((void *)(quest_text_cursor_pos + quest_text_entry_len), (void *)((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len)));
    return 0;
}

s32 quest_download_request_0x24(s32 *arg0) {
    s32 temp_r31;
    s32 temp_r30;

    if ((s32) quest_download_state != 3) {
        return -1;
    }
    temp_r31 = arg0[0];
    temp_r30 = arg0[1];
    if ((s32) (quest_text_cursor_pos + quest_text_entry_len) >= (s32) quest_text_end) {
        return 0;
    }
    free_slot_node_chain(quest_text_cursor_pos, 0);
    quest_text_cursor_pos += quest_text_entry_len;
    quest_text_entry_len = TQuestVmDownLoadServer__sub_803E9F54(quest_text_cursor_pos);
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy((int)temp_r31, (int) (get_entry_text((void *)quest_text_cursor_pos, (void *)quest_text_entry_len)));
    strcpy(temp_r30, (int) (get_entry_text((void *) (quest_text_cursor_pos + quest_text_entry_len), (void *) ((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len))));
    return ((TQuestVmDownLoadServer *)(quest_download_slot_chain_table[quest_text_cursor_pos].c))->count_chain_nodes();
}
s32 quest_download_request_0x23(s32 *arg0) {
    s32 a;
    s32 b;
    s32 i;
    s32 n;

    if (quest_download_state != 3) {
        return -1;
    }
    a = arg0[0];
    b = arg0[1];
    if (quest_text_cursor_pos == 0) {
        return 0;
    }
    free_slot_node_chain(quest_text_cursor_pos, 0);
    for (i = 0; i < quest_text_cursor_pos; i += n) {
        n = TQuestVmDownLoadServer__sub_803E9F54(i);
        if (i + n >= quest_text_cursor_pos) {
            break;
        }
    }
    quest_text_cursor_pos = i;
    quest_text_entry_len = n;
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy(a, get_entry_text((void *)quest_text_cursor_pos, (void *)quest_text_entry_len));
    strcpy(b, get_entry_text((void *)(quest_text_cursor_pos + quest_text_entry_len), (void *)((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len)));
    return ((TQuestVmDownLoadServer *)(quest_download_slot_chain_table[quest_text_cursor_pos].c))->count_chain_nodes();
}
s32 quest_download_request_0x22(s32 *arg0) {
    s32 temp_r31;
    s32 temp_r30;

    if ((s32) quest_download_state != 3) {
        return -1;
    }
    temp_r31 = arg0[0];
    temp_r30 = arg0[1];
    if ((s32) quest_text_entry_len <= 1) {
        return 0;
    }
    TQuestVmDownLoadServer::latch_slot_value(quest_text_cursor_pos);
    TQuestVmDownLoadServer__sub_803EAE84(quest_text_cursor_pos, quest_text_end, (void *)(1));
    quest_text_entry_len -= 1;
    TQuestVmDownLoadServer__sub_803EA9E8(quest_text_cursor_pos, quest_text_end, 1, quest_text_entry_len);
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy((int)temp_r31, (int) (get_entry_text((void *)quest_text_cursor_pos, (void *)quest_text_entry_len)));
    strcpy(temp_r30, (int) (get_entry_text((void *) (quest_text_cursor_pos + quest_text_entry_len), (void *) ((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len))));
    return ((TQuestVmDownLoadServer *)(quest_download_slot_chain_table[quest_text_cursor_pos].c))->count_chain_nodes();
}
s32 quest_download_request_0x21(s32 *arg0) {
    s32 temp_r31;
    s32 temp_r30;

    if ((s32) quest_download_state != 3) {
        return -1;
    }
    temp_r31 = arg0[0];
    temp_r30 = arg0[1];
    if ((s32) (quest_text_cursor_pos + quest_text_entry_len) >= (s32) quest_text_end) {
        return 0;
    }
    TQuestVmDownLoadServer::latch_slot_value(quest_text_cursor_pos);
    TQuestVmDownLoadServer__sub_803EAE84(quest_text_cursor_pos, quest_text_end, (void *)(1));
    quest_text_entry_len += 1;
    TQuestVmDownLoadServer__sub_803EA9E8(quest_text_cursor_pos, quest_text_end, 1, quest_text_entry_len);
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy((int)temp_r31, (int) (get_entry_text((void *)quest_text_cursor_pos, (void *)quest_text_entry_len)));
    strcpy(temp_r30, (int) (get_entry_text((void *) (quest_text_cursor_pos + quest_text_entry_len), (void *) ((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len))));
    return ((TQuestVmDownLoadServer *)(quest_download_slot_chain_table[quest_text_cursor_pos].c))->count_chain_nodes();
}

s32 quest_download_request_0x20(s32 *arg0) {
    u32 i;
    for (i = 0; i < 80; i++) {
        lbl_8058DC98[i] = 0;
        lbl_8058DC48[i] = 0;
    }
    {
        s32 src = *arg0;
        strcpy((int)&quest_convert_string.value, src);
    }
    quest_download_state = 0;
    lbl_805D7830 = 0;
    quest_download_initialized = 1;
    lbl_805D7828 = 0;
    lbl_805D7824 = lbl_80591AC4 + 0x4E;
    quest_download_file_handle = -1;
    lbl_805D7820 = 0;
    lbl_805D7900 = 0;
    lbl_805D78FC = 0;
    lbl_805D78F8 = 0x8002;
    lbl_805D7888 = 0;
    lbl_805D7884 = 1;
    lbl_805D7880 = 0;
    lbl_805D78E4 = 1;
    lbl_805D78E0 = 0x4000;
    lbl_805D7848 = 0;
    quest_download_match_length_limit = 0x24;
    strcpy((int)lbl_805D7894, (int)(s32 *)"  1.");
    strcpy((int)lbl_80596258, (int)"  \x8E\x63      "); // "  残      " (remaining)
    quest_download_server_state = 0;
    lbl_805D7844 = 0;
    lbl_805D7840 = 0;
    lbl_805D783C = 0;
    lbl_805D7838 = 0;
    quest_download_free_list_ready_flag = 1;
    return 0;
}

typedef struct Req_803E5D20 Req_803E5D20;
s32 quest_download_request_0x1E(s32 *arg0) {
  s32 kind;
  s32 x;
  s32 code;
  u8 *src;
  int new_var;
  s32 ch;
  u8 *dst;
  s32 n;
  s32 idx;
  s32 mode;
  u8 r;
  s32 ret;
  Req_803E5D20 req;
  if ((lbl_805D7848 >= 2) || (quest_download_state >= 2))
  {
    return 4;
  }
  mode = arg0[0];
  kind = arg0[-1];
  if ((mode != 1) && (mode != 0))
  {
    return 1;
  }
  new_var = 1;
  idx = arg0[3];
  src = (u8 *) arg0[1];
  x = arg0[2];
  if (((idx - 1) < 0) || ((idx - 1) >= 30))
  {
    code = -1;
  }
  else
  {
    code = (idx - new_var)[quest_download_code_remap_table];
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
    if (TQuestVmDownLoadServer__sub_803ECC7C(ch) == 0)
    {
      return 3;
    }
    TQuestVmDownLoadServer__sub_803EC69C(ch);
    r = TQuestVmDownLoadServer__sub_803EC8D8();
    if (r == 0)
    {
      return 3;
    }
    *(dst++) = r;
    n++;
    src += 2;
  }
  *dst = 0;
  req.buf = quest_request_text_buffer;
  req.len = (s16) n;
  req.a = 0;
  req.code = code;
  req.b = 0;
  req.x = x;
  if (kind == 30)
  {
    if (TQuestVmDownLoadServer__sub_803EF538(&req) == 3)
    {
      return 0;
    }
  }
  else
    if (kind == 31)
  {
    ret = TQuestVmDownLoadServer__sub_803EF208((Req_803EEF2C *)&req);
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

s32 TQuestVmDownLoadServer::reset_download_buffers(s32 *) {
    if ((s32) quest_download_initialized == 0) {
        return -1;
    }
    TQuestVmDownLoadServer::init_buffer_pointers();
    TQuestVmDownLoadServer__sub_803F0890();
    quest_download_state = 0;
    return 0;
}
s32 TQuestVmDownLoadServer::poll_download_status(s32 *) {
    if ((s32) quest_download_initialized == 0) {
        return -1;
    }
    if (TQuestVmDownLoadServer__sub_803F08E4((s8 *)&quest_convert_string.value) == -7) {
        return 1;
    }
    TQuestVmDownLoadServer__sub_803E6ACC(0);
    quest_download_state = 1;
    return 0;
}
s32 quest_download_request_0x19(s32 *arg0) {
    s32 n;
    s32 b;
    s8 *c;
    s16 *d;
    s8 *a;
    s32 ret;

    if (quest_download_state != 3) {
        return -1;
    }
    n = arg0[0];
    if (n <= 0 || n > quest_page_node_count) {
        return 0;
    }
    b = arg0[1];
    a = (s8 *)arg0[2];
    c = (s8 *)arg0[3];
    d = (s16 *)arg0[4];
    quest_page_node_index = n - 1;
    strcpy(b, get_entry_text((void *)quest_text_cursor_pos, (void *)quest_text_entry_len));
    free_slot_node_chain(quest_text_cursor_pos, 1);
    ret = TQuestVmDownLoadServer::sum_entry_sizes((s32)((void *)quest_text_cursor_pos), (s32)((void *)quest_text_entry_len));
    quest_text_cursor_pos += quest_text_entry_len;
    if (quest_text_cursor_pos >= quest_text_end) {
        *a = 0;
        *c = 0;
        *d = 0;
        return ret;
    }
    quest_text_entry_len = TQuestVmDownLoadServer__sub_803E9F54(quest_text_cursor_pos);
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy((int)a, get_entry_text((void *)quest_text_cursor_pos, (void *)quest_text_entry_len));
    strcpy((int)c, get_entry_text((void *)(quest_text_cursor_pos + quest_text_entry_len), (void *)((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len)));
    *d = (s16)((TQuestVmDownLoadServer *)(quest_download_slot_chain_table[quest_text_cursor_pos].c))->count_chain_nodes();
    return ret;
}
s32 quest_download_request_0x18(s32 *arg0) {
    s32 temp_r31;
    if ((s32) quest_download_state != 3) {
        return -1;
    }
    temp_r31 = *(s32 *)((s8 *)arg0 + 0);
    process_entry_text_range(0, quest_text_end);
    strcpy(temp_r31, (int) (((s32)convert_all_entry_text())));
    TQuestVmDownLoadServer::init_buffer_pointers();
    quest_download_state = 1;
    return 0;
}
s32 quest_download_request_0x16(s32 *arg0) {
    s32 err;
    s32 a;
    s32 b;
    err = 0;
    if (quest_download_state != 3) {
        return 0;
    }
    a = arg0[0];
    b = arg0[1];
    switch (arg0[-1]) {
    case 22:
        if (TQuestVmDownLoadServer__sub_803EB0D8(0, 0) == 0) {
            err = 1;
        }
        break;
    case 23:
        if (TQuestVmDownLoadServer__sub_803EB208(0, 0) == 0) {
            err = 1;
        }
        break;
    }
    strcpy(a, get_entry_text((void *)quest_text_cursor_pos, (void *)quest_text_entry_len));
    strcpy(b, get_entry_text((void *)(quest_text_cursor_pos + quest_text_entry_len), (void *)((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len)));
    if (err != 0) {
        return 0;
    }
    return quest_page_node_count;
}
s32 TQuestVmDownLoadServer::handle_list_scroll(s32 *args) {
    s32 b;
    s32 a;
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
        } else if (TQuestVmDownLoadServer__sub_803EB0D8(0, 0) == 0) {
            TQuestVmDownLoadServer__sub_803EC284(0, 1);
            n = quest_page_node_count;
            while (TQuestVmDownLoadServer__sub_803EB208(0, 0) != 0) {
                n += quest_page_node_count;
            }
            TQuestVmDownLoadServer__sub_803EC284(n - 1, 1);
        } else {
            quest_page_node_index = quest_page_node_count - 1;
        }
        break;
    case 21:
        if (quest_page_node_index < quest_page_node_count - 1) {
            quest_page_node_index++;
        } else if (TQuestVmDownLoadServer__sub_803EB208(0, 0) == 0) {
            TQuestVmDownLoadServer__sub_803EC284(0, 1);
        }
        break;
    }
    strcpy(a, get_entry_text((void *)quest_text_cursor_pos, (void *)quest_text_entry_len));
    strcpy(b, get_entry_text((void *)(quest_text_cursor_pos + quest_text_entry_len), (void *)((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len)));
    return quest_page_node_index + 1;
}
s32 OSFillFPUContext(s32 *arg0) {
    u32 id;
    s8 *a;
    s8 *b;
    if (quest_download_state == 0) {
        return -1;
    }
    id = arg0[0];
    a = (s8 *)arg0[1];
    b = (s8 *)arg0[2];
    if (id != 0) {
        if (quest_download_state >= 2) {
            TQuestVmDownLoadServer::init_buffer_pointers();
        }
        if (TQuestVmDownLoadServer__sub_803EDC20(id) < 0) {
            return -1;
        }
    }
    if (quest_text_end <= 0) {
        *a = 0;
        *b = 0;
        return 0;
    }
    TQuestVmDownLoadServer__sub_803EA9E8(0, quest_text_end, 0, -1);
    quest_text_cursor_pos = 0;
    quest_text_entry_len = TQuestVmDownLoadServer__sub_803E9F54(0);
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy((int)a, get_entry_text((void *)quest_text_cursor_pos, (void *)quest_text_entry_len));
    strcpy((int)b, get_entry_text((void *)(quest_text_cursor_pos + quest_text_entry_len), (void *)((quest_text_end - quest_text_cursor_pos) - quest_text_entry_len)));
    quest_download_state = 3;
    return ((TQuestVmDownLoadServer *)(((Ent_803E639C *)&quest_download_slot_chain_table)[0].c))->count_chain_nodes();
}
s32 TQuestVmDownLoadServer::convert_jis_to_sjis_string(s32 *args) {
    u16 buf[4];
    s32 cnt;
    u8 *src;
    u8 *dst;
    u16 flag;
    s16 *p;
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
    p = quest_download_text_buffer;
    n = 0;
    while (*src != 0 && p < quest_download_text_buffer + 0x200) {
        *p++ = *src++ | flag;
        n++;
    }
    p = quest_download_text_buffer;
    while (n > 0) {
        r = convert_romaji_to_kana((u16 *)p, (s32)n, (u16 *)buf, (s32 *)&cnt);
        if (r <= 0) {
            if (r != -1) {
                return (p - quest_download_text_buffer) + 1;
            }
            r = 1;
        }
        p += r;
        n -= r;
        q = buf;
        while (cnt-- != 0) {
            c = TQuestVmDownLoadServer::jis_to_sjis(*q++);
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

u8 lbl_8058DC48[80];
u8 lbl_8058DC98[80];
u8 lbl_8058DCE8[80];
u8 quest_request_text_buffer[80];
QuestConvertString quest_convert_string;
}

struct Stack_803E68D0 {
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
};

struct Req_803E669C { s32 id; s32 a; s32 b; };

struct Req_803E6704 { s32 id; s32 a; s32 b; };

struct Req_803E6738 { s32 id; s32 a; s32 b; };

struct Req_803E676C { s32 id; s32 a; s32 b; };

struct Req_803E6668 { s32 id; s32 a; s32 b; };

struct Req_803E66D0 { s32 id; s32 a; s32 b; };

struct Req_803E67D4 { s32 id; s32 a; s32 b; };

struct Req_803E67A0 { s32 id; s32 a; s32 b; };

struct Req_803E6808 { s32 id; s32 a; s32 b; };

struct Req_803E6908 { s32 id; s32 a; s32 b; };

struct Req_803E693C { s32 id; s32 a; s32 b; };

struct Req_803E689C { s32 id; s32 a; s32 b; };

struct Req_803E6868 { s32 id; s32 a; s32 b; };
struct S_803E6610 { s32 idx; s32 rest; };

s32 TWindowKeyBoardSoft::dispatch_by_index() {
    S_803E6610 *arg0 = (S_803E6610 *)this;
    s32 i = arg0->idx;
    s32 *rest = &arg0->rest;
    if (i <= 0 || (u32)i > 0x3F) {
        return -1;
    }
    return keyboard_soft_dispatch_fn_table[i - 1](rest);
}

void TWindowKeyBoardSoft::dispatch_request_0x28(s32 a, s32 b) {
    Req_803E6668 req;
    req.id = 0x28;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x27(s32 a, s32 b) {
    Req_803E669C req;
    req.id = 0x27;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x26(s32 a, s32 b) {
    Req_803E66D0 req;
    req.id = 0x26;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x25(s32 a, s32 b) {
    Req_803E6704 req;
    req.id = 0x25;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x24(s32 a, s32 b) {
    Req_803E6738 req;
    req.id = 0x24;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x23(s32 a, s32 b) {
    Req_803E676C req;
    req.id = 0x23;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x22(s32 a, s32 b) {
    Req_803E67A0 req;
    req.id = 0x22;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft__sub_803E67D4(s32 a, s32 b) {
    Req_803E67D4 req;
    req.id = 0x21;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x20(s32 a, s32 b) {
    Req_803E6808 req;
    req.id = 0x20;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x1c() {
    s32 sp8;
    sp8 = 0x1C;
    ((TWindowKeyBoardSoft *)(&sp8))->dispatch_by_index();
}

void TWindowKeyBoardSoft__sub_803E6868(s32 a, s32 b) {
    Req_803E6868 req;
    req.id = 0x15;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x14(s32 a, s32 b) {
    Req_803E689C req;
    req.id = 0x14;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}

void TWindowKeyBoardSoft::dispatch_request_0x13(s32 arg0, s32 arg1, s32 arg2) {
    typedef char sp14_offset[(offsetof(Stack_803E68D0, sp14) == 0x0) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_803E68D0, sp18) == 0x4) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_803E68D0, sp1C) == 0x8) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_803E68D0, sp20) == 0xC) ? 1 : -1];
    Stack_803E68D0 stack;
    stack.sp14 = 0x13;
    stack.sp18 = arg0;
    stack.sp1C = arg1;
    stack.sp20 = arg2;
    ((TWindowKeyBoardSoft *)(&stack.sp14))->dispatch_by_index();
}
void TWindowKeyBoardSoft::dispatch_request_0x10(s32 a, s32 b) {
    Req_803E6908 req;
    req.id = 0x10;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}
void TWindowKeyBoardSoft::dispatch_request_0f(s32 a, s32 b) {
    Req_803E693C req;
    req.id = 0xf;
    req.a = a;
    req.b = b;
    ((TWindowKeyBoardSoft *)(&req))->dispatch_by_index();
}
