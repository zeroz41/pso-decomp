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
    virtual void apply_saved_state(s16 *, s32);
    virtual f32 receive_physical_attack(TObjChara *, f32);
};

LAYOUT_ASSERT(TOContainerAncientEnemy_size, sizeof(TOContainerAncientEnemy) == 0x368);
void free_ancient_container_resources(void);

#endif
