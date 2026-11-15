#ifndef PSO_UNK_TEXT_80076BC4_H
#define PSO_UNK_TEXT_80076BC4_H

#include "types.h"

extern "C" {
s32 TAdSinglePlyChrSelectGC__sub_80076D9C(s32 arg0, s32 arg1);
void TAdSinglePlyChrSelectGC__sub_80076DF4(void *p, void *q);
}
s32 chat_accept_submission(s32 arg0);
void chat_dispatch_accepted_result(s32 *arg0);
extern "C" {
void clear_chat_shortcut(s32 i);
s32 *fn_80076BC4(s32 *text);
int get_chat_shortcut(s32 arg0);
bool is_chat_shortcut_set(s32 arg0);
void send_chat_shortcut(void);
}
s32 store_chat_shortcut(s32 arg0, s32 arg1);
void submit_chat_text(u8 *arg0);

// --- C functions defined in text_80076BC4.cpp ---
extern "C" {
s32 TAdSinglePlyChrSelectGC__sub_80076D9C(s32 arg0, s32 arg1);
void TAdSinglePlyChrSelectGC__sub_80076DF4(void *p, void *q);
void clear_chat_shortcut(s32 i);
s32 *fn_80076BC4(s32 *text);
int get_chat_shortcut(s32 arg0);
bool is_chat_shortcut_set(s32 arg0);
void send_chat_shortcut(void);
}
// --- end of C functions

#endif
