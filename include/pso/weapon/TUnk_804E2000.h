#ifndef PSO_WEAPON_TUNK_804E2000_H
#define PSO_WEAPON_TUNK_804E2000_H
#include "types.h"
#include "pso/weapon/TUnk_804E23F0.h"

class TUnk_804E2000 : public TUnk_804E23F0 {
public:
    virtual ~TUnk_804E2000();
    void *enter_state_341();
    u8 unk_204[0x4];
    s32 * m_208;
};

#endif
