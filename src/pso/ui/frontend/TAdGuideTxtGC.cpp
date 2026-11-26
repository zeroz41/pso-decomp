#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/MenuText.h"
#include "types.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowSubTrade.h"
#include "pso/ui/window/TWindowMainMenu.h"

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

void TAdGuideTxtGC::set_line(s32 index, const char *line) {
    if (previous_text[index] != line) {
        text[index] = line;
        alpha[index] = 0;
    }
    previous_text[index] = line;
}

#pragma readonly_strings on
const char *TAdGuideTxtGC::class_name = "TAdGuideTxtGC";

#pragma push
#pragma fp_contract on
void TAdGuideTxtGC::run_task() {
    u32 i;
    f32 t;
    for (i = 0; i < 2; i++) {
        alpha[i] += 25;
        if (alpha[i] > 255) {
            alpha[i] = 255;
        }
        t = 640.0f - (f32)calc_text_width(const_cast<char *>(text[i]));
        position[i].x = t / 2.0f;
        position[i].y = 20.0f * (f32)i + 370.0f;
    }
}
#pragma pop

TAdGuideTxtGC::~TAdGuideTxtGC() {

}

#pragma push
#pragma opt_common_subs off
TAdGuideTxtGC::TAdGuideTxtGC(TObject *parent) : TObject(parent) {
    u32 i;
    m_name = TAdGuideTxtGC::class_name;
    for (i = 0; i < 2; i++) {
        text[i] = "";
        previous_text[i] = "";
        alpha[i] = 0;
    }
    create_draw_line_ctrl(this, 9, 0.0f);
}
#pragma pop

void TWindowSubTrade::finish() {
    parent_menu->on_submenu_closed();
    state = 7;
}
