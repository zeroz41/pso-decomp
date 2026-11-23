#ifndef PSO_UI_WINDOW_TWINDOWMAKETEAM_H
#define PSO_UI_WINDOW_TWINDOWMAKETEAM_H

#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"

struct TKeyBoardControl;
class TWindowMenuInfomation;
class TWindowMenu;

struct TWindowMakeTeam : public TObject {
    TWindowMakeTeam(TObject *parent, s32 mode);
    virtual ~TWindowMakeTeam();
    u8 m_1c;
    u8 m_1d;
    s8 m_1e;
    s8 selected_value;
    s32 m_20;
    char *name;
    char *comment;
    TWindowMenuInfomation *m_menu; // 0x2C: the window create_menu() returns; its entries are marked, disabled and named
    TWindowMenu *m_30;
    TKeyBoardControl *keyboard;
    static void *init_status_disp(s8 arg0);
    static saddr draw_entry_0x110(s8 arg0);
    s32 is_enabled();
    u8 get_mode();
    u8 read_mode();
    s32 get_field_20();
    int test_flag_1d_bit1();
    int test_flag_1d_bit0();
    void set_state(s32 state);
    void send_state();
    void update_ok_button();
    TWindowMenu *create_status_menu_window();
    TWindowMenu *create_entry_menu_window();
    TWindowMenuInfomation *create_menu();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowMakeTeam_flags_offset, offsetof(TWindowMakeTeam, m_1d) == 0x1D);
LAYOUT_ASSERT(TWindowMakeTeam_mode_offset, offsetof(TWindowMakeTeam, m_1e) == 0x1E);
LAYOUT_ASSERT(TWindowMakeTeam_field_20_offset, offsetof(TWindowMakeTeam, m_20) == 0x20);
LAYOUT_ASSERT(TWindowMakeTeam_size, sizeof(TWindowMakeTeam) == 0x38);
#endif
