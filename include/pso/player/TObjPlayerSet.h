#ifndef PSO_PLAYER_TOBJPLAYERSET_H
#define PSO_PLAYER_TOBJPLAYERSET_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjPlayerSet : public TObjBase {
    virtual ~TObjPlayerSet();
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0);
};

typedef char TObjPlayerSet_size[sizeof(TObjPlayerSet) == 0x90 ? 1 : -1];
#endif
