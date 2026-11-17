#ifndef PSO_UI_WINDOW_WINDOWLAYOUTCAMERA2DATA_H
#define PSO_UI_WINDOW_WINDOWLAYOUTCAMERA2DATA_H
#include "types.h"
#include "pso/system/NinjaTypes.h"

// .rodata 0x80477890-0x80477B70, defined by WindowLayoutCamera2Data.cpp (interim data-only unit): no
// code next to it reads it, so its real TU is not known yet.
// Split-screen window screen positions by window id for camera 2, read by get_window_layout_position
// (window_layout_position_table serves the other cameras).
extern const NJS_POINT2 window_layout_position_table_camera2[92];
#endif
