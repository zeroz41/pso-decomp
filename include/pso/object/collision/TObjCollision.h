#ifndef PSO_OBJECT_COLLISION_TOBJCOLLISION_H
#define PSO_OBJECT_COLLISION_TOBJCOLLISION_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjCollidable.h"

struct ObjectSetData;

// An invisible collision volume placed by the map's set data: one body, a
// sphere or (scale.z < 0) a box sized by the set scale.
struct TObjCollision : public TObjCollidable {
    static const char *class_name;
    TObjCollision(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjCollision();
    CollisionBody body;  // the one body; its size comes from the scale and it is a box when scale.z is negative
    virtual void render();
    virtual void run_task();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjCollision_size, sizeof(TObjCollision) == 0xD8);
#endif
