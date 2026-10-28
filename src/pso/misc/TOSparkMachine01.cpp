#include "types.h"
#include "pso/misc/TOSparkMachine01.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TOSparkMachine01.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80177330_lbl_804B43F0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80177330_lbl_804B43F0_size[sizeof(RecoveredGlobal_80177330_lbl_804B43F0) == 0x10 ? 1 : -1];

struct VBase_801773D8 { u8 pad[0x18]; };

struct Obj_801773D8 : VBase_801773D8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(void *);
    s32 unk1c;
    s32 unk20;
    s32 unk24;
    u8 pad28[0x30 - 0x28];
    u32 flags;
    s32 unk34;
    u8 pad38[0x68 - 0x38];
    f32 unk68;
    u8 pad6c[0x90 - 0x6C];
    f32 timer[4];
    u8 on[4];
    f32 speed;
    f32 unka8;
    f32 unkac;
};

struct Model_801773D8 { u8 pad[8]; s32 a; s32 b; };

struct Res_801773D8 { u8 pad[0x42C]; Model_801773D8 *model; };

struct Obj_80177088 { u8 pad[0x90]; f32 timer[4]; u8 on[4]; f32 speed; };

struct VBase_801771F4 { u8 pad[0x18]; };

struct Node_801771F4 { u8 pad[4]; s32 f4; u8 m[0x28]; Node_801771F4 *next; };

struct Res_801771F4 { u8 pad[0x2C]; Node_801771F4 *head; };

struct Obj_801771F4 : VBase_801771F4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
    s32 unk1c;
    s32 unk20;
    s32 unk24;
    u8 pad28[0x34 - 0x28];
    Res_801771F4 *res;
    u8 m38[0x60 - 0x38];
    s32 unk60;
    u8 pad64[0xA0 - 0x64];
    u8 on[4];
    f32 speed;
    f32 unka8;
    f32 unkac;
};

extern "C" {
extern const f32 TOSparkMachine01__data_805DB9EC;
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80177330_lbl_804B43F0 bm_fe_obj_tank_hikari_resource_descriptor;
extern u32 TOSparkMachine01__static_resource;
void __ct__13TUnk_804B9870FP7TObject(void *, s32);
extern s32 __vt__16TOSparkMachine01[];
extern s32 lbl_805D3174;
extern s32 tl_05;
extern const f32 lbl_805DB9F0;
extern const f32 lbl_805DB9F4;
extern const f32 lbl_805DB9F8;
s32 rand(void);
extern const f32 lbl_805DB9E8;
void begin_effect_render__13TParticleCtrlFv(void *);
void rotate_matrix_y(int, int);
void push_matrix();
void post_translate_matrix(void *);
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TOSparkMachine01::update_spark_toggle(s32 i) {
    Obj_80177088 *self = (Obj_80177088 *)this;
    switch (self->on[i]) {
    case 1:
        self->timer[i] += self->speed;
        if (lbl_805DB9E8 * (f32)rand() < self->timer[i]) {
            self->on[i] = 0;
            self->timer[i] = TOSparkMachine01__data_805DB9EC;
        }
        break;
    default:
        self->timer[i] += self->speed;
        if (lbl_805DB9E8 * (f32)rand() < self->timer[i]) {
            self->on[i] = 1;
            self->timer[i] = TOSparkMachine01__data_805DB9EC;
        }
        break;
    }
}

void TOSparkMachine01::run_task() {
    s32 var_r31;
    if (TOSparkMachine01__data_805DB9EC < this->target_scale) {
        var_r31 = 0;
        do {
            update_spark_toggle(var_r31);
            var_r31 += 1;
        } while (var_r31 < 4);
        return;
    }
    this->m_a3 = 0;
    this->m_a2 = 0;
    this->m_a0 = 0;
    update_spark_toggle(1);
}

void TOSparkMachine01::render() {
    Obj_801771F4 *self = (Obj_801771F4 *)this;
    Node_801771F4 *n;
    s32 i;
    Res_801771F4 *r;
    if (self->m8(self->unka8, self->unkac) != 0) {
        push_matrix();
        post_translate_matrix(self->m38);
        rotate_matrix_y(0, self->unk60);
        TObjFish::set_global_param(self->unk24);
        r = self->res;
        n = r->head;
        begin_effect_render__13TParticleCtrlFv(r);
        for (i = 0; i < 4; i++) {
            switch (self->on[i]) {
            case 1:
                push_matrix();
                post_translate_matrix(n->m);
                draw_ginja_model(n->f4);
                pop_matrix();
                break;
            }
            n = n->next;
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TOSparkMachine01::create() {
    void *o = __nw__7TObjectFUl(0xB0);
    if (o != NULL) {
        o = TOSparkMachine01__ct(o, this);
    }
    return o;
}

void TOSparkMachine01::destroy_static_instance() {
    if ((u32) TOSparkMachine01__static_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOSparkMachine01__static_resource, 1);
        TOSparkMachine01__static_resource = 0U;
    }
}

void TOSparkMachine01::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_fe_obj_tank_hikari_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TOSparkMachine01__static_resource) = var_r0;
}

}
TOSparkMachine01::~TOSparkMachine01() {

}
extern "C" {
void *TOSparkMachine01__ct(void *arg0, void *arg1) {
    Obj_801773D8 *self = (Obj_801773D8 *)arg0;
    s32 i;
    __ct__13TUnk_804B9870FP7TObject(self, tl_05);
    *(void **)((u8 *)self + 0x18) = ((s32 *)&__vt__16TOSparkMachine01);
    *(s32 *)self = lbl_805D3174;
    self->m5(arg1);
    self->unk34 = ((Res_801773D8 *)TOSparkMachine01__static_resource)->model->a;
    self->unk24 = ((Res_801773D8 *)TOSparkMachine01__static_resource)->model->b;
    self->unka8 = lbl_805DB9F0;
    self->unkac = lbl_805DB9F4;
    self->flags |= 0x40000000;
    for (i = 0; i < 4; i++) {
        self->timer[i] = TOSparkMachine01__data_805DB9EC;
        self->on[i] = 0;
    }
    self->speed = lbl_805DB9F8 + self->unk68;
    return self;
}

}
