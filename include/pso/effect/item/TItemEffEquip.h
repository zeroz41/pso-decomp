#ifndef PSO_EFFECT_ITEM_TITEMEFFEQUIP_H
#define PSO_EFFECT_ITEM_TITEMEFFEQUIP_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjBase;
class TParticleCtrl;

class TItemEffEquip : public TObject {
public:
 TObjBase *m_1c;       // the equipped actor the effect follows (inferred)
 TParticleCtrl *m_20;  // the particle effect spawned at its center
public:
    virtual ~TItemEffEquip();
    void spawn_equip_particle_effect(saddr);
    virtual void run_task();
public:
    static void create(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
    void release_effect();
};

extern "C" {
void *TItemEffEquip__ct(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5);
}

#endif
