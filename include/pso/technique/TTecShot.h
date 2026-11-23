#ifndef PSO_TECHNIQUE_TTECSHOT_H
#define PSO_TECHNIQUE_TTECSHOT_H
#include <stddef.h>
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/object/base/TObjMotion.h"

struct CsnGroup;
struct TechniqueContactActor;
struct TechniqueContactBody;

class TTecShot : public TEffect {
public:
    TTecShot(saddr arg1, u8 *arg2, u8 *arg3, s32 arg4);
    TTecShot(saddr source, Vec *pos, s32 angle, s32 level);
    virtual ~TTecShot();
    void check_technique_projectile_wall_hit();
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
    f32 range;
    f32 traveled;
    f32 previous[3];
    CsnGroup *ground_candidates[16];
    s16 level;
    s16 band;
    u16 sourceId;
    u8 unk_CA[0x2];
    f32 power;
    u8 parameters[0x28];
    TechniqueContactBody* contact;
    CollisionBody collisionBody;
    TechniqueContactActor* proxy;
    f32 halfWidth;
};

LAYOUT_ASSERT(TechniqueGroundCandidatesOffset, offsetof(TTecShot, ground_candidates) == 0x84);

extern "C" {
// TTecShot::~TTecShot(), called by the destructors that are still written by hand.
void *__dt__8TTecShotFv(void *p, s16 flags);
}

#endif
