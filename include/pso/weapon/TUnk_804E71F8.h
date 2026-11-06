#ifndef PSO_WEAPON_TUNK_804E71F8_H
#define PSO_WEAPON_TUNK_804E71F8_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804E71F8 : public TItemWeapon {
public:
    virtual ~TUnk_804E71F8();
    virtual void emit_marker_effects();
    void *construct_nug2000_bazooka(s32, void *);
};

#endif
