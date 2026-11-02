#ifndef PSO_ITEM_TUNK_804A1098_H
#define PSO_ITEM_TUNK_804A1098_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A1098 : public TItemWeapon {
public:
    virtual ~TUnk_804A1098();
    virtual void vfunc_57();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_weapon();
    virtual void update_attack();
    u8 unk_1F8[0x4];
    s32 m_1fc;
};

#endif
