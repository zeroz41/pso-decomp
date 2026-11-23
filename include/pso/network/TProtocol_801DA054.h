#ifndef PSO_NETWORK_TPROTOCOL_801DA054_H
#define PSO_NETWORK_TPROTOCOL_801DA054_H

#include "types.h"

extern "C" {
void handle_cmd_9F__9TProtocolFR6packet(u8 *protocol);
int handle_cmd_D7__9TProtocolFR6packet(void *p);
}

// --- C functions defined in text_801DA054.cpp ---
extern "C" {
void handle_cmd_9F__9TProtocolFR6packet(u8 *protocol);
int handle_cmd_D7__9TProtocolFR6packet(void *p);
}
// --- end of C functions

#endif
