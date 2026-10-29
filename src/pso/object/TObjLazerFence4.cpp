#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/object/TObjLazerFence4.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MaterialAlphaCompare.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_80193524.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/CameraDistanceFade.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TLazerFenceSw.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/misc/TOAirconCave01.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/npc/TObjNpcEnemy.h"

struct LazerFence4Base_801930E8 { char pad[0x18]; };
struct LazerFence4VObj_801930E8 : LazerFence4Base_801930E8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Cnt_801933C8 { s32 pad0; s32 f4; };

struct Obj_801933C8 { u8 padA0[0xAC]; s32 fAC; f32 fB0; u8 padB4[6]; u16 fBA; u8 padBC[8]; Cnt_801933C8 *fC4; };

struct Node_80193188 { u32 flags; void *model; u8 pad8[0x24]; Node_80193188 *child; Node_80193188 *sibling; };

struct Fence_80193188 { u8 pad0[0x8C]; s32 f8C; u8 pad90[0x2C]; Node_80193188 *fBC; Node_80193188 *fC0; s32 fC4; void *fC8[12]; };

extern "C" {
void rotate_matrix_y(int, void *);
void push_matrix(void);
s32 pop_matrix(void);
void post_translate_matrix(void *);
void draw_ginja_object(void *);
s32 draw_ginja_model_with_motion(s32, s32, f32);
extern void *lazer_fence_norm_texture_list;
u8 is_current_floor_switch_set(int);

s32 get_bml_motion(s32, s32);
Node_80193188 *get_bml_model(s32, s32);
extern s32 lazer_fence_norm_bml_resource;
f32 xz_distance_squared(void *, s32);
s32 update_object_view_visibility__8TObjBaseFff(void *, f32, f32);

extern s32 camera_ctrl_instance;

s32 TObjLazerFence4::update_object_view_visibility(f32 farg0, f32 farg1) {
    u8 *arg0 = (u8 *)this;
    if (TMainTask::get_render_pass() == 1) {
        return this->visibility;
    }
    if (xz_distance_squared((u8 *)&this->position, camera_ctrl_instance + 0x178) < (farg1 * farg1)) {
        this->visibility = 1;
        return this->visibility;
    }
    return update_object_view_visibility__8TObjBaseFff(arg0, farg0, farg1);
}

void TObjLazerFence4::init_models() {
    Fence_80193188 *arg0 = (Fence_80193188 *)this;
    Node_80193188 *node;
    s32 i;
    s32 j;
    if (arg0->f8C % 2 == 0) {
        arg0->fBC = get_bml_model(lazer_fence_norm_bml_resource, 4);
        arg0->fC0 = get_bml_model(lazer_fence_norm_bml_resource, 5);
        arg0->fC4 = get_bml_motion(lazer_fence_norm_bml_resource, 2);
    } else {
        arg0->fBC = get_bml_model(lazer_fence_norm_bml_resource, 6);
        arg0->fC0 = get_bml_model(lazer_fence_norm_bml_resource, 7);
        arg0->fC4 = get_bml_motion(lazer_fence_norm_bml_resource, 3);
    }
    for (j = 0; j < 12; j++) {
        arg0->fC8[j] = 0;
    }
    i = 0;
    node = arg0->fBC->child;
    if (node != 0) {
        while (node != 0 && i < 12) {
            arg0->fC8[i++] = node->model;
            node = node->sibling;
        }
    }
}

void TObjLazerFence4::draw() {
    TObjFish::set_global_param((s32)lazer_fence_norm_texture_list);
    push_matrix();
    post_translate_matrix((void *)((char *)this + 56));
    rotate_matrix_y(0, *(void * *)&this->rotation_y);
    draw_ginja_object(this->m_c0);
    pop_matrix();
}

void TObjLazerFence4::draw_model() {
    u8 *arg0 = (u8 *)this;
  s32 *new_var;
  u16 *new_var2;
  s32 var_r31;
  s32 var_r30;
  var_r30 = 0;
  new_var2 = (u16 *) (((s8 *) arg0) + 0xB8);
  var_r31 = 0;
  do
  {
    ((TObjDoorJung *)(*((s32 *) ((arg0 + var_r31) + 0xC8))))->free_children((void *)(*new_var2));
    var_r30 += 1;
    var_r31 += 4;
  }
  while (var_r30 < 0xC);
  TObjFish::set_global_param((s32)((void *)((*(s32 *)&lazer_fence_norm_texture_list))));
  push_matrix();
  post_translate_matrix((u8 *)&this->position);
  rotate_matrix_y(0, (void *)this->rotation_y);
  draw_ginja_object((void *)(*((s32 *) (((s8 *) arg0) + 0xC0))));
  TParticleCtrl::begin_effect_render();
  new_var = (s32 *) (((s8 *) arg0) + 0xC4);
  draw_ginja_model_with_motion(*((s32 *) (((s8 *) arg0) + 0xBC)), *new_var, *((f32 *) (((s8 *) arg0) + 0xB0)));
  TParticleCtrl::end_effect_render();
  pop_matrix();
}

void TObjLazerFence4::reset_if_door_closed() {
    if (is_current_floor_switch_set(this->m_ba) == 0) {
        set_indexed_flags(0, 1);
        this->m_ac = 0;
    }
}

void TObjLazerFence4::sub_801933C8() {
    ((Obj_801933C8 *)this)->fB0 += 0.9f;
    if (((Obj_801933C8 *)this)->fB0 > (f32)(u32)(((Obj_801933C8 *)this)->fC4->f4 - 1)) {
        ((Obj_801933C8 *)this)->fB0 = 0.0f;
    }
    if (is_current_floor_switch_set(((Obj_801933C8 *)this)->fBA) == 1) {
        ((TObjCollidable *)((Obj_801933C8 *)this))->clear_player_status_flag(0, 1);
        ((Obj_801933C8 *)this)->fAC = 1;
    }
}

void TObjLazerFence4::render() {

    if (((LazerFence4VObj_801930E8*)this)->m8(3e+02f, 6e+01f) != 0) {
        switch (this->m_ac) {
        case 0:
            draw_model();
            return;
        case 1:
            draw();
            break;
        }
    }
}

}

extern "C" {

s32 reset_if_door_closed__15TObjLazerFence4Fv();
s32 sub_801933C8__15TObjLazerFence4Fv();

void TObjLazerFence4::run_task() {

    switch (this->m_ac) {
    case 0:
        sub_801933C8__15TObjLazerFence4Fv();
        return;
    case 1:
        reset_if_door_closed__15TObjLazerFence4Fv();
        return;
    }
}

}

#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define PADV virtual void CAT(pv, __LINE__)();
struct Base_801935D8 { char pad[0x18]; };

struct V_801935D8 : Base_801935D8 {
    PADV
    PADV
    PADV
    PADV
    PADV
    virtual void init(void *);
};

struct Fence_801935D8 {
    s32 id;
    u8 pad4[0x18 - 0x4];
    void *vt;
    u8 pad1C[0x30 - 0x1C];
    u32 flags;
    u8 pad34[0x68 - 0x34];
    f32 f68;
    u8 pad6C[0x84 - 0x6C];
    s32 f84;
    u8 pad88[0x8C - 0x88];
    s32 f8C;
    u8 pad90[0xAC - 0x90];
    s32 fAC;
    f32 fB0;
    u8 padB4[0xB8 - 0xB4];
    u16 fB8;
    s16 fBA;
};

extern "C" {

s32 init_collision_body_parts(void *, void *, int);

void __ct__14TObjCollidableFP7TObject(void *);
extern u16 lbl_80445BE0[];
extern u8 laser_fence4_collision_body_sets[];
extern s32 __vt__15TObjLazerFence4[];
extern s32 lazer_fence4_class_name;

void free_collision_body_parts(void *);

void *TObjLazerFence4::create() {
    void *o = TObject::operator new(0xF8);
    if (o != NULL) {
        o = TObjLazerFence4__ct(o, tl_05, this);
    }
    return o;
}

void *__dt__15TObjLazerFence4Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TObjLazerFence4;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

#define self ((Fence_801935D8 *)arg0)
void *TObjLazerFence4__ct(void *arg0, void *arg1, void *arg2) {
    s32 i;
    ((void (*)(void *, void *, void *))__ct__14TObjCollidableFP7TObject)(self, arg1, arg2);
    self->vt = (void *)__vt__15TObjLazerFence4;
    self->id = lazer_fence4_class_name;
    ((V_801935D8 *)self)->init(arg2);
    self->fAC = 0;
    self->fB0 = 0.0f;
    self->fBA = self->f84;
    i = self->f68;
    if (i < 0) {
        i = 0;
    }
    if (i > 3) {
        i = 3;
    }
    self->fB8 = lbl_80445BE0[i];
    ((TObjLazerFence4 *)self)->init_models();
    init_collision_body_parts(self, laser_fence4_collision_body_sets + (self->f8C % 2) * 0xDC, 5);
    self->flags |= 0x40000000;
    ((TObjPlayer *)self)->register_object_by_id();
    ((TObjCollidable *)self)->refresh_collision_body_centers();
    return self;
}
#undef self
}
