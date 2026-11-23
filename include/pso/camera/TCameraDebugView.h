#ifndef PSO_CAMERA_TCAMERADEBUGVIEW_H
#define PSO_CAMERA_TCAMERADEBUGVIEW_H
#include "types.h"
#include "pso/camera/TCameraController.h"

// Camera mode 6: orbits get_demo_camera_position(), driven by the third
// controller: 0x400 held turns it with the stick, 0x200 held moves it in and out
// with 0x10/0x20, and 0x100 held shows the projection angle ("PERS = %d") and
// changes it with 0x20000/0x10000.
class TCameraDebugView : public TCameraController {
public:
    TCameraDebugView();
    virtual ~TCameraDebugView();
    static TCameraController *create();
    virtual void run_task();
    // The eye of the current demo camera, or the origin without one.
    static Vec get_demo_camera_position();
    f32 distance; // from the target, 20 to 400
};
LAYOUT_ASSERT(TCameraDebugView_size, sizeof(TCameraDebugView) == 0x70);

#endif
