#ifndef PSO_ITEM_TUNK_804A2F78_H
#define PSO_ITEM_TUNK_804A2F78_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A2F78 : public TItemWeapon {
public:
    virtual ~TUnk_804A2F78();
    virtual void vfunc_57();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    void*setup_effect();
    u8 unk_1F8[0x4];
    s32 m_1fc;
    u8 unk_200[0x4];
};

#endif
