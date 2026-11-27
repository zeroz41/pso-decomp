#ifndef PSO_SYSTEM_TLOADCTRL_H
#define PSO_SYSTEM_TLOADCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TAdFadeGC;

struct TLoadCtrl : public TObject {
    TLoadCtrl(TObject *parent);
    virtual ~TLoadCtrl();
    // Nonzero: run_task polls the controllers and the keyboard while loading.
    s32 m_poll_input;
    // Frames since the loader started; the loading screen appears on the second.
    s32 m_frame_count;
    virtual void render();
    virtual void run_task();
    static void cleanup_scene();
    static void start_loading(u32 mode);
    static void poll_default();
    static void step();
    static void set_poll_input(s32 poll_input);
    // Whether a loader is running.
    static BOOL is_loading();

    // The running loader, NULL when none is.
    static TLoadCtrl *instance;
    // 0 now loading, 1 quest, 2 none, 3/4 floor entrance (start_loading's mode).
    static s32 loading_mode;
    static const char *class_name;
};

LAYOUT_ASSERT(TLoadCtrl_size, sizeof(TLoadCtrl) == 0x24);

// The fade task the loader started; cleared once it is queued for destruction.
extern TAdFadeGC *load_ctrl_fade_task;
#endif
