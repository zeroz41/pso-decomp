#ifndef PSO_ENEMY_DELDEPTH_TOBJENEDELDEPTHBOMB_H
#define PSO_ENEMY_DELDEPTH_TOBJENEDELDEPTHBOMB_H

#include "types.h"
#include "pso/object/base/TObjChara.h"


struct TObjEneDelDepthBomb : public TObjChara {
    TObjEneDelDepthBomb(struct TObjEneDelDepth *parent, TObjChara *source, const Vec *position, s32 level);
    virtual ~TObjEneDelDepthBomb();
    virtual void render();
    virtual void run_task();
    s32 fn_80313268();
    static TObjEneDelDepthBomb *create(struct TObjEneDelDepth *parent, TObjChara *source, const Vec *position, s32 level);

    Vec velocity;
    f32 groundHeight;
    f32 distance;
    TObjChara *source;
    s32 age;
    s32 techniqueLevel;
    f32 speed;
};

typedef char TObjEneDelDepthBomb_size[sizeof(TObjEneDelDepthBomb) == 0x358 ? 1 : -1];

#endif
