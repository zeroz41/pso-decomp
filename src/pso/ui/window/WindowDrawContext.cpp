#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowCtrlMain_8024EEF8.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/TObjPlayer_80011014.h"

WindowDrawContext *shared_window_draw_context;
// Window offsets per player viewport for two, three and four split-screen views (camera ids 2-4).
// inferred: _3p/_4p names from the camera-count switch in get_viewport_offset.
extern const NJS_POINT2 window_viewport_offset_table[2] = {
    {0.0f, 40.0f}, {0.0f, 0.0f},
};
extern const NJS_POINT2 window_viewport_offset_table_3p[3] = {
    {8.0f, 40.0f}, {0.0f, 40.0f}, {0.0f, 0.0f},
};
extern const NJS_POINT2 window_viewport_offset_table_4p[4] = {
    {8.0f, 40.0f}, {0.0f, 40.0f}, {8.0f, 0.0f}, {0.0f, 0.0f},
};

extern "C" {
s32 __cvt_fp2unsigned(f32);
NJS_POINT2 *get_zero_vec2();
}

#pragma fp_contract on

#pragma push
#pragma fp_contract on
void WindowDrawContext::scale_point_about_pivot(f32 *q) {
    if (1.0f != scale[0]) {
        q[0] = scale[0] * (q[0] - pivot[0]) + pivot[0];
    }
    if (1.0f != scale[1]) {
        q[1] = scale[1] * (q[1] - pivot[1]) + pivot[1];
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void WindowDrawContext::transform_quad(TexturedQuad *quad) {
    if (1.0f != scale[0]) {
        quad->x0 = scale[0] * (quad->x0 - pivot[0]) + pivot[0];
        quad->x1 = scale[0] * (quad->x1 - pivot[0]) + pivot[0];
    }
    if (1.0f != scale[1]) {
        quad->y0 = scale[1] * (quad->y0 - pivot[1]) + pivot[1];
        quad->y1 = scale[1] * (quad->y1 - pivot[1]) + pivot[1];
    }
}
#pragma pop

void WindowDrawContext::apply_closing_stretch(int ticks) {
    f32 step;
    if (ticks != 0) {
        step = 0.22222222f;
        scale[0] = scale[0] * ((2.3f * (step * (f32)ticks)) + 1.0f);
        scale[1] = scale[1] * (1.0f - (step * (f32)ticks));
    }
}

void WindowDrawContext::set_open_tick(s32 tick) {
    open_tick = tick;
    if (open_tick < 0) {
        f32 fade = (7.5f + open_tick) / 7.5f;
#ifndef __MWERKS__
        // The GameCube unsigned conversion returns zero for negative alpha.
        if (fade < 0.0f) {
            fade = 0.0f;
        }
#endif
        color = (static_cast<u32>(255.0f * fade) << 24) | 0x00FFFFFF;
    }
}

void WindowDrawContext::set_bounds(f32 a, f32 b, f32 c, f32 d) { clip_x0 = a; clip_y0 = b; clip_x1 = c; clip_y1 = d; }


void WindowDrawContext::shrink_clip_right() {
    this->inner_w = (f32) (this->inner_w - 5.0f);
    this->clip_x1 = (f32) (this->clip_x1 - 5.0f);
}


void WindowDrawContext::animate_scale() {
    this->inner_y += 6.0f;
    this->inner_h -= 6.0f;
    this->clip_y0 += 6.0f;
}

s32 WindowDrawContext::is_point_in_bounds(TexturedQuad *quad) {
    if ((quad->x1 < this->clip_x0) || (quad->y1 < this->clip_y0) || (quad->x0 > this->clip_x1) || (quad->y0 > this->clip_y1)) {
        return 0;
    }
    return 1;
}

#pragma push
#pragma fp_contract on
s32 WindowDrawContext::clip_textured_quad(TexturedQuad *b) {
    f32 sx;
    f32 sy;
    f32 d;
    if (is_point_in_bounds(b) == 0) {
        return 0;
    }
    sx = (b->u1 - b->u0) / (b->x1 - b->x0);
    sy = (b->v1 - b->v0) / (b->y1 - b->y0);
    d = clip_x0 - b->x0;
    if (d > 0.0f) {
        b->x0 = clip_x0;
        b->u0 = d * sx + b->u0;
    }
    d = clip_y0 - b->y0;
    if (d > 0.0f) {
        b->y0 = clip_y0;
        b->v0 = d * sy + b->v0;
    }
    d = b->x1 - clip_x1;
    if (d > 0.0f) {
        b->x1 = clip_x1;
        b->u1 = -(d * sx - b->u1);
    }
    d = b->y1 - clip_y1;
    if (d > 0.0f) {
        b->y1 = clip_y1;
        b->v1 = -(d * sy - b->v1);
    }
    return 1;
}
#pragma pop

s32 WindowDrawContext::clip_and_transform_quad(TexturedQuad *quad) {
    if (clip_textured_quad(quad) == 0) {
        return 0;
    }
    transform_quad(quad);
    return 1;
}

#pragma push
#pragma fp_contract on
WindowDrawContext *WindowDrawContext::init_layout(f32 *pos, f32 *size, f32 *scale, u32 flags, f32 depth) {
    f32 mx;
    f32 my;
    s32 cam;
    f32 t;
    if (flags & 0x800) {
        mx = 0.0f;
        my = mx;
    } else {
        mx = 4.0f;
        my = 10.0f;
    }
    this->w = size[0];
    this->h = size[1];
    this->scale[0] = scale[0];
    this->scale[1] = scale[1];
    if (flags & 0x4000) {
        this->pivot[0] = 0.5f * this->w + pos[0];
        this->pivot[1] = 0.5f * this->h + pos[1];
    } else {
        t = 0.5f * this->w;
        this->pivot[0] = t * this->scale[0] + pos[0];
        t = 0.5f * this->h;
        this->pivot[1] = t * this->scale[1] + pos[1];
    }
    this->open_tick = 0;
    this->color = -1;
    this->depth = depth;
    if (!(flags & 0x1000) && is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_no();
        if (cam != 100) {
            adjust_pos_for_split_screen((NJS_POINT2 *)pivot, cam);
            this->scale[0] = this->scale[0] / TCameraCtrl::get_view_scale();
            this->scale[1] = this->scale[1] / TCameraCtrl::get_fov();
        }
    }
    this->x = this->pivot[0] - 0.5f * this->w;
    this->y = this->pivot[1] - 0.5f * this->h;
    this->inner_x = this->x + mx;
    this->inner_y = this->y + my;
    this->inner_w = this->w - 2.0f * mx;
    this->inner_h = this->h - 2.0f * my;
    this->clip_x0 = this->x + mx;
    this->clip_y0 = this->y + my;
    this->clip_x1 = (this->x + this->w) - mx;
    this->clip_y1 = (this->y + this->h) - my;
    return shared_window_draw_context;
}
#pragma pop

void WindowDrawContext::adjust_pos_for_split_screen(NJS_POINT2 *pos, s32 i) {
    const NJS_POINT2 *p;
    if (is_split_screen() == 0 || i == 0x64) {
        return;
    }
    p = get_viewport_offset(i);
    pos->x = pos->x + (p->x + TCameraCtrl::get_split_offset_x(i));
    pos->y = pos->y + (p->y + TCameraCtrl::get_split_offset(i));
    pos->x = pos->x / TCameraCtrl::get_view_scale();
    pos->y = pos->y / TCameraCtrl::get_fov();
}

// The upper bounds are inclusive in the original, so each table can be read one entry past its end.
const NJS_POINT2 *WindowDrawContext::get_viewport_offset(s32 i) {
    switch (TCameraCtrl::get_camera_id()) {
    case 1:
        break;
    case 2:
        if (i >= 0 && i <= 2) {
            return &window_viewport_offset_table[i];
        }
        break;
    case 3:
        if (i >= 0 && i <= 3) {
            return &window_viewport_offset_table_3p[i];
        }
        break;
    case 4:
        if (i >= 0 && i <= 4) {
            return &window_viewport_offset_table_4p[i];
        }
        break;
    }
    return get_zero_vec2();
}

WindowDrawContext *WindowDrawContext::open_singleton(f32 *pos, f32 *size, f32 *scale, f32 depth, u32 flags) {
    if (shared_window_draw_context == NULL) {
        return NULL;
    }
    shared_window_draw_context->init_layout(pos, size, scale, flags, depth);
    return shared_window_draw_context;
}

WindowDrawContext *WindowDrawContext::get_or_create_instance() {
    if (shared_window_draw_context != NULL) {
        return shared_window_draw_context;
    }
    shared_window_draw_context = new WindowDrawContext();
    return shared_window_draw_context;
}

WindowDrawContext::~WindowDrawContext() {
    if (shared_window_draw_context == this) {
        shared_window_draw_context = NULL;
    }
}

WindowDrawContext::WindowDrawContext() {
    x = 0.0f;
    y = 0.0f;
    w = 0.0f;
    h = 0.0f;
    inner_x = 0.0f;
    inner_y = 0.0f;
    inner_w = 0.0f;
    inner_h = 0.0f;
    clip_x0 = 0.0f;
    clip_y0 = 0.0f;
    clip_x1 = 0.0f;
    clip_y1 = 0.0f;
    pivot[0] = 0.0f;
    pivot[1] = 0.0f;
    scale[0] = 1.0f;
    scale[1] = 1.0f;
    open_tick = 0;
    color = 0xFFFFFFFF;
    depth = 0.0f;
}

void TWindowCtrlMain::free_shared_draw_context() {
    if (shared_window_draw_context != NULL) {
        delete shared_window_draw_context;
        shared_window_draw_context = NULL;
    }
}
void TWindowCtrlMain__sub_8024EF30(void) { shared_window_draw_context = NULL; }
