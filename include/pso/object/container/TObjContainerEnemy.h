#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERENEMY_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERENEMY_H

#include "types.h"
#include "pso/player/TUnk_804B6C24.h"

struct TObjContainerEnemy : public TUnk_804B6C24 {
    virtual ~TObjContainerEnemy();
    virtual void debug_print_item_box_info();
    virtual void vfunc_81();
    virtual void vfunc_80();
    virtual void vfunc_79();
    virtual void vfunc_6(s16 *, s32);
    virtual f32 receive_physical_attack(void *, f32);
    static void *create(void *arg0);
};

typedef char TObjContainerEnemy_size[sizeof(TObjContainerEnemy) == 0x368 ? 1 : -1];

extern "C" {
u8 *TObjContainerEnemy__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__18TObjContainerEnemyFv(void *arg0, s16 arg1);
}

#endif
