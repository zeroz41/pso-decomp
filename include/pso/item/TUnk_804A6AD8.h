#ifndef PSO_ITEM_TUNK_804A6AD8_H
#define PSO_ITEM_TUNK_804A6AD8_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// The Yasminkov 9000M weapon class (vtable 0x804A6AD8; old names
// yasminkov_9000m_*): two guns, the second drawn at joint 35 by reserved_53.
// emit_marker_effects fires a shot from each muzzle and starts the slide,
// update_weapon moves slide.y and ejects a casing per gun; the model hook (slot 60)
// translates model node 2 by slide. Made by create_yasminkov_9000m.
class TUnk_804A6AD8 : public TItemWeapon {
public:
    virtual void reserved_53();
    virtual void vfunc_60();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    void yasminkov_9000m_eject_casing(WeaponVector *pos, s32 angle_offset);
    virtual ~TUnk_804A6AD8();
    TUnk_804A6AD8(TObject *parent, u8 *item);
    s32 slide_state;  // 2 opening, 3 open, 1 closing, 0 closed
    WeaponVector slide;
    WeaponVector muzzles[2];   // joint 3 of each gun
    WeaponVector ejectors[2];  // joint 1 of each gun
};

u8 *create_yasminkov_9000m(u8 *item);

#endif
