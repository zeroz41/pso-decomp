#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"

extern "C" {

void __dt__5THeapFv(void*, int);

extern u32 TParticleCtrl__heap;

void TParticleCtrl::free_heap() {
    if ((u32) TParticleCtrl__heap != 0U) {
        __dt__5THeapFv((void*)TParticleCtrl__heap, 1);
        TParticleCtrl__heap = 0U;
    }
}

}
