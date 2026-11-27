#ifndef PSO_QUEST_ASKDICCONVERT_H
#define PSO_QUEST_ASKDICCONVERT_H

#include "types.h"
#include "pso/quest/QuestDownloadRecords.h"
#include "pso/quest/QuestDownloadText.h"

struct QuestDownloadItemNode;
struct QuestDownloadQueueNode;
struct QuestDownloadSegment;
struct QuestDownloadTextNode;
struct QuestDownloadEntryNode;
struct QuestDownloadTextRecord;

QuestDownloadItemNode *alloc_quest_item_node(void);
QuestDownloadQueueNode *alloc_quest_queue_node(void);
QuestDownloadSegment *alloc_quest_segment(void);
QuestDownloadTextNode *alloc_quest_text_node(void);
s32 build_all_entry_text(void);
s32 calc_quest_download_entry_cost(const QuestDownloadEntryNode *a, const QuestDownloadEntryNode *b);
s32 calc_quest_download_item_cost(const QuestDownloadEntryNode *entry, u8 k, u8 v, s32 base);
u16 calc_quest_entry_score(const QuestDownloadEntryNode *entry, u16 attribute);
u8 *convert_all_entry_text(void);
s32 convert_romaji_to_kana(u16 *src, s32 count, u16 *out, s32 *written);
s32 format_number_text_all_modes(const u8 *format, s32 length, QuestDownloadTextRecord *out, s32 *count);
void free_quest_entry_chain(QuestDownloadEntryNode *p);
void free_quest_queue_chain(QuestDownloadQueueNode *p);
void free_quest_segment_chain(QuestDownloadSegment *p);
void free_slot_node_chain(s32 slot, s32 mode);
u16 *get_entry_text(s32 start, s32 len);
s32 is_jis_kanji_code(u16 ch);
s32 is_sjis_double_byte(u16 code);
u8 jis_to_single_byte(u16 code);
s32 measure_entry_group_len(QuestDownloadTextNode *node);
QuestDownloadTextNode *next_quest_text_entry(QuestDownloadTextNode *chain);
void pack_entry_text_chain(s32 start, QuestDownloadTextNode *node);
void process_entry_text_range(s32 pos, s32 end);
s32 quest_text_next_page(s32 mode, s32 force);
s32 quest_text_prev_page(s32 mode, s32 force);
void rebuild_current_slot_text_chain(s32 mode);
void render_quest_text_page(void);
void reset_entry_text_accumulator(void);
void seek_quest_text_page(s32 pos, s32 mode);

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

struct QuestDownloadRequestStorage {
    QuestDownloadRequest request;
    u8 reserved[0x18];
};

struct DownloadDecoderState {
    u16 lead;
    DownloadDecoderState() : lead(0) {}
};

struct FormatNumberTextAllModesTable {
    u8 units[0x14];
    u8 fullwidth_digits[0x18];
    u8 kanji_digits[0x18];
    const u8 *sets[3];
};

#endif
