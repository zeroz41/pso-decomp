#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERABEENEMY_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERABEENEMY_H

#include "types.h"
#include "pso/player/TUnk_804B6C24.h"

struct TObjContainerAbeEnemy : public TUnk_804B6C24 {
    virtual ~TObjContainerAbeEnemy();
    virtual void vfunc_81();
    virtual void debug_print_item_box_info();
    virtual void vfunc_80();
    virtual void vfunc_6(s16 *, s32);
    virtual f32 receive_physical_attack(void *, f32);
};

typedef char TObjContainerAbeEnemy_size[sizeof(TObjContainerAbeEnemy) == 0x368 ? 1 : -1];
#endif
