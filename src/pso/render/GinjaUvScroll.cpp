#include <dolphin/os/OSCache.h>
#include "pso/ui/UISprite.h"
#include "types.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/render/GinjaModel.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/ui/window/ScreenQuadDraw.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/sprite/TQuadSpriteSclColRot.h"

s32 has_texture_scroll_entry(const GinjaDrawRecord *record, u16 id) {
    s32 found = 0;
    if (record != NULL) {
        const GinjaParameter *e = record->parameters;
        u32 i;
        for (i = 0; i < record->parameter_count; i++) {
            if (e->kind == 8 && id == (e->value & 0x1FFF)) {
                found = 1;
            }
            e++;
        }
    }
    return found;
}

void set_ginja_texture_wrap_repeat(GinjaDrawRecord *record) {
    if (record != NULL) {
        GinjaParameter *e = record->parameters;
        u32 i;
        for (i = 0; i < record->parameter_count; i++, e++) {
            if (e->kind == 8) {
                e->value &= ~0xC0000;
                e->value |= 0x40000;
                e->value &= ~0x30000;
                e->value |= 0x10000;
            }
        }
    }
}

void scroll_ginja_mesh_uvs(GinjaModel *model, s32 du, s32 dv, u16 cmd, s32 rewrite) {
    s32 found = 0;
    GinjaVertexArray *a;
    if (model->primary != 0 && has_texture_scroll_entry(model->primary, cmd) == 1) {
        found = 1;
        if (rewrite != 0) {
            set_ginja_texture_wrap_repeat(model->primary);
        }
    }
    if (model->secondary != 0 && has_texture_scroll_entry(model->secondary, cmd) == 1) {
        found = 1;
        if (rewrite != 0) {
            set_ginja_texture_wrap_repeat(model->secondary);
        }
    }
    if (found != 0) {
        for (a = model->vertices; a != 0 && a->attribute != 0xFF; a++) {
            if (a->attribute == 5 || a->attribute == 6) {
                u16 n = a->count;
                NJS_TEX *uv = static_cast<NJS_TEX *>(a->data);
                s32 i;
                for (i = 0; i < n; i++) {
                    uv->u = static_cast<s16>(static_cast<u32>(uv->u) + static_cast<u32>(du));
                    uv->v = static_cast<s16>(static_cast<u32>(uv->v) + static_cast<u32>(dv));
                    uv++;
                }
                DCFlushRangeNoSync(a->data, a->count * 4);
            }
        }
    }
}

void scroll_chunk_plist_uvs(s16 *p, s16 du, s16 dv, u16 texture_id) {
    s16 dy;
    s16 dx;
    s32 t;
    u16 n;
    s16 c;
    dx = du % 256;
    dy = dv % 256;
    while ((t = (u8)*p) != 0xFF) {
        if (t == 8 && (p[1] & 0x1FFF) == texture_id) {
            *p &= ~0x3000;
            advance_chunk_plist(&p);
            p += 2;
            n = *p & 0x1FFF;
            p++;
            while (n != 0) {
                c = *p;
                if (c < 0) {
                    c = -c;
                }
                p++;
                while (c != 0) {
                    c--;
                    *++p += dx;
                    *++p += dy;
                    p++;
                }
                n--;
            }
        } else {
            advance_chunk_plist(&p);
        }
    }
}

void advance_chunk_plist(s16 **plist) {
    s16 *p = *plist;
    s32 type = *p & 0xFF;
    if (type == 0xFF) {
        *plist = p + 1;
        return;
    }
    if ((s16)type == 0) {
        *plist = p + 1;
        return;
    }
    if ((s16)type == 1) {
        *plist = p + 1;
        return;
    }
    if ((s16)type == 2) {
        *plist = p + 1;
        return;
    }
    if ((s16)type == 3) {
        *plist = p + 1;
        return;
    }
    if ((s16)type == 5) {
        *plist = p + 1;
        return;
    }
    if ((s16)type == 4) {
        *plist = p + 1;
        return;
    }
    if ((s16)type == 8) {
        *plist = p + 2;
        return;
    }
    *plist = p + (p[1] + 2);
}
#pragma push
#pragma fp_contract on
void draw_compass_sprite(const NJS_SPRITE *sprite, s32 idx, s32 color, s32 flags, f32 depth) {
    CompassSpriteVertex v[4];
    RotatedQuadSpriteRect info;
    s32 i;
    const NJS_TEXANIM *s;
    f32 x;
    f32 y;
    f32 l;
    f32 t;
    f32 r;
    f32 b;
    f32 sn;
    f32 cs;
    f32 u0, v0, u1, v1;
    f32 cx, cy;
    for (i = 0; i < 4; i++) {
        v[i].z = 1.0f / -depth;
        v[i].color = color;
    }
    s = &sprite->tanim[idx];
    cx = s->cx;
    cy = s->cy;
    l = -cx * sprite->sx;
    t = -cy * sprite->sy;
    r = sprite->sx * (s->sx - cx);
    b = sprite->sy * (s->sy - cy);
    x = sprite->p.x;
    y = sprite->p.y;
    if (flags & 1) {
        sn = sin_table_lookup(sprite->ang);
        cs = cos_table_lookup(sprite->ang);
        v[0].x = (cs * l + x) + sn * t;
        v[1].x = (cs * l + x) + sn * b;
        v[2].x = (cs * r + x) + sn * t;
        v[3].x = (cs * r + x) + sn * b;
        v[0].y = (cs * t + y) - sn * l;
        v[1].y = (cs * b + y) - sn * l;
        v[2].y = (cs * t + y) - sn * r;
        v[3].y = (cs * b + y) - sn * r;
    } else {
        v[0].x = x + l;
        v[0].y = y + t;
        v[1].x = x + l;
        v[1].y = y + b;
        v[2].x = x + r;
        v[2].y = y + t;
        v[3].x = x + r;
        v[3].y = y + b;
    }
    u0 = (f32)s->u1 / 255.0f;
    v0 = (f32)s->v1 / 255.0f;
    u1 = (f32)s->u2 / 255.0f;
    v1 = (f32)s->v2 / 255.0f;
    v[0].u = u0;
    v[0].v = v0;
    v[1].u = u0;
    v[1].v = v1;
    v[2].u = u1;
    v[2].v = v0;
    v[3].u = u1;
    v[3].v = v1;
    info.x = v[0].x;
    info.y = v[0].y;
    info.depth = depth;
    info.edge_a_x = v[1].x - v[0].x;
    info.edge_a_y = v[1].y - v[0].y;
    info.edge_b_x = v[2].x - v[0].x;
    info.edge_b_y = v[2].y - v[0].y;
    info.u = v[0].u;
    info.v = v[0].v;
    info.edge_a_u = v[1].u - v[0].u;
    info.edge_a_v = v[1].v - v[0].v;
    info.edge_b_u = v[2].u - v[0].u;
    info.edge_b_v = v[2].v - v[0].v;
    if (flags & 0x20) {
        begin_screen_draw(1);
    } else {
        begin_screen_draw(0);
    }
    set_draw_texture_and_color(idx, color);
    draw_rotated_quad(&info.x);
    end_screen_draw();
}
#pragma pop
