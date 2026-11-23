#include "pso/system/scene/EndingWallTextures.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/scene/TEndingPic.h"
#include "pso/system/scene/TEndingAB.h"
#include "pso/system/scene/TEndingPicStage.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"

s32 TEndingPic__animation_state;

extern "C" {
int TKeyBoardControl__sub_8000F828(void);
extern const char TEndingPic__class_name_string[] = "TEndingPic";
const char *lbl_805D4378 = TEndingPic__class_name_string;
NJS_TEXLIST *ending_pic_wall_texture_list;

void TEndingPic::advance_animation_state() {
    switch (TEndingPic__animation_state) {
    case 1: {
        s32 ticks = ++elapsed_ticks;
        s32 rate = timing_rate;
        if (ticks > rate * 3 - rate) {
            TEndingPic__animation_state = 2;
            TEndingPicStage::set_picture(next_picture);
            ++next_picture;
        }
        break;
    }
    case 2:
        if (++elapsed_ticks > timing_rate * 13) {
            TEndingPic__animation_state = 3;
            return;
        }
        break;
    case 3: {
        s32 ticks = ++elapsed_ticks;
        s32 rate = timing_rate;
        if (ticks > rate * 14 - rate) {
            TEndingPic__animation_state = 4;
            TEndingPicStage::set_picture(next_picture);
            ++next_picture;
            return;
        }
        break;
    }
    case 4:
        if (++elapsed_ticks > timing_rate * 24) {
            elapsed_ticks = 0;
            TEndingPic__animation_state = 1;
            if (++picture_pair > 5) {
                picture_pair = 5;
                TEndingPic__animation_state = 5;
                return;
            }
        }
        break;
    case 5:
        picture_pair = 5;
        break;
    }
}

void TEndingPic::draw_current_pic() {
    begin_screen_draw(1);
    switch (TEndingPic__animation_state) {
    case 1:
    case 3:
        break;
    case 2:
        set_draw_texture_and_color(picture_pair * 2 + 2, -1);
        draw_textured_quad_at_depth((f32 *)&quads[4], 0.0001f);
        break;
    case 4:
    case 5:
        set_draw_texture_and_color(picture_pair * 2 + 3, -1);
        draw_textured_quad_at_depth((f32 *)&quads[5], 0.0001f);
        break;
    default:
        break;
    }
    TWindowSubStatusDisp::get_player();
}

void TEndingPic::init_positions() {
    quads[0].left = 228.0f;
    quads[0].top = 0.0f;
    quads[0].right = 640.0f;
    quads[0].bottom = 480.0f;
    quads[0].u0 = 0.1953125f;
    quads[0].v0 = 0.0f;
    quads[0].u1 = 1.0f;
    quads[0].v1 = 0.9375f;
    quads[1].left = 0.0f;
    quads[1].top = 0.0f;
    quads[1].right = 100.0f;
    quads[1].bottom = 480.0f;
    quads[1].u0 = 0.0f;
    quads[1].v0 = 0.0f;
    quads[1].u1 = 0.1953125f;
    quads[1].v1 = 0.9375f;
    quads[2].left = 228.0f;
    quads[2].top = 0.0f;
    quads[2].right = 640.0f;
    quads[2].bottom = 480.0f;
    quads[2].u0 = 0.1953125f;
    quads[2].v0 = 0.0f;
    quads[2].u1 = 1.0f;
    quads[2].v1 = 0.9375f;
    quads[3].left = 0.0f;
    quads[3].top = 0.0f;
    quads[3].right = 100.0f;
    quads[3].bottom = 480.0f;
    quads[3].u0 = 0.0f;
    quads[3].v0 = 0.0f;
    quads[3].u1 = 0.1953125f;
    quads[3].v1 = 0.9375f;
    quads[4].left = 316.0f;
    quads[4].top = 32.0f;
    quads[4].right = 616.0f;
    quads[4].bottom = 332.0f;
    quads[4].u0 = 0.0f;
    quads[4].v0 = 0.0f;
    quads[4].u1 = 1.0f;
    quads[4].v1 = 1.0f;
    quads[5].left = 316.0f;
    quads[5].top = 148.0f;
    quads[5].right = 616.0f;
    quads[5].bottom = 448.0f;
    quads[5].u0 = 0.0f;
    quads[5].v0 = 0.0f;
    quads[5].u1 = 1.0f;
    quads[5].v1 = 1.0f;
}

void TEndingPic::render() {
    if ((s32) TEndingPic__animation_state != 0) {
        TObjFish::set_global_param(ending_pic_wall_texture_list);
        draw_current_pic();
    }
}

void TEndingPic::run_task() { advance_animation_state(); }

TEndingPic::~TEndingPic() {}
TEndingPic::TEndingPic(TObject *parent) : TObject(parent) {
    m_name = lbl_805D4378;
    elapsed_ticks = -1;
    TEndingPic__animation_state = 0;
    field_20 = 0xFF;
    picture_pair = 0;
    next_picture = 0;
    ending_pic_wall_texture_list = get_ending_ab_wall_texture_list();
    init_positions();
    switch (TKeyBoardControl__sub_8000F828()) {
    case 0: timing_rate = 30; break;
    case 1: timing_rate = 25; break;
    }
}
}

NJS_TEXLIST *get_ending_ab_wall_texture_list(void) { return ending_ab_wall_texture_list; }
