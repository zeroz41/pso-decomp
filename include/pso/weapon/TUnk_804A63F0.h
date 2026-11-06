#ifndef PSO_WEAPON_TUNK_804A63F0_H
#define PSO_WEAPON_TUNK_804A63F0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A63F0 : public TItemWeapon {
public:
    virtual ~TUnk_804A63F0();
    virtual void emit_marker_effects();
    TUnk_804A63F0(TObject *parent, u8 *item);
};

#endif
