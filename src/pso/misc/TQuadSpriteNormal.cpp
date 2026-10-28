#include "types.h"
#include "pso/misc/TQuadSpriteNormal.h"

#include "pso/system/vector.h"
#include "pso/unk/TUnk_804C57F0.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80141D1C.h"

typedef struct Vec_801E5598 { f32 x, y, z; } Vec_801E5598;

typedef struct Col_801E5598 { f32 r, g, b, a; } Col_801E5598;

typedef struct Quad_801E5598 { f32 x0, y0, x1, y1; Col_801E5598 col; } Quad_801E5598;

typedef struct Node_801E5598 {
    struct Node_801E5598 *next;
    Vec_801E5598 pos;
    Vec_801E5598 ofs;
    u8 pad1C[0x24 - 0x1C];
    s32 tex;
    u8 pad28;
    u8 type;
} Node_801E5598;

typedef struct List_801E5598 { Node_801E5598 *head; u8 pad[0x28]; } List_801E5598;

typedef struct Desc_801E5598 {
    u32 flags;
    s32 param4;
    s32 param8;
    s32 count;
    Col_801E5598 *cols;
    f32 w;
    f32 h;
    s32 param1C;
} Desc_801E5598;

typedef struct Self_801E5598 {
    u8 pad0[0x1C];
    List_801E5598 *lists;
    u8 pad20[0x4];
    s32 active;
    Desc_801E5598 *desc;
} Self_801E5598;

typedef struct Cam_801E5598 { u8 pad0[8]; f32 cx; f32 cy; u8 pad10[8]; f32 sw; f32 aspect; } Cam_801E5598;

extern "C" {
void fn_80141EB4(void);
}
void setSpriteInverseColorBlend(void);
extern "C" {
s32 matrix_mult_vec(int, void *, void *);
void begin_screen_draw(s32 arg0);
void draw_textured_quad_at_depth(f32 *q, f32 depth);
void set_draw_texture_and_color(s32 idx, s32 arg1);
extern Cam_801E5598 lbl_8058D4F8;
extern const f32 lbl_805DC460;
extern const f32 lbl_805DC464;
extern const f32 lbl_805DC468;
void render__17TQuadSpriteNormalFv(Self_801E5598 *self);
void *TQuadSpriteNormal__ct(void *arg0);
void quad_sprite_base_ct(void *);

extern s32 __vt__17TQuadSpriteNormal[];

#pragma push
#pragma fp_contract on
void render__17TQuadSpriteNormalFv(Self_801E5598 *self) {
    Quad_801E5598 q;
    Vec_801E5598 out;
    Vec_801E5598 pos;
    u32 flags;
    f32 sw;
    f32 sh;
    f32 cx;
    f32 cy;
    f32 one;
    s32 ci;
    s32 li;
    s32 i;
    Node_801E5598 *n;
    if (self->active == 0) {
        return;
    }
    flags = self->desc->flags;
    if (flags & 2) {
        if (flags & 4) {
            fn_80141EB4();
        } else {
            set_default_alpha_blend();
        }
    } else if (flags & 4) {
        setSpriteInverseColorBlend();
    } else {
        set_additive_blend();
    }
    sw = lbl_8058D4F8.sw;
    cx = lbl_8058D4F8.cx;
    cy = lbl_8058D4F8.cy;
    sh = sw * (lbl_805DC460 / (lbl_805DC460 * lbl_8058D4F8.aspect));
    TParticleCtrl::begin_effect_render();
    begin_screen_draw(1);
    TObjFish::set_global_param((s32)((void *)self->desc->param4));
    set_draw_texture_and_color(self->desc->param8, self->desc->param1C);
    one = lbl_805DC464;
    for (i = 0, ci = 0, li = 0; i < self->desc->count; i++, ci += 0x10, li += 0x2C) {
        Col_801E5598 *c = (Col_801E5598 *)((u8 *)self->desc->cols + ci);
        n = *(Node_801E5598 **)((u8 *)self->lists + li);
        q.col.r = c->r;
        q.col.g = c->g;
        q.col.b = c->b;
        q.col.a = c->a;
        while (n != NULL) {
            f32 d, sx, sy, x, y, w, h;
            pos.x = n->pos.x + n->ofs.x;
            pos.y = n->pos.y + n->ofs.y;
            pos.z = n->pos.z + n->ofs.z;
            if ((s32)n->type != 1) {
                matrix_mult_vec(0, &pos, &out);
                out.y = -out.y;
            } else {
                VecCopy((Vec *)&out, (const Vec *)&pos);
            }
            if (out.z <= one || (s32)n->type == 1) {
                if ((s32)n->type != 1) {
                    d = lbl_805DC468 / -out.z;
                    sx = sh * d;
                    sy = sw * d;
                    x = out.x * sx + cx;
                    y = out.y * sy + cy;
                    w = sx;
                    h = sy;
                } else {
                    h = w = lbl_805DC468;
                    d = out.z;
                    x = out.x;
                    y = out.y;
                }
                w *= self->desc->w;
                h *= self->desc->h;
                q.x0 = x - w;
                q.x1 = x + w;
                q.y0 = y - h;
                q.y1 = y + h;
                draw_textured_quad_at_depth((f32 *)&q, d);
            }
            n = n->next;
        }
    }
    TWindowSubStatusDisp::get_player();
    TParticleCtrl::end_effect_render();
    ((TUnk_804C57F0 *)self)->quad_sprite_reset_entries();
    set_default_alpha_blend();
}
#pragma pop

}
TQuadSpriteNormal::~TQuadSpriteNormal() {

}


extern void *TQuadSpriteNormal__class_name;

void *TQuadSpriteNormal__ct(void *quad_sprite_normal) {
    quad_sprite_base_ct(quad_sprite_normal);
    *(s32 **)((s8 *)quad_sprite_normal + 0x18) = __vt__17TQuadSpriteNormal;
    *(void * *)&((TQuadSpriteNormal *)quad_sprite_normal)->m_name = TQuadSpriteNormal__class_name;
    return quad_sprite_normal;
}
