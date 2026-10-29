#pragma push

#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjPathObj.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TUnk_804E0988.h"
#include "pso/object/TUnk_804E094C.h"
#include "pso/object/TUnk_804E0910.h"
#include "pso/object/TUnk_804E08D4.h"
#include "pso/object/TUnk_804E0898.h"
struct Vec_802C0CAC { f32 x, y, z; };

struct Entry_802C0CAC { s32 a; union { s32 b; f32 pa; }; union { s32 c; f32 pb; }; f32 d; s32 e; };

struct Obj_802C0CAC {
    u8 pad0[0xA8];
    s32 f98;
    s32 f9C;
    s32 fA0;
    u8 padA4[0x8];
    Vec_802C0CAC vAC;
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
    Vec_802C0CAC vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

extern "C" {
f64 atan2_float(f32, f32);
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
s32 sample_clamped_path_position(void *arg0, s32 arg1, void *arg2, s32 arg3, f32 farg0);
extern "C" {
f32 subtract_vector(Vec_802C0CAC *, Vec_802C0CAC *);
extern Entry_802C0CAC lobby_pigeon_path_profiles[];
extern const f64 lbl_80471960[];

s32 approach_angle_limited(s32, s32, s32);
s32 angle_diff_s16(s32, s32);

s32 TUnk_804E0898::advance_lobby_pigeon_path() {
    Vec_802C0CAC a;
    Vec_802C0CAC b;
    Vec_802C0CAC d;
    s32 tmp;
    s32 tmp2;
    s32 r;
    s32 old;
    s32 diff;
    ((s32 (*)(void *, s32, s32, Vec_802C0CAC *, f32))sample_clamped_path_position)(((Obj_802C0A74 *)this), ((Obj_802C0A74 *)this)->f98, ((Obj_802C0A74 *)this)->fA0, &a, ((Obj_802C0A74 *)this)->fA4);
    VecCopy((Vec *)&((Obj_802C0A74 *)this)->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec_802C0CAC *, f32))sample_clamped_path_position)(((Obj_802C0A74 *)this), ((Obj_802C0A74 *)this)->f98, ((Obj_802C0A74 *)this)->fA0, &b, ((Obj_802C0A74 *)this)->fA4 + lobby_pigeon_path_profiles[((Obj_802C0A74 *)this)->fC8].d);
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

s32 TUnk_804E0898::initialize_lobby_pigeon_path() {
    Vec_802C0CAC a;
    Vec_802C0CAC b;
    Vec_802C0CAC d;
    s32 tmp;
    s32 r;
    Obj_802C0CAC *self = (Obj_802C0CAC *)this;
    this->m_c8 = 0;
    self->fBC = 0;
    this->m_d0 = 0;
    self->fC4 = 0;
    ((s32 (*)(void *, s32, s32, Vec_802C0CAC *, f32))sample_clamped_path_position)(self, this->m_a8, this->m_b0, &a, (0.0f));
    VecCopy((Vec *)&self->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec_802C0CAC *, f32))sample_clamped_path_position)(self, this->m_a8, this->m_b0, &b, lobby_pigeon_path_profiles[this->m_d8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &self->fBC, &tmp);
    this->m_c8 = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

#pragma pop

#pragma push
s32 filter_lobby_pigeon_theme(void *);

void TUnk_804E0898::select_lobby_pigeon_model() {
    s32 temp_r3;

    if ((s32) this->set_params[2] < 1) {
        this->m_a0 = 0;
    } else {
        this->m_a0 = 1;
    }
    temp_r3 = *(s32 *)&this->set_params[1];
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
}

#pragma pop

#pragma push

#include "pso/object/LobbyPigeon.h"

struct Vec_802C22A4 { f32 x, y, z; };

struct Hit_802C22A4 { u8 pad0[4]; Vec_802C22A4 *n; };

struct Obj_802C22A4 {
    u8 pad0[0x1E]; s16 f1E; u8 pad20[0x38 - 0x20]; Vec_802C22A4 pos;
    u8 pad44[0x98 - 0x44];
    s32 f98; s32 f9C; s32 fA0; f32 fA4; u8 padA8[0x4];
    Vec_802C22A4 vAC; s32 fB8; s32 fBC; s32 fC0; s32 fC4; s32 fC8;
};

struct PigeonMovement { s32 motion; f32 pathSpeed, animationSpeed, lookAhead; s32 turnStep; };

extern "C" {
Hit_802C22A4 *csnVecterUnder(Vec_802C22A4 *, s32);
void vec3_add_to(void *, void *);
u8 *TObjPathObj__ct(u8 *arg0, s32 arg1, s32 arg2);

s32 get_bml_model(void *, s32);
s32 get_bml_motion(void *, s32);

s32 rand();
extern s32 lobby_pigeon_vtable[];
extern void* lobby_pigeon_bml_archive;
LobbyPigeon* construct_lobby_pigeon(LobbyPigeon* self, void* parent, const void* source);

void draw_line_strip__10TObjPlayerFPviif(u8 *arg0, s32 arg1, s32 arg2, f32 farg0);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
s32 rotate_matrix_z(s32, s32);
void scale_matrix(void *, f32, f32, f32);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern void *lobby_pigeon_lobby_type;
struct RecoveredGlobal_8019A9B8_lbl_80446184 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8019A9B8_lbl_804B8F60 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8019A880_lbl_804B8F70 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8019A880___vt__8TObjTank {
    s32 value;
    u8 remaining[0x38];
};

struct Vec_802C1660 { f32 x, y, z; };

struct Entry_802C1660 { s32 a; f32 b; f32 c; f32 d; s32 e; };

struct Obj_802C1660 {
    u8 pad0[0x98];
    s32 f98;
    s32 f9C;
    s32 fA0;
    u8 padA4[0x8];
    Vec_802C1660 vAC;
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
    Vec_802C1660 vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

typedef char RecoveredGlobal_8019A880_lbl_804B8F70_size[sizeof(RecoveredGlobal_8019A880_lbl_804B8F70) == 0x2C ? 1 : -1];

typedef char RecoveredGlobal_8019A880___vt__8TObjTank_size[sizeof(RecoveredGlobal_8019A880___vt__8TObjTank) == 0x3C ? 1 : -1];

typedef char RecoveredGlobal_8019A9B8_lbl_80446184_size[sizeof(RecoveredGlobal_8019A9B8_lbl_80446184) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_8019A9B8_lbl_804B8F60_size[sizeof(RecoveredGlobal_8019A9B8_lbl_804B8F60) == 0x10 ? 1 : -1];

struct RecoveredGlobal_802C1B9C_lbl_80471990 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_802C1B9C_lbl_804E081C {
    s32 value;
    u8 remaining[0xC];
};

struct Vec_802C1E34 { f32 x, y, z; };

struct Entry_802C1E34 { s32 a; f32 b; f32 c; f32 d; s32 e; };

struct Obj_802C1E34 {
    u8 pad0[0x98];
    s32 f98;
    s32 f9C;
    s32 fA0;
    u8 padA4[0x8];
    Vec_802C1E34 vAC;
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
    Vec_802C1E34 vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

typedef char RecoveredGlobal_802C1B9C_lbl_80471990_size[sizeof(RecoveredGlobal_802C1B9C_lbl_80471990) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_802C1B9C_lbl_804E081C_size[sizeof(RecoveredGlobal_802C1B9C_lbl_804E081C) == 0x10 ? 1 : -1];

struct RecoveredGlobal_802C20E8_lbl_80471890
{
  s32 value;
  u8 remaining[0x38];
};

struct RecoveredGlobal_802C20E8_lbl_804E0910
{
  s32 value;
  u8 remaining[0x38];
};

typedef struct RecoveredGlobal_802C20E8_lbl_80471890 RecoveredGlobal_802C20E8_lbl_80471890;

typedef struct RecoveredGlobal_802C20E8_lbl_804E0910 RecoveredGlobal_802C20E8_lbl_804E0910;

struct Vec_802C2548 { f32 x, y, z; };

struct Entry_802C2548 { s32 a; f32 b; f32 c; f32 d; s32 e; s32 f; };

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
    Vec_802C2548 vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

struct RecoveredGlobal_802C27FC_lbl_80471848
{
  s32 value;
  u8 remaining[0x44];
};

struct RecoveredGlobal_802C27FC_lbl_804E094C
{
  s32 value;
  u8 remaining[0x38];
};

typedef struct RecoveredGlobal_802C27FC_lbl_80471848 RecoveredGlobal_802C27FC_lbl_80471848;

typedef struct RecoveredGlobal_802C27FC_lbl_804E094C RecoveredGlobal_802C27FC_lbl_804E094C;

struct Q_802C2958 { s32 a; s32 b; s32 c; s32 d; };

struct Obj_802C2958 { u8 pad[0x430]; s32 f430; };

struct Vec_802C2C48 { f32 x, y, z; };

struct Entry_802C2C48 { s32 a; f32 b; f32 c; f32 d; s32 e; };

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
    Vec_802C2C48 vAC;
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
    Vec_802C2C48 vAC;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
};

struct RecoveredGlobal_802C2F04_lbl_804717D4
{
  s32 value;
  u8 remaining[0x60];
};

struct RecoveredGlobal_802C2F04_lbl_804E0988
{
  s32 value;
  u8 remaining[0x38];
};

typedef struct RecoveredGlobal_802C2F04_lbl_804717D4 RecoveredGlobal_802C2F04_lbl_804717D4;

typedef struct RecoveredGlobal_802C2F04_lbl_804E0988 RecoveredGlobal_802C2F04_lbl_804E0988;

struct Vec_802C0F3C { f32 x, y, z; };

struct Mtx_802C0F3C { f32 m[3][4]; };

typedef Entry_802C0CAC Ent_802C0F3C;

struct Cnt_802C0F3C { s32 f0; s32 n; };

struct Obj_802C0F3C {
    u8 pad0[0x38];
    Vec_802C0F3C pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0xAC - 0x64];
    Cnt_802C0F3C *ac;
    u8 padb0[4];
    f32 b4;
    f32 b8;
    Vec_802C0F3C bc;
    u8 padc8[0xD8 - 0xC8];
    s32 d8;
    s32 dc;
};

typedef struct { f32 x, y, z; } Vec_802C17FC;

typedef struct { f32 m[3][4]; } Mtx_802C17FC;

typedef struct { f32 f0, f4, f8, fC; s32 f10; } Ent_802C17FC;

typedef struct { u8 pad[4]; u32 n; } Anim_802C17FC;

void TLobby__sub_8001FE7C(void*, int);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 debug_draw_line(s32 *, s32 *, s32, s32);

u8 * load_gvm_texture_file(s32);
s32 play_sound_effect(int, void *, int, int);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);

void *__dt__13TUnk_804E0898Fv(void *arg0, s16 arg1);
void * TObjPlayer__sub_802C19E8(void *arg0);
void * create__10TObjPlayerFPv(void *arg0);
s32 sub_802C1BFC__13TUnk_804E0910Fv(Obj_802C1BFC *self);
u8 *TObjPlayer__sub_802C20E8(u8 *arg0, s32 arg1, const void* _w2);
void * __dt__13TUnk_804E094CFv(void *arg0, s16 arg1);
u8 *TObjPlayer__sub_802C27FC(u8 *arg0, s32 arg1, const void* _w2);
void * TObjPlayer__sub_802C28B4(void *arg0);
void TObjPlayer__sub_802C2900(void);
void * __dt__13TUnk_804E0988Fv(void *arg0, s16 arg1);
u8 *TObjPlayer__sub_802C2F04(u8 *arg0, s32 arg1, const void* _w2);
void *__dt__11TObjPathObjFv(void *arg0, s16 arg1);
void bind_motion_context(s32 arg0, f32 farg0);
void matrix_mult_vec(void *, void *, void *);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
void set_matrix_identity(u8 *arg0);

s32 release_texture_list(void*);

extern Entry_802C2C48 seabed_dolphin_path_profiles[];
extern u8 seabed_dolphin_anim_binding[];
extern Entry_802C2548 jungle_ebi_path_profiles[];
extern Entry_802C1E34 lobby_pigeon_path_parameters[];
extern Entry_802C1660 jungle_seagull_path_profiles[];
extern Vec_802C17FC lbl_80471908;
extern Ent_802C0F3C lobby_pigeon_path_profiles[];
extern Vec_802C0F3C lobby_pigeon_zero_vec;
extern RecoveredGlobal_8019A9B8_lbl_80446184 lbl_80471978;
extern RecoveredGlobal_802C1B9C_lbl_80471990 lbl_80471990;
extern RecoveredGlobal_8019A9B8_lbl_80446184 lbl_804719A4;
extern u8 lbl_804719B8[];
extern u8 bm_obj_seabed_dolphin_resource_descriptor[];
extern RecoveredGlobal_8019A9B8_lbl_804B8F60 bm_obj_jungle_ebi_resource_descriptor;
extern RecoveredGlobal_802C1B9C_lbl_804E081C bm_obj_jungle_bird_resource_descriptor;
extern RecoveredGlobal_8019A9B8_lbl_804B8F60 bm_obj_jungle_kamome_resource_descriptor;
extern s32 jungle_seagull_vtable[];
extern s32 lbl_804E0910[];
extern s32 lbl_804E094C[];
extern s32 seabed_dolphin_vtable[];
extern u32 seabed_dolphin_bml_archive;
extern s32 seabed_dolphin_texture_handle;
extern u32 jungle_ebi_model_resource;
extern u32 jungle_ebi_texture_gvm_handle;
extern u32 jungle_bird_bml_resource;
extern u32 lobby_pigeon_texture_gvm;
extern u32 lobby_kamome_model_resource;
extern u32 lobby_kamome_texture_gvm_handle;

#pragma push
#pragma fp_contract on
void TUnk_804E0898::vfunc_14() {
    LobbyPigeon *self = (LobbyPigeon *)this;
  if (TObjPlayer::check_demo_mode() == 1 &&
      TMainTask::get_render_pass() == 0)
    draw_line_strip__10TObjPlayerFPviif((u8 *)(self), (s32)(self->model),
                                        (s32)(self->path), (1.0f));
  if (self->phase == 0 || lobby_pigeon_lobby_type == 0)
    return;
  TObjFish::set_global_param((s32)(lobby_pigeon_lobby_type));
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

void TUnk_804E0898::vfunc_13(s32) {
    Obj_802C0F3C *self = (Obj_802C0F3C *)this;
  ((TUnk_804E0898 *)self)->update_lobby_pigeon_visibility();
  self->b4 += lobby_pigeon_path_profiles[self->d8].pa;
  if (((TUnk_804E0898 *)self)->advance_lobby_pigeon_path() == 0) {
    self->b4 = (0.0f);
  }
  self->b8 += lobby_pigeon_path_profiles[self->d8].pb;
  if (self->b8 > (f32)(u32)(self->ac->n - 1)) {
    self->b8 = (0.0f);
  }
  if (--self->dc < 0) {
    Mtx_802C0F3C m;
    Vec_802C0F3C v = lobby_pigeon_zero_vec;
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
#pragma pop

void TUnk_804E0898::update_lobby_pigeon_visibility() {
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

void *__dt__13TUnk_804E0898Fv(void *arg0, s16 arg1) {
  if (arg0 != NULL) {
    *(s32 **)((s8 *)arg0 + 0x18) = lobby_pigeon_vtable;
    ((void (*)(void *, int))__dt__11TObjPathObjFv)(arg0, 0);
    if (arg1 > 0) {
      __dl__7TObjectFPv(arg0);
    }
  }
  return arg0;
}

#pragma fp_contract on
LobbyPigeon* construct_lobby_pigeon(LobbyPigeon* self, void* parent, const void* source) {
    s32 movement;
    s32 selector;
    ((u8 * (*)(LobbyPigeon*, void*, const void*))TObjPathObj__ct)((LobbyPigeon*)(self), (void*)(parent), (const void*)(source));
    self->vtable = ((void* *)&lobby_pigeon_vtable);
    ((TUnk_804E0898 *)self)->select_lobby_pigeon_model();
    self->scale = (1.0f);
    self->model = ((void*)get_bml_model((void *)(lobby_pigeon_bml_archive), (s32)(self->modelIndex)));
    self->animation = ((void*)get_bml_motion((void *)(lobby_pigeon_bml_archive), 0));
    selector = self->movementSelector;
    if (selector < 0) movement = 0;
    else {
        movement = 2;
        if (selector <= 2) movement = selector;
    }
    self->movement = movement;
    self->path = ((void*)get_bml_motion((void *)(lobby_pigeon_bml_archive), (s32)(((PigeonMovement *)&lobby_pigeon_path_profiles)[self->movement].motion)));
    self->pathFrame = (0.0f);
    self->animationFrame = (0.0f);
    ((TUnk_804E0898 *)self)->initialize_lobby_pigeon_path();
    self->viewDistance = (1e+03f);
    self->randomDelay =
        (s32)((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32)rand())) +
              (1.5e+02f));
    return self;
}

void *TObjPlayer::create_child_object(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD0);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *))TObjPlayer__sub_802C19E8)(o, tl_05, arg0);
    }
    return o;
}

void TObjPlayer::destroy_instance() {
    if ((u32) lobby_kamome_texture_gvm_handle != 0U) {
        release_texture_list((void*)lobby_kamome_texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(lobby_kamome_texture_gvm_handle);
        lobby_kamome_texture_gvm_handle = 0U;
    }
    if ((u32) lobby_kamome_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)lobby_kamome_model_resource, 1);
        lobby_kamome_model_resource = 0U;
    }
}

void TObjPlayer::load_kamome_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &bm_obj_jungle_kamome_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&lobby_kamome_model_resource) = var_r0;
    (*(u8 * *)&lobby_kamome_texture_gvm_handle) = load_gvm_texture_file((s32) &lbl_80471978.value);
}

s32 TUnk_804E08D4::update_path_steering() {
    Vec_802C1660 a;
    Vec_802C1660 b;
    Vec_802C1660 d;
    s32 tmp;
    s32 tmp2;
    s32 r;
    s32 old;
    s32 diff;
    ((s32 (*)(void *, s32, s32, Vec_802C1660 *,
              f32))sample_clamped_path_position)(((Obj_802C1428 *)this), ((Obj_802C1428 *)this)->f98, ((Obj_802C1428 *)this)->fA0, &a,
                                                 ((Obj_802C1428 *)this)->fA4);
    VecCopy((Vec *)(&((Obj_802C1428 *)this)->vAC), (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec_802C1660 *,
                  f32))sample_clamped_path_position)(
        ((Obj_802C1428 *)this), ((Obj_802C1428 *)this)->f98, ((Obj_802C1428 *)this)->fA0, &b, ((Obj_802C1428 *)this)->fA4 + jungle_seagull_path_profiles[((Obj_802C1428 *)this)->fC8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    ((f32 (*)(Vec_802C1660 *, Vec_802C1660 *))subtract_vector)(&d, &a);
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

s32 TUnk_804E08D4::sub_802C1660() {
    Vec_802C1660 a;
    Vec_802C1660 b;
    Vec_802C1660 d;
    s32 tmp;
    s32 r;
    Obj_802C1660 *self = (Obj_802C1660 *)this;
    this->m_b8 = 0;
    self->fBC = 0;
    this->m_c0 = 0;
    self->fC4 = 0;
    ((s32 (*)(void *, s32, s32, Vec_802C1660 *,
              f32))sample_clamped_path_position)(self, self->f98, self->fA0, &a,
                                                 (0.0f));
    VecCopy((Vec *)&self->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec_802C1660 *,
                  f32))sample_clamped_path_position)(
        self, self->f98, self->fA0, &b, jungle_seagull_path_profiles[this->m_c8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    ((f32 (*)(Vec_802C1660 *, Vec_802C1660 *))subtract_vector)(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &self->fBC, &tmp);
    this->m_b8 = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

void TUnk_804E08D4::vfunc_14() {
    u8 *arg0 = (u8 *)this;
    if ((TObjPlayer::check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        ((s32 (*)(void *, s32, s32, f32))draw_line_strip__10TObjPlayerFPviif)(arg0, *(s32 *)&this->unk_98, *(s32 *)((s8 *)arg0 + 0xA0), (1.0f));
    }
    TObjFish::set_global_param((*(s32 *)&lobby_kamome_texture_gvm_handle));
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix((u8 *)&this->unk_AC);
    rotate_matrix_y(0, this->m_b8);
    rotate_matrix_z(0, this->m_c0);
    draw_model_motion((void *)(*(s32 *)&this->unk_98), (void *)this->m_9c, this->m_a8);
    pop_matrix();
}

#pragma push
#pragma fp_contract on
void TUnk_804E08D4::vfunc_13(s32) {
    u8 *arg0 = (u8 *)this;
    Mtx_802C17FC m;
    s32 temp_r0;

    this->m_a4 += jungle_seagull_path_profiles[this->m_c8].b;
    if (((TUnk_804E08D4 *)arg0)->update_path_steering() == 0) {
        this->m_a4 = (0.0f);
    }
    this->m_a8 += jungle_seagull_path_profiles[this->m_c8].c;
    if (this->m_a8 > (f32) ((*(Anim_802C17FC * *)&this->m_9c)->n - 1)) {
        this->m_a8 = (0.0f);
    }
    temp_r0 = *(s32 *)&this->unk_CC - 1;
    *(s32 *)&this->unk_CC = temp_r0;
    if (temp_r0 < 0) {
        Vec_802C17FC v = lbl_80471908;
        set_matrix_identity((u8 *)&m);
        translate_matrix_vec3((u8 *)&m, (u8 *)&this->position);
        ((s32 (*)(void *, int))rotate_matrix_y)(&m, this->rotation_y);
        translate_matrix_vec3((u8 *)&m, (u8 *)&this->unk_AC);
        ((s32 (*)(void *, void *, void *))matrix_mult_vec)(&m, &v, &v);
        play_sound_effect(0x4BC04, (u8 *)&this->position, 0x7F, 0);
        *(s32 *)&this->unk_CC = (s32) (((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32) rand()))) + (1.5e+02f));
    }
}
#pragma pop

void *TUnk_804E08D4::dt_path_obj(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = jungle_seagull_vtable;
        ((void (*)(void *, int))__dt__11TObjPathObjFv)(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

#pragma push
#pragma fp_contract on
void *TObjPlayer__sub_802C19E8(void *arg0) {
    s32 temp_r3;
    s32 var_r0;

    ((s32 (*)(void))TObjPathObj__ct)();
    *(s32 **)((s8 *)arg0 + 0x18) = jungle_seagull_vtable;
    *(s32 *)((s8 *)arg0 + 0x98) = ((s32 (*)(s32, s32))get_bml_model)((*(s32 *)&lobby_kamome_model_resource), 0);
    ((TUnk_804E08D4 *)arg0)->m_9c = ((s32 (*)(s32, s32))get_bml_motion)((*(s32 *)&lobby_kamome_model_resource), 0);
    temp_r3 = ((TUnk_804E08D4 *)arg0)->set_params[0];
    var_r0 = (temp_r3 < 0) ? 0 : (temp_r3 > 2) ? 2 : temp_r3;
    ((TUnk_804E08D4 *)arg0)->m_c8 = var_r0;
    *(s32 *)((s8 *)arg0 + 0xA0) = ((s32 (*)(s32, s32))get_bml_motion)((*(s32 *)&lobby_kamome_model_resource), *(s32 *)((s8 *)((s32 *)&jungle_seagull_path_profiles) + (((TUnk_804E08D4 *)arg0)->m_c8 * 0x14)));
    ((TUnk_804E08D4 *)arg0)->m_a4 = (f32) (0.0f);
    ((TUnk_804E08D4 *)arg0)->m_a8 = (f32) (0.0f);
    ((TUnk_804E08D4 *)arg0)->sub_802C1660();
    *(f32 *)((s8 *)arg0 + 0x90) = (f32) (1e+03f);
    *(s32 *)((s8 *)arg0 + 0xCC) = (s32) (((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32) rand()))) + (1.5e+02f));
    return arg0;
}
#pragma pop

void *create__10TObjPlayerFPv(void *arg0) {
    void *o = __nw__7TObjectFUl(0xCC);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *))TObjPlayer__sub_802C20E8)(o, tl_05, arg0);
    }
    return o;
}

void TObjPlayer::free_statics() {
    if ((u32) lobby_pigeon_texture_gvm != 0U) {
        release_texture_list((void*)lobby_pigeon_texture_gvm);
        TAdSinglePlyChrSelectGC::safe_free(lobby_pigeon_texture_gvm);
        lobby_pigeon_texture_gvm = 0U;
    }
    if ((u32) jungle_bird_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)jungle_bird_bml_resource, 1);
        jungle_bird_bml_resource = 0U;
    }
}

void TObjPlayer::load_jungle_bird_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &bm_obj_jungle_bird_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&jungle_bird_bml_resource) = var_r0;
    (*(u8 * *)&lobby_pigeon_texture_gvm) = load_gvm_texture_file((s32) &lbl_80471990.value);
}

s32 TUnk_804E0910::sub_802C1BFC() {
    Vec_802C1E34 a;
    Vec_802C1E34 b;
    Vec_802C1E34 d;
    s32 tmp;
    s32 tmp2;
    s32 r;
    s32 old;
    s32 diff;
    ((s32 (*)(void *, s32, s32, Vec_802C1E34 *,
              f32))sample_clamped_path_position)(((Obj_802C1BFC *)this), ((Obj_802C1BFC *)this)->f98, ((Obj_802C1BFC *)this)->fA0, &a,
                                                 ((Obj_802C1BFC *)this)->fA4);
    VecCopy((Vec *)&((Obj_802C1BFC *)this)->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec_802C1E34 *,
                  f32))sample_clamped_path_position)(
        ((Obj_802C1BFC *)this), ((Obj_802C1BFC *)this)->f98, ((Obj_802C1BFC *)this)->fA0, &b, ((Obj_802C1BFC *)this)->fA4 + lobby_pigeon_path_parameters[((Obj_802C1BFC *)this)->fC8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    ((f32 (*)(Vec_802C1E34 *, Vec_802C1E34 *))subtract_vector)(&d, &a);
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

s32 TUnk_804E0910::sub_802C1E34() {
    Vec_802C1E34 a;
    Vec_802C1E34 b;
    Vec_802C1E34 d;
    s32 tmp;
    s32 r;
    Obj_802C1E34 *self = (Obj_802C1E34 *)this;
    this->m_b8 = 0;
    self->fBC = 0;
    this->m_c0 = 0;
    self->fC4 = 0;
    ((s32 (*)(void *, s32, s32, Vec_802C1E34 *,
              f32))sample_clamped_path_position)(self, self->f98, self->fA0, &a,
                                                 (0.0f));
    VecCopy((Vec *)&self->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec_802C1E34 *,
                  f32))sample_clamped_path_position)(
        self, self->f98, self->fA0, &b, lobby_pigeon_path_parameters[this->m_c8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    ((f32 (*)(Vec_802C1E34 *, Vec_802C1E34 *))subtract_vector)(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &self->fBC, &tmp);
    this->m_b8 = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

void TUnk_804E0910::vfunc_14() {
    u8 *arg0 = (u8 *)this;
    if ((TObjPlayer::check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        ((s32 (*)(void *, s32, s32, f32))draw_line_strip__10TObjPlayerFPviif)(arg0, *(s32 *)&this->unk_98, *(s32 *)((s8 *)arg0 + 0xA0), (1.0f));
    }
    TObjFish::set_global_param((*(s32 *)&lobby_pigeon_texture_gvm));
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix((u8 *)&this->unk_AC);
    rotate_matrix_y(0, this->m_b8);
    rotate_matrix_z(0, this->m_c0);
    draw_model_motion((void *)(*(s32 *)&this->unk_98), (void *)this->m_9c, this->m_a8);
    pop_matrix();
}

void TUnk_804E0910::vfunc_13(s32) {
    Pl_802C1FD0 *arg0 = (Pl_802C1FD0 *)this;
    u8 *t = (u8 *)lobby_pigeon_path_parameters;
    t = t + arg0->idx * 0x14;
    Ent_802C1FD0 *e = (Ent_802C1FD0 *)t;
    f32 ox = arg0->x;
    arg0->x = ox + e->b;
    if (((s32 (*)(Pl_802C1FD0 *, Ent_802C1FD0 *, f32))sub_802C1BFC__13TUnk_804E0910Fv)(arg0, e, ox) == 0) {
        arg0->x = (0.0f);
    }
    arg0->y = arg0->y + lobby_pigeon_path_parameters[arg0->idx].c;
    if (arg0->y > (f32)(arg0->sub->n - 1)) {
        arg0->y = (0.0f);
    }
}

void *TUnk_804E0910::deleting_dtor_pathobj(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804E0910;
        ((void (*)(void *, int))__dt__11TObjPathObjFv)(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

u8 *TObjPlayer__sub_802C20E8(u8 *arg0, s32 arg1, const void* _w2) {
  s32 var_r0;
  s32 temp_r3;
  ((u8 * (*)(LobbyPigeon*, void*, const void*))TObjPathObj__ct)((LobbyPigeon*)(arg0), (void*)(arg1), (const void*)(_w2));
  *((s32 **) (((s8 *) arg0) + 0x18)) = &(*(RecoveredGlobal_802C20E8_lbl_804E0910 *)&lbl_804E0910).value;
  *((s32 *) (((s8 *) arg0) + 0x98)) = get_bml_model((*(u8 * *)&jungle_bird_bml_resource), 0);
  ((TUnk_804E0910 *)arg0)->m_9c = get_bml_motion((*(u8 * *)&jungle_bird_bml_resource), 0);
  temp_r3 = ((TUnk_804E0910 *)arg0)->set_params[0];
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
  ((TUnk_804E0910 *)arg0)->m_c8 = var_r0;
  *((s32 *) (((s8 *) arg0) + 0xA0)) = get_bml_motion((*(u8 * *)&jungle_bird_bml_resource), *((s32 *) (((s8 *) (&(*(RecoveredGlobal_802C20E8_lbl_80471890 *)&lobby_pigeon_path_parameters).value)) + ((((TUnk_804E0910 *)arg0)->m_c8) * 0x14))));
  ((TUnk_804E0910 *)arg0)->m_a4 = (f32) (0.0f);
  ((TUnk_804E0910 *)arg0)->m_a8 = (f32) (0.0f);
  ((TUnk_804E0910 *)arg0)->sub_802C1E34();
  return arg0;
}

void *TObjPlayer::create_path_obj(void *arg0) {
    void *o = __nw__7TObjectFUl(0xCC);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *))TObjPlayer__sub_802C27FC)(o, tl_05, arg0);
    }
    return o;
}

void TObjPlayer::free_chr_select() {
    if ((u32) jungle_ebi_texture_gvm_handle != 0U) {
        release_texture_list((void*)jungle_ebi_texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(jungle_ebi_texture_gvm_handle);
        jungle_ebi_texture_gvm_handle = 0U;
    }
    if ((u32) jungle_ebi_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)jungle_ebi_model_resource, 1);
        jungle_ebi_model_resource = 0U;
    }
}

void TObjPlayer::load_jungle_ebi_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &bm_obj_jungle_ebi_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&jungle_ebi_model_resource) = var_r0;
    (*(u8 * *)&jungle_ebi_texture_gvm_handle) = load_gvm_texture_file((s32) &lbl_804719A4.value);
}

struct Pl_802C26E4;
struct Ent_802C26E4;
struct Vec_802C1660;
s32 TUnk_804E094C::update_path_follow_rotation(void *, f32) {
    s32 r;
    Obj_802C22A4 *self = (Obj_802C22A4 *)this;
    Entry_802C2548 *e;
    s32 old;
    s32 diff;
    Vec_802C22A4 a;
    Vec_802C22A4 b;
    s32 tmp;
    s32 tmp2;
    e = &jungle_ebi_path_profiles[this->m_c8];
    if (!(e->f & 1)) {
        return 1;
    }
    ((s32 (*)(void *, s32, s32, Vec_802C22A4 *,
              f32))sample_clamped_path_position)(self, self->f98, self->fA0, &a,
                                                 this->m_a4);
    VecCopy((Vec *)((Vec_802C1660 *)&self->vAC), (const Vec *)((Vec_802C1660 *)&a));
    r = ((s32 (*)(void *, s32, s32, Vec_802C22A4 *,
                  f32))sample_clamped_path_position)(self, self->f98, self->fA0,
                                                     &b, this->m_a4 + e->d);
    if (this->visibility != 0) {
        Vec_802C22A4 p = self->vAC;
        Hit_802C22A4 *hit;
        vec3_add_to(&p, &self->pos);
        p.y += (1e+04f);
        hit = csnVecterUnder(&p, 0x16EF);
        if (hit != NULL) {
            self->pos.y = hit->n->y;
        }
    }
    {
    Vec_802C22A4 d;
    VecCopy((Vec *)((Vec_802C1660 *)&d), (const Vec *)((Vec_802C1660 *)&b));
    ((f32 (*)(Vec_802C1660 *, Vec_802C1660 *))subtract_vector)((Vec_802C1660 *)&d, (Vec_802C1660 *)&a);
    direction_to_rotation_xz((u8 *)((Vec_802C1660 *)&d), &tmp, &tmp2);
    }
    self->fBC = approach_angle_limited(self->fBC, tmp, e->e);
    old = this->m_b8;
    tmp = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    if (!(e->f & 2)) {
        this->m_b8 = approach_angle_limited(old, tmp, e->e);
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

s32 TUnk_804E094C::sub_802C2548() {
    Vec_802C2548 a;
    Vec_802C2548 b;
    Vec_802C2548 d;
    s32 tmp;
    s32 r;
    Obj_802C2548 *self = (Obj_802C2548 *)this;
    this->m_b8 = 0;
    self->fBC = 0;
    this->m_c0 = 0;
    self->fC4 = 0;
    ((s32 (*)(void *, s32, s32, Vec_802C2548 *,
              f32))sample_clamped_path_position)(self, self->f98, self->fA0, &a,
                                                 (0.0f));
    VecCopy((Vec *)&self->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec_802C2548 *,
                  f32))sample_clamped_path_position)(
        self, self->f98, self->fA0, &b, jungle_ebi_path_profiles[this->m_c8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    ((f32 (*)(Vec_802C2548 *, Vec_802C2548 *))subtract_vector)(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &self->fBC, &tmp);
    this->m_b8 = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

void TUnk_804E094C::vfunc_14() {
    u8 *arg0 = (u8 *)this;
    if ((TObjPlayer::check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        ((s32 (*)(void *, s32, s32, f32))draw_line_strip__10TObjPlayerFPviif)(arg0, *(s32 *)&this->unk_98, *(s32 *)((s8 *)arg0 + 0xA0), (1.0f));
    }
    TObjFish::set_global_param((*(s32 *)&jungle_ebi_texture_gvm_handle));
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix((u8 *)&this->unk_AC);
    rotate_matrix_y(0, this->m_b8);
    rotate_matrix_z(0, this->m_c0);
    draw_model_motion((void *)(*(s32 *)&this->unk_98), (void *)this->m_9c, this->m_a8);
    pop_matrix();
}

void TUnk_804E094C::vfunc_13(s32) {
    Pl_802C26E4 *arg0 = (Pl_802C26E4 *)this;
    Ent_802C26E4 *e = (Ent_802C26E4 *)jungle_ebi_path_profiles;
    e += arg0->idx;
    f32 ox = arg0->x;
    arg0->x = ox + e->b;
    if (((TUnk_804E094C *)arg0)->update_path_follow_rotation((Ent_802C26E4 *)(e), ox) == 0) {
        arg0->x = (0.0f);
    }
    arg0->y = arg0->y + jungle_ebi_path_profiles[arg0->idx].c;
    if (arg0->y > (f32)(arg0->sub->n - 1)) {
        arg0->y = (0.0f);
    }
}

void *__dt__13TUnk_804E094CFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E094C;
        ((void (*)(void *, int))__dt__11TObjPathObjFv)(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TObjPlayer__sub_802C27FC(u8 *arg0, s32 arg1, const void* _w2) {
  s32 var_r0;
  s32 temp_r3;
  ((u8 * (*)(LobbyPigeon*, void*, const void*))TObjPathObj__ct)((LobbyPigeon*)(arg0), (void*)(arg1), (const void*)(_w2));
  *((s32 **) (((s8 *) arg0) + 0x18)) = &(*(RecoveredGlobal_802C27FC_lbl_804E094C *)&lbl_804E094C).value;
  *((s32 *) (((s8 *) arg0) + 0x98)) = get_bml_model((*(u8 * *)&jungle_ebi_model_resource), 0);
  ((TUnk_804E094C *)arg0)->m_9c = get_bml_motion((*(u8 * *)&jungle_ebi_model_resource), 0);
  temp_r3 = ((TUnk_804E094C *)arg0)->set_params[0];
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
  ((TUnk_804E094C *)arg0)->m_c8 = var_r0;
  *((s32 *) (((s8 *) arg0) + 0xA0)) = get_bml_motion((*(u8 * *)&jungle_ebi_model_resource), *((s32 *) (((s8 *) (&(*(RecoveredGlobal_802C27FC_lbl_80471848 *)&jungle_ebi_path_profiles).value)) + ((((TUnk_804E094C *)arg0)->m_c8) * 0x18))));
  ((TUnk_804E094C *)arg0)->m_a4 = (f32) (0.0f);
  ((TUnk_804E094C *)arg0)->m_a8 = (f32) (0.0f);
  ((TUnk_804E094C *)arg0)->sub_802C2548();
  return arg0;
}

void *TObjPlayer__sub_802C28B4(void *arg0) {
    void *o = __nw__7TObjectFUl(0xCC);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *))TObjPlayer__sub_802C2F04)(o, tl_05, arg0);
    }
    return o;
}

void TObjPlayer__sub_802C2900(void) {
    if ((u32) (*(u32 *)&seabed_dolphin_texture_handle) != 0U) {
        release_texture_list((void*)(*(u32 *)&seabed_dolphin_texture_handle));
        TAdSinglePlyChrSelectGC::safe_free((*(u32 *)&seabed_dolphin_texture_handle));
        (*(u32 *)&seabed_dolphin_texture_handle) = 0U;
    }
    if ((u32) seabed_dolphin_bml_archive != 0U) {
        TLobby__sub_8001FE7C((void*)seabed_dolphin_bml_archive, 1);
        seabed_dolphin_bml_archive = 0U;
    }
}

void TObjPlayer::load_seabed_dolphin() {
    Obj_802C2958 *o = ((Obj_802C2958 * (*)(s32))::operator new)(0x440);
    if (o != 0) {
        o = ((Obj_802C2958 * (*)(Obj_802C2958 *, s32, void *, s32, s32, s32))load_resource_from_descriptor)(o, 5, bm_obj_seabed_dolphin_resource_descriptor, 0, 0, 0);
    }
    (*(Obj_802C2958 * *)&seabed_dolphin_bml_archive) = o;
    seabed_dolphin_texture_handle = ((s32 (*)(void *))load_gvm_texture_file)(lbl_804719B8);
    Q_802C2958 q = *(Q_802C2958 *)seabed_dolphin_anim_binding;
    q.a = (*(Obj_802C2958 * *)&seabed_dolphin_bml_archive)->f430;
    TLobby::spawn_npc_enemy((s16)0x40, (s32)(((s32 (*)(void *, s32, s32, s32, s32, void *))get_bml_model)((*(Obj_802C2958 * *)&seabed_dolphin_bml_archive), 0, ((Q_802C2958 *)seabed_dolphin_anim_binding)->c, ((Q_802C2958 *)seabed_dolphin_anim_binding)->b, ((Q_802C2958 *)seabed_dolphin_anim_binding)->a, seabed_dolphin_anim_binding)), (s32)seabed_dolphin_texture_handle, (s32)(&q), (f32)((16.0f)), (f32)((1e+01f)));
}

s32 TUnk_804E0988::sub_802C2A10() {
    Vec_802C2C48 a;
    Vec_802C2C48 b;
    Vec_802C2C48 d;
    s32 tmp;
    s32 tmp2;
    s32 r;
    s32 old;
    s32 diff;
    ((s32 (*)(void *, s32, s32, Vec_802C2C48 *,
              f32))sample_clamped_path_position)(((Obj_802C2A10 *)this), ((Obj_802C2A10 *)this)->f98, ((Obj_802C2A10 *)this)->fA0, &a,
                                                 ((Obj_802C2A10 *)this)->fA4);
    VecCopy((Vec *)&((Obj_802C2A10 *)this)->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec_802C2C48 *,
                  f32))sample_clamped_path_position)(
        ((Obj_802C2A10 *)this), ((Obj_802C2A10 *)this)->f98, ((Obj_802C2A10 *)this)->fA0, &b, ((Obj_802C2A10 *)this)->fA4 + seabed_dolphin_path_profiles[((Obj_802C2A10 *)this)->fC8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    ((f32 (*)(Vec_802C2C48 *, Vec_802C2C48 *))subtract_vector)(&d, &a);
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

s32 TUnk_804E0988::sub_802C2C48() {
    Vec_802C2C48 a;
    Vec_802C2C48 b;
    Vec_802C2C48 d;
    s32 tmp;
    s32 r;
    Obj_802C2C48 *self = (Obj_802C2C48 *)this;
    this->m_b8 = 0;
    self->fBC = 0;
    this->m_c0 = 0;
    self->fC4 = 0;
    ((s32 (*)(void *, s32, s32, Vec_802C2C48 *,
              f32))sample_clamped_path_position)(self, self->f98, self->fA0, &a,
                                                 (0.0f));
    VecCopy((Vec *)&self->vAC, (const Vec *)&a);
    r = ((s32 (*)(void *, s32, s32, Vec_802C2C48 *,
                  f32))sample_clamped_path_position)(
        self, self->f98, self->fA0, &b, seabed_dolphin_path_profiles[this->m_c8].d);
    VecCopy((Vec *)&d, (const Vec *)&b);
    ((f32 (*)(Vec_802C2C48 *, Vec_802C2C48 *))subtract_vector)(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &self->fBC, &tmp);
    this->m_b8 = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

void TUnk_804E0988::vfunc_14() {
    u8 *arg0 = (u8 *)this;
    if ((TObjPlayer::check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        ((s32 (*)(void *, s32, s32, f32))draw_line_strip__10TObjPlayerFPviif)(arg0, *(s32 *)&this->unk_98, *(s32 *)((s8 *)arg0 + 0xA0), (1.0f));
    }
    TObjFish::set_global_param(seabed_dolphin_texture_handle);
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix((u8 *)&this->unk_AC);
    rotate_matrix_y(0, this->m_b8);
    rotate_matrix_z(0, this->m_c0);
    set_motion_packed_rotation();
    draw_model_motion((void *)(*(s32 *)&this->unk_98), (void *)this->m_9c, this->m_a8);
    clear_motion_packed_rotation();
    pop_matrix();
}

void TUnk_804E0988::vfunc_13(s32) {
    Pl_802C2DEC *arg0 = (Pl_802C2DEC *)this;
    Entry_802C2C48 *e = seabed_dolphin_path_profiles;
    f32 ox;
    e += arg0->idx;
    ox = arg0->x;
    arg0->x = ox + e->b;
    if (((TUnk_804E0988 *)arg0)->sub_802C2A10() == 0) {
        arg0->x = (0.0f);
    }
    arg0->y = arg0->y + seabed_dolphin_path_profiles[arg0->idx].c;
    if (arg0->y > (f32)(arg0->sub->n - 1)) {
        arg0->y = (0.0f);
    }
}

void *__dt__13TUnk_804E0988Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = seabed_dolphin_vtable;
        ((void (*)(void *, int))__dt__11TObjPathObjFv)(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TObjPlayer__sub_802C2F04(u8 *arg0, s32 arg1, const void* _w2) {
  s32 var_r0;
  s32 temp_r3;
  ((u8 * (*)(LobbyPigeon*, void*, const void*))TObjPathObj__ct)((LobbyPigeon*)(arg0), (void*)(arg1), (const void*)(_w2));
  *((s32 **) (((s8 *) arg0) + 0x18)) = &(*(RecoveredGlobal_802C2F04_lbl_804E0988 *)&seabed_dolphin_vtable).value;
  *((s32 *) (((s8 *) arg0) + 0x98)) = get_bml_model((*(u8 * *)&seabed_dolphin_bml_archive), 0);
  ((TUnk_804E0988 *)arg0)->m_9c = get_bml_motion((*(u8 * *)&seabed_dolphin_bml_archive), 5);
  temp_r3 = ((TUnk_804E0988 *)arg0)->set_params[0];
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
  ((TUnk_804E0988 *)arg0)->m_c8 = var_r0;
  *((s32 *) (((s8 *) arg0) + 0xA0)) = get_bml_motion((*(u8 * *)&seabed_dolphin_bml_archive), *((s32 *) (((s8 *) (&(*(RecoveredGlobal_802C2F04_lbl_804717D4 *)&seabed_dolphin_path_profiles).value)) + ((((TUnk_804E0988 *)arg0)->m_c8) * 0x14))));
  ((TUnk_804E0988 *)arg0)->m_a4 = (f32) (0.0f);
  ((TUnk_804E0988 *)arg0)->m_a8 = (f32) (0.0f);
  ((TUnk_804E0988 *)arg0)->sub_802C2C48();
  return arg0;
}

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
}
s32 sample_motion_node_transform(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
s32 sample_clamped_path_position(void *arg0, s32 arg1, void *arg2, s32 arg3, f32 farg0) {
  s32 sp24[3];
  s32 sp18[3];
  s32 sp8[4];
  f32 var_f1;
  s32 var_r31;
  u32 temp_r7;

  var_f1 = farg0;
  var_r31 = 1;
  temp_r7 = *(s32 *)((s8 *)arg2 + 4) - 1;
  if (var_f1 > (f32)temp_r7) {
    var_r31 = 0;
    var_f1 = (f32)temp_r7;
  }
  bind_motion_context((s32)arg2, var_f1);
  sample_motion_node_transform((void *)arg1, (void *)arg3, (void *)sp24, (void *)sp18, (void *)sp8);
  return var_r31;
}

#pragma pop

#pragma push

#include "pso/TAdStorySelectGC.h"
#include "pso/object/TObjMotion.h"

struct Base_802C3188 { char pad[0x18]; };
struct VObj_802C3188 : Base_802C3188 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
};

struct VBase_18 { char pad[0x18]; };
struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual s32 m12();
};

struct RecoveredGlobal_802C320C___vt__11TObjPathObj {
    s32 value;
    u8 remaining[0x38];
};

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 __vt__11TObjPathObj[];
extern s32 lbl_805D3EC0;
void TObjPathObj::render() {
    u8 *arg0 = (u8 *)this;
    if ((TMainTask::get_render_pass() != 1) && (((VObj_18 *)(arg0))->m8(*(f32 *)&this->unk_90, this->m_94) != 0)) {
        this->vfunc_14();
    }
}

void TObjPathObj::run_task() {
    struct VObj_802C3188 *o = (struct VObj_802C3188 *)this;
    o->m11();
}

void *__dt__11TObjPathObjFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TObjPathObj;
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_802C320C___vt__11TObjPathObj_size[sizeof(RecoveredGlobal_802C320C___vt__11TObjPathObj) == 0x3C ? 1 : -1];
u8 *TObjPathObj__ct(u8 *path_obj, s32 parent, s32 arg2) {
    __ct__8TObjBaseFP7TObject((void *) (path_obj), (void *) (parent));
    *(s32 **)((s8 *)path_obj + 0x18) = &(*(RecoveredGlobal_802C320C___vt__11TObjPathObj *)&__vt__11TObjPathObj).value;
    *(s32 *)((s8 *)path_obj + 0) = (s32) lbl_805D3EC0;
    ((TObjPathObj *)(path_obj))->apply_object_set_data((void *)arg2);
    *(f32 *)((s8 *)path_obj + 0x90) = (f32) (5e+02f);
    ((TObjPathObj *)path_obj)->m_94 = (f32) (1.5e+02f);
    return path_obj;
}

void TObjPathObj::vfunc_14() {  }
void TObjPathObj::vfunc_13(s32) {  }

}

#pragma pop
