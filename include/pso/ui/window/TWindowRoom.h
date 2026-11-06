#ifndef PSO_UI_WINDOW_TWINDOWROOM_H
#define PSO_UI_WINDOW_TWINDOWROOM_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <stddef.h>

struct TWindowRoom {
    u32 className;
    u8 unknown04[0x14];
    void *objectVtable;
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
    void *get_title_entry();
    void draw_tab(void *context);
    void run_task();
    void draw_status();
};

typedef char TWindowRoomSize[sizeof(TWindowRoom) == 0x64 ? 1 : -1];
typedef char RoomVtableOffset[offsetof(TWindowRoom, objectVtable) == 0x18 ? 1 : -1];
typedef char RoomPositionOffset[offsetof(TWindowRoom, positionX) == 0x30 ? 1 : -1];
typedef char RoomWidthOffset[offsetof(TWindowRoom, width) == 0x38 ? 1 : -1];
typedef char RoomField48Offset[offsetof(TWindowRoom, unknown48) == 0x48 ? 1 : -1];
typedef char RoomTabParameterOffset[offsetof(TWindowRoom, tabParameter) == 0x60 ? 1 : -1];

extern "C" {
void *__dt__11TWindowRoomFv(void *arg0, s16 arg1);
}

#endif
