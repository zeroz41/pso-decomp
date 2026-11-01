#ifndef PSO_MISC_TWINDOWSUBMAGPHOTON_H
#define PSO_MISC_TWINDOWSUBMAGPHOTON_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowSubMagPhoton : public TWindowBase {
    virtual ~TWindowSubMagPhoton();
    void init_photon_blast_entries();
    int get_active_flag();
    virtual void render();
    u8 unk_1C[0x1];
    u8 m_1d;
    u8 unk_1E[0x2];
    s16 m_20;
    u8 _pad22[0x2];
    void* m_24;
    u8 unk_28[0x4];
    s32 m_2c;
    void* m_30;
    u8 _pad34[0x2C];
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
