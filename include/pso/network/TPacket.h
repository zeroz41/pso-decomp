#ifndef PSO_NETWORK_TPACKET_H
#define PSO_NETWORK_TPACKET_H

#include "types.h"

struct TPacket
{
    void clear_send_buffer();
};

extern "C" {
void *TPacket__ct(void *packet);
void *__dt__7TPacketFv(void *arg0, s16 arg1);
}

// --- C functions defined in TPacket.cpp ---
extern "C" {
void *TPacket__ct(void *packet);
void *__dt__7TPacketFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
