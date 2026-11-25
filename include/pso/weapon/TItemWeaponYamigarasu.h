#ifndef PSO_WEAPON_TITEMWEAPONYAMIGARASU_H
#define PSO_WEAPON_TITEMWEAPONYAMIGARASU_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Yamigarasu weapon class (old names
// yamigarasu_start_timers, init_vtable_804A3738): its equip hook (slot 57) starts the
// confusion curse timer and a 90-frame timer event on the equip effect
// objects. Made by TItemWeaponYamigarasu::create.
class TItemWeaponYamigarasu : public TItemWeapon {
public:
    virtual void on_equipped();
    virtual ~TItemWeaponYamigarasu();
    TItemWeaponYamigarasu(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
