#ifndef PSO_ITEM_TUNK_804A64E8_H
#define PSO_ITEM_TUNK_804A64E8_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A64E8 : public TItemWeapon {
public:
    virtual ~TUnk_804A64E8();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void emit_marker_effects();
    virtual void update_attack();
    void*init_position_state();
    u8 unk_1F8[0x4];
    s32 m_1fc;
    u8 unk_200[0x4];
    s32 m_204;
};

#endif
