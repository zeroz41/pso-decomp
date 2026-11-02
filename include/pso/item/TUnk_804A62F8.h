#ifndef PSO_ITEM_TUNK_804A62F8_H
#define PSO_ITEM_TUNK_804A62F8_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A62F8 : public TItemWeapon {
public:
    virtual ~TUnk_804A62F8();
    virtual void vfunc_60();
    virtual void update_weapon();
    u8 unk_1F8[0x4];
};

#endif
