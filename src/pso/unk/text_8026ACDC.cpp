#include "types.h"
#include "pso/unk/text_8026ACDC.h"
#include "pso/unk/text_8026A14C.h"
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
