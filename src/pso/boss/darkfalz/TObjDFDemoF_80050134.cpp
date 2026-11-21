#pragma defer_codegen on

#include "types.h"

#include "pso/camera/CameraPlayback.h"

#include "pso/system/PadRumble.h"

#include "pso/system/task/TObject.h"

#include "pso/boss/darkfalz/TObjDFDemoF.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/camera/TCameraCtrl_800687BC.h"

#include "pso/boss/volopt/TBoss3Volopt.h"

#include "pso/boss/darkfalz/TBoss4Uro.h"

#include "pso/camera/TCameraCtrl.h"

#include "pso/system/SoundEffect.h"
extern "C" {
void __dl__7TObjectFPv(void *);

typedef struct Data_80050194 Data_80050194;

typedef struct Obj_80050194 Obj_80050194;

typedef struct Obj_80050194
{
  const char *f0;
  u8 pad4[0x18 - 0x4];
  void *vt;
  u8 pad1c[0x90 - 0x1c];
  s32 f90;
  s32 f94[3];
  s32 fa0[3];
  s32 fac[3];
  f32 fb8;
} Obj_80050194;

typedef struct Data_80050194
{
  s32 f0[3];
  s32 fc[3];
  f32 f18[3];
  f32 f24[3];
  f32 f30[3];
  u8 pad3c[0x48 - 0x3C];
  u8 vt[4];
} Data_80050194;

s32 get_bml_motion(s32, s32);

s32 get_bml_texlist(BmlResource *resource, s32 index);

s32 get_bml_model(BmlResource *resource, s32 index);

void set_scripted_camera_pose(void *, void *, void *);

const char *TObjDFDemoF__name = "TObjDFDemoF";

void vfunc_6__8TObjBaseFPsl();

void get_name__8TObjBaseFv();

void get_center__8TObjBaseFv();

void apply_object_set_data__8TObjBaseFPv();

void classify_actor_view_detail__8TObjBaseFfff();

void render_shadows__7TObjectFv();

void reset_motion_fields__8TObjBaseFv();

void update_object_view_visibility__8TObjBaseFff();

s32 TObjDFDemoF__bml_model_id_table[3] = {0x0, 0x10, 0x11};

s32 lbl_80485834[3] = {-1, 0x26, 0x27};

void *lbl_80485840[3] = {(void *) 0xc69c4000, (void *) 0x0, (void *) 0x0};

void *lbl_8048584C[3] = {(void *) 0x0, (void *) 0x0, (void *) 0x0};

CameraPlayback lbl_80485858 = {0, 5, 0, 0.0f, 0.5f};

void *three_part_model_translate_offset[3] = {(void *) 0xc69c4000, (void *) 0x0, (void *) 0x0};

#pragma opt_propagation off

#pragma opt_common_subs off

TObjDFDemoF::TObjDFDemoF(TObject *parent) : TObjBase(parent) {
  Obj_80050194 *arg0 = (Obj_80050194 *)this;
  s32 k;
  s32 *ids2;
  s32 h;
  Obj_80050194 *new_var;
  s32 i;
  new_var = arg0;
  new_var->f0 = TObjDFDemoF__name;
  h = TBoss4Uro::get_instance_count();
  for (i = 0; i < 3; i++)
  {
    s32 t = TObjDFDemoF__bml_model_id_table[i];
    ids2 = lbl_80485834;
    {
      k = t;
      arg0->f94[i] = get_bml_model((BmlResource *)h, t);
    }
    arg0->fa0[i] = get_bml_texlist((BmlResource *)h, k);
    if (ids2[i] < 0)
    {
      arg0->fac[i] = 0;
    }
    else
    {
      arg0->fac[i] = get_bml_motion(h, ids2[i]);
    }
  }

  new_var->fb8 = -1.0f;
  activate_camera_mode(5);
  set_scripted_camera_pose(lbl_80485840, lbl_80485840, lbl_8048584C);
  lbl_80485858.cache_target_and_forward(0x392D);
  play_sound_effect(0x3A802, 0, 0, 0);
  start_pad_rumble_all(0x20, 0xF);
  arg0->f90 = 0;
}

TObjDFDemoF::~TObjDFDemoF() {
    restore_player_cameras();
}
}
