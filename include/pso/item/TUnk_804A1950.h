#ifndef PSO_ITEM_TUNK_804A1950_H
#define PSO_ITEM_TUNK_804A1950_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A1950 : public TItemWeapon {
public:
    virtual ~TUnk_804A1950();
    virtual void emit_marker_effects();
    TUnk_804A1950(TObject *parent, u8 *item);
};

#endif
