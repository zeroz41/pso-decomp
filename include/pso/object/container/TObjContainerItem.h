#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERITEM_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERITEM_H

#include "types.h"
#include "pso/object/container/TObjContainerBase.h"

struct TObjContainerItem : public TObjContainerBase {
    TObjContainerItem(TObject *parent, void *set_data);
    virtual ~TObjContainerItem();
    virtual void draw_model();
    virtual void update_state();
    virtual void spawn_break_effects() const;
    virtual void apply_saved_state(s16 *, s32);
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjContainerItem_size, sizeof(TObjContainerItem) == 0x368);

#endif
