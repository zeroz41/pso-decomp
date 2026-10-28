#include "types.h"
#include "pso/boss/TBoss5GryphonColli.h"
#include "pso/boss/TBoss5GryphonDemo.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/TBoss5GryphonDemo.h"
#include "pso/TBoss5GryphonColli.h"
#include "pso/boss/TBoss5GryphonColli_C.h"
#include <stddef.h>
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
extern "C" void *__ct__13TUnk_804AF8A0FP7TObject(void *, s32);

extern "C" {
s32 gryphon_demo_collision_body_desc[11] = { 0, 0, 0, 0x3F800000, 0, 0, 0x8003, 0, 0, 0, 0 };

int TBoss5GryphonDemo::get_state() { return ((int (*)(void*))TBoss5GryphonDemo__sub_8006626C)(*(void**)((char*)this + 0x1c)); }
void TBoss5GryphonDemo::draw_linked_model(void* position, s32 yaw) { ((TBoss5GryphonDemo *)(((TBoss5GryphonColli*)this)->objects[0]))->draw_model(position, yaw); }

TBoss5GryphonColli_C *TBoss5GryphonDemo__sub_800663DC(TBoss5GryphonColli_C *self, s32 arg1, s32 arg2, void *arg3, f32 len);
s32 __ct__7TObjectFP7TObject(void *, void *);
}

TBoss5GryphonColli::~TBoss5GryphonColli() {
    for (s32 index = 0; index < 1; ++index) {
        if (objects[index] != NULL) {
            queue_destruction__7TObjectFv(objects[index]);
            objects[index] = NULL;
        }
    }
}

struct Stack_800661E4 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_800661E4___vt__18TBoss5GryphonColli {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
s32 __nw__7TObjectFUl(int);
extern RecoveredGlobal_800661E4___vt__18TBoss5GryphonColli __vt__18TBoss5GryphonColli;
extern s32 lbl_805D280C;

typedef char RecoveredGlobal_800661E4___vt__18TBoss5GryphonColli_size[sizeof(RecoveredGlobal_800661E4___vt__18TBoss5GryphonColli) == 0x18 ? 1 : -1];
u8 *TBoss5GryphonColli__ct(u8 *object, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_800661E4, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800661E4, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800661E4, sp10) == 0x8) ? 1 : -1];
    Stack_800661E4 stack;
    s32 temp_r3;
    s32 var_r0;
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__18TBoss5GryphonColli.value;
    *(s32 *)((s8 *)object + 0) = (s32) lbl_805D280C;
    stack.sp8 = 0.0f;
    stack.spC = 0.0f;
    stack.sp10 = 3e+01f;
    temp_r3 = __nw__7TObjectFUl(0xB8);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (s32)TBoss5GryphonDemo__sub_800663DC((TBoss5GryphonColli_C *)temp_r3, (s32)object, 1, &stack.sp8, 35.0f);
    }
    *(s32 *)((s8 *)object + 0x1C) = var_r0;
    return object;
}

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
void queue_destruction__7TObjectFv(void *arg0);
void *mem_alloc(u32 size);
u16 register_entity_by_id(void *ov);
int refresh_collision_body_centers__13TUnk_804AF8A0Fv(void*);
extern s32 gryphon_demo_collision_body_desc[];
extern s32 lbl_804886AC[];
extern s32 lbl_805D2808;

void TBoss5GryphonDemo__sub_8006626C(void* p);
int matrix_mult_vec(void*, void*, void*);
int post_translate_matrix(void*);
s32 free_collision_body_parts(void *);
int set_matrix_identity(void*);
int rotate_matrix_y(void*, s32);
int push_matrix(void*);
int pop_matrix(void);
s32 __dl__7TObjectFPv(void *);

void TBoss5GryphonColli_C::render() {  }
void TBoss5GryphonDemo__sub_8006626C(void* p) { ((TBoss5GryphonColli_C *)p)->clear_entry_flags(); }
void TBoss5GryphonDemo::draw_model(void* a1, s32 a2) { push_matrix(this); set_matrix_identity((void*)0); post_translate_matrix(a1); rotate_matrix_y((void*)0, a2); matrix_mult_vec((void*)0, (char*)this + 0xac, (char*)this + 0x38); pop_matrix(); *(s32*)((char*)this + 0x60) = a2; refresh_collision_body_centers__13TUnk_804AF8A0Fv(this); set_all_entry_flags(); }

void TBoss5GryphonColli_C::clear_entry_flags() {
    Obj_800663DC *self = (Obj_800663DC *)this;
    s32 i;
    for (i = 0; i < self->count; i++) {
        self->segs[i].flags &= ~1;
    }
}

void TBoss5GryphonDemo::set_all_entry_flags() {
    O_8006633C *self = (O_8006633C *)this;
    s32 i;
    for (i = 0; i < self->count; i++) {
        self->entries[i].flags |= 1;
    }
}

void *TBoss5GryphonColli_C::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804886AC;
        unregister_object_by_id();
        free_collision_body_parts(this);
        __dt__13TUnk_804AF8A0Fv(this, 0);
        if ((s16) arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

TBoss5GryphonColli_C *TBoss5GryphonDemo__sub_800663DC(TBoss5GryphonColli_C *self, s32 arg1, s32 arg2, void *arg3, f32 len) {
    Obj_800663DC *obj = (Obj_800663DC *)self;
    f32 zero;
    f32 step;
    f32 z;
    Seg_800663DC *s;
    s32 i;
    __ct__13TUnk_804AF8A0FP7TObject(self, arg1);
    obj->vt = lbl_804886AC;
    obj->f0 = lbl_805D2808;
    obj->f1c = TLobby::alloc_actor_ids(0);
    VecCopy((Vec *)obj->posbuf, (const Vec *)arg3);
    obj->count = arg2;
    obj->segs = (Seg_800663DC *)mem_alloc(obj->count * 0x2C);
    step = 2.0f * len;
    s = obj->segs;
    zero = 0.0f;
    i = 0;
    z = len * (obj->count - 1);
    for (; i < obj->count; i++) {
        copy_collision_body((CollisionBody *)s, (const CollisionBody *)gryphon_demo_collision_body_desc);
        s->f0 = zero;
        s->f4 = zero;
        s->f8 = z;
        z -= step;
        s->fc = len;
        s->flags = 0x10003;
        s++;
    }
    refresh_collision_body_centers__13TUnk_804AF8A0Fv(obj);
    register_entity_by_id(obj);
    self->clear_entry_flags();
    return self;
}

}
