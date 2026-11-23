#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/render/render_util.h"
#include "pso/effect/particle/TParticleCtrl_80085EE4.h"
#include "pso/unk/TUnk_8048E6A8.h"
#include "pso/unk/TUnk_8048E6DC.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_8048E728.h"
#include "pso/unk/TUnk_8048E778.h"


#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/network/client_id.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/PlayerSlots.h"
#include "pso/camera/TCameraCtrl.h"

#pragma defer_codegen on

struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

struct Obj_80085798 { u8 pad[0x38]; u8 target[0x10]; };


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

struct Ctrl_80085CB0 {
    u8 pad0[0x38];
    Vec pos;
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
extern s32 tl_particle;
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 __vt__13TUnk_8048E6A8[];
extern s32 __vt__13TUnk_8048E6DC[];
s32 lbl_805D2930 = 1;
f32 vec_squared_length(u8 *arg0);
s32 rotate_vector_by_matrix(int, void *, void *);

}
void set_constant_material_color(u32 x);

u8 *TParticleCtrl::init_particle_obj(s32 arg1, saddr parent) {
    __ct__8TObjBaseFP7TObject(this, (void *)parent);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = __vt__13TUnk_8048E6DC;
    ((VObj_18_1a504b *)(this))->m5(arg1);
    *(f32 *)((s8 *)((u8 *)this) + 0xA4) = 225.0f;
    lbl_805D2930 = 1;
    return ((u8 *)this);
}

TUnk_8048E6DC::~TUnk_8048E6DC() {

}

#pragma fp_contract on
void TUnk_8048E6DC::run_task() {
    Ctrl_80085CB0 *self = (Ctrl_80085CB0 *)this;
    Vec out;
    Vec d;
    f32 v;
    f32 r;
    if (camera_ctrl_instance != NULL) {
        d.x = self->pos.x - camera_ctrl_instance->pos.x;
        d.y = 0.0f;
        d.z = self->pos.z - camera_ctrl_instance->pos.z;
        if (0.0f != vec_squared_length((u8 *)&d)) {
            normalize_vector(&d);
        }
        push_matrix_from(identity_matrix);
        Vec t = { 0.0f, 0.0f, -1.0f };
        rotate_matrix_y(0, camera_ctrl_instance->yaw);
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
        Vec p = camera_ctrl_instance->pos;
        if (csnVector(&p, &self->pos, 0x100) != 0) {
            self->f98 = 1;
        } else {
            self->f98 = 0;
        }
    }
}

#pragma fp_contract reset
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
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(particle_definitions[31].texlist));
    set_draw_texture_and_color(particle_definitions[31].texture, -1);
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
    w = particle_definitions[31].width;
    h = particle_definitions[31].height;
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

u8 *TParticleCtrl::create_particle_obj_ac(s32 arg0) {
    u8 *particle_ctrl;
    u8 *var_r0;
    if (is_split_screen() != 0) {
        return NULL;
    }
    particle_ctrl = (u8 *)(TObject::operator new(0xAC));
    var_r0 = particle_ctrl;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(((TParticleCtrl *)particle_ctrl)->init_particle_obj(arg0, tl_particle));
    }
    return var_r0;
}

u8 *TParticleCtrl::create_particle_obj_90(s32 arg0) {
    u8 *particle_ctrl;
    u8 *var_r0;
    if (is_split_screen() != 0) {
        return NULL;
    }
    particle_ctrl = (u8 *)(TObject::operator new(0x90));
    var_r0 = particle_ctrl;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(((TParticleCtrl *)particle_ctrl)->construct_particle_obj(arg0, tl_particle));
    }
    return var_r0;
}

u8 *TParticleCtrl::construct_particle_obj(s32 arg1, saddr parent) {
    __ct__8TObjBaseFP7TObject(this, (void *)parent);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = __vt__13TUnk_8048E6A8;
    ((VObj_18_1a504b *)(this))->m5(arg1);
    return ((u8 *)this);
}

TUnk_8048E6A8::~TUnk_8048E6A8() {

}

void TUnk_8048E6A8::run_task() {
    u8 *arg0 = (u8 *)this;
    uaddr player;

    player = (uaddr)get_player_by_client_id((local_client_id));
    if ((player != 0U) && (horizontal_distance_squared((const Vec *)(player + 0x38), (const Vec *)(arg0 + 0x38)) < 400.0f)) {
        if (this->scale.x > 0.0f) {
            lbl_805D2930 = 1;
            return;
        }
        lbl_805D2930 = 0;
    }
}

void TUnk_8048E6A8::render() {
    Obj_80085798 *self = (Obj_80085798 *)this;
    if (TObjPlayer::check_demo_mode() != 0) {
        NJS_ARGB color = { 0.5f, 0.0f, 1.0f, 1.0f };
        debug_draw_sphere((const Vec *)self->target, &color, 40.0f);
    }
}
