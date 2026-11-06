#ifndef PSO_EFFECT_TITEMEFFEQUIP_H
#define PSO_EFFECT_TITEMEFFEQUIP_H

#include "pso/TObject.h"
#include "types.h"

class TItemEffEquip : public TObject {
public:
 void* m_1c;
 void* m_20;
public:
    virtual ~TItemEffEquip();
    void spawn_equip_particle_effect(s32);
    virtual void run_task();
public:
    static void create(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
    void release_effect();
};

extern "C" {
void *TItemEffEquip__ct(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5);
}

#endif
