#ifndef PSO_WEAPON_TUNK_804A5A28_H
#define PSO_WEAPON_TUNK_804A5A28_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A5A28 : public TItemWeapon {
public:
    virtual ~TUnk_804A5A28();
    virtual void emit_marker_effects();
    TUnk_804A5A28(TObject *parent, u8 *item);
};

#endif
