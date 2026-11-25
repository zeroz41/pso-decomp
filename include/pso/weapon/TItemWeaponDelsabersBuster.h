#ifndef PSO_WEAPON_TITEMWEAPONDELSABERSBUSTER_H
#define PSO_WEAPON_TITEMWEAPONDELSABERSBUSTER_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponDelsabersBuster : public TItemWeapon {
public:
    virtual ~TItemWeaponDelsabersBuster();
    virtual void update_weapon();
    TItemWeaponDelsabersBuster(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
