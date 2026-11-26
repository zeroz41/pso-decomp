#ifndef PSO_BOSS_TBOSS3VOLOPTFADEIN_H
#define PSO_BOSS_TBOSS3VOLOPTFADEIN_H
#include "types.h"
#include "pso/system/TScreenFade.h"

typedef void (*VoloptFadeCallback)();

// Fades the screen in from white for Vol Opt: alpha falls from 255 to 0, then
// on_done runs (or the task ends) and volopt_fade_in_done is set.
class TBoss3VoloptFadeIn : public TScreenFade {
public:
    VoloptFadeCallback on_done;

    TBoss3VoloptFadeIn(TObject *parent, VoloptFadeCallback on_done);
    virtual ~TBoss3VoloptFadeIn();
    virtual void run_task();
};
LAYOUT_ASSERT(TBoss3VoloptFadeIn_size, sizeof(TBoss3VoloptFadeIn) == 0x28);

// Fades the screen out to white for Vol Opt: alpha rises from 0 to 255, then
// on_done runs (or the task ends) and volopt_fade_out_done is set.
class TBoss3VoloptFadeOut : public TScreenFade {
public:
    VoloptFadeCallback on_done;

    TBoss3VoloptFadeOut(TObject *parent, VoloptFadeCallback on_done);
    virtual ~TBoss3VoloptFadeOut();
    virtual void run_task();
};
LAYOUT_ASSERT(TBoss3VoloptFadeOut_size, sizeof(TBoss3VoloptFadeOut) == 0x28);

extern s32 volopt_fade_out_done;
extern s32 volopt_fade_in_done;

#endif
