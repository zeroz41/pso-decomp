#ifndef PSO_PLAYER_TPLYSMTH_H
#define PSO_PLAYER_TPLYSMTH_H

#include "types.h"
#include "pso/macros.h"
#include "pso/network/protocol/protocol.h"

class TPlySmth {
public:
    TPlySmth();
    TPlySmth &operator=(const TPlySmth &other);

    void bswap();
public:
    u8 m_smth[4];
    u8 m_smth1[4];
};

#endif
