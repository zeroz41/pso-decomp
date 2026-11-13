#ifndef PSO_UI_WINDOW_WINDOWCTRLCALLBACK_H
#define PSO_UI_WINDOW_WINDOWCTRLCALLBACK_H

#include "types.h"

class TWindowCtrlTarget;
typedef void (TWindowCtrlTarget::*WindowCtrlMethod)();

extern "C" {
void call_window_method__11TWindowCtrlFPvi(void *, WindowCtrlMethod);
}

#endif
