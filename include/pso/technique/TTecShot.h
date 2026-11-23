#ifndef PSO_TECHNIQUE_TTECSHOT_H
#define PSO_TECHNIQUE_TTECSHOT_H
#include <stddef.h>
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/CsnGroundCandidates.h"

struct CsnGroup;
struct TechniqueContactBody;

class TTecShot : public TEffect {
public:
    // Flies from `pos` towards the point `target`.
    TTecShot(saddr source, u8 *pos, u8 *target, s32 level);
    TTecShot(saddr source, Vec *pos, s32 angle, s32 level);
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
    virtual void vfunc_8(void *);
    void advance_lifetime_or_destroy();
    void dispatch_all_technique_contacts();
    void dispatch_technique_contact(s32);
    u8 *query_technique_player_contacts(saddr);
    u8 *query_technique_enemy_contacts(saddr);
    Vec *get_pos_ptr();
    f32 range;
    f32 traveled;
    Vec previous;  // position before the last move
    CsnGroundCandidates ground_candidates;
    s16 level;
    s16 band;
    u16 sourceId;
    u8 pad_CA[0x2];
    f32 power;
    u8 parameters[0x28];
    TechniqueContactBody* contact;
    CollisionBody collisionBody;
    TObjCollidable *collidable;
    f32 halfWidth;
};

LAYOUT_ASSERT(TechniqueGroundCandidatesOffset, offsetof(TTecShot, ground_candidates) == 0x84);

#endif
