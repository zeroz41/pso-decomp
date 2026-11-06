#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5PillarSmoke.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D3B30 = "TObjBoss5PillarSmoke";
}

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

extern "C" {
void mem_free(void *);
extern s32 __vt__20TObjBoss5PillarSmoke[];
void *mem_alloc(u32 size);
void __ct__7TObjectFP7TObject(void *, void *);
extern u8 lbl_80450CD0[];
extern const char *lbl_805D3B30;
Smoke_8028AF6C *TObjBoss5PillarSmoke__ct(Smoke_8028AF6C *arg0, void *arg1, Node_8028AF6C *arg2);
}
TObjBoss5PillarSmoke::~TObjBoss5PillarSmoke() {
    s32 i;
    for (i = ((Smoke_8028AEA4 *)this)->count - 1; i >= 0; i--) {
        if (((Smoke_8028AEA4 *)this)->b[i] != NULL) {
            queue_destruction__7TObjectFv(((Smoke_8028AEA4 *)this)->b[i]);
            ((Smoke_8028AEA4 *)this)->b[i] = NULL;
        }
        if (((Smoke_8028AEA4 *)this)->a[i] != NULL) {
            queue_destruction__7TObjectFv(((Smoke_8028AEA4 *)this)->a[i]);
            ((Smoke_8028AEA4 *)this)->a[i] = NULL;
        }
    }
    mem_free(((Smoke_8028AEA4 *)this)->b);
    mem_free(((Smoke_8028AEA4 *)this)->a);
}

Smoke_8028AF6C *TObjBoss5PillarSmoke__ct(Smoke_8028AF6C *arg0, void *arg1, Node_8028AF6C *arg2) {
    s32 i;
    __ct__7TObjectFP7TObject(arg0, arg1);
    arg0->vt = __vt__20TObjBoss5PillarSmoke;
    arg0->f0 = ((s32)lbl_805D3B30);
    arg0->count = 0;
    arg0->a = NULL;
    arg0->b = NULL;
    if (arg2 == NULL) {
        queue_destruction__7TObjectFv(arg0);
        return arg0;
    }
    for (arg2 = arg2->child; arg2 != NULL; arg2 = arg2->next) {
        arg0->count++;
    }
    if (arg0->count <= 0) {
        queue_destruction__7TObjectFv(arg0);
        return arg0;
    }
    arg0->a = (void **)mem_alloc(arg0->count * 4);
    arg0->b = (void **)mem_alloc(arg0->count * 4);
    for (i = 0; i < arg0->count; i++) {
        arg0->a[i] = spawn_continuous_particle_effect_with_flags(lbl_80450CD0, 0x213, 0x40);
        arg0->b[i] = spawn_continuous_particle_effect_with_flags(lbl_80450CD0, 0x214, 0x40);
    }
    return arg0;
}

