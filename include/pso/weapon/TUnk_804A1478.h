#ifndef PSO_WEAPON_TUNK_804A1478_H
#define PSO_WEAPON_TUNK_804A1478_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A1478 : public TItemWeapon {
public:
    virtual ~TUnk_804A1478();
    virtual void emit_marker_effects();
    TUnk_804A1478(TObject *parent, u8 *item);
};

TItem *create_wand_weapon(u8 *item);

#endif
