#ifndef PSO_NETWORK_OBJECTSTATESEND_H
#define PSO_NETWORK_OBJECTSTATESEND_H

#include "types.h"

struct G_UpdateObjectState_6x0B;

// Byte-swaps a 6x0B object-state message and sends it.
void send_object_state(G_UpdateObjectState_6x0B *packet);

#endif
