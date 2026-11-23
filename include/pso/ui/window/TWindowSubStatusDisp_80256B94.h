#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80256B94_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80256B94_H

#include "types.h"

class TWindowStatusGauge;
struct NJS_POINT2;
struct WindowDrawContext;

extern "C" void TWindowSubStatusDisp__sub_80256C40(TWindowStatusGauge *gauge, WindowDrawContext *context, NJS_POINT2 *position, f32 depth);

#endif
