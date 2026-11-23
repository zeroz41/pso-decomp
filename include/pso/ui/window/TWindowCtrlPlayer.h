#ifndef PSO_UI_WINDOW_TWINDOWCTRLPLAYER_H
#define PSO_UI_WINDOW_TWINDOWCTRLPLAYER_H

#include <stddef.h>
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowActionPalette;
struct TWindowLockOn;
struct TWindowMainMenu;
struct TWindowMessageInfomation;
struct TWindowShortListCtrl;
struct TWindowSimpleStatus;

struct TWindowCtrlPlayer : public TObject {
    TWindowCtrlPlayer(TObject *parent, s32 arg2);
    virtual ~TWindowCtrlPlayer();
    void sub_8024E0F0();
    u16 m_1c;
    u16 m_1e;
    u16 m_20;
    u8 _pad22[0x2];
    u32 m_24;
    TWindowMainMenu *m_28;
    TWindowMessageInfomation *message_information;
    TWindowSimpleStatus *simple_status;
    TWindowActionPalette *m_34;
    TWindowLockOn *lock_on_window;
    TWindowShortListCtrl *m_3c;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowCtrlPlayer_status_offset, offsetof(TWindowCtrlPlayer, simple_status) == 0x30);
LAYOUT_ASSERT(TWindowCtrlPlayer_lock_on_offset, offsetof(TWindowCtrlPlayer, lock_on_window) == 0x38);
LAYOUT_ASSERT(TWindowCtrlPlayer_menu_offset, offsetof(TWindowCtrlPlayer, m_28) == 0x28);
LAYOUT_ASSERT(TWindowCtrlPlayer_information_offset, offsetof(TWindowCtrlPlayer, message_information) == 0x2C);
LAYOUT_ASSERT(TWindowCtrlPlayer_action_palette_offset, offsetof(TWindowCtrlPlayer, m_34) == 0x34);
LAYOUT_ASSERT(TWindowCtrlPlayer_short_list_offset, offsetof(TWindowCtrlPlayer, m_3c) == 0x3C);
LAYOUT_ASSERT(TWindowCtrlPlayer_size, sizeof(TWindowCtrlPlayer) == 0x40);

#endif
