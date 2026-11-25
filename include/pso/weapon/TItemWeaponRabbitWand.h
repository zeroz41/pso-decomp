#ifndef PSO_WEAPON_TITEMWEAPONRABBITWAND_H
#define PSO_WEAPON_TITEMWEAPONRABBITWAND_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponRabbitWand : public TItemWeapon {
public:
    virtual ~TItemWeaponRabbitWand();
    virtual void transform_model_node();
    TItemWeaponRabbitWand(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
