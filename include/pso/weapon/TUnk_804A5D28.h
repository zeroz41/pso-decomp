#ifndef PSO_WEAPON_TUNK_804A5D28_H
#define PSO_WEAPON_TUNK_804A5D28_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A5D28 : public TItemWeapon {
public:
    virtual ~TUnk_804A5D28();
    virtual void vfunc_60();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    TUnk_804A5D28(TObject *parent, u8 *item);
    f32 pad_1f8;   // approached to -2.0 then back to 0.0 by update_weapon (vfunc_60 offset)
    s32 m_1fc;     // 1 after a shot, 2 while returning, 0 at rest
};

#endif
