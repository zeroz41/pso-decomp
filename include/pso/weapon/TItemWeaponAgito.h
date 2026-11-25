#ifndef PSO_WEAPON_TITEMWEAPONAGITO_H
#define PSO_WEAPON_TITEMWEAPONAGITO_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponAgito : public TItemWeapon {
public:
    TItemWeaponAgito(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponAgito();
    virtual void emit_marker_effects();
};

#endif
