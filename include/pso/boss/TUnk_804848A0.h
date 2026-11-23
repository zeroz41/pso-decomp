#ifndef PSO_BOSS_TUNK_804848A0_H
#define PSO_BOSS_TUNK_804848A0_H
#include "types.h"
#include "pso/unk/TScreenFade.h"

typedef void (*VoloptFadeCallback)();

// Fades the screen in from white for Vol Opt: alpha falls from 255 to 0, then
// on_done runs (or the task ends) and volopt_fade_in_done is set.
class TUnk_804848A0 : public TScreenFade {
public:
    VoloptFadeCallback on_done;

    TUnk_804848A0(TObject *parent, VoloptFadeCallback on_done);
    virtual ~TUnk_804848A0();
    virtual void run_task();
};
LAYOUT_ASSERT(TUnk_804848A0_size, sizeof(TUnk_804848A0) == 0x28);

// Fades the screen out to white for Vol Opt: alpha rises from 0 to 255, then
// on_done runs (or the task ends) and volopt_fade_out_done is set.
class TUnk_804848B8 : public TScreenFade {
public:
    VoloptFadeCallback on_done;

    TUnk_804848B8(TObject *parent, VoloptFadeCallback on_done);
    virtual ~TUnk_804848B8();
    virtual void run_task();
};
LAYOUT_ASSERT(TUnk_804848B8_size, sizeof(TUnk_804848B8) == 0x28);

extern s32 volopt_fade_out_done;
extern s32 volopt_fade_in_done;

#endif
