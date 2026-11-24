#ifndef PSO_UNK_TEXT_8026A14C_H
#define PSO_UNK_TEXT_8026A14C_H

#include "types.h"

class THeap;

extern THeap *TAdScrollWinGC__chat_log_heap;
extern char *chat_last_line_buffer;

// Frees every chat log line and the last-line buffer.
void clear_chat_log();
// Copies src into dst (size bytes with the terminator), cutting it short only between
// control codes and whole characters.
void copy_clipped_text(char *dst, const char *src, s32 size);

#endif
