#include "types.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdBackGC_8029A7B0.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8029A914.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_8023E480.h"

// texture archive list: {archive name, 0, 0} per entry, as TAdMultiOkGC's multi_confirm_texture_entries
void *lbl_804DBEC0[8][3] = {
    {(void *)"f256_adpic01", 0, 0},
    {(void *)"f256_adpic02", 0, 0},
    {(void *)"f256_adpic03", 0, 0},
    {(void *)"f256_adpic04", 0, 0},
    {(void *)"f128_adpic05", 0, 0},
    {(void *)"f128_adpic06", 0, 0},
    {(void *)"f128_adpic07", 0, 0},
    {(void *)"f128_adpic08", 0, 0},
};
struct AdPicTextureList { void *entries; u32 count; };
__declspec(section ".data") AdPicTextureList chr_select_ad_pic_2_texture_descriptor = { lbl_804DBEC0, 8 };
const char *TAdBackGC__class_name = "TAdBackGC";

struct Fan_8029A6EC { f32 *pos; u32 *col; s32 first; s32 count; };


void TAdBackGC::sub_8029A6EC() {
    f32 pos[8];
    Fan_8029A6EC fan;
    u32 col[4];

    fan.pos = pos;
    fan.col = col;
    fan.first = 0;
    fan.count = 4;
    fan.pos[0] = 0.0f;
    fan.pos[1] = 0.0f;
    fan.col[0] = 0xFF;
    fan.pos[2] = 0.0f;
    fan.pos[3] = 479.0f;
    fan.col[1] = 0xFF;
    fan.pos[4] = 639.0f;
    fan.pos[5] = 479.0f;
    fan.col[2] = 0xFF;
    fan.pos[6] = 639.0f;
    fan.pos[7] = 0.0f;
    fan.col[3] = 0xFF;
    ((TObjCMHairMenu *)&fan)->draw_tri_fan_2d(4, 3, *(f32 *)((u8 *)this + 0x1C) - 0.01f);
}

extern "C" {
s32 defer_render__7TObjectFv();
void __ct__7TObjectFP7TObject(void *);

void TAdBackGC::render() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x20) == 0) {
        if (defer_render__7TObjectFv() == 0) {
            set_depth_buffer_settings_2();
            goto block_4;
        }
    } else if (TMainTask::get_render_pass() != 1) {
block_4:
        ((TAdBackGC *)arg0)->sub_8029A6EC();
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 0xA);
        draw_title_background_layer(&chr_select_ad_pic_2_texture_descriptor, 0, -1, (f32) (*(f32 *)((s8 *)arg0 + 0x1C)));
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x20) == 0) {
            restore_saved_depth_alpha_state();
        }
    }
}

void TAdBackGC::run_task() {  }

extern s32 __vt__9TAdBackGC[];

TAdBackGC::~TAdBackGC() {}
void *__ct__9TAdBackGCFv(void *ad_back_gc) {
    __ct__7TObjectFP7TObject(ad_back_gc);
    *(s32 **)((s8 *)ad_back_gc + 0x18) = __vt__9TAdBackGC;
    *(void * *)&((TAdBackGC *)ad_back_gc)->m_name = (void *)TAdBackGC__class_name;
    *(f32 *)((s8 *)ad_back_gc + 0x1C) = -400.0f;
    *(u32 *)((s8 *)ad_back_gc + 0x20) = 1;
    return ad_back_gc;
}

}

extern "C" {
u32 chr_select_ad_pic_texture;
void release_texture_list(void*);

void TAdSinglePlyChrSelectGC::free_global() {
    if ((u32) chr_select_ad_pic_texture != 0U) {
        release_texture_list((void*)chr_select_ad_pic_texture);
        chr_select_ad_pic_texture = 0U;
    }
}
void register_texture_f256_ad_pic_2(void) { (*(int *)&chr_select_ad_pic_texture) = (int)&chr_select_ad_pic_2_texture_descriptor; TLobby__sub_8023E4B4((s32)"f256_ad_pic_2", (s32)&chr_select_ad_pic_2_texture_descriptor); }

}
