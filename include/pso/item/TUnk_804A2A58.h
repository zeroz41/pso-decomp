#ifndef PSO_ITEM_TUNK_804A2A58_H
#define PSO_ITEM_TUNK_804A2A58_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A2A58 : public TItemWeapon {
public:
    virtual ~TUnk_804A2A58();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    virtual void vfunc_60();
    u8 unk_1F8[0x4];
    s32 m_1fc;
};

extern "C" {
void *baranz_launcher_ct(void *a0);
}

#endif
