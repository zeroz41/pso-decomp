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

#pragma readonly_strings on

const char *TObjCollision::class_name = "TObjCollision";

void TObjCollision::render() {  }
void TObjCollision::run_task() {  }


void *TObjCollision::create(void *set_data) {
    return new TObjCollision(tl_06, set_data);
}
TObjCollision::~TObjCollision() {
    free_collision_body_parts(this);
    this->unregister_object_by_id();
}

TObjCollision::TObjCollision(TObject *parent, void *set_data) : TObjCollidable(parent) {
    s32 flag;
    saddr data = (saddr)set_data;
    this->m_name = TObjCollision::class_name;
    VecCopy(&this->position, (const Vec *)(data + 0xC));
    copy_xyz(&this->rotation_x, (void *)(data + 0x18));
    VecCopy(&this->scale, (const Vec *)(data + 0x24));
    this->actorFlags = (s32) (this->actorFlags | 0x02000000);
    this->body.offset.x = 0.0f;
    this->body.offset.y = 0.0f;
    this->body.offset.z = 0.0f;
    this->body.radius = (f32) this->scale.x;
    this->body.half_width = (f32) this->scale.y;
    if (this->scale.z < 0.0f) {
        flag = 1;
    } else {
        flag = 0;
    }
    this->body.shape = flag;
    this->body.flags = 0x10001;
    if (fabs_float(this->scale.z) < 1000.0f) {
        this->body.flags = (s32) (this->body.flags & 0xFFFFFEFF);
    } else {
        this->body.flags = (s32) (this->body.flags | 0x100);
    }
    init_collision_body_parts(this, &this->body, 1);
    this->register_object_by_id();
}

