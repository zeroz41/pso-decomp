#include "types.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/item/TItemBuff.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"


extern saddr item_nj_chunk_buffer_table[];

void TItemBuff::free_all_and_init() {
    s32 i;
    saddr *var_r29;
    s32 var_r30;
    s32 var_r31;

    TItemBuff__ct();
    var_r31 = 0;
    var_r30 = var_r31;
    i = 0;
    var_r29 = item_nj_chunk_buffer_table;
    do {
        mem_free((void *)var_r29[var_r31]);
        i += 1;
        var_r29[var_r31] = var_r30;
        var_r31 += 1;
    } while (i != 2);
}
