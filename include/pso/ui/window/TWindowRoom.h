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

    static void *operator new(unsigned long size) {
        return TObject::operator new(size);
    }
    TWindowRoom(char *title);
    virtual ~TWindowRoom();
    void *get_title_entry();
    void draw_tab(void *context);
    virtual void run_task();
    virtual void render();
};

typedef char TWindowRoomSize[sizeof(TWindowRoom) == 0x64 ? 1 : -1];
typedef char RoomPositionOffset[offsetof(TWindowRoom, positionX) == 0x30 ? 1 : -1];
typedef char RoomWidthOffset[offsetof(TWindowRoom, width) == 0x38 ? 1 : -1];
typedef char RoomField48Offset[offsetof(TWindowRoom, unknown48) == 0x48 ? 1 : -1];
typedef char RoomTabParameterOffset[offsetof(TWindowRoom, tabParameter) == 0x60 ? 1 : -1];

extern "C" {
// TWindowRoom::~TWindowRoom(), called by the destructors that are still written by hand.
void *__dt__11TWindowRoomFv(void *p, s16 flags);
}

#endif
