#include "types.h"
#include "pso/ui/window/TWindowChoiceSetting.h"


#pragma push
#pragma fp_contract on
void TWindowChoiceSetting::sub_80249078() {
    f32 target;
    u32 steps;

    if (this->m_80 & 1) {
        steps = this->get_array_entry(this->get_field_74());
        target = *(f32 *)(steps + 0xC);
    } else {
        target = 0.0f;
    }
    steps = *(u32 *)&this->unk_50;
    if (steps == 0) {
        *(f32 *)&this->unk_60[0xC] = target;
        return;
    }
    target += 0.5f * (this->m_3c - this->m_4c);
    *(f32 *)&this->unk_60[0xC] += (target - *(f32 *)&this->unk_60[0xC]) / (f32)steps;
}
#pragma pop
