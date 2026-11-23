#ifndef PSO_TECHNIQUE_TTECANTI_H
#define PSO_TECHNIQUE_TTECANTI_H

#include "types.h"
#include "pso/technique/TTecPlayerInfluence.h"
#include "pso/player/TargetCursorList.h"

struct TTecAnti : public TTecPlayerInfluence {
    TTecAnti(void *owner, void *pos, void *targets, s32 level);
    virtual ~TTecAnti();
    void play_anti_cast_sound();
    virtual void apply_to_player(TObjPlayer *player);
    virtual void run_task();
    TargetCursorList targets;
    s32 m_13c;
    static void create(void *source, void *origin, void *targets, s32 level);
    virtual void render();
};

LAYOUT_ASSERT(TTecAnti_size, sizeof(TTecAnti) == 0x140);
#endif
