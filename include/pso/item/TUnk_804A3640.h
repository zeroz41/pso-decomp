#ifndef PSO_ITEM_TUNK_804A3640_H
#define PSO_ITEM_TUNK_804A3640_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A3640 : public TItemWeapon {
public:
    TUnk_804A3640(TObject *parent, u8 *item);
    virtual ~TUnk_804A3640();
    virtual void emit_marker_effects();
};

#endif
