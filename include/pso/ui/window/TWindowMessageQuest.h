#ifndef PSO_UI_WINDOW_TWINDOWMESSAGEQUEST_H
#define PSO_UI_WINDOW_TWINDOWMESSAGEQUEST_H

#include "types.h"

#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowMessage.h"

struct TWindowMessageQuest : public TWindowMessage {
    TWindowMessageQuest(const NJS_POINT2 *position);
    virtual ~TWindowMessageQuest();
    static const char *class_name;
    virtual void render();
    void set_frame_mode(s32 mode);
    s32 frame_mode;
};

LAYOUT_ASSERT(TWindowMessageQuest_size, sizeof(TWindowMessageQuest) == 0x94);

TWindowMessageQuest *create_quest_message_window();

// create_quest_message_window_at's second argument (384 x 80: the window's size)
struct DefaultQuestMessageExtent {
    NJS_POINT2 size;
    f32 reserved;
};


#endif
