#ifndef PSO_UI_WINDOW_TWINDOWROOM_H
#define PSO_UI_WINDOW_TWINDOWROOM_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowBase.h"
#include <stddef.h>

struct TWindowRoom : public TWindowBase {
    u8 unknown1C[0x14];
    f32 positionX;
    u8 unknown34[4];
    f32 width;
    u8 unknown3C[0xC];
    f32 unknown48;
    u8 unknown4C[0x14];
    f32 tabParameter;

    TWindowRoom(char *title);
    virtual ~TWindowRoom();
    void *get_title_entry();
    void draw_tab(void *context);
    virtual void run_task();
    virtual void render();
};

LAYOUT_ASSERT(TWindowRoomSize, sizeof(TWindowRoom) == 0x64);
LAYOUT_ASSERT(RoomPositionOffset, offsetof(TWindowRoom, positionX) == 0x30);
LAYOUT_ASSERT(RoomWidthOffset, offsetof(TWindowRoom, width) == 0x38);
LAYOUT_ASSERT(RoomField48Offset, offsetof(TWindowRoom, unknown48) == 0x48);
LAYOUT_ASSERT(RoomTabParameterOffset, offsetof(TWindowRoom, tabParameter) == 0x60);

extern "C" {
// TWindowRoom::~TWindowRoom(), called by the destructors that are still written by hand.
void *__dt__11TWindowRoomFv(void *p, s16 flags);
}

#endif
