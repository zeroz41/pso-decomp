#include "types.h"
#include "pso/render/GinjaView.h"
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
#include "pso/system/MatrixStack.h"

#pragma push
#pragma fp_contract on
void TQuadSpriteSclColRot::render() {
    RotatedQuadSpriteRect q;
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

    if (queued == 0) {
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
    sw = screen_projection.distance;
    cx = screen_projection.center_x;
    cy = screen_projection.center_y;
    sh = sw * (480.0f / (480.0f * screen_projection.width));
    TParticleCtrl::begin_effect_render();
    begin_screen_draw(1);
    TObjFish::set_global_param(definition->texlist);
    set_draw_texture_and_color(definition->texture, definition->color);
    one = -1.0f;
    zero = 0.0f;
    for (i = 0; i < definition->uv_count; i++) {
        const f32 *uv;
        n = lists[i].next;
        uv = definition->uvs[i];
        q.u = uv[0];
        q.v = uv[1];
        q.edge_a_u = uv[2] - uv[0];
        q.edge_a_v = zero;
        q.edge_b_u = zero;
        q.edge_b_v = uv[3] - uv[1];
        while (n != NULL) {
            f32 sx, sy;
            pos.x = n->pos.x + n->offset.x;
            pos.y = n->pos.y + n->offset.y;
            pos.z = n->pos.z + n->offset.z;
            if (n->type != 1) {
                transform_point_by_current_matrix(&pos.x, &out);
                out.y = -out.y;
            } else {
                VecCopy(&out, &pos);
            }
            if (out.z <= one || n->type == 1) {
                set_constant_material_color(n->color);
                if (n->type != 1) {
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
                w *= n->scale_x;
                h *= n->scale_y;
                c = cos_table_lookup(n->angle);
                s = -sin_table_lookup(n->angle);
                q.depth = d;
                q.x = x - (w * c + h * s);
                q.y = y - (-w * s + h * c);
                w += w;
                h += h;
                q.edge_a_x = w * c;
                q.edge_a_y = -w * s;
                q.edge_b_x = h * s;
                q.edge_b_y = h * c;
                DVDConvertEntrynumToPath(&q.x);
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

const char *quad_sprite_scl_col_rot_class_name = "TQuadSpriteSclColRot";

TQuadSpriteSclColRot::TQuadSpriteSclColRot(TObject *parent, ParticleDefinition *sprite_definition)
    : TQuadSprite(parent, sprite_definition) {
    m_name = quad_sprite_scl_col_rot_class_name;
}
