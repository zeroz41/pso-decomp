#ifndef PSO_WEAPON_TUNK_804A1190_H
#define PSO_WEAPON_TUNK_804A1190_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A1190 : public TItemWeapon {
public:
    virtual ~TUnk_804A1190();
    virtual void emit_marker_effects();
    TUnk_804A1190(TObject *parent, u8 *item);
};

// Factory
extern "C" {
u8 *TObjPlayer__sub_801229EC(u8 *arg0);
}

#endif
