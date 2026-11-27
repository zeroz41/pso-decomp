#ifndef PSO_NETWORK_UPDATEOBJECTSTATECMD_H
#define PSO_NETWORK_UPDATEOBJECTSTATECMD_H

#include "types.h"

struct G_UpdateObjectState_6x0B;

// Byte-swaps a 6x0B object-state message in place.
void bswap_object_state(G_UpdateObjectState_6x0B *packet);

#endif
