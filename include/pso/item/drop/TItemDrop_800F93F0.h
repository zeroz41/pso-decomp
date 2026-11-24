#ifndef PSO_ITEM_DROP_TITEMDROP_800F93F0_H
#define PSO_ITEM_DROP_TITEMDROP_800F93F0_H

#include "types.h"

extern "C" {
saddr TItemDrop__sub_800F9448(saddr arg0, s32 size);
void free_data_file(void *p);
// Loads a whole file into a new buffer; free_data_file frees it.
void *load_data_file(const char *path);
}

#endif
