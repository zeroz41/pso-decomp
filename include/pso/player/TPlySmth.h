#ifndef PSO_PLAYER_TPLYSMTH_H
#define PSO_PLAYER_TPLYSMTH_H

#include "types.h"
#include "pso/macros.h"
#include "pso/network/protocol/protocol.h"

class TPlySmth {
public:
    TPlySmth();
    TPlySmth &operator=(const TPlySmth &other);

    void bswap() {
        bswap_32(as(u32 *, &m_smth));
        bswap_32(as(u32 *, &m_smth1));
    };
public:
    u8 m_smth[4];
    u8 m_smth1[4];
};

extern "C" {
void __as__8TPlySmthFRC8TPlySmth(saddr arg0, saddr arg1);
void __ct__8TPlySmthFv(void *);
}

#endif
