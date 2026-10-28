#include "types.h"
#include "pso/TItemEffEquip.h"
#include "pso/TParticleCtrl.h"

struct VBase_18_7128e8 { char pad[0x18]; };

struct VObj_18_7128e8 : VBase_18_7128e8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7();
};

extern "C" {
u16 get_entity_id(void *);
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
void TItemEffEquip::spawn_equip_particle_effect(s32 arg1) {
    *(s32 *)&this->m_20 = (s32)spawn_continuous_particle_effect_with_flags((void *)(((VObj_18_7128e8 *)((u8 *)(*(u8 * *)&this->m_1c)))->m7()), (s32)arg1, 0x10);
    if ((u32) this->m_20 != 0U) {
        ((TParticleCtrl *)((void *) this->m_20))->set_owner_id(get_entity_id(this->m_1c));
    }
}

}
