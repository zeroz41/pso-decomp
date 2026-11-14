#ifndef PSO_WEAPON_TUNK_804ECDC0_H
#define PSO_WEAPON_TUNK_804ECDC0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804ECDC0 : public TItemWeapon {
public:
    TUnk_804ECDC0(TObject *parent, u8 *item);
    virtual ~TUnk_804ECDC0();
    virtual void emit_marker_effects();
};

extern "C" u8 *TObjPlayer__sub_803265C0(u8 *arg0);

#endif
