#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/ColorLineList.h"
#include "pso/ui/charcreate/TChCrEffFade.h"
#include "pso/system/task/TObject_80019A50.h"
#include "types.h"
#include "pso/system/vector.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include <stddef.h>
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_80293D84.h"

const char *TChCrEffFade__class_name = "TChCrEffFade";

extern "C" {
u32 __cvt_fp2unsigned(f32);

void fn_80293D84(void *arg0, void *arg1, u32 color, f32 scale, f32 alpha) {
    // inferred: the unit hexagon the cells are scaled from
    static const ColorLineVertex hexagon[7] = {
        { 0.5f, -0.865f }, { 1.0f, 0.0f }, { 0.5f, 0.865f }, { -0.5f, 0.865f },
        { -1.0f, 0.0f }, { -0.5f, -0.865f }, { 0.0f, 0.0f },
    };
    const ColorLineVertex *position = static_cast<const ColorLineVertex *>(arg1);
    ColorLineList prim;
    u32 colors[6];
    ColorLineVertex pts[6];
    s32 i;
    u32 c;
    for (i = 0; i < 6; i++) {
        pts[i].x = scale * hexagon[i].x + position->x;
        pts[i].y = scale * hexagon[i].y + position->y;
    }
    c = (color & 0x00FFFFFF) | (__cvt_fp2unsigned(255.0f * alpha) << 24);
    for (i = 0; i < 6; i++) {
        colors[i] = c;
    }
    prim.colors = colors;
    prim.tex = NULL;
    prim.count = 6;
    prim.verts = pts;
    prim.draw_strip_swap_color(6, 6, (-1.5f));
}

void fn_80293E58(void *arg0, f32 scale) {
    // The hexagon grid covers the 640x480 screen plus a 12-unit margin.
    static const NJS_POINT2 grid_start = { -12.0f, -12.0f };
    static const NJS_POINT2 grid_end = { 652.0f, 492.0f };
    NJS_POINT2 p;
    f32 s = 12.0f * scale;
    s32 odd = 1;
    copy_vec2(&p, (void *)&grid_start);
    for (; p.y < grid_end.y; p.y += 10.38f) {
        p.x = grid_start.x;
        if (odd == 0) {
            p.x += -18.0f;
        }
        for (; p.x < grid_end.x; p.x += 36.0f) {
            fn_80293D84(arg0, &p, 0, s, scale);
        }
        odd ^= 1;
    }
}

}

struct FadeStrip : ColorLineList {
    u32 color0, color1, color2, color3;
};


// The 640x480 screen corners the fade strip is drawn over.
ColorLineVertex chcr_eff_fade_strip_rect[4] = {
    {0.0f, 0.0f}, {640.0f, 0.0f}, {640.0f, 480.0f}, {0.0f, 480.0f},
};

void TChCrEffFade::draw_fade_strip(f32 farg0) {
    FadeStrip strip;
    u32 color;
    color = __cvt_fp2unsigned(255.0f * farg0) << 24;
    strip.color3 = color;
    strip.color2 = color;
    strip.color1 = color;
    strip.color0 = color;
    strip.colors = &strip.color0;
    strip.tex = NULL;
    strip.count = 4;
    strip.verts = chcr_eff_fade_strip_rect;
    strip.draw_strip_swap_color(4, 6, -1.5f);
}

extern "C" {


void TChCrEffFade::render() {
    f32 temp_f0;

    TCameraCtrl::restore_full_screen_view();
    switch (mode) {
    case 0:
        draw_fade_strip(alpha);
        break;
    case 1:
        fn_80293E58(this, alpha);
        temp_f0 = alpha;
        draw_fade_strip(temp_f0 * temp_f0);
        break;
    }
    TCameraCtrl::restore_saved_view();
}


void TChCrEffFade::update_fade() {
    s32 temp_r6;

    temp_r6 = frame;
    if (temp_r6 <= 3) {
        alpha = 1.0f;
        return;
    }
    alpha = (f32) (1.0f - ((temp_r6 - 3) / (f32)(length - 3)));
}

void TChCrEffFade::run_task() {
    s32 temp_r3;

    frame = (s32) (frame + step);
    update_fade();
    temp_r3 = frame;
    if ((temp_r3 <= 0) || (temp_r3 >= (s32) length)) {
        queue_destruction();
    }
}

extern saddr tl_fade;

TChCrEffFade::~TChCrEffFade() {}
}
TChCrEffFade::TChCrEffFade(s32 arg1, s32 arg2, s32 arg3) : TObject((TObject *)tl_fade) {
    s32 temp_r0;
    s32 temp_r0_2;
    m_name = TChCrEffFade__class_name;
    step = arg1;
    length = (arg2 + 3);
    temp_r0 = length;
    if (temp_r0 < 4) {
        length = 4;
    } else if (temp_r0 > 0x1C2) {
        length = 0x1C2;
    }
    temp_r0_2 = step;
    if (temp_r0_2 == 1) {
        frame = 0;
    } else if (temp_r0_2 == -1) {
        frame = (s32) length;
    } else {
        step = 1;
        frame = 0;
    }
    this->update_fade();
    mode = arg3;
}
