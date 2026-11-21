#ifndef PSO_UI_WINDOW_TWINDOWSUBSHORTCUT_H
#define PSO_UI_WINDOW_TWINDOWSUBSHORTCUT_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowSubShortCut : public TObject {
    TWindowSubShortCut(TObject *object, void *arg2);
    virtual ~TWindowSubShortCut();
    void open_com_card_list();
    u8 m_1c;
    u8 unk_1D[0x1];
    u16 m_1e;
    uaddr m_20;
    uaddr m_24;
    uaddr m_28;
    uaddr m_2c;
    uaddr m_30;
    uaddr m_34;
    uaddr m_38;
    uaddr m_3c;
    void* m_40;
    s32 open_confirm_message();
    s32 open_confirm_prompt();
    s32 open_menu();
    virtual void render();
    virtual void run_task();
    u8 unk_44[0x1C];
    u8 m_60;
    u8 unk_61[0x33];
};

LAYOUT_ASSERT(TWindowSubShortCut_size, sizeof(TWindowSubShortCut) == 0x94);
#endif
