#ifndef PSO_QUEST_QUESTDOWNLOADTEXT_H
#define PSO_QUEST_QUESTDOWNLOADTEXT_H

#include "types.h"
#include <stddef.h>

struct QuestDownloadInputEntry {
    u16 ch;
    u16 reserved;
    s32 len;
};

// Header shared by decoded dictionary entries and generated numeric text.
struct QuestDownloadTextRecord {
    u16 key;
    u16 attribute;
    u8 extra;
    u8 text[1];
};
LAYOUT_ASSERT(QuestDownloadTextRecordAttribute, offsetof(QuestDownloadTextRecord, attribute) == 2);
LAYOUT_ASSERT(QuestDownloadTextRecordPayload, offsetof(QuestDownloadTextRecord, text) == 5);

struct QuestDownloadRequest {
    char *name;
    s16 len;
    u8 pad6;
    u8 x7;
    u8 x8;
    u8 pad9[3];
    u8 *text;
    s32 calc_text_length() const;
    s32 calc_message_length() const;
};

LAYOUT_ASSERT(QuestDownloadInputEntrySize, sizeof(QuestDownloadInputEntry) == 8);
LAYOUT_ASSERT(QuestDownloadInputEntryLength, offsetof(QuestDownloadInputEntry, len) == 4);
LAYOUT_ASSERT(QuestDownloadRequestSize, sizeof(QuestDownloadRequest) == 0x10);
LAYOUT_ASSERT(QuestDownloadRequestLength, offsetof(QuestDownloadRequest, len) == 4);
LAYOUT_ASSERT(QuestDownloadRequestPad6, offsetof(QuestDownloadRequest, pad6) == 6);
LAYOUT_ASSERT(QuestDownloadRequestKind, offsetof(QuestDownloadRequest, x7) == 7);
LAYOUT_ASSERT(QuestDownloadRequestExtra, offsetof(QuestDownloadRequest, x8) == 8);
LAYOUT_ASSERT(QuestDownloadRequestText, offsetof(QuestDownloadRequest, text) == 0xC);

extern QuestDownloadInputEntry quest_download_entry_table[39];
extern "C" {
LAYOUT_ASSERT(QuestDownloadInputTableSize, sizeof(quest_download_entry_table) == 0x138);
}
extern QuestDownloadInputEntry *input_entry_end;
extern QuestDownloadInputEntry *input_entry_cursor;

// Native character codes are halfwords; the single-byte conversion returns a byte.
s32 kana_takes_handakuten(u16 code);
s32 kana_takes_dakuten(u16 code);
// The output must have room for two bytes, even when the caller expects one.
s32 jis_to_halfwidth_kana(u8 *output, u16 code);
extern "C" {
u16 sjis_to_jis(u16 code);
}

s32 delete_name_entry(QuestDownloadRequest *request);
s32 register_name_entry(QuestDownloadRequest *request);

#endif
