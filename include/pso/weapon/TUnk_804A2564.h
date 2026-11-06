#ifndef PSO_WEAPON_TUNK_804A2564_H
#define PSO_WEAPON_TUNK_804A2564_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A2564 : public TItemWeapon {
public:
    virtual ~TUnk_804A2564();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    u8 unk_1F8[0x4];
    f32 m_1fc;
    u8 unk_200[0x34];
    s32 m_234;
    u8 unk_238[0x4];
    s32 m_23c;
};

#endif
