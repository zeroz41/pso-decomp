#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERNOITEM_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERNOITEM_H

#include "types.h"
#include "pso/player/TObjContainerCommon.h"

struct TObjContainerNoItem : public TObjContainerCommon {
    TObjContainerNoItem(TObject *parent, void *set_data);
    virtual ~TObjContainerNoItem();
    virtual void draw_model();
    virtual void update_state();
    virtual void spawn_break_effects() const;
    virtual void apply_saved_state(s16 *, s32);
    virtual f32 receive_physical_attack(TObjChara *, f32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjContainerNoItem_size, sizeof(TObjContainerNoItem) == 0x368);


#endif
