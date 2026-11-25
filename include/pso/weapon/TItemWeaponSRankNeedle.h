#ifndef PSO_WEAPON_TITEMWEAPONSRANKNEEDLE_H
#define PSO_WEAPON_TITEMWEAPONSRANKNEEDLE_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TItemWeaponSRankNeedle : public TUnk_804A4948 {
public:
    TItemWeaponSRankNeedle(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankNeedle();
    virtual void emit_marker_effects();
};

#endif
