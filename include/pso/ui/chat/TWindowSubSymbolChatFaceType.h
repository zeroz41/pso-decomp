#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATFACETYPE_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATFACETYPE_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowSubSymbolChatFaceType : public TWindowBase {
    TWindowSubSymbolChatFaceType(s32 arg1, s32 arg2);
    virtual ~TWindowSubSymbolChatFaceType();
    void update_parts_entries();
    void handle_input();
    s32 is_open();
    virtual void render();
    virtual void run_task();
    u8 _pad1C[0x4];
    s16 m_20;
    u8 _pad22[0x2];
    void* m_24;
    u8 _pad28[0x4];
    u32 m_2c;
    u8 _pad30[0x2C];
    u32 m_5c;
    u8 m_60;
    u8 m_61;
    u8 m_62;
    u8 _pad63[0x1];
    u32 m_64;
    uaddr m_68;
    void close_when_chat_closed();
    void confirm_selection();
};

LAYOUT_ASSERT(TWindowSubSymbolChatFaceType_size, sizeof(TWindowSubSymbolChatFaceType) == 0x6C);

#endif
