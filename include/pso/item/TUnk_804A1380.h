#ifndef PSO_ITEM_TUNK_804A1380_H
#define PSO_ITEM_TUNK_804A1380_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// The weapon class whose emit_marker_effects launches TTecFoie (vtable 0x804A1380).
class TUnk_804A1380 : public TItemWeapon {
public:
    virtual ~TUnk_804A1380();
    TUnk_804A1380(TObject *parent, u8 *item);
    virtual void emit_marker_effects();
};

#endif
