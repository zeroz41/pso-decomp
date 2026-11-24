#ifndef PSO_NPC_TOBJNPCFEMALEMACHO_H
#define PSO_NPC_TOBJNPCFEMALEMACHO_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct BmlResource;

struct TObjNpcFemaleMacho : public TObjNpcFemale {
    TObjNpcFemaleMacho(TObject *parent, void *set_data);
    virtual ~TObjNpcFemaleMacho();
    static void close_dialog_window();
    static void load_resources();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *lobby_resource;
};

LAYOUT_ASSERT(TObjNpcFemaleMacho_size, sizeof(TObjNpcFemaleMacho) == 0x3B8);

#endif
