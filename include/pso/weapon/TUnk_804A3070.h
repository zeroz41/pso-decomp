#ifndef PSO_WEAPON_TUNK_804A3070_H
#define PSO_WEAPON_TUNK_804A3070_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A3070 : public TItemWeapon {
public:
    TUnk_804A3070(TObject *parent, u8 *item);
    virtual ~TUnk_804A3070();
    virtual void emit_marker_effects();
};

u8 *create_agito_weapon(u8 *arg0);

#endif
