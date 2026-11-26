#include "types.h"
#include "pso/unk/text_8026AC50.h"
#include "pso/unk/text_8026A14C.h"
#include "pso/system/THeap.h"
#include "pso/ui/window/TWindowMessageLog.h"

void free_chat_log_lines(void) {
    s32 i;
    char *v;
    for (i = 29; i >= 0; i--) {
        v = chat_log_lines[i];
        if (v != 0) {
            scroll_win_chat_log_heap->heap_free(v);
            chat_log_lines[i] = 0;
        }
    }
    if (chat_last_line_buffer != NULL) {
        scroll_win_chat_log_heap->heap_free(chat_last_line_buffer);
        chat_last_line_buffer = NULL;
    }
    delete scroll_win_chat_log_heap;
    scroll_win_chat_log_heap = NULL;
}
