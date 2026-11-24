#ifndef PSO_NPC_TOBJNPCCLOAKROOMBASE_H
#define PSO_NPC_TOBJNPCCLOAKROOMBASE_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct BmlResource;

struct TObjNpcCloakroomBase : public TObjNpcFemale {
    TObjNpcCloakroomBase(TObject *parent, void *set_data);
    virtual ~TObjNpcCloakroomBase();
    virtual void play_voice();
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    static void *create(void *set_data);
    static void destroy_static_instance();
    static void load_shared_resource();
    static const char *name;
    static BmlResource *static_instance;
};

LAYOUT_ASSERT(TObjNpcCloakroomBase_size, sizeof(TObjNpcCloakroomBase) == 0x3B8);

#endif
