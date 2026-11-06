#ifndef PSO_ITEM_TUNK_804A3738_H
#define PSO_ITEM_TUNK_804A3738_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// The Yamigarasu weapon class (vtable 0x804A3738; old names
// yamigarasu_start_timers, init_vtable_804A3738): its equip hook (slot 57) starts the
// confusion curse timer and a 90-frame timer event on the equip effect
// objects. Made by yamigarasu_create.
class TUnk_804A3738 : public TItemWeapon {
public:
    virtual void vfunc_57();
    virtual ~TUnk_804A3738();
    TUnk_804A3738(TObject *parent, u8 *item);
};

u8 *yamigarasu_create(u8 *item);

#endif
