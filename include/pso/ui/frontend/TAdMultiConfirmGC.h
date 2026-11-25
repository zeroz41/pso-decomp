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
    static int reset_cursor(void* p);
    static int set_cursor_index_1(void* p);
    static int set_cursor_index_2(void* p);
};

LAYOUT_ASSERT(TAdMultiConfirmGC_size, sizeof(TAdMultiConfirmGC) == 0x4C);
#endif
