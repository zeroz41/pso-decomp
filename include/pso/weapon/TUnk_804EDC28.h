#ifndef PSO_WEAPON_TUNK_804EDC28_H
#define PSO_WEAPON_TUNK_804EDC28_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The guardianna weapon class (vtable 0x804EDC28), made by create_guardianna.
class TUnk_804EDC28 : public TItemWeapon {
public:
    TUnk_804EDC28(TObject *parent, u8 *item);
    virtual ~TUnk_804EDC28();
    virtual void emit_marker_effects();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
};

u8 *create_guardianna(u8 *item);

#endif
