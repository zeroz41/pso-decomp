#include "types.h"
#include "pso/enemy/TObjEneHoldEffect.h"
#include "pso/enemy/TObjEneHoldEffect.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/effect/TParticleCtrl.h"

extern "C" {

void *__dt__17TObjEneHoldEffectFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

extern s32 __vt__17TObjEneHoldEffect[];

}
TObjEneHoldEffect::~TObjEneHoldEffect() {
    if (*(void **)((s8 *)this + 0x90) != NULL) { TParticleCtrl::release(*(void **)((s8 *)this + 0x90)); this->m_90 = 0; }
}
extern "C" {

}
