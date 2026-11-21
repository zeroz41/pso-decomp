#include "pso/ui/window/WindowDrawContext.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowAddition.h"

#pragma readonly_strings on

extern "C" {
s32 set_position_xy__15TWindowAdditionFff(f32, f32);
const char *TWindowAddition__name = "TWindowAddition";
#pragma push
#pragma fp_contract on
void TWindowAddition::step_window_tween() {
    f32 d;
    u32 n = tween_ticks;
    if (n == 0) {
        d = target_size[0] - frame_size[0];
        save_position();
    } else {
        d = (target_size[1] - frame_size[1]) / n;
        frame_position[0] += (target_position[0] - frame_position[0]) / n;
        frame_position[1] += (target_position[1] - frame_position[1]) / tween_ticks;
        frame_size[0] += (target_size[0] - frame_size[0]) / tween_ticks;
        frame_size[1] += d;
        tween_ticks--;
    }
    scroll_offset[1] -= 0.5f * d;
}
#pragma pop

WindowDrawContext *TWindowAddition::get_draw_context() {
    WindowDrawContext *context = setup_window_draw_context(content_scale);
    context->inner_x -= scroll_offset[0];
    context->inner_y -= scroll_offset[1];
    return context;
}

void TWindowAddition::sub_802443B4(u8 *) {
    m_name = TWindowAddition__name;
    scroll_offset[0] = 0.0f;
    scroll_offset[1] = 0.0f;
    set_position_xy__15TWindowAdditionFff(1.0f, 1.0f);
}

}
