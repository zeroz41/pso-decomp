#include "types.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/item/TItemBuff.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"


extern saddr item_nj_chunk_buffer_table[];

void TItemBuff::free_all_and_init() {
    s32 i;
    saddr *table;
    s32 zero;
    s32 index;

    free_item_buff();
    index = 0;
    zero = index;
    i = 0;
    table = item_nj_chunk_buffer_table;
    do {
        mem_free((void *)table[index]);
        i += 1;
        table[index] = zero;
        index += 1;
    } while (i != 2);
}
