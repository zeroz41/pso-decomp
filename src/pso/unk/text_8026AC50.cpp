#include "types.h"
#include "pso/unk/text_8026AC50.h"
#include "pso/system/THeap.h"
extern "C" {
void __dt__5THeapFv(void *, s32);
extern u32 chat_log_lines[];
extern void *TAdScrollWinGC__chat_log_heap;
extern u32 chat_last_line_buffer;
void fn_8026AC50(void) {
    s32 i;
    u32 v;
    for (i = 29; i >= 0; i--) {
        v = chat_log_lines[i];
        if (v != 0) {
            ((THeap *)TAdScrollWinGC__chat_log_heap)->heap_free((void *)v);
            chat_log_lines[i] = 0;
        }
    }
    v = chat_last_line_buffer;
    if (v != 0) {
        ((THeap *)TAdScrollWinGC__chat_log_heap)->heap_free((void *)v);
        chat_last_line_buffer = 0;
    }
    __dt__5THeapFv(TAdScrollWinGC__chat_log_heap, 1);
    TAdScrollWinGC__chat_log_heap = 0;
}

}
