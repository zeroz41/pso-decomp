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
extern QuestDownloadInputEntry *input_entry_end;
extern QuestDownloadInputEntry *input_entry_cursor;

// Native character codes are halfwords; the single-byte conversion returns a byte.
s32 kana_takes_handakuten(u16 code);
s32 kana_takes_dakuten(u16 code);
// The output must have room for two bytes, even when the caller expects one.
s32 jis_to_halfwidth_kana(u8 *output, u16 code);
u16 sjis_to_jis(u16 code);
}
u8 jis_to_single_byte(u16 code);
s32 is_sjis_double_byte(u16 code);

s32 convert_romaji_to_kana(u16 *src, s32 count, u16 *out, s32 *written);
void reset_entry_text_accumulator(void);
void process_entry_text_range(s32 start, s32 end);
u16 *get_entry_text(s32 start, s32 length);
u8 *convert_all_entry_text(void);
void free_slot_node_chain(s32 slot, s32 mode);
s32 build_all_entry_text(void);
s32 format_number_text_all_modes(const u8 *format, s32 length, QuestDownloadTextRecord *out, s32 *count);
extern "C" {
s32 delete_name_entry(QuestDownloadRequest *request);
s32 register_name_entry(QuestDownloadRequest *request);
}

#endif
