#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/animation/MotionContext.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/object/lobby/LobbyPigeonPath.h"

#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/TObjPathObj.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TObjSeabedDolphin.h"
#include "pso/object/TObjJungleEbi.h"
#include "pso/object/TObjJungleBird.h"
#include "pso/object/TObjJungleKamome.h"
#include "pso/object/TObjLobbyPigeon.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include <stdlib.h>
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/lobby/LobbyPigeonTheme.h"

struct Entry_802C0CAC { s32 a; union { f32 pa; s32 b; }; union { f32 pb; s32 c; }; f32 d; s32 e; };

struct Obj_802C0CAC {
    u8 pad0[0xA8];
    s32 f98;
    s32 f9C;
    s32 fA0;
    u8 padA4[0x8];
    Vec vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

struct Obj_802C0A74 {
    u8 pad0[0xA8];
    s32 f98;
    s32 f9C;
    s32 fA0;
    f32 fA4;
    u8 padA8[0x4];
    Vec vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

struct Entry_802C1660 { s32 a; f32 b; f32 c; f32 d; s32 e; };
struct Entry_802C1E34 { s32 a; f32 b; f32 c; f32 d; s32 e; };
struct Entry_802C2548 { s32 a; f32 b; f32 c; f32 d; s32 e; s32 f; };
struct Entry_802C2C48 { s32 a; f32 b; f32 c; f32 d; s32 e; };
typedef Entry_802C0CAC Ent_802C0F3C;

// Resource descriptors of the path-following objects: seabed dolphin, jungle ebi, jungle bird,
// jungle kamome and lobby pigeon.
const char *bm_obj_seabed_dolphin_model_names[2] = { "d_dolf.nj", NULL };
const char *bm_obj_seabed_dolphin_motion_names[7] = { "d_20mcircle.njm", "d_30mcircle.njm", "d_30mx_01.njm", "d_30mx_02.njm", "d_30mx_03.njm", "d_dolf.njm", NULL };
BmlResourceDescriptor bm_obj_seabed_dolphin_resource_descriptor = { "bm_obj_seabed_dolphin.bml", bm_obj_seabed_dolphin_model_names, bm_obj_seabed_dolphin_motion_names, 1, 6 };
const char *bm_obj_jungle_ebi_model_names[2] = { "fe_obj_h_ebi.nj", NULL };
const char *bm_obj_jungle_ebi_motion_names[5] = { "fe_obj_h_ebi.njm", "path01_h_ebi.njm", "path02_h_ebi.njm", "path03_h_ebi.njm", NULL };
BmlResourceDescriptor bm_obj_jungle_ebi_resource_descriptor = { "bm_obj_jungle_ebi.bml", bm_obj_jungle_ebi_model_names, bm_obj_jungle_ebi_motion_names, 1, 4 };
const char *bm_obj_jungle_bird_model_names[2] = { "fe_obj_h_tori.nj", NULL };
const char *bm_obj_jungle_bird_motion_names[5] = { "fe_obj_h_tori.njm", "path01_h_tori.njm", "path02_h_tori.njm", "path03_h_tori.njm", NULL };
BmlResourceDescriptor bm_obj_jungle_bird_resource_descriptor = { "bm_obj_jungle_bird.bml", bm_obj_jungle_bird_model_names, bm_obj_jungle_bird_motion_names, 1, 4 };
const char *bm_obj_jungle_kamome_model_names[2] = { "fe_obj_h_kamome.nj", NULL };
const char *bm_obj_jungle_kamome_motion_names[5] = { "fe_obj_h_kamome.njm", "path01_h2_tori.njm", "path02_h2_tori.njm", "path03_h2_tori.njm", NULL };
BmlResourceDescriptor bm_obj_jungle_kamome_resource_descriptor = { "bm_obj_jungle_kamome.bml", bm_obj_jungle_kamome_model_names, bm_obj_jungle_kamome_motion_names, 1, 4 };
const char *bm_obj_lobby_pigeon_model_names[3] = { "lobby_obj_hato.nj", "lobby_obj_karasu.nj", NULL };
const char *bm_obj_lobby_pigeon_motion_names[5] = { "lobby_obj_hato.njm", "path01_h_pigeon.njm", "path02_h_pigeon.njm", "path03_h_pigeon.njm", NULL };
BmlResourceDescriptor bm_obj_lobby_pigeon_resource_descriptor = { "bm_obj_lobby_pigeon.bml", bm_obj_lobby_pigeon_model_names, bm_obj_lobby_pigeon_motion_names, 2, 4 };

uaddr seabed_dolphin_bml_archive;
NJS_TEXLIST *seabed_dolphin_texture_handle;
uaddr jungle_ebi_model_resource;
NJS_TEXLIST *jungle_ebi_texture_gvm_handle;
uaddr jungle_bird_bml_resource;
NJS_TEXLIST *lobby_pigeon_texture_gvm;
uaddr lobby_kamome_model_resource;
NJS_TEXLIST *lobby_kamome_texture_gvm_handle;
struct BmlResource;
BmlResource *lobby_pigeon_bml_archive;
NJS_TEXLIST *lobby_pigeon_lobby_type;

// TObjPathObj's class name.
const char *TObjPathObj__name = "TObjPathObj";

// Path profiles: {motion, pathSpeed, animationSpeed, lookAhead, turnStep}
// (PigeonMovement's fields); turnStep 182 is one degree in 0x10000 units.
extern const Entry_802C2C48 seabed_dolphin_path_profiles[5] = {
    {0, 0.2f, 0.6f, 0.1f, 182},
    {1, 0.2f, 0.6f, 0.1f, 182},
    {2, 0.2f, 0.6f, 0.1f, 182},
    {3, 0.2f, 0.6f, 0.1f, 182},
    {4, 0.2f, 0.6f, 0.1f, 182},
};
// The dolphin's one action (mode 1, motion 5 at 0.6 speed); inferred name: the action table of
// seabed_dolphin_anim_binding, which load_seabed_dolphin hands to NpcModelRegistry::register_animated_chunk.
TObjMotionAction seabed_dolphin_actions[1] = {
    {1, 0, 5, 0.6f, 0},
};
extern const NpcAnimationBinding seabed_dolphin_anim_binding = { NULL, seabed_dolphin_actions, 0, 0, 1 };
extern const Entry_802C2548 jungle_ebi_path_profiles[3] = {
    {1, 0.01f, 0.6f, 0.1f, 182, 5},
    {2, 0.01f, 0.6f, 0.1f, 182, 5},
    {3, 0.01f, 0.6f, 0.1f, 364, 5},
};
extern const Entry_802C1E34 lobby_pigeon_path_parameters[3] = {
    {1, 0.1f, 0.6f, 0.1f, 364},
    {2, 0.1f, 0.6f, 0.1f, 364},
    {3, 0.1f, 0.6f, 0.1f, 546},
};
extern const Entry_802C1660 jungle_seagull_path_profiles[3] = {
    {1, 0.1f, 0.6f, 0.1f, 364},
    {2, 0.1f, 0.6f, 0.1f, 364},
    {3, 0.1f, 0.6f, 0.1f, 546},
};
extern const Vec lbl_80471908 = {0.0f, 0.0f, 0.0f};
extern const Ent_802C0F3C lobby_pigeon_path_profiles[3] = {
    {1, 0.1f, 2.0f, 0.1f, 364},
    {2, 0.1f, 2.0f, 0.1f, 364},
    {3, 0.1f, 2.0f, 0.1f, 546},
};
extern const Vec lobby_pigeon_zero_vec = {0.0f, 0.0f, 0.0f};
extern const f64 lbl_80471960[1] = {10430.38043493439};

void direction_to_rotation_xz(u8 *dir, s32 *rot_a, s32 *rot_b);
s32 sample_clamped_path_position(void *arg0, saddr arg1, void *arg2, saddr arg3, f32 farg0);
extern "C" {
s32 approach_angle_limited(s32, s32, s32);
s32 angle_diff_s16(s32, s32);

}

#include "pso/object/lobby/LobbyPigeon.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/math/MatrixTransforms.h"

struct Obj_802C22A4 {
    u8 pad0[0x1E]; s16 f1E; u8 pad20[0x38 - 0x20]; Vec pos;
    u8 pad44[0x98 - 0x44];
    s32 f98; s32 f9C; s32 fA0; f32 fA4; u8 padA8[0x4];
    Vec vAC; s32 fB8; s32 fBC; s32 fC0; s32 fC4; s32 fC8;
};

struct PigeonMovement { s32 motion; f32 pathSpeed, animationSpeed, lookAhead; s32 turnStep; };

extern "C" {


saddr get_bml_motion(void *, s32);

s32 post_translate_matrix(void *);

struct Obj_802C1660 {
    u8 pad0[0x98];
    s32 f98;
    s32 f9C;
    s32 fA0;
    u8 padA4[0x8];
    Vec vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

struct Obj_802C1428 {
    u8 pad0[0x98];
    s32 f98;
    s32 f9C;
    s32 fA0;
    f32 fA4;
    u8 padA8[0x4];
    Vec vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

struct Obj_802C1E34 {
    u8 pad0[0x98];
    s32 f98;
    s32 f9C;
    s32 fA0;
    u8 padA4[0x8];
    Vec vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

struct Obj_802C1BFC {
    u8 pad0[0x98];
    s32 f98;
    s32 f9C;
    s32 fA0;
    f32 fA4;
    u8 padA8[0x4];
    Vec vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

struct Ent_802C1FD0 { s32 a; f32 b; f32 c; s32 d; s32 e; };
struct Sub_802C1FD0 { s32 a; u32 n; };
struct Pl_802C1FD0 {
    u8 pad0[0x9C];
    Sub_802C1FD0 *sub;
    u8 pad4[0xA4 - 0xA0];
    f32 x;
    f32 y;
    u8 padac[0xC8 - 0xAC];
    s32 idx;
};

struct Ent_802C26E4 { s32 a; f32 b; f32 c; s32 d; s32 e; s32 f; };
struct Sub_802C26E4 { s32 a; u32 n; };
struct Pl_802C26E4 {
    u8 pad0[0x9C];
    Sub_802C26E4 *sub;
    u8 pad4[0xA4 - 0xA0];
    f32 x;
    f32 y;
    u8 padac[0xC8 - 0xAC];
    s32 idx;
};

struct Obj_802C2548 {
    u8 pad0[0x98];
    s32 f98;
    s32 f9C;
    s32 fA0;
    u8 padA4[0x8];
    Vec vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

struct Obj_802C2958 { u8 pad[0x430]; s32 f430; };

struct Sub_802C2DEC { s32 a; u32 n; };
struct Pl_802C2DEC {
    u8 pad0[0x9C];
    Sub_802C2DEC *sub;
    u8 pad4[0xA4 - 0xA0];
    f32 x;
    f32 y;
    u8 padac[0xC8 - 0xAC];
    s32 idx;
};

struct Obj_802C2C48 {
    u8 pad0[0x98];
    s32 f98;
    s32 f9C;
    s32 fA0;
    u8 padA4[0x8];
    Vec vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

struct Obj_802C2A10 {
    u8 pad0[0x98];
    s32 f98;
    s32 f9C;
    s32 fA0;
    f32 fA4;
    u8 padA8[0x4];
    Vec vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

struct Mtx_802C0F3C { f32 m[3][4]; };

struct Cnt_802C0F3C { s32 f0; s32 n; };

struct Obj_802C0F3C {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0xAC - 0x64];
    Cnt_802C0F3C *ac;
    u8 padb0[4];
    f32 b4;
    f32 b8;
    Vec bc;
    u8 padc8[0xD8 - 0xC8];
    s32 d8;
    s32 dc;
};

typedef struct { f32 m[3][4]; } Mtx_802C17FC;

typedef struct { f32 f0, f4, f8, fC; s32 f10; } Ent_802C17FC;

typedef struct { u8 pad[4]; u32 n; } Anim_802C17FC;

s32 debug_draw_line(s32 *, s32 *, s32, s32);
void matrix_mult_vec(void *, void *, void *);

s32 release_texture_list(void*);
}
struct Pl_802C26E4;
struct Ent_802C26E4;

#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/TLanguage_801E4874.h"


#pragma push
#pragma readonly_strings on
void TObjPathObj::vfunc_13() {  }

void TObjPathObj::vfunc_14() {  }

TObjPathObj::TObjPathObj(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjPathObj__name;
    apply_object_set_data(set_data);
    view_distance = 5e+02f;
    m_94 = 1.5e+02f;
}

TObjPathObj::~TObjPathObj() {}

void TObjPathObj::run_task() {
    vfunc_13();
}

void TObjPathObj::render() {
    if (TMainTask::get_render_pass() != 1 && update_object_view_visibility(view_distance, m_94) != 0) {
        vfunc_14();
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 sample_clamped_path_position(void *arg0, saddr node, void *motion, saddr pos, f32 farg0) {
  s32 ang[3];
  s32 scl[3];
  s32 quat[4];
  f32 frame;
  s32 var_r31;
  u32 temp_r7;

  frame = farg0;
  var_r31 = 1;
  temp_r7 = *(s32 *)((s8 *)motion + 4) - 1;
  if (frame > (f32)temp_r7) {
    var_r31 = 0;
    frame = (f32)temp_r7;
  }
  bind_motion_context((NJS_MOTION *)motion, frame);
  sample_motion_node_transform((NJS_OBJECT *)node, (f32 *)pos, ang, (f32 *)scl, (f32 *)quat);
  return var_r31;
}
#pragma pop

#pragma push
#pragma fp_contract on

void draw_line_strip__10TObjPlayerFPviif(u8 *path_obj, s32 arg1, s32 arg2, f32 farg0) {
    s32 sp14[3];
    s32 sp8[3];
    f32 var_f31;
    s32 temp_r30;

    var_f31 = (0.0f);
    do {
      ((s32 (*)(void *, s32, s32, s32 *, f32))sample_clamped_path_position)(
          path_obj, arg1, arg2, sp14, var_f31);
      var_f31 += farg0;
      temp_r30 = ((s32 (*)(void *, s32, s32, s32 *,
                           f32))sample_clamped_path_position)(path_obj, arg1, arg2,
                                                              sp8, var_f31);
      push_matrix();
      post_translate_matrix(path_obj + 0x38);
      rotate_matrix_y(0, ((TObjPathObj *)path_obj)->rotation_y);
      debug_draw_line(sp14, sp8, 0xF0F0F0FF, 0xF0F0F0FF);
      pop_matrix();
    } while (temp_r30 != 0);
}
#pragma pop

#pragma push
#pragma fp_contract on
TObjSeabedDolphin::TObjSeabedDolphin(TObject *parent, void *set_data) : TObjPathObj(parent, set_data) {
  s32 var_r0;
  s32 temp_r3;
  motion_model = get_bml_model((BmlResource *)(*(u8 * *)&seabed_dolphin_bml_archive), 0);
  bml_motion = get_bml_motion((*(u8 * *)&seabed_dolphin_bml_archive), 5);
  temp_r3 = set_params[0];
  if (temp_r3 < 0)
  {
    var_r0 = 0;
  }
  else
  {
    var_r0 = 4;
    if (temp_r3 <= 4)
    {
      var_r0 = temp_r3;
    }
  }
  m_c8 = var_r0;
  *((s32 *) (((s8 *) this) + 0xA0)) = get_bml_motion((*(u8 * *)&seabed_dolphin_bml_archive), *((s32 *) ((s8 *)&seabed_dolphin_path_profiles + ((m_c8) * 0x14))));
  m_a4 = 0.0f;
  m_a8 = 0.0f;
  sub_802C2C48();
}

TObjSeabedDolphin::~TObjSeabedDolphin() {}

void TObjSeabedDolphin::vfunc_13() {
    Pl_802C2DEC *arg0 = (Pl_802C2DEC *)this;
    const Entry_802C2C48 *e = seabed_dolphin_path_profiles;
    f32 ox;
    e += arg0->idx;
    ox = arg0->x;
    arg0->x = ox + e->b;
    if (((TObjSeabedDolphin *)arg0)->sub_802C2A10() == 0) {
        arg0->x = (0.0f);
    }
    arg0->y = arg0->y + seabed_dolphin_path_profiles[arg0->idx].c;
    if (arg0->y > (f32)(arg0->sub->n - 1)) {
        arg0->y = (0.0f);
    }
}

void TObjSeabedDolphin::vfunc_14() {
    u8 *arg0 = (u8 *)this;
    if ((TObjPlayer::check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        ((s32 (*)(void *, s32, s32, f32))draw_line_strip__10TObjPlayerFPviif)(arg0, *(s32 *)&this->motion_model, *(s32 *)((s8 *)arg0 + 0xA0), (1.0f));
    }
    TObjFish::set_global_param(seabed_dolphin_texture_handle);
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix((u8 *)&this->unk_AC);
    rotate_matrix_y(0, this->m_b8);
    rotate_matrix_z(0, this->m_c0);
    set_motion_packed_rotation();
    draw_model_motion(this->motion_model, (void *)this->bml_motion, this->m_a8);
    clear_motion_packed_rotation();
    pop_matrix();
}

s32 TObjSeabedDolphin::sub_802C2C48() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 r;
    Obj_802C2C48 *self = (Obj_802C2C48 *)this;
    this->m_b8 = 0;
    self->fBC = 0;
    this->m_c0 = 0;
    self->fC4 = 0;
    ((s32 (*)(void *, s32, s32, Vec *,
              f32))sample_clamped_path_position)(self, self->f98, self->fA0, &a,
                                                 (0.0f));
    VecCopy((Vec *)&self->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec *,
                  f32))sample_clamped_path_position)(
        self, self->f98, self->fA0, &b, seabed_dolphin_path_profiles[this->m_c8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &self->fBC, &tmp);
    this->m_b8 = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

s32 TObjSeabedDolphin::sub_802C2A10() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 tmp2;
    s32 r;
    s32 old;
    s32 diff;
    ((s32 (*)(void *, s32, s32, Vec *,
              f32))sample_clamped_path_position)(((Obj_802C2A10 *)this), ((Obj_802C2A10 *)this)->f98, ((Obj_802C2A10 *)this)->fA0, &a,
                                                 ((Obj_802C2A10 *)this)->fA4);
    VecCopy((Vec *)&((Obj_802C2A10 *)this)->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec *,
                  f32))sample_clamped_path_position)(
        ((Obj_802C2A10 *)this), ((Obj_802C2A10 *)this)->f98, ((Obj_802C2A10 *)this)->fA0, &b, ((Obj_802C2A10 *)this)->fA4 + seabed_dolphin_path_profiles[((Obj_802C2A10 *)this)->fC8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &tmp, &tmp2);
    ((Obj_802C2A10 *)this)->fBC = approach_angle_limited(((Obj_802C2A10 *)this)->fBC, tmp, seabed_dolphin_path_profiles[((Obj_802C2A10 *)this)->fC8].e);
    old = ((Obj_802C2A10 *)this)->fB8;
    tmp = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    ((Obj_802C2A10 *)this)->fB8 = approach_angle_limited(old, tmp, seabed_dolphin_path_profiles[((Obj_802C2A10 *)this)->fC8].e);
    diff = angle_diff_s16(old, tmp);
    if (diff > 0x30) {
        if (((Obj_802C2A10 *)this)->fC4 > 0) {
            ((Obj_802C2A10 *)this)->fC4 = 0;
        }
        ((Obj_802C2A10 *)this)->fC4 -= 0x40;
        if (((Obj_802C2A10 *)this)->fC4 < -0x200) {
            ((Obj_802C2A10 *)this)->fC4 = -0x200;
        }
        ((Obj_802C2A10 *)this)->fC0 += ((Obj_802C2A10 *)this)->fC4;
        if (((Obj_802C2A10 *)this)->fC0 < -0x2000) {
            ((Obj_802C2A10 *)this)->fC0 = -0x2000;
        }
    } else if (diff < -0x30) {
        if (((Obj_802C2A10 *)this)->fC4 < 0) {
            ((Obj_802C2A10 *)this)->fC4 = 0;
        }
        ((Obj_802C2A10 *)this)->fC4 += 0x40;
        if (((Obj_802C2A10 *)this)->fC4 > 0x200) {
            ((Obj_802C2A10 *)this)->fC4 = 0x200;
        }
        ((Obj_802C2A10 *)this)->fC0 += ((Obj_802C2A10 *)this)->fC4;
        if (((Obj_802C2A10 *)this)->fC0 > 0x2000) {
            ((Obj_802C2A10 *)this)->fC0 = 0x2000;
        }
    } else {
        ((Obj_802C2A10 *)this)->fC4 = 0;
        if (((Obj_802C2A10 *)this)->fC0 > 0x100) {
            ((Obj_802C2A10 *)this)->fC0 -= 0x100;
        } else if (((Obj_802C2A10 *)this)->fC0 < -0x100) {
            ((Obj_802C2A10 *)this)->fC0 += 0x100;
        } else {
            ((Obj_802C2A10 *)this)->fC0 = 0;
        }
    }
    return r;
}

void TObjSeabedDolphin::load_static_resource() {
    Obj_802C2958 *o = (Obj_802C2958 *)new BmlResource(5, &bm_obj_seabed_dolphin_resource_descriptor, 0, 0, NULL);
    (*(Obj_802C2958 * *)&seabed_dolphin_bml_archive) = o;
    seabed_dolphin_texture_handle = load_gvm_texture_file("obj_seabed_dolphin.gvm");
    NpcAnimationBinding binding = seabed_dolphin_anim_binding;
    binding.motions = reinterpret_cast<BmlMotionEntry *>((*(Obj_802C2958 * *)&seabed_dolphin_bml_archive)->f430);
    NpcModelRegistry::register_animated_chunk(0x40,
        reinterpret_cast<void *>(get_bml_model((BmlResource *)reinterpret_cast<void *>(seabed_dolphin_bml_archive), 0)),
        seabed_dolphin_texture_handle, &binding, 16.0f, 10.0f);
}
#pragma pop

#pragma push
#pragma fp_contract on

void TObjSeabedDolphin::destroy_instance() {
    if (seabed_dolphin_texture_handle != NULL) {
        release_texture_list(seabed_dolphin_texture_handle);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)seabed_dolphin_texture_handle);
        seabed_dolphin_texture_handle = NULL;
    }
    if ((u32) seabed_dolphin_bml_archive != 0U) {
        delete (BmlResource *)seabed_dolphin_bml_archive;
        seabed_dolphin_bml_archive = 0U;
    }
}

void *TObjSeabedDolphin::create(void *set_data) {
    return new TObjSeabedDolphin(tl_05, set_data);
}
#pragma pop

#pragma push
#pragma fp_contract on
TObjJungleEbi::TObjJungleEbi(TObject *parent, void *set_data) : TObjPathObj(parent, set_data) {
  s32 var_r0;
  s32 temp_r3;
  motion_model = get_bml_model((BmlResource *)(*(u8 * *)&jungle_ebi_model_resource), 0);
  bml_motion = get_bml_motion((*(u8 * *)&jungle_ebi_model_resource), 0);
  temp_r3 = set_params[0];
  if (temp_r3 < 0)
  {
    var_r0 = 0;
  }
  else
  {
    var_r0 = 2;
    if (temp_r3 <= 2)
    {
      var_r0 = temp_r3;
    }
  }
  m_c8 = var_r0;
  *((s32 *) (((s8 *) this) + 0xA0)) = get_bml_motion((*(u8 * *)&jungle_ebi_model_resource), *((s32 *) ((s8 *)&jungle_ebi_path_profiles + ((m_c8) * 0x18))));
  m_a4 = 0.0f;
  m_a8 = 0.0f;
  sub_802C2548();
}

TObjJungleEbi::~TObjJungleEbi() {}

void TObjJungleEbi::vfunc_13() {
    Pl_802C26E4 *arg0 = (Pl_802C26E4 *)this;
    Ent_802C26E4 *e = (Ent_802C26E4 *)jungle_ebi_path_profiles;
    e += arg0->idx;
    f32 ox = arg0->x;
    arg0->x = ox + e->b;
    if (((TObjJungleEbi *)arg0)->update_path_follow_rotation((Ent_802C26E4 *)(e), ox) == 0) {
        arg0->x = (0.0f);
    }
    arg0->y = arg0->y + jungle_ebi_path_profiles[arg0->idx].c;
    if (arg0->y > (f32)(arg0->sub->n - 1)) {
        arg0->y = (0.0f);
    }
}

void TObjJungleEbi::vfunc_14() {
    u8 *arg0 = (u8 *)this;
    if ((TObjPlayer::check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        ((s32 (*)(void *, s32, s32, f32))draw_line_strip__10TObjPlayerFPviif)(arg0, *(s32 *)&this->motion_model, *(s32 *)((s8 *)arg0 + 0xA0), (1.0f));
    }
    TObjFish::set_global_param(jungle_ebi_texture_gvm_handle);
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix((u8 *)&this->unk_AC);
    rotate_matrix_y(0, this->angle);
    rotate_matrix_z(0, this->m_c0);
    draw_model_motion(this->motion_model, (void *)this->bml_motion, this->m_a8);
    pop_matrix();
}

s32 TObjJungleEbi::sub_802C2548() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 r;
    Obj_802C2548 *self = (Obj_802C2548 *)this;
    this->angle = 0;
    self->fBC = 0;
    this->m_c0 = 0;
    self->fC4 = 0;
    ((s32 (*)(void *, s32, s32, Vec *,
              f32))sample_clamped_path_position)(self, self->f98, self->fA0, &a,
                                                 (0.0f));
    VecCopy((Vec *)&self->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec *,
                  f32))sample_clamped_path_position)(
        self, self->f98, self->fA0, &b, jungle_ebi_path_profiles[this->m_c8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &self->fBC, &tmp);
    this->angle = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

s32 TObjJungleEbi::update_path_follow_rotation(void *, f32) {
    s32 r;
    Obj_802C22A4 *self = (Obj_802C22A4 *)this;
    const Entry_802C2548 *e;
    s32 old;
    s32 diff;
    Vec a;
    Vec b;
    s32 tmp;
    s32 tmp2;
    e = &jungle_ebi_path_profiles[this->m_c8];
    if (!(e->f & 1)) {
        return 1;
    }
    ((s32 (*)(void *, s32, s32, Vec *,
              f32))sample_clamped_path_position)(self, self->f98, self->fA0, &a,
                                                 this->m_a4);
    VecCopy(&self->vAC, &a);
    r = ((s32 (*)(void *, s32, s32, Vec *,
                  f32))sample_clamped_path_position)(self, self->f98, self->fA0,
                                                     &b, this->m_a4 + e->d);
    if (this->visibility != 0) {
        Vec p = self->vAC;
        CsnHit *hit;
        vec3_add_to(&p, &self->pos);
        p.y += (1e+04f);
        hit = csnVecterUnder(&p, 0x16EF);
        if (hit != NULL) {
            self->pos.y = hit->contact->point.y;
        }
    }
    {
    Vec d;
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)((Vec *)&d), &tmp, &tmp2);
    }
    self->fBC = approach_angle_limited(self->fBC, tmp, e->e);
    old = this->angle;
    tmp = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    if (!(e->f & 2)) {
        this->angle = approach_angle_limited(old, tmp, e->e);
    }
    if (!(e->f & 4)) {
        diff = angle_diff_s16(old, tmp);
        if (diff > 0x30) {
            if (self->fC4 > 0) {
                self->fC4 = 0;
            }
            self->fC4 -= 0x40;
            if (self->fC4 < -0x200) {
                self->fC4 = -0x200;
            }
            this->m_c0 += self->fC4;
            if (this->m_c0 < -0x2000) {
                this->m_c0 = -0x2000;
            }
        } else if (diff < -0x30) {
            if (self->fC4 < 0) {
                self->fC4 = 0;
            }
            self->fC4 += 0x40;
            if (self->fC4 > 0x200) {
                self->fC4 = 0x200;
            }
            this->m_c0 += self->fC4;
            if (this->m_c0 > 0x2000) {
                this->m_c0 = 0x2000;
            }
        } else {
            self->fC4 = 0;
            if (this->m_c0 > 0x100) {
                this->m_c0 -= 0x100;
            } else if (this->m_c0 < -0x100) {
                this->m_c0 += 0x100;
            } else {
                this->m_c0 = 0;
            }
        }
    }
    return r;
}

void TObjJungleEbi::load_static_resource() {
    saddr var_r0;
    var_r0 = (saddr)new BmlResource(5, &bm_obj_jungle_ebi_resource_descriptor, 0, 0, NULL);
    (*(saddr *)&jungle_ebi_model_resource) = var_r0;
    jungle_ebi_texture_gvm_handle = load_gvm_texture_file("obj_jungle_ebi.gvm");
}

void TObjJungleEbi::destroy_instance() {
    if (jungle_ebi_texture_gvm_handle != NULL) {
        release_texture_list(jungle_ebi_texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)jungle_ebi_texture_gvm_handle);
        jungle_ebi_texture_gvm_handle = NULL;
    }
    if ((u32) jungle_ebi_model_resource != 0U) {
        delete (BmlResource *)jungle_ebi_model_resource;
        jungle_ebi_model_resource = 0U;
    }
}

void *TObjJungleEbi::create(void *set_data) {
    return new TObjJungleEbi(tl_05, set_data);
}

TObjJungleBird::TObjJungleBird(TObject *parent, void *set_data) : TObjPathObj(parent, set_data) {
  s32 var_r0;
  s32 temp_r3;
  motion_model = get_bml_model((BmlResource *)(*(u8 * *)&jungle_bird_bml_resource), 0);
  bml_motion = get_bml_motion((*(u8 * *)&jungle_bird_bml_resource), 0);
  temp_r3 = set_params[0];
  if (temp_r3 < 0)
  {
    var_r0 = 0;
  }
  else
  {
    var_r0 = 2;
    if (temp_r3 <= 2)
    {
      var_r0 = temp_r3;
    }
  }
  m_c8 = var_r0;
  *((s32 *) (((s8 *) this) + 0xA0)) = get_bml_motion((*(u8 * *)&jungle_bird_bml_resource), *((s32 *) ((s8 *)&lobby_pigeon_path_parameters + ((m_c8) * 0x14))));
  m_a4 = 0.0f;
  m_a8 = 0.0f;
  sub_802C1E34();
}

TObjJungleBird::~TObjJungleBird() {}

void TObjJungleBird::vfunc_13() {
    Pl_802C1FD0 *arg0 = (Pl_802C1FD0 *)this;
    u8 *t = (u8 *)lobby_pigeon_path_parameters;
    t = t + arg0->idx * 0x14;
    Ent_802C1FD0 *e = (Ent_802C1FD0 *)t;
    f32 ox = arg0->x;
    arg0->x = ox + e->b;
    if (((TObjJungleBird *)arg0)->update_path_steering() == 0) {
        arg0->x = (0.0f);
    }
    arg0->y = arg0->y + lobby_pigeon_path_parameters[arg0->idx].c;
    if (arg0->y > (f32)(arg0->sub->n - 1)) {
        arg0->y = (0.0f);
    }
}

void TObjJungleBird::vfunc_14() {
    u8 *arg0 = (u8 *)this;
    if ((TObjPlayer::check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        ((s32 (*)(void *, s32, s32, f32))draw_line_strip__10TObjPlayerFPviif)(arg0, *(s32 *)&this->motion_model, *(s32 *)((s8 *)arg0 + 0xA0), (1.0f));
    }
    TObjFish::set_global_param(lobby_pigeon_texture_gvm);
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix((u8 *)&this->unk_AC);
    rotate_matrix_y(0, this->m_b8);
    rotate_matrix_z(0, this->m_c0);
    draw_model_motion(this->motion_model, (void *)this->bml_motion, this->m_a8);
    pop_matrix();
}

s32 TObjJungleBird::sub_802C1E34() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 r;
    Obj_802C1E34 *self = (Obj_802C1E34 *)this;
    this->m_b8 = 0;
    self->fBC = 0;
    this->m_c0 = 0;
    self->fC4 = 0;
    ((s32 (*)(void *, s32, s32, Vec *,
              f32))sample_clamped_path_position)(self, self->f98, self->fA0, &a,
                                                 (0.0f));
    VecCopy((Vec *)&self->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec *,
                  f32))sample_clamped_path_position)(
        self, self->f98, self->fA0, &b, lobby_pigeon_path_parameters[this->m_c8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &self->fBC, &tmp);
    this->m_b8 = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

s32 TObjJungleBird::update_path_steering() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 tmp2;
    s32 r;
    s32 old;
    s32 diff;
    ((s32 (*)(void *, s32, s32, Vec *,
              f32))sample_clamped_path_position)(((Obj_802C1BFC *)this), ((Obj_802C1BFC *)this)->f98, ((Obj_802C1BFC *)this)->fA0, &a,
                                                 ((Obj_802C1BFC *)this)->fA4);
    VecCopy((Vec *)&((Obj_802C1BFC *)this)->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec *,
                  f32))sample_clamped_path_position)(
        ((Obj_802C1BFC *)this), ((Obj_802C1BFC *)this)->f98, ((Obj_802C1BFC *)this)->fA0, &b, ((Obj_802C1BFC *)this)->fA4 + lobby_pigeon_path_parameters[((Obj_802C1BFC *)this)->fC8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &tmp, &tmp2);
    ((Obj_802C1BFC *)this)->fBC = approach_angle_limited(((Obj_802C1BFC *)this)->fBC, tmp, lobby_pigeon_path_parameters[((Obj_802C1BFC *)this)->fC8].e);
    old = ((Obj_802C1BFC *)this)->fB8;
    tmp = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    ((Obj_802C1BFC *)this)->fB8 = approach_angle_limited(old, tmp, lobby_pigeon_path_parameters[((Obj_802C1BFC *)this)->fC8].e);
    diff = angle_diff_s16(old, tmp);
    if (diff > 0x30) {
        if (((Obj_802C1BFC *)this)->fC4 > 0) {
            ((Obj_802C1BFC *)this)->fC4 = 0;
        }
        ((Obj_802C1BFC *)this)->fC4 -= 0x40;
        if (((Obj_802C1BFC *)this)->fC4 < -0x200) {
            ((Obj_802C1BFC *)this)->fC4 = -0x200;
        }
        ((Obj_802C1BFC *)this)->fC0 += ((Obj_802C1BFC *)this)->fC4;
        if (((Obj_802C1BFC *)this)->fC0 < -0x2000) {
            ((Obj_802C1BFC *)this)->fC0 = -0x2000;
        }
    } else if (diff < -0x30) {
        if (((Obj_802C1BFC *)this)->fC4 < 0) {
            ((Obj_802C1BFC *)this)->fC4 = 0;
        }
        ((Obj_802C1BFC *)this)->fC4 += 0x40;
        if (((Obj_802C1BFC *)this)->fC4 > 0x200) {
            ((Obj_802C1BFC *)this)->fC4 = 0x200;
        }
        ((Obj_802C1BFC *)this)->fC0 += ((Obj_802C1BFC *)this)->fC4;
        if (((Obj_802C1BFC *)this)->fC0 > 0x2000) {
            ((Obj_802C1BFC *)this)->fC0 = 0x2000;
        }
    } else {
        ((Obj_802C1BFC *)this)->fC4 = 0;
        if (((Obj_802C1BFC *)this)->fC0 > 0x100) {
            ((Obj_802C1BFC *)this)->fC0 -= 0x100;
        } else if (((Obj_802C1BFC *)this)->fC0 < -0x100) {
            ((Obj_802C1BFC *)this)->fC0 += 0x100;
        } else {
            ((Obj_802C1BFC *)this)->fC0 = 0;
        }
    }
    return r;
}

void TObjJungleBird::load_static_resource() {
    saddr var_r0;
    var_r0 = (saddr)new BmlResource(5, &bm_obj_jungle_bird_resource_descriptor, 0, 0, NULL);
    (*(saddr *)&jungle_bird_bml_resource) = var_r0;
    lobby_pigeon_texture_gvm = load_gvm_texture_file("obj_jungle_bird.gvm");
}

void TObjJungleBird::destroy_instance() {
    if (lobby_pigeon_texture_gvm != NULL) {
        release_texture_list(lobby_pigeon_texture_gvm);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)lobby_pigeon_texture_gvm);
        lobby_pigeon_texture_gvm = NULL;
    }
    if ((u32) jungle_bird_bml_resource != 0U) {
        delete (BmlResource *)jungle_bird_bml_resource;
        jungle_bird_bml_resource = 0U;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on

void *TObjJungleBird::create(void *set_data) {
    return new TObjJungleBird(tl_05, set_data);
}
#pragma pop

#pragma push
#pragma fp_contract on
TObjJungleKamome::TObjJungleKamome(TObject *parent, void *set_data) : TObjPathObj(parent, set_data) {
    s32 temp_r3;
    s32 var_r0;

    *(s32 *)((s8 *)this + 0x98) = ((s32 (*)(saddr, s32))get_bml_model)((*(saddr *)&lobby_kamome_model_resource), 0);
    m_9c = ((s32 (*)(saddr, s32))get_bml_motion)((*(saddr *)&lobby_kamome_model_resource), 0);
    temp_r3 = set_params[0];
    var_r0 = (temp_r3 < 0) ? 0 : (temp_r3 > 2) ? 2 : temp_r3;
    m_c8 = var_r0;
    *(s32 *)((s8 *)this + 0xA0) = ((s32 (*)(saddr, s32))get_bml_motion)((*(saddr *)&lobby_kamome_model_resource), *(s32 *)((s8 *)((s32 *)&jungle_seagull_path_profiles) + (m_c8 * 0x14)));
    m_a4 = 0.0f;
    m_a8 = 0.0f;
    sub_802C1660();
    view_distance = 1e+03f;
    *(s32 *)((s8 *)this + 0xCC) = (s32) (((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32) rand()))) + (1.5e+02f));
}

TObjJungleKamome::~TObjJungleKamome() {}

void TObjJungleKamome::vfunc_13() {
    u8 *arg0 = (u8 *)this;
    Mtx_802C17FC m;
    s32 temp_r0;

    this->m_a4 += jungle_seagull_path_profiles[this->m_c8].b;
    if (((TObjJungleKamome *)arg0)->update_path_steering() == 0) {
        this->m_a4 = (0.0f);
    }
    this->m_a8 += jungle_seagull_path_profiles[this->m_c8].c;
    if (this->m_a8 > (f32) ((*(Anim_802C17FC * *)&this->m_9c)->n - 1)) {
        this->m_a8 = (0.0f);
    }
    temp_r0 = *(s32 *)&this->unk_CC - 1;
    *(s32 *)&this->unk_CC = temp_r0;
    if (temp_r0 < 0) {
        Vec v = lbl_80471908;
        set_matrix_identity((u8 *)&m);
        translate_matrix_vec3((u8 *)&m, (u8 *)&this->position);
        ((s32 (*)(void *, int))rotate_matrix_y)(&m, this->rotation_y);
        translate_matrix_vec3((u8 *)&m, (u8 *)&this->unk_AC);
        ((s32 (*)(void *, void *, void *))matrix_mult_vec)(&m, &v, &v);
        play_sound_effect(0x4BC04, (u8 *)&this->position, 0x7F, 0);
        *(s32 *)&this->unk_CC = (s32) (((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32) rand()))) + (1.5e+02f));
    }
}

void TObjJungleKamome::vfunc_14() {
    u8 *arg0 = (u8 *)this;
    if ((TObjPlayer::check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        ((s32 (*)(void *, s32, s32, f32))draw_line_strip__10TObjPlayerFPviif)(arg0, *(s32 *)&this->motion_model, *(s32 *)((s8 *)arg0 + 0xA0), (1.0f));
    }
    TObjFish::set_global_param(lobby_kamome_texture_gvm_handle);
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix((u8 *)&this->unk_AC);
    rotate_matrix_y(0, this->m_b8);
    rotate_matrix_z(0, this->m_c0);
    draw_model_motion(this->motion_model, (void *)this->m_9c, this->m_a8);
    pop_matrix();
}

s32 TObjJungleKamome::sub_802C1660() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 r;
    Obj_802C1660 *self = (Obj_802C1660 *)this;
    this->m_b8 = 0;
    self->fBC = 0;
    this->m_c0 = 0;
    self->fC4 = 0;
    ((s32 (*)(void *, s32, s32, Vec *,
              f32))sample_clamped_path_position)(self, self->f98, self->fA0, &a,
                                                 (0.0f));
    VecCopy((Vec *)&self->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec *,
                  f32))sample_clamped_path_position)(
        self, self->f98, self->fA0, &b, jungle_seagull_path_profiles[this->m_c8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &self->fBC, &tmp);
    this->m_b8 = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

s32 TObjJungleKamome::update_path_steering() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 tmp2;
    s32 r;
    s32 old;
    s32 diff;
    ((s32 (*)(void *, s32, s32, Vec *,
              f32))sample_clamped_path_position)(((Obj_802C1428 *)this), ((Obj_802C1428 *)this)->f98, ((Obj_802C1428 *)this)->fA0, &a,
                                                 ((Obj_802C1428 *)this)->fA4);
    VecCopy((Vec *)(&((Obj_802C1428 *)this)->vAC), (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec *,
                  f32))sample_clamped_path_position)(
        ((Obj_802C1428 *)this), ((Obj_802C1428 *)this)->f98, ((Obj_802C1428 *)this)->fA0, &b, ((Obj_802C1428 *)this)->fA4 + jungle_seagull_path_profiles[((Obj_802C1428 *)this)->fC8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &tmp, &tmp2);
    ((Obj_802C1428 *)this)->fBC = approach_angle_limited(((Obj_802C1428 *)this)->fBC, tmp, jungle_seagull_path_profiles[((Obj_802C1428 *)this)->fC8].e);
    old = ((Obj_802C1428 *)this)->fB8;
    tmp = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    ((Obj_802C1428 *)this)->fB8 = approach_angle_limited(old, tmp, jungle_seagull_path_profiles[((Obj_802C1428 *)this)->fC8].e);
    diff = angle_diff_s16(old, tmp);
    if (diff > 0x30) {
        if (((Obj_802C1428 *)this)->fC4 > 0) {
            ((Obj_802C1428 *)this)->fC4 = 0;
        }
        ((Obj_802C1428 *)this)->fC4 -= 0x40;
        if (((Obj_802C1428 *)this)->fC4 < -0x200) {
            ((Obj_802C1428 *)this)->fC4 = -0x200;
        }
        ((Obj_802C1428 *)this)->fC0 += ((Obj_802C1428 *)this)->fC4;
        if (((Obj_802C1428 *)this)->fC0 < -0x2000) {
            ((Obj_802C1428 *)this)->fC0 = -0x2000;
        }
    } else if (diff < -0x30) {
        if (((Obj_802C1428 *)this)->fC4 < 0) {
            ((Obj_802C1428 *)this)->fC4 = 0;
        }
        ((Obj_802C1428 *)this)->fC4 += 0x40;
        if (((Obj_802C1428 *)this)->fC4 > 0x200) {
            ((Obj_802C1428 *)this)->fC4 = 0x200;
        }
        ((Obj_802C1428 *)this)->fC0 += ((Obj_802C1428 *)this)->fC4;
        if (((Obj_802C1428 *)this)->fC0 > 0x2000) {
            ((Obj_802C1428 *)this)->fC0 = 0x2000;
        }
    } else {
        ((Obj_802C1428 *)this)->fC4 = 0;
        if (((Obj_802C1428 *)this)->fC0 > 0x100) {
            ((Obj_802C1428 *)this)->fC0 -= 0x100;
        } else if (((Obj_802C1428 *)this)->fC0 < -0x100) {
            ((Obj_802C1428 *)this)->fC0 += 0x100;
        } else {
            ((Obj_802C1428 *)this)->fC0 = 0;
        }
    }
    return r;
}

void TObjJungleKamome::load_static_resource() {
    saddr temp_r3;
    s32 var_r0;
    var_r0 = (saddr)new BmlResource(5, &bm_obj_jungle_kamome_resource_descriptor, 0, 0, NULL);
    (*(saddr *)&lobby_kamome_model_resource) = var_r0;
    lobby_kamome_texture_gvm_handle = load_gvm_texture_file("obj_jungle_kamome.gvm");
}

void TObjJungleKamome::destroy_instance() {
    if (lobby_kamome_texture_gvm_handle != NULL) {
        release_texture_list(lobby_kamome_texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)lobby_kamome_texture_gvm_handle);
        lobby_kamome_texture_gvm_handle = NULL;
    }
    if ((u32) lobby_kamome_model_resource != 0U) {
        delete (BmlResource *)lobby_kamome_model_resource;
        lobby_kamome_model_resource = 0U;
    }
}

void *TObjJungleKamome::create(void *set_data) {
    return new TObjJungleKamome(tl_05, set_data);
}

TObjLobbyPigeon::TObjLobbyPigeon(TObject *parent, void *set_data) : TObjPathObj(parent, set_data) {
    LobbyPigeon *self = (LobbyPigeon *)this;
    s32 movement;
    s32 selector;
    select_lobby_pigeon_model();
    self->scale = (1.0f);
    self->model = ((void*)get_bml_model((BmlResource *)lobby_pigeon_bml_archive, (s32)(self->modelIndex)));
    self->animation = ((void*)get_bml_motion(lobby_pigeon_bml_archive, 0));
    selector = self->movementSelector;
    if (selector < 0) movement = 0;
    else {
        movement = 2;
        if (selector <= 2) movement = selector;
    }
    self->movement = movement;
    self->path = ((void*)get_bml_motion(lobby_pigeon_bml_archive, (s32)(((PigeonMovement *)&lobby_pigeon_path_profiles)[self->movement].motion)));
    self->pathFrame = (0.0f);
    self->animationFrame = (0.0f);
    initialize_lobby_pigeon_path();
    self->viewDistance = (1e+03f);
    self->randomDelay =
        (s32)((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32)rand())) +
              (1.5e+02f));
}
#pragma pop

TObjLobbyPigeon::~TObjLobbyPigeon() {}

void TObjLobbyPigeon::update_lobby_pigeon_visibility() {
  switch (((LobbyPigeon *)this)->phase) {
  case 0:
    if (((LobbyPigeon *)this)->theme == ((s32 (*)(LobbyPigeon *))filter_lobby_pigeon_theme)(((LobbyPigeon *)this))) {
      ((LobbyPigeon *)this)->phase = 2;
    }
    break;
  case 2: {
    f32 lim = 1.0f;
    ((LobbyPigeon *)this)->scale += 0.1f;
    if (((LobbyPigeon *)this)->scale >= lim) {
      ((LobbyPigeon *)this)->scale = lim;
      ((LobbyPigeon *)this)->phase = 3;
    }
  } break;
  case 1: {
    f32 lim = 0.0f;
    ((LobbyPigeon *)this)->scale -= 0.1f;
    if (((LobbyPigeon *)this)->scale <= lim) {
      ((LobbyPigeon *)this)->scale = lim;
      ((LobbyPigeon *)this)->phase = 0;
    }
  } break;
  case 3:
  default:
    if (((LobbyPigeon *)this)->theme != ((s32 (*)(LobbyPigeon *))filter_lobby_pigeon_theme)(((LobbyPigeon *)this))) {
      ((LobbyPigeon *)this)->phase = 1;
    }
    break;
  }
}

#pragma push
#pragma fp_contract on
void TObjLobbyPigeon::vfunc_13() {
    Obj_802C0F3C *self = (Obj_802C0F3C *)this;
  ((TObjLobbyPigeon *)self)->update_lobby_pigeon_visibility();
  self->b4 += lobby_pigeon_path_profiles[self->d8].pa;
  if (((TObjLobbyPigeon *)self)->advance_lobby_pigeon_path() == 0) {
    self->b4 = (0.0f);
  }
  self->b8 += lobby_pigeon_path_profiles[self->d8].pb;
  if (self->b8 > (f32)(u32)(self->ac->n - 1)) {
    self->b8 = (0.0f);
  }
  if (--self->dc < 0) {
    Mtx_802C0F3C m;
    Vec v = lobby_pigeon_zero_vec;
    set_matrix_identity((u8 *)&m);
    translate_matrix_vec3((u8 *)&m, (u8 *)&self->pos);
    ((void (*)(void *, s32))rotate_matrix_y)(&m, self->f60);
    translate_matrix_vec3((u8 *)&m, (u8 *)&self->bc);
    matrix_mult_vec(&m, &v, &v);
    self->dc =
        (s32)((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32)rand())) +
              (1.5e+02f));
  }
}

void TObjLobbyPigeon::vfunc_14() {
    LobbyPigeon *self = (LobbyPigeon *)this;
  if (TObjPlayer::check_demo_mode() == 1 &&
      TMainTask::get_render_pass() == 0)
    draw_line_strip__10TObjPlayerFPviif((u8 *)(self), (saddr)(self->model),
                                        (saddr)(self->path), (1.0f));
  if (self->phase == 0 || lobby_pigeon_lobby_type == NULL)
    return;
  TObjFish::set_global_param(lobby_pigeon_lobby_type);
  push_matrix();
  post_translate_matrix((void *)(self->position));
  rotate_matrix_y(0, (s32)(self->facing));
  post_translate_matrix((void *)(self->pathPosition));
  rotate_matrix_y(0, (s32)(self->pathYaw));
  rotate_matrix_z(0, (s32)(self->pathRoll));
  if (self->phase != 3)
    scale_matrix(0, self->scale, self->scale, self->scale);
  draw_model_motion((self->model), (self->animation), self->animationFrame);
  pop_matrix();
}
#pragma pop

void TObjLobbyPigeon::select_lobby_pigeon_model() {
    s32 temp_r3;

    if ((s32) this->set_params[2] < 1) {
        this->m_a0 = 0;
    } else {
        this->m_a0 = 1;
    }
    temp_r3 = this->set_params[1];
    if (temp_r3 < 1) {
        *(s32 *)((s8 *)this + 0xA4) = 0;
    } else if ((s32) this->m_a0 == 0) {
        if (temp_r3 > 1) {
            *(s32 *)((s8 *)this + 0xA4) = 3;
        } else {
            *(s32 *)((s8 *)this + 0xA4) = 0xA;
        }
    } else {
        *(s32 *)((s8 *)this + 0xA4) = 5;
    }
    if ((s32) *(s32 *)((s8 *)this + 0xA4) == filter_lobby_pigeon_theme(this)) {
        *(s32 *)((s8 *)this + 0x98) = 3;
        return;
    }
    *(s32 *)((s8 *)this + 0x98) = 0;
}

s32 TObjLobbyPigeon::initialize_lobby_pigeon_path() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 r;
    Obj_802C0CAC *self = (Obj_802C0CAC *)this;
    this->m_c8 = 0;
    self->fBC = 0;
    this->m_d0 = 0;
    self->fC4 = 0;
    ((s32 (*)(void *, s32, s32, Vec *, f32))sample_clamped_path_position)(self, this->m_a8, this->m_b0, &a, (0.0f));
    VecCopy((Vec *)&self->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec *, f32))sample_clamped_path_position)(self, this->m_a8, this->m_b0, &b, lobby_pigeon_path_profiles[this->m_d8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &self->fBC, &tmp);
    this->m_c8 = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

s32 TObjLobbyPigeon::advance_lobby_pigeon_path() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 tmp2;
    s32 r;
    s32 old;
    s32 diff;
    ((s32 (*)(void *, s32, s32, Vec *, f32))sample_clamped_path_position)(((Obj_802C0A74 *)this), ((Obj_802C0A74 *)this)->f98, ((Obj_802C0A74 *)this)->fA0, &a, ((Obj_802C0A74 *)this)->fA4);
    VecCopy((Vec *)&((Obj_802C0A74 *)this)->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec *, f32))sample_clamped_path_position)(((Obj_802C0A74 *)this), ((Obj_802C0A74 *)this)->f98, ((Obj_802C0A74 *)this)->fA0, &b, ((Obj_802C0A74 *)this)->fA4 + lobby_pigeon_path_profiles[((Obj_802C0A74 *)this)->fC8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &tmp, &tmp2);
    ((Obj_802C0A74 *)this)->fBC = approach_angle_limited(((Obj_802C0A74 *)this)->fBC, tmp, lobby_pigeon_path_profiles[((Obj_802C0A74 *)this)->fC8].e);
    old = ((Obj_802C0A74 *)this)->fB8;
    tmp = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    ((Obj_802C0A74 *)this)->fB8 = approach_angle_limited(old, tmp, lobby_pigeon_path_profiles[((Obj_802C0A74 *)this)->fC8].e);
    diff = angle_diff_s16(old, tmp);
    if (diff > 0x30) {
        if (((Obj_802C0A74 *)this)->fC4 > 0) {
            ((Obj_802C0A74 *)this)->fC4 = 0;
        }
        ((Obj_802C0A74 *)this)->fC4 -= 0x40;
        if (((Obj_802C0A74 *)this)->fC4 < -0x200) {
            ((Obj_802C0A74 *)this)->fC4 = -0x200;
        }
        ((Obj_802C0A74 *)this)->fC0 += ((Obj_802C0A74 *)this)->fC4;
        if (((Obj_802C0A74 *)this)->fC0 < -0x2000) {
            ((Obj_802C0A74 *)this)->fC0 = -0x2000;
        }
    } else if (diff < -0x30) {
        if (((Obj_802C0A74 *)this)->fC4 < 0) {
            ((Obj_802C0A74 *)this)->fC4 = 0;
        }
        ((Obj_802C0A74 *)this)->fC4 += 0x40;
        if (((Obj_802C0A74 *)this)->fC4 > 0x200) {
            ((Obj_802C0A74 *)this)->fC4 = 0x200;
        }
        ((Obj_802C0A74 *)this)->fC0 += ((Obj_802C0A74 *)this)->fC4;
        if (((Obj_802C0A74 *)this)->fC0 > 0x2000) {
            ((Obj_802C0A74 *)this)->fC0 = 0x2000;
        }
    } else {
        ((Obj_802C0A74 *)this)->fC4 = 0;
        if (((Obj_802C0A74 *)this)->fC0 > 0x100) {
            ((Obj_802C0A74 *)this)->fC0 -= 0x100;
        } else if (((Obj_802C0A74 *)this)->fC0 < -0x100) {
            ((Obj_802C0A74 *)this)->fC0 += 0x100;
        } else {
            ((Obj_802C0A74 *)this)->fC0 = 0;
        }
    }
    return r;
}

// The callers pass the pigeon; the theme does not depend on it.
s32 filter_lobby_pigeon_theme(void *) {
    s32 filtered_event_theme;

    filtered_event_theme = TLobby::get_filtered_event_theme();
    switch (filtered_event_theme) {
    case 3:
    case 9:
        filtered_event_theme = 3;
        break;
    }
    return filtered_event_theme;
}

void TObjLobbyPigeon::load_static_resource() {
    saddr temp_r3;
    lobby_pigeon_bml_archive = new BmlResource(5, &bm_obj_lobby_pigeon_resource_descriptor, 0, 0, NULL);
    lobby_pigeon_lobby_type = TLobby::get_lobby_texlist();
}

void TObjLobbyPigeon::destroy_instance() {
    if (lobby_pigeon_bml_archive != NULL) {
        delete (BmlResource *)lobby_pigeon_bml_archive;
        lobby_pigeon_bml_archive = NULL;
    }
}

void *TObjLobbyPigeon::create(void *set_data) {
    return new TObjLobbyPigeon(tl_05, set_data);
}
