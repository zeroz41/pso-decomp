#ifndef PSO_MISC_TWINDOWMENUMAINMENU_H
#define PSO_MISC_TWINDOWMENUMAINMENU_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowMenuMainMenu : public TWindowBase {
    virtual ~TWindowMenuMainMenu();
    void handle_navigation_input();
    void handle_confirm();
    void handle_cancel();
    int get_menu_flag();
    int is_flag_set();
    virtual void render();
    virtual void run_task();
    u8 _pad1C[0x4];
    u16 m_20;
    u8 unk_22[0xA];
    s32 m_2c;
    u8 unk_30[0x24];
    f32 m_54;
    u8 unk_58[0x8];
    u8 m_60;
    u8 m_61;
    u16 m_62;
    void* m_64;
    u8 unk_68[0xDC];
};

typedef char TWindowMenuMainMenu_size[sizeof(TWindowMenuMainMenu) == 0x144 ? 1 : -1];

extern "C" {
u8 *TWindowMenuMainMenu__ct(TWindowMenuMainMenu *arg0, s32 arg1, s16 arg2);
void *__dt__19TWindowMenuMainMenuFv(void *arg0, s16 arg1);
void render__19TWindowMenuMainMenuFv(s32 arg0);
void run_task__19TWindowMenuMainMenuFv(TWindowMenuMainMenu *arg0);
}

// --- C functions defined in TWindowMenuMainMenu.cpp ---
extern "C" {
u8 *TWindowMenuMainMenu__ct(TWindowMenuMainMenu *window_menu_main_menu, s32 arg1, s16 arg2);
void *__dt__19TWindowMenuMainMenuFv(void *arg0, s16 arg1);
void render__19TWindowMenuMainMenuFv(s32 arg0);
void run_task__19TWindowMenuMainMenuFv(TWindowMenuMainMenu *window_menu_main_menu);
}
// --- end of C functions

#endif
