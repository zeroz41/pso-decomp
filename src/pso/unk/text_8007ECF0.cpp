#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/MenuText.h"
#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_8007ECF0.h"
#include "pso/render/TDLGraph.h"
#include "pso/object/warp/TObjWarpString.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

#include <stdio.h>

struct E_8007F3F8 { s32 a; f32 f; };

struct O_8007F3F8 { u8 pad[0x40]; s32 count; E_8007F3F8 e[4]; };

extern "C" {
s32 fn_8007F3F8(O_8007F3F8 *arg0, f32 farg0);
struct Obj_8007F0E4 {
    u8 pad0[0x1C];
    f32 f1C;
    u32 flags;
    s32 f24;
    u8 pad28[4];
    s32 time;
    s32 f30;
};

s32 fn_8007F4B8(void *, s32, f32);

extern char lbl_80438AE0[];
extern char lbl_80438AEC[];

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
void fn_8007ECF0(u8 *arg0, s32 arg1, s32 arg2) {
    f32 temp_f1;
    s32 temp_r0_2;
    s32 temp_r3;
    s32 var_r3;
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) ((f32) arg1 / (f32) arg2);
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x1C);
    if (temp_f1 < 0.0f) {
        *(f32 *)((s8 *)arg0 + 0x1C) = 0.0f;
    } else if (temp_f1 > 1.0f) {
        *(f32 *)((s8 *)arg0 + 0x1C) = 1.0f;
    }
    if (((s32) *(s32 *)((s8 *)arg0 + 0x28) != 0) && (fn_8007F4B8(arg0, *(s32 *)((s8 *)arg0 + 0x24), *(f32 *)((s8 *)arg0 + 0x1C)) != 0)) {
        temp_r3 = fn_8007F3F8((O_8007F3F8 *)(arg0), *(f32 *)((s8 *)arg0 + 0x1C));
        if (temp_r3 >= 0) {
            var_r3 = temp_r3 + (s32) ((30.0f * ((f32) temp_r3 / 1800.0f)) + 30.0f);
            if (var_r3 > 0x464F) {
                var_r3 = 0x464F;
            }
            switch (*(s32 *)((s8 *)arg0 + 0x28)) {
            case 0:
                break;
            case -1:
                if (var_r3 >= 0x12C) {
                    *(s32 *)((s8 *)arg0 + 0x28) = 1;
                    *(s32 *)((s8 *)arg0 + 0x2C) = var_r3;
                    *(s32 *)((s8 *)arg0 + 0x30) = (s32) *(s32 *)((s8 *)arg0 + 0x24);
                }
                break;
            case 1:
                temp_r0_2 = *(s32 *)((s8 *)arg0 + 0x2C);
                if (temp_r0_2 > var_r3) {
                    *(s32 *)((s8 *)arg0 + 0x2C) = var_r3;
                } else if ((s32) (var_r3 - temp_r0_2) >= 0x4B) {
                    *(s32 *)((s8 *)arg0 + 0x2C) = var_r3;
                }
                *(s32 *)((s8 *)arg0 + 0x30) = (s32) *(s32 *)((s8 *)arg0 + 0x24);
                break;
            }
        }
    }
    if (1.0f == *(f32 *)((s8 *)arg0 + 0x1C)) {
        ((TObject *)arg0)->queue_destruction();
    }
}
#pragma pop


void draw_outlined_string_right_aligned__14TObjWarpStringFPviiPv(void *, s32 x0, s32 y0, char *str) {
    f32 x;
    f32 y;
    f32 xr;
    f32 yb;

    x = (f32)(u32)(x0 - calc_text_width(str));
    y = (f32)y0;
    draw_menu_text(x - 2.0f, y - 2.0f, str, 0xFF000000);
    draw_menu_text(x, y - 2.0f, str, 0xFF000000);
    xr = 2.0f + x;
    draw_menu_text(xr, y - 2.0f, str, 0xFF000000);
    draw_menu_text(x - 2.0f, y, str, 0xFF000000);
    draw_menu_text(xr, y, str, 0xFF000000);
    yb = 2.0f + y;
    draw_menu_text(x - 2.0f, yb, str, 0xFF000000);
    draw_menu_text(x, yb, str, 0xFF000000);
    draw_menu_text(xr, yb, str, 0xFF000000);
    draw_menu_text(x, y, str, 0xFFFFFFFF);
}

void TDLGraph::draw_percent_text(f32 farg0, f32 farg1) {
    char text[8];
    s32 var_r5;

    if (this->m_20 & 2) {
        text[0] = '\0';
        var_r5 = (s32) (100.0f * this->m_1c);
        if (var_r5 < 0) {
            var_r5 = 0;
        } else if (var_r5 > 0x64) {
            var_r5 = 0x64;
        }
        sprintf(text, "%3d%", var_r5);
        draw_outlined_string_right_aligned__14TObjWarpStringFPviiPv(this, (s32) farg0, (s32) farg1, text);
    }
}

#pragma push
#pragma opt_propagation off
void TDLGraph::draw_countdown_timer(f32 x, f32 y) {
    Obj_8007F0E4 *self = (Obj_8007F0E4 *)this;
    char buf[16];
    s32 t;
    s32 mins;
    s32 secs;
    s32 frac;
    f32 r;
    f32 k;

    if (!(self->flags & 1)) {
        return;
    }
    buf[0] = 0;
    t = self->time;
    if (t <= 0) {
        return;
    }
    mins = t / 1800;
    secs = (t / 30) % 60;
    frac = (t % 30) / 3;
    if (mins > 0) {
        sprintf(buf, lbl_80438AE0, mins, secs, frac);
    } else {
        sprintf(buf, lbl_80438AEC, secs, frac);
    }
    draw_outlined_string_right_aligned__14TObjWarpStringFPviiPv(self, (s32)x, (s32)y, buf);
    if (self->f30 > 0 && self->f24 - self->f30 > 0x4B && self->f1C > 1e-5f) {
        k = 1.0f;
        r = k / self->f1C;
        r -= k;
        self->time = (s32)(r * (f32)self->f24);
        if (self->time > 0x464F) {
            self->time = 0x464F;
        }
        self->f30 = self->f24;
    }
    if (self->time > 5) {
        self->time--;
    }
}
#pragma pop

struct VtxList_8007F27C {
    NJS_POINT2 *pos;
    u32 *col;
    s32 n;
    s32 cap;
};

extern const VtxList_8007F27C lbl_80438AB4;

#pragma push
#pragma fp_contract on
void fn_8007F27C(TDLGraph *self, const NJS_POINT2 *pos, const NJS_POINT2 *size) {
    NJS_POINT2 v[4];
    u32 col[4];
    VtxList_8007F27C vl = lbl_80438AB4;
    const f32 margin = 2.0f;
    vl.pos = v;
    vl.col = col;
    col[0] = col[1] = col[2] = col[3] = 0xFF;
    v[0].x = v[3].x = pos->x - margin;
    v[1].x = v[2].x = margin + (pos->x + size->x);
    v[0].y = v[1].y = pos->y - margin;
    v[2].y = v[3].y = margin + (pos->y + size->y);
    ((TObjCMHairMenu *)&vl)->draw_tri_fan_2d(4, 2, -2.0f);

    col[0] = col[1] = col[2] = col[3] = self->m_34;
    v[0].x = v[3].x = pos->x;
    v[1].x = v[2].x = size->x * self->m_1c + pos->x;
    v[0].y = v[1].y = pos->y;
    v[2].y = v[3].y = size->y + pos->y;
    ((TObjCMHairMenu *)&vl)->draw_tri_fan_2d(4, 2, -1.0f);

    col[0] = col[1] = col[2] = col[3] = self->m_38;
    v[0].x = v[3].x = size->x + pos->x;
    ((TObjCMHairMenu *)&vl)->draw_tri_fan_2d(4, 2, -1.0f);
}
#pragma pop


s32 fn_8007F3F8(O_8007F3F8 *arg0, f32 farg0) {
    f32 sum;
    f32 df;
    f32 da;
    s32 i;
    if (arg0->count < 9) {
        return -1;
    }
    sum = 0.0f;
    for (i = 0; i < 3; i++) {
        da = (f32)(arg0->e[i].a - arg0->e[i + 1].a);
        df = arg0->e[i].f - arg0->e[i + 1].f;
        if (da <= 1e-05f || df <= 1e-05f) {
            return -1;
        }
        sum += da / df;
    }
    sum /= 3.0f;
    return (s32)((1.0f - farg0) * sum);
}

}
