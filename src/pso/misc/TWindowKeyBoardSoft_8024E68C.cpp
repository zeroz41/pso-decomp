#include "types.h"
#include "pso/misc/TWindowKeyBoardSoft_8024E68C.h"
#include "pso/system/memory.h"
#include "pso/misc/TWindowKeyBoardSoft.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredFields_8024E754_arg0
{
  u8 unknown_0[0x28];
  f32 field_28;
  f32 field_2C;
};

struct Ctx_8024E6D8 { u8 pad[0x20]; f32 pivot[2]; f32 scale[2]; };

struct Vec2_8024EC34 { f32 x; f32 y; };

struct Ctx_8024E68C { u8 pad[0x20]; f32 pivot[2]; f32 scale[2]; };

struct Box_8024E8E8 { f32 x0, y0, x1, y1; f32 u0, v0, u1, v1; };

struct Win_8024E8E8 { u8 pad[0x3C]; f32 x0, y0, x1, y1; };

struct Win_8024EA50 {
    f32 x, y;
    f32 w, h;
    f32 x10, y14, x18, y1c;
    Vec2_8024EC34 c;
    f32 sx, sy;
    s32 f30;
    s32 f34;
    f32 depth;
    f32 x3c, y40, x44, y48;
};

extern u32 soft_keyboard_instance;
extern "C" {
s32 __cvt_fp2unsigned(f32);
extern const f32 lbl_805DCC84;
extern const f32 lbl_805DCC88;
extern const float lbl_805DCC78;
extern const f32 lbl_805DCC7C;
extern const f32 lbl_805DCC80;
void apply_context_transform_to_rect(Ctx_8024E6D8 *c, f32 *q);
s32 is_split_screen();
f32 TCameraCtrl__sub_80068A04(s32);
Vec2_8024EC34 *get_viewport_offset__19TWindowKeyBoardSoftFi(s32);
Vec2_8024EC34 *get_zero_vec2();
extern Vec2_8024EC34 keyboard_soft_viewport_offset_table[];
extern Vec2_8024EC34 lbl_8044EC80[];
extern Vec2_8024EC34 lbl_8044EC98[];
extern const float lbl_805DCC94;
s32 clip_textured_quad__19TWindowKeyBoardSoftFPvPv(Win_8024E8E8 *w, Box_8024E8E8 *b);
extern const f32 lbl_805DCC98;
extern const f32 lbl_805DCC9C;
extern const f32 lbl_805DCCA0;
extern const f32 lbl_805DCCA4;
u32 init_text_window_layout(Win_8024EA50 *win, f32 *pos, f32 *size, f32 *scale, u32 flags, f32 depth);

typedef struct RecoveredFields_8024E754_arg0 RecoveredFields_8024E754_arg0;
#pragma fp_contract on

#pragma push
#pragma fp_contract on
void TWindowKeyBoardSoft::scale_point_about_pivot(f32 *q) {
    Ctx_8024E68C *c = (Ctx_8024E68C *)this;
    if ((*(const f32 *)&lbl_805DCC78) != c->scale[0]) {
        q[0] = c->scale[0] * (q[0] - c->pivot[0]) + c->pivot[0];
    }
    if ((*(const f32 *)&lbl_805DCC78) != c->scale[1]) {
        q[1] = c->scale[1] * (q[1] - c->pivot[1]) + c->pivot[1];
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void apply_context_transform_to_rect(Ctx_8024E6D8 *c, f32 *q) {
    if ((*(const f32 *)&lbl_805DCC78) != c->scale[0]) {
        q[0] = c->scale[0] * (q[0] - c->pivot[0]) + c->pivot[0];
        q[2] = c->scale[0] * (q[2] - c->pivot[0]) + c->pivot[0];
    }
    if ((*(const f32 *)&lbl_805DCC78) != c->scale[1]) {
        q[1] = c->scale[1] * (q[1] - c->pivot[1]) + c->pivot[1];
        q[3] = c->scale[1] * (q[3] - c->pivot[1]) + c->pivot[1];
    }
}
}
#pragma pop

void apply_window_closing_stretch(u8 *arg0, int arg1) {
  f32 temp_f2;
  RecoveredFields_8024E754_arg0 *new_var;
  new_var = (RecoveredFields_8024E754_arg0 *) arg0;
  if (arg1 != 0)
  {
    temp_f2 = lbl_805DCC80;
    ;
    new_var->field_28 = (f32) (new_var->field_28 * ((lbl_805DCC7C * (temp_f2 * ((f32) arg1))) + (*(const f32 *)&lbl_805DCC78)));
    new_var->field_2C = (f32) (new_var->field_2C * ((*(const f32 *)&lbl_805DCC78) - (temp_f2 * ((f32) arg1))));
  }
}

#pragma push
#pragma opt_common_subs off

void TWindowKeyBoardSoft::set_open_tick(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    *(s32 *)((s8 *)arg0 + 0x30) = arg1;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x30);
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)arg0 + 0x34) = (s32) ((__cvt_fp2unsigned(lbl_805DCC84 * ((lbl_805DCC88 + (f32) temp_r0) / lbl_805DCC88)) << 0x18) | 0xFF0000 | 0xFFFF);
    }
}
#pragma pop

void TWindowKeyBoardSoft::set_bounds(f32 a, f32 b, f32 c, f32 d) { *(f32*)((char*)this + 0x3c) = a; *(f32*)((char*)this + 0x40) = b; *(f32*)((char*)this + 0x44) = c; *(f32*)((char*)this + 0x48) = d; }

extern const f32 lbl_805DCC8C;

void TWindowKeyBoardSoft::shrink_clip_right() {
    *(f32 *)((s8 *)this + 0x18) = (f32) (*(f32 *)((s8 *)this + 0x18) - lbl_805DCC8C);
    *(f32 *)((s8 *)this + 0x44) = (f32) (*(f32 *)((s8 *)this + 0x44) - lbl_805DCC8C);
}

extern const f32 lbl_805DCC90;

void TWindowKeyBoardSoft::animate_scale() {
    *(f32 *)((s8 *)this + 0x14) = (f32) (*(f32 *)((s8 *)this + 0x14) + lbl_805DCC90);
    *(f32 *)((s8 *)this + 0x1C) = (f32) (*(f32 *)((s8 *)this + 0x1C) - lbl_805DCC90);
    *(f32 *)((s8 *)this + 0x40) = (f32) (*(f32 *)((s8 *)this + 0x40) + lbl_805DCC90);
}

s32 TWindowKeyBoardSoft::is_point_in_bounds(void *arg1) {
    if ((*(f32 *)((s8 *)arg1 + 8) < *(f32 *)((s8 *)this + 0x3C)) || (*(f32 *)((s8 *)arg1 + 0xC) < *(f32 *)((s8 *)this + 0x40)) || (*(f32 *)((s8 *)arg1 + 0) > *(f32 *)((s8 *)this + 0x44)) || (*(f32 *)((s8 *)arg1 + 4) > *(f32 *)((s8 *)this + 0x48))) {
        return 0;
    }
    return 1;
}

#pragma push
#pragma fp_contract on
s32 clip_textured_quad__19TWindowKeyBoardSoftFPvPv(Win_8024E8E8 *w, Box_8024E8E8 *b) {
    f32 sx;
    f32 sy;
    f32 d;
    if (((TWindowKeyBoardSoft *)w)->is_point_in_bounds(b) == 0) {
        return 0;
    }
    sx = (b->u1 - b->u0) / (b->x1 - b->x0);
    sy = (b->v1 - b->v0) / (b->y1 - b->y0);
    d = w->x0 - b->x0;
    if (d > (*(const f32 *)&lbl_805DCC94)) {
        b->x0 = w->x0;
        b->u0 = d * sx + b->u0;
    }
    d = w->y0 - b->y0;
    if (d > (*(const f32 *)&lbl_805DCC94)) {
        b->y0 = w->y0;
        b->v0 = d * sy + b->v0;
    }
    d = b->x1 - w->x1;
    if (d > (*(const f32 *)&lbl_805DCC94)) {
        b->x1 = w->x1;
        b->u1 = -(d * sx - b->u1);
    }
    d = b->y1 - w->y1;
    if (d > (*(const f32 *)&lbl_805DCC94)) {
        b->y1 = w->y1;
        b->v1 = -(d * sy - b->v1);
    }
    return 1;
}
#pragma pop

s32 try_open__19TWindowKeyBoardSoftFii(s32 arg0, s32 arg1) {
    if (clip_textured_quad__19TWindowKeyBoardSoftFPvPv((Win_8024E8E8 *)(arg0), (Box_8024E8E8 *)(arg1)) == 0) {
        return 0;
    }
    apply_context_transform_to_rect((Ctx_8024E6D8 *)(arg0), (f32 *)arg1);
    return 1;
}

#pragma push
#pragma fp_contract on
u32 init_text_window_layout(Win_8024EA50 *win, f32 *pos, f32 *size, f32 *scale, u32 flags, f32 depth) {
    f32 mx;
    f32 my;
    s32 cam;
    f32 t;
    if (flags & 0x800) {
        mx = (*(const f32 *)&lbl_805DCC94);
        my = mx;
    } else {
        mx = lbl_805DCC98;
        my = lbl_805DCC9C;
    }
    win->w = size[0];
    win->h = size[1];
    win->sx = scale[0];
    win->sy = scale[1];
    if (flags & 0x4000) {
        win->c.x = lbl_805DCCA0 * win->w + pos[0];
        win->c.y = lbl_805DCCA0 * win->h + pos[1];
    } else {
        t = lbl_805DCCA0 * win->w;
        win->c.x = t * win->sx + pos[0];
        t = lbl_805DCCA0 * win->h;
        win->c.y = t * win->sy + pos[1];
    }
    win->f30 = 0;
    win->f34 = -1;
    win->depth = depth;
    if (!(flags & 0x1000) && is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_no();
        if (cam != 100) {
            ((TWindowKeyBoardSoft *)(&win->c))->adjust_pos_for_split_screen(cam);
            win->sx = win->sx / TCameraCtrl::get_view_scale();
            win->sy = win->sy / TCameraCtrl::get_fov();
        }
    }
    win->x = win->c.x - lbl_805DCCA0 * win->w;
    win->y = win->c.y - lbl_805DCCA0 * win->h;
    win->x10 = win->x + mx;
    win->y14 = win->y + my;
    win->x18 = win->w - lbl_805DCCA4 * mx;
    win->y1c = win->h - lbl_805DCCA4 * my;
    win->x3c = win->x + mx;
    win->y40 = win->y + my;
    win->x44 = (win->x + win->w) - mx;
    win->y48 = (win->y + win->h) - my;
    return soft_keyboard_instance;
}
#pragma pop

void TWindowKeyBoardSoft::adjust_pos_for_split_screen(s32 i) {
    Vec2_8024EC34 *arg0 = (Vec2_8024EC34 *)this;
    Vec2_8024EC34 *p;
    if (is_split_screen() == 0 || i == 0x64) {
        return;
    }
    p = get_viewport_offset__19TWindowKeyBoardSoftFi(i);
    arg0->x = arg0->x + (p->x + TCameraCtrl__sub_80068A04(i));
    arg0->y = arg0->y + (p->y + TCameraCtrl::get_split_offset(i));
    arg0->x = arg0->x / TCameraCtrl::get_view_scale();
    arg0->y = arg0->y / TCameraCtrl::get_fov();
}

Vec2_8024EC34 *get_viewport_offset__19TWindowKeyBoardSoftFi(s32 i) {
    switch (TCameraCtrl::get_camera_id()) {
    case 1:
        break;
    case 2:
        if (i >= 0 && i <= 2) {
            return &keyboard_soft_viewport_offset_table[i];
        }
        break;
    case 3:
        if (i >= 0 && i <= 3) {
            return &lbl_8044EC80[i];
        }
        break;
    case 4:
        if (i >= 0 && i <= 4) {
            return &lbl_8044EC98[i];
        }
        break;
    }
    return get_zero_vec2();
}

u32 open_singleton__19TWindowKeyBoardSoftFiiii(s32 pos, s32 size, s32 scale, s32 flags, u32 _w4, f32 depth) {
    if ((u32) soft_keyboard_instance == 0U) {
        return 0U;
    }
    init_text_window_layout((Win_8024EA50 *)(soft_keyboard_instance), (f32 *)pos, (f32 *)size, (f32 *)scale, (u32)flags, depth);
    return soft_keyboard_instance;
}

u32 TWindowKeyBoardSoft::get_or_create_instance() {
    u32 temp_r3;
    u32 var_r0;
    if ((u32) soft_keyboard_instance != 0U) {
        return soft_keyboard_instance;
    }
    temp_r3 = (int)::operator new(0x4C);
    var_r0 = temp_r3;
    if (var_r0 != 0U) {
        var_r0 = ((TWindowKeyBoardSoft *)temp_r3)->init_layout();
    }
    soft_keyboard_instance = var_r0;
    return var_r0;
}

u32 TWindowKeyBoardSoft::free_singleton(u32 arg0, s16 arg1) {
    if (arg0 != 0U) {
        if ((u32) soft_keyboard_instance == arg0) {
            soft_keyboard_instance = 0U;
        }
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

u32 TWindowKeyBoardSoft::init_layout() { *(float*)((char*)this + 0x0) = lbl_805DCC94; *(float*)((char*)this + 0x4) = lbl_805DCC94; *(float*)((char*)this + 0x8) = lbl_805DCC94; *(float*)((char*)this + 0xc) = lbl_805DCC94; *(float*)((char*)this + 0x10) = lbl_805DCC94; *(float*)((char*)this + 0x14) = lbl_805DCC94; *(float*)((char*)this + 0x18) = lbl_805DCC94; *(float*)((char*)this + 0x1c) = lbl_805DCC94; *(float*)((char*)this + 0x3c) = lbl_805DCC94; *(float*)((char*)this + 0x40) = lbl_805DCC94; *(float*)((char*)this + 0x44) = lbl_805DCC94; *(float*)((char*)this + 0x48) = lbl_805DCC94; *(float*)((char*)this + 0x20) = lbl_805DCC94; *(float*)((char*)this + 0x24) = lbl_805DCC94; *(float*)((char*)this + 0x28) = lbl_805DCC78; *(float*)((char*)this + 0x2c) = lbl_805DCC78; *(int*)((char*)this + 0x30) = 0; *(int*)((char*)this + 0x34) = -1; *(float*)((char*)this + 0x38) = lbl_805DCC94; }
