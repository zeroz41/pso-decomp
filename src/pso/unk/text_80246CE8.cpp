#include "types.h"
#include "pso/misc/TWindowChallengeResult.h"
#include "pso/unk/text_80246CE8.h"
#include "pso/misc/TWindowBase.h"

extern "C" {
s32 draw_visible_window_entries(void *, void *, int);
void TWindowChallengeResult::render() {
    s32 temp_r3;
    s32 arg0 = (s32)this;
    temp_r3 = ((TWindowBase *)arg0)->setup_window_draw_context(arg0 + 0x60);
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries((void *)arg0, (void *)(arg0 + 0x24), (int)temp_r3);
}

}
