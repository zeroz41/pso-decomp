#ifndef PSO_NPC_TOBJNPCLAPPY_H
#define PSO_NPC_TOBJNPCLAPPY_H

#include "types.h"
#include "pso/npc/TObjNpcBase.h"

struct TObjNpcLappy : public TObjNpcBase {
    TObjNpcLappy(TObject *parent, void *set_data);
    virtual ~TObjNpcLappy();
    virtual void request_action(s32);
};

LAYOUT_ASSERT(TObjNpcLappy_size, sizeof(TObjNpcLappy) == 0x3B8);

extern "C" {
void *TObjNpcLappy__create(void *set_data);
}
#endif
