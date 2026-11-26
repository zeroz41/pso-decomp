#ifndef PSO_UI_FRONTEND_TADMULTICONFIRMGC_H
#define PSO_UI_FRONTEND_TADMULTICONFIRMGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TAdMultiOkGC;
class TAdChrSelPlayerGC;
class TAdGuideTxtGC;

struct TAdMultiConfirmGC : public TObject {
    TAdMultiConfirmGC(TObject *parent);
    virtual ~TAdMultiConfirmGC();
    u32 state;
    u32 count;                          // players taking part
    s32 ids[4];                         // multiplayer slot of each of them
    TAdChrSelPlayerGC *players[4];
    TAdGuideTxtGC *guide;
    TAdMultiOkGC *ok;
    virtual void render();
    virtual void run_task();
    void fn_802FF760();
    void fn_802FF7EC();
};

LAYOUT_ASSERT(TAdMultiConfirmGC_size, sizeof(TAdMultiConfirmGC) == 0x4C);
#endif
