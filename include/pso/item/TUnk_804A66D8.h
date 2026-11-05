#ifndef PSO_ITEM_TUNK_804A66D8_H
#define PSO_ITEM_TUNK_804A66D8_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A66D8 : public TItemWeapon {
public:
    virtual ~TUnk_804A66D8();
    virtual void emit_marker_effects();
    virtual void reserved_53();
    TUnk_804A66D8(TObject *parent, u8 *item);
    WeaponVector gun_point;         // first gun's shot origin (as TUnk_804A0EA8)
    WeaponVector second_gun_point;  // second gun's
};

// Factory
u8 *create_twin_psychogun(s32 arg0);

#endif
