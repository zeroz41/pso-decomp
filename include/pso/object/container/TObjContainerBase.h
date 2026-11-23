#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERBASE_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERBASE_H

#include "types.h"
#include "pso/player/TUnk_804B6C24.h"

struct TObjContainerBase : public TUnk_804B6C24 {
    TObjContainerBase(TObject *parent, void *set_data);
    virtual ~TObjContainerBase();
    virtual void vfunc_79() const;
    virtual void vfunc_81();
    virtual void vfunc_80();
    virtual void vfunc_6(s16 *, s32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjContainerBase_size, sizeof(TObjContainerBase) == 0x368);
#endif
