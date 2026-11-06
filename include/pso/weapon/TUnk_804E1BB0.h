#ifndef PSO_WEAPON_TUNK_804E1BB0_H
#define PSO_WEAPON_TUNK_804E1BB0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804E1BB0 : public TItemWeapon {
public:
    virtual ~TUnk_804E1BB0();
    virtual void reserved_53();
    void *init_state_513(s32, void *);
};

#endif
