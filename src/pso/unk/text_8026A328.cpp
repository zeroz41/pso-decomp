#include "types.h"
#include "pso/unk/text_8026A328.h"
#include "pso/unk/text_8026A14C.h"
#include "pso/system/THeap.h"

void free_chat_last_line() {
    if (chat_last_line_buffer != NULL) {
        scroll_win_chat_log_heap->heap_free(chat_last_line_buffer);
        chat_last_line_buffer = NULL;
    }
}
