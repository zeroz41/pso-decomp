#ifndef PSO_WEAPON_TUNK_804ED1A0_H
#define PSO_WEAPON_TUNK_804ED1A0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804ED1A0 : public TItemWeapon {
public:
    // No destructor of its own: the compiler's comes last in the TU.
    TUnk_804ED1A0(TObject *parent, u8 *item);
    virtual void reserved_53();
    virtual void update_weapon();
};

u8 *create_morning_glory(u8 *arg0);

#endif
