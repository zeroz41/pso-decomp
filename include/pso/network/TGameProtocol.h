#ifndef PSO_NETWORK_TGAMEPROTOCOL_H
#define PSO_NETWORK_TGAMEPROTOCOL_H

#include "pso/TObject.h"
#include "types.h"

class TGameProtocol : public TObject {
public:
    virtual ~TGameProtocol();
    virtual void run_task();
};

extern "C" {
void *TGameProtocol__ct(void *game_protocol);
}

#endif
