#ifndef PSO_WEAPON_TUNK_804A3830_H
#define PSO_WEAPON_TUNK_804A3830_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A3830 : public TItemWeapon {
public:
    TUnk_804A3830(TObject *parent, u8 *item);
    virtual ~TUnk_804A3830();
    virtual void reserved_53();
};

#endif
