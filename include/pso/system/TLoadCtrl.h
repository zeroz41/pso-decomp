#ifndef PSO_SYSTEM_TLOADCTRL_H
#define PSO_SYSTEM_TLOADCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TLoadCtrl : public TObject {
    TLoadCtrl(saddr);
    virtual ~TLoadCtrl();
    s32 m_1c;
    s32 m_20;
    virtual void render();
    virtual void run_task();
    static void cleanup_scene();
    static void start_loading(u32 arg0);
    static void poll_default();
    static void step();
    static void set_field1C(s32 arg0);
    // Whether a loader is running.
    static BOOL is_loading();
};

LAYOUT_ASSERT(TLoadCtrl_size, sizeof(TLoadCtrl) == 0x24);

extern "C" {
// The fade task the loader started; cleared once it is queued for destruction.
extern saddr TLoadCtrl__fade_task;
}
#endif
