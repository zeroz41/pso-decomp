#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

void TWindowCtrl::set_position(void *arg1) {
    if ((*(f32 *)&this->m_30 != *(f32 *)((s8 *)arg1 + 0)) || (*(f32 *)&this->m_34 != *(f32 *)((s8 *)arg1 + 4))) {
        *(f32 *)&this->m_30 = *(f32 *)((s8 *)arg1 + 0);
        *(f32 *)&this->m_34 = (f32) *(f32 *)((s8 *)arg1 + 4);
        this->m_50 = 3;
    }
}
