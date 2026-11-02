#ifndef PSO_ITEM_TUNK_804A1570_H
#define PSO_ITEM_TUNK_804A1570_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A1570 : public TItemWeapon {
public:
    virtual ~TUnk_804A1570();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    virtual void reserved_53();
    void*enter_state_513();
    u8 unk_1F8[0x4];
    s32 m_1fc;
    u8 unk_200[0x4];
};

#endif
