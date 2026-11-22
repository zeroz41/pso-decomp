#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject.h"

#include "pso/player/TObjPlayer.h"

#include "pso/system/vector.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/boss/dragon/TBoss1DragonColli_C.h"

#include "pso/boss/dragon/TBoss1DragonColli.h"

#include "pso/unk/text_803D96A8.h"

#include "types.h"

#include <stddef.h>

#include "pso/boss/darkfalz/TOBoss4Rock.h"

#pragma readonly_strings on

// Stored in the object name field by the constructors.
const char *TBoss1DragonColli_C__name = "TBoss1DragonColli_C";

const char *TBoss1DragonColli__name = "TBoss1DragonColli";

struct E_8002B3F4 { u8 pad[0x18]; u32 flags; u8 pad2[0x2c - 0x1c]; };

struct O_8002B3F4 { u8 pad[0xa4]; E_8002B3F4 *elems; s32 count; };

struct E_8002B42C { u8 pad[0x18]; u32 flags; u8 pad2[0x2c - 0x1c]; };

struct O_8002B42C { u8 pad[0xa4]; E_8002B42C *elems; s32 count; };

struct O_8002B3F4;

struct E_8002B4CC { f32 x, y, z, w; u8 pad10[8]; u32 flags; u8 pad1c[0x2c - 0x1c]; };

struct O_8002B4CC {
    const char *name;
    u8 pad4[0x18 - 4];
    void *vt;
    s16 f1c;
    u8 pad1e[0xa4 - 0x1e];
    E_8002B4CC *elems;
    s32 count;
    u8 pos[0xc];
};
extern "C" {

u16 register_entity_by_id(void *ov);

extern CollisionBody TBoss1DragonColli_sphere_chain_desc;
}

#include "pso/boss/dragon/TBoss1DragonDemo.h"

#include "pso/unk/TLobby.h"
#include "pso/math/MatrixVector.h"

#pragma inline_depth(1)

#pragma auto_inline off

#pragma dont_inline off
extern "C" {

void TBoss1DragonColli__sub_8002B35C(void* p);

int matrix_mult_vec(void*, void*, void*);

int post_translate_matrix(void*);

s32 free_collision_body_parts(void *);

void set_matrix_identity(u8 *arg0);

int rotate_matrix_y(void*, void*);




void run_task__7TObjectFv();

void render__7TObjectFv();

void render_shadows__7TObjectFv();

void vfunc_6__8TObjBaseFPsl();

void apply_object_set_data__8TObjBaseFPv();

void reset_motion_fields__14TObjCollidableFv();

void get_center__8TObjBaseFv();

void update_object_view_visibility__8TObjBaseFff();

void classify_actor_view_detail__8TObjBaseFfff();

void get_name__8TObjBaseFv();

void interact__14TObjCollidableFl();
}

CollisionBody TBoss1DragonColli_sphere_chain_desc = {
    {0.0f, 0.0f, 0.0f}, 25.0f, 0.0f, 0, 0x8003,
};

#pragma push
#pragma scheduling off
// Copies one collision body.
void copy_collision_body(CollisionBody *dst, const CollisionBody *src) {
    *dst = *src;
}

#pragma pop
#define self ((O_8002B4CC *)this)
TBoss1DragonColli_C::TBoss1DragonColli_C(TObject *parent, s32 arg2, Vec *arg3, f32 scale) : TObjCollidable(parent) {
    E_8002B4CC *e;
    s32 i;
    f32 zero;
    f32 step;
    f32 z;
    self->name = TBoss1DragonColli_C__name;
    VecCopy((Vec *)self->pos, arg3);
    self->f1c = TLobby::alloc_actor_ids(0);
    self->count = arg2;
    self->elems = (E_8002B4CC *)mem_alloc(self->count * 0x2C);
    step = 2.0f * scale;
    e = self->elems;
    zero = 0.0f;
    z = scale * (self->count - 1);
    for (i = 0; i < self->count; i++) {
        copy_collision_body((CollisionBody *)e, &TBoss1DragonColli_sphere_chain_desc);
        e->x = zero;
        e->y = zero;
        e->z = z;
        z -= step;
        e->w = scale;
        e->flags = 0x10003;
        e++;
    }
    ((TObjCollidable *)self)->refresh_collision_body_centers();
    register_entity_by_id(self);
    ((TBoss1DragonColli_C *)self)->clear_segment_flags();
}

#undef self
TBoss1DragonColli_C::~TBoss1DragonColli_C() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}
extern "C" {
void TBoss1DragonColli::set_elem_flags() {
    s32 i;
    for (i = 0; i < ((O_8002B42C *)this)->count; i++) {
        ((O_8002B42C *)this)->elems[i].flags |= 1;
    }
}

void TBoss1DragonColli_C::clear_segment_flags() {
    O_8002B3F4 *self = (O_8002B3F4 *)this;
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        self->elems[i].flags &= ~1;
    }
}

void TBoss1DragonColli::draw(void* a1, void* a2) { push_matrix(); set_matrix_identity((u8 *)((void*)0)); post_translate_matrix(a1); rotate_matrix_y((void*)0, a2); matrix_mult_vec((void*)0, (char*)this + 0xac, (char*)this + 0x38); pop_matrix(); *(void**)((char*)this + 0x60) = a2; ((TObjCollidable *)this)->refresh_collision_body_centers(); set_elem_flags(); }

void TBoss1DragonColli__sub_8002B35C(void* p) { ((TBoss1DragonColli_C *)p)->clear_segment_flags(); }

void TBoss1DragonColli_C::render() {  }
}

TBoss1DragonColli::TBoss1DragonColli(TObject *parent) : TObject(parent) {
    Vec stack;
    m_name = TBoss1DragonColli__name;
    stack.x = 0.0f;
    stack.y = 0.0f;
    stack.z = 0.0f;
    objects[0] = new TBoss1DragonColli_C(this, 1, &stack, 25.0f);
    stack.x = -4.0f;
    stack.y = 0.0f;
    stack.z = 40.0f;
    objects[1] = new TBoss1DragonColli_C(this, 3, &stack, 10.0f);
    stack.x = -4.0f;
    stack.y = 0.0f;
    stack.z = -100.0f;
    objects[2] = new TBoss1DragonColli_C(this, 5, &stack, 10.0f);
}

TBoss1DragonColli::~TBoss1DragonColli() {
    for (s32 index = 0; index < 3; ++index) {
        if (objects[index] != NULL) {
            objects[index]->queue_destruction();
            objects[index] = NULL;
        }
    }
}
