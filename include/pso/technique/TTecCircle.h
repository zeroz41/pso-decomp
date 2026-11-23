#ifndef PSO_TECHNIQUE_TTECCIRCLE_H
#define PSO_TECHNIQUE_TTECCIRCLE_H
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/object/base/TObjMotion.h"

// Base of the area techniques: TTecGrants, TTecJelin, TTecZarua, TTecReverser, TTecRaBarta,
// TTecRaFoie, TTecRaZonde, TTecGiFoie, TTecLuker and TTecKafun derive from it.
class TTecCircle : public TEffect {
public:
    TTecCircle(saddr arg1, saddr arg2, s32 arg4);
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
    void sub_8022C008();
    void count_if_within_range();
    virtual void render();
    virtual void run_task();
    f32 lifetime;  // tick_lifetime destroys it once age passes this
    s32 m_74;
    s16 m_78;
    s16 band;  // TObjPlayer::get_level_tier(level)
    Vec target;  // sub_8022C008 moves position toward it
    f32 m_88;
    u8 unk_8C[0x4];
    f32 m_90;
    u8 unk_94[0x14];
    s16 m_a8;
    u8 unk_AA[0x2];
    s32 m_ac;
    u8 unk_B0[0x4];
    u16 m_b4;
    u8 unk_B6[0x2];
    saddr m_b8;
    CollisionBody collisionBody;
    TObjCollidable *m_e8;
};
LAYOUT_ASSERT(TTecCircleSize, sizeof(TTecCircle) == 0xEC);

#endif
