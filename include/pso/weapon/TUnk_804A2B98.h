#ifndef PSO_WEAPON_TUNK_804A2B98_H
#define PSO_WEAPON_TUNK_804A2B98_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A2B98 : public TItemWeapon {
public:
    virtual ~TUnk_804A2B98();
    virtual void draw_held_model();
    virtual void emit_marker_effects();
    virtual void on_equipped();
    virtual void on_unequipped();
    virtual void transform_model_node();
    TUnk_804A2B98(TObject *parent, u8 *item);
};

#endif
