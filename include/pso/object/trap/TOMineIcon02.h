#ifndef PSO_OBJECT_TRAP_TOMINEICON02_H
#define PSO_OBJECT_TRAP_TOMINEICON02_H

#include "types.h"
#include "pso/object/trap/TOMine.h"

struct TOMineIcon02 : public TOMine {
    TOMineIcon02(TObject *parent, void *set_data);
    virtual ~TOMineIcon02();
    virtual void vfunc_84();
    virtual void vfunc_82();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOMineIcon02_size, sizeof(TOMineIcon02) == 0x37C);

#endif
