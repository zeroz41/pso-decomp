#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer_803E5668.h"
#include "pso/quest/TQuestVmDownLoadServer.h"

#pragma readonly_strings on

struct RecoveredGlobal_803E5EFC_lbl_8058DD88 {
    s32 value;
    u8 remaining[0x7C];
};

extern "C" {
extern RecoveredGlobal_803E5EFC_lbl_8058DD88 lbl_8058DD88;
}


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
extern s32 quest_download_initialized;
extern s32 lbl_805D7834;
void TQuestVmDownLoadServer__sub_803E6ACC(s32 arg0);
s32 TQuestVmDownLoadServer__sub_803F08E4(s8 *arg0);
extern RecoveredGlobal_803E5EFC_lbl_8058DD88 lbl_8058DD88;
u8 * TQuestVmDownLoadServer__sub_803EE828(void);
s32 TQuestVmDownLoadServer__sub_803EE2F4(int, void *);
extern s32 lbl_805D78C0;
s32 strcpy(int, int);
s32 TQuestVmDownLoadServer__sub_803EBC88(int);
s32 TQuestVmDownLoadServer__sub_803EC284(int, int);
s32 TQuestVmDownLoadServer__sub_803EE718(void *, void *);
extern Ent_803E5670 quest_download_slot_chain_table[];
extern s32 lbl_805D78EC;
extern s32 lbl_805D78F0;
s32 TQuestVmDownLoadServer__sub_803EB0D8(s32 arg0, s32 arg1);
s32 TQuestVmDownLoadServer__sub_803EB208(int, int);
extern s32 lbl_805D789C;
extern s32 lbl_805D7898;
s32 TQuestVmDownLoadServer__sub_803E9F54(s32 arg0);
s32 TQuestVmDownLoadServer__sub_803EA9E8(int, int, int, int);
s32 TQuestVmDownLoadServer__sub_803EDC20(u32);
s32 TQuestVmDownLoadServer__sub_803EDF64(s16 *, s32, u16 *, s32 *);
extern s16 quest_download_text_buffer[0x200];
s32 TQuestVmDownLoadServer__sub_803EE870(void *, int);
void TQuestVmDownLoadServer__sub_803EAE84(s32 arg0, s32 arg1, void *arg2);
extern char lbl_8047E68C[];
extern u8 lbl_8058DC48[80];
extern u8 lbl_8058DC98[80];
extern u8 lbl_80591AC4[];
extern u8 lbl_80596258[];
extern s32 lbl_805D7820;
extern u8 *lbl_805D7824;
s32 lbl_805D7828;
extern s32 lbl_805D7830;
extern s32 lbl_805D7838;
extern s32 lbl_805D783C;
extern s32 lbl_805D7840;
extern s32 lbl_805D7844;
extern s32 lbl_805D7848;
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
extern s32 lbl_805D7904;
s32 TQuestVmDownLoadServer__sub_803EC69C(s32);
u8 TQuestVmDownLoadServer__sub_803EC8D8();
s32 TQuestVmDownLoadServer__sub_803ECC7C(u32 arg0);
s32 TQuestVmDownLoadServer__sub_803EF208(Req_803E5D20 *);
s32 TQuestVmDownLoadServer__sub_803EF538(Req_803E5D20 *);
extern u8 quest_download_code_remap_table[];
extern u8 lbl_8058DD38[];

s32 TQuestVmDownLoadServer__sub_803E5668(void) {
    return -1;
}

s32 TQuestVmDownLoadServer__sub_803E5670(s32 *arg0) {
    s32 a;
    s32 b;
    s32 k;
    if (lbl_805D7834 != 3) {
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
    if (quest_download_slot_chain_table[lbl_805D78F0].c == 0) {
        return -1;
    }
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy(a, (int)TQuestVmDownLoadServer__sub_803EE718((void *)lbl_805D78F0, (void *)lbl_805D78EC));
    strcpy(b, (int)TQuestVmDownLoadServer__sub_803EE718((void *)(lbl_805D78F0 + lbl_805D78EC), (void *)((lbl_805D78C0 - lbl_805D78F0) - lbl_805D78EC)));
    return 0;
}

s32 TQuestVmDownLoadServer__sub_803E577C(u8 *arg0) {
    s32 temp_r31;
    s32 temp_r30;

    if ((s32) lbl_805D7834 != 3) {
        return -1;
    }
    temp_r31 = *(s32 *)((s8 *)arg0 + 0);
    temp_r30 = *(s32 *)((s8 *)arg0 + 4);
    if ((s32) (lbl_805D78F0 + lbl_805D78EC) >= (s32) lbl_805D78C0) {
        return 0;
    }
    TQuestVmDownLoadServer__sub_803EE870((void *)lbl_805D78F0, 0);
    lbl_805D78F0 += lbl_805D78EC;
    lbl_805D78EC = TQuestVmDownLoadServer__sub_803E9F54(lbl_805D78F0);
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy((int)temp_r31, (int) (TQuestVmDownLoadServer__sub_803EE718((void *)lbl_805D78F0, (void *)lbl_805D78EC)));
    strcpy(temp_r30, (int) (TQuestVmDownLoadServer__sub_803EE718((void *) (lbl_805D78F0 + lbl_805D78EC), (void *) ((lbl_805D78C0 - lbl_805D78F0) - lbl_805D78EC))));
    return ((TQuestVmDownLoadServer *)(quest_download_slot_chain_table[lbl_805D78F0].c))->count_chain_nodes();
}
s32 TQuestVmDownLoadServer__sub_803E5874(s32 *arg0) {
    s32 a;
    s32 b;
    s32 i;
    s32 n;

    if (lbl_805D7834 != 3) {
        return -1;
    }
    a = arg0[0];
    b = arg0[1];
    if (lbl_805D78F0 == 0) {
        return 0;
    }
    TQuestVmDownLoadServer__sub_803EE870((void *)lbl_805D78F0, 0);
    for (i = 0; i < lbl_805D78F0; i += n) {
        n = TQuestVmDownLoadServer__sub_803E9F54(i);
        if (i + n >= lbl_805D78F0) {
            break;
        }
    }
    lbl_805D78F0 = i;
    lbl_805D78EC = n;
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy(a, TQuestVmDownLoadServer__sub_803EE718((void *)lbl_805D78F0, (void *)lbl_805D78EC));
    strcpy(b, TQuestVmDownLoadServer__sub_803EE718((void *)(lbl_805D78F0 + lbl_805D78EC), (void *)((lbl_805D78C0 - lbl_805D78F0) - lbl_805D78EC)));
    return ((TQuestVmDownLoadServer *)(quest_download_slot_chain_table[lbl_805D78F0].c))->count_chain_nodes();
}
s32 TQuestVmDownLoadServer__sub_803E5990(u8 *arg0) {
    s32 temp_r31;
    s32 temp_r30;

    if ((s32) lbl_805D7834 != 3) {
        return -1;
    }
    temp_r31 = *(s32 *)((s8 *)arg0 + 0);
    temp_r30 = *(s32 *)((s8 *)arg0 + 4);
    if ((s32) lbl_805D78EC <= 1) {
        return 0;
    }
    TQuestVmDownLoadServer::latch_slot_value(lbl_805D78F0);
    TQuestVmDownLoadServer__sub_803EAE84(lbl_805D78F0, lbl_805D78C0, (void *)(1));
    lbl_805D78EC -= 1;
    TQuestVmDownLoadServer__sub_803EA9E8(lbl_805D78F0, lbl_805D78C0, 1, lbl_805D78EC);
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy((int)temp_r31, (int) (TQuestVmDownLoadServer__sub_803EE718((void *)lbl_805D78F0, (void *)lbl_805D78EC)));
    strcpy(temp_r30, (int) (TQuestVmDownLoadServer__sub_803EE718((void *) (lbl_805D78F0 + lbl_805D78EC), (void *) ((lbl_805D78C0 - lbl_805D78F0) - lbl_805D78EC))));
    return ((TQuestVmDownLoadServer *)(quest_download_slot_chain_table[lbl_805D78F0].c))->count_chain_nodes();
}
s32 TQuestVmDownLoadServer__sub_803E5A8C(u8 *arg0) {
    s32 temp_r31;
    s32 temp_r30;

    if ((s32) lbl_805D7834 != 3) {
        return -1;
    }
    temp_r31 = *(s32 *)((s8 *)arg0 + 0);
    temp_r30 = *(s32 *)((s8 *)arg0 + 4);
    if ((s32) (lbl_805D78F0 + lbl_805D78EC) >= (s32) lbl_805D78C0) {
        return 0;
    }
    TQuestVmDownLoadServer::latch_slot_value(lbl_805D78F0);
    TQuestVmDownLoadServer__sub_803EAE84(lbl_805D78F0, lbl_805D78C0, (void *)(1));
    lbl_805D78EC += 1;
    TQuestVmDownLoadServer__sub_803EA9E8(lbl_805D78F0, lbl_805D78C0, 1, lbl_805D78EC);
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy((int)temp_r31, (int) (TQuestVmDownLoadServer__sub_803EE718((void *)lbl_805D78F0, (void *)lbl_805D78EC)));
    strcpy(temp_r30, (int) (TQuestVmDownLoadServer__sub_803EE718((void *) (lbl_805D78F0 + lbl_805D78EC), (void *) ((lbl_805D78C0 - lbl_805D78F0) - lbl_805D78EC))));
    return ((TQuestVmDownLoadServer *)(quest_download_slot_chain_table[lbl_805D78F0].c))->count_chain_nodes();
}

s32 TQuestVmDownLoadServer__sub_803E5B94(s32 *arg0) {
    u32 i;
    for (i = 0; i < 80; i++) {
        lbl_8058DC98[i] = 0;
        lbl_8058DC48[i] = 0;
    }
    {
        s32 src = *arg0;
        strcpy((int)&lbl_8058DD88.value, src);
    }
    lbl_805D7834 = 0;
    lbl_805D7830 = 0;
    quest_download_initialized = 1;
    lbl_805D7828 = 0;
    lbl_805D7824 = lbl_80591AC4 + 0x4E;
    lbl_805D7904 = -1;
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
    strcpy((int)lbl_80596258, (int)lbl_8047E68C);
    quest_download_server_state = 0;
    lbl_805D7844 = 0;
    lbl_805D7840 = 0;
    lbl_805D783C = 0;
    lbl_805D7838 = 0;
    quest_download_free_list_ready_flag = 1;
    return 0;
}

typedef struct Req_803E5D20 Req_803E5D20;
s32 TQuestVmDownLoadServer__sub_803E5D20(s32 *arg0) {
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
  if ((lbl_805D7848 >= 2) || (lbl_805D7834 >= 2))
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
  dst = lbl_8058DD38;
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
  req.buf = lbl_8058DD38;
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
    ret = TQuestVmDownLoadServer__sub_803EF208(&req);
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

s32 TQuestVmDownLoadServer::reset_download_buffers() {
    if ((s32) quest_download_initialized == 0) {
        return -1;
    }
    TQuestVmDownLoadServer::init_buffer_pointers();
    TQuestVmDownLoadServer__sub_803F0890();
    lbl_805D7834 = 0;
    return 0;
}
typedef char RecoveredGlobal_803E5EFC_lbl_8058DD88_size[sizeof(RecoveredGlobal_803E5EFC_lbl_8058DD88) == 0x80 ? 1 : -1];
s32 TQuestVmDownLoadServer::poll_download_status() {
    if ((s32) quest_download_initialized == 0) {
        return -1;
    }
    if (TQuestVmDownLoadServer__sub_803F08E4((s8 *)&lbl_8058DD88.value) == -7) {
        return 1;
    }
    TQuestVmDownLoadServer__sub_803E6ACC(0);
    lbl_805D7834 = 1;
    return 0;
}
s32 TQuestVmDownLoadServer__sub_803E5F5C(s32 *arg0) {
    s32 n;
    s32 b;
    s8 *c;
    s16 *d;
    s8 *a;
    s32 ret;

    if (lbl_805D7834 != 3) {
        return -1;
    }
    n = arg0[0];
    if (n <= 0 || n > lbl_805D789C) {
        return 0;
    }
    b = arg0[1];
    a = (s8 *)arg0[2];
    c = (s8 *)arg0[3];
    d = (s16 *)arg0[4];
    lbl_805D7898 = n - 1;
    strcpy(b, TQuestVmDownLoadServer__sub_803EE718((void *)lbl_805D78F0, (void *)lbl_805D78EC));
    TQuestVmDownLoadServer__sub_803EE870((void *)lbl_805D78F0, 1);
    ret = TQuestVmDownLoadServer::sum_entry_sizes((s32)((void *)lbl_805D78F0), (s32)((void *)lbl_805D78EC));
    lbl_805D78F0 += lbl_805D78EC;
    if (lbl_805D78F0 >= lbl_805D78C0) {
        *a = 0;
        *c = 0;
        *d = 0;
        return ret;
    }
    lbl_805D78EC = TQuestVmDownLoadServer__sub_803E9F54(lbl_805D78F0);
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy((int)a, TQuestVmDownLoadServer__sub_803EE718((void *)lbl_805D78F0, (void *)lbl_805D78EC));
    strcpy((int)c, TQuestVmDownLoadServer__sub_803EE718((void *)(lbl_805D78F0 + lbl_805D78EC), (void *)((lbl_805D78C0 - lbl_805D78F0) - lbl_805D78EC)));
    *d = (s16)((TQuestVmDownLoadServer *)(quest_download_slot_chain_table[lbl_805D78F0].c))->count_chain_nodes();
    return ret;
}
s32 TQuestVmDownLoadServer__sub_803E60CC(s32 *arg0) {
    s32 temp_r31;
    if ((s32) lbl_805D7834 != 3) {
        return -1;
    }
    temp_r31 = *(s32 *)((s8 *)arg0 + 0);
    TQuestVmDownLoadServer__sub_803EE2F4(0, (void *)lbl_805D78C0);
    strcpy(temp_r31, (int) (((s32)TQuestVmDownLoadServer__sub_803EE828())));
    TQuestVmDownLoadServer::init_buffer_pointers();
    lbl_805D7834 = 1;
    return 0;
}
s32 TQuestVmDownLoadServer__sub_803E6134(s32 *arg0) {
    s32 err;
    s32 a;
    s32 b;
    err = 0;
    if (lbl_805D7834 != 3) {
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
    strcpy(a, TQuestVmDownLoadServer__sub_803EE718((void *)lbl_805D78F0, (void *)lbl_805D78EC));
    strcpy(b, TQuestVmDownLoadServer__sub_803EE718((void *)(lbl_805D78F0 + lbl_805D78EC), (void *)((lbl_805D78C0 - lbl_805D78F0) - lbl_805D78EC)));
    if (err != 0) {
        return 0;
    }
    return lbl_805D789C;
}
s32 TQuestVmDownLoadServer::handle_list_scroll() {
    s32 *arg0 = (s32 *)this;
    s32 b;
    s32 a;
    s32 n;
    u8 unused[8];
    if (lbl_805D7834 != 3) {
        return 0;
    }
    a = arg0[0];
    b = arg0[1];
    switch (arg0[-1]) {
    case 20:
        if (lbl_805D7898 > 0) {
            lbl_805D7898--;
        } else if (TQuestVmDownLoadServer__sub_803EB0D8(0, 0) == 0) {
            TQuestVmDownLoadServer__sub_803EC284(0, 1);
            n = lbl_805D789C;
            while (TQuestVmDownLoadServer__sub_803EB208(0, 0) != 0) {
                n += lbl_805D789C;
            }
            TQuestVmDownLoadServer__sub_803EC284(n - 1, 1);
        } else {
            lbl_805D7898 = lbl_805D789C - 1;
        }
        break;
    case 21:
        if (lbl_805D7898 < lbl_805D789C - 1) {
            lbl_805D7898++;
        } else if (TQuestVmDownLoadServer__sub_803EB208(0, 0) == 0) {
            TQuestVmDownLoadServer__sub_803EC284(0, 1);
        }
        break;
    }
    strcpy(a, TQuestVmDownLoadServer__sub_803EE718((void *)lbl_805D78F0, (void *)lbl_805D78EC));
    strcpy(b, TQuestVmDownLoadServer__sub_803EE718((void *)(lbl_805D78F0 + lbl_805D78EC), (void *)((lbl_805D78C0 - lbl_805D78F0) - lbl_805D78EC)));
    return lbl_805D7898 + 1;
}
s32 OSFillFPUContext(s32 *arg0) {
    u32 id;
    s8 *a;
    s8 *b;
    if (lbl_805D7834 == 0) {
        return -1;
    }
    id = arg0[0];
    a = (s8 *)arg0[1];
    b = (s8 *)arg0[2];
    if (id != 0) {
        if (lbl_805D7834 >= 2) {
            TQuestVmDownLoadServer::init_buffer_pointers();
        }
        if (TQuestVmDownLoadServer__sub_803EDC20(id) < 0) {
            return -1;
        }
    }
    if (lbl_805D78C0 <= 0) {
        *a = 0;
        *b = 0;
        return 0;
    }
    TQuestVmDownLoadServer__sub_803EA9E8(0, lbl_805D78C0, 0, -1);
    lbl_805D78F0 = 0;
    lbl_805D78EC = TQuestVmDownLoadServer__sub_803E9F54(0);
    TQuestVmDownLoadServer__sub_803EC284(0, 1);
    strcpy((int)a, TQuestVmDownLoadServer__sub_803EE718((void *)lbl_805D78F0, (void *)lbl_805D78EC));
    strcpy((int)b, TQuestVmDownLoadServer__sub_803EE718((void *)(lbl_805D78F0 + lbl_805D78EC), (void *)((lbl_805D78C0 - lbl_805D78F0) - lbl_805D78EC)));
    lbl_805D7834 = 3;
    return ((TQuestVmDownLoadServer *)(((Ent_803E639C *)&quest_download_slot_chain_table)[0].c))->count_chain_nodes();
}
s32 TQuestVmDownLoadServer::convert_jis_to_sjis_string() {
    s32 *arg0 = (s32 *)this;
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
    src = (u8 *)arg0[0];
    dst = (u8 *)arg0[1];
    if (arg0[-1] == 0xF) {
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
        r = TQuestVmDownLoadServer__sub_803EDF64(p, n, buf, &cnt);
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

}

extern "C" {
u8 lbl_8058DC48[80];
u8 lbl_8058DC98[80];
u8 lbl_8058DCE8[80];
u8 lbl_8058DD38[80];
RecoveredGlobal_803E5EFC_lbl_8058DD88 lbl_8058DD88;
}
