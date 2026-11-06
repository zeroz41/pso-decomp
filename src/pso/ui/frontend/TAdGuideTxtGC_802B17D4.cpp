#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/MenuText.h"

void TAdGuideTxtGC::render() {
    if (TMainTask::get_render_pass() != 1) {
        u32 i = 0;
        do {
            u32 color = (alpha[i] << 24) | 0xFFFFFF;
            draw_menu_text(position[i].x, position[i].y, text[i], color);
            i++;
        } while (i < 2);
    }
}
