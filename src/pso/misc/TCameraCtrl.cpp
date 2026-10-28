#include "types.h"
#include "pso/TObject.h"
#include "pso/misc/TUnk_80488A28.h"
#include "pso/system/vector.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/camera/CreationCamera.h"

struct RecoveredGlobal_8006ABAC_lbl_804FF610 {
    s32 value;
    u8 remaining[0x8];
};
struct RecoveredGlobal_8006ABAC_lbl_804FF61C {
    s32 value;
    u8 remaining[0x8];
};

struct Vec_8006AF9C { f32 x, y, z; };

struct Obj_8006AF9C {
    u8 pad0[0x19c];
    s32 f19c;
};

void set_camera_look_at(u8 *eye, u8 *target, u8 *up);
extern "C" {
s32 set_perspective_projection_from_fov(int, f32, f32, f32);
f32 vec_squared_length(void *);
}
extern f32 lbl_804FF5E8[10];
extern u32 TCameraCtrl__up_vector[3];
extern const f32 TCameraCtrl__data_805D8FA8;
extern const f32 TCameraCtrl__data_805D8FAC;
extern const f32 TCameraCtrl__data_805D8FDC;
extern const f32 TCameraCtrl__data_805D8FE0;
struct C30_8006AD34 { u8 b[0x30]; };
f32 lbl_804FF5E8[10];
f32 camera_right[3];
RecoveredGlobal_8006ABAC_lbl_804FF61C camera_pitch_rotated_up_vector;
u8 TCameraCtrl__view_state[12];
u32 TCameraCtrl__data_804FF634[18];
u32 lbl_804FF67C[18];
u32 TCameraCtrl__up_vector[3];
u8 TCameraCtrl__view_matrix[0x30];
C30_8006AD34 TCameraCtrl__view_matrices[4];
extern void *camera_controller_registry[13];
extern void *lbl_80488AC0[6];

struct A_8006A35C { s8 f0; u8 pad1; s16 f2; s32 f4; s32 f8; };
struct B_8006A35C { u8 pad[8]; f32 f8; f32 fc; u8 pad10[8]; f32 f18; u8 pad1c[0xC]; f32 f28; f32 f2c; f32 f30; f32 f34; f32 f38; f32 f3c; f32 f40; f32 f44; };
struct C_8006A35C { f32 f0; f32 f4; f32 f8; };
#define camera_controller_registry (*(RecoveredGlobal_8006A788_camera_controller_registry *)camera_controller_registry)
extern "C" {
void TCameraCtrl__sub_80068358(void *, void *, f32, f32);
extern s32 camera_view_state_flag;
extern s8 camera_ctrl_view_state_byte;
extern s32 TCameraCtrl__pose_snap_flags;
extern const f32 TCameraCtrl__data_805D8FD8;
}
struct RecoveredGlobal_8006A5DC_TCameraCtrl__data_804FF628 {
    u8 value;
    u8 remaining[0xB];
};

struct VBase_18_f8ef8c
{
  char pad[0x18];
};

struct VObj_18_f8ef8c : VBase_18_f8ef8c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5();
};

struct RecoveredGlobal_8006A788_camera_controller_registry
{
  s32 value;
  u8 remaining[0x64];
};

struct RecoveredGlobal_8006A788_TCameraCtrl__data_804FF628
{
  s8 value;
  u8 remaining[0xB];
};

struct VBase_18_9639c7
{
  char pad[0x18];
};

struct VObj_18_9639c7 : VBase_18_9639c7 {
    virtual void m0();
    virtual s32 m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual s32 m9();
};

struct RecoveredGlobal_8006A7D8_camera_controller_registry
{
  s32 value;
  u8 remaining[0x64];
};

struct RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628
{
  s32 value;
  u8 remaining[0x8];
};

struct RecoveredGlobal_8006A5EC_camera_controller_registry
{
  s32 value;
  u8 remaining[0x64];
};

struct RecoveredGlobal_8006A5EC_TCameraCtrl__data_804FF628
{
  s8 value;
  u8 remaining[0xB];
};

struct Vec_8006A410
{
  f32 x;
  f32 y;
  f32 z;
};

struct VBase_8006A410
{
  char pad[0x18];
};

struct Ctrl_8006A410 : VBase_8006A410 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6(void *);
    u8 pad1C[0x3C - 0x1C];
    Vec_8006A410 pos;
    Vec_8006A410 tgt;
};

struct Master_8006A410
{
  u8 pad[0xD4];
  Vec_8006A410 pos[4];
  Vec_8006A410 tgt[4];
};

struct Views_8006A410
{
  u8 pad[0x10];
  s32 players[4];
};

extern "C" {
u8 TCameraCtrl__sub_8006A5DC(void);
s32 is_split_screen();
s32 apply_camera_controller_pose(int);
s32 resolve_anchor_obstruction__11TCameraCtrlFv(void *, int);
s32 clamp_to_target_obstruction__11TCameraCtrlFv(void *, int);
extern u8 *camera_ctrl_instance;
s32 obj_getField1c(void *);
s32 *get_character_select_request_buffer(void);
s32 is_boss_area(void);
void reset__11TCameraCtrlFv(void);
void TCameraCtrl__sub_80068354(void);

extern s16 TCameraCtrl__data_805D4E0A;

void reset__11TCameraCtrlFv(void) {
    TCameraCtrl__data_805D4E0A = 0;
    TCameraCtrl__sub_80068354();
    *(s8 *)((s8 *)TCameraCtrl__view_state + 0) = 0;
    *(s16 *)((s8 *)TCameraCtrl__view_state + 2) = 0;
    *(s32 *)((s8 *)TCameraCtrl__view_state + 4) = 0;
    *(s32 *)((s8 *)TCameraCtrl__view_state + 8) = 0;
}
void TCameraCtrl::reset_view_state() {
    A_8006A35C *pa = (A_8006A35C *)TCameraCtrl__view_state;
    B_8006A35C *pb = (B_8006A35C *)TCameraCtrl__data_804FF634;
    C_8006A35C *pc;

    TCameraCtrl__pose_snap_flags = 0;
    ((A_8006A35C *)TCameraCtrl__view_state)->f0 = 0;
    pa->f2 = 0;
    pa->f4 = 0;
    pa->f8 = 0;
    pb->f18 = TCameraCtrl__data_805D8FA8;
    pb->f28 = TCameraCtrl__data_805D8FA8;
    pb->f2c = TCameraCtrl__data_805D8FA8;
    pb->f8 = TCameraCtrl__data_805D8FA8;
    pb->fc = TCameraCtrl__data_805D8FA8;
    pb->f30 = TCameraCtrl__data_805D8FA8;
    pb->f34 = TCameraCtrl__data_805D8FA8;
    pb->f38 = TCameraCtrl__data_805D8FA8;
    pb->f3c = TCameraCtrl__data_805D8FA8;
    pb->f40 = TCameraCtrl__data_805D8FAC;
    pb->f44 = TCameraCtrl__data_805D8FD8;
    TCameraCtrl__sub_80068358(pb, pa, TCameraCtrl__data_805D8FAC, TCameraCtrl__data_805D8FA8);
    ((C_8006A35C *)TCameraCtrl__up_vector)->f0 = TCameraCtrl__data_805D8FA8;
    pc = (C_8006A35C *)TCameraCtrl__up_vector;
    pc->f4 = TCameraCtrl__data_805D8FAC;
    pc->f8 = TCameraCtrl__data_805D8FA8;
    camera_view_state_flag = 0;
    camera_ctrl_view_state_byte = -1;
    TCameraCtrl__data_805D4E0A = 0;
}
}
void select_camera_controller(s32 arg0);
void reset_cameras_to_actor(void *actor, s32 arg1);
typedef char RecoveredGlobal_8006A5DC_TCameraCtrl__data_804FF628_size[sizeof(RecoveredGlobal_8006A5DC_TCameraCtrl__data_804FF628) == 0xC ? 1 : -1];

typedef struct Ctrl_8006A410 Ctrl_8006A410;
typedef struct Master_8006A410 Master_8006A410;
typedef struct VBase_8006A410 VBase_8006A410;
typedef struct Vec_8006A410 Vec_8006A410;
typedef struct Views_8006A410 Views_8006A410;
void reset_cameras_to_actor(void *actor, s32 arg1) {
  s32 view = 0;
  u16 new_var;
  s32 count = 0;
  Ctrl_8006A410 *c;
  s32 id;
  s32 i;
  if (actor == 0)
  {
    return;
  }
  new_var = (u16) obj_getField1c(actor);
  id = new_var;
  if (is_split_screen() == 0)
  {
    view = 0;
  }
  else
  {
    Views_8006A410 *v = (Views_8006A410 *) get_character_select_request_buffer();
    for (i = 0; i < 4; i++)
    {
      s32 p = v->players[i];
      if (p == id)
      {
        view = count;
      }
      if (p >= 0)
      {
        count++;
      }
    }
  }
  c = ((Ctrl_8006A410 **) (&camera_controller_registry))[((u8) TCameraCtrl__view_state[0]) + view];
  if (c != 0)
  {
    if (is_split_screen() == 0)
    {
      *((void **) (((s8 *) camera_ctrl_instance) + 0x90)) = actor;
    }
    ((TUnk_80488A28 *)c)->set_target((u32)actor);
    c->m6(actor);
    if (is_split_screen() != 0)
    {
      *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) |= 0x800;
      if (is_boss_area() == 0)
      {
        *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) |= 0x1000;
        *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) |= 0x2000;
        *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) |= 0x4000;
        *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) |= 0x8000;
        *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) &= (-0x1001) << view;
      }
    }
    else
    {
      *((s32 *) (((s8 *) TCameraCtrl__view_state) + 8)) |= 0x800;
    }
  }
  c = ((Ctrl_8006A410 **) (&camera_controller_registry))[view];
  if (c != 0)
  {
    ((TUnk_80488A28 *)c)->set_target((u32)actor);
    c->m6(actor);
  }
  if (camera_ctrl_instance != 0)
  {
    VecCopy((Vec *)(&((Master_8006A410 *) camera_ctrl_instance)->pos[view]), (const Vec *)&c->pos);
    VecCopy((Vec *)(&((Master_8006A410 *) camera_ctrl_instance)->tgt[view]), (const Vec *)&c->tgt);
  }
}
extern "C" {

u8 TCameraCtrl__sub_8006A5DC(void) {
    return (*(RecoveredGlobal_8006A5DC_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value;
}
typedef struct RecoveredGlobal_8006A788_TCameraCtrl__data_804FF628 RecoveredGlobal_8006A788_TCameraCtrl__data_804FF628;
typedef struct RecoveredGlobal_8006A788_camera_controller_registry RecoveredGlobal_8006A788_camera_controller_registry;
typedef struct VBase_18_f8ef8c VBase_18_f8ef8c;
typedef struct VObj_18_f8ef8c VObj_18_f8ef8c;
typedef char RecoveredGlobal_8006A788_camera_controller_registry_size[((sizeof(RecoveredGlobal_8006A788_camera_controller_registry)) == 0x68) ? (1) : (-1)];
typedef char RecoveredGlobal_8006A788_TCameraCtrl__data_804FF628_size[((sizeof(RecoveredGlobal_8006A788_TCameraCtrl__data_804FF628)) == 0xC) ? (1) : (-1)];
#define PSO_VCALL_VObj_18_f8ef8c_m5(_self) (((VObj_18_f8ef8c *)(_self))->m5())

typedef struct RecoveredGlobal_8006A5EC_TCameraCtrl__data_804FF628 RecoveredGlobal_8006A5EC_TCameraCtrl__data_804FF628;
typedef struct RecoveredGlobal_8006A5EC_camera_controller_registry RecoveredGlobal_8006A5EC_camera_controller_registry;
typedef char RecoveredGlobal_8006A5EC_camera_controller_registry_size[((sizeof(RecoveredGlobal_8006A5EC_camera_controller_registry)) == 0x68) ? (1) : (-1)];
typedef char RecoveredGlobal_8006A5EC_TCameraCtrl__data_804FF628_size[((sizeof(RecoveredGlobal_8006A5EC_TCameraCtrl__data_804FF628)) == 0xC) ? (1) : (-1)];
#define PSO_VCALL_VObj_18_f8ef8c_m5(_self) (((VObj_18_f8ef8c *)(_self))->m5())
void TCameraCtrl::select_active_controller(s8 arg0) {
  f32 temp_f0;
  f32 temp_f0_2;
  f32 temp_f0_3;
  f32 temp_f0_4;
  f32 temp_f0_5;
  f32 temp_f0_6;
  u8 *temp_r31;
  (*(RecoveredGlobal_8006A5EC_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value = arg0;
  temp_r31 = (u8 *) (*((u8 **) (((s8 *) (((u8 *) (&(*(RecoveredGlobal_8006A5EC_camera_controller_registry *)&camera_controller_registry).value)) + ((arg0 * 4) & 0x3FC))) + 0)));
  if (temp_r31 != 0)
  {
    PSO_VCALL_VObj_18_f8ef8c_m5(temp_r31);
    if (((void *) camera_ctrl_instance) != 0)
    {
      temp_f0 = *((f32 *) (((s8 *) temp_r31) + 0x3C));
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x1A0)) = temp_f0;
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x178)) = temp_f0;
      temp_f0_2 = *((f32 *) (((s8 *) temp_r31) + 0x40));
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x1A4)) = temp_f0_2;
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x17C)) = temp_f0_2;
      temp_f0_3 = *((f32 *) (((s8 *) temp_r31) + 0x44));
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x1A8)) = temp_f0_3;
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x180)) = temp_f0_3;
      temp_f0_4 = *((f32 *) (((s8 *) temp_r31) + 0x48));
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x1AC)) = temp_f0_4;
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x184)) = temp_f0_4;
      temp_f0_5 = *((f32 *) (((s8 *) temp_r31) + 0x4C));
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x1B0)) = temp_f0_5;
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x188)) = temp_f0_5;
      temp_f0_6 = *((f32 *) (((s8 *) temp_r31) + 0x50));
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x1B4)) = temp_f0_6;
      *((f32 *) (((s8 *) camera_ctrl_instance) + 0x18C)) = temp_f0_6;
    }
  }
}

struct Cam_8006A6C4
{
  u8 pad0[0x68];
  f32 f68;
  f32 f6C;
  f32 f70;
  u8 pad74[0x1C0 - 0x74];
  u32 f1C0;
  f32 f1C4;
};
f32 sin_table_lookup(s32);
extern const f32 lbl_805D8FF4;
void TCameraCtrl::update_shake() {
  Cam_8006A6C4 *self = (Cam_8006A6C4 *) this;
  f32 amp;
  s32 k;
  if (self->f1C0 != 0) {
    self->f1C0--;
    k = self->f1C0 * 40;
    amp = self->f1C4 * (f32)self->f1C0;
    self->f68 = TCameraCtrl__data_805D8FA8;
    self->f6C = amp * sin_table_lookup((s32)(lbl_805D8FF4 * (f32)k));
    self->f70 = TCameraCtrl__data_805D8FA8;
  }
}
}

void select_camera_controller(s32 arg0) {
  u8 *temp_r0;
  (*(RecoveredGlobal_8006A788_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value = arg0;
  temp_r0 = (u8 *) (*((s32 *) (((s8 *)&camera_controller_registry.value) + ((arg0 * 4) & 0x3FC))));
  if (temp_r0 != 0)
  {
    PSO_VCALL_VObj_18_f8ef8c_m5(temp_r0);
  }
}
typedef struct RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628;
typedef struct RecoveredGlobal_8006A7D8_camera_controller_registry RecoveredGlobal_8006A7D8_camera_controller_registry;
typedef struct VBase_18_9639c7 VBase_18_9639c7;
typedef struct VObj_18_9639c7 VObj_18_9639c7;
typedef char RecoveredGlobal_8006A7D8_camera_controller_registry_size[((sizeof(RecoveredGlobal_8006A7D8_camera_controller_registry)) == 0x68) ? (1) : (-1)];
typedef char RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628_size[((sizeof(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628)) == 0xC) ? (1) : (-1)];
#define PSO_VCALL_VObj_18_9639c7_m1(_self) (((VObj_18_9639c7 *)(_self))->m1())
#define PSO_VCALL_VObj_18_9639c7_m4(_self, _arg0) (((VObj_18_9639c7 *)(_self))->m4((_arg0)))
#define PSO_VCALL_VObj_18_9639c7_m9(_self) (((VObj_18_9639c7 *)(_self))->m9())

void TCameraCtrl::update_active_controller() {
  s32 temp_r3;
  s32 var_r27;
  s32 camera_no;
  s32 *new_var;
  u8 *temp_r30;
  if (((u8) (*((u8 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 0)))) != 0)
  {
    camera_no = 0;
  }
  else
    if (is_split_screen() != 0)
  {
    camera_no = TCameraCtrl::get_camera_no();
  }
  else
  {
    camera_no = 0;
  }
  temp_r30 = (u8 *) (*((void **) (((s8 *) (((u8 *) (&(*(RecoveredGlobal_8006A7D8_camera_controller_registry *)&camera_controller_registry).value)) + (((*((u8 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 0))) + camera_no) * 4))) + 0)));
  if (temp_r30 != 0)
  {
    if (!((*((s32 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8))) & 0x800))
    {
      PSO_VCALL_VObj_18_9639c7_m1(temp_r30);
    }
    if ((*((s32 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8))) & 2)
    {
      PSO_VCALL_VObj_18_9639c7_m4(temp_r30, 0);
    }
    else
      if ((*((s32 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8))) & 0x80)
    {
      PSO_VCALL_VObj_18_9639c7_m4(temp_r30, 1);
    }
    apply_camera_controller_pose((int) temp_r30);
    new_var = (s32 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8);
    var_r27 = 0;
    if (is_split_screen() != 0)
    {
      if ((((*new_var) & 0x20) || ((*new_var) & 0x800)) && (!((*new_var) & (0x1000 << camera_no))))
      {
        var_r27 = 1;
        *new_var = (s32) ((*((s32 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8))) & ((-0x1001) << camera_no));
      }
    }
    else
      if (((*new_var) & 0x20) || ((*((s32 *) (((s8 *) (&(*(RecoveredGlobal_8006A7D8_TCameraCtrl__data_804FF628 *)&TCameraCtrl__view_state).value)) + 8))) & 0x800))
    {
      var_r27 = 1;
    }
    if (var_r27 != 0)
    {
      update_position();
    }
    else
    {
      if ((*((s32 *) (((s8 *) temp_r30) + 0x38))) & 1)
      {
        resolve_anchor_obstruction__11TCameraCtrlFv((void *) this, (int) temp_r30);
      }
      temp_r3 = *((s32 *) (((s8 *) temp_r30) + 0x38));
      if (temp_r3 & 4)
      {
        update_pose_smoothing();
      }
      else
        if (temp_r3 & 8)
      {
        update_target_smoothing();
      }
      else
      {
        update_position();
      }
      if ((*((s32 *) (((s8 *) temp_r30) + 0x38))) & 1)
      {
        clamp_to_target_obstruction__11TCameraCtrlFv((void *) this, (int) temp_r30);
      }
      update_shake();
    }
    set_perspective_projection_from_fov(this->m_19c, (f32) TCameraCtrl__data_805D8FDC, (f32) TCameraCtrl__data_805D8FAC, (f32) TCameraCtrl__data_805D8FE0);
    PSO_VCALL_VObj_18_9639c7_m9(temp_r30);
    if (is_split_screen() == 0)
    {
      *((s32 *) (((s8 *) ((u8 *)this)) + 0x94)) = this->m_194;
    }
  }
}

#undef camera_controller_registry

#define camera_controller_registry ((Ctl_8006AA90 **)camera_controller_registry)
#define lbl_80488AC0 ((u8 *)lbl_80488AC0)

struct Ctl_8006AA90 {
    u8 pad[0x18];
    virtual ~Ctl_8006AA90();
};

extern "C" {
void __dt__7TObjectFv(void *, s32);
void __dl__7TObjectFPv(void *);
Ctl_8006AA90 *TCameraCtrl__sub_8006AA90(Ctl_8006AA90 *self, s16 arg1);
void *get_player_by_client_id(s32 i);

extern s32 local_client_id;

void TCameraCtrl::update_target_from_state() {
    if ((!(*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 4) && !(*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 8)) || (*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 0x20) || (*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 0x80) || (*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 0x800)) {
        if (*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 2) {
            select_camera_controller(this->m_20 + 9);
            return;
        }
        if ((*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 0x20) || (*(s32 *)((s8 *)TCameraCtrl__view_state + 8) & 0x80)) {
            select_camera_controller(*(u8 *)((s8 *)TCameraCtrl__view_state + 1));
            u32 temp = (u32)get_player_by_client_id(local_client_id);
            if (temp != 0U) {
                reset_cameras_to_actor((void *)temp, 0);
            }
        }
    }
}
Ctl_8006AA90 *TCameraCtrl__sub_8006AA90(Ctl_8006AA90 *self, s16 arg1) {
    s32 i;
    if (self != NULL) {
        *(u8 **)((u8 *)self + 0x18) = lbl_80488AC0;
        (*(s32 *)&camera_ctrl_instance) = 0;
        for (i = 0; i < 13; i++) {
            if (camera_controller_registry[i] != NULL) {
                delete camera_controller_registry[i];
                camera_controller_registry[i] = NULL;
            }
        }
        ((s32 *)&TCameraCtrl__view_state)[1] = 0;
        __dt__7TObjectFv(self, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

}

#undef camera_controller_registry
#undef lbl_80488AC0

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_30 { u8 bytes[0x30]; };

struct RecoveredGlobal_8006B324_lbl_805137F8 {
    s32 value;
    u8 remaining[0x20];
};

#include <stddef.h>
#include "pso/TMainTask.h"
#include "pso/boss/TObjBoss2Tunnel.h"
struct Stack_8006ABAC {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
};

struct RecoveredGlobal_8006ABAC_lbl_804381A4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006ABAC_lbl_804381B0 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006ABAC_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct Stack_8006AC70 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
};

struct RecoveredGlobal_8006AC70_lbl_8043818C {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006AC70_lbl_80438198 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006AC70_lbl_804FF610 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006AC70_lbl_804FF61C {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006AC70_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct Vec_8006B0D4 { f32 x, y, z; };
struct Count_8006B0D4 {
    s8 flag;
    s32 count;
    u8 pad8[0x8];
};
struct Cam_8006B0D4 {
    s32 name;
    u8 pad4[0x14];
    void *vt;
    s8 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    f32 f2C;
    f32 f30;
    s32 f34;
    f32 f38[10];
    u8 pad60[0x4];
    s16 f64;
    Vec_8006B0D4 f68;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad84[0x8];
    s32 f8C;
    s32 f90;
    s32 f94[4];
    Vec_8006B0D4 fA4[4];
    Vec_8006B0D4 fD4[4];
    Vec_8006B0D4 f104[4];
    Vec_8006B0D4 f134[4];
    s32 f164[4];
    s32 f174;
    Vec_8006B0D4 f178;
    Vec_8006B0D4 f184;
    s32 f190;
    s32 f194;
    s32 f198;
    s32 f19C;
    Vec_8006B0D4 f1A0;
    Vec_8006B0D4 f1AC;
    f32 f1B8;
    f32 f1BC;
    s32 f1C0;
    u8 pad1C4[0x4];
    Vec_8006B0D4 f1C8;
};

extern "C" {
u8 * copy_view_params__11TCameraCtrlFii(C30_8006AD34 *arg0, const C30_8006AD34 *arg1);
extern RecoveredGlobal_8006B324_lbl_805137F8 chr_select_request_buffer;
s32 rotate_matrix_y(int, void *);
s32 rotate_matrix_x(int, void *);
s32 push_matrix_from(void *);
f32 rotate_vector_by_current_matrix(void *, void *);
s32 pop_matrix();
extern RecoveredGlobal_8006ABAC_lbl_804381A4 lbl_804381A4;
extern RecoveredGlobal_8006ABAC_lbl_804381B0 lbl_804381B0;
extern RecoveredGlobal_8006ABAC_lbl_804FF61C camera_pitch_rotated_up_vector;
extern RecoveredGlobal_8006ABAC_lbl_8058D490 identity_matrix;
extern RecoveredGlobal_8006AC70_lbl_8043818C lbl_8043818C;
extern RecoveredGlobal_8006AC70_lbl_80438198 lbl_80438198;
struct V3_8006AD34 { f32 x, y, z; };
u8 *get_target__11TCameraCtrlFv(void *);
s32 reset_view_flags__11TCameraCtrlFv(void *);
s32 cycle_spectate_target__11TCameraCtrlFv(void *);
void vector_length(void *);
void normalize_vector(void *);
int TCameraCtrl__sub_8006B370(f32);
u16 TCameraCtrl__sub_8006B358(void* p);
int is_quest_active(void);
int TCameraCtrl__sub_8006B3B8(void* p);
s32 get_mode__11TCameraCtrlFPv(void* p);
void render__11TCameraCtrlFv(void *arg0);
int reset_to_local_player__11TCameraCtrlFv(void*);
int set_fixed_position_and_target__11TCameraCtrlFPUcPUc(void*);

extern "C" {
void *TCameraCtrl__vt0(void);
}
extern "C" {
void *TCameraCtrl__vt10(void);
}
extern "C" {
void *TCameraCtrl__vt11(void);
}
extern "C" {
void *TCameraCtrl__vt12(void);
}
extern "C" {
void *TCameraCtrl__vt4(void);
}
extern "C" {
void *TCameraCtrl__vt5(void);
}
extern "C" {
void *TCameraCtrl__vt6(void);
}
extern "C" {
void *TCameraCtrl__vt7(void);
}
extern "C" {
void *TCameraCtrl__vt9(void);
}
extern "C" {
void render_shadows__7TObjectFv();
}
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 lbl_805D283C;
extern const f32 lbl_805D8FE4;
void run_task__11TCameraCtrlFv(u8 *arg0);
void *camera_controller_registry[13] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *lbl_80488A8C[13] = {
    (void *)&TCameraCtrl__vt0, (void *)&TCameraCtrl__vt0, (void *)&TCameraCtrl__vt0, (void *)&TCameraCtrl__vt0,
    (void *)&TCameraCtrl__vt4, (void *)&TCameraCtrl__vt5, (void *)&TCameraCtrl__vt6, (void *)&TCameraCtrl__vt7,
    (void *)&CreationCamera::create, (void *)&TCameraCtrl__vt9, (void *)&TCameraCtrl__vt10, (void *)&TCameraCtrl__vt11,
    (void *)&TCameraCtrl__vt12,
};
void *lbl_80488AC0[6] = {
    (void *)0x0, (void *)0x0, (void *)&TCameraCtrl__sub_8006AA90, (void *)&run_task__11TCameraCtrlFv,
    (void *)&render__11TCameraCtrlFv, (void *)&render_shadows__7TObjectFv,
};

void TCameraCtrl::render() {
    if ((is_split_screen() == 0) && (TMainTask::get_render_pass() != 1)) {
        if ((u8) *(u8 *)((s8 *)this + 0x1C) == 0) {
            setup_default_view((Vec_8006AF9C *)(0));
        }
        *(u8 *)((s8 *)this + 0x1C) = 0U;
    }
}

    extern int camera_split_screen_selector;

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
typedef char RecoveredGlobal_8006ABAC_lbl_804381A4_size[sizeof(RecoveredGlobal_8006ABAC_lbl_804381A4) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006ABAC_lbl_804381B0_size[sizeof(RecoveredGlobal_8006ABAC_lbl_804381B0) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006ABAC_lbl_804FF610_size[sizeof(RecoveredGlobal_8006ABAC_lbl_804FF610) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006ABAC_lbl_804FF61C_size[sizeof(RecoveredGlobal_8006ABAC_lbl_804FF61C) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006ABAC_lbl_8058D490_size[sizeof(RecoveredGlobal_8006ABAC_lbl_8058D490) == 0x30 ? 1 : -1];
void TCameraCtrl::calc_axes_from_angles(s32 arg0, s32 arg1, s32 arg2) {
    typedef char sp8_offset[(offsetof(Stack_8006ABAC, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8006ABAC, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8006ABAC, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8006ABAC, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_8006ABAC, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_8006ABAC, sp1C) == 0x14) ? 1 : -1];
    Stack_8006ABAC stack;
    stack.sp14 = *(s32 *)((s8 *)&lbl_804381A4.value + 0);
    stack.sp18 = *(s32 *)((s8 *)&lbl_804381A4.value + 4);
    stack.sp1C = *(s32 *)((s8 *)&lbl_804381A4.value + 8);
    stack.sp8 = *(s32 *)((s8 *)&lbl_804381B0.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_804381B0.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_804381B0.value + 8);
    push_matrix_from((void *)&identity_matrix.value);
    rotate_matrix_y(0, (void *)arg2);
    rotate_vector_by_current_matrix((void *)&stack.sp14, (void *)camera_right);
    pop_matrix();
    push_matrix_from((void *)&identity_matrix.value);
    rotate_matrix_x(0, (void *)arg1);
    rotate_vector_by_current_matrix((void *)&stack.sp8, (void *)&camera_pitch_rotated_up_vector.value);
    pop_matrix();
}
#pragma pop

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_8006AC70_lbl_8043818C_size[sizeof(RecoveredGlobal_8006AC70_lbl_8043818C) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006AC70_lbl_80438198_size[sizeof(RecoveredGlobal_8006AC70_lbl_80438198) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006AC70_lbl_804FF610_size[sizeof(RecoveredGlobal_8006AC70_lbl_804FF610) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006AC70_lbl_804FF61C_size[sizeof(RecoveredGlobal_8006AC70_lbl_804FF61C) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006AC70_lbl_8058D490_size[sizeof(RecoveredGlobal_8006AC70_lbl_8058D490) == 0x30 ? 1 : -1];
void TCameraCtrl::calc_rotated_axes() {
    typedef char sp8_offset[(offsetof(Stack_8006AC70, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8006AC70, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8006AC70, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8006AC70, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_8006AC70, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_8006AC70, sp1C) == 0x14) ? 1 : -1];
    Stack_8006AC70 stack;
    stack.sp14 = *(s32 *)((s8 *)&lbl_8043818C.value + 0);
    stack.sp18 = *(s32 *)((s8 *)&lbl_8043818C.value + 4);
    stack.sp1C = *(s32 *)((s8 *)&lbl_8043818C.value + 8);
    stack.sp8 = *(s32 *)((s8 *)&lbl_80438198.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_80438198.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_80438198.value + 8);
    push_matrix_from((void *) (&(*(RecoveredGlobal_8006AC70_lbl_8058D490 *)&identity_matrix).value));
    rotate_matrix_y(0, (void *)this->m_194);
    rotate_vector_by_current_matrix((void *)&stack.sp14, (void *)camera_right);
    pop_matrix();
    push_matrix_from((void *) (&(*(RecoveredGlobal_8006AC70_lbl_8058D490 *)&identity_matrix).value));
    rotate_matrix_x(0, (void *)this->m_190);
    rotate_vector_by_current_matrix((void *)&stack.sp8, (void *) (&(*(RecoveredGlobal_8006AC70_lbl_804FF61C *)&camera_pitch_rotated_up_vector).value));
    pop_matrix();
}
#pragma pop

#define ISNAN(x) TCameraCtrl__sub_8006B370(x)
#define G (camera_ctrl_instance)
#define GF(o) (*(f32 *)(G + (o)))
void TCameraCtrl::run_task() {
    u8 *arg0 = (u8 *)this;
    V3_8006AD34 v;
    u8 *t;
    s32 i;
    s32 off;

    arg0[0x1C] = 1;
    ((TCameraCtrl *)arg0)->update_target_from_state();
    cycle_spectate_target__11TCameraCtrlFv(arg0);
    ((TCameraCtrl *)arg0)->update_active_controller();
    reset_view_flags__11TCameraCtrlFv(arg0);
    if (G != NULL) {
        if (ISNAN(GF(0x178)) == 0 && ISNAN(GF(0x17C)) == 0) {
            ISNAN(GF(0x180));
        }
        if (ISNAN(GF(0x178)) == 0 && ISNAN(GF(0x17C)) == 0) {
            ISNAN(GF(0x180));
        }
        if (ISNAN(GF(0x184)) == 0 && ISNAN(GF(0x188)) == 0) {
            ISNAN(GF(0x18C));
        }
    }
    if (G != NULL) {
        t = get_target__11TCameraCtrlFv(arg0);
        v.x = (((f32 *)t)[0] + GF(0x184)) - GF(0x178);
        v.y = (((f32 *)t)[1] + GF(0x188)) - GF(0x17C);
        v.z = (((f32 *)t)[2] + GF(0x18C)) - GF(0x180);
        lbl_804FF5E8[0] = *(f32 *)(arg0 + 0x178);
        lbl_804FF5E8[1] = *(f32 *)(arg0 + 0x17C);
        lbl_804FF5E8[2] = *(f32 *)(arg0 + 0x180);
        if (TCameraCtrl__data_805D8FA8 != vec_squared_length(&v)) {
            normalize_vector(&v);
        }
        lbl_804FF5E8[3] = v.x;
        lbl_804FF5E8[4] = v.y;
        lbl_804FF5E8[5] = v.z;
        vector_length(&v);
    }
    if (is_split_screen() != 0) {
        if (TCameraCtrl__view_state[0] == 5) {
            ((TObjBoss2Tunnel *)lbl_804FF5E8)->render(&TCameraCtrl__view_matrices[TCameraCtrl::get_camera_no()]);
            for (i = 1; i < 4; i++) {
                copy_view_params__11TCameraCtrlFii(&TCameraCtrl__view_matrices[i], &TCameraCtrl__view_matrices[0]);
            }
        } else {
            ((TObjBoss2Tunnel *)lbl_804FF5E8)->render(&TCameraCtrl__view_matrices[TCameraCtrl::get_camera_no()]);
        }
    } else {
        ((TObjBoss2Tunnel *)lbl_804FF5E8)->render(TCameraCtrl__view_matrix);
    }
    ((TCameraCtrl *)arg0)->calc_rotated_axes();
}
#undef ISNAN
#undef G
#undef GF

u8 * copy_view_params__11TCameraCtrlFii(C30_8006AD34 *arg0, const C30_8006AD34 *arg1) {
    *(ByteBlock_30 *)(arg0) = *(const ByteBlock_30 *)(arg1);
    return (u8 *)arg0;
}

#define self ((Cam_8006B0D4 *)arg0)

void TCameraCtrl::setup_default_view(void *arg1_arg) {
    Vec_8006AF9C *arg1 = (Vec_8006AF9C *)arg1_arg;
    Vec_8006AF9C eye;
    Vec_8006AF9C at;
    Vec_8006AF9C d;
    Vec_8006AF9C *pat;
    eye.x = lbl_804FF5E8[0];
    eye.y = lbl_804FF5E8[1];
    eye.z = lbl_804FF5E8[2];
    if (arg1 != 0) {
        eye.x += arg1->x;
        eye.y += arg1->y;
        eye.z += arg1->z;
    }
    at.x = lbl_804FF5E8[3] + eye.x;
    at.y = lbl_804FF5E8[4] + eye.y;
    at.z = lbl_804FF5E8[5] + eye.z;
    d.x = eye.x - at.x;
    d.y = eye.y - at.y;
    d.z = eye.z - at.z;
    pat = &at;
    if (TCameraCtrl__data_805D8FA8 == vec_squared_length(&d)) {
        pat->z += TCameraCtrl__data_805D8FAC;
    }
    if (TCameraCtrl__data_805D8FA8 == d.x && TCameraCtrl__data_805D8FA8 == d.z) {
        pat->z += TCameraCtrl__data_805D8FAC;
    }
    set_perspective_projection_from_fov(((Obj_8006AF9C *)this)->f19c, TCameraCtrl__data_805D8FDC, TCameraCtrl__data_805D8FAC, TCameraCtrl__data_805D8FE0);
    set_camera_look_at((u8 *)&eye, (u8 *)&at, (u8 *)TCameraCtrl__up_vector);
}

#pragma push
#pragma opt_common_subs off
u8 *TCameraCtrl__ct(u8 *arg0, void *parent) {
    s32 i;
    s32 k;
    s32 j;

    __ct__7TObjectFP7TObject(arg0, parent);
    self->vt = (void **)lbl_80488AC0;
    self->name = lbl_805D283C;
    self->f1C = 0;
    camera_ctrl_instance = arg0;
    self->f19C = 0x3555;
    self->f90 = 0;
    self->f174 = 0;
    self->f1C8.x = TCameraCtrl__data_805D8FA8;
    self->f1C8.y = TCameraCtrl__data_805D8FA8;
    self->f1C8.z = TCameraCtrl__data_805D8FA8;
    for (i = 0; i < 4; i++) {
        self->f94[i] = 0;
        self->fA4[i].x = TCameraCtrl__data_805D8FA8;
        self->fA4[i].y = TCameraCtrl__data_805D8FA8;
        self->fA4[i].z = TCameraCtrl__data_805D8FA8;
        self->f134[i].x = TCameraCtrl__data_805D8FA8;
        self->f134[i].y = TCameraCtrl__data_805D8FA8;
        self->f134[i].z = TCameraCtrl__data_805D8FA8;
        self->f164[i] = 0;
    }
    self->f178.x = TCameraCtrl__data_805D8FA8;
    self->f178.y = TCameraCtrl__data_805D8FA8;
    self->f178.z = TCameraCtrl__data_805D8FA8;
    self->f1A0.x = TCameraCtrl__data_805D8FA8;
    self->f1A0.y = TCameraCtrl__data_805D8FA8;
    self->f1A0.z = TCameraCtrl__data_805D8FA8;
    self->f184.x = TCameraCtrl__data_805D8FA8;
    self->f184.y = TCameraCtrl__data_805D8FA8;
    self->f184.z = TCameraCtrl__data_805D8FA8;
    self->f1AC.x = TCameraCtrl__data_805D8FA8;
    self->f1AC.y = TCameraCtrl__data_805D8FA8;
    self->f1AC.z = TCameraCtrl__data_805D8FA8;
    self->f190 = 0;
    self->f194 = 0;
    self->f198 = 0;
    self->f1C0 = 0;
    self->f1B8 = TCameraCtrl__data_805D8FA8;
    self->f1BC = TCameraCtrl__data_805D8FA8;
    self->f8C = 0;
    self->f68.x = TCameraCtrl__data_805D8FA8;
    self->f68.y = TCameraCtrl__data_805D8FA8;
    self->f68.z = TCameraCtrl__data_805D8FA8;
    self->f20 = 0;
    self->f24 = 0;
    self->f28 = 0;
    self->f2C = TCameraCtrl__data_805D8FA8;
    self->f30 = TCameraCtrl__data_805D8FA8;
    self->f34 = 0;
    self->f64 = 0;
    self->f38[0] = TCameraCtrl__data_805D8FA8;
    self->f38[1] = TCameraCtrl__data_805D8FA8;
    self->f38[2] = TCameraCtrl__data_805D8FA8;
    self->f38[3] = TCameraCtrl__data_805D8FA8;
    self->f38[4] = TCameraCtrl__data_805D8FA8;
    self->f38[5] = TCameraCtrl__data_805D8FA8;
    self->f38[6] = TCameraCtrl__data_805D8FA8;
    self->f38[7] = TCameraCtrl__data_805D8FA8;
    self->f38[8] = TCameraCtrl__data_805D8FA8;
    self->f38[9] = TCameraCtrl__data_805D8FA8;
    self->f74 = TCameraCtrl__data_805D8FA8;
    self->f78 = TCameraCtrl__data_805D8FA8;
    self->f7C = TCameraCtrl__data_805D8FA8;
    self->f80 = TCameraCtrl__data_805D8FA8;
    self->f80 = TCameraCtrl__data_805D8FA8;
    self->f80 = TCameraCtrl__data_805D8FA8;
    {
        for (k = 0; k < 13; k++) {
            ((s32 *)camera_controller_registry)[(*(Count_8006B0D4 *)TCameraCtrl__view_state).count++] = ((s32 (**)(void))lbl_80488A8C)[k]();
        }
    }
    (*(Count_8006B0D4 *)TCameraCtrl__view_state).flag = 0;
    for (j = 0; j < 4; j++) {
        self->fD4[j].x = TCameraCtrl__data_805D8FA8;
        self->fD4[j].y = TCameraCtrl__data_805D8FA8;
        self->fD4[j].z = TCameraCtrl__data_805D8FA8;
        self->f104[j].x = TCameraCtrl__data_805D8FA8;
        self->f104[j].y = TCameraCtrl__data_805D8FA8;
        self->f104[j].z = TCameraCtrl__data_805D8FA8;
    }
    lbl_804FF5E8[0] = TCameraCtrl__data_805D8FA8;
    lbl_804FF5E8[1] = TCameraCtrl__data_805D8FA8;
    lbl_804FF5E8[2] = TCameraCtrl__data_805D8FA8;
    lbl_804FF5E8[3] = TCameraCtrl__data_805D8FA8;
    lbl_804FF5E8[4] = TCameraCtrl__data_805D8FA8;
    lbl_804FF5E8[5] = lbl_805D8FE4;
    return arg0;
}
#pragma pop
#undef self

typedef char RecoveredGlobal_8006B324_lbl_805137F8_size[sizeof(RecoveredGlobal_8006B324_lbl_805137F8) == 0x24 ? 1 : -1];
s32 *get_character_select_request_buffer(void) {
    return &chr_select_request_buffer.value;
}

int TCameraCtrl::get_instance() {  return camera_split_screen_selector; }

    extern int TCameraCtrl__camera_id;
int TCameraCtrl::get_camera_id() {  return TCameraCtrl__camera_id; }

    extern short TCameraCtrl__viewport_size;
    extern short TCameraCtrl__viewport_height;
void TCameraCtrl::set_target(int a0, int a1) { TCameraCtrl__viewport_size = a0; TCameraCtrl__viewport_height = a1; }

    extern short TCameraCtrl__viewport_x;
    extern short TCameraCtrl__viewport_y;
void TCameraCtrl::set_target_coords(int a0, int a1) { TCameraCtrl__viewport_x = a0; TCameraCtrl__viewport_y = a1; }

u16 TCameraCtrl__sub_8006B358(void* p) { return *(u16*)((char*)p + 0x20); }
s32 get_mode__11TCameraCtrlFPv(void* p) { return *(s32*)((char*)p + 0x1c); }

    extern int quest_active_flag;
int is_quest_active(void) {  return quest_active_flag; }

int TCameraCtrl__sub_8006B370(f32 farg0) {
    u32 v = *(u32 *)&farg0 & 0x7F800000;
    return v == 0x7F800000;
}

int TCameraCtrl::reset_battle_camera() { return reset_to_local_player__11TCameraCtrlFv(this); }
int TCameraCtrl__sub_8006B3B8(void* p) { return set_fixed_position_and_target__11TCameraCtrlFPUcPUc(p); }

}
