#ifndef PSO_OBJECT_TOBJTANK_H
#define PSO_OBJECT_TOBJTANK_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjTank : public TObjCollidable {
    TObjTank(TObject *parent, ObjectSetData *placement);
    virtual ~TObjTank();
    virtual void render();
    virtual void run_task();
    static void free_globals();
    static void load_globals();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjTank_size, sizeof(TObjTank) == 0xAC);

#endif
