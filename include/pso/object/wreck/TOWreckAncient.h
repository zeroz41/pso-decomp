#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

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

typedef char TOWreckAncient_size[sizeof(TOWreckAncient) == 0xB4 ? 1 : -1];

// One collision sphere per wreck model (TOWreckAncient.cpp); each subclass passes its model's entry.
extern CollisionBody TOWreckAncient__collision_body_templates[7];
#endif
