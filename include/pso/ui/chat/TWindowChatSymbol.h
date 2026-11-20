#ifndef PSO_UI_CHAT_TWINDOWCHATSYMBOL_H
#define PSO_UI_CHAT_TWINDOWCHATSYMBOL_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowChatSymbol : public TWindowBase {
    TWindowChatSymbol(s32 arg1, s32 arg2);
    virtual ~TWindowChatSymbol();
    virtual void render();
    u8 unk_1C[0x4];
    void * m_20;
    void* m_24;
    u8 unk_28[0x4];
    s32 m_2c;
    u8 unk_30[0x18];
    f32 m_48;
    u8 unk_4C[0x10];
    u32 m_5c;
    uaddr m_60;
    u32 m_64;
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowChatSymbol_size, sizeof(TWindowChatSymbol) == 0x68);
#endif
