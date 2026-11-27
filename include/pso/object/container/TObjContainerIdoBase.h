#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERIDOBASE_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERIDOBASE_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TObjContainerIdoBase : public TObjCollidable {
public:
    TObjContainerIdoBase(TObject *parent);
    virtual ~TObjContainerIdoBase();
    virtual void update_state();
    virtual void draw_model();
    virtual void render();
    virtual void run_task();
    // The far_depth and radius render passes to update_object_view_visibility.
    f32 view_far_depth;
    f32 view_radius;
};

#endif
