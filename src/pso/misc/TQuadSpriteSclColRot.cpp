#include "types.h"
#include "pso/misc/TQuadSpriteSclColRot.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80141D1C.h"

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

struct QuadSpriteUV {
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
};

struct QuadSpriteDesc {
    u32 flags;
    s32 texture_list;
    s32 texture;
    s32 count;
    QuadSpriteUV *uvs;
    f32 w;
    f32 h;
    s32 color;
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

void quad_sprite_base_ct(void *);
void transform_point_by_current_matrix(Vec *in, Vec *out);
f32 sin_table_lookup(s32 angle);
f32 cos_table_lookup(s32 angle);
extern SpriteCamera lbl_8058D4F8;

extern s32 __vt__20TQuadSpriteSclColRot[];

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
    flags = ((QuadSpriteDesc *)m_28)->flags;
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
    sh = sw * (480.0f / (480.0f * lbl_8058D4F8.aspect));
    TParticleCtrl::begin_effect_render();
    begin_screen_draw(1);
    TObjFish::set_global_param(((QuadSpriteDesc *)m_28)->texture_list);
    set_draw_texture_and_color(((QuadSpriteDesc *)m_28)->texture, ((QuadSpriteDesc *)m_28)->color);
    one = -1.0f;
    zero = 0.0f;
    for (i = 0; i < ((QuadSpriteDesc *)m_28)->count; i++) {
        QuadSpriteUV *uv;
        n = (*(QuadSpriteList **)unk_1C)[i].head;
        uv = &((QuadSpriteDesc *)m_28)->uvs[i];
        q.u = uv->u0;
        q.v = uv->v0;
        q.uw = uv->u1 - uv->u0;
        q.ux = zero;
        q.vx = zero;
        q.vh = uv->v1 - uv->v0;
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
                w *= ((QuadSpriteDesc *)m_28)->w;
                h *= ((QuadSpriteDesc *)m_28)->h;
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

extern void *TQuadSpriteSclColRot__class_name;

void *TQuadSpriteSclColRot__ct(void *quad_sprite_scl_col_rot) {
    quad_sprite_base_ct(quad_sprite_scl_col_rot);
    *(s32 **)((s8 *)quad_sprite_scl_col_rot + 0x18) = __vt__20TQuadSpriteSclColRot;
    *(void * *)&((TQuadSpriteSclColRot *)quad_sprite_scl_col_rot)->m_name = TQuadSpriteSclColRot__class_name;
    return quad_sprite_scl_col_rot;
}
