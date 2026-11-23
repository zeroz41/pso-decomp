#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer_803E6970.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/QuestDownloadServer.h"

#pragma dont_inline off
#pragma inline_depth(2)

extern "C" {
QuestDownloadNameCacheImage lbl_80591EC8;
QuestDownloadCachedNameIndex lbl_80593EC8;
u8 lbl_805D7868;
u8 *lbl_805D786C;
u8 *lbl_805D7870;
s32 lbl_805D7874;
QuestDownloadCachedNameNode *lbl_805D7878;
void mark_name_cache_dirty(void) {
    lbl_805D7868 = 1;
}

void rotate_cache_page(void);

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

inline QuestDownloadCachedNameNode *FindName_80591EC8(char *buf, s16 len, QuestDownloadCachedNameNode ***plink) {
    QuestDownloadCachedNameNode *n;
    QuestDownloadCachedNameNode *prev = NULL;
    s32 h;
    h = Hash_80591EC8(buf);
    for (n = lbl_80593EC8.heads[h]; n != NULL; n = n->next) {
        s32 r;
        u8 elen = n->encodedRecord[2];
        r = strncmp((char *)(n->encodedRecord + 3), buf, (s16)elen);
        if (r == 0) {
            if (len == (s16)elen) {
                break;
            }
        } else if (r > 0) {
            break;
        }
        prev = n;
    }
    *plink = prev == NULL ? &lbl_80593EC8.heads[h] : &prev->next;
    return n;
}

void relocate_name_record(s32 id) {
    char buf[0x50];
    s32 unused[3];
    s16 page;
    int page_wide;
    u8 *p;
    s16 len;
    u8 *dst;
    s16 elen;
    QuestDownloadCachedNameNode *n;
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
        rotate_cache_page();
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
    n = lbl_80593EC8.heads[h];
    while (n != NULL) {
        elen = n->encodedRecord[2];
        r = strncmp((char *)(n->encodedRecord + 3), buf, elen);
        if (r == 0) {
            if (len == elen) {
                break;
            }
        } else if (r > 0) {
            break;
        }
        n = n->next;
    }

    if (n->encodedRecord != p) {
        return;
    }
    n->encodedRecord = dst;
    while (size != 0) {
        *dst++ = *p++;
        size--;
    }

    rec[2] = 0;
    TQuestVmDownLoadServer::invalidate_entries_by_id(id);
}

// Id of a name-cache record: its 0x400-byte page in bits 12 and up, its offset in the page below.
inline s32 NameRecordId_80591EC8(QuestDownloadNameCacheImage *cache, void *rec) {
    s32 off = (u8 *)rec - (u8 *)cache;
    return ((off / 1024) << 12) | (off % 1024);
}

s32 TQuestVmDownLoadServer::lookup_name_entry(char *name, s16 name_len, QuestNameLookupResult *out) {
    QuestDownloadCachedNameNode *n;
    s32 r;
    u8 len;
    u8 *e;
    for (n = lbl_80593EC8.heads[Hash_80591EC8(name)]; n != NULL; n = n->next) {
        e = n->encodedRecord;
        len = e[2];
        r = strncmp((char *)(e + 3), name, (s16)len);
        if (r == 0) {
            if ((s16)len == name_len) {
                break;
            }
        } else if (r > 0) {
            out->record_id = -1;
            return 0;
        }
    }
    if (n == NULL) {
        out->record_id = -1;
        return 0;
    }
    out->page_index = 0;
    out->record_id = NameRecordId_80591EC8(&lbl_80591EC8, e);
    out->encodedRecord = e;
    return 1;
}

s32 lookup_name_prefix(char *name, s16 name_len, QuestNameLookupResult *out) {
    QuestDownloadCachedNameNode *n;
    u8 *e;
    s16 len;
    u8 *found;
    s16 pre;
    s16 blen;
    s32 r;
    s16 m;
    blen = 0;
    pre = 0;
    out->prefix_length = 0;
    out->match_length = 0;
    for (n = lbl_80593EC8.heads[Hash_80591EC8(name)]; n != NULL; n = n->next) {
        e = n->encodedRecord;
        len = e[2];
        m = TQuestVmDownLoadServer::match_prefix_length(e + 3, (u8 *)name, (s16)len);
        if (m >= pre) {
            pre = m + 1;
        }
        r = strncmp((char *)(e + 3), name, (s16)len);
        if (r == 0) {
            if ((s16)len == name_len) {
                return 2;
            }
            blen = len;
            found = e;
        } else if (r > 0) {
            if (strncmp((char *)(e + 3), name, name_len) == 0) {
                return 2;
            }
            break;
        }
    }
    if (blen == 0) {
        out->record_id = -1;
        return 0;
    }
    out->page_index = 0;
    out->record_id = NameRecordId_80591EC8(&lbl_80591EC8, found);
    out->match_length = blen;
    out->prefix_length = pre;
    out->encodedRecord = found;
    return 1;
}

inline s32 RecordSize_803E8DA0(QuestDownloadRequest *req) {
    s32 extra;
    if (req->x8 != 0 || req->x7 >= 0x2D) {
        extra = 3;
    } else {
        extra = 2;
    }
    return 3 + req->len + extra + TQuestVmDownLoadServer::calc_sjis_string_width(req->text);
}
inline void WriteRecord_803E8DA0(u8 *p, s32 size, QuestDownloadRequest *req, u8 attr) {
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
        rotate_cache_page();
    }
    p = lbl_805D7870;
    lbl_805D7870 += size;
    lbl_805D7870[0] = 0;
    lbl_805D7870[1] = 0;
    return p;
}
s32 store_name_record(char *name, QuestDownloadRequest *req, s32 attr) {
    QuestDownloadNameCacheImage *cache;
    QuestDownloadCachedNameNode *n;
    QuestDownloadCachedNameNode *node;
    QuestDownloadCachedNameNode **link;
    u8 *e;
    s32 size;
    u8 *rec;
    lbl_805D7868 = 1;
    cache = &lbl_80591EC8;
    n = FindName_80591EC8(name, req->len, &link);
    e = n->encodedRecord;
    if (e[2] == req->len && strncmp(name, (char *)(e + 3), req->len) == 0) {
        e[2] = 0;
        *link = n->next;
        TQuestVmDownLoadServer::invalidate_entries_by_id(NameRecordId_80591EC8(cache, n->encodedRecord));
        n->next = lbl_805D7878;
        lbl_805D7878 = n;
    }
    if (lbl_805D7878 == NULL) {
        rotate_cache_page();
    }
    node = lbl_805D7878;
    lbl_805D7878 = node->next;
    size = RecordSize_803E8DA0(req);
    rec = AllocRecord_80591EC8(size);
    WriteRecord_803E8DA0(rec, size, req, attr);
    n = FindName_80591EC8(name, req->len, &link);
    node->encodedRecord = rec;
    node->next = n;
    *link = node;
    return 0;
}

void TQuestVmDownLoadServer::append_message_text(u8 *record, s32 size, QuestDownloadRequest *msg, u8 attr) {
    u16 cur;
    s32 v;
    u8 *p;
    u8 *s;
    cur = record[0];
    cur += record[1] << 8;
    v = size + cur;
    record[0] = v % 256;
    record[1] = v / 256;
    p = record + cur;
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
void TQuestVmDownLoadServer::build_message_packet(u8 *p, s32 size, QuestDownloadRequest *msg, u8 attr) {
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

s32 QuestDownloadRequest::calc_text_length() const {
    const QuestDownloadRequest *msg = this;
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

s32 QuestDownloadRequest::calc_message_length() const {
    const QuestDownloadRequest *msg = this;
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

// The original code addresses the name index relative to the eight page images.
#ifdef __MWERKS__
#define QUEST_DOWNLOAD_CACHE_INDEX(base) reinterpret_cast<QuestDownloadCachedNameIndex *>((base) + sizeof(lbl_80591EC8))
#else
#define QUEST_DOWNLOAD_CACHE_INDEX(base) (&lbl_80593EC8)
#endif

#pragma push
#pragma opt_common_subs off
#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
// The caller supplies the copied, terminated name. The stopping node and its
// predecessor link are both needed by insertion and page rotation.
inline QuestDownloadCachedNameNode *find_cached_name_link(
        char *name, size_t cacheAddress, u8 inputLength, QuestDownloadCachedNameNode **&link) {
    s16 wanted;
    s32 bucket;
    QuestDownloadCachedNameNode *node;
    QuestDownloadCachedNameNode *previous;
    u8 recordLength;
    previous = NULL;
    u8 first = (u8)name[0];
    if (first >= 0xA0 && first < 0xF0) {
        bucket = first - 0xA0;
    } else {
        bucket = 0;
    }
    node = QUEST_DOWNLOAD_CACHE_INDEX(cacheAddress)->heads[bucket];
    wanted = (s16)inputLength;
    for (; node != NULL; node = node->next) {
        u8 *indexed = node->encodedRecord;
        recordLength = indexed[2];
        s32 comparison = strncmp((const char *)(indexed + 3), name, (s16)recordLength);
        if (comparison == 0) {
            if (wanted == (s16)recordLength) {
                break;
            }
        } else if (comparison > 0) {
            break;
        }
        previous = node;
    }
    if (previous == NULL) {
        link = &QUEST_DOWNLOAD_CACHE_INDEX(cacheAddress)->heads[bucket];
    } else {
        link = &previous->next;
    }
    return node;
}
#pragma push
#pragma inline_depth(2)
inline s32 read_name_image_bytes(s32 handle, u8 *image, s32 length) {
    return TQuestVmDownLoadServer::aram_read_thunk(handle, image, length);
}
// Keep the fixed cache-image read distinct from its byte-count adapter; their
// native inline lifetimes also determine the rebuild name-buffer offset.
inline s32 read_cached_name_image(s32 handle, u8 *image) {
    return read_name_image_bytes(handle, image, 0x2000);
}
#pragma pop

#pragma pop

#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
#pragma opt_common_subs off

s32 load_name_cache_image(void) {
    // Keep the decoded name at the retail stack offset.
    union {
        char name[0x50];
        f64 alignment;
    } scratch;
    u8 *pageStart;
    u8 *record;
    s32 page;
    u8 len;
    QuestDownloadCachedNameNode *node;
    QuestDownloadCachedNameNode **link;

    size_t cacheAddress = (size_t)&lbl_80591EC8;
    if (TQuestVmDownLoadServer::seek_or_reopen(0x1400) == -1) {
        return -1;
    }
    s32 readCount = (s32)read_cached_name_image(
            quest_download_file_handle, reinterpret_cast<u8 *>(&lbl_80591EC8));
    if (readCount != 0x2000) {
        return -1;
    }
    pageStart = reinterpret_cast<u8 *>(&lbl_80591EC8);
    for (page = 0; page < 8; page++, pageStart += 0x400) {
        for (record = pageStart;
             (u16)(record[0] + (record[1] << 8)) != 0;
             record += (u16)(record[0] + (record[1] << 8))) {
            len = record[2];
            if ((s16)len != 0) {
                strncpy(scratch.name, (const char *)(record + 3), (s16)len);
                scratch.name[(s16)len] = 0;
                node = find_cached_name_link(scratch.name, cacheAddress, len, link);
                if (lbl_805D7878 == NULL) {
                    rotate_cache_page();
                }
                QuestDownloadCachedNameNode *allocated = lbl_805D7878;
                lbl_805D7878 = allocated->next;
                allocated->encodedRecord = record;
                allocated->next = node;
                *link = allocated;
            }
        }
        if (lbl_805D7874 == page) {
            lbl_805D7870 = record;
            lbl_805D786C = pageStart + 0x400;
        }
    }
    return 0;
}

#pragma pop

u8 *TQuestVmDownLoadServer::get_buffer_ptr(s32 id) {
    return &lbl_80591EC8.pages[(s16)(id >> 12)][(s16)(id & 0xFFF)];
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
#pragma opt_common_subs off

void rotate_cache_page(void) {
    char name[0x50];

    size_t cacheAddress = (size_t)&lbl_80591EC8;
    u8 *cacheBytes = reinterpret_cast<u8 *>(cacheAddress);
    u8 *record;
    u8 len;
    QuestDownloadCachedNameNode *node;
    QuestDownloadCachedNameNode **link;

    *lbl_805D7870++ = 0;
    *lbl_805D7870++ = 0;
    lbl_805D7874 = (lbl_805D7874 + 1) % 8;
    lbl_805D7870 = cacheBytes + lbl_805D7874 * 0x400;
    lbl_805D786C = lbl_805D7870 + 0x400;
    for (record = lbl_805D7870;
         (u16)(record[0] + (record[1] << 8)) != 0;
         record += (u16)(record[0] + (record[1] << 8))) {
        len = record[2];
        if ((s16)len != 0) {
            strncpy(name, (const char *)(record + 3), (s16)len);
            name[(s16)len] = 0;
            node = find_cached_name_link(name, cacheAddress, len, link);
            // The native code also requires a non-null stopping node here.
            if (node->encodedRecord == record) {
                *link = node->next;
                node->next = lbl_805D7878;
                lbl_805D7878 = node;
            }
        }
    }
    TQuestVmDownLoadServer::clear_entries_by_id(lbl_805D7874);
}

#pragma pop

void save_name_cache(void) {
    if (lbl_805D7868 != 0) {
        if (TQuestVmDownLoadServer::seek_or_reopen(0x1400) != -1) {
            TQuestVmDownLoadServer__sub_803E8788(quest_download_file_handle, lbl_80591EC8.pages, 0x2000);
        }
    }
}

#pragma push
#pragma opt_common_subs off

void __VIRetraceHandler(void) {
    size_t cacheAddress = (size_t)&lbl_80591EC8;
    QuestDownloadCachedNameNode *node = QUEST_DOWNLOAD_CACHE_INDEX(cacheAddress)->nodes;
    QuestDownloadCachedNameNode *end = node + 511;
    for (; node < end; node++) {
        node->next = node + 1;
    }
    node->next = NULL;
    lbl_805D7878 = QUEST_DOWNLOAD_CACHE_INDEX(cacheAddress)->nodes;
    for (u32 i = 0; i < 80; i++) {
        QUEST_DOWNLOAD_CACHE_INDEX(cacheAddress)->heads[i] = NULL;
    }
    if (load_name_cache_image() == -1) {
        u8 *bytes = reinterpret_cast<u8 *>(cacheAddress);
        u8 *page = bytes;
        for (s32 i = 0; i < 8; i++) {
            page[1] = 0;
            page[0] = 0;
            page += 0x400;
        }
        lbl_805D7874 = 0;
        lbl_805D7870 = bytes;
        // Rewind the completed page walk to the end of the first append page.
        lbl_805D786C = page -= sizeof(lbl_80591EC8) - 0x400;
    }
    lbl_805D7868 = 0;
}

#pragma pop

}
