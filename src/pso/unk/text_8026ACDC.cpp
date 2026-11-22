#include "types.h"
#include "pso/unk/text_8026ACDC.h"
#include "pso/unk/text_8026A14C.h"
#include "pso/system/THeap.h"

extern void *chat_log_lines[];

void TLobby__sub_8026ACDC(void) {
    s32 i;
    TAdScrollWinGC__chat_log_heap = new THeap(0x2000, 8);
    chat_last_line_buffer = NULL;
    for (i = 0; i < 0x1E; i++) {
        chat_log_lines[i] = NULL;
    }
}
