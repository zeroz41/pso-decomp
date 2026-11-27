#ifndef PSO_QUEST_QUESTDOWNLOADSERVER_H
#define PSO_QUEST_QUESTDOWNLOADSERVER_H

// Record types and data shared by the three quest download server TUs (_803E6970, _803E8918, _803E9A24).

#include "types.h"
#include <string.h>
#include "pso/quest/QuestDownloadRecords.h"
#include "pso/quest/QuestDownloadText.h"
#include "pso/quest/QuestDownloadWorkspace.h"
#include "pso/quest/QuestDownloadCacheTypes.h"
#include "pso/quest/AskDicFile.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/QuestDownloadCharTables.h"
#include "pso/quest/AskDic.h"

struct QuestSymbolLookupResult {
    s16 page_index;
    s16 record_offset;
    u8 reserved[8];
    u8 *encodedRecord;
};

struct QuestNameLookupResult {
    s16 page_index;
    s16 record_id;
    s16 match_length;
    s16 prefix_length;
    u8 reserved[4];
    u8 *encodedRecord;
};

LAYOUT_ASSERT(QuestSymbolLookupRecordOffset, offsetof(QuestSymbolLookupResult, encodedRecord) == 0xC);
LAYOUT_ASSERT(QuestNameLookupRecordOffset, offsetof(QuestNameLookupResult, encodedRecord) == 0xC);

// Name cache: eight 0x400-byte record pages (name_cache_image), then the hash buckets (name_cache_index)
// and the free-list node pool that __VIRetraceHandler links up.
struct QuestDownloadNameCacheImage {
    u8 pages[8][0x400];
};

extern u8 name_entry_text_buffer[0x50];
extern u8 name_entry_name_buffer[0x50];
extern u8 learned_name_text_buffer[0x50];
extern u8 quest_request_text_buffer[0x50];
extern s32 lbl_805D7880;
extern s32 lbl_805D7884;
extern s32 quest_download_free_list_ready_flag;
extern s16 lbl_805D78E0;
extern s32 lbl_805D78E4;
void convert_input_range(s32 start, s32 inputEnd, s32 mode, s32 selectedLength);
extern "C" {
s32 set_input_text(u32 input_address);
}
s32 load_name_cache_image(void);
void rotate_cache_page(void);
QuestDownloadTextNode *build_entry_candidates(const QuestDownloadEntryPrefix *entry);
s32 compute_entry_cost(QuestDownloadEntryNode *e, s32 idx, s32 max);
const u8 *find_romaji_kana_row(u16 *start, u16 *end);
void learn_conversion_result(s32 pos, s32 len, QuestDownloadTextNode *node, QuestDownloadEntryNode *link);
s32 store_learned_name(QuestDownloadRequest *req, s32 *ids, s32 n);
s32 remove_record_entry(u8 *rec, QuestDownloadRequest *msg);
s32 update_entry_frequency(u32 id, u16 key, s32 *ids, s32 n);
s32 lookup_dictionary_prefix(u8 *name, s16 len, QuestNameLookupResult *out);
extern "C" {
extern u8 quest_download_scratch_storage[0x28] ATTRIBUTE_ALIGN(4);
extern u16 quest_download_buffer_storage[0x64] ATTRIBUTE_ALIGN(4);
extern s32 quest_download_state;
extern s32 lbl_805D7848;
extern u8 *input_code_end;
extern u8 *input_code_cursor;
extern s32 quest_text_end;
extern u16 *quest_download_buffer_ptr;
extern u16 *input_buffer_cursor;
extern u16 *quest_download_buffer_start;
extern u16 *quest_vm_download_buffer_end;
extern s32 quest_download_match_length_limit;
extern s32 quest_download_server_state;
// The ARAM backend returns -1 for a closed file.
extern s32 quest_download_file_handle;
extern char quest_vm_download_server_file_info[0x44] ATTRIBUTE_ALIGN(4);
extern saddr ask_dictionary_open_mode;
extern QuestDownloadNameCacheImage name_cache_image;
extern u8 name_cache_dirty;
extern const u8 romaji_kana_char_class_table[0x100];
extern s32 quest_download_initialized;
extern s32 quest_download_state;
extern s32 lbl_805D7908;
extern s32 lbl_805D790C;
extern s32 ask_convert_mode;
extern u8 quest_name_index_table[1024][4] ATTRIBUTE_ALIGN(4);
void __VIRetraceHandler(void);
}
extern s32 quest_download_free_cell_count;
void free_quest_queue_chain(QuestDownloadQueueNode *p);
void free_quest_entry_chain(QuestDownloadEntryNode *p);
void free_quest_segment_chain(QuestDownloadSegment *p);
extern QuestDownloadFileCache quest_download_slot_table;
QuestDownloadEntryNode *insert_quest_download_entry(QuestDownloadEntryNode *head, QuestDownloadEntryNode *entry);
extern s32 quest_download_name_search_lo;
extern s32 quest_download_name_search_hi;
QuestDownloadItemNode *alloc_quest_item_node(void);
void reset_slot(QuestDownloadSlot *slot, s32 mode);
extern "C" {
s32 convert_quest_text_u8_to_u16(u16 *, const u8 *, int);
}
s32 write_entry_group_text(s32 start, s32 count, QuestDownloadTextNode *node, u16 *buf);
s32 store_name_record(char *, QuestDownloadRequest *, s32);
extern s32 ask_learning_enabled;
s32 store_name_entry(QuestDownloadRequest *req);
void relocate_name_record(s32 id);
void clear_record_values(u8 *p);
extern u32 quest_download_aram_size;
extern u8 ask_header_buffer[0x404];
extern s32 ask_header_dirty;
extern s32 quest_download_ask_header_size;
extern s32 quest_download_header_name_index_hi_count;
extern s32 name_cache_page_index;
extern s32 number_format_mode;
extern s32 quest_page_text_limit;
extern saddr quest_text_entry_len;
extern "C" {
s32 quest_text_u16_to_u8(u16 *, u8 *, s32);
}
extern u16 quest_text_page_buffer[];
extern u8 *quest_download_text_write_ptr;
void pack_entry_text_chain(s32 start, QuestDownloadTextNode *node);
extern u16 quest_text_u8_buffer[];
extern s32 quest_page_node_index;
extern QuestDownloadTextNode *quest_page_node_head;
extern s32 lbl_805D78E8;
extern saddr quest_text_cursor_pos;
extern "C" {
void DCInvalidateRange(void *, u32);
u32 OSGetTick(void);
u32 __OSBusClock AT_ADDRESS(0x800000F8);
void OSReport(const char *, ...);
}
extern u32 quest_download_aram_timeout;
extern u32 quest_download_aram_priority;
extern u32 quest_download_aram_owner;
extern u32 quest_download_aram_dma_pending;
extern u32 quest_download_aram_base;
void render_quest_text_page(void);
void seek_quest_text_page(s32, s32);
extern s32 quest_page_node_count;
s32 measure_entry_group_len(QuestDownloadTextNode *quest_download_text_node);
void release_node_chain(QuestDownloadItemNode *p);
s32 parse_record_query_entries(u8 *data, QuestDownloadQueryEntry *entries, s32 n, s32 *max);
s32 query_exact_matches(const char *name, s16 len, QuestDownloadQueryResult *out);
s32 can_connect_word_class(u8 a, u8 b, u8 c);
s32 query_prefix_matches(const char *name, s16 len, QuestDownloadQueryResult *out);
QuestDownloadSegment *find_segments_at(s32, s32, u8, u8);
QuestDownloadEntryNode *alloc_quest_entry_node(void);
QuestDownloadEntryNode *expand_item_entries(s32 start, s32 end, const QuestDownloadItemNode *t);
QuestDownloadTextNode *alloc_quest_text_node(void);
QuestDownloadSegment *alloc_quest_segment(void);
extern QuestDownloadCachePage *file_page_cache_head;
extern QuestDownloadCachedNameIndex name_cache_index;
s32 lookup_name_prefix(char *name, s16 name_len, QuestNameLookupResult *out);
void find_best_matching_entry(u8 *data, s32 key, s32 sub_key, s32 *best, u8 *dst, s32 flags);
extern const char ask_header_signature[];
void collect_matching_entries(u8 *data, s32 key, s32 sub_key, s32 *cnt, s32 *total, u8 *buf, s32 flags);
extern u8 *allowed_char_bitmap;
extern "C" {

LAYOUT_ASSERT(QuestDownloadScratchSize, sizeof(quest_download_scratch_storage) == 0x28);
LAYOUT_ASSERT(QuestDownloadBufferSize, sizeof(quest_download_buffer_storage) == 0xC8);
}
void clear_entry_reference_counts(void);
void mark_allowed_char(u8 *text, s16 mode);

#endif
