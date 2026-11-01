#include "types.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubTechnique.h"

extern "C" {
s32 TWindowSubTechnique::sub_80286AA8() {
    if ((u32) this->m_34 == 0U) {
        return 0;
    }
    if ((s32) this->m_2c == ((TWindowMenu *)this->m_34)->get_selected_value()) {
        return 0;
    }
    this->m_2c = ((TWindowMenu *)this->m_34)->get_selected_value();
    return 1;
}

}
