#ifndef PSO_WEAPON_TUNK_804A3548_H
#define PSO_WEAPON_TUNK_804A3548_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The weapon class whose emit_marker_effects launches TTecFoie at joint 1
// (vtable 0x804A3548). Made by TObjPlayer::create_vtable_804A3548.
class TUnk_804A3548 : public TItemWeapon {
public:
    virtual ~TUnk_804A3548();
    virtual void emit_marker_effects();
    TUnk_804A3548(TObject *parent, u8 *item);
};

#endif
