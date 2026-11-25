#ifndef PSO_WEAPON_TITEMWEAPONDEMOLITIONCOMET_H
#define PSO_WEAPON_TITEMWEAPONDEMOLITIONCOMET_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponDemolitionComet : public TItemWeapon {
public:
    TItemWeaponDemolitionComet(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponDemolitionComet();
    virtual void update_attack();
    virtual void update_idle();
    virtual void transform_model_node();
    f32 z_offset;  // translate_matrix z offset for passes 3 and 4
    f32 alpha_offset;  // offset material colour alpha for pass 2
};

#endif
