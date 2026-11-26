#ifndef PSO_QUEST_TQUESTVMDOWNLOADSERVER_803E5668_H
#define PSO_QUEST_TQUESTVMDOWNLOADSERVER_803E5668_H

#include "types.h"

// keyboard_soft_dispatch_fn_table handlers. args[-1] is the request id, args[0..] its arguments
// (0x16-0x17, 0x1E-0x1F and 0x25-0x2C share one handler each).
s32 quest_download_request_convert(saddr *args);
s32 quest_download_request_unassigned(saddr *);
s32 quest_download_request_convert_as(saddr *args);
s32 quest_download_request_next_segment(saddr *args);
s32 quest_download_request_prev_segment(saddr *args);
s32 quest_download_request_shrink_segment(saddr *args);
s32 quest_download_request_extend_segment(saddr *args);
s32 quest_download_request_open(saddr *args);
s32 quest_download_request_edit_word(saddr *args);
s32 quest_download_request_select_candidate(saddr *args);
s32 quest_download_request_convert_all(saddr *args);
s32 quest_download_request_turn_page(saddr *args);

// Senders of conversion requests to the keyboard_soft_dispatch_fn_table handlers (same TU).
s32 ime_request_0x28(char *text, char *rest);
s32 ime_request_0x27(char *text, char *rest);
s32 ime_request_0x26(char *text, char *rest);
s32 ime_request_0x25(char *text, char *rest);
s32 ime_request_next_segment(char *text, char *rest);
s32 ime_request_prev_segment(char *text, char *rest);
s32 ime_request_shrink_segment(char *text, char *rest);
s32 ime_request_extend_segment(char *text, char *rest);
s32 ime_request_open(const char *a, const char *b);
s32 ime_request_poll_status();
s32 ime_request_next_candidate(char *text, char *rest);
s32 ime_request_prev_candidate(char *text, char *rest);
s32 ime_request_convert(const u8 *reading, char *text, char *rest);
s32 ime_request_romaji_to_hiragana(const char *romaji, char *kana);
s32 ime_request_romaji_to_katakana(const char *romaji, char *kana);

struct QuestConvertString {
    char value[0x80];
};

LAYOUT_ASSERT(QuestConvertStringSize, sizeof(QuestConvertString) == 0x80);
extern QuestConvertString quest_convert_string ATTRIBUTE_ALIGN(4);

#endif
