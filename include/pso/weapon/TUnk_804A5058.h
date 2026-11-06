#ifndef PSO_WEAPON_TUNK_804A5058_H
#define PSO_WEAPON_TUNK_804A5058_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A5058 : public TItemWeapon {
public:
    virtual ~TUnk_804A5058();
    virtual void vfunc_60();
    TUnk_804A5058(TObject *parent, u8 *item);
};

#endif
