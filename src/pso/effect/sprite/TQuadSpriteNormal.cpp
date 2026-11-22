#include "types.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/effect/sprite/TQuadSpriteNormal.h"

#include "pso/system/vector.h"
#include "pso/unk/TUnk_804C57F0.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/unk/text_803D853C.h"

typedef struct Col_801E5598 { f32 r, g, b, a; } Col_801E5598;

typedef struct Quad_801E5598 { f32 x0, y0, x1, y1; Col_801E5598 col; } Quad_801E5598;

typedef struct Node_801E5598 {
    struct Node_801E5598 *next;
    Vec pos;
    Vec ofs;
    u8 pad1C[0x24 - 0x1C];
    s32 tex;
    u8 pad28;
    u8 type;
} Node_801E5598;

typedef struct List_801E5598 { Node_801E5598 *head; u8 pad[0x28]; } List_801E5598;

typedef struct Self_801E5598 {
    u8 pad0[0x1C];
    List_801E5598 *lists;
    u8 pad20[0x4];
    s32 active;
    ParticleDefinition *definition;
} Self_801E5598;

typedef struct Cam_801E5598 { u8 pad0[8]; f32 cx; f32 cy; u8 pad10[8]; f32 sw; f32 aspect; } Cam_801E5598;

extern Cam_801E5598 lbl_8058D4F8;

#pragma push
#pragma fp_contract on
extern "C" void render__17TQuadSpriteNormalFv(Self_801E5598 *self) {
    Quad_801E5598 q;
    Vec out;
    Vec pos;
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
    flags = self->definition->flags;
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
    sw = lbl_8058D4F8.sw;
    cx = lbl_8058D4F8.cx;
    cy = lbl_8058D4F8.cy;
    sh = sw * (480.0f / (480.0f * lbl_8058D4F8.aspect));
    TParticleCtrl::begin_effect_render();
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(self->definition->texlist));
    set_draw_texture_and_color(self->definition->texture, self->definition->color);
    one = -1.0f;
    for (i = 0, ci = 0, li = 0; i < self->definition->uv_count; i++, ci += 0x10, li += 0x2C) {
        Col_801E5598 *c = (Col_801E5598 *)((u8 *)self->definition->uvs + ci);
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
                    d = 1.0f / -out.z;
                    sx = sh * d;
                    sy = sw * d;
                    x = out.x * sx + cx;
                    y = out.y * sy + cy;
                    w = sx;
                    h = sy;
                } else {
                    h = w = 1.0f;
                    d = out.z;
                    x = out.x;
                    y = out.y;
                }
                w *= self->definition->width;
                h *= self->definition->height;
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
TQuadSpriteNormal::~TQuadSpriteNormal() {

}


const char *TQuadSpriteNormal__class_name = "TQuadSpriteNormal";

#define quad_sprite_normal ((u8 *)this)
TQuadSpriteNormal::TQuadSpriteNormal(TObject *parent, ParticleDefinition *sprite_definition) : TUnk_804C57F0(parent, sprite_definition) {
    ((TQuadSpriteNormal *)quad_sprite_normal)->m_name = TQuadSpriteNormal__class_name;
}
#undef quad_sprite_normal
