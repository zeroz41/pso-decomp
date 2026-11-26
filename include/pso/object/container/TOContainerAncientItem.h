#ifndef PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEM_H
#define PSO_OBJECT_CONTAINER_TOCONTAINERANCIENTITEM_H
#include "types.h"
#include "pso/object/container/TObjContainerBase.h"

class TOContainerAncientItem : public TObjContainerBase {
public:
    TOContainerAncientItem(void *set_data);
    virtual ~TOContainerAncientItem();
    virtual void draw_model();
    virtual void update_state();
    virtual void spawn_break_effects() const;
};

#endif
