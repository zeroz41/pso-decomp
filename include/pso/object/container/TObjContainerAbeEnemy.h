#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERABEENEMY_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERABEENEMY_H

#include "types.h"
#include "pso/object/container/TObjContainerBase.h"

struct TObjContainerAbeEnemy : public TObjContainerBase {
    TObjContainerAbeEnemy(TObject *parent, void *set_data);
    virtual ~TObjContainerAbeEnemy();
    virtual void spawn_break_effects() const;
    virtual void draw_model();
    virtual void debug_print_item_box_info();
    virtual void update_state();
    virtual void apply_saved_state(s16 *, s32);
    virtual f32 receive_physical_attack(TObjChara *, f32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjContainerAbeEnemy_size, sizeof(TObjContainerAbeEnemy) == 0x368);
#endif
