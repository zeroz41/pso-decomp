#ifndef PSO_ITEM_TUNK_804A65E0_H
#define PSO_ITEM_TUNK_804A65E0_H
#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TargetCursorList.h"

// Weapon class with vtable 0x804A65E0 (old ctor name TObjPlayer::initialize_effect_object):
// its special casts Gizonde from joint 0 at the owner's captured targets. Made by
// TObjPlayer::create_effect_object.
class TUnk_804A65E0 : public TItemWeapon {
public:
    virtual ~TUnk_804A65E0();
    virtual void vfunc_57();
    virtual void emit_marker_effects();
    TUnk_804A65E0(TObject *parent, u8 *item);
    WeaponVector cast_point;   // 0x1F8: joint 0, where Gizonde starts (inferred name)
    TargetCursorList targets;  // 0x204: Gizonde's targets
};

#endif
