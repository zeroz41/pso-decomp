#include "types.h"
#include "pso/render/GinjaView.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/effect/sprite/TQuadSpriteNormal.h"
#include "pso/system/vector.h"
#include "pso/effect/sprite/TQuadSprite.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/unk/text_803D853C.h"

#pragma push
#pragma fp_contract on
void TQuadSpriteNormal::render() {
    QuadSpriteRect q;
    Vec out;
    Vec pos;
    u32 flags;
    f32 sw;
    f32 sh;
    f32 cx;
    f32 cy;
    f32 one;
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
    for (i = 0; i < definition->uv_count; i++) {
        const f32 *uv;
        n = lists[i].next;
        uv = definition->uvs[i];
        q.u0 = uv[0];
        q.v0 = uv[1];
        q.u1 = uv[2];
        q.v1 = uv[3];
        while (n != NULL) {
            f32 d, sx, sy, x, y, w, h;
            pos.x = n->pos.x + n->offset.x;
            pos.y = n->pos.y + n->offset.y;
            pos.z = n->pos.z + n->offset.z;
            if (n->type != 1) {
                matrix_mult_vec(0, &pos, &out);
                out.y = -out.y;
            } else {
                VecCopy(&out, &pos);
            }
            if (out.z <= one || n->type == 1) {
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
                q.x0 = x - w;
                q.x1 = x + w;
                q.y0 = y - h;
                q.y1 = y + h;
                draw_textured_quad_at_depth(&q.x0, d);
            }
            n = n->next;
        }
    }
    TWindowSubStatusDisp::get_player();
    TParticleCtrl::end_effect_render();
    quad_sprite_reset_entries();
    set_default_alpha_blend();
}
#pragma pop

TQuadSpriteNormal::~TQuadSpriteNormal() {
}

const char *quad_sprite_normal_class_name = "TQuadSpriteNormal";

TQuadSpriteNormal::TQuadSpriteNormal(TObject *parent, ParticleDefinition *sprite_definition)
    : TQuadSprite(parent, sprite_definition) {
    m_name = quad_sprite_normal_class_name;
}
