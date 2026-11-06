#ifndef PSO_ITEM_TUNK_804A5648_H
#define PSO_ITEM_TUNK_804A5648_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// Weapon class with vtable 0x804A5648 (old ctor name enter_state_515), made by
// TObjPlayer__sub_8012CE44.
class TUnk_804A5648 : public TItemWeapon {
public:
    virtual ~TUnk_804A5648();
    virtual void emit_marker_effects();
    TUnk_804A5648(TObject *parent, u8 *item);
    virtual void reserved_53();
    // The two points emit_marker_effects shoots from (launch_shot origins);
    // reserved_53 fills them (draw_status_icons).
    WeaponVector shot_origins[2];
};

extern "C" u8 *TObjPlayer__sub_8012CE44(s32 item);

#endif
