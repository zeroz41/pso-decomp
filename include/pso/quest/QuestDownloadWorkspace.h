#ifndef PSO_QUEST_QUESTDOWNLOADWORKSPACE_H
#define PSO_QUEST_QUESTDOWNLOADWORKSPACE_H

#include "types.h"
#include "pso/quest/QuestDownloadRecords.h"
#include <stddef.h>

struct QuestDownloadItemNode;
struct QuestDownloadMatchToken;

struct QuestDownloadQueryEntry {
    u8 a;
    u8 b;
    u8 c;
    u8 pad;
    u16 key;
};

// The original query appends six-byte entries and stops at 32.
struct QuestDownloadQueryResult {
    s16 len;
    u32 x4;
    s16 len2;
    s16 xa;
    s16 count;
    QuestDownloadQueryEntry entries[32];
};

struct QuestDownloadWorkspace {
    u8 reserved[0x8C0];
    QuestDownloadQueryResult result;
};

struct QuestDownloadDisplayPrefix { u8 text[12]; };

// Text scratch used synchronously as bytes, character codes, or item IDs.
union QuestDownloadTextBuffer {
    u8 bytes[0x404];
    u16 words[0x202];
    s32 ids[0x101];
};

extern "C" {
extern QuestDownloadWorkspace conversion_workspace;
extern QuestDownloadDisplayPrefix quest_download_display_prefix;
extern QuestDownloadTextBuffer quest_download_text_buffer;
}

LAYOUT_ASSERT(QuestDownloadQueryEntrySize, sizeof(QuestDownloadQueryEntry) == 6);
LAYOUT_ASSERT(QuestDownloadQueryEntriesOffset, offsetof(QuestDownloadQueryResult, entries) == 14);
LAYOUT_ASSERT(QuestDownloadQueryResultSize, sizeof(QuestDownloadQueryResult) == 0xD0);
LAYOUT_ASSERT(QuestDownloadWorkspaceResultOffset, offsetof(QuestDownloadWorkspace, result) == 0x8C0);
LAYOUT_ASSERT(QuestDownloadWorkspaceSize, sizeof(QuestDownloadWorkspace) == 0x990);
LAYOUT_ASSERT(QuestDownloadDisplayPrefixSize, sizeof(QuestDownloadDisplayPrefix) == 0xC);
LAYOUT_ASSERT(QuestDownloadTextBufferSize, sizeof(QuestDownloadTextBuffer) == 0x404);

#endif
