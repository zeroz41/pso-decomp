#ifndef PSO_QUEST_QUESTDOWNLOADRECORDS_H
#define PSO_QUEST_QUESTDOWNLOADRECORDS_H

#include "types.h"
#include <stddef.h>

struct QuestDownloadItemNode;
struct QuestDownloadMatchToken { u8 a; u8 b; u8 off; u8 d; };
typedef char QuestDownloadMatchTokenSize[sizeof(QuestDownloadMatchToken) == 4 ? 1 : -1];

// A matched sequence segment produced by the recursive dictionary search.
struct QuestDownloadSegment {
    s16 off;
    u8 reserved_2[2];
    u8 a;
    u8 b;
    u8 reserved_6[2];
    QuestDownloadSegment *next;
};

typedef char QuestDownloadSegmentSize[sizeof(QuestDownloadSegment) == 0xC ? 1 : -1];
typedef char QuestDownloadSegmentNext[offsetof(QuestDownloadSegment, next) == 8 ? 1 : -1];

// One fragment in a download text entry. The low flag bit joins the next
// fragment to this entry. The other fields are used by headed fragments.
struct QuestDownloadTextNode {
    u8 flags;
    u8 data[5];
    u8 len;
    u8 pad7;
    const QuestDownloadItemNode *source;
    u16 key;
    u16 attribute;
    QuestDownloadTextNode *next;
};

// A prefix is shared by candidate scoring and formatting.
struct QuestDownloadEntryPrefix {
    s16 off;
    u8 a;
    u8 b;
    const QuestDownloadItemNode *source;
};

struct QuestDownloadEntryNode {
    QuestDownloadEntryPrefix prefix;
    u16 cost;
    u16 base;
    QuestDownloadEntryNode *next;
};

typedef char QuestDownloadEntryPrefixSize[sizeof(QuestDownloadEntryPrefix) == 8 ? 1 : -1];
typedef char QuestDownloadEntryNodeSize[sizeof(QuestDownloadEntryNode) == 0x10 ? 1 : -1];
typedef char QuestDownloadEntryNodeNext[offsetof(QuestDownloadEntryNode, next) == 0xC ? 1 : -1];

// The decoded cache item or default item prefix, distinct from a four-byte match token.
struct QuestDownloadItemNode {
    s16 off;
    u8 a;
    u8 b;
    s32 x4;
    u16 c;
    u8 reserved_a[2];
    QuestDownloadItemNode *next;
};

// A pending scored candidate and the remainder of its text fragments.
struct QuestDownloadQueueNode {
    QuestDownloadEntryNode *entry;
    u16 score;
    u8 reserved_6[2];
    QuestDownloadTextNode *text;
    QuestDownloadQueueNode *next;
};

typedef char QuestDownloadQueueNodeSize[sizeof(QuestDownloadQueueNode) == 0x10 ? 1 : -1];
typedef char QuestDownloadQueueNodeNext[offsetof(QuestDownloadQueueNode, next) == 0xC ? 1 : -1];
typedef char QuestDownloadTextAttributeOffset[offsetof(QuestDownloadTextNode, attribute) == 0xE ? 1 : -1];

struct QuestDownloadSlot {
    const QuestDownloadMatchToken *tokens;
    QuestDownloadItemNode *items;
    QuestDownloadEntryNode *head;
    QuestDownloadTextNode *chain;
    s32 timer;
    s8 x14;
    s8 x15;
    s8 x16;
    s8 width;
    s8 x18;
    s8 x19;
    u8 reserved_1a[2];
};

typedef char QuestDownloadTextNodeSize[sizeof(QuestDownloadTextNode) == 0x14 ? 1 : -1];
typedef char QuestDownloadTextNodeNextOffset[offsetof(QuestDownloadTextNode, next) == 0x10 ? 1 : -1];
typedef char QuestDownloadItemNodeSize[sizeof(QuestDownloadItemNode) == 0x10 ? 1 : -1];
typedef char QuestDownloadItemNextOffset[offsetof(QuestDownloadItemNode, next) == 0xC ? 1 : -1];
typedef char QuestDownloadSlotSize[sizeof(QuestDownloadSlot) == 0x1C ? 1 : -1];
typedef char QuestDownloadSlotTextOffset[offsetof(QuestDownloadSlot, chain) == 0xC ? 1 : -1];

extern "C" {
extern QuestDownloadSlot quest_download_slot_chain_table[80];
s32 count_quest_text_entries(const QuestDownloadTextNode *chain);
QuestDownloadTextNode *advance_quest_text_entries(QuestDownloadTextNode *chain, s32 count);
QuestDownloadTextNode *next_quest_text_entry(QuestDownloadTextNode *chain);
QuestDownloadTextNode *detach_quest_text_tail(QuestDownloadTextNode *chain);
void free_quest_text_chain(QuestDownloadTextNode *chain);
}

#endif
