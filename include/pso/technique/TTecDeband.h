#ifndef PSO_TECHNIQUE_TTECDEBAND_H
#define PSO_TECHNIQUE_TTECDEBAND_H

#include "types.h"
#include "pso/player/TargetCursorList.h"
#include "pso/technique/TTecPlayerInfluence.h"

struct TTecDeband : public TTecPlayerInfluence {
    static const char *class_name;
    TTecDeband(void *owner, void *pos, void *arg3, s32 level);
    TTecDeband(void *owner, void *pos, s32 level);
    virtual ~TTecDeband();
    virtual void apply_to_player(TObjPlayer *player);
    virtual void run_task();
    TargetCursorList targets;
    // 1 when cast on a target list: run_task gives the effect to the caster and
    // the listed players; 0 gives it to the party members in range.
    s32 use_targets;
    void init_params();
    void update_effect_params();
    static void create(saddr owner, saddr pos, saddr targets, s32 level);
    static void create(void *owner, void *pos, s32 level);
    virtual void render();
    void play_state_sound();
};

LAYOUT_ASSERT(TTecDeband_size, sizeof(TTecDeband) == 0x140);

extern "C" {
void *__dt__10TTecDebandFv(void *arg0, s16 arg1);
}

#endif
