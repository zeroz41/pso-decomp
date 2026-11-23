#ifndef PSO_OBJECT_TRAP_TOMINEICON01_H
#define PSO_OBJECT_TRAP_TOMINEICON01_H

#include "types.h"
#include "pso/object/trap/TOMine.h"

struct TOMineIcon01 : public TOMine {
    TOMineIcon01(TObject *parent, void *set_data);
    virtual ~TOMineIcon01();
    virtual void vfunc_84();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOMineIcon01_size, sizeof(TOMineIcon01) == 0x37C);

#endif
