#ifndef PSO_WEAPON_TUNK_804A6DC0_H
#define PSO_WEAPON_TUNK_804A6DC0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A6DC0 : public TItemWeapon {
public:
    TUnk_804A6DC0(TObject *parent, u8 *item);
    virtual ~TUnk_804A6DC0();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    virtual void vfunc_60();
    s32 state;
    float m_1fc;
    f32 m_200;
    u8 unk_204[0x4];
};

#endif
