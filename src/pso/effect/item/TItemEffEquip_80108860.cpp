#include "types.h"
#include "pso/effect/item/TItemEffEquip.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/base/TObjMotion.h"

extern "C" {
u16 get_entity_id(void *);
TParticleCtrl *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
void TItemEffEquip::spawn_equip_particle_effect(saddr arg1) {
    m_20 = spawn_continuous_particle_effect_with_flags(m_1c->get_center(), arg1, 0x10);
    if (m_20 != NULL) {
        m_20->set_owner_id(get_entity_id(m_1c));
    }
}

}
