#ifndef PSO_MISC_TOBOSS4BIRD_H
#define PSO_MISC_TOBOSS4BIRD_H

#include "types.h"
#include "pso/misc/TOBoss4.h"
#include "pso/animation/ActorAnimationState.h"

// A flock of birds circling its set position, bobbing up and down.
struct TOBoss4Bird : public TOBoss4 {
    TOBoss4Bird(void *set_data);
    virtual ~TOBoss4Bird();
    virtual void run_task();
    virtual void render();
    static void *create(void *set_data);
    static const char *class_name;
    AnimationMotion *motion;
    f32 animation_end_frame;
    f32 animation_step;
    f32 animation_frame;
    f32 speed;
    f32 wander_height;
    f32 wander_radius;  // also the squared arrival distance
    s32 state;  // 0 pick a new target, 1 fly towards it
    s32 count;  // 1-6, set param 4 + 3
    Vec *offsets;
    s32 *angles;
    Vec target;
    f32 bob_height;
    f32 bob_offset;
    f32 bob_rate;
    s32 bob_angle_step;
    s32 bob_angle;
    s32 flight_timer;
};

typedef char TOBoss4Bird_size[sizeof(TOBoss4Bird) == 0xE8 ? 1 : -1];
#endif
