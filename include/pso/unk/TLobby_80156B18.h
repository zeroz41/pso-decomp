#ifndef PSO_UNK_TLOBBY_80156B18_H
#define PSO_UNK_TLOBBY_80156B18_H

#include "types.h"

struct G_UpdateObjectState_6x0B;

// Byte-swaps a 6x0B object-state message in place.
void bswap_object_state(G_UpdateObjectState_6x0B *packet);

#endif
