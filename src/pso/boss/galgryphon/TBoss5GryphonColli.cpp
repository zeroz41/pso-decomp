#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/galgryphon/TBoss5GryphonColli.h"
#include "pso/boss/galgryphon/TBoss5GryphonDemo.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/boss/galgryphon/TBoss5GryphonColli_C.h"
#include <stddef.h>
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/math/MatrixVector.h"


#pragma readonly_strings on

extern "C" {
s32 gryphon_demo_collision_body_desc[11] = { 0, 0, 0, 0x3F800000, 0, 0, 0x8003, 0, 0, 0, 0 };

const char *lbl_805D2808 = "TBoss5GryphonColli_C";
const char *TBoss5GryphonColli__name = "TBoss5GryphonColli";


s32 __ct__7TObjectFP7TObject(void *, void *);
}

struct RecoveredGlobal_800661E4___vt__18TBoss5GryphonColli {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
extern RecoveredGlobal_800661E4___vt__18TBoss5GryphonColli __vt__18TBoss5GryphonColli;
extern const char *TBoss5GryphonColli__name;

LAYOUT_ASSERT(RecoveredGlobal_800661E4___vt__18TBoss5GryphonColli_size, sizeof(RecoveredGlobal_800661E4___vt__18TBoss5GryphonColli) == 0x18);
}

struct E_8006633C { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };

struct O_8006633C { u8 pad[0xa4]; E_8006633C *entries; s32 count; };

struct Seg_800663DC {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fc;
    u8 pad10[8];
    s32 flags;
    u8 pad1c[0x10];
};

struct Obj_800663DC {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    s16 f1c;
    u8 pad1e[0xA4 - 0x1E];
    Seg_800663DC *segs;
    s32 count;
    u8 posbuf[0xC];
};

extern "C" {
extern s32 gryphon_demo_collision_body_desc[];
extern const char *lbl_805D2808;

void TBoss5GryphonDemo__sub_8006626C(void* p);
int matrix_mult_vec(void*, void*, void*);
int post_translate_matrix(void*);
int rotate_matrix_y(void*, s32);

}

// Written last to first: the unit is generated deferred (see configure.py).

TBoss5GryphonColli_C::TBoss5GryphonColli_C(TObject *parent, s32 count, const Vec *pos, f32 len) : TObjCollidable(parent) {
    f32 zero;
    f32 step;
    f32 z;
    CollisionBody *body;
    s32 i;
    m_name = lbl_805D2808;
    entity_id = TLobby::alloc_actor_ids(0);
    VecCopy(&base_position, pos);
    body_count = count;
    bodies = (CollisionBody *)mem_alloc(body_count * sizeof(CollisionBody));
    step = 2.0f * len;
    body = bodies;
    zero = 0.0f;
    i = 0;
    z = len * (body_count - 1);
    for (; i < body_count; i++) {
        copy_collision_body(body, (const CollisionBody *)gryphon_demo_collision_body_desc);
        body->offset.x = zero;
        body->offset.y = zero;
        body->offset.z = z;
        z -= step;
        body->radius = len;
        body->flags = 0x10003;
        body++;
    }
    refresh_collision_body_centers();
    register_entity_by_id(this);
    clear_entry_flags();
}

TBoss5GryphonColli_C::~TBoss5GryphonColli_C() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TBoss5GryphonDemo::set_all_entry_flags() {
    O_8006633C *self = (O_8006633C *)this;
    s32 i;
    for (i = 0; i < self->count; i++) {
        self->entries[i].flags |= 1;
    }
}

void TBoss5GryphonColli_C::clear_entry_flags() {
    Obj_800663DC *self = (Obj_800663DC *)this;
    s32 i;
    for (i = 0; i < this->body_count; i++) {
        self->segs[i].flags &= ~1;
    }
}

void TBoss5GryphonDemo::draw_model(void* a1, s32 a2) { push_matrix(); set_matrix_identity((u8 *)((void*)0)); post_translate_matrix(a1); rotate_matrix_y((void*)0, a2); matrix_mult_vec((void*)0, (char*)this + 0xac, (char*)this + 0x38); pop_matrix(); *(s32*)((char*)this + 0x60) = a2; ((TObjCollidable *)this)->refresh_collision_body_centers(); set_all_entry_flags(); }
void TBoss5GryphonDemo__sub_8006626C(void* p) { ((TBoss5GryphonColli_C *)p)->clear_entry_flags(); }
void TBoss5GryphonColli_C::render() {  }

u8 *TBoss5GryphonColli__ct(u8 *object, saddr parent) {
    Vec stack;
    __ct__7TObjectFP7TObject((void *)object, (void *)parent);
    *(s32 **)((s8 *)object + 0x18) = &__vt__18TBoss5GryphonColli.value;
    *(s32 *)((s8 *)object + 0) = (saddr) ((saddr)TBoss5GryphonColli__name);
    stack.x = 0.0f;
    stack.y = 0.0f;
    stack.z = 3e+01f;
    ((TBoss5GryphonColli *)object)->objects[0] = new TBoss5GryphonColli_C((TObject *)object, 1, &stack, 35.0f);
    return object;
}

TBoss5GryphonColli::~TBoss5GryphonColli() {
    for (s32 index = 0; index < 1; ++index) {
        if (objects[index] != NULL) {
            objects[index]->queue_destruction();
            objects[index] = NULL;
        }
    }
}

void TBoss5GryphonDemo::draw_linked_model(void* position, s32 yaw) { ((TBoss5GryphonDemo *)(((TBoss5GryphonColli*)this)->objects[0]))->draw_model(position, yaw); }
int TBoss5GryphonDemo::get_state() { return ((int (*)(void*))TBoss5GryphonDemo__sub_8006626C)(*(void**)((char*)this + 0x1c)); }
