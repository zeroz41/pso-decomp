#ifndef PSO_OBJECT_TOBJTANK_H
#define PSO_OBJECT_TOBJTANK_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjTank : public TObjCollidable {
    TObjTank(TObject *parent, saddr set_data);
    virtual ~TObjTank();
    virtual void render();
    virtual void run_task();
    static void free_globals();
    static void load_globals();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjTank_size, sizeof(TObjTank) == 0xAC);

extern "C" {
void *__dt__8TObjTankFv(void *arg0, s16 arg1);
}

#endif
