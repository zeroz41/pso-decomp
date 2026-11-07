#ifndef PSO_NPC_TOBJNPCKENKYUW_H
#define PSO_NPC_TOBJNPCKENKYUW_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcKenkyuW : public TUnk_804A9F50 {
    virtual ~TObjNpcKenkyuW();
    static void destroy_instance();
    static void load_resource_instance();
};

typedef char TObjNpcKenkyuW_size[sizeof(TObjNpcKenkyuW) == 0x3B8 ? 1 : -1];

extern "C" {
u8 *TObjNpcKenkyuW__ct(u8 *arg0, s32 arg1, s32 arg2);
void clear_technique_contacts__10TObjPlayerFv(void);
}

// --- C functions defined in TObjNpcKenkyuW.cpp ---
extern "C" {
u8 *TObjNpcKenkyuW__ct(u8 *player, s32 arg1, s32 arg2);
void clear_technique_contacts__10TObjPlayerFv(void);
}
// --- end of C functions

#endif
