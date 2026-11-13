#ifndef PSO_UI_WINDOW_TWINDOWSHORTCUT_H
#define PSO_UI_WINDOW_TWINDOWSHORTCUT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowChatSymbol;

struct TWindowShortCut : public TWindowBase {
    virtual ~TWindowShortCut();
    virtual void render();
    u8 _pad1C[0x4];
    s16 m_20;
    u8 _pad22[0x2];
    void* m_24;
    u8 _pad28[0x38];
    u32 m_60;
    TWindowBase *message_window;
    TWindowChatSymbol *symbol_chat_window;
    s32 index;
    s32 *chat_shortcut;
    virtual void run_task();
    void sub_8026E1D4(s32 index, s32 *chat_shortcut);
};

typedef char TWindowShortCut_size[sizeof(TWindowShortCut) == 0x74 ? 1 : -1];

extern "C" {
u8 *TWindowShortCut__ct(TWindowShortCut *window_short_cut, s32 arg1, s32 index, s32 chat_shortcut_addr);
void *__dt__15TWindowShortCutFv(TWindowShortCut *self, s16 arg1);
void render__15TWindowShortCutFv(u8 *arg0);
}

#endif
