#ifndef PSO_UI_TADMULTIPLYCHRSELECTTRANSITIONGC_H
#define PSO_UI_TADMULTIPLYCHRSELECTTRANSITIONGC_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TWindowBase;

/* Character-select transition task: slides two status panels between position and target;
 * multi_chr_select_transition_instance holds the live instance for the TWindowSubSymbolChat display callback. */
class TAdMultiPlyChrSelectTransitionGC : public TObject {
public:
    TAdMultiPlyChrSelectTransitionGC(TObject *parent, s32 client);
    virtual ~TAdMultiPlyChrSelectTransitionGC();
    virtual void render();
    virtual void run_task();
    void update_transition_anim();

    f32 position0X;
    f32 position0Y;
    f32 target0X;
    f32 target0Y;
    f32 position1X;
    f32 position1Y;
    f32 target1X;
    f32 target1Y;
    s32 client;
    s32 timer;
    TObject *parent;
    TWindowBase *statusWindow;
    TWindowBase *callback;
};
LAYOUT_ASSERT(TAdMultiPlyChrSelectTransitionGC_size, sizeof(TAdMultiPlyChrSelectTransitionGC) == 0x50);

#endif
