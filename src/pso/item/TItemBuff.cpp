#include "types.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/item/TItemBuff.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"


void TItemBuff::free_all_and_init() {
    s32 i;
    char **table;
    s32 index;

    free_item_buff();
    index = 0;
    i = 0;
    table = item_nj_chunk_buffer_table;
    do {
        mem_free(table[index]);
        i += 1;
        table[index] = NULL;
        index += 1;
    } while (i != 2);
}
