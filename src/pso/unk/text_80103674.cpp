#include "types.h"
#include "pso/unk/text_80103674.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/weapon/TItemAttacker.h"
extern uaddr item_nj_chunk_buffer_table[];
// inferred: clears the item buffer state and allocates the two 0x200-byte NJ chunk buffers; init_game_resources calls it first.
void init_item_chunk_buffers(void) {
    s32 i;
    item_buffer_temp_mode = 0;
    item_buff_buffer = NULL;
    for (i = 0; i != 2; i++) {
        item_nj_chunk_buffer_table[i] = (uaddr)mem_alloc(0x200);
    }
}
