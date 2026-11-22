#include "pso/render/GinjaMaterial.h"
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/city/CityVerticalModel.h"
#include "pso/object/city/CityTraffic.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TUnk_804B5C08.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/task/TMainTask.h"

struct VBase_18_26a62c
{
  char pad[0x18];
};

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredFields_80182E90_arg0
{
  u8 unknown_0[0x60];
  s32 field_60;
  u8 unknown_64[0x2C];
  s32 field_90;
  u8 unknown_94[0x8];
  f32 field_9C;
};

extern "C" {
void vfunc_13__13TUnk_804B5C08Fl(void* a0);
s32 post_translate_matrix(void *);
void render__13TUnk_804B5C08Fv(u8 *arg0);
void run_task__13TUnk_804B5C08Fv(u8 *arg0);
extern s32 city_vertical_model_vtable[];
s32 __ct__8TObjBaseFP7TObject(void *, void *);
void TUnk_804B5C08::vfunc_13(s32) { this->m_9c = 0.0f; *(int*)((char*)this + 0x90) = 1; }
typedef struct RecoveredFields_80182E90_arg0 RecoveredFields_80182E90_arg0;
typedef struct VBase_18_26a62c VBase_18_26a62c;
typedef struct VObj_18_26a62c VObj_18_26a62c;
#pragma fp_contract on
void TUnk_804B5C08::render() {
    u8 *arg0 = (u8 *)this;
  u8 *new_var2;
  unsigned char new_var;
  new_var = ((s32) ((RecoveredFields_80182E90_arg0 *) arg0)->field_90) != 0;
  if (new_var)
  {
    if ((this->update_object_view_visibility((600.0f), (50.0f))) == 0)
    {
      ((RecoveredFields_80182E90_arg0 *) arg0)->field_9C = ((RecoveredFields_80182E90_arg0 *) arg0)->field_9C;
      return;
    }
    TObjFish::set_global_param((saddr)city_common_texture_list);
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    translate_matrix(0, 0.0f, (f32) ((RecoveredFields_80182E90_arg0 *) arg0)->field_9C, 0.0f);
    new_var2 = arg0;
    rotate_matrix_y(0, (int) ((RecoveredFields_80182E90_arg0 *) new_var2)->field_60);
    draw_ginja_object(get_city_common_model(8));
    pop_matrix();
  }
}
#pragma fp_contract on
void TUnk_804B5C08::run_task() {
    u8 *arg0 = (u8 *)this;
  switch (*((s32 *) (((s8 *) arg0) + 0x90)))
  {
    case 0:
      *((s32 *) (((s8 *) arg0) + 0x98)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x98))) - 1);
      if (((s32) (*((s32 *) (((s8 *) arg0) + 0x98)))) <= 0)
    {
      *((s32 *) (((s8 *) arg0) + 0x98)) = 0x12C;
      if ((this->m_94) == 2)
      {
        *((s32 *) (((s8 *) arg0) + 0x90)) = 1;
        this->m_9c = -200.0f;
        return;
        return;
      }
      *((s32 *) (((s8 *) arg0) + 0x90)) = 2;
      this->m_9c = 200.0f;
    }
      return;
    case 1:
      this->m_9c += 2.0f;
      if ((this->m_9c) >= 200.0f)
    {
      this->m_94 = 1;
      *((s32 *) (((s8 *) arg0) + 0x90)) = 0;
      return;
    }
      break;
    case 2:
      this->m_9c -= 2.0f;
      if ((this->m_9c) <= -200.0f)
    {
      this->m_94 = 2;
      *((s32 *) (((s8 *) arg0) + 0x90)) = 0 * 0;
      return;
    }
      break;
  }
}
void *create_city_vertical_model(void *arg0) {
    void *o = TObject::operator new(0xA0);
    if (o != NULL) {
        o = construct_city_vertical_model((u8 *)o, (saddr)tl_05, (saddr)arg0);
    }
    return o;
}
}
void *destroy_city_vertical_model(void *base, s16 arg1) {
    if (base != NULL) {
        *(s32 **)((s8 *)base + 0x18) = city_vertical_model_vtable;
        __dt__8TObjBaseFv(base, 0);
        if (arg1 > 0) {
            TObject::operator delete(base);
        }
    }
    return base;
}
u8 *construct_city_vertical_model(u8 *arg0, saddr parent, saddr set_data) {
    __ct__8TObjBaseFP7TObject((void *)arg0, (void *)parent);
    *(s32 **)((s8 *)arg0 + 0x18) = city_vertical_model_vtable;
    ((TUnk_804B5C08 *)(arg0))->apply_object_set_data((void *)set_data);
    *(s32 *)((s8 *)arg0 + 0x90) = 1;
    ((TUnk_804B5C08 *)arg0)->m_94 = 2;
    *(s32 *)((s8 *)arg0 + 0x98) = 0;
    ((TUnk_804B5C08 *)arg0)->m_9c = 0.0f;
    return arg0;
}
extern "C" {

void render_shadows__7TObjectFv();
void vfunc_6__8TObjBaseFPsl();
void apply_object_set_data__8TObjBaseFPv();
void reset_motion_fields__8TObjBaseFv();
void get_center__8TObjBaseFv();
void update_object_view_visibility__8TObjBaseFff();
void classify_actor_view_detail__8TObjBaseFfff();
void get_name__8TObjBaseFv();
}
s32 city_vertical_model_vtable[14] = {
    0,
    0,
    (saddr)destroy_city_vertical_model,
    (saddr)run_task__13TUnk_804B5C08Fv,
    (saddr)render__13TUnk_804B5C08Fv,
    (saddr)render_shadows__7TObjectFv,
    (saddr)vfunc_6__8TObjBaseFPsl,
    (saddr)apply_object_set_data__8TObjBaseFPv,
    (saddr)reset_motion_fields__8TObjBaseFv,
    (saddr)get_center__8TObjBaseFv,
    (saddr)update_object_view_visibility__8TObjBaseFff,
    (saddr)classify_actor_view_detail__8TObjBaseFfff,
    (saddr)get_name__8TObjBaseFv,
    (saddr)vfunc_13__13TUnk_804B5C08Fl,
};
