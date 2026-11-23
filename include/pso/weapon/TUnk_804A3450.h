#ifndef PSO_WEAPON_TUNK_804A3450_H
#define PSO_WEAPON_TUNK_804A3450_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The weapon class whose emit_marker_effects casts Jellen or, with TP,
// Zalure. Made by TObjPlayer::create_substate_b.
class TUnk_804A3450 : public TItemWeapon {
public:
    virtual void on_equipped();
    virtual void emit_marker_effects();
    virtual ~TUnk_804A3450();
    TUnk_804A3450(TObject *parent, u8 *item);
};

#endif
