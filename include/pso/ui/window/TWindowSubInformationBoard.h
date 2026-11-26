#ifndef PSO_UI_WINDOW_TWINDOWSUBINFORMATIONBOARD_H
#define PSO_UI_WINDOW_TWINDOWSUBINFORMATIONBOARD_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TKeyBoardControl;
struct TWindowMenu;
struct TWindowMessage;
struct TWindowMessageYesNo;

struct TWindowSubInformationBoard : public TObject {
    TWindowSubInformationBoard(TObject *parent, s32 client);
    virtual ~TWindowSubInformationBoard();
    u32 open_card_info_window();
    u8 state;
    u8 _pad1D[0x3];
    s32 client;
    u32 shown_index;    // index set_page/set_message_index last showed; -1 after a new message window
    TWindowMainMenu *parent_menu;
    TWindowMenu *menu_window;    // create_info_board_menu (TWindowMenu)
    uaddr page_menu;      // sub_8034CDE0: one entry per info-board page, picks set_page
    TWindowMessage *message_window; // TWindowMessage::create (open_card_info_window, show_card_a7)
    TWindowMessageYesNo *dialog_window;
    TKeyBoardControl *keyboard;
    void* m_40;
    virtual void render();
    virtual void run_task();
    static void clear_if_current(u32 arg0);
    void set_page(s32 page);
    void set_message_index(s32 index);
    static TKeyBoardControl *open_keyboard(saddr parent);
    u32 show_card_a7();
    TWindowMenu *create_info_board_menu();
    u32 sub_8034CDE0();
    u8 unk_44[0x8D0];
};

LAYOUT_ASSERT(TWindowSubInformationBoard_size, sizeof(TWindowSubInformationBoard) == 0x914);

#endif
