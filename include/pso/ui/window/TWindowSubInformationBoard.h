#ifndef PSO_UI_WINDOW_TWINDOWSUBINFORMATIONBOARD_H
#define PSO_UI_WINDOW_TWINDOWSUBINFORMATIONBOARD_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TKeyBoardControl;

struct TWindowSubInformationBoard : public TObject {
    TWindowSubInformationBoard(TObject *object, void *arg2);
    virtual ~TWindowSubInformationBoard();
    u32 open_card_info_window();
    u8 m_1c;
    u8 _pad1D[0x3];
    u32 m_20;
    u32 shown_index;    // index set_page/set_message_index last showed; -1 after a new message window
    TWindowMainMenu *parent_menu;
    uaddr menu_window;    // create_info_board_menu (TWindowMenu)
    uaddr page_menu;      // sub_8034CDE0: one entry per info-board page, picks set_page
    uaddr message_window; // TWindowMessage::create (open_card_info_window, show_card_a7)
    uaddr m_38;
    TKeyBoardControl *keyboard;
    void* m_40;
    virtual void render();
    virtual void run_task();
    static void clear_if_current(u32 arg0);
    void set_page(s32 arg1);
    void set_message_index(s32 index);
    static TKeyBoardControl *open_keyboard(saddr parent);
    u32 show_card_a7();
    u32 create_info_board_menu();
    u32 sub_8034CDE0();
    u8 unk_44[0x8D0];
};

LAYOUT_ASSERT(TWindowSubInformationBoard_size, sizeof(TWindowSubInformationBoard) == 0x914);

#endif
