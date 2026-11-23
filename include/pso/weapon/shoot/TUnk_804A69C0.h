#ifndef PSO_WEAPON_SHOOT_TUNK_804A69C0_H
#define PSO_WEAPON_SHOOT_TUNK_804A69C0_H
#include "types.h"
#include "pso/weapon/shoot/TItemShootModel.h"

class TUnk_804A69C0 : public TItemShootModel {
public:
    TUnk_804A69C0(void *owner, const Vec *pos, const Vec *dir, f32 life);
    virtual ~TUnk_804A69C0();
    virtual void hook();
    virtual void render();
};
LAYOUT_ASSERT(TUnk_804A69C0_size, sizeof(TUnk_804A69C0) == 0x6C);

#endif
