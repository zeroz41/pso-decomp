#ifndef PSO_MISC_TUNK_80488838_H
#define PSO_MISC_TUNK_80488838_H
#include "types.h"
#include "pso/misc/TUnk_80488A28.h"

struct ControllerInputContext;

class TUnk_80488838 : public TUnk_80488A28 {
public:
    TUnk_80488838();
    virtual ~TUnk_80488838();
    void update_orbit_camera();
    virtual void run_task();
    ControllerInputContext *controller;
    f32 m_70;
};
typedef char TUnk_80488838_size[sizeof(TUnk_80488838) == 0x74 ? 1 : -1];

#endif
