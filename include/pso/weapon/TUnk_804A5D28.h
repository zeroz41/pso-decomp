#ifndef PSO_WEAPON_TUNK_804A5D28_H
#define PSO_WEAPON_TUNK_804A5D28_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A5D28 : public TItemWeapon {
public:
    virtual ~TUnk_804A5D28();
    virtual void vfunc_60();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    void*setup_flame_effect();
    u8 unk_1F8[0x4];
    s32 m_1fc;
};

#endif
