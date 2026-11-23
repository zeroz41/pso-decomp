#ifndef PSO_TECHNIQUE_TTECRESTA_H
#define PSO_TECHNIQUE_TTECRESTA_H

#include "types.h"
#include "pso/player/TargetCursorList.h"
#include "pso/technique/TTecPlayerInfluence.h"

struct TTecResta : public TTecPlayerInfluence {
    TTecResta(void *owner, void *pos, void *targets, s32 level);
    TTecResta(void *owner, void *pos, s32 level);
    virtual ~TTecResta();
    virtual void apply_to_player(TObjPlayer *player);
    virtual void run_task();
    TargetCursorList targets;
    s32 m_13c;
    void play_launch_sound();
    int init_cast();
    static f32 calc_heal_amount(s32 level);
    void init_parameters();
    static void create(void *owner, void *pos, s32 level);
    static void create(void *source, void *origin, void *targets, s32 level);
    virtual void render();
};

LAYOUT_ASSERT(TTecResta_size, sizeof(TTecResta) == 0x140);
#endif
