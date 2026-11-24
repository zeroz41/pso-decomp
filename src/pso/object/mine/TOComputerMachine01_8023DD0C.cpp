#include "pso/ui/UISprite.h"
#include "types.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/render/GinjaModel.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/object/mine/TOComputerMachine01_8023DD0C.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/math/AngleLookup.h"

struct UV_8023DDC8 { s16 u; s16 v; };

struct Vtx_8023E0FC { f32 x, y, z, u, v; s32 color; };

struct Info_8023E0FC { f32 x, y, z; f32 dx1, dy1, dx2, dy2; f32 pad; f32 u, v, du1, dv1, du2, dv2; u8 pad2[8]; };

extern "C" {
void DCFlushRangeNoSync(void *, u32);

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

void scroll_ginja_mesh_uvs(GinjaModel *self, s32 du, s32 dv, u16 cmd, s32 rewrite) {
    s32 found = 0;
    GinjaVertexArray *a;
    if (self->primary != 0 && has_texture_scroll_entry(self->primary, cmd) == 1) {
        found = 1;
        if (rewrite != 0) {
            set_ginja_texture_wrap_repeat(self->primary);
        }
    }
    if (self->secondary != 0 && has_texture_scroll_entry(self->secondary, cmd) == 1) {
        found = 1;
        if (rewrite != 0) {
            set_ginja_texture_wrap_repeat(self->secondary);
        }
    }
    if (found != 0) {
        for (a = self->vertices; a != 0 && a->attribute != 0xFF; a++) {
            if (a->attribute == 5 || a->attribute == 6) {
                u16 n = a->count;
                UV_8023DDC8 *uv = static_cast<UV_8023DDC8 *>(a->data);
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

void TObjPlayer__sub_8023DEE0(s16 *p, s16 a, s16 b, u16 id) {
    s16 dy;
    s16 dx;
    s32 t;
    u16 n;
    s16 c;
    dx = a % 256;
    dy = b % 256;
    while ((t = (u8)*p) != 0xFF) {
        if (t == 8 && (p[1] & 0x1FFF) == id) {
            *p &= ~0x3000;
            TObjPlayer__sub_8023E034((void **)&p);
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
            TObjPlayer__sub_8023E034((void **)&p);
        }
    }
}

void TObjPlayer__sub_8023E034(void **arg0) {
    s16 temp_r0;
    u8 *temp_r5;
    temp_r5 = (u8 *)(*(u8 **)((s8 *)arg0 + 0));
    temp_r0 = *(s16 *)((s8 *)temp_r5 + 0);
    if ((s32) (u8) temp_r0 == 0xFF) {
        *(u8 **)((s8 *)arg0 + 0) = temp_r5 + 2;
        return;
    }
    if ((s16) (u8) temp_r0 == 0) {
        *(u8 **)((s8 *)arg0 + 0) = temp_r5 + 2;
        return;
    }
    if ((s16) (u8) temp_r0 == 1) {
        *(u8 **)((s8 *)arg0 + 0) = temp_r5 + 2;
        return;
    }
    if ((s16) (u8) temp_r0 == 2) {
        *(u8 **)((s8 *)arg0 + 0) = temp_r5 + 2;
        return;
    }
    if ((s16) (u8) temp_r0 == 3) {
        *(u8 **)((s8 *)arg0 + 0) = temp_r5 + 2;
        return;
    }
    if ((s16) (u8) temp_r0 == 5) {
        *(u8 **)((s8 *)arg0 + 0) = temp_r5 + 2;
        return;
    }
    if ((s16) (u8) temp_r0 == 4) {
        *(u8 **)((s8 *)arg0 + 0) = temp_r5 + 2;
        return;
    }
    if ((s16) (u8) temp_r0 == 8) {
        *(u8 **)((s8 *)arg0 + 0) = temp_r5 + 4;
        return;
    }
    *(u8 **)((s8 *)arg0 + 0) = temp_r5 + ((*(s16 *)((s8 *)temp_r5 + 2) + 2) * 2);
}
#pragma push
#pragma fp_contract on
void draw_compass_sprite(const NJS_SPRITE *sprite, s32 idx, s32 color, s32 flags, f32 depth) {
    Vtx_8023E0FC v[4];
    Info_8023E0FC info;
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
    info.z = depth;
    info.dx1 = v[1].x - v[0].x;
    info.dy1 = v[1].y - v[0].y;
    info.dx2 = v[2].x - v[0].x;
    info.dy2 = v[2].y - v[0].y;
    info.u = v[0].u;
    info.v = v[0].v;
    info.du1 = v[1].u - v[0].u;
    info.dv1 = v[1].v - v[0].v;
    info.du2 = v[2].u - v[0].u;
    info.dv2 = v[2].v - v[0].v;
    if (flags & 0x20) {
        begin_screen_draw(1);
    } else {
        begin_screen_draw(0);
    }
    set_draw_texture_and_color(idx, color);
    DVDConvertEntrynumToPath((f32 *)&info);
    TWindowSubStatusDisp::get_player();
}
#pragma pop

}
