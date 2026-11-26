#ifndef PSO_TECHNIQUE_TTECSHOT_H
#define PSO_TECHNIQUE_TTECSHOT_H
#include <stddef.h>
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/CsnGroundCandidates.h"
#include "pso/technique/TechniqueParams.h"

class TObjChara;
struct CsnGroup;
struct CollisionBody;
struct TechniqueContactList;

class TTecShot : public TEffect {
public:
    // Flies from `pos` towards the point `target`.
    TTecShot(TObjBase *source, Vec *pos, Vec *target, s32 level);
    TTecShot(TObjBase *source, Vec *pos, int angle, s32 level);
    virtual ~TTecShot();
    void check_technique_projectile_wall_hit();
    // Slides along the floor (Barta) instead of flying straight.
    void step_ground_technique_projectile();
    void move_ground_technique_projectile();
    void move_technique_projectile();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_6();
    virtual void debug_print_tech_params();
    virtual void apply_to_target(TObjChara *);
    void advance_lifetime_or_destroy();
    void dispatch_all_technique_contacts();
    void dispatch_technique_contact(s32);
    TechniqueContactList *query_technique_player_contacts(TObjBase *source);
    TechniqueContactList *query_technique_enemy_contacts(TObjBase *source);
    Vec *get_pos_ptr();
    f32 range;
    f32 traveled;
    Vec previous;  // position before the last move
    CsnGroundCandidates ground_candidates;
    s16 level;
    s16 band;
    u16 sourceId;
    u8 pad_CA[0x2];
    TechniqueParams params;  // calc_technique_parameters for the cast's level
    CollisionBody *contact;
    CollisionBody collisionBody;
    TObjCollidable *collidable;
    f32 halfWidth;
};

LAYOUT_ASSERT(TechniqueGroundCandidatesOffset, offsetof(TTecShot, ground_candidates) == 0x84);

#endif
