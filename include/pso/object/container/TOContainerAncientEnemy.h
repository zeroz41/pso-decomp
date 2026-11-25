#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTENEMY_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTENEMY_H

#include "types.h"
#include "pso/player/TObjContainerCommon.h"

struct TOContainerAncientEnemy : public TObjContainerCommon {
    TOContainerAncientEnemy(void *set_data);
    virtual ~TOContainerAncientEnemy();
    virtual void debug_print_item_box_info();
    virtual void draw_model();
    virtual void update_state();
    virtual void spawn_break_effects() const;
    virtual void vfunc_6(s16 *, s32);
    virtual f32 receive_physical_attack(void *, f32);
};

LAYOUT_ASSERT(TOContainerAncientEnemy_size, sizeof(TOContainerAncientEnemy) == 0x368);
#endif
