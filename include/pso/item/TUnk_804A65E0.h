#ifndef PSO_ITEM_TUNK_804A65E0_H
#define PSO_ITEM_TUNK_804A65E0_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A65E0 : public TItemWeapon {
public:
    virtual ~TUnk_804A65E0();
    virtual void vfunc_57();
    virtual void emit_marker_effects();
    u8 unk_1F8[0xC];
    s32 m_204;
};

#endif
