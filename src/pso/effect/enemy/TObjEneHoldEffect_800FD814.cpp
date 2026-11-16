#include "types.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"

extern "C" {

int is_float_nonfinite(f32 farg0);

u8 TObjEneHoldEffect::is_camera_visible() {
    int var_r31;

    var_r31 = 0;
    if ((is_float_nonfinite(*(f32 *)&this->m_name) != 0) || (is_float_nonfinite(*(f32 *)&this->m_flags) != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

}
