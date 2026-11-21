#ifndef PSO_NPC_TOBJNPCCONNOISSEUR_H
#define PSO_NPC_TOBJNPCCONNOISSEUR_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcConnoisseur : public TUnk_804A9F50 {
    TObjNpcConnoisseur(TObject *parent, void *set_data);
    virtual ~TObjNpcConnoisseur();
    static void destroy_instance();
    static void load_section_motion();
};

typedef char TObjNpcConnoisseur_size[sizeof(TObjNpcConnoisseur) == 0x3B8 ? 1 : -1];

extern "C" {
void *TObjNpcExpertBase__create(void *arg0);
void *__dt__18TObjNpcConnoisseurFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcConnoisseur.cpp ---
extern "C" {
void *TObjNpcExpertBase__create(void *arg0);
void *__dt__18TObjNpcConnoisseurFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
