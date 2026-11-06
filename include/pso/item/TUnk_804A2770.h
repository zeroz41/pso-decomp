#ifndef PSO_ITEM_TUNK_804A2770_H
#define PSO_ITEM_TUNK_804A2770_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// Cane weapon class with vtable 0x804A2770 (old ctor name TObjPlayer__sub_80125F24), made by
// TObjPlayer::create_obj_80125F60.
class TUnk_804A2770 : public TItemWeapon {
public:
    virtual ~TUnk_804A2770();
    virtual void emit_marker_effects();
    TUnk_804A2770(TObject *parent, u8 *item);
};


#endif
