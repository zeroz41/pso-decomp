#ifndef PSO_ITEM_TUNK_804A3260_H
#define PSO_ITEM_TUNK_804A3260_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A3260 : public TItemWeapon {
public:
    virtual ~TUnk_804A3260();
    virtual void vfunc_60();
    virtual void reserved_53();
    virtual void update_weapon();
    u8 unk_1F8[0x18];
    s32 m_210;
    u8 unk_214[0x4];
    s32 m_218;
    u8 unk_21C[0x4];
};

#endif
