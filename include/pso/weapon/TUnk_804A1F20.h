#ifndef PSO_WEAPON_TUNK_804A1F20_H
#define PSO_WEAPON_TUNK_804A1F20_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A1F20 : public TItemWeapon {
public:
    virtual ~TUnk_804A1F20();
    virtual void update_weapon();
    TUnk_804A1F20(TObject *parent, u8 *item);
};

u8 *create_delsabers_buster_weapon(u8 *arg0);

#endif
