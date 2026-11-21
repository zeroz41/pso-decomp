#ifndef PSO_WEAPON_SHOOT_TUNK_804A5340_H
#define PSO_WEAPON_SHOOT_TUNK_804A5340_H
#include "types.h"
#include "pso/weapon/shoot/TItemShootModel.h"

class TUnk_804A5340 : public TItemShootModel {
public:
    virtual ~TUnk_804A5340();
    virtual void hook();
    virtual void render();
};
LAYOUT_ASSERT(TUnk_804A5340_size, sizeof(TUnk_804A5340) == 0x6C);

#endif
