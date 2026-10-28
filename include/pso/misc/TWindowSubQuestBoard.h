#ifndef PSO_MISC_TWINDOWSUBQUESTBOARD_H
#define PSO_MISC_TWINDOWSUBQUESTBOARD_H

#include "types.h"
#include "pso/TObject.h"

class TQuestThreadBoard;

struct TWindowSubQuestBoard : public TObject {
    TWindowSubQuestBoard(TObject *arg1, void *arg2);
    virtual ~TWindowSubQuestBoard();
    u8 m_1c;
    u8 _pad1D[0x3];
    u32 m_20;
    u32 m_24;
    u32 m_28;
    TQuestThreadBoard *quest_thread_board;
    void set_board_flags(s32 arg1);
    void set_card_window_flags(s32 arg1);
    void clear_card_window_flags(s32 arg1);
    void set_card_flags_scaled(s32 arg1);
    int set_card_flags_direct(int a1);
    virtual void render();
    virtual void run_task();
    u8 get_page_index();
};

typedef char TWindowSubQuestBoard_size[sizeof(TWindowSubQuestBoard) == 0x30 ? 1 : -1];

extern "C" {
u8 *TWindowSubQuestBoard__sub_8027CE74(u8 *arg0, u8 *arg1, s32 arg2);
void TWindowSubQuestBoard__sub_8027CF50(s32 arg0, s32 arg1);
void *__dt__20TWindowSubQuestBoardFv(void *arg0, s16 arg1);
}

// --- C functions defined in TWindowSubQuestBoard.cpp ---
extern "C" {
u8 *TWindowSubQuestBoard__sub_8027CE74(u8 *arg0, u8 *arg1, s32 arg2);
void TWindowSubQuestBoard__sub_8027CF50(s32 arg0, s32 arg1);
}
// --- end of C functions

#endif
