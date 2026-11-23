#ifndef PSO_TECHNIQUE_TTECPLAYERINFLUENCE_H
#define PSO_TECHNIQUE_TTECPLAYERINFLUENCE_H

#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TechniqueContact.h"

class TObjPlayer;

struct TTecPlayerInfluence : public TEffect {
    TTecPlayerInfluence(void *owner, void *pos, s32 level);
    virtual ~TTecPlayerInfluence();
    static const char *class_name;
    virtual void tick_lifetime();
    // Gives one player the technique's effect.
    virtual void apply_to_player(TObjPlayer *player);
    void sub_80237258();
    // Applies the technique to every player in range (apply_to_player).
    void deliver_technique_to_party_targets();
    void spawn_support_tec_range_effect();
    TechniqueContactList *find_support_technique_contact_for_target(saddr player);
    TechniqueContactList *gather_player_contacts(TObjCollidable *target, CollisionBody *body, void *player);
    TechniqueContactList *gather_contacts_for_self(saddr player);
    f32 lifetime;  // tick_lifetime destroys it once age passes this
    TechniqueParams params;  // calc_technique_parameters for the cast's level
    s32 pad_A0;
    s16 level;
    s16 band;  // TObjPlayer::get_level_tier(level)
    u16 sourceId;  // the caster's entity id, looked up again every frame
    u8 pad_AA[0x2];
    s32 show_effects;  // 0 for a local player that has its effects off
    CollisionBody collisionBody;
    TObjCollidable *target;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TTecPlayerInfluence_size, sizeof(TTecPlayerInfluence) == 0xE0);

#endif
