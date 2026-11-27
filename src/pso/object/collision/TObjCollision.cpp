#include "types.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/object/collision/TObjCollision.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/object/base/ObjectSetData.h"

#pragma readonly_strings on

const char *TObjCollision::class_name = "TObjCollision";

void TObjCollision::render() {  }
void TObjCollision::run_task() {  }


void *TObjCollision::create(void *set_data) {
    return new TObjCollision(tl_06, (ObjectSetData *)set_data);
}
TObjCollision::~TObjCollision() {
    free_collision_body_parts(this);
    this->unregister_object_by_id();
}

TObjCollision::TObjCollision(TObject *parent, ObjectSetData *set_data) : TObjCollidable(parent) {
    m_name = class_name;
    VecCopy(&position, &set_data->position);
    copy_xyz(&rotation, set_data->rotation);
    VecCopy(&scale, &set_data->scale);
    actorFlags |= 0x02000000;
    body.offset.x = 0.0f;
    body.offset.y = 0.0f;
    body.offset.z = 0.0f;
    body.radius = scale.x;
    body.half_width = scale.y;
    body.shape = scale.z < 0.0f ? 1 : 0;
    body.flags = 0x10001;
    if (fabs_float(scale.z) < 1000.0f) {
        body.flags &= ~0x100;
    } else {
        body.flags |= 0x100;
    }
    init_collision_body_parts(this, &body, 1);
    register_object_by_id();
}
