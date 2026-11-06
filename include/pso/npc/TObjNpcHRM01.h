#ifndef PSO_NPC_TOBJNPCHRM01_H
#define PSO_NPC_TOBJNPCHRM01_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcHRM01 : public TUnk_804A9F50 {
    virtual ~TObjNpcHRM01();
    static void free_shared_objects();
    static void load_resources();
};

typedef char TObjNpcHRM01_size[sizeof(TObjNpcHRM01) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcHRM01__create(void *set_data);
TObjNpcHRM01 *TObjNpcHRM01__ct(TObjNpcHRM01 *npc, TObjControl *control, void *set_data);
}

#endif
