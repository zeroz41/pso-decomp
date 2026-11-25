#ifndef PSO_WEAPON_TITEMWEAPONRAINBOWBATON_H
#define PSO_WEAPON_TITEMWEAPONRAINBOWBATON_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponRainbowBaton : public TItemWeapon {
public:
    TItemWeaponRainbowBaton(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponRainbowBaton();
    virtual void emit_marker_effects();
};

extern "C" TItem *TItemWeaponRainbowBaton::create(u8 *item);

#endif
