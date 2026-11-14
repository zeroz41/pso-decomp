#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TUnk_804B6C24.h"

extern "C" {

extern s32 TParticleCtrl__class_name_descriptor;

u32 TParticleCtrl::validate_ctrl() {
    if (((u32) *(u32 *)&this->m_flags != 0U) && (((TUnk_804B6C24 *)(*(s32 *)&this->m_flags))->check_value_equals(TParticleCtrl__class_name_descriptor) == 0)) {
        *(u32 *)&this->m_flags = 0U;
    }
    return *(u32 *)&this->m_flags;
}

}
