#include "types.h"
#include "pso/ui/TAdEnterBaseGC.h"
#include "pso/unk/text_8032AACC.h"
#include "pso/unk/text_8032AC9C.h"
struct P2_8032AC9C { f32 x, y; };

extern "C" {
void draw_window_frame__11TWindowBaseFPv();
void *get_localized_text_entry(int, int);
void render_status_line__15TAdSubPlyItemGCFi(void *, int, f32, f32, f32);
extern P2_8032AC9C password_screen_status_line_position[];
extern s32 TAdEnterBaseGC__entry_mode;
extern const f32 lbl_805DF778;
void fn_8032AC9C(void *arg0, void *arg1) {
    draw_window_frame__11TWindowBaseFPv();
    render_status_line__15TAdSubPlyItemGCFi(get_localized_text_entry(0x17, 4), -1, password_screen_status_line_position[0].x, password_screen_status_line_position[0].y, lbl_805DF778);
    switch (TAdEnterBaseGC__entry_mode) {
    case 0:
    case 1:
        fn_8032AC94();
        return;
    case 2:
        fn_8032AC24();
        return;
    case 3:
        draw_masked_password_field((s32)arg1);
        return;
    }
}

}
