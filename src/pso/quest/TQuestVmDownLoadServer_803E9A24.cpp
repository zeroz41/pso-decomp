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
inline void append_item_node(Slot_803EA428 *slot, Node_803EA384 *node) {
    Node_803EA384 **pp = &slot->list;
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
        append_item_node(slot, node);
    }
}
s32 TQuestVmDownLoadServer__sub_803EA428(s32 start, s32 end) {
    char *text;
    u32 i;
    s32 j;
    Work_80595008 *work;
    u32 n;
    Slot_803EA428 *slot;
    u8 kind;
    u32 len;
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
            append_item_node(slot, build_item_list__22TQuestVmDownLoadServerFiPv(start, (Hdr_803EA384 *)&work->match));
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
            append_item_node(&work->slots[start], build_item_list__22TQuestVmDownLoadServerFiPv(start, (Hdr_803EA384 *)&work->match));
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
    Out_803E9FFC *o;
    Slot_803EA428 *last;
    Out_803E9FFC **pp;
    Ent_803E9DE0 *e;
    s32 n;
    Slot_803EA428 *slot;
    u8 *text;
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
        work->slots[pos].x15 = n;
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
}
