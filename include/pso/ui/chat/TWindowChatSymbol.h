#ifndef PSO_UI_CHAT_TWINDOWCHATSYMBOL_H
#define PSO_UI_CHAT_TWINDOWCHATSYMBOL_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowChatSymbol : public TWindowBase {
    TWindowChatSymbol(s32 arg1, s32 arg2);
    virtual ~TWindowChatSymbol();
    virtual void render();
    u32 m_60;
    u32 m_64;
    virtual void run_task();
};

typedef char TWindowChatSymbol_size[sizeof(TWindowChatSymbol) == 0x68 ? 1 : -1];
#endif
