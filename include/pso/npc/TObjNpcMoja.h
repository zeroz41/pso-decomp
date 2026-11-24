#ifndef PSO_NPC_TOBJNPCMOJA_H
#define PSO_NPC_TOBJNPCMOJA_H

#include "types.h"
#include "pso/npc/TObjNpcBase.h"

struct TObjNpcMoja : public TObjNpcBase {
    TObjNpcMoja(TObject *parent, void *set_data);
    virtual ~TObjNpcMoja();
    virtual void render();
    virtual void request_action(s32);
    static void *create(void *set_data);

    static const char *name;
    static CollisionBody collision_body_parts;
};

LAYOUT_ASSERT(TObjNpcMoja_size, sizeof(TObjNpcMoja) == 0x3B8);
#endif
