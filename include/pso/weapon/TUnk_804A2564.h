#ifndef PSO_WEAPON_TUNK_804A2564_H
#define PSO_WEAPON_TUNK_804A2564_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A2564 : public TItemWeapon {
public:
    virtual ~TUnk_804A2564();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    // Clears reload_timer.
    virtual void vfunc_57();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
    // Draws the loaded projectile (second_model) while reload_timer is 0.
    virtual void vfunc_60();
    TUnk_804A2564(TObject *parent, u8 *item);
    f32 pad_1f8;
    f32 pad_1fc;
    f32 pad_200;
    u8 pad_204[0x234 - 0x204];
    s32 reload_timer;      // 60 after a shot, counted down by update_weapon
    f32 pad_238;
    u32 descriptor_flags;  // ORed into the effect descriptor's flags
};
typedef char TUnk_804A2564_size[sizeof(TUnk_804A2564) == 0x240 ? 1 : -1];

#endif
