#ifndef PSO_UI_WINDOW_TWINDOWSUBQUESTBOARD_H
#define PSO_UI_WINDOW_TWINDOWSUBQUESTBOARD_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TQuestThreadBoard;
struct TWindowMainMenu;

struct TWindowSubQuestBoard : public TObject {
    TWindowSubQuestBoard(TObject *object, void *arg2);
    virtual ~TWindowSubQuestBoard();
    u8 m_1c;
    u8 _pad1D[0x3];
    u32 m_20;
    TWindowMainMenu *parent_menu;
    uaddr m_28;
    TQuestThreadBoard *quest_thread_board;
    void set_board_flags(s32 value);
    void set_card_window_flags(s32 value);
    void clear_card_window_flags(s32 value);
    void set_card_flags_scaled(s32 value);
    int set_card_flags_direct(int a1);
    virtual void render();
    virtual void run_task();
    u8 get_page_index();
};

LAYOUT_ASSERT(TWindowSubQuestBoard_size, sizeof(TWindowSubQuestBoard) == 0x30);

extern "C" {
void *__dt__20TWindowSubQuestBoardFv(void *arg0, s16 arg1);
}

// --- C functions defined in TWindowSubQuestBoard.cpp ---
extern "C" {
u8 *TWindowSubQuestBoard__sub_8027CE74(u8 *arg0, TWindowMainMenu *parent, s32 client_id);
void TWindowSubQuestBoard__sub_8027CF50(saddr client_id, s32 value);
}
// --- end of C functions

extern "C" {
int TWindowSubQuestBoard__sub_8027D1DC(void *p);
}

#endif
