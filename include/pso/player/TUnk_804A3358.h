#ifndef PSO_PLAYER_TUNK_804A3358_H
#define PSO_PLAYER_TUNK_804A3358_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// Weapon class with vtable 0x804A3358 (old ctor name init_variant_34), made by
// TObjPlayer__sub_801277EC.
class TUnk_804A3358 : public TItemWeapon {
public:
    virtual ~TUnk_804A3358();
    virtual void emit_marker_effects();
    TUnk_804A3358(TObject *parent, u8 *item);
};

extern "C" u8 *TObjPlayer__sub_801277EC(u8 *item);

#endif
