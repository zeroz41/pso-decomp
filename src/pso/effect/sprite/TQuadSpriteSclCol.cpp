#include "types.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/effect/sprite/TQuadSpriteSclCol.h"

#include "pso/system/vector.h"
#include "pso/unk/TUnk_804C57F0.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/MatrixStack.h"

typedef struct Col_801E5C24 { f32 r, g, b, a; } Col_801E5C24;

typedef struct Quad_801E5C24 { f32 x0, y0, x1, y1; Col_801E5C24 col; } Quad_801E5C24;

typedef struct Node_801E5C24 {
    struct Node_801E5C24 *next;
    Vec pos;
    Vec ofs;
    f32 sx;
    f32 sy;
    s32 tex;
    u8 pad28;
    u8 type;
} Node_801E5C24;

typedef struct List_801E5C24 { Node_801E5C24 *head; u8 pad[0x28]; } List_801E5C24;

typedef struct Self_801E5C24 {
    u8 pad0[0x1C];
    List_801E5C24 *lists;
    u8 pad20[0x4];
    s32 active;
    ParticleDefinition *definition;
} Self_801E5C24;

typedef struct Cam_801E5C24 { u8 pad0[8]; f32 cx; f32 cy; u8 pad10[8]; f32 sw; f32 aspect; } Cam_801E5C24;

extern Cam_801E5C24 lbl_8058D4F8;


#pragma push
#pragma fp_contract on
extern "C" void render__17TQuadSpriteSclColFv(Self_801E5C24 *self) {
    Quad_801E5C24 q;
    Vec out;
    Vec pos;
    u32 flags;
    f32 one;
    f32 sw;
    f32 sh;
    f32 cx;
    f32 cy;
    s32 ci;
    s32 li;
    s32 i;
    Node_801E5C24 *n;
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
        Col_801E5C24 *c = (Col_801E5C24 *)((u8 *)self->definition->uvs + ci);
        n = *(Node_801E5C24 **)((u8 *)self->lists + li);
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
                transform_point_by_current_matrix(&pos.x, &out);
                out.y = -out.y;
            } else {
                VecCopy((Vec *)&out, (const Vec *)&pos);
            }
            if (out.z <= one || (s32)n->type == 1) {
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
                w *= n->sx;
                h *= n->sy;
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
TQuadSpriteSclCol::~TQuadSpriteSclCol() {

}


const char *TQuadSpriteSclCol__class_name = "TQuadSpriteSclCol";

#define quad_sprite_scl_col ((u8 *)this)
TQuadSpriteSclCol::TQuadSpriteSclCol(TObject *parent, ParticleDefinition *sprite_definition) : TUnk_804C57F0(parent, sprite_definition) {
    ((TQuadSpriteSclCol *)quad_sprite_scl_col)->m_name = TQuadSpriteSclCol__class_name;
}
#undef quad_sprite_scl_col
