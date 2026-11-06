#include "types.h"
#include "pso/unk/text_8026A328.h"
#include "pso/system/THeap.h"

extern s32 TAdScrollWinGC__chat_log_heap;
extern u32 chat_last_line_buffer;

void TLobby__sub_8026A328(void) {
    if ((u32) chat_last_line_buffer != 0U) {
        ((THeap *)TAdScrollWinGC__chat_log_heap)->heap_free((void *)chat_last_line_buffer);
        chat_last_line_buffer = 0U;
    }
}
