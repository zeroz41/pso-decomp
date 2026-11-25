#ifndef PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATFACETYPE_H
#define PSO_UI_CHAT_TWINDOWSUBSYMBOLCHATFACETYPE_H

#include <stddef.h>
#include "types.h"

struct NJS_POINT2;
#include "pso/ui/window/TWindowBase.h"

struct TWindowSubStatusDisp;

struct TWindowSubSymbolChatFaceType : public TWindowBase {
    TWindowSubSymbolChatFaceType(const NJS_POINT2 *position, s8 *selected);
    virtual ~TWindowSubSymbolChatFaceType();
    void update_parts_entries();
    void handle_input();
    s32 is_open();
    s32 is_cancelled();
    s32 get_face_index();
    virtual void render();
    virtual void run_task();
    u8 result_flags;
    u8 cursor_col;
    u8 cursor_row;
    u8 _pad63[0x1];
    s8 *selection; // Borrowed selection byte.
    TWindowSubStatusDisp *status_disp;
    void close_when_chat_closed();
    void confirm_selection();
};

LAYOUT_ASSERT(TWindowSubSymbolChatFaceType_size, sizeof(TWindowSubSymbolChatFaceType) == 0x6C);

LAYOUT_ASSERT(FaceType_selection, offsetof(TWindowSubSymbolChatFaceType, selection) == 0x64);
LAYOUT_ASSERT(FaceType_heading, offsetof(TWindowSubSymbolChatFaceType, status_disp) == 0x68);

#endif
