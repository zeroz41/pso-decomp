#include "types.h"
#include "pso/object/mine/TOComputerMachine01_8023DD0C.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/math/AngleLookup.h"

struct Ent_8023DD0C { u8 type; u8 pad[3]; u32 f4; };

struct Tbl_8023DD0C { Ent_8023DD0C *entries; u32 count; };

struct Ent_8023DD60 { u8 type; u8 pad[3]; u32 f4; };

struct Tbl_8023DD60 { Ent_8023DD60 *entries; u32 count; };

struct UV_8023DDC8 { s16 u; s16 v; };

struct Arr_8023DDC8 { u8 type; u8 pad; u16 count; u8 pad2[4]; UV_8023DDC8 *uv; u8 pad3[4]; };

struct Model_8023DDC8 { Arr_8023DDC8 *arrays; u8 pad[4]; void *s0; void *s1; };

struct Spr_8023E0FC { s16 x0, y0, cx, cy, u0, v0, u1, v1; u8 pad[4]; };

struct Self_8023E0FC { f32 x, y; u8 pad8[4]; f32 sx, sy; s32 rot; u8 pad18[4]; Spr_8023E0FC *sprs; };

struct Vtx_8023E0FC { f32 x, y, z, u, v; s32 color; };

struct Info_8023E0FC { f32 x, y, z; f32 dx1, dy1, dx2, dy2; f32 pad; f32 u, v, du1, dv1, du2, dv2; u8 pad2[8]; };

extern "C" {
s32 has_texture_scroll_entry(Tbl_8023DD0C *t, u16 id);
void set_ginja_texture_wrap_repeat(Tbl_8023DD60 *t);
void DCFlushRangeNoSync(void *, u32);
void scroll_ginja_mesh_uvs(Model_8023DDC8 *self, s16 du, s16 dv, u16 cmd, s32 rewrite);

s32 has_texture_scroll_entry(Tbl_8023DD0C *t, u16 id) {
    s32 found = 0;
    if (t != 0) {
        Ent_8023DD0C *e = t->entries;
        u32 i;
        for (i = 0; i < t->count; i++) {
            if (e->type == 8 && id == (e->f4 & 0x1FFF)) {
                found = 1;
            }
            e++;
        }
    }
    return found;
}

void set_ginja_texture_wrap_repeat(Tbl_8023DD60 *t) {
    if (t != 0) {
        Ent_8023DD60 *e = t->entries;
        u32 i;
        for (i = 0; i < t->count; i++, e++) {
            if (e->type == 8) {
                e->f4 &= ~0xC0000;
                e->f4 |= 0x40000;
                e->f4 &= ~0x30000;
                e->f4 |= 0x10000;
            }
        }
    }
}

void scroll_ginja_mesh_uvs(Model_8023DDC8 *self, s16 du, s16 dv, u16 cmd, s32 rewrite) {
    s32 found = 0;
    Arr_8023DDC8 *a;
    if (self->s0 != 0 && has_texture_scroll_entry((Tbl_8023DD0C *)(self->s0), cmd) == 1) {
        found = 1;
        if (rewrite != 0) {
            set_ginja_texture_wrap_repeat((Tbl_8023DD60 *)(self->s0));
        }
    }
    if (self->s1 != 0 && has_texture_scroll_entry((Tbl_8023DD0C *)(self->s1), cmd) == 1) {
        found = 1;
        if (rewrite != 0) {
            set_ginja_texture_wrap_repeat((Tbl_8023DD60 *)(self->s1));
        }
    }
    if (found != 0) {
        for (a = self->arrays; a != 0 && a->type != 0xFF; a++) {
            if (a->type == 5 || a->type == 6) {
                u16 n = a->count;
                UV_8023DDC8 *uv = a->uv;
                s32 i;
                for (i = 0; i < n; i++) {
                    uv->u += du;
                    uv->v += dv;
                    uv++;
                }
                DCFlushRangeNoSync(a->uv, a->count * 4);
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
void TObjPlayer::draw_compass_sprite(s32 idx, s32 color, s32 flags, f32 z) {
    Self_8023E0FC *self = (Self_8023E0FC *)this;
    Vtx_8023E0FC v[4];
    Info_8023E0FC info;
    s32 i;
    Spr_8023E0FC *s;
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
        v[i].z = 1.0f / -z;
        v[i].color = color;
    }
    s = &self->sprs[idx];
    cx = s->cx;
    cy = s->cy;
    l = -cx * self->sx;
    t = -cy * self->sy;
    r = self->sx * (s->x0 - cx);
    b = self->sy * (s->y0 - cy);
    x = self->x;
    y = self->y;
    if (flags & 1) {
        sn = sin_table_lookup(self->rot);
        cs = cos_table_lookup(self->rot);
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
    u0 = (f32)s->u0 / 255.0f;
    v0 = (f32)s->v0 / 255.0f;
    u1 = (f32)s->u1 / 255.0f;
    v1 = (f32)s->v1 / 255.0f;
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
    info.z = z;
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
