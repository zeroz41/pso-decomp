#ifndef PSO_NPC_TOBJNPCBRINGER_H
#define PSO_NPC_TOBJNPCBRINGER_H
#include "types.h"
#include "pso/npc/TObjNpcBase.h"

class TObjNpcBringer : public TObjNpcBase {
public:
    TObjNpcBringer(TObject *parent, void *set_data);
    virtual ~TObjNpcBringer();
    virtual void request_action(s32);
    static void *create(void *set_data);

    static const char *name;
    static CollisionBody collision_body_parts[2];
};
LAYOUT_ASSERT(TObjNpcBringer_size, sizeof(TObjNpcBringer) == 0x3B8);

#endif
