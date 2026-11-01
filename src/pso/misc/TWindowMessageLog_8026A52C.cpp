#include "types.h"
#include "pso/misc/TWindowMessageLog.h"

extern "C" {

s32 update_fade__11TWindowBaseFv();

extern f32 lbl_805DD240;

void TWindowMessageLog::update_fade_offset() {
    f32 temp_f1;
    f32 temp_f31;

    temp_f31 = *(f32 *)&this->m_4c;
    update_fade__11TWindowBaseFv();
    temp_f1 = *(f32 *)&this->m_4c - temp_f31;
    if (lbl_805DD240 != temp_f1) {
        this->m_84 = (f32) (this->m_84 - temp_f1);
        this->m_6c = (f32) (this->m_6c - temp_f1);
        clamp_scroll_offset();
    }
}

}
