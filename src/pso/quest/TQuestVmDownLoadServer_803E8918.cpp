#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer_803E6970.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/QuestDownloadServer.h"

extern "C" {
NameCache_80591EC8 lbl_80591EC8;
NameHash_80593EC8 lbl_80593EC8;
void TQuestVmDownLoadServer__sub_803E8918(void) {
    lbl_805D7868 = 1;
}

extern u8 *lbl_805D786C;
extern u8 *lbl_805D7870;
extern Node_803E8B1C *lbl_805D7878;
void TQuestVmDownLoadServer__sub_803E95BC(void);

inline int Hash_80591EC8(char *s) {
    int h;
    u8 c = s[0];
    if (c >= 0xA0 && c < 0xF0) {
        h = c - 0xA0;
    } else {
        h = 0;
    }
    return h;
}
inline Node_803E8B1C *FindName_80591EC8(char *buf, s16 len, Node_803E8B1C ***plink) {
    Node_803E8B1C *n;
    Node_803E8B1C *prev = NULL;
    s32 h;
    h = Hash_80591EC8(buf);
    for (n = lbl_80593EC8.hash[h]; n != NULL; n = n->next) {
        s32 r;
        u8 elen = n->ent->len;
        r = strncmp(n->ent->name, buf, (s16)elen);
        if (r == 0) {
            if (len == (s16)elen) {
                break;
            }
        } else if (r > 0) {
            break;
        }
        prev = n;
    }
    *plink = prev == NULL ? &lbl_80593EC8.hash[h] : &prev->next;
    return n;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
extern "C" void TQuestVmDownLoadServer__sub_803E8924(s32 arg0) {
  char buf[0x50];
  s32 pad[3];
  s16 key;
  int new_var2;
  u8 *p;
  s16 len;
  u8 *dst;
  s16 new_var;
  Node_803E8B1C *n;
  s32 cost;
  s32 i;
  s32 r;
  u8 c;
  key = (s16) (new_var2 = arg0 >> 12);
  if (lbl_805D7874 == key)
  {
    return;
  }
  p = (((u8 *) (&lbl_80591EC8)) + (key << 10)) + ((s16) (arg0 & 0xFFF));
  u8 *h = &p[(lbl_805D7874 == key) * 0];
  cost = (*h) + (p[1] << 8);
  cost &= 0xFFFF;
  u8 *q = p;
  if (((u32) lbl_805D7870) > ((u32) ((lbl_805D786C - cost) - 2)))
  {
    TQuestVmDownLoadServer__sub_803E95BC();
  }
  dst = lbl_805D7870;
  lbl_805D7870 += cost;
  lbl_805D7870[0] = 0;
  lbl_805D7870[1] = 0;
  if (key == lbl_805D7874)
  {
    return;
  }
  len = p[2];
  strncpy(buf, ((const char *) p) + 3, len);
  buf[len] = 0;
  c = buf[0];
  if ((c >= 0xA0) && (c < 0xF0))
  {
    i = c - 0xA0;
  }
  else
  {
    i = 0;
  }
  n = lbl_80593EC8.hash[i];
  while (n != 0)
  {
    s16 l = n->ent->len;
    new_var = l;
    r = strncmp(n->ent->name, buf, new_var);
    if (r == 0)
    {
      if (len == new_var)
      {
        break;
      }
    }
    else
      if (r > 0)
    {
      break;
    }
    n = n->next;
  }

  if (n->ent != ((Ent_803E8B1C *) p))
  {
    return;
  }
  n->ent = (Ent_803E8B1C *) dst;
  while (cost != 0)
  {
    *(dst++) = *(p++);
    cost--;
  }

  q[2] = 0;
  TQuestVmDownLoadServer::invalidate_entries_by_id(arg0);
}
#pragma pop

typedef char RecoveredGlobal_803E9764_lbl_80591EC8_size[sizeof(RecoveredGlobal_803E9764_lbl_80591EC8) == 0x2000 ? 1 : -1];

typedef char RecoveredGlobal_803E9594_lbl_80591EC8_size[sizeof(RecoveredGlobal_803E9594_lbl_80591EC8) == 0x2000 ? 1 : -1];

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 IsSjisLead_803E92C0(u8 c) {
    if ((c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 IsSjisLead_803E90A8(u8 c) {
    if ((c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Hash_803E8C2C(char *s) {
    s32 h;
    u8 c = s[0];
    if (c >= 0xA0 && c < 0xF0) {
        h = c - 0xA0;
    } else {
        h = 0;
    }
    return h;
}

// Id of a name-cache record: its 0x400-byte page in bits 12 and up, its offset in the page below
// (name inferred).
inline s32 NameRecordId_80591EC8(NameCache_80591EC8 *cache, void *rec) {
    s32 off = (u8 *)rec - (u8 *)cache;
    return ((off / 1024) << 12) | (off % 1024);
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Hash_803E8B1C(char *s) {
    s32 h;
    u8 c = s[0];
    if (c >= 0xA0 && c < 0xF0) {
        h = c - 0xA0;
    } else {
        h = 0;
    }
    return h;
}
s32 lookup_name_entry__22TQuestVmDownLoadServerFPvsPv(char *arg0, s16 arg1, Out_803E8B1C *arg2) {
    Node_803E8B1C *n;
    s32 r;
    u8 len;
    Ent_803E8B1C *e;
    for (n = lbl_80593EC8.hash[Hash_803E8B1C(arg0)]; n != NULL; n = n->next) {
        e = n->ent;
        len = e->len;
        r = strncmp(e->name, arg0, (s16)len);
        if (r == 0) {
            if ((s16)len == arg1) {
                break;
            }
        } else if (r > 0) {
            arg2->id = -1;
            return 0;
        }
    }
    if (n == NULL) {
        arg2->id = -1;
        return 0;
    }
    arg2->a = 0;
    arg2->id = NameRecordId_80591EC8(&lbl_80591EC8, e);
    arg2->ent = e;
    return 1;
}
#pragma pop

s32 TQuestVmDownLoadServer__sub_803E8C2C(char *arg0, s16 arg1, Out_803E8C2C *arg2) {
    Node_803E8B1C *n;
    Ent_803E8B1C *e;
    s16 len;
    Ent_803E8B1C *found;
    s16 pre;
    s16 blen;
    s32 r;
    s16 m;
    blen = 0;
    pre = 0;
    arg2->pre = 0;
    arg2->len = 0;
    for (n = lbl_80593EC8.hash[Hash_803E8C2C(arg0)]; n != NULL; n = n->next) {
        e = n->ent;
        len = e->len;
        m = TQuestVmDownLoadServer::match_prefix_length((u8 *)e->name, (u8 *)arg0, (s16)len);
        if (m >= pre) {
            pre = m + 1;
        }
        r = strncmp(e->name, arg0, (s16)len);
        if (r == 0) {
            if ((s16)len == arg1) {
                return 2;
            }
            blen = len;
            found = e;
        } else if (r > 0) {
            if (strncmp(e->name, arg0, arg1) == 0) {
                return 2;
            }
            break;
        }
    }
    if (blen == 0) {
        arg2->id = -1;
        return 0;
    }
    arg2->a = 0;
    arg2->id = NameRecordId_80591EC8(&lbl_80591EC8, found);
    arg2->len = blen;
    arg2->pre = pre;
    arg2->ent = found;
    return 1;
}
#pragma pop


#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline s32 RecordSize_803E8DA0(Req_803EEF2C *req) {
    s32 extra;
    if (req->x8 != 0 || req->x7 >= 0x2D) {
        extra = 3;
    } else {
        extra = 2;
    }
    return 3 + req->len + extra + TQuestVmDownLoadServer::calc_sjis_string_width(req->text);
}
inline void WriteRecord_803E8DA0(u8 *p, s32 size, Req_803EEF2C *req, u8 attr) {
    *p++ = size % 256;
    *p++ = size / 256;
    *p++ = req->len;
    strncpy((char *)p, req->name, req->len);
    p += req->len;
    *p++ = req->x7;
    *p++ = attr;
    if (req->x8 != 0 || req->x7 >= 0x2D) {
        *p++ = req->x8;
    }
    TQuestVmDownLoadServer::copy_sjis_string(req->text, p);
}
inline u8 *AllocRecord_80591EC8(s32 size) {
    u8 *p;
    if (lbl_805D7870 > lbl_805D786C - size - 2) {
        TQuestVmDownLoadServer__sub_803E95BC();
    }
    p = lbl_805D7870;
    lbl_805D7870 += size;
    lbl_805D7870[0] = 0;
    lbl_805D7870[1] = 0;
    return p;
}
s32 TQuestVmDownLoadServer__sub_803E8DA0(char *name, Req_803EEF2C *req, s32 attr) {
    NameCache_80591EC8 *cache;
    Node_803E8B1C *n;
    Node_803E8B1C *node;
    Node_803E8B1C **link;
    Ent_803E8B1C *e;
    s32 size;
    u8 *rec;
    lbl_805D7868 = 1;
    cache = &lbl_80591EC8;
    n = FindName_80591EC8(name, req->len, &link);
    e = n->ent;
    if (e->len == req->len && strncmp(name, e->name, req->len) == 0) {
        e->len = 0;
        *link = n->next;
        TQuestVmDownLoadServer::invalidate_entries_by_id(NameRecordId_80591EC8(cache, n->ent));
        n->next = lbl_805D7878;
        lbl_805D7878 = n;
    }
    if (lbl_805D7878 == NULL) {
        TQuestVmDownLoadServer__sub_803E95BC();
    }
    node = lbl_805D7878;
    lbl_805D7878 = node->next;
    size = RecordSize_803E8DA0(req);
    rec = AllocRecord_80591EC8(size);
    WriteRecord_803E8DA0(rec, size, req, attr);
    n = FindName_80591EC8(name, req->len, &link);
    node->ent = (Ent_803E8B1C *)rec;
    node->next = n;
    *link = node;
    return 0;
}
#pragma pop

void append_message_text__22TQuestVmDownLoadServerFPviPvUc(u8 *arg0, s32 arg1, Msg_803E90A8 *arg2, u8 arg3) {
    u16 cur;
    s32 v;
    u8 *p;
    u8 *s;
    cur = arg0[0];
    cur += arg0[1] << 8;
    v = arg1 + cur;
    arg0[0] = v % 256;
    arg0[1] = v / 256;
    p = arg0 + cur;
    *p++ = arg2->x7;
    *p++ = arg3;
    if (arg2->x8 != 0 || arg2->x7 >= 0x2D) {
        *p++ = arg2->x8;
    }
    s = arg2->text;
    while (*s != 0) {
        if (IsSjisLead_803E90A8(*s)) {
            *p++ = *s++;
        } else {
            *p++ = 0xFF;
        }
        *p++ = *s++;
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline s32 IsSjisLead_803E9190(u8 c) {
    if ((c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
        return 1;
    }
    return 0;
}
inline void CopyText_803E9190(u8 *s, u8 *p) {
    while (*s != 0) {
        if (IsSjisLead_803E9190(*s)) {
            *p++ = *s++;
        } else {
            *p++ = 0xFF;
        }
        *p++ = *s++;
    }
}
void build_message_packet__22TQuestVmDownLoadServerFPviPvUc(u8 *arg0, s32 arg1, Msg_803E9190 *arg2, u8 arg3) {
    u8 unused[8];
    *arg0++ = arg1 % 256;
    *arg0++ = arg1 / 256;
    *arg0++ = arg2->len;
    strncpy((char *)arg0, arg2->name, arg2->len);
    arg0 += arg2->len;
    *arg0++ = arg2->x7;
    *arg0++ = arg3;
    if (arg2->x8 != 0 || arg2->x7 >= 0x2D) {
        *arg0++ = arg2->x8;
    }
    CopyText_803E9190(arg2->text, arg0);
}
#pragma pop

s32 TQuestVmDownLoadServer::calc_text_length() {
    Msg_803E92C0 *arg0 = (Msg_803E92C0 *)this;
    s32 n;
    u8 *p;
    s32 extra;
    if (arg0->x8 != 0 || arg0->x7 >= 0x2D) {
        extra = 3;
    } else {
        extra = 2;
    }
    p = arg0->text;
    n = 0;
    while (*p != 0) {
        if (IsSjisLead_803E92C0(*p)) {
            p += 2;
        } else {
            p += 1;
        }
        n += 2;
    }
    return extra + n;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 IsSjisLead_803E9348(u8 c) {
    if ((c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
        return 1;
    }
    return 0;
}
s32 TQuestVmDownLoadServer::calc_message_length() {
    Msg_803E9348 *arg0 = (Msg_803E9348 *)this;
    s32 n;
    u8 *p;
    s32 extra;
    if (arg0->x8 != 0 || arg0->x7 >= 0x2D) {
        extra = 3;
    } else {
        extra = 2;
    }
    p = arg0->text;
    n = 0;
    while (*p != 0) {
        if (IsSjisLead_803E9348(*p)) {
            p += 2;
        } else {
            p += 1;
        }
        n += 2;
    }
    extra = arg0->len + extra;
    n = extra + n;
    return n + 3;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
extern "C" s32 TQuestVmDownLoadServer__sub_803E93DC(void) {
  u8 buf[0x50];
  Node_803E95BC *pc[2];
  u8 *base = (u8 *) (&lbl_80591EC8);
  u8 *slot;
  u8 *p;
  s32 i;
  s16 len;
  s16 clen;
  u8 kind;
  s32 idx;
  s32 cmp;
  u16 size;
  Node_803E95BC *n;
  Node_803E95BC **link;
  if (TQuestVmDownLoadServer::seek_or_reopen(0x1400) == (-1))
  {
    return -1;
  }
  if (((TQuestVmDownLoadServer *) lbl_805D7904)->aram_read_thunk((u32) (&lbl_80591EC8), 0x2000) != 0x2000)
  {
    return -1;
  }
  slot = (u8 *) (&lbl_80591EC8);
  for (i = 0; i < 8; i++)
  {
    for (p = slot; ((u16) (p[0] + (p[1] << 8))) != 0; p += (u16) (p[0] + (p[1] << 8)))
    {
      len = (s16) p[2];
      if (len != 0)
      {
        strncpy((char *) buf, (char *) (p + 3), len);
        buf[len] = 0;
        pc[1] = 0;
        kind = buf[0];
        if ((kind >= 0xa0) && (kind < 0xf0))
        {
          idx = kind - 0xa0;
        }
        else
        {
          idx = 0;
        }
        pc[0] = ((Node_803E95BC **) (base + 0x2000))[idx];
        while (pc[0] != 0)
        {
          clen = (s16) ((((((pc[0]->data[2] & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu);
          cmp = strncmp(((char *) pc[0]->data) + 3, (char *) buf, clen);
          if (cmp == 0)
          {
            if (len == clen)
            {
              break;
            }
          }
          else
            if (cmp > 0)
          {
            break;
          }
          pc[1] = pc[0];
          pc[0] = pc[0]->next;
        }

        if (pc[1] == 0)
        {
          Node_803E95BC **table = (Node_803E95BC **) (base + 0x2000);
          link = &table[idx];
        }
        else
        {
          link = &pc[1]->next;
        }
        if (lbl_805D7878 == 0)
        {
          TQuestVmDownLoadServer__sub_803E95BC();
        }
        n = (Node_803E95BC *) lbl_805D7878;
        lbl_805D7878 = (Node_803E8B1C *) n->next;
        n->data = p;
        n->next = pc[0];
        *link = n;
      }
    }

    if (lbl_805D7874 == i)
    {
      lbl_805D7870 = p;
      lbl_805D786C = slot + 0x400;
    }
    slot += 0x400;
  }

  return 0;
}
#pragma pop

u8 *TQuestVmDownLoadServer::get_buffer_ptr(s32 arg0) {
    return (u8 *)&(*(RecoveredGlobal_803E9594_lbl_80591EC8 *)&lbl_80591EC8).value + ((s16) (arg0 >> 0xC) << 0xA) + (s16) (arg0 & 0xFFF);
}

#pragma push
#pragma opt_common_subs off
void TQuestVmDownLoadServer__sub_803E95BC(void) {
  s32 pad[1];
  u8 buf[0x50];
  u8 *base = (u8 *) (&lbl_80591EC8);
  u8 *p;
  u8 kind;
  u8 rkind;
  s32 i;
  s32 c;
  Node_803E95BC *new_var[2];
  Node_803E95BC **slot;
  *(lbl_805D7870++) = 0;
  *(lbl_805D7870++) = 0;
  lbl_805D7874 = (lbl_805D7874 + 1) % 8;
  lbl_805D7870 = base + (lbl_805D7874 << 10);
  lbl_805D786C = lbl_805D7870 + 0x400;
  p = lbl_805D7870;
  while (((u16) (p[0] + (p[1] << 8))) != 0)
  {
    kind = p[2];
    if ((s16) kind != 0)
    {
      strncpy((char *) buf, ((char *) p) + 3, (s16) kind);
      buf[(s16) kind] = 0;
      new_var[1] = 0;
      if ((buf[0] >= 0xa0) && (buf[0] < 0xf0))
      {
        i = buf[0] - 0xa0;
      }
      else
      {
        i = 0;
      }
      new_var[0] = *(((Node_803E95BC **) (base + 0x2000)) + i);
      while (new_var[0] != 0)
      {
        rkind = new_var[new_var[0]->data[2] * 0]->data[2];
        c = strncmp(((char *) new_var[0]->data) + 3, (char *) buf, (s16) rkind);
        if (c == 0)
        {
          if ((s16) kind == (s16) rkind)
          {
            break;
          }
        }
        else
          if (c > 0)
        {
          break;
        }
        new_var[1] = new_var[0];
        new_var[0] = new_var[0]->next;
      }

      if (new_var[1] == 0)
      {
        slot = ((Node_803E95BC **) (base + 0x2000)) + i;
      }
      else
      {
        slot = &new_var[1]->next;
      }
      if (new_var[0]->data == p)
      {
        *slot = new_var[0]->next;
        new_var[0]->next = (Node_803E95BC *) lbl_805D7878;
        lbl_805D7878 = (Node_803E8B1C *) new_var[0];
      }
    }
    p += (u16) (p[0] + (p[1] << 8));
  }

  TQuestVmDownLoadServer::clear_entries_by_id(lbl_805D7874);
}
#pragma pop

void TQuestVmDownLoadServer__sub_803E9764(void) {
    if ((u8) (*(u8 *)&lbl_805D7868) != 0) {
        if (TQuestVmDownLoadServer::seek_or_reopen(0x1400) != -1) {
            TQuestVmDownLoadServer__sub_803E8788(lbl_805D7904, lbl_80591EC8.pages, 0x2000);
        }
    }
}


void __VIRetraceHandler(void) {
    u8 *base = (u8 *)&lbl_80591EC8;
    u8 *p = base + 0x2140;
    u8 *end = base + 0x3138;
    s32 zero = 0;
    s32 pad[4];

    while (p < end) {
        *(u8 **)(p + 4) = p + 8;
        p += 8;
    }
    *(s32 *)(p + 4) = zero;
    lbl_805D7878 = (Node_803E8B1C *)(base + 0x2140);
    *(s32 *)(base + 0x2000) = zero;
    *(s32 *)(base + 0x2004) = zero;
    *(s32 *)(base + 0x2008) = zero;
    *(s32 *)(base + 0x200c) = zero;
    *(s32 *)(base + 0x2010) = zero;
    *(s32 *)(base + 0x2014) = zero;
    *(s32 *)(base + 0x2018) = zero;
    *(s32 *)(base + 0x201c) = zero;
    *(s32 *)(base + 0x2020) = zero;
    *(s32 *)(base + 0x2024) = zero;
    *(s32 *)(base + 0x2028) = zero;
    *(s32 *)(base + 0x202c) = zero;
    *(s32 *)(base + 0x2030) = zero;
    *(s32 *)(base + 0x2034) = zero;
    *(s32 *)(base + 0x2038) = zero;
    *(s32 *)(base + 0x203c) = zero;
    *(s32 *)(base + 0x2040) = zero;
    *(s32 *)(base + 0x2044) = zero;
    *(s32 *)(base + 0x2048) = zero;
    *(s32 *)(base + 0x204c) = zero;
    *(s32 *)(base + 0x2050) = zero;
    *(s32 *)(base + 0x2054) = zero;
    *(s32 *)(base + 0x2058) = zero;
    *(s32 *)(base + 0x205c) = zero;
    *(s32 *)(base + 0x2060) = zero;
    *(s32 *)(base + 0x2064) = zero;
    *(s32 *)(base + 0x2068) = zero;
    *(s32 *)(base + 0x206c) = zero;
    *(s32 *)(base + 0x2070) = zero;
    *(s32 *)(base + 0x2074) = zero;
    *(s32 *)(base + 0x2078) = zero;
    *(s32 *)(base + 0x207c) = zero;
    *(s32 *)(base + 0x2080) = zero;
    *(s32 *)(base + 0x2084) = zero;
    *(s32 *)(base + 0x2088) = zero;
    *(s32 *)(base + 0x208c) = zero;
    *(s32 *)(base + 0x2090) = zero;
    *(s32 *)(base + 0x2094) = zero;
    *(s32 *)(base + 0x2098) = zero;
    *(s32 *)(base + 0x209c) = zero;
    *(s32 *)(base + 0x20a0) = zero;
    *(s32 *)(base + 0x20a4) = zero;
    *(s32 *)(base + 0x20a8) = zero;
    *(s32 *)(base + 0x20ac) = zero;
    *(s32 *)(base + 0x20b0) = zero;
    *(s32 *)(base + 0x20b4) = zero;
    *(s32 *)(base + 0x20b8) = zero;
    *(s32 *)(base + 0x20bc) = zero;
    *(s32 *)(base + 0x20c0) = zero;
    *(s32 *)(base + 0x20c4) = zero;
    *(s32 *)(base + 0x20c8) = zero;
    *(s32 *)(base + 0x20cc) = zero;
    *(s32 *)(base + 0x20d0) = zero;
    *(s32 *)(base + 0x20d4) = zero;
    *(s32 *)(base + 0x20d8) = zero;
    *(s32 *)(base + 0x20dc) = zero;
    *(s32 *)(base + 0x20e0) = zero;
    *(s32 *)(base + 0x20e4) = zero;
    *(s32 *)(base + 0x20e8) = zero;
    *(s32 *)(base + 0x20ec) = zero;
    *(s32 *)(base + 0x20f0) = zero;
    *(s32 *)(base + 0x20f4) = zero;
    *(s32 *)(base + 0x20f8) = zero;
    *(s32 *)(base + 0x20fc) = zero;
    *(s32 *)(base + 0x2100) = zero;
    *(s32 *)(base + 0x2104) = zero;
    *(s32 *)(base + 0x2108) = zero;
    *(s32 *)(base + 0x210c) = zero;
    *(s32 *)(base + 0x2110) = zero;
    *(s32 *)(base + 0x2114) = zero;
    *(s32 *)(base + 0x2118) = zero;
    *(s32 *)(base + 0x211c) = zero;
    *(s32 *)(base + 0x2120) = zero;
    *(s32 *)(base + 0x2124) = zero;
    *(s32 *)(base + 0x2128) = zero;
    *(s32 *)(base + 0x212c) = zero;
    *(s32 *)(base + 0x2130) = zero;
    *(s32 *)(base + 0x2134) = zero;
    *(s32 *)(base + 0x2138) = zero;
    *(s32 *)(base + 0x213c) = zero;

    if (TQuestVmDownLoadServer__sub_803E93DC() == -1) {
        u8 *q = base + 0x400;
        base[1] = 0;
        base[0] = 0;
        q[1] = 0;
        q[0] = 0;
        base[0x801] = 0;
        base[0x800] = 0;
        base[0xC01] = 0;
        base[0xC00] = 0;
        base[0x1001] = 0;
        base[0x1000] = 0;
        base[0x1401] = 0;
        base[0x1400] = 0;
        base[0x1801] = 0;
        base[0x1800] = 0;
        base[0x1C01] = 0;
        base[0x1C00] = 0;
        lbl_805D7874 = zero;
        lbl_805D7870 = base;
        lbl_805D786C = base + 0x400;
    }
    lbl_805D7868 = 0;
}

typedef char RecoveredGlobal_803E9F20_lbl_80595998_size[sizeof(RecoveredGlobal_803E9F20_lbl_80595998) == 0x8C0 ? 1 : -1];

}
