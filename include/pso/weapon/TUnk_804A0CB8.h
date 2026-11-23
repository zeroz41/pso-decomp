#ifndef PSO_WEAPON_TUNK_804A0CB8_H
#define PSO_WEAPON_TUNK_804A0CB8_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

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

u32 belra_cannon_create_extra_shot(void *player, s32 pos, s32 dir, f32 life);
saddr belra_cannon_create_shot(void *owner, s32 pos, s32 dir, f32 life);
TItem *create_belra_cannon(u8 *item);

#endif
