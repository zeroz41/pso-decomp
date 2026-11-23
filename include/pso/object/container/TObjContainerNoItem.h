#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERNOITEM_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERNOITEM_H

#include "types.h"
#include "pso/player/TUnk_804B6C24.h"

struct TObjContainerNoItem : public TUnk_804B6C24 {
    TObjContainerNoItem(TObject *parent, void *set_data);
    virtual ~TObjContainerNoItem();
    virtual void vfunc_81();
    virtual void vfunc_80();
    virtual void vfunc_79() const;
    virtual void vfunc_6(s16 *, s32);
    virtual f32 receive_physical_attack(void *, f32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjContainerNoItem_size, sizeof(TObjContainerNoItem) == 0x368);


#endif
