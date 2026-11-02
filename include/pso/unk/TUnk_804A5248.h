#ifndef PSO_UNK_TUNK_804A5248_H
#define PSO_UNK_TUNK_804A5248_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A5248 : public TItemWeapon {
public:
    virtual ~TUnk_804A5248();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    u8 unk_1F8[0x4];
};

#endif
