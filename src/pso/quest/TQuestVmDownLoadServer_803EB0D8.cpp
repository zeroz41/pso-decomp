#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer_803E6970.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/QuestDownloadServer.h"
struct QuestDownloadFreeLink { QuestDownloadFreeLink *next; };
// Every block is either free or occupied by one live node.
union QuestDownloadPoolCell {
    QuestDownloadFreeLink free;
    QuestDownloadTextNode text;
    QuestDownloadEntryNode entry;
    QuestDownloadQueueNode queue;
    QuestDownloadSegment segment;
    QuestDownloadItemNode item;
};

LAYOUT_ASSERT(QuestDownloadPoolCellSize, sizeof(QuestDownloadPoolCell) == 0x14);

enum QuestDownloadPoolPlacement { quest_download_pool_storage };
#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline void *operator new(size_t, void *storage, QuestDownloadPoolPlacement) { return storage; }
#pragma pop

u8 *quest_download_text_write_ptr;
u8 lbl_805D7894[4];
s32 quest_page_node_index;
s32 quest_page_node_count;
QuestDownloadTextNode *quest_page_node_head;
s32 quest_page_text_limit;
s32 quest_download_free_list_ready_flag;
s32 quest_download_free_cell_count;
QuestDownloadFreeLink *quest_download_free_list;
s32 lbl_805D78B4;

u8 *lbl_805D78B8;
u8 *lbl_805D78BC;
s32 quest_text_end;
QuestDownloadInputEntry *lbl_805D78C4;
QuestDownloadInputEntry *lbl_805D78C8;
u16 *quest_download_buffer_ptr;
u16 *lbl_805D78D0;
u16 *quest_download_buffer_start;
u16 *quest_vm_download_buffer_end;
s32 quest_download_match_length_limit;
s16 lbl_805D78E0;
s32 lbl_805D78E4;
s32 lbl_805D78E8;
saddr quest_text_entry_len;
saddr quest_text_cursor_pos;
s32 quest_download_server_state;
saddr lbl_805D78F8;
s32 lbl_805D78FC;
s32 lbl_805D7900;
s32 quest_download_file_handle;  // what the quest-file open returns; -1 = closed (named from use)

struct QuestDownloadRequestStorage {
    QuestDownloadRequest request;
    u8 reserved[0x18];
};
LAYOUT_ASSERT(QuestDownloadRequestStorageSize, sizeof(QuestDownloadRequestStorage) == 0x28);
LAYOUT_ASSERT(QuestDownloadRequestStorageRequest, offsetof(QuestDownloadRequestStorage, request) == 0);

extern "C" {
#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Len_803EB328(QuestDownloadTextNode *p) {
    s32 n;
    if (p->flags == 0x80) {
        return quest_text_entry_len * 2;
    }
    n = (quest_text_entry_len - p->len) * 2;
    while (p->flags & 1) {
        n += strlen(reinterpret_cast<const char *>(p) + 1);
        p = p->next;
    }
    return n + strlen(reinterpret_cast<const char *>(p) + 1);
}
inline QuestDownloadTextNode *Next_803EB328(QuestDownloadTextNode *p) {
    while (p->flags & 1) {
        p = p->next;
    }
    return p->next;
}


#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline QuestDownloadTextNode *Advance_803EB0D8(QuestDownloadTextNode *p, s32 n) {
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
    s32 r = TQuestVmDownLoadServer::count_fitting_entries(quest_page_node_head);
    if (r == 0) {
        TQuestVmDownLoadServer__sub_803EC284(0, 0);
    } else {
        quest_page_node_count = r;
    }
    quest_page_node_index = 0;
}
s32 TQuestVmDownLoadServer__sub_803EB0D8(s32 mode, s32 force) {
    QuestDownloadTextNode *save = quest_page_node_head;
    s32 cnt = quest_page_node_count;
    u8 unused[8];
    TQuestVmDownLoadServer__sub_803EC284(0, 0);
    if (save == quest_page_node_head) {
        if (force == 0) {
            quest_page_node_head = save;
            quest_page_node_count = cnt;
            quest_page_node_index = 0;
            return 0;
        }
        save = NULL;
    }
    for (;;) {
        if (Advance_803EB0D8(quest_page_node_head, quest_page_node_count) == save) {
            break;
        }
        quest_page_node_head = Advance_803EB0D8(quest_page_node_head, quest_page_node_count);
        Reload_803EB0D8();
    }
    if (mode == 1) {
        TQuestVmDownLoadServer__sub_803EB4D4();
    }
    return 1;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline QuestDownloadTextNode *next_entry_group(QuestDownloadTextNode *p) {
    while (p->flags & 1) {
        p = p->next;
    }
    return p->next;
}
inline QuestDownloadTextNode *advance_entry_groups(QuestDownloadTextNode *p, s32 n) {
    while (n-- != 0) {
        p = next_entry_group(p);
    }
    return p;
}
inline s32 count_fitting_groups(QuestDownloadTextNode *head) {
    QuestDownloadTextNode *p;
    s32 n;
    s32 total;
    s32 limit;
    if (head == NULL) {
        return 0;
    }
    p = head;
    n = total = 0;
    limit = quest_page_text_limit - 9;
    while (n < 9 && p != NULL) {
        total += measure_entry_group_len(p) + 3;
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
    QuestDownloadTextNode *save = quest_page_node_head;
    s32 count;
    quest_page_node_head = advance_entry_groups(save, quest_page_node_count);
    count = count_fitting_groups(quest_page_node_head);
    if (count == 0) {
        if (force == 0) {
            quest_page_node_head = save;
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

s32 TQuestVmDownLoadServer::count_fitting_entries(QuestDownloadTextNode *node_803_eb328) {
    s32 n;
    s32 total;
    s32 lim;
    QuestDownloadTextNode *p;
    if (node_803_eb328 == NULL) {
        return 0;
    }
    p = node_803_eb328;
    total = 0;
    lim = quest_page_text_limit - 9;
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
inline s32 group_name_text(QuestDownloadTextNode *p, u16 *buf) {
    s32 n = 0;
    for (;;) {
        n += TQuestVmDownLoadServer__convert_quest_text_u8_to_u16(buf + n, reinterpret_cast<u8 *>(p) + 1, 6);
        if (!(p->flags & 1)) {
            break;
        }
        p = p->next;
    }
    return n;
}
s32 write_entry_group_text(s32 start, s32 count, QuestDownloadTextNode *node, u16 *buf) {
    s32 n;
    if (node == NULL || (node->flags & 0x80)) {
        return TQuestVmDownLoadServer__sub_803E6970(start, count, buf, 0);
    }
    n = group_name_text(node, buf);
    buf += n;
    return n + TQuestVmDownLoadServer__sub_803E6970((s32)(start + node->len), (s32)(count - node->len), buf, 0);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 count_entry_groups(QuestDownloadTextNode *p) {
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
inline s32 entry_group_text(s32 start, s32 count, QuestDownloadTextNode *node, u16 *buf) {
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
    QuestDownloadTextNode *node;
    s32 w;
    s32 pos;
    s32 d;

    p = &lbl_80596258.text[5];
    n = count_entry_groups(quest_page_node_head);
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
    TQuestVmDownLoadServer__convert_quest_text_u8_to_u16(lbl_805A0340, lbl_80596258.text, 0);
    node = quest_page_node_head;
    pos = 9;
    for (i = 0; i < quest_page_node_count; i++) {
        lbl_805D7894[2] = i + '1';
        pos += TQuestVmDownLoadServer__convert_quest_text_u8_to_u16(&lbl_805A0340[pos], lbl_805D7894, 0);
        w = entry_group_text(quest_text_cursor_pos, quest_text_entry_len, node, &lbl_805A0340[pos]);
        if (i == quest_page_node_index) {
            TQuestVmDownLoadServer__set_text_run_attr(&lbl_805A0340[pos], w, 7);
        } else {
            TQuestVmDownLoadServer__set_text_run_attr(&lbl_805A0340[pos], w, 0);
        }
        pos += w;
        if ((node = next_entry_group(node)) == NULL) {
            break;
        }
    }
    buf = &lbl_805A0340[pos];
    for (; pos < quest_page_text_limit; pos++) {
        TQuestVmDownLoadServer__convert_quest_text_u8_to_u16(buf, (const u8 *)" ", 0);
        buf++;
    }
}
#pragma pop

extern "C" QuestDownloadTextNode *advance_quest_text_entries(QuestDownloadTextNode *p, s32 n) {
    s32 i;
    for (i = 0; i != n; i++) {
        while (p->flags & 1) {
            p = p->next;
        }
        p = p->next;
    }
    return p;
}

s32 measure_entry_group_len(QuestDownloadTextNode *node) {
    s32 n;
    if (node->flags == 0x80) {
        return quest_text_entry_len * 2;
    }
    n = (quest_text_entry_len - node->len) * 2;
    while (node->flags & 1) {
        n += strlen(reinterpret_cast<const char *>(node) + 1);
        node = node->next;
    }
    return n + strlen(reinterpret_cast<const char *>(node) + 1);
}

extern "C" s32 count_quest_text_entries(const QuestDownloadTextNode *p) {
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

QuestDownloadTextNode *next_quest_text_entry(QuestDownloadTextNode *p) {
    while (p->flags & 1) {
        p = p->next;
    }
    return p->next;
}

extern "C" QuestDownloadTextNode *detach_quest_text_tail(QuestDownloadTextNode *p) {
    QuestDownloadTextNode *next;
    while (p->flags & 1) {
        p = p->next;
    }
    next = p->next;
    p->next = NULL;
    return next;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 Conv_803EB8BC(s32 start, s32 count, QuestDownloadTextNode *node, u16 *buf) {
    s32 n;
    QuestDownloadTextNode *p;
    u16 *b = buf;
    s32 lim = count;
    u8 unused[8];
    if (node == NULL || (node->flags & 0x80)) {
        return TQuestVmDownLoadServer__sub_803E6970(start, lim, b, 0);
    }
    p = node;
    n = 0;
    for (;;) {
        n += TQuestVmDownLoadServer__convert_quest_text_u8_to_u16(b + n, reinterpret_cast<u8 *>(p) + 1, 6);
        if (!(p->flags & 1)) {
            break;
        }
        p = p->next;
    }
    b += n;
    return n + TQuestVmDownLoadServer__sub_803E6970((s32)(start + node->len), (s32)(lim - node->len), b, 0);
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
inline QuestDownloadTextNode *Last_803EB8BC(QuestDownloadTextNode *p) {
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

void append_unique_node__22TQuestVmDownLoadServerFiPvPvPv(s32 start, QuestDownloadTextNode **headp, QuestDownloadTextNode **tailp, QuestDownloadTextNode *n) {
    s32 len;

    len = Conv_803EB8BC(start, quest_text_entry_len, n, lbl_805A0340);
    len = TQuestVmDownLoadServer__sub_803EC71C(lbl_805A0340, (u8 *)lbl_805A02A8, len);
    if (Find_803EB8BC((u8 *)lbl_805A02A8, len)) {
        free_quest_text_chain(n);
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
inline s32 Conv_803EBA98(s32 start, s32 count, QuestDownloadTextNode *node, u16 *buf) {
    QuestDownloadTextNode *p;
    s32 n;
    u16 *b = buf;
    s32 lim = count;
    u8 unused[8];
    if (node == NULL || (node->flags & 0x80)) {
        return TQuestVmDownLoadServer__sub_803E6970(start, lim, b, 0);
    }
    p = node;
    n = 0;
    for (;;) {
        n += TQuestVmDownLoadServer__convert_quest_text_u8_to_u16(b + n, reinterpret_cast<u8 *>(p) + 1, 6);
        if (!(p->flags & 1)) {
            break;
        }
        p = p->next;
    }
    b += n;
    return n + TQuestVmDownLoadServer__sub_803E6970((s32)(start + node->len), (s32)(lim - node->len), b, 0);
}
inline QuestDownloadTextNode *Next_803EBA98(QuestDownloadTextNode *p) {
    while (p->flags & 1) {
        p = p->next;
    }
    return p->next;
}
void pack_entry_text_chain(s32 start, QuestDownloadTextNode *node) {
    s32 n;
    s32 len;
    quest_download_text_write_ptr = quest_download_text_buffer;
    while (node != NULL) {
        n = Conv_803EBA98(start, quest_text_entry_len, node, lbl_805A0340);
        len = TQuestVmDownLoadServer__sub_803EC71C(lbl_805A0340, quest_download_text_write_ptr + 1, n);
        *quest_download_text_write_ptr++ = len;
        quest_download_text_write_ptr += len;
        node = Next_803EBA98(node);
    }
}
#pragma pop

QuestDownloadQueueNode *TQuestVmDownLoadServer__alloc_quest_queue_node(void);

#pragma push
#pragma opt_dead_assignments off
#pragma dont_inline off
#pragma inline_depth(1)
inline QuestDownloadTextNode *Detach_803EBBBC(QuestDownloadTextNode *p) {
    QuestDownloadTextNode *next;
    while (p->flags & 1) {
        p = p->next;
    }
    next = p->next;
    p->next = NULL;
    return next;
}
QuestDownloadTextNode *get_next_node__22TQuestVmDownLoadServerFPv(QuestDownloadQueueNode *p) {
    QuestDownloadQueueNode *best = NULL;
    QuestDownloadTextNode *ret;
    u32 key;
    for (; p != NULL; p = p->next) {
        if (p->text != NULL && (best == NULL || p->score > key)) {
            best = p;
            key = p->score;
        }
    }
    if (best == NULL) {
        return NULL;
    }
    ret = best->text;
    best->text = Detach_803EBBBC(ret);
    best->score = best->text == NULL ? 0 : TQuestVmDownLoadServer__sub_803ED0B4(best->entry, best->text->attribute);
    return ret;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline QuestDownloadTextNode *build_entry_text(s32 idx, s32 len, s32 mode) {
    QuestDownloadTextNode *first;
    QuestDownloadTextNode *tail;
    QuestDownloadTextRecord *src = (QuestDownloadTextRecord *)quest_download_text_buffer;
    src->key = 0xFFFF;
    src->attribute = 0;
    src->extra = 0;
    TQuestVmDownLoadServer__sub_803E6B70(src->text, idx, len, mode);
    return TQuestVmDownLoadServer::build_text_node_chain(src, NULL, len, &first, &tail);
}

void rebuild_current_slot_text_chain(s32 mode) {
    QuestDownloadSlot *slot = &quest_download_slot_chain_table[quest_text_cursor_pos];
    free_quest_text_chain(slot->chain);
    slot->chain = build_entry_text(quest_text_cursor_pos, quest_text_entry_len, mode);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline QuestDownloadTextNode *Default_803EBEFC(s32 x) {
    QuestDownloadTextNode *n = TQuestVmDownLoadServer__alloc_quest_text_node();
    if (n != NULL) {
        n->flags = 0x80;
        n->data[0] = 0;
        n->len = x;
        n->pad7 = 0;
        n->source = NULL;
        n->key = 0xFFFF;
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
QuestDownloadTextNode *TQuestVmDownLoadServer::build_text_node_chain(
    QuestDownloadTextRecord *s, const QuestDownloadItemNode *source, s32 length, QuestDownloadTextNode **head, QuestDownloadTextNode **tail) {
    u8 *text;
    s32 rem;
    QuestDownloadTextNode *n;
    QuestDownloadTextNode *m;
    s32 c;
    u8 unused[8];
    text = s->text;
    rem = strlen((const char *)text);
    n = TQuestVmDownLoadServer__alloc_quest_text_node();
    if (n == NULL) {
        return NULL;
    }
    n->flags = 0;
    c = Copy_803EBD38(n->data, text, 4);
    rem -= c;
    n->len = length;
    text += c;
    n->pad7 = s->extra;
    n->source = source;
    n->key = s->key;
    n->attribute = s->attribute;
    n->next = NULL;
    *head = n;
    while (rem > 0) {
        m = TQuestVmDownLoadServer__alloc_quest_text_node();
        if (m == NULL) {
            free_quest_text_chain(*head);
            return NULL;
        }
        n->flags |= 1;
        m->flags = 2;
        c = Copy_803EBD38(reinterpret_cast<u8 *>(m) + 1, text, 14);
        rem -= c;
        text += c;
        m->next = NULL;
        n->next = m;
        n = m;
    }
    *tail = n;
    return *head;
}
#pragma pop

QuestDownloadTextNode *TQuestVmDownLoadServer__sub_803EBEFC(const QuestDownloadEntryPrefix *entry) {
    s32 count;
    QuestDownloadTextNode *first;
    QuestDownloadTextNode *tl;
    s32 pad;
    QuestDownloadTextNode *head;
    u8 *base;
    const QuestDownloadItemNode *t;
    QuestDownloadTextNode *tail;
    u8 *p;

    base = lbl_80596258.text;
    t = entry->source;
    if (t == NULL || t->off == 0) {
def:
        return Default_803EBEFC(entry->off);
    }
    if ((u32)t->x4 == 0xFFFFFFFFU) {
        if (t->a != 0x1F) {
            goto def;
        }
        if (format_number_text_all_modes(quest_download_scratch_storage + quest_text_cursor_pos, t->off,
                                         reinterpret_cast<QuestDownloadTextRecord *>(base + 0xC), &count) > 0) {
            goto build;
        }
        goto def;
    } else {
        if (TQuestVmDownLoadServer::read_quest_chunk(t->x4, t->a, t->b, base + 0xC, &count) <= 0) {
            goto def;
        }
    }
build:
    p = base + 0xC;
    tail = NULL;
    head = NULL;
    while (count > 0) {
        if (TQuestVmDownLoadServer::build_text_node_chain(reinterpret_cast<QuestDownloadTextRecord *>(p), t, t->off, &first, &tl) == NULL) {
            free_quest_text_chain(head);
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
        if ((uaddr)p & 1) {
            p++;
        }
        count--;
    }
    return head;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline QuestDownloadTextNode *Default_803EC09C(s32 x) {
    QuestDownloadTextNode *n = TQuestVmDownLoadServer__alloc_quest_text_node();
    if (n != NULL) {
        n->flags = 0x80;
        n->data[0] = 0;
        n->len = x;
        n->pad7 = 0;
        n->source = NULL;
        n->key = 0xFFFF;
        n->next = NULL;
    }
    return n;
}
inline QuestDownloadTextNode *Last_803EC09C(QuestDownloadTextNode *p) {
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
    QuestDownloadSlot *e;
    QuestDownloadTextNode *tail;
    QuestDownloadTextNode *head;
    QuestDownloadEntryNode *o;
    QuestDownloadQueueNode *qh;
    QuestDownloadQueueNode *q;
    QuestDownloadQueueNode *qt;
    QuestDownloadTextNode *r;
    QuestDownloadTextNode *n;

    e = &quest_download_slot_chain_table[quest_text_cursor_pos];
    if ((uaddr)(o = e->head) == 0xFFFFFFFFU) {
        return;
    }
    qh = NULL;
    qt = NULL;
    for (; o != NULL; o = o->next) {
        if (o->prefix.off != quest_text_entry_len) {
            continue;
        }
        q = TQuestVmDownLoadServer__alloc_quest_queue_node();
        if (q == NULL) {
            for (; qh != NULL; qh = qh->next) {
                TQuestVmDownLoadServer::push_download_entry(qh->text);
            }
            qh = NULL;
            break;
        }
        q->text = r = TQuestVmDownLoadServer__sub_803EBEFC(&o->prefix);
        q->entry = o;
        q->score = (r == NULL) ? 0 : TQuestVmDownLoadServer__sub_803ED0B4(o, r->attribute);
        q->next = NULL;
        if (qh == NULL) {
            qh = qt = q;
        } else {
            qt->next = q;
            qt = q;
        }
    }
    e = &quest_download_slot_chain_table[idx = quest_text_cursor_pos];
    head = e->chain;
    tail = Last_803EC09C(head);
    pack_entry_text_chain(idx, head);
    while ((n = get_next_node__22TQuestVmDownLoadServerFPv(qh)) != NULL) {
        append_unique_node__22TQuestVmDownLoadServerFiPvPvPv(idx, &head, &tail, n);
    }
    if ((n = Default_803EC09C(quest_text_entry_len)) != NULL) {
        append_unique_node__22TQuestVmDownLoadServerFiPvPvPv(idx, &head, &tail, n);
    }
    e->chain = head;
    TQuestVmDownLoadServer__free_quest_queue_chain(qh);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TQuestVmDownLoadServer__sub_803EC284(s32 pos, s32 mode) {
    QuestDownloadTextNode *p;
    s32 n;
    if (mode == 1) {
        TQuestVmDownLoadServer__sub_803EC09C();
    }
    p = quest_download_slot_chain_table[quest_text_cursor_pos].chain;
    if (quest_download_state > 0) {
        quest_page_text_limit = 0x50;
    } else {
        quest_page_text_limit = TQuestVmDownLoadServer::get_buffer_size();
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
    quest_page_node_head = p;
    quest_page_node_index = pos;
    quest_page_node_count = n;
done:
    if (mode == 1 && quest_download_state == 0) {
        TQuestVmDownLoadServer__sub_803EB4D4();
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline QuestDownloadTextNode *Default_803EC460(s32 x) {
    QuestDownloadTextNode *n = TQuestVmDownLoadServer__alloc_quest_text_node();
    if (n != NULL) {
        n->flags = 0x80;
        n->data[0] = 0;
        n->len = x;
        n->pad7 = 0;
        n->source = NULL;
        n->key = 0xFFFF;
        n->next = NULL;
    }
    return n;
}

void TQuestVmDownLoadServer__sub_803EC460(s32 pos, s32 x) {
    QuestDownloadTextNode *first;
    QuestDownloadTextNode *tl;
    QuestDownloadSlot *e;
    u8 *base;
    QuestDownloadEntryNode *o;
    QuestDownloadEntryNode *best;
    u16 bestv;
    u16 v;
    const QuestDownloadItemNode *t;

    e = &quest_download_slot_chain_table[pos];
    base = lbl_80596258.text;
    best = NULL;
    bestv = 0;
    if (e->chain != NULL) {
        return;
    }
    if ((uaddr)(o = e->head) == 0xFFFFFFFFU) {
def:
        e->chain = Default_803EC460(x);
        return;
    }
    for (; o != NULL; o = o->next) {
        if (o->prefix.off != x) {
            continue;
        }
        v = (o->prefix.source == NULL) ? 0 : TQuestVmDownLoadServer__sub_803ED0B4(o, o->prefix.source->c);
        if (v > bestv || best == NULL) {
            bestv = v;
            best = o;
        }
    }
    if (best == NULL || (t = best->prefix.source) == NULL || t->off == 0) {
        goto def;
    }
    if ((u32)t->x4 == 0xFFFFFFFFU) {
        if (t->a != 0x1F) {
            goto def;
        }
        if (TQuestVmDownLoadServer__sub_803EED0C(quest_download_scratch_storage + pos, t->off,
                                             reinterpret_cast<QuestDownloadTextRecord *>(base + 0xC)) > 0) {
            goto build;
        }
        goto def;
    } else {
        if (TQuestVmDownLoadServer__sub_803F0048(t->x4, t->a, t->b, base + 0xC) <= 0) {
            goto def;
        }
    }
build:
    e->chain = TQuestVmDownLoadServer::build_text_node_chain(reinterpret_cast<QuestDownloadTextRecord *>(base + 0xC), t, t->off, &first, &tl);
}
#pragma pop

u16 TQuestVmDownLoadServer::jis_to_sjis(u16 jis) {
    u8 lo;
    u8 hi;
    hi = jis >> 8;
    lo = jis;
    if (jis < 0x2121 || jis > 0x7E7E) {
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

u16 TQuestVmDownLoadServer__sub_803EC69C(u16 code) {
    u32 lo = code & 0xff;
    u8 hi = ((u32)code >> 8) & 0xff;
    code = hi;
    u32 row;
    u8 outlo;
    if (lo < 0x40 || lo > 0xfc || lo == 0x7f) {
        return 0;
    }
    if (hi >= 0xe0) {
        code -= 0x40;
    }
    row = ((u8)code - 0x81) * 2 + 0x21;
    if ((u8)lo >= 0x9f) {
        row++;
        outlo = lo - 0x7e;
    } else if ((u8)lo >= 0x80) {
        outlo = lo - 0x20;
    } else {
        outlo = lo - 0x1f;
    }
    return ((row << 8) & 0xff00) | outlo;
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

s32 TQuestVmDownLoadServer::is_valid_sjis_code(u16 ch) {
    s32 symbol_row;
    if ((ch >= 0x2120U) && (ch < 0x3020U)) {
        if ((s32) (ch & 0xFF00) == 0x2500) {
            symbol_row = 1;
        } else {
            symbol_row = 0;
        }
        if (symbol_row != 0) {
            return 0;
        }
        return 1;
    }
    return 0;
}

s32 TQuestVmDownLoadServer__sub_803EC884(u16 ch) {
    if (ch >= 0x3020U) {
        return 1;
    }
    return 0;
}

s32 TQuestVmDownLoadServer::is_download_command(u16 ch, s32 arg1) {
    if ((arg1 != 0) && (ch == 0x213C)) {
        return 1;
    }
    if ((s32) (ch & 0xFF00) == 0x2500) {
        return 1;
    }
    return 0;
}

u8 TQuestVmDownLoadServer__sub_803EC8D8(u16 code) {
    s32 row;
    u8 byte;
    u16 wide;
    if ((code > 0x20U) && (code < 0x7FU)) {
        byte = 0;
        return 0;
    }
    wide = code;
    row = code & 0xFF00;
    switch (row) {
    case 0x2300:
        byte = wide & 0x7F;
        return byte;
    case 0x2400:
        byte = (wide & 0x7F) | 0x80;
        return byte;
    case 0x2500:
        byte = 0;
        return 0;
    default:
        return TQuestVmDownLoadServer::lookup_value_by_key(code);
    }
}

s32 TQuestVmDownLoadServer__convert_quest_text_u8_to_u16(u16 *out, const u8 *text, int attr) {
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

void TQuestVmDownLoadServer__set_text_run_attr(u16 *run, s32 count, s32 attr) {
    u16 a = attr << 12;
    while (count-- != 0) {
        *run = (*run & 0xFFF) | a;
        run++;
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

s32 TQuestVmDownLoadServer__is_sjis_double_byte(u16 code) {
    u8 hi = (code >> 8) & 0xFF;
    u8 lo = code;
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

s32 TQuestVmDownLoadServer::is_sjis_lead_byte(u8 c) {
    if ((c < 0x81U) || (c > 0xFCU) || ((c >= 0xA0U) && (c < 0xE0U))) {
        return 0;
    }
    return 1;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
inline void return_quest_pool_cell(void *storage) {
    QuestDownloadPoolCell *cell = static_cast<QuestDownloadPoolCell *>(storage);
    new (&cell->free, quest_download_pool_storage) QuestDownloadFreeLink;
    cell->free.next = quest_download_free_list;
    quest_download_free_list = &cell->free;
    quest_download_free_cell_count += 1;
}

void TQuestVmDownLoadServer__free_quest_queue_chain(QuestDownloadQueueNode *p) {
    while (p != NULL) {
        QuestDownloadQueueNode *next = p->next;
        if (p != NULL) {
            return_quest_pool_cell(p);
        }
        p = next;
    }
}

extern "C" void free_quest_text_chain(QuestDownloadTextNode *p) {
    while (p != NULL) {
        QuestDownloadTextNode *next = p->next;
        if (p != NULL) {
            return_quest_pool_cell(p);
        }
        p = next;
    }
}

void TQuestVmDownLoadServer__free_quest_entry_chain(QuestDownloadEntryNode *p) {
    QuestDownloadEntryNode *next;
    while (p != NULL) {
        next = p->next;
        if (p != NULL) {
            return_quest_pool_cell(p);
        }
        p = next;
    }
}

void release_node_chain__22TQuestVmDownLoadServerFPv(QuestDownloadItemNode *p) {
    u32 prev = 0xFFFFFFFF;
    QuestDownloadItemNode *next;
    while (p != NULL) {
        next = p->next;
        if ((prev == 0xFFFFFFFF || (u32)p->x4 != prev) && (u32)p->x4 != 0xFFFFFFFF) {
            TQuestVmDownLoadServer__sub_803EED9C((u32)p->x4);
        }
        prev = (u32)p->x4;
        if (p != NULL) {
            return_quest_pool_cell(p);
        }
        p = next;
    }
}

void TQuestVmDownLoadServer__free_quest_segment_chain(QuestDownloadSegment *p) {
    QuestDownloadSegment *next;
    while (p != NULL) {
        next = p->next;
        if (p != NULL) {
            return_quest_pool_cell(p);
        }
        p = next;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline QuestDownloadFreeLink *pop_free_block() {
    QuestDownloadFreeLink *p = quest_download_free_list;
    if (p == NULL) {
        return NULL;
    }
    quest_download_free_list = quest_download_free_list->next;
    quest_download_free_cell_count--;
    return p;
}

QuestDownloadQueueNode *TQuestVmDownLoadServer__alloc_quest_queue_node(void) {
    QuestDownloadFreeLink *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    QuestDownloadPoolCell *cell = reinterpret_cast<QuestDownloadPoolCell *>(p);
    new (&cell->queue, quest_download_pool_storage) QuestDownloadQueueNode;
    return reinterpret_cast<QuestDownloadQueueNode *>(p);
}

QuestDownloadTextNode *TQuestVmDownLoadServer__alloc_quest_text_node(void) {
    QuestDownloadFreeLink *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    QuestDownloadPoolCell *cell = reinterpret_cast<QuestDownloadPoolCell *>(p);
    u8 *bytes = reinterpret_cast<u8 *>(cell);
    const u8 attribute_high = bytes[offsetof(QuestDownloadTextNode, attribute)];
    const u8 attribute_low = bytes[offsetof(QuestDownloadTextNode, attribute) + 1];
    new (&cell->text, quest_download_pool_storage) QuestDownloadTextNode;
    bytes[offsetof(QuestDownloadTextNode, attribute)] = attribute_high;
    bytes[offsetof(QuestDownloadTextNode, attribute) + 1] = attribute_low;
    return reinterpret_cast<QuestDownloadTextNode *>(p);
}

QuestDownloadSegment *TQuestVmDownLoadServer__alloc_quest_segment(void) {
    QuestDownloadFreeLink *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    QuestDownloadPoolCell *cell = reinterpret_cast<QuestDownloadPoolCell *>(p);
    new (&cell->segment, quest_download_pool_storage) QuestDownloadSegment;
    return reinterpret_cast<QuestDownloadSegment *>(p);
}

QuestDownloadEntryNode *TQuestVmDownLoadServer__alloc_quest_entry_node(void) {
    QuestDownloadFreeLink *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    QuestDownloadPoolCell *cell = reinterpret_cast<QuestDownloadPoolCell *>(p);
    new (&cell->entry, quest_download_pool_storage) QuestDownloadEntryNode;
    return reinterpret_cast<QuestDownloadEntryNode *>(p);
}

QuestDownloadItemNode *TQuestVmDownLoadServer__sub_803ECF84(void) {
    QuestDownloadFreeLink *p = pop_free_block();
    if (p == NULL) {
        return NULL;
    }
    QuestDownloadPoolCell *cell = reinterpret_cast<QuestDownloadPoolCell *>(p);
    new (&cell->item, quest_download_pool_storage) QuestDownloadItemNode;
    return reinterpret_cast<QuestDownloadItemNode *>(p);
}
#pragma pop

#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
void TQuestVmDownLoadServer::push_download_entry(void *storage) {
    if (storage != NULL) {
        return_quest_pool_cell(storage);
    }
}

QuestDownloadPoolCell quest_download_block_pool[2000];
void TQuestVmDownLoadServer::init_block_free_list() {
    QuestDownloadPoolCell *p;
    if (quest_download_free_list_ready_flag == 0 && quest_download_free_cell_count == 2000) {
        return;
    }
    quest_download_free_list = &quest_download_block_pool[0].free;
    for (p = quest_download_block_pool; p < &quest_download_block_pool[1999]; p++) {
        new (&p->free, quest_download_pool_storage) QuestDownloadFreeLink;
        p->free.next = &(p + 1)->free;
    }
    new (&p->free, quest_download_pool_storage) QuestDownloadFreeLink;
    p->free.next = NULL;
    quest_download_free_cell_count = 2000;
    quest_download_free_list_ready_flag = 0;
}
#pragma pop

u16 TQuestVmDownLoadServer__sub_803ED0B4(const QuestDownloadEntryNode *entry, u16 attribute) {
    if (attribute != 0) {
        return attribute + 0x3E8;
    }
    return entry->cost;
}


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

s32 calc_quest_download_item_cost(const QuestDownloadEntryNode *entry, u8 k, u8 v, s32 base) {
    s32 lvl = 0;
    const QuestDownloadItemNode *s = entry->prefix.source;

    if (s != NULL && ((s->a >= 0x14 && s->a <= 0x19) || s->a == 0x32)) {
        lvl = 1;
        if (s->off + 1 == entry->prefix.off) {
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


s32 TQuestVmDownLoadServer::calc_pair_cost_bonus(u8 arg0, u8 bk, s32 extra) {
    if (arg0 >= 0x14 && arg0 <= 0x18) {
        if (bk >= 0x14 && bk <= 0x18) {
            return extra + 3;
        }
        return extra;
    }
    if (arg0 == 0x1F && bk == 0x1F) {
        return extra + 0xF;
    }
    if (arg0 == 0x21 || arg0 == 0x26 || arg0 == 0x27) {
        return extra + 0x14;
    }
    if (arg0 == 0x20 || arg0 == 0x22) {
        return extra + 0xF;
    }
    if (arg0 == 0x1B && bk == 0x1C) {
        return extra + 0x14;
    }
    if (arg0 == 0x1A && bk == 0x1A) {
        return extra + 5;
    }
    return extra;
}

s32 TQuestVmDownLoadServer::calc_item_entry_cost_extra(u8 arg0, u8 arg1, u8 bk, s32 extra) {
    if ((arg0 == 0xD) && (arg1 == 0)) {
        if ((bk >= 1U) && (bk <= 0x17U)) {
            return extra + 3;
        }
    } else if ((arg1 >= 4U) && (arg1 <= 6U) && (bk >= 1U) && (bk <= 0x17U)) {
        if ((arg0 == 0x8D) || ((arg0 == 0x8E) && (arg1 == 6))) {
            return extra + 0xA;
        }
        if (arg0 <= 0x8CU) {
            return extra + 3;
        }
    } else if ((arg1 == 8) && (bk >= 0x14U) && (bk <= 0x18U)) {
        if (((arg0 >= 0x80U) && (arg0 <= 0x8EU)) || (arg0 == 0x92) || (arg0 == 0x94) || (arg0 == 0xA0) || (arg0 == 0xA2) || ((u8)(arg0 - 0xAE) <= 1U) || (arg0 == 0xB1) || (arg0 == 1) || ((arg0 >= 0xAU) && (arg0 <= 0xCU))) {
            return extra + 0xF;
        }
        return extra + 3;
    }
    return extra;
}


s32 calc_quest_download_entry_cost(const QuestDownloadEntryNode *a, const QuestDownloadEntryNode *b) {
    const QuestDownloadItemNode *s2;
    u8 k;
    u8 bk;
    s32 extra;
    const QuestDownloadItemNode *s;
    u8 q;
    u8 p;

    extra = 0;
    p = 0;
    q = 0;
    if ((k = a->prefix.a) >= 0x2D && k <= 0x38) {
        p = a->prefix.b;
    } else {
        q = a->prefix.b;
    }
    if (b == NULL) {
        bk = 0;
    } else if ((s = b->prefix.source) == NULL) {
        bk = 0;
    } else {
        if ((bk = s->a) == 0x28) {
            return 0;
        }
        if (bk == 0x29 || (bk == 0x19 && s->off > 0) || (bk == 0x1F && (u32)s->x4 == 0xFFFFFFFFU)) {
            extra = 0x14;
        }
    }
    if ((s2 = a->prefix.source) != NULL) {
        if (s2->a == 0x19 && s2->off == 0) {
            extra += 10;
        } else if (s2->a <= 0x19 || s2->a >= 0x1F) {
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
        if (b->prefix.source != NULL) {
            p = b->prefix.source->b;
        } else {
            p = 0;
        }
        return TQuestVmDownLoadServer::calc_item_cost_bonus(p, k, q, extra, 2);
    }
    if (k >= 0x14 && k < 0xC0) {
        return TQuestVmDownLoadServer::calc_pair_cost_bonus(k, bk, extra);
    }
    if (k >= 0xC0) {
        return calc_quest_download_item_cost(a, k, bk, extra);
    }
    return extra;
}


#pragma push
#pragma opt_common_subs off
void TQuestVmDownLoadServer::reset_slot_chain_timers(s32 pos) {
    QuestDownloadEntryNode *n;
    const QuestDownloadItemNode *l;
    QuestDownloadSlot *t = &quest_download_slot_chain_table[pos];
    for (n = t->head; n != NULL; n = n->next) {
        n->base = 0;
        l = n->prefix.source;
        if (l != NULL && l->a == 0x19 && l->off == 0) {
            n->base = 10;
        }
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline QuestDownloadEntryNode *slot_chain_head(s32 i) {
    return quest_download_slot_chain_table[i].head;
}
inline s32 is_special_entry(QuestDownloadEntryNode *e) {
    if (e->prefix.source != NULL && (e->prefix.source->a == 0x28 || e->prefix.source->a == 0x29)) {
        return 1;
    }
    return 0;
}
inline s32 link_cost(QuestDownloadEntryNode *e, QuestDownloadEntryNode *q) {
    s32 a;
    s32 b;
    s32 c;
    if (q == NULL) {
        b = e->prefix.off;
        a = 0;
        c = 1;
    } else {
        a = e->prefix.off;
        c = 0;
        b = q->prefix.off;
    }
    return a * 16 + b * 17 + e->base + calc_quest_download_entry_cost(e, q) + c * 50;
}
s32 TQuestVmDownLoadServer__sub_803ED84C(QuestDownloadEntryNode *e, s32 idx, s32 max) {
    QuestDownloadEntryNode *q;
    u16 best;
    u16 v;
    s16 n;
    if (is_special_entry(e)) {
        e->cost = 0;
        return 0;
    }
    n = e->prefix.off;
    if (e->prefix.a == 0xFF || idx + n >= max) {
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
inline s32 IsSpecial_803ED9AC(QuestDownloadEntryNode *e) {
    if (e->prefix.source != NULL && (e->prefix.source->a == 0x28 || e->prefix.source->a == 0x29)) {
        return 1;
    }
    return 0;
}
inline void Relax_803ED9AC(QuestDownloadEntryNode *best, s32 idx, s32 max) {
    QuestDownloadEntryNode *q;
    s32 v;
    s32 n = best->prefix.off;
    if (best->prefix.a == 0xFF || idx + n >= max) {
        return;
    }
    q = quest_download_slot_chain_table[idx + n].head;
    if (q == NULL) {
        return;
    }
    for (; q != NULL; q = q->next) {
        q->base = 0;
        if (!IsSpecial_803ED9AC(q)) {
            v = calc_quest_download_entry_cost(best, q);
            if (v > 0) {
                q->base = v;
            }
        }
    }
}
s32 TQuestVmDownLoadServer::select_best_slot_entry(s32 idx, s32 max, s32 want) {
    QuestDownloadSlot *slot = &quest_download_slot_chain_table[idx];
    QuestDownloadEntryNode *e;
    QuestDownloadEntryNode *best;
    QuestDownloadEntryNode *q;
    for (e = slot->head; e != NULL; e = e->next) {
        if (want < 0 || e->prefix.off == want) {
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
    return best->prefix.off;
}
#pragma pop
#pragma pop

s32 TQuestVmDownLoadServer__sub_803EDB20(u8 ch) {
    return romaji_kana_char_class_table[ch] & 0x20;
}

s32 TQuestVmDownLoadServer__sub_803EDB3C(u8 ch) {
    return romaji_kana_char_class_table[ch] & 0x40;
}

s32 TQuestVmDownLoadServer__sub_803EDB58(u8 ch) {
    return romaji_kana_char_class_table[ch] & 0x80;
}

s32 TQuestVmDownLoadServer__sub_803EDB74(u8 ch) {
    return romaji_kana_char_class_table[ch] & 0xC0;
}

s32 TQuestVmDownLoadServer::sum_entry_sizes(s32 start, s32 n) {
    QuestDownloadInputEntry *e = &quest_download_entry_table[start];
    s32 sum = 0;
    s32 i;
    for (i = n; i > 0; i--) {
        sum += e->len;
        e++;
    }
    return sum;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
#pragma opt_propagation off
struct DownloadDecoderState {
    u16 lead;
    DownloadDecoderState() : lead(0) {}
};

inline s32 count_encoded_download_input(QuestDownloadInputEntry *&entry) {
    QuestDownloadInputEntry *end = lbl_805D78C8;
    entry = end;
    s32 encoded = 0;
    QuestDownloadInputEntry *scan;
    for (scan = quest_download_entry_table; scan < end; scan++) {
        if (scan->ch & 0xFF00) encoded += 2;
        else encoded++;
    }
    return encoded;
}
extern "C" s32 TQuestVmDownLoadServer__sub_803EDC20(u32 input_address) {
    QuestDownloadInputEntry *entry;
    u8 *codes;
    s32 count;
    u8 *input;
    DownloadDecoderState state;
    s32 encoded;
    u16 ch;
    input = reinterpret_cast<u8 *>(input_address);
    codes = lbl_805D78BC;
    count = quest_text_end;
    encoded = count_encoded_download_input(entry);
    for (; *input != 0; input++) {
        if (state.lead != 0) {
            ch = TQuestVmDownLoadServer__sub_803EC69C((state.lead << 8) | *input);
            if (ch != 0) {
                if (count >= 0x24 || encoded >= 0x4E) return -1;
                entry->ch = ch;
                entry->len = 2;
                entry++;
                *codes++ = TQuestVmDownLoadServer__sub_803EC8D8(ch);
                count++;
                encoded += 2;
            }
            state.lead = 0;
        } else if (TQuestVmDownLoadServer::is_sjis_lead_byte(*input)) {
            state.lead = *input;
        } else if ((*input >= 0x20 && *input < 0x7F) || (*input >= 0xA0 && *input < 0xE0)) {
            if (count >= 0x24 || encoded >= 0x4F) return -1;
            entry->ch = *input;
            state.lead = 0;
            entry->len = 1;
            encoded++;
            *codes++ = state.lead;
            entry++;
            count++;
        }
    }
    lbl_805D78C8 = entry;
    lbl_805D78C4 = entry;
    lbl_805D78BC = codes;
    lbl_805D78B8 = codes;
    quest_text_end = count;
    return count;
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

// Romaji to kana rows: the second letter of the key (0 for none), then the
// kana of the five vowels a i u e o, each as two JIS row-4 (hiragana) cells,
// the second 0 for a single kana. Row 0 is the bare vowels.
// inferred: name from the lookup in TQuestVmDownLoadServer__sub_803EDDA4
const u8 romaji_kana_rows[49][11] = {
    {0, 0x22, 0x00, 0x24, 0x00, 0x26, 0x00, 0x28, 0x00, 0x2A, 0x00}, // a i u e o
    {0, 0x50, 0x00, 0x53, 0x00, 0x56, 0x00, 0x59, 0x00, 0x5C, 0x00}, // ba bi bu be bo
    {'Y', 0x53, 0x63, 0x53, 0x23, 0x53, 0x65, 0x53, 0x27, 0x53, 0x67}, // bya byi byu bye byo
    {0, 0x2B, 0x00, 0x37, 0x00, 0x2F, 0x00, 0x3B, 0x00, 0x33, 0x00}, // ca ci cu ce co
    {'H', 0x41, 0x63, 0x41, 0x00, 0x41, 0x65, 0x41, 0x27, 0x41, 0x67}, // cha chi chu che cho
    {'Y', 0x41, 0x63, 0x41, 0x23, 0x41, 0x65, 0x41, 0x27, 0x41, 0x67}, // cya cyi cyu cye cyo
    {0, 0x40, 0x00, 0x42, 0x00, 0x45, 0x00, 0x47, 0x00, 0x49, 0x00}, // da di du de do
    {'H', 0x47, 0x63, 0x47, 0x23, 0x47, 0x65, 0x47, 0x27, 0x47, 0x67}, // dha dhi dhu dhe dho
    {'Y', 0x42, 0x63, 0x42, 0x23, 0x42, 0x65, 0x42, 0x27, 0x42, 0x67}, // dya dyi dyu dye dyo
    {0, 0x55, 0x21, 0x55, 0x23, 0x55, 0x00, 0x55, 0x27, 0x55, 0x29}, // fa fi fu fe fo
    {'Y', 0x55, 0x63, 0x55, 0x23, 0x55, 0x65, 0x55, 0x27, 0x55, 0x67}, // fya fyi fyu fye fyo
    {0, 0x2C, 0x00, 0x2E, 0x00, 0x30, 0x00, 0x32, 0x00, 0x34, 0x00}, // ga gi gu ge go
    {'W', 0x30, 0x21, 0x30, 0x23, 0x30, 0x00, 0x30, 0x27, 0x30, 0x29}, // gwa gwi gwu gwe gwo
    {'Y', 0x2E, 0x63, 0x2E, 0x23, 0x2E, 0x65, 0x2E, 0x27, 0x2E, 0x67}, // gya gyi gyu gye gyo
    {0, 0x4F, 0x00, 0x52, 0x00, 0x55, 0x00, 0x58, 0x00, 0x5B, 0x00}, // ha hi hu he ho
    {'Y', 0x52, 0x63, 0x52, 0x23, 0x52, 0x65, 0x52, 0x27, 0x52, 0x67}, // hya hyi hyu hye hyo
    {0, 0x38, 0x63, 0x38, 0x00, 0x38, 0x65, 0x38, 0x27, 0x38, 0x67}, // ja ji ju je jo
    {'Y', 0x38, 0x63, 0x38, 0x23, 0x38, 0x65, 0x38, 0x27, 0x38, 0x67}, // jya jyi jyu jye jyo
    {0, 0x2B, 0x00, 0x2D, 0x00, 0x2F, 0x00, 0x31, 0x00, 0x33, 0x00}, // ka ki ku ke ko
    {'W', 0x2F, 0x6E, 0x2F, 0x23, 0x2F, 0x00, 0x2F, 0x27, 0x2F, 0x29}, // kwa kwi kwu kwe kwo
    {'Y', 0x2D, 0x63, 0x2D, 0x23, 0x2D, 0x65, 0x2D, 0x27, 0x2D, 0x67}, // kya kyi kyu kye kyo
    {0, 0x21, 0x00, 0x23, 0x00, 0x25, 0x00, 0x27, 0x00, 0x29, 0x00}, // la li lu le lo
    {'Y', 0x63, 0x00, 0x23, 0x00, 0x65, 0x00, 0x27, 0x00, 0x67, 0x00}, // lya lyi lyu lye lyo
    {0, 0x5E, 0x00, 0x5F, 0x00, 0x60, 0x00, 0x61, 0x00, 0x62, 0x00}, // ma mi mu me mo
    {'Y', 0x5F, 0x63, 0x5F, 0x23, 0x5F, 0x65, 0x5F, 0x27, 0x5F, 0x67}, // mya myi myu mye myo
    {0, 0x4A, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4E, 0x00}, // na ni nu ne no
    {'Y', 0x4B, 0x63, 0x4B, 0x23, 0x4B, 0x65, 0x4B, 0x27, 0x4B, 0x67}, // nya nyi nyu nye nyo
    {0, 0x51, 0x00, 0x54, 0x00, 0x57, 0x00, 0x5A, 0x00, 0x5D, 0x00}, // pa pi pu pe po
    {'Y', 0x54, 0x63, 0x54, 0x23, 0x54, 0x65, 0x54, 0x27, 0x54, 0x67}, // pya pyi pyu pye pyo
    {0, 0x2F, 0x21, 0x2F, 0x23, 0x2F, 0x00, 0x2F, 0x27, 0x2F, 0x29}, // qa qi qu qe qo
    {'Y', 0x2F, 0x63, 0x2F, 0x23, 0x2F, 0x65, 0x2F, 0x27, 0x2F, 0x67}, // qya qyi qyu qye qyo
    {0, 0x69, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6C, 0x00, 0x6D, 0x00}, // ra ri ru re ro
    {'Y', 0x6A, 0x63, 0x6A, 0x23, 0x6A, 0x65, 0x6A, 0x27, 0x6A, 0x67}, // rya ryi ryu rye ryo
    {0, 0x35, 0x00, 0x37, 0x00, 0x39, 0x00, 0x3B, 0x00, 0x3D, 0x00}, // sa si su se so
    {'H', 0x37, 0x63, 0x37, 0x00, 0x37, 0x65, 0x37, 0x27, 0x37, 0x67}, // sha shi shu she sho
    {'Y', 0x37, 0x63, 0x37, 0x23, 0x37, 0x65, 0x37, 0x27, 0x37, 0x67}, // sya syi syu sye syo
    {0, 0x3F, 0x00, 0x41, 0x00, 0x44, 0x00, 0x46, 0x00, 0x48, 0x00}, // ta ti tu te to
    {'H', 0x46, 0x63, 0x46, 0x23, 0x46, 0x65, 0x46, 0x27, 0x46, 0x67}, // tha thi thu the tho
    {'S', 0x44, 0x21, 0x44, 0x23, 0x44, 0x00, 0x44, 0x27, 0x44, 0x29}, // tsa tsi tsu tse tso
    {'Y', 0x41, 0x63, 0x41, 0x23, 0x41, 0x65, 0x41, 0x27, 0x41, 0x67}, // tya tyi tyu tye tyo
    {0, 0x74, 0x21, 0x74, 0x23, 0x74, 0x00, 0x74, 0x27, 0x74, 0x29}, // va vi vu ve vo
    {0, 0x6F, 0x00, 0x26, 0x23, 0x26, 0x00, 0x26, 0x27, 0x72, 0x00}, // wa wi wu we wo
    {'H', 0x26, 0x21, 0x26, 0x23, 0x26, 0x00, 0x26, 0x27, 0x26, 0x29}, // wha whi whu whe who
    {0, 0x21, 0x00, 0x23, 0x00, 0x25, 0x00, 0x27, 0x00, 0x29, 0x00}, // xa xi xu xe xo
    {'Y', 0x63, 0x00, 0x23, 0x00, 0x65, 0x00, 0x27, 0x00, 0x67, 0x00}, // xya xyi xyu xye xyo
    {0, 0x64, 0x00, 0x24, 0x00, 0x66, 0x00, 0x24, 0x27, 0x68, 0x00}, // ya yi yu ye yo
    {0, 0x36, 0x00, 0x38, 0x00, 0x3A, 0x00, 0x3C, 0x00, 0x3E, 0x00}, // za zi zu ze zo
    {'Y', 0x38, 0x63, 0x38, 0x23, 0x38, 0x65, 0x38, 0x27, 0x38, 0x67}, // zya zyi zyu zye zyo
    {0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // end of the table
};

// inferred: the first row per initial letter A-Z, then the end row; NULL for a vowel
const u8 (*const romaji_kana_rows_by_initial[27])[11] = {
    NULL, &romaji_kana_rows[1], &romaji_kana_rows[3], &romaji_kana_rows[6],
    NULL, &romaji_kana_rows[9], &romaji_kana_rows[11], &romaji_kana_rows[14],
    NULL, &romaji_kana_rows[16], &romaji_kana_rows[18], &romaji_kana_rows[21],
    &romaji_kana_rows[23], &romaji_kana_rows[25], NULL, &romaji_kana_rows[27],
    &romaji_kana_rows[29], &romaji_kana_rows[31], &romaji_kana_rows[33], &romaji_kana_rows[36],
    NULL, &romaji_kana_rows[40], &romaji_kana_rows[41], &romaji_kana_rows[43],
    &romaji_kana_rows[45], &romaji_kana_rows[46], &romaji_kana_rows[48],
};

// Looks up a one- or two-letter key: romaji_kana_rows_by_initial holds, per initial
// letter, the first 11-byte row of romaji_kana_rows (second letter, then text).
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
        return &romaji_kana_rows[0][1];
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
        grp = &romaji_kana_rows_by_initial[idx];
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

// Keys that only make a small kana: the key length, the key, then the JIS
// row-4 cell (small tsu, small wa) and its terminator; 0 ends the table.
const u8 quest_download_keyword_table[] = {
    4, 'L', 'T', 'S', 'U', 0x43, 0,
    3, 'L', 'T', 'U', 0x43, 0,
    3, 'L', 'W', 'A', 0x6E, 0,
    4, 'X', 'T', 'S', 'U', 0x43, 0,
    3, 'X', 'T', 'U', 0x43, 0,
    3, 'X', 'W', 'A', 0x6E, 0,
    0,
};

const u8 *TQuestVmDownLoadServer::find_keyword_entry(u16 *start, u16 *end) {
    u8 c;
    const u8 *p;
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


// Converts the romaji at src (n characters left) to kana in out; *count gets the
// number of characters written. Returns the number consumed, 0 when more input
// is needed, -1/-2 on no match (behaviour inferred).
s32 convert_romaji_to_kana(u16 *src, s32 n, u16 *out, s32 *count) {
    const u8 *e;
    u16 *p;
    u8 kind;
    s32 len;
    u8 c2;
    u16 mode;
    s32 c;
    kind = romaji_kana_char_class_table[src[0] & 0xFF] & 0xF;
    *count = 1;
    if (kind <= 9) {
        if (kind <= 5) {
            len = 1;
            p = src;
            e = &romaji_kana_rows[0][1];
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
        c2 = src[1] & 0xFF;
        p = src + 1;
        c = src[0] & 0xFF;
        if (c == c2) {
            if (kind == 12) {
                return 2;
            }
            if (kind == 13) {
                out[0] = TQuestVmDownLoadServer__sub_803E719C('C', *p);
                return 1;
            }
        }
        if (c == 'x' || c == 'X') {
            c2 = src[1] & 0xFF;
            p = src + 1;
            if (c2 == 0x6E || c2 == 0x4E) {
                out[0] = TQuestVmDownLoadServer__sub_803E719C('s', src[0]);
                return 2;
            }
        }
        if (mode == 1 && c2 == 0x27) {
            return 2;
        }
        kind = romaji_kana_char_class_table[c2] & 0xF;
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
            kind = romaji_kana_char_class_table[*p & 0xFF] & 0xF;
            if ((kind >= 6 && kind <= 12) || len > 4) {
                return -2;
            }
        }
    }
    return 0;
}

void reset_entry_text_accumulator(void) {
    lbl_8058DC98[0] = 0;
}

extern u8 lbl_8058DC48[0x50];
void TQuestVmDownLoadServer__sub_803EE580(s32 pos, s32 len, QuestDownloadTextNode *node, QuestDownloadEntryNode *link);

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
// Copies the entry text at pos to dst and converts it to text (name inferred).
inline void copy_entry_text(u8 *dst, u8 *text, s32 pos, s32 len, QuestDownloadTextNode *node) {
    strncpy((char *)dst, reinterpret_cast<char *>(quest_download_scratch_storage) + pos, len);
    dst[len] = 0;
    if (len != strlen((char *)dst)) {
        lbl_8058DC98[0] = 0;
    } else {
        TQuestVmDownLoadServer__sub_803EC71C(lbl_805A0340, text, write_entry_group_text(pos, len, node, lbl_805A0340));
    }
}

void process_entry_text_range(s32 pos, s32 end) {
    QuestDownloadRequest req;
    QuestDownloadSlot *slot;
    QuestDownloadTextNode *node;
    u8 *name;
    u8 *text;
    s32 len;
    s64 name_len;
    const QuestDownloadItemNode *sub;
    s32 n;
    while (pos < end && (n = TQuestVmDownLoadServer__sub_803E9F54(pos)) != 0) {
        slot = &quest_download_slot_chain_table[pos];
        if (pos == quest_text_cursor_pos && (lbl_805D78E8 == 1 || quest_download_state >= 3)) {
            node = advance_quest_text_entries(quest_page_node_head, quest_page_node_index);
        } else {
            node = advance_quest_text_entries(slot->chain, 0);
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
                if (node == NULL || (sub = node->source) == NULL) {
                    req.x7 = 0x28;
                    req.x8 = 0;
                } else {
                    req.x7 = sub->a;
                    req.x8 = sub->b;
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
extern QuestDownloadRequestStorage lbl_805A0698;
s32 TQuestVmDownLoadServer__sub_803EEDC0(QuestDownloadRequest *req, s32 *ids, s32 n);
s32 TQuestVmDownLoadServer__sub_803EF958(u32 id, u16 key, s32 *ids, s32 n);

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)

extern u8 quest_request_text_buffer[];

#pragma push
#pragma optimization_level 2
void TQuestVmDownLoadServer__sub_803EE580(s32 a, s32 b, QuestDownloadTextNode *cmdp, QuestDownloadEntryNode *listp) {
  QuestDownloadEntryNode *list = (QuestDownloadEntryNode *) listp;
  s32 *buf;
  QuestDownloadRequest *obj = (0, &lbl_805A0698.request);
  QuestDownloadTextNode *cmd = (QuestDownloadTextNode *) cmdp;
  const QuestDownloadItemNode *p;
  s32 r;
  QuestDownloadTextNode *q2;
  u32 prev;
  QuestDownloadRequest *new_var;
  s32 pad;
  s32 *pp = &pad;
  q2 = cmd;
  if (q2->key == (-1))
  {
    p = 0;
  }
  else
  {
    if ((p = cmd->source) == 0)
    {
      return;
    }
  }
  new (quest_download_text_buffer, quest_download_scratch_words_or_ids) QuestDownloadScratchIds;
  buf = reinterpret_cast<QuestDownloadScratchIds *>(quest_download_text_buffer)->values;
  if ((list == 0) || (list == ((QuestDownloadEntryNode *) (-1))))
  {
    if (p)
    {
      *(buf++) = p->x4;
    }
  }
  else
  {
    prev = -1;
    do
    {
      const QuestDownloadItemNode *item = list->prefix.source;
      if (((item != 0) && (((u32) item->x4) != 0xFFFFFFFF)) && (((u32) item->x4) != prev))
      {
        prev = item->x4;
        *(buf++) = prev;
      }
      list = list->next;
    }
    while (list != 0);
  }
  if (p == 0)
  {
    strncpy((char *) quest_request_text_buffer, reinterpret_cast<char *>(quest_download_scratch_storage) + a, b);
    quest_request_text_buffer[b] = 0;
    r = write_entry_group_text(a, b, cmd, lbl_805A0340);
    TQuestVmDownLoadServer__sub_803EC71C(lbl_805A0340, lbl_8058DCE8, r);
    obj->name = (char *) quest_request_text_buffer;
    obj->len = (s16) b;
    obj->pad6 = 0;
    obj->x7 = 0x19;
    obj->x8 = 0;
    new_var = (QuestDownloadRequest *) obj;
    obj->text = lbl_8058DCE8;
    TQuestVmDownLoadServer__sub_803EEDC0(new_var, reinterpret_cast<QuestDownloadScratchIds *>(quest_download_text_buffer)->values, buf - ((0, reinterpret_cast<QuestDownloadScratchIds *>(quest_download_text_buffer)->values)));
  }
  else
  {
    TQuestVmDownLoadServer__sub_803EF958(p->x4, cmd->key, reinterpret_cast<QuestDownloadScratchIds *>(quest_download_text_buffer)->values, buf - (reinterpret_cast<QuestDownloadScratchIds *>(quest_download_text_buffer)->values));
  }
}
#pragma pop
#pragma pop

u16 *get_entry_text(s32 i, s32 len) {
    u16 *out;
    s32 n;
    s32 end;
    s32 r;
    QuestDownloadTextNode *node;
    out = lbl_805A0340;
    end = i + len;
    while (i < end && (n = TQuestVmDownLoadServer__sub_803E9F54(i)) != 0) {
        if (i == quest_text_cursor_pos) {
            if (lbl_805D78E8 == 1 || quest_download_state >= 3) {
                node = advance_quest_text_entries(quest_page_node_head, quest_page_node_index);
            } else {
                node = advance_quest_text_entries(quest_download_slot_chain_table[i].chain, 0);
            }
            r = write_entry_group_text(i, n, node, out);
        } else {
            r = write_entry_group_text(i, n, quest_download_slot_chain_table[i].chain, out);
        }
        out += r;
        i += n;
    }
    TQuestVmDownLoadServer__sub_803EC71C((u16 *)lbl_805A0340, (u8 *)lbl_805A02A8, (s32)(out - lbl_805A0340));
    return lbl_805A02A8;
}

u8 *convert_all_entry_text(void) {
    TQuestVmDownLoadServer__sub_803EC71C((u16 *)(((u8 *)&lbl_805A0340)), (u8 *)(((u8 *)&lbl_805A02A8)), (s32)(build_all_entry_text()));
    return ((u8 *)&lbl_805A02A8);
}

// Drops the node chain of a slot; in mode 1 the nodes before the current
// position are first returned to the download entry pool.
void free_slot_node_chain(s32 slot, s32 mode) {
    QuestDownloadTextNode *p;
    QuestDownloadTextNode *end;
    QuestDownloadTextNode *next;
    if ((p = quest_download_slot_chain_table[slot].chain) != NULL) {
        if (mode == 1 && (lbl_805D78E8 == 1 || quest_download_state >= 3)) {
            end = advance_quest_text_entries(quest_page_node_head, quest_page_node_index);
            while (p != NULL) {
                if (p == end) {
                    break;
                }
                next = next_quest_text_entry(p);
                TQuestVmDownLoadServer::push_download_entry(p);
                p = next;
            }
            quest_download_slot_chain_table[slot].chain = p;
        }
        free_quest_text_chain(detach_quest_text_tail(p));
    }
}

s32 build_all_entry_text(void) {
    s32 r;
    QuestDownloadTextNode *node;
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
                node = advance_quest_text_entries(quest_page_node_head, quest_page_node_index);
            } else {
                node = advance_quest_text_entries(quest_download_slot_chain_table[i].chain, 0);
            }
            r = write_entry_group_text(i, n, node, out);
            quest_text_entry_len = n;
            TQuestVmDownLoadServer__set_text_run_attr(out, r, 7);
        } else {
            r = write_entry_group_text(i, n, quest_download_slot_chain_table[i].chain, out);
            TQuestVmDownLoadServer__set_text_run_attr(out, r, 6);
        }
        out += r;
        i += n;
        total += r;
    }
    return total;
}

s32 format_number_text_all_modes(const u8 *format, s32 length, QuestDownloadTextRecord *out, s32 *count) {
    s32 i;
    u8 *r;
    if (quest_download_file_handle == -1) {
        return -3;
    }
    *count = 0;
    r = TQuestVmDownLoadServer::format_number_text(format, length, out, lbl_805D78FC);
    if (r != 0) {
        out = reinterpret_cast<QuestDownloadTextRecord *>(r);
        (*count)++;
    }
    for (i = 0; i < 4; i++) {
        if (i != lbl_805D78FC) {
            r = TQuestVmDownLoadServer::format_number_text(format, length, out, i);
            if (r != 0) {
                out = reinterpret_cast<QuestDownloadTextRecord *>(r);
                (*count)++;
            }
        }
    }
    return 1;
}

struct Tbl_803EEB10 {
    u8 units[0x14];
    u8 fullwidth_digits[0x18];
    u8 kanji_digits[0x18];
    const u8 *sets[3];
};
// The digit and unit kanji the number formatter writes (Shift-JIS):
// units = 拾壱弐参十百千万億兆 (no terminator), fullwidth_digits = ０..９,
// kanji_digits = 〇一二三四五六七八九. The unit text also supplies set 2 (壱弐参).
const Tbl_803EEB10 quest_download_number_text_table = {
    {0x8F, 0x45, 0x88, 0xEB, 0x93, 0xF3, 0x8E, 0x51, 0x8F, 0x5C,
     0x95, 0x53, 0x90, 0xE7, 0x96, 0x9C, 0x89, 0xAD, 0x92, 0x9B},
    "\x82\x4F\x82\x50\x82\x51\x82\x52\x82\x53\x82\x54\x82\x55\x82\x56\x82\x57\x82\x58",
    "\x81\x5A\x88\xEA\x93\xF1\x8E\x4F\x8E\x6C\x8C\xDC\x98\x5A\x8E\xB5\x94\xAA\x8B\xE3",
    {quest_download_number_text_table.fullwidth_digits, quest_download_number_text_table.kanji_digits,
     quest_download_number_text_table.units},
};

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

#define n ((s16)num)
u8 *TQuestVmDownLoadServer::format_number_text(const u8 *input, s32 num, QuestDownloadTextRecord *o, s32 mode) {
    const u8 *s = input;
    const Tbl_803EEB10 *t = &quest_download_number_text_table;
    s32 u;
    const u8 *const *mp;
    const u8 *const *up;
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
    o->key = mode;
    o->attribute = 0;
    o->extra = 0;
    p = o->text;
    mp = reinterpret_cast<const u8 *const *>(reinterpret_cast<const u8 *>(&t->sets) + mode * sizeof(t->sets[0]));
    mark = p;
    up = &t->sets[2];
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
            *p++ = (*reinterpret_cast<const u8 *const *>(reinterpret_cast<const u8 *>(&t->sets) + set * sizeof(t->sets[0])))[d * 2];
            *p++ = (*reinterpret_cast<const u8 *const *>(reinterpret_cast<const u8 *>(&t->sets) + set * sizeof(t->sets[0])))[d * 2 + 1];
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
inline u32 Call_803EED0C(const u8 *input, s32 length, QuestDownloadTextRecord *output, s32 mode) {
    return reinterpret_cast<uaddr>(TQuestVmDownLoadServer::format_number_text(input, length, output, mode));
}
s32 TQuestVmDownLoadServer__sub_803EED0C(const u8 *input, s32 length, QuestDownloadTextRecord *output) {
    if (quest_download_file_handle == -1) {
        return -3;
    }
    if (Call_803EED0C(input, length, output, lbl_805D78FC) == 0) {
        Call_803EED0C(input, length, output, 0);
    }
    return 1;
}
#pragma pop

s32 TQuestVmDownLoadServer::get_download_state() {
    return lbl_805D7900;
}

s32 TQuestVmDownLoadServer__sub_803EED9C(u32 index) {
    TQuestVmDownLoadServer::release_ref_slot(index);
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
                TQuestVmDownLoadServer__sub_803EF8E0(TQuestVmDownLoadServer::get_cached_page(page) + a);
                TQuestVmDownLoadServer::set_active();
            }
            if (b != -1) {
                TQuestVmDownLoadServer__sub_803EF8E0(TQuestVmDownLoadServer::get_buffer_ptr(b));
                mark_name_cache_dirty();
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
s32 TQuestVmDownLoadServer__sub_803EEDC0(QuestDownloadRequest *req, s32 *ids, s32 n) {
    char buf[0x50];
    s32 v;
    if (lbl_805D7900 == 0) {
        return 3;
    }
    if (quest_download_file_handle == -1) {
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
    store_name_record(buf, req, v);
    TQuestVmDownLoadServer::set_slot_values_for_indices(ids, n, v);
    return 3;
}
#pragma pop

s32 TQuestVmDownLoadServer__sub_803EEF2C(QuestDownloadRequest *req) {
    char buf[0x50];
    if (lbl_805D7900 == 0) {
        return 3;
    }
    if (quest_download_file_handle == -1) {
        return -3;
    }
    strncpy(buf, req->name, req->len);
    if (req->x7 == 0x28 || req->x7 == 0x29) {
        req->x7 = 0x27;
    }
    buf[req->len] = 0;
    store_name_record(buf, req, 1);
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
s32 TQuestVmDownLoadServer__sub_803EEFC8(u8 *rec, QuestDownloadRequest *msg) {
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

s32 TQuestVmDownLoadServer__sub_803EF208(QuestDownloadRequest *msg) {
    u8 *end;
    u8 *p;
    s32 not_found = 1;
    u8 n;
    s32 c;
    s32 size;
    char buf[0x50];
    if (quest_download_file_handle == -1) {
        return -3;
    }
    if (lbl_805D78F8 == 0x8000) {
        return -6;
    }
    strncpy(buf, msg->name, msg->len);
    buf[msg->len] = 0;
    p = TQuestVmDownLoadServer::get_cached_page(TQuestVmDownLoadServer::find_name_index(reinterpret_cast<const char *>(buf)));
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

s32 TQuestVmDownLoadServer__sub_803EF538(QuestDownloadRequest *msg) {
    u8 *end;
    u8 *page;
    u8 *p;
    s32 is_new = 1;
    u8 n;
    s32 c;
    s32 len;
    s32 size;
    char buf[0x50];
    if (quest_download_file_handle == -1) {
        return -3;
    }
    if (lbl_805D78F8 == 0x8000) {
        return -6;
    }
    strncpy(buf, msg->name, msg->len);
    buf[msg->len] = 0;
    page = TQuestVmDownLoadServer::get_cached_page(TQuestVmDownLoadServer::find_name_index(reinterpret_cast<const char *>(buf)));
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
    len = is_new ? msg->calc_message_length() : msg->calc_text_length();
    if (end > page + 0x3FE - len) {
        return -5;
    }
    if (is_new) {
        shift_tail_bytes(p, end + 2, len);
        TQuestVmDownLoadServer::build_message_packet(p, len, msg, 0);
        if (msg->len <= 2) {
            TQuestVmDownLoadServer__sub_803E7F9C((u8 *)buf, msg->len);
        }
    } else {
        shift_tail_bytes(p + (u16)(p[0] + (p[1] << 8)), end + 2, len);
        TQuestVmDownLoadServer::append_message_text(p, len, msg, max_entry_index(p) + 1);
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
    if (quest_download_file_handle == -1) {
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
            base = TQuestVmDownLoadServer::get_cached_page(page) + a;
        }
        v = ((TQuestVmDownLoadServer *)ids)->get_max_size_of_indices(n);
        p = base + (off & ~0x8000) + 1;
        if (*p != 0 && *p == v) {
            if (key & 0x8000) {
                relocate_name_record(b);
                mark_name_cache_dirty();
            }
            return 3;
        }
        if (++v == 0xFF) {
            release_index_entries(ids, n);
            v = 1;
        }
        *p = v;
        if (key & 0x8000) {
            relocate_name_record(b);
            mark_name_cache_dirty();
        } else {
            TQuestVmDownLoadServer::set_active();
        }
        TQuestVmDownLoadServer::set_slot_values_for_indices(ids, n, v);
        return 3;
    }
}
#pragma pop

QuestDownloadTextRecord *TQuestVmDownLoadServer::find_insert_position(u8 *buffer, s32 key, s32 n, s32 len) {
    u8 *p = buffer;
    u8 *end = p + len;
    u8 *s;
    u8 *d;
    while (p < end) {
        if (reinterpret_cast<const QuestDownloadTextRecord *>(p)->attribute < key) {
            break;
        }
        p += 5;
        while (*p++ != 0) {
        }
        if ((uaddr)p & 1) {
            p++;
        }
    }
    if (p < end) {
        for (s = end - 1; s >= p; s--) {
            s[n] = *s;
        }
    }
    return reinterpret_cast<QuestDownloadTextRecord *>(p);
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
    QuestDownloadTextRecord *out;
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
            out = TQuestVmDownLoadServer::find_insert_position(buf, value, size, *total);
            out->key = flags | (rec - data);
            text = rec + 2;
            out->attribute = rec[1];
            out->extra = 0;
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

s32 TQuestVmDownLoadServer::read_quest_chunk(u32 id, u8 key, u8 sub_key, u8 *buf, s32 *out) {
    s32 a;
    s32 b;
    s32 cnt;
    s32 total;
    s32 r;
    s32 v;
    if (quest_download_file_handle == -1) {
        return -3;
    }
    r = TQuestVmDownLoadServer__sub_803E779C(id, &a, &b, &cnt);
    if (r == -1) {
        return 0;
    }
    cnt = 0;
    total = 0;
    if (a != -1) {
        TQuestVmDownLoadServer__sub_803EFCB4(TQuestVmDownLoadServer::get_cached_page(r) + a, key, sub_key, &cnt, &total, buf, 0);
    }
    if (b != -1) {
        TQuestVmDownLoadServer__sub_803EFCB4(TQuestVmDownLoadServer::get_buffer_ptr(b), key, sub_key, &cnt, &total, buf, 0x8000);
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
    QuestDownloadTextRecord *out;
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
        out = (QuestDownloadTextRecord *)dst;
        out->key = flags | (found - data);
        text = found + 2;
        out->attribute = found[1];
        out->extra = 0;
        if (found[2] <= 0xB) {
            text++;
        }
        TQuestVmDownLoadServer::unescape_copy_string(out->text, text, end);
    }
}

s32 TQuestVmDownLoadServer__sub_803F0048(s32 id, u8 key, u8 sub_key, void *dst) {
    s32 a;
    s32 b;
    s32 c;
    s32 best;
    s32 page;
    if (quest_download_file_handle == -1) {
        return -3;
    }
    page = TQuestVmDownLoadServer__sub_803E779C(id, &a, &b, &c);
    if (page == -1) {
        return 0;
    }
    best = -1;
    if (a != -1) {
        TQuestVmDownLoadServer__sub_803EFF20(TQuestVmDownLoadServer::get_cached_page(page) + a, key, sub_key, &best, (u8 *)dst, 0);
    }
    if (b != -1) {
        TQuestVmDownLoadServer__sub_803EFF20(TQuestVmDownLoadServer::get_buffer_ptr(b), key, sub_key, &best, (u8 *)dst, 0x8000);
    }
    if (best == -1) {
        return 0;
    }
    return 1;
}

s32 TQuestVmDownLoadServer::find_symbol_entry(const char *name, s16 len, QuestSymbolLookupResult *out) {
    s32 id;
    u8 n;
    u8 *base;
    u8 *p;
    s32 c;
    if (len <= 2 && is_char_allowed(reinterpret_cast<const u8 *>(name), len) != 0) {
        out->record_offset = -1;
        return 0;
    }
    id = TQuestVmDownLoadServer::find_name_index(name);
    base = TQuestVmDownLoadServer::get_cached_page(id);
    p = base;
    while ((u16)(p[0] + (p[1] << 8)) != 0) {
        n = p[2];
        c = strncmp((const char *)(p + 3), name, (s16)n);
        if (c == 0) {
            if ((s16)n == len) {
                break;
            }
        } else if (c > 0) {
            out->record_offset = -1;
            return 0;
        }
        p += (u16)(p[0] + (p[1] << 8));
    }
    if ((u16)(p[0] + (p[1] << 8)) == 0) {
        out->record_offset = -1;
        return 0;
    }
    out->page_index = id;
    out->record_offset = p - base;
    out->encodedRecord = p;
    return 1;
}

s32 TQuestVmDownLoadServer__sub_803F0268(const char *name, s16 len, QuestDownloadQueryResult *out) {
    char buf[0x50];
    QuestSymbolLookupResult i1;
    QuestNameLookupResult i2;
    s32 max;
    s32 r1;
    s32 r2;
    u32 r;
    if (quest_download_file_handle == -1) {
        return -3;
    }
    strncpy(buf, name, len);
    buf[len] = 0;
    r1 = TQuestVmDownLoadServer::find_symbol_entry(buf, len, &i1);
    r2 = TQuestVmDownLoadServer::lookup_name_entry(buf, len, &i2);
    if (r1 == 0 && r2 == 0) {
        return 0;
    }
    out->len = len;
    out->len2 = len;
    out->xa = 1;
    out->count = 0;
    max = 0;
    if (r1 == 1) {
        out->count = TQuestVmDownLoadServer__sub_803F03B4(i1.encodedRecord, out->entries, 0, &max);
    }
    if (r2 == 1) {
        out->count = TQuestVmDownLoadServer__sub_803F03B4(i2.encodedRecord, out->entries, out->count, &max);
    }
    out->x4 = r = TQuestVmDownLoadServer::acquire_slot_entry(i1.page_index, i1.record_offset, i2.record_id, max);
    if (r == 0xFFFFFFFF) {
        return 0;
    }
    return 1;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline s32 merge_duplicate_entry(QuestDownloadQueryEntry *begin, QuestDownloadQueryEntry *e) {
    QuestDownloadQueryEntry *q;
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

s32 TQuestVmDownLoadServer__sub_803F03B4(u8 *data, QuestDownloadQueryEntry *cur, s32 n, s32 *max) {
  u8 *end;
  QuestDownloadQueryEntry *e = cur;
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

s32 TQuestVmDownLoadServer__sub_803F0500(u8 *name, s16 len, QuestNameLookupResult *out) {
    s16 blen;
    s16 cnt;
    s16 pre;
    saddr idx;
    s32 first;
    u8 *page;
    u8 *p;
    u8 *found;
    u8 n;
    first = 1;
    out->prefix_length = 0;
    out->match_length = 0;
    idx = TQuestVmDownLoadServer::find_name_index(reinterpret_cast<const char *>(name));
    if (TQuestVmDownLoadServer::has_name_mismatch(idx, name) == 0) {
        return 2;
    }
    pre = 0;
    for (;;) {
        page = TQuestVmDownLoadServer::get_cached_page(idx);
        p = page;
        cnt = TQuestVmDownLoadServer::count_matching_name_prefix(idx, name);
        blen = 0;
        for (; (u16)(p[0] + (p[1] << 8)) != 0; p += (u16)(p[0] + (p[1] << 8))) {
            s16 m;
            s32 r;
            n = p[2];
            m = TQuestVmDownLoadServer::match_prefix_length(p + 3, name, (s16)n);
            if (m >= pre) {
                pre = m + 1;
            }
            r = strncmp((char *)(p + 3), (char *)name, (s16)n);
            if (r == 0) {
                if ((s16)n == len && first) {
                    return 2;
                }
                blen = n;
                found = p;
            } else if (r > 0) {
                if (strncmp((char *)(p + 3), (char *)name, len) == 0 && first) {
                    return 2;
                }
                break;
            }
        }
        if (blen > 0) {
            break;
        }
        if (cnt <= 1) {
            out->record_id = -1;
            return 0;
        }
        len = cnt - 1;
        name[len] = 0;
        idx = TQuestVmDownLoadServer::find_name_index(reinterpret_cast<const char *>(name));
        first = 0;
    }
    out->page_index = idx;
    out->record_id = found - page;
    out->match_length = blen;
    out->prefix_length = pre;
    out->encodedRecord = found;
    return 1;
}

s32 TQuestVmDownLoadServer__sub_803F06B8(const char *name, s16 len, QuestDownloadQueryResult *out) {
    char buf[0x50];
    QuestNameLookupResult o1;
    QuestNameLookupResult o2;
    s32 max;
    s32 r1;
    s32 r2;
    s32 n;
    u32 r;
    if (quest_download_file_handle == -1) {
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
    r2 = lookup_name_prefix(buf, len, &o2);
    if (r2 == 2) {
        return 2;
    }
    if (r1 == 0 && r2 == 0) {
        return 0;
    }
    out->xa = 1;
    max = 0;
    out->len2 = o1.prefix_length > o2.prefix_length ? o1.prefix_length : o2.prefix_length;
    if (o1.match_length > o2.match_length) {
        out->len = o1.match_length;
        out->count = TQuestVmDownLoadServer__sub_803F03B4(o1.encodedRecord, out->entries, 0, &max);
        o2.record_id = -1;
    } else if (o1.match_length < o2.match_length) {
        out->len = o2.match_length;
        out->count = TQuestVmDownLoadServer__sub_803F03B4(o2.encodedRecord, out->entries, 0, &max);
        o1.record_id = -1;
    } else {
        out->len = o1.match_length;
        n = TQuestVmDownLoadServer__sub_803F03B4(o1.encodedRecord, out->entries, 0, &max);
        out->count = TQuestVmDownLoadServer__sub_803F03B4(o2.encodedRecord, out->entries, n, &max);
    }
    out->x4 = r = TQuestVmDownLoadServer::acquire_slot_entry(o1.page_index, o1.record_id, o2.record_id, max);
    if (r == 0xFFFFFFFF) {
        return 0;
    }
    return 1;
}

s32 TQuestVmDownLoadServer__sub_803F0890(void) {
    if ((s32) quest_download_file_handle == -1) {
        return -3;
    }
    TQuestVmDownLoadServer__sub_803E8150();
    save_name_cache();
    TQuestVmDownLoadServer::retry_seek_active_entries();
    if (TQuestVmDownLoadServer__sub_803E86C8() == -1) {
        return -2;
    }
    return 3;
}

s32 TQuestVmDownLoadServer__sub_803F08E4(s8 *quest_vm_down_load_server) {
    s32 r;

    if (quest_download_file_handle != -1) {
        return -4;
    }
    if (*quest_vm_down_load_server == 0) {
        return -1;
    }
    TQuestVmDownLoadServer::set_file_info_name(reinterpret_cast<const char *>(quest_vm_down_load_server));
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

}

u16 lbl_805A02A8[0x4C];
u16 lbl_805A0340[0x98];
u8 quest_download_scratch_storage[0x28] ATTRIBUTE_ALIGN(4);
QuestDownloadInputEntry quest_download_entry_table[39];
u16 quest_download_buffer_storage[0x64] ATTRIBUTE_ALIGN(4);
QuestDownloadRequestStorage lbl_805A0698;
