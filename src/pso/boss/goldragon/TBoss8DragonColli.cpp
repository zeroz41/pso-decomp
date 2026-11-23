#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/goldragon/TBoss8DragonColli.h"
#include "pso/boss/goldragon/TBoss8DragonColli_C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/TLobby.h"
#include "types.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801542CC.h"

#pragma defer_codegen on

const char *TBoss8DragonColli_C__name = "TBoss8DragonColli_C";
const char *TBoss8DragonColli__name = "TBoss8DragonColli";

CollisionBody boss8_collision_segment_desc = {
    {0.0f, 0.0f, 0.0f}, 25.0f, 0.0f, 0, 0x8003,
};

TBoss8DragonColli_C::TBoss8DragonColli_C(TObject *parent, s32 count, Vec *offset, f32 scale) : TObjCollidable(parent) {
    CollisionBody *e;
    s32 i;
    f32 zero;
    f32 step;
    f32 z;
    m_name = TBoss8DragonColli_C__name;
    VecCopy(&local_position, offset);
    entity_id = alloc_object_ids(0);
    body_count = count;
    bodies = (CollisionBody *)mem_alloc(body_count * sizeof(CollisionBody));
    step = 2.0f * scale;
    e = bodies;
    zero = 0.0f;
    z = scale * (body_count - 1);
    for (i = 0; i < body_count; i++) {
        copy_collision_body(e, &boss8_collision_segment_desc);
        e->offset.x = zero;
        e->offset.y = zero;
        e->offset.z = z;
        z -= step;
        e->radius = scale;
        e->flags = 0x10003;
        e++;
    }
    refresh_collision_body_centers();
    register_entity_by_id(this);
    clear_segment_flags();
}

TBoss8DragonColli_C::~TBoss8DragonColli_C() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TBoss8DragonColli_C::set_segment_flags() {
    s32 i;
    for (i = 0; i < body_count; i++) bodies[i].flags |= 1;
}

void TBoss8DragonColli_C::clear_segment_flags() {
    s32 i;
    for (i = 0; i < body_count; i++) bodies[i].flags &= ~1;
}

// Places the chain at local_position from pos turned by angle and enables its bodies.
void TBoss8DragonColli_C::enable_at(Vec *pos, s32 angle) {
    push_matrix();
    set_matrix_identity(NULL);
    post_translate_matrix(&pos->x);
    rotate_matrix_y(NULL, angle);
    matrix_mult_vec(NULL, &local_position, &position);
    pop_matrix();
    rotation_y = angle;
    refresh_collision_body_centers();
    set_segment_flags();
}

void TBoss8DragonColli_C::disable() { clear_segment_flags(); }

void TBoss8DragonColli_C::render() {  }

TBoss8DragonColli::TBoss8DragonColli(TObject *parent) : TObject(parent) {
    Vec offset;
    m_name = TBoss8DragonColli__name;
    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = 0.0f;
    objects[0] = new TBoss8DragonColli_C(this, 1, &offset, 25.0f);
    offset.x = -4.0f;
    offset.y = 0.0f;
    offset.z = 40.0f;
    objects[1] = new TBoss8DragonColli_C(this, 3, &offset, 10.0f);
    offset.x = -4.0f;
    offset.y = 0.0f;
    offset.z = -100.0f;
    objects[2] = new TBoss8DragonColli_C(this, 5, &offset, 10.0f);
}

TBoss8DragonColli::~TBoss8DragonColli() {
    for (saddr index = 0; index < 3; ++index) {
        if (objects[index] != NULL) {
            objects[index]->queue_destruction();
            objects[index] = NULL;
        }
    }
}
