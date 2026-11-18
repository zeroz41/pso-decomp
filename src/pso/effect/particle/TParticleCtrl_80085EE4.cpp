#include "pso/render/render_util.h"
#include "pso/effect/particle/TParticleCtrl_80085EE4.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_8048E728.h"
#include "pso/unk/TUnk_8048E778.h"
#include "pso/unk/TUnk_8048E6DC.h"
#include "pso/unk/TUnk_8048E6A8.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"

#include "pso/effect/particle/TParticleCtrl_80327D30.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/player/TObjPlayer_80011014.h"

struct Col_80086418 { u8 a, r, g, b; };

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
    Vec pos;
    Vec off;
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
    Vec pos;
    Vec ofs;
    f32 w;
    f32 h;
    u32 color;
    s8 frame;
};


extern "C" {
struct RecoveredGlobal_TParticleCtrl__data_80511F70 { s32 value; u8 remaining[0x1AC]; };
extern RecoveredGlobal_TParticleCtrl__data_80511F70 TParticleCtrl__data_80511F70;
u8 * __dt__7TObjectFv(void *, s16);
struct RecoveredGlobal_lbl_8048E728 { s32 value; u8 remaining[0x14]; };
extern RecoveredGlobal_lbl_8048E728 lbl_8048E728;
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
s32 emit_particle_strip_vertices(void *, int);
extern Tex_80086248 lbl_804C5820[];
extern u8 *camera_ctrl_instance;
void set_inverse_alpha_blend(void);
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
void set_inverse_color_blend(void);
void set_constant_material_color(u32 x);
extern Cam_80085EE4 lbl_8058D4F8;


#pragma push
#pragma fp_contract on
void TUnk_8048E778::draw_sprite_quad(s32 kind) {
    Particle_80085EE4 *p = (Particle_80085EE4 *)this;
    Vec view;
    Vec world;
    Quad_80085EE4 quad;
    UV_80086248 *uv;
    f32 sx;
    f32 sy;
    f32 x;
    f32 cy;
    f32 z;
    f32 y;
    f32 c;
    f32 s;
    u32 flags;
    f32 a;
    f32 b;

    flags = lbl_804C5820[kind].flags;
    if (flags & 2) {
        if (flags & 4) {
            set_inverse_alpha_blend();
        } else {
            set_default_alpha_blend();
        }
    } else if (flags & 4) {
        set_inverse_color_blend();
    } else {
        set_additive_blend();
    }
    sy = lbl_8058D4F8.scale;
    x = lbl_8058D4F8.cx;
    cy = lbl_8058D4F8.cy;
    sx = sy * (480.0f / (480.0f * lbl_8058D4F8.aspect));
    TParticleCtrl::begin_effect_render();
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_804C5820[kind].param);
    set_draw_texture_and_color(lbl_804C5820[kind].tex, lbl_804C5820[kind].color);
    uv = &lbl_804C5820[kind].uvs[p->f94];
    quad.u = uv->u0;
    quad.v = uv->v0;
    quad.du = uv->u1 - uv->u0;
    quad.k1 = quad.k0 = 0.0f;
    quad.dv = uv->v1 - uv->v0;
    world.x = p->pos.x + p->off.x;
    world.y = p->pos.y + p->off.y;
    world.z = p->pos.z + p->off.z;
    if (p->f95 != 1) {
        matrix_mult_vec(0, &world, &view);
        view.y = -view.y;
    } else {
        VecCopy((Vec *)&view, (const Vec *)&world);
    }
    if (view.z <= -1.0f || p->f95 == 1) {
        set_constant_material_color(p->f90);
        if (p->f95 != 1) {
            z = 1.0f / -view.z;
            a = sx * z;
            b = sy * z;
            sx = a;
            sy = b;
            x = view.x * a + x;
            y = view.y * b + cy;
        } else {
            sx = 1.0f;
            z = view.z;
            sy = sx;
            x = view.x;
            y = view.y;
        }
        sx *= lbl_804C5820[kind].sx;
        sy *= lbl_804C5820[kind].sy;
        sx *= p->f88;
        sy *= p->f8C;
        c = cos_table_lookup(p->f96);
        s = -sin_table_lookup(p->f96);
        quad.z = z;
        quad.x = x - (sx * c + sy * s);
        quad.y = y - (-sx * s + sy * c);
        sy = sy + sy;
        sx = sx + sx;
        quad.ax = sx * c;
        quad.ay = -sx * s;
        quad.bx = sy * s;
        quad.by = sy * c;
        DVDConvertEntrynumToPath((f32 *)&quad);
    }
    TWindowSubStatusDisp::get_player();
    TParticleCtrl::end_effect_render();
    set_default_alpha_blend();
}
#pragma pop

s32 TUnk_8048E728::is_particle_sprite_additive() {
    return **(s32 **)((s8 *)(*(s32 *)((s8 *)&TParticleCtrl__data_80511F70.value + (this->sprite_index * 4))) + 0x28) & 1;
}

void TParticleCtrl::mark_active() {
    *(u16 *)((s8 *)this + 0x24) = (u16) (*(u16 *)((s8 *)this + 0x24) | 0x2000);
    request_indirect_effect(0x1F);
}

void TUnk_8048E728::draw_particle_refraction_quad() {
    Ctrl_80086248 *self = (Ctrl_80086248 *)this;
    Vec p;
    Vtx_80086248 v[4];
    s32 frame;
    UV_80086248 *uv;
    frame = self->frame;
    if (is_split_screen() != 0) {
        return;
    }
    TParticleCtrl::begin_effect_render();
    uv = &lbl_804C5820[self->tex].uvs[frame];
    p.x = self->pos.x + self->ofs.x;
    p.y = self->pos.y + self->ofs.y;
    p.z = self->pos.z + self->ofs.z;
    v[0].x = 10.0f * self->w; v[0].y = 10.0f * self->h; v[0].z = 0.0f; v[0].u = uv->u0; v[0].v = uv->v0; v[0].color = self->color;
    v[1].x = 10.0f * self->w; v[1].y = -10.0f * self->h; v[1].z = 0.0f; v[1].u = uv->u1; v[1].v = uv->v0; v[1].color = self->color;
    v[2].x = -10.0f * self->w; v[2].y = 10.0f * self->h; v[2].z = 0.0f; v[2].u = uv->u0; v[2].v = uv->v1; v[2].color = self->color;
    v[3].x = -10.0f * self->w; v[3].y = -10.0f * self->h; v[3].z = 0.0f; v[3].u = uv->u1; v[3].v = uv->v1; v[3].color = self->color;
    push_matrix();
    post_translate_matrix(&p);
    rotate_matrix_y(0, *(s32 *)(camera_ctrl_instance + 0x194));
    rotate_matrix_x(0, *(s32 *)(camera_ctrl_instance + 0x190));
    load_projected_texture_matrix(1.1333334f);
    TObjFish::set_global_param(*(s32 *)((u8 *)lbl_804C5820 + 0x16C));
    set_texture_num(self->tex);
    TParticleCtrl::setup_particle_draw(1);
    GXSetNumTevStages(2);
    GXSetNumTexGens(2);
    GXSetTevOp(0, 0);
    play_indirect_effect_recipe(0x1F, 0, 1);
    TObjPlayer::setup_tev_stage();
    emit_particle_strip_vertices(v, 4);
    TParticleCtrl::reset_particles();
    reset_particle_tev();
    reset_indirect_tev(1);
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TUnk_8048E728::apply_particle_model_fade_color(s32 mode) {
    Ctrl_80086418 *self = (Ctrl_80086418 *)this;
    NJS_ARGB f;
    if (mode != 0) {
        set_color_blend_mode(1, 4, 1, 0);
        Col_80086418 c = self->color;
        f.a = 0.0f;
        f.r = -(1.0f - c.r / 255.0f);
        f.g = -(1.0f - c.g / 255.0f);
        f.b = -(1.0f - c.b / 255.0f);
    } else {
        set_color_blend_mode(1, 4, 5, 0);
        Col_80086418 c = self->color;
        f.a = -(1.0f - c.a / 255.0f);
        f.r = 0.0f;
        f.g = 0.0f;
        f.b = 0.0f;
    }
    set_constant_material((const NJS_ARGB *)(((f32 *)&f)));
}

u8 *__dt__13TUnk_8048E728Fv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &lbl_8048E728.value;
        *(s32 *)((s8 *)arg0 + 0x20) = 0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            TUnk_8048E728::operator delete(arg0);
        }
    }
    return arg0;
}
void *init_particle_base(void *object, void *arg1, s32 arg2) {
    Particle_800865BC *p = (Particle_800865BC *)object;
    f32 v;
    __ct__7TObjectFP7TObject(object, (void *)arg2);
    p->vt = &lbl_8048E728.value;
    p->fB0 = 0;
    p->fB4 = 0;
    p->fB8 = 0;
    p->fBC = 0.0f;
    p->f48 = 0.0f;
    p->f4C = 0.0f;
    p->f50 = 0.0f;
    p->f54 = 0.0f;
    p->f98 = 0;
    p->f9C = 0;
    p->fA0 = 0;
    p->fA4 = 1.0f;
    p->fA8 = 1.0f;
    p->src = (Src_800865BC *)arg1;
    v = 0.0f;
    if (p->src->f58 > 0.0f) {
        v = 1.0f / p->src->f58;
    }
    p->f60 = v;
    v = 0.0f;
    if (p->src->f5C > 0.0f) {
        v = 1.0f / p->src->f5C;
    }
    p->f64 = v;
    p->tex = find_particle_texture_index(p->src->texId);
    p->f28 = 1.0f;
    p->f2C = 1.0f;
    p->f3C = 0.0f;
    p->f40 = 0.0f;
    p->f44 = 0.0f;
    p->f58 = 0.0f;
    p->f5C = 0.0f;
    p->f70 = 0.0f;
    p->f74 = 0.0f;
    p->f78 = 0.0f;
    p->f7C = 0.0f;
    p->f80 = 0.0f;
    p->f84 = 0.0f;
    p->f88 = 0.0f;
    p->f8C = 0.0f;
    p->f90 = 0;
    p->f94 = 0;
    p->f95 = 0;
    p->f96 = 0;
    p->f6C = 0;
    p->f24 = 0;
    p->f26 = 0xFFFF;
    return object;
}
