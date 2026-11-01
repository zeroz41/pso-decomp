#ifndef PSO_MISC_TWINDOWSUBQUESTBOARDSELECT_H
#define PSO_MISC_TWINDOWSUBQUESTBOARDSELECT_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowSubQuestBoardSelect : public TWindowBase {
    virtual ~TWindowSubQuestBoardSelect();
    void update_slot_display_flags();
    int is_shortcut_active();
    void sub_8027D230();
    int is_open();
    virtual void render();
    u8 _pad1C[0x4];
    s16 m_20;
    u8 _pad22[0x2];
    void* m_24;
    u8 _pad28[0x34];
    u32 m_5c;
    u8 m_60;
    u8 m_61;
    u8 _pad62[0x2];
    u32 m_64;
    void handle_cancel();
    void handle_decide();
    void select_next();
    s32 handle_page_input();
    virtual void run_task();
};

typedef char TWindowSubQuestBoardSelect_size[sizeof(TWindowSubQuestBoardSelect) == 0x68 ? 1 : -1];

extern "C" {
s32 get_slot_flag__26TWindowSubQuestBoardSelectFic(s32 arg0, s8 arg1);
void render__26TWindowSubQuestBoardSelectFv(u8 *arg0);
void *__dt__26TWindowSubQuestBoardSelectFv(void *arg0, s16 arg1);
u8 *TWindowSubQuestBoardSelect__ct(TWindowSubQuestBoardSelect *window_sub_quest_board_select);
}
#endif
