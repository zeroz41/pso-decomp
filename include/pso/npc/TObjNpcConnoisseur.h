#ifndef PSO_NPC_TOBJNPCCONNOISSEUR_H
#define PSO_NPC_TOBJNPCCONNOISSEUR_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;

struct TObjNpcConnoisseur : public TObjNpcMale {
    TObjNpcConnoisseur(TObject *parent, void *set_data);
    virtual ~TObjNpcConnoisseur();
    static void destroy_instance();
    static void load_section_motion();
    static void *create(void *set_data);
    static const char *name;
    static s32 section_id;
    static BmlResource *instance;
};

LAYOUT_ASSERT(TObjNpcConnoisseur_size, sizeof(TObjNpcConnoisseur) == 0x3B8);

#endif
