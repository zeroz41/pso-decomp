#ifndef PSO_EFFECT_ITEM_TITEMEFFSHIELD_H
#define PSO_EFFECT_ITEM_TITEMEFFSHIELD_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TItemEffShield : public TObject {
public:
    virtual ~TItemEffShield();
    virtual void run_task();
public:
    void spawn_recipe_particles();
public:
    u8 *ct_init(u8 *arg1, s16 arg2);
};

#endif
