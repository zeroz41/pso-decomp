#ifndef PSO_UI_WINDOW_TWINDOWSUBQUESTBOARDSELECT_H
#define PSO_UI_WINDOW_TWINDOWSUBQUESTBOARDSELECT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowSubStatusDisp;

struct TWindowSubQuestBoardSelect : public TWindowBase {
    TWindowSubQuestBoardSelect();
    virtual ~TWindowSubQuestBoardSelect();
    void update_slot_display_flags();
    int is_shortcut_active();
    void sub_8027D230();
    int is_open();
    virtual void render();
    u8 m_60;
    u8 m_61;
    u8 _pad62[0x2];
    TWindowSubStatusDisp *m_64;
    void handle_cancel();
    void handle_decide();
    void select_next();
    void handle_page_input();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubQuestBoardSelect_size, sizeof(TWindowSubQuestBoardSelect) == 0x68);

extern "C" {
s32 get_slot_flag__26TWindowSubQuestBoardSelectFic(s32 arg0, s8 arg1);
}
#endif
