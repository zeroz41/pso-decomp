#ifndef PSO_SYSTEM_NINJACHUNK_H
#define PSO_SYSTEM_NINJACHUNK_H

#include "types.h"

// Read a Ninja model, texture or motion chunk and apply its POF0 pointer offsets.
// Pass NULL for destination to allocate storage for the chunk.
extern "C" void *TLobby__sub_801E38A0(const u8 *file, u32 *offset, u32 *type, void *destination, u32 *size_out);

#endif
