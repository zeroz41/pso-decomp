#ifndef PSO_ITEM_TUNK_804A3450_H
#define PSO_ITEM_TUNK_804A3450_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// The weapon class whose emit_marker_effects casts Jellen or, with TP,
// Zalure (vtable 0x804A3450). Made by TObjPlayer::create_substate_b.
class TUnk_804A3450 : public TItemWeapon {
public:
    virtual void vfunc_57();
    virtual void emit_marker_effects();
    virtual ~TUnk_804A3450();
    TUnk_804A3450(TObject *parent, u8 *item);
};

#endif
