#ifndef PSO_UI_WINDOW_TWINDOWMAINMENU1P_H
#define PSO_UI_WINDOW_TWINDOWMAINMENU1P_H

#include "types.h"
#include "pso/ui/window/TWindowMainMenu.h"

struct TWindowMainMenu1P : public TWindowMainMenu {
    virtual ~TWindowMainMenu1P();
    virtual void vfunc_6();
    virtual void vfunc_8();
    virtual void vfunc_7();
    virtual void vfunc_9();
    u8 m_60;
    u8 m_61;
    u8 _pad62[0x2];
    void* m_64;
    void update_backdrop_transition();
    void render();
    void run_task();
    void create_char_select_slot();
    u8 unk_4C[0x8];
    void * m_54;
    u8 unk_58[0x14];
    f32 m_6c;
    u8 unk_70[0x1C];
    f32 m_8c;
    u8 unk_90[0x4];
    f32 m_94;
    u8 unk_98[0x4];
    f32 m_9c;
    u8 unk_A0[0x4];
    f32 m_a4;
    u8 unk_A8[0x4];
};

typedef char TWindowMainMenu1P_size[sizeof(TWindowMainMenu1P) == 0xAC ? 1 : -1];

extern "C" {
void *TWindowMainMenu1P__ct(TWindowMainMenu1P *arg0);
u8 *__dt__17TWindowMainMenu1PFv(u8 *arg0, s16 arg1);
}

// --- C functions defined in TWindowMainMenu1P.cpp ---
extern "C" {
void *TWindowMainMenu1P__ct(TWindowMainMenu1P *window_main_menu1_p);
u8 *__dt__17TWindowMainMenu1PFv(u8 *arg0, s16 arg1);
}
// --- end of C functions

#endif
