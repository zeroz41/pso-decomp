#ifndef PSO_WEAPON_TITEMWEAPONPANZERFAUST_H
#define PSO_WEAPON_TITEMWEAPONPANZERFAUST_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/object/base/TObjCollidable.h"

class TItemWeaponPanzerFaust : public TItemWeapon {
public:
    virtual ~TItemWeaponPanzerFaust();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    // Clears reload_timer.
    virtual void on_equipped();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);
    // Draws the loaded projectile (second_model) while reload_timer is 0.
    virtual void transform_model_node();
    TItemWeaponPanzerFaust(TObject *parent, u8 *item);
    f32 pad_1f8;
    f32 pad_1fc;
    f32 pad_200;
    u8 pad_204[0x234 - 0x204];
    s32 reload_timer;      // 60 after a shot, counted down by update_weapon
    f32 pad_238;
    u32 descriptor_flags;  // ORed into the effect descriptor's flags
};
LAYOUT_ASSERT(TItemWeaponPanzerFaust_size, sizeof(TItemWeaponPanzerFaust) == 0x240);


TItem *create_panzer_faust(u8 *item);
// The Panzer Faust's hit and wall-hit callbacks.
void spawn_faust_hit_explosion(s32 id, ActorBodyHit *hit);
void spawn_faust_wall_explosion(s32 id, Vec *pos);

#endif
