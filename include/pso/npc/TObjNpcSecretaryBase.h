#ifndef PSO_NPC_TOBJNPCSECRETARYBASE_H
#define PSO_NPC_TOBJNPCSECRETARYBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

struct TObjNpcSecretaryBase : public TUnk_804A8640 {
    TObjNpcSecretaryBase(TObject *parent, void *set_data);
    virtual ~TObjNpcSecretaryBase();
    static void free_static_data();
    static void load_static_data();
};

LAYOUT_ASSERT(TObjNpcSecretaryBase_size, sizeof(TObjNpcSecretaryBase) == 0x3B8);

class TObjControl;

extern "C" {
void *TObjNpcSecretaryBase__create(void *set_data);
}

#endif
