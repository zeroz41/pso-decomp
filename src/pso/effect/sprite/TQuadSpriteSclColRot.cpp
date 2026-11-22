#include "types.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/effect/sprite/TQuadSpriteSclColRot.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/math/AngleLookup.h"

struct QuadSpriteNode {
    QuadSpriteNode *next;
    Vec pos;
    Vec ofs;
    f32 sx;
    f32 sy;
    u32 color;
    u8 pad28;
    u8 type;
    s16 angle;
};

struct QuadSpriteList {
    QuadSpriteNode *head;
    u8 pad4[0x28];
};

struct RotatedSpriteQuad {
    f32 x;
    f32 y;
    f32 z;
    f32 ax;
    f32 ay;
    f32 bx;
    f32 by;
    u32 pad1C;
    f32 u;
    f32 v;
    f32 uw;
    f32 ux;
    f32 vx;
    f32 vh;
    f32 m_38;
    f32 m_3c;
};

struct SpriteCamera {
    u8 pad0[8];
    f32 cx;
    f32 cy;
    u8 pad10[8];
    f32 sw;
    f32 aspect;
};

extern "C" {

void transform_point_by_current_matrix(Vec *in, Vec *out);
extern SpriteCamera screen_projection;


}
#pragma push
#pragma fp_contract on
void TQuadSpriteSclColRot::render() {
    RotatedSpriteQuad q;
    Vec out;
    Vec pos;
    u32 flags;
    f32 c;
    f32 one;
    f32 zero;
    f32 sw;
    f32 s;
    f32 d;
    f32 sh;
    f32 cx;
    f32 cy;
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    s32 i;
    QuadSpriteNode *n;

    if (*(s32 *)unk_24 == 0) {
        return;
    }
    flags = definition->flags;
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
    sw = screen_projection.sw;
    cx = screen_projection.cx;
    cy = screen_projection.cy;
    sh = sw * (480.0f / (480.0f * screen_projection.aspect));
    TParticleCtrl::begin_effect_render();
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(definition->texlist));
    set_draw_texture_and_color(definition->texture, definition->color);
    one = -1.0f;
    zero = 0.0f;
    for (i = 0; i < definition->uv_count; i++) {
        const f32 *uv;
        n = (*(QuadSpriteList **)unk_1C)[i].head;
        uv = definition->uvs[i];
        q.u = uv[0];
        q.v = uv[1];
        q.uw = uv[2] - uv[0];
        q.ux = zero;
        q.vx = zero;
        q.vh = uv[3] - uv[1];
        while (n != NULL) {
            f32 sx, sy;
            pos.x = n->pos.x + n->ofs.x;
            pos.y = n->pos.y + n->ofs.y;
            pos.z = n->pos.z + n->ofs.z;
            if ((s32)n->type != 1) {
                transform_point_by_current_matrix(&pos, &out);
                out.y = -out.y;
            } else {
                VecCopy(&out, &pos);
            }
            if (out.z <= one || (s32)n->type == 1) {
                set_constant_material_color(n->color);
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
                w *= definition->width;
                h *= definition->height;
                w *= n->sx;
                h *= n->sy;
                c = cos_table_lookup(n->angle);
                s = -sin_table_lookup(n->angle);
                q.z = d;
                q.x = x - (w * c + h * s);
                q.y = y - (-w * s + h * c);
                w += w;
                h += h;
                q.ax = w * c;
                q.ay = -w * s;
                q.bx = h * s;
                q.by = h * c;
                DVDConvertEntrynumToPath((f32 *)&q);
            }
            n = n->next;
        }
        TWindowSubStatusDisp::get_player();
    }
    TParticleCtrl::end_effect_render();
    quad_sprite_reset_entries();
    set_default_alpha_blend();
}
#pragma pop

TQuadSpriteSclColRot::~TQuadSpriteSclColRot() {

}

const char *TQuadSpriteSclColRot__class_name = "TQuadSpriteSclColRot";

#define quad_sprite_scl_col_rot ((u8 *)this)
TQuadSpriteSclColRot::TQuadSpriteSclColRot(TObject *parent, ParticleDefinition *sprite_definition) : TUnk_804C57F0(parent, sprite_definition) {
    ((TQuadSpriteSclColRot *)quad_sprite_scl_col_rot)->m_name = TQuadSpriteSclColRot__class_name;
}
#undef quad_sprite_scl_col_rot
