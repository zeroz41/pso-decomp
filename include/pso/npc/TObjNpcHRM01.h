#ifndef PSO_NPC_TOBJNPCHRM01_H
#define PSO_NPC_TOBJNPCHRM01_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcHRM01 : public TUnk_804A9F50 {
    TObjNpcHRM01(TObject *parent, void *set_data);
    virtual ~TObjNpcHRM01();
    static void free_shared_objects();
    static void load_resources();
};

LAYOUT_ASSERT(TObjNpcHRM01_size, sizeof(TObjNpcHRM01) == 0x3B8);

class TObjControl;

extern "C" {
void *TObjNpcHRM01__create(void *set_data);
}

#endif
