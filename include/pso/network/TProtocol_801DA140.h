#ifndef PSO_NETWORK_TPROTOCOL_801DA140_H
#define PSO_NETWORK_TPROTOCOL_801DA140_H

#include "types.h"

extern "C" {
void send_download_head_d7(TProtocol *self, s8 flags, const char *filename);
}

// --- C functions defined in TProtocol_801DA140.cpp ---
extern "C" {
void send_download_head_d7(TProtocol *self, s8 flags, const char *filename);
}
// --- end of C functions

#endif
