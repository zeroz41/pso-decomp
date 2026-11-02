#ifndef PSO_ITEM_TUNK_804A1A48_H
#define PSO_ITEM_TUNK_804A1A48_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A1A48 : public TItemWeapon {
public:
    virtual ~TUnk_804A1A48();
    virtual void reserved_53();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    void *init_state_1();
    u8 unk_1F8[0x4];
    s32 m_1fc;
};

#endif
