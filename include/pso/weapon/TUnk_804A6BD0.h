#ifndef PSO_WEAPON_TUNK_804A6BD0_H
#define PSO_WEAPON_TUNK_804A6BD0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Yasminkov 3000R weapon class (vtable 0x804A6BD0; old names
// yasminkov_3000r_*): emit_marker_effects ejects a casing and starts the
// slide, update_weapon moves slide.z back and forth, the model hook (slot 60) translates
// model node 1 by slide. Made by create_yasminkov_3000r.
class TUnk_804A6BD0 : public TItemWeapon {
public:
    virtual void vfunc_60();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    virtual ~TUnk_804A6BD0();
    TUnk_804A6BD0(TObject *parent, u8 *item);
    WeaponVector slide;
    s32 slide_state;  // 2 opening, 3 open, 1 closing, 0 closed
};

u8 *create_yasminkov_3000r(u8 *item);

#endif
