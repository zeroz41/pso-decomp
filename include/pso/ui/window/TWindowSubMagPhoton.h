#ifndef PSO_UI_WINDOW_TWINDOWSUBMAGPHOTON_H
#define PSO_UI_WINDOW_TWINDOWSUBMAGPHOTON_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowSubMagPhoton : public TWindowBase {
    virtual ~TWindowSubMagPhoton();
    void init_photon_blast_entries();
    int get_active_flag();
    virtual void render();
    u8 m_60;
    u8 m_61;
    s16 m_62;
    u8 _pad64[0xC];
    u32 m_70;
    void handle_cancel();
    void play_open_sound();
    void update_selection_input();
    s32 draw_cursor(int arg1);
    virtual void run_task();
    void get_cursor_origin(void *xy);
};

typedef char TWindowSubMagPhoton_size[sizeof(TWindowSubMagPhoton) == 0x74 ? 1 : -1];
#endif
