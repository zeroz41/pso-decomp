#ifndef PSO_SYSTEM_MEMORYMOVE_H
#define PSO_SYSTEM_MEMORYMOVE_H

#include "types.h"

void move_data(void *dst, const void *src, s32 n);
void copy_u16_array(u16 *dst, u16 *src, s32 n);

#endif
