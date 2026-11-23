#ifndef PSO_NPC_TOBJNPCGOVERNORBASE_H
#define PSO_NPC_TOBJNPCGOVERNORBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcGovernorBase : public TUnk_804A9F50 {
    TObjNpcGovernorBase(TObject *parent, void *set_data);
    virtual ~TObjNpcGovernorBase();
    static void free_shared_data();
    static void load_shared_resource();
};

LAYOUT_ASSERT(TObjNpcGovernorBase_size, sizeof(TObjNpcGovernorBase) == 0x3B8);

extern "C" {
void *TObjNpcGovernorBase__create(void *set_data);
void *__dt__19TObjNpcGovernorBaseFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcGovernorBase.cpp ---
extern "C" {
void *TObjNpcGovernorBase__create(void *set_data);
void *__dt__19TObjNpcGovernorBaseFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
