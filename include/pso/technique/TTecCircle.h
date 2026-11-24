#ifndef PSO_TECHNIQUE_TTECCIRCLE_H
#define PSO_TECHNIQUE_TTECCIRCLE_H
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/technique/TechniqueParams.h"

class TObjChara;
struct TechniqueContactList;
struct TechniqueContactBody;

// Base of the area techniques: TTecGrants, TTecJelin, TTecZarua, TTecReverser, TTecRaBarta,
// TTecRaFoie, TTecRaZonde, TTecGiFoie, TTecLuker and TTecKafun derive from it.
class TTecCircle : public TEffect {
public:
    TTecCircle(saddr source, saddr pos, s32 level);
    TTecCircle(saddr source, Vec *pos, Vec *target, s32 level);
    virtual ~TTecCircle();
    virtual void apply_to_target(TObjChara *);
    virtual void tick_lifetime();
    virtual void vfunc_8(void *);
    virtual void vfunc_9();
    TechniqueContactList *find_area_contact(saddr);
    TechniqueContactList *collect_body_contacts(TObjCollidable *target, CollisionBody *body, void *player);
    TechniqueContactList *collect_body_contacts_for_target(saddr player);
    void apply_technique_to_area_targets();
    void move_toward_target();
    void count_if_within_range();
    virtual void render();
    virtual void run_task();
    f32 lifetime;  // tick_lifetime destroys it once age passes this
    s32 m_74;
    s16 level;
    s16 band;  // TObjPlayer::get_level_tier(level)
    Vec target;  // where the circle travels to before it spreads
    TechniqueParams params;  // calc_technique_parameters for the cast's level; range is the radius the area grows to
    u16 sourceId;
    u8 pad_B6[0x2];
    TechniqueContactBody *contact;  // the body of the target being hit
    CollisionBody collisionBody;
    TObjCollidable *collidable;
};
LAYOUT_ASSERT(TTecCircleSize, sizeof(TTecCircle) == 0xEC);

#endif
