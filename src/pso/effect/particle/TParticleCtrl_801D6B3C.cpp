#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TUnk_804B6C24.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject.h"


uaddr TParticleCtrl::validate_ctrl() {
    if (((u32) *(u32 *)&this->m_flags != 0U) && ((*(TUnk_804B6C24 **)&this->m_flags)->check_value_equals((saddr)TParticleCtrl::class_name) == 0)) {
        *(u32 *)&this->m_flags = 0U;
    }
    return *(u32 *)&this->m_flags;
}


void TParticleCtrl::destroy_particle() {
    void *x;
    x = (void *)((TParticleCtrl *)this)->validate_ctrl();
    if (x != NULL) {
        ((TObject *)(*(void * *)&this->m_flags))->queue_destruction();
    }
}
