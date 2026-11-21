#ifndef PSO_UI_CHAT_TWINDOWCHATSYMBOL_H
#define PSO_UI_CHAT_TWINDOWCHATSYMBOL_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowChatSymbol : public TWindowBase {
    TWindowChatSymbol(saddr arg1, saddr arg2);
    virtual ~TWindowChatSymbol();
    virtual void render();
    uaddr m_60;
    u32 m_64;
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowChatSymbol_size, sizeof(TWindowChatSymbol) == 0x68);
#endif
