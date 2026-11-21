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
struct Hdr_803EA384 {
    s16 len;
    u32 x4;
    s16 len2;
    s16 xa;
    s16 count;
    QuestDownloadQueryEntry entries[32];
};
typedef Hdr_803EA384 QuestDownloadQueryResult;

struct QuestDownloadWorkspace {
    u8 reserved[0x8C0];
    QuestDownloadQueryResult result;
};

struct QuestDownloadDisplayPrefix { u8 text[12]; };

// These buffers are used synchronously as bytes, character codes, or item IDs.
struct QuestDownloadScratchWords { u16 values[0x202]; };
struct QuestDownloadScratchIds { s32 values[0x101]; };

extern "C" {
extern QuestDownloadWorkspace lbl_80595008;
extern QuestDownloadDisplayPrefix lbl_80596258;
extern u8 quest_download_text_buffer[0x404] ATTRIBUTE_ALIGN(4);
}

LAYOUT_ASSERT(QuestDownloadQueryEntrySize, sizeof(QuestDownloadQueryEntry) == 6);
LAYOUT_ASSERT(QuestDownloadQueryEntriesOffset, offsetof(QuestDownloadQueryResult, entries) == 14);
LAYOUT_ASSERT(QuestDownloadQueryResultSize, sizeof(QuestDownloadQueryResult) == 0xD0);
LAYOUT_ASSERT(QuestDownloadWorkspaceResultOffset, offsetof(QuestDownloadWorkspace, result) == 0x8C0);
LAYOUT_ASSERT(QuestDownloadWorkspaceSize, sizeof(QuestDownloadWorkspace) == 0x990);
LAYOUT_ASSERT(QuestDownloadDisplayPrefixSize, sizeof(QuestDownloadDisplayPrefix) == 0xC);
LAYOUT_ASSERT(QuestDownloadScratchWordsSize, sizeof(QuestDownloadScratchWords) == 0x404);
LAYOUT_ASSERT(QuestDownloadScratchIdsSize, sizeof(QuestDownloadScratchIds) == 0x404);

enum QuestDownloadScratchPlacement { quest_download_scratch_words_or_ids };
#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline void *operator new(size_t, void *storage, QuestDownloadScratchPlacement) {
    return storage;
}
#pragma pop

#endif
