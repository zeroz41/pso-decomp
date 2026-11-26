#ifndef PSO_TECHNIQUE_TTECRESTA_H
#define PSO_TECHNIQUE_TTECRESTA_H

#include "types.h"
#include "pso/player/TargetCursorList.h"
#include "pso/technique/TTecPlayerInfluence.h"

struct TTecResta : public TTecPlayerInfluence {
    static const char *class_name;
    TTecResta(TObjBase *owner, Vec *pos, TargetCursorList *targets, s32 level);
    TTecResta(TObjBase *owner, Vec *pos, s32 level);
    virtual ~TTecResta();
    virtual void apply_to_player(TObjPlayer *player);
    virtual void run_task();
    TargetCursorList targets;
    // 1 when cast on a target list: run_task gives the effect to the caster and
    // the listed players; 0 gives it to the party members in range.
    s32 use_targets;
    void play_launch_sound();
    void init_cast();
    static f32 calc_heal_amount(s32 level);
    void init_parameters();
    static void create(TObjBase *owner, Vec *pos, s32 level);
    static void create(TObjBase *source, Vec *origin, TargetCursorList *targets, s32 level);
    virtual void render();
};

LAYOUT_ASSERT(TTecResta_size, sizeof(TTecResta) == 0x140);

struct RecoveryEffectRow { s32 delay; s32 duration; s32 entry; u32 flags; };

#endif
