#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERBASE_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERBASE_H

#include "types.h"
#include "pso/player/TUnk_804B6C24.h"

struct TObjContainerBase : public TUnk_804B6C24 {
    virtual ~TObjContainerBase();
    virtual void vfunc_81();
    virtual void vfunc_80();
    virtual void vfunc_6(s16 *, s32);
};

typedef char TObjContainerBase_size[sizeof(TObjContainerBase) == 0x368 ? 1 : -1];
#endif
