#include "types.h"
#include "pso/unk/TLobby.h"

    extern int switch_doors_force_closed;
void TLobby::reset_door_state() { switch_doors_force_closed = 0; }
