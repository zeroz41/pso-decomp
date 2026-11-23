#ifndef PSO_UI_WINDOW_TWINDOWSUBQUESTBOARD_H
#define PSO_UI_WINDOW_TWINDOWSUBQUESTBOARD_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TQuestThreadBoard;
struct TWindowMainMenu;
struct TWindowSubQuestBoardSelect;

struct TWindowSubQuestBoard : public TObject {
    TWindowSubQuestBoard(TObject *object, void *client);
    virtual ~TWindowSubQuestBoard();
    u8 state;
    u8 pad_1d[0x3];
    void *client;
    TWindowMainMenu *parent_menu;
    TWindowSubQuestBoardSelect *select_window;
    TQuestThreadBoard *quest_thread_board;

    static const char *class_name;
    void set_board_flags(s32 value);
    void set_card_window_flags(s32 value);
    void clear_card_window_flags(s32 value);
    void set_card_flags_scaled(s32 value);
    int set_card_flags_direct(int card_flags_direct);
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubQuestBoard_size, sizeof(TWindowSubQuestBoard) == 0x30);

extern "C" {
void *__dt__20TWindowSubQuestBoardFv(void *arg0, s16 arg1);
}

// --- C functions defined in TWindowSubQuestBoard.cpp ---
extern "C" {
void TWindowSubQuestBoard__sub_8027CF50(saddr client_id, s32 value);
}
// --- end of C functions


#endif
