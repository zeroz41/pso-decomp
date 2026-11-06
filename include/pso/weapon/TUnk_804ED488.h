#ifndef PSO_WEAPON_TUNK_804ED488_H
#define PSO_WEAPON_TUNK_804ED488_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804ED488 : public TItemWeapon {
public:
    virtual ~TUnk_804ED488();
    virtual void update_weapon();
    virtual void emit_marker_effects();
};

#endif
