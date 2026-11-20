#ifndef PSO_NPC_TOBJNPCHOSA_H
#define PSO_NPC_TOBJNPCHOSA_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcHosa : public TUnk_804A9F50 {
    virtual ~TObjNpcHosa();
    static void destroy_static_instance();
    static void load_static_resource();
};

LAYOUT_ASSERT(TObjNpcHosa_size, sizeof(TObjNpcHosa) == 0x3B8);

extern "C" {
u8 *TObjNpcHosa__ct(u8 *arg0, s32 arg1, saddr arg2);
void *TObjNpcKenkyuW__create(void *arg0);
void *__dt__11TObjNpcHosaFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcHosa.cpp ---
extern "C" {
u8 *TObjNpcHosa__ct(u8 *player, s32 arg1, saddr arg2);
void *TObjNpcKenkyuW__create(void *arg0);
void *__dt__11TObjNpcHosaFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
