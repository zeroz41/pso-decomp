#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_8048E728.h"
#include "pso/misc/TUnk_8048E778.h"
#include "pso/misc/TUnk_8048E6DC.h"
#include "pso/misc/TUnk_8048E6A8.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct RecoveredGlobal_800861F4_TParticleCtrl__data_80511F70 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_8008655C_lbl_8048E728 {
    s32 value;
    u8 remaining[0x14];
};

struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

struct RecoveredGlobal_800858D0_lbl_8048E6A8 {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_80085E78_lbl_8048E6DC {
    s32 value;
    u8 remaining[0x30];
};

struct Col_80085798 { u32 r; u32 g; u32 b; u32 a; };

struct Obj_80085798 { u8 pad[0x38]; u8 target[0x10]; };

struct Col_80086418 { u8 a, r, g, b; };

struct FCol_80086418 { f32 a, r, g, b; };

struct Ctrl_80086418 {
    u8 pad0[0x90];
    Col_80086418 color;
};

struct Src_800865BC {
    u8 pad0[0x14];
    s32 texId;
    u8 pad18[0x58 - 0x18];
    f32 f58;
    f32 f5C;
};

struct Particle_800865BC {
    u8 pad0[0x18];
    void *vt;
    s16 tex;
    u8 pad1E[0x20 - 0x1E];
    Src_800865BC *src;
    s16 f24;
    u16 f26;
    f32 f28, f2C;
    u8 pad30[0x3C - 0x30];
    f32 f3C, f40, f44, f48, f4C, f50, f54, f58, f5C, f60, f64;
    u8 pad68[0x6C - 0x68];
    s32 f6C;
    f32 f70, f74, f78, f7C, f80, f84, f88, f8C;
    s32 f90;
    s8 f94;
    s8 f95;
    s16 f96;
    s32 f98, f9C, fA0;
    f32 fA4, fA8;
    u8 padAC[0xB0 - 0xAC];
    s32 fB0, fB4, fB8;
    f32 fBC;
};

struct Vec_80086248 { f32 x, y, z; };

struct Vtx_80086248 { f32 x, y, z, u, v; u32 color; };

struct UV_80086248 { f32 u0, v0, u1, v1; };

struct Tex_80086248 {
    u32 flags;
    s32 param;
    s32 tex;
    u8 pad0C[4];
    UV_80086248 *uvs;
    f32 sx;
    f32 sy;
    s32 color;
    u8 pad20[8];
};

typedef struct Vec_80085EE4 { f32 x, y, z; } Vec_80085EE4;
typedef struct Quad_80085EE4 { f32 x, y, z, ax, ay, bx, by, pad1C; f32 u, v, du, k0, k1, dv; f32 pad38[2]; } Quad_80085EE4;

typedef struct Cam_80085EE4 {
    u8 pad0[8];
    f32 cx;
    f32 cy;
    u8 pad10[8];
    f32 scale;
    f32 aspect;
} Cam_80085EE4;

typedef struct Particle_80085EE4 {
    u8 pad0[0x70];
    Vec_80085EE4 pos;
    Vec_80085EE4 off;
    f32 f88;
    f32 f8C;
    s32 f90;
    s8 f94;
    s8 f95;
    s16 f96;
} Particle_80085EE4;

struct Ctrl_80086248 {
    u8 pad0[0x1C];
    u16 tex;
    u8 pad1E[0x70 - 0x1E];
    Vec_80086248 pos;
    Vec_80086248 ofs;
    f32 w;
    f32 h;
    u32 color;
    s8 frame;
};

struct Vec_80085CB0 { f32 x, y, z; };

struct Player_80085CB0 {
    u8 pad0[0x178];
    Vec_80085CB0 pos;
    u8 pad184[0x194 - 0x184];
    s32 f194;
};

struct Ctrl_80085CB0 {
    u8 pad0[0x38];
    Vec_80085CB0 pos;
    u8 pad44[0x68 - 0x44];
    f32 f68;
    u8 pad6C[0x90 - 0x6C];
    f32 f90;
    f32 f94;
    s32 f98;
    f32 screen_x;
    f32 screen_y;
    f32 alpha;
};

struct Color_800859EC { u8 a, r, g, b; };

struct Quad_800859EC { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

extern "C" {
s32 is_split_screen(void);
u8 *__nw__7TObjectFUl(s32);
extern s32 tl_particle;
extern RecoveredGlobal_800861F4_TParticleCtrl__data_80511F70 TParticleCtrl__data_80511F70;
u8 * __dt__7TObjectFv(void *, s16);
extern RecoveredGlobal_8008655C_lbl_8048E728 lbl_8048E728;
u8 *__dt__13TUnk_8048E728Fv(u8 *arg0, s16 arg1);
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 lbl_8048E6A8[];
extern s32 lbl_8048E6DC[];
extern s32 lbl_805D2930;
extern Col_80085798 demo_mode_particle_color;
void TObjRoomId__sub_80141CF4(void *dst, Col_80085798 *src, f32 t);
void set_color_blend_mode(s32 a, s32 b, s32 c, s32 d);
void __ct__7TObjectFP7TObject(void *, void *);
s32 GXSetNumTexGens(int);
s32 GXSetTevOp(int, int);
s32 GXSetNumTevStages(int);
s32 rotate_matrix_y(int, s32);
s32 rotate_matrix_x(int, s32);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
s32 TParticleCtrl__sub_803E2A1C(void *, int);
extern Tex_80086248 lbl_804C5820[];
extern u8 *camera_ctrl_instance;
void fn_80141EB4(void);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
s32 matrix_mult_vec(int, void *, void *);
void begin_screen_draw(s32 arg0);
void DVDConvertEntrynumToPath(f32 *q);
void set_draw_texture_and_color(s32 idx, s32 arg1);
}
void *init_particle_base(void *arg0, void *arg1, s32 arg2);
void load_projected_texture_matrix(f32 farg0);
void play_indirect_effect_recipe(u8 arg0, u16 sampler, s32 second);
s32 set_texture_num(s32 i);
void setSpriteInverseColorBlend(void);
void set_constant_material_color(u32 x);
extern Cam_80085EE4 lbl_8058D4F8;
extern "C" {
f32 fabs_float(f32);
u32 csnVector(void *, void *, int);
f32 vec3_dot(void *, void *);
f32 vec_squared_length(u8 *arg0);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 normalize_vector(void *);
s32 push_matrix_from(void *);
extern Vec_80085CB0 lbl_804393D0;
extern s32 identity_matrix[];
void project_world_to_screen(s32, void *, void *);
void *TParticleCtrl__sub_80085878(void *arg0, s16 arg1);
void *TParticleCtrl__sub_80085E20(void *arg0, s16 arg1);
f32 horizontal_distance_squared(void *, void *);
void *get_player_by_client_id(s32 i);
void __dl__7TObjectFPv(void *);

extern s32 local_client_id;

void TUnk_8048E6A8::render() {
    Obj_80085798 *self = (Obj_80085798 *)this;
    if (TObjPlayer::check_demo_mode() != 0) {
        Col_80085798 c = demo_mode_particle_color;
        TObjRoomId__sub_80141CF4(self->target, &c, 40.0f);
    }
}

void TUnk_8048E6A8::run_task() {
    u8 *arg0 = (u8 *)this;
    u32 player;

    player = (u32)get_player_by_client_id((local_client_id));
    if ((player != 0U) && (horizontal_distance_squared((void *)(player + 0x38), (void *)(arg0 + 0x38)) < 400.0f)) {
        if (this->scale.x > 0.0f) {
            lbl_805D2930 = 1;
            return;
        }
        lbl_805D2930 = 0;
    }
}

void *TParticleCtrl__sub_80085878(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_8048E6A8;
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_800858D0_lbl_8048E6A8_size[sizeof(RecoveredGlobal_800858D0_lbl_8048E6A8) == 0x34 ? 1 : -1];
u8 *TParticleCtrl::construct_particle_obj(s32 arg1, s32 arg2) {
    __ct__8TObjBaseFP7TObject(this, (void *)arg2);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_800858D0_lbl_8048E6A8 *)&lbl_8048E6A8).value;
    ((VObj_18_1a504b *)(this))->m5(arg1);
    return ((u8 *)this);
}

u8 *TParticleCtrl::create_particle_obj_90(s32 arg0) {
    u8 *particle_ctrl;
    u8 *var_r0;
    if (is_split_screen() != 0) {
        return NULL;
    }
    particle_ctrl = (u8 *)(__nw__7TObjectFUl(0x90));
    var_r0 = particle_ctrl;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(((TParticleCtrl *)particle_ctrl)->construct_particle_obj(arg0, tl_particle));
    }
    return var_r0;
}

u8 *TParticleCtrl::create_particle_obj_ac(s32 arg0) {
    u8 *particle_ctrl;
    u8 *var_r0;
    if (is_split_screen() != 0) {
        return NULL;
    }
    particle_ctrl = (u8 *)(__nw__7TObjectFUl(0xAC));
    var_r0 = particle_ctrl;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(((TParticleCtrl *)particle_ctrl)->init_particle_obj(arg0, tl_particle));
    }
    return var_r0;
}

void TUnk_8048E6DC::render() {
    Ctrl_80085CB0 *self = (Ctrl_80085CB0 *)this;
    Color_800859EC color;
    Quad_800859EC quad;
    f32 limit;
    f32 v;
    f32 s;
    f32 w;
    f32 h;

    limit = 225.0f;
    if (lbl_805D2930 == 0) {
        return;
    }
    if (self->f98 != 0) {
        limit = 50.0f;
    }
    if (self->alpha < limit) {
        v = 3.0f + self->alpha;
        self->alpha = v < 0.0f ? 0.0f : (v < limit ? v : limit);
    } else {
        v = self->alpha - 3.0f;
        self->alpha = v < limit ? limit : (v < 255.0f ? v : 255.0f);
    }
    TParticleCtrl::begin_effect_render();
    if (self->f94 > 0.0f) {
        project_world_to_screen(0, &self->pos, &self->screen_x);
        if (self->screen_x > 650.0f) {
            self->screen_x = 650.0f;
        }
        if (self->screen_x < -10.0f) {
            self->screen_x = -10.0f;
        }
        if (self->screen_y > 490.0f) {
            self->screen_y = 490.0f;
        }
        if (self->screen_y < -10.0f) {
            self->screen_y = -10.0f;
        }
    }
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_804C5820[31].param);
    set_draw_texture_and_color(lbl_804C5820[31].tex, -1);
    if (self->f94 < 0.0f) {
        color.a = 0;
    } else if (self->f94 <= 0.5f) {
        v = self->f94 * (2.5f * self->alpha);
        color.a = v < 0.0f ? 0.0f : (v < 255.0f ? v : 255.0f);
    } else {
        color.a = self->alpha;
    }
    if (self->f68 < 0.0f) {
        color.r = 0x80;
        color.g = 0x80;
        color.b = 0x80;
    } else if (self->f68 >= 10.0f) {
        color.r = 0x55;
        color.g = 0x23;
        color.b = 0;
    } else {
        color.r = 0xFF;
        color.g = 0x80;
        color.b = 0x40;
    }
    w = lbl_804C5820[31].sx;
    h = lbl_804C5820[31].sy;
    s = 0.5f * self->f90;
    w *= s;
    h *= s;
    quad.x0 = self->screen_x - w;
    quad.x1 = self->screen_x + w;
    quad.y0 = self->screen_y - h;
    quad.y1 = self->screen_y + h;
    quad.u0 = 0.0f;
    quad.v0 = 0.0f;
    quad.u1 = 1.0f;
    quad.v1 = 1.0f;
    set_constant_material_color(*(u32 *)&color);
    draw_textured_quad_at_depth((f32 *)&quad, 0.1f);
    TWindowSubStatusDisp::get_player();
    TParticleCtrl::end_effect_render();
}

#pragma fp_contract on
void TUnk_8048E6DC::run_task() {
    Ctrl_80085CB0 *self = (Ctrl_80085CB0 *)this;
    Vec_80085CB0 out;
    Vec_80085CB0 d;
    f32 v;
    f32 r;
    if ((*(Player_80085CB0 * *)&camera_ctrl_instance) != NULL) {
        d.x = self->pos.x - (*(Player_80085CB0 * *)&camera_ctrl_instance)->pos.x;
        d.y = 0.0f;
        d.z = self->pos.z - (*(Player_80085CB0 * *)&camera_ctrl_instance)->pos.z;
        if (0.0f != vec_squared_length((u8 *)&d)) {
            normalize_vector(&d);
        }
        push_matrix_from(identity_matrix);
        Vec_80085CB0 t = lbl_804393D0;
        rotate_matrix_y(0, (s32)((*(Player_80085CB0 * *)&camera_ctrl_instance)->f194));
        rotate_vector_by_matrix(0, &t, &out);
        pop_matrix();
        self->f94 = vec3_dot(&out, &d);
        r = fabs_float(self->f94);
        if (self->f94 >= 0.0f) {
            v = fabs_float(1.0f - r);
            if (v > 0.6f) {
                v = 0.6f;
            }
        } else {
            v = 0.0f;
        }
        self->f90 = 50.0f * v + 25.0f;
        Vec_80085CB0 p = (*(Player_80085CB0 * *)&camera_ctrl_instance)->pos;
        if (csnVector(&p, &self->pos, 0x100) != 0) {
            self->f98 = 1;
        } else {
            self->f98 = 0;
        }
    }
}

void *TParticleCtrl__sub_80085E20(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_8048E6DC;
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_800861F4_TParticleCtrl__data_80511F70_size[sizeof(RecoveredGlobal_800861F4_TParticleCtrl__data_80511F70) == 0x1B0 ? 1 : -1];

typedef char RecoveredGlobal_80085E78_lbl_8048E6DC_size[sizeof(RecoveredGlobal_80085E78_lbl_8048E6DC) == 0x34 ? 1 : -1];
u8 *TParticleCtrl::init_particle_obj(s32 arg1, s32 arg2) {
    __ct__8TObjBaseFP7TObject(this, (void *)arg2);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_80085E78_lbl_8048E6DC *)&lbl_8048E6DC).value;
    ((VObj_18_1a504b *)(this))->m5(arg1);
    *(f32 *)((s8 *)((u8 *)this) + 0xA4) = 225.0f;
    lbl_805D2930 = 1;
    return ((u8 *)this);
}
}
