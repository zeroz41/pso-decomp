#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERNOITEM_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERNOITEM_H

#include "types.h"
#include "pso/player/TUnk_804B6C24.h"

struct TObjContainerNoItem : public TUnk_804B6C24 {
    virtual ~TObjContainerNoItem();
    virtual void vfunc_81();
    virtual void vfunc_80();
    virtual void vfunc_79();
    virtual void vfunc_6(s16 *, s32);
    virtual f32 receive_physical_attack(void *, f32);
    static void *create(void *arg0);
};

typedef char TObjContainerNoItem_size[sizeof(TObjContainerNoItem) == 0x368 ? 1 : -1];

extern "C" {
u8 *TObjContainerNoItem__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__19TObjContainerNoItemFv(void *arg0, s16 arg1);
}

#endif
