#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer_803E6970.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/QuestDownloadServer.h"

#pragma dont_inline off
#pragma inline_depth(2)

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
inline s32 IsSjisLead(u8 c) {
    if ((c >= 0x80 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
        return 1;
    }
    return 0;
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

void TQuestVmDownLoadServer__sub_803E8924(s32 id) {
    char buf[0x50];
    s32 unused[3];
    s16 page;
    int page_wide;
    u8 *p;
    s16 len;
    u8 *dst;
    s16 elen;
    Node_803E8B1C *n;
    s32 size;
    s32 h;
    s32 r;
    u8 c;
    page = (s16)(page_wide = id >> 12);
    if (lbl_805D7874 == page) {
        return;
    }
    p = &lbl_80591EC8.pages[page][(s16)(id & 0xFFF)];
    u8 *lo = &p[(lbl_805D7874 == page) * 0];
    size = *lo + (p[1] << 8);
    size &= 0xFFFF;
    u8 *rec = p;
    if (lbl_805D7870 > lbl_805D786C - size - 2) {
        TQuestVmDownLoadServer__sub_803E95BC();
    }
    dst = lbl_805D7870;
    lbl_805D7870 += size;
    lbl_805D7870[0] = 0;
    lbl_805D7870[1] = 0;
    if (page == lbl_805D7874) {
        return;
    }
    len = p[2];
    strncpy(buf, (const char *)p + 3, len);
    buf[len] = 0;
    c = buf[0];
    if (c >= 0xA0 && c < 0xF0) {
        h = c - 0xA0;
    } else {
        h = 0;
    }
    n = lbl_80593EC8.hash[h];
    while (n != NULL) {
        elen = n->ent->len;
        r = strncmp(n->ent->name, buf, elen);
        if (r == 0) {
            if (len == elen) {
                break;
            }
        } else if (r > 0) {
            break;
        }
        n = n->next;
    }

    if (n->ent != (Ent_803E8B1C *)p) {
        return;
    }
    n->ent = (Ent_803E8B1C *)dst;
    while (size != 0) {
        *dst++ = *p++;
        size--;
    }

    rec[2] = 0;
    TQuestVmDownLoadServer::invalidate_entries_by_id(id);
}

// Id of a name-cache record: its 0x400-byte page in bits 12 and up, its offset in the page below.
inline s32 NameRecordId_80591EC8(NameCache_80591EC8 *cache, void *rec) {
    s32 off = (u8 *)rec - (u8 *)cache;
    return ((off / 1024) << 12) | (off % 1024);
}

s32 lookup_name_entry__22TQuestVmDownLoadServerFPvsPv(char *name, s16 name_len, Out_803E8C2C *out) {
    Node_803E8B1C *n;
    s32 r;
    u8 len;
    Ent_803E8B1C *e;
    for (n = lbl_80593EC8.hash[Hash_80591EC8(name)]; n != NULL; n = n->next) {
        e = n->ent;
        len = e->len;
        r = strncmp(e->name, name, (s16)len);
        if (r == 0) {
            if ((s16)len == name_len) {
                break;
            }
        } else if (r > 0) {
            out->id = -1;
            return 0;
        }
    }
    if (n == NULL) {
        out->id = -1;
        return 0;
    }
    out->a = 0;
    out->id = NameRecordId_80591EC8(&lbl_80591EC8, e);
    out->ent = e;
    return 1;
}

s32 TQuestVmDownLoadServer__sub_803E8C2C(char *name, s16 name_len, Out_803E8C2C *out) {
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
    out->pre = 0;
    out->len = 0;
    for (n = lbl_80593EC8.hash[Hash_80591EC8(name)]; n != NULL; n = n->next) {
        e = n->ent;
        len = e->len;
        m = TQuestVmDownLoadServer::match_prefix_length((u8 *)e->name, (u8 *)name, (s16)len);
        if (m >= pre) {
            pre = m + 1;
        }
        r = strncmp(e->name, name, (s16)len);
        if (r == 0) {
            if ((s16)len == name_len) {
                return 2;
            }
            blen = len;
            found = e;
        } else if (r > 0) {
            if (strncmp(e->name, name, name_len) == 0) {
                return 2;
            }
            break;
        }
    }
    if (blen == 0) {
        out->id = -1;
        return 0;
    }
    out->a = 0;
    out->id = NameRecordId_80591EC8(&lbl_80591EC8, found);
    out->len = blen;
    out->pre = pre;
    out->ent = found;
    return 1;
}

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

void append_message_text__22TQuestVmDownLoadServerFPviPvUc(u8 *rec, s32 size, Req_803EEF2C *msg, u8 attr) {
    u16 cur;
    s32 v;
    u8 *p;
    u8 *s;
    cur = rec[0];
    cur += rec[1] << 8;
    v = size + cur;
    rec[0] = v % 256;
    rec[1] = v / 256;
    p = rec + cur;
    *p++ = msg->x7;
    *p++ = attr;
    if (msg->x8 != 0 || msg->x7 >= 0x2D) {
        *p++ = msg->x8;
    }
    s = msg->text;
    while (*s != 0) {
        if (IsSjisLead(*s)) {
            *p++ = *s++;
        } else {
            *p++ = 0xFF;
        }
        *p++ = *s++;
    }
}

inline void CopyText_803E9190(u8 *s, u8 *p) {
    while (*s != 0) {
        if (IsSjisLead(*s)) {
            *p++ = *s++;
        } else {
            *p++ = 0xFF;
        }
        *p++ = *s++;
    }
}
void build_message_packet__22TQuestVmDownLoadServerFPviPvUc(u8 *p, s32 size, Req_803EEF2C *msg, u8 attr) {
    u8 unused[8];
    *p++ = size % 256;
    *p++ = size / 256;
    *p++ = msg->len;
    strncpy((char *)p, msg->name, msg->len);
    p += msg->len;
    *p++ = msg->x7;
    *p++ = attr;
    if (msg->x8 != 0 || msg->x7 >= 0x2D) {
        *p++ = msg->x8;
    }
    CopyText_803E9190(msg->text, p);
}

s32 TQuestVmDownLoadServer::calc_text_length() {
    Req_803EEF2C *msg = (Req_803EEF2C *)this;
    s32 n;
    u8 *p;
    s32 extra;
    if (msg->x8 != 0 || msg->x7 >= 0x2D) {
        extra = 3;
    } else {
        extra = 2;
    }
    p = msg->text;
    n = 0;
    while (*p != 0) {
        if (IsSjisLead(*p)) {
            p += 2;
        } else {
            p += 1;
        }
        n += 2;
    }
    return extra + n;
}

s32 TQuestVmDownLoadServer::calc_message_length() {
    Req_803EEF2C *msg = (Req_803EEF2C *)this;
    s32 n;
    u8 *p;
    s32 extra;
    if (msg->x8 != 0 || msg->x7 >= 0x2D) {
        extra = 3;
    } else {
        extra = 2;
    }
    p = msg->text;
    n = 0;
    while (*p != 0) {
        if (IsSjisLead(*p)) {
            p += 2;
        } else {
            p += 1;
        }
        n += 2;
    }
    extra = msg->len + extra;
    n = extra + n;
    return n + 3;
}

#pragma push
#pragma opt_common_subs off
s32 TQuestVmDownLoadServer__sub_803E93DC(void) {
    u8 buf[0x50];
    Node_803E8B1C *pc[2];
    NameCacheArea_80591EC8 *area = (NameCacheArea_80591EC8 *)&lbl_80591EC8;
    u8 *slot;
    u8 *p;
    s32 i;
    s16 len;
    s16 clen;
    u8 kind;
    s32 idx;
    s32 cmp;
    s16 unused;
    Node_803E8B1C *n;
    Node_803E8B1C **link;
    if (TQuestVmDownLoadServer::seek_or_reopen(0x1400) == -1) {
        return -1;
    }
    if (((TQuestVmDownLoadServer *)lbl_805D7904)->aram_read_thunk((u32)lbl_80591EC8.pages, 0x2000) != 0x2000) {
        return -1;
    }
    slot = lbl_80591EC8.pages[0];
    for (i = 0; i < 8; i++) {
        for (p = slot; (u16)(p[0] + (p[1] << 8)) != 0; p += (u16)(p[0] + (p[1] << 8))) {
            len = (s16)p[2];
            if (len != 0) {
                strncpy((char *)buf, (char *)(p + 3), len);
                buf[len] = 0;
                pc[1] = NULL;
                kind = buf[0];
                if (kind >= 0xA0 && kind < 0xF0) {
                    idx = kind - 0xA0;
                } else {
                    idx = 0;
                }
                pc[0] = ((Node_803E8B1C **)area->names.hash)[idx];
                while (pc[0] != NULL) {
                    clen = (s16)(pc[0]->ent->len & 0xFFFFu);
                    cmp = strncmp(pc[0]->ent->name, (char *)buf, clen);
                    if (cmp == 0) {
                        if (len == clen) {
                            break;
                        }
                    } else if (cmp > 0) {
                        break;
                    }
                    pc[1] = pc[0];
                    pc[0] = pc[0]->next;
                }

                if (pc[1] == NULL) {
                    Node_803E8B1C **table = area->names.hash;
                    link = &table[idx];
                } else {
                    link = &pc[1]->next;
                }
                if (lbl_805D7878 == NULL) {
                    TQuestVmDownLoadServer__sub_803E95BC();
                }
                n = lbl_805D7878;
                lbl_805D7878 = n->next;
                n->ent = (Ent_803E8B1C *)p;
                n->next = pc[0];
                *link = n;
            }
        }

        if (lbl_805D7874 == i) {
            lbl_805D7870 = p;
            lbl_805D786C = slot + 0x400;
        }
        slot += 0x400;
    }

    return 0;
}

#pragma pop

u8 *TQuestVmDownLoadServer::get_buffer_ptr(s32 id) {
    return &lbl_80591EC8.pages[(s16)(id >> 12)][(s16)(id & 0xFFF)];
}

#pragma push
#pragma opt_common_subs off
void TQuestVmDownLoadServer__sub_803E95BC(void) {
    u8 buf[0x50];
    NameCacheArea_80591EC8 *area = (NameCacheArea_80591EC8 *)&lbl_80591EC8;
    u8 *p;
    u8 len;
    u8 elen;
    s32 h;
    s32 r;
    Node_803E8B1C *pc[2];
    Node_803E8B1C **link;
    *lbl_805D7870++ = 0;
    *lbl_805D7870++ = 0;
    lbl_805D7874 = (lbl_805D7874 + 1) % 8;
    lbl_805D7870 = area->cache.pages[lbl_805D7874];
    lbl_805D786C = lbl_805D7870 + 0x400;
    p = lbl_805D7870;
    while ((u16)(p[0] + (p[1] << 8)) != 0) {
        len = p[2];
        if ((s16)len != 0) {
            strncpy((char *)buf, (char *)p + 3, (s16)len);
            buf[(s16)len] = 0;
            pc[1] = NULL;
            if (buf[0] >= 0xA0 && buf[0] < 0xF0) {
                h = buf[0] - 0xA0;
            } else {
                h = 0;
            }
            pc[0] = ((Node_803E8B1C **)area->names.hash)[h];
            while (pc[0] != NULL) {
                elen = pc[pc[0]->ent->len * 0]->ent->len;
                r = strncmp(pc[0]->ent->name, (char *)buf, (s16)elen);
                if (r == 0) {
                    if ((s16)len == (s16)elen) {
                        break;
                    }
                } else if (r > 0) {
                    break;
                }
                pc[1] = pc[0];
                pc[0] = pc[0]->next;
            }

            if (pc[1] == NULL) {
                link = (Node_803E8B1C **)area->names.hash + h;
            } else {
                link = &pc[1]->next;
            }
            if (pc[0]->ent == (Ent_803E8B1C *)p) {
                *link = pc[0]->next;
                pc[0]->next = lbl_805D7878;
                lbl_805D7878 = pc[0];
            }
        }
        p += (u16)(p[0] + (p[1] << 8));
    }

    TQuestVmDownLoadServer::clear_entries_by_id(lbl_805D7874);
}

#pragma pop

void TQuestVmDownLoadServer__sub_803E9764(void) {
    if (lbl_805D7868 != 0) {
        if (TQuestVmDownLoadServer::seek_or_reopen(0x1400) != -1) {
            TQuestVmDownLoadServer__sub_803E8788(lbl_805D7904, lbl_80591EC8.pages, 0x2000);
        }
    }
}

void __VIRetraceHandler(void) {
    NameCacheArea_80591EC8 *area = (NameCacheArea_80591EC8 *)&lbl_80591EC8;
    Node_803E8B1C *n = area->names.nodes;
    Node_803E8B1C *end = &area->names.nodes[0x1FF];
    s32 unused[6];

    while (n < end) {
        n->next = n + 1;
        n++;
    }
    n->next = NULL;
    lbl_805D7878 = area->names.nodes;
    area->names.hash[0] = NULL;
    area->names.hash[1] = NULL;
    area->names.hash[2] = NULL;
    area->names.hash[3] = NULL;
    area->names.hash[4] = NULL;
    area->names.hash[5] = NULL;
    area->names.hash[6] = NULL;
    area->names.hash[7] = NULL;
    area->names.hash[8] = NULL;
    area->names.hash[9] = NULL;
    area->names.hash[10] = NULL;
    area->names.hash[11] = NULL;
    area->names.hash[12] = NULL;
    area->names.hash[13] = NULL;
    area->names.hash[14] = NULL;
    area->names.hash[15] = NULL;
    area->names.hash[16] = NULL;
    area->names.hash[17] = NULL;
    area->names.hash[18] = NULL;
    area->names.hash[19] = NULL;
    area->names.hash[20] = NULL;
    area->names.hash[21] = NULL;
    area->names.hash[22] = NULL;
    area->names.hash[23] = NULL;
    area->names.hash[24] = NULL;
    area->names.hash[25] = NULL;
    area->names.hash[26] = NULL;
    area->names.hash[27] = NULL;
    area->names.hash[28] = NULL;
    area->names.hash[29] = NULL;
    area->names.hash[30] = NULL;
    area->names.hash[31] = NULL;
    area->names.hash[32] = NULL;
    area->names.hash[33] = NULL;
    area->names.hash[34] = NULL;
    area->names.hash[35] = NULL;
    area->names.hash[36] = NULL;
    area->names.hash[37] = NULL;
    area->names.hash[38] = NULL;
    area->names.hash[39] = NULL;
    area->names.hash[40] = NULL;
    area->names.hash[41] = NULL;
    area->names.hash[42] = NULL;
    area->names.hash[43] = NULL;
    area->names.hash[44] = NULL;
    area->names.hash[45] = NULL;
    area->names.hash[46] = NULL;
    area->names.hash[47] = NULL;
    area->names.hash[48] = NULL;
    area->names.hash[49] = NULL;
    area->names.hash[50] = NULL;
    area->names.hash[51] = NULL;
    area->names.hash[52] = NULL;
    area->names.hash[53] = NULL;
    area->names.hash[54] = NULL;
    area->names.hash[55] = NULL;
    area->names.hash[56] = NULL;
    area->names.hash[57] = NULL;
    area->names.hash[58] = NULL;
    area->names.hash[59] = NULL;
    area->names.hash[60] = NULL;
    area->names.hash[61] = NULL;
    area->names.hash[62] = NULL;
    area->names.hash[63] = NULL;
    area->names.hash[64] = NULL;
    area->names.hash[65] = NULL;
    area->names.hash[66] = NULL;
    area->names.hash[67] = NULL;
    area->names.hash[68] = NULL;
    area->names.hash[69] = NULL;
    area->names.hash[70] = NULL;
    area->names.hash[71] = NULL;
    area->names.hash[72] = NULL;
    area->names.hash[73] = NULL;
    area->names.hash[74] = NULL;
    area->names.hash[75] = NULL;
    area->names.hash[76] = NULL;
    area->names.hash[77] = NULL;
    area->names.hash[78] = NULL;
    area->names.hash[79] = NULL;

    if (TQuestVmDownLoadServer__sub_803E93DC() == -1) {
        u8 *page1 = area->cache.pages[1];
        area->cache.pages[0][1] = 0;
        area->cache.pages[0][0] = 0;
        page1[1] = 0;
        page1[0] = 0;
        area->cache.pages[2][1] = 0;
        area->cache.pages[2][0] = 0;
        area->cache.pages[3][1] = 0;
        area->cache.pages[3][0] = 0;
        area->cache.pages[4][1] = 0;
        area->cache.pages[4][0] = 0;
        area->cache.pages[5][1] = 0;
        area->cache.pages[5][0] = 0;
        area->cache.pages[6][1] = 0;
        area->cache.pages[6][0] = 0;
        area->cache.pages[7][1] = 0;
        area->cache.pages[7][0] = 0;
        lbl_805D7874 = 0;
        lbl_805D7870 = area->cache.pages[0];
        lbl_805D786C = page1;
    }
    lbl_805D7868 = 0;
}

}
