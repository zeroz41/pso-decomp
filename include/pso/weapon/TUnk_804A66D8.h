#ifndef PSO_WEAPON_TUNK_804A66D8_H
#define PSO_WEAPON_TUNK_804A66D8_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A66D8 : public TItemWeapon {
public:
    virtual ~TUnk_804A66D8();
    virtual void emit_marker_effects();
    virtual void reserved_53();
    TUnk_804A66D8(TObject *parent, u8 *item);
    Vec gun_point;         // first gun's shot origin (as TUnk_804A0EA8)
    Vec second_gun_point;  // second gun's
};

// Factory
TItem *create_twin_psychogun(u8 *item);

#endif
