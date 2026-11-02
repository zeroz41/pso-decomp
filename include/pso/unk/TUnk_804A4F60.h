#ifndef PSO_UNK_TUNK_804A4F60_H
#define PSO_UNK_TUNK_804A4F60_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A4F60 : public TItemWeapon {
public:
    virtual ~TUnk_804A4F60();
    virtual void activate_effect(s32);
    virtual void update_idle();
    void psycho_wand_roll_extra();
    virtual void update_attack();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    u8 unk_1F8[0x4];
    f32 m_1fc;
    u8 unk_200[0x4];
    f32 m_204;
    u8 unk_208[0x5C];
    s32 m_264;
    u8 unk_268[0xC];
    f32 m_274;
    u8 unk_278[0x4];
};

#endif
