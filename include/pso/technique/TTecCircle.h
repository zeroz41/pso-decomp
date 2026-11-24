#ifndef PSO_TECHNIQUE_TTECCIRCLE_H
#define PSO_TECHNIQUE_TTECCIRCLE_H
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/object/base/TObjMotion.h"

// Base of the area techniques: TTecGrants, TTecJelin, TTecZarua, TTecReverser, TTecRaBarta,
// TTecRaFoie, TTecRaZonde, TTecGiFoie, TTecLuker and TTecKafun derive from it.
class TTecCircle : public TEffect {
public:
    TTecCircle(saddr source, saddr pos, s32 level);
    TTecCircle(saddr source, Vec *pos, Vec *target, s32 level);
    virtual ~TTecCircle();
    virtual void vfunc_6(void *);
    virtual void tick_lifetime();
    virtual void vfunc_8(void *);
    virtual void vfunc_9();
    void find_area_contact(saddr);
    saddr collect_body_contacts(TObjCollidable *target, CollisionBody *body, void *player);
    saddr collect_body_contacts_for_target(saddr player);
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
    f32 power;  // the technique parameters (TechniqueParams) start here
    u8 pad_8C[0x4];
    f32 scope;  // the radius the area grows to
    u8 pad_94[0x14];
    s16 m_a8;
    u8 pad_AA[0x2];
    s16 base_power;
    u8 pad_AE[0x2];
    u8 pad_B0[0x4];
    u16 sourceId;
    u8 pad_B6[0x2];
    union {
        saddr m_b8;
        saddr attack_context;
    };
    CollisionBody collisionBody;
    TObjCollidable *collidable;
};
LAYOUT_ASSERT(TTecCircleSize, sizeof(TTecCircle) == 0xEC);

#endif
