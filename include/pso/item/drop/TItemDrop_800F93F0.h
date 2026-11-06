#ifndef PSO_ITEM_DROP_TITEMDROP_800F93F0_H
#define PSO_ITEM_DROP_TITEMDROP_800F93F0_H

#include "types.h"

extern "C" {
s32 TItemDrop__sub_800F9448(s32 arg0, s32 arg1);
int free_data_file(void *p);
// Loads a whole file into a new buffer; free_data_file frees it.
void *load_data_file(const char *path);
s32 load_relocatable_file(s32 arg0, s32 arg1);
}

// --- C functions defined in TItemDrop_800F93F0.cpp ---
extern "C" {
s32 TItemDrop__sub_800F9448(s32 arg0, s32 arg1);
int free_data_file(void *p);
void *load_data_file(const char *path);
s32 load_relocatable_file(s32 arg0, s32 arg1);
}
// --- end of C functions

#endif
