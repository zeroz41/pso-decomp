#ifndef PSO_UI_WINDOW_TWINDOWMESSAGEINFOMATION_H
#define PSO_UI_WINDOW_TWINDOWMESSAGEINFOMATION_H

#include "types.h"

struct NJS_POINT2;
#include "pso/ui/window/TWindowMessage.h"

struct TWindowMessageInfomation : public TWindowMessage {
    TWindowMessageInfomation(const NJS_POINT2 *position, s32 client);
    virtual ~TWindowMessageInfomation();
    static const char *class_name;
    void render();
};

LAYOUT_ASSERT(TWindowMessageInfomation_size, sizeof(TWindowMessageInfomation) == 0x90);
#endif
