#ifndef PSO_WEAPON_TITEMWEAPONCHAINSAWD_H
#define PSO_WEAPON_TITEMWEAPONCHAINSAWD_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponChainSawd : public TItemWeapon {
public:
    // No destructor of its own: the compiler's comes last in the TU.
    virtual void emit_marker_effects();
    virtual void update_weapon();
    TItemWeaponChainSawd(TObject *parent, u8 *item);
    s16 uv_scroll;  // scroll_item_model_uvs du
    u8 pad_1fa[0x1FC - 0x1FA];
};

#endif
