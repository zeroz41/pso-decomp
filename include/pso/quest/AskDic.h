#ifndef PSO_QUEST_ASKDIC_H
#define PSO_QUEST_ASKDIC_H

#include "types.h"

// The kana-kanji conversion dictionary engine behind the software keyboard: the ACCESS ASK
// dictionary ("ASK Copyright (C) ACCESS CO.,LTD.", "ASKDIC:ARAM DMA Timeout!!").
struct QuestDownloadItemNode;
struct QuestDownloadMatchToken;
struct QuestDownloadQueryResult;
struct QuestDownloadRequest;
struct QuestDownloadTextNode;
struct QuestDownloadTextRecord;
struct QuestNameLookupResult;
struct QuestSymbolLookupResult;

s32 reset_download_buffers(saddr *);
s32 poll_download_status(saddr *);
s32 handle_list_scroll(saddr *args);
s32 convert_jis_to_sjis_string(saddr *args);
void init_buffer_pointers();
s32 get_buffer_size();
u8 lookup_value_by_key(u16 key);
u16 map_key_to_code(u32 ch);
s32 is_valid_item_for_slot(u8 c, u8 k);
void invalidate_entries_by_id(s32 id);
void clear_entries_by_id(s32 id);
s32 release_ref_slot(u32 index);
s32 set_slot_values_for_indices(s32 *ids, s32 count, u32 value);
s32 get_max_size_of_indices(s32 *ids, s32 count);
u32 acquire_slot_entry(s32 page_index, s32 file_offset, s32 cached_id, s32 value);
void retry_seek_active_entries();
void set_active();
u8 *get_cached_page(s32 page);
s32 match_prefix_length(const u8 *a, const u8 *b, s32 n);
s32 count_matching_name_prefix(s32 idx, u8 *name);
s32 has_name_mismatch(s32 row, u8 *key);
s32 find_name_index(const char *key);
s32 is_char_allowed(const u8 *text, s16 len);
s32 read_ask_header();
void init_page_cache();
s32 seek_or_reopen(int pos);
s32 find_file_info_index();
void set_file_info_name(const char *filename);
s32 aram_read_thunk(s32 handle, void *dst, s32 size);
void unescape_copy_string(u8 *dst, u8 *src, u8 *end);
s32 count_entries_until_terminator(const u8 *p, const u8 *end);
void copy_sjis_string(u8 *src, u8 *dst);
s32 calc_sjis_string_width(u8 *text);
s32 lookup_name_entry(char *name, s16 name_len, QuestNameLookupResult *out);
void append_message_text(u8 *record, s32 size, QuestDownloadRequest *msg, u8 attr);
void build_message_packet(u8 *record, s32 size, QuestDownloadRequest *msg, u8 attr);
u8 *get_buffer_ptr(s32 id);
s32 is_download_cmd_allowed(u8 cmd);
const QuestDownloadMatchToken *find_longest_match_entry(u8 *text, s32 remaining, s32 *length);
void latch_slot_value(s32 index);
QuestDownloadItemNode *build_item_list(s32 start, QuestDownloadQueryResult *query);
s32 count_leading_entries(s32 i, s32 end);
void init_entries();
s32 count_fitting_entries(QuestDownloadTextNode *head);
QuestDownloadTextNode *build_text_node_chain(QuestDownloadTextRecord *record, const QuestDownloadItemNode *source, s32 length, QuestDownloadTextNode **head, QuestDownloadTextNode **tail);
u16 jis_to_sjis(u16 jis);
s32 is_valid_sjis_code(u16 ch);
s32 is_download_command(u16 ch, s32 allow_long_vowel_mark);
s32 encode_char_with_attr(u16 *out, u16 ch, s32 attr);
s32 is_sjis_lead_byte(u8 c);
void push_download_entry(void *storage);
void init_block_free_list();
s32 aram_dma_read(s32 handle, void *dst, s32 size);
s32 calc_item_cost_bonus(u8 kind, u8 v, u8 w, s32 base, s32 add);
s32 calc_pair_cost_bonus(u8 kind, u8 bk, s32 extra);
s32 calc_item_entry_cost_extra(u8 kind, u8 subkind, u8 bk, s32 extra);
void reset_slot_chain_timers(s32 pos);
s32 select_best_slot_entry(s32 idx, s32 max, s32 want);
s32 sum_entry_sizes(s32 start, s32 n);
const u8 *find_keyword_entry(u16 *start, u16 *end);
QuestDownloadTextRecord *format_number_text(const u8 *input, s32 length, QuestDownloadTextRecord *out, s32 mode);
s32 get_download_state();
QuestDownloadTextRecord *find_insert_position(u8 *buffer, s32 key, s32 n, s32 len);
s32 read_quest_chunk(u32 id, u8 key, u8 sub_key, u8 *buf, s32 *out);
s32 find_symbol_entry(const char *name, s16 len, QuestSymbolLookupResult *out);

#endif
