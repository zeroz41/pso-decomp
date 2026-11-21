#ifndef PSO_UI_WINDOW_TWINDOWMAINMENU1P_H
#define PSO_UI_WINDOW_TWINDOWMAINMENU1P_H

#include "types.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/system/NinjaTypes.h"

struct TWindowMainMenu1P : public TWindowMainMenu {
    TWindowMainMenu1P(TObject *parent, s32 client);
    virtual ~TWindowMainMenu1P();
    virtual void vfunc_6();
    virtual void vfunc_8();
    virtual void vfunc_7();
    virtual void vfunc_9();
    void update_backdrop_transition();
    void render();
    void run_task();
    void create_char_select_slot();

    u8 m_60;
    u8 m_61;
    CameraViewParams backdrop;
};

typedef char TWindowMainMenu1P_size[sizeof(TWindowMainMenu1P) == 0xAC ? 1 : -1];
typedef char MainMenu1PTransitionOffset[offsetof(TWindowMainMenu1P, m_60) == 0x60 ? 1 : -1];
typedef char MainMenu1PBackdropOffset[offsetof(TWindowMainMenu1P, backdrop) == 0x64 ? 1 : -1];


// Window screen positions by window id, read by get_window_layout_position: the full-screen
// table covers every window id (get_option_entry reads ids 0xCF and 0xD0), the split-screen
// table only the first 92.
extern const NJS_POINT2 window_layout_rect_table[210];
extern const NJS_POINT2 window_layout_position_table[92];

#endif
