#ifndef PSO_WEAPON_TUNK_804A1C38_H
#define PSO_WEAPON_TUNK_804A1C38_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A1C38 : public TItemWeapon {
public:
    virtual ~TUnk_804A1C38();
    TUnk_804A1C38(TObject *parent, u8 *item);
    virtual void reserved_53();
};

u8 *create_claw_weapon(u8 *arg0);

#endif
