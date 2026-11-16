#ifndef PSO_UNK_TUNK_80488838_H
#define PSO_UNK_TUNK_80488838_H
#include "types.h"
#include "pso/unk/TUnk_80488A28.h"

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

// --- C functions defined in TUnk_80488838.cpp ---
extern "C" {
void *TCameraCtrl__vt7(void);
void *__dt__13TUnk_80488838Fv(void *arg0, s16 arg1);
void target_player0__11TCameraCtrlFi(s32 arg0);
}
// --- end of C functions

#endif
