#ifndef PSO_QUEST_DOWNLOAD_CACHE_TYPES_H
#define PSO_QUEST_DOWNLOAD_CACHE_TYPES_H

#include "types.h"
#include <stddef.h>

struct QuestDownloadCacheEntry {
    u8 referenceCount;
    u8 value;
    u16 pageIndex;
    s16 fileOffset;
    s16 cachedId;
};

struct QuestDownloadCachePage {
    s32 pageIndex;
    s32 state;
    QuestDownloadCachePage *next;
    u8 bytes[0x400];
};

// The 128 slot records precede the ten file pages in quest_download_slot_table.
struct QuestDownloadFileCache {
    QuestDownloadCacheEntry entries[128];
    QuestDownloadCachePage pages[10];
};

struct QuestDownloadCachedNameNode {
    // Two little-endian size bytes and a name-length byte precede the name.
    u8 *encodedRecord;
    QuestDownloadCachedNameNode *next;
};

// Each bucket points into the shared pool of 512 nodes.
struct QuestDownloadCachedNameIndex {
    QuestDownloadCachedNameNode *heads[80];
    QuestDownloadCachedNameNode nodes[512];
};

#define QUEST_CACHE_CHECK(name, condition) typedef char name[(condition) ? 1 : -1]
QUEST_CACHE_CHECK(QuestCacheEntry_extent, sizeof(QuestDownloadCacheEntry) == 8);
QUEST_CACHE_CHECK(QuestCacheEntry_value, offsetof(QuestDownloadCacheEntry, value) == 1);
QUEST_CACHE_CHECK(QuestCacheEntry_page, offsetof(QuestDownloadCacheEntry, pageIndex) == 2);
QUEST_CACHE_CHECK(QuestCacheEntry_file, offsetof(QuestDownloadCacheEntry, fileOffset) == 4);
QUEST_CACHE_CHECK(QuestCacheEntry_cached, offsetof(QuestDownloadCacheEntry, cachedId) == 6);
QUEST_CACHE_CHECK(QuestCachePage_extent, sizeof(QuestDownloadCachePage) == 0x40C);
QUEST_CACHE_CHECK(QuestCachePage_state, offsetof(QuestDownloadCachePage, state) == 4);
QUEST_CACHE_CHECK(QuestCachePage_next, offsetof(QuestDownloadCachePage, next) == 8);
QUEST_CACHE_CHECK(QuestCachePage_bytes, offsetof(QuestDownloadCachePage, bytes) == 0xC);
QUEST_CACHE_CHECK(QuestFileCache_pages, offsetof(QuestDownloadFileCache, pages) == 0x400);
QUEST_CACHE_CHECK(QuestFileCache_extent, sizeof(QuestDownloadFileCache) == 0x2C78);
QUEST_CACHE_CHECK(QuestCachedNameNode_extent, sizeof(QuestDownloadCachedNameNode) == 8);
QUEST_CACHE_CHECK(QuestCachedNameNode_next, offsetof(QuestDownloadCachedNameNode, next) == 4);
QUEST_CACHE_CHECK(QuestCachedNameIndex_nodes, offsetof(QuestDownloadCachedNameIndex, nodes) == 0x140);
QUEST_CACHE_CHECK(QuestCachedNameIndex_extent, sizeof(QuestDownloadCachedNameIndex) == 0x1140);
#undef QUEST_CACHE_CHECK

#endif
