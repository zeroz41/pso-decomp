#ifndef PSO_NPC_TOBJNPCCLOAKROOMBASE_H
#define PSO_NPC_TOBJNPCCLOAKROOMBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

struct TObjNpcCloakroomBase : public TUnk_804A8640 {
    TObjNpcCloakroomBase(TObject *parent, void *set_data);
    virtual ~TObjNpcCloakroomBase();
    virtual void play_voice();
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    static void *create(void *set_data);
    static void destroy_static_instance();
    static void load_shared_resource();
};

LAYOUT_ASSERT(TObjNpcCloakroomBase_size, sizeof(TObjNpcCloakroomBase) == 0x3B8);

extern "C" {
void *TObjNpcConnoisseur__create(void *set_data);
void *__dt__20TObjNpcCloakroomBaseFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcCloakroomBase.cpp ---
extern "C" {
void *TObjNpcConnoisseur__create(void *set_data);
void *__dt__20TObjNpcCloakroomBaseFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
