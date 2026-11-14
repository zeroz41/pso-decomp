#ifndef PSO_UI_FRONTEND_TADSCROLLWINGC_8026A5F8_H
#define PSO_UI_FRONTEND_TADSCROLLWINGC_8026A5F8_H

#include "types.h"

extern "C" {
void TAdScrollWinGC__sub_8026A5F8(void *a0);
void TWindowSubLog__sub_8026A664(u8 *arg0, f32 farg0);
}
void cache_last_chat_line(u32 text);
extern "C" {
void chat_log_add_line(const char *text);
}
void chat_log_remove_line(s32 arg0);
s32 chat_text_lacks_language_tag(const char *text);
extern "C" {
void fn_8026A61C(void *p, f32 v);
}

// --- C functions defined in TAdScrollWinGC_8026A5F8.cpp ---
extern "C" {
void TAdScrollWinGC__sub_8026A5F8(void *a0);
void TWindowSubLog__sub_8026A664(u8 *arg0, f32 farg0);
void chat_log_add_line(const char *text);
void fn_8026A61C(void *p, f32 v);
}
// --- end of C functions

#endif
