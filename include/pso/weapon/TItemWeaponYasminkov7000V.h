#ifndef PSO_WEAPON_TITEMWEAPONYASMINKOV7000V_H
#define PSO_WEAPON_TITEMWEAPONYASMINKOV7000V_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponYasminkov7000V : public TItemWeapon {
public:
    TItemWeaponYasminkov7000V(TObject *parent, u8 *item);
    virtual ~TItemWeaponYasminkov7000V();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    virtual void transform_model_node();
    s32 state;
    float m_1fc;
    f32 m_200;
    u8 unk_204[0x4];
};

TItem *create_yasminkov_7000v(u8 *item);

#endif
