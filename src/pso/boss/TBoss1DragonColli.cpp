#include "pso/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TBoss1DragonColli_C.h"
class TBoss1DragonColli : public TObject {
public:
    TObject *objects[3];
public:
    virtual void render();
    virtual ~TBoss1DragonColli();
};

#include "types.h"

#include <stddef.h>
struct Stack_8002B250 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_8002B250___vt__17TBoss1DragonColli { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8002B250___vt__17TBoss1DragonColli_size[sizeof(RecoveredGlobal_8002B250___vt__17TBoss1DragonColli) == 0x18 ? 1 : -1];

struct E_8002B3F4 { u8 pad[0x18]; u32 flags; u8 pad2[0x2c - 0x1c]; };

struct O_8002B3F4 { u8 pad[0xa4]; E_8002B3F4 *elems; s32 count; };

struct E_8002B42C { u8 pad[0x18]; u32 flags; u8 pad2[0x2c - 0x1c]; };

struct O_8002B42C { u8 pad[0xa4]; E_8002B42C *elems; s32 count; };

struct O_8002B3F4;
struct E_8002B4CC { f32 x, y, z, w; u8 pad10[8]; u32 flags; u8 pad1c[0x2c - 0x1c]; };

struct O_8002B4CC {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt;
    s16 f1c;
    u8 pad1e[0xa4 - 0x1e];
    E_8002B4CC *elems;
    s32 count;
    u8 pos[0xc];
};

extern "C" {
s32 __nw__7TObjectFUl(int);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern void *__vt__17TBoss1DragonColli[];
extern s32 TBoss1DragonColli__name;
extern const f32 lbl_805D8108;
extern const f32 lbl_805D810C;
extern const f32 lbl_805D8110;
extern const f32 lbl_805D8114;
extern const f32 lbl_805D8118;
extern const f32 lbl_805D811C;
u8 *TBoss1DragonColli__ct(u8 *arg0, s32 arg1);
void set_elem_flags__17TBoss1DragonColliFPv(O_8002B42C *self);
void *mem_alloc(u32 size);
u16 register_entity_by_id(void *ov);
s32 __ct__14TObjCollidableFP7TObject(void *, void *);
extern CollisionBody TBoss1DragonColli_sphere_chain_desc;
extern s32 __vt__19TBoss1DragonColli_C[];
extern s32 TBoss1DragonColli_C__name;
extern const f32 lbl_805D8120;
s32 TBoss1DragonColli_C__ct(int arg0, void *arg1, int arg2, void *arg3, f32 scale);
void queue_destruction__7TObjectFv(void*);
}

TBoss1DragonColli::~TBoss1DragonColli() {
    for (s32 index = 0; index < 3; ++index) {
        if (objects[index] != NULL) {
            queue_destruction__7TObjectFv(objects[index]);
            objects[index] = NULL;
        }
    }
}

#include "pso/TBoss1DragonDemo.h"
#include "pso/misc/TLobby.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
void render__19TBoss1DragonColli_CFv(void);
void TBoss1DragonColli__sub_8002B35C(void* p);
void *__dt__19TBoss1DragonColli_CFv(void *arg0, s16 arg1);
void draw__17TBoss1DragonColliFPvPvPv(void* p, void* a1, void* a2);
int matrix_mult_vec(void*, void*, void*);
int post_translate_matrix(void*);
s32 free_collision_body_parts(void *);
int set_matrix_identity(void*);
int rotate_matrix_y(void*, void*);
int push_matrix(void*);
int pop_matrix(void);
s32 __dl__7TObjectFPv(void *);

u8 *TBoss1DragonColli__ct(u8 *object, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_8002B250, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8002B250, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8002B250, sp10) == 0x8) ? 1 : -1];
    Stack_8002B250 stack;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = (s32 *)__vt__17TBoss1DragonColli;
    *(s32 *)((s8 *)object + 0) = (s32) TBoss1DragonColli__name;
    stack.sp8 = lbl_805D8108;
    stack.spC = lbl_805D8108;
    stack.sp10 = lbl_805D8108;
    temp_r3 = __nw__7TObjectFUl(0xB8);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = TBoss1DragonColli_C__ct(temp_r3, object, 1, &stack.sp8, lbl_805D810C);
    }
    *(s32 *)((s8 *)object + 0x1C) = var_r0;
    stack.sp8 = lbl_805D8110;
    stack.spC = lbl_805D8108;
    stack.sp10 = lbl_805D8114;
    temp_r3_2 = __nw__7TObjectFUl(0xB8);
    var_r0_2 = temp_r3_2;
    if (var_r0_2 != 0) {
        var_r0_2 = TBoss1DragonColli_C__ct(temp_r3_2, object, 3, &stack.sp8, lbl_805D8118);
    }
    *(s32 *)((s8 *)object + 0x20) = var_r0_2;
    stack.sp8 = lbl_805D8110;
    stack.spC = lbl_805D8108;
    stack.sp10 = lbl_805D811C;
    temp_r3_3 = __nw__7TObjectFUl(0xB8);
    var_r0_3 = temp_r3_3;
    if (var_r0_3 != 0) {
        var_r0_3 = TBoss1DragonColli_C__ct(temp_r3_3, object, 5, &stack.sp8, lbl_805D8118);
    }
    *(s32 *)((s8 *)object + 0x24) = var_r0_3;
    return object;
}

void TBoss1DragonColli_C::render() {  }

void TBoss1DragonColli__sub_8002B35C(void* p) { ((TBoss1DragonColli_C *)p)->clear_segment_flags(); }

void draw__17TBoss1DragonColliFPvPvPv(void* p, void* a1, void* a2) { push_matrix(p); set_matrix_identity((void*)0); post_translate_matrix(a1); rotate_matrix_y((void*)0, a2); matrix_mult_vec((void*)0, (char*)p + 0xac, (char*)p + 0x38); pop_matrix(); *(void**)((char*)p + 0x60) = a2; ((TObjCollidable *)p)->refresh_collision_body_centers(); set_elem_flags__17TBoss1DragonColliFPv((O_8002B42C *)(p)); }

void TBoss1DragonColli_C::clear_segment_flags() {
    O_8002B3F4 *self = (O_8002B3F4 *)this;
    s32 i;
    for (i = 0; i < self->count; i++) {
        self->elems[i].flags &= ~1;
    }
}

void set_elem_flags__17TBoss1DragonColliFPv(O_8002B42C *self) {
    s32 i;
    for (i = 0; i < self->count; i++) {
        self->elems[i].flags |= 1;
    }
}

void *__dt__19TBoss1DragonColli_CFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TBoss1DragonColli_C;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__14TObjCollidableFv(arg0, 0);
        if ((s16) arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define self ((O_8002B4CC *)arg0)
s32 TBoss1DragonColli_C__ct(int arg0, void *arg1, int arg2, void *arg3, f32 scale) {
    E_8002B4CC *e;
    s32 i;
    f32 zero;
    f32 step;
    f32 z;
    __ct__14TObjCollidableFP7TObject(self, arg1);
    self->vt = ((u8 *)&__vt__19TBoss1DragonColli_C);
    self->f0 = TBoss1DragonColli_C__name;
    VecCopy((Vec *)self->pos, (const Vec *)arg3);
    self->f1c = TLobby::alloc_actor_ids(0);
    self->count = arg2;
    self->elems = (E_8002B4CC *)mem_alloc(self->count * 0x2C);
    step = lbl_805D8120 * scale;
    e = self->elems;
    zero = lbl_805D8108;
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
    return arg0;
}
#undef self

// *dst = *src. In the original this is the compiler-generated CollisionBody
// assignment, emitted unscheduled the way CodeWarrior 1.3.2 does (this TU
// compiles identically under 1.3.2 with `*e = desc` left to the compiler);
// it is a named function here because the 2.6 TUs that call it must not
// emit copies of their own.
#pragma push
#pragma scheduling off
void copy_collision_body(CollisionBody *dst, const CollisionBody *src) {
    *dst = *src;
}
#pragma pop

void __dt__17TBoss1DragonColliFv();
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
CollisionBody TBoss1DragonColli_sphere_chain_desc = {
    {0.0f, 0.0f, 0.0f}, 25.0f, 0.0f, 0, 0x8003,
};
void *__vt__17TBoss1DragonColli[] = {
    0,
    0,
    (void *)__dt__17TBoss1DragonColliFv,
    (void *)run_task__7TObjectFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};
s32 __vt__19TBoss1DragonColli_C[] = {
    0,
    0,
    (s32)__dt__19TBoss1DragonColli_CFv,
    (s32)run_task__7TObjectFv,
    (s32)render__19TBoss1DragonColli_CFv,
    (s32)render_shadows__7TObjectFv,
    (s32)vfunc_6__8TObjBaseFPsl,
    (s32)apply_object_set_data__8TObjBaseFPv,
    (s32)reset_motion_fields__14TObjCollidableFv,
    (s32)get_center__8TObjBaseFv,
    (s32)update_object_view_visibility__8TObjBaseFff,
    (s32)classify_actor_view_detail__8TObjBaseFfff,
    (s32)get_name__8TObjBaseFv,
    (s32)interact__14TObjCollidableFl,
    0,
};
}
