#ifndef PSO_UI_WINDOW_TWINDOWMESSAGEINFOMATION_H
#define PSO_UI_WINDOW_TWINDOWMESSAGEINFOMATION_H

#include "types.h"
#include "pso/ui/window/TWindowMessage.h"

struct TWindowMessageInfomation : public TWindowMessage {
    virtual ~TWindowMessageInfomation();
    void render();
};

typedef char TWindowMessageInfomation_size[sizeof(TWindowMessageInfomation) == 0x90 ? 1 : -1];
#endif
