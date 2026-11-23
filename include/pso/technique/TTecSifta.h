#ifndef PSO_TECHNIQUE_TTECSIFTA_H
#define PSO_TECHNIQUE_TTECSIFTA_H

#include "types.h"
#include "pso/player/TargetCursorList.h"
#include "pso/technique/TTecPlayerInfluence.h"

struct TTecSifta : public TTecPlayerInfluence {
    TTecSifta(void *owner, void *pos, void *targets, s32 level);
    TTecSifta(void *owner, void *pos, s32 level);
    virtual ~TTecSifta();
    void play_sifta_cast_sound();
    void spawn_sifta_range_effect();
    virtual void apply_to_player(TObjPlayer *player);
    virtual void run_task();
    TargetCursorList targets;
    s32 m_13c;
    void update_effect_params();
    static void create_instance(void *source, void *origin, void *targets, s32 level);
    static void create(void *owner, void *pos, s32 level);
    virtual void render();
};

LAYOUT_ASSERT(TTecSifta_size, sizeof(TTecSifta) == 0x140);
#endif
