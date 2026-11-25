#ifndef PSO_WEAPON_TITEMWEAPONFLIGHTCUTTER_H
#define PSO_WEAPON_TITEMWEAPONFLIGHTCUTTER_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponFlightCutter : public TItemWeapon {
public:
    virtual ~TItemWeaponFlightCutter();
    virtual void emit_marker_effects();
    TItemWeaponFlightCutter(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
