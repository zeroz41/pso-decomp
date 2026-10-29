#ifndef PSO_SYSTEM_BMLRESOURCELOADER_H
#define PSO_SYSTEM_BMLRESOURCELOADER_H

#include "types.h"

struct BmlResource;
struct BmlResourceDescriptor;

// Defined in TLobby_8001EF5C.cpp (which still spells them with its own
// stand-in types).
extern "C" {
// Loads the archive a descriptor names into resource (0x440 bytes from
// operator new).
BmlResource *load_resource_from_descriptor(void *resource, s32 kind, BmlResourceDescriptor *descriptor, s32 arg3, s32 arg4, s32 arg5);
void TLobby__sub_8001FE7C(void *resource, int del);
}

#endif
