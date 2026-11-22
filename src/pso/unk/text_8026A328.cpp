#include "types.h"
#include "pso/unk/text_8026A328.h"
#include "pso/unk/text_8026A14C.h"
#include "pso/system/THeap.h"

void TLobby__sub_8026A328(void) {
    if (chat_last_line_buffer != NULL) {
        TAdScrollWinGC__chat_log_heap->heap_free(chat_last_line_buffer);
        chat_last_line_buffer = NULL;
    }
}
