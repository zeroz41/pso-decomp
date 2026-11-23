#ifndef PSO_NPC_TOBJNPCHOSA_H
#define PSO_NPC_TOBJNPCHOSA_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcHosa : public TUnk_804A9F50 {
    TObjNpcHosa(TObject *parent, void *set_data);
    virtual ~TObjNpcHosa();
    static void destroy_static_instance();
    static void load_static_resource();
};

LAYOUT_ASSERT(TObjNpcHosa_size, sizeof(TObjNpcHosa) == 0x3B8);

extern "C" {
void *TObjNpcKenkyuW__create(void *set_data);
void *__dt__11TObjNpcHosaFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcHosa.cpp ---
extern "C" {
void *TObjNpcKenkyuW__create(void *set_data);
void *__dt__11TObjNpcHosaFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
