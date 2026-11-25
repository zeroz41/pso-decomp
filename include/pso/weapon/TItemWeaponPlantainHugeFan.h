#ifndef PSO_WEAPON_TITEMWEAPONPLANTAINHUGEFAN_H
#define PSO_WEAPON_TITEMWEAPONPLANTAINHUGEFAN_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponPlantainHugeFan : public TItemWeapon {
public:
    virtual ~TItemWeaponPlantainHugeFan();
    virtual void emit_marker_effects();
    TItemWeaponPlantainHugeFan(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    u8 pad_1f8[0x204 - 0x1F8];  // size from create_state_34; not touched in this TU
};

#endif
