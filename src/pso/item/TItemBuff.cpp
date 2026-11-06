#include "types.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/item/TItemBuff.h"

extern "C" {

void mem_free(void *p);

extern s32 item_nj_chunk_buffer_table[];

void TItemBuff::free_all_and_init() {
    s32 var_r28;
    s32 *var_r29;
    s32 var_r30;
    s32 var_r31;

    TItemBuff__ct();
    var_r31 = 0;
    var_r30 = var_r31;
    var_r28 = 0;
    var_r29 = item_nj_chunk_buffer_table;
    do {
        mem_free((void *)var_r29[var_r31]);
        var_r28 += 1;
        var_r29[var_r31] = var_r30;
        var_r31 += 1;
    } while (var_r28 != 2);
}

}
