#ifndef PSO_ITEM_TUNK_804A6010_H
#define PSO_ITEM_TUNK_804A6010_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// The Twinkle Star weapon class (vtable 0x804A6010): update_weapon spins the
// stars, vfunc_60 turns model nodes 1 and 3 by star_angle. Made by
// TObjPlayer::create_state_0.
class TUnk_804A6010 : public TItemWeapon {
public:
    virtual void vfunc_60();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    virtual ~TUnk_804A6010();
    TUnk_804A6010(TObject *parent, u8 *item);
    s32 star_angle;  // BAMS, +0xCCC per update_weapon
};

#endif
