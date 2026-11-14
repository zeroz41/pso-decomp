#include "types.h"
#include "pso/unk/text_80103674.h"
extern "C" {
void *mem_alloc(u32 size);
extern u32 item_buffer_temp_mode;
extern u32 item_buff_buffer;
extern u32 item_nj_chunk_buffer_table[];
// inferred: clears the item buffer state and allocates the two 0x200-byte NJ chunk buffers; init_game_resources calls it first.
void init_item_chunk_buffers(void) {
    s32 i;
    item_buffer_temp_mode = 0;
    item_buff_buffer = 0;
    for (i = 0; i != 2; i++) {
        item_nj_chunk_buffer_table[i] = (u32)mem_alloc(0x200);
    }
}

}
