#ifndef PSO_NPC_TOBJNPCLAPPY_H
#define PSO_NPC_TOBJNPCLAPPY_H

#include "types.h"
#include "pso/npc/TObjNpcBase.h"

struct TObjNpcLappy : public TObjNpcBase {
    TObjNpcLappy(TObject *parent, void *set_data);
    virtual ~TObjNpcLappy();
    virtual void request_action(s32);
    static void *create(void *set_data);

    static const char *name;
    static CollisionBody collision_body_parts;
};

LAYOUT_ASSERT(TObjNpcLappy_size, sizeof(TObjNpcLappy) == 0x3B8);

#endif
