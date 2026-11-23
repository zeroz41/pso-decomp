#ifndef PSO_EFFECT_ITEM_TITEMWPNCARDEFFECT_H
#define PSO_EFFECT_ITEM_TITEMWPNCARDEFFECT_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/NinjaTypes.h"

// A card weapon's shot that stuck in an actor (anchored to the hit body) or a
// wall: a particle flash, then a trail, gone after 12 frames.
class TItemWpnCardEffect : public TObject {
public:
    TItemWpnCardEffect(TObject *parent, f32 *position, f32 *direction, s32 tint, s32 item_id);
    TItemWpnCardEffect(TObject *parent, ActorBodyHit *hit, f32 *direction, s32 tint, s32 item_id);
    virtual ~TItemWpnCardEffect();
    void anchor_card_effect();
    virtual void run_task();
    virtual void start_card_effect_flash();
    virtual void start_card_effect_trail();
    virtual void update_fade();  // every frame after the flash and trail steps
    void init();
    void destroy_effect_objects();

    static const char *class_name;

    void *particles[3];  // queued for destruction by destroy_effect_objects
    ActorBodyHit hit_target;
    s32 age;            // frames run: the flash starts at 0, the trail at 6, the effect ends at 12
    u16 target_id;      // get_entity_id of hit_target's actor, 0xFFFF when placed at a position
    Vec direction;      // normalized by init
    Vec anchor_offset;  // direction times the hit body's radius: position is the body's center less this
    u32 tint;           // the particles' tint colour, 0 for none
    s32 rotation[3];    // x, y, z angles; y faces direction
    s32 item_id;        // the card, looked up with find_item_by_id
    Vec position;
};
LAYOUT_ASSERT(TItemWpnCardEffect_size, sizeof(TItemWpnCardEffect) == 0x70);

// The card drawn with the weapon's second model, fading in while flashing.
class TItemWpnCardModelEffect : public TItemWpnCardEffect {
public:
    TItemWpnCardModelEffect(TObject *parent, f32 *position, f32 *direction, s32 tint, s32 item_id);
    TItemWpnCardModelEffect(TObject *parent, ActorBodyHit *hit, f32 *direction, s32 tint, s32 item_id);
    virtual ~TItemWpnCardModelEffect();
    void init_offset_vectors();
    virtual void render();
    virtual void update_fade();
    virtual void start_card_effect_trail();
    virtual void start_card_effect_flash();
    u32 card_flags;     // bit 0 while the card fades in (start_card_effect_flash)
    Vec scale;
    NJS_ARGB color;     // the constant material colour render draws the card with; a fades between -1 and 0
};
LAYOUT_ASSERT(TItemWpnCardModelEffect_size, sizeof(TItemWpnCardModelEffect) == 0x90);

// Guardianna's yellow card where a shot hits a wall; the red and untinted cards of other weapons.
void start_guardianna_wall_card(s32 item_id, saddr position, saddr direction);
void start_red_wall_card(s32 item_id, saddr position, saddr direction);
void start_wall_card(s32 item_id, saddr position, saddr direction);

#endif
