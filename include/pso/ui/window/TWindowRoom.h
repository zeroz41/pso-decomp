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
    void draw_tab(WindowDrawContext *context);
    virtual void run_task();
    virtual void render();
};

LAYOUT_ASSERT(TWindowRoomSize, sizeof(TWindowRoom) == 0x64);
LAYOUT_ASSERT(RoomTabParameterOffset, offsetof(TWindowRoom, tabParameter) == 0x60);

extern "C" {
// TWindowRoom::~TWindowRoom(), called by the destructors that are still written by hand.
void *__dt__11TWindowRoomFv(void *p, s16 flags);
}

#endif
