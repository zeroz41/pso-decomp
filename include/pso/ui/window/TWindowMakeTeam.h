#ifndef PSO_UI_WINDOW_TWINDOWMAKETEAM_H
#define PSO_UI_WINDOW_TWINDOWMAKETEAM_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMakeTeam : public TObject {
    virtual ~TWindowMakeTeam();
    u8 m_1c;
    u8 m_1d;
    s8 m_1e;
    s8 m_1f;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u32 m_menu; // 0x2C: the window create_menu() returns; its entries are marked, disabled and named
    u32 m_30;
    u32 m_34;
    static s32 draw_entry_0x110(s8 arg0);
    u8 is_enabled();
    void set_state(s32 arg1);
    void send_state();
    void update_ok_button();
    s32 create_status_menu_window();
    s32 create_entry_menu_window();
    static s32 create_menu();
    virtual void render();
    virtual void run_task();
    void set_entry_string_by_id(void *arg1, s32 arg2);
};

LAYOUT_ASSERT(TWindowMakeTeam_size, sizeof(TWindowMakeTeam) == 0x38);
#endif
