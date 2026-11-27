#ifndef PSO_OBJECT_TRAP_TOMINEICON04_H
#define PSO_OBJECT_TRAP_TOMINEICON04_H

#include "types.h"
#include "pso/object/trap/TOMine.h"

struct TOMineIcon04 : public TOMine {
    TOMineIcon04(TObject *parent, ObjectSetData *set_data);
    virtual ~TOMineIcon04();
    virtual void vfunc_84();
    virtual void spawn_blast_particle();
    virtual void play_trigger_sound();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TOMineIcon04_size, sizeof(TOMineIcon04) == 0x37C);
extern const char *mine_icon04_name;

#endif
