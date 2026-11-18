#ifndef PSO_UI_WINDOW_TWINDOWSNAPSHOT_H
#define PSO_UI_WINDOW_TWINDOWSNAPSHOT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowSnapShot : public TWindowBase {
    TWindowSnapShot(s32 arg1);
    virtual ~TWindowSnapShot();
    virtual void render();
    u8 _pad1C[0x8];
    void* m_24;
    u8 _pad28[0x4];
    u32 m_2c;
    u8 unk_30[0x10];
    u8 unk_40[0x1C];
    u32 m_5c;
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

typedef char TWindowSnapShot_size[sizeof(TWindowSnapShot) == 0x64 ? 1 : -1];

extern "C" {
u8 *__ct__15TWindowSnapShotFl(TWindowSnapShot *arg0, s32 arg1);
const char *get_player_motion_filename(void);
}
s32 load_player_motion_data(void);
extern "C" {
void render__15TWindowSnapShotFv(u8 *arg0);
}

#endif
