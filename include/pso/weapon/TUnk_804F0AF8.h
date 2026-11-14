#ifndef PSO_WEAPON_TUNK_804F0AF8_H
#define PSO_WEAPON_TUNK_804F0AF8_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804F0AF8 : public TItemWeapon {
public:
    virtual ~TUnk_804F0AF8();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void reserved_53();
    virtual void update_attack();
    TUnk_804F0AF8(TObject *parent, u8 *item);
    s32 unk_1F8;
    u32 m_1fc;
};

#endif
