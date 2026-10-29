#ifndef PSO_SYSTEM_BML_RESOURCE_LOAD_H
#define PSO_SYSTEM_BML_RESOURCE_LOAD_H

#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"

// The BML archive loader (the TLobby_8001EF5C unit): builds a BmlResource
// in `memory` (0x440 bytes from operator new) from a descriptor, and tears
// one down again (del > 0 frees it).
extern "C" {
BmlResource *load_resource_from_descriptor(void *memory, s32 kind, BmlResourceDescriptor *descriptor, s32, s32, s32);
void TLobby__sub_8001FE7C(BmlResource *resource, s16 del);
}

#endif
