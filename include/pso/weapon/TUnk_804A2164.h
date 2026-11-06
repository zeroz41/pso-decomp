#ifndef PSO_WEAPON_TUNK_804A2164_H
#define PSO_WEAPON_TUNK_804A2164_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A2164 : public TItemWeapon {
public:
    virtual ~TUnk_804A2164();
    virtual void vfunc_60();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    u8 unk_1F8[0x4];
    s32 m_1fc;
    u8 unk_200[0x4];
    s32 m_204;
};

#endif
