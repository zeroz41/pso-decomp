#ifndef PSO_WEAPON_TUNK_804A1288_H
#define PSO_WEAPON_TUNK_804A1288_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A1288 : public TItemWeapon {
public:
    virtual ~TUnk_804A1288();
    TUnk_804A1288(TObject *parent, u8 *item);
    virtual void emit_marker_effects();
};

#endif
