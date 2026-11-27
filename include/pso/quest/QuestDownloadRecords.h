#ifndef PSO_QUEST_QUESTDOWNLOADRECORDS_H
#define PSO_QUEST_QUESTDOWNLOADRECORDS_H

#include "types.h"
#include <stddef.h>

struct QuestDownloadItemNode;
struct QuestDownloadMatchToken { u8 a; u8 b; u8 off; u8 d; };
LAYOUT_ASSERT(QuestDownloadMatchTokenSize, sizeof(QuestDownloadMatchToken) == 4);

// A matched sequence segment produced by the recursive dictionary search.
struct QuestDownloadSegment {
    s16 off;
    u8 reserved_2[2];
    u8 a;
    u8 b;
    u8 reserved_6[2];
    QuestDownloadSegment *next;
};

LAYOUT_ASSERT(QuestDownloadSegmentSize, sizeof(QuestDownloadSegment) == 0xC);
LAYOUT_ASSERT(QuestDownloadSegmentNext, offsetof(QuestDownloadSegment, next) == 8);

// One fragment in a download text entry. The low flag bit joins the next
// fragment to this entry. The other fields are used by headed fragments.
struct QuestDownloadTextNode {
    u8 flags;
    // Up to 4 text bytes in a headed fragment; a continuation fragment (flags 2)
    // runs its 14 bytes on over the fields below.
    u8 text[5];
    u8 len;
    u8 extra; // the text record's extra byte
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

LAYOUT_ASSERT(QuestDownloadEntryPrefixSize, sizeof(QuestDownloadEntryPrefix) == 8);
LAYOUT_ASSERT(QuestDownloadEntryPrefixSource, offsetof(QuestDownloadEntryPrefix, source) == 4);
LAYOUT_ASSERT(QuestDownloadEntryNodeSize, sizeof(QuestDownloadEntryNode) == 0x10);
LAYOUT_ASSERT(QuestDownloadEntryNodeNext, offsetof(QuestDownloadEntryNode, next) == 0xC);

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

LAYOUT_ASSERT(QuestDownloadQueueNodeSize, sizeof(QuestDownloadQueueNode) == 0x10);
LAYOUT_ASSERT(QuestDownloadQueueNodeNext, offsetof(QuestDownloadQueueNode, next) == 0xC);
LAYOUT_ASSERT(QuestDownloadTextAttributeOffset, offsetof(QuestDownloadTextNode, attribute) == 0xE);

struct QuestDownloadSlot {
    const QuestDownloadMatchToken *tokens;
    QuestDownloadItemNode *items;
    QuestDownloadEntryNode *head;
    QuestDownloadTextNode *chain;
    s32 timer;
    s8 fixed;          // the segment starting here is settled
    s8 length;         // characters in the segment starting here
    s8 latched_length; // length when the segment was first settled
    s8 width;
    s8 token_length;   // length of the longest dictionary match starting here
    s8 x19;
    u8 reserved_1a[2];
};

LAYOUT_ASSERT(QuestDownloadTextNodeSize, sizeof(QuestDownloadTextNode) == 0x14);
LAYOUT_ASSERT(QuestDownloadTextNodeTextOffset, offsetof(QuestDownloadTextNode, text) == 1);
LAYOUT_ASSERT(QuestDownloadTextNodeSourceOffset, offsetof(QuestDownloadTextNode, source) == 8);
LAYOUT_ASSERT(QuestDownloadTextNodeNextOffset, offsetof(QuestDownloadTextNode, next) == 0x10);
LAYOUT_ASSERT(QuestDownloadItemNodeSize, sizeof(QuestDownloadItemNode) == 0x10);
LAYOUT_ASSERT(QuestDownloadItemNextOffset, offsetof(QuestDownloadItemNode, next) == 0xC);
LAYOUT_ASSERT(QuestDownloadSlotSize, sizeof(QuestDownloadSlot) == 0x1C);
LAYOUT_ASSERT(QuestDownloadSlotItemsOffset, offsetof(QuestDownloadSlot, items) == 4);
LAYOUT_ASSERT(QuestDownloadSlotHeadOffset, offsetof(QuestDownloadSlot, head) == 8);
LAYOUT_ASSERT(QuestDownloadSlotTextOffset, offsetof(QuestDownloadSlot, chain) == 0xC);

extern QuestDownloadSlot quest_download_slot_chain_table[80];
extern "C" {
s32 count_quest_text_entries(const QuestDownloadTextNode *chain);
QuestDownloadTextNode *advance_quest_text_entries(QuestDownloadTextNode *chain, s32 count);
}
QuestDownloadTextNode *next_quest_text_entry(QuestDownloadTextNode *chain);
extern "C" {
QuestDownloadTextNode *detach_quest_text_tail(QuestDownloadTextNode *chain);
void free_quest_text_chain(QuestDownloadTextNode *chain);
}

#endif
