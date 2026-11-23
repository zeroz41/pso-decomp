#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/camera/TCineCtrl.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

TCineCtrl *TCineCtrl::instance;

// Draws the top and bottom bars, bar_height lines each, over the full screen.
void TCineCtrl::render() {
    NJS_POINT2COL poly;
    NJS_COLOR col[4];
    NJS_POINT2 pos[4];
    if (!(alpha <= 0.0f)) {
        TCameraCtrl::restore_full_screen_view();
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        poly.p = pos;
        poly.col = col;
        poly.tex = NULL;
        poly.num = 4;
        rgba.a = alpha;
        poly.p[0].x = 0.0f;
        poly.p[0].y = 0.0f;
        poly.col[0].color = color;
        poly.p[1].x = 640.0f;
        poly.p[1].y = 0.0f;
        poly.col[1].color = color;
        poly.p[2].x = 640.0f;
        poly.p[2].y = bar_height;
        poly.col[2].color = color;
        poly.p[3].x = 0.0f;
        poly.p[3].y = bar_height;
        poly.col[3].color = color;
        draw_polygon_2d(&poly, 4, 0x16, -10.0f);
        poly.p[0].x = 0.0f;
        poly.p[0].y = 480.0f - bar_height;
        poly.col[0].color = color;
        poly.p[1].x = 640.0f;
        poly.p[1].y = 480.0f - bar_height;
        poly.col[1].color = color;
        poly.p[2].x = 640.0f;
        poly.p[2].y = 480.0f;
        poly.col[2].color = color;
        poly.p[3].x = 0.0f;
        poly.p[3].y = 480.0f;
        poly.col[3].color = color;
        draw_polygon_2d(&poly, 4, 0x16, -10.0f);
        TCameraCtrl::restore_saved_view();
    }
}

#pragma push
#pragma opt_common_subs off
void TCineCtrl::update_letterbox_hide() {
    Callback done;
    alpha = alpha - 8.0f;
    bar_height = bar_height - 2.0f;
    if (alpha <= 0.0f) {
        alpha = 0.0f;
    }
    if (bar_height <= 0.0f) {
        bar_height = 0.0f;
        done = on_done;
        if (done != NULL) {
            done(this);
        }
        state = STATE_IDLE;
    }
}
#pragma pop

void TCineCtrl::begin_letterbox_hide(Callback on_done) {
    if (instance != NULL) {
        instance->on_done = on_done;
        instance->alpha = 255.0f;
        instance->bar_height = 70.0f;
        instance->rgba.b = 0;
        instance->rgba.g = 0;
        instance->rgba.r = 0;
        instance->state = STATE_HIDE;
    }
}

#pragma push
#pragma opt_common_subs off
void TCineCtrl::update_letterbox_show() {
    Callback done;
    alpha += 8.0f;
    bar_height += 2.0f;
    if (alpha >= 255.0f) {
        alpha = 255.0f;
    }
    if (bar_height >= 70.0f) {
        bar_height = 70.0f;
        done = on_done;
        if (done != NULL) {
            done(this);
        }
        state = STATE_IDLE;
    }
}
#pragma pop

void TCineCtrl::begin_letterbox_show(Callback on_done) {
    if (instance != NULL) {
        instance->on_done = on_done;
        instance->alpha = 0.0f;
        instance->bar_height = 0.0f;
        instance->rgba.b = 0;
        instance->rgba.g = 0;
        instance->rgba.r = 0;
        instance->state = STATE_SHOW;
    }
}

const char *TCineCtrl::class_name = "TCineCtrl";

void TCineCtrl::run_task() {
    switch (state) {
    case STATE_IDLE:
        break;
    case STATE_SHOW:
        update_letterbox_show();
        break;
    case STATE_HIDE:
        update_letterbox_hide();
        break;
    }
}

TCineCtrl::~TCineCtrl() {
    instance = NULL;
}

// Always joins the fade list, whatever parent it is given.
TCineCtrl::TCineCtrl(TObject *parent) : TObject(tl_fade) {
    m_name = class_name;
    alpha = 0.0f;
    bar_height = 0.0f;
    color = 0;
    state = STATE_IDLE;
    instance = this;
}
