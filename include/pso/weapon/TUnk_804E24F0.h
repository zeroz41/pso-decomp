#ifndef PSO_WEAPON_TUNK_804E24F0_H
#define PSO_WEAPON_TUNK_804E24F0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Same shape as TUnk_804F28E0 (vtable 0x804E24F0); made by TAdPlayerLoadGC::create_instance.
class TUnk_804E24F0 : public TItemWeapon {
public:
    TUnk_804E24F0(TObject *parent, u8 *item);
    virtual ~TUnk_804E24F0();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void emit_marker_effects();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
    virtual void update_attack();
    f32 pad_1f8;
};

#endif
