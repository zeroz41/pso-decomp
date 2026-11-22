#ifndef PSO_UI_WINDOW_TWINDOWSNAPSHOT_H
#define PSO_UI_WINDOW_TWINDOWSNAPSHOT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowSnapShot : public TWindowBase {
    TWindowSnapShot(saddr arg1);
    virtual ~TWindowSnapShot();
    virtual void render();
    u8 m_60;
    static void free_shared_instance();
    static int get_height();
    void play_open_sound();
    virtual void run_task();
    static int get_width();
    static void init_default();
    static void alloc_buffer();
    u8 unk_61[0x3];
};

LAYOUT_ASSERT(TWindowSnapShot_size, sizeof(TWindowSnapShot) == 0x64);

extern "C" {
const char *get_player_motion_filename(void);
}
s32 load_player_motion_data(void);

#endif
