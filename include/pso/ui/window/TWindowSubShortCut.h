#ifndef PSO_UI_WINDOW_TWINDOWSUBSHORTCUT_H
#define PSO_UI_WINDOW_TWINDOWSUBSHORTCUT_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowSubShortCut : public TObject {
    TWindowSubShortCut(TObject *arg1, void *arg2);
    virtual ~TWindowSubShortCut();
    void open_com_card_list();
    u8 m_1c;
    u8 unk_1D[0x1];
    u16 m_1e;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    u32 m_34;
    u32 m_38;
    u32 m_3c;
    void* m_40;
    s32 open_confirm_message();
    s32 open_confirm_prompt();
    s32 open_menu();
    virtual void render();
    virtual void run_task();
    void set_flag1e_bit80();
    void close_and_clear_flag();
    void free_icon();
    u8 unk_44[0x1C];
    u8 m_60;
    u8 unk_61[0x33];
};

typedef char TWindowSubShortCut_size[sizeof(TWindowSubShortCut) == 0x94 ? 1 : -1];
extern "C" {
void *__dt__18TWindowSubShortCutFv(TWindowSubShortCut *arg0, s16 arg1);
}

// --- C functions defined in TWindowSubShortCut.cpp ---
extern "C" {
void *__dt__18TWindowSubShortCutFv(TWindowSubShortCut *arg0, s16 arg1);
}
// --- end of C functions

#endif
