#include "types.h"
#include "pso/render/ColorLineList.h"
#include "pso/render/Draw2D.h"
#include "pso/render/GinjaTexture.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/system/task/TObject.h"

NJS_TEXNAME lbl_804DBEC0[8] = {
    {(char *)"f256_adpic01", 0, 0},
    {(char *)"f256_adpic02", 0, 0},
    {(char *)"f256_adpic03", 0, 0},
    {(char *)"f256_adpic04", 0, 0},
    {(char *)"f128_adpic05", 0, 0},
    {(char *)"f128_adpic06", 0, 0},
    {(char *)"f128_adpic07", 0, 0},
    {(char *)"f128_adpic08", 0, 0},
};
__declspec(section ".data") NJS_TEXLIST chr_select_ad_pic_2_texture_descriptor = {lbl_804DBEC0, 8};
const char *TAdBackGC__class_name = "TAdBackGC";


void TAdBackGC::sub_8029A6EC() {
    ColorLineVertex pos[4];
    ColorLineList fan;
    u32 col[4];

    fan.verts = pos;
    fan.colors = col;
    fan.tex = NULL;
    fan.count = 4;
    fan.verts[0].x = 0.0f;
    fan.verts[0].y = 0.0f;
    fan.colors[0] = 0xFF;
    fan.verts[1].x = 0.0f;
    fan.verts[1].y = 479.0f;
    fan.colors[1] = 0xFF;
    fan.verts[2].x = 639.0f;
    fan.verts[2].y = 479.0f;
    fan.colors[2] = 0xFF;
    fan.verts[3].x = 639.0f;
    fan.verts[3].y = 0.0f;
    fan.colors[3] = 0xFF;
    draw_polygon_2d((NJS_POINT2COL *)&fan, 4, 3, this->m_depth - 0.01f);
}

extern "C" {

void TAdBackGC::render() {
    if (m_20 == 0) {
        if (defer_render() == 0) {
            set_depth_buffer_settings_2();
            goto draw;
        }
    } else if (TMainTask::get_render_pass() != 1) {
draw:
        sub_8029A6EC();
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 0xA);
        draw_title_background_layer(&chr_select_ad_pic_2_texture_descriptor, 0, -1, m_depth);
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        if (m_20 == 0) {
            restore_saved_depth_alpha_state();
        }
    }
}

void TAdBackGC::run_task() {  }

TAdBackGC::~TAdBackGC() {}
TAdBackGC::TAdBackGC(TObject *parent) : TObject(parent) {
    m_name = TAdBackGC__class_name;
    m_depth = -400.0f;
    m_20 = 1;
}

NJS_TEXLIST *chr_select_ad_pic_texture;

void TAdSinglePlyChrSelectGC::free_global() {
    if (chr_select_ad_pic_texture != NULL) {
        release_texture_list(chr_select_ad_pic_texture);
        chr_select_ad_pic_texture = NULL;
    }
}
void register_texture_f256_ad_pic_2(void) { chr_select_ad_pic_texture = &chr_select_ad_pic_2_texture_descriptor; load_streamed_prs_texture((saddr)"f256_ad_pic_2", (saddr)&chr_select_ad_pic_2_texture_descriptor); }

}
