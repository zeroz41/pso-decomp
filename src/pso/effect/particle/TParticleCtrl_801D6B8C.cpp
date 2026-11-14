#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *validate_ctrl__13TParticleCtrlFv(void *);

void TParticleCtrl::destroy_particle() {
    void *x;
    x = validate_ctrl__13TParticleCtrlFv(this);
    if (x != NULL) {
        ((TObject *)(*(void * *)&this->m_flags))->queue_destruction();
    }
}

}
