#ifndef PSO_TECHNIQUE_TTECANTI_H
#define PSO_TECHNIQUE_TTECANTI_H

#include "types.h"
#include "pso/technique/TTecPlayerInfluence.h"
#include "pso/player/TargetCursorList.h"

struct TTecAnti : public TTecPlayerInfluence {
    static const char *class_name;
    TTecAnti(TObjBase *owner, Vec *pos, TargetCursorList *targets, s32 level);
    virtual ~TTecAnti();
    void play_anti_cast_sound();
    void spawn_anti_range_effect();
    void setup_params();  // empty; the constructor calls it after loading params
    virtual void apply_to_player(TObjPlayer *player);
    virtual void run_task();
    TargetCursorList targets;
    // 1 when cast on a target list: run_task gives the effect to the caster and
    // the listed players; 0 gives it to the party members in range.
    s32 use_targets;
    static void create(TObjBase *source, Vec *origin, TargetCursorList *targets, s32 level);
    virtual void render();
};

LAYOUT_ASSERT(TTecAnti_size, sizeof(TTecAnti) == 0x140);

// A particle emitter of the Anti effect: it starts after `delay` frames, `count` times; bit 0 of flags puts it at the
// ground position instead of the body position.
struct AntiEmitterRow { s32 delay; s32 count; s32 id; s32 flags; };

#endif
