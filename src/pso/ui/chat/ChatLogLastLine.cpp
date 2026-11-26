#include "types.h"
#include "pso/ui/chat/ChatLogLastLine.h"
#include "pso/ui/chat/ChatLogText.h"
#include "pso/system/THeap.h"

void free_chat_last_line() {
    if (chat_last_line_buffer != NULL) {
        scroll_win_chat_log_heap->heap_free(chat_last_line_buffer);
        chat_last_line_buffer = NULL;
    }
}
