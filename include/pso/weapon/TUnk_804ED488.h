#ifndef PSO_WEAPON_TUNK_804ED488_H
#define PSO_WEAPON_TUNK_804ED488_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804ED488 : public TItemWeapon {
public:
    TUnk_804ED488(TObject *parent, u8 *item);
    virtual ~TUnk_804ED488();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
};

u8 *create_dark_flow(u8 *arg0);

#endif
