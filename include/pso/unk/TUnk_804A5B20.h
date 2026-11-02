#ifndef PSO_UNK_TUNK_804A5B20_H
#define PSO_UNK_TUNK_804A5B20_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A5B20 : public TItemWeapon {
public:
    virtual ~TUnk_804A5B20();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    u8 unk_1F8[0x4];
    f32 m_1fc;
    u8 unk_200[0x4];
    f32 m_204;
};

#endif
