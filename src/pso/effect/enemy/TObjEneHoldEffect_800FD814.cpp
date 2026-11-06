#include "types.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"

extern "C" {

int TCameraCtrl__sub_8006B370(f32 farg0);

u8 TObjEneHoldEffect::is_camera_visible() {
    int var_r31;

    var_r31 = 0;
    if ((TCameraCtrl__sub_8006B370(*(f32 *)&this->m_name) != 0) || (TCameraCtrl__sub_8006B370(*(f32 *)&this->m_flags) != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

}
