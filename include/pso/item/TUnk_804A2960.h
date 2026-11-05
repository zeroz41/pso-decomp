#ifndef PSO_ITEM_TUNK_804A2960_H
#define PSO_ITEM_TUNK_804A2960_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A2960 : public TItemWeapon {
public:
    virtual ~TUnk_804A2960();
    virtual void emit_marker_effects();
    u8 unk_1F8[0x4];
    s32 m_1fc;
    u8 unk_200[0x4];
};

extern "C" {
void *__dt__13TUnk_804A2960Fv(void *arg0, s16 arg1);
u8 *freeze_curse_timer_ct(u8 *event, s32 effect_objects, u16 owner_client, s32 frames, f32 rate);
}

#endif
