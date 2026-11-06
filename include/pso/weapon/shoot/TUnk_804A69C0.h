#ifndef PSO_WEAPON_SHOOT_TUNK_804A69C0_H
#define PSO_WEAPON_SHOOT_TUNK_804A69C0_H
#include "types.h"
#include "pso/weapon/shoot/TItemShootModel.h"

class TUnk_804A69C0 : public TItemShootModel {
public:
    virtual ~TUnk_804A69C0();
    void *init_shoot_model();
    virtual void hook();
    virtual void render();
};
typedef char TUnk_804A69C0_size[sizeof(TUnk_804A69C0) == 0x6C ? 1 : -1];

#endif
