#ifndef PSO_ITEM_TUNK_804A2260_H
#define PSO_ITEM_TUNK_804A2260_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A2260 : public TItemWeapon {
public:
    virtual ~TUnk_804A2260();
    virtual void vfunc_60();
    void sub_80124C90();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    u8 unk_1F8[0x4];
};

#endif
