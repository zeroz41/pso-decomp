#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/system/THeap.h"

extern "C" {

s32 TLobby__sub_800F9FD0();
}
void process_async_file_reads(void);

    extern saddr game_heap;

void TLobby::free_static_buffer(void* a0) { ((THeap *)game_heap)->heap_free(a0); }

void *TLobby::alloc_from_heap(size_t size) { return ((THeap *)game_heap)->heap_alloc(size); }

void TLobby::pump_frames() {
loop_1:
    if (TLobby__sub_800F9FD0() != 0) {
        process_async_file_reads();
        TLobby::run_frame();
        goto loop_1;
    }
}
