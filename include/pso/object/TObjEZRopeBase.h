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
    void sub_800FF8CC(void *, void *, s32);
    void sub_800FF788(void *);
};

LAYOUT_ASSERT(TObjEZRopeSegment_size, sizeof(TObjEZRopeSegment) == 0x18);
LAYOUT_ASSERT(TObjEZRopeBase_size, sizeof(TObjEZRopeBase) == 0x30);

#endif
