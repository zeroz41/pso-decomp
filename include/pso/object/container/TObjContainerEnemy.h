#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERENEMY_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERENEMY_H

#include "types.h"
#include "pso/player/TObjContainerCommon.h"

struct TObjContainerEnemy : public TObjContainerCommon {
    TObjContainerEnemy(TObject *parent, void *set_data);
    virtual ~TObjContainerEnemy();
    virtual void debug_print_item_box_info();
    virtual void draw_model();
    virtual void update_state();
    virtual void spawn_break_effects() const;
    virtual void vfunc_6(s16 *, s32);
    virtual f32 receive_physical_attack(void *, f32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjContainerEnemy_size, sizeof(TObjContainerEnemy) == 0x368);


#endif
