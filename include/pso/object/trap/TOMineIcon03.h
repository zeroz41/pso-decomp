#ifndef PSO_OBJECT_TRAP_TOMINEICON03_H
#define PSO_OBJECT_TRAP_TOMINEICON03_H

#include "types.h"
#include "pso/object/trap/TOMine.h"

struct TOMineIcon03 : public TOMine {
    TOMineIcon03(TObject *parent, ObjectSetData *set_data);
    virtual ~TOMineIcon03();
    virtual void vfunc_84();
    virtual void spawn_blast_particle();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TOMineIcon03_size, sizeof(TOMineIcon03) == 0x37C);

extern const char *mine_icon03_name;

#endif
