#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/TUnk_804C57F0.h"
#include "pso/render/render_util.h"
#include "pso/effect/particle/TParticleCtrl_80085EE4.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/render/GinjaView.h"
#include "pso/effect/TEffect.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_8048E728.h"
#include "pso/unk/TUnk_8048E778.h"
#include "pso/unk/TUnk_8048E6DC.h"
#include "pso/unk/TUnk_8048E6A8.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/ParticleRadial.h"
#include "pso/system/THeap.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"

#include "pso/effect/particle/TParticleCtrl_80327D30.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803DC86C.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D853C.h"
#include "pso/camera/TCameraCtrl.h"

struct Col_80086418 { u8 a, r, g, b; };

struct Ctrl_80086418 {
    u8 pad0[0x90];
    Col_80086418 color;
};

struct Vtx_80086248 { f32 x, y, z, u, v; u32 color; };

typedef struct Quad_80085EE4 { f32 x, y, z, ax, ay, bx, by, pad1C; f32 u, v, du, k0, k1, dv; f32 pad38[2]; } Quad_80085EE4;

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
s32 GXSetNumTexGens(int);
s32 GXSetTevOp(int, int);
s32 GXSetNumTevStages(int);
s32 post_translate_matrix(void *);
s32 emit_particle_strip_vertices(void *, int);
}
void load_projected_texture_matrix(f32 farg0);
void play_indirect_effect_recipe(u8 arg0, u16 sampler, s32 second);
s32 set_texture_num(s32 i);


THeap *TParticleCtrl__heap;

// Built -inline off,deferred: the functions below are written last to first
// (see configure.py).

void *TParticleCtrl::generate_child_default(void *param, void *pos, void *parent) {
    Vec dir = {0.0f, 0.0f, 0.0f};
    return alloc_child_particle(param, pos, &dir, parent);
}

#pragma readonly_strings on
ParticleGenerator particle_ctrl_generator_table[] = {
    {"EMIT", TParticleCtrl::create_random_spread},
    {"SPAIRAL", TParticleCtrl::generate_child_default},
    {"VACUUM", create_random_particle},
};
#pragma readonly_strings reset

void TParticleCtrl::init_heap(u32 size) {
    if (TParticleCtrl__heap == NULL) {
        TParticleCtrl__heap = new THeap(size, 16);
    }
}

void TParticleCtrl::free_heap() {
    if (TParticleCtrl__heap != NULL) {
        delete TParticleCtrl__heap;
        TParticleCtrl__heap = NULL;
    }
}

void *TUnk_8048E728::operator new(size_t size) {
    TUnk_8048E728 *p = (TUnk_8048E728 *)alt_heap->heap_alloc(size);
    if (p == NULL) {
        if (TParticleCtrl__heap != NULL) {
            p = (TUnk_8048E728 *)TParticleCtrl__heap->heap_alloc(size);
            if (p != NULL) {
                p->from_particle_heap = 1;
            }
        }
    } else {
        p->from_particle_heap = 0;
    }
    return p;
}

void TUnk_8048E728::operator delete(void *p) {
    if (p != NULL) {
        if (((TUnk_8048E728 *)p)->from_particle_heap != 0) {
            TParticleCtrl__heap->heap_free(p);
            return;
        }
        alt_heap->heap_free(p);
    }
}

TUnk_8048E728::TUnk_8048E728(ParticleParam *src, TObject *parent) : TObject(parent) {
    f32 v;
    model = NULL;
    unk_B4 = 0;
    motion = NULL;
    motion_frame = 0.0f;
    unk_48 = 0.0f;
    color_base[0] = 0.0f;
    color_base[1] = 0.0f;
    color_base[2] = 0.0f;
    unk_98 = 0;
    m_9c = 0;
    unk_A0 = 0;
    m_a4 = 1.0f;
    unk_A8 = 1.0f;
    param = src;
    v = 0.0f;
    if (param->fade_in_end > 0.0f) {
        v = 1.0f / param->fade_in_end;
    }
    fade_in_scale = v;
    v = 0.0f;
    if (param->fade_out_start > 0.0f) {
        v = 1.0f / param->fade_out_start;
    }
    fade_out_scale = v;
    sprite_index = find_particle_texture_index(param->unk_14);
    m_28 = 1.0f;
    unk_2C = 1.0f;
    step.x = 0.0f;
    step.y = 0.0f;
    step.z = 0.0f;
    age = 0.0f;
    age_rate = 0.0f;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    attach.x = 0.0f;
    attach.y = 0.0f;
    attach.z = 0.0f;
    m_88 = 0.0f;
    unk_8C = 0.0f;
    color = 0;
    frame = 0;
    unk_95 = 0;
    m_96 = 0;
    unk_6C = 0;
    flags = 0;
    target_id = 0xFFFF;
}

TUnk_8048E728::~TUnk_8048E728() {
    param = NULL;
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

void TUnk_8048E728::draw_particle_refraction_quad() {
    Ctrl_80086248 *self = (Ctrl_80086248 *)this;
    Vec p;
    Vtx_80086248 v[4];
    s32 frame;
    const f32 *uv;
    frame = self->frame;
    if (is_split_screen() != 0) {
        return;
    }
    TParticleCtrl::begin_effect_render();
    uv = lbl_804C5820[self->tex].uvs[frame];
    p.x = self->pos.x + self->ofs.x;
    p.y = self->pos.y + self->ofs.y;
    p.z = self->pos.z + self->ofs.z;
    v[0].x = 10.0f * self->w; v[0].y = 10.0f * self->h; v[0].z = 0.0f; v[0].u = uv[0]; v[0].v = uv[1]; v[0].color = self->color;
    v[1].x = 10.0f * self->w; v[1].y = -10.0f * self->h; v[1].z = 0.0f; v[1].u = uv[2]; v[1].v = uv[1]; v[1].color = self->color;
    v[2].x = -10.0f * self->w; v[2].y = 10.0f * self->h; v[2].z = 0.0f; v[2].u = uv[0]; v[2].v = uv[3]; v[2].color = self->color;
    v[3].x = -10.0f * self->w; v[3].y = -10.0f * self->h; v[3].z = 0.0f; v[3].u = uv[2]; v[3].v = uv[3]; v[3].color = self->color;
    push_matrix();
    post_translate_matrix(&p);
    rotate_matrix_y(0, camera_ctrl_instance->yaw);
    rotate_matrix_x(0, camera_ctrl_instance->pitch);
    load_projected_texture_matrix(1.1333334f);
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(lbl_804C5820[9].texlist));
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

void TParticleCtrl::mark_active() {
    *(u16 *)((s8 *)this + 0x24) = (u16) (*(u16 *)((s8 *)this + 0x24) | 0x2000);
    request_indirect_effect(0x1F);
}

s32 TUnk_8048E728::is_particle_sprite_additive(s32) {
    return TParticleCtrl__data_80511F70[sprite_index]->definition->flags & 1;
}

#pragma push
#pragma fp_contract on
void TUnk_8048E778::draw_sprite_quad(s32 kind) {
    Particle_80085EE4 *p = (Particle_80085EE4 *)this;
    Vec view;
    Vec world;
    Quad_80085EE4 quad;
    const f32 *uv;
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
    sy = screen_projection.distance;
    x = screen_projection.center_x;
    cy = screen_projection.center_y;
    sx = sy * (480.0f / (480.0f * screen_projection.width));
    TParticleCtrl::begin_effect_render();
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(lbl_804C5820[kind].texlist));
    set_draw_texture_and_color(lbl_804C5820[kind].texture, lbl_804C5820[kind].color);
    uv = lbl_804C5820[kind].uvs[p->f94];
    quad.u = uv[0];
    quad.v = uv[1];
    quad.du = uv[2] - uv[0];
    quad.k1 = quad.k0 = 0.0f;
    quad.dv = uv[3] - uv[1];
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
        sx *= lbl_804C5820[kind].width;
        sy *= lbl_804C5820[kind].height;
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
