#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5PillarSmoke.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/render/ModelDrawContext.h"

#pragma readonly_strings on


const char *TObjBoss5PillarSmoke__name = "TObjBoss5PillarSmoke";

// Where the smoke particles are parked (fn_8028AE1C, the constructor) and the
// node origin the model callback projects (TObjBoss5PillarDemo__sub_8028ACE8).
static const Vec lbl_80450CD0 = {0.0f, -1000.0f, 0.0f};
static const Vec lbl_80450CDC = {0.0f, 0.0f, 0.0f};

struct Smoke_8028AEA4 {
    u8 pad[0x18];
    void *vt;
    s32 count;
    void **a;
    void **b;
};

struct Node_8028AF6C { u8 pad[0x2C]; Node_8028AF6C *child; Node_8028AF6C *next; };

struct Smoke_8028AF6C {
    s32 f0;
    u8 pad[0x14];
    void *vt;
    s32 count;
    void **a;
    void **b;
};

// The pillar's model callback and the smoke placement: their .sbss, the two
// templates above and the smoke layout (count, a, b at 0x1C) are this unit's,
// so the TU starts at 0x8028ACE8, not at the destructor.
struct Pd_8028ACE8 { u8 pad[0x1C]; s32 count; void **a; void **b; };
struct O_8028AE1C { u8 pad[0x1c]; s32 count; void **a; void **b; };

extern "C" {
s32 boss5_pillar_demo_index;
void * boss5_pillar_demo_ptr;

void TObjBoss5PillarDemo__sub_8028ACE8(Pd_8028ACE8 *arg0, void* _w1) {
    f32 sp[3];
    s32 idx;
    idx = boss5_pillar_demo_index - 1;
    boss5_pillar_demo_index += 1;
    if (idx >= 0 && idx < arg0->count) {
        transform_to_view__11TCameraCtrlFii((saddr)&lbl_80450CDC, (saddr)sp);
        if (arg0->a != NULL && arg0->a[idx] != NULL) {
            ((TParticleCtrl *)arg0->a[idx])->set_position(sp);
        }
        if (arg0->b != NULL && arg0->b[idx] != NULL) {
            ((TParticleCtrl *)arg0->b[idx])->set_position(sp);
        }
    }
}

void TObjBoss5PillarDemo__sub_8028AD88(void* a0) { TObjBoss5PillarDemo__sub_8028ACE8((Pd_8028ACE8 *)(boss5_pillar_demo_ptr), a0); }

void TObjBoss5PillarDemo__sub_8028ADB0(u32 arg0) {
    if (arg0 != 0U) {
        set_model_node_callback(0);
    }
}

void fn_8028ADDC(void *p) {
    if (p) {
        boss5_pillar_demo_index = 0;
        boss5_pillar_demo_ptr = p;
        set_model_node_callback((saddr)TObjBoss5PillarDemo__sub_8028AD88);
    }
}
void fn_8028AE1C(O_8028AE1C *smoke) {
    s32 i;
    for (i = 0; i < smoke->count; i++) {
        if (smoke->a[i] != 0) {
            ((TParticleCtrl *)smoke->a[i])->set_position((void *)&lbl_80450CD0);
        }
        if (smoke->b[i] != 0) {
            ((TParticleCtrl *)smoke->b[i])->set_position((void *)&lbl_80450CD0);
        }
    }
}
}

void TObjBoss5PillarSmoke::render() {  }
void TObjBoss5PillarSmoke::run_task() {  }

extern "C" {
extern s32 __vt__20TObjBoss5PillarSmoke[];
void __ct__7TObjectFP7TObject(void *, void *);
Smoke_8028AF6C *TObjBoss5PillarSmoke__ct(Smoke_8028AF6C *arg0, void *parent, Node_8028AF6C *smokeParent);
}
TObjBoss5PillarSmoke::~TObjBoss5PillarSmoke() {
    s32 i;
    for (i = ((Smoke_8028AEA4 *)this)->count - 1; i >= 0; i--) {
        if (((Smoke_8028AEA4 *)this)->b[i] != NULL) {
            ((TObject *)(((Smoke_8028AEA4 *)this)->b[i]))->queue_destruction();
            ((Smoke_8028AEA4 *)this)->b[i] = NULL;
        }
        if (((Smoke_8028AEA4 *)this)->a[i] != NULL) {
            ((TObject *)(((Smoke_8028AEA4 *)this)->a[i]))->queue_destruction();
            ((Smoke_8028AEA4 *)this)->a[i] = NULL;
        }
    }
    mem_free(((Smoke_8028AEA4 *)this)->b);
    mem_free(((Smoke_8028AEA4 *)this)->a);
}

Smoke_8028AF6C *TObjBoss5PillarSmoke__ct(Smoke_8028AF6C *arg0, void *parent, Node_8028AF6C *smokeParent) {
    s32 i;
    __ct__7TObjectFP7TObject(arg0, parent);
    arg0->vt = __vt__20TObjBoss5PillarSmoke;
    arg0->f0 = ((saddr)TObjBoss5PillarSmoke__name);
    arg0->count = 0;
    arg0->a = NULL;
    arg0->b = NULL;
    if (smokeParent == NULL) {
        ((TObject *)arg0)->queue_destruction();
        return arg0;
    }
    for (smokeParent = smokeParent->child; smokeParent != NULL; smokeParent = smokeParent->next) {
        arg0->count++;
    }
    if (arg0->count <= 0) {
        ((TObject *)arg0)->queue_destruction();
        return arg0;
    }
    arg0->a = (void **)mem_alloc(arg0->count * 4);
    arg0->b = (void **)mem_alloc(arg0->count * 4);
    for (i = 0; i < arg0->count; i++) {
        arg0->a[i] = spawn_continuous_particle_effect_with_flags((void *)&lbl_80450CD0, 0x213, 0x40);
        arg0->b[i] = spawn_continuous_particle_effect_with_flags((void *)&lbl_80450CD0, 0x214, 0x40);
    }
    return arg0;
}
