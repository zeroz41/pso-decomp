#ifndef PSO_UI_WINDOW_TWINDOWMAINMENU1P_H
#define PSO_UI_WINDOW_TWINDOWMAINMENU1P_H

#include "types.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/system/NinjaTypes.h"

struct TWindowMainMenu1P : public TWindowMainMenu {
    TWindowMainMenu1P(TObject *parent, s32 client);
    virtual ~TWindowMainMenu1P();
    virtual void open_main_menu();
    virtual void close_main_menu();
    virtual void on_menu_opened();
    virtual void on_submenu_closed();
    void update_backdrop_transition();
    void render();
    void run_task();
    void create_char_select_slot();

    u8 m_60;
    u8 m_61;
    CameraViewParams backdrop;
};

LAYOUT_ASSERT(TWindowMainMenu1P_size, sizeof(TWindowMainMenu1P) == 0xAC);
LAYOUT_ASSERT(MainMenu1PTransitionOffset, offsetof(TWindowMainMenu1P, m_60) == 0x60);
LAYOUT_ASSERT(MainMenu1PBackdropOffset, offsetof(TWindowMainMenu1P, backdrop) == 0x64);


// Window screen positions by window id, read by get_window_layout_position: the full-screen
// table covers every window id (get_option_entry reads ids 0xCF and 0xD0), the split-screen
// table only the first 92.
extern const NJS_POINT2 window_layout_rect_table[210];
extern const NJS_POINT2 window_layout_position_table[92];

#endif
