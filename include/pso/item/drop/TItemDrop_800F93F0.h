#ifndef PSO_ITEM_DROP_TITEMDROP_800F93F0_H
#define PSO_ITEM_DROP_TITEMDROP_800F93F0_H

#include "types.h"

// Applies the REL relocations of a file already in memory; returns its root, or NULL when size is not positive.
void *relocate_rel_data(void *data, s32 size);

void free_data_file(void *p);
// Loads a whole file into a new buffer; free_data_file frees it.
void *load_data_file(const char *path);

#endif
