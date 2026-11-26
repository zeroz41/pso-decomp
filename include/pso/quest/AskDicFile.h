#ifndef PSO_QUEST_ASKDICFILE_H
#define PSO_QUEST_ASKDICFILE_H

#include "types.h"

struct QuestDownloadEntryNode;
#include "pso/quest/QuestDownloadText.h"

extern "C" {
s32 render_input_entries_text(s32 start, s32 count, u16 *buf, s32 flag);
}
void reset_text_input_state(s32 mode);
void copy_input_entry_text(u8 *dst, s32 start, s32 count, s32 mode);
s32 compose_kana_jis_code(u8 ch, s32 jis);
extern "C" {
u16 single_byte_to_kana_jis_code(u16 ch);
}
s32 get_slot_entry_info(u32 id, s32 *file_offset, s32 *cached_id, s32 *value);
s32 read_name_index_table(void);
s32 write_ask_header(void);
s32 close_download_file(void);
s32 aram_write_stub(s32 handle, const void *src, s32 size);
void mark_name_cache_dirty(void);
void save_name_cache(void);
s32 get_slot_entry_length(s32 slot_index);
void reset_slot_range(s32 begin, s32 end, s32 mode);
s32 quest_text_prev_page(s32 mode, s32 force);
void build_cursor_candidates(void);
void build_best_candidate(s32 pos, s32 x);
s32 is_jis_kanji_code(u16 ch);
extern "C" {
void set_quest_text_run_attr(u16 *run, s32 count, s32 attr);
}
u16 calc_quest_entry_score(const QuestDownloadEntryNode *entry, u16 attribute);
s32 quest_char_is_closing_mark(u8 ch);
s32 quest_char_is_letter(u8 ch);
s32 quest_char_is_digit(u8 ch);
s32 quest_char_is_alnum(u8 ch);
s32 format_number_current_mode(const u8 *input, s32 length, QuestDownloadTextRecord *output);
s32 release_slot_entry(u32 index);
s32 find_best_slot_entry(s32 id, u8 key, u8 sub_key, void *dst);
s32 save_and_close_download_file(void);
s32 open_ask_dictionary(s8 *quest_vm_down_load_server);
s32 start_askdic(void);
extern "C" {
s32 aram_seek(s32 handle, s32 offset, s32 whence);
}
s32 aram_close(s32 handle);
extern "C" {
s32 aram_open(const char *name, s32 mode);
}

struct IsValidItemForSlotRow { s16 single; s16 pair; };

#endif
