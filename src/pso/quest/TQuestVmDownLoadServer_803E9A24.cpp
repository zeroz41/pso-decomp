#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer_803E6970.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/QuestDownloadServer.h"

extern "C" {
s32 TQuestVmDownLoadServer::is_download_cmd_allowed(u8 arg0) {
    if ((lbl_805D7888 - 1) <= 1U) {
        return 0;
    }
    switch (arg0) {
    case 0x9D:
    case 0xA1:
    case 0xA3:
    case 0xA5:
    case 0xA7:
    case 0xA9:
    case 0xC3:
    case 0xE3:
    case 0xE5:
    case 0xE7:
    case 0xEE:
    case 0xF2:
    case 0xF3:
        return 1;
    default:
        return 0;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
#pragma opt_common_subs off
inline s32 IsX_803E9FFC(u8 arg0) {
    if ((lbl_805D7888 - 1) <= 1U) {
        return 0;
    }
    switch (arg0) {
    case 0x9D:
    case 0xA1:
    case 0xA3:
    case 0xA5:
    case 0xA7:
    case 0xA9:
    case 0xC3:
    case 0xE3:
    case 0xE5:
    case 0xE7:
    case 0xEE:
    case 0xF2:
    case 0xF3:
        return 1;
    default:
        return 0;
    }
}
// Inferred: true for the characters that end a name (space, punctuation, SJIS-range markers).
inline s32 IsBreakChar_803E9A74(u8 c) {
    if (c >= 0xA0) {
        return 0;
    }
    switch (c) {
    case 0x20:
    case 0x21:
    case 0x2C:
    case 0x2E:
    case 0x3A:
    case 0x3B:
    case 0x3F:
    case 0x98:
    case 0x9B:
    case 0x9C:
        return 1;
    default:
        return 0;
    }
}
Seg_803E9FFC *TQuestVmDownLoadServer__sub_803E9A74(s32 pos, s32 end, u8 a, u8 b) {
    s32 n;
    Obj_803EADD4 *slot;
    Ent_803E9DE0 *sub;
    Ent_803E9DE0 *e;
    Seg_803E9FFC *head;
    head = NULL;
    if (pos >= end) {
        if (lbl_805D7888 < 3) {
            return NULL;
        }
        return (Seg_803E9FFC *)-1;
    }
    slot = &((Obj_803EADD4 *)quest_download_slot_chain_table)[pos];
    e = (Ent_803E9DE0 *)slot->x0;
    if ((u32)e == 0xFFFFFFFF) {
        return (Seg_803E9FFC *)-1;
    }
    if (e == NULL && IsBreakChar_803E9A74(((u8 *)&quest_download_scratch_storage)[pos])) {
        if (a == 0 || TQuestVmDownLoadServer::is_valid_item_for_slot(a, b)) {
            Seg_803E9FFC *s = (Seg_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF0C();
            if (s != NULL) {
                s->off = 1;
                s->a = 0xFF;
                s->x2 = 0xFF;
                s->b = 0;
                s->x3 = 0;
                s->next = NULL;
            }
            return s;
        }
    }
    // Entries that end at this position.
    for (; e != NULL; e -= (s8)e->d) {
        if (TQuestVmDownLoadServer::is_valid_item_for_slot(e->a, e->b)) {
            if (a == 0 || TQuestVmDownLoadServer__sub_803E7390(a, b, e->a)) {
                u8 *text = (u8 *)&quest_download_scratch_storage + pos;
                n = lbl_8047F0F8[e->off];
                if (pos + n >= end || !IsX_803E9FFC(text[n])) {
                    Seg_803E9FFC *s = (Seg_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF0C();
                    if (s != NULL) {
                        s->off = n;
                        s->x2 = s->a = e->a;
                        s->x3 = s->b = e->b;
                        s->next = head;
                        head = s;
                    }
                }
            }
        }
        if ((s8)e->d == 0) {
            break;
        }
    }
    // Entries continued by the segments that follow them.
    for (sub = (Ent_803E9DE0 *)slot->x0; sub != NULL; sub -= (s8)sub->d) {
        if (a == 0 || TQuestVmDownLoadServer__sub_803E7390(a, b, sub->a)) {
            Seg_803E9FFC *r;
            n = lbl_8047F0F8[sub->off];
            r = TQuestVmDownLoadServer__sub_803E9A74(pos + n, end, sub->a, sub->b);
            if ((u32)r == 0xFFFFFFFF) {
                TQuestVmDownLoadServer__sub_803ECE5C((Node_803ECE5C *)head);
                return (Seg_803E9FFC *)-1;
            }
            if (r != NULL) {
                Seg_803E9FFC *s;
                for (s = r;; s = s->next) {
                    s->off += n;
                    s->x2 = sub->a;
                    s->x3 = sub->b;
                    if (s->next == NULL) {
                        break;
                    }
                }
                s->next = head;
                head = r;
            }
        }
        if ((s8)sub->d == 0) {
            break;
        }
    }
    return head;
}
#pragma pop

Ent_803E9DE0 *find_longest_match_entry__22TQuestVmDownLoadServerFPviPv(u8 *arg0, s32 arg1, s32 *arg2) {
    u8 *s;
    u8 *a;
    s32 k;
    s32 rem;
    Ent_803E9DE0 *p;
    s32 m;
    s32 best = 1;
    u8 c = arg0[0];
    if (c < 0xA0) {
        *arg2 = 1;
        return NULL;
    }
    c -= 0xA0;
    for (p = &quest_download_lz_match_entry_table[quest_download_lz_match_index_table[c + 1]] - 1; p >= &quest_download_lz_match_entry_table[quest_download_lz_match_index_table[c]]; p--) {
        a = arg0 + 1;
        rem = arg1 - 1;
        s = &lbl_8047F0F8[p->off];
        m = 1;
        k = *s++ - 1;
        while (1) {
            if (k == 0) {
                if (m > best) {
                    best = m;
                }
                *arg2 = best;
                return p;
            }
            if (rem == 0) {
                if (lbl_805D7888 >= 3) {
                    return (Ent_803E9DE0 *)-1;
                }
                break;
            }
            m++;
            if (*s != *a) {
                if (m > best) {
                    best = m;
                }
                break;
            }
            a++;
            s++;
            rem--;
            k--;
        }
    }
    *arg2 = best;
    return NULL;
}

void TQuestVmDownLoadServer::latch_slot_value(s32 arg0) {
    struct Fields_temp_r3 { u8 pad_0[20]; u8 field_14; u8 field_15; u8 field_16; };
    u8 *temp_r3;
    temp_r3 = (u8 *)quest_download_slot_chain_table + (arg0 * 0x1C);
    if (((s8) ((Fields_temp_r3*)temp_r3)->field_16 == 0) && ((s8) ((Fields_temp_r3*)temp_r3)->field_14 != 0)) {
        ((Fields_temp_r3*)temp_r3)->field_16 = (u8) ((Fields_temp_r3*)temp_r3)->field_15;
    }
}

s32 TQuestVmDownLoadServer__sub_803E9F54(s32 arg0) {
    R_803E9F54 *r;
    if (arg0 >= quest_text_end) {
        return 0;
    }
    r = &((R_803E9F54 *)quest_download_slot_chain_table)[arg0];
    if (lbl_805D7848 == 2 && r->a == 0) {
        return 0;
    }
    return (s8)r->b;
}

N_803E9FA4 *insert_sorted_node__22TQuestVmDownLoadServerFPvPv(N_803E9FA4 *arg0, N_803E9FA4 *arg1) {
    N_803E9FA4 *cur;
    N_803E9FA4 *prev;
    s16 k = arg1->key;
    if (arg0 == NULL || arg0->key < k) {
        arg1->next = arg0;
        return arg1;
    }
    cur = arg0->next;
    prev = arg0;
    while (cur != NULL) {
        if (cur->key < k) {
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    prev->next = arg1;
    arg1->next = cur;
    return arg0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void *TQuestVmDownLoadServer__sub_803E9FFC(s32 arg0, s32 arg1, Tok_803E9FFC *t) {
    s32 off;
    Out_803E9FFC *head;
    Out_803E9FFC *tail;
    s32 pos;
    Seg_803E9FFC *s;
    Seg_803E9FFC *first;
    Out_803E9FFC *o;
    off = t->off;
    head = NULL;
    tail = NULL;
    pos = arg0 + off;
    s = TQuestVmDownLoadServer__sub_803E9A74(pos, arg1, t->a, t->b);
    if ((u32)s == 0xFFFFFFFFU) {
        return (void *)-1;
    }
    for (first = s; s != NULL; s = s->next) {
        o = (Out_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF48();
        if (o == NULL) {
            break;
        }
        if (head == NULL) {
            head = o;
        }
        o->off = off + s->off;
        o->a = s->a;
        o->b = s->b;
        o->src = t;
        o->x8 = 0;
        o->xa = 0;
        o->next = NULL;
        if (tail != NULL) {
            tail->next = o;
        }
        tail = o;
    }
    TQuestVmDownLoadServer__sub_803ECE5C((Node_803ECE5C *)first);
    if (off > 0 && TQuestVmDownLoadServer::is_valid_item_for_slot(t->a, t->b) != 0) {
        if (pos >= arg1 || IsX_803E9FFC(((u8 *)&quest_download_scratch_storage)[pos]) == 0) {
            o = (Out_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF48();
            if (o != NULL) {
                if (head == NULL) {
                    head = o;
                }
                o->off = off;
                o->a = t->a;
                o->b = t->b;
                o->src = t;
                o->x8 = 0;
                o->xa = 0;
                o->next = NULL;
                if (tail != NULL) {
                    tail->next = o;
                }
            }
        }
    }
    return head;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline N_803E9FA4 *merge_sorted_nodes(N_803E9FA4 *head, N_803E9FA4 *list) {
    N_803E9FA4 *n;
    N_803E9FA4 *next;
    for (n = list; n != NULL; n = next) {
        next = n->next;
        head = insert_sorted_node__22TQuestVmDownLoadServerFPvPv(head, n);
    }
    return head;
}
// inferred: stores the length of the run of download-allowed commands after start
inline void set_allowed_cmd_run(Out_803E9FFC *o, s32 start, s32 end) {
    s32 i;
    for (i = start + 1; i < end; i++) {
        if (!TQuestVmDownLoadServer::is_download_cmd_allowed(((u8 *)&quest_download_scratch_storage)[i])) {
            break;
        }
    }
    o->off = i - start;
}
s32 TQuestVmDownLoadServer__sub_803EA1A8(s32 start, s32 end) {
    Obj_803EADD4 *e;
    Node_803ECDC4 *tok;
    N_803E9FA4 *list;
    Out_803E9FFC *o;
    e = (Obj_803EADD4 *)&quest_download_slot_chain_table[start];
    if ((u32)e->x4 != 0xFFFFFFFF) {
        for (tok = e->x4; tok != NULL; tok = tok->next) {
            list = (N_803E9FA4 *)TQuestVmDownLoadServer__sub_803E9FFC(start, end, (Tok_803E9FFC *)tok);
            if ((u32)list == 0xFFFFFFFF) {
                if (e->x8 != NULL) {
                    TQuestVmDownLoadServer__sub_803ECD8C(e->x8);
                    e->x8 = NULL;
                }
                return 0;
            }
            if (list != NULL) {
                e->x8 = (Node_803ECD8C *)merge_sorted_nodes((N_803E9FA4 *)e->x8, list);
            }
        }
    }
    list = (N_803E9FA4 *)TQuestVmDownLoadServer__sub_803E9FFC(start, end, lbl_8047F8A8);
    if ((u32)list == 0xFFFFFFFF) {
        if (e->x8 != NULL) {
            TQuestVmDownLoadServer__sub_803ECD8C(e->x8);
            e->x8 = NULL;
        }
        return 0;
    }
    if (list != NULL) {
        quest_download_slot_chain_table[start].head = (Elem_803ED9AC *)merge_sorted_nodes((N_803E9FA4 *)quest_download_slot_chain_table[start].head, list);
    }
    if (e->x8 == NULL) {
        o = (Out_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF48();
        if (o == NULL) {
            return -1;
        }
        set_allowed_cmd_run(o, start, end);
        o->a = 0x28;
        o->b = 0;
        o->src = NULL;
        o->x8 = 0;
        o->xa = 0;
        o->next = NULL;
        e->x8 = (Node_803ECD8C *)o;
        return 1;
    }
    return 1;
}
#pragma pop

Node_803EA384 *build_item_list__22TQuestVmDownLoadServerFiPv(s32 arg0, Hdr_803EA384 *arg1) {
    s16 id;
    s32 x4;
    s32 n;
    Item_803EA384 *it;
    Node_803EA384 *head;
    Node_803EA384 *prev;
    Node_803EA384 *node;
    u8 unused[8];
    it = arg1->items;
    head = NULL;
    prev = NULL;
    id = arg1->id;
    x4 = arg1->x4;
    n = arg1->count;
    while (n-- != 0) {
        node = TQuestVmDownLoadServer__sub_803ECF84();
        if (node == NULL) {
            break;
        }
        if (head == NULL) {
            head = node;
        }
        node->id = id;
        node->a = it->a;
        node->b = it->b;
        node->x4 = x4;
        node->c = it->c;
        node->next = NULL;
        if (prev != NULL) {
            prev->next = node;
        }
        prev = node;
        it++;
    }
    return head;
}

struct Slot_803EA428 {
    Ent_803E9DE0 *x0;
    Node_803EA384 *list;
    Out_803E9FFC *x8;
    Node_803ECD54 *xc;
    u8 pad10[4];
    s8 x14;
    s8 x15;
    u8 pad16;
    s8 width;
    s8 x18;
    u8 pad19[3];
};

// lbl_80595008 and quest_download_slot_chain_table are addressed from one base register in this function
// (slot = lbl_80595008 + 0x990 + start * 0x1C), so they are one object here.
struct Work_80595008 {
    u8 pad_0[0x8C0];
    Out_803F0268 match;
    u8 pad_match_end[0xD0 - sizeof(Out_803F0268)];
    Slot_803EA428 slots[80];
};

extern Work_80595008 lbl_80595008;

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void append_item_node(Node_803EA384 **pp, Node_803EA384 *node) {
    while (*pp != NULL) {
        pp = &(*pp)->next;
    }
    *pp = node;
}
inline void add_text_node(Slot_803EA428 *slot, s32 len, u8 kind) {
    Node_803EA384 *node = TQuestVmDownLoadServer__sub_803ECF84();
    if (node != NULL) {
        node->id = len;
        node->a = kind;
        node->b = 0;
        node->x4 = -1;
        node->c = 0;
        node->next = NULL;
        slot->width = len + 1;
        append_item_node(&slot->list, node);
    }
}
s32 TQuestVmDownLoadServer__sub_803EA428(s32 start, s32 end) {
    u32 i;
    s32 j;
    Work_80595008 *work;
    u32 n;
    Slot_803EA428 *slot;
    u8 kind;
    u32 len;
    char *text;
    char *p;
    Ent_803E6970 *e;
    u8 attr;
    s32 r;

    work = &lbl_80595008;
    n = end - start;
    if (n == 0) {
        return 0;
    }
    text = (char *)&quest_download_scratch_storage + start;
    kind = 0;
    slot = &work->slots[start];
    if (TQuestVmDownLoadServer__sub_803EDB58(*text)) {
        kind = 0x1F;
        for (len = 1, p = text + 1; len < n; len++, p++) {
            if (!TQuestVmDownLoadServer__sub_803EDB58(*p)) {
                break;
            }
        }
        if (lbl_805D7888 >= 3 && len >= n) {
            return 0;
        }
    } else if (TQuestVmDownLoadServer__sub_803EDB3C(*text)) {
        kind = 0x19;
        for (len = 1, p = text + 1; len < n; len++, p++) {
            if (!TQuestVmDownLoadServer__sub_803EDB74(*p)) {
                break;
            }
        }
        if (lbl_805D7888 >= 3 && len >= n) {
            return 0;
        }
    } else if (TQuestVmDownLoadServer__sub_803EDB20(*text)) {
        if (lbl_805D7888 >= 3 && n <= 1) {
            return 0;
        }
        i = 1;
        len = 1;
        kind = 0x19;
        goto emit;
    } else if (*text != 0 && (u8)*text < 0xA0) {
        if (lbl_805D7888 >= 3 && n <= 1) {
            return 0;
        }
        i = 1;
        len = 1;
        kind = 0x29;
        goto emit;
    } else if (*text == 0 && !(((Ent_803E6970 *)&quest_download_entry_table)[start].ch & 0xFF00)) {
        e = (Ent_803E6970 *)&quest_download_entry_table + (j = start + 1);
        for (; j < end; j++) {
            if (e->ch & 0xFF00) {
                break;
            }
            e++;
        }
        attr = 0x19;
        goto single;
    } else if (*text == 0 && TQuestVmDownLoadServer::is_download_command(((Ent_803E6970 *)&quest_download_entry_table)[start].ch, 0)) {
        for (j = start + 1, e = (Ent_803E6970 *)&quest_download_entry_table + j; j < end; e++, j++) {
            if (!TQuestVmDownLoadServer::is_download_command(e->ch, 1)) {
                break;
            }
        }
        attr = 0x19;
    single:
        if (lbl_805D7888 >= 3 && j == end) {
            return 0;
        }
        add_text_node(&work->slots[start], j - start, attr);
        return 1;
    } else if (*text == 0) {
        for (j = start + 1, p = text + 1; j < end; j++, p++) {
            if (*p != 0) {
                break;
            }
        }
        e = (Ent_803E6970 *)&quest_download_entry_table + j;
        if (TQuestVmDownLoadServer__sub_803EC884((--e)->ch)) {
            attr = 0x28;
        } else if (TQuestVmDownLoadServer::is_valid_sjis_code(e->ch)) {
            attr = 0x29;
        } else {
            attr = 0x19;
        }
        goto single;
    } else {
        len = 1;
    }
lookup:
    for (i = 0, p = text; i < n; i++) {
        if (*p++ == 0) {
            break;
        }
    }
    r = TQuestVmDownLoadServer__sub_803F06B8(text, i, &work->match);
    switch (r) {
    case 2:
        if (lbl_805D7888 >= 3) {
            return 0;
        }
        break;
    case 1:
        if (kind != 0 && work->match.len <= (s32)len) {
            TQuestVmDownLoadServer__sub_803EED9C(work->match.x4);
            i = len;
            slot->width = work->match.len2;
        } else {
            append_item_node(&slot->list, build_item_list__22TQuestVmDownLoadServerFiPv(start, (Hdr_803EA384 *)&work->match));
            slot->width = work->match.len2;
            i = work->match.len - 1;
        }
        break;
    case 0:
    default:
        if (kind != 0) {
            i = len;
            break;
        }
        slot->list = (Node_803EA384 *)-1;
        return -1;
    }
emit:
    for (; i >= len; i--) {
        if (kind != 0 && i == len) {
            add_text_node(slot, len, kind);
        }
        if (TQuestVmDownLoadServer__sub_803F0268(text, i, &work->match) == 1) {
            if (slot->width == -1) {
                slot->width = work->match.len2;
            }
            append_item_node(&work->slots[start].list, build_item_list__22TQuestVmDownLoadServerFiPv(start, (Hdr_803EA384 *)&work->match));
        }
    }
    return 1;
}
#pragma pop

s32 TQuestVmDownLoadServer::count_leading_entries(s32 i, s32 end) {
    Ent_803EA960 *e = &((Ent_803EA960 *)quest_download_slot_chain_table)[i];
    s32 n;
    s32 total = 0;
    while (i < end) {
        n = e->count;
        if (n == 0) {
            return -1;
        }
        if (e->obj != NULL && (u32)e->obj != 0xFFFFFFFF && e->obj->type != 0x28) {
            break;
        }
        total += n;
        i += n;
        e += n;
    }
    if (total == 0 || i >= end) {
        return total;
    }
    return total + n;
}

extern s32 lbl_805D7880;

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void release_slot_chains(Slot_803EA428 *slot) {
    if ((u32)slot->x8 != 0xFFFFFFFF) {
        TQuestVmDownLoadServer__sub_803ECD8C((Node_803ECD8C *)slot->x8);
    }
    slot->x8 = NULL;
    slot->x15 = 0;
    ((TQuestVmDownLoadServer *)slot->xc)->free_node_list();
    slot->xc = NULL;
}
void TQuestVmDownLoadServer__sub_803EA9E8(s32 start, s32 end, s32 mode, s32 count) {
    Work_80595008 *work;
    Slot_803EA428 *first;
    Slot_803EA428 *next;
    Slot_803EA428 *last;
    Out_803E9FFC *o;
    Out_803E9FFC **pp;
    u8 *text;
    Ent_803E9DE0 *e;
    s32 n;
    Slot_803EA428 *slot;
    s32 k;
    s32 len;
    s32 mark;
    s32 pos;
    s32 match_len;

    work = &lbl_80595008;
    first = &work->slots[start];
    text = (u8 *)&quest_download_scratch_storage + start;
    lbl_805D7888 = mode;
    for (n = end - start, slot = first; n > 0; text++, n--, slot++) {
        if ((u32)slot->x0 == 0xFFFFFFFF) {
            e = find_longest_match_entry__22TQuestVmDownLoadServerFPviPv(text, n, &match_len);
            if ((u32)e == 0xFFFFFFFF) {
                break;
            }
            slot->x18 = match_len;
            slot->x0 = e;
        }
    }
    if (lbl_805D7888 == 3 && lbl_805D7880 != 0) {
        return;
    }
    pos = start;
    mark = start + count;
    while (pos < end) {
        slot = &work->slots[pos];
        if (work->slots[pos].x15 > 0) {
            pos += work->slots[pos].x15;
            continue;
        }
        if (slot->list == NULL && TQuestVmDownLoadServer__sub_803EA428(pos, end) == 0) {
            break;
        }
        if (slot->x8 == NULL && TQuestVmDownLoadServer__sub_803EA1A8(pos, end) == 0) {
            break;
        }
        for (o = slot->x8; o != NULL; o = o->next) {
            k = pos + o->off;
            if (k >= end) {
                if (lbl_805D7888 >= 3) {
                    if (o->a != 0xFF) {
                        break;
                    }
                    lbl_805D7888 = 0;
                }
            } else {
                next = &work->slots[k];
                if (next->list == NULL && TQuestVmDownLoadServer__sub_803EA428(k, end) == 0) {
                    break;
                }
                if (next->x8 == NULL && TQuestVmDownLoadServer__sub_803EA1A8(k, end) == 0) {
                    break;
                }
            }
        }
        if (pos == start) {
            if (lbl_805D7888 == 1) {
                TQuestVmDownLoadServer::select_best_slot_entry(pos, end, count);
                first->x14 = 1;
                len = count;
            } else if (lbl_805D7888 == 2) {
                first->x14 = 1;
                len = count;
            } else {
                goto pick;
            }
        } else {
            if (pos == mark && lbl_805D7888 == 2) {
                TQuestVmDownLoadServer::reset_slot_chain_timers(pos);
            }
        pick:
            len = TQuestVmDownLoadServer::select_best_slot_entry(pos, end, -1);
            if (len == -1) {
                break;
            }
        }
        pp = &slot->x8;
        o = slot->x8;
        while (o != NULL) {
            if (o->off == len) {
                pp = &o->next;
            } else {
                *pp = o->next;
                TQuestVmDownLoadServer::push_download_entry((s32 *)o);
            }
            o = *pp;
        }
        TQuestVmDownLoadServer__sub_803EC460(pos, len);
        slot->x15 = len;
        pos += len;
    }
    for (pos = start; pos < end; pos += n) {
        slot = last = &work->slots[pos];
        len = slot->x15;
        if (slot->x14 != 0) {
            n = len;
            continue;
        }
        n = TQuestVmDownLoadServer::count_leading_entries(pos, end);
        if (n < 0) {
            return;
        }
        if (n == 0) {
            n = len;
        }
        if (n == len) {
            last->x14 = 1;
            continue;
        }
        for (; len < n; len += last->x15) {
            release_slot_chains(last);
            last = &work->slots[pos + len];
        }
        release_slot_chains(last);
        slot->x15 = n;
        o = (Out_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF48();
        if (o != NULL) {
            o->off = n;
            o->a = 0x28;
            o->b = 0;
            o->src = NULL;
            o->x8 = 0;
            o->xa = 0;
            o->next = NULL;
            slot->x8 = o;
            slot->x14 = 1;
            TQuestVmDownLoadServer__sub_803EC460(pos, n);
        }
    }
}
#pragma pop

void TQuestVmDownLoadServer__sub_803EADD4(Obj_803EADD4 *arg0, s32 arg1) {
    if (arg1 == 0) {
        arg0->x0 = -1;
        arg0->x18 = -1;
        if ((u32)arg0->x4 != 0xFFFFFFFF) {
            release_node_chain__22TQuestVmDownLoadServerFPv((Node_803ECDC4 *)(arg0->x4));
        }
        arg0->x4 = NULL;
        arg0->x17 = -1;
        arg0->x19 = -1;
        arg0->x16 = 0;
    }
    if (arg0->x8 != NULL && (u32)arg0->x8 != 0xFFFFFFFF) {
        TQuestVmDownLoadServer__sub_803ECD8C(arg0->x8);
    }
    arg0->x8 = NULL;
    if (arg0->xc != NULL) {
        ((TQuestVmDownLoadServer *)(arg0->xc))->free_node_list();
    }
    arg0->xc = NULL;
    arg0->x10 = 0;
    arg0->x14 = 0;
    arg0->x15 = 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Len_803EB328(Node_803EB328 *p) {
    s32 n;
    if (p->flags == 0x80) {
        return quest_text_entry_len * 2;
    }
    n = (quest_text_entry_len - p->x6) * 2;
    while (p->flags & 1) {
        n += strlen(p->name);
        p = p->next;
    }
    return n + strlen(p->name);
}
inline Node_803EB328 *Next_803EB328(Node_803EB328 *p) {
    while (p->flags & 1) {
        p = p->next;
    }
    return p->next;
}

void TQuestVmDownLoadServer__sub_803EAE84(s32 arg0, s32 arg1, void *arg2) {
    R_803EAE84 *p;
    R_803EAE84 *end;
    end = &((R_803EAE84 *)quest_download_slot_chain_table)[arg1];
    p = &((R_803EAE84 *)quest_download_slot_chain_table)[arg0];
    for (; p < end; p++) {
        TQuestVmDownLoadServer__sub_803EADD4((Obj_803EADD4 *)(p), (s32)arg2);
    }
}

struct Ent_803EAEF0 {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xc;
    s32 x10;
    u8 x14;
    u8 x15;
    u8 x16;
    s8 x17;
    s8 x18;
    s8 x19;
};

void TQuestVmDownLoadServer::init_entries() {
    Ent_803EAEF0 *p;

    for (p = (Ent_803EAEF0 *)quest_download_slot_chain_table; p < (Ent_803EAEF0 *)quest_download_slot_chain_table + 80; p++) {
        p->x0 = -1;
        p->x4 = 0;
        p->x8 = 0;
        p->xc = 0;
        p->x10 = 0;
        p->x14 = 0;
        p->x15 = 0;
        p->x16 = 0;
        p->x17 = -1;
        p->x18 = -1;
        p->x19 = -1;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline Node_803EB0D8 *Advance_803EB0D8(Node_803EB0D8 *p, s32 n) {
    s32 i;
    for (i = 0; i != n; i++) {
        while (p->flags & 1) {
            p = p->next;
        }
        p = p->next;
    }
    return p;
}
inline void Reload_803EB0D8(void) {
    s32 r = count_fitting_entries__22TQuestVmDownLoadServerFPv((Node_803EB328 *)((*(Node_803EB0D8 * *)&lbl_805D78A0)));
    if (r == 0) {
        TQuestVmDownLoadServer__sub_803EC284(0, 0);
    } else {
        quest_page_node_count = r;
    }
    quest_page_node_index = 0;
}
s32 TQuestVmDownLoadServer__sub_803EB0D8(s32 arg0, s32 arg1) {
    Node_803EB0D8 *save = (*(Node_803EB0D8 * *)&lbl_805D78A0);
    s32 cnt = quest_page_node_count;
    u8 unused[8];
    TQuestVmDownLoadServer__sub_803EC284(0, 0);
    if (save == (*(Node_803EB0D8 * *)&lbl_805D78A0)) {
        if (arg1 == 0) {
            (*(Node_803EB0D8 * *)&lbl_805D78A0) = save;
            quest_page_node_count = cnt;
            quest_page_node_index = 0;
            return 0;
        }
        save = NULL;
    }
    for (;;) {
        if (Advance_803EB0D8((*(Node_803EB0D8 * *)&lbl_805D78A0), quest_page_node_count) == save) {
            break;
        }
        (*(Node_803EB0D8 * *)&lbl_805D78A0) = Advance_803EB0D8((*(Node_803EB0D8 * *)&lbl_805D78A0), quest_page_node_count);
        Reload_803EB0D8();
    }
    if (arg0 == 1) {
        TQuestVmDownLoadServer__sub_803EB4D4();
    }
    return 1;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline Node_803EB420 *next_entry_group(Node_803EB420 *p) {
    while (p->flags & 1) {
        p = p->next;
    }
    return p->next;
}
inline Node_803EB420 *advance_entry_groups(Node_803EB420 *p, s32 n) {
    while (n-- != 0) {
        p = next_entry_group(p);
    }
    return p;
}
inline s32 count_fitting_groups(Node_803EB420 *head) {
    Node_803EB420 *p;
    s32 n;
    s32 total;
    s32 limit;
    if (head == NULL) {
        return 0;
    }
    p = head;
    n = total = 0;
    limit = lbl_805D78A4 - 9;
    while (n < 9 && p != NULL) {
        total += TQuestVmDownLoadServer__sub_803EB7C0((Node_803EB7C0 *)p) + 3;
        if (total > limit) {
            break;
        }
        n++;
        p = next_entry_group(p);
    }
    if (n == 0) {
        return 1;
    }
    return n;
}
s32 TQuestVmDownLoadServer__sub_803EB208(s32 mode, s32 force) {
    Node_803EB420 *save = lbl_805D78A0;
    s32 count;
    lbl_805D78A0 = advance_entry_groups(save, quest_page_node_count);
    count = count_fitting_groups(lbl_805D78A0);
    if (count == 0) {
        if (force == 0) {
            lbl_805D78A0 = save;
            return 0;
        }
        TQuestVmDownLoadServer__sub_803EC284(0, 0);
    } else {
        quest_page_node_count = count;
    }
    quest_page_node_index = 0;
    if (mode == 1) {
        TQuestVmDownLoadServer__sub_803EB4D4();
    }
    return 1;
}
#pragma pop

s32 count_fitting_entries__22TQuestVmDownLoadServerFPv(Node_803EB328 *arg0) {
    s32 n;
    s32 total;
    s32 lim;
    Node_803EB328 *p;
    if (arg0 == NULL) {
        return 0;
    }
    p = arg0;
    total = 0;
    lim = lbl_805D78A4 - 9;
    n = 0;
    while (n < 9 && p != NULL) {
        total += Len_803EB328(p) + 3;
        if (total > lim) {
            break;
        }
        n++;
        p = Next_803EB328(p);
    }
    if (n == 0) {
        return 1;
    }
    return n;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 group_name_text(Node_803EB420 *p, u16 *buf) {
    s32 n = 0;
    for (;;) {
        n += TQuestVmDownLoadServer__sub_803EC95C(buf + n, p->data, 6);
        if (!(p->flags & 1)) {
            break;
        }
        p = p->next;
    }
    return n;
}
s32 TQuestVmDownLoadServer__sub_803EB420(s32 start, s32 count, Node_803EB420 *arg2, u16 *buf) {
    s32 n;
    if (arg2 == NULL || (arg2->flags & 0x80)) {
        return TQuestVmDownLoadServer__sub_803E6970(start, count, buf, 0);
    }
    n = group_name_text(arg2, buf);
    buf += n;
    return n + TQuestVmDownLoadServer__sub_803E6970((s32)(start + arg2->len), (s32)(count - arg2->len), buf, 0);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 count_entry_groups(Node_803EB420 *p) {
    s32 n = 0;
    while (p != NULL) {
        while (p->flags & 1) {
            p = p->next;
        }
        p = p->next;
        n++;
    }
    return n;
}
inline s32 entry_group_text(s32 start, s32 count, Node_803EB420 *node, u16 *buf) {
    s32 n;
    if (node == NULL || (node->flags & 0x80)) {
        return TQuestVmDownLoadServer__sub_803E6970(start, count, buf, 0);
    }
    n = group_name_text(node, buf);
    buf += n;
    return n + TQuestVmDownLoadServer__sub_803E6970(start + node->len, count - node->len, buf, 0);
}
void TQuestVmDownLoadServer__sub_803EB4D4(void) {
    u8 *p;
    s32 n;
    u16 *buf;
    s32 i;
    Node_803EB420 *node;
    s32 w;
    s32 pos;
    s32 d;

    p = &lbl_80596258[5];
    n = count_entry_groups(lbl_805D78A0);
    n -= quest_page_node_index;
    n--;
    if (n < 0) {
        n = 0;
    }
    d = n / 100;
    if (d != 0) {
        *p++ = d + '0';
    } else {
        *p++ = ' ';
    }
    n %= 100;
    d = n / 10;
    if (d != 0 || p[-1] != 0x20U) {
        *p++ = d + '0';
    } else {
        *p++ = ' ';
    }
    n %= 10;
    *p = n + '0';
    TQuestVmDownLoadServer__sub_803EC95C(lbl_805A0340, lbl_80596258, 0);
    node = lbl_805D78A0;
    pos = 9;
    for (i = 0; i < quest_page_node_count; i++) {
        lbl_805D7894[2] = i + '1';
        pos += TQuestVmDownLoadServer__sub_803EC95C(&lbl_805A0340[pos], lbl_805D7894, 0);
        w = entry_group_text(quest_text_cursor_pos, quest_text_entry_len, node, &lbl_805A0340[pos]);
        if (i == quest_page_node_index) {
            TQuestVmDownLoadServer__sub_803ECA1C(&lbl_805A0340[pos], w, 7);
        } else {
            TQuestVmDownLoadServer__sub_803ECA1C(&lbl_805A0340[pos], w, 0);
        }
        pos += w;
        if ((node = next_entry_group(node)) == NULL) {
            break;
        }
    }
    buf = &lbl_805A0340[pos];
    for (; pos < lbl_805D78A4; pos++) {
        TQuestVmDownLoadServer__sub_803EC95C(buf, lbl_805E10D0, 0);
        buf++;
    }
}
#pragma pop

Node_803EB420 *advance_nodes__22TQuestVmDownLoadServerFPvi(Node_803EB420 *p, s32 n) {
    s32 i;
    for (i = 0; i != n; i++) {
        while (p->flags & 1) {
            p = p->next;
        }
        p = p->next;
    }
    return p;
}

s32 TQuestVmDownLoadServer__sub_803EB7C0(Node_803EB7C0 *arg0) {
    s32 n;
    if (arg0->flags == 0x80) {
        return quest_text_entry_len * 2;
    }
    n = (quest_text_entry_len - arg0->len) * 2;
    while (arg0->flags & 1) {
        n += strlen(arg0->text);
        arg0 = arg0->next;
    }
    return n + strlen(arg0->text);
}

s32 TQuestVmDownLoadServer::count_chain_nodes() {
    Node_803EB844 *p = (Node_803EB844 *)this;
    s32 n = 0;
    while (p != NULL) {
        while (p->flags & 1) {
            p = p->next;
        }
        p = p->next;
        n++;
    }
    return n;
}

Node_803EB878 *TQuestVmDownLoadServer__sub_803EB878(Node_803EB878 *p) {
    while (p->flags & 1) {
        p = p->next;
    }
    return p->next;
}

Node_803EB894 *detach_node_chain__22TQuestVmDownLoadServerFPv(Node_803EB894 *p) {
    Node_803EB894 *next;
    while (p->flags & 1) {
        p = p->next;
    }
    next = p->next;
    p->next = NULL;
    return next;
}

struct Node_803EB8BC { u8 flags; u8 data[5]; u8 len; u8 pad[9]; Node_803EB8BC *next; };

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Conv_803EB8BC(s32 start, s32 arg1, Node_803EB8BC *arg2, u16 *arg3) {
    s32 n;
    Node_803EB8BC *p;
    u16 *b = arg3;
    s32 lim = arg1;
    u8 unused[8];
    if (arg2 == NULL || (arg2->flags & 0x80)) {
        return TQuestVmDownLoadServer__sub_803E6970(start, lim, b, 0);
    }
    p = arg2;
    n = 0;
    for (;;) {
        n += TQuestVmDownLoadServer__sub_803EC95C(b + n, &p->flags + 1, 6);
        if (!(p->flags & 1)) {
            break;
        }
        p = p->next;
    }
    b += n;
    return n + TQuestVmDownLoadServer__sub_803E6970((s32)(start + arg2->len), (s32)(lim - arg2->len), b, 0);
}
inline s32 Find_803EB8BC(u8 *key, s32 len) {
    s32 l;
    u8 *p;
    for (p = quest_download_text_buffer; p < quest_download_text_write_ptr; p += l) {
        l = *p++;
        if (l == len && strncmp((const char *)p, (const char *)key, l) == 0) {
            return 1;
        }
    }
    return 0;
}
inline void Add_803EB8BC(u8 *key, s32 len) {
    if (quest_download_text_write_ptr + len + 1 <= quest_download_text_buffer + 0x400) {
        *quest_download_text_write_ptr++ = len;
        strncpy((char *)quest_download_text_write_ptr, (const char *)key, len);
        quest_download_text_write_ptr += len;
    }
}
inline Node_803EB8BC *Last_803EB8BC(Node_803EB8BC *p) {
    if (p == NULL) {
        return NULL;
    }
    for (;;) {
        if (p->next == NULL) {
            break;
        }
        p = p->next;
    }
    return p;
}

void append_unique_node__22TQuestVmDownLoadServerFiPvPvPv(s32 start, Node_803EB8BC **headp, Node_803EB8BC **tailp, Node_803EB8BC *n) {
    s32 len;

    len = Conv_803EB8BC(start, quest_text_entry_len, n, lbl_805A0340);
    len = TQuestVmDownLoadServer__sub_803EC71C(lbl_805A0340, (u8 *)lbl_805A02A8, len);
    if (Find_803EB8BC((u8 *)lbl_805A02A8, len)) {
        ((TQuestVmDownLoadServer *)n)->free_node_list();
        return;
    }
    Add_803EB8BC((u8 *)lbl_805A02A8, len);
    if (*headp == NULL) {
        *tailp = n;
        *headp = n;
    } else {
        (*tailp)->next = n;
    }
    *tailp = Last_803EB8BC(n);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Conv_803EBA98(s32 start, s32 arg1, Node_803EBA98 *arg2, u16 *arg3) {
    Node_803EBA98 *p;
    s32 n;
    u16 *b = arg3;
    s32 lim = arg1;
    u8 unused[8];
    if (arg2 == NULL || (arg2->flags & 0x80)) {
        return TQuestVmDownLoadServer__sub_803E6970(start, lim, b, 0);
    }
    p = arg2;
    n = 0;
    for (;;) {
        n += TQuestVmDownLoadServer__sub_803EC95C(b + n, &p->flags + 1, 6);
        if (!(p->flags & 1)) {
            break;
        }
        p = p->next;
    }
    b += n;
    return n + TQuestVmDownLoadServer__sub_803E6970((s32)(start + arg2->len), (s32)(lim - arg2->len), b, 0);
}
inline Node_803EBA98 *Next_803EBA98(Node_803EBA98 *p) {
    while (p->flags & 1) {
        p = p->next;
    }
    return p->next;
}
void TQuestVmDownLoadServer__sub_803EBA98(s32 start, Node_803EBA98 *arg1) {
    s32 n;
    s32 len;
    quest_download_text_write_ptr = quest_download_text_buffer;
    while (arg1 != NULL) {
        n = Conv_803EBA98(start, quest_text_entry_len, arg1, lbl_805A0340);
        len = TQuestVmDownLoadServer__sub_803EC71C(lbl_805A0340, quest_download_text_write_ptr + 1, n);
        *quest_download_text_write_ptr++ = len;
        quest_download_text_write_ptr += len;
        arg1 = Next_803EBA98(arg1);
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline Node_803ECD54 *build_entry_text(s32 idx, s32 len, s32 mode) {
    void *first;
    void *tail;
    Src_803EBD38 *src = (Src_803EBD38 *)quest_download_text_buffer;
    src->x0 = 0xFFFF;
    src->x2 = 0;
    src->x4 = 0;
    TQuestVmDownLoadServer__sub_803E6B70(src->text, idx, len, mode);
    return (Node_803ECD54 *)TQuestVmDownLoadServer::build_text_node_chain(src, NULL, len, &first, &tail);
}

void TQuestVmDownLoadServer__sub_803EBC88(s32 mode) {
    Obj_803EADD4 *e = &((Obj_803EADD4 *)quest_download_slot_chain_table)[quest_text_cursor_pos];
    ((TQuestVmDownLoadServer *)e->xc)->free_node_list();
    e->xc = build_entry_text(quest_text_cursor_pos, quest_text_entry_len, mode);
}
#pragma pop

struct Tok_803EBEFC { s16 x0; u8 x2; u8 x3; s32 x4; };
struct Arg_803EBEFC { s16 x0; u8 pad[2]; Tok_803EBEFC *tok; };
struct N_803EBEFC {
    u8 flags;
    u8 text[5];
    u8 x6;
    u8 x7;
    s32 x8;
    u16 xc;
    u16 xe;
    N_803EBEFC *next;
};

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline N_803EBEFC *Default_803EBEFC(s32 x) {
    N_803EBEFC *n = (N_803EBEFC *)TQuestVmDownLoadServer__sub_803ECED0();
    if (n != NULL) {
        n->flags = 0x80;
        n->text[0] = 0;
        n->x6 = x;
        n->x7 = 0;
        n->x8 = 0;
        n->xc = 0xFFFF;
        n->next = NULL;
    }
    return n;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Copy_803EBD38(u8 *dst, u8 *src, s32 max) {
    s32 n = max;
    u8 *s = src;
    u8 *d = dst;
    while (*s != 0 && n > 0) {
        if (TQuestVmDownLoadServer::is_sjis_lead_byte(*s)) {
            if (n <= 1) {
                break;
            }
            *d++ = *s++;
            n--;
        }
        *d++ = *s++;
        n--;
    }
    *d = 0;
    return max - n;
}
#define s ((Src_803EBD38 *)sp)
#define headp ((N_803EBD38 **)hp)
#define tailp ((N_803EBD38 **)tp)
void *TQuestVmDownLoadServer::build_text_node_chain(void *sp, void *a1, s32 a2, void *hp, void *tp) {
    u8 *text;
    s32 rem;
    N_803EBD38 *n;
    N_803EBD38 *m;
    s32 c;
    u8 unused[8];
    text = s->text;
    rem = strlen((const char *)text);
    n = (N_803EBD38 *)TQuestVmDownLoadServer__sub_803ECED0();
    if (n == NULL) {
        return NULL;
    }
    n->flags = 0;
    c = Copy_803EBD38(n->text, text, 4);
    rem -= c;
    n->x6 = a2;
    text += c;
    n->x7 = s->x4;
    n->x8 = (s32)a1;
    n->xc = s->x0;
    n->xe = s->x2;
    n->next = NULL;
    *headp = n;
    while (rem > 0) {
        m = (N_803EBD38 *)TQuestVmDownLoadServer__sub_803ECED0();
        if (m == NULL) {
            ((TQuestVmDownLoadServer *)((Node_803ECD54 *)*headp))->free_node_list();
            return NULL;
        }
        n->flags |= 1;
        m->flags = 2;
        c = Copy_803EBD38(m->text, text, 14);
        rem -= c;
        text += c;
        m->next = NULL;
        n->next = m;
        n = m;
    }
    *tailp = n;
    return *headp;
}
#undef s
#undef headp
#undef tailp
#pragma pop

N_803EBEFC *TQuestVmDownLoadServer__sub_803EBEFC(Arg_803EBEFC *a) {
    s32 count;
    N_803EBEFC *first;
    N_803EBEFC *tl;
    s32 pad;
    N_803EBEFC *head;
    u8 *base;
    Tok_803EBEFC *t;
    N_803EBEFC *tail;
    u8 *p;

    base = lbl_80596258;
    t = a->tok;
    if (t == NULL || t->x0 == 0) {
def:
        return Default_803EBEFC(a->x0);
    }
    if ((u32)t->x4 == 0xFFFFFFFFU) {
        if (t->x2 != 0x1F) {
            goto def;
        }
        if (TQuestVmDownLoadServer__sub_803EEA48((s32)&quest_download_scratch_storage + quest_text_cursor_pos, t->x0, base + 0xC, &count) > 0) {
            goto build;
        }
        goto def;
    } else {
        if (TQuestVmDownLoadServer::read_quest_chunk(t->x4, t->x2, t->x3, base + 0xC, &count) <= 0) {
            goto def;
        }
    }
build:
    p = base + 0xC;
    tail = NULL;
    head = NULL;
    while (count > 0) {
        if (TQuestVmDownLoadServer::build_text_node_chain(p, t, t->x0, &first, &tl) == NULL) {
            ((TQuestVmDownLoadServer *)head)->free_node_list();
            return NULL;
        }
        if (head == NULL) {
            head = first;
            tail = tl;
        } else {
            tail->next = first;
            tail = tl;
        }
        p += 5;
        while (*p++ != 0) {
        }
        if ((u32)p & 1) {
            p++;
        }
        count--;
    }
    return head;
}
#pragma pop

struct N_803EC09C {
    u8 flags;
    u8 text[5];
    u8 x6;
    u8 x7;
    s32 x8;
    u16 xc;
    u16 xe;
    N_803EC09C *next;
};
struct Out_803EC09C {
    s16 off; u8 a; u8 b;
    void *src;
    s16 x8; s16 xa;
    Out_803EC09C *next;
};
struct Q_803EC09C {
    Out_803EC09C *o;
    u16 x4;
    u8 pad[2];
    N_803EC09C *x8;
    Q_803EC09C *next;
};
struct Ent_803EC09C {
    s32 x0;
    void *toks;
    Out_803EC09C *list;
    N_803EC09C *xc;
    u8 pad[0xC];
};
Q_803EC09C *TQuestVmDownLoadServer__sub_803ECE94(void);
N_803EC09C *get_next_node__22TQuestVmDownLoadServerFPv(Q_803EC09C *);

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline N_803EC09C *Default_803EC09C(s32 x) {
    N_803EC09C *n = (N_803EC09C *)TQuestVmDownLoadServer__sub_803ECED0();
    if (n != NULL) {
        n->flags = 0x80;
        n->text[0] = 0;
        n->x6 = x;
        n->x7 = 0;
        n->x8 = 0;
        n->xc = 0xFFFF;
        n->next = NULL;
    }
    return n;
}
inline N_803EC09C *Last_803EC09C(N_803EC09C *p) {
    if (p == NULL) {
        return NULL;
    }
    for (;;) {
        if (p->next == NULL) {
            break;
        }
        p = p->next;
    }
    return p;
}

void TQuestVmDownLoadServer__sub_803EC09C(void) {
    s32 idx;
    Ent_803EC09C *e;
    N_803EC09C *tail;
    N_803EC09C *head;
    Out_803EC09C *o;
    Q_803EC09C *qh;
    Q_803EC09C *q;
    Q_803EC09C *qt;
    N_803EC09C *r;
    N_803EC09C *n;

    if ((u32)(o = ((Ent_803EC09C *)quest_download_slot_chain_table)[quest_text_cursor_pos].list) == 0xFFFFFFFFU) {
        return;
    }
    qh = NULL;
    qt = NULL;
    for (; o != NULL; o = o->next) {
        if (o->off != quest_text_entry_len) {
            continue;
        }
        q = TQuestVmDownLoadServer__sub_803ECE94();
        if (q == NULL) {
            for (; qh != NULL; qh = qh->next) {
                TQuestVmDownLoadServer::push_download_entry((s32 *)qh->x8);
            }
            qh = NULL;
            break;
        }
        q->x8 = r = (N_803EC09C *)TQuestVmDownLoadServer__sub_803EBEFC((Arg_803EBEFC *)o);
        q->o = o;
        q->x4 = (r == NULL) ? 0 : TQuestVmDownLoadServer__sub_803ED0B4((u8 *)o, r->xe);
        q->next = NULL;
        if (qh == NULL) {
            qh = qt = q;
        } else {
            qt->next = q;
            qt = q;
        }
    }
    e = &((Ent_803EC09C *)quest_download_slot_chain_table)[idx = quest_text_cursor_pos];
    head = e->xc;
    tail = Last_803EC09C(head);
    TQuestVmDownLoadServer__sub_803EBA98(idx, (Node_803EBA98 *)head);
    while ((n = get_next_node__22TQuestVmDownLoadServerFPv(qh)) != NULL) {
        append_unique_node__22TQuestVmDownLoadServerFiPvPvPv(idx, (Node_803EB8BC **)&head, (Node_803EB8BC **)&tail, (Node_803EB8BC *)n);
    }
    if ((n = Default_803EC09C(quest_text_entry_len)) != NULL) {
        append_unique_node__22TQuestVmDownLoadServerFiPvPvPv(idx, (Node_803EB8BC **)&head, (Node_803EB8BC **)&tail, (Node_803EB8BC *)n);
    }
    e->xc = head;
    TQuestVmDownLoadServer__sub_803ECD1C((Node_803ECD1C *)qh);
}
#pragma pop

#pragma push
#pragma opt_dead_assignments off
#pragma dont_inline off
#pragma inline_depth(1)
inline N_803EC09C *Detach_803EBBBC(N_803EC09C *p) {
    N_803EC09C *next;
    while (p->flags & 1) {
        p = p->next;
    }
    next = p->next;
    p->next = NULL;
    return next;
}
N_803EC09C *get_next_node__22TQuestVmDownLoadServerFPv(Q_803EC09C *p) {
    Q_803EC09C *best = NULL;
    N_803EC09C *ret;
    u32 key;
    for (; p != NULL; p = p->next) {
        if (p->x8 != NULL && (best == NULL || p->x4 > key)) {
            best = p;
            key = p->x4;
        }
    }
    if (best == NULL) {
        return NULL;
    }
    ret = best->x8;
    best->x8 = Detach_803EBBBC(ret);
    best->x4 = best->x8 == NULL ? 0 : TQuestVmDownLoadServer__sub_803ED0B4((u8 *)best->o, best->x8->xe);
    return ret;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TQuestVmDownLoadServer__sub_803EC284(s32 pos, s32 mode) {
    Node_803EB420 *p;
    s32 n;
    if (mode == 1) {
        TQuestVmDownLoadServer__sub_803EC09C();
    }
    p = quest_download_slot_chain_table[quest_text_cursor_pos].chain;
    if (quest_download_state > 0) {
        lbl_805D78A4 = 0x50;
    } else {
        lbl_805D78A4 = TQuestVmDownLoadServer::get_buffer_size();
    }
    n = count_fitting_groups(p);
    while (pos >= n) {
        pos -= n;
        while (n-- != 0) {
            p = next_entry_group(p);
        }
        n = count_fitting_groups(p);
        if (n == 0) {
            TQuestVmDownLoadServer__sub_803EC284(0, 0);
            goto done;
        }
    }
    lbl_805D78A0 = p;
    quest_page_node_index = pos;
    quest_page_node_count = n;
done:
    if (mode == 1 && quest_download_state == 0) {
        TQuestVmDownLoadServer__sub_803EB4D4();
    }
}
#pragma pop

struct Tok_803EC460 { s16 x0; u8 x2; u8 x3; s32 x4; u16 x8; };
struct Out_803EC460 {
    s16 off; u8 a; u8 b;
    Tok_803EC460 *src;
    s16 x8; s16 xa;
    Out_803EC460 *next;
};
struct N_803EC460 {
    u8 flags;
    u8 text[5];
    u8 x6;
    u8 x7;
    s32 x8;
    u16 xc;
    u16 xe;
    N_803EC460 *next;
};
struct Ent_803EC460 {
    s32 x0;
    void *toks;
    Out_803EC460 *list;
    N_803EC460 *xc;
    u8 pad[0xC];
};

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline N_803EC460 *Default_803EC460(s32 x) {
    N_803EC460 *n = (N_803EC460 *)TQuestVmDownLoadServer__sub_803ECED0();
    if (n != NULL) {
        n->flags = 0x80;
        n->text[0] = 0;
        n->x6 = x;
        n->x7 = 0;
        n->x8 = 0;
        n->xc = 0xFFFF;
        n->next = NULL;
    }
    return n;
}

void TQuestVmDownLoadServer__sub_803EC460(s32 pos, s32 x) {
    N_803EC460 *first;
    N_803EC460 *tl;
    Ent_803EC460 *e;
    u8 *base;
    Out_803EC460 *o;
    Out_803EC460 *best;
    u16 bestv;
    u16 v;
    Tok_803EC460 *t;

    e = &((Ent_803EC460 *)quest_download_slot_chain_table)[pos];
    base = lbl_80596258;
    best = NULL;
    bestv = 0;
    if (e->xc != NULL) {
        return;
    }
    if ((u32)(o = e->list) == 0xFFFFFFFFU) {
def:
        e->xc = Default_803EC460(x);
        return;
    }
    for (; o != NULL; o = o->next) {
        if (o->off != x) {
            continue;
        }
        v = (o->src == NULL) ? 0 : TQuestVmDownLoadServer__sub_803ED0B4((u8 *)o, o->src->x8);
        if (v > bestv || best == NULL) {
            bestv = v;
            best = o;
        }
    }
    if (best == NULL || (t = best->src) == NULL || t->x0 == 0) {
        goto def;
    }
    if ((u32)t->x4 == 0xFFFFFFFFU) {
        if (t->x2 != 0x1F) {
            goto def;
        }
        if (TQuestVmDownLoadServer__sub_803EED0C((s32)&quest_download_scratch_storage + pos, t->x0, (s32)(base + 0xC)) > 0) {
            goto build;
        }
        goto def;
    } else {
        if (TQuestVmDownLoadServer__sub_803F0048(t->x4, t->x2, t->x3, base + 0xC) <= 0) {
            goto def;
        }
    }
build:
    e->xc = (N_803EC460 *)TQuestVmDownLoadServer::build_text_node_chain(base + 0xC, t, t->x0, &first, &tl);
}
#pragma pop

u16 TQuestVmDownLoadServer::jis_to_sjis(u16 arg0) {
    u8 lo;
    u8 hi;
    hi = arg0 >> 8;
    lo = arg0;
    if (arg0 < 0x2121 || arg0 > 0x7E7E) {
        return 0;
    }
    if (lo < 0x21 || lo >= 0x7F) {
        return 0;
    }
    lo += 0x1F;
    if (hi & 1) {
        hi >>= 1;
    } else {
        hi >>= 1;
        hi--;
        lo += 0x5E;
    }
    if (lo >= 0x7F) {
        lo++;
    }
    if (hi < 0x2F) {
        hi += 0x71;
    } else {
        hi += 0xB1;
    }
    return (hi << 8) | lo;
}

s32 TQuestVmDownLoadServer__sub_803EC69C(u32 arg0) {
    u8 hi;
    u32 lo;
    u32 tr;
    u8 ld;
    hi = ((u16)arg0) >> 8;
    lo = (u8)arg0;
    if (lo < 0x40 || lo > 0xFC || lo == 0x7F) {
        return 0;
    }
    if (hi >= 0xE0) {
        hi -= 0x40;
    }
    ld = ((hi - 0x81) << 1) + 0x21;
    tr = (u8)lo;
    if (tr >= 0x9F) {
        ld++;
        tr = lo - 0x7E;
    } else if (tr >= 0x80) {
        tr = lo - 0x20;
    } else {
        tr = lo - 0x1F;
    }
    return (ld << 8) | (u8)tr;
}

static inline s32 is_jis_byte(u8 c) {
    s32 r = 0;
    if (c >= 0x21 && c <= 0x7E) {
        r = 1;
    }
    return r;
}

static inline s32 is_jis_code(u16 code) {
    s32 ok = 0;
    u8 hi = code >> 8;
    u8 lo = code;
    if (is_jis_byte(hi) && is_jis_byte(lo)) {
        ok = 1;
    }
    return ok;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 TQuestVmDownLoadServer__sub_803EC71C(u16 *src, u8 *dst, s32 n) {
    u16 nib;
    u16 next;
    u16 code;
    u16 v;
    s32 i = 0;
    int hi;
    u8 *out = dst;
    u16 c;
    while (i < n) {
        c = (v = *src);
        nib = (v >> 8) & 0xF;
        if (nib == 0) {
            *out = (s8)c;
            src++;
            out++;
            i++;
            continue;
        }
        if ((nib & 1) == 0) {
            /* As in the game: src and i are not advanced, so this never exits. */
            continue;
        }
        next = *(++src);
        hi = (v & 0xFF) << 8;
        i++;
        if (((next >> 8) & 0xF) != (nib + 1)) {
            continue;
        }
        code = hi | (next & 0xFF);
        src++;
        i++;
        if (is_jis_code(code)) {
            code = TQuestVmDownLoadServer::jis_to_sjis(code);
        }
        out[0] = (s8)(code >> 8);
        out[1] = (s8)code;
        out += 2;
    }

    *out = 0;
    return out - dst;
}
#pragma pop

s32 TQuestVmDownLoadServer::is_valid_sjis_code(u16 arg0) {
    s32 var_r0;
    if ((arg0 >= 0x2120U) && (arg0 < 0x3020U)) {
        if ((s32) (arg0 & 0xFF00) == 0x2500) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        if (var_r0 != 0) {
            return 0;
        }
        return 1;
    }
    return 0;
}

s32 TQuestVmDownLoadServer__sub_803EC884(u16 arg0) {
    if (arg0 >= 0x3020U) {
        return 1;
    }
    return 0;
}

s32 TQuestVmDownLoadServer::is_download_command(u16 arg0, s32 arg1) {
    if ((arg1 != 0) && (arg0 == 0x213C)) {
        return 1;
    }
    if ((s32) (arg0 & 0xFF00) == 0x2500) {
        return 1;
    }
    return 0;
}

s32 TQuestVmDownLoadServer__sub_803EC8D8(u16 arg0) {
    s32 temp_r0;
    s32 var_r3;
    u16 var_r4;
    if ((arg0 > 0x20U) && (arg0 < 0x7FU)) {
        var_r3 = 0;
        return 0;
    }
    var_r4 = arg0;
    temp_r0 = arg0 & 0xFF00;
    switch (temp_r0) {
    case 0x2300:
        var_r3 = var_r4 & 0x7F;
        return var_r3;
    case 0x2400:
        var_r3 = (var_r4 & 0x7F) | 0x80;
        return var_r3;
    case 0x2500:
        var_r3 = 0;
        return 0;
    default:
        return TQuestVmDownLoadServer::lookup_value_by_key(arg0);
    }
}

s32 TQuestVmDownLoadServer__sub_803EC95C(u16 *out, const u8 *text, int attr) {
    u16 *dst = out;
    u8 c;
    while ((c = *text) != 0) {
        if (c < 0x80 || (c >= 0xA0 && c < 0xE0)) {
            dst += TQuestVmDownLoadServer::encode_char_with_attr(dst, *text++, attr);
        } else {
            u16 ch = (c << 8) | text[1];
            dst += TQuestVmDownLoadServer::encode_char_with_attr(dst, ch, attr);
            text += 2;
        }
    }
    return dst - out;
}

void TQuestVmDownLoadServer__sub_803ECA1C(u16 *arg0, s32 arg1, s32 arg2) {
    u16 a = arg2 << 12;
    while (arg1-- != 0) {
        *arg0 = (*arg0 & 0xFFF) | a;
        arg0++;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline s32 IsLead_803ECAE8(u32 c) {
  if (((c < 0x81) || (c > 0xFC)) || ((c >= 0xA0) && (c < 0xE0)))
  {
    return 0;
  }
  return 1;
}

inline s32 IsTrail_803ECAE8(u8 c) {
  if (((c < 0x40) || (c > 0xFC)) || (c == 0x7F))
  {
    return 0;
  }
  return 1;
}

inline s32 IsSjis_803ECAE8(s32 lo, s32 hi) {
  if (IsLead_803ECAE8(hi) == 0)
  {
    return 0;
  }
  return IsTrail_803ECAE8(lo);
}

inline s32 IsJis_803ECAE8(u8 c) {
  s32 r = 0;
  if ((c >= 0x21) && (c <= 0x7E))
  {
    r = 1;
  }
  return r;
}

inline s32 IsJisPair_803ECAE8(s32 lo, s32 hi) {
  s32 r = 0;
  if (IsJis_803ECAE8(hi) && IsJis_803ECAE8(lo))
  {
    r = 1;
  }
  return r;
}

inline s32 Kind_803ECAE8(u16 c, s32 lo) {
  switch (c & 0xFF00)
  {
    case 0x8000:

    case 0x8500:
      return 1;

    case 0x8600:
      if (lo < 0x9E)
    {
      return 1;
    }
      break;

  }

  return 2;
}

s32 TQuestVmDownLoadServer::encode_char_with_attr(u16 *out, u16 ch, s32 attr) {
  s32 hi;
  u16 c;
  s32 lo;
  int new_var;
  u16 a;
  c = ch;
  a = (attr & 0xF) << 12;
  new_var = ch & 0xFF;
  hi = (ch >> 8) & 0xFF;
  lo = new_var;
  if (IsSjis_803ECAE8(new_var, hi))
  {
    if (Kind_803ECAE8(c, new_var) == 1)
    {
      a |= 0x300;
    }
    else
    {
      a |= 0x700;
    }
  }
  else
    if (IsJisPair_803ECAE8(new_var, hi))
  {
    a |= 0x500;
    if (ch == 0x2474)
    {
      ch = 0x2574;
    }
  }
  else
  {
    *out = a | lo;
    return 1;
  }
  *(out++) = a | (ch >> 8);
  *out = (a + 0x100) | (ch & 0xFF);
  return 2;
}

#pragma pop

s32 TQuestVmDownLoadServer__sub_803ECC7C(u32 arg0) {
    u8 hi = (arg0 >> 8) & 0xFF;
    u8 lo = arg0;
    s32 lead;
    if (hi < 0x81 || hi > 0xFC || (hi >= 0xA0 && hi < 0xE0)) {
        lead = 0;
    } else {
        lead = 1;
    }
    if (lead == 0) {
        return 0;
    }
    if (lo < 0x40 || lo > 0xFC || lo == 0x7F) {
        return 0;
    }
    return 1;
}

s32 TQuestVmDownLoadServer::is_sjis_lead_byte(u8 arg0) {
    if ((arg0 < 0x81U) || (arg0 > 0xFCU) || ((arg0 >= 0xA0U) && (arg0 < 0xE0U))) {
        return 0;
    }
    return 1;
}

void TQuestVmDownLoadServer__sub_803ECD1C(Node_803ECD1C *p) {
    while (p != NULL) {
        Node_803ECD1C *next = p->next;
        if (p != NULL) {
            *(s32 *)p = (long)(*(s32 * *)&lbl_805D78B0);
            (*(s32 * *)&lbl_805D78B0) = (s32 *)p;
            lbl_805D78AC += 1;
        }
        p = next;
    }
}

void TQuestVmDownLoadServer::free_node_list() {
    Node_803ECD54 *p = (Node_803ECD54 *)this;
    while (p != NULL) {
        Node_803ECD54 *next = p->next;
        if (p != NULL) {
            *(s32 *)p = (long)(*(s32 * *)&lbl_805D78B0);
            (*(s32 * *)&lbl_805D78B0) = (s32 *)p;
            lbl_805D78AC += 1;
        }
        p = next;
    }
}

void TQuestVmDownLoadServer__sub_803ECD8C(Node_803ECD8C *p) {
    Node_803ECD8C *next;
    while (p != NULL) {
        next = p->next;
        if (p != NULL) {
            p->link = lbl_805D78B0;
            lbl_805D78B0 = (s32 *)p;
            lbl_805D78AC += 1;
        }
        p = next;
    }
}

void release_node_chain__22TQuestVmDownLoadServerFPv(Node_803ECDC4 *p) {
    u32 prev = 0xFFFFFFFF;
    Node_803ECDC4 *next;
    while (p != NULL) {
        next = p->next;
        if ((prev == 0xFFFFFFFF || p->id != prev) && p->id != 0xFFFFFFFF) {
            TQuestVmDownLoadServer__sub_803EED9C(p->id);
        }
        prev = p->id;
        if (p != NULL) {
            p->link = (*(s32 * *)&lbl_805D78B0);
            (*(s32 * *)&lbl_805D78B0) = (s32 *)p;
            lbl_805D78AC += 1;
        }
        p = next;
    }
}

void TQuestVmDownLoadServer__sub_803ECE5C(Node_803ECE5C *p) {
    Node_803ECE5C *next;
    while (p != NULL) {
        next = p->next;
        if (p != NULL) {
            p->link = lbl_805D78B0;
            lbl_805D78B0 = (s32 *)p;
            lbl_805D78AC += 1;
        }
        p = next;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 *pop_free_block() {
    s32 *p = lbl_805D78B0;
    if (p == NULL) {
        return NULL;
    }
    lbl_805D78B0 = (s32 *)*lbl_805D78B0;
    lbl_805D78AC--;
    return p;
}

Q_803EC09C *TQuestVmDownLoadServer__sub_803ECE94(void) {
    s32 *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    return (Q_803EC09C *)p;
}

void *TQuestVmDownLoadServer__sub_803ECED0(void) {
    s32 *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    return p;
}

void *TQuestVmDownLoadServer__sub_803ECF0C(void) {
    s32 *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    return p;
}

void *TQuestVmDownLoadServer__sub_803ECF48(void) {
    s32 *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    return p;
}

Node_803EA384 *TQuestVmDownLoadServer__sub_803ECF84(void) {
    s32 *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    return (Node_803EA384 *)p;
}
#pragma pop

void TQuestVmDownLoadServer::push_download_entry(s32 *arg0) {
    if (arg0 != NULL) {
        *arg0 = (long) (lbl_805D78B0);
        lbl_805D78B0 = arg0;
        lbl_805D78AC += 1;
    }
}

struct Blk_803ECFE4 { Blk_803ECFE4 *next; u8 pad[0x10]; };
Blk_803ECFE4 quest_download_block_pool[2000];
extern s32 quest_download_free_list_ready_flag;
void TQuestVmDownLoadServer::init_block_free_list() {
    Blk_803ECFE4 *p;
    if (quest_download_free_list_ready_flag == 0 && lbl_805D78AC == 2000) {
        return;
    }
    lbl_805D78B0 = (s32 *)quest_download_block_pool;
    for (p = quest_download_block_pool; p < &quest_download_block_pool[1999]; p++) {
        p->next = p + 1;
    }
    p->next = NULL;
    lbl_805D78AC = 2000;
    quest_download_free_list_ready_flag = 0;
}

u16 TQuestVmDownLoadServer__sub_803ED0B4(u8 *arg0, u16 arg1) {
    struct Fields_arg0 { u8 pad_0[8]; u16 field_8; };
    if (arg1 != 0) {
        return arg1 + 0x3E8;
    }
    return ((Fields_arg0*)arg0)->field_8;
}

struct Sub_803ED26C { s16 x0; u8 x2; };
struct Arg_803ED26C { s16 x0; u8 pad[2]; Sub_803ED26C *x4; };

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 InRange_803ED26C(u8 v) {
    s32 r = 0;
    if (v >= 1 && v <= 0xD) {
        r = 1;
    }
    return r;
}

s32 TQuestVmDownLoadServer::calc_item_cost_bonus(u8 kind, u8 v, u8 w, s32 base, s32 add) {
    s32 r = 0;
    switch (kind) {
    case 0:
        if ((v >= 0x14 && v <= 0x19) || v == 0x32) {
            r = 0xF;
        }
        break;
    case 1:
        if (v == 0x1A) {
            r = 0x14;
        }
        break;
    case 2:
        if ((u8)(v - 0x1B) <= 1) {
            r = 0xF;
        }
        break;
    case 3:
        if (v == 0x1F || v == 0x38) {
            r = 0x14;
        }
        break;
    case 4:
        if (v == 0x16) {
            r = 0x14;
        }
        break;
    case 5:
        if (w == 0xFF) {
            if (v >= 1 && v <= 0xD) {
                r = 0xF;
            }
        } else if ((v >= 0x80 && v <= 0x8B && w == 4) || (v == 0xD && w == 0)) {
            r = 0xF;
        }
        break;
    case 6:
        if (v >= 0x14 && v <= 0x19) {
            r = 0xF;
        } else if (v == 0x1F || v == 0x38) {
            r = 0x14;
        }
        break;
    case 7:
        if (v == 0x1D) {
            r = 0xF;
        }
        break;
    case 8:
        if ((v >= 0x14 && v <= 0x19) || (v >= 1 && v <= 0xD)) {
            r = 0x14;
        }
        break;
    }
    if (r == 0) {
        return base;
    }
    return base + r + add;
}

s32 TQuestVmDownLoadServer::calc_item_entry_cost(u8 k, u8 v, s32 base) {
    Arg_803ED26C *a = (Arg_803ED26C *)this;
    s32 lvl = 0;
    Sub_803ED26C *s = a->x4;

    if (s != NULL && ((s->x2 >= 0x14 && s->x2 <= 0x19) || s->x2 == 0x32)) {
        lvl = 1;
        if (s->x0 + 1 == a->x0) {
            lvl = 2;
        }
    }
    if (k == 0xC7) {
        if (InRange_803ED26C(v)) {
            return base + 0x1E;
        }
        return base + 0x19;
    }
    if (k == 0xC8) {
        if (v == 0) {
            return base;
        }
        if (lvl == 2) {
            return base + 0x14;
        }
        return base + 5;
    }
    if (k == 0xC1 || k == 0xE1) {
        if (lvl == 2) {
            base += 5;
        }
        return base;
    }
    if ((u8)(k - 0xC4) <= 1 || (k >= 0xCE && k <= 0xD1)) {
        if ((v >= 1 && v <= 0xD) || (v >= 0x16 && v <= 0x17)) {
            return base + 5;
        }
        return base;
    }
    if (k == 0xC2) {
        if (v == 0) {
            return base;
        }
        if (lvl == 2) {
            base += 3;
        }
        return base;
    }
    if (k >= 0xFC && k <= 0xFD && v >= 1 && v <= 0x17) {
        return base + 0x12;
    }
    if ((k == 0xFA || k == 0xFE) && v >= 0x14 && v <= 0x18) {
        return base + 0x12;
    }
    return base;
}
#pragma pop


s32 TQuestVmDownLoadServer::calc_pair_cost_bonus(u8 arg0, u8 arg1, s32 arg2) {
    if (arg0 >= 0x14 && arg0 <= 0x18) {
        if (arg1 >= 0x14 && arg1 <= 0x18) {
            return arg2 + 3;
        }
        return arg2;
    }
    if (arg0 == 0x1F && arg1 == 0x1F) {
        return arg2 + 0xF;
    }
    if (arg0 == 0x21 || arg0 == 0x26 || arg0 == 0x27) {
        return arg2 + 0x14;
    }
    if (arg0 == 0x20 || arg0 == 0x22) {
        return arg2 + 0xF;
    }
    if (arg0 == 0x1B && arg1 == 0x1C) {
        return arg2 + 0x14;
    }
    if (arg0 == 0x1A && arg1 == 0x1A) {
        return arg2 + 5;
    }
    return arg2;
}

s32 TQuestVmDownLoadServer::calc_item_entry_cost_extra(u8 arg0, u8 arg1, u8 arg2, s32 arg3) {
    if ((arg0 == 0xD) && (arg1 == 0)) {
        if ((arg2 >= 1U) && (arg2 <= 0x17U)) {
            return arg3 + 3;
        }
    } else if ((arg1 >= 4U) && (arg1 <= 6U) && (arg2 >= 1U) && (arg2 <= 0x17U)) {
        if ((arg0 == 0x8D) || ((arg0 == 0x8E) && (arg1 == 6))) {
            return arg3 + 0xA;
        }
        if (arg0 <= 0x8CU) {
            return arg3 + 3;
        }
    } else if ((arg1 == 8) && (arg2 >= 0x14U) && (arg2 <= 0x18U)) {
        if (((arg0 >= 0x80U) && (arg0 <= 0x8EU)) || (arg0 == 0x92) || (arg0 == 0x94) || (arg0 == 0xA0) || (arg0 == 0xA2) || ((u8)(arg0 - 0xAE) <= 1U) || (arg0 == 0xB1) || (arg0 == 1) || ((arg0 >= 0xAU) && (arg0 <= 0xCU))) {
            return arg3 + 0xF;
        }
        return arg3 + 3;
    }
    return arg3;
}

struct Sub_803ED63C { s16 x0; u8 x2; u8 x3; s32 x4; };
struct Arg_803ED63C { s16 x0; u8 x2; u8 x3; Sub_803ED63C *x4; };

s32 calc_entry_cost__22TQuestVmDownLoadServerFPvPv(Arg_803ED63C *a, Arg_803ED63C *b) {
    Sub_803ED63C *s2;
    u8 k;
    u8 bk;
    s32 extra;
    Sub_803ED63C *s;
    u8 q;
    u8 p;

    extra = 0;
    p = 0;
    q = 0;
    if ((k = a->x2) >= 0x2D && k <= 0x38) {
        p = a->x3;
    } else {
        q = a->x3;
    }
    if (b == NULL) {
        bk = 0;
    } else if ((s = b->x4) == NULL) {
        bk = 0;
    } else {
        if ((bk = s->x2) == 0x28) {
            return 0;
        }
        if (bk == 0x29 || (bk == 0x19 && s->x0 > 0) || (bk == 0x1F && (u32)s->x4 == 0xFFFFFFFFU)) {
            extra = 0x14;
        }
    }
    if ((s2 = a->x4) != NULL) {
        if (s2->x2 == 0x19 && s2->x0 == 0) {
            extra += 10;
        } else if (s2->x2 <= 0x19 || s2->x2 >= 0x1F) {
            extra += 1;
        }
    }
    if (q != 0 || k == 0xD) {
        return TQuestVmDownLoadServer::calc_item_entry_cost_extra(k, q, bk, extra);
    }
    if (k == 0x2D) {
        return TQuestVmDownLoadServer::calc_item_cost_bonus(p, bk, 0xFF, extra, 0);
    }
    if (bk >= 0x32 && bk <= 0x38) {
        if (b->x4 != NULL) {
            p = b->x4->x3;
        } else {
            p = 0;
        }
        return TQuestVmDownLoadServer::calc_item_cost_bonus(p, k, q, extra, 2);
    }
    if (k >= 0x14 && k < 0xC0) {
        return TQuestVmDownLoadServer::calc_pair_cost_bonus(k, bk, extra);
    }
    if (k >= 0xC0) {
        return ((TQuestVmDownLoadServer *)a)->calc_item_entry_cost(k, bk, extra);
    }
    return extra;
}

struct N_803ED7F0 { s16 a; u8 kind; u8 pad0; N_803ED7F0 *link; u8 pad1[2]; s16 timer; N_803ED7F0 *next; };
struct T_803ED7F0 { u8 pad[8]; N_803ED7F0 *head; u8 pad2[0x10]; };

#pragma push
#pragma opt_common_subs off
void TQuestVmDownLoadServer::reset_slot_chain_timers(s32 arg0) {
    N_803ED7F0 *n;
    N_803ED7F0 *l;
    T_803ED7F0 *t = &((T_803ED7F0 *)quest_download_slot_chain_table)[arg0];
    for (n = t->head; n != NULL; n = n->next) {
        n->timer = 0;
        l = n->link;
        if (l != NULL && l->kind == 0x19 && l->a == 0) {
            n->timer = 10;
        }
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline Elem_803ED9AC *slot_chain_head(s32 i) {
    return quest_download_slot_chain_table[i].head;
}
inline s32 is_special_entry(Elem_803ED9AC *e) {
    if (e->sub != NULL && (e->sub->type == 0x28 || e->sub->type == 0x29)) {
        return 1;
    }
    return 0;
}
inline s32 link_cost(Elem_803ED9AC *e, Elem_803ED9AC *q) {
    s32 a;
    s32 b;
    s32 c;
    if (q == NULL) {
        b = e->len;
        a = 0;
        c = 1;
    } else {
        a = e->len;
        c = 0;
        b = q->len;
    }
    return a * 16 + b * 17 + e->base + calc_entry_cost__22TQuestVmDownLoadServerFPvPv((Arg_803ED63C *)e, (Arg_803ED63C *)q) + c * 50;
}
s32 TQuestVmDownLoadServer__sub_803ED84C(Elem_803ED9AC *e, s32 idx, s32 max) {
    Elem_803ED9AC *q;
    u16 best;
    u16 v;
    s16 n;
    if (is_special_entry(e)) {
        e->cost = 0;
        return 0;
    }
    n = e->len;
    if (e->kind == 0xFF || idx + n >= max) {
        best = link_cost(e, NULL);
    } else {
        if ((q = slot_chain_head(idx + n)) == NULL && lbl_805D7888 >= 3) {
            return -1;
        }
        best = 0;
        for (; q != NULL; q = q->next) {
            v = link_cost(e, q);
            if (v > best) {
                best = v;
            }
        }
    }
    e->cost = best;
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs off

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline s32 IsSpecial_803ED9AC(Elem_803ED9AC *e) {
    if (e->sub != NULL && (e->sub->type == 0x28 || e->sub->type == 0x29)) {
        return 1;
    }
    return 0;
}
inline void Relax_803ED9AC(Elem_803ED9AC *best, s32 idx, s32 max) {
    Elem_803ED9AC *q;
    s32 v;
    s32 n = best->len;
    if (best->kind == 0xFF || idx + n >= max) {
        return;
    }
    q = quest_download_slot_chain_table[idx + n].head;
    if (q == NULL) {
        return;
    }
    for (; q != NULL; q = q->next) {
        q->base = 0;
        if (!IsSpecial_803ED9AC(q)) {
            v = calc_entry_cost__22TQuestVmDownLoadServerFPvPv((Arg_803ED63C *)best, (Arg_803ED63C *)q);
            if (v > 0) {
                q->base = v;
            }
        }
    }
}
s32 TQuestVmDownLoadServer::select_best_slot_entry(s32 idx, s32 max, s32 want) {
    Slot_803ED9AC *slot = &quest_download_slot_chain_table[idx];
    Elem_803ED9AC *e;
    Elem_803ED9AC *best;
    Elem_803ED9AC *q;
    for (e = slot->head; e != NULL; e = e->next) {
        if (want < 0 || e->len == want) {
            if (TQuestVmDownLoadServer__sub_803ED84C(e, idx, max) == -1) {
                return -1;
            }
        }
    }
    if (slot == NULL || slot->head == NULL) {
        return -1;
    }
    best = slot->head;
    for (q = best->next; q != NULL; q = q->next) {
        if (q->cost > best->cost) {
            best = q;
        }
    }
    Relax_803ED9AC(best, idx, max);
    return best->len;
}
#pragma pop
#pragma pop

s32 TQuestVmDownLoadServer__sub_803EDB20(u8 arg0) {
    return lbl_8047F8B8[arg0] & 0x20;
}

s32 TQuestVmDownLoadServer__sub_803EDB3C(u8 arg0) {
    return lbl_8047F8B8[arg0] & 0x40;
}

s32 TQuestVmDownLoadServer__sub_803EDB58(u8 arg0) {
    return lbl_8047F8B8[arg0] & 0x80;
}

s32 TQuestVmDownLoadServer__sub_803EDB74(u8 arg0) {
    return lbl_8047F8B8[arg0] & 0xC0;
}

s32 TQuestVmDownLoadServer::sum_entry_sizes(s32 start, s32 n) {
    Ent_803EDB90 *e = &((Ent_803EDB90 *)&quest_download_entry_table)[start];
    s32 sum = 0;
    s32 i;
    for (i = n; i > 0; i--) {
        sum += e->size;
        e++;
    }
    return sum;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 entry_text_width(Ent_803E6B70 *end) {
    Ent_803E6B70 *it;
    s32 width = 0;
    for (it = (Ent_803E6B70 *)&quest_download_entry_table; it < end; it++) {
        if (it->ch & 0xFF00) {
            width += 2;
        } else {
            width += 1;
        }
    }
    return width;
}
extern "C" s32 TQuestVmDownLoadServer__sub_803EDC20(u32 arg0) {
  s32 *rec = lbl_805D78C8;
  u8 *out = (u8 *) lbl_805D78BC;
  s32 cnt = quest_text_end;
  u8 *s = (u8 *) arg0;
  u32 pending = 0;
  s32 w;
  u16 TQuestVmDownLoadServer__sub_803EC69C(int);
  u16 code;
  w = entry_text_width((Ent_803E6B70 *)lbl_805D78C8);
  while ((*s) != 0)
  {
    if (((u16) pending) != 0)
    {
      pending = (((u16) pending) << 8) | (*s);
      code = TQuestVmDownLoadServer__sub_803EC69C(pending);
      if (code != 0)
      {
        if ((cnt >= 0x24) || (w >= 0x4e))
        {
          return -1;
        }
        *((u16 *) rec) = code;
        rec[1] = 2;
        rec += 2;
        *(out++) = TQuestVmDownLoadServer__sub_803EC8D8(code);
        cnt++;
        w += 2;
      }
      pending = 0;
    }
    else
      if (TQuestVmDownLoadServer::is_sjis_lead_byte(*s))
    {
      pending = *s;
    }
    else
      if ((((*s) >= 0x20) && ((*s) < 0x7F)) || (((*s) >= 0xA0) && ((*s) < 0xE0)))
    {
      if ((cnt >= 0x24) || (w >= 0x4F))
      {
        return -1;
      }
      *((u16 *) rec) = *s;
      rec[1] = 1;
      rec += 2;
      *(out++) = 0;
      cnt++;
      w += 1;
      pending = 0;
    }
    s++;
  }

  lbl_805D78C8 = rec;
  lbl_805D78C4 = rec;
  lbl_805D78BC = (s32 *) out;
  lbl_805D78B8 = (s32 *) out;
  quest_text_end = cnt;
  return cnt;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
// Upper-cases an ASCII letter (name inferred).
inline u8 ascii_to_upper(u8 c) {
    if (c >= 0x61U && c <= 0x7AU) {
        c -= 0x20;
    }
    return c;
}

// Looks up a one- or two-letter key: lbl_8047FBD4 holds, per initial
// letter, the first 11-byte row of lbl_8047F9B8 (second letter, then text).
const u8 *TQuestVmDownLoadServer__sub_803EDDA4(u16 *start, u16 *end) {
    s32 len;
    s32 c;
    s32 idx;
    s32 c2;
    const u8 (*const *grp)[11];
    const u8 (*row)[11];
    const u8 (*next)[11];
    len = end - start;
    if (len == 0) {
        return &lbl_8047F9B8[0][1];
    }
    if (len == 1 || len == 2) {
        c = start[0] & 0xFF;
        if (c >= 'a' && c <= 'z') {
            idx = c - 'a';
        } else if (c >= 'A' && c <= 'Z') {
            idx = c - 'A';
        } else {
            return NULL;
        }
        grp = &lbl_8047FBD4[idx];
        row = *grp;
        if (len == 1) {
            return &(*row)[1];
        }
        while ((next = *++grp) == NULL) {
        }
        c2 = ascii_to_upper(start[1] & 0xFF);
        for (row++; row < next; row++) {
            if ((*row)[0] == c2) {
                return &(*row)[1];
            }
        }
    }
    return NULL;
}
#pragma pop

u8 *TQuestVmDownLoadServer::find_keyword_entry(u16 *start, u16 *end) {
    u8 c;
    u8 *p;
    u16 *s;
    s32 rem;
    s32 len;
    s32 n;
    len = end - start;
    p = quest_download_keyword_table;
    while (*p != 0) {
        n = *p++;
        if (len == n) {
            s = start;
            for (rem = len; rem > 0;) {
                c = *s++;
                if (c >= 0x61U && c <= 0x7AU) {
                    c -= 0x20;
                }
                if (*p != c) {
                    break;
                }
                rem--;
                p++;
            }
            if (rem == 0) {
                return p;
            }
            p += rem;
        } else {
            p += n;
        }
        while (*p++ != 0) {
        }
    }
    return NULL;
}

extern s32 lbl_805D78E4;

// Converts the romaji at src (n characters left) to kana in out; *count gets the
// number of characters written. Returns the number consumed, 0 when more input
// is needed, -1/-2 on no match (behaviour inferred).
s32 TQuestVmDownLoadServer__sub_803EDF64(u16 *src, s32 n, u16 *out, s32 *count) {
    const u8 *e;
    u16 *p;
    u8 kind;
    s32 len;
    u16 mode;
    s32 c;
    u8 c2;
    kind = lbl_8047F8B8[src[0] & 0xFF] & 0xF;
    *count = 1;
    if (kind <= 9) {
        if (kind <= 5) {
            len = 1;
            p = src;
            e = &lbl_8047F9B8[0][1];
            goto vowel;
        }
        if (kind <= 8 || lbl_805D78E4 == 0) {
            out[0] = TQuestVmDownLoadServer__sub_803E721C(src[0]);
        } else {
            out[0] = TQuestVmDownLoadServer::map_key_to_code(src[0]);
        }
        return 1;
    } else {
        mode = 0;
        if (kind <= 12) {
            if (kind == 12) {
                out[0] = TQuestVmDownLoadServer__sub_803E719C('s', src[0]);
                mode = 1;
            } else {
                out[0] = TQuestVmDownLoadServer__sub_803E721C(src[0]);
                if (kind == 10) {
                    mode = 2;
                } else {
                    mode = 3;
                }
            }
        }
        if (n == 1) {
            if (mode != 0) {
                return -1;
            }
            return 0;
        }
        c2 = src[1];
        p = src + 1;
        c = src[0] & 0xFF;
        if (c == (src[1] & 0xFF)) {
            if (kind == 12) {
                return 2;
            }
            if (kind == 13) {
                out[0] = TQuestVmDownLoadServer__sub_803E719C('C', *p);
                return 1;
            }
        }
        if ((c == 'x' || c == 'X') && (c2 == 'n' || c2 == 'N')) {
            out[0] = TQuestVmDownLoadServer__sub_803E719C('s', src[0]);
            return 2;
        }
        if (mode == 1 && c2 == '\'') {
            return 2;
        }
        kind = lbl_8047F8B8[c2] & 0xF;
        if (kind == 7 && mode == 3) {
            out[0] += 2;
            return 2;
        }
        if (kind == 6 && mode >= 2) {
            out[0] += 1;
            if ((src[0] & 0xFF) == 0xB3) {
                out[0] = TQuestVmDownLoadServer__sub_803E719C('t', *p);
            }
            return 2;
        }
        if (mode >= 2 || (kind > 5 && kind <= 14 && mode == 1)) {
            return 1;
        }
        len = 2;
        for (;;) {
            if (kind <= 5) {
                e = TQuestVmDownLoadServer::find_keyword_entry(src, p + 1);
                if (e == NULL) {
                    e = TQuestVmDownLoadServer__sub_803EDDA4(src, p);
                    if (e == NULL) {
                        return -2;
                    }
                vowel:
                    e += (kind - 1) * 2;
                }
                *out++ = TQuestVmDownLoadServer__sub_803E719C(*e++, *p);
                if (*e != 0) {
                    *out = TQuestVmDownLoadServer__sub_803E719C(*e, *p);
                    *count = 2;
                }
                return len;
            }
            if (len++ >= n) {
                break;
            }
            p++;
            kind = lbl_8047F8B8[*p & 0xFF] & 0xF;
            if ((kind >= 6 && kind <= 12) || len > 4) {
                return -2;
            }
        }
    }
    return 0;
}

void TQuestVmDownLoadServer__sub_803EE2E4(void) {
    lbl_8058DC98[0] = 0;
}

extern u8 lbl_8058DC48[0x50];
void TQuestVmDownLoadServer__sub_803EE580(s32 pos, s32 len, Node_803EB420 *node, Elem_803ED9AC *link);

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
// Copies the entry text at pos to dst and converts it to text (name inferred).
inline void copy_entry_text(u8 *dst, u8 *text, s32 pos, s32 len, Node_803EB420 *node) {
    strncpy((char *)dst, (char *)&quest_download_scratch_storage + pos, len);
    dst[len] = 0;
    if (len != strlen((char *)dst)) {
        lbl_8058DC98[0] = 0;
    } else {
        TQuestVmDownLoadServer__sub_803EC71C(lbl_805A0340, text, TQuestVmDownLoadServer__sub_803EB420(pos, len, node, lbl_805A0340));
    }
}

void TQuestVmDownLoadServer__sub_803EE2F4(s32 pos, s32 end) {
    Req_803EEF2C req;
    Slot_803ED9AC *slot;
    Node_803EB420 *node;
    u8 *name;
    u8 *text;
    s32 len;
    s64 name_len;
    Sub_803ED9AC *sub;
    s32 n;
    while (pos < end && (n = TQuestVmDownLoadServer__sub_803E9F54(pos)) != 0) {
        slot = &quest_download_slot_chain_table[pos];
        if (pos == quest_text_cursor_pos && (lbl_805D78E8 == 1 || quest_download_state >= 3)) {
            node = advance_nodes__22TQuestVmDownLoadServerFPvi(lbl_805D78A0, quest_page_node_index);
        } else {
            node = advance_nodes__22TQuestVmDownLoadServerFPvi(slot->chain, 0);
        }
        if (lbl_805D7848 != 3 && quest_download_state <= 2) {
        plain:
            TQuestVmDownLoadServer__sub_803EE580(pos, n, node, slot->head);
            pos += n;
            continue;
        }
        if (slot->x16 != 0 && slot->x16 != slot->x15) {
            name = lbl_8058DC98;
            text = lbl_8058DC48;
            len = n;
            copy_entry_text(name, text, pos, len, node);
            TQuestVmDownLoadServer__sub_803EE580(pos, n, node, slot->head);
        } else {
            if (lbl_8058DC98[0] == 0) {
                goto plain;
            }
            name = lbl_8058DC98 + strlen((char *)lbl_8058DC98);
            text = lbl_8058DC48 + strlen((char *)lbl_8058DC48);
            len = node->len;
            copy_entry_text(name, text, pos, len, node);
            if (lbl_8058DC98[0] != 0) {
                req.name = (char *)lbl_8058DC98;
                name_len = strlen((char *)lbl_8058DC98);
                req.len = name_len;
                req.pad6 = 0;
                if (node == NULL || (sub = node->sub) == NULL) {
                    req.x7 = 0x28;
                    req.x8 = 0;
                } else {
                    req.x7 = sub->type;
                    req.x8 = sub->x3;
                }
                req.text = lbl_8058DC48;
                TQuestVmDownLoadServer__sub_803EEF2C(&req);
            }
            lbl_8058DC98[0] = 0;
        }
        pos += n;
    }
}
#pragma pop

extern u8 lbl_8058DCE8[];
extern u8 lbl_8058DD38[];
extern u8 lbl_805A0698[];
s32 TQuestVmDownLoadServer__sub_803EEDC0(Req_803EEF2C *req, s32 *ids, s32 n);
s32 TQuestVmDownLoadServer__sub_803EF958(u32 id, u16 key, s32 *ids, s32 n);

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)

extern u8 quest_request_text_buffer[];

#pragma push
#pragma optimization_level 2
void TQuestVmDownLoadServer__sub_803EE580(s32 a, s32 b, Node_803EB420 *cmdp, Elem_803ED9AC *listp) {
  Elem_803ED9AC *list = (Elem_803ED9AC *) listp;
  s32 *buf;
  Req_803EEF2C *obj = (0, (Req_803EEF2C *) lbl_805A0698);
  Node_803EB420 *cmd = (Node_803EB420 *) cmdp;
  Sub_803ED9AC *p;
  s32 r;
  Node_803EB420 *q2;
  u32 prev;
  Req_803EEF2C *new_var;
  s32 pad;
  s32 *pp = &pad;
  q2 = cmd;
  if (q2->key == (-1))
  {
    p = 0;
  }
  else
  {
    if ((p = cmd->sub) == 0)
    {
      return;
    }
  }
  buf = (s32 *) quest_download_text_buffer;
  if ((list == 0) || (list == ((Elem_803ED9AC *) (-1))))
  {
    if (p)
    {
      *(buf++) = p->id;
    }
  }
  else
  {
    prev = -1;
    do
    {
      Sub_803ED9AC *item = list->sub;
      if (((item != 0) && (((u32) item->id) != 0xFFFFFFFF)) && (((u32) item->id) != prev))
      {
        prev = item->id;
        *(buf++) = prev;
      }
      list = list->next;
    }
    while (list != 0);
  }
  if (p == 0)
  {
    strncpy((char *) quest_request_text_buffer, ((char *) (&quest_download_scratch_storage)) + a, b);
    quest_request_text_buffer[b] = 0;
    r = TQuestVmDownLoadServer__sub_803EB420(a, b, cmd, lbl_805A0340);
    TQuestVmDownLoadServer__sub_803EC71C(lbl_805A0340, lbl_8058DCE8, r);
    obj->name = (char *) quest_request_text_buffer;
    obj->len = (s16) b;
    obj->pad6 = 0;
    obj->x7 = 0x19;
    obj->x8 = 0;
    new_var = (Req_803EEF2C *) obj;
    obj->text = lbl_8058DCE8;
    TQuestVmDownLoadServer__sub_803EEDC0(new_var, (s32 *) quest_download_text_buffer, buf - ((0, (s32 *) quest_download_text_buffer)));
  }
  else
  {
    TQuestVmDownLoadServer__sub_803EF958(p->id, cmd->key, (s32 *) quest_download_text_buffer, buf - ((s32 *) quest_download_text_buffer));
  }
}
#pragma pop
#pragma pop

u16 *TQuestVmDownLoadServer__sub_803EE718(s32 i, s32 len) {
    u16 *out;
    s32 n;
    s32 end;
    s32 r;
    Node_803EB420 *node;
    out = lbl_805A0340;
    end = i + len;
    while (i < end && (n = TQuestVmDownLoadServer__sub_803E9F54(i)) != 0) {
        if (i == quest_text_cursor_pos) {
            if (lbl_805D78E8 == 1 || quest_download_state >= 3) {
                node = advance_nodes__22TQuestVmDownLoadServerFPvi(lbl_805D78A0, quest_page_node_index);
            } else {
                node = advance_nodes__22TQuestVmDownLoadServerFPvi(*(Node_803EB420 **)((s8 *)((u8 *)quest_download_slot_chain_table + i * 0x1C) + 0xC), 0);
            }
            r = TQuestVmDownLoadServer__sub_803EB420(i, n, node, out);
        } else {
            r = TQuestVmDownLoadServer__sub_803EB420(i, n, *(Node_803EB420 **)((s8 *)((u8 *)quest_download_slot_chain_table + i * 0x1C) + 0xC), out);
        }
        out += r;
        i += n;
    }
    TQuestVmDownLoadServer__sub_803EC71C((u16 *)lbl_805A0340, (u8 *)lbl_805A02A8, (s32)(out - lbl_805A0340));
    return lbl_805A02A8;
}

u8 *TQuestVmDownLoadServer__sub_803EE828(void) {
    TQuestVmDownLoadServer__sub_803EC71C((u16 *)(((u8 *)&lbl_805A0340)), (u8 *)(((u8 *)&lbl_805A02A8)), (s32)(TQuestVmDownLoadServer__sub_803EE934()));
    return ((u8 *)&lbl_805A02A8);
}

// Drops the node chain of a slot; in mode 1 the nodes before the current
// position are first returned to the download entry pool.
void TQuestVmDownLoadServer__sub_803EE870(s32 slot, s32 mode) {
    Node_803EB420 *p;
    Node_803EB420 *end;
    Node_803EB420 *next;
    if ((p = quest_download_slot_chain_table[slot].chain) != NULL) {
        if (mode == 1 && (lbl_805D78E8 == 1 || quest_download_state >= 3)) {
            end = advance_nodes__22TQuestVmDownLoadServerFPvi(lbl_805D78A0, quest_page_node_index);
            while (p != NULL) {
                if (p == end) {
                    break;
                }
                next = (Node_803EB420 *)TQuestVmDownLoadServer__sub_803EB878((Node_803EB878 *)p);
                TQuestVmDownLoadServer::push_download_entry((s32 *)p);
                p = next;
            }
            quest_download_slot_chain_table[slot].chain = p;
        }
        ((TQuestVmDownLoadServer *)detach_node_chain__22TQuestVmDownLoadServerFPv((Node_803EB894 *)p))->free_node_list();
    }
}

s32 TQuestVmDownLoadServer__sub_803EE934(void) {
    s32 r;
    Node_803EB420 *node;
    u16 *out;
    s32 total;
    s32 i;
    s32 n;
    out = lbl_805A0340;
    i = 0;
    total = 0;
    while ((n = TQuestVmDownLoadServer__sub_803E9F54(i)) != 0) {
        if (i == quest_text_cursor_pos) {
            if (lbl_805D78E8 == 1 || quest_download_state >= 3) {
                node = advance_nodes__22TQuestVmDownLoadServerFPvi(lbl_805D78A0, quest_page_node_index);
            } else {
                node = advance_nodes__22TQuestVmDownLoadServerFPvi(*(Node_803EB420 **)((s8 *)((u8 *)quest_download_slot_chain_table + i * 0x1C) + 0xC), 0);
            }
            r = TQuestVmDownLoadServer__sub_803EB420(i, n, node, out);
            quest_text_entry_len = n;
            TQuestVmDownLoadServer__sub_803ECA1C(out, r, 7);
        } else {
            r = TQuestVmDownLoadServer__sub_803EB420(i, n, *(Node_803EB420 **)((s8 *)((u8 *)quest_download_slot_chain_table + i * 0x1C) + 0xC), out);
            TQuestVmDownLoadServer__sub_803ECA1C(out, r, 6);
        }
        out += r;
        i += n;
        total += r;
    }
    return total;
}

s32 TQuestVmDownLoadServer__sub_803EEA48(s32 arg0, s32 arg1, void *arg2, s32 *arg3) {
    s32 i;
    void *r;
    if (lbl_805D7904 == -1) {
        return -3;
    }
    *arg3 = 0;
    r = format_number_text__22TQuestVmDownLoadServerFiiPvi(arg0, arg1, arg2, lbl_805D78FC);
    if (r != 0) {
        arg2 = r;
        (*arg3)++;
    }
    for (i = 0; i < 4; i++) {
        if (i != lbl_805D78FC) {
            r = format_number_text__22TQuestVmDownLoadServerFiiPvi(arg0, arg1, arg2, i);
            if (r != 0) {
                arg2 = r;
                (*arg3)++;
            }
        }
    }
    return 1;
}

struct Tbl_803EEB10 {
    u8 units[0x14];
    u8 fullwidth_digits[0x18];
    u8 kanji_digits[0x18];
    u8 *sets[2];
    u8 *units_text;
};
struct Out_803EEB10 {
    u16 mode;
    s16 x2;
    u8 x4;
    u8 text[1];
};
extern Tbl_803EEB10 quest_download_number_text_table;

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 IsSmall_803EEB10(s32 d) {
    s32 r = 0;
    if (d >= 1 && d <= 3) {
        r = 1;
    }
    return r;
}

#define n ((s16)arg1)
void *format_number_text__22TQuestVmDownLoadServerFiiPvi(s32 arg0, s32 arg1, void *arg2, s32 mode) {
    u8 *s = (u8 *)arg0;
    Out_803EEB10 *o = (Out_803EEB10 *)arg2;
    Tbl_803EEB10 *t = &quest_download_number_text_table;
    s32 u;
    u8 **mp;
    u8 **up;
    u8 *p;
    u8 *mark;
    s32 i;
    s32 pos;
    s32 d;
    s32 rem;
    s32 set;

    if (mode >= 2 && n > 0xD) {
        return NULL;
    }
    o->mode = mode;
    o->x2 = 0;
    o->x4 = 0;
    p = o->text;
    mp = (u8 **)((u8 *)t->sets + mode * 4);
    mark = p;
    up = &t->units_text;
    for (i = 0; i < n; i++, s++) {
        d = *s - '0';
        if (mode < 2) {
            *p++ = (*mp)[d * 2];
            *p++ = (*mp)[d * 2 + 1];
            continue;
        }
        rem = n - i - 1;
        pos = rem % 4;
        if (d != 0 && !(mode == 2 && d == 1 && (u32)(pos - 1) <= 1)) {
            set = IsSmall_803EEB10(d) ? mode - 1 : 1;
            *p++ = (*(u8 **)((u8 *)t->sets + set * 4))[d * 2];
            *p++ = (*(u8 **)((u8 *)t->sets + set * 4))[d * 2 + 1];
        }
        if (rem == 0) {
            continue;
        }
        if (pos == 0 && mark == p) {
            continue;
        }
        if (pos != 0 && d == 0) {
            continue;
        }
        if (pos == 0) {
            u = rem / 4 + 6;
        } else if (pos == 1) {
            if (mode == 2) {
                u = 4;
            } else {
                u = 0;
            }
        } else {
            u = pos + 3;
        }
        *p++ = (*up)[u * 2];
        *p++ = (*up)[u * 2 + 1];
        if (pos == 0) {
            mark = p;
        }
    }
    if (p == o->text) {
        return NULL;
    }
    *p = 0;
    return p + 1;
}
#undef n
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs off
inline u32 Call_803EED0C(s32 a, s32 b, s32 c, s32 d) {
    return ((u32)format_number_text__22TQuestVmDownLoadServerFiiPvi((s32)a, (s32)b, (void *)c, (s32)d));
}
s32 TQuestVmDownLoadServer__sub_803EED0C(s32 arg0, s32 arg1, s32 arg2) {
    if (lbl_805D7904 == -1) {
        return -3;
    }
    if (Call_803EED0C(arg0, arg1, arg2, lbl_805D78FC) == 0) {
        Call_803EED0C(arg0, arg1, arg2, 0);
    }
    return 1;
}
#pragma pop

s32 TQuestVmDownLoadServer::get_download_state() {
    return lbl_805D7900;
}

s32 TQuestVmDownLoadServer__sub_803EED9C(u32 arg0) {
    TQuestVmDownLoadServer::release_ref_slot(arg0);
    return 3;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline void release_index_entries(s32 *ids, s32 n) {
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    for (i = 0; i < n; i++) {
        s32 page = TQuestVmDownLoadServer__sub_803E779C(ids[i], &a, &b, &c);
        if (page != -1) {
            if (a != -1) {
                TQuestVmDownLoadServer__sub_803EF8E0(get_cached_page__22TQuestVmDownLoadServerFi(page) + a);
                TQuestVmDownLoadServer::set_active();
            }
            if (b != -1) {
                TQuestVmDownLoadServer__sub_803EF8E0(TQuestVmDownLoadServer::get_buffer_ptr(b));
                TQuestVmDownLoadServer__sub_803E8918();
            }
        }
    }
}
inline s32 is_digit_string(u8 *s) {
    for (; *s != 0; s++) {
        if (*s < 0x30 || *s > 0x39) {
            return 0;
        }
    }
    return 1;
}
s32 TQuestVmDownLoadServer__sub_803EEDC0(Req_803EEF2C *req, s32 *ids, s32 n) {
    char buf[0x50];
    s32 v;
    if (lbl_805D7900 == 0) {
        return 3;
    }
    if (lbl_805D7904 == -1) {
        return -3;
    }
    strncpy(buf, req->name, req->len);
    buf[req->len] = 0;
    if (is_digit_string((u8 *)buf)) {
        req->x7 = 0x1F;
    }
    v = ((TQuestVmDownLoadServer *)ids)->get_max_size_of_indices(n) + 1;
    if (v == 0xFF) {
        release_index_entries(ids, n);
        v = 1;
    }
    TQuestVmDownLoadServer__sub_803E8DA0(buf, req, v);
    TQuestVmDownLoadServer::set_slot_values_for_indices(ids, n, v);
    return 3;
}
#pragma pop

s32 TQuestVmDownLoadServer__sub_803EEF2C(Req_803EEF2C *arg0) {
    char buf[0x50];
    if (lbl_805D7900 == 0) {
        return 3;
    }
    if (lbl_805D7904 == -1) {
        return -3;
    }
    strncpy(buf, arg0->name, arg0->len);
    if (arg0->x7 == 0x28 || arg0->x7 == 0x29) {
        arg0->x7 = 0x27;
    }
    buf[arg0->len] = 0;
    TQuestVmDownLoadServer__sub_803E8DA0(buf, arg0, 1);
    return 3;
}

inline u8 *skip_entry_text(u8 *p, u8 *end) {
    for (; p < end; p += 2) {
        if (*p <= 0x38) {
            break;
        }
    }
    return p;
}

inline void shift_bytes(u8 *p, u8 *end, s32 delta) {
    u8 *s;
    if (delta > 0) {
        for (s = end - 1; p <= s; s--) {
            s[delta] = *s;
        }
    } else if (delta < 0) {
        for (; p < end; p++) {
            p[delta] = *p;
        }
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
s32 TQuestVmDownLoadServer__sub_803EEFC8(u8 *rec, Req_803EEF2C *msg) {
    s32 len;
    s32 size;
    u8 *data;
    u8 *end;
    u8 *start;
    u8 *text;
    s32 d;
    s32 n;
    u8 buf[0x80];
    TQuestVmDownLoadServer::copy_sjis_string(msg->text, buf);
    len = TQuestVmDownLoadServer::calc_sjis_string_width(msg->text);
    buf[len] = 0;
    data = rec;
    size = (u16)(rec[0] + (rec[1] << 8));
    end = rec + size;
    rec = rec + 3 + rec[2];
    while ((start = rec) < end) {
        rec += 2;
        if (*rec <= 0xB) {
            rec++;
        }
        text = rec;
        rec = skip_entry_text(rec, end);
        n = rec - text;
        if (start[0] == msg->x7 && n == len && strncmp((char *)text, (char *)buf, n) == 0) {
            break;
        }
    }
    d = rec - start;
    if (d > 0) {
        if (start == data + 3 + data[2] && rec == end) {
            return -1;
        }
        shift_bytes(rec, end, -d);
        data[0] = (size - d) % 256;
        data[1] = (size - d) / 256;
    }
    return d;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline void shift_tail_bytes(u8 *p, u8 *end, s32 delta) {
    if (delta > 0) {
        for (end--; p <= end; end--) {
            end[delta] = *end;
        }
    } else if (delta < 0) {
        for (; p < end; p++) {
            p[delta] = *p;
        }
    }
}

inline s32 max_entry_index(u8 *rec) {
    s32 max = 0;
    u8 *end = rec + (u16)(rec[0] + (rec[1] << 8));
    u8 *p = rec + 3 + rec[2];
    while (p < end) {
        if (max < p[1]) {
            max = p[1];
        }
        p += 2;
        if (*p <= 0xB) {
            p++;
        }
        p = skip_entry_text(p, end);
    }
    return max;
}

// Size of a page record: little-endian u16 at its start (name inferred).
inline u16 record_size(u8 *p) {
    return p[0] + (p[1] << 8);
}

s32 TQuestVmDownLoadServer__sub_803EF208(Req_803EEF2C *msg) {
    u8 *end;
    u8 *p;
    s32 not_found = 1;
    u8 n;
    s32 c;
    s32 size;
    char buf[0x50];
    if (lbl_805D7904 == -1) {
        return -3;
    }
    if (lbl_805D78F8 == 0x8000) {
        return -6;
    }
    strncpy(buf, msg->name, msg->len);
    buf[msg->len] = 0;
    p = get_cached_page__22TQuestVmDownLoadServerFi(((TQuestVmDownLoadServer *)buf)->find_name_index());
    for (end = p; (size = (u16)(end[0] + (end[1] << 8))) != 0; end += size) {
    }
    for (; p < end; p += record_size(p)) {
        n = p[2];
        c = strncmp((const char *)(p + 3), buf, (s16)n);
        if (c == 0) {
            if ((s16)n == msg->len) {
                not_found = 0;
                break;
            }
        } else if (c > 0) {
            break;
        }
    }
    if (not_found) {
        return 0;
    }
    c = TQuestVmDownLoadServer__sub_803EEFC8(p, msg);
    if (c == 0) {
        return 0;
    }
    if (c == -1) {
        shift_tail_bytes(p + (u16)(p[0] + (p[1] << 8)), end + 2, -(u16)(p[0] + (p[1] << 8)));
    } else {
        shift_tail_bytes(p + (u16)(p[0] + (p[1] << 8)) + c, end + 2, -c);
    }
    TQuestVmDownLoadServer__sub_803E79AC();
    TQuestVmDownLoadServer::set_active();
    return 3;
}

s32 TQuestVmDownLoadServer__sub_803EF538(Msg_803E9190 *msg) {
    u8 *end;
    u8 *page;
    u8 *p;
    s32 is_new = 1;
    u8 n;
    s32 c;
    s32 len;
    s32 size;
    char buf[0x50];
    if (lbl_805D7904 == -1) {
        return -3;
    }
    if (lbl_805D78F8 == 0x8000) {
        return -6;
    }
    strncpy(buf, msg->name, msg->len);
    buf[msg->len] = 0;
    page = get_cached_page__22TQuestVmDownLoadServerFi(((TQuestVmDownLoadServer *)buf)->find_name_index());
    for (end = page; (size = (u16)(end[0] + (end[1] << 8))) != 0; end += size) {
    }
    for (p = page; p < end; p += (u16)(p[0] + (p[1] << 8))) {
        n = p[2];
        c = strncmp((const char *)(p + 3), buf, (s16)n);
        if (c == 0) {
            if ((s16)n == msg->len) {
                is_new = 0;
                break;
            }
        } else if (c > 0) {
            break;
        }
    }
    len = is_new ? ((TQuestVmDownLoadServer *)msg)->calc_message_length() : ((TQuestVmDownLoadServer *)msg)->calc_text_length();
    if (end > page + 0x3FE - len) {
        return -5;
    }
    if (is_new) {
        shift_tail_bytes(p, end + 2, len);
        build_message_packet__22TQuestVmDownLoadServerFPviPvUc(p, len, msg, 0);
        if (msg->len <= 2) {
            TQuestVmDownLoadServer__sub_803E7F9C((u8 *)buf, msg->len);
        }
    } else {
        shift_tail_bytes(p + (u16)(p[0] + (p[1] << 8)), end + 2, len);
        append_message_text__22TQuestVmDownLoadServerFPviPvUc(p, len, (Msg_803E90A8 *)msg, max_entry_index(p) + 1);
    }
    TQuestVmDownLoadServer__sub_803E79AC();
    TQuestVmDownLoadServer::set_active();
    return 3;
}
#pragma pop

void TQuestVmDownLoadServer__sub_803EF8E0(u8 *p) {
    u8 *end = p + (u16)(p[0] + (p[1] << 8));
    p = p + 3 + p[2];
    while (p < end) {
        p[1] = 0;
        p += 2;
        if (*p <= 0xB) {
            p++;
        }
        for (; p < end; p += 2) {
            if (*p <= 0x38) {
                break;
            }
        }
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
s32 TQuestVmDownLoadServer__sub_803EF958(u32 id, u16 key, s32 *ids, s32 n) {
    s32 page;
    u8 *base;
    u8 *p;
    u16 off;
    if (lbl_805D7900 == 0) {
        return 3;
    }
    if (lbl_805D7904 == -1) {
        return -3;
    }
    if (id == 0xFFFFFFFF && key <= 3) {
        lbl_805D78FC = key;
        release_index_entries(ids, n);
        TQuestVmDownLoadServer::set_slot_values_for_indices(ids, n, 0);
        return 3;
    }
    {
        s32 a;
        s32 b;
        s32 v;
        page = TQuestVmDownLoadServer__sub_803E779C(id, &a, &b, &v);
        if (page == -1) {
            return 0;
        }
        off = key;
        if (key & 0x8000) {
            if (b == -1) {
                return 0;
            }
            base = TQuestVmDownLoadServer::get_buffer_ptr(b);
        } else {
            if (a == -1) {
                return 0;
            }
            base = get_cached_page__22TQuestVmDownLoadServerFi(page) + a;
        }
        v = ((TQuestVmDownLoadServer *)ids)->get_max_size_of_indices(n);
        p = base + (off & ~0x8000) + 1;
        if (*p != 0 && *p == v) {
            if (key & 0x8000) {
                TQuestVmDownLoadServer__sub_803E8924(b);
                TQuestVmDownLoadServer__sub_803E8918();
            }
            return 3;
        }
        if (++v == 0xFF) {
            release_index_entries(ids, n);
            v = 1;
        }
        *p = v;
        if (key & 0x8000) {
            TQuestVmDownLoadServer__sub_803E8924(b);
            TQuestVmDownLoadServer__sub_803E8918();
        } else {
            TQuestVmDownLoadServer::set_active();
        }
        TQuestVmDownLoadServer::set_slot_values_for_indices(ids, n, v);
        return 3;
    }
}
#pragma pop

u8 *TQuestVmDownLoadServer::find_insert_position(s32 key, s32 n, s32 len) {
    u8 *p = (u8 *)this;
    u8 *end = p + len;
    u8 *s;
    u8 *d;
    while (p < end) {
        if (*(u16 *)(p + 2) < key) {
            break;
        }
        p += 5;
        while (*p++ != 0) {
        }
        if ((u32)p & 1) {
            p++;
        }
    }
    if (p < end) {
        for (s = end - 1; s >= p; s--) {
            s[n] = *s;
        }
    }
    return p;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
void TQuestVmDownLoadServer__sub_803EFCB4(u8 *data, s32 key, s32 sub_key, s32 *cnt, s32 *total, u8 *buf, s32 flags) {
    u8 *p;
    u8 *end;
    u8 *rec;
    s32 size;
    u8 *text;
    Src_803EBD38 *out;
    s32 sub;
    s32 value;
    u8 unused[8];
    end = data + (u16)(data[0] + (data[1] << 8));
    p = data + 3 + data[2];
    while (p < end) {
        rec = p;
        value = p[1];
        p += 2;
        if (*p <= 0xB) {
            sub = *p;
            p++;
        } else {
            sub = 0;
        }
        if (key == rec[0] && sub_key == sub) {
            size = TQuestVmDownLoadServer::count_entries_until_terminator(p, end) + 6;
            if (size & 1) {
                size++;
            }
            out = (Src_803EBD38 *)((TQuestVmDownLoadServer *)buf)->find_insert_position(value, size, *total);
            out->x0 = flags | (rec - data);
            text = rec + 2;
            out->x2 = rec[1];
            out->x4 = 0;
            if (rec[2] <= 0xB) {
                text++;
            }
            TQuestVmDownLoadServer::unescape_copy_string(out->text, text, end);
            *total += size;
            (*cnt)++;
        }
        p = skip_entry_text(p, end);
    }
}
#pragma pop

s32 TQuestVmDownLoadServer::read_quest_chunk(u32 id, u8 a1, u8 a2, u8 *buf, s32 *out) {
    s32 a;
    s32 b;
    s32 cnt;
    s32 total;
    s32 r;
    s32 v;
    if (lbl_805D7904 == -1) {
        return -3;
    }
    r = TQuestVmDownLoadServer__sub_803E779C(id, &a, &b, &cnt);
    if (r == -1) {
        return 0;
    }
    cnt = 0;
    total = 0;
    if (a != -1) {
        TQuestVmDownLoadServer__sub_803EFCB4(get_cached_page__22TQuestVmDownLoadServerFi(r) + a, a1, a2, &cnt, &total, buf, 0);
    }
    if (b != -1) {
        TQuestVmDownLoadServer__sub_803EFCB4(TQuestVmDownLoadServer::get_buffer_ptr(b), a1, a2, &cnt, &total, buf, 0x8000);
    }
    v = cnt;
    *out = v;
    if (v == 0) {
        return 0;
    }
    return 1;
}

void TQuestVmDownLoadServer__sub_803EFF20(u8 *data, s32 key, s32 sub_key, s32 *best, u8 *dst, s32 flags) {
    u8 *p;
    u8 *rec;
    u8 *end;
    u8 *found;
    u8 *text;
    Src_803EBD38 *out;
    u8 unused[8];
    s32 start_best;
    s32 sub;
    s32 value;
    start_best = *best;
    end = data + (u16)(data[0] + (data[1] << 8));
    p = data + 3 + data[2];
    while (p < end) {
        rec = p;
        value = p[1];
        p += 2;
        if (*p <= 0xB) {
            sub = *p;
            p++;
        } else {
            sub = 0;
        }
        if (key == rec[0] && sub_key == sub && value > *best) {
            found = rec;
            *best = value;
        }
        for (; p < end; p += 2) {
            if (*p <= 0x38) {
                break;
            }
        }
    }
    if (*best > start_best) {
        out = (Src_803EBD38 *)dst;
        out->x0 = flags | (found - data);
        text = found + 2;
        out->x2 = found[1];
        out->x4 = 0;
        if (found[2] <= 0xB) {
            text++;
        }
        TQuestVmDownLoadServer::unescape_copy_string(out->text, text, end);
    }
}

s32 TQuestVmDownLoadServer__sub_803F0048(s32 id, u8 a1, u8 a2, void *dst) {
    s32 a;
    s32 b;
    s32 c;
    s32 best;
    s32 page;
    if (lbl_805D7904 == -1) {
        return -3;
    }
    page = TQuestVmDownLoadServer__sub_803E779C(id, &a, &b, &c);
    if (page == -1) {
        return 0;
    }
    best = -1;
    if (a != -1) {
        TQuestVmDownLoadServer__sub_803EFF20(get_cached_page__22TQuestVmDownLoadServerFi(page) + a, a1, a2, &best, (u8 *)dst, 0);
    }
    if (b != -1) {
        TQuestVmDownLoadServer__sub_803EFF20(TQuestVmDownLoadServer::get_buffer_ptr(b), a1, a2, &best, (u8 *)dst, 0x8000);
    }
    if (best == -1) {
        return 0;
    }
    return 1;
}

s32 find_symbol_entry__22TQuestVmDownLoadServerFPvsPv(const char *name, s16 len, Info_803F0138 *out) {
    u8 n;
    u8 *base;
    u8 *p;
    s32 id;
    s32 c;
    if (len <= 2 && ((TQuestVmDownLoadServer *)name)->is_char_allowed(len) != 0) {
        out->off = -1;
        return 0;
    }
    id = ((TQuestVmDownLoadServer *)name)->find_name_index();
    {
        u8 *get_cached_page__22TQuestVmDownLoadServerFi(void);
        base = get_cached_page__22TQuestVmDownLoadServerFi();
    }
    p = base;
    while ((u16)(p[0] + (p[1] << 8)) != 0) {
        n = p[2];
        c = strncmp((const char *)(p + 3), name, (s16)n);
        if (c == 0) {
            if ((s16)n == len) {
                break;
            }
        } else if (c > 0) {
            out->off = -1;
            return 0;
        }
        p += (u16)(p[0] + (p[1] << 8));
    }
    if ((u16)(p[0] + (p[1] << 8)) == 0) {
        out->off = -1;
        return 0;
    }
    out->id = id;
    out->off = p - base;
    out->p = p;
    return 1;
}

s32 TQuestVmDownLoadServer__sub_803F0268(const char *name, s16 len, Out_803F0268 *out) {
    char buf[0x50];
    Info_803F0138 i1;
    Info_803F0138 i2;
    s32 max;
    s32 r1;
    s32 r2;
    u32 r;
    if (lbl_805D7904 == -1) {
        return -3;
    }
    strncpy(buf, name, len);
    buf[len] = 0;
    r1 = find_symbol_entry__22TQuestVmDownLoadServerFPvsPv(buf, len, &i1);
    r2 = lookup_name_entry__22TQuestVmDownLoadServerFPvsPv((char *)(buf), len, (Out_803E8B1C *)(&i2));
    if (r1 == 0 && r2 == 0) {
        return 0;
    }
    out->len = len;
    out->len2 = len;
    out->xa = 1;
    out->count = 0;
    max = 0;
    if (r1 == 1) {
        out->count = TQuestVmDownLoadServer__sub_803F03B4(i1.p, out->ents, 0, &max);
    }
    if (r2 == 1) {
        out->count = TQuestVmDownLoadServer__sub_803F03B4(i2.p, out->ents, out->count, &max);
    }
    out->x4 = r = TQuestVmDownLoadServer::acquire_slot_entry(i1.id, i1.off, i2.off, max);
    if (r == 0xFFFFFFFF) {
        return 0;
    }
    return 1;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 merge_duplicate_entry(Ent_803F03B4 *begin, Ent_803F03B4 *e) {
    Ent_803F03B4 *q;
    for (q = begin; q < e; q++) {
        if (q->a == e->a && q->b == e->b) {
            if (q->key < e->key) {
                q->key = e->key;
            }
            return 1;
        }
    }
    return 0;
}
inline u8 *skip_record_args(u8 *p, u8 *end) {
    for (; p < end; p += 2) {
        if (*p <= 0x38) {
            break;
        }
    }
    return p;
}

s32 TQuestVmDownLoadServer__sub_803F03B4(u8 *data, Ent_803F03B4 *cur, s32 n, s32 *max) {
  u8 *end;
  Ent_803F03B4 *e = cur;
  s32 d;
  end = data + ((u16) (data[0] + (data[1] << 8)));
  data = (data + 3) + data[2];
  cur += n;
  while (data < end)
  {
    cur->a = data[0];
    d = data[1];
    data += 2;
    cur->key = d;
    if (((u16) d) > (*max))
    {
      *max = cur->key;
    }
    if ((*data) <= 0xb)
    {
      cur->b = *data;
      data++;
    }
    else
    {
      cur->b = 0;
    }
    cur->c = 0;
    if (merge_duplicate_entry(e, cur) == 0)
    {
      n++;
      cur++;
      if (n >= 0x20)
      {
        break;
      }
    }
    data = skip_record_args(data, end);
  }

  return n;
}
#pragma pop

s32 TQuestVmDownLoadServer__sub_803F0500(u8 *name, s16 len, Out_803E8C2C *out) {
    s16 blen;
    s16 cnt;
    s16 pre;
    s32 idx;
    s32 first;
    u8 *page;
    u8 *p;
    u8 *found;
    u8 n;
    first = 1;
    out->pre = 0;
    out->len = 0;
    idx = ((TQuestVmDownLoadServer *)name)->find_name_index();
    if (((TQuestVmDownLoadServer *)idx)->has_name_mismatch(name) == 0) {
        return 2;
    }
    pre = 0;
    for (;;) {
        page = get_cached_page__22TQuestVmDownLoadServerFi(idx);
        p = page;
        cnt = TQuestVmDownLoadServer::count_matching_name_prefix(idx, name);
        blen = 0;
        for (; (u16)(p[0] + (p[1] << 8)) != 0; p += (u16)(p[0] + (p[1] << 8))) {
            s16 m;
            s32 r;
            Ent_803E8B1C *e = (Ent_803E8B1C *)p;
            n = e->len;
            m = TQuestVmDownLoadServer::match_prefix_length((u8 *)e->name, name, (s16)n);
            if (m >= pre) {
                pre = m + 1;
            }
            r = strncmp(e->name, (char *)name, (s16)n);
            if (r == 0) {
                if ((s16)n == len && first) {
                    return 2;
                }
                blen = n;
                found = p;
            } else if (r > 0) {
                if (strncmp(e->name, (char *)name, len) == 0 && first) {
                    return 2;
                }
                break;
            }
        }
        if (blen > 0) {
            break;
        }
        if (cnt <= 1) {
            out->id = -1;
            return 0;
        }
        len = cnt - 1;
        name[len] = 0;
        idx = ((TQuestVmDownLoadServer *)name)->find_name_index();
        first = 0;
    }
    out->a = idx;
    out->id = found - page;
    out->len = blen;
    out->pre = pre;
    out->ent = (Ent_803E8B1C *)found;
    return 1;
}

s32 TQuestVmDownLoadServer__sub_803F06B8(const char *name, s16 len, Out_803F0268 *out) {
    char buf[0x50];
    Out_803E8C2C o1;
    Out_803E8C2C o2;
    s32 max;
    s32 r1;
    s32 r2;
    s32 n;
    u32 r;
    if (lbl_805D7904 == -1) {
        return -3;
    }
    strncpy(buf, name, len);
    buf[len] = 0;
    r1 = TQuestVmDownLoadServer__sub_803F0500((u8 *)buf, len, &o1);
    if (r1 == 2) {
        return 2;
    }
    strncpy(buf, name, len);
    buf[len] = 0;
    r2 = TQuestVmDownLoadServer__sub_803E8C2C(buf, len, &o2);
    if (r2 == 2) {
        return 2;
    }
    if (r1 == 0 && r2 == 0) {
        return 0;
    }
    out->xa = 1;
    max = 0;
    out->len2 = o1.pre > o2.pre ? o1.pre : o2.pre;
    if (o1.len > o2.len) {
        out->len = o1.len;
        out->count = TQuestVmDownLoadServer__sub_803F03B4((u8 *)o1.ent, out->ents, 0, &max);
        o2.id = -1;
    } else if (o1.len < o2.len) {
        out->len = o2.len;
        out->count = TQuestVmDownLoadServer__sub_803F03B4((u8 *)o2.ent, out->ents, 0, &max);
        o1.id = -1;
    } else {
        out->len = o1.len;
        n = TQuestVmDownLoadServer__sub_803F03B4((u8 *)o1.ent, out->ents, 0, &max);
        out->count = TQuestVmDownLoadServer__sub_803F03B4((u8 *)o2.ent, out->ents, n, &max);
    }
    out->x4 = r = TQuestVmDownLoadServer::acquire_slot_entry(o1.a, o1.id, o2.id, max);
    if (r == 0xFFFFFFFF) {
        return 0;
    }
    return 1;
}

s32 TQuestVmDownLoadServer__sub_803F0890(void) {
    if ((s32) lbl_805D7904 == -1) {
        return -3;
    }
    TQuestVmDownLoadServer__sub_803E8150();
    TQuestVmDownLoadServer__sub_803E9764();
    TQuestVmDownLoadServer::retry_seek_active_entries();
    if (TQuestVmDownLoadServer__sub_803E86C8() == -1) {
        return -2;
    }
    return 3;
}

s32 TQuestVmDownLoadServer__sub_803F08E4(s8 *quest_vm_down_load_server) {
    s32 r;

    if (lbl_805D7904 != -1) {
        return -4;
    }
    if (*quest_vm_down_load_server == 0) {
        return -1;
    }
    ((TQuestVmDownLoadServer *)quest_vm_down_load_server)->set_file_info_name();
    r = TQuestVmDownLoadServer::find_file_info_index();
    if (r != 0) {
        if (r == -1) {
            return -7;
        }
        return -8;
    }
    if (TQuestVmDownLoadServer::read_ask_header() == -1) {
        TQuestVmDownLoadServer__sub_803E86C8();
        return -2;
    }
    if (TQuestVmDownLoadServer__sub_803E8084() == -1) {
        TQuestVmDownLoadServer__sub_803E86C8();
        return -2;
    }
    TQuestVmDownLoadServer::init_page_cache();
    __VIRetraceHandler();
    if (lbl_805D78F8 == 0x8000) {
        return -6;
    }
    return 3;
}

s32 TQuestVmDownLoadServer__sub_803F09A4(void) {
    s32 var_r3;
    quest_download_state = 0;
    quest_download_initialized = 1;
    lbl_805D7908 = 0;
    lbl_805D790C = 0;
    var_r3 = dispatch_request_0x20__19TWindowKeyBoardSoftFll(&lbl_805E10D8, &lbl_805E10E0);
    if (var_r3 == 0) {
        var_r3 = dispatch_request_0x1c__19TWindowKeyBoardSoftFv();
    }
    if (var_r3 > 0) {
        var_r3 = -1;
    }
    return var_r3;
}

s32 TQuestVmDownLoadServer__sub_803F09FC(void *arg0, int arg1, int arg2) {
    s32 r;
    switch (arg2) {
    case 0:
        if (arg1 < 0) {
            return -1;
        }
        lbl_805D7914.remain = lbl_805D7910 - arg1;
        lbl_805D7914.pos = arg1;
        break;
    case 1:
        r = lbl_805D7914.remain - arg1;
        if (r < 0 || (u32)r > lbl_805D7910) {
            return -1;
        }
        lbl_805D7914.remain = r;
        lbl_805D7914.pos += arg1;
        break;
    case 2:
        if (arg1 > 0) {
            return -1;
        }
        lbl_805D7914.remain = -arg1;
        arg1 = lbl_805D7910 + arg1;
        lbl_805D7914.pos = arg1 - 1;
        break;
    }
    return lbl_805D7914.pos;
}

u32 TQuestVmDownLoadServer::aram_dma_read(void *h, void *dst, int size) {
    u32 n;
    u32 len;
    u32 start;
    u8 *base;
    base = quest_download_aram_dma_buffer;
    n = lbl_805D7914.remain;
    if ((u32)lbl_805D7914.remain >= (u32)size) {
        n = size;
    }
    len = n;
    if (n & 3) {
        len = (n | 3) + 1;
    }
    DCInvalidateRange(base + 0x40, 0x2000);
    (*(u32 *)&quest_download_aram_dma_pending) = 1;
    ARQPostRequest(base + 0x2040, lbl_805D7924, 1, lbl_805D7920, lbl_805D792C + lbl_805D7914.pos,
                   (u32)(base + 0x40), len, TQuestVmDownLoadServer__sub_803F0BE8);
    start = OSGetTick();
    for (;;) {
        if ((*(u32 *)&quest_download_aram_dma_pending) == 0) {
            memcpy(dst, base + 0x40, n);
            break;
        }
        if (OSGetTick() - start > lbl_805D791C) {
            (*(u32 *)&quest_download_aram_dma_pending) = 0;
            ARQRemoveRequest(base + 0x2040);
            OSReport(aram_dma_timeout_message);
            return -1;
        }
    }
    lbl_805D7914.remain -= n;
    lbl_805D7914.pos += n;
    return n;
}

s32 TQuestVmDownLoadServer__sub_803F0BD8(void * _w0) {
    return 0;
}

s32 TQuestVmDownLoadServer__sub_803F0BE0(void * _w0, void * _w1) {
    return 1;
}

void TQuestVmDownLoadServer__sub_803F0BE8(u8 *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 4) == (u32) lbl_805D7924) {
        quest_download_aram_dma_pending = 0;
    }
}

void TQuestVmDownLoadServer__sub_803F0C04(u32 aram_addr, s32 size, u32 owner, u32 priority, u32 timeout_ms) {
    lbl_805D792C = aram_addr;
    lbl_805D7914.remain = size;
    lbl_805D7914.pos = 0;
    lbl_805D7924 = owner;
    lbl_805D7910 = lbl_805D7914.remain;
    lbl_805D7920 = priority;
    lbl_805D791C = timeout_ms * (__OSBusClock / 4 / 1000);
}

}

u16 lbl_805A02A8[0x4C];
u16 lbl_805A0340[0x98];
RecoveredGlobal_803E6ACC_lbl_805A0470 quest_download_scratch_storage;
RecoveredGlobal_803E6ACC_lbl_805A0498 quest_download_entry_table;
RecoveredGlobal_803E6ACC_lbl_805A05D0 quest_download_buffer_storage;
u8 lbl_805A0698[0x28];
u8 quest_download_aram_dma_buffer[0x2060];
