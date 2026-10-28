#ifndef PSO_ITEM_TUNK_804A5930_H
#define PSO_ITEM_TUNK_804A5930_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A5930 : public TItemWeapon {
public:
    virtual ~TUnk_804A5930();
    void sub_8010047C(s16);
    virtual void use();
    u8 unk_1F8[0x4];
};

#endif
