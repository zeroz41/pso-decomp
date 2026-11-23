#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATFACETYPE_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATFACETYPE_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowSubStatusDisp;

struct TWindowSubSymbolChatFaceType : public TWindowBase {
    TWindowSubSymbolChatFaceType(void *position, s8 *selection);
    virtual ~TWindowSubSymbolChatFaceType();
    void update_parts_entries();
    void handle_input();
    s32 is_open();
    virtual void render();
    virtual void run_task();
    u8 m_60;
    u8 m_61;
    u8 m_62;
    u8 _pad63[0x1];
    s8 *m_64; // Borrowed selection byte.
    TWindowSubStatusDisp *m_68;
    void close_when_chat_closed();
    void confirm_selection();
};

LAYOUT_ASSERT(TWindowSubSymbolChatFaceType_size, sizeof(TWindowSubSymbolChatFaceType) == 0x6C);

LAYOUT_ASSERT(FaceType_selection, offsetof(TWindowSubSymbolChatFaceType, m_64) == 0x64);
LAYOUT_ASSERT(FaceType_heading, offsetof(TWindowSubSymbolChatFaceType, m_68) == 0x68);

#endif
