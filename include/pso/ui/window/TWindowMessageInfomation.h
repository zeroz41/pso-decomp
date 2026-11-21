#ifndef PSO_UI_WINDOW_TWINDOWMESSAGEINFOMATION_H
#define PSO_UI_WINDOW_TWINDOWMESSAGEINFOMATION_H

#include "types.h"
#include "pso/ui/window/TWindowMessage.h"

struct TWindowMessageInfomation : public TWindowMessage {
    TWindowMessageInfomation(s32 parent, s32 client);
    virtual ~TWindowMessageInfomation();
    void render();
};

LAYOUT_ASSERT(TWindowMessageInfomation_size, sizeof(TWindowMessageInfomation) == 0x90);
#endif
