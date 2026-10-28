#include "pso/TAdBackGC.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/ui/TAdBackGC_8029A7B0.h"
#include "pso/unk/text_80141A30.h"
#include "pso/render/depth_buffer.h"

#include "types.h"
#include "pso/TMainTask.h"

extern "C" {
s32 draw_title_background_layer(void *, int, int, f32);
s32 defer_render__7TObjectFv();
extern s32 chr_select_ad_pic_2_texture_descriptor[];
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
        draw_title_background_layer(chr_select_ad_pic_2_texture_descriptor, 0, -1, (f32) (*(f32 *)((s8 *)arg0 + 0x1C)));
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x20) == 0) {
            restore_saved_depth_alpha_state();
        }
    }
}

void TAdBackGC::run_task() {  }

extern const f32 lbl_805DDC68;
extern s32 __vt__9TAdBackGC[];
extern void *TAdBackGC__class_name;

TAdBackGC::~TAdBackGC() {}
void *__ct__9TAdBackGCFv(void *ad_back_gc) {
    __ct__7TObjectFP7TObject(ad_back_gc);
    *(s32 **)((s8 *)ad_back_gc + 0x18) = __vt__9TAdBackGC;
    *(void * *)&((TAdBackGC *)ad_back_gc)->m_name = TAdBackGC__class_name;
    *(f32 *)((s8 *)ad_back_gc + 0x1C) = lbl_805DDC68;
    *(u32 *)((s8 *)ad_back_gc + 0x20) = 1;
    return ad_back_gc;
}

}
