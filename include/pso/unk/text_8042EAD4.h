#ifndef PSO_UNK_TEXT_8042EAD4_H
#define PSO_UNK_TEXT_8042EAD4_H

#include "types.h"
#include "pso/unk/SharedMemory.h"

s32 set_shared_memory_data(u8 *source, u32 size);
void launch_iwanaga_dol(DolHeader *dol_image, s32 arg1);
void init_shared_memory();
s32 set_disc_error_message(s32 index, const char *text);

#endif
