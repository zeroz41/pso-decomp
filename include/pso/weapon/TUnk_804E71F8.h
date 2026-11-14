#ifndef PSO_WEAPON_TUNK_804E71F8_H
#define PSO_WEAPON_TUNK_804E71F8_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804E71F8 : public TItemWeapon {
public:
    virtual ~TUnk_804E71F8();
    virtual void emit_marker_effects();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
    TUnk_804E71F8(TObject *parent, u8 *item);
};

#endif
