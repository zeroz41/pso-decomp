#ifndef PSO_NPC_TOBJNPCKENKYUW_H
#define PSO_NPC_TOBJNPCKENKYUW_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct TObjNpcKenkyuW : public TObjNpcMale {
    TObjNpcKenkyuW(TObject *parent, void *set_data);
    virtual ~TObjNpcKenkyuW();
    static void destroy_instance();
    static void load_resource_instance();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjNpcKenkyuW_size, sizeof(TObjNpcKenkyuW) == 0x3B8);

extern "C" {
void clear_technique_contacts__10TObjPlayerFv(void);
}

// --- C functions defined in TObjNpcKenkyuW.cpp ---
extern "C" {
void clear_technique_contacts__10TObjPlayerFv(void);
}
// --- end of C functions

#endif
