#ifndef PSO_NPC_TOBJNPCEXPERTBASE_H
#define PSO_NPC_TOBJNPCEXPERTBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcExpertBase : public TUnk_804A9F50 {
    TObjNpcExpertBase(TObject *parent, void *set_data);
    virtual ~TObjNpcExpertBase();
    static void free_shared_data();
    static void load_shared_resource();
};

LAYOUT_ASSERT(TObjNpcExpertBase_size, sizeof(TObjNpcExpertBase) == 0x3B8);

extern "C" {
void *__dt__17TObjNpcExpertBaseFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcExpertBase.cpp ---
extern "C" {
void *__dt__17TObjNpcExpertBaseFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
