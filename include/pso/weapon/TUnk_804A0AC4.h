#ifndef PSO_WEAPON_TUNK_804A0AC4_H
#define PSO_WEAPON_TUNK_804A0AC4_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A0AC4 : public TItemWeapon {
public:
    virtual ~TUnk_804A0AC4();
    virtual void emit_marker_effects();
    TUnk_804A0AC4(TObject *parent, u8 *item);
    u8 pad_1f8[0x204 - 0x1F8];  // size from create_state_34; not touched in this TU
};

#endif
