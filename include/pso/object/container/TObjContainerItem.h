#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERITEM_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERITEM_H

#include "types.h"
#include "pso/player/TUnk_804B6C24.h"

struct TObjContainerItem : public TUnk_804B6C24 {
    TObjContainerItem(TObject *parent, void *set_data);
    virtual ~TObjContainerItem();
    virtual void vfunc_81();
    virtual void vfunc_80();
    virtual void vfunc_79() const;
    virtual void vfunc_6(s16 *, s32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjContainerItem_size, sizeof(TObjContainerItem) == 0x368);
#endif
