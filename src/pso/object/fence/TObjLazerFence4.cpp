#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/object/fence/TObjLazerFenceNorm.h"
#include "types.h"
#include "pso/object/fence/TObjLazerFence4.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/door/TObjDoorJung.h"

#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_80193524.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/camera/CameraDistanceFade.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/fence/TLazerFenceSw.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/object/cave/TOAirconCave01.h"
#include "pso/object/key/TOKey.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/NinjaUtil.h"


#pragma readonly_strings on

const u16 lbl_80445BE0[] = {0, 1, 2, 3};

CollisionBody laser_fence4_collision_body_sets[2][5] = {
    {
        {{0.0f, 0.0f, 0.0f}, 24.0f, 24.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{20.0f, 0.0f, 20.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{20.0f, 0.0f, -20.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{-20.0f, 0.0f, 20.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{-20.0f, 0.0f, -20.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
    },
    {
        {{0.0f, 0.0f, 0.0f}, 33.0f, 33.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{30.0f, 0.0f, 30.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{30.0f, 0.0f, -30.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{-30.0f, 0.0f, 30.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{-30.0f, 0.0f, -30.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
    },
};

const char *lazer_fence4_class_name = "TObjLazerFence4";


struct Cnt_801933C8 { s32 pad0; s32 f4; };

struct Obj_801933C8 { u8 padA0[0xAC]; s32 fAC; f32 fB0; u8 padB4[6]; u16 id; u8 padBC[8]; Cnt_801933C8 *fC4; };

struct Node_80193188 { u32 flags; void *model; u8 pad8[0x24]; Node_80193188 *child; Node_80193188 *sibling; };

struct Fence_80193188 { u8 pad0[0x8C]; s32 f8C; u8 pad90[0x2C]; Node_80193188 *fBC; Node_80193188 *fC0; saddr bml_motion; void *fC8[12]; };

extern "C" {
void post_translate_matrix(void *);

s32 TObjLazerFence4::update_object_view_visibility(f32 farg0, f32 farg1) {
    u8 *arg0 = (u8 *)this;
    if (TMainTask::get_render_pass() == 1) {
        return this->visibility;
    }
    if (xz_distance_squared(&this->position, &camera_ctrl_instance->pos) < (farg1 * farg1)) {
        this->visibility = 1;
        return this->visibility;
    }
    return ((TObjBase *)arg0)->TObjBase::update_object_view_visibility(farg0, farg1);
}

void TObjLazerFence4::init_models() {
    Fence_80193188 *arg0 = (Fence_80193188 *)this;
    Node_80193188 *node;
    s32 i;
    s32 j;
    if (arg0->f8C % 2 == 0) {
        arg0->fBC = (Node_80193188 *)get_bml_model((BmlResource *)lazer_fence_norm_bml_resource, 4);
        arg0->fC0 = (Node_80193188 *)get_bml_model((BmlResource *)lazer_fence_norm_bml_resource, 5);
        arg0->bml_motion = (saddr)get_bml_motion(lazer_fence_norm_bml_resource, 2);
    } else {
        arg0->fBC = (Node_80193188 *)get_bml_model((BmlResource *)lazer_fence_norm_bml_resource, 6);
        arg0->fC0 = (Node_80193188 *)get_bml_model((BmlResource *)lazer_fence_norm_bml_resource, 7);
        arg0->bml_motion = (saddr)get_bml_motion(lazer_fence_norm_bml_resource, 3);
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
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lazer_fence_norm_texture_list));
    push_matrix();
    post_translate_matrix((void *)((char *)this + 56));
    rotate_matrix_y(0, this->rotation_y);
    draw_ginja_object(this->m_c0);
    pop_matrix();
}

void TObjLazerFence4::draw_model() {
    u8 *arg0 = (u8 *)this;
  void **new_var;
  u16 *new_var2;
  s32 var_r31;
  s32 i;
  i = 0;
  new_var2 = (u16 *) (((s8 *) arg0) + 0xB8);
  var_r31 = 0;
  do
  {
    set_ginja_model_texture_slot(reinterpret_cast<void *>((*((s32 *) ((arg0 + var_r31) + 0xC8)))), (*new_var2));
    i += 1;
    var_r31 += 4;
  }
  while (i < 0xC);
  TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lazer_fence_norm_texture_list));
  push_matrix();
  post_translate_matrix((u8 *)&this->position);
  rotate_matrix_y(0, this->rotation_y);
  draw_ginja_object(this->m_c0);
  TParticleCtrl::begin_effect_render();
  new_var = (void **) (((s8 *) arg0) + 0xC4);
  draw_ginja_model_with_motion(this->m_bc, *new_var, *((f32 *) (((s8 *) arg0) + 0xB0)));
  TParticleCtrl::end_effect_render();
  pop_matrix();
}

void TObjLazerFence4::reset_if_door_closed() {
    if (is_current_floor_switch_set(this->id) == 0) {
        set_indexed_flags(0, 1);
        this->m_ac = 0;
    }
}

void TObjLazerFence4::sub_801933C8() {
    ((Obj_801933C8 *)this)->fB0 += 0.9f;
    if (((Obj_801933C8 *)this)->fB0 > (f32)(u32)(((Obj_801933C8 *)this)->fC4->f4 - 1)) {
        ((Obj_801933C8 *)this)->fB0 = 0.0f;
    }
    if (is_current_floor_switch_set(((Obj_801933C8 *)this)->id) == 1) {
        ((TObjCollidable *)((Obj_801933C8 *)this))->clear_player_status_flag(0, 1);
        ((Obj_801933C8 *)this)->fAC = 1;
    }
}

void TObjLazerFence4::render() {

    if (this->update_object_view_visibility(3e+02f, 6e+01f) != 0) {
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


void TObjLazerFence4::run_task() {

    switch (this->m_ac) {
    case 0:
        sub_801933C8();
        return;
    case 1:
        reset_if_door_closed();
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
    const char *id;
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


void free_collision_body_parts(void *);

void *TObjLazerFence4::create(void *set_data) {
    return new TObjLazerFence4((TObject *)tl_05, set_data);
}

}
TObjLazerFence4::~TObjLazerFence4() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}


#define self ((Fence_801935D8 *)this)
TObjLazerFence4::TObjLazerFence4(TObject *parent, void *arg2) : TObjCollidable(parent) {
    s32 i;
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
    init_collision_body_parts(self, laser_fence4_collision_body_sets[self->f8C % 2], 5);
    self->flags |= 0x40000000;
    ((TObjPlayer *)self)->register_object_by_id();
    ((TObjCollidable *)self)->refresh_collision_body_centers();
}
#undef self
