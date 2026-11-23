#ifndef PSO_WEAPON_TUNK_804A5550_H
#define PSO_WEAPON_TUNK_804A5550_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class made by create_saber_weapon (old ctor name
// TObjPlayer::init_state(long, void *)).
class TUnk_804A5550 : public TItemWeapon {
public:
    virtual ~TUnk_804A5550();
    virtual void update_weapon();
    TUnk_804A5550(TObject *parent, u8 *item);
};

TItem *create_saber_weapon(u8 *item);

#endif
