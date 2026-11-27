#ifndef PSO_UI_WINDOW_TWINDOWSUBQUESTBOARD_H
#define PSO_UI_WINDOW_TWINDOWSUBQUESTBOARD_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TQuestThreadBoard;
struct TWindowMainMenu;
struct TWindowSubQuestBoardSelect;

struct TWindowSubQuestBoard : public TObject {
    TWindowSubQuestBoard(TObject *object, s32 client);
    virtual ~TWindowSubQuestBoard();
    u8 state;
    u8 pad_1d[0x3];
    s32 client;
    TWindowMainMenu *parent_menu;
    TWindowSubQuestBoardSelect *select_window;
    TQuestThreadBoard *quest_thread_board;

    static const char *class_name;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubQuestBoard_size, sizeof(TWindowSubQuestBoard) == 0x30);

// The quest board option setters TWindowSubOption::update_quest_board_card_flags calls: each stores
// value into one bit field of client_id's CharacterSaveRecord::card_window_flags.
void set_board_flags(saddr client_id, s32 value);
void set_card_window_flags(saddr client_id, s32 value);
void clear_card_window_flags(saddr client_id, s32 value);
void set_card_flag_4(saddr client_id, s32 value);
void set_card_flags_scaled(saddr client_id, s32 value);
void set_card_flags_direct(saddr client_id, s32 value);

#endif
