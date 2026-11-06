#include "types.h"
#include "pso/effect/item/TItemEffEquip.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/effect/particle/TParticleCtrl.h"

void TItemEffEquip::release_effect() {
    if (((u32) this->m_1c != 0U) && ((s32) *(s32 *)((s8 *)this + 0x24) != -1)) {
        TParticleCtrl::release((void *)*(s32 *)&this->m_20);
        spawn_equip_particle_effect(*(s32 *)((s8 *)this + 0x24));
    }
}
