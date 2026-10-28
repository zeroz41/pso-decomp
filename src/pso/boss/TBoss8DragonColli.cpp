#include "pso/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TBoss8DragonColli_C.h"
class TBoss8DragonColli : public TObject {
public:
    virtual void render();
    virtual ~TBoss8DragonColli();
    TObject *objects[3];
};
#include "types.h"
struct E_802F3144 { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };

struct O_802F3144 { u8 pad[0xa4]; E_802F3144 *arr; s32 count; };

struct E_802F310C { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };

struct O_802F310C { u8 pad[0xa4]; E_802F310C *arr; s32 count; };

struct O_802F310C;
struct E_802F31E4 { f32 x, y, z, w; u8 pad10[8]; u32 flags; u8 pad1c[0x2c - 0x1c]; };

struct O_802F31E4 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt;
    s16 f1c;
    u8 pad1e[0xa4 - 0x1e];
    E_802F31E4 *elems;
    s32 count;
    u8 pos[0xc];
};

extern "C" {
void set_all_flags__17TBoss8DragonColliFPv(O_802F3144 *self);
void fn_8002B630(u8 *arg0, u8 *arg1);
void *mem_alloc(u32 size);
u16 register_entity_by_id(void *ov);
s32 __ct__13TUnk_804AF8A0FP7TObject(void *, void *);
extern u8 boss8_collision_segment_desc[];
extern s32 lbl_804E4BB4[];
extern s32 lbl_805D4000;
extern const f32 lbl_805DED20;
extern const f32 lbl_805DED38;
s32 init_collision_segments__17TBoss8DragonColliFiPviPvf(int arg0, void *arg1, int arg2, void *arg3, f32 scale);
void queue_destruction__7TObjectFv(void *);
}

TBoss8DragonColli::~TBoss8DragonColli() {
    for (s32 index = 0; index < 3; ++index) {
        if (objects[index] != NULL) {
            queue_destruction__7TObjectFv(objects[index]);
            objects[index] = NULL;
        }
    }
}

#include <stddef.h>
#include "pso/misc/TLobby.h"

struct Stack_802F2F68 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_802F2F68___vt__17TBoss8DragonColli { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_802F2F68___vt__17TBoss8DragonColli_size[sizeof(RecoveredGlobal_802F2F68___vt__17TBoss8DragonColli) == 0x18 ? 1 : -1];

extern "C" {
s32 __nw__7TObjectFUl(int);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern void *__vt__17TBoss8DragonColli[];
extern s32 lbl_805D4004;
extern const f32 lbl_805DED24;
extern const f32 lbl_805DED28;
extern const f32 lbl_805DED2C;
extern const f32 lbl_805DED30;
extern const f32 lbl_805DED34;
u8 *TBoss8DragonColli__ct(u8 *arg0, s32 arg1);
void render__19TBoss8DragonColli_CFv(void);
void TBoss8DragonColli__sub_802F3074(void* p);
void *destroy__17TBoss8DragonColliFPvs(void *arg0, s16 arg1);
void init__17TBoss8DragonColliFPvPvPv(void* p, void* a1, void* a2);
int matrix_mult_vec(void*, void*, void*);
int post_translate_matrix(void*);
void free_collision_body_parts(void *);
int set_matrix_identity(void*);
int rotate_matrix_y(void*, void*);
int push_matrix(void*);
int pop_matrix(void);
void __dl__7TObjectFPv(void *);

u8 *TBoss8DragonColli__ct(u8 *object, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_802F2F68, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802F2F68, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_802F2F68, sp10) == 0x8) ? 1 : -1];
    Stack_802F2F68 stack;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = (s32 *)__vt__17TBoss8DragonColli;
    *(s32 *)((s8 *)object + 0) = (s32) lbl_805D4004;
    stack.sp8 = lbl_805DED20;
    stack.spC = lbl_805DED20;
    stack.sp10 = lbl_805DED20;
    temp_r3 = __nw__7TObjectFUl(0xB8);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = init_collision_segments__17TBoss8DragonColliFiPviPvf(temp_r3, object, 1, &stack.sp8, lbl_805DED24);
    }
    *(s32 *)((s8 *)object + 0x1C) = var_r0;
    stack.sp8 = lbl_805DED28;
    stack.spC = lbl_805DED20;
    stack.sp10 = lbl_805DED2C;
    temp_r3_2 = __nw__7TObjectFUl(0xB8);
    var_r0_2 = temp_r3_2;
    if (var_r0_2 != 0) {
        var_r0_2 = init_collision_segments__17TBoss8DragonColliFiPviPvf(temp_r3_2, object, 3, &stack.sp8, lbl_805DED30);
    }
    *(s32 *)((s8 *)object + 0x20) = var_r0_2;
    stack.sp8 = lbl_805DED28;
    stack.spC = lbl_805DED20;
    stack.sp10 = lbl_805DED34;
    temp_r3_3 = __nw__7TObjectFUl(0xB8);
    var_r0_3 = temp_r3_3;
    if (var_r0_3 != 0) {
        var_r0_3 = init_collision_segments__17TBoss8DragonColliFiPviPvf(temp_r3_3, object, 5, &stack.sp8, lbl_805DED30);
    }
    *(s32 *)((s8 *)object + 0x24) = var_r0_3;
    return object;
}

void TBoss8DragonColli_C::render() {  }
void TBoss8DragonColli__sub_802F3074(void* p) { ((TBoss8DragonColli_C *)p)->clear_segment_flags(); }
void init__17TBoss8DragonColliFPvPvPv(void* p, void* a1, void* a2) { push_matrix(p); set_matrix_identity((void*)0); post_translate_matrix(a1); rotate_matrix_y((void*)0, a2); matrix_mult_vec((void*)0, (char*)p + 0xac, (char*)p + 0x38); pop_matrix(); *(void**)((char*)p + 0x60) = a2; ((TUnk_804AF8A0 *)p)->refresh_collision_body_centers(); set_all_flags__17TBoss8DragonColliFPv((O_802F3144 *)(p)); }

void TBoss8DragonColli_C::clear_segment_flags() {
    O_802F310C *self = (O_802F310C *)this;
    s32 i;
    for (i = 0; i < self->count; i++) self->arr[i].flags &= ~1;
}

void set_all_flags__17TBoss8DragonColliFPv(O_802F3144 *self) {
    s32 i;
    for (i = 0; i < self->count; i++) self->arr[i].flags |= 1;
}

void *destroy__17TBoss8DragonColliFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E4BB4;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804AF8A0Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#define self ((O_802F31E4 *)arg0)
s32 init_collision_segments__17TBoss8DragonColliFiPviPvf(int arg0, void *arg1, int arg2, void *arg3, f32 scale) {
    E_802F31E4 *e;
    s32 i;
    f32 zero;
    f32 step;
    f32 z;
    __ct__13TUnk_804AF8A0FP7TObject(self, arg1);
    self->vt = ((u8 *)&lbl_804E4BB4);
    self->f0 = lbl_805D4000;
    VecCopy((Vec *)self->pos, (const Vec *)arg3);
    self->f1c = TLobby::alloc_actor_ids(0);
    self->count = arg2;
    self->elems = (E_802F31E4 *)mem_alloc(self->count * 0x2C);
    step = lbl_805DED38 * scale;
    e = self->elems;
    zero = lbl_805DED20;
    z = scale * (self->count - 1);
    for (i = 0; i < self->count; i++) {
        fn_8002B630((u8 *)e, boss8_collision_segment_desc);
        e->x = zero;
        e->y = zero;
        e->z = z;
        z -= step;
        e->w = scale;
        e->flags = 0x10003;
        e++;
    }
    ((TUnk_804AF8A0 *)self)->refresh_collision_body_centers();
    register_entity_by_id(self);
    ((TBoss8DragonColli_C *)self)->clear_segment_flags();
    return arg0;
}
#undef self

void __dt__17TBoss8DragonColliFv();
void run_task__7TObjectFv();
void render__7TObjectFv();
void render_shadows__7TObjectFv();
void vfunc_6__13TUnk_804B9870FPsl();
void apply_object_set_data__13TUnk_804B9870FPv();
void reset_motion_fields__13TUnk_804AF8A0Fv();
void vfunc_9__13TUnk_804B9870Fv();
void update_object_view_visibility__13TUnk_804B9870Fff();
void classify_actor_view_detail__13TUnk_804B9870Ffff();
void get_name__13TUnk_804B9870Fv();
void vfunc_13__13TUnk_804AF8A0Fl();
u8 boss8_collision_segment_desc[0x2C] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x41, 0xC8, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x80, 0x03,
};
void *__vt__17TBoss8DragonColli[] = {
    0,
    0,
    (void *)__dt__17TBoss8DragonColliFv,
    (void *)run_task__7TObjectFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};
s32 lbl_804E4BB4[] = {
    0,
    0,
    (s32)destroy__17TBoss8DragonColliFPvs,
    (s32)run_task__7TObjectFv,
    (s32)render__19TBoss8DragonColli_CFv,
    (s32)render_shadows__7TObjectFv,
    (s32)vfunc_6__13TUnk_804B9870FPsl,
    (s32)apply_object_set_data__13TUnk_804B9870FPv,
    (s32)reset_motion_fields__13TUnk_804AF8A0Fv,
    (s32)vfunc_9__13TUnk_804B9870Fv,
    (s32)update_object_view_visibility__13TUnk_804B9870Fff,
    (s32)classify_actor_view_detail__13TUnk_804B9870Ffff,
    (s32)get_name__13TUnk_804B9870Fv,
    (s32)vfunc_13__13TUnk_804AF8A0Fl,
    0,
};
}
