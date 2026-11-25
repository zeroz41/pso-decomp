#ifndef PSO_WEAPON_TITEMWEAPONHUGEBATTLEFAN_H
#define PSO_WEAPON_TITEMWEAPONHUGEBATTLEFAN_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include <dolphin/mtx/GeoTypes.h>

// Weapon class (old ctor name init_state_vector), made by
// TItemWeaponHugeBattleFan::create.
class TItemWeaponHugeBattleFan : public TItemWeapon {
public:
    virtual ~TItemWeaponHugeBattleFan();
    virtual void transform_model_node();
    virtual void update_weapon();
    TItemWeaponHugeBattleFan(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual void emit_marker_effects();
    Vec scale;  // scale_current_matrix of model 1; y drops to 0.1 on the special, regrows
};


#endif
