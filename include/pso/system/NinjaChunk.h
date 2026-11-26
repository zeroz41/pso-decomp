#ifndef PSO_SYSTEM_NINJACHUNK_H
#define PSO_SYSTEM_NINJACHUNK_H

#include "types.h"

// Read a Ninja model, texture or motion chunk and apply its POF0 pointer offsets.
// Pass NULL for destination to allocate storage for the chunk.
void *read_ninja_chunk(const u8 *file, u32 *offset, u32 *type, void *destination, u32 *size_out);

#endif
