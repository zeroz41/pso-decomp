#ifndef PSO_UI_WINDOW_TWINDOWROOM_H
#define PSO_UI_WINDOW_TWINDOWROOM_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowBase.h"
#include <stddef.h>

struct TWindowRoom : public TWindowBase {
    f32 tabParameter;

    TWindowRoom(char *title);
    virtual ~TWindowRoom();
    void *get_title_entry();
    void draw_tab(void *context);
    virtual void run_task();
    virtual void render();
};

typedef char TWindowRoomSize[sizeof(TWindowRoom) == 0x64 ? 1 : -1];
typedef char RoomTabParameterOffset[offsetof(TWindowRoom, tabParameter) == 0x60 ? 1 : -1];

extern "C" {
// TWindowRoom::~TWindowRoom(), called by the destructors that are still written by hand.
void *__dt__11TWindowRoomFv(void *p, s16 flags);
}

#endif
