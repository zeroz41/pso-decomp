#ifndef PSO_UI_CHAT_CHATLOGTEXT_H
#define PSO_UI_CHAT_CHATLOGTEXT_H

#include "types.h"

class THeap;

extern THeap *scroll_win_chat_log_heap;
extern char *chat_last_line_buffer;

// Frees every chat log line and the last-line buffer.
void clear_chat_log();
// Copies src into dst (size bytes with the terminator), cutting it short only between
// control codes and whole characters.
void copy_clipped_text(char *dst, const char *src, s32 size);

#endif
