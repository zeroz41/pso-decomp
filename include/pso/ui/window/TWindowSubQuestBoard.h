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
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubQuestBoard_size, sizeof(TWindowSubQuestBoard) == 0x30);

// Option menu setters: write one field of the client's card window flags
// (TWindowKeyBoardHard::set_card_window_flags), named by the bits they keep.
void set_card_flags_1C00(saddr client_id, s32 value);
void set_card_flags_300(saddr client_id, s32 value);
void set_card_flag_8(saddr client_id, s32 value);
void set_card_flag_4(saddr client_id, s32 value);
void set_card_flag_2(saddr client_id, s32 value);
int set_card_flag_1(saddr client_id, int value);

#endif
