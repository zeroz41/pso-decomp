#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/wreck/TOWreckAncientResources.h"

struct TOWreckAncient : public TObjCollidable {
    TOWreckAncient(s32 model_index);
    virtual ~TOWreckAncient();
    virtual void render();
    static void free_statics();
    static void load_resources();
    // inferred: render passes both to update_object_view_visibility(far_depth, radius).
    f32 view_far_depth;
    f32 view_radius;
};

LAYOUT_ASSERT(TOWreckAncient_size, sizeof(TOWreckAncient) == 0xB4);

#endif
