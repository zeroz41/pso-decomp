#ifndef PSO_WEAPON_TUNK_804A3168_H
#define PSO_WEAPON_TUNK_804A3168_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A3168 : public TItemWeapon {
public:
    TUnk_804A3168(TObject *parent, u8 *item);
    virtual ~TUnk_804A3168();
    virtual void emit_marker_effects();
};

extern "C" u8 *TObjPlayer__sub_80127314(u8 *item);

#endif
