#include "types.h"
#include "pso/render/GinjaView.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/effect/sprite/TQuadSpriteCol.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_804C57F0.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/unk/text_803D853C.h"

#pragma readonly_strings on

typedef struct Col_801E4FF0 { f32 r, g, b, a; } Col_801E4FF0;

typedef struct Quad_801E4FF0 { f32 x0, y0, x1, y1; Col_801E4FF0 col; } Quad_801E4FF0;

typedef struct Node_801E4FF0 {
    struct Node_801E4FF0 *next;
    Vec pos;
    Vec ofs;
    u8 pad1C[0x24 - 0x1C];
    s32 tex;
    u8 pad28;
    u8 type;
} Node_801E4FF0;

typedef struct List_801E4FF0 { Node_801E4FF0 *head; u8 pad[0x28]; } List_801E4FF0;

typedef struct Self_801E4FF0 {
    u8 pad0[0x1C];
    List_801E4FF0 *lists;
    u8 pad20[0x8];
    ParticleDefinition *definition;
} Self_801E4FF0;


void TUnk_804C57F0::render() {  }


#pragma push
#pragma fp_contract on
void TQuadSpriteCol::render() {
    Self_801E4FF0 *self = (Self_801E4FF0 *)this;
    Quad_801E4FF0 q;
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
    Node_801E4FF0 *n;
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
    sw = screen_projection.distance;
    cx = screen_projection.center_x;
    cy = screen_projection.center_y;
    sh = sw * (480.0f / (480.0f * screen_projection.width));
    TParticleCtrl::begin_effect_render();
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(self->definition->texlist));
    set_draw_texture_and_color(self->definition->texture, self->definition->color);
    one = 1.0f;
    for (i = 0, ci = 0, li = 0; i < self->definition->uv_count; i++, ci += 0x10, li += 0x2C) {
        Col_801E4FF0 *c = (Col_801E4FF0 *)((u8 *)self->definition->uvs + ci);
        n = *(Node_801E4FF0 **)((u8 *)self->lists + li);
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
            if (out.z >= one || (s32)n->type == 1) {
                set_constant_material_color(n->tex);
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
        TWindowSubStatusDisp::get_player();
    }
    TParticleCtrl::end_effect_render();
    ((TUnk_804C57F0 *)self)->quad_sprite_reset_entries();
    set_default_alpha_blend();
}
#pragma pop
TQuadSpriteCol::~TQuadSpriteCol() {

}


const char *TQuadSpriteCol__class_name = "TQuadSpriteCol";

#define quad_sprite_col ((u8 *)this)
TQuadSpriteCol::TQuadSpriteCol(TObject *parent, ParticleDefinition *sprite_definition) : TUnk_804C57F0(parent, sprite_definition) {
    ((TQuadSpriteCol *)quad_sprite_col)->m_name = TQuadSpriteCol__class_name;
}
#undef quad_sprite_col
