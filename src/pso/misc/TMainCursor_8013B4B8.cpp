#include "types.h"
#include "pso/render/render_util.h"
#include "pso/misc/TMainCursor.h"
#include "pso/misc/TPlyPhotonChair.h"

extern "C" {

s32 draw_chunk_object();

extern f32 TMainCursor__data_805DB0C0;
extern f32 lbl_805DB0C8;
extern f32 TMainCursor__data_805DB0CC;

void TMainCursor::update_photon_chair() {
    s32 arg0 = (s32)this;
    if (((TMainCursor *)(arg0 + 0x4C))->get_pos() > lbl_805DB0C8) {
        save_model_draw_state((void*)(arg0 + 0x4C));
        begin_constant_color_draw_argb((void *)(arg0 + 0x4C), TMainCursor__data_805DB0CC, TMainCursor__data_805DB0C0, TMainCursor__data_805DB0C0, TMainCursor__data_805DB0C0);
        TMainCursor::get_cursor_state();
        draw_chunk_object();
        restore_model_draw_state((void*)(arg0 + 0x4C));
    }
}

}
