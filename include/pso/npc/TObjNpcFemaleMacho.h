#ifndef PSO_NPC_TOBJNPCFEMALEMACHO_H
#define PSO_NPC_TOBJNPCFEMALEMACHO_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

struct BmlResource;

struct TObjNpcFemaleMacho : public TUnk_804A8640 {
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
