#ifndef PSO_WEAPON_TITEMWEAPONCARD_H
#define PSO_WEAPON_TITEMWEAPONCARD_H
#include "types.h"
#include <stddef.h>
#include "pso/weapon/TItemWeapon.h"

struct ActorBodyHit;
class TParticleCtrl;

// The thrown card weapons: weapon groups 0x8C (Talis, Mahu, Hitogata,
// Dancing Hitogata), 0x93 (the ten section ID cards), 0x96 (Gal Wind) and
// 0xA4 (Amore Rose). The held card leaves the hand at the throw; on the third
// step of a combo it is thrown three times in a fan.
class TItemWeaponCard : public TItemWeapon {
public:
    TItemWeaponCard(TObject *parent, u8 *item);
    static TItem *create(u8 *item); // weapon_factory_table entry
    virtual ~TItemWeaponCard();
    virtual void emit_marker_effects();
    virtual void draw_held_model();
    virtual void update_weapon();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);
    virtual void transform_model_node();
    // Run by emit_marker_effects at the throw point after the shots: the cane
    // effect on the first step of a combo.
    virtual void spawn_throw_effect(Vec *pos);

    u32 fan_flags;      // bit 0 while the attack stage is 2: draw the two extra cards
    s32 effect_id;      // TItemEffCane::create's effect: 445, 341 or 447
    f32 effect_scale;   // the shot's scale (WeaponEffectDescriptor::scale)
    void *wall_effect;  // called where the shot hits a wall (WeaponEffectDescriptor::wall_effect)
    void *hit_effect;   // called on the target the shot hits (WeaponEffectDescriptor::hit_effect)
};

// Weapon 0x8C00 and every card group without its own class.
class TItemWeaponTalis : public TItemWeaponCard {
public:
    TItemWeaponTalis(TObject *parent, u8 *item);
    virtual ~TItemWeaponTalis();
};

// Weapon 0x8C01.
class TItemWeaponMahu : public TItemWeaponCard {
public:
    TItemWeaponMahu(TObject *parent, u8 *item);
    virtual ~TItemWeaponMahu();
};

// Weapon 0x8C02.
class TItemWeaponHitogata : public TItemWeaponCard {
public:
    TItemWeaponHitogata(TObject *parent, u8 *item);
    virtual ~TItemWeaponHitogata();
    virtual void spawn_throw_effect(Vec *pos);
};

// Weapon 0x8C03: up to five copies of the model circle the owner, one more
// every 150 frames; the throw launches a shot from each.
class TItemWeaponDancingHitogata : public TItemWeaponCard {
public:
    TItemWeaponDancingHitogata(TObject *parent, u8 *item);
    virtual ~TItemWeaponDancingHitogata();
    virtual void activate_effect(s32 count);
    virtual void emit_marker_effects();
    virtual void draw_held_model();
    virtual void update_weapon();
    virtual void on_equipped();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);
    virtual void spawn_throw_effect(Vec *pos);
    // Places the circling copies around the owner's body centre.
    void update_orbit_points();

    Vec orbit_points[5];
    s16 orbit_timer;    // frames since the last copy was added
    s16 orbit_count;    // copies circling, up to 5 (activate_effect)
    f32 orbit_radius;   // the owner's body radius plus 5
    s32 orbit_angle;
};

// Weapon group 0x93: Viridia Card .. Whitill Card, named for the section IDs.
class TItemWeaponSectionIdCard : public TItemWeaponCard {
public:
    TItemWeaponSectionIdCard(TObject *parent, u8 *item);
    virtual ~TItemWeaponSectionIdCard();
    // The hit_effect and wall_effect: spawn_hit_particles where the shot struck.
    static void spawn_hit_particles_at(s32 item_id, ActorBodyHit *hit, Vec *dir);
    static void spawn_hit_particles_at_vec(s32 item_id, Vec *pos, Vec *dir);
    static void spawn_hit_particles(Vec *pos, const Vec *dir);
};

// Weapon 0xA400.
class TItemWeaponAmoreRose : public TItemWeaponCard {
public:
    TItemWeaponAmoreRose(TObject *parent, u8 *item);
    virtual ~TItemWeaponAmoreRose();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);
};

// Weapon 0x9600: on the third step of a combo it costs 7% of the owner's HP
// and hits ten times.
class TItemWeaponGalWind : public TItemWeaponCard {
public:
    TItemWeaponGalWind(TObject *parent, u8 *item);
    virtual ~TItemWeaponGalWind();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);
    // The hit_effect: spawn_hit_particle on the struck body's surface.
    static void spawn_hit_effect(s32 item_id, ActorBodyHit *hit, Vec *dir);
    static TParticleCtrl *spawn_hit_particle(Vec *pos);
};

// The Hitogata throw effect: particle 0x1BF carrying item model 0xD.
void spawn_hitogata_particle(Vec *pos);
// The point where a shot moving along direction meets the struck body's sphere.
void get_hit_surface_point(const ActorBodyHit *hit, Vec *out, Vec *direction);

LAYOUT_ASSERT(TItemWeaponCardFanFlagsOffset, offsetof(TItemWeaponCard, fan_flags) == 0x1F8);
LAYOUT_ASSERT(TItemWeaponCardHitEffectOffset, offsetof(TItemWeaponCard, hit_effect) == 0x208);
LAYOUT_ASSERT(TItemWeaponDancingHitogataOrbitOffset, offsetof(TItemWeaponDancingHitogata, orbit_points) == 0x20C);
LAYOUT_ASSERT(TItemWeaponDancingHitogataAngleOffset, offsetof(TItemWeaponDancingHitogata, orbit_angle) == 0x250);

#endif
