#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERITEM_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERITEM_H

#include "types.h"
#include "pso/player/TUnk_804B6C24.h"

struct TObjContainerItem : public TUnk_804B6C24 {
    virtual ~TObjContainerItem();
    virtual void vfunc_81();
    virtual void vfunc_80();
    virtual void vfunc_79();
    virtual void vfunc_6(s16 *, s32);
    static void *create(void *arg0);
};

typedef char TObjContainerItem_size[sizeof(TObjContainerItem) == 0x368 ? 1 : -1];
#endif
