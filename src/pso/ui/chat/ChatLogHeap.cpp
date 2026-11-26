#include "types.h"
#include "pso/ui/chat/ChatLogHeap.h"
#include "pso/ui/chat/ChatLogText.h"
#include "pso/system/THeap.h"
#include "pso/ui/window/TWindowMessageLog.h"

void init_chat_log_heap(void) {
    s32 i;
    scroll_win_chat_log_heap = new THeap(0x2000, 8);
    chat_last_line_buffer = NULL;
    for (i = 0; i < 0x1E; i++) {
        chat_log_lines[i] = NULL;
    }
}
