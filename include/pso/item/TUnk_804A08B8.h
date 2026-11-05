#ifndef PSO_ITEM_TUNK_804A08B8_H
#define PSO_ITEM_TUNK_804A08B8_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A08B8 : public TItemWeapon {
public:
    virtual ~TUnk_804A08B8();
    virtual void emit_marker_effects();
    virtual void vfunc_57();
    TUnk_804A08B8(TObject *parent, u8 *item);
};

#endif
