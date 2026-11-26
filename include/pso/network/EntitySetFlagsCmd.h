#ifndef PSO_NETWORK_ENTITYSETFLAGSCMD_H
#define PSO_NETWORK_ENTITYSETFLAGSCMD_H

#include "types.h"

void build_6x76_set_entity_set_flags(void *p);

struct SendPlayerUpdateItem { u8 pad[0x80]; s32 v; };

struct SendPlayerUpdateObject { u8 pad[0x1c]; s32 max; s32 count; SendPlayerUpdateItem **ptrs; s32 *vals; };

#endif
