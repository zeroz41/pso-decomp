#include "types.h"
#include "pso/ui/window/TWindowMessageLog.h"

extern "C" {

s32 clamp_scroll_offset__17TWindowMessageLogFv(f32);

extern const f32 lbl_805DD240;

void TWindowMessageLog::update_scroll_animation() {
    f32 temp_f1;
    f32 temp_f1_2;

    temp_f1 = this->m_94;
    if (lbl_805DD240 != temp_f1) {
        this->m_84 = (f32) (this->m_84 + temp_f1);
        temp_f1_2 = this->m_6c;
        this->m_6c = (f32) (temp_f1_2 + this->m_94);
        this->m_94 = (f32) (this->m_94 * lbl_805DD240);
        clamp_scroll_offset__17TWindowMessageLogFv(temp_f1_2);
    }
}

}
