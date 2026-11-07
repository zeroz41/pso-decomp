#ifndef PSO_NPC_TOBJNPCLAPPY_H
#define PSO_NPC_TOBJNPCLAPPY_H

#include "types.h"
#include "pso/npc/TObjNpcBase.h"

struct TObjNpcLappy : public TObjNpcBase {
    virtual ~TObjNpcLappy();
    virtual void request_action(s32);
};

typedef char TObjNpcLappy_size[sizeof(TObjNpcLappy) == 0x3B8 ? 1 : -1];

extern "C" {
void *TObjNpcLappy__create(void *set_data);
u8 *TObjNpcLappy__ct(u8 *self, void *parent, s32 arg2);
}
#endif
