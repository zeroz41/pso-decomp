#ifndef PSO_NPC_TOBJNPCMOJA_H
#define PSO_NPC_TOBJNPCMOJA_H

#include "types.h"
#include "pso/npc/TObjNpcBase.h"

struct TObjNpcMoja : public TObjNpcBase {
    virtual ~TObjNpcMoja();
    virtual void request_action(s32);
    static void *create(void *arg0);
};

LAYOUT_ASSERT(TObjNpcMoja_size, sizeof(TObjNpcMoja) == 0x3B8);
#endif
