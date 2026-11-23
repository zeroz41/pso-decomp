#ifndef PSO_UNK_TEXT_8026A93C_H
#define PSO_UNK_TEXT_8026A93C_H

#include "types.h"

extern "C" {
u8 *create_message_log_window(s32 parent, saddr extent, s32 client);
void post_chat_log_message(u16 arg0, s32 *shared_text_buffer);
}

// --- C functions defined in text_8026A93C.cpp ---
extern "C" {
u8 *create_message_log_window(s32 parent, saddr extent, s32 client);
void post_chat_log_message(u16 arg0, s32 *shared_text_buffer);
}
// --- end of C functions

#endif
