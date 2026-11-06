#ifndef PSO_WEAPON_TUNK_804A09B0_H
#define PSO_WEAPON_TUNK_804A09B0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A09B0 : public TItemWeapon {
public:
    virtual ~TUnk_804A09B0();
    TUnk_804A09B0(TObject *parent, u8 *item);
    virtual void emit_marker_effects();
};

#endif
