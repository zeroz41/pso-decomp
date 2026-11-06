#ifndef PSO_BOSS_DRAGON_TOBJBOSS1ROCK_H
#define PSO_BOSS_DRAGON_TOBJBOSS1ROCK_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"

// A rock thrown up by the Dragon (Boss 1): it flies on m_velocity, bounces off
// the ground and fades out once it has lived 40 frames.
struct TObjBoss1Rock : public TObject {
    TObjBoss1Rock(TObject *parent, const Vec *pos, const Vec *vel, s32 kind);
    TObjBoss1Rock(TObject *parent, const Vec *pos, const Vec *vel);
    virtual ~TObjBoss1Rock();
    virtual void run_task();
    virtual void render();
    void sub_8002E1CC(const Vec *pos, const Vec *vel, s32 kind);

    Vec m_position;
    Vec m_velocity;
    s32 m_rotation_y;
    s32 m_rotation_x;
    s32 m_frames;
    NJS_ARGB m_color;    // a falls to 0 as the rock fades
    s32 m_model_index;   // entry of the dragon ground model table: 1, or 2 when kind is 0
};

typedef char TObjBoss1Rock_size[sizeof(TObjBoss1Rock) == 0x54 ? 1 : -1];
#endif
