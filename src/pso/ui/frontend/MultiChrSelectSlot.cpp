#include "types.h"
#include "pso/ui/frontend/MultiChrSelectSlot.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"

void copy_creation_input_state(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); *(u32*)((char*)p + 0x8) = *(u32*)((char*)q + 0x8); *(u32*)((char*)p + 0xc) = *(u32*)((char*)q + 0xc); *(u32*)((char*)p + 0x10) = *(u32*)((char*)q + 0x10); *(u32*)((char*)p + 0x14) = *(u32*)((char*)q + 0x14); }

int is_multi_chr_select_slot_chosen() { return multi_chr_select_slot_chosen; }
