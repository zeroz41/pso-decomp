#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"

extern "C" {

s32 check_value_equals__13TUnk_804B6C24Fl(s32, s32);

extern s32 TParticleCtrl__class_name_descriptor;

u32 TParticleCtrl::validate_ctrl() {
    if (((u32) *(u32 *)&this->m_flags != 0U) && (check_value_equals__13TUnk_804B6C24Fl(*(s32 *)&this->m_flags, TParticleCtrl__class_name_descriptor) == 0)) {
        *(u32 *)&this->m_flags = 0U;
    }
    return *(u32 *)&this->m_flags;
}

}
