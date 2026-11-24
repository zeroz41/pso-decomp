#ifndef PSO_BOSS_DARKFALZ_TOBOSS4ROCK_H
#define PSO_BOSS_DARKFALZ_TOBOSS4ROCK_H

#include "types.h"
#include "pso/boss/darkfalz/TOBoss4.h"
#include "pso/system/memory.h"

struct TOBoss4RockAngles {
    s32 x;
    s32 y;
    s32 z;
};

// A column of rocks that rise from the floor and respawn once they pass the
// top of the arena.
struct TOBoss4Rock : public TOBoss4 {
    TOBoss4Rock(void *set_data);
    virtual ~TOBoss4Rock();
    virtual void run_task();
    virtual void render();
    static void *create(void *set_data);
    static const char *class_name;
    f32 spread;  // horizontal range the rocks respawn in
    s32 count;   // 1-8, from set param 4
    NJS_OBJECT **models;
    NJS_TEXLIST **texlists;
    Vec *positions;
    f32 *speeds;
    TOBoss4RockAngles *rotations;
    TOBoss4RockAngles *rotation_speeds;
};

LAYOUT_ASSERT(TOBoss4Rock_size, sizeof(TOBoss4Rock) == 0xB8);
#endif
