#ifndef PSO_TECHNIQUE_TTECDEBAND_H
#define PSO_TECHNIQUE_TTECDEBAND_H

#include "types.h"
#include "pso/player/TargetCursorList.h"
#include "pso/technique/TTecPlayerInfluence.h"

struct TTecDeband : public TTecPlayerInfluence {
    TTecDeband(void *owner, void *pos, void *arg3, s32 level);
    TTecDeband(void *owner, void *pos, s32 level);
    virtual ~TTecDeband();
    virtual void apply_to_player(TObjPlayer *player);
    virtual void run_task();
    TargetCursorList targets;
    s32 m_13c;
    void init_params();
    void update_effect_params();
    static void create(saddr arg0, saddr arg1, saddr arg2, s32 arg3);
    static void create(void *owner, void *pos, s32 level);
    virtual void render();
    void play_state_sound();
};

LAYOUT_ASSERT(TTecDeband_size, sizeof(TTecDeband) == 0x140);

extern "C" {
void *__dt__10TTecDebandFv(void *arg0, s16 arg1);
}

#endif
