#ifndef PSO_ITEM_TUNK_804A4D70_H
#define PSO_ITEM_TUNK_804A4D70_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A4D70 : public TItemWeapon {
public:
    virtual ~TUnk_804A4D70();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_weapon();
    virtual void update_attack();
    virtual void emit_marker_effects();
    void apply_scale_if_active(f32);
    u8 unk_1F8[0x4];
    f32 m_1fc;
    u8 unk_200[0x4];
    f32 m_204;
    u8 unk_208[0x4];
    f32 m_20c;
    u8 unk_210[0x4];
    f32 m_214;
    u8 unk_218[0x4];
    f32 m_21c;
};

#endif
