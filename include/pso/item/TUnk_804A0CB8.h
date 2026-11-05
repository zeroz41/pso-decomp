#ifndef PSO_ITEM_TUNK_804A0CB8_H
#define PSO_ITEM_TUNK_804A0CB8_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A0CB8 : public TItemWeapon {
public:
    virtual ~TUnk_804A0CB8();
    TUnk_804A0CB8(TObject *parent, u8 *item);
    virtual void update_weapon();
    virtual void emit_marker_effects();
    // 0 after a shot until belra_cannon_return_timer fires (0x1E frames); update_weapon
    // hides model node child bit 8 while 0.
    s32 shot_ready;
};

u32 belra_cannon_create_extra_shot(void *arg0, s32 arg1, s32 arg2, f32 farg0);
long belra_cannon_create_shot(u8 *arg0);
u8 *create_belra_cannon(u8 *arg0);

#endif
