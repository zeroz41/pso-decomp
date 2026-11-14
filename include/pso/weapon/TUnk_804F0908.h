#ifndef PSO_WEAPON_TUNK_804F0908_H
#define PSO_WEAPON_TUNK_804F0908_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804F0908 : public TItemWeapon {
public:
    virtual ~TUnk_804F0908();
    virtual void emit_marker_effects();
    TUnk_804F0908(TObject *parent, u8 *item);
};

#endif
