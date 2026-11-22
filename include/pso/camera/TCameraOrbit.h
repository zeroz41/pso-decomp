#ifndef PSO_CAMERA_TCAMERAORBIT_H
#define PSO_CAMERA_TCAMERAORBIT_H
#include "types.h"
#include "pso/unk/TUnk_80488A28.h"

struct ControllerInputContext;

// Camera mode 7: orbits player 0, starting behind it. While the first
// controller holds 0x400 its stick turns the camera and 0x20000/0x10000 move it
// out and in.
class TCameraOrbit : public TUnk_80488A28 {
public:
    TCameraOrbit();
    virtual ~TCameraOrbit();
    static TUnk_80488A28 *create();
    void update_orbit_camera();
    void reset_behind_player();
    void target_player0();
    virtual void reset_state();
    virtual void run_task();
    ControllerInputContext *controller;
    f32 distance; // from player 0, 15 to 1000
};
LAYOUT_ASSERT(TCameraOrbit_size, sizeof(TCameraOrbit) == 0x74);

#endif
