#ifndef PSO_ITEM_TUNK_804A2678_H
#define PSO_ITEM_TUNK_804A2678_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A2678 : public TItemWeapon {
public:
    virtual ~TUnk_804A2678();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    u8 unk_1F8[0x4];
};

#endif
