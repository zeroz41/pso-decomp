#ifndef PSO_WEAPON_SHOOT_TUNK_804A2148_H
#define PSO_WEAPON_SHOOT_TUNK_804A2148_H
#include "types.h"
#include "pso/weapon/shoot/TItemShootModel.h"

// The drill launcher's shot (drill_launcher_create_shot).
class TUnk_804A2148 : public TItemShootModel {
public:
    TUnk_804A2148(void *owner, const Vec *pos, const Vec *dir, f32 life);
    virtual ~TUnk_804A2148();
    virtual void hook();
    virtual void render();
};
LAYOUT_ASSERT(TUnk_804A2148_size, sizeof(TUnk_804A2148) == 0x6C);

#endif
