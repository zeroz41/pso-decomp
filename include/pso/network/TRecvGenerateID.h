#ifndef PSO_NETWORK_TRECVGENERATEID_H
#define PSO_NETWORK_TRECVGENERATEID_H

#include "types.h"

void bswap_generate_id_payload(void *p);
extern "C" {
void bswap__15TRecvGenerateIDFv(saddr arg0);
}

// --- C functions defined in TRecvGenerateID.cpp ---
extern "C" {
void bswap__15TRecvGenerateIDFv(saddr arg0);
}
void bswap_generate_id_payload(void *p);
// --- end of C functions

#endif
