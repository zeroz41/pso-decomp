#ifndef PSO_UNK_TUNK_80488838_H
#define PSO_UNK_TUNK_80488838_H
#include "types.h"
#include "pso/camera/TCameraController.h"

struct ControllerInputContext;

class TUnk_80488838 : public TCameraController {
public:
    TUnk_80488838();
    virtual ~TUnk_80488838();
    void update_orbit_camera();
    void reset_behind_player();
    virtual void reset_state();
    virtual void run_task();
    ControllerInputContext *controller;
    f32 m_70;
};
LAYOUT_ASSERT(TUnk_80488838_size, sizeof(TUnk_80488838) == 0x74);

// --- C functions defined in TUnk_80488838.cpp ---
extern "C" {
void *TCameraCtrl__vt7(void);
void target_player0__11TCameraCtrlFi(saddr arg0);
}
// --- end of C functions

#endif
