#ifndef PSO_OBJECT_TOBJEZROPEBASE_H
#define PSO_OBJECT_TOBJEZROPEBASE_H

#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "types.h"

struct NJS_OBJECT;

// One rope of the object: count points spaced by step; a count below 2 ends the table. The drawn
// pieces use body_model, the last one tip_model.
struct TObjEZRopeSegment {
    s8 count;
    Vec step;
    NJS_OBJECT *body_model;
    NJS_OBJECT *tip_model;
};

// Where a rope hangs from, and the twist its pieces are drawn with.
struct TObjEZRopeEnd {
    s32 twist;
    Vec pos;
};

// A sphere the rope points are pushed out of; the list ends at a negative radius.
struct TObjEZRopeCollider {
    f32 radius;
    Vec center;
};

class TObjEZRopeBase : public TObject {
public:
    s32 segment_count;
    TObjEZRopeSegment *segments;
    TObjEZRopeEnd *ends;
    TObjEZRopeCollider *colliders;
    Vec *points;
public:
    TObjEZRopeBase(TObject *parent);
    virtual ~TObjEZRopeBase();
    // Takes the rope tables and allocates the points; the points start at each end, spaced by step.
    void init_ropes(TObjEZRopeSegment *segment_list, TObjEZRopeEnd *end_list, TObjEZRopeCollider *collider_list);
    // Moves the points by gravity, keeping each rope's spacing, and pushes them out of the colliders.
    void update_ropes(Vec *gravity);
    void resolve_collisions(Vec *p, f32 len);
};

LAYOUT_ASSERT(TObjEZRopeSegment_size, sizeof(TObjEZRopeSegment) == 0x18);
LAYOUT_ASSERT(TObjEZRopeBase_size, sizeof(TObjEZRopeBase) == 0x30);

#endif
