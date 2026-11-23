#ifndef PSO_UI_CHAT_TWINDOWCHATSYMBOL_H
#define PSO_UI_CHAT_TWINDOWCHATSYMBOL_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct SymbolChatPreset;

struct TWindowChatSymbol : public TWindowBase {
    TWindowChatSymbol(saddr arg1, saddr arg2);
    virtual ~TWindowChatSymbol();
    void set_selection(SymbolChatPreset *preset);
    void set_from_key(s32 index);
    void update_visibility();
    virtual void render();
    SymbolChatPreset *selected_preset;
    u32 m_64;
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowChatSymbol_size, sizeof(TWindowChatSymbol) == 0x68);
#endif
