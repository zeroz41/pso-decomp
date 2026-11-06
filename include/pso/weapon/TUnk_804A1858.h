#ifndef PSO_WEAPON_TUNK_804A1858_H
#define PSO_WEAPON_TUNK_804A1858_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A1858 : public TItemWeapon {
public:
    // No destructor of its own: the compiler's comes last in the TU.
    virtual void emit_marker_effects();
    virtual void update_weapon();
    TUnk_804A1858(TObject *parent, u8 *item);
    s16 uv_scroll;  // scroll_item_model_uvs du
    u8 pad_1fa[0x1FC - 0x1FA];
};

#endif
