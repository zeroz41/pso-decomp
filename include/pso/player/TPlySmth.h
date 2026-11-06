#ifndef PSO_PLAYER_TPLYSMTH_H
#define PSO_PLAYER_TPLYSMTH_H

#include "types.h"
#include "pso/macros.h"
#include "pso/protocol.h"

class TPlySmth {
public:
    TPlySmth() {};

    void bswap() {
        bswap_32(as(u32 *, &m_smth));
        bswap_32(as(u32 *, &m_smth1));
    };
public:
    u8 m_smth[4];
    u8 m_smth1[4];
public:
    void*construct();
};

extern "C" {
void __as__8TPlySmthFRC8TPlySmth(s32 arg0, s32 arg1);
void __ct__8TPlySmthFv(void *);
}

#endif
