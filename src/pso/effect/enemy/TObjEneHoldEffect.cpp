#include "types.h"
#include "pso/effect/enemy/TObjEneHoldEffect.h"

#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/effect/particle/TParticleCtrl.h"

TObjEneHoldEffect::~TObjEneHoldEffect() {
    if (*(void **)((s8 *)this + 0x90) != NULL) { TParticleCtrl::release(*(void **)((s8 *)this + 0x90)); this->m_90 = 0; }
}
