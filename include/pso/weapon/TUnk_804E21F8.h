#ifndef PSO_WEAPON_TUNK_804E21F8_H
#define PSO_WEAPON_TUNK_804E21F8_H
#include "types.h"
#include "pso/weapon/TUnk_804E23F0.h"

class TUnk_804E21F8 : public TUnk_804E23F0 {
public:
    TUnk_804E21F8(TObject *parent, u8 *item);
    virtual ~TUnk_804E21F8();
    virtual void activate_effect(s32);
    virtual void emit_marker_effects();
    virtual void reserved_53();
    virtual void update_weapon();
    virtual void on_equipped();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
    virtual void vfunc_62(Vec *pos);
    void sub_802D577C();
    Vec pad_20c[5];  // the shot origins sub_802D577C places around the owner
    s16 pad_248;     // frames since the last added shot
    s16 pad_24a;     // shots in use, up to 5 (activate_effect)
    f32 pad_24c;
    s32 pad_250;     // the ring's angle
};

#endif
