#ifndef PSO_UI_WINDOW_TWINDOWMESSAGEQUEST_H
#define PSO_UI_WINDOW_TWINDOWMESSAGEQUEST_H

#include "types.h"
#include "pso/ui/window/TWindowMessage.h"

struct TWindowMessageQuest : public TWindowMessage {
    TWindowMessageQuest(s32 parent);
    virtual ~TWindowMessageQuest();
    virtual void render();
    u8 unk_90[0x4];
};

LAYOUT_ASSERT(TWindowMessageQuest_size, sizeof(TWindowMessageQuest) == 0x94);

extern "C" {
void *__dt__19TWindowMessageQuestFv(void *arg0, s16 arg1);
}

extern "C" {
void create_quest_message_window(void);
}

#endif
