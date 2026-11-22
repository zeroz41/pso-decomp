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
    uaddr m_24;
    uaddr m_28;
    uaddr m_menu; // 0x2C: the window create_menu() returns; its entries are marked, disabled and named
    uaddr m_30;
    uaddr m_34;
    static void *init_status_disp(s8 arg0);
    static saddr draw_entry_0x110(s8 arg0);
    s32 is_enabled();
    void set_state(s32 arg1);
    void send_state();
    void update_ok_button();
    saddr create_status_menu_window();
    saddr create_entry_menu_window();
    saddr create_menu();
    virtual void render();
    virtual void run_task();
    void set_entry_string_by_id(void *arg1, s32 arg2);
};

LAYOUT_ASSERT(TWindowMakeTeam_size, sizeof(TWindowMakeTeam) == 0x38);
#endif
