#ifndef PSO_WEAPON_TUNK_804A5648_H
#define PSO_WEAPON_TUNK_804A5648_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class with vtable 0x804A5648 (old ctor name enter_state_515), made by
// TObjPlayer__sub_8012CE44.
class TUnk_804A5648 : public TItemWeapon {
public:
    virtual ~TUnk_804A5648();
    virtual void emit_marker_effects();
    TUnk_804A5648(TObject *parent, u8 *item);
    virtual void draw_held_model();
    // The two points emit_marker_effects shoots from (launch_shot origins);
    // draw_held_model fills them (draw_status_icons).
    Vec shot_origins[2];
};

extern "C" TItem *TObjPlayer__sub_8012CE44(u8 *item);

#endif
