#ifndef PSO_UI_WINDOW_TWINDOWMESSAGEQUEST_H
#define PSO_UI_WINDOW_TWINDOWMESSAGEQUEST_H

#include "types.h"

struct NJS_POINT2;
#include "pso/ui/window/TWindowMessage.h"

struct TWindowMessageQuest : public TWindowMessage {
    TWindowMessageQuest(const NJS_POINT2 *position);
    virtual ~TWindowMessageQuest();
    virtual void render();
    void set_frame_mode(s32 mode);
    s32 frame_mode;
};

LAYOUT_ASSERT(TWindowMessageQuest_size, sizeof(TWindowMessageQuest) == 0x94);

extern "C" {
void *__dt__19TWindowMessageQuestFv(void *arg0, s16 arg1);
}

TWindowMessageQuest *create_quest_message_window();

#endif
