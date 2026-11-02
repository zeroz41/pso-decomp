#ifndef PSO_ITEM_TUNK_804A69DC_H
#define PSO_ITEM_TUNK_804A69DC_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A69DC : public TItemWeapon {
public:
    virtual ~TUnk_804A69DC();
    virtual void reserved_53();
    virtual void vfunc_60();
    virtual void activate_effect(s32);
    virtual void update_idle();
    virtual void update_attack();
    void for_each_target_in_range(f32);
    void *init_state_35();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    u8 unk_1F8[0x4];
    s32 m_1fc;
    u8 unk_200[0x4];
    s32 m_204;
};

#endif
