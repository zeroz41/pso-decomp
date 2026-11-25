#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/system/THeap.h"
#include "pso/unk/text_800FA464.h"

extern "C" {

s32 is_async_file_read_busy();
}

void TLobby::free_static_buffer(void* a0) { game_heap->heap_free(a0); }

void *TLobby::alloc_from_heap(size_t size) { return game_heap->heap_alloc(size); }

void TLobby::pump_frames() {
loop_1:
    if (is_async_file_read_busy() != 0) {
        process_async_file_reads();
        TLobby::run_frame();
        goto loop_1;
    }
}
